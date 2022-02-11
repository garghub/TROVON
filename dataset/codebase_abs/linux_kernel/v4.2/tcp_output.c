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
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_9 ( V_2 ) -> V_71 . V_74 )
F_5 ( V_4 ) -> V_65 &= ~ ( V_69 | V_66 ) ;
}
static void
F_42 ( const struct V_75 * V_76 , struct V_77 * V_78 ,
struct V_1 * V_2 )
{
if ( F_43 ( V_76 ) -> V_79 ) {
V_78 -> V_80 = 1 ;
if ( F_37 ( V_2 ) )
F_38 ( V_2 ) ;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_81 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_67 & V_68 ) {
if ( V_4 -> V_82 != V_81 &&
! F_11 ( F_5 ( V_4 ) -> V_83 , V_8 -> V_11 ) ) {
F_38 ( V_2 ) ;
if ( V_8 -> V_67 & V_84 ) {
V_8 -> V_67 &= ~ V_84 ;
F_45 ( V_4 ) -> V_85 = 1 ;
F_46 ( V_4 ) -> V_86 |= V_87 ;
}
} else if ( ! F_37 ( V_2 ) ) {
F_47 ( V_2 ) ;
}
if ( V_8 -> V_67 & V_88 )
F_45 ( V_4 ) -> V_80 = 1 ;
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
if ( F_52 ( V_100 -> V_19 ) ) {
* V_98 ++ = F_53 ( ( V_107 << 24 ) |
( V_108 << 16 ) |
V_100 -> V_19 ) ;
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
struct V_122 * V_123 = V_8 -> V_59 . V_124 ?
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
V_8 -> V_59 . V_124 = 0 ;
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
V_100 -> V_19 = F_13 ( V_2 ) ;
V_145 -= V_153 ;
if ( F_54 ( V_154 && ! * V_144 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = F_57 ( V_4 ) + V_8 -> V_155 ;
V_100 -> V_116 = V_8 -> V_59 . V_156 ;
V_145 -= V_157 ;
}
if ( F_54 ( V_158 ) ) {
V_100 -> V_120 = V_8 -> V_59 . V_48 ;
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
static unsigned int F_58 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
unsigned int V_19 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
const struct V_143 * V_144 ,
struct V_133 * V_134 )
{
struct V_166 * V_167 = F_43 ( V_76 ) ;
unsigned int V_145 = V_146 ;
#ifdef F_56
if ( V_144 ) {
V_100 -> V_101 |= V_102 ;
V_145 -= V_152 ;
V_167 -> V_168 &= ! V_167 -> V_169 ;
}
#endif
V_100 -> V_19 = V_19 ;
V_145 -= V_153 ;
if ( F_54 ( V_167 -> V_47 ) ) {
V_100 -> V_120 = V_167 -> V_48 ;
V_100 -> V_101 |= V_117 ;
V_145 -= V_159 ;
}
if ( F_54 ( V_167 -> V_168 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = F_57 ( V_4 ) ;
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
static unsigned int F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_99 * V_100 ,
struct V_143 * * V_144 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_170 = 0 ;
unsigned int V_171 ;
V_100 -> V_101 = 0 ;
#ifdef F_56
* V_144 = V_8 -> V_150 -> V_151 ( V_2 , V_2 ) ;
if ( F_52 ( * V_144 ) ) {
V_100 -> V_101 |= V_102 ;
V_170 += V_152 ;
}
#else
* V_144 = NULL ;
#endif
if ( F_54 ( V_8 -> V_59 . V_168 ) ) {
V_100 -> V_101 |= V_109 ;
V_100 -> V_115 = V_4 ? F_57 ( V_4 ) + V_8 -> V_155 : 0 ;
V_100 -> V_116 = V_8 -> V_59 . V_156 ;
V_170 += V_157 ;
}
V_171 = V_8 -> V_59 . V_172 + V_8 -> V_59 . V_124 ;
if ( F_52 ( V_171 ) ) {
const unsigned int V_145 = V_146 - V_170 ;
V_100 -> V_121 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_170 += V_173 +
V_100 -> V_121 * V_130 ;
}
return V_170 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_174 ) &
( V_175 | V_176 | V_177 |
V_178 | V_179 ) )
F_61 ( V_2 , F_62 ( V_2 ) , F_3 ( V_2 ) -> V_180 ,
0 , V_181 ) ;
}
static void F_63 ( unsigned long V_182 )
{
struct V_183 * V_184 = (struct V_183 * ) V_182 ;
F_64 ( V_185 ) ;
unsigned long V_89 ;
struct V_186 * V_187 , * V_188 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_65 ( V_89 ) ;
F_66 ( & V_184 -> V_189 , & V_185 ) ;
F_67 ( V_89 ) ;
F_68 (q, n, &list) {
V_8 = F_69 ( V_187 , struct V_7 , V_190 ) ;
F_70 ( & V_8 -> V_190 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_71 ( V_2 ) ;
if ( ! F_72 ( V_2 ) ) {
F_60 ( V_2 ) ;
} else {
F_73 ( V_191 , & V_8 -> V_192 ) ;
}
F_74 ( V_2 ) ;
F_75 ( V_193 , & V_8 -> V_192 ) ;
F_76 ( V_2 ) ;
}
}
void F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_89 , V_194 ;
do {
V_89 = V_8 -> V_192 ;
if ( ! ( V_89 & V_195 ) )
return;
V_194 = V_89 & ~ V_195 ;
} while ( F_78 ( & V_8 -> V_192 , V_89 , V_194 ) != V_89 );
if ( V_89 & ( 1UL << V_191 ) )
F_60 ( V_2 ) ;
F_79 ( V_2 ) ;
if ( V_89 & ( 1UL << V_196 ) ) {
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
}
if ( V_89 & ( 1UL << V_197 ) ) {
F_82 ( V_2 ) ;
F_81 ( V_2 ) ;
}
if ( V_89 & ( 1UL << V_198 ) ) {
F_2 ( V_2 ) -> V_199 -> V_200 ( V_2 ) ;
F_81 ( V_2 ) ;
}
}
void T_9 F_83 ( void )
{
int V_201 ;
F_84 (i) {
struct V_183 * V_184 = & F_85 ( V_183 , V_201 ) ;
F_86 ( & V_184 -> V_189 ) ;
F_87 ( & V_184 -> V_202 ,
F_63 ,
( unsigned long ) V_184 ) ;
}
}
void F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_203 ;
V_203 = F_89 ( V_4 -> V_204 - 1 , & V_2 -> V_205 ) ;
if ( V_203 >= F_90 ( 1 ) && F_91 () == V_206 )
goto V_207;
if ( F_92 ( V_208 , & V_8 -> V_192 ) &&
! F_93 ( V_193 , & V_8 -> V_192 ) ) {
unsigned long V_89 ;
struct V_183 * V_184 ;
F_65 ( V_89 ) ;
V_184 = F_94 ( & V_183 ) ;
F_95 ( & V_8 -> V_190 , & V_184 -> V_189 ) ;
F_96 ( & V_184 -> V_202 ) ;
F_67 ( V_89 ) ;
return;
}
V_207:
F_76 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_209 ,
T_10 V_210 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_211 * V_212 ;
struct V_7 * V_8 ;
struct V_213 * V_214 ;
struct V_99 V_100 ;
unsigned int V_215 , V_216 ;
struct V_143 * V_144 ;
struct V_77 * V_78 ;
int V_217 ;
F_98 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_209 ) {
F_99 ( & V_4 -> V_218 ) ;
if ( F_52 ( F_100 ( V_4 ) ) )
V_4 = F_101 ( V_4 , V_210 ) ;
else
V_4 = F_102 ( V_4 , V_210 ) ;
if ( F_52 ( ! V_4 ) )
return - V_219 ;
}
V_212 = F_103 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_214 = F_5 ( V_4 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
if ( F_52 ( V_214 -> V_65 & V_94 ) )
V_215 = F_55 ( V_2 , V_4 , & V_100 , & V_144 ) ;
else
V_215 = F_59 ( V_2 , V_4 , & V_100 ,
& V_144 ) ;
V_216 = V_215 + sizeof( struct V_77 ) ;
if ( F_104 ( V_8 ) == 0 )
F_18 ( V_2 , V_220 ) ;
V_4 -> V_221 = F_105 ( V_2 ) < F_90 ( 1 ) ;
F_106 ( V_4 , V_216 ) ;
F_107 ( V_4 ) ;
F_108 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_222 = F_109 ( V_4 ) ? V_223 : F_88 ;
F_110 ( V_4 , V_2 ) ;
F_111 ( V_4 -> V_204 , & V_2 -> V_205 ) ;
V_78 = F_45 ( V_4 ) ;
V_78 -> V_224 = V_212 -> V_225 ;
V_78 -> V_226 = V_212 -> V_227 ;
V_78 -> V_83 = F_53 ( V_214 -> V_83 ) ;
V_78 -> V_228 = F_53 ( V_8 -> V_61 ) ;
* ( ( ( V_229 * ) V_78 ) + 6 ) = F_112 ( ( ( V_216 >> 2 ) << 12 ) |
V_214 -> V_65 ) ;
if ( F_52 ( V_214 -> V_65 & V_94 ) ) {
V_78 -> V_230 = F_112 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_78 -> V_230 = F_112 ( F_31 ( V_2 ) ) ;
}
V_78 -> V_231 = 0 ;
V_78 -> V_232 = 0 ;
if ( F_52 ( F_50 ( V_8 ) && F_11 ( V_214 -> V_83 , V_8 -> V_97 ) ) ) {
if ( F_11 ( V_8 -> V_97 , V_214 -> V_83 + 0x10000 ) ) {
V_78 -> V_232 = F_112 ( V_8 -> V_97 - V_214 -> V_83 ) ;
V_78 -> V_233 = 1 ;
} else if ( F_113 ( V_214 -> V_83 + 0xFFFF , V_8 -> V_11 ) ) {
V_78 -> V_232 = F_112 ( 0xFFFF ) ;
V_78 -> V_233 = 1 ;
}
}
F_51 ( ( T_8 * ) ( V_78 + 1 ) , V_8 , & V_100 ) ;
F_46 ( V_4 ) -> V_86 = V_2 -> V_234 ;
if ( F_54 ( ( V_214 -> V_65 & V_94 ) == 0 ) )
F_44 ( V_2 , V_4 , V_216 ) ;
#ifdef F_56
if ( V_144 ) {
F_114 ( V_2 , V_235 ) ;
V_8 -> V_150 -> V_236 ( V_100 . V_106 ,
V_144 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_199 -> V_237 ( V_2 , V_4 ) ;
if ( F_54 ( V_214 -> V_65 & V_238 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_82 != V_216 )
F_22 ( V_8 , V_2 ) ;
if ( F_113 ( V_214 -> V_12 , V_8 -> V_11 ) || V_214 -> V_83 == V_214 -> V_12 )
F_115 ( F_9 ( V_2 ) , V_239 ,
F_6 ( V_4 ) ) ;
V_8 -> V_240 += F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_241 = F_6 ( V_4 ) ;
F_46 ( V_4 ) -> V_242 = F_116 ( V_4 ) ;
V_4 -> V_243 . V_244 = 0 ;
memset ( V_4 -> V_245 , 0 , F_21 ( sizeof( struct V_246 ) ,
sizeof( struct V_247 ) ) ) ;
V_217 = V_6 -> V_199 -> V_248 ( V_2 , V_4 , & V_212 -> V_249 . V_250 ) ;
if ( F_54 ( V_217 <= 0 ) )
return V_217 ;
F_117 ( V_2 ) ;
return F_118 ( V_217 ) ;
}
static void F_119 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_251 = F_5 ( V_4 ) -> V_12 ;
F_120 ( V_4 ) ;
F_121 ( V_2 , V_4 ) ;
V_2 -> V_252 += V_4 -> V_204 ;
F_122 ( V_2 , V_4 -> V_204 ) ;
}
static void F_123 ( struct V_3 * V_4 , unsigned int V_253 )
{
if ( V_4 -> V_82 <= V_253 || V_4 -> V_90 == V_254 ) {
F_49 ( V_4 , 1 ) ;
F_5 ( V_4 ) -> V_255 = 0 ;
} else {
F_49 ( V_4 , F_124 ( V_4 -> V_82 , V_253 ) ) ;
F_5 ( V_4 ) -> V_255 = V_253 ;
}
}
static void F_125 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_256 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! V_8 -> V_257 || F_126 ( V_8 ) )
return;
if ( F_113 ( F_127 ( V_8 ) , F_5 ( V_4 ) -> V_83 ) )
V_8 -> V_258 -= V_256 ;
}
static void F_128 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_256 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_10 -= V_256 ;
if ( F_5 ( V_4 ) -> V_93 & V_259 )
V_8 -> V_257 -= V_256 ;
if ( F_5 ( V_4 ) -> V_93 & V_260 )
V_8 -> V_261 -= V_256 ;
if ( F_5 ( V_4 ) -> V_93 & V_262 )
V_8 -> V_263 -= V_256 ;
if ( F_126 ( V_8 ) && V_256 > 0 )
V_8 -> V_257 -= F_30 ( T_4 , V_8 -> V_257 , V_256 ) ;
F_125 ( V_2 , V_4 , V_256 ) ;
if ( V_8 -> V_264 &&
F_11 ( F_5 ( V_4 ) -> V_83 , F_5 ( V_8 -> V_264 ) -> V_83 ) &&
( F_129 ( V_8 ) || ( F_5 ( V_4 ) -> V_93 & V_259 ) ) )
V_8 -> V_265 -= V_256 ;
F_130 ( V_8 ) ;
}
static void F_131 ( struct V_3 * V_4 , struct V_3 * V_266 )
{
struct V_267 * V_268 = F_46 ( V_4 ) ;
if ( F_52 ( V_268 -> V_269 & V_270 ) &&
! F_11 ( V_268 -> V_271 , F_5 ( V_266 ) -> V_83 ) ) {
struct V_267 * V_272 = F_46 ( V_266 ) ;
T_7 V_273 = V_268 -> V_269 & V_270 ;
V_268 -> V_269 &= ~ V_273 ;
V_272 -> V_269 |= V_273 ;
F_132 ( V_268 -> V_271 , V_272 -> V_271 ) ;
}
}
int F_133 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_82 ,
unsigned int V_253 , T_10 V_274 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_275 ;
int V_276 , V_277 ;
int V_278 ;
T_7 V_89 ;
if ( F_134 ( V_82 > V_4 -> V_82 ) )
return - V_279 ;
V_276 = F_135 ( V_4 ) - V_82 ;
if ( V_276 < 0 )
V_276 = 0 ;
if ( F_136 ( V_4 , V_274 ) )
return - V_280 ;
V_275 = F_137 ( V_2 , V_276 , V_274 , true ) ;
if ( ! V_275 )
return - V_280 ;
V_2 -> V_252 += V_275 -> V_204 ;
F_122 ( V_2 , V_275 -> V_204 ) ;
V_278 = V_4 -> V_82 - V_82 - V_276 ;
V_275 -> V_204 += V_278 ;
V_4 -> V_204 -= V_278 ;
F_5 ( V_275 ) -> V_83 = F_5 ( V_4 ) -> V_83 + V_82 ;
F_5 ( V_275 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_275 ) -> V_83 ;
V_89 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_89 & ~ ( V_95 | V_281 ) ;
F_5 ( V_275 ) -> V_65 = V_89 ;
F_5 ( V_275 ) -> V_93 = F_5 ( V_4 ) -> V_93 ;
if ( ! F_46 ( V_4 ) -> V_282 && V_4 -> V_90 != V_91 ) {
V_275 -> V_92 = F_138 ( V_4 -> V_182 + V_82 ,
F_139 ( V_275 , V_276 ) ,
V_276 , 0 ) ;
F_140 ( V_4 , V_82 ) ;
V_4 -> V_92 = F_141 ( V_4 -> V_92 , V_275 -> V_92 , V_82 ) ;
} else {
V_4 -> V_90 = V_91 ;
F_142 ( V_4 , V_275 , V_82 ) ;
}
V_275 -> V_90 = V_4 -> V_90 ;
V_275 -> V_243 = V_4 -> V_243 ;
F_131 ( V_4 , V_275 ) ;
V_277 = F_6 ( V_4 ) ;
F_123 ( V_4 , V_253 ) ;
F_123 ( V_275 , V_253 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_275 ) -> V_12 ) ) {
int V_283 = V_277 - F_6 ( V_4 ) -
F_6 ( V_275 ) ;
if ( V_283 )
F_128 ( V_2 , V_4 , V_283 ) ;
}
F_120 ( V_275 ) ;
F_143 ( V_4 , V_275 , V_2 ) ;
return 0 ;
}
static void F_144 ( struct V_3 * V_4 , int V_82 )
{
struct V_267 * V_268 ;
int V_201 , V_284 , V_285 ;
V_285 = F_30 ( int , V_82 , F_135 ( V_4 ) ) ;
if ( V_285 ) {
F_145 ( V_4 , V_285 ) ;
V_82 -= V_285 ;
if ( ! V_82 )
return;
}
V_285 = V_82 ;
V_284 = 0 ;
V_268 = F_46 ( V_4 ) ;
for ( V_201 = 0 ; V_201 < V_268 -> V_282 ; V_201 ++ ) {
int V_170 = F_146 ( & V_268 -> V_286 [ V_201 ] ) ;
if ( V_170 <= V_285 ) {
F_147 ( V_4 , V_201 ) ;
V_285 -= V_170 ;
} else {
V_268 -> V_286 [ V_284 ] = V_268 -> V_286 [ V_201 ] ;
if ( V_285 ) {
V_268 -> V_286 [ V_284 ] . V_287 += V_285 ;
F_148 ( & V_268 -> V_286 [ V_284 ] , V_285 ) ;
V_285 = 0 ;
}
V_284 ++ ;
}
}
V_268 -> V_282 = V_284 ;
F_149 ( V_4 ) ;
V_4 -> V_288 -= V_82 ;
V_4 -> V_82 = V_4 -> V_288 ;
}
int F_150 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_82 )
{
if ( F_136 ( V_4 , V_181 ) )
return - V_280 ;
F_144 ( V_4 , V_82 ) ;
F_5 ( V_4 ) -> V_83 += V_82 ;
V_4 -> V_90 = V_91 ;
V_4 -> V_204 -= V_82 ;
V_2 -> V_252 -= V_82 ;
F_151 ( V_2 , V_82 ) ;
F_152 ( V_2 , V_289 ) ;
if ( F_6 ( V_4 ) > 1 )
F_123 ( V_4 , F_116 ( V_4 ) ) ;
return 0 ;
}
static inline int F_153 ( struct V_1 * V_2 , int V_290 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_253 ;
V_253 = V_290 - V_6 -> V_199 -> V_291 - sizeof( struct V_77 ) ;
if ( V_6 -> V_199 -> V_292 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_253 -= V_6 -> V_199 -> V_292 ;
}
if ( V_253 > V_8 -> V_59 . V_293 )
V_253 = V_8 -> V_59 . V_293 ;
V_253 -= V_6 -> V_294 ;
if ( V_253 < 48 )
V_253 = 48 ;
return V_253 ;
}
int F_155 ( struct V_1 * V_2 , int V_290 )
{
return F_153 ( V_2 , V_290 ) -
( F_3 ( V_2 ) -> V_81 - sizeof( struct V_77 ) ) ;
}
int F_156 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_295 ;
V_295 = V_19 +
V_8 -> V_81 +
V_6 -> V_294 +
V_6 -> V_199 -> V_291 ;
if ( V_6 -> V_199 -> V_292 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_295 += V_6 -> V_199 -> V_292 ;
}
return V_295 ;
}
void F_157 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_296 * V_296 = F_9 ( V_2 ) ;
V_6 -> V_297 . V_298 = V_296 -> V_71 . V_299 > 1 ;
V_6 -> V_297 . V_300 = V_8 -> V_59 . V_293 + sizeof( struct V_77 ) +
V_6 -> V_199 -> V_291 ;
V_6 -> V_297 . V_301 = F_156 ( V_2 , V_296 -> V_71 . V_302 ) ;
V_6 -> V_297 . V_303 = 0 ;
if ( V_6 -> V_297 . V_298 )
V_6 -> V_297 . V_304 = V_23 ;
}
unsigned int F_158 ( struct V_1 * V_2 , T_4 V_290 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_253 ;
if ( V_6 -> V_297 . V_300 > V_290 )
V_6 -> V_297 . V_300 = V_290 ;
V_253 = F_155 ( V_2 , V_290 ) ;
V_253 = F_159 ( V_8 , V_253 ) ;
V_6 -> V_305 = V_290 ;
if ( V_6 -> V_297 . V_298 )
V_253 = F_20 ( V_253 , F_155 ( V_2 , V_6 -> V_297 . V_301 ) ) ;
V_8 -> V_306 = V_253 ;
return V_253 ;
}
unsigned int F_62 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_253 ;
unsigned int V_307 ;
struct V_99 V_100 ;
struct V_143 * V_144 ;
V_253 = V_8 -> V_306 ;
if ( V_18 ) {
T_4 V_295 = F_160 ( V_18 ) ;
if ( V_295 != F_2 ( V_2 ) -> V_305 )
V_253 = F_158 ( V_2 , V_295 ) ;
}
V_307 = F_59 ( V_2 , NULL , & V_100 , & V_144 ) +
sizeof( struct V_77 ) ;
if ( V_307 != V_8 -> V_81 ) {
int V_22 = ( int ) V_307 - V_8 -> V_81 ;
V_253 -= V_22 ;
}
return V_253 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_308 == V_309 &&
V_2 -> V_310 && ! F_162 ( V_311 , & V_2 -> V_310 -> V_89 ) ) {
T_4 V_312 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_313 = F_21 ( V_8 -> V_32 , V_312 ) ;
if ( V_313 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_313 ) >> 1 ;
}
V_8 -> V_32 = 0 ;
}
V_8 -> V_31 = V_23 ;
}
static void F_163 ( struct V_1 * V_2 , bool V_314 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_96 , V_8 -> V_315 ) ||
V_8 -> V_10 > V_8 -> V_316 ) {
V_8 -> V_316 = V_8 -> V_10 ;
V_8 -> V_315 = V_8 -> V_11 ;
V_8 -> V_314 = V_314 ;
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
return F_113 ( V_8 -> V_317 , V_8 -> V_96 ) &&
! F_113 ( V_8 -> V_317 , V_8 -> V_11 ) ;
}
static void F_166 ( struct V_7 * V_8 , unsigned int V_253 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_82 < F_6 ( V_4 ) * V_253 )
V_8 -> V_317 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_167 ( bool V_318 , const struct V_7 * V_8 ,
int V_180 )
{
return V_318 &&
( ( V_180 & V_319 ) ||
( ! V_180 && V_8 -> V_10 && F_165 ( V_8 ) ) ) ;
}
static T_4 F_168 ( const struct V_1 * V_2 , unsigned int V_253 )
{
T_4 V_320 , V_321 ;
V_320 = F_20 ( V_2 -> V_322 >> 10 ,
V_2 -> V_323 - 1 - V_324 ) ;
V_321 = F_29 ( T_4 , V_320 / V_253 , V_325 ) ;
return F_30 ( T_4 , V_321 , V_2 -> V_326 ) ;
}
static unsigned int F_169 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_253 ,
unsigned int V_327 ,
int V_180 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_318 , V_328 , V_230 , V_329 ;
V_230 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_83 ;
V_329 = V_253 * V_327 ;
if ( F_54 ( V_329 <= V_230 && V_4 != F_170 ( V_2 ) ) )
return V_329 ;
V_328 = F_20 ( V_4 -> V_82 , V_230 ) ;
if ( V_329 <= V_328 )
return V_329 ;
V_318 = V_328 % V_253 ;
if ( F_167 ( V_318 != 0 , V_8 , V_180 ) )
return V_328 - V_318 ;
return V_328 ;
}
static inline unsigned int F_171 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_330 , V_26 , V_331 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_95 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_330 = F_104 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_330 >= V_26 )
return 0 ;
V_331 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_331 , V_26 - V_330 ) ;
}
static int F_172 ( struct V_3 * V_4 , unsigned int V_253 )
{
int V_332 = F_6 ( V_4 ) ;
if ( ! V_332 || ( V_332 > 1 && F_116 ( V_4 ) != V_253 ) ) {
F_123 ( V_4 , V_253 ) ;
V_332 = F_6 ( V_4 ) ;
}
return V_332 ;
}
static inline bool F_173 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_333 , int V_180 )
{
if ( V_180 & V_334 )
return true ;
if ( F_50 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_95 ) )
return true ;
if ( ! F_167 ( V_4 -> V_82 < V_333 , V_8 , V_180 ) )
return true ;
return false ;
}
static bool F_174 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_333 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_82 > V_333 )
V_12 = F_5 ( V_4 ) -> V_83 + V_333 ;
return ! F_113 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_175 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_333 , int V_180 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_335 ;
F_172 ( V_4 , V_333 ) ;
if ( ! F_173 ( V_8 , V_4 , V_333 , V_180 ) )
return 0 ;
V_335 = F_171 ( V_8 , V_4 ) ;
if ( V_335 && ! F_174 ( V_8 , V_4 , V_333 ) )
V_335 = 0 ;
return V_335 ;
}
bool F_176 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_177 ( V_2 ) ;
return V_4 &&
F_175 ( V_2 , V_4 , F_62 ( V_2 ) ,
( F_178 ( V_2 , V_4 ) ?
V_8 -> V_180 : V_334 ) ) ;
}
static int F_179 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_82 ,
unsigned int V_253 , T_10 V_274 )
{
struct V_3 * V_275 ;
int V_278 = V_4 -> V_82 - V_82 ;
T_7 V_89 ;
if ( V_4 -> V_82 != V_4 -> V_288 )
return F_133 ( V_2 , V_4 , V_82 , V_253 , V_274 ) ;
V_275 = F_137 ( V_2 , 0 , V_274 , true ) ;
if ( F_52 ( ! V_275 ) )
return - V_280 ;
V_2 -> V_252 += V_275 -> V_204 ;
F_122 ( V_2 , V_275 -> V_204 ) ;
V_275 -> V_204 += V_278 ;
V_4 -> V_204 -= V_278 ;
F_5 ( V_275 ) -> V_83 = F_5 ( V_4 ) -> V_83 + V_82 ;
F_5 ( V_275 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_275 ) -> V_83 ;
V_89 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_89 & ~ ( V_95 | V_281 ) ;
F_5 ( V_275 ) -> V_65 = V_89 ;
F_5 ( V_275 ) -> V_93 = 0 ;
V_275 -> V_90 = V_4 -> V_90 = V_91 ;
F_142 ( V_4 , V_275 , V_82 ) ;
F_131 ( V_4 , V_275 ) ;
F_123 ( V_4 , V_253 ) ;
F_123 ( V_275 , V_253 ) ;
F_120 ( V_275 ) ;
F_143 ( V_4 , V_275 , V_2 ) ;
return 0 ;
}
static bool F_180 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_314 , T_4 V_327 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_336 , V_337 , V_338 , V_339 , V_330 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_218 V_33 ;
struct V_3 * V_189 ;
int V_340 ;
if ( F_5 ( V_4 ) -> V_65 & V_95 )
goto V_341;
if ( ! ( ( 1 << V_6 -> V_308 ) & ( V_342 | V_343 ) ) )
goto V_341;
if ( ( T_3 ) ( V_23 - V_8 -> V_24 ) > 0 )
goto V_341;
V_330 = F_104 ( V_8 ) ;
F_98 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_330 ) ) ;
V_337 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_83 ;
V_338 = ( V_8 -> V_27 - V_330 ) * V_8 -> V_306 ;
V_339 = F_20 ( V_337 , V_338 ) ;
if ( V_339 >= V_327 * V_8 -> V_306 )
goto V_341;
if ( ( V_4 != F_170 ( V_2 ) ) && ( V_339 >= V_4 -> V_82 ) )
goto V_341;
V_340 = F_181 ( V_344 ) ;
if ( V_340 ) {
T_4 V_345 = F_20 ( V_8 -> V_346 , V_8 -> V_27 * V_8 -> V_306 ) ;
V_345 /= V_340 ;
if ( V_339 >= V_345 )
goto V_341;
} else {
if ( V_339 > F_182 ( V_8 ) * V_8 -> V_306 )
goto V_341;
}
V_189 = F_183 ( V_2 ) ;
F_99 ( & V_33 ) ;
V_336 = F_184 ( & V_33 , & V_189 -> V_218 ) ;
if ( V_336 < ( V_8 -> V_347 >> 4 ) )
goto V_341;
if ( V_338 < V_337 && V_338 < V_4 -> V_82 )
* V_314 = true ;
return true ;
V_341:
return false ;
}
static inline void F_185 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_296 * V_296 = F_9 ( V_2 ) ;
T_4 V_348 ;
T_3 V_22 ;
V_348 = V_296 -> V_71 . V_349 ;
V_22 = V_23 - V_6 -> V_297 . V_304 ;
if ( F_52 ( V_22 >= V_348 * V_350 ) ) {
int V_19 = F_62 ( V_2 ) ;
V_6 -> V_297 . V_303 = 0 ;
V_6 -> V_297 . V_300 = V_8 -> V_59 . V_293 +
sizeof( struct V_77 ) +
V_6 -> V_199 -> V_291 ;
V_6 -> V_297 . V_301 = F_156 ( V_2 , V_19 ) ;
V_6 -> V_297 . V_304 = V_23 ;
}
}
static int F_186 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_351 , * V_352 ;
struct V_296 * V_296 = F_9 ( V_2 ) ;
int V_82 ;
int V_303 ;
int V_353 ;
int V_354 ;
int V_253 ;
int V_348 ;
if ( ! V_6 -> V_297 . V_298 ||
V_6 -> V_297 . V_303 ||
F_2 ( V_2 ) -> V_308 != V_309 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_172 || V_8 -> V_59 . V_124 )
return - 1 ;
V_253 = F_62 ( V_2 ) ;
V_303 = F_155 ( V_2 , ( V_6 -> V_297 . V_300 +
V_6 -> V_297 . V_301 ) >> 1 ) ;
V_353 = V_303 + ( V_8 -> V_355 + 1 ) * V_8 -> V_306 ;
V_348 = V_6 -> V_297 . V_300 - V_6 -> V_297 . V_301 ;
if ( V_303 > F_155 ( V_2 , V_6 -> V_297 . V_300 ) ||
V_348 < V_296 -> V_71 . V_356 ) {
F_185 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_251 - V_8 -> V_11 < V_353 )
return - 1 ;
if ( V_8 -> V_346 < V_353 )
return - 1 ;
if ( F_113 ( V_8 -> V_11 + V_353 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_104 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_104 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_351 = F_137 ( V_2 , V_303 , V_181 , false ) ;
if ( ! V_351 )
return - 1 ;
V_2 -> V_252 += V_351 -> V_204 ;
F_122 ( V_2 , V_351 -> V_204 ) ;
V_4 = F_177 ( V_2 ) ;
F_5 ( V_351 ) -> V_83 = F_5 ( V_4 ) -> V_83 ;
F_5 ( V_351 ) -> V_12 = F_5 ( V_4 ) -> V_83 + V_303 ;
F_5 ( V_351 ) -> V_65 = V_238 ;
F_5 ( V_351 ) -> V_93 = 0 ;
V_351 -> V_92 = 0 ;
V_351 -> V_90 = V_4 -> V_90 ;
F_187 ( V_351 , V_4 , V_2 ) ;
V_82 = 0 ;
F_188 (skb, next, sk) {
V_354 = F_30 ( int , V_4 -> V_82 , V_303 - V_82 ) ;
if ( V_351 -> V_90 )
F_189 ( V_4 , 0 , F_139 ( V_351 , V_354 ) , V_354 ) ;
else
V_351 -> V_92 = F_190 ( V_4 , 0 ,
F_139 ( V_351 , V_354 ) ,
V_354 , V_351 -> V_92 ) ;
if ( V_4 -> V_82 <= V_354 ) {
F_5 ( V_351 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_191 ( V_4 , V_2 ) ;
F_192 ( V_2 , V_4 ) ;
} else {
F_5 ( V_351 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_95 | V_281 ) ;
if ( ! F_46 ( V_4 ) -> V_282 ) {
F_193 ( V_4 , V_354 ) ;
if ( V_4 -> V_90 != V_91 )
V_4 -> V_92 = F_194 ( V_4 -> V_182 ,
V_4 -> V_82 , 0 ) ;
} else {
F_144 ( V_4 , V_354 ) ;
F_123 ( V_4 , V_253 ) ;
}
F_5 ( V_4 ) -> V_83 += V_354 ;
}
V_82 += V_354 ;
if ( V_82 >= V_303 )
break;
}
F_172 ( V_351 , V_351 -> V_82 ) ;
if ( ! F_97 ( V_2 , V_351 , 1 , V_181 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_351 ) ;
V_6 -> V_297 . V_303 = F_156 ( V_2 , V_351 -> V_82 ) ;
V_8 -> V_357 . V_358 = F_5 ( V_351 ) -> V_83 ;
V_8 -> V_357 . V_359 = F_5 ( V_351 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_61 ( struct V_1 * V_2 , unsigned int V_253 , int V_180 ,
int V_360 , T_10 V_274 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_332 , V_361 ;
int V_335 ;
int V_362 ;
bool V_314 = false ;
T_4 V_327 ;
V_361 = 0 ;
if ( ! V_360 ) {
V_362 = F_186 ( V_2 ) ;
if ( ! V_362 ) {
return false ;
} else if ( V_362 > 0 ) {
V_361 = 1 ;
}
}
V_327 = F_168 ( V_2 , V_253 ) ;
while ( ( V_4 = F_177 ( V_2 ) ) ) {
unsigned int V_339 ;
V_332 = F_172 ( V_4 , V_253 ) ;
F_98 ( ! V_332 ) ;
if ( F_52 ( V_8 -> V_363 ) && V_8 -> V_364 == V_365 ) {
F_99 ( & V_4 -> V_218 ) ;
goto V_363;
}
V_335 = F_171 ( V_8 , V_4 ) ;
if ( ! V_335 ) {
V_314 = true ;
if ( V_360 == 2 )
V_335 = 1 ;
else
break;
}
if ( F_52 ( ! F_174 ( V_8 , V_4 , V_253 ) ) )
break;
if ( V_332 == 1 ) {
if ( F_52 ( ! F_173 ( V_8 , V_4 , V_253 ,
( F_178 ( V_2 , V_4 ) ?
V_180 : V_334 ) ) ) )
break;
} else {
if ( ! V_360 &&
F_180 ( V_2 , V_4 , & V_314 ,
V_327 ) )
break;
}
V_339 = V_253 ;
if ( V_332 > 1 && ! F_50 ( V_8 ) )
V_339 = F_169 ( V_2 , V_4 , V_253 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_180 ) ;
if ( V_4 -> V_82 > V_339 &&
F_52 ( F_179 ( V_2 , V_4 , V_339 , V_253 , V_274 ) ) )
break;
V_339 = F_21 ( 2 * V_4 -> V_204 , V_2 -> V_322 >> 10 ) ;
V_339 = F_30 ( T_4 , V_339 , V_366 ) ;
if ( F_195 ( & V_2 -> V_205 ) > V_339 ) {
F_73 ( V_208 , & V_8 -> V_192 ) ;
F_196 () ;
if ( F_195 ( & V_2 -> V_205 ) > V_339 )
break;
}
if ( F_52 ( F_97 ( V_2 , V_4 , 1 , V_274 ) ) )
break;
V_363:
F_1 ( V_2 , V_4 ) ;
F_166 ( V_8 , V_253 , V_4 ) ;
V_361 += F_6 ( V_4 ) ;
if ( V_360 )
break;
}
if ( F_54 ( V_361 ) ) {
if ( F_197 ( V_2 ) )
V_8 -> V_367 += V_361 ;
if ( V_360 != 2 )
F_198 ( V_2 ) ;
F_163 ( V_2 , V_314 ) ;
return false ;
}
return ( V_360 == 2 ) || ( ! V_8 -> V_10 && F_177 ( V_2 ) ) ;
}
bool F_198 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_368 , V_369 , V_370 ;
T_4 V_371 = F_199 ( V_8 -> V_347 >> 3 ) ;
if ( F_134 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_134 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_174 == V_372 )
return false ;
if ( V_6 -> V_13 != V_373 )
return false ;
if ( V_374 < 3 || ! V_8 -> V_347 || ! V_8 -> V_10 ||
! F_200 ( V_8 ) || F_2 ( V_2 ) -> V_308 != V_309 )
return false ;
if ( ( V_8 -> V_27 > F_104 ( V_8 ) ) &&
F_177 ( V_2 ) )
return false ;
V_368 = V_371 << 1 ;
if ( V_8 -> V_10 == 1 )
V_368 = F_29 ( T_4 , V_368 ,
( V_371 + ( V_371 >> 1 ) + V_375 ) ) ;
V_368 = F_29 ( T_4 , V_368 , F_201 ( 10 ) ) ;
V_369 = V_23 + V_368 ;
V_370 = ( T_4 ) F_2 ( V_2 ) -> V_376 ;
if ( ( T_3 ) ( V_369 - V_370 ) > 0 ) {
T_3 V_22 = V_370 - V_23 ;
if ( V_22 > 0 )
V_368 = V_22 ;
}
F_202 ( V_2 , V_15 , V_368 ,
V_377 ) ;
return true ;
}
static bool F_203 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_52 ( F_204 ( V_2 , V_4 ) ) ) {
F_205 ( F_9 ( V_2 ) ,
V_378 ) ;
return true ;
}
return false ;
}
void F_206 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_379 ;
int V_19 = F_62 ( V_2 ) ;
int V_217 = - 1 ;
if ( F_177 ( V_2 ) ) {
V_217 = F_61 ( V_2 , V_19 , V_380 , 2 , V_181 ) ;
goto V_381;
}
if ( V_8 -> V_382 )
goto V_381;
V_4 = F_170 ( V_2 ) ;
if ( F_134 ( ! V_4 ) )
goto V_381;
if ( F_203 ( V_2 , V_4 ) )
goto V_381;
V_379 = F_6 ( V_4 ) ;
if ( F_134 ( ! V_379 ) )
goto V_381;
if ( ( V_379 > 1 ) && ( V_4 -> V_82 > ( V_379 - 1 ) * V_19 ) ) {
if ( F_52 ( F_133 ( V_2 , V_4 , ( V_379 - 1 ) * V_19 , V_19 ,
V_181 ) ) )
goto V_381;
V_4 = F_170 ( V_2 ) ;
}
if ( F_134 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_381;
V_217 = F_207 ( V_2 , V_4 ) ;
if ( F_54 ( ! V_217 ) )
V_8 -> V_382 = V_8 -> V_11 ;
V_381:
F_202 ( V_2 , V_373 ,
F_2 ( V_2 ) -> V_30 ,
V_377 ) ;
if ( F_54 ( ! V_217 ) )
F_205 ( F_9 ( V_2 ) ,
V_383 ) ;
}
void F_208 ( struct V_1 * V_2 , unsigned int V_333 ,
int V_180 )
{
if ( F_52 ( V_2 -> V_174 == V_384 ) )
return;
if ( F_61 ( V_2 , V_333 , V_180 , 0 ,
F_209 ( V_2 , V_181 ) ) )
F_210 ( V_2 ) ;
}
void F_211 ( struct V_1 * V_2 , unsigned int V_253 )
{
struct V_3 * V_4 = F_177 ( V_2 ) ;
F_98 ( ! V_4 || V_4 -> V_82 < V_253 ) ;
F_61 ( V_2 , V_253 , V_334 , 1 , V_2 -> V_385 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_386 ;
int V_387 = F_212 ( V_2 ) ;
int V_388 = F_213 ( V_2 ) ;
int V_389 = F_30 ( int , V_8 -> V_46 , V_388 ) ;
int V_230 ;
if ( V_19 > V_389 )
V_19 = V_389 ;
if ( V_387 < ( V_389 >> 1 ) ) {
V_6 -> V_35 . V_390 = 0 ;
if ( F_214 ( V_2 ) )
V_8 -> V_391 = F_20 ( V_8 -> V_391 ,
4U * V_8 -> V_20 ) ;
V_387 = F_215 ( V_387 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_387 < ( V_388 >> 4 ) || V_387 < V_19 )
return 0 ;
}
if ( V_387 > V_8 -> V_391 )
V_387 = V_8 -> V_391 ;
V_230 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_230 = V_387 ;
if ( ( ( V_230 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_230 )
V_230 = ( ( ( V_230 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_230 <= V_387 - V_19 || V_230 > V_387 )
V_230 = ( V_387 / V_19 ) * V_19 ;
else if ( V_19 == V_389 &&
V_387 > V_230 + ( V_389 >> 1 ) )
V_230 = V_387 ;
}
return V_230 ;
}
static void F_216 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_392 = F_217 ( V_2 , V_4 ) ;
int V_393 , V_394 ;
V_393 = V_4 -> V_82 ;
V_394 = V_392 -> V_82 ;
F_98 ( F_6 ( V_4 ) != 1 || F_6 ( V_392 ) != 1 ) ;
F_218 ( V_2 , V_392 , V_4 ) ;
F_191 ( V_392 , V_2 ) ;
F_219 ( V_392 , F_139 ( V_4 , V_394 ) ,
V_394 ) ;
if ( V_392 -> V_90 == V_91 )
V_4 -> V_90 = V_91 ;
if ( V_4 -> V_90 != V_91 )
V_4 -> V_92 = F_220 ( V_4 -> V_92 , V_392 -> V_92 , V_393 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_392 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_392 ) -> V_65 ;
F_5 ( V_4 ) -> V_93 |= F_5 ( V_392 ) -> V_93 & V_395 ;
F_221 ( V_8 ) ;
if ( V_392 == V_8 -> V_396 )
V_8 -> V_396 = V_4 ;
F_128 ( V_2 , V_392 , F_6 ( V_392 ) ) ;
F_192 ( V_2 , V_392 ) ;
}
static bool F_222 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_46 ( V_4 ) -> V_282 != 0 )
return false ;
if ( F_100 ( V_4 ) )
return false ;
if ( V_4 == F_177 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_93 & V_259 )
return false ;
return true ;
}
static void F_223 ( struct V_1 * V_2 , struct V_3 * V_397 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_397 , * V_398 ;
bool V_399 = true ;
if ( ! V_400 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_94 )
return;
F_188 (skb, tmp, sk) {
if ( ! F_222 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_82 ;
if ( V_399 ) {
V_399 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_82 > F_224 ( V_397 ) )
break;
if ( F_113 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_216 ( V_2 , V_397 ) ;
}
}
int F_207 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_333 ;
int V_217 ;
if ( V_6 -> V_297 . V_303 ) {
V_6 -> V_297 . V_303 = 0 ;
}
if ( F_195 ( & V_2 -> V_205 ) >
F_20 ( V_2 -> V_252 + ( V_2 -> V_252 >> 2 ) , V_2 -> V_401 ) )
return - V_402 ;
if ( F_203 ( V_2 , V_4 ) )
return - V_403 ;
if ( F_11 ( F_5 ( V_4 ) -> V_83 , V_8 -> V_96 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_96 ) )
F_225 () ;
if ( F_150 ( V_2 , V_4 , V_8 -> V_96 - F_5 ( V_4 ) -> V_83 ) )
return - V_280 ;
}
if ( F_2 ( V_2 ) -> V_199 -> V_404 ( V_2 ) )
return - V_405 ;
V_333 = F_62 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_83 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_83 != V_8 -> V_96 )
return - V_402 ;
if ( V_4 -> V_82 > V_333 ) {
if ( F_133 ( V_2 , V_4 , V_333 , V_333 , V_181 ) )
return - V_280 ;
} else {
int V_406 = F_6 ( V_4 ) ;
if ( F_52 ( V_406 > 1 ) ) {
if ( F_136 ( V_4 , V_181 ) )
return - V_280 ;
F_172 ( V_4 , V_333 ) ;
F_128 ( V_2 , V_4 , V_406 - F_6 ( V_4 ) ) ;
}
}
if ( ( F_5 ( V_4 ) -> V_65 & V_407 ) == V_407 )
F_41 ( V_2 , V_4 ) ;
F_223 ( V_2 , V_4 , V_333 ) ;
if ( F_52 ( ( V_408 && ( ( unsigned long ) V_4 -> V_182 & 3 ) ) ||
F_226 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_351 = F_227 ( V_4 , V_324 ,
V_181 ) ;
V_217 = V_351 ? F_97 ( V_2 , V_351 , 0 , V_181 ) :
- V_219 ;
} else {
V_217 = F_97 ( V_2 , V_4 , 1 , V_181 ) ;
}
if ( F_54 ( ! V_217 ) ) {
F_5 ( V_4 ) -> V_93 |= V_395 ;
F_228 ( F_9 ( V_2 ) , V_409 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_94 )
F_205 ( F_9 ( V_2 ) , V_410 ) ;
V_8 -> V_411 ++ ;
}
return V_217 ;
}
int F_229 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_217 = F_207 ( V_2 , V_4 ) ;
if ( V_217 == 0 ) {
#if V_412 > 0
if ( F_5 ( V_4 ) -> V_93 & V_260 ) {
F_230 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_261 )
V_8 -> V_413 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_93 |= V_414 ;
V_8 -> V_261 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_415 )
V_8 -> V_415 = F_57 ( V_4 ) ;
F_5 ( V_4 ) -> V_228 = V_8 -> V_11 ;
} else if ( V_217 != - V_403 ) {
F_205 ( F_9 ( V_2 ) , V_416 ) ;
}
if ( V_8 -> V_417 < 0 )
V_8 -> V_417 = 0 ;
V_8 -> V_417 += F_6 ( V_4 ) ;
return V_217 ;
}
static bool F_231 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_308 != V_418 )
return false ;
if ( F_126 ( V_8 ) )
return false ;
if ( F_176 ( V_2 ) )
return false ;
return true ;
}
void F_232 ( struct V_1 * V_2 )
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
if ( ! V_8 -> V_263 )
V_8 -> V_423 = V_8 -> V_96 ;
if ( V_8 -> V_396 ) {
V_4 = V_8 -> V_396 ;
V_420 = F_5 ( V_4 ) -> V_12 ;
if ( F_113 ( V_420 , V_8 -> V_423 ) )
V_420 = V_8 -> V_423 ;
} else {
V_4 = F_183 ( V_2 ) ;
V_420 = V_8 -> V_96 ;
}
F_233 (skb, sk) {
T_5 V_93 = F_5 ( V_4 ) -> V_93 ;
if ( V_4 == F_177 ( V_2 ) )
break;
if ( ! V_419 )
V_8 -> V_396 = V_4 ;
if ( F_104 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_422 ) {
V_424:
if ( ! F_11 ( F_5 ( V_4 ) -> V_83 , F_127 ( V_8 ) ) )
break;
V_421 = V_425 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_83 , V_8 -> V_423 ) ) {
V_8 -> V_423 = V_420 ;
if ( ! F_231 ( V_2 ) )
break;
if ( V_419 ) {
V_4 = V_419 ;
V_419 = NULL ;
}
V_422 = 1 ;
goto V_424;
} else if ( ! ( V_93 & V_262 ) ) {
if ( ! V_419 && ! ( V_93 & ( V_260 | V_259 ) ) )
V_419 = V_4 ;
continue;
} else {
V_420 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_308 != V_426 )
V_421 = V_427 ;
else
V_421 = V_428 ;
}
if ( V_93 & ( V_259 | V_260 ) )
continue;
if ( F_229 ( V_2 , V_4 ) )
return;
F_205 ( F_9 ( V_2 ) , V_421 ) ;
if ( F_197 ( V_2 ) )
V_8 -> V_367 += F_6 ( V_4 ) ;
if ( V_4 == F_183 ( V_2 ) )
F_202 ( V_2 , V_373 ,
F_2 ( V_2 ) -> V_30 ,
V_377 ) ;
}
}
void F_234 ( struct V_1 * V_2 , int V_170 )
{
int V_429 , V_430 ;
if ( V_170 <= V_2 -> V_431 )
return;
V_429 = F_235 ( V_170 ) ;
V_2 -> V_431 += V_429 * V_432 ;
F_236 ( V_2 , V_429 , & V_430 ) ;
}
void F_237 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_433 = F_170 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_433 && ( F_177 ( V_2 ) || F_214 ( V_2 ) ) ) {
V_434:
F_5 ( V_433 ) -> V_65 |= V_95 ;
F_5 ( V_433 ) -> V_12 ++ ;
V_8 -> V_251 ++ ;
if ( ! F_177 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_238 ( V_324 , V_2 -> V_385 ) ;
if ( F_52 ( ! V_4 ) ) {
if ( V_433 )
goto V_434;
return;
}
F_239 ( V_4 , V_324 ) ;
F_234 ( V_2 , V_4 -> V_204 ) ;
F_48 ( V_4 , V_8 -> V_251 ,
V_238 | V_95 ) ;
F_119 ( V_2 , V_4 ) ;
}
F_208 ( V_2 , F_62 ( V_2 ) , V_380 ) ;
}
void F_240 ( struct V_1 * V_2 , T_10 V_435 )
{
struct V_3 * V_4 ;
V_4 = F_241 ( V_324 , V_435 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_436 ) ;
return;
}
F_239 ( V_4 , V_324 ) ;
F_48 ( V_4 , F_10 ( V_2 ) ,
V_238 | V_437 ) ;
if ( F_97 ( V_2 , V_4 , 0 , V_435 ) )
F_34 ( F_9 ( V_2 ) , V_436 ) ;
F_228 ( F_9 ( V_2 ) , V_438 ) ;
}
int F_242 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_183 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_65 & V_94 ) ) {
F_243 ( L_2 , V_439 ) ;
return - V_440 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_238 ) ) {
if ( F_100 ( V_4 ) ) {
struct V_3 * V_351 = F_244 ( V_4 , V_181 ) ;
if ( ! V_351 )
return - V_280 ;
F_191 ( V_4 , V_2 ) ;
F_120 ( V_351 ) ;
F_245 ( V_2 , V_351 ) ;
F_192 ( V_2 , V_4 ) ;
V_2 -> V_252 += V_351 -> V_204 ;
F_122 ( V_2 , V_351 -> V_204 ) ;
V_4 = V_351 ;
}
F_5 ( V_4 ) -> V_65 |= V_238 ;
F_36 ( V_2 , V_4 ) ;
}
return F_97 ( V_2 , V_4 , 1 , V_181 ) ;
}
struct V_3 * F_246 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_75 * V_76 ,
struct V_133 * V_134 )
{
struct V_99 V_100 ;
struct V_166 * V_167 = F_43 ( V_76 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_77 * V_78 ;
struct V_3 * V_4 ;
struct V_143 * V_144 = NULL ;
int V_216 ;
int V_19 ;
V_4 = F_247 ( V_2 , V_324 , 1 , V_181 ) ;
if ( F_52 ( ! V_4 ) ) {
F_248 ( V_18 ) ;
return NULL ;
}
F_239 ( V_4 , V_324 ) ;
F_249 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_441 && V_8 -> V_59 . V_441 < V_19 )
V_19 = V_8 -> V_59 . V_441 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
#ifdef F_250
if ( F_52 ( V_76 -> V_442 ) )
V_4 -> V_218 . V_443 = F_251 ( V_76 ) ;
else
#endif
F_99 ( & V_4 -> V_218 ) ;
#ifdef F_56
F_252 () ;
V_144 = F_253 ( V_76 ) -> V_150 -> V_444 ( V_2 , F_254 ( V_76 ) ) ;
#endif
V_216 = F_58 ( V_2 , V_76 , V_19 , V_4 , & V_100 , V_144 ,
V_134 ) + sizeof( * V_78 ) ;
F_106 ( V_4 , V_216 ) ;
F_107 ( V_4 ) ;
V_78 = F_45 ( V_4 ) ;
memset ( V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 -> V_445 = 1 ;
V_78 -> V_446 = 1 ;
F_42 ( V_76 , V_78 , V_2 ) ;
V_78 -> V_224 = F_112 ( V_167 -> V_447 ) ;
V_78 -> V_226 = V_167 -> V_448 ;
F_48 ( V_4 , F_253 ( V_76 ) -> V_449 ,
V_94 | V_238 ) ;
V_78 -> V_83 = F_53 ( F_5 ( V_4 ) -> V_83 ) ;
V_78 -> V_228 = F_53 ( F_253 ( V_76 ) -> V_61 ) ;
V_78 -> V_230 = F_112 ( F_20 ( V_76 -> V_45 , 65535U ) ) ;
F_51 ( ( T_8 * ) ( V_78 + 1 ) , V_8 , & V_100 ) ;
V_78 -> V_450 = ( V_216 >> 2 ) ;
F_255 ( F_9 ( V_2 ) , V_239 ) ;
#ifdef F_56
if ( V_144 )
F_253 ( V_76 ) -> V_150 -> V_236 ( V_100 . V_106 ,
V_144 , F_254 ( V_76 ) , V_4 ) ;
F_256 () ;
#endif
V_4 -> V_243 . V_244 = 0 ;
return V_4 ;
}
static void F_257 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_451 * V_452 ;
T_4 V_453 = F_23 ( V_18 , V_454 ) ;
if ( V_453 == V_455 )
return;
F_252 () ;
V_452 = F_258 ( V_453 ) ;
if ( F_54 ( V_452 && F_259 ( V_452 -> V_456 ) ) ) {
F_260 ( V_6 -> V_457 -> V_456 ) ;
V_6 -> V_458 = F_261 ( V_18 ) ;
V_6 -> V_457 = V_452 ;
}
F_256 () ;
}
static void F_262 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_48 ;
V_8 -> V_81 = sizeof( struct V_77 ) +
( V_154 ? V_157 : 0 ) ;
#ifdef F_56
if ( V_8 -> V_150 -> V_151 ( V_2 , V_2 ) )
V_8 -> V_81 += V_152 ;
#endif
if ( V_8 -> V_59 . V_441 )
V_8 -> V_59 . V_293 = V_8 -> V_59 . V_441 ;
V_8 -> V_459 = 0 ;
F_157 ( V_2 ) ;
F_158 ( V_2 , F_160 ( V_18 ) ) ;
F_257 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_460 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_441 && V_8 -> V_59 . V_441 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_441 ;
F_263 ( V_2 ) ;
if ( V_2 -> V_461 & V_462 &&
( V_8 -> V_46 > F_213 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_213 ( V_2 ) ;
F_28 ( F_213 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_463 ? V_8 -> V_81 - sizeof( struct V_77 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_158 ,
& V_48 ,
F_23 ( V_18 , V_464 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_391 = V_8 -> V_45 ;
V_2 -> V_465 = 0 ;
F_264 ( V_2 , V_466 ) ;
V_8 -> V_346 = 0 ;
F_265 ( V_8 , 0 ) ;
V_8 -> V_96 = V_8 -> V_251 ;
V_8 -> V_317 = V_8 -> V_251 ;
V_8 -> V_97 = V_8 -> V_251 ;
V_8 -> V_11 = V_8 -> V_251 ;
if ( F_54 ( ! V_8 -> V_363 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_467 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_468 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_469 ;
F_2 ( V_2 ) -> V_470 = 0 ;
F_266 ( V_8 ) ;
}
static void F_267 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_213 * V_214 = F_5 ( V_4 ) ;
V_214 -> V_12 += V_4 -> V_82 ;
F_120 ( V_4 ) ;
F_268 ( V_2 , V_4 ) ;
V_2 -> V_252 += V_4 -> V_204 ;
F_122 ( V_2 , V_4 -> V_204 ) ;
V_8 -> V_251 = V_214 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_269 ( struct V_1 * V_2 , struct V_3 * V_445 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_147 * V_471 = V_8 -> V_149 ;
int V_472 = 0 , V_50 , V_217 = 0 , V_473 ;
unsigned long V_474 = 0 ;
struct V_3 * V_475 ;
V_8 -> V_59 . V_293 = V_8 -> V_20 ;
F_270 ( V_2 , & V_8 -> V_59 . V_293 , & V_471 -> V_162 ,
& V_472 , & V_474 ) ;
if ( V_472 > 1 &&
F_271 ( V_476 , V_474 + ( 60 * V_350 << V_472 ) ) ) {
V_471 -> V_162 . V_82 = - 1 ;
goto V_477;
}
if ( V_478 & V_479 )
V_471 -> V_162 . V_82 = - 1 ;
else if ( V_471 -> V_162 . V_82 <= 0 )
goto V_477;
if ( V_8 -> V_59 . V_441 && V_8 -> V_59 . V_441 < V_8 -> V_59 . V_293 )
V_8 -> V_59 . V_293 = V_8 -> V_59 . V_441 ;
V_50 = F_153 ( V_2 , F_2 ( V_2 ) -> V_305 ) -
V_146 ;
V_50 = F_30 ( V_480 , V_50 , V_471 -> V_170 ) ;
V_50 = F_30 ( V_480 , V_50 , F_272 ( V_324 ) ) ;
V_475 = F_137 ( V_2 , V_50 , V_2 -> V_385 , false ) ;
if ( ! V_475 )
goto V_477;
V_475 -> V_90 = V_91 ;
memcpy ( V_475 -> V_245 , V_445 -> V_245 , sizeof( V_445 -> V_245 ) ) ;
V_473 = F_273 ( F_139 ( V_475 , V_50 ) , V_50 ,
& V_471 -> V_182 -> V_481 ) ;
if ( F_52 ( ! V_473 ) ) {
F_274 ( V_475 ) ;
goto V_477;
}
if ( V_473 != V_50 ) {
F_140 ( V_475 , V_473 ) ;
V_50 = V_473 ;
}
if ( V_50 == V_471 -> V_170 )
V_471 -> V_182 = NULL ;
V_471 -> V_473 = V_50 ;
F_267 ( V_2 , V_475 ) ;
V_217 = F_97 ( V_2 , V_475 , 1 , V_2 -> V_385 ) ;
V_445 -> V_218 = V_475 -> V_218 ;
F_5 ( V_475 ) -> V_83 ++ ;
F_5 ( V_475 ) -> V_65 = V_238 | V_281 ;
if ( ! V_217 ) {
V_8 -> V_475 = ( V_471 -> V_473 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_482;
}
V_477:
if ( V_471 -> V_162 . V_82 > 0 )
V_471 -> V_162 . V_82 = 0 ;
V_217 = F_97 ( V_2 , V_445 , 1 , V_2 -> V_385 ) ;
if ( V_217 )
V_8 -> V_164 = 0 ;
V_482:
V_471 -> V_162 . V_82 = - 1 ;
return V_217 ;
}
int F_275 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_275 ;
int V_217 ;
F_262 ( V_2 ) ;
if ( F_52 ( V_8 -> V_363 ) ) {
F_276 ( V_2 , NULL ) ;
return 0 ;
}
V_275 = F_137 ( V_2 , 0 , V_2 -> V_385 , true ) ;
if ( F_52 ( ! V_275 ) )
return - V_219 ;
F_48 ( V_275 , V_8 -> V_251 ++ , V_94 ) ;
V_8 -> V_415 = V_23 ;
F_267 ( V_2 , V_275 ) ;
F_39 ( V_2 , V_275 ) ;
V_217 = V_8 -> V_149 ? F_269 ( V_2 , V_275 ) :
F_97 ( V_2 , V_275 , 1 , V_2 -> V_385 ) ;
if ( V_217 == - V_483 )
return V_217 ;
V_8 -> V_11 = V_8 -> V_251 ;
V_8 -> V_484 = V_8 -> V_251 ;
F_228 ( F_9 ( V_2 ) , V_485 ) ;
F_202 ( V_2 , V_373 ,
F_2 ( V_2 ) -> V_30 , V_377 ) ;
return 0 ;
}
void F_277 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_368 ;
F_18 ( V_2 , V_486 ) ;
if ( V_37 > V_487 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_488 = V_350 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_489 & V_490 ) )
V_488 = V_375 ;
if ( V_8 -> V_347 ) {
int V_371 = F_29 ( int , F_199 ( V_8 -> V_347 >> 3 ) ,
V_487 ) ;
if ( V_371 < V_488 )
V_488 = V_371 ;
}
V_37 = F_20 ( V_37 , V_488 ) ;
}
V_368 = V_476 + V_37 ;
if ( V_6 -> V_35 . V_489 & V_491 ) {
if ( V_6 -> V_35 . V_492 ||
F_278 ( V_6 -> V_35 . V_368 , V_476 + ( V_37 >> 2 ) ) ) {
F_279 ( V_2 ) ;
return;
}
if ( ! F_271 ( V_368 , V_6 -> V_35 . V_368 ) )
V_368 = V_6 -> V_35 . V_368 ;
}
V_6 -> V_35 . V_489 |= V_493 | V_491 ;
V_6 -> V_35 . V_368 = V_368 ;
F_280 ( V_2 , & V_6 -> V_494 , V_368 ) ;
}
void F_279 ( struct V_1 * V_2 )
{
struct V_3 * V_275 ;
if ( V_2 -> V_174 == V_384 )
return;
F_18 ( V_2 , V_495 ) ;
V_275 = F_241 ( V_324 , F_209 ( V_2 , V_181 ) ) ;
if ( ! V_275 ) {
F_281 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_496 ;
F_202 ( V_2 , V_41 ,
V_375 , V_377 ) ;
return;
}
F_239 ( V_275 , V_324 ) ;
F_48 ( V_275 , F_10 ( V_2 ) , V_238 ) ;
F_282 ( V_275 ) ;
F_99 ( & V_275 -> V_218 ) ;
F_97 ( V_2 , V_275 , 0 , F_209 ( V_2 , V_181 ) ) ;
}
static int F_283 ( struct V_1 * V_2 , int V_497 , int V_498 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_241 ( V_324 , F_209 ( V_2 , V_181 ) ) ;
if ( ! V_4 )
return - 1 ;
F_239 ( V_4 , V_324 ) ;
F_48 ( V_4 , V_8 -> V_96 - ! V_497 , V_238 ) ;
F_99 ( & V_4 -> V_218 ) ;
F_205 ( F_9 ( V_2 ) , V_498 ) ;
return F_97 ( V_2 , V_4 , 0 , V_181 ) ;
}
void F_284 ( struct V_1 * V_2 )
{
if ( V_2 -> V_174 == V_499 ) {
F_3 ( V_2 ) -> V_500 = F_3 ( V_2 ) -> V_61 - 1 ;
F_283 ( V_2 , 0 , V_501 ) ;
}
}
int F_285 ( struct V_1 * V_2 , int V_498 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_174 == V_384 )
return - 1 ;
V_4 = F_177 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_83 , F_12 ( V_8 ) ) ) {
int V_217 ;
unsigned int V_19 = F_62 ( V_2 ) ;
unsigned int V_502 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_83 ;
if ( F_11 ( V_8 -> V_484 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_484 = F_5 ( V_4 ) -> V_12 ;
if ( V_502 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_83 ||
V_4 -> V_82 > V_19 ) {
V_502 = F_20 ( V_502 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_281 ;
if ( F_133 ( V_2 , V_4 , V_502 , V_19 , V_181 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_123 ( V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_281 ;
V_217 = F_97 ( V_2 , V_4 , 1 , V_181 ) ;
if ( ! V_217 )
F_1 ( V_2 , V_4 ) ;
return V_217 ;
} else {
if ( F_286 ( V_8 -> V_97 , V_8 -> V_96 + 1 , V_8 -> V_96 + 0xFFFF ) )
F_283 ( V_2 , 1 , V_498 ) ;
return F_283 ( V_2 , 0 , V_498 ) ;
}
}
void F_287 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_503 ;
int V_217 ;
V_217 = F_285 ( V_2 , V_501 ) ;
if ( V_8 -> V_10 || ! F_177 ( V_2 ) ) {
V_6 -> V_504 = 0 ;
V_6 -> V_505 = 0 ;
return;
}
if ( V_217 <= 0 ) {
if ( V_6 -> V_505 < V_506 )
V_6 -> V_505 ++ ;
V_6 -> V_504 ++ ;
V_503 = V_377 ;
} else {
if ( ! V_6 -> V_504 )
V_6 -> V_504 = 1 ;
V_503 = V_507 ;
}
F_202 ( V_2 , V_508 ,
F_288 ( V_2 , V_503 ) ,
V_377 ) ;
}
int F_289 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
const struct V_509 * V_510 = F_253 ( V_76 ) -> V_150 ;
struct V_511 V_250 ;
int V_512 ;
V_512 = V_510 -> V_513 ( V_2 , NULL , & V_250 , V_76 , 0 , NULL ) ;
if ( ! V_512 ) {
F_255 ( F_9 ( V_2 ) , V_409 ) ;
F_205 ( F_9 ( V_2 ) , V_410 ) ;
}
return V_512 ;
}
