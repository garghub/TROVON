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
static void F_7 ( struct V_1 * V_2 , bool V_17 )
{
struct V_12 * V_13 = V_2 -> V_14 -> V_15 ;
if ( ! V_13 || ! V_13 -> V_18 )
return;
V_13 -> V_18 ( V_2 -> V_14 , V_17 ) ;
}
static bool
F_8 ( struct V_19 * V_4 , unsigned int V_20 )
{
unsigned int V_21 = V_4 -> V_22 / ( 13 * V_20 ) ;
unsigned int V_23 = V_4 -> V_22 / ( 16 * V_20 ) ;
int V_24 = V_20 - ( V_4 -> V_22 / ( 13 * V_21 ) ) ;
int V_25 = V_20 - ( V_4 -> V_22 / ( 16 * V_23 ) ) ;
if( V_24 < 0 )
V_24 = - V_24 ;
if( V_25 < 0 )
V_25 = - V_25 ;
return ( V_24 > V_25 ) ;
}
static unsigned int
F_9 ( struct V_19 * V_4 , unsigned int V_20 )
{
unsigned int V_26 ;
if ( ! F_8 ( V_4 , V_20 ) )
V_26 = 13 ;
else
V_26 = 16 ;
return V_4 -> V_22 / ( V_20 * V_26 ) ;
}
static void F_10 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_1 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
V_2 -> V_27 |= V_28 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_16 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
if ( V_2 -> V_27 & V_30 ) {
V_2 -> V_27 &= ~ V_30 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
}
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_17 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
V_2 -> V_27 &= ~ V_31 ;
V_2 -> V_4 . V_32 &= ~ V_33 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_34 )
{
struct V_35 * V_36 = & V_2 -> V_4 . V_37 -> V_36 ;
int V_38 ;
if ( V_2 -> V_4 . V_39 ) {
F_3 ( V_2 , V_40 , V_2 -> V_4 . V_39 ) ;
V_2 -> V_4 . V_41 . V_42 ++ ;
V_2 -> V_4 . V_39 = 0 ;
return;
}
if ( F_19 ( V_36 ) || F_20 ( & V_2 -> V_4 ) ) {
F_16 ( & V_2 -> V_4 ) ;
return;
}
V_38 = V_2 -> V_4 . V_43 / 4 ;
do {
F_3 ( V_2 , V_40 , V_36 -> V_44 [ V_36 -> V_45 ] ) ;
V_36 -> V_45 = ( V_36 -> V_45 + 1 ) & ( V_46 - 1 ) ;
V_2 -> V_4 . V_41 . V_42 ++ ;
if ( F_19 ( V_36 ) )
break;
} while ( -- V_38 > 0 );
if ( F_21 ( V_36 ) < V_47 ) {
F_22 ( & V_2 -> V_4 . V_48 ) ;
F_23 ( & V_2 -> V_4 ) ;
F_24 ( & V_2 -> V_4 . V_48 ) ;
}
if ( F_19 ( V_36 ) )
F_16 ( & V_2 -> V_4 ) ;
}
static inline void F_25 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_27 & V_30 ) ) {
V_2 -> V_27 |= V_30 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
}
}
static void F_26 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
F_25 ( V_2 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_27 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_49 ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_27 &= ~ ( V_31 | V_50 ) ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_30 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_49 ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_27 |= V_31 | V_50 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static unsigned int F_31 ( struct V_1 * V_2 )
{
unsigned int V_51 ;
V_51 = F_1 ( V_2 , V_52 ) ;
V_51 |= V_2 -> V_53 ;
V_2 -> V_53 = 0 ;
if ( ( V_51 & V_54 ) == 0 )
return V_51 ;
if ( V_51 & V_54 && V_2 -> V_27 & V_28 &&
V_2 -> V_4 . V_37 != NULL ) {
if ( V_51 & V_55 )
V_2 -> V_4 . V_41 . V_56 ++ ;
if ( V_51 & V_57 )
V_2 -> V_4 . V_41 . V_58 ++ ;
if ( V_51 & V_59 )
F_32
( & V_2 -> V_4 , V_51 & V_60 ) ;
if ( V_51 & V_61 )
F_33
( & V_2 -> V_4 , V_51 & V_62 ) ;
F_34 ( & V_2 -> V_4 . V_37 -> V_4 . V_63 ) ;
}
return V_51 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_34 )
{
unsigned int V_64 ;
unsigned char V_65 = 0 ;
if ( F_36 ( V_34 & V_33 ) )
V_65 = F_1 ( V_2 , V_66 ) ;
V_2 -> V_4 . V_41 . V_67 ++ ;
V_64 = V_68 ;
if ( V_34 & V_69 ) {
V_64 = V_70 ;
V_34 &= ~ ( V_71 | V_72 ) ;
V_2 -> V_4 . V_41 . V_73 ++ ;
if ( F_37 ( & V_2 -> V_4 ) )
return;
}
if ( V_34 & V_72 ) {
V_64 = V_74 ;
V_2 -> V_4 . V_41 . V_75 ++ ;
}
if ( V_34 & V_71 ) {
V_64 = V_76 ;
V_2 -> V_4 . V_41 . V_77 ++ ;
}
if ( V_34 & V_78 )
V_2 -> V_4 . V_41 . V_79 ++ ;
#ifdef F_38
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_80 -> V_81 ) {
V_34 |= V_2 -> V_82 ;
}
#endif
F_39 ( & V_2 -> V_4 , V_34 , V_78 , 0 , V_64 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_34 )
{
unsigned char V_65 = 0 ;
unsigned int V_64 ;
if ( ! ( V_34 & V_33 ) )
return;
V_65 = F_1 ( V_2 , V_66 ) ;
V_64 = V_68 ;
V_2 -> V_4 . V_41 . V_67 ++ ;
if ( F_41 ( & V_2 -> V_4 , V_65 ) )
return;
F_39 ( & V_2 -> V_4 , V_34 , V_78 , V_65 , V_64 ) ;
}
static T_1 F_42 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
unsigned int V_85 , V_34 ;
unsigned int type ;
T_1 V_86 = V_87 ;
int V_88 = 256 ;
F_24 ( & V_2 -> V_4 . V_48 ) ;
F_13 ( V_2 -> V_14 ) ;
do {
V_85 = F_1 ( V_2 , V_89 ) ;
if ( V_85 & V_90 )
break;
V_86 = V_91 ;
V_34 = F_1 ( V_2 , V_92 ) ;
type = V_85 & 0x3e ;
switch ( type ) {
case V_93 :
F_31 ( V_2 ) ;
break;
case V_94 :
F_18 ( V_2 , V_34 ) ;
break;
case V_95 :
case V_96 :
F_40 ( V_2 , V_34 ) ;
break;
case V_97 :
F_35 ( V_2 , V_34 ) ;
break;
case V_98 :
break;
case V_99 :
default:
break;
}
} while ( ! ( V_85 & V_90 ) && V_88 -- );
F_22 ( & V_2 -> V_4 . V_48 ) ;
F_43 ( & V_2 -> V_4 . V_37 -> V_4 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_100 = V_101 ;
return V_86 ;
}
static unsigned int F_44 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_49 = 0 ;
unsigned int V_86 = 0 ;
F_13 ( V_2 -> V_14 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_2 , V_2 -> V_4 . line ) ;
F_28 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_86 = F_1 ( V_2 , V_92 ) & V_102 ? V_103 : 0 ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
return V_86 ;
}
static unsigned int F_45 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned int V_51 ;
unsigned int V_86 = 0 ;
F_13 ( V_2 -> V_14 ) ;
V_51 = F_31 ( V_2 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_3 , V_2 -> V_4 . line ) ;
if ( V_51 & V_60 )
V_86 |= V_104 ;
if ( V_51 & V_105 )
V_86 |= V_106 ;
if ( V_51 & V_107 )
V_86 |= V_108 ;
if ( V_51 & V_62 )
V_86 |= V_109 ;
return V_86 ;
}
static void F_46 ( struct V_19 * V_4 , unsigned int V_110 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned char V_111 = 0 , V_112 ;
F_12 ( V_2 -> V_4 . V_14 , L_4 , V_2 -> V_4 . line ) ;
if ( V_110 & V_113 )
V_111 |= V_114 ;
if ( V_110 & V_115 )
V_111 |= V_116 ;
if ( V_110 & V_117 )
V_111 |= V_118 ;
if ( V_110 & V_119 )
V_111 |= V_120 ;
if ( V_110 & V_121 )
V_111 |= V_122 ;
F_13 ( V_2 -> V_14 ) ;
V_112 = F_1 ( V_2 , V_123 ) ;
V_112 &= ~ ( V_122 | V_120 | V_118 |
V_116 | V_114 ) ;
V_2 -> V_111 = V_112 | V_111 ;
F_3 ( V_2 , V_123 , V_2 -> V_111 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
if ( F_47 ( V_2 -> V_124 ) &&
! ! ( V_110 & V_115 ) != V_2 -> V_125 ) {
V_2 -> V_125 = ! V_2 -> V_125 ;
if ( F_48 ( V_2 -> V_124 ) )
F_49 ( & V_2 -> V_126 ) ;
else
F_50 ( V_2 -> V_124 ,
V_2 -> V_125 != V_2 -> V_127 ) ;
}
}
static void F_51 ( struct V_19 * V_4 , int V_128 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_49 = 0 ;
F_12 ( V_2 -> V_4 . V_14 , L_5 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_48 , V_49 ) ;
if ( V_128 == - 1 )
V_2 -> V_129 |= V_130 ;
else
V_2 -> V_129 &= ~ V_130 ;
F_3 ( V_2 , V_131 , V_2 -> V_129 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static int F_52 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_49 = 0 ;
int V_132 ;
V_132 = F_53 ( V_2 -> V_4 . V_83 , F_42 , V_2 -> V_4 . V_133 ,
V_2 -> V_134 , V_2 ) ;
if ( V_132 )
return V_132 ;
F_12 ( V_2 -> V_4 . V_14 , L_6 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_123 , V_114 ) ;
( void ) F_1 ( V_2 , V_92 ) ;
if ( F_1 ( V_2 , V_92 ) & V_33 )
( void ) F_1 ( V_2 , V_66 ) ;
( void ) F_1 ( V_2 , V_89 ) ;
( void ) F_1 ( V_2 , V_52 ) ;
F_3 ( V_2 , V_131 , V_135 ) ;
F_28 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_4 . V_110 |= V_119 ;
F_46 ( & V_2 -> V_4 , V_2 -> V_4 . V_110 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_53 = 0 ;
V_2 -> V_27 = V_31 | V_50 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_136 , V_137 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_100 = V_101 ;
return 0 ;
}
static void F_54 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_49 = 0 ;
F_12 ( V_2 -> V_4 . V_14 , L_7 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
V_2 -> V_27 = 0 ;
F_3 ( V_2 , V_29 , 0 ) ;
F_28 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_4 . V_110 &= ~ V_119 ;
F_46 ( & V_2 -> V_4 , V_2 -> V_4 . V_110 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_3 ( V_2 , V_131 , F_1 ( V_2 , V_131 ) & ~ V_130 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_92 ) & V_33 )
( void ) F_1 ( V_2 , V_66 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
F_55 ( V_2 -> V_4 . V_83 , V_2 ) ;
}
static void F_56 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_57 ( V_139 , struct V_1 ,
V_126 ) ;
F_58 ( & V_2 -> V_140 , V_2 -> V_141 ) ;
if ( F_47 ( V_2 -> V_124 ) )
F_59 ( V_2 -> V_124 ,
V_2 -> V_125 != V_2 -> V_127 ) ;
}
static void
F_60 ( struct V_19 * V_4 , struct V_142 * V_143 ,
struct V_142 * V_144 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned char V_145 = 0 ;
unsigned long V_49 = 0 ;
unsigned int V_20 , V_146 ;
switch ( V_143 -> V_147 & V_148 ) {
case V_149 :
V_145 = V_150 ;
break;
case V_151 :
V_145 = V_152 ;
break;
case V_153 :
V_145 = V_154 ;
break;
default:
case V_155 :
V_145 = V_135 ;
break;
}
if ( V_143 -> V_147 & V_156 )
V_145 |= V_157 ;
if ( V_143 -> V_147 & V_158 )
V_145 |= V_159 ;
if ( ! ( V_143 -> V_147 & V_160 ) )
V_145 |= V_161 ;
if ( V_143 -> V_147 & V_162 )
V_145 |= V_163 ;
V_20 = F_61 ( V_4 , V_143 , V_144 , 0 , V_4 -> V_22 / 13 ) ;
V_146 = F_9 ( V_4 , V_20 ) ;
V_2 -> V_164 = ( V_165 * V_2 -> V_4 . V_43 ) / ( V_20 / 8 ) ;
V_2 -> V_141 = V_2 -> V_164 ;
F_49 ( & V_2 -> V_126 ) ;
V_2 -> V_166 = V_146 & 0xff ;
V_2 -> V_167 = V_146 >> 8 ;
V_2 -> V_168 = V_169 ;
V_2 -> V_170 = V_171 | V_172 |
V_9 ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_62 ( V_4 , V_143 -> V_147 , V_20 ) ;
V_2 -> V_4 . V_32 = V_78 | V_173 | V_33 ;
if ( V_143 -> V_174 & V_175 )
V_2 -> V_4 . V_32 |= V_71 | V_72 ;
if ( V_143 -> V_174 & ( V_176 | V_177 ) )
V_2 -> V_4 . V_32 |= V_69 ;
V_2 -> V_4 . V_178 = 0 ;
if ( V_143 -> V_174 & V_179 )
V_2 -> V_4 . V_178 |= V_72 | V_71 ;
if ( V_143 -> V_174 & V_180 ) {
V_2 -> V_4 . V_178 |= V_69 ;
if ( V_143 -> V_174 & V_179 )
V_2 -> V_4 . V_178 |= V_78 ;
}
if ( ( V_143 -> V_147 & V_181 ) == 0 )
V_2 -> V_4 . V_178 |= V_33 ;
V_2 -> V_27 &= ~ V_28 ;
if ( F_63 ( & V_2 -> V_4 , V_143 -> V_147 ) )
V_2 -> V_27 |= V_28 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_131 , V_145 ) ;
V_2 -> V_129 = V_145 ;
V_2 -> V_182 = 0 ;
F_3 ( V_2 , V_131 , V_183 ) ;
F_3 ( V_2 , V_184 , 0 ) ;
F_3 ( V_2 , V_185 , 0 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
V_2 -> V_187 = F_1 ( V_2 , V_188 ) & ~ V_189 ;
V_2 -> V_187 &= ~ V_190 ;
F_3 ( V_2 , V_188 , V_2 -> V_187 | V_189 ) ;
F_3 ( V_2 , V_131 , V_183 ) ;
V_2 -> V_111 = F_1 ( V_2 , V_123 ) & ~ V_191 ;
F_3 ( V_2 , V_123 , V_2 -> V_111 | V_191 ) ;
V_2 -> V_182 |= V_192 ;
V_2 -> V_170 &= ~ V_193 ;
V_2 -> V_170 &= ~ V_194 ;
V_2 -> V_170 |= V_195 | V_196 |
V_9 ;
F_3 ( V_2 , V_8 , V_2 -> V_170 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_197 , V_2 -> V_182 ) ;
F_3 ( V_2 , V_131 , V_183 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_111 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_131 , V_183 ) ;
if ( V_2 -> V_198 & V_199 )
F_64 ( V_2 , V_2 -> V_168 ) ;
else
F_3 ( V_2 , V_200 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 | V_189 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_184 , V_2 -> V_166 ) ;
F_3 ( V_2 , V_185 , V_2 -> V_167 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_131 , V_145 ) ;
if ( ! F_8 ( V_4 , V_20 ) )
V_2 -> V_168 = V_201 ;
else
V_2 -> V_168 = V_202 ;
if ( V_2 -> V_198 & V_199 )
F_64 ( V_2 , V_2 -> V_168 ) ;
else
F_3 ( V_2 , V_200 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_203 , V_143 -> V_204 [ V_205 ] ) ;
F_3 ( V_2 , V_206 , V_143 -> V_204 [ V_207 ] ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 | V_189 ) ;
F_3 ( V_2 , V_131 , V_183 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_111 | V_191 ) ;
F_3 ( V_2 , V_208 , V_209 ) ;
if ( V_143 -> V_147 & V_210 && V_2 -> V_4 . V_49 & V_211 ) {
V_2 -> V_187 |= V_212 | V_213 ;
V_2 -> V_111 |= V_114 ;
} else {
V_2 -> V_187 &= ~ ( V_212 | V_213 ) ;
}
if ( V_2 -> V_4 . V_49 & V_214 ) {
V_2 -> V_187 &= V_215 ;
if ( V_143 -> V_174 & V_216 )
V_2 -> V_187 |= V_217 ;
if ( V_143 -> V_174 & V_218 )
V_2 -> V_187 |= V_219 ;
if ( V_143 -> V_174 & V_220 )
V_2 -> V_111 |= V_221 ;
else
V_2 -> V_111 &= ~ V_221 ;
}
F_3 ( V_2 , V_123 , V_2 -> V_111 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_131 , V_2 -> V_129 ) ;
F_46 ( & V_2 -> V_4 , V_2 -> V_4 . V_110 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_8 , V_2 -> V_4 . line ) ;
}
static int F_65 ( struct V_19 * V_4 , unsigned int V_37 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_7 ( V_2 , V_37 ) ;
return 0 ;
}
static void
F_66 ( struct V_19 * V_4 , unsigned int V_37 ,
unsigned int V_222 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned char V_187 ;
F_12 ( V_2 -> V_4 . V_14 , L_9 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
V_187 = F_1 ( V_2 , V_188 ) ;
F_3 ( V_2 , V_188 , V_187 | V_189 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
F_3 ( V_2 , V_29 , ( V_37 != 0 ) ? V_223 : 0 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_188 , V_187 ) ;
F_3 ( V_2 , V_131 , 0 ) ;
if ( ! F_67 ( V_2 -> V_14 ) ) {
if ( ! V_37 )
F_68 ( V_2 -> V_14 ) ;
else
F_69 ( V_2 -> V_14 ) ;
}
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_70 ( struct V_19 * V_4 )
{
F_12 ( V_4 -> V_14 , L_10 ) ;
}
static int F_71 ( struct V_19 * V_4 )
{
F_12 ( V_4 -> V_14 , L_11 ) ;
return 0 ;
}
static void F_72 ( struct V_19 * V_4 , int V_49 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_12 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . type = V_224 ;
V_2 -> V_4 . V_49 |= V_214 | V_211 ;
}
static int
F_73 ( struct V_19 * V_4 , struct V_225 * V_226 )
{
F_12 ( V_4 -> V_14 , L_13 ) ;
return - V_227 ;
}
static const char *
F_74 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_14 , V_2 -> V_4 . line ) ;
return V_2 -> V_134 ;
}
static inline void F_75 ( struct V_1 * V_2 )
{
unsigned int V_51 , V_228 = 10000 ;
do {
V_51 = F_1 ( V_2 , V_92 ) ;
if ( V_51 & V_69 )
V_2 -> V_82 = V_69 ;
if ( -- V_228 == 0 )
break;
F_76 ( 1 ) ;
} while ( ( V_51 & V_229 ) != V_229 );
if ( V_2 -> V_4 . V_49 & V_230 ) {
V_228 = 1000000 ;
for ( V_228 = 1000000 ; V_228 ; V_228 -- ) {
unsigned int V_231 = F_1 ( V_2 , V_52 ) ;
V_2 -> V_53 |= V_231 & V_232 ;
if ( V_231 & V_62 )
break;
F_76 ( 1 ) ;
}
}
}
static void F_77 ( struct V_19 * V_4 , unsigned char V_65 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_40 , V_65 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static int F_78 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned int V_51 ;
F_13 ( V_2 -> V_14 ) ;
V_51 = F_1 ( V_2 , V_92 ) ;
if ( ! ( V_51 & V_33 ) ) {
V_51 = V_233 ;
goto V_234;
}
V_51 = F_1 ( V_2 , V_66 ) ;
V_234:
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
return V_51 ;
}
static void F_79 ( struct V_19 * V_4 , int V_65 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_40 , V_65 ) ;
}
static void
F_80 ( struct V_235 * V_236 , const char * V_237 ,
unsigned int V_38 )
{
struct V_1 * V_2 = V_238 [ V_236 -> V_81 ] ;
unsigned long V_49 ;
unsigned int V_27 ;
int V_239 = 1 ;
F_13 ( V_2 -> V_14 ) ;
F_81 ( V_49 ) ;
if ( V_2 -> V_4 . V_240 )
V_239 = 0 ;
else if ( V_241 )
V_239 = F_82 ( & V_2 -> V_4 . V_48 ) ;
else
F_24 ( & V_2 -> V_4 . V_48 ) ;
V_27 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_83 ( & V_2 -> V_4 , V_237 , V_38 , F_79 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_29 , V_27 ) ;
if ( V_2 -> V_53 )
F_31 ( V_2 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
if ( V_239 )
F_22 ( & V_2 -> V_4 . V_48 ) ;
F_84 ( V_49 ) ;
}
static int T_2
F_85 ( struct V_235 * V_236 , char * V_242 )
{
struct V_1 * V_2 ;
int V_20 = 115200 ;
int V_243 = 8 ;
int V_75 = 'n' ;
int V_244 = 'n' ;
if ( V_238 [ V_236 -> V_81 ] == NULL )
return - V_245 ;
V_2 = V_238 [ V_236 -> V_81 ] ;
if ( V_242 )
F_86 ( V_242 , & V_20 , & V_75 , & V_243 , & V_244 ) ;
return F_87 ( & V_2 -> V_4 , V_236 , V_20 , V_75 , V_243 , V_244 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_238 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_88 ( struct V_1 * V_2 )
{}
static int F_89 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
F_91 ( & V_247 , & V_2 -> V_4 ) ;
F_92 ( & V_2 -> V_126 ) ;
return 0 ;
}
static int F_93 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
F_94 ( & V_247 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
T_3 V_248 , V_249 ;
T_4 V_250 , V_251 , V_252 ;
V_248 = F_1 ( V_2 , V_253 ) ;
V_249 = V_248 >> V_254 ;
switch ( V_249 ) {
case 0 :
V_251 = ( V_248 & V_255 ) >>
V_256 ;
V_252 = ( V_248 & V_257 ) ;
break;
case 1 :
V_251 = ( V_248 & V_258 ) >>
V_259 ;
V_252 = ( V_248 & V_260 ) ;
break;
default:
F_96 ( V_2 -> V_14 ,
L_15 ,
V_2 -> V_134 ) ;
V_251 = 0xff ;
V_252 = 0xff ;
}
V_250 = F_97 ( V_251 , V_252 ) ;
switch ( V_250 ) {
case V_261 :
V_2 -> V_198 |= ( V_199 |
V_262 ) ;
break;
case V_263 :
V_2 -> V_198 |= ( V_199 |
V_262 ) ;
break;
case V_264 :
V_2 -> V_198 |= V_199 ;
break;
default:
break;
}
}
static struct V_12 * F_98 ( struct V_246 * V_14 )
{
struct V_12 * V_265 ;
V_265 = F_99 ( V_14 , sizeof( * V_265 ) , V_266 ) ;
if ( ! V_265 )
return NULL ;
F_100 ( V_14 -> V_267 , L_16 ,
& V_265 -> V_22 ) ;
return V_265 ;
}
static int F_101 ( struct V_268 * V_269 )
{
struct V_1 * V_2 ;
struct V_270 * V_271 , * V_83 ;
struct V_12 * V_265 = V_269 -> V_14 . V_15 ;
int V_86 ;
if ( V_269 -> V_14 . V_267 )
V_265 = F_98 ( & V_269 -> V_14 ) ;
V_271 = F_102 ( V_269 , V_272 , 0 ) ;
if ( ! V_271 ) {
F_103 ( & V_269 -> V_14 , L_17 ) ;
return - V_245 ;
}
V_83 = F_102 ( V_269 , V_273 , 0 ) ;
if ( ! V_83 ) {
F_103 ( & V_269 -> V_14 , L_18 ) ;
return - V_245 ;
}
if ( ! F_104 ( & V_269 -> V_14 , V_271 -> V_274 , F_105 ( V_271 ) ,
V_269 -> V_14 . V_275 -> V_134 ) ) {
F_103 ( & V_269 -> V_14 , L_19 ) ;
return - V_276 ;
}
if ( F_47 ( V_265 -> V_124 ) &&
V_265 -> V_277 ) {
V_86 = F_106 ( V_265 -> V_124 , L_20 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_107 ( V_265 -> V_124 ,
V_265 -> V_127 ) ;
if ( V_86 < 0 )
return V_86 ;
}
V_2 = F_99 ( & V_269 -> V_14 , sizeof( * V_2 ) , V_266 ) ;
if ( ! V_2 )
return - V_278 ;
if ( F_47 ( V_265 -> V_124 ) &&
V_265 -> V_277 ) {
V_2 -> V_124 = V_265 -> V_124 ;
V_2 -> V_127 = V_265 -> V_127 ;
} else
V_2 -> V_124 = - V_227 ;
V_2 -> V_125 = 0 ;
V_2 -> V_14 = & V_269 -> V_14 ;
V_2 -> V_4 . V_14 = & V_269 -> V_14 ;
V_2 -> V_4 . type = V_224 ;
V_2 -> V_4 . V_279 = V_280 ;
V_2 -> V_4 . V_83 = V_83 -> V_274 ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_43 = 64 ;
V_2 -> V_4 . V_281 = & V_282 ;
if ( V_269 -> V_14 . V_267 )
V_2 -> V_4 . line = F_108 ( V_269 -> V_14 . V_267 , L_21 ) ;
else
V_2 -> V_4 . line = V_269 -> V_283 ;
if ( V_2 -> V_4 . line < 0 ) {
F_103 ( & V_269 -> V_14 , L_22 ,
V_2 -> V_4 . line ) ;
V_86 = - V_245 ;
goto V_284;
}
V_2 -> V_285 = F_109 ( & V_269 -> V_14 ) ;
if ( F_110 ( V_2 -> V_285 ) ) {
F_96 ( & V_269 -> V_14 , L_23 ,
V_2 -> V_4 . line , F_111 ( V_2 -> V_285 ) ) ;
V_2 -> V_285 = NULL ;
}
sprintf ( V_2 -> V_134 , L_24 , V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_286 = V_271 -> V_274 ;
V_2 -> V_4 . V_6 = F_112 ( & V_269 -> V_14 , V_271 -> V_274 ,
F_105 ( V_271 ) ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_103 ( & V_269 -> V_14 , L_25 ) ;
V_86 = - V_278 ;
goto V_287;
}
V_2 -> V_4 . V_49 = V_265 -> V_49 ;
V_2 -> V_4 . V_22 = V_265 -> V_22 ;
if ( ! V_2 -> V_4 . V_22 ) {
V_2 -> V_4 . V_22 = V_288 ;
F_96 ( & V_269 -> V_14 , L_26
L_27 , V_288 ) ;
}
V_2 -> V_141 = V_289 ;
V_2 -> V_164 = V_289 ;
F_113 ( & V_2 -> V_140 ,
V_290 , V_2 -> V_141 ) ;
V_291 = F_114 ( V_2 -> V_134 ) ;
F_115 ( & V_2 -> V_126 , F_56 ) ;
F_116 ( V_269 , V_2 ) ;
F_117 ( & V_269 -> V_14 ) ;
F_118 ( & V_269 -> V_14 ) ;
F_119 ( & V_269 -> V_14 ,
V_265 -> V_292 ) ;
F_120 ( & V_269 -> V_14 ) ;
F_13 ( & V_269 -> V_14 ) ;
F_95 ( V_2 ) ;
V_293 [ V_2 -> V_4 . line ] = V_2 ;
F_88 ( V_2 ) ;
V_86 = F_121 ( & V_247 , & V_2 -> V_4 ) ;
if ( V_86 != 0 )
goto V_294;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
return 0 ;
V_294:
F_122 ( & V_269 -> V_14 ) ;
F_123 ( & V_269 -> V_14 ) ;
V_287:
V_284:
F_103 ( & V_269 -> V_14 , L_28 ,
V_269 -> V_283 , V_295 , V_86 ) ;
return V_86 ;
}
static int F_124 ( struct V_268 * V_14 )
{
struct V_1 * V_2 = F_125 ( V_14 ) ;
F_126 ( V_2 -> V_14 ) ;
F_123 ( V_2 -> V_14 ) ;
F_127 ( & V_247 , & V_2 -> V_4 ) ;
F_128 ( & V_2 -> V_140 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 , T_5 V_168 )
{
T_5 V_296 = 255 ;
F_3 ( V_2 , V_200 , V_168 ) ;
F_76 ( 2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_170 | V_11 |
V_10 ) ;
while ( V_173 != ( F_1 ( V_2 , V_92 ) &
( V_173 | V_33 ) ) ) {
V_296 -- ;
if ( ! V_296 ) {
F_129 ( V_2 -> V_14 , L_29 ,
F_1 ( V_2 , V_92 ) ) ;
break;
}
F_76 ( 1 ) ;
}
}
static void F_130 ( struct V_1 * V_2 )
{
if ( V_2 -> V_198 & V_199 )
F_64 ( V_2 , V_169 ) ;
else
F_3 ( V_2 , V_200 , V_169 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_188 , V_189 ) ;
F_3 ( V_2 , V_131 , 0x0 ) ;
F_3 ( V_2 , V_29 , 0x0 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_184 , V_2 -> V_166 ) ;
F_3 ( V_2 , V_185 , V_2 -> V_167 ) ;
F_3 ( V_2 , V_131 , 0x0 ) ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_170 ) ;
F_3 ( V_2 , V_131 , V_183 ) ;
F_3 ( V_2 , V_123 , V_2 -> V_111 ) ;
F_3 ( V_2 , V_131 , V_186 ) ;
F_3 ( V_2 , V_197 , V_2 -> V_182 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_131 , V_2 -> V_129 ) ;
if ( V_2 -> V_198 & V_199 )
F_64 ( V_2 , V_2 -> V_168 ) ;
else
F_3 ( V_2 , V_200 , V_2 -> V_168 ) ;
}
static int F_131 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( ! V_2 )
return - V_227 ;
if ( ! V_13 )
return 0 ;
V_2 -> V_297 = F_6 ( V_2 ) ;
if ( F_67 ( V_14 ) ) {
if ( ! V_2 -> V_298 ) {
F_7 ( V_2 , true ) ;
V_2 -> V_298 = true ;
}
} else {
if ( V_2 -> V_298 ) {
F_7 ( V_2 , false ) ;
V_2 -> V_298 = false ;
}
}
V_2 -> V_141 = V_289 ;
F_49 ( & V_2 -> V_126 ) ;
return 0 ;
}
static int F_132 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
int V_299 = F_6 ( V_2 ) ;
if ( V_299 < 0 ) {
F_103 ( V_14 , L_30 ,
V_299 ) ;
F_130 ( V_2 ) ;
} else if ( V_2 -> V_297 != V_299 ) {
F_130 ( V_2 ) ;
}
V_2 -> V_141 = V_2 -> V_164 ;
F_49 ( & V_2 -> V_126 ) ;
return 0 ;
}
static int T_2 F_133 ( void )
{
int V_86 ;
V_86 = F_134 ( & V_247 ) ;
if ( V_86 != 0 )
return V_86 ;
V_86 = F_135 ( & V_300 ) ;
if ( V_86 != 0 )
F_136 ( & V_247 ) ;
return V_86 ;
}
static void T_6 F_137 ( void )
{
F_138 ( & V_300 ) ;
F_136 ( & V_247 ) ;
}
