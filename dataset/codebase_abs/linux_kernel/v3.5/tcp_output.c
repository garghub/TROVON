static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_6 -> V_8 ;
F_3 ( V_2 , V_4 ) ;
V_6 -> V_9 = F_4 ( V_4 ) -> V_10 ;
if ( V_6 -> V_11 == 2 )
V_6 -> V_11 = 3 ;
V_6 -> V_8 += F_5 ( V_4 ) ;
if ( ! V_7 || V_6 -> V_12 )
F_6 ( V_2 ) ;
}
static inline T_1 F_7 ( const struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_8 ( F_9 ( V_6 ) , V_6 -> V_9 ) )
return V_6 -> V_9 ;
else
return F_9 ( V_6 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = F_11 ( V_2 ) ;
int V_15 = V_6 -> V_16 ;
if ( V_14 ) {
unsigned int V_17 = F_12 ( V_14 ) ;
if ( V_17 < V_15 ) {
V_15 = V_17 ;
V_6 -> V_16 = V_15 ;
}
}
return ( T_2 ) V_15 ;
}
static void F_13 ( struct V_1 * V_2 , const struct V_13 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_18 = V_19 - V_6 -> V_20 ;
T_4 V_21 = F_14 ( V_6 , V_14 ) ;
T_4 V_22 = V_6 -> V_23 ;
F_15 ( V_2 , V_24 ) ;
V_6 -> V_25 = F_16 ( V_2 ) ;
V_21 = F_17 ( V_21 , V_22 ) ;
while ( ( V_18 -= F_18 ( V_2 ) -> V_26 ) > 0 && V_22 > V_21 )
V_22 >>= 1 ;
V_6 -> V_23 = F_19 ( V_22 , V_21 ) ;
V_6 -> V_27 = V_19 ;
V_6 -> V_28 = 0 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
const T_4 V_31 = V_19 ;
if ( V_32 &&
( ! V_6 -> V_8 && ( T_3 ) ( V_31 - V_6 -> V_20 ) > V_30 -> V_26 ) )
F_13 ( V_2 , F_11 ( V_2 ) ) ;
V_6 -> V_20 = V_31 ;
if ( ( T_4 ) ( V_31 - V_30 -> V_33 . V_34 ) < V_30 -> V_33 . V_35 )
V_30 -> V_33 . V_36 = 1 ;
}
static inline void F_21 ( struct V_1 * V_2 , unsigned int V_37 )
{
F_22 ( V_2 , V_37 ) ;
F_23 ( V_2 , V_38 ) ;
}
void F_24 ( int V_39 , T_1 V_15 ,
T_1 * V_40 , T_1 * V_41 ,
int V_42 , T_5 * V_43 ,
T_1 V_44 )
{
unsigned int V_45 = ( V_39 < 0 ? 0 : V_39 ) ;
if ( * V_41 == 0 )
( * V_41 ) = ( 65535 << 14 ) ;
V_45 = F_17 ( * V_41 , V_45 ) ;
if ( V_45 > V_15 )
V_45 = ( V_45 / V_15 ) * V_15 ;
if ( V_46 )
( * V_40 ) = F_17 ( V_45 , V_47 ) ;
else
( * V_40 ) = V_45 ;
( * V_43 ) = 0 ;
if ( V_42 ) {
V_45 = F_25 ( T_4 , V_48 [ 2 ] , V_49 ) ;
V_45 = F_26 ( T_4 , V_45 , * V_41 ) ;
while ( V_45 > 65535 && ( * V_43 ) < 14 ) {
V_45 >>= 1 ;
( * V_43 ) ++ ;
}
}
if ( V_15 > ( 1 << * V_43 ) ) {
int V_50 = V_51 ;
if ( V_15 > 1460 )
V_50 =
F_25 ( T_4 , ( 1460 * V_51 ) / V_15 , 2 ) ;
if ( V_44 )
* V_40 = F_17 ( * V_40 , V_44 * V_15 ) ;
else
* V_40 = F_17 ( * V_40 , V_50 * V_15 ) ;
}
( * V_41 ) = F_17 ( 65535U << ( * V_43 ) , * V_41 ) ;
}
static T_6 F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_52 = F_28 ( V_6 ) ;
T_4 V_53 = F_29 ( V_2 ) ;
if ( V_53 < V_52 ) {
V_53 = F_30 ( V_52 , 1 << V_6 -> V_54 . V_43 ) ;
}
V_6 -> V_40 = V_53 ;
V_6 -> V_55 = V_6 -> V_56 ;
if ( ! V_6 -> V_54 . V_43 && V_46 )
V_53 = F_17 ( V_53 , V_47 ) ;
else
V_53 = F_17 ( V_53 , ( 65535U << V_6 -> V_54 . V_43 ) ) ;
V_53 >>= V_6 -> V_54 . V_43 ;
if ( V_53 == 0 )
V_6 -> V_57 = 0 ;
return V_53 ;
}
static inline void F_31 ( const struct V_5 * V_6 , struct V_3 * V_4 )
{
F_4 ( V_4 ) -> V_58 &= ~ V_59 ;
if ( ! ( V_6 -> V_60 & V_61 ) )
F_4 ( V_4 ) -> V_58 &= ~ V_62 ;
}
static inline void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_60 = 0 ;
if ( V_63 == 1 ) {
F_4 ( V_4 ) -> V_58 |= V_62 | V_59 ;
V_6 -> V_60 = V_61 ;
}
}
static T_7 void
F_33 ( const struct V_64 * V_65 , struct V_66 * V_67 )
{
if ( F_34 ( V_65 ) -> V_68 )
V_67 -> V_69 = 1 ;
}
static inline void F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_60 & V_61 ) {
if ( V_4 -> V_71 != V_70 &&
! F_8 ( F_4 ( V_4 ) -> V_72 , V_6 -> V_9 ) ) {
F_36 ( V_2 ) ;
if ( V_6 -> V_60 & V_73 ) {
V_6 -> V_60 &= ~ V_73 ;
F_37 ( V_4 ) -> V_74 = 1 ;
F_38 ( V_4 ) -> V_75 |= V_76 ;
}
} else {
F_39 ( V_2 ) ;
}
if ( V_6 -> V_60 & V_77 )
F_37 ( V_4 ) -> V_69 = 1 ;
}
}
static void F_40 ( struct V_3 * V_4 , T_4 V_72 , T_8 V_78 )
{
V_4 -> V_79 = V_80 ;
V_4 -> V_81 = 0 ;
F_4 ( V_4 ) -> V_58 = V_78 ;
F_4 ( V_4 ) -> V_82 = 0 ;
F_38 ( V_4 ) -> V_83 = 1 ;
F_38 ( V_4 ) -> V_84 = 0 ;
F_38 ( V_4 ) -> V_75 = 0 ;
F_4 ( V_4 ) -> V_72 = V_72 ;
if ( V_78 & ( V_85 | V_86 ) )
V_72 ++ ;
F_4 ( V_4 ) -> V_10 = V_72 ;
}
static inline bool F_41 ( const struct V_5 * V_6 )
{
return V_6 -> V_87 != V_6 -> V_88 ;
}
static T_8 F_42 ( T_8 V_89 )
{
int V_90 ;
if ( V_89 > 0 )
return V_89 ;
V_90 = F_43 ( V_91 ) ;
if ( V_90 <= 0 )
return 0 ;
if ( V_90 <= V_92 )
return V_92 ;
if ( V_90 >= V_93 )
return V_93 ;
if ( V_90 & 1 )
V_90 ++ ;
return ( T_8 ) V_90 ;
}
static void F_44 ( T_9 * V_94 , struct V_5 * V_6 ,
struct V_95 * V_96 )
{
T_8 V_97 = V_96 -> V_97 ;
if ( F_45 ( V_98 & V_97 ) ) {
if ( F_45 ( V_99 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_100 << 24 ) |
( V_101 << 16 ) |
( V_102 << 8 ) |
V_103 ) ;
} else {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_102 << 8 ) |
V_103 ) ;
}
V_97 &= ~ V_99 ;
V_96 -> V_105 = ( T_5 * ) V_94 ;
V_94 += 4 ;
}
if ( F_45 ( V_96 -> V_15 ) ) {
* V_94 ++ = F_46 ( ( V_106 << 24 ) |
( V_107 << 16 ) |
V_96 -> V_15 ) ;
}
if ( F_47 ( V_108 & V_97 ) ) {
if ( F_45 ( V_109 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_110 << 24 ) |
( V_111 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
V_97 &= ~ V_109 ;
} else {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_112 << 8 ) |
V_113 ) ;
}
* V_94 ++ = F_46 ( V_96 -> V_114 ) ;
* V_94 ++ = F_46 ( V_96 -> V_115 ) ;
}
if ( F_45 ( V_99 & V_97 ) ) {
T_5 * V_116 = V_96 -> V_105 ;
T_8 V_90 = V_96 -> V_117 ;
if ( 0x2 & V_90 ) {
T_5 * V_118 = ( T_5 * ) V_94 ;
* V_118 ++ = V_100 ;
* V_118 ++ = V_101 + V_90 ;
* V_118 ++ = * V_116 ++ ;
* V_118 ++ = * V_116 ++ ;
V_94 ++ ;
V_90 -= 2 ;
} else {
* V_94 ++ = F_46 ( ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_100 << 8 ) |
V_101 ) +
V_90 ) ;
}
if ( V_90 > 0 ) {
memcpy ( V_94 , V_116 , V_90 ) ;
V_94 += ( V_90 / 4 ) ;
}
}
if ( F_45 ( V_109 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_110 << 8 ) |
V_111 ) ;
}
if ( F_45 ( V_119 & V_97 ) ) {
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_120 << 16 ) |
( V_121 << 8 ) |
V_96 -> V_122 ) ;
}
if ( F_45 ( V_96 -> V_123 ) ) {
struct V_124 * V_125 = V_6 -> V_54 . V_126 ?
V_6 -> V_127 : V_6 -> V_128 ;
int V_129 ;
* V_94 ++ = F_46 ( ( V_104 << 24 ) |
( V_104 << 16 ) |
( V_130 << 8 ) |
( V_131 + ( V_96 -> V_123 *
V_132 ) ) ) ;
for ( V_129 = 0 ; V_129 < V_96 -> V_123 ;
++ V_129 ) {
* V_94 ++ = F_46 ( V_125 [ V_129 ] . V_133 ) ;
* V_94 ++ = F_46 ( V_125 [ V_129 ] . V_10 ) ;
}
V_6 -> V_54 . V_126 = 0 ;
}
}
static unsigned int F_48 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_134 * * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_136 * V_137 = V_6 -> V_138 ;
unsigned int V_139 = V_140 ;
T_8 V_90 = ( ! V_6 -> V_54 . V_141 && V_137 != NULL ) ?
F_42 ( V_137 -> V_142 ) :
0 ;
#ifdef F_49
* V_135 = V_6 -> V_143 -> V_144 ( V_2 , V_2 ) ;
if ( * V_135 ) {
V_96 -> V_97 |= V_98 ;
V_139 -= V_145 ;
}
#else
* V_135 = NULL ;
#endif
V_96 -> V_15 = F_10 ( V_2 ) ;
V_139 -= V_146 ;
if ( F_47 ( V_147 && * V_135 == NULL ) ) {
V_96 -> V_97 |= V_108 ;
V_96 -> V_114 = F_4 ( V_4 ) -> V_148 ;
V_96 -> V_115 = V_6 -> V_54 . V_149 ;
V_139 -= V_150 ;
}
if ( F_47 ( V_151 ) ) {
V_96 -> V_122 = V_6 -> V_54 . V_43 ;
V_96 -> V_97 |= V_119 ;
V_139 -= V_152 ;
}
if ( F_47 ( V_153 ) ) {
V_96 -> V_97 |= V_109 ;
if ( F_45 ( ! ( V_108 & V_96 -> V_97 ) ) )
V_139 -= V_154 ;
}
if ( * V_135 == NULL &&
( V_108 & V_96 -> V_97 ) &&
V_90 > 0 ) {
int V_155 = V_101 + V_90 ;
if ( 0x2 & V_155 ) {
V_155 += 2 ;
if ( V_155 > V_139 ) {
V_90 -= 2 ;
V_155 -= 4 ;
}
}
while ( V_155 > V_139 && V_92 <= V_90 ) {
V_90 -= 4 ;
V_155 -= 4 ;
}
if ( V_92 <= V_90 ) {
V_96 -> V_97 |= V_99 ;
V_96 -> V_105 = ( T_5 * ) & V_137 -> V_156 [ 0 ] ;
V_96 -> V_117 = V_90 ;
V_137 -> V_142 = V_90 ;
if ( V_137 -> V_142 != V_137 -> V_157 ) {
F_50 ( & V_137 -> V_156 [ 0 ] ,
V_90 ) ;
V_137 -> V_157 = V_90 ;
}
V_139 -= V_155 ;
}
}
return V_140 - V_139 ;
}
static unsigned int F_51 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
unsigned int V_15 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_134 * * V_135 ,
struct V_158 * V_159 )
{
struct V_160 * V_161 = F_34 ( V_65 ) ;
unsigned int V_139 = V_140 ;
T_8 V_162 = ( V_159 != NULL && ! V_159 -> V_141 ) ?
V_159 -> V_162 :
0 ;
#ifdef F_49
* V_135 = F_52 ( V_65 ) -> V_143 -> V_144 ( V_2 , V_65 ) ;
if ( * V_135 ) {
V_96 -> V_97 |= V_98 ;
V_139 -= V_145 ;
V_161 -> V_163 &= ! V_161 -> V_164 ;
}
#else
* V_135 = NULL ;
#endif
V_96 -> V_15 = V_15 ;
V_139 -= V_146 ;
if ( F_47 ( V_161 -> V_42 ) ) {
V_96 -> V_122 = V_161 -> V_43 ;
V_96 -> V_97 |= V_119 ;
V_139 -= V_152 ;
}
if ( F_47 ( V_161 -> V_163 ) ) {
V_96 -> V_97 |= V_108 ;
V_96 -> V_114 = F_4 ( V_4 ) -> V_148 ;
V_96 -> V_115 = V_65 -> V_149 ;
V_139 -= V_150 ;
}
if ( F_47 ( V_161 -> V_164 ) ) {
V_96 -> V_97 |= V_109 ;
if ( F_45 ( ! V_161 -> V_163 ) )
V_139 -= V_154 ;
}
if ( * V_135 == NULL &&
V_161 -> V_163 &&
V_162 > V_101 ) {
int V_155 = V_162 ;
if ( 0x2 & V_155 ) {
V_155 += 2 ;
}
if ( V_155 <= V_139 ) {
V_96 -> V_97 |= V_99 ;
V_96 -> V_117 = V_162 - V_101 ;
V_139 -= V_155 ;
} else {
V_159 -> V_141 = 1 ;
V_96 -> V_117 = 0 ;
}
}
return V_140 - V_139 ;
}
static unsigned int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_134 * * V_135 )
{
struct V_165 * V_166 = V_4 ? F_4 ( V_4 ) : NULL ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_167 = 0 ;
unsigned int V_168 ;
#ifdef F_49
* V_135 = V_6 -> V_143 -> V_144 ( V_2 , V_2 ) ;
if ( F_45 ( * V_135 ) ) {
V_96 -> V_97 |= V_98 ;
V_167 += V_145 ;
}
#else
* V_135 = NULL ;
#endif
if ( F_47 ( V_6 -> V_54 . V_163 ) ) {
V_96 -> V_97 |= V_108 ;
V_96 -> V_114 = V_166 ? V_166 -> V_148 : 0 ;
V_96 -> V_115 = V_6 -> V_54 . V_149 ;
V_167 += V_150 ;
}
V_168 = V_6 -> V_54 . V_169 + V_6 -> V_54 . V_126 ;
if ( F_45 ( V_168 ) ) {
const unsigned int V_139 = V_140 - V_167 ;
V_96 -> V_123 =
F_26 (unsigned int, eff_sacks,
(remaining - TCPOLEN_SACK_BASE_ALIGNED) /
TCPOLEN_SACK_PERBLOCK) ;
V_167 += V_170 +
V_96 -> V_123 * V_132 ;
}
return V_167 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_171 ,
T_10 V_172 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_173 * V_174 ;
struct V_5 * V_6 ;
struct V_165 * V_166 ;
struct V_95 V_96 ;
unsigned int V_175 , V_176 ;
struct V_134 * V_135 ;
struct V_66 * V_67 ;
int V_177 ;
F_55 ( ! V_4 || ! F_5 ( V_4 ) ) ;
if ( V_30 -> V_178 -> V_78 & V_179 )
F_56 ( V_4 ) ;
if ( F_47 ( V_171 ) ) {
if ( F_45 ( F_57 ( V_4 ) ) )
V_4 = F_58 ( V_4 , V_172 ) ;
else
V_4 = F_59 ( V_4 , V_172 ) ;
if ( F_45 ( ! V_4 ) )
return - V_180 ;
}
V_174 = F_60 ( V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_166 = F_4 ( V_4 ) ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
if ( F_45 ( V_166 -> V_58 & V_85 ) )
V_175 = F_48 ( V_2 , V_4 , & V_96 , & V_135 ) ;
else
V_175 = F_53 ( V_2 , V_4 , & V_96 ,
& V_135 ) ;
V_176 = V_175 + sizeof( struct V_66 ) ;
if ( F_61 ( V_6 ) == 0 ) {
F_15 ( V_2 , V_181 ) ;
V_4 -> V_182 = 1 ;
} else
V_4 -> V_182 = 0 ;
F_62 ( V_4 , V_176 ) ;
F_63 ( V_4 ) ;
F_64 ( V_4 , V_2 ) ;
V_67 = F_37 ( V_4 ) ;
V_67 -> V_183 = V_174 -> V_184 ;
V_67 -> V_185 = V_174 -> V_186 ;
V_67 -> V_72 = F_46 ( V_166 -> V_72 ) ;
V_67 -> V_187 = F_46 ( V_6 -> V_56 ) ;
* ( ( ( V_188 * ) V_67 ) + 6 ) = F_65 ( ( ( V_176 >> 2 ) << 12 ) |
V_166 -> V_58 ) ;
if ( F_45 ( V_166 -> V_58 & V_85 ) ) {
V_67 -> V_189 = F_65 ( F_17 ( V_6 -> V_40 , 65535U ) ) ;
} else {
V_67 -> V_189 = F_65 ( F_27 ( V_2 ) ) ;
}
V_67 -> V_190 = 0 ;
V_67 -> V_191 = 0 ;
if ( F_45 ( F_41 ( V_6 ) && F_8 ( V_166 -> V_72 , V_6 -> V_88 ) ) ) {
if ( F_8 ( V_6 -> V_88 , V_166 -> V_72 + 0x10000 ) ) {
V_67 -> V_191 = F_65 ( V_6 -> V_88 - V_166 -> V_72 ) ;
V_67 -> V_192 = 1 ;
} else if ( F_66 ( V_166 -> V_72 + 0xFFFF , V_6 -> V_9 ) ) {
V_67 -> V_191 = F_65 ( 0xFFFF ) ;
V_67 -> V_192 = 1 ;
}
}
F_44 ( ( T_9 * ) ( V_67 + 1 ) , V_6 , & V_96 ) ;
if ( F_47 ( ( V_166 -> V_58 & V_85 ) == 0 ) )
F_35 ( V_2 , V_4 , V_176 ) ;
#ifdef F_49
if ( V_135 ) {
F_67 ( V_2 , V_193 ) ;
V_6 -> V_143 -> V_194 ( V_96 . V_105 ,
V_135 , V_2 , NULL , V_4 ) ;
}
#endif
V_30 -> V_195 -> V_196 ( V_2 , V_4 ) ;
if ( F_47 ( V_166 -> V_58 & V_197 ) )
F_21 ( V_2 , F_5 ( V_4 ) ) ;
if ( V_4 -> V_71 != V_176 )
F_20 ( V_6 , V_2 ) ;
if ( F_66 ( V_166 -> V_10 , V_6 -> V_9 ) || V_166 -> V_72 == V_166 -> V_10 )
F_68 ( F_69 ( V_2 ) , V_198 ,
F_5 ( V_4 ) ) ;
V_177 = V_30 -> V_195 -> V_199 ( V_4 , & V_174 -> V_200 . V_201 ) ;
if ( F_47 ( V_177 <= 0 ) )
return V_177 ;
F_70 ( V_2 , 1 ) ;
return F_71 ( V_177 ) ;
}
static void F_72 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_202 = F_4 ( V_4 ) -> V_10 ;
F_73 ( V_4 ) ;
F_74 ( V_2 , V_4 ) ;
V_2 -> V_203 += V_4 -> V_204 ;
F_75 ( V_2 , V_4 -> V_204 ) ;
}
static void F_76 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_205 )
{
if ( V_4 -> V_71 <= V_205 || ! F_77 ( V_2 ) ||
V_4 -> V_79 == V_206 ) {
F_38 ( V_4 ) -> V_83 = 1 ;
F_38 ( V_4 ) -> V_84 = 0 ;
F_38 ( V_4 ) -> V_75 = 0 ;
} else {
F_38 ( V_4 ) -> V_83 = F_78 ( V_4 -> V_71 , V_205 ) ;
F_38 ( V_4 ) -> V_84 = V_205 ;
F_38 ( V_4 ) -> V_75 = V_2 -> V_207 ;
}
}
static void F_79 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_208 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_209 || F_80 ( V_6 ) )
return;
if ( F_66 ( F_81 ( V_6 ) , F_4 ( V_4 ) -> V_72 ) )
V_6 -> V_210 -= V_208 ;
}
static void F_82 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_208 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 -= V_208 ;
if ( F_4 ( V_4 ) -> V_82 & V_211 )
V_6 -> V_209 -= V_208 ;
if ( F_4 ( V_4 ) -> V_82 & V_212 )
V_6 -> V_213 -= V_208 ;
if ( F_4 ( V_4 ) -> V_82 & V_214 )
V_6 -> V_215 -= V_208 ;
if ( F_80 ( V_6 ) && V_208 > 0 )
V_6 -> V_209 -= F_26 ( T_4 , V_6 -> V_209 , V_208 ) ;
F_79 ( V_2 , V_4 , V_208 ) ;
if ( V_6 -> V_216 &&
F_8 ( F_4 ( V_4 ) -> V_72 , F_4 ( V_6 -> V_216 ) -> V_72 ) &&
( F_83 ( V_6 ) || ( F_4 ( V_4 ) -> V_82 & V_211 ) ) )
V_6 -> V_217 -= V_208 ;
F_84 ( V_6 ) ;
}
int F_85 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_71 ,
unsigned int V_205 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_218 ;
int V_219 , V_220 ;
int V_221 ;
T_8 V_78 ;
if ( F_86 ( V_71 > V_4 -> V_71 ) )
return - V_222 ;
V_219 = F_87 ( V_4 ) - V_71 ;
if ( V_219 < 0 )
V_219 = 0 ;
if ( F_57 ( V_4 ) &&
F_88 ( V_4 ) &&
F_89 ( V_4 , 0 , 0 , V_223 ) )
return - V_224 ;
V_218 = F_90 ( V_2 , V_219 , V_223 ) ;
if ( V_218 == NULL )
return - V_224 ;
V_2 -> V_203 += V_218 -> V_204 ;
F_75 ( V_2 , V_218 -> V_204 ) ;
V_221 = V_4 -> V_71 - V_71 - V_219 ;
V_218 -> V_204 += V_221 ;
V_4 -> V_204 -= V_221 ;
F_4 ( V_218 ) -> V_72 = F_4 ( V_4 ) -> V_72 + V_71 ;
F_4 ( V_218 ) -> V_10 = F_4 ( V_4 ) -> V_10 ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_218 ) -> V_72 ;
V_78 = F_4 ( V_4 ) -> V_58 ;
F_4 ( V_4 ) -> V_58 = V_78 & ~ ( V_86 | V_225 ) ;
F_4 ( V_218 ) -> V_58 = V_78 ;
F_4 ( V_218 ) -> V_82 = F_4 ( V_4 ) -> V_82 ;
if ( ! F_38 ( V_4 ) -> V_226 && V_4 -> V_79 != V_80 ) {
V_218 -> V_81 = F_91 ( V_4 -> V_227 + V_71 ,
F_92 ( V_218 , V_219 ) ,
V_219 , 0 ) ;
F_93 ( V_4 , V_71 ) ;
V_4 -> V_81 = F_94 ( V_4 -> V_81 , V_218 -> V_81 , V_71 ) ;
} else {
V_4 -> V_79 = V_80 ;
F_95 ( V_4 , V_218 , V_71 ) ;
}
V_218 -> V_79 = V_4 -> V_79 ;
F_4 ( V_218 ) -> V_148 = F_4 ( V_4 ) -> V_148 ;
V_218 -> V_228 = V_4 -> V_228 ;
V_220 = F_5 ( V_4 ) ;
F_76 ( V_2 , V_4 , V_205 ) ;
F_76 ( V_2 , V_218 , V_205 ) ;
if ( ! F_8 ( V_6 -> V_9 , F_4 ( V_218 ) -> V_10 ) ) {
int V_229 = V_220 - F_5 ( V_4 ) -
F_5 ( V_218 ) ;
if ( V_229 )
F_82 ( V_2 , V_4 , V_229 ) ;
}
F_73 ( V_218 ) ;
F_96 ( V_4 , V_218 , V_2 ) ;
return 0 ;
}
static void F_97 ( struct V_3 * V_4 , int V_71 )
{
int V_230 , V_231 , V_232 ;
V_232 = F_26 ( int , V_71 , F_87 ( V_4 ) ) ;
if ( V_232 ) {
F_98 ( V_4 , V_232 ) ;
V_4 -> V_233 -= V_232 ;
V_71 -= V_232 ;
if ( ! V_71 )
return;
}
V_232 = V_71 ;
V_231 = 0 ;
for ( V_230 = 0 ; V_230 < F_38 ( V_4 ) -> V_226 ; V_230 ++ ) {
int V_167 = F_99 ( & F_38 ( V_4 ) -> V_234 [ V_230 ] ) ;
if ( V_167 <= V_232 ) {
F_100 ( V_4 , V_230 ) ;
V_232 -= V_167 ;
} else {
F_38 ( V_4 ) -> V_234 [ V_231 ] = F_38 ( V_4 ) -> V_234 [ V_230 ] ;
if ( V_232 ) {
F_38 ( V_4 ) -> V_234 [ V_231 ] . V_235 += V_232 ;
F_101 ( & F_38 ( V_4 ) -> V_234 [ V_231 ] , V_232 ) ;
V_232 = 0 ;
}
V_231 ++ ;
}
}
F_38 ( V_4 ) -> V_226 = V_231 ;
F_102 ( V_4 ) ;
V_4 -> V_236 -= V_71 ;
V_4 -> V_71 = V_4 -> V_236 ;
}
int F_103 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_71 )
{
if ( F_57 ( V_4 ) && F_89 ( V_4 , 0 , 0 , V_223 ) )
return - V_224 ;
F_97 ( V_4 , V_71 ) ;
F_4 ( V_4 ) -> V_72 += V_71 ;
V_4 -> V_79 = V_80 ;
V_4 -> V_204 -= V_71 ;
V_2 -> V_203 -= V_71 ;
F_104 ( V_2 , V_71 ) ;
F_105 ( V_2 , V_237 ) ;
if ( F_5 ( V_4 ) > 1 )
F_76 ( V_2 , V_4 , F_106 ( V_4 ) ) ;
return 0 ;
}
int F_107 ( struct V_1 * V_2 , int V_238 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_205 ;
V_205 = V_238 - V_30 -> V_195 -> V_239 - sizeof( struct V_66 ) ;
if ( V_30 -> V_195 -> V_240 ) {
const struct V_13 * V_14 = F_11 ( V_2 ) ;
if ( V_14 && F_108 ( V_14 ) )
V_205 -= V_30 -> V_195 -> V_240 ;
}
if ( V_205 > V_6 -> V_54 . V_241 )
V_205 = V_6 -> V_54 . V_241 ;
V_205 -= V_30 -> V_242 ;
if ( V_205 < 48 )
V_205 = 48 ;
V_205 -= V_6 -> V_70 - sizeof( struct V_66 ) ;
return V_205 ;
}
int F_109 ( struct V_1 * V_2 , int V_15 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_243 ;
V_243 = V_15 +
V_6 -> V_70 +
V_30 -> V_242 +
V_30 -> V_195 -> V_239 ;
if ( V_30 -> V_195 -> V_240 ) {
const struct V_13 * V_14 = F_11 ( V_2 ) ;
if ( V_14 && F_108 ( V_14 ) )
V_243 += V_30 -> V_195 -> V_240 ;
}
return V_243 ;
}
void F_110 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
V_30 -> V_244 . V_245 = V_246 > 1 ;
V_30 -> V_244 . V_247 = V_6 -> V_54 . V_241 + sizeof( struct V_66 ) +
V_30 -> V_195 -> V_239 ;
V_30 -> V_244 . V_248 = F_109 ( V_2 , V_249 ) ;
V_30 -> V_244 . V_250 = 0 ;
}
unsigned int F_111 ( struct V_1 * V_2 , T_4 V_238 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_205 ;
if ( V_30 -> V_244 . V_247 > V_238 )
V_30 -> V_244 . V_247 = V_238 ;
V_205 = F_107 ( V_2 , V_238 ) ;
V_205 = F_112 ( V_6 , V_205 ) ;
V_30 -> V_251 = V_238 ;
if ( V_30 -> V_244 . V_245 )
V_205 = F_17 ( V_205 , F_107 ( V_2 , V_30 -> V_244 . V_248 ) ) ;
V_6 -> V_252 = V_205 ;
return V_205 ;
}
unsigned int F_113 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_13 * V_14 = F_11 ( V_2 ) ;
T_4 V_205 ;
unsigned int V_253 ;
struct V_95 V_96 ;
struct V_134 * V_135 ;
V_205 = V_6 -> V_252 ;
if ( V_14 ) {
T_4 V_243 = F_114 ( V_14 ) ;
if ( V_243 != F_18 ( V_2 ) -> V_251 )
V_205 = F_111 ( V_2 , V_243 ) ;
}
V_253 = F_53 ( V_2 , NULL , & V_96 , & V_135 ) +
sizeof( struct V_66 ) ;
if ( V_253 != V_6 -> V_70 ) {
int V_18 = ( int ) V_253 - V_6 -> V_70 ;
V_205 -= V_18 ;
}
return V_205 ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 >= V_6 -> V_23 ) {
V_6 -> V_28 = 0 ;
V_6 -> V_27 = V_19 ;
} else {
if ( V_6 -> V_8 > V_6 -> V_28 )
V_6 -> V_28 = V_6 -> V_8 ;
if ( V_32 &&
( T_3 ) ( V_19 - V_6 -> V_27 ) >= F_18 ( V_2 ) -> V_26 )
F_116 ( V_2 ) ;
}
}
static unsigned int F_117 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_205 , unsigned int V_22 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_254 , V_189 , V_255 ;
V_189 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_72 ;
V_255 = V_205 * V_22 ;
if ( F_47 ( V_255 <= V_189 && V_4 != F_118 ( V_2 ) ) )
return V_255 ;
V_254 = F_17 ( V_4 -> V_71 , V_189 ) ;
if ( V_255 <= V_254 )
return V_255 ;
return V_254 - V_254 % V_205 ;
}
static inline unsigned int F_119 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_4 V_256 , V_22 ;
if ( ( F_4 ( V_4 ) -> V_58 & V_86 ) &&
F_5 ( V_4 ) == 1 )
return 1 ;
V_256 = F_61 ( V_6 ) ;
V_22 = V_6 -> V_23 ;
if ( V_256 < V_22 )
return ( V_22 - V_256 ) ;
return 0 ;
}
static int F_120 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_205 )
{
int V_257 = F_5 ( V_4 ) ;
if ( ! V_257 || ( V_257 > 1 && F_106 ( V_4 ) != V_205 ) ) {
F_76 ( V_2 , V_4 , V_205 ) ;
V_257 = F_5 ( V_4 ) ;
}
return V_257 ;
}
static inline bool F_121 ( const struct V_5 * V_6 )
{
return F_66 ( V_6 -> V_258 , V_6 -> V_87 ) &&
! F_66 ( V_6 -> V_258 , V_6 -> V_9 ) ;
}
static inline bool F_122 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
unsigned int V_205 , int V_259 )
{
return V_4 -> V_71 < V_205 &&
( ( V_259 & V_260 ) ||
( ! V_259 && V_6 -> V_8 && F_121 ( V_6 ) ) ) ;
}
static inline bool F_123 ( const struct V_5 * V_6 , const struct V_3 * V_4 ,
unsigned int V_261 , int V_259 )
{
if ( V_259 & V_262 )
return true ;
if ( F_41 ( V_6 ) || ( V_6 -> V_11 == 2 ) ||
( F_4 ( V_4 ) -> V_58 & V_86 ) )
return true ;
if ( ! F_122 ( V_6 , V_4 , V_261 , V_259 ) )
return true ;
return false ;
}
static bool F_124 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
unsigned int V_261 )
{
T_4 V_10 = F_4 ( V_4 ) -> V_10 ;
if ( V_4 -> V_71 > V_261 )
V_10 = F_4 ( V_4 ) -> V_72 + V_261 ;
return ! F_66 ( V_10 , F_9 ( V_6 ) ) ;
}
static unsigned int F_125 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_261 , int V_259 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_263 ;
F_120 ( V_2 , V_4 , V_261 ) ;
if ( ! F_123 ( V_6 , V_4 , V_261 , V_259 ) )
return 0 ;
V_263 = F_119 ( V_6 , V_4 ) ;
if ( V_263 && ! F_124 ( V_6 , V_4 , V_261 ) )
V_263 = 0 ;
return V_263 ;
}
bool F_126 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_127 ( V_2 ) ;
return V_4 &&
F_125 ( V_2 , V_4 , F_113 ( V_2 ) ,
( F_128 ( V_2 , V_4 ) ?
V_6 -> V_259 : V_262 ) ) ;
}
static int F_129 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_71 ,
unsigned int V_205 , T_10 V_264 )
{
struct V_3 * V_218 ;
int V_221 = V_4 -> V_71 - V_71 ;
T_8 V_78 ;
if ( V_4 -> V_71 != V_4 -> V_236 )
return F_85 ( V_2 , V_4 , V_71 , V_205 ) ;
V_218 = F_90 ( V_2 , 0 , V_264 ) ;
if ( F_45 ( V_218 == NULL ) )
return - V_224 ;
V_2 -> V_203 += V_218 -> V_204 ;
F_75 ( V_2 , V_218 -> V_204 ) ;
V_218 -> V_204 += V_221 ;
V_4 -> V_204 -= V_221 ;
F_4 ( V_218 ) -> V_72 = F_4 ( V_4 ) -> V_72 + V_71 ;
F_4 ( V_218 ) -> V_10 = F_4 ( V_4 ) -> V_10 ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_218 ) -> V_72 ;
V_78 = F_4 ( V_4 ) -> V_58 ;
F_4 ( V_4 ) -> V_58 = V_78 & ~ ( V_86 | V_225 ) ;
F_4 ( V_218 ) -> V_58 = V_78 ;
F_4 ( V_218 ) -> V_82 = 0 ;
V_218 -> V_79 = V_4 -> V_79 = V_80 ;
F_95 ( V_4 , V_218 , V_71 ) ;
F_76 ( V_2 , V_4 , V_205 ) ;
F_76 ( V_2 , V_218 , V_205 ) ;
F_73 ( V_218 ) ;
F_96 ( V_4 , V_218 , V_2 ) ;
return 0 ;
}
static bool F_130 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_18 ( V_2 ) ;
T_4 V_265 , V_266 , V_267 , V_256 ;
int V_268 ;
if ( F_4 ( V_4 ) -> V_58 & V_86 )
goto V_269;
if ( V_30 -> V_270 != V_271 )
goto V_269;
if ( V_6 -> V_272 &&
( ( ( T_4 ) V_273 << 1 ) >> 1 ) - ( V_6 -> V_272 >> 1 ) > 1 )
goto V_269;
V_256 = F_61 ( V_6 ) ;
F_55 ( F_5 ( V_4 ) <= 1 || ( V_6 -> V_23 <= V_256 ) ) ;
V_265 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_72 ;
V_266 = ( V_6 -> V_23 - V_256 ) * V_6 -> V_252 ;
V_267 = F_17 ( V_265 , V_266 ) ;
if ( V_267 >= V_2 -> V_274 )
goto V_269;
if ( ( V_4 != F_118 ( V_2 ) ) && ( V_267 >= V_4 -> V_71 ) )
goto V_269;
V_268 = F_43 ( V_275 ) ;
if ( V_268 ) {
T_4 V_276 = F_17 ( V_6 -> V_277 , V_6 -> V_23 * V_6 -> V_252 ) ;
V_276 /= V_268 ;
if ( V_267 >= V_276 )
goto V_269;
} else {
if ( V_267 > F_131 ( V_6 ) * V_6 -> V_252 )
goto V_269;
}
V_6 -> V_272 = 1 | ( V_273 << 1 ) ;
return true ;
V_269:
V_6 -> V_272 = 0 ;
return false ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_3 * V_4 , * V_278 , * V_279 ;
int V_71 ;
int V_250 ;
int V_280 ;
int V_281 ;
int V_205 ;
if ( ! V_30 -> V_244 . V_245 ||
V_30 -> V_244 . V_250 ||
F_18 ( V_2 ) -> V_270 != V_271 ||
V_6 -> V_23 < 11 ||
V_6 -> V_54 . V_169 || V_6 -> V_54 . V_126 )
return - 1 ;
V_205 = F_113 ( V_2 ) ;
V_250 = 2 * V_6 -> V_252 ;
V_280 = V_250 + ( V_6 -> V_282 + 1 ) * V_6 -> V_252 ;
if ( V_250 > F_107 ( V_2 , V_30 -> V_244 . V_247 ) ) {
return - 1 ;
}
if ( V_6 -> V_202 - V_6 -> V_9 < V_280 )
return - 1 ;
if ( V_6 -> V_277 < V_280 )
return - 1 ;
if ( F_66 ( V_6 -> V_9 + V_280 , F_9 ( V_6 ) ) )
return 0 ;
if ( F_61 ( V_6 ) + 2 > V_6 -> V_23 ) {
if ( ! F_61 ( V_6 ) )
return - 1 ;
else
return 0 ;
}
if ( ( V_278 = F_90 ( V_2 , V_250 , V_223 ) ) == NULL )
return - 1 ;
V_2 -> V_203 += V_278 -> V_204 ;
F_75 ( V_2 , V_278 -> V_204 ) ;
V_4 = F_127 ( V_2 ) ;
F_4 ( V_278 ) -> V_72 = F_4 ( V_4 ) -> V_72 ;
F_4 ( V_278 ) -> V_10 = F_4 ( V_4 ) -> V_72 + V_250 ;
F_4 ( V_278 ) -> V_58 = V_197 ;
F_4 ( V_278 ) -> V_82 = 0 ;
V_278 -> V_81 = 0 ;
V_278 -> V_79 = V_4 -> V_79 ;
F_133 ( V_278 , V_4 , V_2 ) ;
V_71 = 0 ;
F_134 (skb, next, sk) {
V_281 = F_26 ( int , V_4 -> V_71 , V_250 - V_71 ) ;
if ( V_278 -> V_79 )
F_135 ( V_4 , 0 , F_92 ( V_278 , V_281 ) , V_281 ) ;
else
V_278 -> V_81 = F_136 ( V_4 , 0 ,
F_92 ( V_278 , V_281 ) ,
V_281 , V_278 -> V_81 ) ;
if ( V_4 -> V_71 <= V_281 ) {
F_4 ( V_278 ) -> V_58 |= F_4 ( V_4 ) -> V_58 ;
F_137 ( V_4 , V_2 ) ;
F_138 ( V_2 , V_4 ) ;
} else {
F_4 ( V_278 ) -> V_58 |= F_4 ( V_4 ) -> V_58 &
~ ( V_86 | V_225 ) ;
if ( ! F_38 ( V_4 ) -> V_226 ) {
F_139 ( V_4 , V_281 ) ;
if ( V_4 -> V_79 != V_80 )
V_4 -> V_81 = F_140 ( V_4 -> V_227 ,
V_4 -> V_71 , 0 ) ;
} else {
F_97 ( V_4 , V_281 ) ;
F_76 ( V_2 , V_4 , V_205 ) ;
}
F_4 ( V_4 ) -> V_72 += V_281 ;
}
V_71 += V_281 ;
if ( V_71 >= V_250 )
break;
}
F_120 ( V_2 , V_278 , V_278 -> V_71 ) ;
F_4 ( V_278 ) -> V_148 = V_19 ;
if ( ! F_54 ( V_2 , V_278 , 1 , V_223 ) ) {
V_6 -> V_23 -- ;
F_1 ( V_2 , V_278 ) ;
V_30 -> V_244 . V_250 = F_109 ( V_2 , V_278 -> V_71 ) ;
V_6 -> V_283 . V_284 = F_4 ( V_278 ) -> V_72 ;
V_6 -> V_283 . V_285 = F_4 ( V_278 ) -> V_10 ;
return 1 ;
}
return - 1 ;
}
static bool F_141 ( struct V_1 * V_2 , unsigned int V_205 , int V_259 ,
int V_286 , T_10 V_264 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_257 , V_287 ;
int V_263 ;
int V_288 ;
V_287 = 0 ;
if ( ! V_286 ) {
V_288 = F_132 ( V_2 ) ;
if ( ! V_288 ) {
return false ;
} else if ( V_288 > 0 ) {
V_287 = 1 ;
}
}
while ( ( V_4 = F_127 ( V_2 ) ) ) {
unsigned int V_267 ;
V_257 = F_120 ( V_2 , V_4 , V_205 ) ;
F_55 ( ! V_257 ) ;
V_263 = F_119 ( V_6 , V_4 ) ;
if ( ! V_263 )
break;
if ( F_45 ( ! F_124 ( V_6 , V_4 , V_205 ) ) )
break;
if ( V_257 == 1 ) {
if ( F_45 ( ! F_123 ( V_6 , V_4 , V_205 ,
( F_128 ( V_2 , V_4 ) ?
V_259 : V_262 ) ) ) )
break;
} else {
if ( ! V_286 && F_130 ( V_2 , V_4 ) )
break;
}
V_267 = V_205 ;
if ( V_257 > 1 && ! F_41 ( V_6 ) )
V_267 = F_117 ( V_2 , V_4 , V_205 ,
V_263 ) ;
if ( V_4 -> V_71 > V_267 &&
F_45 ( F_129 ( V_2 , V_4 , V_267 , V_205 , V_264 ) ) )
break;
F_4 ( V_4 ) -> V_148 = V_19 ;
if ( F_45 ( F_54 ( V_2 , V_4 , 1 , V_264 ) ) )
break;
F_1 ( V_2 , V_4 ) ;
F_142 ( V_6 , V_205 , V_4 ) ;
V_287 += F_5 ( V_4 ) ;
if ( V_286 )
break;
}
if ( F_18 ( V_2 ) -> V_270 == V_289 )
V_6 -> V_290 += V_287 ;
if ( F_47 ( V_287 ) ) {
F_115 ( V_2 ) ;
return false ;
}
return ! V_6 -> V_8 && F_127 ( V_2 ) ;
}
void F_143 ( struct V_1 * V_2 , unsigned int V_261 ,
int V_259 )
{
if ( F_45 ( V_2 -> V_291 == V_292 ) )
return;
if ( F_141 ( V_2 , V_261 , V_259 , 0 , V_223 ) )
F_144 ( V_2 ) ;
}
void F_145 ( struct V_1 * V_2 , unsigned int V_205 )
{
struct V_3 * V_4 = F_127 ( V_2 ) ;
F_55 ( ! V_4 || V_4 -> V_71 < V_205 ) ;
F_141 ( V_2 , V_205 , V_262 , 1 , V_2 -> V_293 ) ;
}
T_4 F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 = V_30 -> V_33 . V_294 ;
int V_295 = F_146 ( V_2 ) ;
int V_296 = F_26 ( int , V_6 -> V_41 , F_147 ( V_2 ) ) ;
int V_189 ;
if ( V_15 > V_296 )
V_15 = V_296 ;
if ( V_295 < ( V_296 >> 1 ) ) {
V_30 -> V_33 . V_297 = 0 ;
if ( F_148 ( V_2 ) )
V_6 -> V_298 = F_17 ( V_6 -> V_298 ,
4U * V_6 -> V_16 ) ;
if ( V_295 < V_15 )
return 0 ;
}
if ( V_295 > V_6 -> V_298 )
V_295 = V_6 -> V_298 ;
V_189 = V_6 -> V_40 ;
if ( V_6 -> V_54 . V_43 ) {
V_189 = V_295 ;
if ( ( ( V_189 >> V_6 -> V_54 . V_43 ) << V_6 -> V_54 . V_43 ) != V_189 )
V_189 = ( ( ( V_189 >> V_6 -> V_54 . V_43 ) + 1 )
<< V_6 -> V_54 . V_43 ) ;
} else {
if ( V_189 <= V_295 - V_15 || V_189 > V_295 )
V_189 = ( V_295 / V_15 ) * V_15 ;
else if ( V_15 == V_296 &&
V_295 > V_189 + ( V_296 >> 1 ) )
V_189 = V_295 ;
}
return V_189 ;
}
static void F_149 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_299 = F_150 ( V_2 , V_4 ) ;
int V_300 , V_301 ;
V_300 = V_4 -> V_71 ;
V_301 = V_299 -> V_71 ;
F_55 ( F_5 ( V_4 ) != 1 || F_5 ( V_299 ) != 1 ) ;
F_151 ( V_2 , V_299 , V_4 ) ;
F_137 ( V_299 , V_2 ) ;
F_152 ( V_299 , F_92 ( V_4 , V_301 ) ,
V_301 ) ;
if ( V_299 -> V_79 == V_80 )
V_4 -> V_79 = V_80 ;
if ( V_4 -> V_79 != V_80 )
V_4 -> V_81 = F_153 ( V_4 -> V_81 , V_299 -> V_81 , V_300 ) ;
F_4 ( V_4 ) -> V_10 = F_4 ( V_299 ) -> V_10 ;
F_4 ( V_4 ) -> V_58 |= F_4 ( V_299 ) -> V_58 ;
F_4 ( V_4 ) -> V_82 |= F_4 ( V_299 ) -> V_82 & V_302 ;
F_154 ( V_6 ) ;
if ( V_299 == V_6 -> V_303 )
V_6 -> V_303 = V_4 ;
F_82 ( V_2 , V_299 , F_5 ( V_299 ) ) ;
F_138 ( V_2 , V_299 ) ;
}
static bool F_155 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( F_5 ( V_4 ) > 1 )
return false ;
if ( F_38 ( V_4 ) -> V_226 != 0 )
return false ;
if ( F_57 ( V_4 ) )
return false ;
if ( V_4 == F_127 ( V_2 ) )
return false ;
if ( F_4 ( V_4 ) -> V_82 & V_211 )
return false ;
return true ;
}
static void F_156 ( struct V_1 * V_2 , struct V_3 * V_304 ,
int V_45 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_304 , * V_305 ;
bool V_306 = true ;
if ( ! V_307 )
return;
if ( F_4 ( V_4 ) -> V_58 & V_85 )
return;
F_134 (skb, tmp, sk) {
if ( ! F_155 ( V_2 , V_4 ) )
break;
V_45 -= V_4 -> V_71 ;
if ( V_306 ) {
V_306 = false ;
continue;
}
if ( V_45 < 0 )
break;
if ( V_4 -> V_71 > F_157 ( V_304 ) )
break;
if ( F_66 ( F_4 ( V_4 ) -> V_10 , F_9 ( V_6 ) ) )
break;
F_149 ( V_2 , V_304 ) ;
}
}
int F_158 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_18 ( V_2 ) ;
unsigned int V_261 ;
int V_177 ;
if ( V_30 -> V_244 . V_250 ) {
V_30 -> V_244 . V_250 = 0 ;
}
if ( F_159 ( & V_2 -> V_308 ) >
F_17 ( V_2 -> V_203 + ( V_2 -> V_203 >> 2 ) , V_2 -> V_309 ) )
return - V_310 ;
if ( F_8 ( F_4 ( V_4 ) -> V_72 , V_6 -> V_87 ) ) {
if ( F_8 ( F_4 ( V_4 ) -> V_10 , V_6 -> V_87 ) )
F_160 () ;
if ( F_103 ( V_2 , V_4 , V_6 -> V_87 - F_4 ( V_4 ) -> V_72 ) )
return - V_224 ;
}
if ( F_18 ( V_2 ) -> V_195 -> V_311 ( V_2 ) )
return - V_312 ;
V_261 = F_113 ( V_2 ) ;
if ( ! F_8 ( F_4 ( V_4 ) -> V_72 , F_9 ( V_6 ) ) &&
F_4 ( V_4 ) -> V_72 != V_6 -> V_87 )
return - V_310 ;
if ( V_4 -> V_71 > V_261 ) {
if ( F_85 ( V_2 , V_4 , V_261 , V_261 ) )
return - V_224 ;
} else {
int V_313 = F_5 ( V_4 ) ;
if ( F_45 ( V_313 > 1 ) ) {
F_120 ( V_2 , V_4 , V_261 ) ;
F_82 ( V_2 , V_4 , V_313 - F_5 ( V_4 ) ) ;
}
}
F_156 ( V_2 , V_4 , V_261 ) ;
if ( V_4 -> V_71 > 0 &&
( F_4 ( V_4 ) -> V_58 & V_86 ) &&
V_6 -> V_87 == ( F_4 ( V_4 ) -> V_10 - 1 ) ) {
if ( ! F_161 ( V_4 , 0 ) ) {
F_40 ( V_4 , F_4 ( V_4 ) -> V_10 - 1 ,
F_4 ( V_4 ) -> V_58 ) ;
V_4 -> V_79 = V_206 ;
}
}
F_4 ( V_4 ) -> V_148 = V_19 ;
if ( F_45 ( V_314 && ( ( unsigned long ) V_4 -> V_227 & 3 ) ) ) {
struct V_3 * V_278 = F_162 ( V_4 , V_315 ,
V_223 ) ;
V_177 = V_278 ? F_54 ( V_2 , V_278 , 0 , V_223 ) :
- V_180 ;
} else {
V_177 = F_54 ( V_2 , V_4 , 1 , V_223 ) ;
}
if ( V_177 == 0 ) {
F_163 ( F_69 ( V_2 ) , V_316 ) ;
V_6 -> V_317 ++ ;
#if V_318 > 0
if ( F_4 ( V_4 ) -> V_82 & V_212 ) {
F_164 ( L_1 ) ;
}
#endif
if ( ! V_6 -> V_213 )
V_6 -> V_319 = V_6 -> V_9 ;
F_4 ( V_4 ) -> V_82 |= V_320 ;
V_6 -> V_213 += F_5 ( V_4 ) ;
if ( ! V_6 -> V_321 )
V_6 -> V_321 = F_4 ( V_4 ) -> V_148 ;
V_6 -> V_322 += F_5 ( V_4 ) ;
F_4 ( V_4 ) -> V_187 = V_6 -> V_9 ;
}
return V_177 ;
}
static bool F_165 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_270 != V_289 )
return false ;
if ( F_80 ( V_6 ) )
return false ;
if ( F_126 ( V_2 ) )
return false ;
return true ;
}
void F_166 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_3 * V_323 = NULL ;
T_4 V_324 ;
int V_325 ;
int V_326 = 0 ;
if ( ! V_6 -> V_8 )
return;
if ( ! V_6 -> V_215 )
V_6 -> V_327 = V_6 -> V_87 ;
if ( V_6 -> V_303 ) {
V_4 = V_6 -> V_303 ;
V_324 = F_4 ( V_4 ) -> V_10 ;
if ( F_66 ( V_324 , V_6 -> V_327 ) )
V_324 = V_6 -> V_327 ;
} else {
V_4 = F_167 ( V_2 ) ;
V_324 = V_6 -> V_87 ;
}
F_168 (skb, sk) {
T_5 V_82 = F_4 ( V_4 ) -> V_82 ;
if ( V_4 == F_127 ( V_2 ) )
break;
if ( V_323 == NULL )
V_6 -> V_303 = V_4 ;
if ( F_61 ( V_6 ) >= V_6 -> V_23 )
return;
if ( V_326 ) {
V_328:
if ( ! F_8 ( F_4 ( V_4 ) -> V_72 , F_81 ( V_6 ) ) )
break;
V_325 = V_329 ;
} else if ( ! F_8 ( F_4 ( V_4 ) -> V_72 , V_6 -> V_327 ) ) {
V_6 -> V_327 = V_324 ;
if ( ! F_165 ( V_2 ) )
break;
if ( V_323 != NULL ) {
V_4 = V_323 ;
V_323 = NULL ;
}
V_326 = 1 ;
goto V_328;
} else if ( ! ( V_82 & V_214 ) ) {
if ( V_323 == NULL && ! ( V_82 & ( V_212 | V_211 ) ) )
V_323 = V_4 ;
continue;
} else {
V_324 = F_4 ( V_4 ) -> V_10 ;
if ( V_30 -> V_270 != V_330 )
V_325 = V_331 ;
else
V_325 = V_332 ;
}
if ( V_82 & ( V_211 | V_212 ) )
continue;
if ( F_158 ( V_2 , V_4 ) ) {
F_169 ( F_69 ( V_2 ) , V_333 ) ;
return;
}
F_169 ( F_69 ( V_2 ) , V_325 ) ;
if ( F_18 ( V_2 ) -> V_270 == V_289 )
V_6 -> V_290 += F_5 ( V_4 ) ;
if ( V_4 == F_167 ( V_2 ) )
F_170 ( V_2 , V_334 ,
F_18 ( V_2 ) -> V_26 ,
V_335 ) ;
}
}
void F_171 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = F_118 ( V_2 ) ;
int V_205 ;
V_205 = F_113 ( V_2 ) ;
if ( F_127 ( V_2 ) != NULL ) {
F_4 ( V_4 ) -> V_58 |= V_86 ;
F_4 ( V_4 ) -> V_10 ++ ;
V_6 -> V_202 ++ ;
} else {
for (; ; ) {
V_4 = F_172 ( V_315 ,
V_2 -> V_293 ) ;
if ( V_4 )
break;
F_173 () ;
}
F_174 ( V_4 , V_315 ) ;
F_40 ( V_4 , V_6 -> V_202 ,
V_197 | V_86 ) ;
F_72 ( V_2 , V_4 ) ;
}
F_143 ( V_2 , V_205 , V_336 ) ;
}
void F_175 ( struct V_1 * V_2 , T_10 V_337 )
{
struct V_3 * V_4 ;
V_4 = F_176 ( V_315 , V_337 ) ;
if ( ! V_4 ) {
F_177 ( F_69 ( V_2 ) , V_338 ) ;
return;
}
F_174 ( V_4 , V_315 ) ;
F_40 ( V_4 , F_7 ( V_2 ) ,
V_197 | V_339 ) ;
F_4 ( V_4 ) -> V_148 = V_19 ;
if ( F_54 ( V_2 , V_4 , 0 , V_337 ) )
F_177 ( F_69 ( V_2 ) , V_338 ) ;
F_163 ( F_69 ( V_2 ) , V_340 ) ;
}
int F_178 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_167 ( V_2 ) ;
if ( V_4 == NULL || ! ( F_4 ( V_4 ) -> V_58 & V_85 ) ) {
F_179 ( L_2 , V_341 ) ;
return - V_342 ;
}
if ( ! ( F_4 ( V_4 ) -> V_58 & V_197 ) ) {
if ( F_57 ( V_4 ) ) {
struct V_3 * V_278 = F_180 ( V_4 , V_223 ) ;
if ( V_278 == NULL )
return - V_224 ;
F_137 ( V_4 , V_2 ) ;
F_73 ( V_278 ) ;
F_181 ( V_2 , V_278 ) ;
F_138 ( V_2 , V_4 ) ;
V_2 -> V_203 += V_278 -> V_204 ;
F_75 ( V_2 , V_278 -> V_204 ) ;
V_4 = V_278 ;
}
F_4 ( V_4 ) -> V_58 |= V_197 ;
F_31 ( F_2 ( V_2 ) , V_4 ) ;
}
F_4 ( V_4 ) -> V_148 = V_19 ;
return F_54 ( V_2 , V_4 , 1 , V_223 ) ;
}
struct V_3 * F_182 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_64 * V_65 ,
struct V_343 * V_344 )
{
struct V_95 V_96 ;
struct V_158 * V_159 = F_183 ( V_344 ) ;
struct V_160 * V_161 = F_34 ( V_65 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_136 * V_137 = V_6 -> V_138 ;
struct V_66 * V_67 ;
struct V_3 * V_4 ;
struct V_134 * V_135 ;
int V_176 ;
int V_15 ;
int V_345 = 0 ;
if ( V_137 != NULL && V_137 -> V_346 && V_137 -> V_345 )
V_345 = V_137 -> V_345 ;
V_4 = F_184 ( V_2 , V_315 + 15 + V_345 , 1 , V_223 ) ;
if ( V_4 == NULL )
return NULL ;
F_174 ( V_4 , V_315 ) ;
F_185 ( V_4 , F_186 ( V_14 ) ) ;
V_15 = F_12 ( V_14 ) ;
if ( V_6 -> V_54 . V_347 && V_6 -> V_54 . V_347 < V_15 )
V_15 = V_6 -> V_54 . V_347 ;
if ( V_65 -> V_40 == 0 ) {
T_5 V_43 ;
V_65 -> V_41 = V_6 -> V_41 ? : F_187 ( V_14 , V_348 ) ;
if ( V_2 -> V_349 & V_350 &&
( V_65 -> V_41 > F_147 ( V_2 ) || V_65 -> V_41 == 0 ) )
V_65 -> V_41 = F_147 ( V_2 ) ;
F_24 ( F_147 ( V_2 ) ,
V_15 - ( V_161 -> V_163 ? V_150 : 0 ) ,
& V_65 -> V_40 ,
& V_65 -> V_41 ,
V_161 -> V_42 ,
& V_43 ,
F_187 ( V_14 , V_351 ) ) ;
V_161 -> V_43 = V_43 ;
}
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
#ifdef F_188
if ( F_45 ( V_65 -> V_352 ) )
F_4 ( V_4 ) -> V_148 = F_189 ( V_65 ) ;
else
#endif
F_4 ( V_4 ) -> V_148 = V_19 ;
V_176 = F_51 ( V_2 , V_65 , V_15 ,
V_4 , & V_96 , & V_135 , V_159 )
+ sizeof( * V_67 ) ;
F_62 ( V_4 , V_176 ) ;
F_63 ( V_4 ) ;
V_67 = F_37 ( V_4 ) ;
memset ( V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 -> V_353 = 1 ;
V_67 -> V_354 = 1 ;
F_33 ( V_65 , V_67 ) ;
V_67 -> V_183 = V_161 -> V_355 ;
V_67 -> V_185 = V_161 -> V_356 ;
F_40 ( V_4 , F_52 ( V_65 ) -> V_357 ,
V_85 | V_197 ) ;
if ( V_99 & V_96 . V_97 ) {
if ( V_345 ) {
T_8 * V_358 = F_92 ( V_4 , V_345 ) ;
memcpy ( V_358 , V_137 -> V_359 , V_345 ) ;
F_4 ( V_4 ) -> V_10 += V_345 ;
}
if ( V_96 . V_117 > 0 ) {
T_1 V_360 [ V_361 ] ;
T_4 * V_362 = & V_159 -> V_363 [ V_364 ] ;
T_4 * V_365 = & V_362 [ V_366 - 1 ] ;
* V_365 -- ^= V_96 . V_114 ;
* V_365 -- ^= F_52 ( V_65 ) -> V_367 + 1 ;
* V_365 -- ^= F_4 ( V_4 ) -> V_72 + 1 ;
* V_365 -- ^= ( ( ( V_368 T_4 ) V_67 -> V_185 << 16 ) | ( V_368 T_4 ) V_67 -> V_183 ) ;
* V_365 -- ^= ( T_4 ) ( unsigned long ) V_137 ;
F_190 ( ( T_1 * ) & V_159 -> V_363 [ 0 ] ,
( char * ) V_362 ,
& V_360 [ 0 ] ) ;
V_96 . V_105 =
( T_5 * ) & V_159 -> V_363 [ 0 ] ;
}
}
V_67 -> V_72 = F_46 ( F_4 ( V_4 ) -> V_72 ) ;
V_67 -> V_187 = F_46 ( F_52 ( V_65 ) -> V_367 + 1 ) ;
V_67 -> V_189 = F_65 ( F_17 ( V_65 -> V_40 , 65535U ) ) ;
F_44 ( ( T_9 * ) ( V_67 + 1 ) , V_6 , & V_96 ) ;
V_67 -> V_369 = ( V_176 >> 2 ) ;
F_68 ( F_69 ( V_2 ) , V_198 , F_5 ( V_4 ) ) ;
#ifdef F_49
if ( V_135 ) {
F_52 ( V_65 ) -> V_143 -> V_194 ( V_96 . V_105 ,
V_135 , NULL , V_65 , V_4 ) ;
}
#endif
return V_4 ;
}
void F_191 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_5 V_43 ;
V_6 -> V_70 = sizeof( struct V_66 ) +
( V_147 ? V_150 : 0 ) ;
#ifdef F_49
if ( V_6 -> V_143 -> V_144 ( V_2 , V_2 ) != NULL )
V_6 -> V_70 += V_145 ;
#endif
if ( V_6 -> V_54 . V_347 )
V_6 -> V_54 . V_241 = V_6 -> V_54 . V_347 ;
V_6 -> V_370 = 0 ;
F_110 ( V_2 ) ;
F_111 ( V_2 , F_114 ( V_14 ) ) ;
if ( ! V_6 -> V_41 )
V_6 -> V_41 = F_187 ( V_14 , V_348 ) ;
V_6 -> V_16 = F_12 ( V_14 ) ;
if ( V_6 -> V_54 . V_347 && V_6 -> V_54 . V_347 < V_6 -> V_16 )
V_6 -> V_16 = V_6 -> V_54 . V_347 ;
F_192 ( V_2 ) ;
if ( V_2 -> V_349 & V_350 &&
( V_6 -> V_41 > F_147 ( V_2 ) || V_6 -> V_41 == 0 ) )
V_6 -> V_41 = F_147 ( V_2 ) ;
F_24 ( F_147 ( V_2 ) ,
V_6 -> V_16 - ( V_6 -> V_54 . V_371 ? V_6 -> V_70 - sizeof( struct V_66 ) : 0 ) ,
& V_6 -> V_40 ,
& V_6 -> V_41 ,
V_151 ,
& V_43 ,
F_187 ( V_14 , V_351 ) ) ;
V_6 -> V_54 . V_43 = V_43 ;
V_6 -> V_298 = V_6 -> V_40 ;
V_2 -> V_372 = 0 ;
F_193 ( V_2 , V_373 ) ;
V_6 -> V_277 = 0 ;
F_194 ( V_6 , 0 ) ;
V_6 -> V_87 = V_6 -> V_202 ;
V_6 -> V_258 = V_6 -> V_202 ;
V_6 -> V_88 = V_6 -> V_202 ;
V_6 -> V_9 = V_6 -> V_202 ;
if ( F_47 ( ! V_6 -> V_374 ) )
V_6 -> V_56 = 0 ;
V_6 -> V_55 = V_6 -> V_56 ;
V_6 -> V_375 = V_6 -> V_56 ;
F_18 ( V_2 ) -> V_26 = V_376 ;
F_18 ( V_2 ) -> V_377 = 0 ;
F_195 ( V_6 ) ;
}
int F_196 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_218 ;
int V_177 ;
F_191 ( V_2 ) ;
V_218 = F_172 ( V_315 + 15 , V_2 -> V_293 ) ;
if ( F_45 ( V_218 == NULL ) )
return - V_180 ;
F_174 ( V_218 , V_315 ) ;
F_40 ( V_218 , V_6 -> V_202 ++ , V_85 ) ;
F_32 ( V_2 , V_218 ) ;
F_4 ( V_218 ) -> V_148 = V_19 ;
V_6 -> V_321 = F_4 ( V_218 ) -> V_148 ;
F_73 ( V_218 ) ;
F_197 ( V_2 , V_218 ) ;
V_2 -> V_203 += V_218 -> V_204 ;
F_75 ( V_2 , V_218 -> V_204 ) ;
V_6 -> V_8 += F_5 ( V_218 ) ;
V_177 = F_54 ( V_2 , V_218 , 1 , V_2 -> V_293 ) ;
if ( V_177 == - V_378 )
return V_177 ;
V_6 -> V_9 = V_6 -> V_202 ;
V_6 -> V_379 = V_6 -> V_202 ;
F_163 ( F_69 ( V_2 ) , V_380 ) ;
F_170 ( V_2 , V_334 ,
F_18 ( V_2 ) -> V_26 , V_335 ) ;
return 0 ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
int V_35 = V_30 -> V_33 . V_35 ;
unsigned long V_381 ;
if ( V_35 > V_382 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_383 = V_384 / 2 ;
if ( V_30 -> V_33 . V_36 ||
( V_30 -> V_33 . V_385 & V_386 ) )
V_383 = V_387 ;
if ( V_6 -> V_388 ) {
int V_389 = F_19 ( V_6 -> V_388 >> 3 , V_382 ) ;
if ( V_389 < V_383 )
V_383 = V_389 ;
}
V_35 = F_17 ( V_35 , V_383 ) ;
}
V_381 = V_273 + V_35 ;
if ( V_30 -> V_33 . V_385 & V_390 ) {
if ( V_30 -> V_33 . V_391 ||
F_199 ( V_30 -> V_33 . V_381 , V_273 + ( V_35 >> 2 ) ) ) {
F_200 ( V_2 ) ;
return;
}
if ( ! F_201 ( V_381 , V_30 -> V_33 . V_381 ) )
V_381 = V_30 -> V_33 . V_381 ;
}
V_30 -> V_33 . V_385 |= V_392 | V_390 ;
V_30 -> V_33 . V_381 = V_381 ;
F_202 ( V_2 , & V_30 -> V_393 , V_381 ) ;
}
void F_200 ( struct V_1 * V_2 )
{
struct V_3 * V_218 ;
if ( V_2 -> V_291 == V_292 )
return;
V_218 = F_176 ( V_315 , V_223 ) ;
if ( V_218 == NULL ) {
F_203 ( V_2 ) ;
F_18 ( V_2 ) -> V_33 . V_35 = V_394 ;
F_170 ( V_2 , V_38 ,
V_387 , V_335 ) ;
return;
}
F_174 ( V_218 , V_315 ) ;
F_40 ( V_218 , F_7 ( V_2 ) , V_197 ) ;
F_4 ( V_218 ) -> V_148 = V_19 ;
F_54 ( V_2 , V_218 , 0 , V_223 ) ;
}
static int F_204 ( struct V_1 * V_2 , int V_395 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
V_4 = F_176 ( V_315 , V_223 ) ;
if ( V_4 == NULL )
return - 1 ;
F_174 ( V_4 , V_315 ) ;
F_40 ( V_4 , V_6 -> V_87 - ! V_395 , V_197 ) ;
F_4 ( V_4 ) -> V_148 = V_19 ;
return F_54 ( V_2 , V_4 , 0 , V_223 ) ;
}
void F_205 ( struct V_1 * V_2 )
{
if ( V_2 -> V_291 == V_396 ) {
F_2 ( V_2 ) -> V_397 = F_2 ( V_2 ) -> V_56 - 1 ;
F_2 ( V_2 ) -> V_9 = F_2 ( V_2 ) -> V_202 ;
F_204 ( V_2 , 0 ) ;
}
}
int F_206 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_2 -> V_291 == V_292 )
return - 1 ;
if ( ( V_4 = F_127 ( V_2 ) ) != NULL &&
F_8 ( F_4 ( V_4 ) -> V_72 , F_9 ( V_6 ) ) ) {
int V_177 ;
unsigned int V_15 = F_113 ( V_2 ) ;
unsigned int V_398 = F_9 ( V_6 ) - F_4 ( V_4 ) -> V_72 ;
if ( F_8 ( V_6 -> V_379 , F_4 ( V_4 ) -> V_10 ) )
V_6 -> V_379 = F_4 ( V_4 ) -> V_10 ;
if ( V_398 < F_4 ( V_4 ) -> V_10 - F_4 ( V_4 ) -> V_72 ||
V_4 -> V_71 > V_15 ) {
V_398 = F_17 ( V_398 , V_15 ) ;
F_4 ( V_4 ) -> V_58 |= V_225 ;
if ( F_85 ( V_2 , V_4 , V_398 , V_15 ) )
return - 1 ;
} else if ( ! F_5 ( V_4 ) )
F_76 ( V_2 , V_4 , V_15 ) ;
F_4 ( V_4 ) -> V_58 |= V_225 ;
F_4 ( V_4 ) -> V_148 = V_19 ;
V_177 = F_54 ( V_2 , V_4 , 1 , V_223 ) ;
if ( ! V_177 )
F_1 ( V_2 , V_4 ) ;
return V_177 ;
} else {
if ( F_207 ( V_6 -> V_88 , V_6 -> V_87 + 1 , V_6 -> V_87 + 0xFFFF ) )
F_204 ( V_2 , 1 ) ;
return F_204 ( V_2 , 0 ) ;
}
}
void F_208 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_18 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_177 ;
V_177 = F_206 ( V_2 ) ;
if ( V_6 -> V_8 || ! F_127 ( V_2 ) ) {
V_30 -> V_399 = 0 ;
V_30 -> V_400 = 0 ;
return;
}
if ( V_177 <= 0 ) {
if ( V_30 -> V_400 < V_401 )
V_30 -> V_400 ++ ;
V_30 -> V_399 ++ ;
F_170 ( V_2 , V_402 ,
F_17 ( V_30 -> V_26 << V_30 -> V_400 , V_335 ) ,
V_335 ) ;
} else {
if ( ! V_30 -> V_399 )
V_30 -> V_399 = 1 ;
F_170 ( V_2 , V_402 ,
F_17 ( V_30 -> V_26 << V_30 -> V_400 ,
V_403 ) ,
V_335 ) ;
}
}
