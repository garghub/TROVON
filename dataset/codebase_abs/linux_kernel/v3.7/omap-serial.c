static inline unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_4 . V_5 ;
return F_2 ( V_2 -> V_4 . V_6 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_7 )
{
V_3 <<= V_2 -> V_4 . V_5 ;
F_4 ( V_7 , V_2 -> V_4 . V_6 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_8 , V_9 ) ;
F_3 ( V_2 , V_8 , V_9 |
V_10 | V_11 ) ;
F_3 ( V_2 , V_8 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 -> V_15 ;
if ( ! V_13 || ! V_13 -> V_16 )
return 0 ;
return V_13 -> V_16 ( V_2 -> V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 -> V_15 ;
if ( ! V_13 || ! V_13 -> V_17 )
return;
V_13 -> V_17 ( V_2 -> V_14 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 -> V_15 ;
if ( ! V_13 || ! V_13 -> V_18 )
return;
V_13 -> V_18 ( V_2 -> V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 , bool V_19 )
{
struct V_12 * V_13 = V_2 -> V_14 -> V_15 ;
if ( ! V_13 || ! V_13 -> V_20 )
return;
V_13 -> V_20 ( V_2 -> V_14 , V_19 ) ;
}
static unsigned int
F_10 ( struct V_21 * V_4 , unsigned int V_22 )
{
unsigned int V_23 ;
if ( V_22 > V_24 && V_22 != 3000000 )
V_23 = 13 ;
else
V_23 = 16 ;
return V_4 -> V_25 / ( V_22 * V_23 ) ;
}
static void F_11 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_1 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
V_2 -> V_26 |= V_27 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static void F_17 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_14 ( V_2 -> V_14 ) ;
if ( V_2 -> V_26 & V_29 ) {
V_2 -> V_26 &= ~ V_29 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
}
F_7 ( V_2 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static void F_18 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_14 ( V_2 -> V_14 ) ;
V_2 -> V_26 &= ~ V_30 ;
V_2 -> V_4 . V_31 &= ~ V_32 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_33 )
{
struct V_34 * V_35 = & V_2 -> V_4 . V_36 -> V_35 ;
int V_37 ;
if ( ! ( V_33 & V_38 ) )
return;
if ( V_2 -> V_4 . V_39 ) {
F_3 ( V_2 , V_40 , V_2 -> V_4 . V_39 ) ;
V_2 -> V_4 . V_41 . V_42 ++ ;
V_2 -> V_4 . V_39 = 0 ;
return;
}
if ( F_20 ( V_35 ) || F_21 ( & V_2 -> V_4 ) ) {
F_17 ( & V_2 -> V_4 ) ;
return;
}
V_37 = V_2 -> V_4 . V_43 / 4 ;
do {
F_3 ( V_2 , V_40 , V_35 -> V_44 [ V_35 -> V_45 ] ) ;
V_35 -> V_45 = ( V_35 -> V_45 + 1 ) & ( V_46 - 1 ) ;
V_2 -> V_4 . V_41 . V_42 ++ ;
if ( F_20 ( V_35 ) )
break;
} while ( -- V_37 > 0 );
if ( F_22 ( V_35 ) < V_47 ) {
F_23 ( & V_2 -> V_4 . V_48 ) ;
F_24 ( & V_2 -> V_4 ) ;
F_25 ( & V_2 -> V_4 . V_48 ) ;
}
if ( F_20 ( V_35 ) )
F_17 ( & V_2 -> V_4 ) ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_26 & V_29 ) ) {
V_2 -> V_26 |= V_29 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
}
}
static void F_27 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_14 ( V_2 -> V_14 ) ;
F_26 ( V_2 ) ;
F_8 ( V_2 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
unsigned int V_49 ;
V_49 = F_1 ( V_2 , V_50 ) ;
V_49 |= V_2 -> V_51 ;
V_2 -> V_51 = 0 ;
if ( ( V_49 & V_52 ) == 0 )
return V_49 ;
if ( V_49 & V_52 && V_2 -> V_26 & V_27 &&
V_2 -> V_4 . V_36 != NULL ) {
if ( V_49 & V_53 )
V_2 -> V_4 . V_41 . V_54 ++ ;
if ( V_49 & V_55 )
V_2 -> V_4 . V_41 . V_56 ++ ;
if ( V_49 & V_57 )
F_29
( & V_2 -> V_4 , V_49 & V_58 ) ;
if ( V_49 & V_59 )
F_30
( & V_2 -> V_4 , V_49 & V_60 ) ;
F_31 ( & V_2 -> V_4 . V_36 -> V_4 . V_61 ) ;
}
return V_49 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_33 )
{
unsigned int V_62 ;
unsigned char V_63 = 0 ;
if ( F_33 ( V_33 & V_32 ) )
V_63 = F_1 ( V_2 , V_64 ) ;
V_2 -> V_4 . V_41 . V_65 ++ ;
V_62 = V_66 ;
if ( V_33 & V_67 ) {
V_62 = V_68 ;
V_33 &= ~ ( V_69 | V_70 ) ;
V_2 -> V_4 . V_41 . V_71 ++ ;
if ( F_34 ( & V_2 -> V_4 ) )
return;
}
if ( V_33 & V_70 ) {
V_62 = V_72 ;
V_2 -> V_4 . V_41 . V_73 ++ ;
}
if ( V_33 & V_69 ) {
V_62 = V_74 ;
V_2 -> V_4 . V_41 . V_75 ++ ;
}
if ( V_33 & V_76 )
V_2 -> V_4 . V_41 . V_77 ++ ;
#ifdef F_35
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_78 -> V_79 ) {
V_33 |= V_2 -> V_80 ;
}
#endif
F_36 ( & V_2 -> V_4 , V_33 , V_76 , 0 , V_62 ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_33 )
{
unsigned char V_63 = 0 ;
unsigned int V_62 ;
if ( ! ( V_33 & V_32 ) )
return;
V_63 = F_1 ( V_2 , V_64 ) ;
V_62 = V_66 ;
V_2 -> V_4 . V_41 . V_65 ++ ;
if ( F_38 ( & V_2 -> V_4 , V_63 ) )
return;
F_36 ( & V_2 -> V_4 , V_33 , V_76 , V_63 , V_62 ) ;
}
static T_1 F_39 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
struct V_83 * V_84 = V_2 -> V_4 . V_36 -> V_4 . V_84 ;
unsigned int V_85 , V_33 ;
unsigned int type ;
T_1 V_86 = V_87 ;
int V_88 = 256 ;
F_25 ( & V_2 -> V_4 . V_48 ) ;
F_14 ( V_2 -> V_14 ) ;
do {
V_85 = F_1 ( V_2 , V_89 ) ;
if ( V_85 & V_90 )
break;
V_86 = V_91 ;
V_33 = F_1 ( V_2 , V_92 ) ;
type = V_85 & 0x3e ;
switch ( type ) {
case V_93 :
F_28 ( V_2 ) ;
break;
case V_94 :
F_19 ( V_2 , V_33 ) ;
break;
case V_95 :
case V_96 :
F_37 ( V_2 , V_33 ) ;
break;
case V_97 :
F_32 ( V_2 , V_33 ) ;
break;
case V_98 :
break;
case V_99 :
default:
break;
}
} while ( ! ( V_85 & V_90 ) && V_88 -- );
F_23 ( & V_2 -> V_4 . V_48 ) ;
F_40 ( V_84 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
V_2 -> V_100 = V_101 ;
return V_86 ;
}
static unsigned int F_41 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_102 = 0 ;
unsigned int V_86 = 0 ;
F_14 ( V_2 -> V_14 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_2 , V_2 -> V_4 . line ) ;
F_42 ( & V_2 -> V_4 . V_48 , V_102 ) ;
V_86 = F_1 ( V_2 , V_92 ) & V_103 ? V_104 : 0 ;
F_43 ( & V_2 -> V_4 . V_48 , V_102 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
return V_86 ;
}
static unsigned int F_44 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned int V_49 ;
unsigned int V_86 = 0 ;
F_14 ( V_2 -> V_14 ) ;
V_49 = F_28 ( V_2 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_3 , V_2 -> V_4 . line ) ;
if ( V_49 & V_58 )
V_86 |= V_105 ;
if ( V_49 & V_106 )
V_86 |= V_107 ;
if ( V_49 & V_108 )
V_86 |= V_109 ;
if ( V_49 & V_60 )
V_86 |= V_110 ;
return V_86 ;
}
static void F_45 ( struct V_21 * V_4 , unsigned int V_111 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_112 = 0 ;
F_13 ( V_2 -> V_4 . V_14 , L_4 , V_2 -> V_4 . line ) ;
if ( V_111 & V_113 )
V_112 |= V_114 ;
if ( V_111 & V_115 )
V_112 |= V_116 ;
if ( V_111 & V_117 )
V_112 |= V_118 ;
if ( V_111 & V_119 )
V_112 |= V_120 ;
if ( V_111 & V_121 )
V_112 |= V_122 ;
F_14 ( V_2 -> V_14 ) ;
V_2 -> V_112 = F_1 ( V_2 , V_123 ) ;
V_2 -> V_112 |= V_112 ;
F_3 ( V_2 , V_123 , V_2 -> V_112 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
if ( F_46 ( V_2 -> V_124 ) &&
! ! ( V_111 & V_115 ) != V_2 -> V_125 ) {
V_2 -> V_125 = ! V_2 -> V_125 ;
if ( F_47 ( V_2 -> V_124 ) )
F_48 ( & V_2 -> V_126 ) ;
else
F_49 ( V_2 -> V_124 ,
V_2 -> V_125 != V_2 -> V_127 ) ;
}
}
static void F_50 ( struct V_21 * V_4 , int V_128 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_102 = 0 ;
F_13 ( V_2 -> V_4 . V_14 , L_5 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
F_42 ( & V_2 -> V_4 . V_48 , V_102 ) ;
if ( V_128 == - 1 )
V_2 -> V_129 |= V_130 ;
else
V_2 -> V_129 &= ~ V_130 ;
F_3 ( V_2 , V_131 , V_2 -> V_129 ) ;
F_43 ( & V_2 -> V_4 . V_48 , V_102 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static int F_51 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_102 = 0 ;
int V_132 ;
V_132 = F_52 ( V_2 -> V_4 . V_81 , F_39 , V_2 -> V_4 . V_133 ,
V_2 -> V_134 , V_2 ) ;
if ( V_132 )
return V_132 ;
F_13 ( V_2 -> V_4 . V_14 , L_6 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_123 , V_114 ) ;
( void ) F_1 ( V_2 , V_92 ) ;
if ( F_1 ( V_2 , V_92 ) & V_32 )
( void ) F_1 ( V_2 , V_64 ) ;
( void ) F_1 ( V_2 , V_89 ) ;
( void ) F_1 ( V_2 , V_50 ) ;
F_3 ( V_2 , V_131 , V_135 ) ;
F_42 ( & V_2 -> V_4 . V_48 , V_102 ) ;
V_2 -> V_4 . V_111 |= V_119 ;
F_45 ( & V_2 -> V_4 , V_2 -> V_4 . V_111 ) ;
F_43 ( & V_2 -> V_4 . V_48 , V_102 ) ;
V_2 -> V_51 = 0 ;
V_2 -> V_26 = V_30 | V_136 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_137 , V_138 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
V_2 -> V_100 = V_101 ;
return 0 ;
}
static void F_53 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_102 = 0 ;
F_13 ( V_2 -> V_4 . V_14 , L_7 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
V_2 -> V_26 = 0 ;
F_3 ( V_2 , V_28 , 0 ) ;
F_42 ( & V_2 -> V_4 . V_48 , V_102 ) ;
V_2 -> V_4 . V_111 &= ~ V_119 ;
F_45 ( & V_2 -> V_4 , V_2 -> V_4 . V_111 ) ;
F_43 ( & V_2 -> V_4 . V_48 , V_102 ) ;
F_3 ( V_2 , V_131 , F_1 ( V_2 , V_131 ) & ~ V_130 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_92 ) & V_32 )
( void ) F_1 ( V_2 , V_64 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
F_54 ( V_2 -> V_4 . V_81 , V_2 ) ;
}
static inline void
F_55
( struct V_1 * V_2 , struct V_139 * V_140 )
{
V_2 -> V_129 = F_1 ( V_2 , V_131 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
V_2 -> V_142 = F_1 ( V_2 , V_143 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 & ~ V_144 ) ;
F_3 ( V_2 , V_145 , V_140 -> V_146 [ V_147 ] ) ;
F_3 ( V_2 , V_148 , V_140 -> V_146 [ V_149 ] ) ;
V_2 -> V_142 &= V_150 ;
if ( V_140 -> V_151 & V_152 )
V_2 -> V_142 |= V_153 ;
if ( V_140 -> V_151 & V_154 )
V_2 -> V_142 |= V_155 ;
F_3 ( V_2 , V_143 , V_2 -> V_142 | V_144 ) ;
F_3 ( V_2 , V_131 , V_156 ) ;
V_2 -> V_112 = F_1 ( V_2 , V_123 ) ;
if ( V_140 -> V_151 & V_157 )
V_2 -> V_112 |= V_158 ;
F_3 ( V_2 , V_123 , V_2 -> V_112 | V_159 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_160 , V_161 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 | V_162 ) ;
F_3 ( V_2 , V_131 , V_156 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_112 & ~ V_159 ) ;
F_3 ( V_2 , V_131 , V_2 -> V_129 ) ;
}
static void F_56 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = F_57 ( V_164 , struct V_1 ,
V_126 ) ;
F_58 ( & V_2 -> V_165 , V_2 -> V_166 ) ;
if ( F_46 ( V_2 -> V_124 ) )
F_59 ( V_2 -> V_124 ,
V_2 -> V_125 != V_2 -> V_127 ) ;
}
static void
F_60 ( struct V_21 * V_4 , struct V_139 * V_140 ,
struct V_139 * V_167 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_168 = 0 ;
unsigned char V_142 = 0 ;
unsigned long V_102 = 0 ;
unsigned int V_22 , V_169 ;
switch ( V_140 -> V_170 & V_171 ) {
case V_172 :
V_168 = V_173 ;
break;
case V_174 :
V_168 = V_175 ;
break;
case V_176 :
V_168 = V_177 ;
break;
default:
case V_178 :
V_168 = V_135 ;
break;
}
if ( V_140 -> V_170 & V_179 )
V_168 |= V_180 ;
if ( V_140 -> V_170 & V_181 )
V_168 |= V_182 ;
if ( ! ( V_140 -> V_170 & V_183 ) )
V_168 |= V_184 ;
V_22 = F_61 ( V_4 , V_140 , V_167 , 0 , V_4 -> V_25 / 13 ) ;
V_169 = F_10 ( V_4 , V_22 ) ;
V_2 -> V_185 = ( V_186 * V_2 -> V_4 . V_43 ) / ( V_22 / 8 ) ;
V_2 -> V_166 = V_2 -> V_185 ;
F_48 ( & V_2 -> V_126 ) ;
V_2 -> V_187 = V_169 & 0xff ;
V_2 -> V_188 = V_169 >> 8 ;
V_2 -> V_189 = V_190 ;
V_2 -> V_191 = V_192 | V_193 |
V_9 ;
F_14 ( V_2 -> V_14 ) ;
F_42 ( & V_2 -> V_4 . V_48 , V_102 ) ;
F_62 ( V_4 , V_140 -> V_170 , V_22 ) ;
V_2 -> V_4 . V_31 = V_76 | V_38 | V_32 ;
if ( V_140 -> V_151 & V_194 )
V_2 -> V_4 . V_31 |= V_69 | V_70 ;
if ( V_140 -> V_151 & ( V_195 | V_196 ) )
V_2 -> V_4 . V_31 |= V_67 ;
V_2 -> V_4 . V_197 = 0 ;
if ( V_140 -> V_151 & V_198 )
V_2 -> V_4 . V_197 |= V_70 | V_69 ;
if ( V_140 -> V_151 & V_199 ) {
V_2 -> V_4 . V_197 |= V_67 ;
if ( V_140 -> V_151 & V_198 )
V_2 -> V_4 . V_197 |= V_76 ;
}
if ( ( V_140 -> V_170 & V_200 ) == 0 )
V_2 -> V_4 . V_197 |= V_32 ;
V_2 -> V_26 &= ~ V_27 ;
if ( F_63 ( & V_2 -> V_4 , V_140 -> V_170 ) )
V_2 -> V_26 |= V_27 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_131 , V_168 ) ;
V_2 -> V_129 = V_168 ;
V_2 -> V_201 = V_202 ;
F_3 ( V_2 , V_131 , V_156 ) ;
F_3 ( V_2 , V_203 , 0 ) ;
F_3 ( V_2 , V_204 , 0 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
V_2 -> V_142 = F_1 ( V_2 , V_143 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 | V_144 ) ;
F_3 ( V_2 , V_131 , V_156 ) ;
V_2 -> V_112 = F_1 ( V_2 , V_123 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_112 | V_159 ) ;
V_2 -> V_201 |= V_205 ;
V_2 -> V_191 &= ~ V_206 ;
V_2 -> V_191 &= ~ V_207 ;
V_2 -> V_191 |= V_208 | V_209 |
V_9 ;
F_3 ( V_2 , V_8 , V_2 -> V_191 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_210 , V_2 -> V_201 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 ) ;
F_3 ( V_2 , V_131 , V_156 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_112 ) ;
if ( V_2 -> V_211 & V_212 )
F_64 ( V_2 , V_2 -> V_189 ) ;
else
F_3 ( V_2 , V_213 , V_2 -> V_189 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
V_2 -> V_142 = F_1 ( V_2 , V_143 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 | V_144 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_28 , 0 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_203 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_204 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 ) ;
F_3 ( V_2 , V_131 , V_168 ) ;
if ( V_22 > 230400 && V_22 != 3000000 )
V_2 -> V_189 = V_214 ;
else
V_2 -> V_189 = V_215 ;
if ( V_2 -> V_211 & V_212 )
F_64 ( V_2 , V_2 -> V_189 ) ;
else
F_3 ( V_2 , V_213 , V_2 -> V_189 ) ;
if ( V_140 -> V_170 & V_216 ) {
V_142 |= ( V_217 | V_218 ) ;
F_3 ( V_2 , V_131 , V_156 ) ;
V_2 -> V_112 = F_1 ( V_2 , V_123 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_112 | V_159 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
V_2 -> V_142 = F_1 ( V_2 , V_143 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 | V_144 ) ;
F_3 ( V_2 , V_160 , V_161 ) ;
F_3 ( V_2 , V_143 , V_142 ) ;
F_3 ( V_2 , V_131 , V_156 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_112 | V_114 ) ;
F_3 ( V_2 , V_131 , V_168 ) ;
}
F_45 ( & V_2 -> V_4 , V_2 -> V_4 . V_111 ) ;
F_55 ( V_2 , V_140 ) ;
F_43 ( & V_2 -> V_4 . V_48 , V_102 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_8 , V_2 -> V_4 . line ) ;
}
static int F_65 ( struct V_21 * V_4 , unsigned int V_36 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_9 ( V_2 , V_36 ) ;
return 0 ;
}
static void
F_66 ( struct V_21 * V_4 , unsigned int V_36 ,
unsigned int V_219 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_142 ;
F_13 ( V_2 -> V_4 . V_14 , L_9 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
V_142 = F_1 ( V_2 , V_143 ) ;
F_3 ( V_2 , V_143 , V_142 | V_144 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_28 , ( V_36 != 0 ) ? V_220 : 0 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_143 , V_142 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
if ( ! F_67 ( V_2 -> V_14 ) ) {
if ( ! V_36 )
F_68 ( V_2 -> V_14 ) ;
else
F_69 ( V_2 -> V_14 ) ;
}
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static void F_70 ( struct V_21 * V_4 )
{
F_13 ( V_4 -> V_14 , L_10 ) ;
}
static int F_71 ( struct V_21 * V_4 )
{
F_13 ( V_4 -> V_14 , L_11 ) ;
return 0 ;
}
static void F_72 ( struct V_21 * V_4 , int V_102 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_12 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . type = V_221 ;
}
static int
F_73 ( struct V_21 * V_4 , struct V_222 * V_223 )
{
F_13 ( V_4 -> V_14 , L_13 ) ;
return - V_224 ;
}
static const char *
F_74 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_14 , V_2 -> V_4 . line ) ;
return V_2 -> V_134 ;
}
static inline void F_75 ( struct V_1 * V_2 )
{
unsigned int V_49 , V_225 = 10000 ;
do {
V_49 = F_1 ( V_2 , V_92 ) ;
if ( V_49 & V_67 )
V_2 -> V_80 = V_67 ;
if ( -- V_225 == 0 )
break;
F_76 ( 1 ) ;
} while ( ( V_49 & V_226 ) != V_226 );
if ( V_2 -> V_4 . V_102 & V_227 ) {
V_225 = 1000000 ;
for ( V_225 = 1000000 ; V_225 ; V_225 -- ) {
unsigned int V_228 = F_1 ( V_2 , V_50 ) ;
V_2 -> V_51 |= V_228 & V_229 ;
if ( V_228 & V_60 )
break;
F_76 ( 1 ) ;
}
}
}
static void F_77 ( struct V_21 * V_4 , unsigned char V_63 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_14 ( V_2 -> V_14 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_40 , V_63 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static int F_78 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned int V_49 ;
F_14 ( V_2 -> V_14 ) ;
V_49 = F_1 ( V_2 , V_92 ) ;
if ( ! ( V_49 & V_32 ) ) {
V_49 = V_230 ;
goto V_231;
}
V_49 = F_1 ( V_2 , V_64 ) ;
V_231:
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
return V_49 ;
}
static void F_79 ( struct V_21 * V_4 , int V_63 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_40 , V_63 ) ;
}
static void
F_80 ( struct V_232 * V_233 , const char * V_234 ,
unsigned int V_37 )
{
struct V_1 * V_2 = V_235 [ V_233 -> V_79 ] ;
unsigned long V_102 ;
unsigned int V_26 ;
int V_236 = 1 ;
F_14 ( V_2 -> V_14 ) ;
F_81 ( V_102 ) ;
if ( V_2 -> V_4 . V_237 )
V_236 = 0 ;
else if ( V_238 )
V_236 = F_82 ( & V_2 -> V_4 . V_48 ) ;
else
F_25 ( & V_2 -> V_4 . V_48 ) ;
V_26 = F_1 ( V_2 , V_28 ) ;
F_3 ( V_2 , V_28 , 0 ) ;
F_83 ( & V_2 -> V_4 , V_234 , V_37 , F_79 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_28 , V_26 ) ;
if ( V_2 -> V_51 )
F_28 ( V_2 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
if ( V_236 )
F_23 ( & V_2 -> V_4 . V_48 ) ;
F_84 ( V_102 ) ;
}
static int T_2
F_85 ( struct V_232 * V_233 , char * V_239 )
{
struct V_1 * V_2 ;
int V_22 = 115200 ;
int V_240 = 8 ;
int V_73 = 'n' ;
int V_241 = 'n' ;
if ( V_235 [ V_233 -> V_79 ] == NULL )
return - V_242 ;
V_2 = V_235 [ V_233 -> V_79 ] ;
if ( V_239 )
F_86 ( V_239 , & V_22 , & V_73 , & V_240 , & V_241 ) ;
return F_87 ( & V_2 -> V_4 , V_233 , V_22 , V_73 , V_240 , V_241 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_235 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_88 ( struct V_1 * V_2 )
{}
static int F_89 ( struct V_243 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
F_91 ( & V_244 , & V_2 -> V_4 ) ;
F_92 ( & V_2 -> V_126 ) ;
return 0 ;
}
static int F_93 ( struct V_243 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
F_94 ( & V_244 , & V_2 -> V_4 ) ;
return 0 ;
}
static void T_3 F_95 ( struct V_1 * V_2 )
{
T_4 V_245 , V_246 ;
T_5 V_247 , V_248 , V_249 ;
V_245 = F_1 ( V_2 , V_250 ) ;
V_246 = V_245 >> V_251 ;
switch ( V_246 ) {
case 0 :
V_248 = ( V_245 & V_252 ) >>
V_253 ;
V_249 = ( V_245 & V_254 ) ;
break;
case 1 :
V_248 = ( V_245 & V_255 ) >>
V_256 ;
V_249 = ( V_245 & V_257 ) ;
break;
default:
F_96 ( V_2 -> V_14 ,
L_15 ,
V_2 -> V_134 ) ;
V_248 = 0xff ;
V_249 = 0xff ;
}
V_247 = F_97 ( V_248 , V_249 ) ;
switch ( V_247 ) {
case V_258 :
V_2 -> V_211 |= ( V_212 |
V_259 ) ;
break;
case V_260 :
V_2 -> V_211 |= ( V_212 |
V_259 ) ;
break;
case V_261 :
V_2 -> V_211 |= V_212 ;
break;
default:
break;
}
}
int T_3 F_98 ( struct V_262 * V_263 )
{
struct V_1 * V_2 ;
struct V_264 * V_265 , * V_81 ;
struct V_12 * V_266 = V_263 -> V_14 . V_15 ;
int V_86 ;
if ( V_263 -> V_14 . V_267 )
V_266 = F_99 ( & V_263 -> V_14 ) ;
V_265 = F_100 ( V_263 , V_268 , 0 ) ;
if ( ! V_265 ) {
F_101 ( & V_263 -> V_14 , L_16 ) ;
return - V_242 ;
}
V_81 = F_100 ( V_263 , V_269 , 0 ) ;
if ( ! V_81 ) {
F_101 ( & V_263 -> V_14 , L_17 ) ;
return - V_242 ;
}
if ( ! F_102 ( & V_263 -> V_14 , V_265 -> V_270 , F_103 ( V_265 ) ,
V_263 -> V_14 . V_271 -> V_134 ) ) {
F_101 ( & V_263 -> V_14 , L_18 ) ;
return - V_272 ;
}
if ( F_46 ( V_266 -> V_124 ) &&
V_266 -> V_273 ) {
V_86 = F_104 ( V_266 -> V_124 , L_19 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_105 ( V_266 -> V_124 ,
V_266 -> V_127 ) ;
if ( V_86 < 0 )
return V_86 ;
}
V_2 = F_106 ( & V_263 -> V_14 , sizeof( * V_2 ) , V_274 ) ;
if ( ! V_2 )
return - V_275 ;
if ( F_46 ( V_266 -> V_124 ) &&
V_266 -> V_273 ) {
V_2 -> V_124 = V_266 -> V_124 ;
V_2 -> V_127 = V_266 -> V_127 ;
} else
V_2 -> V_124 = - V_224 ;
V_2 -> V_125 = 0 ;
V_2 -> V_14 = & V_263 -> V_14 ;
V_2 -> V_4 . V_14 = & V_263 -> V_14 ;
V_2 -> V_4 . type = V_221 ;
V_2 -> V_4 . V_276 = V_277 ;
V_2 -> V_4 . V_81 = V_81 -> V_270 ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_43 = 64 ;
V_2 -> V_4 . V_278 = & V_279 ;
if ( V_263 -> V_14 . V_267 )
V_2 -> V_4 . line = F_107 ( V_263 -> V_14 . V_267 , L_20 ) ;
else
V_2 -> V_4 . line = V_263 -> V_280 ;
if ( V_2 -> V_4 . line < 0 ) {
F_101 ( & V_263 -> V_14 , L_21 ,
V_2 -> V_4 . line ) ;
V_86 = - V_242 ;
goto V_281;
}
V_2 -> V_282 = F_108 ( & V_263 -> V_14 ) ;
if ( F_109 ( V_2 -> V_282 ) ) {
F_96 ( & V_263 -> V_14 , L_22 ,
V_2 -> V_4 . line , F_110 ( V_2 -> V_282 ) ) ;
V_2 -> V_282 = NULL ;
}
sprintf ( V_2 -> V_134 , L_23 , V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_283 = V_265 -> V_270 ;
V_2 -> V_4 . V_6 = F_111 ( & V_263 -> V_14 , V_265 -> V_270 ,
F_103 ( V_265 ) ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_101 ( & V_263 -> V_14 , L_24 ) ;
V_86 = - V_275 ;
goto V_284;
}
V_2 -> V_4 . V_102 = V_266 -> V_102 ;
V_2 -> V_4 . V_25 = V_266 -> V_25 ;
if ( ! V_2 -> V_4 . V_25 ) {
V_2 -> V_4 . V_25 = V_285 ;
F_96 ( & V_263 -> V_14 , L_25
L_26 , V_285 ) ;
}
V_2 -> V_166 = V_286 ;
V_2 -> V_185 = V_286 ;
F_112 ( & V_2 -> V_165 ,
V_287 , V_2 -> V_166 ) ;
V_288 = F_113 ( V_2 -> V_134 ) ;
F_114 ( & V_2 -> V_126 , F_56 ) ;
F_115 ( V_263 , V_2 ) ;
F_116 ( & V_263 -> V_14 ) ;
F_117 ( & V_263 -> V_14 ) ;
F_118 ( & V_263 -> V_14 ,
V_266 -> V_289 ) ;
F_119 ( & V_263 -> V_14 ) ;
F_14 ( & V_263 -> V_14 ) ;
F_95 ( V_2 ) ;
V_290 [ V_2 -> V_4 . line ] = V_2 ;
F_88 ( V_2 ) ;
V_86 = F_120 ( & V_244 , & V_2 -> V_4 ) ;
if ( V_86 != 0 )
goto V_291;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
return 0 ;
V_291:
F_121 ( & V_263 -> V_14 ) ;
F_122 ( & V_263 -> V_14 ) ;
V_284:
V_281:
F_101 ( & V_263 -> V_14 , L_27 ,
V_263 -> V_280 , V_292 , V_86 ) ;
return V_86 ;
}
static int T_6 F_123 ( struct V_262 * V_14 )
{
struct V_1 * V_2 = F_124 ( V_14 ) ;
F_125 ( V_2 -> V_14 ) ;
F_122 ( V_2 -> V_14 ) ;
F_126 ( & V_244 , & V_2 -> V_4 ) ;
F_127 ( & V_2 -> V_165 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 , T_7 V_189 )
{
T_7 V_293 = 255 ;
F_3 ( V_2 , V_213 , V_189 ) ;
F_76 ( 2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_191 | V_11 |
V_10 ) ;
while ( V_38 != ( F_1 ( V_2 , V_92 ) &
( V_38 | V_32 ) ) ) {
V_293 -- ;
if ( ! V_293 ) {
F_128 ( V_2 -> V_14 , L_28 ,
F_1 ( V_2 , V_92 ) ) ;
break;
}
F_76 ( 1 ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
if ( V_2 -> V_211 & V_212 )
F_64 ( V_2 , V_190 ) ;
else
F_3 ( V_2 , V_213 , V_190 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_143 , V_144 ) ;
F_3 ( V_2 , V_131 , 0x0 ) ;
F_3 ( V_2 , V_28 , 0x0 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_203 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_204 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_131 , 0x0 ) ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_191 ) ;
F_3 ( V_2 , V_131 , V_156 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_112 ) ;
F_3 ( V_2 , V_131 , V_141 ) ;
F_3 ( V_2 , V_210 , V_2 -> V_201 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_142 ) ;
F_3 ( V_2 , V_131 , V_2 -> V_129 ) ;
if ( V_2 -> V_211 & V_212 )
F_64 ( V_2 , V_2 -> V_189 ) ;
else
F_3 ( V_2 , V_213 , V_2 -> V_189 ) ;
}
static int F_130 ( struct V_243 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( ! V_2 )
return - V_224 ;
if ( ! V_13 )
return 0 ;
V_2 -> V_294 = F_6 ( V_2 ) ;
if ( F_67 ( V_14 ) ) {
if ( ! V_2 -> V_295 ) {
F_9 ( V_2 , true ) ;
V_2 -> V_295 = true ;
}
} else {
if ( V_2 -> V_295 ) {
F_9 ( V_2 , false ) ;
V_2 -> V_295 = false ;
}
}
V_2 -> V_166 = V_286 ;
F_48 ( & V_2 -> V_126 ) ;
return 0 ;
}
static int F_131 ( struct V_243 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
T_4 V_296 = F_6 ( V_2 ) ;
if ( V_2 -> V_294 != V_296 )
F_129 ( V_2 ) ;
V_2 -> V_166 = V_2 -> V_185 ;
F_48 ( & V_2 -> V_126 ) ;
return 0 ;
}
static int T_2 F_132 ( void )
{
int V_86 ;
V_86 = F_133 ( & V_244 ) ;
if ( V_86 != 0 )
return V_86 ;
V_86 = F_134 ( & V_297 ) ;
if ( V_86 != 0 )
F_135 ( & V_244 ) ;
return V_86 ;
}
static void T_8 F_136 ( void )
{
F_137 ( & V_297 ) ;
F_135 ( & V_244 ) ;
}
