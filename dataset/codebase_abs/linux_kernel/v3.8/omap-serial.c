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
static void F_28 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_49 ;
F_14 ( V_2 -> V_14 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_26 &= ~ ( V_30 | V_50 ) ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_30 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static void F_31 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_49 ;
F_14 ( V_2 -> V_14 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_26 |= V_30 | V_50 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_30 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static unsigned int F_32 ( struct V_1 * V_2 )
{
unsigned int V_51 ;
V_51 = F_1 ( V_2 , V_52 ) ;
V_51 |= V_2 -> V_53 ;
V_2 -> V_53 = 0 ;
if ( ( V_51 & V_54 ) == 0 )
return V_51 ;
if ( V_51 & V_54 && V_2 -> V_26 & V_27 &&
V_2 -> V_4 . V_36 != NULL ) {
if ( V_51 & V_55 )
V_2 -> V_4 . V_41 . V_56 ++ ;
if ( V_51 & V_57 )
V_2 -> V_4 . V_41 . V_58 ++ ;
if ( V_51 & V_59 )
F_33
( & V_2 -> V_4 , V_51 & V_60 ) ;
if ( V_51 & V_61 )
F_34
( & V_2 -> V_4 , V_51 & V_62 ) ;
F_35 ( & V_2 -> V_4 . V_36 -> V_4 . V_63 ) ;
}
return V_51 ;
}
static void F_36 ( struct V_1 * V_2 , unsigned int V_33 )
{
unsigned int V_64 ;
unsigned char V_65 = 0 ;
if ( F_37 ( V_33 & V_32 ) )
V_65 = F_1 ( V_2 , V_66 ) ;
V_2 -> V_4 . V_41 . V_67 ++ ;
V_64 = V_68 ;
if ( V_33 & V_69 ) {
V_64 = V_70 ;
V_33 &= ~ ( V_71 | V_72 ) ;
V_2 -> V_4 . V_41 . V_73 ++ ;
if ( F_38 ( & V_2 -> V_4 ) )
return;
}
if ( V_33 & V_72 ) {
V_64 = V_74 ;
V_2 -> V_4 . V_41 . V_75 ++ ;
}
if ( V_33 & V_71 ) {
V_64 = V_76 ;
V_2 -> V_4 . V_41 . V_77 ++ ;
}
if ( V_33 & V_78 )
V_2 -> V_4 . V_41 . V_79 ++ ;
#ifdef F_39
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_80 -> V_81 ) {
V_33 |= V_2 -> V_82 ;
}
#endif
F_40 ( & V_2 -> V_4 , V_33 , V_78 , 0 , V_64 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_33 )
{
unsigned char V_65 = 0 ;
unsigned int V_64 ;
if ( ! ( V_33 & V_32 ) )
return;
V_65 = F_1 ( V_2 , V_66 ) ;
V_64 = V_68 ;
V_2 -> V_4 . V_41 . V_67 ++ ;
if ( F_42 ( & V_2 -> V_4 , V_65 ) )
return;
F_40 ( & V_2 -> V_4 , V_33 , V_78 , V_65 , V_64 ) ;
}
static T_1 F_43 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_85 * V_86 = V_2 -> V_4 . V_36 -> V_4 . V_86 ;
unsigned int V_87 , V_33 ;
unsigned int type ;
T_1 V_88 = V_89 ;
int V_90 = 256 ;
F_25 ( & V_2 -> V_4 . V_48 ) ;
F_14 ( V_2 -> V_14 ) ;
do {
V_87 = F_1 ( V_2 , V_91 ) ;
if ( V_87 & V_92 )
break;
V_88 = V_93 ;
V_33 = F_1 ( V_2 , V_94 ) ;
type = V_87 & 0x3e ;
switch ( type ) {
case V_95 :
F_32 ( V_2 ) ;
break;
case V_96 :
F_19 ( V_2 , V_33 ) ;
break;
case V_97 :
case V_98 :
F_41 ( V_2 , V_33 ) ;
break;
case V_99 :
F_36 ( V_2 , V_33 ) ;
break;
case V_100 :
break;
case V_101 :
default:
break;
}
} while ( ! ( V_87 & V_92 ) && V_90 -- );
F_23 ( & V_2 -> V_4 . V_48 ) ;
F_44 ( V_86 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
V_2 -> V_102 = V_103 ;
return V_88 ;
}
static unsigned int F_45 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_49 = 0 ;
unsigned int V_88 = 0 ;
F_14 ( V_2 -> V_14 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_2 , V_2 -> V_4 . line ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_88 = F_1 ( V_2 , V_94 ) & V_104 ? V_105 : 0 ;
F_30 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
return V_88 ;
}
static unsigned int F_46 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned int V_51 ;
unsigned int V_88 = 0 ;
F_14 ( V_2 -> V_14 ) ;
V_51 = F_32 ( V_2 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_3 , V_2 -> V_4 . line ) ;
if ( V_51 & V_60 )
V_88 |= V_106 ;
if ( V_51 & V_107 )
V_88 |= V_108 ;
if ( V_51 & V_109 )
V_88 |= V_110 ;
if ( V_51 & V_62 )
V_88 |= V_111 ;
return V_88 ;
}
static void F_47 ( struct V_21 * V_4 , unsigned int V_112 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_113 = 0 , V_114 ;
F_13 ( V_2 -> V_4 . V_14 , L_4 , V_2 -> V_4 . line ) ;
if ( V_112 & V_115 )
V_113 |= V_116 ;
if ( V_112 & V_117 )
V_113 |= V_118 ;
if ( V_112 & V_119 )
V_113 |= V_120 ;
if ( V_112 & V_121 )
V_113 |= V_122 ;
if ( V_112 & V_123 )
V_113 |= V_124 ;
F_14 ( V_2 -> V_14 ) ;
V_114 = F_1 ( V_2 , V_125 ) ;
V_114 &= ~ ( V_124 | V_122 | V_120 |
V_118 | V_116 ) ;
V_2 -> V_113 = V_114 | V_113 ;
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
if ( F_48 ( V_2 -> V_126 ) &&
! ! ( V_112 & V_117 ) != V_2 -> V_127 ) {
V_2 -> V_127 = ! V_2 -> V_127 ;
if ( F_49 ( V_2 -> V_126 ) )
F_50 ( & V_2 -> V_128 ) ;
else
F_51 ( V_2 -> V_126 ,
V_2 -> V_127 != V_2 -> V_129 ) ;
}
}
static void F_52 ( struct V_21 * V_4 , int V_130 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_49 = 0 ;
F_13 ( V_2 -> V_4 . V_14 , L_5 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
if ( V_130 == - 1 )
V_2 -> V_131 |= V_132 ;
else
V_2 -> V_131 &= ~ V_132 ;
F_3 ( V_2 , V_133 , V_2 -> V_131 ) ;
F_30 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static int F_53 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_49 = 0 ;
int V_134 ;
V_134 = F_54 ( V_2 -> V_4 . V_83 , F_43 , V_2 -> V_4 . V_135 ,
V_2 -> V_136 , V_2 ) ;
if ( V_134 )
return V_134 ;
F_13 ( V_2 -> V_4 . V_14 , L_6 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_125 , V_116 ) ;
( void ) F_1 ( V_2 , V_94 ) ;
if ( F_1 ( V_2 , V_94 ) & V_32 )
( void ) F_1 ( V_2 , V_66 ) ;
( void ) F_1 ( V_2 , V_91 ) ;
( void ) F_1 ( V_2 , V_52 ) ;
F_3 ( V_2 , V_133 , V_137 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_4 . V_112 |= V_121 ;
F_47 ( & V_2 -> V_4 , V_2 -> V_4 . V_112 ) ;
F_30 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_53 = 0 ;
V_2 -> V_26 = V_30 | V_50 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
V_2 -> V_102 = V_103 ;
return 0 ;
}
static void F_55 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned long V_49 = 0 ;
F_13 ( V_2 -> V_4 . V_14 , L_7 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
V_2 -> V_26 = 0 ;
F_3 ( V_2 , V_28 , 0 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
V_2 -> V_4 . V_112 &= ~ V_121 ;
F_47 ( & V_2 -> V_4 , V_2 -> V_4 . V_112 ) ;
F_30 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_3 ( V_2 , V_133 , F_1 ( V_2 , V_133 ) & ~ V_132 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_94 ) & V_32 )
( void ) F_1 ( V_2 , V_66 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
F_56 ( V_2 -> V_4 . V_83 , V_2 ) ;
}
static void F_57 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_58 ( V_141 , struct V_1 ,
V_128 ) ;
F_59 ( & V_2 -> V_142 , V_2 -> V_143 ) ;
if ( F_48 ( V_2 -> V_126 ) )
F_60 ( V_2 -> V_126 ,
V_2 -> V_127 != V_2 -> V_129 ) ;
}
static void
F_61 ( struct V_21 * V_4 , struct V_144 * V_145 ,
struct V_144 * V_146 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_147 = 0 ;
unsigned long V_49 = 0 ;
unsigned int V_22 , V_148 ;
switch ( V_145 -> V_149 & V_150 ) {
case V_151 :
V_147 = V_152 ;
break;
case V_153 :
V_147 = V_154 ;
break;
case V_155 :
V_147 = V_156 ;
break;
default:
case V_157 :
V_147 = V_137 ;
break;
}
if ( V_145 -> V_149 & V_158 )
V_147 |= V_159 ;
if ( V_145 -> V_149 & V_160 )
V_147 |= V_161 ;
if ( ! ( V_145 -> V_149 & V_162 ) )
V_147 |= V_163 ;
V_22 = F_62 ( V_4 , V_145 , V_146 , 0 , V_4 -> V_25 / 13 ) ;
V_148 = F_10 ( V_4 , V_22 ) ;
V_2 -> V_164 = ( V_165 * V_2 -> V_4 . V_43 ) / ( V_22 / 8 ) ;
V_2 -> V_143 = V_2 -> V_164 ;
F_50 ( & V_2 -> V_128 ) ;
V_2 -> V_166 = V_148 & 0xff ;
V_2 -> V_167 = V_148 >> 8 ;
V_2 -> V_168 = V_169 ;
V_2 -> V_170 = V_171 | V_172 |
V_9 ;
F_14 ( V_2 -> V_14 ) ;
F_29 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_63 ( V_4 , V_145 -> V_149 , V_22 ) ;
V_2 -> V_4 . V_31 = V_78 | V_38 | V_32 ;
if ( V_145 -> V_173 & V_174 )
V_2 -> V_4 . V_31 |= V_71 | V_72 ;
if ( V_145 -> V_173 & ( V_175 | V_176 ) )
V_2 -> V_4 . V_31 |= V_69 ;
V_2 -> V_4 . V_177 = 0 ;
if ( V_145 -> V_173 & V_178 )
V_2 -> V_4 . V_177 |= V_72 | V_71 ;
if ( V_145 -> V_173 & V_179 ) {
V_2 -> V_4 . V_177 |= V_69 ;
if ( V_145 -> V_173 & V_178 )
V_2 -> V_4 . V_177 |= V_78 ;
}
if ( ( V_145 -> V_149 & V_180 ) == 0 )
V_2 -> V_4 . V_177 |= V_32 ;
V_2 -> V_26 &= ~ V_27 ;
if ( F_64 ( & V_2 -> V_4 , V_145 -> V_149 ) )
V_2 -> V_26 |= V_27 ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_133 , V_147 ) ;
V_2 -> V_131 = V_147 ;
V_2 -> V_181 = V_182 ;
F_3 ( V_2 , V_133 , V_183 ) ;
F_3 ( V_2 , V_184 , 0 ) ;
F_3 ( V_2 , V_185 , 0 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
V_2 -> V_187 = F_1 ( V_2 , V_188 ) & ~ V_189 ;
V_2 -> V_187 &= ~ V_190 ;
F_3 ( V_2 , V_188 , V_2 -> V_187 | V_189 ) ;
F_3 ( V_2 , V_133 , V_183 ) ;
V_2 -> V_113 = F_1 ( V_2 , V_125 ) & ~ V_191 ;
F_3 ( V_2 , V_125 , V_2 -> V_113 | V_191 ) ;
V_2 -> V_181 |= V_192 ;
V_2 -> V_170 &= ~ V_193 ;
V_2 -> V_170 &= ~ V_194 ;
V_2 -> V_170 |= V_195 | V_196 |
V_9 ;
F_3 ( V_2 , V_8 , V_2 -> V_170 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_197 , V_2 -> V_181 ) ;
F_3 ( V_2 , V_133 , V_183 ) ;
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_133 , V_183 ) ;
if ( V_2 -> V_198 & V_199 )
F_65 ( V_2 , V_2 -> V_168 ) ;
else
F_3 ( V_2 , V_200 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 | V_189 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_28 , 0 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_184 , V_2 -> V_166 ) ;
F_3 ( V_2 , V_185 , V_2 -> V_167 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_133 , V_147 ) ;
if ( V_22 > 230400 && V_22 != 3000000 )
V_2 -> V_168 = V_201 ;
else
V_2 -> V_168 = V_202 ;
if ( V_2 -> V_198 & V_199 )
F_65 ( V_2 , V_2 -> V_168 ) ;
else
F_3 ( V_2 , V_200 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_203 , V_145 -> V_204 [ V_205 ] ) ;
F_3 ( V_2 , V_206 , V_145 -> V_204 [ V_207 ] ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 | V_189 ) ;
F_3 ( V_2 , V_133 , V_183 ) ;
F_3 ( V_2 , V_125 , V_2 -> V_113 | V_191 ) ;
F_3 ( V_2 , V_208 , V_209 ) ;
if ( V_145 -> V_149 & V_210 && V_2 -> V_4 . V_49 & V_211 ) {
V_2 -> V_187 |= V_212 | V_213 ;
V_2 -> V_113 |= V_116 ;
} else {
V_2 -> V_187 &= ~ ( V_212 | V_213 ) ;
}
if ( V_2 -> V_4 . V_49 & V_214 ) {
V_2 -> V_187 &= V_215 ;
if ( V_145 -> V_173 & V_216 )
V_2 -> V_187 |= V_217 ;
if ( V_145 -> V_173 & V_218 )
V_2 -> V_187 |= V_219 ;
if ( V_145 -> V_173 & V_220 )
V_2 -> V_113 |= V_221 ;
else
V_2 -> V_113 &= ~ V_221 ;
}
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_133 , V_2 -> V_131 ) ;
F_47 ( & V_2 -> V_4 , V_2 -> V_4 . V_112 ) ;
F_30 ( & V_2 -> V_4 . V_48 , V_49 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_8 , V_2 -> V_4 . line ) ;
}
static int F_66 ( struct V_21 * V_4 , unsigned int V_36 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_9 ( V_2 , V_36 ) ;
return 0 ;
}
static void
F_67 ( struct V_21 * V_4 , unsigned int V_36 ,
unsigned int V_222 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_187 ;
F_13 ( V_2 -> V_4 . V_14 , L_9 , V_2 -> V_4 . line ) ;
F_14 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
V_187 = F_1 ( V_2 , V_188 ) ;
F_3 ( V_2 , V_188 , V_187 | V_189 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_28 , ( V_36 != 0 ) ? V_223 : 0 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_188 , V_187 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
if ( ! F_68 ( V_2 -> V_14 ) ) {
if ( ! V_36 )
F_69 ( V_2 -> V_14 ) ;
else
F_70 ( V_2 -> V_14 ) ;
}
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static void F_71 ( struct V_21 * V_4 )
{
F_13 ( V_4 -> V_14 , L_10 ) ;
}
static int F_72 ( struct V_21 * V_4 )
{
F_13 ( V_4 -> V_14 , L_11 ) ;
return 0 ;
}
static void F_73 ( struct V_21 * V_4 , int V_49 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_12 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . type = V_224 ;
V_2 -> V_4 . V_49 |= V_214 | V_211 ;
}
static int
F_74 ( struct V_21 * V_4 , struct V_225 * V_226 )
{
F_13 ( V_4 -> V_14 , L_13 ) ;
return - V_227 ;
}
static const char *
F_75 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_13 ( V_2 -> V_4 . V_14 , L_14 , V_2 -> V_4 . line ) ;
return V_2 -> V_136 ;
}
static inline void F_76 ( struct V_1 * V_2 )
{
unsigned int V_51 , V_228 = 10000 ;
do {
V_51 = F_1 ( V_2 , V_94 ) ;
if ( V_51 & V_69 )
V_2 -> V_82 = V_69 ;
if ( -- V_228 == 0 )
break;
F_77 ( 1 ) ;
} while ( ( V_51 & V_229 ) != V_229 );
if ( V_2 -> V_4 . V_49 & V_230 ) {
V_228 = 1000000 ;
for ( V_228 = 1000000 ; V_228 ; V_228 -- ) {
unsigned int V_231 = F_1 ( V_2 , V_52 ) ;
V_2 -> V_53 |= V_231 & V_232 ;
if ( V_231 & V_62 )
break;
F_77 ( 1 ) ;
}
}
}
static void F_78 ( struct V_21 * V_4 , unsigned char V_65 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_14 ( V_2 -> V_14 ) ;
F_76 ( V_2 ) ;
F_3 ( V_2 , V_40 , V_65 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
}
static int F_79 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned int V_51 ;
F_14 ( V_2 -> V_14 ) ;
V_51 = F_1 ( V_2 , V_94 ) ;
if ( ! ( V_51 & V_32 ) ) {
V_51 = V_233 ;
goto V_234;
}
V_51 = F_1 ( V_2 , V_66 ) ;
V_234:
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
return V_51 ;
}
static void F_80 ( struct V_21 * V_4 , int V_65 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
F_76 ( V_2 ) ;
F_3 ( V_2 , V_40 , V_65 ) ;
}
static void
F_81 ( struct V_235 * V_236 , const char * V_237 ,
unsigned int V_37 )
{
struct V_1 * V_2 = V_238 [ V_236 -> V_81 ] ;
unsigned long V_49 ;
unsigned int V_26 ;
int V_239 = 1 ;
F_14 ( V_2 -> V_14 ) ;
F_82 ( V_49 ) ;
if ( V_2 -> V_4 . V_240 )
V_239 = 0 ;
else if ( V_241 )
V_239 = F_83 ( & V_2 -> V_4 . V_48 ) ;
else
F_25 ( & V_2 -> V_4 . V_48 ) ;
V_26 = F_1 ( V_2 , V_28 ) ;
F_3 ( V_2 , V_28 , 0 ) ;
F_84 ( & V_2 -> V_4 , V_237 , V_37 , F_80 ) ;
F_76 ( V_2 ) ;
F_3 ( V_2 , V_28 , V_26 ) ;
if ( V_2 -> V_53 )
F_32 ( V_2 ) ;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
if ( V_239 )
F_23 ( & V_2 -> V_4 . V_48 ) ;
F_85 ( V_49 ) ;
}
static int T_2
F_86 ( struct V_235 * V_236 , char * V_242 )
{
struct V_1 * V_2 ;
int V_22 = 115200 ;
int V_243 = 8 ;
int V_75 = 'n' ;
int V_244 = 'n' ;
if ( V_238 [ V_236 -> V_81 ] == NULL )
return - V_245 ;
V_2 = V_238 [ V_236 -> V_81 ] ;
if ( V_242 )
F_87 ( V_242 , & V_22 , & V_75 , & V_243 , & V_244 ) ;
return F_88 ( & V_2 -> V_4 , V_236 , V_22 , V_75 , V_243 , V_244 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
V_238 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_89 ( struct V_1 * V_2 )
{}
static int F_90 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_91 ( V_14 ) ;
F_92 ( & V_247 , & V_2 -> V_4 ) ;
F_93 ( & V_2 -> V_128 ) ;
return 0 ;
}
static int F_94 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_91 ( V_14 ) ;
F_95 ( & V_247 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
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
F_97 ( V_2 -> V_14 ,
L_15 ,
V_2 -> V_136 ) ;
V_251 = 0xff ;
V_252 = 0xff ;
}
V_250 = F_98 ( V_251 , V_252 ) ;
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
static struct V_12 * F_99 ( struct V_246 * V_14 )
{
struct V_12 * V_265 ;
V_265 = F_100 ( V_14 , sizeof( * V_265 ) , V_266 ) ;
if ( ! V_265 )
return NULL ;
F_101 ( V_14 -> V_267 , L_16 ,
& V_265 -> V_25 ) ;
return V_265 ;
}
static int F_102 ( struct V_268 * V_269 )
{
struct V_1 * V_2 ;
struct V_270 * V_271 , * V_83 ;
struct V_12 * V_265 = V_269 -> V_14 . V_15 ;
int V_88 ;
if ( V_269 -> V_14 . V_267 )
V_265 = F_99 ( & V_269 -> V_14 ) ;
V_271 = F_103 ( V_269 , V_272 , 0 ) ;
if ( ! V_271 ) {
F_104 ( & V_269 -> V_14 , L_17 ) ;
return - V_245 ;
}
V_83 = F_103 ( V_269 , V_273 , 0 ) ;
if ( ! V_83 ) {
F_104 ( & V_269 -> V_14 , L_18 ) ;
return - V_245 ;
}
if ( ! F_105 ( & V_269 -> V_14 , V_271 -> V_274 , F_106 ( V_271 ) ,
V_269 -> V_14 . V_275 -> V_136 ) ) {
F_104 ( & V_269 -> V_14 , L_19 ) ;
return - V_276 ;
}
if ( F_48 ( V_265 -> V_126 ) &&
V_265 -> V_277 ) {
V_88 = F_107 ( V_265 -> V_126 , L_20 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = F_108 ( V_265 -> V_126 ,
V_265 -> V_129 ) ;
if ( V_88 < 0 )
return V_88 ;
}
V_2 = F_100 ( & V_269 -> V_14 , sizeof( * V_2 ) , V_266 ) ;
if ( ! V_2 )
return - V_278 ;
if ( F_48 ( V_265 -> V_126 ) &&
V_265 -> V_277 ) {
V_2 -> V_126 = V_265 -> V_126 ;
V_2 -> V_129 = V_265 -> V_129 ;
} else
V_2 -> V_126 = - V_227 ;
V_2 -> V_127 = 0 ;
V_2 -> V_14 = & V_269 -> V_14 ;
V_2 -> V_4 . V_14 = & V_269 -> V_14 ;
V_2 -> V_4 . type = V_224 ;
V_2 -> V_4 . V_279 = V_280 ;
V_2 -> V_4 . V_83 = V_83 -> V_274 ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_43 = 64 ;
V_2 -> V_4 . V_281 = & V_282 ;
if ( V_269 -> V_14 . V_267 )
V_2 -> V_4 . line = F_109 ( V_269 -> V_14 . V_267 , L_21 ) ;
else
V_2 -> V_4 . line = V_269 -> V_283 ;
if ( V_2 -> V_4 . line < 0 ) {
F_104 ( & V_269 -> V_14 , L_22 ,
V_2 -> V_4 . line ) ;
V_88 = - V_245 ;
goto V_284;
}
V_2 -> V_285 = F_110 ( & V_269 -> V_14 ) ;
if ( F_111 ( V_2 -> V_285 ) ) {
F_97 ( & V_269 -> V_14 , L_23 ,
V_2 -> V_4 . line , F_112 ( V_2 -> V_285 ) ) ;
V_2 -> V_285 = NULL ;
}
sprintf ( V_2 -> V_136 , L_24 , V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_286 = V_271 -> V_274 ;
V_2 -> V_4 . V_6 = F_113 ( & V_269 -> V_14 , V_271 -> V_274 ,
F_106 ( V_271 ) ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_104 ( & V_269 -> V_14 , L_25 ) ;
V_88 = - V_278 ;
goto V_287;
}
V_2 -> V_4 . V_49 = V_265 -> V_49 ;
V_2 -> V_4 . V_25 = V_265 -> V_25 ;
if ( ! V_2 -> V_4 . V_25 ) {
V_2 -> V_4 . V_25 = V_288 ;
F_97 ( & V_269 -> V_14 , L_26
L_27 , V_288 ) ;
}
V_2 -> V_143 = V_289 ;
V_2 -> V_164 = V_289 ;
F_114 ( & V_2 -> V_142 ,
V_290 , V_2 -> V_143 ) ;
V_291 = F_115 ( V_2 -> V_136 ) ;
F_116 ( & V_2 -> V_128 , F_57 ) ;
F_117 ( V_269 , V_2 ) ;
F_118 ( & V_269 -> V_14 ) ;
F_119 ( & V_269 -> V_14 ) ;
F_120 ( & V_269 -> V_14 ,
V_265 -> V_292 ) ;
F_121 ( & V_269 -> V_14 ) ;
F_14 ( & V_269 -> V_14 ) ;
F_96 ( V_2 ) ;
V_293 [ V_2 -> V_4 . line ] = V_2 ;
F_89 ( V_2 ) ;
V_88 = F_122 ( & V_247 , & V_2 -> V_4 ) ;
if ( V_88 != 0 )
goto V_294;
F_15 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_14 ) ;
return 0 ;
V_294:
F_123 ( & V_269 -> V_14 ) ;
F_124 ( & V_269 -> V_14 ) ;
V_287:
V_284:
F_104 ( & V_269 -> V_14 , L_28 ,
V_269 -> V_283 , V_295 , V_88 ) ;
return V_88 ;
}
static int F_125 ( struct V_268 * V_14 )
{
struct V_1 * V_2 = F_126 ( V_14 ) ;
F_127 ( V_2 -> V_14 ) ;
F_124 ( V_2 -> V_14 ) ;
F_128 ( & V_247 , & V_2 -> V_4 ) ;
F_129 ( & V_2 -> V_142 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , T_5 V_168 )
{
T_5 V_296 = 255 ;
F_3 ( V_2 , V_200 , V_168 ) ;
F_77 ( 2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_170 | V_11 |
V_10 ) ;
while ( V_38 != ( F_1 ( V_2 , V_94 ) &
( V_38 | V_32 ) ) ) {
V_296 -- ;
if ( ! V_296 ) {
F_130 ( V_2 -> V_14 , L_29 ,
F_1 ( V_2 , V_94 ) ) ;
break;
}
F_77 ( 1 ) ;
}
}
static void F_131 ( struct V_1 * V_2 )
{
if ( V_2 -> V_198 & V_199 )
F_65 ( V_2 , V_169 ) ;
else
F_3 ( V_2 , V_200 , V_169 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_188 , V_189 ) ;
F_3 ( V_2 , V_133 , 0x0 ) ;
F_3 ( V_2 , V_28 , 0x0 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_184 , V_2 -> V_166 ) ;
F_3 ( V_2 , V_185 , V_2 -> V_167 ) ;
F_3 ( V_2 , V_133 , 0x0 ) ;
F_3 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_170 ) ;
F_3 ( V_2 , V_133 , V_183 ) ;
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_3 ( V_2 , V_133 , V_186 ) ;
F_3 ( V_2 , V_197 , V_2 -> V_181 ) ;
F_3 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_133 , V_2 -> V_131 ) ;
if ( V_2 -> V_198 & V_199 )
F_65 ( V_2 , V_2 -> V_168 ) ;
else
F_3 ( V_2 , V_200 , V_2 -> V_168 ) ;
}
static int F_132 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_91 ( V_14 ) ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( ! V_2 )
return - V_227 ;
if ( ! V_13 )
return 0 ;
V_2 -> V_297 = F_6 ( V_2 ) ;
if ( F_68 ( V_14 ) ) {
if ( ! V_2 -> V_298 ) {
F_9 ( V_2 , true ) ;
V_2 -> V_298 = true ;
}
} else {
if ( V_2 -> V_298 ) {
F_9 ( V_2 , false ) ;
V_2 -> V_298 = false ;
}
}
V_2 -> V_143 = V_289 ;
F_50 ( & V_2 -> V_128 ) ;
return 0 ;
}
static int F_133 ( struct V_246 * V_14 )
{
struct V_1 * V_2 = F_91 ( V_14 ) ;
int V_299 = F_6 ( V_2 ) ;
if ( V_299 < 0 ) {
F_104 ( V_14 , L_30 ,
V_299 ) ;
F_131 ( V_2 ) ;
} else if ( V_2 -> V_297 != V_299 ) {
F_131 ( V_2 ) ;
}
V_2 -> V_143 = V_2 -> V_164 ;
F_50 ( & V_2 -> V_128 ) ;
return 0 ;
}
static int T_2 F_134 ( void )
{
int V_88 ;
V_88 = F_135 ( & V_247 ) ;
if ( V_88 != 0 )
return V_88 ;
V_88 = F_136 ( & V_300 ) ;
if ( V_88 != 0 )
F_137 ( & V_247 ) ;
return V_88 ;
}
static void T_6 F_138 ( void )
{
F_139 ( & V_300 ) ;
F_137 ( & V_247 ) ;
}
