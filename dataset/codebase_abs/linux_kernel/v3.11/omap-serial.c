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
return - V_17 ;
return V_13 -> V_16 ( V_2 -> V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 , bool V_18 )
{
struct V_12 * V_13 = V_2 -> V_14 -> V_15 ;
if ( ! V_13 || ! V_13 -> V_19 )
return;
V_13 -> V_19 ( V_2 -> V_14 , V_18 ) ;
}
static bool
F_8 ( struct V_20 * V_4 , unsigned int V_21 )
{
unsigned int V_22 = V_4 -> V_23 / ( 13 * V_21 ) ;
unsigned int V_24 = V_4 -> V_23 / ( 16 * V_21 ) ;
int V_25 = V_21 - ( V_4 -> V_23 / ( 13 * V_22 ) ) ;
int V_26 = V_21 - ( V_4 -> V_23 / ( 16 * V_24 ) ) ;
if( V_25 < 0 )
V_25 = - V_25 ;
if( V_26 < 0 )
V_26 = - V_26 ;
return ( V_25 > V_26 ) ;
}
static unsigned int
F_9 ( struct V_20 * V_4 , unsigned int V_21 )
{
unsigned int V_27 ;
if ( ! F_8 ( V_4 , V_21 ) )
V_27 = 13 ;
else
V_27 = 16 ;
return V_4 -> V_23 / ( V_21 * V_27 ) ;
}
static void F_10 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_1 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
V_2 -> V_28 |= V_29 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_16 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
if ( V_2 -> V_28 & V_31 ) {
V_2 -> V_28 &= ~ V_31 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_17 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
V_2 -> V_28 &= ~ V_32 ;
V_2 -> V_4 . V_33 &= ~ V_34 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_35 )
{
struct V_36 * V_37 = & V_2 -> V_4 . V_38 -> V_37 ;
int V_39 ;
if ( V_2 -> V_4 . V_40 ) {
F_3 ( V_2 , V_41 , V_2 -> V_4 . V_40 ) ;
V_2 -> V_4 . V_42 . V_43 ++ ;
V_2 -> V_4 . V_40 = 0 ;
return;
}
if ( F_19 ( V_37 ) || F_20 ( & V_2 -> V_4 ) ) {
F_16 ( & V_2 -> V_4 ) ;
return;
}
V_39 = V_2 -> V_4 . V_44 / 4 ;
do {
F_3 ( V_2 , V_41 , V_37 -> V_45 [ V_37 -> V_46 ] ) ;
V_37 -> V_46 = ( V_37 -> V_46 + 1 ) & ( V_47 - 1 ) ;
V_2 -> V_4 . V_42 . V_43 ++ ;
if ( F_19 ( V_37 ) )
break;
} while ( -- V_39 > 0 );
if ( F_21 ( V_37 ) < V_48 ) {
F_22 ( & V_2 -> V_4 . V_49 ) ;
F_23 ( & V_2 -> V_4 ) ;
F_24 ( & V_2 -> V_4 . V_49 ) ;
}
if ( F_19 ( V_37 ) )
F_16 ( & V_2 -> V_4 ) ;
}
static inline void F_25 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_28 & V_31 ) ) {
V_2 -> V_28 |= V_31 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
}
static void F_26 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
F_25 ( V_2 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_27 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_50 ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_49 , V_50 ) ;
V_2 -> V_28 &= ~ ( V_32 | V_51 ) ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_29 ( & V_2 -> V_4 . V_49 , V_50 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_30 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_50 ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_49 , V_50 ) ;
V_2 -> V_28 |= V_32 | V_51 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_29 ( & V_2 -> V_4 . V_49 , V_50 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static unsigned int F_31 ( struct V_1 * V_2 )
{
unsigned int V_52 ;
V_52 = F_1 ( V_2 , V_53 ) ;
V_52 |= V_2 -> V_54 ;
V_2 -> V_54 = 0 ;
if ( ( V_52 & V_55 ) == 0 )
return V_52 ;
if ( V_52 & V_55 && V_2 -> V_28 & V_29 &&
V_2 -> V_4 . V_38 != NULL ) {
if ( V_52 & V_56 )
V_2 -> V_4 . V_42 . V_57 ++ ;
if ( V_52 & V_58 )
V_2 -> V_4 . V_42 . V_59 ++ ;
if ( V_52 & V_60 )
F_32
( & V_2 -> V_4 , V_52 & V_61 ) ;
if ( V_52 & V_62 )
F_33
( & V_2 -> V_4 , V_52 & V_63 ) ;
F_34 ( & V_2 -> V_4 . V_38 -> V_4 . V_64 ) ;
}
return V_52 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_35 )
{
unsigned int V_65 ;
unsigned char V_66 = 0 ;
if ( F_36 ( V_35 & V_34 ) )
V_66 = F_1 ( V_2 , V_67 ) ;
V_2 -> V_4 . V_42 . V_68 ++ ;
V_65 = V_69 ;
if ( V_35 & V_70 ) {
V_65 = V_71 ;
V_35 &= ~ ( V_72 | V_73 ) ;
V_2 -> V_4 . V_42 . V_74 ++ ;
if ( F_37 ( & V_2 -> V_4 ) )
return;
}
if ( V_35 & V_73 ) {
V_65 = V_75 ;
V_2 -> V_4 . V_42 . V_76 ++ ;
}
if ( V_35 & V_72 ) {
V_65 = V_77 ;
V_2 -> V_4 . V_42 . V_78 ++ ;
}
if ( V_35 & V_79 )
V_2 -> V_4 . V_42 . V_80 ++ ;
#ifdef F_38
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_81 -> V_82 ) {
V_35 |= V_2 -> V_83 ;
}
#endif
F_39 ( & V_2 -> V_4 , V_35 , V_79 , 0 , V_65 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_35 )
{
unsigned char V_66 = 0 ;
unsigned int V_65 ;
if ( ! ( V_35 & V_34 ) )
return;
V_66 = F_1 ( V_2 , V_67 ) ;
V_65 = V_69 ;
V_2 -> V_4 . V_42 . V_68 ++ ;
if ( F_41 ( & V_2 -> V_4 , V_66 ) )
return;
F_39 ( & V_2 -> V_4 , V_35 , V_79 , V_66 , V_65 ) ;
}
static T_1 F_42 ( int V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
unsigned int V_86 , V_35 ;
unsigned int type ;
T_1 V_87 = V_88 ;
int V_89 = 256 ;
F_24 ( & V_2 -> V_4 . V_49 ) ;
F_13 ( V_2 -> V_14 ) ;
do {
V_86 = F_1 ( V_2 , V_90 ) ;
if ( V_86 & V_91 )
break;
V_87 = V_92 ;
V_35 = F_1 ( V_2 , V_93 ) ;
type = V_86 & 0x3e ;
switch ( type ) {
case V_94 :
F_31 ( V_2 ) ;
break;
case V_95 :
F_18 ( V_2 , V_35 ) ;
break;
case V_96 :
case V_97 :
F_40 ( V_2 , V_35 ) ;
break;
case V_98 :
F_35 ( V_2 , V_35 ) ;
break;
case V_99 :
break;
case V_100 :
default:
break;
}
} while ( ! ( V_86 & V_91 ) && V_89 -- );
F_22 ( & V_2 -> V_4 . V_49 ) ;
F_43 ( & V_2 -> V_4 . V_38 -> V_4 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_101 = V_102 ;
return V_87 ;
}
static unsigned int F_44 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_50 = 0 ;
unsigned int V_87 = 0 ;
F_13 ( V_2 -> V_14 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_2 , V_2 -> V_4 . line ) ;
F_28 ( & V_2 -> V_4 . V_49 , V_50 ) ;
V_87 = F_1 ( V_2 , V_93 ) & V_103 ? V_104 : 0 ;
F_29 ( & V_2 -> V_4 . V_49 , V_50 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
return V_87 ;
}
static unsigned int F_45 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned int V_52 ;
unsigned int V_87 = 0 ;
F_13 ( V_2 -> V_14 ) ;
V_52 = F_31 ( V_2 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_3 , V_2 -> V_4 . line ) ;
if ( V_52 & V_61 )
V_87 |= V_105 ;
if ( V_52 & V_106 )
V_87 |= V_107 ;
if ( V_52 & V_108 )
V_87 |= V_109 ;
if ( V_52 & V_63 )
V_87 |= V_110 ;
return V_87 ;
}
static void F_46 ( struct V_20 * V_4 , unsigned int V_111 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned char V_112 = 0 , V_113 ;
F_12 ( V_2 -> V_4 . V_14 , L_4 , V_2 -> V_4 . line ) ;
if ( V_111 & V_114 )
V_112 |= V_115 ;
if ( V_111 & V_116 )
V_112 |= V_117 ;
if ( V_111 & V_118 )
V_112 |= V_119 ;
if ( V_111 & V_120 )
V_112 |= V_121 ;
if ( V_111 & V_122 )
V_112 |= V_123 ;
F_13 ( V_2 -> V_14 ) ;
V_113 = F_1 ( V_2 , V_124 ) ;
V_113 &= ~ ( V_123 | V_121 | V_119 |
V_117 | V_115 ) ;
V_2 -> V_112 = V_113 | V_112 ;
F_3 ( V_2 , V_124 , V_2 -> V_112 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
if ( F_47 ( V_2 -> V_125 ) &&
! ! ( V_111 & V_116 ) != V_2 -> V_126 ) {
V_2 -> V_126 = ! V_2 -> V_126 ;
if ( F_48 ( V_2 -> V_125 ) )
F_49 ( & V_2 -> V_127 ) ;
else
F_50 ( V_2 -> V_125 ,
V_2 -> V_126 != V_2 -> V_128 ) ;
}
}
static void F_51 ( struct V_20 * V_4 , int V_129 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_50 = 0 ;
F_12 ( V_2 -> V_4 . V_14 , L_5 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_49 , V_50 ) ;
if ( V_129 == - 1 )
V_2 -> V_130 |= V_131 ;
else
V_2 -> V_130 &= ~ V_131 ;
F_3 ( V_2 , V_132 , V_2 -> V_130 ) ;
F_29 ( & V_2 -> V_4 . V_49 , V_50 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static int F_52 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_50 = 0 ;
int V_133 ;
V_133 = F_53 ( V_2 -> V_4 . V_84 , F_42 , V_2 -> V_4 . V_134 ,
V_2 -> V_135 , V_2 ) ;
if ( V_133 )
return V_133 ;
F_12 ( V_2 -> V_4 . V_14 , L_6 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_124 , V_115 ) ;
( void ) F_1 ( V_2 , V_93 ) ;
if ( F_1 ( V_2 , V_93 ) & V_34 )
( void ) F_1 ( V_2 , V_67 ) ;
( void ) F_1 ( V_2 , V_90 ) ;
( void ) F_1 ( V_2 , V_53 ) ;
F_3 ( V_2 , V_132 , V_136 ) ;
F_28 ( & V_2 -> V_4 . V_49 , V_50 ) ;
V_2 -> V_4 . V_111 |= V_120 ;
F_46 ( & V_2 -> V_4 , V_2 -> V_4 . V_111 ) ;
F_29 ( & V_2 -> V_4 . V_49 , V_50 ) ;
V_2 -> V_54 = 0 ;
V_2 -> V_28 = V_32 | V_51 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_3 ( V_2 , V_137 , V_138 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_101 = V_102 ;
return 0 ;
}
static void F_54 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned long V_50 = 0 ;
F_12 ( V_2 -> V_4 . V_14 , L_7 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
V_2 -> V_28 = 0 ;
F_3 ( V_2 , V_30 , 0 ) ;
F_28 ( & V_2 -> V_4 . V_49 , V_50 ) ;
V_2 -> V_4 . V_111 &= ~ V_120 ;
F_46 ( & V_2 -> V_4 , V_2 -> V_4 . V_111 ) ;
F_29 ( & V_2 -> V_4 . V_49 , V_50 ) ;
F_3 ( V_2 , V_132 , F_1 ( V_2 , V_132 ) & ~ V_131 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_93 ) & V_34 )
( void ) F_1 ( V_2 , V_67 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
F_55 ( V_2 -> V_4 . V_84 , V_2 ) ;
}
static void F_56 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_57 ( V_140 , struct V_1 ,
V_127 ) ;
F_58 ( & V_2 -> V_141 , V_2 -> V_142 ) ;
if ( F_47 ( V_2 -> V_125 ) )
F_59 ( V_2 -> V_125 ,
V_2 -> V_126 != V_2 -> V_128 ) ;
}
static void
F_60 ( struct V_20 * V_4 , struct V_143 * V_144 ,
struct V_143 * V_145 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned char V_146 = 0 ;
unsigned long V_50 = 0 ;
unsigned int V_21 , V_147 ;
switch ( V_144 -> V_148 & V_149 ) {
case V_150 :
V_146 = V_151 ;
break;
case V_152 :
V_146 = V_153 ;
break;
case V_154 :
V_146 = V_155 ;
break;
default:
case V_156 :
V_146 = V_136 ;
break;
}
if ( V_144 -> V_148 & V_157 )
V_146 |= V_158 ;
if ( V_144 -> V_148 & V_159 )
V_146 |= V_160 ;
if ( ! ( V_144 -> V_148 & V_161 ) )
V_146 |= V_162 ;
if ( V_144 -> V_148 & V_163 )
V_146 |= V_164 ;
V_21 = F_61 ( V_4 , V_144 , V_145 , 0 , V_4 -> V_23 / 13 ) ;
V_147 = F_9 ( V_4 , V_21 ) ;
V_2 -> V_165 = ( V_166 * V_2 -> V_4 . V_44 ) / ( V_21 / 8 ) ;
V_2 -> V_142 = V_2 -> V_165 ;
F_49 ( & V_2 -> V_127 ) ;
V_2 -> V_167 = V_147 & 0xff ;
V_2 -> V_168 = V_147 >> 8 ;
V_2 -> V_169 = V_170 ;
V_2 -> V_171 = V_172 | V_173 |
V_9 ;
F_13 ( V_2 -> V_14 ) ;
F_28 ( & V_2 -> V_4 . V_49 , V_50 ) ;
F_62 ( V_4 , V_144 -> V_148 , V_21 ) ;
V_2 -> V_4 . V_33 = V_79 | V_174 | V_34 ;
if ( V_144 -> V_175 & V_176 )
V_2 -> V_4 . V_33 |= V_72 | V_73 ;
if ( V_144 -> V_175 & ( V_177 | V_178 ) )
V_2 -> V_4 . V_33 |= V_70 ;
V_2 -> V_4 . V_179 = 0 ;
if ( V_144 -> V_175 & V_180 )
V_2 -> V_4 . V_179 |= V_73 | V_72 ;
if ( V_144 -> V_175 & V_181 ) {
V_2 -> V_4 . V_179 |= V_70 ;
if ( V_144 -> V_175 & V_180 )
V_2 -> V_4 . V_179 |= V_79 ;
}
if ( ( V_144 -> V_148 & V_182 ) == 0 )
V_2 -> V_4 . V_179 |= V_34 ;
V_2 -> V_28 &= ~ V_29 ;
if ( F_63 ( & V_2 -> V_4 , V_144 -> V_148 ) )
V_2 -> V_28 |= V_29 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_3 ( V_2 , V_132 , V_146 ) ;
V_2 -> V_130 = V_146 ;
V_2 -> V_183 = 0 ;
F_3 ( V_2 , V_132 , V_184 ) ;
F_3 ( V_2 , V_185 , 0 ) ;
F_3 ( V_2 , V_186 , 0 ) ;
F_3 ( V_2 , V_132 , 0 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
V_2 -> V_188 = F_1 ( V_2 , V_189 ) & ~ V_190 ;
V_2 -> V_188 &= ~ V_191 ;
F_3 ( V_2 , V_189 , V_2 -> V_188 | V_190 ) ;
F_3 ( V_2 , V_132 , V_184 ) ;
V_2 -> V_112 = F_1 ( V_2 , V_124 ) & ~ V_192 ;
F_3 ( V_2 , V_124 , V_2 -> V_112 | V_192 ) ;
V_2 -> V_183 |= V_193 ;
V_2 -> V_171 &= ~ V_194 ;
V_2 -> V_171 &= ~ V_195 ;
V_2 -> V_171 |= V_196 | V_197 |
V_9 ;
F_3 ( V_2 , V_8 , V_2 -> V_171 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_198 , V_2 -> V_183 ) ;
F_3 ( V_2 , V_132 , V_184 ) ;
F_3 ( V_2 , V_124 , V_2 -> V_112 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_189 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_132 , V_184 ) ;
if ( V_2 -> V_199 & V_200 )
F_64 ( V_2 , V_2 -> V_169 ) ;
else
F_3 ( V_2 , V_201 , V_2 -> V_169 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_189 , V_2 -> V_188 | V_190 ) ;
F_3 ( V_2 , V_132 , 0 ) ;
F_3 ( V_2 , V_30 , 0 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_185 , V_2 -> V_167 ) ;
F_3 ( V_2 , V_186 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_132 , 0 ) ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_189 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_132 , V_146 ) ;
if ( ! F_8 ( V_4 , V_21 ) )
V_2 -> V_169 = V_202 ;
else
V_2 -> V_169 = V_203 ;
if ( V_2 -> V_199 & V_200 )
F_64 ( V_2 , V_2 -> V_169 ) ;
else
F_3 ( V_2 , V_201 , V_2 -> V_169 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_204 , V_144 -> V_205 [ V_206 ] ) ;
F_3 ( V_2 , V_207 , V_144 -> V_205 [ V_208 ] ) ;
F_3 ( V_2 , V_189 , V_2 -> V_188 | V_190 ) ;
F_3 ( V_2 , V_132 , V_184 ) ;
F_3 ( V_2 , V_124 , V_2 -> V_112 | V_192 ) ;
F_3 ( V_2 , V_209 , V_210 ) ;
if ( V_144 -> V_148 & V_211 && V_2 -> V_4 . V_50 & V_212 ) {
V_2 -> V_188 |= V_213 | V_214 ;
V_2 -> V_112 |= V_115 ;
} else {
V_2 -> V_188 &= ~ ( V_213 | V_214 ) ;
}
if ( V_2 -> V_4 . V_50 & V_215 ) {
V_2 -> V_188 &= V_216 ;
if ( V_144 -> V_175 & V_217 )
V_2 -> V_188 |= V_218 ;
if ( V_144 -> V_175 & V_219 )
V_2 -> V_188 |= V_220 ;
if ( V_144 -> V_175 & V_221 )
V_2 -> V_112 |= V_222 ;
else
V_2 -> V_112 &= ~ V_222 ;
}
F_3 ( V_2 , V_124 , V_2 -> V_112 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_189 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_132 , V_2 -> V_130 ) ;
F_46 ( & V_2 -> V_4 , V_2 -> V_4 . V_111 ) ;
F_29 ( & V_2 -> V_4 . V_49 , V_50 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_8 , V_2 -> V_4 . line ) ;
}
static int F_65 ( struct V_20 * V_4 , unsigned int V_38 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_7 ( V_2 , V_38 ) ;
return 0 ;
}
static void
F_66 ( struct V_20 * V_4 , unsigned int V_38 ,
unsigned int V_223 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned char V_188 ;
F_12 ( V_2 -> V_4 . V_14 , L_9 , V_2 -> V_4 . line ) ;
F_13 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
V_188 = F_1 ( V_2 , V_189 ) ;
F_3 ( V_2 , V_189 , V_188 | V_190 ) ;
F_3 ( V_2 , V_132 , 0 ) ;
F_3 ( V_2 , V_30 , ( V_38 != 0 ) ? V_224 : 0 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_189 , V_188 ) ;
F_3 ( V_2 , V_132 , 0 ) ;
if ( ! F_67 ( V_2 -> V_14 ) ) {
if ( ! V_38 )
F_68 ( V_2 -> V_14 ) ;
else
F_69 ( V_2 -> V_14 ) ;
}
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static void F_70 ( struct V_20 * V_4 )
{
F_12 ( V_4 -> V_14 , L_10 ) ;
}
static int F_71 ( struct V_20 * V_4 )
{
F_12 ( V_4 -> V_14 , L_11 ) ;
return 0 ;
}
static void F_72 ( struct V_20 * V_4 , int V_50 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_12 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . type = V_225 ;
V_2 -> V_4 . V_50 |= V_215 | V_212 ;
}
static int
F_73 ( struct V_20 * V_4 , struct V_226 * V_227 )
{
F_12 ( V_4 -> V_14 , L_13 ) ;
return - V_17 ;
}
static const char *
F_74 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_12 ( V_2 -> V_4 . V_14 , L_14 , V_2 -> V_4 . line ) ;
return V_2 -> V_135 ;
}
static inline void F_75 ( struct V_1 * V_2 )
{
unsigned int V_52 , V_228 = 10000 ;
do {
V_52 = F_1 ( V_2 , V_93 ) ;
if ( V_52 & V_70 )
V_2 -> V_83 = V_70 ;
if ( -- V_228 == 0 )
break;
F_76 ( 1 ) ;
} while ( ( V_52 & V_229 ) != V_229 );
if ( V_2 -> V_4 . V_50 & V_230 ) {
V_228 = 1000000 ;
for ( V_228 = 1000000 ; V_228 ; V_228 -- ) {
unsigned int V_231 = F_1 ( V_2 , V_53 ) ;
V_2 -> V_54 |= V_231 & V_232 ;
if ( V_231 & V_63 )
break;
F_76 ( 1 ) ;
}
}
}
static void F_77 ( struct V_20 * V_4 , unsigned char V_66 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_13 ( V_2 -> V_14 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_41 , V_66 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
}
static int F_78 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
unsigned int V_52 ;
F_13 ( V_2 -> V_14 ) ;
V_52 = F_1 ( V_2 , V_93 ) ;
if ( ! ( V_52 & V_34 ) ) {
V_52 = V_233 ;
goto V_234;
}
V_52 = F_1 ( V_2 , V_67 ) ;
V_234:
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
return V_52 ;
}
static void F_79 ( struct V_20 * V_4 , int V_66 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_41 , V_66 ) ;
}
static void
F_80 ( struct V_235 * V_236 , const char * V_237 ,
unsigned int V_39 )
{
struct V_1 * V_2 = V_238 [ V_236 -> V_82 ] ;
unsigned long V_50 ;
unsigned int V_28 ;
int V_239 = 1 ;
F_13 ( V_2 -> V_14 ) ;
F_81 ( V_50 ) ;
if ( V_2 -> V_4 . V_240 )
V_239 = 0 ;
else if ( V_241 )
V_239 = F_82 ( & V_2 -> V_4 . V_49 ) ;
else
F_24 ( & V_2 -> V_4 . V_49 ) ;
V_28 = F_1 ( V_2 , V_30 ) ;
F_3 ( V_2 , V_30 , 0 ) ;
F_83 ( & V_2 -> V_4 , V_237 , V_39 , F_79 ) ;
F_75 ( V_2 ) ;
F_3 ( V_2 , V_30 , V_28 ) ;
if ( V_2 -> V_54 )
F_31 ( V_2 ) ;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
if ( V_239 )
F_22 ( & V_2 -> V_4 . V_49 ) ;
F_84 ( V_50 ) ;
}
static int T_2
F_85 ( struct V_235 * V_236 , char * V_242 )
{
struct V_1 * V_2 ;
int V_21 = 115200 ;
int V_243 = 8 ;
int V_76 = 'n' ;
int V_244 = 'n' ;
if ( V_238 [ V_236 -> V_82 ] == NULL )
return - V_245 ;
V_2 = V_238 [ V_236 -> V_82 ] ;
if ( V_242 )
F_86 ( V_242 , & V_21 , & V_76 , & V_243 , & V_244 ) ;
return F_87 ( & V_2 -> V_4 , V_236 , V_21 , V_76 , V_243 , V_244 ) ;
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
V_2 -> V_247 = true ;
return 0 ;
}
static void F_91 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
V_2 -> V_247 = false ;
}
static int F_92 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
F_93 ( & V_248 , & V_2 -> V_4 ) ;
F_94 ( & V_2 -> V_127 ) ;
return 0 ;
}
static int F_95 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
F_96 ( & V_248 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
T_3 V_249 , V_250 ;
T_4 V_251 , V_252 , V_253 ;
V_249 = F_1 ( V_2 , V_254 ) ;
V_250 = V_249 >> V_255 ;
switch ( V_250 ) {
case 0 :
V_252 = ( V_249 & V_256 ) >>
V_257 ;
V_253 = ( V_249 & V_258 ) ;
break;
case 1 :
V_252 = ( V_249 & V_259 ) >>
V_260 ;
V_253 = ( V_249 & V_261 ) ;
break;
default:
F_98 ( V_2 -> V_14 ,
L_15 ,
V_2 -> V_135 ) ;
V_252 = 0xff ;
V_253 = 0xff ;
}
V_251 = F_99 ( V_252 , V_253 ) ;
switch ( V_251 ) {
case V_262 :
V_2 -> V_199 |= ( V_200 |
V_263 ) ;
break;
case V_264 :
V_2 -> V_199 |= ( V_200 |
V_263 ) ;
break;
case V_265 :
V_2 -> V_199 |= V_200 ;
break;
default:
break;
}
}
static struct V_12 * F_100 ( struct V_246 * V_14 )
{
struct V_12 * V_266 ;
V_266 = F_101 ( V_14 , sizeof( * V_266 ) , V_267 ) ;
if ( ! V_266 )
return NULL ;
F_102 ( V_14 -> V_268 , L_16 ,
& V_266 -> V_23 ) ;
return V_266 ;
}
static int F_103 ( struct V_269 * V_270 )
{
struct V_1 * V_2 ;
struct V_271 * V_272 , * V_84 ;
struct V_12 * V_266 = V_270 -> V_14 . V_15 ;
int V_87 ;
if ( V_270 -> V_14 . V_268 )
V_266 = F_100 ( & V_270 -> V_14 ) ;
V_272 = F_104 ( V_270 , V_273 , 0 ) ;
if ( ! V_272 ) {
F_105 ( & V_270 -> V_14 , L_17 ) ;
return - V_245 ;
}
V_84 = F_104 ( V_270 , V_274 , 0 ) ;
if ( ! V_84 ) {
F_105 ( & V_270 -> V_14 , L_18 ) ;
return - V_245 ;
}
if ( ! F_106 ( & V_270 -> V_14 , V_272 -> V_275 , F_107 ( V_272 ) ,
V_270 -> V_14 . V_276 -> V_135 ) ) {
F_105 ( & V_270 -> V_14 , L_19 ) ;
return - V_277 ;
}
if ( F_47 ( V_266 -> V_125 ) &&
V_266 -> V_278 ) {
V_87 = F_108 ( V_266 -> V_125 , L_20 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_109 ( V_266 -> V_125 ,
V_266 -> V_128 ) ;
if ( V_87 < 0 )
return V_87 ;
}
V_2 = F_101 ( & V_270 -> V_14 , sizeof( * V_2 ) , V_267 ) ;
if ( ! V_2 )
return - V_279 ;
if ( F_47 ( V_266 -> V_125 ) &&
V_266 -> V_278 ) {
V_2 -> V_125 = V_266 -> V_125 ;
V_2 -> V_128 = V_266 -> V_128 ;
} else
V_2 -> V_125 = - V_17 ;
V_2 -> V_126 = 0 ;
V_2 -> V_14 = & V_270 -> V_14 ;
V_2 -> V_4 . V_14 = & V_270 -> V_14 ;
V_2 -> V_4 . type = V_225 ;
V_2 -> V_4 . V_280 = V_281 ;
V_2 -> V_4 . V_84 = V_84 -> V_275 ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_44 = 64 ;
V_2 -> V_4 . V_282 = & V_283 ;
if ( V_270 -> V_14 . V_268 )
V_2 -> V_4 . line = F_110 ( V_270 -> V_14 . V_268 , L_21 ) ;
else
V_2 -> V_4 . line = V_270 -> V_284 ;
if ( V_2 -> V_4 . line < 0 ) {
F_105 ( & V_270 -> V_14 , L_22 ,
V_2 -> V_4 . line ) ;
V_87 = - V_245 ;
goto V_285;
}
V_2 -> V_286 = F_111 ( & V_270 -> V_14 ) ;
if ( F_112 ( V_2 -> V_286 ) ) {
F_98 ( & V_270 -> V_14 , L_23 ,
V_2 -> V_4 . line , F_113 ( V_2 -> V_286 ) ) ;
V_2 -> V_286 = NULL ;
}
sprintf ( V_2 -> V_135 , L_24 , V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_287 = V_272 -> V_275 ;
V_2 -> V_4 . V_6 = F_114 ( & V_270 -> V_14 , V_272 -> V_275 ,
F_107 ( V_272 ) ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_105 ( & V_270 -> V_14 , L_25 ) ;
V_87 = - V_279 ;
goto V_288;
}
V_2 -> V_4 . V_50 = V_266 -> V_50 ;
V_2 -> V_4 . V_23 = V_266 -> V_23 ;
if ( ! V_2 -> V_4 . V_23 ) {
V_2 -> V_4 . V_23 = V_289 ;
F_98 ( & V_270 -> V_14 , L_26
L_27 , V_289 ) ;
}
V_2 -> V_142 = V_290 ;
V_2 -> V_165 = V_290 ;
F_115 ( & V_2 -> V_141 ,
V_291 , V_2 -> V_142 ) ;
V_292 = F_116 ( V_2 -> V_135 ) ;
F_117 ( & V_2 -> V_127 , F_56 ) ;
F_118 ( V_270 , V_2 ) ;
F_119 ( & V_270 -> V_14 ) ;
if ( V_266 -> V_293 == 0 )
V_266 -> V_293 = - 1 ;
F_120 ( V_2 -> V_14 , true ) ;
F_121 ( & V_270 -> V_14 ) ;
F_122 ( & V_270 -> V_14 ,
V_266 -> V_293 ) ;
F_123 ( & V_270 -> V_14 ) ;
F_13 ( & V_270 -> V_14 ) ;
F_97 ( V_2 ) ;
V_294 [ V_2 -> V_4 . line ] = V_2 ;
F_88 ( V_2 ) ;
V_87 = F_124 ( & V_248 , & V_2 -> V_4 ) ;
if ( V_87 != 0 )
goto V_295;
F_14 ( V_2 -> V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
return 0 ;
V_295:
F_125 ( & V_270 -> V_14 ) ;
F_126 ( & V_270 -> V_14 ) ;
V_288:
V_285:
F_105 ( & V_270 -> V_14 , L_28 ,
V_270 -> V_284 , V_296 , V_87 ) ;
return V_87 ;
}
static int F_127 ( struct V_269 * V_14 )
{
struct V_1 * V_2 = F_128 ( V_14 ) ;
F_129 ( V_2 -> V_14 ) ;
F_126 ( V_2 -> V_14 ) ;
F_130 ( & V_248 , & V_2 -> V_4 ) ;
F_131 ( & V_2 -> V_141 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 , T_5 V_169 )
{
T_5 V_297 = 255 ;
F_3 ( V_2 , V_201 , V_169 ) ;
F_76 ( 2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_171 | V_11 |
V_10 ) ;
while ( V_174 != ( F_1 ( V_2 , V_93 ) &
( V_174 | V_34 ) ) ) {
V_297 -- ;
if ( ! V_297 ) {
F_132 ( V_2 -> V_14 , L_29 ,
F_1 ( V_2 , V_93 ) ) ;
break;
}
F_76 ( 1 ) ;
}
}
static void F_133 ( struct V_1 * V_2 )
{
if ( V_2 -> V_199 & V_200 )
F_64 ( V_2 , V_170 ) ;
else
F_3 ( V_2 , V_201 , V_170 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_189 , V_190 ) ;
F_3 ( V_2 , V_132 , 0x0 ) ;
F_3 ( V_2 , V_30 , 0x0 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_185 , V_2 -> V_167 ) ;
F_3 ( V_2 , V_186 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_132 , 0x0 ) ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_171 ) ;
F_3 ( V_2 , V_132 , V_184 ) ;
F_3 ( V_2 , V_124 , V_2 -> V_112 ) ;
F_3 ( V_2 , V_132 , V_187 ) ;
F_3 ( V_2 , V_198 , V_2 -> V_183 ) ;
F_3 ( V_2 , V_189 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_132 , V_2 -> V_130 ) ;
if ( V_2 -> V_199 & V_200 )
F_64 ( V_2 , V_2 -> V_169 ) ;
else
F_3 ( V_2 , V_201 , V_2 -> V_169 ) ;
}
static int F_134 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
if ( ! V_2 )
return - V_17 ;
if ( V_2 -> V_247 && ! V_298 &&
F_135 ( & V_2 -> V_4 ) )
return - V_277 ;
V_2 -> V_299 = F_6 ( V_2 ) ;
if ( F_67 ( V_14 ) ) {
if ( ! V_2 -> V_300 ) {
F_7 ( V_2 , true ) ;
V_2 -> V_300 = true ;
}
} else {
if ( V_2 -> V_300 ) {
F_7 ( V_2 , false ) ;
V_2 -> V_300 = false ;
}
}
V_2 -> V_142 = V_290 ;
F_49 ( & V_2 -> V_127 ) ;
return 0 ;
}
static int F_136 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_90 ( V_14 ) ;
int V_301 = F_6 ( V_2 ) ;
if ( V_301 < 0 ) {
F_12 ( V_14 , L_30 ,
V_301 ) ;
F_133 ( V_2 ) ;
} else if ( V_2 -> V_299 != V_301 ) {
F_133 ( V_2 ) ;
}
V_2 -> V_142 = V_2 -> V_165 ;
F_49 ( & V_2 -> V_127 ) ;
return 0 ;
}
static int T_2 F_137 ( void )
{
int V_87 ;
V_87 = F_138 ( & V_248 ) ;
if ( V_87 != 0 )
return V_87 ;
V_87 = F_139 ( & V_302 ) ;
if ( V_87 != 0 )
F_140 ( & V_248 ) ;
return V_87 ;
}
static void T_6 F_141 ( void )
{
F_142 ( & V_302 ) ;
F_140 ( & V_248 ) ;
}
