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
V_8 -> V_67 = 0 ;
if ( F_9 ( V_2 ) -> V_70 . V_71 == 1 ||
F_37 ( V_2 ) ) {
F_5 ( V_4 ) -> V_65 |= V_69 | V_66 ;
V_8 -> V_67 = V_68 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
}
static void
F_40 ( const struct V_72 * V_73 , struct V_74 * V_75 ,
struct V_1 * V_2 )
{
if ( F_41 ( V_73 ) -> V_76 ) {
V_75 -> V_77 = 1 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_78 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_67 & V_68 ) {
if ( V_4 -> V_79 != V_78 &&
! F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_11 ) ) {
F_38 ( V_2 ) ;
if ( V_8 -> V_67 & V_81 ) {
V_8 -> V_67 &= ~ V_81 ;
F_43 ( V_4 ) -> V_82 = 1 ;
F_44 ( V_4 ) -> V_83 |= V_84 ;
}
} else if ( ! F_37 ( V_2 ) ) {
F_45 ( V_2 ) ;
}
if ( V_8 -> V_67 & V_85 )
F_43 ( V_4 ) -> V_77 = 1 ;
}
}
static void F_46 ( struct V_3 * V_4 , T_4 V_80 , T_7 V_86 )
{
struct V_87 * V_88 = F_44 ( V_4 ) ;
V_4 -> V_89 = V_90 ;
V_4 -> V_91 = 0 ;
F_5 ( V_4 ) -> V_65 = V_86 ;
F_5 ( V_4 ) -> V_92 = 0 ;
F_47 ( V_4 , 1 ) ;
V_88 -> V_93 = 0 ;
V_88 -> V_83 = 0 ;
F_5 ( V_4 ) -> V_80 = V_80 ;
if ( V_86 & ( V_94 | V_95 ) )
V_80 ++ ;
F_5 ( V_4 ) -> V_12 = V_80 ;
}
static inline bool F_48 ( const struct V_7 * V_8 )
{
return V_8 -> V_96 != V_8 -> V_97 ;
}
static void F_49 ( T_8 * V_98 , struct V_7 * V_8 ,
struct V_99 * V_100 )
{
T_6 V_101 = V_100 -> V_101 ;
if ( F_50 ( V_102 & V_101 ) ) {
* V_98 ++ = F_51 ( ( V_103 << 24 ) | ( V_103 << 16 ) |
( V_104 << 8 ) | V_105 ) ;
V_100 -> V_106 = ( T_5 * ) V_98 ;
V_98 += 4 ;
}
if ( F_50 ( V_100 -> V_19 ) ) {
* V_98 ++ = F_51 ( ( V_107 << 24 ) |
( V_108 << 16 ) |
V_100 -> V_19 ) ;
}
if ( F_52 ( V_109 & V_101 ) ) {
if ( F_50 ( V_110 & V_101 ) ) {
* V_98 ++ = F_51 ( ( V_111 << 24 ) |
( V_112 << 16 ) |
( V_113 << 8 ) |
V_114 ) ;
V_101 &= ~ V_110 ;
} else {
* V_98 ++ = F_51 ( ( V_103 << 24 ) |
( V_103 << 16 ) |
( V_113 << 8 ) |
V_114 ) ;
}
* V_98 ++ = F_51 ( V_100 -> V_115 ) ;
* V_98 ++ = F_51 ( V_100 -> V_116 ) ;
}
if ( F_50 ( V_110 & V_101 ) ) {
* V_98 ++ = F_51 ( ( V_103 << 24 ) |
( V_103 << 16 ) |
( V_111 << 8 ) |
V_112 ) ;
}
if ( F_50 ( V_117 & V_101 ) ) {
* V_98 ++ = F_51 ( ( V_103 << 24 ) |
( V_118 << 16 ) |
( V_119 << 8 ) |
V_100 -> V_120 ) ;
}
if ( F_50 ( V_100 -> V_121 ) ) {
struct V_122 * V_123 = V_8 -> V_59 . V_124 ?
V_8 -> V_125 : V_8 -> V_126 ;
int V_127 ;
* V_98 ++ = F_51 ( ( V_103 << 24 ) |
( V_103 << 16 ) |
( V_128 << 8 ) |
( V_129 + ( V_100 -> V_121 *
V_130 ) ) ) ;
for ( V_127 = 0 ; V_127 < V_100 -> V_121 ;
++ V_127 ) {
* V_98 ++ = F_51 ( V_123 [ V_127 ] . V_131 ) ;
* V_98 ++ = F_51 ( V_123 [ V_127 ] . V_12 ) ;
}
V_8 -> V_59 . V_124 = 0 ;
}
if ( F_50 ( V_132 & V_101 ) ) {
struct V_133 * V_134 = V_100 -> V_135 ;
* V_98 ++ = F_51 ( ( V_136 << 24 ) |
( ( V_137 + V_134 -> V_79 ) << 16 ) |
V_138 ) ;
memcpy ( V_98 , V_134 -> V_139 , V_134 -> V_79 ) ;
if ( ( V_134 -> V_79 & 3 ) == 2 ) {
T_7 * V_140 = ( ( T_7 * ) V_98 ) + V_134 -> V_79 ;
V_140 [ 0 ] = V_140 [ 1 ] = V_103 ;
}
V_98 += ( V_134 -> V_79 + 3 ) >> 2 ;
}
}
static unsigned int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
struct V_141 * * V_142 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_143 = V_144 ;
struct V_145 * V_146 = V_8 -> V_147 ;
#ifdef F_54
* V_142 = V_8 -> V_148 -> V_149 ( V_2 , V_2 ) ;
if ( * V_142 ) {
V_100 -> V_101 |= V_102 ;
V_143 -= V_150 ;
}
#else
* V_142 = NULL ;
#endif
V_100 -> V_19 = F_13 ( V_2 ) ;
V_143 -= V_151 ;
if ( F_52 ( V_152 && * V_142 == NULL ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = F_55 ( V_4 ) + V_8 -> V_153 ;
V_100 -> V_116 = V_8 -> V_59 . V_154 ;
V_143 -= V_155 ;
}
if ( F_52 ( V_156 ) ) {
V_100 -> V_120 = V_8 -> V_59 . V_48 ;
V_100 -> V_101 |= V_117 ;
V_143 -= V_157 ;
}
if ( F_52 ( V_158 ) ) {
V_100 -> V_101 |= V_110 ;
if ( F_50 ( ! ( V_109 & V_100 -> V_101 ) ) )
V_143 -= V_159 ;
}
if ( V_146 && V_146 -> V_160 . V_79 >= 0 ) {
T_4 V_161 = V_137 + V_146 -> V_160 . V_79 ;
V_161 = ( V_161 + 3 ) & ~ 3U ;
if ( V_143 >= V_161 ) {
V_100 -> V_101 |= V_132 ;
V_100 -> V_135 = & V_146 -> V_160 ;
V_143 -= V_161 ;
V_8 -> V_162 = 1 ;
}
}
return V_144 - V_143 ;
}
static unsigned int F_56 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
unsigned int V_19 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
struct V_141 * * V_142 ,
struct V_133 * V_134 )
{
struct V_163 * V_164 = F_41 ( V_73 ) ;
unsigned int V_143 = V_144 ;
#ifdef F_54
* V_142 = F_57 ( V_73 ) -> V_148 -> V_149 ( V_2 , V_73 ) ;
if ( * V_142 ) {
V_100 -> V_101 |= V_102 ;
V_143 -= V_150 ;
V_164 -> V_165 &= ! V_164 -> V_166 ;
}
#else
* V_142 = NULL ;
#endif
V_100 -> V_19 = V_19 ;
V_143 -= V_151 ;
if ( F_52 ( V_164 -> V_47 ) ) {
V_100 -> V_120 = V_164 -> V_48 ;
V_100 -> V_101 |= V_117 ;
V_143 -= V_157 ;
}
if ( F_52 ( V_164 -> V_165 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = F_55 ( V_4 ) ;
V_100 -> V_116 = V_73 -> V_154 ;
V_143 -= V_155 ;
}
if ( F_52 ( V_164 -> V_166 ) ) {
V_100 -> V_101 |= V_110 ;
if ( F_50 ( ! V_164 -> V_165 ) )
V_143 -= V_159 ;
}
if ( V_134 != NULL && V_134 -> V_79 >= 0 ) {
T_4 V_161 = V_137 + V_134 -> V_79 ;
V_161 = ( V_161 + 3 ) & ~ 3U ;
if ( V_143 >= V_161 ) {
V_100 -> V_101 |= V_132 ;
V_100 -> V_135 = V_134 ;
V_143 -= V_161 ;
}
}
return V_144 - V_143 ;
}
static unsigned int F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
struct V_141 * * V_142 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_167 = 0 ;
unsigned int V_168 ;
V_100 -> V_101 = 0 ;
#ifdef F_54
* V_142 = V_8 -> V_148 -> V_149 ( V_2 , V_2 ) ;
if ( F_50 ( * V_142 ) ) {
V_100 -> V_101 |= V_102 ;
V_167 += V_150 ;
}
#else
* V_142 = NULL ;
#endif
if ( F_52 ( V_8 -> V_59 . V_165 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = V_4 ? F_55 ( V_4 ) + V_8 -> V_153 : 0 ;
V_100 -> V_116 = V_8 -> V_59 . V_154 ;
V_167 += V_155 ;
}
V_168 = V_8 -> V_59 . V_169 + V_8 -> V_59 . V_124 ;
if ( F_50 ( V_168 ) ) {
const unsigned int V_143 = V_144 - V_167 ;
V_100 -> V_121 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_167 += V_170 +
V_100 -> V_121 * V_130 ;
}
return V_167 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_171 ) &
( V_172 | V_173 | V_174 |
V_175 | V_176 ) )
F_60 ( V_2 , F_61 ( V_2 ) , F_3 ( V_2 ) -> V_177 ,
0 , V_178 ) ;
}
static void F_62 ( unsigned long V_179 )
{
struct V_180 * V_181 = (struct V_180 * ) V_179 ;
F_63 ( V_182 ) ;
unsigned long V_86 ;
struct V_183 * V_184 , * V_185 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_64 ( V_86 ) ;
F_65 ( & V_181 -> V_186 , & V_182 ) ;
F_66 ( V_86 ) ;
F_67 (q, n, &list) {
V_8 = F_68 ( V_184 , struct V_7 , V_187 ) ;
F_69 ( & V_8 -> V_187 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_70 ( V_2 ) ;
if ( ! F_71 ( V_2 ) ) {
F_59 ( V_2 ) ;
} else {
F_72 ( V_188 , & V_8 -> V_189 ) ;
}
F_73 ( V_2 ) ;
F_74 ( V_190 , & V_8 -> V_189 ) ;
F_75 ( V_2 ) ;
}
}
void F_76 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_86 , V_191 ;
do {
V_86 = V_8 -> V_189 ;
if ( ! ( V_86 & V_192 ) )
return;
V_191 = V_86 & ~ V_192 ;
} while ( F_77 ( & V_8 -> V_189 , V_86 , V_191 ) != V_86 );
if ( V_86 & ( 1UL << V_188 ) )
F_59 ( V_2 ) ;
F_78 ( V_2 ) ;
if ( V_86 & ( 1UL << V_193 ) ) {
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_86 & ( 1UL << V_194 ) ) {
F_81 ( V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_86 & ( 1UL << V_195 ) ) {
F_2 ( V_2 ) -> V_196 -> V_197 ( V_2 ) ;
F_80 ( V_2 ) ;
}
}
void T_9 F_82 ( void )
{
int V_198 ;
F_83 (i) {
struct V_180 * V_181 = & F_84 ( V_180 , V_198 ) ;
F_85 ( & V_181 -> V_186 ) ;
F_86 ( & V_181 -> V_199 ,
F_62 ,
( unsigned long ) V_181 ) ;
}
}
void F_87 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_200 ;
V_200 = F_88 ( V_4 -> V_201 - 1 , & V_2 -> V_202 ) ;
if ( V_200 >= F_89 ( 1 ) && F_90 () == V_203 )
goto V_204;
if ( F_91 ( V_205 , & V_8 -> V_189 ) &&
! F_92 ( V_190 , & V_8 -> V_189 ) ) {
unsigned long V_86 ;
struct V_180 * V_181 ;
F_64 ( V_86 ) ;
V_181 = F_93 ( & V_180 ) ;
F_94 ( & V_8 -> V_187 , & V_181 -> V_186 ) ;
F_95 ( & V_181 -> V_199 ) ;
F_66 ( V_86 ) ;
return;
}
V_204:
F_75 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_206 ,
T_10 V_207 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_208 * V_209 ;
struct V_7 * V_8 ;
struct V_210 * V_211 ;
struct V_99 V_100 ;
unsigned int V_212 , V_213 ;
struct V_141 * V_142 ;
struct V_74 * V_75 ;
int V_214 ;
F_97 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_206 ) {
F_98 ( & V_4 -> V_215 ) ;
if ( F_50 ( F_99 ( V_4 ) ) )
V_4 = F_100 ( V_4 , V_207 ) ;
else
V_4 = F_101 ( V_4 , V_207 ) ;
if ( F_50 ( ! V_4 ) )
return - V_216 ;
}
V_209 = F_102 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_211 = F_5 ( V_4 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
if ( F_50 ( V_211 -> V_65 & V_94 ) )
V_212 = F_53 ( V_2 , V_4 , & V_100 , & V_142 ) ;
else
V_212 = F_58 ( V_2 , V_4 , & V_100 ,
& V_142 ) ;
V_213 = V_212 + sizeof( struct V_74 ) ;
if ( F_103 ( V_8 ) == 0 )
F_18 ( V_2 , V_217 ) ;
V_4 -> V_218 = F_104 ( V_2 ) < F_89 ( 1 ) ;
F_105 ( V_4 , V_213 ) ;
F_106 ( V_4 ) ;
F_107 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_219 = F_87 ;
F_108 ( V_4 , V_2 ) ;
F_109 ( V_4 -> V_201 , & V_2 -> V_202 ) ;
V_75 = F_43 ( V_4 ) ;
V_75 -> V_220 = V_209 -> V_221 ;
V_75 -> V_222 = V_209 -> V_223 ;
V_75 -> V_80 = F_51 ( V_211 -> V_80 ) ;
V_75 -> V_224 = F_51 ( V_8 -> V_61 ) ;
* ( ( ( V_225 * ) V_75 ) + 6 ) = F_110 ( ( ( V_213 >> 2 ) << 12 ) |
V_211 -> V_65 ) ;
if ( F_50 ( V_211 -> V_65 & V_94 ) ) {
V_75 -> V_226 = F_110 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_75 -> V_226 = F_110 ( F_31 ( V_2 ) ) ;
}
V_75 -> V_227 = 0 ;
V_75 -> V_228 = 0 ;
if ( F_50 ( F_48 ( V_8 ) && F_11 ( V_211 -> V_80 , V_8 -> V_97 ) ) ) {
if ( F_11 ( V_8 -> V_97 , V_211 -> V_80 + 0x10000 ) ) {
V_75 -> V_228 = F_110 ( V_8 -> V_97 - V_211 -> V_80 ) ;
V_75 -> V_229 = 1 ;
} else if ( F_111 ( V_211 -> V_80 + 0xFFFF , V_8 -> V_11 ) ) {
V_75 -> V_228 = F_110 ( 0xFFFF ) ;
V_75 -> V_229 = 1 ;
}
}
F_49 ( ( T_8 * ) ( V_75 + 1 ) , V_8 , & V_100 ) ;
if ( F_52 ( ( V_211 -> V_65 & V_94 ) == 0 ) )
F_42 ( V_2 , V_4 , V_213 ) ;
#ifdef F_54
if ( V_142 ) {
F_112 ( V_2 , V_230 ) ;
V_8 -> V_148 -> V_231 ( V_100 . V_106 ,
V_142 , V_2 , NULL , V_4 ) ;
}
#endif
V_6 -> V_196 -> V_232 ( V_2 , V_4 ) ;
if ( F_52 ( V_211 -> V_65 & V_233 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_79 != V_213 )
F_22 ( V_8 , V_2 ) ;
if ( F_111 ( V_211 -> V_12 , V_8 -> V_11 ) || V_211 -> V_80 == V_211 -> V_12 )
F_113 ( F_9 ( V_2 ) , V_234 ,
F_6 ( V_4 ) ) ;
F_44 ( V_4 ) -> V_235 = F_6 ( V_4 ) ;
V_4 -> V_236 . V_237 = 0 ;
memset ( V_4 -> V_238 , 0 , F_21 ( sizeof( struct V_239 ) ,
sizeof( struct V_240 ) ) ) ;
V_214 = V_6 -> V_196 -> V_241 ( V_2 , V_4 , & V_209 -> V_242 . V_243 ) ;
if ( F_52 ( V_214 <= 0 ) )
return V_214 ;
F_114 ( V_2 ) ;
return F_115 ( V_214 ) ;
}
static void F_116 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_244 = F_5 ( V_4 ) -> V_12 ;
F_117 ( V_4 ) ;
F_118 ( V_2 , V_4 ) ;
V_2 -> V_245 += V_4 -> V_201 ;
F_119 ( V_2 , V_4 -> V_201 ) ;
}
static void F_120 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_246 )
{
struct V_87 * V_88 = F_44 ( V_4 ) ;
F_121 ( F_99 ( V_4 ) ) ;
if ( V_4 -> V_79 <= V_246 || V_4 -> V_89 == V_247 ) {
F_47 ( V_4 , 1 ) ;
V_88 -> V_93 = 0 ;
V_88 -> V_83 = 0 ;
} else {
F_47 ( V_4 , F_122 ( V_4 -> V_79 , V_246 ) ) ;
V_88 -> V_93 = V_246 ;
V_88 -> V_83 = V_2 -> V_248 ;
}
}
static void F_123 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_249 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_250 || F_124 ( V_8 ) )
return;
if ( F_111 ( F_125 ( V_8 ) , F_5 ( V_4 ) -> V_80 ) )
V_8 -> V_251 -= V_249 ;
}
static void F_126 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_249 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_249 ;
if ( F_5 ( V_4 ) -> V_92 & V_252 )
V_8 -> V_250 -= V_249 ;
if ( F_5 ( V_4 ) -> V_92 & V_253 )
V_8 -> V_254 -= V_249 ;
if ( F_5 ( V_4 ) -> V_92 & V_255 )
V_8 -> V_256 -= V_249 ;
if ( F_124 ( V_8 ) && V_249 > 0 )
V_8 -> V_250 -= F_30 ( T_4 , V_8 -> V_250 , V_249 ) ;
F_123 ( V_2 , V_4 , V_249 ) ;
if ( V_8 -> V_257 &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_5 ( V_8 -> V_257 ) -> V_80 ) &&
( F_127 ( V_8 ) || ( F_5 ( V_4 ) -> V_92 & V_252 ) ) )
V_8 -> V_258 -= V_249 ;
F_128 ( V_8 ) ;
}
static void F_129 ( struct V_3 * V_4 , struct V_3 * V_259 )
{
struct V_87 * V_88 = F_44 ( V_4 ) ;
if ( F_50 ( V_88 -> V_260 & V_261 ) &&
! F_11 ( V_88 -> V_262 , F_5 ( V_259 ) -> V_80 ) ) {
struct V_87 * V_263 = F_44 ( V_259 ) ;
T_7 V_264 = V_88 -> V_260 & V_261 ;
V_88 -> V_260 &= ~ V_264 ;
V_263 -> V_260 |= V_264 ;
F_130 ( V_88 -> V_262 , V_263 -> V_262 ) ;
}
}
int F_131 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 ,
unsigned int V_246 , T_10 V_265 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_266 ;
int V_267 , V_268 ;
int V_269 ;
T_7 V_86 ;
if ( F_132 ( V_79 > V_4 -> V_79 ) )
return - V_270 ;
V_267 = F_133 ( V_4 ) - V_79 ;
if ( V_267 < 0 )
V_267 = 0 ;
if ( F_134 ( V_4 , V_265 ) )
return - V_271 ;
V_266 = F_135 ( V_2 , V_267 , V_265 ) ;
if ( V_266 == NULL )
return - V_271 ;
V_2 -> V_245 += V_266 -> V_201 ;
F_119 ( V_2 , V_266 -> V_201 ) ;
V_269 = V_4 -> V_79 - V_79 - V_267 ;
V_266 -> V_201 += V_269 ;
V_4 -> V_201 -= V_269 ;
F_5 ( V_266 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_266 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_266 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_95 | V_272 ) ;
F_5 ( V_266 ) -> V_65 = V_86 ;
F_5 ( V_266 ) -> V_92 = F_5 ( V_4 ) -> V_92 ;
if ( ! F_44 ( V_4 ) -> V_273 && V_4 -> V_89 != V_90 ) {
V_266 -> V_91 = F_136 ( V_4 -> V_179 + V_79 ,
F_137 ( V_266 , V_267 ) ,
V_267 , 0 ) ;
F_138 ( V_4 , V_79 ) ;
V_4 -> V_91 = F_139 ( V_4 -> V_91 , V_266 -> V_91 , V_79 ) ;
} else {
V_4 -> V_89 = V_90 ;
F_140 ( V_4 , V_266 , V_79 ) ;
}
V_266 -> V_89 = V_4 -> V_89 ;
V_266 -> V_236 = V_4 -> V_236 ;
F_129 ( V_4 , V_266 ) ;
V_268 = F_6 ( V_4 ) ;
F_120 ( V_2 , V_4 , V_246 ) ;
F_120 ( V_2 , V_266 , V_246 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_266 ) -> V_12 ) ) {
int V_274 = V_268 - F_6 ( V_4 ) -
F_6 ( V_266 ) ;
if ( V_274 )
F_126 ( V_2 , V_4 , V_274 ) ;
}
F_117 ( V_266 ) ;
F_141 ( V_4 , V_266 , V_2 ) ;
return 0 ;
}
static void F_142 ( struct V_3 * V_4 , int V_79 )
{
struct V_87 * V_88 ;
int V_198 , V_275 , V_276 ;
V_276 = F_30 ( int , V_79 , F_133 ( V_4 ) ) ;
if ( V_276 ) {
F_143 ( V_4 , V_276 ) ;
V_79 -= V_276 ;
if ( ! V_79 )
return;
}
V_276 = V_79 ;
V_275 = 0 ;
V_88 = F_44 ( V_4 ) ;
for ( V_198 = 0 ; V_198 < V_88 -> V_273 ; V_198 ++ ) {
int V_167 = F_144 ( & V_88 -> V_277 [ V_198 ] ) ;
if ( V_167 <= V_276 ) {
F_145 ( V_4 , V_198 ) ;
V_276 -= V_167 ;
} else {
V_88 -> V_277 [ V_275 ] = V_88 -> V_277 [ V_198 ] ;
if ( V_276 ) {
V_88 -> V_277 [ V_275 ] . V_278 += V_276 ;
F_146 ( & V_88 -> V_277 [ V_275 ] , V_276 ) ;
V_276 = 0 ;
}
V_275 ++ ;
}
}
V_88 -> V_273 = V_275 ;
F_147 ( V_4 ) ;
V_4 -> V_279 -= V_79 ;
V_4 -> V_79 = V_4 -> V_279 ;
}
int F_148 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_79 )
{
if ( F_134 ( V_4 , V_178 ) )
return - V_271 ;
F_142 ( V_4 , V_79 ) ;
F_5 ( V_4 ) -> V_80 += V_79 ;
V_4 -> V_89 = V_90 ;
V_4 -> V_201 -= V_79 ;
V_2 -> V_245 -= V_79 ;
F_149 ( V_2 , V_79 ) ;
F_150 ( V_2 , V_280 ) ;
if ( F_6 ( V_4 ) > 1 )
F_120 ( V_2 , V_4 , F_151 ( V_4 ) ) ;
return 0 ;
}
static inline int F_152 ( struct V_1 * V_2 , int V_281 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_246 ;
V_246 = V_281 - V_6 -> V_196 -> V_282 - sizeof( struct V_74 ) ;
if ( V_6 -> V_196 -> V_283 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_153 ( V_18 ) )
V_246 -= V_6 -> V_196 -> V_283 ;
}
if ( V_246 > V_8 -> V_59 . V_284 )
V_246 = V_8 -> V_59 . V_284 ;
V_246 -= V_6 -> V_285 ;
if ( V_246 < 48 )
V_246 = 48 ;
return V_246 ;
}
int F_154 ( struct V_1 * V_2 , int V_281 )
{
return F_152 ( V_2 , V_281 ) -
( F_3 ( V_2 ) -> V_78 - sizeof( struct V_74 ) ) ;
}
int F_155 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_286 ;
V_286 = V_19 +
V_8 -> V_78 +
V_6 -> V_285 +
V_6 -> V_196 -> V_282 ;
if ( V_6 -> V_196 -> V_283 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_153 ( V_18 ) )
V_286 += V_6 -> V_196 -> V_283 ;
}
return V_286 ;
}
void F_156 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_287 . V_288 = V_289 > 1 ;
V_6 -> V_287 . V_290 = V_8 -> V_59 . V_284 + sizeof( struct V_74 ) +
V_6 -> V_196 -> V_282 ;
V_6 -> V_287 . V_291 = F_155 ( V_2 , V_292 ) ;
V_6 -> V_287 . V_293 = 0 ;
}
unsigned int F_157 ( struct V_1 * V_2 , T_4 V_281 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_246 ;
if ( V_6 -> V_287 . V_290 > V_281 )
V_6 -> V_287 . V_290 = V_281 ;
V_246 = F_154 ( V_2 , V_281 ) ;
V_246 = F_158 ( V_8 , V_246 ) ;
V_6 -> V_294 = V_281 ;
if ( V_6 -> V_287 . V_288 )
V_246 = F_20 ( V_246 , F_154 ( V_2 , V_6 -> V_287 . V_291 ) ) ;
V_8 -> V_295 = V_246 ;
return V_246 ;
}
unsigned int F_61 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_246 ;
unsigned int V_296 ;
struct V_99 V_100 ;
struct V_141 * V_142 ;
V_246 = V_8 -> V_295 ;
if ( V_18 ) {
T_4 V_286 = F_159 ( V_18 ) ;
if ( V_286 != F_2 ( V_2 ) -> V_294 )
V_246 = F_157 ( V_2 , V_286 ) ;
}
V_296 = F_58 ( V_2 , NULL , & V_100 , & V_142 ) +
sizeof( struct V_74 ) ;
if ( V_296 != V_8 -> V_78 ) {
int V_22 = ( int ) V_296 - V_8 -> V_78 ;
V_246 -= V_22 ;
}
return V_246 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_297 == V_298 &&
V_2 -> V_299 && ! F_161 ( V_300 , & V_2 -> V_299 -> V_86 ) ) {
T_4 V_301 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_302 = F_21 ( V_8 -> V_32 , V_301 ) ;
if ( V_302 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_302 ) >> 1 ;
}
V_8 -> V_32 = 0 ;
}
V_8 -> V_31 = V_23 ;
}
static void F_162 ( struct V_1 * V_2 , bool V_303 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_96 , V_8 -> V_304 ) ||
V_8 -> V_10 > V_8 -> V_305 ) {
V_8 -> V_305 = V_8 -> V_10 ;
V_8 -> V_304 = V_8 -> V_11 ;
V_8 -> V_303 = V_303 ;
}
if ( F_163 ( V_2 ) ) {
V_8 -> V_32 = 0 ;
V_8 -> V_31 = V_23 ;
} else {
if ( V_8 -> V_10 > V_8 -> V_32 )
V_8 -> V_32 = V_8 -> V_10 ;
if ( V_34 &&
( T_3 ) ( V_23 - V_8 -> V_31 ) >= F_2 ( V_2 ) -> V_30 )
F_160 ( V_2 ) ;
}
}
static bool F_164 ( const struct V_7 * V_8 )
{
return F_111 ( V_8 -> V_306 , V_8 -> V_96 ) &&
! F_111 ( V_8 -> V_306 , V_8 -> V_11 ) ;
}
static void F_165 ( struct V_7 * V_8 , unsigned int V_246 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_79 < F_6 ( V_4 ) * V_246 )
V_8 -> V_306 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_166 ( bool V_307 , const struct V_7 * V_8 ,
int V_177 )
{
return V_307 &&
( ( V_177 & V_308 ) ||
( ! V_177 && V_8 -> V_10 && F_164 ( V_8 ) ) ) ;
}
static unsigned int F_167 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_246 ,
unsigned int V_309 ,
int V_177 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_307 , V_310 , V_226 , V_311 ;
V_226 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_311 = V_246 * V_309 ;
if ( F_52 ( V_311 <= V_226 && V_4 != F_168 ( V_2 ) ) )
return V_311 ;
V_310 = F_20 ( V_4 -> V_79 , V_226 ) ;
if ( V_311 <= V_310 )
return V_311 ;
V_307 = V_310 % V_246 ;
if ( F_166 ( V_307 != 0 , V_8 , V_177 ) )
return V_310 - V_307 ;
return V_310 ;
}
static inline unsigned int F_169 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_312 , V_26 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_95 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_312 = F_103 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_312 < V_26 )
return ( V_26 - V_312 ) ;
return 0 ;
}
static int F_170 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_246 )
{
int V_313 = F_6 ( V_4 ) ;
if ( ! V_313 || ( V_313 > 1 && F_151 ( V_4 ) != V_246 ) ) {
F_120 ( V_2 , V_4 , V_246 ) ;
V_313 = F_6 ( V_4 ) ;
}
return V_313 ;
}
static inline bool F_171 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_314 , int V_177 )
{
if ( V_177 & V_315 )
return true ;
if ( F_48 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_95 ) )
return true ;
if ( ! F_166 ( V_4 -> V_79 < V_314 , V_8 , V_177 ) )
return true ;
return false ;
}
static bool F_172 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_314 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_79 > V_314 )
V_12 = F_5 ( V_4 ) -> V_80 + V_314 ;
return ! F_111 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_173 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_314 , int V_177 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_316 ;
F_170 ( V_2 , V_4 , V_314 ) ;
if ( ! F_171 ( V_8 , V_4 , V_314 , V_177 ) )
return 0 ;
V_316 = F_169 ( V_8 , V_4 ) ;
if ( V_316 && ! F_172 ( V_8 , V_4 , V_314 ) )
V_316 = 0 ;
return V_316 ;
}
bool F_174 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_175 ( V_2 ) ;
return V_4 &&
F_173 ( V_2 , V_4 , F_61 ( V_2 ) ,
( F_176 ( V_2 , V_4 ) ?
V_8 -> V_177 : V_315 ) ) ;
}
static int F_177 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_79 ,
unsigned int V_246 , T_10 V_265 )
{
struct V_3 * V_266 ;
int V_269 = V_4 -> V_79 - V_79 ;
T_7 V_86 ;
if ( V_4 -> V_79 != V_4 -> V_279 )
return F_131 ( V_2 , V_4 , V_79 , V_246 , V_265 ) ;
V_266 = F_135 ( V_2 , 0 , V_265 ) ;
if ( F_50 ( V_266 == NULL ) )
return - V_271 ;
V_2 -> V_245 += V_266 -> V_201 ;
F_119 ( V_2 , V_266 -> V_201 ) ;
V_266 -> V_201 += V_269 ;
V_4 -> V_201 -= V_269 ;
F_5 ( V_266 ) -> V_80 = F_5 ( V_4 ) -> V_80 + V_79 ;
F_5 ( V_266 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_266 ) -> V_80 ;
V_86 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_86 & ~ ( V_95 | V_272 ) ;
F_5 ( V_266 ) -> V_65 = V_86 ;
F_5 ( V_266 ) -> V_92 = 0 ;
V_266 -> V_89 = V_4 -> V_89 = V_90 ;
F_140 ( V_4 , V_266 , V_79 ) ;
F_129 ( V_4 , V_266 ) ;
F_120 ( V_2 , V_4 , V_246 ) ;
F_120 ( V_2 , V_266 , V_246 ) ;
F_117 ( V_266 ) ;
F_141 ( V_4 , V_266 , V_2 ) ;
return 0 ;
}
static bool F_178 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_303 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_317 , V_318 , V_319 , V_312 ;
int V_320 ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
goto V_321;
if ( V_6 -> V_297 != V_298 )
goto V_321;
if ( V_8 -> V_322 &&
( ( ( T_4 ) V_323 << 1 ) >> 1 ) - ( V_8 -> V_322 >> 1 ) > 1 )
goto V_321;
V_312 = F_103 ( V_8 ) ;
F_97 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_312 ) ) ;
V_317 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
V_318 = ( V_8 -> V_27 - V_312 ) * V_8 -> V_295 ;
V_319 = F_20 ( V_317 , V_318 ) ;
if ( V_319 >= F_30 (unsigned int, sk->sk_gso_max_size,
tp->xmit_size_goal_segs * tp->mss_cache) )
goto V_321;
if ( ( V_4 != F_168 ( V_2 ) ) && ( V_319 >= V_4 -> V_79 ) )
goto V_321;
V_320 = F_179 ( V_324 ) ;
if ( V_320 ) {
T_4 V_325 = F_20 ( V_8 -> V_326 , V_8 -> V_27 * V_8 -> V_295 ) ;
V_325 /= V_320 ;
if ( V_319 >= V_325 )
goto V_321;
} else {
if ( V_319 > F_180 ( V_8 ) * V_8 -> V_295 )
goto V_321;
}
if ( ! V_8 -> V_322 )
V_8 -> V_322 = 1 | ( V_323 << 1 ) ;
if ( V_318 < V_317 && V_318 < V_4 -> V_79 )
* V_303 = true ;
return true ;
V_321:
V_8 -> V_322 = 0 ;
return false ;
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_327 , * V_328 ;
int V_79 ;
int V_293 ;
int V_329 ;
int V_330 ;
int V_246 ;
if ( ! V_6 -> V_287 . V_288 ||
V_6 -> V_287 . V_293 ||
F_2 ( V_2 ) -> V_297 != V_298 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_169 || V_8 -> V_59 . V_124 )
return - 1 ;
V_246 = F_61 ( V_2 ) ;
V_293 = 2 * V_8 -> V_295 ;
V_329 = V_293 + ( V_8 -> V_331 + 1 ) * V_8 -> V_295 ;
if ( V_293 > F_154 ( V_2 , V_6 -> V_287 . V_290 ) ) {
return - 1 ;
}
if ( V_8 -> V_244 - V_8 -> V_11 < V_329 )
return - 1 ;
if ( V_8 -> V_326 < V_329 )
return - 1 ;
if ( F_111 ( V_8 -> V_11 + V_329 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_103 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_103 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_327 = F_135 ( V_2 , V_293 , V_178 ) ) == NULL )
return - 1 ;
V_2 -> V_245 += V_327 -> V_201 ;
F_119 ( V_2 , V_327 -> V_201 ) ;
V_4 = F_175 ( V_2 ) ;
F_5 ( V_327 ) -> V_80 = F_5 ( V_4 ) -> V_80 ;
F_5 ( V_327 ) -> V_12 = F_5 ( V_4 ) -> V_80 + V_293 ;
F_5 ( V_327 ) -> V_65 = V_233 ;
F_5 ( V_327 ) -> V_92 = 0 ;
V_327 -> V_91 = 0 ;
V_327 -> V_89 = V_4 -> V_89 ;
F_182 ( V_327 , V_4 , V_2 ) ;
V_79 = 0 ;
F_183 (skb, next, sk) {
V_330 = F_30 ( int , V_4 -> V_79 , V_293 - V_79 ) ;
if ( V_327 -> V_89 )
F_184 ( V_4 , 0 , F_137 ( V_327 , V_330 ) , V_330 ) ;
else
V_327 -> V_91 = F_185 ( V_4 , 0 ,
F_137 ( V_327 , V_330 ) ,
V_330 , V_327 -> V_91 ) ;
if ( V_4 -> V_79 <= V_330 ) {
F_5 ( V_327 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_186 ( V_4 , V_2 ) ;
F_187 ( V_2 , V_4 ) ;
} else {
F_5 ( V_327 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_95 | V_272 ) ;
if ( ! F_44 ( V_4 ) -> V_273 ) {
F_188 ( V_4 , V_330 ) ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_189 ( V_4 -> V_179 ,
V_4 -> V_79 , 0 ) ;
} else {
F_142 ( V_4 , V_330 ) ;
F_120 ( V_2 , V_4 , V_246 ) ;
}
F_5 ( V_4 ) -> V_80 += V_330 ;
}
V_79 += V_330 ;
if ( V_79 >= V_293 )
break;
}
F_170 ( V_2 , V_327 , V_327 -> V_79 ) ;
if ( ! F_96 ( V_2 , V_327 , 1 , V_178 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_327 ) ;
V_6 -> V_287 . V_293 = F_155 ( V_2 , V_327 -> V_79 ) ;
V_8 -> V_332 . V_333 = F_5 ( V_327 ) -> V_80 ;
V_8 -> V_332 . V_334 = F_5 ( V_327 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_60 ( struct V_1 * V_2 , unsigned int V_246 , int V_177 ,
int V_335 , T_10 V_265 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_313 , V_336 ;
int V_316 ;
int V_337 ;
bool V_303 = false ;
V_336 = 0 ;
if ( ! V_335 ) {
V_337 = F_181 ( V_2 ) ;
if ( ! V_337 ) {
return false ;
} else if ( V_337 > 0 ) {
V_336 = 1 ;
}
}
while ( ( V_4 = F_175 ( V_2 ) ) ) {
unsigned int V_319 ;
V_313 = F_170 ( V_2 , V_4 , V_246 ) ;
F_97 ( ! V_313 ) ;
if ( F_50 ( V_8 -> V_338 ) && V_8 -> V_339 == V_340 ) {
F_98 ( & V_4 -> V_215 ) ;
goto V_338;
}
V_316 = F_169 ( V_8 , V_4 ) ;
if ( ! V_316 ) {
V_303 = true ;
if ( V_335 == 2 )
V_316 = 1 ;
else
break;
}
if ( F_50 ( ! F_172 ( V_8 , V_4 , V_246 ) ) )
break;
if ( V_313 == 1 ) {
if ( F_50 ( ! F_171 ( V_8 , V_4 , V_246 ,
( F_176 ( V_2 , V_4 ) ?
V_177 : V_315 ) ) ) )
break;
} else {
if ( ! V_335 &&
F_178 ( V_2 , V_4 , & V_303 ) )
break;
}
V_319 = F_29 (unsigned int, sysctl_tcp_limit_output_bytes,
sk->sk_pacing_rate >> 10 ) ;
if ( F_190 ( & V_2 -> V_202 ) > V_319 ) {
F_72 ( V_205 , & V_8 -> V_189 ) ;
F_191 () ;
if ( F_190 ( & V_2 -> V_202 ) > V_319 )
break;
}
V_319 = V_246 ;
if ( V_313 > 1 && ! F_48 ( V_8 ) )
V_319 = F_167 ( V_2 , V_4 , V_246 ,
F_30 (unsigned int,
cwnd_quota,
sk->sk_gso_max_segs) ,
V_177 ) ;
if ( V_4 -> V_79 > V_319 &&
F_50 ( F_177 ( V_2 , V_4 , V_319 , V_246 , V_265 ) ) )
break;
if ( F_50 ( F_96 ( V_2 , V_4 , 1 , V_265 ) ) )
break;
V_338:
F_1 ( V_2 , V_4 ) ;
F_165 ( V_8 , V_246 , V_4 ) ;
V_336 += F_6 ( V_4 ) ;
if ( V_335 )
break;
}
if ( F_52 ( V_336 ) ) {
if ( F_192 ( V_2 ) )
V_8 -> V_341 += V_336 ;
if ( V_335 != 2 )
F_193 ( V_2 ) ;
F_162 ( V_2 , V_303 ) ;
return false ;
}
return ( V_335 == 2 ) || ( ! V_8 -> V_10 && F_175 ( V_2 ) ) ;
}
bool F_193 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_342 , V_343 , V_344 ;
T_4 V_345 = F_194 ( V_8 -> V_346 >> 3 ) ;
if ( F_132 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_132 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_171 == V_347 )
return false ;
if ( V_6 -> V_13 != V_348 )
return false ;
if ( V_349 < 3 || ! V_8 -> V_346 || ! V_8 -> V_10 ||
! F_195 ( V_8 ) || F_2 ( V_2 ) -> V_297 != V_298 )
return false ;
if ( ( V_8 -> V_27 > F_103 ( V_8 ) ) &&
F_175 ( V_2 ) )
return false ;
V_342 = V_345 << 1 ;
if ( V_8 -> V_10 == 1 )
V_342 = F_29 ( T_4 , V_342 ,
( V_345 + ( V_345 >> 1 ) + V_350 ) ) ;
V_342 = F_29 ( T_4 , V_342 , F_196 ( 10 ) ) ;
V_343 = V_23 + V_342 ;
V_344 = ( T_4 ) F_2 ( V_2 ) -> V_351 ;
if ( ( T_3 ) ( V_343 - V_344 ) > 0 ) {
T_3 V_22 = V_344 - V_23 ;
if ( V_22 > 0 )
V_342 = V_22 ;
}
F_197 ( V_2 , V_15 , V_342 ,
V_352 ) ;
return true ;
}
static bool F_198 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_50 ( F_199 ( V_2 , V_4 ) ) ) {
F_200 ( F_9 ( V_2 ) ,
V_353 ) ;
return true ;
}
return false ;
}
void F_201 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_354 ;
int V_19 = F_61 ( V_2 ) ;
int V_214 = - 1 ;
if ( F_175 ( V_2 ) != NULL ) {
V_214 = F_60 ( V_2 , V_19 , V_355 , 2 , V_178 ) ;
goto V_356;
}
if ( V_8 -> V_357 )
goto V_356;
V_4 = F_168 ( V_2 ) ;
if ( F_132 ( ! V_4 ) )
goto V_356;
if ( F_198 ( V_2 , V_4 ) )
goto V_356;
V_354 = F_6 ( V_4 ) ;
if ( F_132 ( ! V_354 ) )
goto V_356;
if ( ( V_354 > 1 ) && ( V_4 -> V_79 > ( V_354 - 1 ) * V_19 ) ) {
if ( F_50 ( F_131 ( V_2 , V_4 , ( V_354 - 1 ) * V_19 , V_19 ,
V_178 ) ) )
goto V_356;
V_4 = F_168 ( V_2 ) ;
}
if ( F_132 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_356;
V_214 = F_202 ( V_2 , V_4 ) ;
if ( F_52 ( ! V_214 ) )
V_8 -> V_357 = V_8 -> V_11 ;
V_356:
F_197 ( V_2 , V_348 ,
F_2 ( V_2 ) -> V_30 ,
V_352 ) ;
if ( F_52 ( ! V_214 ) )
F_200 ( F_9 ( V_2 ) ,
V_358 ) ;
}
void F_203 ( struct V_1 * V_2 , unsigned int V_314 ,
int V_177 )
{
if ( F_50 ( V_2 -> V_171 == V_359 ) )
return;
if ( F_60 ( V_2 , V_314 , V_177 , 0 ,
F_204 ( V_2 , V_178 ) ) )
F_205 ( V_2 ) ;
}
void F_206 ( struct V_1 * V_2 , unsigned int V_246 )
{
struct V_3 * V_4 = F_175 ( V_2 ) ;
F_97 ( ! V_4 || V_4 -> V_79 < V_246 ) ;
F_60 ( V_2 , V_246 , V_315 , 1 , V_2 -> V_360 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_361 ;
int V_362 = F_207 ( V_2 ) ;
int V_363 = F_208 ( V_2 ) ;
int V_364 = F_30 ( int , V_8 -> V_46 , V_363 ) ;
int V_226 ;
if ( V_19 > V_364 )
V_19 = V_364 ;
if ( V_362 < ( V_364 >> 1 ) ) {
V_6 -> V_35 . V_365 = 0 ;
if ( F_209 ( V_2 ) )
V_8 -> V_366 = F_20 ( V_8 -> V_366 ,
4U * V_8 -> V_20 ) ;
V_362 = F_210 ( V_362 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_362 < ( V_363 >> 4 ) || V_362 < V_19 )
return 0 ;
}
if ( V_362 > V_8 -> V_366 )
V_362 = V_8 -> V_366 ;
V_226 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_226 = V_362 ;
if ( ( ( V_226 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_226 )
V_226 = ( ( ( V_226 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_226 <= V_362 - V_19 || V_226 > V_362 )
V_226 = ( V_362 / V_19 ) * V_19 ;
else if ( V_19 == V_364 &&
V_362 > V_226 + ( V_364 >> 1 ) )
V_226 = V_362 ;
}
return V_226 ;
}
static void F_211 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_367 = F_212 ( V_2 , V_4 ) ;
int V_368 , V_369 ;
V_368 = V_4 -> V_79 ;
V_369 = V_367 -> V_79 ;
F_97 ( F_6 ( V_4 ) != 1 || F_6 ( V_367 ) != 1 ) ;
F_213 ( V_2 , V_367 , V_4 ) ;
F_186 ( V_367 , V_2 ) ;
F_214 ( V_367 , F_137 ( V_4 , V_369 ) ,
V_369 ) ;
if ( V_367 -> V_89 == V_90 )
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_89 != V_90 )
V_4 -> V_91 = F_215 ( V_4 -> V_91 , V_367 -> V_91 , V_368 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_367 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_367 ) -> V_65 ;
F_5 ( V_4 ) -> V_92 |= F_5 ( V_367 ) -> V_92 & V_370 ;
F_216 ( V_8 ) ;
if ( V_367 == V_8 -> V_371 )
V_8 -> V_371 = V_4 ;
F_126 ( V_2 , V_367 , F_6 ( V_367 ) ) ;
F_187 ( V_2 , V_367 ) ;
}
static bool F_217 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_44 ( V_4 ) -> V_273 != 0 )
return false ;
if ( F_99 ( V_4 ) )
return false ;
if ( V_4 == F_175 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_92 & V_252 )
return false ;
return true ;
}
static void F_218 ( struct V_1 * V_2 , struct V_3 * V_372 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_372 , * V_373 ;
bool V_374 = true ;
if ( ! V_375 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_94 )
return;
F_183 (skb, tmp, sk) {
if ( ! F_217 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_79 ;
if ( V_374 ) {
V_374 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_79 > F_219 ( V_372 ) )
break;
if ( F_111 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_211 ( V_2 , V_372 ) ;
}
}
int F_202 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_314 ;
int V_214 ;
if ( V_6 -> V_287 . V_293 ) {
V_6 -> V_287 . V_293 = 0 ;
}
if ( F_190 ( & V_2 -> V_202 ) >
F_20 ( V_2 -> V_245 + ( V_2 -> V_245 >> 2 ) , V_2 -> V_376 ) )
return - V_377 ;
if ( F_198 ( V_2 , V_4 ) )
return - V_378 ;
if ( F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_96 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_96 ) )
F_220 () ;
if ( F_148 ( V_2 , V_4 , V_8 -> V_96 - F_5 ( V_4 ) -> V_80 ) )
return - V_271 ;
}
if ( F_2 ( V_2 ) -> V_196 -> V_379 ( V_2 ) )
return - V_380 ;
V_314 = F_61 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_80 != V_8 -> V_96 )
return - V_377 ;
if ( V_4 -> V_79 > V_314 ) {
if ( F_131 ( V_2 , V_4 , V_314 , V_314 , V_178 ) )
return - V_271 ;
} else {
int V_381 = F_6 ( V_4 ) ;
if ( F_50 ( V_381 > 1 ) ) {
if ( F_134 ( V_4 , V_178 ) )
return - V_271 ;
F_170 ( V_2 , V_4 , V_314 ) ;
F_126 ( V_2 , V_4 , V_381 - F_6 ( V_4 ) ) ;
}
}
F_218 ( V_2 , V_4 , V_314 ) ;
if ( F_50 ( ( V_382 && ( ( unsigned long ) V_4 -> V_179 & 3 ) ) ||
F_221 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_327 = F_222 ( V_4 , V_383 ,
V_178 ) ;
V_214 = V_327 ? F_96 ( V_2 , V_327 , 0 , V_178 ) :
- V_216 ;
} else {
V_214 = F_96 ( V_2 , V_4 , 1 , V_178 ) ;
}
if ( F_52 ( ! V_214 ) ) {
F_5 ( V_4 ) -> V_92 |= V_370 ;
F_223 ( F_9 ( V_2 ) , V_384 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_94 )
F_200 ( F_9 ( V_2 ) , V_385 ) ;
V_8 -> V_386 ++ ;
}
return V_214 ;
}
int F_224 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_214 = F_202 ( V_2 , V_4 ) ;
if ( V_214 == 0 ) {
#if V_387 > 0
if ( F_5 ( V_4 ) -> V_92 & V_253 ) {
F_225 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_254 )
V_8 -> V_388 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_92 |= V_389 ;
V_8 -> V_254 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_390 )
V_8 -> V_390 = F_55 ( V_4 ) ;
F_5 ( V_4 ) -> V_224 = V_8 -> V_11 ;
} else if ( V_214 != - V_378 ) {
F_200 ( F_9 ( V_2 ) , V_391 ) ;
}
if ( V_8 -> V_392 < 0 )
V_8 -> V_392 = 0 ;
V_8 -> V_392 += F_6 ( V_4 ) ;
return V_214 ;
}
static bool F_226 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_297 != V_393 )
return false ;
if ( F_124 ( V_8 ) )
return false ;
if ( F_174 ( V_2 ) )
return false ;
return true ;
}
void F_227 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_394 = NULL ;
T_4 V_395 ;
int V_396 ;
int V_397 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_256 )
V_8 -> V_398 = V_8 -> V_96 ;
if ( V_8 -> V_371 ) {
V_4 = V_8 -> V_371 ;
V_395 = F_5 ( V_4 ) -> V_12 ;
if ( F_111 ( V_395 , V_8 -> V_398 ) )
V_395 = V_8 -> V_398 ;
} else {
V_4 = F_228 ( V_2 ) ;
V_395 = V_8 -> V_96 ;
}
F_229 (skb, sk) {
T_5 V_92 = F_5 ( V_4 ) -> V_92 ;
if ( V_4 == F_175 ( V_2 ) )
break;
if ( V_394 == NULL )
V_8 -> V_371 = V_4 ;
if ( F_103 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_397 ) {
V_399:
if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , F_125 ( V_8 ) ) )
break;
V_396 = V_400 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_80 , V_8 -> V_398 ) ) {
V_8 -> V_398 = V_395 ;
if ( ! F_226 ( V_2 ) )
break;
if ( V_394 != NULL ) {
V_4 = V_394 ;
V_394 = NULL ;
}
V_397 = 1 ;
goto V_399;
} else if ( ! ( V_92 & V_255 ) ) {
if ( V_394 == NULL && ! ( V_92 & ( V_253 | V_252 ) ) )
V_394 = V_4 ;
continue;
} else {
V_395 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_297 != V_401 )
V_396 = V_402 ;
else
V_396 = V_403 ;
}
if ( V_92 & ( V_252 | V_253 ) )
continue;
if ( F_224 ( V_2 , V_4 ) )
return;
F_200 ( F_9 ( V_2 ) , V_396 ) ;
if ( F_192 ( V_2 ) )
V_8 -> V_341 += F_6 ( V_4 ) ;
if ( V_4 == F_228 ( V_2 ) )
F_197 ( V_2 , V_348 ,
F_2 ( V_2 ) -> V_30 ,
V_352 ) ;
}
}
void F_230 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_168 ( V_2 ) ;
int V_246 ;
V_246 = F_61 ( V_2 ) ;
if ( F_175 ( V_2 ) != NULL ) {
F_5 ( V_4 ) -> V_65 |= V_95 ;
F_5 ( V_4 ) -> V_12 ++ ;
V_8 -> V_244 ++ ;
} else {
for (; ; ) {
V_4 = F_231 ( V_383 ,
V_2 -> V_360 ) ;
if ( V_4 )
break;
F_232 () ;
}
F_233 ( V_4 , V_383 ) ;
F_46 ( V_4 , V_8 -> V_244 ,
V_233 | V_95 ) ;
F_116 ( V_2 , V_4 ) ;
}
F_203 ( V_2 , V_246 , V_355 ) ;
}
void F_234 ( struct V_1 * V_2 , T_10 V_404 )
{
struct V_3 * V_4 ;
V_4 = F_235 ( V_383 , V_404 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_405 ) ;
return;
}
F_233 ( V_4 , V_383 ) ;
F_46 ( V_4 , F_10 ( V_2 ) ,
V_233 | V_406 ) ;
if ( F_96 ( V_2 , V_4 , 0 , V_404 ) )
F_34 ( F_9 ( V_2 ) , V_405 ) ;
F_223 ( F_9 ( V_2 ) , V_407 ) ;
}
int F_236 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_228 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_5 ( V_4 ) -> V_65 & V_94 ) ) {
F_237 ( L_2 , V_408 ) ;
return - V_409 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_233 ) ) {
if ( F_99 ( V_4 ) ) {
struct V_3 * V_327 = F_238 ( V_4 , V_178 ) ;
if ( V_327 == NULL )
return - V_271 ;
F_186 ( V_4 , V_2 ) ;
F_117 ( V_327 ) ;
F_239 ( V_2 , V_327 ) ;
F_187 ( V_2 , V_4 ) ;
V_2 -> V_245 += V_327 -> V_201 ;
F_119 ( V_2 , V_327 -> V_201 ) ;
V_4 = V_327 ;
}
F_5 ( V_4 ) -> V_65 |= V_233 ;
F_36 ( V_2 , V_4 ) ;
}
return F_96 ( V_2 , V_4 , 1 , V_178 ) ;
}
struct V_3 * F_240 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_72 * V_73 ,
struct V_133 * V_134 )
{
struct V_99 V_100 ;
struct V_163 * V_164 = F_41 ( V_73 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_74 * V_75 ;
struct V_3 * V_4 ;
struct V_141 * V_142 ;
int V_213 ;
int V_19 ;
V_4 = F_241 ( V_2 , V_383 , 1 , V_178 ) ;
if ( F_50 ( ! V_4 ) ) {
F_242 ( V_18 ) ;
return NULL ;
}
F_233 ( V_4 , V_383 ) ;
F_243 ( V_4 , V_18 ) ;
F_244 ( V_4 , V_2 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_410 && V_8 -> V_59 . V_410 < V_19 )
V_19 = V_8 -> V_59 . V_410 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
#ifdef F_245
if ( F_50 ( V_73 -> V_411 ) )
V_4 -> V_215 . V_412 = F_246 ( V_73 ) ;
else
#endif
F_98 ( & V_4 -> V_215 ) ;
V_213 = F_56 ( V_2 , V_73 , V_19 , V_4 , & V_100 , & V_142 ,
V_134 ) + sizeof( * V_75 ) ;
F_105 ( V_4 , V_213 ) ;
F_106 ( V_4 ) ;
V_75 = F_43 ( V_4 ) ;
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 -> V_413 = 1 ;
V_75 -> V_414 = 1 ;
F_40 ( V_73 , V_75 , V_2 ) ;
V_75 -> V_220 = F_110 ( V_164 -> V_415 ) ;
V_75 -> V_222 = V_164 -> V_416 ;
F_46 ( V_4 , F_57 ( V_73 ) -> V_417 ,
V_94 | V_233 ) ;
V_75 -> V_80 = F_51 ( F_5 ( V_4 ) -> V_80 ) ;
V_75 -> V_224 = F_51 ( F_57 ( V_73 ) -> V_61 ) ;
V_75 -> V_226 = F_110 ( F_20 ( V_73 -> V_45 , 65535U ) ) ;
F_49 ( ( T_8 * ) ( V_75 + 1 ) , V_8 , & V_100 ) ;
V_75 -> V_418 = ( V_213 >> 2 ) ;
F_247 ( F_9 ( V_2 ) , V_234 ) ;
#ifdef F_54
if ( V_142 ) {
F_57 ( V_73 ) -> V_148 -> V_231 ( V_100 . V_106 ,
V_142 , NULL , V_73 , V_4 ) ;
}
#endif
return V_4 ;
}
static void F_248 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_48 ;
V_8 -> V_78 = sizeof( struct V_74 ) +
( V_152 ? V_155 : 0 ) ;
#ifdef F_54
if ( V_8 -> V_148 -> V_149 ( V_2 , V_2 ) != NULL )
V_8 -> V_78 += V_150 ;
#endif
if ( V_8 -> V_59 . V_410 )
V_8 -> V_59 . V_284 = V_8 -> V_59 . V_410 ;
V_8 -> V_419 = 0 ;
F_156 ( V_2 ) ;
F_157 ( V_2 , F_159 ( V_18 ) ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_420 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_410 && V_8 -> V_59 . V_410 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_410 ;
F_249 ( V_2 ) ;
if ( V_2 -> V_421 & V_422 &&
( V_8 -> V_46 > F_208 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_208 ( V_2 ) ;
F_28 ( F_208 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_423 ? V_8 -> V_78 - sizeof( struct V_74 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_156 ,
& V_48 ,
F_23 ( V_18 , V_424 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_366 = V_8 -> V_45 ;
V_2 -> V_425 = 0 ;
F_250 ( V_2 , V_426 ) ;
V_8 -> V_326 = 0 ;
F_251 ( V_8 , 0 ) ;
V_8 -> V_96 = V_8 -> V_244 ;
V_8 -> V_306 = V_8 -> V_244 ;
V_8 -> V_97 = V_8 -> V_244 ;
V_8 -> V_11 = V_8 -> V_244 ;
if ( F_52 ( ! V_8 -> V_338 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_427 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_428 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_429 ;
F_2 ( V_2 ) -> V_430 = 0 ;
F_252 ( V_8 ) ;
}
static void F_253 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_210 * V_211 = F_5 ( V_4 ) ;
V_211 -> V_12 += V_4 -> V_79 ;
F_117 ( V_4 ) ;
F_254 ( V_2 , V_4 ) ;
V_2 -> V_245 += V_4 -> V_201 ;
F_119 ( V_2 , V_4 -> V_201 ) ;
V_8 -> V_244 = V_211 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_255 ( struct V_1 * V_2 , struct V_3 * V_413 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_145 * V_431 = V_8 -> V_147 ;
int V_432 = 0 , V_50 , V_198 , V_214 = 0 , V_433 = V_431 -> V_179 -> V_434 ;
struct V_3 * V_435 = NULL , * V_179 ;
unsigned long V_436 = 0 ;
V_8 -> V_59 . V_284 = V_8 -> V_20 ;
F_256 ( V_2 , & V_8 -> V_59 . V_284 , & V_431 -> V_160 ,
& V_432 , & V_436 ) ;
if ( V_432 > 1 &&
F_257 ( V_323 , V_436 + ( 60 * V_437 << V_432 ) ) ) {
V_431 -> V_160 . V_79 = - 1 ;
goto V_438;
}
if ( V_439 & V_440 )
V_431 -> V_160 . V_79 = - 1 ;
else if ( V_431 -> V_160 . V_79 <= 0 )
goto V_438;
if ( V_8 -> V_59 . V_410 && V_8 -> V_59 . V_410 < V_8 -> V_59 . V_284 )
V_8 -> V_59 . V_284 = V_8 -> V_59 . V_410 ;
V_50 = F_152 ( V_2 , F_2 ( V_2 ) -> V_294 ) -
V_144 ;
V_50 = F_30 ( V_441 , V_50 , V_431 -> V_167 ) ;
V_50 = F_30 ( V_441 , V_50 , F_258 ( V_383 ) ) ;
V_435 = F_259 ( V_413 , V_383 , V_50 ,
V_2 -> V_360 ) ;
if ( V_435 == NULL )
goto V_438;
for ( V_198 = 0 ; V_198 < V_433 && V_435 -> V_79 < V_50 ; ++ V_198 ) {
struct V_442 * V_443 = & V_431 -> V_179 -> V_444 [ V_198 ] ;
unsigned char T_11 * V_445 = V_443 -> V_446 ;
int V_79 = V_443 -> V_447 ;
if ( V_435 -> V_79 + V_79 > V_50 )
V_79 = V_50 - V_435 -> V_79 ;
else if ( V_198 + 1 == V_433 )
V_431 -> V_179 = NULL ;
if ( F_260 ( V_435 , V_445 , V_79 ) )
goto V_438;
}
V_179 = F_100 ( V_435 , V_2 -> V_360 ) ;
if ( V_179 == NULL )
goto V_438;
F_5 ( V_179 ) -> V_80 ++ ;
F_5 ( V_179 ) -> V_65 &= ~ V_94 ;
F_5 ( V_179 ) -> V_65 = ( V_233 | V_272 ) ;
F_253 ( V_2 , V_179 ) ;
V_431 -> V_448 = V_179 -> V_79 ;
F_98 ( & V_413 -> V_215 ) ;
V_179 -> V_215 = V_413 -> V_215 ;
if ( F_96 ( V_2 , V_435 , 0 , V_2 -> V_360 ) == 0 ) {
V_8 -> V_435 = ( V_431 -> V_448 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_449;
}
V_435 = NULL ;
V_438:
if ( V_431 -> V_160 . V_79 > 0 )
V_431 -> V_160 . V_79 = 0 ;
V_214 = F_96 ( V_2 , V_413 , 1 , V_2 -> V_360 ) ;
if ( V_214 )
V_8 -> V_162 = 0 ;
F_261 ( V_435 ) ;
V_449:
V_431 -> V_160 . V_79 = - 1 ;
return V_214 ;
}
int F_262 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_266 ;
int V_214 ;
F_248 ( V_2 ) ;
if ( F_50 ( V_8 -> V_338 ) ) {
F_263 ( V_2 , NULL ) ;
return 0 ;
}
V_266 = F_231 ( V_383 + 15 , V_2 -> V_360 ) ;
if ( F_50 ( V_266 == NULL ) )
return - V_216 ;
F_233 ( V_266 , V_383 ) ;
F_46 ( V_266 , V_8 -> V_244 ++ , V_94 ) ;
V_8 -> V_390 = V_23 ;
F_253 ( V_2 , V_266 ) ;
F_39 ( V_2 , V_266 ) ;
V_214 = V_8 -> V_147 ? F_255 ( V_2 , V_266 ) :
F_96 ( V_2 , V_266 , 1 , V_2 -> V_360 ) ;
if ( V_214 == - V_450 )
return V_214 ;
V_8 -> V_11 = V_8 -> V_244 ;
V_8 -> V_451 = V_8 -> V_244 ;
F_223 ( F_9 ( V_2 ) , V_452 ) ;
F_197 ( V_2 , V_348 ,
F_2 ( V_2 ) -> V_30 , V_352 ) ;
return 0 ;
}
void F_264 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_342 ;
F_18 ( V_2 , V_453 ) ;
if ( V_37 > V_454 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_455 = V_437 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_456 & V_457 ) )
V_455 = V_350 ;
if ( V_8 -> V_346 ) {
int V_345 = F_29 ( int , F_194 ( V_8 -> V_346 >> 3 ) ,
V_454 ) ;
if ( V_345 < V_455 )
V_455 = V_345 ;
}
V_37 = F_20 ( V_37 , V_455 ) ;
}
V_342 = V_323 + V_37 ;
if ( V_6 -> V_35 . V_456 & V_458 ) {
if ( V_6 -> V_35 . V_459 ||
F_265 ( V_6 -> V_35 . V_342 , V_323 + ( V_37 >> 2 ) ) ) {
F_266 ( V_2 ) ;
return;
}
if ( ! F_257 ( V_342 , V_6 -> V_35 . V_342 ) )
V_342 = V_6 -> V_35 . V_342 ;
}
V_6 -> V_35 . V_456 |= V_460 | V_458 ;
V_6 -> V_35 . V_342 = V_342 ;
F_267 ( V_2 , & V_6 -> V_461 , V_342 ) ;
}
void F_266 ( struct V_1 * V_2 )
{
struct V_3 * V_266 ;
if ( V_2 -> V_171 == V_359 )
return;
F_18 ( V_2 , V_462 ) ;
V_266 = F_235 ( V_383 , F_204 ( V_2 , V_178 ) ) ;
if ( V_266 == NULL ) {
F_268 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_463 ;
F_197 ( V_2 , V_41 ,
V_350 , V_352 ) ;
return;
}
F_233 ( V_266 , V_383 ) ;
F_46 ( V_266 , F_10 ( V_2 ) , V_233 ) ;
F_98 ( & V_266 -> V_215 ) ;
F_96 ( V_2 , V_266 , 0 , F_204 ( V_2 , V_178 ) ) ;
}
static int F_269 ( struct V_1 * V_2 , int V_464 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_235 ( V_383 , F_204 ( V_2 , V_178 ) ) ;
if ( V_4 == NULL )
return - 1 ;
F_233 ( V_4 , V_383 ) ;
F_46 ( V_4 , V_8 -> V_96 - ! V_464 , V_233 ) ;
F_98 ( & V_4 -> V_215 ) ;
return F_96 ( V_2 , V_4 , 0 , V_178 ) ;
}
void F_270 ( struct V_1 * V_2 )
{
if ( V_2 -> V_171 == V_465 ) {
F_3 ( V_2 ) -> V_466 = F_3 ( V_2 ) -> V_61 - 1 ;
F_269 ( V_2 , 0 ) ;
}
}
int F_271 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_171 == V_359 )
return - 1 ;
if ( ( V_4 = F_175 ( V_2 ) ) != NULL &&
F_11 ( F_5 ( V_4 ) -> V_80 , F_12 ( V_8 ) ) ) {
int V_214 ;
unsigned int V_19 = F_61 ( V_2 ) ;
unsigned int V_467 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_80 ;
if ( F_11 ( V_8 -> V_451 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_451 = F_5 ( V_4 ) -> V_12 ;
if ( V_467 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_80 ||
V_4 -> V_79 > V_19 ) {
V_467 = F_20 ( V_467 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_272 ;
if ( F_131 ( V_2 , V_4 , V_467 , V_19 , V_178 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_120 ( V_2 , V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_272 ;
V_214 = F_96 ( V_2 , V_4 , 1 , V_178 ) ;
if ( ! V_214 )
F_1 ( V_2 , V_4 ) ;
return V_214 ;
} else {
if ( F_272 ( V_8 -> V_97 , V_8 -> V_96 + 1 , V_8 -> V_96 + 0xFFFF ) )
F_269 ( V_2 , 1 ) ;
return F_269 ( V_2 , 0 ) ;
}
}
void F_273 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_468 ;
int V_214 ;
V_214 = F_271 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_175 ( V_2 ) ) {
V_6 -> V_469 = 0 ;
V_6 -> V_470 = 0 ;
return;
}
if ( V_214 <= 0 ) {
if ( V_6 -> V_470 < V_471 )
V_6 -> V_470 ++ ;
V_6 -> V_469 ++ ;
V_468 = V_352 ;
} else {
if ( ! V_6 -> V_469 )
V_6 -> V_469 = 1 ;
V_468 = V_472 ;
}
F_197 ( V_2 , V_473 ,
F_274 ( V_6 , V_468 ) ,
V_352 ) ;
}
int F_275 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
const struct V_474 * V_475 = F_57 ( V_73 ) -> V_148 ;
struct V_476 V_243 ;
int V_477 ;
V_477 = V_475 -> V_478 ( V_2 , NULL , & V_243 , V_73 , 0 , NULL ) ;
if ( ! V_477 ) {
F_247 ( F_9 ( V_2 ) , V_384 ) ;
F_200 ( F_9 ( V_2 ) , V_385 ) ;
}
return V_477 ;
}
