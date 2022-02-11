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
T_7 * V_138 = ( T_7 * ) V_100 ;
T_4 V_81 ;
if ( V_136 -> exp ) {
V_81 = V_139 + V_136 -> V_81 ;
* V_100 = F_52 ( ( V_140 << 24 ) | ( V_81 << 16 ) |
V_141 ) ;
V_138 += V_139 ;
} else {
V_81 = V_142 + V_136 -> V_81 ;
* V_138 ++ = V_143 ;
* V_138 ++ = V_81 ;
}
memcpy ( V_138 , V_136 -> V_144 , V_136 -> V_81 ) ;
if ( ( V_81 & 3 ) == 2 ) {
V_138 [ V_136 -> V_81 ] = V_105 ;
V_138 [ V_136 -> V_81 + 1 ] = V_105 ;
}
V_100 += ( V_81 + 3 ) >> 2 ;
}
}
static unsigned int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_145 * * V_146 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_147 = V_148 ;
struct V_149 * V_150 = V_8 -> V_151 ;
#ifdef F_55
* V_146 = V_8 -> V_152 -> V_153 ( V_2 , V_2 ) ;
if ( * V_146 ) {
V_102 -> V_103 |= V_104 ;
V_147 -= V_154 ;
}
#else
* V_146 = NULL ;
#endif
V_102 -> V_19 = F_13 ( V_2 ) ;
V_147 -= V_155 ;
if ( F_53 ( V_156 && ! * V_146 ) ) {
V_102 -> V_103 |= V_111 ;
V_102 -> V_117 = F_56 ( V_4 ) + V_8 -> V_157 ;
V_102 -> V_118 = V_8 -> V_59 . V_158 ;
V_147 -= V_159 ;
}
if ( F_53 ( V_160 ) ) {
V_102 -> V_122 = V_8 -> V_59 . V_48 ;
V_102 -> V_103 |= V_119 ;
V_147 -= V_161 ;
}
if ( F_53 ( V_162 ) ) {
V_102 -> V_103 |= V_112 ;
if ( F_51 ( ! ( V_111 & V_102 -> V_103 ) ) )
V_147 -= V_163 ;
}
if ( V_150 && V_150 -> V_164 . V_81 >= 0 ) {
T_4 V_165 = V_150 -> V_164 . V_81 ;
V_165 += V_150 -> V_164 . exp ? V_139 :
V_142 ;
V_165 = ( V_165 + 3 ) & ~ 3U ;
if ( V_147 >= V_165 ) {
V_102 -> V_103 |= V_134 ;
V_102 -> V_137 = & V_150 -> V_164 ;
V_147 -= V_165 ;
V_8 -> V_166 = 1 ;
V_8 -> V_167 = V_150 -> V_164 . exp ? 1 : 0 ;
}
}
return V_148 - V_147 ;
}
static unsigned int F_57 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
unsigned int V_19 , struct V_3 * V_4 ,
struct V_101 * V_102 ,
const struct V_145 * V_146 ,
struct V_135 * V_136 )
{
struct V_168 * V_169 = F_42 ( V_75 ) ;
unsigned int V_147 = V_148 ;
#ifdef F_55
if ( V_146 ) {
V_102 -> V_103 |= V_104 ;
V_147 -= V_154 ;
V_169 -> V_170 &= ! V_169 -> V_171 ;
}
#endif
V_102 -> V_19 = V_19 ;
V_147 -= V_155 ;
if ( F_53 ( V_169 -> V_47 ) ) {
V_102 -> V_122 = V_169 -> V_48 ;
V_102 -> V_103 |= V_119 ;
V_147 -= V_161 ;
}
if ( F_53 ( V_169 -> V_170 ) ) {
V_102 -> V_103 |= V_111 ;
V_102 -> V_117 = F_56 ( V_4 ) ;
V_102 -> V_118 = V_75 -> V_158 ;
V_147 -= V_159 ;
}
if ( F_53 ( V_169 -> V_171 ) ) {
V_102 -> V_103 |= V_112 ;
if ( F_51 ( ! V_169 -> V_170 ) )
V_147 -= V_163 ;
}
if ( V_136 != NULL && V_136 -> V_81 >= 0 ) {
T_4 V_165 = V_136 -> V_81 ;
V_165 += V_136 -> exp ? V_139 :
V_142 ;
V_165 = ( V_165 + 3 ) & ~ 3U ;
if ( V_147 >= V_165 ) {
V_102 -> V_103 |= V_134 ;
V_102 -> V_137 = V_136 ;
V_147 -= V_165 ;
}
}
return V_148 - V_147 ;
}
static unsigned int F_58 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_101 * V_102 ,
struct V_145 * * V_146 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_172 = 0 ;
unsigned int V_173 ;
V_102 -> V_103 = 0 ;
#ifdef F_55
* V_146 = V_8 -> V_152 -> V_153 ( V_2 , V_2 ) ;
if ( F_51 ( * V_146 ) ) {
V_102 -> V_103 |= V_104 ;
V_172 += V_154 ;
}
#else
* V_146 = NULL ;
#endif
if ( F_53 ( V_8 -> V_59 . V_170 ) ) {
V_102 -> V_103 |= V_111 ;
V_102 -> V_117 = V_4 ? F_56 ( V_4 ) + V_8 -> V_157 : 0 ;
V_102 -> V_118 = V_8 -> V_59 . V_158 ;
V_172 += V_159 ;
}
V_173 = V_8 -> V_59 . V_174 + V_8 -> V_59 . V_126 ;
if ( F_51 ( V_173 ) ) {
const unsigned int V_147 = V_148 - V_172 ;
V_102 -> V_123 =
F_30 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_172 += V_175 +
V_102 -> V_123 * V_132 ;
}
return V_172 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ( 1 << V_2 -> V_176 ) &
( V_177 | V_178 | V_179 |
V_180 | V_181 ) )
F_60 ( V_2 , F_61 ( V_2 ) , F_3 ( V_2 ) -> V_182 ,
0 , V_183 ) ;
}
static void F_62 ( unsigned long V_184 )
{
struct V_185 * V_186 = (struct V_185 * ) V_184 ;
F_63 ( V_187 ) ;
unsigned long V_88 ;
struct V_188 * V_189 , * V_190 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
F_64 ( V_88 ) ;
F_65 ( & V_186 -> V_191 , & V_187 ) ;
F_66 ( V_88 ) ;
F_67 (q, n, &list) {
V_8 = F_68 ( V_189 , struct V_7 , V_192 ) ;
F_69 ( & V_8 -> V_192 ) ;
V_2 = (struct V_1 * ) V_8 ;
F_70 ( V_2 ) ;
if ( ! F_71 ( V_2 ) ) {
F_59 ( V_2 ) ;
} else {
F_72 ( V_193 , & V_8 -> V_194 ) ;
}
F_73 ( V_2 ) ;
F_74 ( V_195 , & V_8 -> V_194 ) ;
F_75 ( V_2 ) ;
}
}
void F_76 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_88 , V_196 ;
do {
V_88 = V_8 -> V_194 ;
if ( ! ( V_88 & V_197 ) )
return;
V_196 = V_88 & ~ V_197 ;
} while ( F_77 ( & V_8 -> V_194 , V_88 , V_196 ) != V_88 );
if ( V_88 & ( 1UL << V_193 ) )
F_59 ( V_2 ) ;
F_78 ( V_2 ) ;
if ( V_88 & ( 1UL << V_198 ) ) {
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_199 ) ) {
F_81 ( V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_88 & ( 1UL << V_200 ) ) {
F_2 ( V_2 ) -> V_201 -> V_202 ( V_2 ) ;
F_80 ( V_2 ) ;
}
}
void T_9 F_82 ( void )
{
int V_203 ;
F_83 (i) {
struct V_185 * V_186 = & F_84 ( V_185 , V_203 ) ;
F_85 ( & V_186 -> V_191 ) ;
F_86 ( & V_186 -> V_204 ,
F_62 ,
( unsigned long ) V_186 ) ;
}
}
void F_87 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_205 ;
V_205 = F_88 ( V_4 -> V_206 - 1 , & V_2 -> V_207 ) ;
if ( V_205 >= F_89 ( 1 ) && F_90 () == V_208 )
goto V_209;
if ( F_91 ( V_210 , & V_8 -> V_194 ) &&
! F_92 ( V_195 , & V_8 -> V_194 ) ) {
unsigned long V_88 ;
struct V_185 * V_186 ;
F_64 ( V_88 ) ;
V_186 = F_93 ( & V_185 ) ;
F_94 ( & V_8 -> V_192 , & V_186 -> V_191 ) ;
F_95 ( & V_186 -> V_204 ) ;
F_66 ( V_88 ) ;
return;
}
V_209:
F_75 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_211 ,
T_10 V_212 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_213 * V_214 ;
struct V_7 * V_8 ;
struct V_215 * V_216 ;
struct V_101 V_102 ;
unsigned int V_217 , V_218 ;
struct V_145 * V_146 ;
struct V_76 * V_77 ;
int V_219 ;
F_97 ( ! V_4 || ! F_6 ( V_4 ) ) ;
if ( V_211 ) {
F_98 ( & V_4 -> V_220 ) ;
if ( F_51 ( F_99 ( V_4 ) ) )
V_4 = F_100 ( V_4 , V_212 ) ;
else
V_4 = F_101 ( V_4 , V_212 ) ;
if ( F_51 ( ! V_4 ) )
return - V_221 ;
}
V_214 = F_102 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_216 = F_5 ( V_4 ) ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
if ( F_51 ( V_216 -> V_65 & V_96 ) )
V_217 = F_54 ( V_2 , V_4 , & V_102 , & V_146 ) ;
else
V_217 = F_58 ( V_2 , V_4 , & V_102 ,
& V_146 ) ;
V_218 = V_217 + sizeof( struct V_76 ) ;
if ( F_103 ( V_8 ) == 0 )
F_18 ( V_2 , V_222 ) ;
V_4 -> V_223 = F_104 ( V_2 ) < F_89 ( 1 ) ;
F_105 ( V_4 , V_218 ) ;
F_106 ( V_4 ) ;
F_107 ( V_4 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_224 = F_108 ( V_4 ) ? V_225 : F_87 ;
F_109 ( V_4 , V_2 ) ;
F_110 ( V_4 -> V_206 , & V_2 -> V_207 ) ;
V_77 = F_44 ( V_4 ) ;
V_77 -> V_226 = V_214 -> V_227 ;
V_77 -> V_228 = V_214 -> V_229 ;
V_77 -> V_82 = F_52 ( V_216 -> V_82 ) ;
V_77 -> V_230 = F_52 ( V_8 -> V_61 ) ;
* ( ( ( V_231 * ) V_77 ) + 6 ) = F_111 ( ( ( V_218 >> 2 ) << 12 ) |
V_216 -> V_65 ) ;
if ( F_51 ( V_216 -> V_65 & V_96 ) ) {
V_77 -> V_232 = F_111 ( F_20 ( V_8 -> V_45 , 65535U ) ) ;
} else {
V_77 -> V_232 = F_111 ( F_31 ( V_2 ) ) ;
}
V_77 -> V_233 = 0 ;
V_77 -> V_234 = 0 ;
if ( F_51 ( F_49 ( V_8 ) && F_11 ( V_216 -> V_82 , V_8 -> V_99 ) ) ) {
if ( F_11 ( V_8 -> V_99 , V_216 -> V_82 + 0x10000 ) ) {
V_77 -> V_234 = F_111 ( V_8 -> V_99 - V_216 -> V_82 ) ;
V_77 -> V_235 = 1 ;
} else if ( F_112 ( V_216 -> V_82 + 0xFFFF , V_8 -> V_11 ) ) {
V_77 -> V_234 = F_111 ( 0xFFFF ) ;
V_77 -> V_235 = 1 ;
}
}
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_102 ) ;
if ( F_53 ( ( V_216 -> V_65 & V_96 ) == 0 ) )
F_43 ( V_2 , V_4 , V_218 ) ;
#ifdef F_55
if ( V_146 ) {
F_113 ( V_2 , V_236 ) ;
V_8 -> V_152 -> V_237 ( V_102 . V_108 ,
V_146 , V_2 , V_4 ) ;
}
#endif
V_6 -> V_201 -> V_238 ( V_2 , V_4 ) ;
if ( F_53 ( V_216 -> V_65 & V_239 ) )
F_24 ( V_2 , F_6 ( V_4 ) ) ;
if ( V_4 -> V_81 != V_218 )
F_22 ( V_8 , V_2 ) ;
if ( F_112 ( V_216 -> V_12 , V_8 -> V_11 ) || V_216 -> V_82 == V_216 -> V_12 )
F_114 ( F_9 ( V_2 ) , V_240 ,
F_6 ( V_4 ) ) ;
F_45 ( V_4 ) -> V_241 = F_6 ( V_4 ) ;
V_4 -> V_242 . V_243 = 0 ;
memset ( V_4 -> V_244 , 0 , F_21 ( sizeof( struct V_245 ) ,
sizeof( struct V_246 ) ) ) ;
V_219 = V_6 -> V_201 -> V_247 ( V_2 , V_4 , & V_214 -> V_248 . V_249 ) ;
if ( F_53 ( V_219 <= 0 ) )
return V_219 ;
F_115 ( V_2 ) ;
return F_116 ( V_219 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_250 = F_5 ( V_4 ) -> V_12 ;
F_118 ( V_4 ) ;
F_119 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_4 -> V_206 ;
F_120 ( V_2 , V_4 -> V_206 ) ;
}
static void F_121 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_252 )
{
struct V_89 * V_90 = F_45 ( V_4 ) ;
F_122 ( F_99 ( V_4 ) ) ;
if ( V_4 -> V_81 <= V_252 || V_4 -> V_91 == V_253 ) {
F_48 ( V_4 , 1 ) ;
V_90 -> V_95 = 0 ;
V_90 -> V_85 = 0 ;
} else {
F_48 ( V_4 , F_123 ( V_4 -> V_81 , V_252 ) ) ;
V_90 -> V_95 = V_252 ;
V_90 -> V_85 = V_2 -> V_254 ;
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
if ( F_5 ( V_4 ) -> V_94 & V_258 )
V_8 -> V_256 -= V_255 ;
if ( F_5 ( V_4 ) -> V_94 & V_259 )
V_8 -> V_260 -= V_255 ;
if ( F_5 ( V_4 ) -> V_94 & V_261 )
V_8 -> V_262 -= V_255 ;
if ( F_125 ( V_8 ) && V_255 > 0 )
V_8 -> V_256 -= F_30 ( T_4 , V_8 -> V_256 , V_255 ) ;
F_124 ( V_2 , V_4 , V_255 ) ;
if ( V_8 -> V_263 &&
F_11 ( F_5 ( V_4 ) -> V_82 , F_5 ( V_8 -> V_263 ) -> V_82 ) &&
( F_128 ( V_8 ) || ( F_5 ( V_4 ) -> V_94 & V_258 ) ) )
V_8 -> V_264 -= V_255 ;
F_129 ( V_8 ) ;
}
static void F_130 ( struct V_3 * V_4 , struct V_3 * V_265 )
{
struct V_89 * V_90 = F_45 ( V_4 ) ;
if ( F_51 ( V_90 -> V_266 & V_267 ) &&
! F_11 ( V_90 -> V_268 , F_5 ( V_265 ) -> V_82 ) ) {
struct V_89 * V_269 = F_45 ( V_265 ) ;
T_7 V_270 = V_90 -> V_266 & V_267 ;
V_90 -> V_266 &= ~ V_270 ;
V_269 -> V_266 |= V_270 ;
F_131 ( V_90 -> V_268 , V_269 -> V_268 ) ;
}
}
int F_132 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 ,
unsigned int V_252 , T_10 V_271 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_272 ;
int V_273 , V_274 ;
int V_275 ;
T_7 V_88 ;
if ( F_133 ( V_81 > V_4 -> V_81 ) )
return - V_276 ;
V_273 = F_134 ( V_4 ) - V_81 ;
if ( V_273 < 0 )
V_273 = 0 ;
if ( F_135 ( V_4 , V_271 ) )
return - V_277 ;
V_272 = F_136 ( V_2 , V_273 , V_271 ) ;
if ( ! V_272 )
return - V_277 ;
V_2 -> V_251 += V_272 -> V_206 ;
F_120 ( V_2 , V_272 -> V_206 ) ;
V_275 = V_4 -> V_81 - V_81 - V_273 ;
V_272 -> V_206 += V_275 ;
V_4 -> V_206 -= V_275 ;
F_5 ( V_272 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_272 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_272 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_88 & ~ ( V_97 | V_278 ) ;
F_5 ( V_272 ) -> V_65 = V_88 ;
F_5 ( V_272 ) -> V_94 = F_5 ( V_4 ) -> V_94 ;
if ( ! F_45 ( V_4 ) -> V_279 && V_4 -> V_91 != V_92 ) {
V_272 -> V_93 = F_137 ( V_4 -> V_184 + V_81 ,
F_138 ( V_272 , V_273 ) ,
V_273 , 0 ) ;
F_139 ( V_4 , V_81 ) ;
V_4 -> V_93 = F_140 ( V_4 -> V_93 , V_272 -> V_93 , V_81 ) ;
} else {
V_4 -> V_91 = V_92 ;
F_141 ( V_4 , V_272 , V_81 ) ;
}
V_272 -> V_91 = V_4 -> V_91 ;
V_272 -> V_242 = V_4 -> V_242 ;
F_130 ( V_4 , V_272 ) ;
V_274 = F_6 ( V_4 ) ;
F_121 ( V_2 , V_4 , V_252 ) ;
F_121 ( V_2 , V_272 , V_252 ) ;
if ( ! F_11 ( V_8 -> V_11 , F_5 ( V_272 ) -> V_12 ) ) {
int V_280 = V_274 - F_6 ( V_4 ) -
F_6 ( V_272 ) ;
if ( V_280 )
F_127 ( V_2 , V_4 , V_280 ) ;
}
F_118 ( V_272 ) ;
F_142 ( V_4 , V_272 , V_2 ) ;
return 0 ;
}
static void F_143 ( struct V_3 * V_4 , int V_81 )
{
struct V_89 * V_90 ;
int V_203 , V_281 , V_282 ;
V_282 = F_30 ( int , V_81 , F_134 ( V_4 ) ) ;
if ( V_282 ) {
F_144 ( V_4 , V_282 ) ;
V_81 -= V_282 ;
if ( ! V_81 )
return;
}
V_282 = V_81 ;
V_281 = 0 ;
V_90 = F_45 ( V_4 ) ;
for ( V_203 = 0 ; V_203 < V_90 -> V_279 ; V_203 ++ ) {
int V_172 = F_145 ( & V_90 -> V_283 [ V_203 ] ) ;
if ( V_172 <= V_282 ) {
F_146 ( V_4 , V_203 ) ;
V_282 -= V_172 ;
} else {
V_90 -> V_283 [ V_281 ] = V_90 -> V_283 [ V_203 ] ;
if ( V_282 ) {
V_90 -> V_283 [ V_281 ] . V_284 += V_282 ;
F_147 ( & V_90 -> V_283 [ V_281 ] , V_282 ) ;
V_282 = 0 ;
}
V_281 ++ ;
}
}
V_90 -> V_279 = V_281 ;
F_148 ( V_4 ) ;
V_4 -> V_285 -= V_81 ;
V_4 -> V_81 = V_4 -> V_285 ;
}
int F_149 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_81 )
{
if ( F_135 ( V_4 , V_183 ) )
return - V_277 ;
F_143 ( V_4 , V_81 ) ;
F_5 ( V_4 ) -> V_82 += V_81 ;
V_4 -> V_91 = V_92 ;
V_4 -> V_206 -= V_81 ;
V_2 -> V_251 -= V_81 ;
F_150 ( V_2 , V_81 ) ;
F_151 ( V_2 , V_286 ) ;
if ( F_6 ( V_4 ) > 1 )
F_121 ( V_2 , V_4 , F_152 ( V_4 ) ) ;
return 0 ;
}
static inline int F_153 ( struct V_1 * V_2 , int V_287 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_252 ;
V_252 = V_287 - V_6 -> V_201 -> V_288 - sizeof( struct V_76 ) ;
if ( V_6 -> V_201 -> V_289 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_252 -= V_6 -> V_201 -> V_289 ;
}
if ( V_252 > V_8 -> V_59 . V_290 )
V_252 = V_8 -> V_59 . V_290 ;
V_252 -= V_6 -> V_291 ;
if ( V_252 < 48 )
V_252 = 48 ;
return V_252 ;
}
int F_155 ( struct V_1 * V_2 , int V_287 )
{
return F_153 ( V_2 , V_287 ) -
( F_3 ( V_2 ) -> V_80 - sizeof( struct V_76 ) ) ;
}
int F_156 ( struct V_1 * V_2 , int V_19 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_292 ;
V_292 = V_19 +
V_8 -> V_80 +
V_6 -> V_291 +
V_6 -> V_201 -> V_288 ;
if ( V_6 -> V_201 -> V_289 ) {
const struct V_17 * V_18 = F_14 ( V_2 ) ;
if ( V_18 && F_154 ( V_18 ) )
V_292 += V_6 -> V_201 -> V_289 ;
}
return V_292 ;
}
void F_157 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_293 * V_293 = F_9 ( V_2 ) ;
V_6 -> V_294 . V_295 = V_293 -> V_71 . V_296 > 1 ;
V_6 -> V_294 . V_297 = V_8 -> V_59 . V_290 + sizeof( struct V_76 ) +
V_6 -> V_201 -> V_288 ;
V_6 -> V_294 . V_298 = F_156 ( V_2 , V_293 -> V_71 . V_299 ) ;
V_6 -> V_294 . V_300 = 0 ;
if ( V_6 -> V_294 . V_295 )
V_6 -> V_294 . V_301 = V_23 ;
}
unsigned int F_158 ( struct V_1 * V_2 , T_4 V_287 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_252 ;
if ( V_6 -> V_294 . V_297 > V_287 )
V_6 -> V_294 . V_297 = V_287 ;
V_252 = F_155 ( V_2 , V_287 ) ;
V_252 = F_159 ( V_8 , V_252 ) ;
V_6 -> V_302 = V_287 ;
if ( V_6 -> V_294 . V_295 )
V_252 = F_20 ( V_252 , F_155 ( V_2 , V_6 -> V_294 . V_298 ) ) ;
V_8 -> V_303 = V_252 ;
return V_252 ;
}
unsigned int F_61 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_17 * V_18 = F_14 ( V_2 ) ;
T_4 V_252 ;
unsigned int V_304 ;
struct V_101 V_102 ;
struct V_145 * V_146 ;
V_252 = V_8 -> V_303 ;
if ( V_18 ) {
T_4 V_292 = F_160 ( V_18 ) ;
if ( V_292 != F_2 ( V_2 ) -> V_302 )
V_252 = F_158 ( V_2 , V_292 ) ;
}
V_304 = F_58 ( V_2 , NULL , & V_102 , & V_146 ) +
sizeof( struct V_76 ) ;
if ( V_304 != V_8 -> V_80 ) {
int V_22 = ( int ) V_304 - V_8 -> V_80 ;
V_252 -= V_22 ;
}
return V_252 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_305 == V_306 &&
V_2 -> V_307 && ! F_162 ( V_308 , & V_2 -> V_307 -> V_88 ) ) {
T_4 V_309 = F_17 ( V_8 , F_14 ( V_2 ) ) ;
T_4 V_310 = F_21 ( V_8 -> V_32 , V_309 ) ;
if ( V_310 < V_8 -> V_27 ) {
V_8 -> V_29 = F_19 ( V_2 ) ;
V_8 -> V_27 = ( V_8 -> V_27 + V_310 ) >> 1 ;
}
V_8 -> V_32 = 0 ;
}
V_8 -> V_31 = V_23 ;
}
static void F_163 ( struct V_1 * V_2 , bool V_311 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( ! F_11 ( V_8 -> V_98 , V_8 -> V_312 ) ||
V_8 -> V_10 > V_8 -> V_313 ) {
V_8 -> V_313 = V_8 -> V_10 ;
V_8 -> V_312 = V_8 -> V_11 ;
V_8 -> V_311 = V_311 ;
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
return F_112 ( V_8 -> V_314 , V_8 -> V_98 ) &&
! F_112 ( V_8 -> V_314 , V_8 -> V_11 ) ;
}
static void F_166 ( struct V_7 * V_8 , unsigned int V_252 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_81 < F_6 ( V_4 ) * V_252 )
V_8 -> V_314 = F_5 ( V_4 ) -> V_12 ;
}
static bool F_167 ( bool V_315 , const struct V_7 * V_8 ,
int V_182 )
{
return V_315 &&
( ( V_182 & V_316 ) ||
( ! V_182 && V_8 -> V_10 && F_165 ( V_8 ) ) ) ;
}
static T_4 F_168 ( const struct V_1 * V_2 , unsigned int V_252 )
{
T_4 V_317 , V_318 ;
V_317 = F_20 ( V_2 -> V_319 >> 10 ,
V_2 -> V_320 - 1 - V_321 ) ;
V_318 = F_29 ( T_4 , V_317 / V_252 , V_322 ) ;
return F_30 ( T_4 , V_318 , V_2 -> V_323 ) ;
}
static unsigned int F_169 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_252 ,
unsigned int V_324 ,
int V_182 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_315 , V_325 , V_232 , V_326 ;
V_232 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_326 = V_252 * V_324 ;
if ( F_53 ( V_326 <= V_232 && V_4 != F_170 ( V_2 ) ) )
return V_326 ;
V_325 = F_20 ( V_4 -> V_81 , V_232 ) ;
if ( V_326 <= V_325 )
return V_326 ;
V_315 = V_325 % V_252 ;
if ( F_167 ( V_315 != 0 , V_8 , V_182 ) )
return V_325 - V_315 ;
return V_325 ;
}
static inline unsigned int F_171 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 )
{
T_4 V_327 , V_26 , V_328 ;
if ( ( F_5 ( V_4 ) -> V_65 & V_97 ) &&
F_6 ( V_4 ) == 1 )
return 1 ;
V_327 = F_103 ( V_8 ) ;
V_26 = V_8 -> V_27 ;
if ( V_327 >= V_26 )
return 0 ;
V_328 = F_21 ( V_26 >> 1 , 1U ) ;
return F_20 ( V_328 , V_26 - V_327 ) ;
}
static int F_172 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_252 )
{
int V_329 = F_6 ( V_4 ) ;
if ( ! V_329 || ( V_329 > 1 && F_152 ( V_4 ) != V_252 ) ) {
F_121 ( V_2 , V_4 , V_252 ) ;
V_329 = F_6 ( V_4 ) ;
}
return V_329 ;
}
static inline bool F_173 ( const struct V_7 * V_8 , const struct V_3 * V_4 ,
unsigned int V_330 , int V_182 )
{
if ( V_182 & V_331 )
return true ;
if ( F_49 ( V_8 ) || ( F_5 ( V_4 ) -> V_65 & V_97 ) )
return true ;
if ( ! F_167 ( V_4 -> V_81 < V_330 , V_8 , V_182 ) )
return true ;
return false ;
}
static bool F_174 ( const struct V_7 * V_8 ,
const struct V_3 * V_4 ,
unsigned int V_330 )
{
T_4 V_12 = F_5 ( V_4 ) -> V_12 ;
if ( V_4 -> V_81 > V_330 )
V_12 = F_5 ( V_4 ) -> V_82 + V_330 ;
return ! F_112 ( V_12 , F_12 ( V_8 ) ) ;
}
static unsigned int F_175 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_330 , int V_182 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_332 ;
F_172 ( V_2 , V_4 , V_330 ) ;
if ( ! F_173 ( V_8 , V_4 , V_330 , V_182 ) )
return 0 ;
V_332 = F_171 ( V_8 , V_4 ) ;
if ( V_332 && ! F_174 ( V_8 , V_4 , V_330 ) )
V_332 = 0 ;
return V_332 ;
}
bool F_176 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_177 ( V_2 ) ;
return V_4 &&
F_175 ( V_2 , V_4 , F_61 ( V_2 ) ,
( F_178 ( V_2 , V_4 ) ?
V_8 -> V_182 : V_331 ) ) ;
}
static int F_179 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_81 ,
unsigned int V_252 , T_10 V_271 )
{
struct V_3 * V_272 ;
int V_275 = V_4 -> V_81 - V_81 ;
T_7 V_88 ;
if ( V_4 -> V_81 != V_4 -> V_285 )
return F_132 ( V_2 , V_4 , V_81 , V_252 , V_271 ) ;
V_272 = F_136 ( V_2 , 0 , V_271 ) ;
if ( F_51 ( ! V_272 ) )
return - V_277 ;
V_2 -> V_251 += V_272 -> V_206 ;
F_120 ( V_2 , V_272 -> V_206 ) ;
V_272 -> V_206 += V_275 ;
V_4 -> V_206 -= V_275 ;
F_5 ( V_272 ) -> V_82 = F_5 ( V_4 ) -> V_82 + V_81 ;
F_5 ( V_272 ) -> V_12 = F_5 ( V_4 ) -> V_12 ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_272 ) -> V_82 ;
V_88 = F_5 ( V_4 ) -> V_65 ;
F_5 ( V_4 ) -> V_65 = V_88 & ~ ( V_97 | V_278 ) ;
F_5 ( V_272 ) -> V_65 = V_88 ;
F_5 ( V_272 ) -> V_94 = 0 ;
V_272 -> V_91 = V_4 -> V_91 = V_92 ;
F_141 ( V_4 , V_272 , V_81 ) ;
F_130 ( V_4 , V_272 ) ;
F_121 ( V_2 , V_4 , V_252 ) ;
F_121 ( V_2 , V_272 , V_252 ) ;
F_118 ( V_272 ) ;
F_142 ( V_4 , V_272 , V_2 ) ;
return 0 ;
}
static bool F_180 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool * V_311 , T_4 V_324 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_333 , V_334 , V_335 , V_336 , V_327 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_220 V_33 ;
struct V_3 * V_191 ;
int V_337 ;
if ( F_5 ( V_4 ) -> V_65 & V_97 )
goto V_338;
if ( ! ( ( 1 << V_6 -> V_305 ) & ( V_339 | V_340 ) ) )
goto V_338;
if ( ( T_3 ) ( V_23 - V_8 -> V_24 ) > 0 )
goto V_338;
V_327 = F_103 ( V_8 ) ;
F_97 ( F_6 ( V_4 ) <= 1 || ( V_8 -> V_27 <= V_327 ) ) ;
V_334 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
V_335 = ( V_8 -> V_27 - V_327 ) * V_8 -> V_303 ;
V_336 = F_20 ( V_334 , V_335 ) ;
if ( V_336 >= V_324 * V_8 -> V_303 )
goto V_338;
if ( ( V_4 != F_170 ( V_2 ) ) && ( V_336 >= V_4 -> V_81 ) )
goto V_338;
V_337 = F_181 ( V_341 ) ;
if ( V_337 ) {
T_4 V_342 = F_20 ( V_8 -> V_343 , V_8 -> V_27 * V_8 -> V_303 ) ;
V_342 /= V_337 ;
if ( V_336 >= V_342 )
goto V_338;
} else {
if ( V_336 > F_182 ( V_8 ) * V_8 -> V_303 )
goto V_338;
}
V_191 = F_183 ( V_2 ) ;
F_98 ( & V_33 ) ;
V_333 = F_184 ( & V_33 , & V_191 -> V_220 ) ;
if ( V_333 < ( V_8 -> V_344 >> 4 ) )
goto V_338;
if ( V_335 < V_334 && V_335 < V_4 -> V_81 )
* V_311 = true ;
return true ;
V_338:
return false ;
}
static inline void F_185 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_293 * V_293 = F_9 ( V_2 ) ;
T_4 V_345 ;
T_3 V_22 ;
V_345 = V_293 -> V_71 . V_346 ;
V_22 = V_23 - V_6 -> V_294 . V_301 ;
if ( F_51 ( V_22 >= V_345 * V_347 ) ) {
int V_19 = F_61 ( V_2 ) ;
V_6 -> V_294 . V_300 = 0 ;
V_6 -> V_294 . V_297 = V_8 -> V_59 . V_290 +
sizeof( struct V_76 ) +
V_6 -> V_201 -> V_288 ;
V_6 -> V_294 . V_298 = F_156 ( V_2 , V_19 ) ;
V_6 -> V_294 . V_301 = V_23 ;
}
}
static int F_186 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_348 , * V_349 ;
struct V_293 * V_293 = F_9 ( V_2 ) ;
int V_81 ;
int V_300 ;
int V_350 ;
int V_351 ;
int V_252 ;
int V_345 ;
if ( ! V_6 -> V_294 . V_295 ||
V_6 -> V_294 . V_300 ||
F_2 ( V_2 ) -> V_305 != V_306 ||
V_8 -> V_27 < 11 ||
V_8 -> V_59 . V_174 || V_8 -> V_59 . V_126 )
return - 1 ;
V_252 = F_61 ( V_2 ) ;
V_300 = F_155 ( V_2 , ( V_6 -> V_294 . V_297 +
V_6 -> V_294 . V_298 ) >> 1 ) ;
V_350 = V_300 + ( V_8 -> V_352 + 1 ) * V_8 -> V_303 ;
V_345 = V_6 -> V_294 . V_297 - V_6 -> V_294 . V_298 ;
if ( V_300 > F_155 ( V_2 , V_6 -> V_294 . V_297 ) ||
V_345 < V_293 -> V_71 . V_353 ) {
F_185 ( V_2 ) ;
return - 1 ;
}
if ( V_8 -> V_250 - V_8 -> V_11 < V_350 )
return - 1 ;
if ( V_8 -> V_343 < V_350 )
return - 1 ;
if ( F_112 ( V_8 -> V_11 + V_350 , F_12 ( V_8 ) ) )
return 0 ;
if ( F_103 ( V_8 ) + 2 > V_8 -> V_27 ) {
if ( ! F_103 ( V_8 ) )
return - 1 ;
else
return 0 ;
}
V_348 = F_136 ( V_2 , V_300 , V_183 ) ;
if ( ! V_348 )
return - 1 ;
V_2 -> V_251 += V_348 -> V_206 ;
F_120 ( V_2 , V_348 -> V_206 ) ;
V_4 = F_177 ( V_2 ) ;
F_5 ( V_348 ) -> V_82 = F_5 ( V_4 ) -> V_82 ;
F_5 ( V_348 ) -> V_12 = F_5 ( V_4 ) -> V_82 + V_300 ;
F_5 ( V_348 ) -> V_65 = V_239 ;
F_5 ( V_348 ) -> V_94 = 0 ;
V_348 -> V_93 = 0 ;
V_348 -> V_91 = V_4 -> V_91 ;
F_187 ( V_348 , V_4 , V_2 ) ;
V_81 = 0 ;
F_188 (skb, next, sk) {
V_351 = F_30 ( int , V_4 -> V_81 , V_300 - V_81 ) ;
if ( V_348 -> V_91 )
F_189 ( V_4 , 0 , F_138 ( V_348 , V_351 ) , V_351 ) ;
else
V_348 -> V_93 = F_190 ( V_4 , 0 ,
F_138 ( V_348 , V_351 ) ,
V_351 , V_348 -> V_93 ) ;
if ( V_4 -> V_81 <= V_351 ) {
F_5 ( V_348 ) -> V_65 |= F_5 ( V_4 ) -> V_65 ;
F_191 ( V_4 , V_2 ) ;
F_192 ( V_2 , V_4 ) ;
} else {
F_5 ( V_348 ) -> V_65 |= F_5 ( V_4 ) -> V_65 &
~ ( V_97 | V_278 ) ;
if ( ! F_45 ( V_4 ) -> V_279 ) {
F_193 ( V_4 , V_351 ) ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_194 ( V_4 -> V_184 ,
V_4 -> V_81 , 0 ) ;
} else {
F_143 ( V_4 , V_351 ) ;
F_121 ( V_2 , V_4 , V_252 ) ;
}
F_5 ( V_4 ) -> V_82 += V_351 ;
}
V_81 += V_351 ;
if ( V_81 >= V_300 )
break;
}
F_172 ( V_2 , V_348 , V_348 -> V_81 ) ;
if ( ! F_96 ( V_2 , V_348 , 1 , V_183 ) ) {
V_8 -> V_27 -- ;
F_1 ( V_2 , V_348 ) ;
V_6 -> V_294 . V_300 = F_156 ( V_2 , V_348 -> V_81 ) ;
V_8 -> V_354 . V_355 = F_5 ( V_348 ) -> V_82 ;
V_8 -> V_354 . V_356 = F_5 ( V_348 ) -> V_12 ;
return 1 ;
}
return - 1 ;
}
static bool F_60 ( struct V_1 * V_2 , unsigned int V_252 , int V_182 ,
int V_357 , T_10 V_271 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_329 , V_358 ;
int V_332 ;
int V_359 ;
bool V_311 = false ;
T_4 V_324 ;
V_358 = 0 ;
if ( ! V_357 ) {
V_359 = F_186 ( V_2 ) ;
if ( ! V_359 ) {
return false ;
} else if ( V_359 > 0 ) {
V_358 = 1 ;
}
}
V_324 = F_168 ( V_2 , V_252 ) ;
while ( ( V_4 = F_177 ( V_2 ) ) ) {
unsigned int V_336 ;
V_329 = F_172 ( V_2 , V_4 , V_252 ) ;
F_97 ( ! V_329 ) ;
if ( F_51 ( V_8 -> V_360 ) && V_8 -> V_361 == V_362 ) {
F_98 ( & V_4 -> V_220 ) ;
goto V_360;
}
V_332 = F_171 ( V_8 , V_4 ) ;
if ( ! V_332 ) {
V_311 = true ;
if ( V_357 == 2 )
V_332 = 1 ;
else
break;
}
if ( F_51 ( ! F_174 ( V_8 , V_4 , V_252 ) ) )
break;
if ( V_329 == 1 || ! V_324 ) {
if ( F_51 ( ! F_173 ( V_8 , V_4 , V_252 ,
( F_178 ( V_2 , V_4 ) ?
V_182 : V_331 ) ) ) )
break;
} else {
if ( ! V_357 &&
F_180 ( V_2 , V_4 , & V_311 ,
V_324 ) )
break;
}
V_336 = V_252 ;
if ( V_329 > 1 && V_324 && ! F_49 ( V_8 ) )
V_336 = F_169 ( V_2 , V_4 , V_252 ,
F_30 (unsigned int,
cwnd_quota,
max_segs) ,
V_182 ) ;
if ( V_4 -> V_81 > V_336 &&
F_51 ( F_179 ( V_2 , V_4 , V_336 , V_252 , V_271 ) ) )
break;
V_336 = F_21 ( 2 * V_4 -> V_206 , V_2 -> V_319 >> 10 ) ;
V_336 = F_30 ( T_4 , V_336 , V_363 ) ;
if ( F_195 ( & V_2 -> V_207 ) > V_336 ) {
F_72 ( V_210 , & V_8 -> V_194 ) ;
F_196 () ;
if ( F_195 ( & V_2 -> V_207 ) > V_336 )
break;
}
if ( F_51 ( F_96 ( V_2 , V_4 , 1 , V_271 ) ) )
break;
V_360:
F_1 ( V_2 , V_4 ) ;
F_166 ( V_8 , V_252 , V_4 ) ;
V_358 += F_6 ( V_4 ) ;
if ( V_357 )
break;
}
if ( F_53 ( V_358 ) ) {
if ( F_197 ( V_2 ) )
V_8 -> V_364 += V_358 ;
if ( V_357 != 2 )
F_198 ( V_2 ) ;
F_163 ( V_2 , V_311 ) ;
return false ;
}
return ( V_357 == 2 ) || ( ! V_8 -> V_10 && F_177 ( V_2 ) ) ;
}
bool F_198 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_4 V_365 , V_366 , V_367 ;
T_4 V_368 = F_199 ( V_8 -> V_344 >> 3 ) ;
if ( F_133 ( V_6 -> V_13 == V_14 ) )
return false ;
if ( F_133 ( V_6 -> V_13 == V_15 ) ) {
F_7 ( V_2 ) ;
return false ;
}
if ( V_2 -> V_176 == V_369 )
return false ;
if ( V_6 -> V_13 != V_370 )
return false ;
if ( V_371 < 3 || ! V_8 -> V_344 || ! V_8 -> V_10 ||
! F_200 ( V_8 ) || F_2 ( V_2 ) -> V_305 != V_306 )
return false ;
if ( ( V_8 -> V_27 > F_103 ( V_8 ) ) &&
F_177 ( V_2 ) )
return false ;
V_365 = V_368 << 1 ;
if ( V_8 -> V_10 == 1 )
V_365 = F_29 ( T_4 , V_365 ,
( V_368 + ( V_368 >> 1 ) + V_372 ) ) ;
V_365 = F_29 ( T_4 , V_365 , F_201 ( 10 ) ) ;
V_366 = V_23 + V_365 ;
V_367 = ( T_4 ) F_2 ( V_2 ) -> V_373 ;
if ( ( T_3 ) ( V_366 - V_367 ) > 0 ) {
T_3 V_22 = V_367 - V_23 ;
if ( V_22 > 0 )
V_365 = V_22 ;
}
F_202 ( V_2 , V_15 , V_365 ,
V_374 ) ;
return true ;
}
static bool F_203 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_51 ( F_204 ( V_2 , V_4 ) ) ) {
F_205 ( F_9 ( V_2 ) ,
V_375 ) ;
return true ;
}
return false ;
}
void F_206 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
int V_376 ;
int V_19 = F_61 ( V_2 ) ;
int V_219 = - 1 ;
if ( F_177 ( V_2 ) ) {
V_219 = F_60 ( V_2 , V_19 , V_377 , 2 , V_183 ) ;
goto V_378;
}
if ( V_8 -> V_379 )
goto V_378;
V_4 = F_170 ( V_2 ) ;
if ( F_133 ( ! V_4 ) )
goto V_378;
if ( F_203 ( V_2 , V_4 ) )
goto V_378;
V_376 = F_6 ( V_4 ) ;
if ( F_133 ( ! V_376 ) )
goto V_378;
if ( ( V_376 > 1 ) && ( V_4 -> V_81 > ( V_376 - 1 ) * V_19 ) ) {
if ( F_51 ( F_132 ( V_2 , V_4 , ( V_376 - 1 ) * V_19 , V_19 ,
V_183 ) ) )
goto V_378;
V_4 = F_170 ( V_2 ) ;
}
if ( F_133 ( ! V_4 || ! F_6 ( V_4 ) ) )
goto V_378;
V_219 = F_207 ( V_2 , V_4 ) ;
if ( F_53 ( ! V_219 ) )
V_8 -> V_379 = V_8 -> V_11 ;
V_378:
F_202 ( V_2 , V_370 ,
F_2 ( V_2 ) -> V_30 ,
V_374 ) ;
if ( F_53 ( ! V_219 ) )
F_205 ( F_9 ( V_2 ) ,
V_380 ) ;
}
void F_208 ( struct V_1 * V_2 , unsigned int V_330 ,
int V_182 )
{
if ( F_51 ( V_2 -> V_176 == V_381 ) )
return;
if ( F_60 ( V_2 , V_330 , V_182 , 0 ,
F_209 ( V_2 , V_183 ) ) )
F_210 ( V_2 ) ;
}
void F_211 ( struct V_1 * V_2 , unsigned int V_252 )
{
struct V_3 * V_4 = F_177 ( V_2 ) ;
F_97 ( ! V_4 || V_4 -> V_81 < V_252 ) ;
F_60 ( V_2 , V_252 , V_331 , 1 , V_2 -> V_382 ) ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_19 = V_6 -> V_35 . V_383 ;
int V_384 = F_212 ( V_2 ) ;
int V_385 = F_213 ( V_2 ) ;
int V_386 = F_30 ( int , V_8 -> V_46 , V_385 ) ;
int V_232 ;
if ( V_19 > V_386 )
V_19 = V_386 ;
if ( V_384 < ( V_386 >> 1 ) ) {
V_6 -> V_35 . V_387 = 0 ;
if ( F_214 ( V_2 ) )
V_8 -> V_388 = F_20 ( V_8 -> V_388 ,
4U * V_8 -> V_20 ) ;
V_384 = F_215 ( V_384 , 1 << V_8 -> V_59 . V_48 ) ;
if ( V_384 < ( V_385 >> 4 ) || V_384 < V_19 )
return 0 ;
}
if ( V_384 > V_8 -> V_388 )
V_384 = V_8 -> V_388 ;
V_232 = V_8 -> V_45 ;
if ( V_8 -> V_59 . V_48 ) {
V_232 = V_384 ;
if ( ( ( V_232 >> V_8 -> V_59 . V_48 ) << V_8 -> V_59 . V_48 ) != V_232 )
V_232 = ( ( ( V_232 >> V_8 -> V_59 . V_48 ) + 1 )
<< V_8 -> V_59 . V_48 ) ;
} else {
if ( V_232 <= V_384 - V_19 || V_232 > V_384 )
V_232 = ( V_384 / V_19 ) * V_19 ;
else if ( V_19 == V_386 &&
V_384 > V_232 + ( V_386 >> 1 ) )
V_232 = V_384 ;
}
return V_232 ;
}
static void F_216 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_389 = F_217 ( V_2 , V_4 ) ;
int V_390 , V_391 ;
V_390 = V_4 -> V_81 ;
V_391 = V_389 -> V_81 ;
F_97 ( F_6 ( V_4 ) != 1 || F_6 ( V_389 ) != 1 ) ;
F_218 ( V_2 , V_389 , V_4 ) ;
F_191 ( V_389 , V_2 ) ;
F_219 ( V_389 , F_138 ( V_4 , V_391 ) ,
V_391 ) ;
if ( V_389 -> V_91 == V_92 )
V_4 -> V_91 = V_92 ;
if ( V_4 -> V_91 != V_92 )
V_4 -> V_93 = F_220 ( V_4 -> V_93 , V_389 -> V_93 , V_390 ) ;
F_5 ( V_4 ) -> V_12 = F_5 ( V_389 ) -> V_12 ;
F_5 ( V_4 ) -> V_65 |= F_5 ( V_389 ) -> V_65 ;
F_5 ( V_4 ) -> V_94 |= F_5 ( V_389 ) -> V_94 & V_392 ;
F_221 ( V_8 ) ;
if ( V_389 == V_8 -> V_393 )
V_8 -> V_393 = V_4 ;
F_127 ( V_2 , V_389 , F_6 ( V_389 ) ) ;
F_192 ( V_2 , V_389 ) ;
}
static bool F_222 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) > 1 )
return false ;
if ( F_45 ( V_4 ) -> V_279 != 0 )
return false ;
if ( F_99 ( V_4 ) )
return false ;
if ( V_4 == F_177 ( V_2 ) )
return false ;
if ( F_5 ( V_4 ) -> V_94 & V_258 )
return false ;
return true ;
}
static void F_223 ( struct V_1 * V_2 , struct V_3 * V_394 ,
int V_50 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 = V_394 , * V_395 ;
bool V_396 = true ;
if ( ! V_397 )
return;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
return;
F_188 (skb, tmp, sk) {
if ( ! F_222 ( V_2 , V_4 ) )
break;
V_50 -= V_4 -> V_81 ;
if ( V_396 ) {
V_396 = false ;
continue;
}
if ( V_50 < 0 )
break;
if ( V_4 -> V_81 > F_224 ( V_394 ) )
break;
if ( F_112 ( F_5 ( V_4 ) -> V_12 , F_12 ( V_8 ) ) )
break;
F_216 ( V_2 , V_394 ) ;
}
}
int F_207 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_330 ;
int V_219 ;
if ( V_6 -> V_294 . V_300 ) {
V_6 -> V_294 . V_300 = 0 ;
}
if ( F_195 ( & V_2 -> V_207 ) >
F_20 ( V_2 -> V_251 + ( V_2 -> V_251 >> 2 ) , V_2 -> V_398 ) )
return - V_399 ;
if ( F_203 ( V_2 , V_4 ) )
return - V_400 ;
if ( F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_98 ) ) {
if ( F_11 ( F_5 ( V_4 ) -> V_12 , V_8 -> V_98 ) )
F_225 () ;
if ( F_149 ( V_2 , V_4 , V_8 -> V_98 - F_5 ( V_4 ) -> V_82 ) )
return - V_277 ;
}
if ( F_2 ( V_2 ) -> V_201 -> V_401 ( V_2 ) )
return - V_402 ;
V_330 = F_61 ( V_2 ) ;
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) &&
F_5 ( V_4 ) -> V_82 != V_8 -> V_98 )
return - V_399 ;
if ( V_4 -> V_81 > V_330 ) {
if ( F_132 ( V_2 , V_4 , V_330 , V_330 , V_183 ) )
return - V_277 ;
} else {
int V_403 = F_6 ( V_4 ) ;
if ( F_51 ( V_403 > 1 ) ) {
if ( F_135 ( V_4 , V_183 ) )
return - V_277 ;
F_172 ( V_2 , V_4 , V_330 ) ;
F_127 ( V_2 , V_4 , V_403 - F_6 ( V_4 ) ) ;
}
}
F_223 ( V_2 , V_4 , V_330 ) ;
if ( F_51 ( ( V_404 && ( ( unsigned long ) V_4 -> V_184 & 3 ) ) ||
F_226 ( V_4 ) >= 0xFFFF ) ) {
struct V_3 * V_348 = F_227 ( V_4 , V_321 ,
V_183 ) ;
V_219 = V_348 ? F_96 ( V_2 , V_348 , 0 , V_183 ) :
- V_221 ;
} else {
V_219 = F_96 ( V_2 , V_4 , 1 , V_183 ) ;
}
if ( F_53 ( ! V_219 ) ) {
F_5 ( V_4 ) -> V_94 |= V_392 ;
F_228 ( F_9 ( V_2 ) , V_405 ) ;
if ( F_5 ( V_4 ) -> V_65 & V_96 )
F_205 ( F_9 ( V_2 ) , V_406 ) ;
V_8 -> V_407 ++ ;
}
return V_219 ;
}
int F_229 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_219 = F_207 ( V_2 , V_4 ) ;
if ( V_219 == 0 ) {
#if V_408 > 0
if ( F_5 ( V_4 ) -> V_94 & V_259 ) {
F_230 ( L_1 ) ;
}
#endif
if ( ! V_8 -> V_260 )
V_8 -> V_409 = V_8 -> V_11 ;
F_5 ( V_4 ) -> V_94 |= V_410 ;
V_8 -> V_260 += F_6 ( V_4 ) ;
if ( ! V_8 -> V_411 )
V_8 -> V_411 = F_56 ( V_4 ) ;
F_5 ( V_4 ) -> V_230 = V_8 -> V_11 ;
} else if ( V_219 != - V_400 ) {
F_205 ( F_9 ( V_2 ) , V_412 ) ;
}
if ( V_8 -> V_413 < 0 )
V_8 -> V_413 = 0 ;
V_8 -> V_413 += F_6 ( V_4 ) ;
return V_219 ;
}
static bool F_231 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_305 != V_414 )
return false ;
if ( F_125 ( V_8 ) )
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
struct V_3 * V_415 = NULL ;
T_4 V_416 ;
int V_417 ;
int V_418 = 0 ;
if ( ! V_8 -> V_10 )
return;
if ( ! V_8 -> V_262 )
V_8 -> V_419 = V_8 -> V_98 ;
if ( V_8 -> V_393 ) {
V_4 = V_8 -> V_393 ;
V_416 = F_5 ( V_4 ) -> V_12 ;
if ( F_112 ( V_416 , V_8 -> V_419 ) )
V_416 = V_8 -> V_419 ;
} else {
V_4 = F_183 ( V_2 ) ;
V_416 = V_8 -> V_98 ;
}
F_233 (skb, sk) {
T_5 V_94 = F_5 ( V_4 ) -> V_94 ;
if ( V_4 == F_177 ( V_2 ) )
break;
if ( ! V_415 )
V_8 -> V_393 = V_4 ;
if ( F_103 ( V_8 ) >= V_8 -> V_27 )
return;
if ( V_418 ) {
V_420:
if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , F_126 ( V_8 ) ) )
break;
V_417 = V_421 ;
} else if ( ! F_11 ( F_5 ( V_4 ) -> V_82 , V_8 -> V_419 ) ) {
V_8 -> V_419 = V_416 ;
if ( ! F_231 ( V_2 ) )
break;
if ( V_415 ) {
V_4 = V_415 ;
V_415 = NULL ;
}
V_418 = 1 ;
goto V_420;
} else if ( ! ( V_94 & V_261 ) ) {
if ( ! V_415 && ! ( V_94 & ( V_259 | V_258 ) ) )
V_415 = V_4 ;
continue;
} else {
V_416 = F_5 ( V_4 ) -> V_12 ;
if ( V_6 -> V_305 != V_422 )
V_417 = V_423 ;
else
V_417 = V_424 ;
}
if ( V_94 & ( V_258 | V_259 ) )
continue;
if ( F_229 ( V_2 , V_4 ) )
return;
F_205 ( F_9 ( V_2 ) , V_417 ) ;
if ( F_197 ( V_2 ) )
V_8 -> V_364 += F_6 ( V_4 ) ;
if ( V_4 == F_183 ( V_2 ) )
F_202 ( V_2 , V_370 ,
F_2 ( V_2 ) -> V_30 ,
V_374 ) ;
}
}
static void F_234 ( struct V_1 * V_2 , int V_172 )
{
int V_425 , V_426 ;
if ( V_172 <= V_2 -> V_427 )
return;
V_425 = F_235 ( V_172 ) ;
V_2 -> V_427 += V_425 * V_428 ;
F_236 ( V_2 , V_425 , & V_426 ) ;
}
void F_237 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_429 = F_170 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
if ( V_429 && ( F_177 ( V_2 ) || F_214 ( V_2 ) ) ) {
V_430:
F_5 ( V_429 ) -> V_65 |= V_97 ;
F_5 ( V_429 ) -> V_12 ++ ;
V_8 -> V_250 ++ ;
if ( ! F_177 ( V_2 ) ) {
V_8 -> V_11 ++ ;
return;
}
} else {
V_4 = F_238 ( V_321 , V_2 -> V_382 ) ;
if ( F_51 ( ! V_4 ) ) {
if ( V_429 )
goto V_430;
return;
}
F_239 ( V_4 , V_321 ) ;
F_234 ( V_2 , V_4 -> V_206 ) ;
F_47 ( V_4 , V_8 -> V_250 ,
V_239 | V_97 ) ;
F_117 ( V_2 , V_4 ) ;
}
F_208 ( V_2 , F_61 ( V_2 ) , V_377 ) ;
}
void F_240 ( struct V_1 * V_2 , T_10 V_431 )
{
struct V_3 * V_4 ;
V_4 = F_241 ( V_321 , V_431 ) ;
if ( ! V_4 ) {
F_34 ( F_9 ( V_2 ) , V_432 ) ;
return;
}
F_239 ( V_4 , V_321 ) ;
F_47 ( V_4 , F_10 ( V_2 ) ,
V_239 | V_433 ) ;
if ( F_96 ( V_2 , V_4 , 0 , V_431 ) )
F_34 ( F_9 ( V_2 ) , V_432 ) ;
F_228 ( F_9 ( V_2 ) , V_434 ) ;
}
int F_242 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_183 ( V_2 ) ;
if ( ! V_4 || ! ( F_5 ( V_4 ) -> V_65 & V_96 ) ) {
F_243 ( L_2 , V_435 ) ;
return - V_436 ;
}
if ( ! ( F_5 ( V_4 ) -> V_65 & V_239 ) ) {
if ( F_99 ( V_4 ) ) {
struct V_3 * V_348 = F_244 ( V_4 , V_183 ) ;
if ( ! V_348 )
return - V_277 ;
F_191 ( V_4 , V_2 ) ;
F_118 ( V_348 ) ;
F_245 ( V_2 , V_348 ) ;
F_192 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_348 -> V_206 ;
F_120 ( V_2 , V_348 -> V_206 ) ;
V_4 = V_348 ;
}
F_5 ( V_4 ) -> V_65 |= V_239 ;
F_36 ( V_2 , V_4 ) ;
}
return F_96 ( V_2 , V_4 , 1 , V_183 ) ;
}
struct V_3 * F_246 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_74 * V_75 ,
struct V_135 * V_136 )
{
struct V_101 V_102 ;
struct V_168 * V_169 = F_42 ( V_75 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_76 * V_77 ;
struct V_3 * V_4 ;
struct V_145 * V_146 = NULL ;
int V_218 ;
int V_19 ;
V_4 = F_247 ( V_2 , V_321 , 1 , V_183 ) ;
if ( F_51 ( ! V_4 ) ) {
F_248 ( V_18 ) ;
return NULL ;
}
F_239 ( V_4 , V_321 ) ;
F_249 ( V_4 , V_18 ) ;
V_19 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_437 && V_8 -> V_59 . V_437 < V_19 )
V_19 = V_8 -> V_59 . V_437 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
#ifdef F_250
if ( F_51 ( V_75 -> V_438 ) )
V_4 -> V_220 . V_439 = F_251 ( V_75 ) ;
else
#endif
F_98 ( & V_4 -> V_220 ) ;
#ifdef F_55
F_252 () ;
V_146 = F_253 ( V_75 ) -> V_152 -> V_440 ( V_2 , F_254 ( V_75 ) ) ;
#endif
V_218 = F_57 ( V_2 , V_75 , V_19 , V_4 , & V_102 , V_146 ,
V_136 ) + sizeof( * V_77 ) ;
F_105 ( V_4 , V_218 ) ;
F_106 ( V_4 ) ;
V_77 = F_44 ( V_4 ) ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_441 = 1 ;
V_77 -> V_442 = 1 ;
F_41 ( V_75 , V_77 , V_2 ) ;
V_77 -> V_226 = F_111 ( V_169 -> V_443 ) ;
V_77 -> V_228 = V_169 -> V_444 ;
F_47 ( V_4 , F_253 ( V_75 ) -> V_445 ,
V_96 | V_239 ) ;
V_77 -> V_82 = F_52 ( F_5 ( V_4 ) -> V_82 ) ;
V_77 -> V_230 = F_52 ( F_253 ( V_75 ) -> V_61 ) ;
V_77 -> V_232 = F_111 ( F_20 ( V_75 -> V_45 , 65535U ) ) ;
F_50 ( ( T_8 * ) ( V_77 + 1 ) , V_8 , & V_102 ) ;
V_77 -> V_446 = ( V_218 >> 2 ) ;
F_255 ( F_9 ( V_2 ) , V_240 ) ;
#ifdef F_55
if ( V_146 )
F_253 ( V_75 ) -> V_152 -> V_237 ( V_102 . V_108 ,
V_146 , F_254 ( V_75 ) , V_4 ) ;
F_256 () ;
#endif
V_4 -> V_242 . V_243 = 0 ;
return V_4 ;
}
static void F_257 ( struct V_1 * V_2 , const struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_447 * V_448 ;
T_4 V_449 = F_23 ( V_18 , V_450 ) ;
if ( V_449 == V_451 )
return;
F_252 () ;
V_448 = F_258 ( V_449 ) ;
if ( F_53 ( V_448 && F_259 ( V_448 -> V_452 ) ) ) {
F_260 ( V_6 -> V_453 -> V_452 ) ;
V_6 -> V_454 = F_261 ( V_18 ) ;
V_6 -> V_453 = V_448 ;
}
F_256 () ;
}
static void F_262 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_5 V_48 ;
V_8 -> V_80 = sizeof( struct V_76 ) +
( V_156 ? V_159 : 0 ) ;
#ifdef F_55
if ( V_8 -> V_152 -> V_153 ( V_2 , V_2 ) )
V_8 -> V_80 += V_154 ;
#endif
if ( V_8 -> V_59 . V_437 )
V_8 -> V_59 . V_290 = V_8 -> V_59 . V_437 ;
V_8 -> V_455 = 0 ;
F_157 ( V_2 ) ;
F_158 ( V_2 , F_160 ( V_18 ) ) ;
F_257 ( V_2 , V_18 ) ;
if ( ! V_8 -> V_46 )
V_8 -> V_46 = F_23 ( V_18 , V_456 ) ;
V_8 -> V_20 = F_15 ( V_18 ) ;
if ( V_8 -> V_59 . V_437 && V_8 -> V_59 . V_437 < V_8 -> V_20 )
V_8 -> V_20 = V_8 -> V_59 . V_437 ;
F_263 ( V_2 ) ;
if ( V_2 -> V_457 & V_458 &&
( V_8 -> V_46 > F_213 ( V_2 ) || V_8 -> V_46 == 0 ) )
V_8 -> V_46 = F_213 ( V_2 ) ;
F_28 ( F_213 ( V_2 ) ,
V_8 -> V_20 - ( V_8 -> V_59 . V_459 ? V_8 -> V_80 - sizeof( struct V_76 ) : 0 ) ,
& V_8 -> V_45 ,
& V_8 -> V_46 ,
V_160 ,
& V_48 ,
F_23 ( V_18 , V_460 ) ) ;
V_8 -> V_59 . V_48 = V_48 ;
V_8 -> V_388 = V_8 -> V_45 ;
V_2 -> V_461 = 0 ;
F_264 ( V_2 , V_462 ) ;
V_8 -> V_343 = 0 ;
F_265 ( V_8 , 0 ) ;
V_8 -> V_98 = V_8 -> V_250 ;
V_8 -> V_314 = V_8 -> V_250 ;
V_8 -> V_99 = V_8 -> V_250 ;
V_8 -> V_11 = V_8 -> V_250 ;
if ( F_53 ( ! V_8 -> V_360 ) )
V_8 -> V_61 = 0 ;
else
V_8 -> V_463 = V_23 ;
V_8 -> V_60 = V_8 -> V_61 ;
V_8 -> V_464 = V_8 -> V_61 ;
F_2 ( V_2 ) -> V_30 = V_465 ;
F_2 ( V_2 ) -> V_466 = 0 ;
F_266 ( V_8 ) ;
}
static void F_267 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_215 * V_216 = F_5 ( V_4 ) ;
V_216 -> V_12 += V_4 -> V_81 ;
F_118 ( V_4 ) ;
F_268 ( V_2 , V_4 ) ;
V_2 -> V_251 += V_4 -> V_206 ;
F_120 ( V_2 , V_4 -> V_206 ) ;
V_8 -> V_250 = V_216 -> V_12 ;
V_8 -> V_10 += F_6 ( V_4 ) ;
}
static int F_269 ( struct V_1 * V_2 , struct V_3 * V_441 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_149 * V_467 = V_8 -> V_151 ;
int V_468 = 0 , V_50 , V_219 = 0 , V_469 ;
unsigned long V_470 = 0 ;
struct V_3 * V_471 ;
V_8 -> V_59 . V_290 = V_8 -> V_20 ;
F_270 ( V_2 , & V_8 -> V_59 . V_290 , & V_467 -> V_164 ,
& V_468 , & V_470 ) ;
if ( V_468 > 1 &&
F_271 ( V_472 , V_470 + ( 60 * V_347 << V_468 ) ) ) {
V_467 -> V_164 . V_81 = - 1 ;
goto V_473;
}
if ( V_474 & V_475 )
V_467 -> V_164 . V_81 = - 1 ;
else if ( V_467 -> V_164 . V_81 <= 0 )
goto V_473;
if ( V_8 -> V_59 . V_437 && V_8 -> V_59 . V_437 < V_8 -> V_59 . V_290 )
V_8 -> V_59 . V_290 = V_8 -> V_59 . V_437 ;
V_50 = F_153 ( V_2 , F_2 ( V_2 ) -> V_302 ) -
V_148 ;
V_50 = F_30 ( V_476 , V_50 , V_467 -> V_172 ) ;
V_50 = F_30 ( V_476 , V_50 , F_272 ( V_321 ) ) ;
V_471 = F_136 ( V_2 , V_50 , V_2 -> V_382 ) ;
if ( ! V_471 )
goto V_473;
V_471 -> V_91 = V_92 ;
memcpy ( V_471 -> V_244 , V_441 -> V_244 , sizeof( V_441 -> V_244 ) ) ;
V_469 = F_273 ( F_138 ( V_471 , V_50 ) , V_50 ,
& V_467 -> V_184 -> V_477 ) ;
if ( F_51 ( ! V_469 ) ) {
F_274 ( V_471 ) ;
goto V_473;
}
if ( V_469 != V_50 ) {
F_139 ( V_471 , V_469 ) ;
V_50 = V_469 ;
}
if ( V_50 == V_467 -> V_172 )
V_467 -> V_184 = NULL ;
V_467 -> V_469 = V_50 ;
F_267 ( V_2 , V_471 ) ;
V_219 = F_96 ( V_2 , V_471 , 1 , V_2 -> V_382 ) ;
V_441 -> V_220 = V_471 -> V_220 ;
F_5 ( V_471 ) -> V_82 ++ ;
F_5 ( V_471 ) -> V_65 = V_239 | V_278 ;
if ( ! V_219 ) {
V_8 -> V_471 = ( V_467 -> V_469 > 0 ) ;
F_34 ( F_9 ( V_2 ) , V_16 ) ;
goto V_478;
}
V_473:
if ( V_467 -> V_164 . V_81 > 0 )
V_467 -> V_164 . V_81 = 0 ;
V_219 = F_96 ( V_2 , V_441 , 1 , V_2 -> V_382 ) ;
if ( V_219 )
V_8 -> V_166 = 0 ;
V_478:
V_467 -> V_164 . V_81 = - 1 ;
return V_219 ;
}
int F_275 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_272 ;
int V_219 ;
F_262 ( V_2 ) ;
if ( F_51 ( V_8 -> V_360 ) ) {
F_276 ( V_2 , NULL ) ;
return 0 ;
}
V_272 = F_136 ( V_2 , 0 , V_2 -> V_382 ) ;
if ( F_51 ( ! V_272 ) )
return - V_221 ;
F_47 ( V_272 , V_8 -> V_250 ++ , V_96 ) ;
V_8 -> V_411 = V_23 ;
F_267 ( V_2 , V_272 ) ;
F_39 ( V_2 , V_272 ) ;
V_219 = V_8 -> V_151 ? F_269 ( V_2 , V_272 ) :
F_96 ( V_2 , V_272 , 1 , V_2 -> V_382 ) ;
if ( V_219 == - V_479 )
return V_219 ;
V_8 -> V_11 = V_8 -> V_250 ;
V_8 -> V_480 = V_8 -> V_250 ;
F_228 ( F_9 ( V_2 ) , V_481 ) ;
F_202 ( V_2 , V_370 ,
F_2 ( V_2 ) -> V_30 , V_374 ) ;
return 0 ;
}
void F_277 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 = V_6 -> V_35 . V_37 ;
unsigned long V_365 ;
F_18 ( V_2 , V_482 ) ;
if ( V_37 > V_483 ) {
const struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_484 = V_347 / 2 ;
if ( V_6 -> V_35 . V_39 ||
( V_6 -> V_35 . V_485 & V_486 ) )
V_484 = V_372 ;
if ( V_8 -> V_344 ) {
int V_368 = F_29 ( int , F_199 ( V_8 -> V_344 >> 3 ) ,
V_483 ) ;
if ( V_368 < V_484 )
V_484 = V_368 ;
}
V_37 = F_20 ( V_37 , V_484 ) ;
}
V_365 = V_472 + V_37 ;
if ( V_6 -> V_35 . V_485 & V_487 ) {
if ( V_6 -> V_35 . V_488 ||
F_278 ( V_6 -> V_35 . V_365 , V_472 + ( V_37 >> 2 ) ) ) {
F_279 ( V_2 ) ;
return;
}
if ( ! F_271 ( V_365 , V_6 -> V_35 . V_365 ) )
V_365 = V_6 -> V_35 . V_365 ;
}
V_6 -> V_35 . V_485 |= V_489 | V_487 ;
V_6 -> V_35 . V_365 = V_365 ;
F_280 ( V_2 , & V_6 -> V_490 , V_365 ) ;
}
void F_279 ( struct V_1 * V_2 )
{
struct V_3 * V_272 ;
if ( V_2 -> V_176 == V_381 )
return;
F_18 ( V_2 , V_491 ) ;
V_272 = F_241 ( V_321 , F_209 ( V_2 , V_183 ) ) ;
if ( ! V_272 ) {
F_281 ( V_2 ) ;
F_2 ( V_2 ) -> V_35 . V_37 = V_492 ;
F_202 ( V_2 , V_41 ,
V_372 , V_374 ) ;
return;
}
F_239 ( V_272 , V_321 ) ;
F_47 ( V_272 , F_10 ( V_2 ) , V_239 ) ;
F_282 ( V_272 ) ;
F_98 ( & V_272 -> V_220 ) ;
F_96 ( V_2 , V_272 , 0 , F_209 ( V_2 , V_183 ) ) ;
}
static int F_283 ( struct V_1 * V_2 , int V_493 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_241 ( V_321 , F_209 ( V_2 , V_183 ) ) ;
if ( ! V_4 )
return - 1 ;
F_239 ( V_4 , V_321 ) ;
F_47 ( V_4 , V_8 -> V_98 - ! V_493 , V_239 ) ;
F_98 ( & V_4 -> V_220 ) ;
return F_96 ( V_2 , V_4 , 0 , V_183 ) ;
}
void F_284 ( struct V_1 * V_2 )
{
if ( V_2 -> V_176 == V_494 ) {
F_3 ( V_2 ) -> V_495 = F_3 ( V_2 ) -> V_61 - 1 ;
F_283 ( V_2 , 0 ) ;
}
}
int F_285 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_176 == V_381 )
return - 1 ;
V_4 = F_177 ( V_2 ) ;
if ( V_4 && F_11 ( F_5 ( V_4 ) -> V_82 , F_12 ( V_8 ) ) ) {
int V_219 ;
unsigned int V_19 = F_61 ( V_2 ) ;
unsigned int V_496 = F_12 ( V_8 ) - F_5 ( V_4 ) -> V_82 ;
if ( F_11 ( V_8 -> V_480 , F_5 ( V_4 ) -> V_12 ) )
V_8 -> V_480 = F_5 ( V_4 ) -> V_12 ;
if ( V_496 < F_5 ( V_4 ) -> V_12 - F_5 ( V_4 ) -> V_82 ||
V_4 -> V_81 > V_19 ) {
V_496 = F_20 ( V_496 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_278 ;
if ( F_132 ( V_2 , V_4 , V_496 , V_19 , V_183 ) )
return - 1 ;
} else if ( ! F_6 ( V_4 ) )
F_121 ( V_2 , V_4 , V_19 ) ;
F_5 ( V_4 ) -> V_65 |= V_278 ;
V_219 = F_96 ( V_2 , V_4 , 1 , V_183 ) ;
if ( ! V_219 )
F_1 ( V_2 , V_4 ) ;
return V_219 ;
} else {
if ( F_286 ( V_8 -> V_99 , V_8 -> V_98 + 1 , V_8 -> V_98 + 0xFFFF ) )
F_283 ( V_2 , 1 ) ;
return F_283 ( V_2 , 0 ) ;
}
}
void F_287 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned long V_497 ;
int V_219 ;
V_219 = F_285 ( V_2 ) ;
if ( V_8 -> V_10 || ! F_177 ( V_2 ) ) {
V_6 -> V_498 = 0 ;
V_6 -> V_499 = 0 ;
return;
}
if ( V_219 <= 0 ) {
if ( V_6 -> V_499 < V_500 )
V_6 -> V_499 ++ ;
V_6 -> V_498 ++ ;
V_497 = V_374 ;
} else {
if ( ! V_6 -> V_498 )
V_6 -> V_498 = 1 ;
V_497 = V_501 ;
}
F_202 ( V_2 , V_502 ,
F_288 ( V_6 , V_497 ) ,
V_374 ) ;
}
int F_289 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
const struct V_503 * V_504 = F_253 ( V_75 ) -> V_152 ;
struct V_505 V_249 ;
int V_506 ;
V_506 = V_504 -> V_507 ( V_2 , NULL , & V_249 , V_75 , 0 , NULL ) ;
if ( ! V_506 ) {
F_255 ( F_9 ( V_2 ) , V_405 ) ;
F_205 ( F_9 ( V_2 ) , V_406 ) ;
}
return V_506 ;
}
