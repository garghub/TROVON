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
V_4 -> V_221 = F_109 ( V_4 ) ? V_222 : F_88 ;
F_110 ( V_4 , V_2 ) ;
F_111 ( V_4 -> V_203 , & V_2 -> V_204 ) ;
V_77 = F_44 ( V_4 ) ;
V_77 -> V_223 = V_211 -> V_224 ;
V_77 -> V_225 = V_211 -> V_226 ;
V_77 -> V_82 = F_52 ( V_213 -> V_82 ) ;
V_77 -> V_227 = F_52 ( V_8 -> V_61 ) ;
* ( ( ( V_228 * ) V_77 ) + 6 ) = F_112 ( ( ( V_215 >> 2 ) << 12 ) |
V_213 -> V_65 ) ;
if ( F_51 ( V_213 -> V_65 & V_96 ) ) {
V_77 -> V_229 = F_112 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_77 -> V_229 = F_112 ( F_31 ( V_2 ) ) ;
}
V_77 -> V_230 = 0 ;
V_77 -> V_231 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_213 -> V_82 , V_8 -> V_99 ) ) ) {
if ( F_11 ( V_8 -> V_99 , V_213 -> V_82 + 0x10000 ) ) {
V_77 -> V_231 = F_112 ( V_8 -> V_99 - V_213 -> V_82 ) ;
V_77 -> V_232 = 1 ;
} else if ( F_113 ( V_213 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_231 = F_112 ( 0xFFFF ) ;
V_77 -> V_232 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_102 ) ;
if ( F_53 ( ( V_213 -> V_65 & V_96 ) == 0 ) )
F_43 ( V_2 , V_4 , V_215 ) ;
#ifdef F_55
if ( V_144 ) {
F_114 ( V_2 , V_233 ) ;
V_8 -> V_150 -> V_234 ( V_102 . V_108 ,
V_144 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_198 -> V_235 ( V_2 , V_4 ) ;
if ( F_53 ( V_213 -> V_65 & V_236 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_215 )
F_22 ( V_8 , V_2 ) ;
if ( F_113 ( V_213 -> V_12 , V_8 -> V_11 ) || V_213 -> V_82 == V_213 -> V_12 )
F_115 ( F_9 ( V_2 ) , V_237 ,
F_6 ( V_4 ) ) ;
F_45 ( V_4 ) -> V_238 = F_6 ( V_4 ) ;
V_4 -> V_239 . V_240 = 0 ;
memset ( V_4 -> V_241 , 0 , F_21 ( sizeof( struct V_242 ) ,
sizeof( struct V_243 ) ) ) ;
V_216 = V_6 -> V_198 -> V_244 ( V_2 , V_4 , & V_211 -> V_245 . V_246 ) ;
if ( F_53 ( V_216 <= 0 ) )
return V_216 ;
F_116 ( V_2 ) ;
return F_117 ( V_216 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_247 = F_5 ( V_4 ) -> V_12 ;
F_119 ( V_4 ) ;
F_120 ( V_2 , V_4 ) ;
V_2 -> V_248 += V_4 -> V_203 ;
F_121 ( V_2 , V_4 -> V_203 ) ;
}
static void F_122 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_249 )
{
struct V_89 * V_90 = F_45 ( V_4 ) ;
F_123 ( F_100 ( V_4 ) ) ;
if ( V_4 -> V_81 <= V_249 || V_4 -> V_91 == V_250 ) {
F_48 ( V_4 , 1 ) ;
V_90 -> V_95 = 0 ;
V_90 -> V_85 = 0 ;
} else {
F_48 ( V_4 , F_124 ( V_4 -> V_81 , V_249 ) ) ;
V_90 -> V_95 = V_249 ;
V_90 -> V_85 = V_2 -> V_251 ;
}
}
static void F_125 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_252 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_253 || F_126 ( V_8 ) )
return;
if ( F_113 ( F_127 ( V_8 ) , F_5 ( V_4 ) -> V_82 ) )
V_8 -> V_254 -= V_252 ;
}
static void F_128 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_252 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_252 ;
if ( F_5 ( V_4 ) -> V_94 & V_255 )
V_8 -> V_253 -= V_252 ;
if ( F_5 ( V_4 ) -> V_94 & V_256 )
V_8 -> V_257 -= V_252 ;
if ( F_5 ( V_4 ) -> V_94 & V_258 )
V_8 -> V_259 -= V_252 ;
if ( F_126 ( V_8 ) && V_252 > 0 )
V_8 -> V_253 -= F_30 ( T_4 , V_8 -> V_253 , V_252 ) ;
F_125 ( V_2 , V_4 , V_252 ) ;
if ( V_8 -> V_260 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_260 ) -> V_82 ) &&
( F_129 ( V_8 ) || ( F_5 ( V_4 ) -> V_94 & V_255 ) ) )
V_8 -> V_261 -= V_252 ;
F_130 ( V_8 ) ;
}
static void F_131 ( struct V_3 * V_4 , struct V_3 * V_262 )
{
struct V_89 * V_90 = F_45 ( V_4 ) ;
if ( F_51 ( V_90 -> V_263 & V_264 ) &&
! F_11 ( V_90 -> V_265 , F_5 ( V_262 ) -> V_82 ) ) {
struct V_89 * V_266 = F_45 ( V_262 ) ;
T_7 V_267 = V_90 -> V_263 & V_264 ;
V_90 -> V_263 &= ~ V_267 ;
V_266 -> V_263 |= V_267 ;
F_132 ( V_90 -> V_265 , V_266 -> V_265 ) ;
}
}
int F_133 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_249 , T_10 V_268 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_269 ;
int V_270 , V_271 ;
int V_272 ;
T_7 V_88 ;
if ( F_134 ( V_81 > V_4 -> V_81 ) )
return - V_273 ;
V_270 = F_135 ( V_4 ) - V_81 ;
if ( V_270 < 0 )
V_270 = 0 ;
if ( F_136 ( V_4 , V_268 ) )
return - V_274 ;
V_269 = F_137 ( V_2 , V_270 , V_268 ) ;
if ( V_269 == NULL )
return - V_274 ;
V_2 -> V_248 += V_269 -> V_203 ;
F_121 ( V_2 , V_269 -> V_203 ) ;
V_272 = V_4 -> V_81 - V_81 - V_270 ;
V_269 -> V_203 += V_272 ;
V_4 -> V_203 -= V_272 ;
F_5 ( V_269 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_269 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_269 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_88 & ~ ( V_97 | V_275 ) ;
F_5 ( V_269 ) -> V_65 = V_88 ;
F_5 ( V_269 ) -> V_94 = F_5 ( V_4 ) -> V_94 ;
if ( ! F_45 ( V_4 ) -> V_276 && V_4 -> V_91 != V_92 ) {
V_269 -> V_93 = F_138 ( V_4 -> V_181 + V_81 ,
F_139 ( V_269 , V_270 ) ,
V_270 , 0 ) ;
F_140 ( V_4 , V_81 ) ;
V_4 -> V_93 = F_141 ( V_4 -> V_93 , V_269 -> V_93 , V_81 ) ;
} else {
V_4 -> V_91 = V_92 ;
F_142 ( V_4 , V_269 , V_81 ) ;
}
V_269 -> V_91 = V_4 -> V_91 ;
V_269 -> V_239 = V_4 -> V_239 ;
F_131 ( V_4 , V_269 ) ;
V_271 = F_6 ( V_4 ) ;
F_122 ( V_2 , V_4 , V_249 ) ;
F_122 ( V_2 , V_269 , V_249 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_269 ) -> V_12 ) ) {
int V_277 = V_271 - F_6 ( V_4 ) -
F_6 ( V_269 ) ;
if ( V_277 )
F_128 ( V_2 , V_4 , V_277 ) ;
}
F_119 ( V_269 ) ;
F_143 ( V_4 , V_269 , V_2 ) ;
return 0 ;
}
static void F_144 ( struct V_3 * V_4 , int V_81 )
{
struct V_89 * V_90 ;
int V_200 , V_278 , V_279 ;
V_279 = F_30 ( int , V_81 , F_135 ( V_4 ) ) ;
if ( V_279 ) {
F_145 ( V_4 , V_279 ) ;
V_81 -= V_279 ;
if ( ! V_81 )
return;
}
V_279 = V_81 ;
V_278 = 0 ;
V_90 = F_45 ( V_4 ) ;
for ( V_200 = 0 ; V_200 < V_90 -> V_276 ; V_200 ++ ) {
int V_169 = F_146 ( & V_90 -> V_280 [ V_200 ] ) ;
if ( V_169 <= V_279 ) {
F_147 ( V_4 , V_200 ) ;
V_279 -= V_169 ;
} else {
V_90 -> V_280 [ V_278 ] = V_90 -> V_280 [ V_200 ] ;
if ( V_279 ) {
V_90 -> V_280 [ V_278 ] . V_281 += V_279 ;
F_148 ( & V_90 -> V_280 [ V_278 ] , V_279 ) ;
V_279 = 0 ;
}
V_278 ++ ;
}
}
V_90 -> V_276 = V_278 ;
F_149 ( V_4 ) ;
V_4 -> V_282 -= V_81 ;
V_4 -> V_81 = V_4 -> V_282 ;
}
int F_150 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_136 ( V_4 , V_180 ) )
return - V_274 ;
F_144 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_91 = V_92 ;
V_4 -> V_203 -= V_81 ;
V_2 -> V_248 -= V_81 ;
F_151 ( V_2 , V_81 ) ;
F_152 ( V_2 , V_283 ) ;
if ( F_6 ( V_4 ) > 1 )
F_122 ( V_2 , V_4 , F_153 ( V_4 ) ) ;
return 0 ;
}
static inline int F_154 ( struct V_1 * V_2 , int V_284 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_249 ;
V_249 = V_284 - V_6 -> V_198 -> V_285 - sizeof( struct V_76 ) ;
if ( V_6 -> V_198 -> V_286 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_155 ( V_18 ) )
V_249 -= V_6 -> V_198 -> V_286 ;
}
if ( V_249 > V_8 -> V_59 . V_287 )
V_249 = V_8 -> V_59 . V_287 ;
V_249 -= V_6 -> V_288 ;
if ( V_249 < 48 )
V_249 = 48 ;
return V_249 ;
}
int F_156 ( struct V_1 * V_2 , int V_284 )
{
return F_154 ( V_2 , V_284 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_157 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_289 ;
V_289 = V_19 +
V_8 -> V_80 +
V_6 -> V_288 +
V_6 -> V_198 -> V_285 ;
if ( V_6 -> V_198 -> V_286 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_155 ( V_18 ) )
V_289 += V_6 -> V_198 -> V_286 ;
}
return V_289 ;
}
void F_158 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_290 * V_290 = F_9 ( V_2 ) ;
V_6 -> V_291 . V_292 = V_290 -> V_71 . V_293 > 1 ;
V_6 -> V_291 . V_294 = V_8 -> V_59 . V_287 + sizeof( struct V_76 ) +
V_6 -> V_198 -> V_285 ;
V_6 -> V_291 . V_295 = F_157 ( V_2 , V_290 -> V_71 . V_296 ) ;
V_6 -> V_291 . V_297 = 0 ;
}
unsigned int F_159 ( struct V_1 * V_2 , T_4 V_284 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_249 ;
if ( V_6 -> V_291 . V_294 > V_284 )
V_6 -> V_291 . V_294 = V_284 ;
V_249 = F_156 ( V_2 , V_284 ) ;
V_249 = F_160 ( V_8 , V_249 ) ;
V_6 -> V_298 = V_284 ;
if ( V_6 -> V_291 . V_292 )
V_249 = F_20 ( V_249 , F_156 ( V_2 , V_6 -> V_291 . V_295 ) ) ;
V_8 -> V_299 = V_249 ;
return V_249 ;
}
unsigned int F_62 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_249 ;
unsigned int V_300 ;
struct V_101 V_102 ;
struct V_143 * V_144 ;
V_249 = V_8 -> V_299 ;
if ( V_18 ) {
T_4 V_289 = F_161 ( V_18 ) ;
if ( V_289 != F_2 ( V_2 ) -> V_298 )
V_249 = F_159 ( V_2 , V_289 ) ;
}
V_300 = F_59 ( V_2 , NULL , & V_102 , & V_144 ) +
sizeof( struct V_76 ) ;
if ( V_300 != V_8 -> V_80 ) {
int V_22 = ( int ) V_300 - V_8 -> V_80 ;
V_249 -= V_22 ;
}
return V_249 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_301 == V_302 &&
V_2 -> V_303 && ! F_163 ( V_304 , & V_2 -> V_303 -> V_88 ) ) {
T_4 V_305 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_306 = F_21 ( V_8 -> V_32 , V_305 ) ;
if ( V_306 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_306 ) >> 1 ;
}
V_8 -> V_32 = 0 ;
}
V_8 -> V_31 = V_23 ;
}
static void F_164 ( struct V_1 * V_2 , bool V_307 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_98 , V_8 -> V_308 ) ||
V_8 -> V_10 > V_8 -> V_309 ) {
V_8 -> V_309 = V_8 -> V_10 ;
V_8 -> V_308 = V_8 -> V_11 ;
V_8 -> V_307 = V_307 ;
}
if ( F_165 ( V_2 ) ) {
V_8 -> V_32 = 0 ;
V_8 -> V_31 = V_23 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_32 )
V_8 -> V_32 = V_8 -> V_10 ;
if ( V_34 &&
( T_3 ) ( V_23 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 )
F_162 ( V_2 ) ;
}
}
static bool F_166 ( const struct V_7 * V_8 )
{
return F_113 ( V_8 -> V_310 , V_8 -> V_98 ) &&
! F_113 ( V_8 -> V_310 , V_8 -> V_11 ) ;
}
static void F_167 ( struct V_7 * V_8 , unsigned int V_249 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_249 )
V_8 -> V_310 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_168 ( bool V_311 , const struct V_7 * V_8 ,
int V_179 )
{
return V_311 &&
( ( V_179 & V_312 ) ||
( ! V_179 && V_8 -> V_10 && F_166 ( V_8 ) ) ) ;
}
static T_4 F_169 ( const struct V_1 * V_2 , unsigned int V_249 )
{
T_4 V_313 , V_314 ;
V_313 = F_20 ( V_2 -> V_315 >> 10 ,
V_2 -> V_316 - 1 - V_317 ) ;
V_314 = F_29 ( T_4 , V_313 / V_249 , V_318 ) ;
return F_30 ( T_4 , V_314 , V_2 -> V_319 ) ;
}
static unsigned int F_170 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_249 ,
unsigned int V_320 ,
int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_311 , V_321 , V_229 , V_322 ;
V_229 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_322 = V_249 * V_320 ;
if ( F_53 ( V_322 <= V_229 && V_4 != F_171 ( V_2 ) ) )
return V_322 ;
V_321 = F_20 ( V_4 -> V_81 , V_229 ) ;
if ( V_322 <= V_321 )
return V_322 ;
V_311 = V_321 % V_249 ;
if ( F_168 ( V_311 != 0 , V_8 , V_179 ) )
return V_321 - V_311 ;
return V_321 ;
}
static inline unsigned int F_172 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_323 , V_26 , V_324 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_97 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_323 = F_104 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_323 >= V_26 )
return 0 ;
V_324 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_324 , V_26 - V_323 ) ;
}
static int F_173 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_249 )
{
int V_325 = F_6 ( V_4 ) ;
if ( ! V_325 || ( V_325 > 1 && F_153 ( V_4 ) != V_249 ) ) {
F_122 ( V_2 , V_4 , V_249 ) ;
V_325 = F_6 ( V_4 ) ;
}
return V_325 ;
}
static inline bool F_174 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_326 , int V_179 )
{
if ( V_179 & V_327 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_97 ) )
return true ;
if ( ! F_168 ( V_4 -> V_81 < V_326 , V_8 , V_179 ) )
return true ;
return false ;
}
static bool F_175 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_326 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_326 )
V_12 = F_5 ( V_4 ) -> V_82 + V_326 ;
return ! F_113 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_176 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_326 , int V_179 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_328 ;
F_173 ( V_2 , V_4 , V_326 ) ;
if ( ! F_174 ( V_8 , V_4 , V_326 , V_179 ) )
return 0 ;
V_328 = F_172 ( V_8 , V_4 ) ;
if ( V_328 && ! F_175 ( V_8 , V_4 , V_326 ) )
V_328 = 0 ;
return V_328 ;
}
bool F_177 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_178 ( V_2 ) ;
return V_4 &&
F_176 ( V_2 , V_4 , F_62 ( V_2 ) ,
( F_179 ( V_2 , V_4 ) ?
V_8 -> V_179 : V_327 ) ) ;
}
static int F_180 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_249 , T_10 V_268 )
{
struct V_3 * V_269 ;
int V_272 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_282 )
return F_133 ( V_2 , V_4 , V_81 , V_249 , V_268 ) ;
V_269 = F_137 ( V_2 , 0 , V_268 ) ;
if ( F_51 ( V_269 == NULL ) )
return - V_274 ;
V_2 -> V_248 += V_269 -> V_203 ;
F_121 ( V_2 , V_269 -> V_203 ) ;
V_269 -> V_203 += V_272 ;
V_4 -> V_203 -= V_272 ;
F_5 ( V_269 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_269 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_269 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_88 & ~ ( V_97 | V_275 ) ;
F_5 ( V_269 ) -> V_65 = V_88 ;
F_5 ( V_269 ) -> V_94 = 0 ;
V_269 -> V_91 = V_4 -> V_91 = V_92 ;
F_142 ( V_4 , V_269 , V_81 ) ;
F_131 ( V_4 , V_269 ) ;
F_122 ( V_2 , V_4 , V_249 ) ;
F_122 ( V_2 , V_269 , V_249 ) ;
F_119 ( V_269 ) ;
F_143 ( V_4 , V_269 , V_2 ) ;
return 0 ;
}
static bool F_181 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_307 , T_4 V_320 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_329 , V_330 , V_331 , V_323 ;
int V_332 ;
if ( F_5 ( V_4 ) -> V_65 & V_97 )
goto V_333;
if ( V_6 -> V_301 != V_302 )
goto V_333;
if ( V_8 -> V_334 &&
( ( ( T_4 ) V_335 << 1 ) >> 1 ) - ( V_8 -> V_334 >> 1 ) > 1 )
goto V_333;
V_323 = F_104 ( V_8 ) ;
F_98 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_323 ) ) ;
V_329 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_330 = ( V_8 -> V_27 - V_323 ) * V_8 -> V_299 ;
V_331 = F_20 ( V_329 , V_330 ) ;
if ( V_331 >= V_320 * V_8 -> V_299 )
goto V_333;
if ( ( V_4 != F_171 ( V_2 ) ) && ( V_331 >= V_4 -> V_81 ) )
goto V_333;
V_332 = F_182 ( V_336 ) ;
if ( V_332 ) {
T_4 V_337 = F_20 ( V_8 -> V_338 , V_8 -> V_27 * V_8 -> V_299 ) ;
V_337 /= V_332 ;
if ( V_331 >= V_337 )
goto V_333;
} else {
if ( V_331 > F_183 ( V_8 ) * V_8 -> V_299 )
goto V_333;
}
if ( ! V_8 -> V_334 )
V_8 -> V_334 = 1 | ( V_335 << 1 ) ;
if ( V_330 < V_329 && V_330 < V_4 -> V_81 )
* V_307 = true ;
return true ;
V_333:
V_8 -> V_334 = 0 ;
return false ;
}
static int F_184 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_339 , * V_340 ;
int V_81 ;
int V_297 ;
int V_341 ;
int V_342 ;
int V_249 ;
if ( ! V_6 -> V_291 . V_292 ||
V_6 -> V_291 . V_297 ||
F_2 ( V_2 ) -> V_301 != V_302 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_171 || V_8 -> V_59 . V_126 )
return - 1 ;
V_249 = F_62 ( V_2 ) ;
V_297 = 2 * V_8 -> V_299 ;
V_341 = V_297 + ( V_8 -> V_343 + 1 ) * V_8 -> V_299 ;
if ( V_297 > F_156 ( V_2 , V_6 -> V_291 . V_294 ) ) {
return - 1 ;
}
if ( V_8 -> V_247 - V_8 -> V_11 < V_341 )
return - 1 ;
if ( V_8 -> V_338 < V_341 )
return - 1 ;
if ( F_113 ( V_8 -> V_11 + V_341 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_104 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_104 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_339 = F_137 ( V_2 , V_297 , V_180 ) ) == NULL )
return - 1 ;
V_2 -> V_248 += V_339 -> V_203 ;
F_121 ( V_2 , V_339 -> V_203 ) ;
V_4 = F_178 ( V_2 ) ;
F_5 ( V_339 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_339 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_297 ;
F_5 ( V_339 ) -> V_65 = V_236 ;
F_5 ( V_339 ) -> V_94 = 0 ;
V_339 -> V_93 = 0 ;
V_339 -> V_91 = V_4 -> V_91 ;
F_185 ( V_339 , V_4 , V_2 ) ;
V_81 = 0 ;
F_186 (skb, next, sk) {
V_342 = F_30 ( int , V_4 -> V_81 , V_297 - V_81 ) ;
if ( V_339 -> V_91 )
F_187 ( V_4 , 0 , F_139 ( V_339 , V_342 ) , V_342 ) ;
else
V_339 -> V_93 = F_188 ( V_4 , 0 ,
F_139 ( V_339 , V_342 ) ,
V_342 , V_339 -> V_93 ) ;
if ( V_4 -> V_81 <= V_342 ) {
F_5 ( V_339 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_189 ( V_4 , V_2 ) ;
F_190 ( V_2 , V_4 ) ;
} else {
F_5 ( V_339 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_97 | V_275 ) ;
if ( ! F_45 ( V_4 ) -> V_276 ) {
F_191 ( V_4 , V_342 ) ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_192 ( V_4 -> V_181 ,
V_4 -> V_81 , 0 ) ;
} else {
F_144 ( V_4 , V_342 ) ;
F_122 ( V_2 , V_4 , V_249 ) ;
}
F_5 ( V_4 ) -> V_82 += V_342 ;
}
V_81 += V_342 ;
if ( V_81 >= V_297 )
break;
}
F_173 ( V_2 , V_339 , V_339 -> V_81 ) ;
if ( ! F_97 ( V_2 , V_339 , 1 , V_180 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_339 ) ;
V_6 -> V_291 . V_297 = F_157 ( V_2 , V_339 -> V_81 ) ;
V_8 -> V_344 . V_345 = F_5 ( V_339 ) -> V_82 ;
V_8 -> V_344 . V_346 = F_5 ( V_339 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_61 ( struct V_1 * V_2 , unsigned int V_249 , int V_179 ,
int V_347 , T_10 V_268 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_325 , V_348 ;
int V_328 ;
int V_349 ;
bool V_307 = false ;
T_4 V_320 ;
V_348 = 0 ;
if ( ! V_347 ) {
V_349 = F_184 ( V_2 ) ;
if ( ! V_349 ) {
return false ;
} else if ( V_349 > 0 ) {
V_348 = 1 ;
}
}
V_320 = F_169 ( V_2 , V_249 ) ;
while ( ( V_4 = F_178 ( V_2 ) ) ) {
unsigned int V_331 ;
V_325 = F_173 ( V_2 , V_4 , V_249 ) ;
F_98 ( ! V_325 ) ;
if ( F_51 ( V_8 -> V_350 ) && V_8 -> V_351 == V_352 ) {
F_99 ( & V_4 -> V_217 ) ;
goto V_350;
}
V_328 = F_172 ( V_8 , V_4 ) ;
if ( ! V_328 ) {
V_307 = true ;
if ( V_347 == 2 )
V_328 = 1 ;
else
break;
}
if ( F_51 ( ! F_175 ( V_8 , V_4 , V_249 ) ) )
break;
if ( V_325 == 1 || ! V_320 ) {
if ( F_51 ( ! F_174 ( V_8 , V_4 , V_249 ,
( F_179 ( V_2 , V_4 ) ?
V_179 : V_327 ) ) ) )
break;
} else {
if ( ! V_347 &&
F_181 ( V_2 , V_4 , & V_307 ,
V_320 ) )
break;
}
V_331 = V_249 ;
if ( V_325 > 1 && V_320 && ! F_49 ( V_8 ) )
V_331 = F_170 ( V_2 , V_4 , V_249 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_179 ) ;
if ( V_4 -> V_81 > V_331 &&
F_51 ( F_180 ( V_2 , V_4 , V_331 , V_249 , V_268 ) ) )
break;
V_331 = F_21 ( 2 * V_4 -> V_203 , V_2 -> V_315 >> 10 ) ;
V_331 = F_30 ( T_4 , V_331 , V_353 ) ;
if ( F_193 ( & V_2 -> V_204 ) > V_331 ) {
F_73 ( V_207 , & V_8 -> V_191 ) ;
F_194 () ;
if ( F_193 ( & V_2 -> V_204 ) > V_331 )
break;
}
if ( F_51 ( F_97 ( V_2 , V_4 , 1 , V_268 ) ) )
break;
V_350:
F_1 ( V_2 , V_4 ) ;
F_167 ( V_8 , V_249 , V_4 ) ;
V_348 += F_6 ( V_4 ) ;
if ( V_347 )
break;
}
if ( F_53 ( V_348 ) ) {
if ( F_195 ( V_2 ) )
V_8 -> V_354 += V_348 ;
if ( V_347 != 2 )
F_196 ( V_2 ) ;
F_164 ( V_2 , V_307 ) ;
return false ;
}
return ( V_347 == 2 ) || ( ! V_8 -> V_10 && F_178 ( V_2 ) ) ;
}
bool F_196 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_355 , V_356 , V_357 ;
T_4 V_358 = F_197 ( V_8 -> V_359 >> 3 ) ;
if ( F_134 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_134 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_173 == V_360 )
return false ;
if ( V_6 -> V_13 != V_361 )
return false ;
if ( V_362 < 3 || ! V_8 -> V_359 || ! V_8 -> V_10 ||
! F_198 ( V_8 ) || F_2 ( V_2 ) -> V_301 != V_302 )
return false ;
if ( ( V_8 -> V_27 > F_104 ( V_8 ) ) &&
F_178 ( V_2 ) )
return false ;
V_355 = V_358 << 1 ;
if ( V_8 -> V_10 == 1 )
V_355 = F_29 ( T_4 , V_355 ,
( V_358 + ( V_358 >> 1 ) + V_363 ) ) ;
V_355 = F_29 ( T_4 , V_355 , F_199 ( 10 ) ) ;
V_356 = V_23 + V_355 ;
V_357 = ( T_4 ) F_2 ( V_2 ) -> V_364 ;
if ( ( T_3 ) ( V_356 - V_357 ) > 0 ) {
T_3 V_22 = V_357 - V_23 ;
if ( V_22 > 0 )
V_355 = V_22 ;
}
F_200 ( V_2 , V_15 , V_355 ,
V_365 ) ;
return true ;
}
static bool F_201 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_202 ( V_2 , V_4 ) ) ) {
F_203 ( F_9 ( V_2 ) ,
V_366 ) ;
return true ;
}
return false ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_367 ;
int V_19 = F_62 ( V_2 ) ;
int V_216 = - 1 ;
if ( F_178 ( V_2 ) != NULL ) {
V_216 = F_61 ( V_2 , V_19 , V_368 , 2 , V_180 ) ;
goto V_369;
}
if ( V_8 -> V_370 )
goto V_369;
V_4 = F_171 ( V_2 ) ;
if ( F_134 ( ! V_4 ) )
goto V_369;
if ( F_201 ( V_2 , V_4 ) )
goto V_369;
V_367 = F_6 ( V_4 ) ;
if ( F_134 ( ! V_367 ) )
goto V_369;
if ( ( V_367 > 1 ) && ( V_4 -> V_81 > ( V_367 - 1 ) * V_19 ) ) {
if ( F_51 ( F_133 ( V_2 , V_4 , ( V_367 - 1 ) * V_19 , V_19 ,
V_180 ) ) )
goto V_369;
V_4 = F_171 ( V_2 ) ;
}
if ( F_134 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_369;
V_216 = F_205 ( V_2 , V_4 ) ;
if ( F_53 ( ! V_216 ) )
V_8 -> V_370 = V_8 -> V_11 ;
V_369:
F_200 ( V_2 , V_361 ,
F_2 ( V_2 ) -> V_30 ,
V_365 ) ;
if ( F_53 ( ! V_216 ) )
F_203 ( F_9 ( V_2 ) ,
V_371 ) ;
}
void F_206 ( struct V_1 * V_2 , unsigned int V_326 ,
int V_179 )
{
if ( F_51 ( V_2 -> V_173 == V_372 ) )
return;
if ( F_61 ( V_2 , V_326 , V_179 , 0 ,
F_207 ( V_2 , V_180 ) ) )
F_208 ( V_2 ) ;
}
void F_209 ( struct V_1 * V_2 , unsigned int V_249 )
{
struct V_3 * V_4 = F_178 ( V_2 ) ;
F_98 ( ! V_4 || V_4 -> V_81 < V_249 ) ;
F_61 ( V_2 , V_249 , V_327 , 1 , V_2 -> V_373 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_374 ;
int V_375 = F_210 ( V_2 ) ;
int V_376 = F_211 ( V_2 ) ;
int V_377 = F_30 ( int , V_8 -> V_46 , V_376 ) ;
int V_229 ;
if ( V_19 > V_377 )
V_19 = V_377 ;
if ( V_375 < ( V_377 >> 1 ) ) {
V_6 -> V_35 . V_378 = 0 ;
if ( F_212 ( V_2 ) )
V_8 -> V_379 = F_20 ( V_8 -> V_379 ,
4U * V_8 -> V_20 ) ;
V_375 = F_213 ( V_375 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_375 < ( V_376 >> 4 ) || V_375 < V_19 )
return 0 ;
}
if ( V_375 > V_8 -> V_379 )
V_375 = V_8 -> V_379 ;
V_229 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_229 = V_375 ;
if ( ( ( V_229 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_229 )
V_229 = ( ( ( V_229 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_229 <= V_375 - V_19 || V_229 > V_375 )
V_229 = ( V_375 / V_19 ) * V_19 ;
else if ( V_19 == V_377 &&
V_375 > V_229 + ( V_377 >> 1 ) )
V_229 = V_375 ;
}
return V_229 ;
}
static void F_214 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_380 = F_215 ( V_2 , V_4 ) ;
int V_381 , V_382 ;
V_381 = V_4 -> V_81 ;
V_382 = V_380 -> V_81 ;
F_98 ( F_6 ( V_4 ) != 1 || F_6 ( V_380 ) != 1 ) ;
F_216 ( V_2 , V_380 , V_4 ) ;
F_189 ( V_380 , V_2 ) ;
F_217 ( V_380 , F_139 ( V_4 , V_382 ) ,
V_382 ) ;
if ( V_380 -> V_91 == V_92 )
V_4 -> V_91 = V_92 ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_218 ( V_4 -> V_93 , V_380 -> V_93 , V_381 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_380 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_380 ) -> V_65 ;
F_5 ( V_4 ) -> V_94 |= F_5 ( V_380 ) -> V_94 & V_383 ;
F_219 ( V_8 ) ;
if ( V_380 == V_8 -> V_384 )
V_8 -> V_384 = V_4 ;
F_128 ( V_2 , V_380 , F_6 ( V_380 ) ) ;
F_190 ( V_2 , V_380 ) ;
}
static bool F_220 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_45 ( V_4 ) -> V_276 != 0 )
return false ;
if ( F_100 ( V_4 ) )
return false ;
if ( V_4 == F_178 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_94 & V_255 )
return false ;
return true ;
}
static void F_221 ( struct V_1 * V_2 , struct V_3 * V_385 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_385 , * V_386 ;
bool V_387 = true ;
if ( ! V_388 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
return;
F_186 (skb, tmp, sk) {
if ( ! F_220 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_81 ;
if ( V_387 ) {
V_387 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_81 > F_222 ( V_385 ) )
break;
if ( F_113 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_214 ( V_2 , V_385 ) ;
}
}
int F_205 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_326 ;
int V_216 ;
if ( V_6 -> V_291 . V_297 ) {
V_6 -> V_291 . V_297 = 0 ;
}
if ( F_193 ( & V_2 -> V_204 ) >
F_20 ( V_2 -> V_248 + ( V_2 -> V_248 >> 2 ) , V_2 -> V_389 ) )
return - V_390 ;
if ( F_201 ( V_2 , V_4 ) )
return - V_391 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_98 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_98 ) )
F_223 () ;
if ( F_150 ( V_2 , V_4 , V_8 -> V_98 - F_5 ( V_4 ) -> V_82 ) )
return - V_274 ;
}
if ( F_2 ( V_2 ) -> V_198 -> V_392 ( V_2 ) )
return - V_393 ;
V_326 = F_62 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_98 )
return - V_390 ;
if ( V_4 -> V_81 > V_326 ) {
if ( F_133 ( V_2 , V_4 , V_326 , V_326 , V_180 ) )
return - V_274 ;
} else {
int V_394 = F_6 ( V_4 ) ;
if ( F_51 ( V_394 > 1 ) ) {
if ( F_136 ( V_4 , V_180 ) )
return - V_274 ;
F_173 ( V_2 , V_4 , V_326 ) ;
F_128 ( V_2 , V_4 , V_394 - F_6 ( V_4 ) ) ;
}
}
F_221 ( V_2 , V_4 , V_326 ) ;
if ( F_51 ( ( V_395 && ( ( unsigned long ) V_4 -> V_181 & 3 ) ) ||
F_224 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_339 = F_225 ( V_4 , V_317 ,
V_180 ) ;
V_216 = V_339 ? F_97 ( V_2 , V_339 , 0 , V_180 ) :
- V_218 ;
} else {
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
}
if ( F_53 ( ! V_216 ) ) {
F_5 ( V_4 ) -> V_94 |= V_383 ;
F_226 ( F_9 ( V_2 ) , V_396 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
F_203 ( F_9 ( V_2 ) , V_397 ) ;
V_8 -> V_398 ++ ;
}
return V_216 ;
}
int F_227 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_216 = F_205 ( V_2 , V_4 ) ;
if ( V_216 == 0 ) {
#if V_399 > 0
if ( F_5 ( V_4 ) -> V_94 & V_256 ) {
F_228 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_257 )
V_8 -> V_400 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_94 |= V_401 ;
V_8 -> V_257 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_402 )
V_8 -> V_402 = F_56 ( V_4 ) ;
F_5 ( V_4 ) -> V_227 = V_8 -> V_11 ;
} else if ( V_216 != - V_391 ) {
F_203 ( F_9 ( V_2 ) , V_403 ) ;
}
if ( V_8 -> V_404 < 0 )
V_8 -> V_404 = 0 ;
V_8 -> V_404 += F_6 ( V_4 ) ;
return V_216 ;
}
static bool F_229 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_301 != V_405 )
return false ;
if ( F_126 ( V_8 ) )
return false ;
if ( F_177 ( V_2 ) )
return false ;
return true ;
}
void F_230 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_406 = NULL ;
T_4 V_407 ;
int V_408 ;
int V_409 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_259 )
V_8 -> V_410 = V_8 -> V_98 ;
if ( V_8 -> V_384 ) {
V_4 = V_8 -> V_384 ;
V_407 = F_5 ( V_4 ) -> V_12 ;
if ( F_113 ( V_407 , V_8 -> V_410 ) )
V_407 = V_8 -> V_410 ;
} else {
V_4 = F_231 ( V_2 ) ;
V_407 = V_8 -> V_98 ;
}
F_232 (skb, sk) {
T_5 V_94 = F_5 ( V_4 ) -> V_94 ;
if ( V_4 == F_178 ( V_2 ) )
break;
if ( V_406 == NULL )
V_8 -> V_384 = V_4 ;
if ( F_104 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_409 ) {
V_411:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_127 ( V_8 ) ) )
break;
V_408 = V_412 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_410 ) ) {
V_8 -> V_410 = V_407 ;
if ( ! F_229 ( V_2 ) )
break;
if ( V_406 != NULL ) {
V_4 = V_406 ;
V_406 = NULL ;
}
V_409 = 1 ;
goto V_411;
} else if ( ! ( V_94 & V_258 ) ) {
if ( V_406 == NULL && ! ( V_94 & ( V_256 | V_255 ) ) )
V_406 = V_4 ;
continue;
} else {
V_407 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_301 != V_413 )
V_408 = V_414 ;
else
V_408 = V_415 ;
}
if ( V_94 & ( V_255 | V_256 ) )
continue;
if ( F_227 ( V_2 , V_4 ) )
return;
F_203 ( F_9 ( V_2 ) , V_408 ) ;
if ( F_195 ( V_2 ) )
V_8 -> V_354 += F_6 ( V_4 ) ;
if ( V_4 == F_231 ( V_2 ) )
F_200 ( V_2 , V_361 ,
F_2 ( V_2 ) -> V_30 ,
V_365 ) ;
}
}
void F_233 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_171 ( V_2 ) ;
int V_249 ;
V_249 = F_62 ( V_2 ) ;
if ( F_178 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_65 |= V_97 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_247 ++ ;
} else {
for (; ; ) {
V_4 = F_137 ( V_2 , 0 , V_2 -> V_373 ) ;
if ( V_4 )
break;
F_234 () ;
}
F_47 ( V_4 , V_8 -> V_247 ,
V_236 | V_97 ) ;
F_118 ( V_2 , V_4 ) ;
}
F_206 ( V_2 , V_249 , V_368 ) ;
}
void F_235 ( struct V_1 * V_2 , T_10 V_416 )
{
struct V_3 * V_4 ;
V_4 = F_236 ( V_317 , V_416 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_417 ) ;
return;
}
F_237 ( V_4 , V_317 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_236 | V_418 ) ;
if ( F_97 ( V_2 , V_4 , 0 , V_416 ) )
F_34 ( F_9 ( V_2 ) , V_417 ) ;
F_226 ( F_9 ( V_2 ) , V_419 ) ;
}
int F_238 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_231 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_65 & V_96 ) ) {
F_239 ( L_2 , V_420 ) ;
return - V_421 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_236 ) ) {
if ( F_100 ( V_4 ) ) {
struct V_3 * V_339 = F_240 ( V_4 , V_180 ) ;
if ( V_339 == NULL )
return - V_274 ;
F_189 ( V_4 , V_2 ) ;
F_119 ( V_339 ) ;
F_241 ( V_2 , V_339 ) ;
F_190 ( V_2 , V_4 ) ;
V_2 -> V_248 += V_339 -> V_203 ;
F_121 ( V_2 , V_339 -> V_203 ) ;
V_4 = V_339 ;
}
F_5 ( V_4 ) -> V_65 |= V_236 ;
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
V_4 = F_243 ( V_2 , V_317 , 1 , V_180 ) ;
if ( F_51 ( ! V_4 ) ) {
F_244 ( V_18 ) ;
return NULL ;
}
F_237 ( V_4 , V_317 ) ;
F_245 ( V_4 , V_18 ) ;
F_246 ( V_4 , V_2 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_422 && V_8 -> V_59 . V_422 < V_19 )
V_19 = V_8 -> V_59 . V_422 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
#ifdef F_247
if ( F_51 ( V_75 -> V_423 ) )
V_4 -> V_217 . V_424 = F_248 ( V_75 ) ;
else
#endif
F_99 ( & V_4 -> V_217 ) ;
V_215 = F_57 ( V_2 , V_75 , V_19 , V_4 , & V_102 , & V_144 ,
V_136 ) + sizeof( * V_77 ) ;
F_106 ( V_4 , V_215 ) ;
F_107 ( V_4 ) ;
V_77 = F_44 ( V_4 ) ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_425 = 1 ;
V_77 -> V_426 = 1 ;
F_41 ( V_75 , V_77 , V_2 ) ;
V_77 -> V_223 = F_112 ( V_166 -> V_427 ) ;
V_77 -> V_225 = V_166 -> V_428 ;
F_47 ( V_4 , F_58 ( V_75 ) -> V_429 ,
V_96 | V_236 ) ;
V_77 -> V_82 = F_52 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_227 = F_52 ( F_58 ( V_75 ) -> V_61 ) ;
V_77 -> V_229 = F_112 ( F_20 ( V_75 -> V_45 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_102 ) ;
V_77 -> V_430 = ( V_215 >> 2 ) ;
F_249 ( F_9 ( V_2 ) , V_237 ) ;
#ifdef F_55
if ( V_144 ) {
F_58 ( V_75 ) -> V_150 -> V_234 ( V_102 . V_108 ,
V_144 , NULL , V_75 , V_4 ) ;
}
#endif
return V_4 ;
}
static void F_250 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_431 * V_432 ;
T_4 V_433 = F_23 ( V_18 , V_434 ) ;
if ( V_433 == V_435 )
return;
F_251 () ;
V_432 = F_252 ( V_433 ) ;
if ( F_53 ( V_432 && F_253 ( V_432 -> V_436 ) ) ) {
F_254 ( V_6 -> V_437 -> V_436 ) ;
V_6 -> V_438 = F_255 ( V_18 ) ;
V_6 -> V_437 = V_432 ;
}
F_256 () ;
}
static void F_257 ( struct V_1 * V_2 )
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
if ( V_8 -> V_59 . V_422 )
V_8 -> V_59 . V_287 = V_8 -> V_59 . V_422 ;
V_8 -> V_439 = 0 ;
F_158 ( V_2 ) ;
F_159 ( V_2 , F_161 ( V_18 ) ) ;
F_250 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_440 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_422 && V_8 -> V_59 . V_422 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_422 ;
F_258 ( V_2 ) ;
if ( V_2 -> V_441 & V_442 &&
( V_8 -> V_46 > F_211 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_211 ( V_2 ) ;
F_28 ( F_211 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_443 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_158 ,
& V_48 ,
F_23 ( V_18 , V_444 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_379 = V_8 -> V_45 ;
V_2 -> V_445 = 0 ;
F_259 ( V_2 , V_446 ) ;
V_8 -> V_338 = 0 ;
F_260 ( V_8 , 0 ) ;
V_8 -> V_98 = V_8 -> V_247 ;
V_8 -> V_310 = V_8 -> V_247 ;
V_8 -> V_99 = V_8 -> V_247 ;
V_8 -> V_11 = V_8 -> V_247 ;
if ( F_53 ( ! V_8 -> V_350 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_447 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_448 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_449 ;
F_2 ( V_2 ) -> V_450 = 0 ;
F_261 ( V_8 ) ;
}
static void F_262 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_212 * V_213 = F_5 ( V_4 ) ;
V_213 -> V_12 += V_4 -> V_81 ;
F_119 ( V_4 ) ;
F_263 ( V_2 , V_4 ) ;
V_2 -> V_248 += V_4 -> V_203 ;
F_121 ( V_2 , V_4 -> V_203 ) ;
V_8 -> V_247 = V_213 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_264 ( struct V_1 * V_2 , struct V_3 * V_425 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_147 * V_451 = V_8 -> V_149 ;
int V_452 = 0 , V_50 , V_216 = 0 , V_453 ;
unsigned long V_454 = 0 ;
struct V_3 * V_455 ;
V_8 -> V_59 . V_287 = V_8 -> V_20 ;
F_265 ( V_2 , & V_8 -> V_59 . V_287 , & V_451 -> V_162 ,
& V_452 , & V_454 ) ;
if ( V_452 > 1 &&
F_266 ( V_335 , V_454 + ( 60 * V_456 << V_452 ) ) ) {
V_451 -> V_162 . V_81 = - 1 ;
goto V_457;
}
if ( V_458 & V_459 )
V_451 -> V_162 . V_81 = - 1 ;
else if ( V_451 -> V_162 . V_81 <= 0 )
goto V_457;
if ( V_8 -> V_59 . V_422 && V_8 -> V_59 . V_422 < V_8 -> V_59 . V_287 )
V_8 -> V_59 . V_287 = V_8 -> V_59 . V_422 ;
V_50 = F_154 ( V_2 , F_2 ( V_2 ) -> V_298 ) -
V_146 ;
V_50 = F_30 ( V_460 , V_50 , V_451 -> V_169 ) ;
V_50 = F_30 ( V_460 , V_50 , F_267 ( V_317 ) ) ;
V_455 = F_137 ( V_2 , V_50 , V_2 -> V_373 ) ;
if ( ! V_455 )
goto V_457;
V_455 -> V_91 = V_92 ;
memcpy ( V_455 -> V_241 , V_425 -> V_241 , sizeof( V_425 -> V_241 ) ) ;
V_453 = F_268 ( F_139 ( V_455 , V_50 ) , V_50 ,
& V_451 -> V_181 -> V_461 ) ;
if ( F_51 ( ! V_453 ) ) {
F_269 ( V_455 ) ;
goto V_457;
}
if ( V_453 != V_50 ) {
F_140 ( V_455 , V_453 ) ;
V_50 = V_453 ;
}
if ( V_50 == V_451 -> V_169 )
V_451 -> V_181 = NULL ;
V_451 -> V_453 = V_50 ;
F_262 ( V_2 , V_455 ) ;
V_216 = F_97 ( V_2 , V_455 , 1 , V_2 -> V_373 ) ;
V_425 -> V_217 = V_455 -> V_217 ;
F_5 ( V_455 ) -> V_82 ++ ;
F_5 ( V_455 ) -> V_65 = V_236 | V_275 ;
if ( ! V_216 ) {
V_8 -> V_455 = ( V_451 -> V_453 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_462;
}
V_457:
if ( V_451 -> V_162 . V_81 > 0 )
V_451 -> V_162 . V_81 = 0 ;
V_216 = F_97 ( V_2 , V_425 , 1 , V_2 -> V_373 ) ;
if ( V_216 )
V_8 -> V_164 = 0 ;
V_462:
V_451 -> V_162 . V_81 = - 1 ;
return V_216 ;
}
int F_270 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_269 ;
int V_216 ;
F_257 ( V_2 ) ;
if ( F_51 ( V_8 -> V_350 ) ) {
F_271 ( V_2 , NULL ) ;
return 0 ;
}
V_269 = F_137 ( V_2 , 0 , V_2 -> V_373 ) ;
if ( F_51 ( ! V_269 ) )
return - V_218 ;
F_47 ( V_269 , V_8 -> V_247 ++ , V_96 ) ;
V_8 -> V_402 = V_23 ;
F_262 ( V_2 , V_269 ) ;
F_39 ( V_2 , V_269 ) ;
V_216 = V_8 -> V_149 ? F_264 ( V_2 , V_269 ) :
F_97 ( V_2 , V_269 , 1 , V_2 -> V_373 ) ;
if ( V_216 == - V_463 )
return V_216 ;
V_8 -> V_11 = V_8 -> V_247 ;
V_8 -> V_464 = V_8 -> V_247 ;
F_226 ( F_9 ( V_2 ) , V_465 ) ;
F_200 ( V_2 , V_361 ,
F_2 ( V_2 ) -> V_30 , V_365 ) ;
return 0 ;
}
void F_272 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_355 ;
F_18 ( V_2 , V_466 ) ;
if ( V_37 > V_467 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_468 = V_456 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_469 & V_470 ) )
V_468 = V_363 ;
if ( V_8 -> V_359 ) {
int V_358 = F_29 ( int , F_197 ( V_8 -> V_359 >> 3 ) ,
V_467 ) ;
if ( V_358 < V_468 )
V_468 = V_358 ;
}
V_37 = F_20 ( V_37 , V_468 ) ;
}
V_355 = V_335 + V_37 ;
if ( V_6 -> V_35 . V_469 & V_471 ) {
if ( V_6 -> V_35 . V_472 ||
F_273 ( V_6 -> V_35 . V_355 , V_335 + ( V_37 >> 2 ) ) ) {
F_274 ( V_2 ) ;
return;
}
if ( ! F_266 ( V_355 , V_6 -> V_35 . V_355 ) )
V_355 = V_6 -> V_35 . V_355 ;
}
V_6 -> V_35 . V_469 |= V_473 | V_471 ;
V_6 -> V_35 . V_355 = V_355 ;
F_275 ( V_2 , & V_6 -> V_474 , V_355 ) ;
}
void F_274 ( struct V_1 * V_2 )
{
struct V_3 * V_269 ;
if ( V_2 -> V_173 == V_372 )
return;
F_18 ( V_2 , V_475 ) ;
V_269 = F_236 ( V_317 , F_207 ( V_2 , V_180 ) ) ;
if ( V_269 == NULL ) {
F_276 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_476 ;
F_200 ( V_2 , V_41 ,
V_363 , V_365 ) ;
return;
}
F_237 ( V_269 , V_317 ) ;
F_47 ( V_269 , F_10 ( V_2 ) , V_236 ) ;
F_277 ( V_269 ) ;
F_99 ( & V_269 -> V_217 ) ;
F_97 ( V_2 , V_269 , 0 , F_207 ( V_2 , V_180 ) ) ;
}
static int F_278 ( struct V_1 * V_2 , int V_477 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_236 ( V_317 , F_207 ( V_2 , V_180 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_237 ( V_4 , V_317 ) ;
F_47 ( V_4 , V_8 -> V_98 - ! V_477 , V_236 ) ;
F_99 ( & V_4 -> V_217 ) ;
return F_97 ( V_2 , V_4 , 0 , V_180 ) ;
}
void F_279 ( struct V_1 * V_2 )
{
if ( V_2 -> V_173 == V_478 ) {
F_3 ( V_2 ) -> V_479 = F_3 ( V_2 ) -> V_61 - 1 ;
F_278 ( V_2 , 0 ) ;
}
}
int F_280 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_173 == V_372 )
return - 1 ;
if ( ( V_4 = F_178 ( V_2 ) ) != NULL &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_216 ;
unsigned int V_19 = F_62 ( V_2 ) ;
unsigned int V_480 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_464 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_464 = F_5 ( V_4 ) -> V_12 ;
if ( V_480 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_480 = F_20 ( V_480 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_275 ;
if ( F_133 ( V_2 , V_4 , V_480 , V_19 , V_180 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_122 ( V_2 , V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_275 ;
V_216 = F_97 ( V_2 , V_4 , 1 , V_180 ) ;
if ( ! V_216 )
F_1 ( V_2 , V_4 ) ;
return V_216 ;
} else {
if ( F_281 ( V_8 -> V_99 , V_8 -> V_98 + 1 , V_8 -> V_98 + 0xFFFF ) )
F_278 ( V_2 , 1 ) ;
return F_278 ( V_2 , 0 ) ;
}
}
void F_282 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_481 ;
int V_216 ;
V_216 = F_280 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_178 ( V_2 ) ) {
V_6 -> V_482 = 0 ;
V_6 -> V_483 = 0 ;
return;
}
if ( V_216 <= 0 ) {
if ( V_6 -> V_483 < V_484 )
V_6 -> V_483 ++ ;
V_6 -> V_482 ++ ;
V_481 = V_365 ;
} else {
if ( ! V_6 -> V_482 )
V_6 -> V_482 = 1 ;
V_481 = V_485 ;
}
F_200 ( V_2 , V_486 ,
F_283 ( V_6 , V_481 ) ,
V_365 ) ;
}
int F_284 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_487 * V_488 = F_58 ( V_75 ) -> V_150 ;
struct V_489 V_246 ;
int V_490 ;
V_490 = V_488 -> V_491 ( V_2 , NULL , & V_246 , V_75 , 0 , NULL ) ;
if ( ! V_490 ) {
F_249 ( F_9 ( V_2 ) , V_396 ) ;
F_203 ( F_9 ( V_2 ) , V_397 ) ;
}
return V_490 ;
}
