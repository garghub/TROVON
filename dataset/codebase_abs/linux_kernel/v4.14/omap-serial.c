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
struct V_12 * V_13 = F_7 ( V_2 -> V_14 ) ;
if ( ! V_13 || ! V_13 -> V_15 )
return - V_16 ;
return V_13 -> V_15 ( V_2 -> V_14 ) ;
}
static void F_8 ( struct V_1 * V_2 , bool V_17 )
{
struct V_12 * V_13 = F_7 ( V_2 -> V_14 ) ;
if ( ! V_13 || ! V_13 -> V_18 )
return;
V_13 -> V_18 ( V_2 -> V_14 , V_17 ) ;
}
static inline int F_9 ( struct V_19 * V_4 ,
unsigned int V_20 , unsigned int V_21 )
{
unsigned int V_22 = V_4 -> V_23 / ( V_21 * V_20 ) ;
int V_24 ;
if ( V_22 == 0 )
V_22 = 1 ;
V_24 = V_20 - ( V_4 -> V_23 / ( V_21 * V_22 ) ) ;
if ( V_24 < 0 )
V_24 = - V_24 ;
return V_24 ;
}
static bool
F_10 ( struct V_19 * V_4 , unsigned int V_20 )
{
int V_25 = F_9 ( V_4 , V_20 , 13 ) ;
int V_26 = F_9 ( V_4 , V_20 , 16 ) ;
return ( V_25 >= V_26 ) ;
}
static unsigned int
F_11 ( struct V_19 * V_4 , unsigned int V_20 )
{
unsigned int V_21 ;
if ( ! F_10 ( V_4 , V_20 ) )
V_21 = 13 ;
else
V_21 = 16 ;
return V_4 -> V_23 / ( V_21 * V_20 ) ;
}
static void F_12 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_1 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_27 |= V_28 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_18 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
int V_30 ;
F_15 ( V_2 -> V_14 ) ;
if ( V_4 -> V_31 . V_32 & V_33 ) {
if ( V_2 -> V_34 & V_35 ) {
V_2 -> V_34 &= ~ V_35 ;
F_3 ( V_2 , V_36 , V_2 -> V_34 ) ;
V_30 = ( V_4 -> V_31 . V_32 & V_37 ) ?
1 : 0 ;
if ( F_19 ( V_2 -> V_38 ) != V_30 ) {
if ( V_4 -> V_31 . V_39 > 0 )
F_20 (
V_4 -> V_31 . V_39 ) ;
F_21 ( V_2 -> V_38 , V_30 ) ;
}
} else {
V_2 -> V_34 |= V_35 ;
F_3 ( V_2 , V_36 , V_2 -> V_34 ) ;
return;
}
}
if ( V_2 -> V_27 & V_40 ) {
V_2 -> V_27 &= ~ V_40 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
}
if ( ( V_4 -> V_31 . V_32 & V_33 ) &&
! ( V_4 -> V_31 . V_32 & V_41 ) ) {
F_3 ( V_2 , V_8 , V_2 -> V_42 | V_10 ) ;
V_2 -> V_27 |= V_43 | V_44 ;
V_2 -> V_4 . V_45 |= V_46 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
}
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_22 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_27 &= ~ ( V_43 | V_44 ) ;
V_2 -> V_4 . V_45 &= ~ V_46 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_47 )
{
struct V_48 * V_49 = & V_2 -> V_4 . V_50 -> V_49 ;
int V_51 ;
if ( V_2 -> V_4 . V_52 ) {
F_3 ( V_2 , V_53 , V_2 -> V_4 . V_52 ) ;
V_2 -> V_4 . V_54 . V_55 ++ ;
V_2 -> V_4 . V_52 = 0 ;
return;
}
if ( F_24 ( V_49 ) || F_25 ( & V_2 -> V_4 ) ) {
F_18 ( & V_2 -> V_4 ) ;
return;
}
V_51 = V_2 -> V_4 . V_56 / 4 ;
do {
F_3 ( V_2 , V_53 , V_49 -> V_57 [ V_49 -> V_58 ] ) ;
V_49 -> V_58 = ( V_49 -> V_58 + 1 ) & ( V_59 - 1 ) ;
V_2 -> V_4 . V_54 . V_55 ++ ;
if ( F_24 ( V_49 ) )
break;
} while ( -- V_51 > 0 );
if ( F_26 ( V_49 ) < V_60 )
F_27 ( & V_2 -> V_4 ) ;
if ( F_24 ( V_49 ) )
F_18 ( & V_2 -> V_4 ) ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_27 & V_40 ) ) {
V_2 -> V_27 |= V_40 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
}
}
static void F_29 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
int V_30 ;
F_15 ( V_2 -> V_14 ) ;
if ( V_4 -> V_31 . V_32 & V_33 ) {
V_2 -> V_34 &= ~ V_35 ;
F_3 ( V_2 , V_36 , V_2 -> V_34 ) ;
V_30 = ( V_4 -> V_31 . V_32 & V_61 ) ? 1 : 0 ;
if ( F_19 ( V_2 -> V_38 ) != V_30 ) {
F_21 ( V_2 -> V_38 , V_30 ) ;
if ( V_4 -> V_31 . V_62 > 0 )
F_20 ( V_4 -> V_31 . V_62 ) ;
}
}
if ( ( V_4 -> V_31 . V_32 & V_33 ) &&
! ( V_4 -> V_31 . V_32 & V_41 ) )
F_22 ( V_4 ) ;
F_28 ( V_2 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_30 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_32 ;
F_15 ( V_2 -> V_14 ) ;
F_31 ( & V_2 -> V_4 . V_63 , V_32 ) ;
V_2 -> V_27 &= ~ ( V_43 | V_44 ) ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_32 ( & V_2 -> V_4 . V_63 , V_32 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_33 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_32 ;
F_15 ( V_2 -> V_14 ) ;
F_31 ( & V_2 -> V_4 . V_63 , V_32 ) ;
V_2 -> V_27 |= V_43 | V_44 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_32 ( & V_2 -> V_4 . V_63 , V_32 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static unsigned int F_34 ( struct V_1 * V_2 )
{
unsigned int V_64 ;
V_64 = F_1 ( V_2 , V_65 ) ;
V_64 |= V_2 -> V_66 ;
V_2 -> V_66 = 0 ;
if ( ( V_64 & V_67 ) == 0 )
return V_64 ;
if ( V_64 & V_67 && V_2 -> V_27 & V_28 &&
V_2 -> V_4 . V_50 != NULL ) {
if ( V_64 & V_68 )
V_2 -> V_4 . V_54 . V_69 ++ ;
if ( V_64 & V_70 )
V_2 -> V_4 . V_54 . V_71 ++ ;
if ( V_64 & V_72 )
F_35
( & V_2 -> V_4 , V_64 & V_73 ) ;
if ( V_64 & V_74 )
F_36
( & V_2 -> V_4 , V_64 & V_75 ) ;
F_37 ( & V_2 -> V_4 . V_50 -> V_4 . V_76 ) ;
}
return V_64 ;
}
static void F_38 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned int V_77 ;
unsigned char V_78 = 0 ;
if ( F_39 ( V_47 & V_46 ) )
V_78 = F_1 ( V_2 , V_79 ) ;
V_2 -> V_4 . V_54 . V_80 ++ ;
V_77 = V_81 ;
if ( V_47 & V_82 ) {
V_77 = V_83 ;
V_47 &= ~ ( V_84 | V_85 ) ;
V_2 -> V_4 . V_54 . V_86 ++ ;
if ( F_40 ( & V_2 -> V_4 ) )
return;
}
if ( V_47 & V_85 ) {
V_77 = V_87 ;
V_2 -> V_4 . V_54 . V_88 ++ ;
}
if ( V_47 & V_84 ) {
V_77 = V_89 ;
V_2 -> V_4 . V_54 . V_90 ++ ;
}
if ( V_47 & V_91 )
V_2 -> V_4 . V_54 . V_92 ++ ;
#ifdef F_41
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_93 -> V_94 ) {
V_47 |= V_2 -> V_95 ;
}
#endif
F_42 ( & V_2 -> V_4 , V_47 , V_91 , 0 , V_77 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned char V_78 = 0 ;
unsigned int V_77 ;
if ( ! ( V_47 & V_46 ) )
return;
V_78 = F_1 ( V_2 , V_79 ) ;
V_77 = V_81 ;
V_2 -> V_4 . V_54 . V_80 ++ ;
if ( F_44 ( & V_2 -> V_4 , V_78 ) )
return;
F_42 ( & V_2 -> V_4 , V_47 , V_91 , V_78 , V_77 ) ;
}
static T_1 F_45 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
unsigned int V_98 , V_47 ;
unsigned int type ;
T_1 V_99 = V_100 ;
int V_101 = 256 ;
F_46 ( & V_2 -> V_4 . V_63 ) ;
F_15 ( V_2 -> V_14 ) ;
do {
V_98 = F_1 ( V_2 , V_102 ) ;
if ( V_98 & V_103 )
break;
V_99 = V_104 ;
V_47 = F_1 ( V_2 , V_105 ) ;
type = V_98 & 0x3e ;
switch ( type ) {
case V_106 :
F_34 ( V_2 ) ;
break;
case V_107 :
F_23 ( V_2 , V_47 ) ;
break;
case V_108 :
case V_109 :
F_43 ( V_2 , V_47 ) ;
break;
case V_110 :
F_38 ( V_2 , V_47 ) ;
break;
case V_111 :
break;
case V_112 :
default:
break;
}
} while ( ! ( V_98 & V_103 ) && V_101 -- );
F_47 ( & V_2 -> V_4 . V_63 ) ;
F_48 ( & V_2 -> V_4 . V_50 -> V_4 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
V_2 -> V_113 = V_114 ;
return V_99 ;
}
static unsigned int F_49 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_32 = 0 ;
unsigned int V_99 = 0 ;
F_15 ( V_2 -> V_14 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_2 , V_2 -> V_4 . line ) ;
F_31 ( & V_2 -> V_4 . V_63 , V_32 ) ;
V_99 = F_1 ( V_2 , V_105 ) & V_115 ? V_116 : 0 ;
F_32 ( & V_2 -> V_4 . V_63 , V_32 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
return V_99 ;
}
static unsigned int F_50 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned int V_64 ;
unsigned int V_99 = 0 ;
F_15 ( V_2 -> V_14 ) ;
V_64 = F_34 ( V_2 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_3 , V_2 -> V_4 . line ) ;
if ( V_64 & V_73 )
V_99 |= V_117 ;
if ( V_64 & V_118 )
V_99 |= V_119 ;
if ( V_64 & V_120 )
V_99 |= V_121 ;
if ( V_64 & V_75 )
V_99 |= V_122 ;
return V_99 ;
}
static void F_51 ( struct V_19 * V_4 , unsigned int V_123 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned char V_124 = 0 , V_125 , V_126 ;
F_14 ( V_2 -> V_4 . V_14 , L_4 , V_2 -> V_4 . line ) ;
if ( V_123 & V_127 )
V_124 |= V_128 ;
if ( V_123 & V_129 )
V_124 |= V_130 ;
if ( V_123 & V_131 )
V_124 |= V_132 ;
if ( V_123 & V_133 )
V_124 |= V_134 ;
if ( V_123 & V_135 )
V_124 |= V_136 ;
F_15 ( V_2 -> V_14 ) ;
V_125 = F_1 ( V_2 , V_137 ) ;
V_125 &= ~ ( V_136 | V_134 | V_132 |
V_130 | V_128 ) ;
V_2 -> V_124 = V_125 | V_124 ;
F_3 ( V_2 , V_137 , V_2 -> V_124 ) ;
V_126 = F_1 ( V_2 , V_138 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
if ( ( V_123 & V_127 ) && ( V_4 -> V_64 & V_140 ) )
V_2 -> V_141 |= V_142 ;
else
V_2 -> V_141 &= V_142 ;
F_3 ( V_2 , V_143 , V_2 -> V_141 ) ;
F_3 ( V_2 , V_138 , V_126 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_52 ( struct V_19 * V_4 , int V_144 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_32 = 0 ;
F_14 ( V_2 -> V_4 . V_14 , L_5 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
F_31 ( & V_2 -> V_4 . V_63 , V_32 ) ;
if ( V_144 == - 1 )
V_2 -> V_126 |= V_145 ;
else
V_2 -> V_126 &= ~ V_145 ;
F_3 ( V_2 , V_138 , V_2 -> V_126 ) ;
F_32 ( & V_2 -> V_4 . V_63 , V_32 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static int F_53 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_32 = 0 ;
int V_146 ;
V_146 = F_54 ( V_2 -> V_4 . V_96 , F_45 , V_2 -> V_4 . V_147 ,
V_2 -> V_148 , V_2 ) ;
if ( V_146 )
return V_146 ;
if ( V_2 -> V_149 ) {
V_146 = F_55 ( V_2 -> V_14 , V_2 -> V_149 ) ;
if ( V_146 ) {
F_56 ( V_2 -> V_4 . V_96 , V_2 ) ;
return V_146 ;
}
}
F_14 ( V_2 -> V_4 . V_14 , L_6 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
( void ) F_1 ( V_2 , V_105 ) ;
if ( F_1 ( V_2 , V_105 ) & V_46 )
( void ) F_1 ( V_2 , V_79 ) ;
( void ) F_1 ( V_2 , V_102 ) ;
( void ) F_1 ( V_2 , V_65 ) ;
F_3 ( V_2 , V_138 , V_150 ) ;
F_31 ( & V_2 -> V_4 . V_63 , V_32 ) ;
V_2 -> V_4 . V_123 |= V_133 ;
F_51 ( & V_2 -> V_4 , V_2 -> V_4 . V_123 ) ;
F_32 ( & V_2 -> V_4 . V_63 , V_32 ) ;
V_2 -> V_66 = 0 ;
V_2 -> V_27 = V_43 | V_44 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
V_2 -> V_151 = V_152 ;
if ( V_2 -> V_153 & V_154 )
V_2 -> V_151 |= V_155 ;
F_3 ( V_2 , V_156 , V_2 -> V_151 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
V_2 -> V_113 = V_114 ;
return 0 ;
}
static void F_57 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_32 = 0 ;
F_14 ( V_2 -> V_4 . V_14 , L_7 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_27 = 0 ;
F_3 ( V_2 , V_29 , 0 ) ;
F_31 ( & V_2 -> V_4 . V_63 , V_32 ) ;
V_2 -> V_4 . V_123 &= ~ V_133 ;
F_51 ( & V_2 -> V_4 , V_2 -> V_4 . V_123 ) ;
F_32 ( & V_2 -> V_4 . V_63 , V_32 ) ;
F_3 ( V_2 , V_138 , F_1 ( V_2 , V_138 ) & ~ V_145 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_105 ) & V_46 )
( void ) F_1 ( V_2 , V_79 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
F_56 ( V_2 -> V_4 . V_96 , V_2 ) ;
F_58 ( V_2 -> V_14 ) ;
}
static void F_59 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_60 ( V_158 , struct V_1 ,
V_159 ) ;
F_61 ( & V_2 -> V_160 , V_2 -> V_161 ) ;
}
static void
F_62 ( struct V_19 * V_4 , struct V_162 * V_163 ,
struct V_162 * V_164 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned char V_165 = 0 ;
unsigned long V_32 = 0 ;
unsigned int V_20 , V_166 ;
switch ( V_163 -> V_167 & V_168 ) {
case V_169 :
V_165 = V_170 ;
break;
case V_171 :
V_165 = V_172 ;
break;
case V_173 :
V_165 = V_174 ;
break;
default:
case V_175 :
V_165 = V_150 ;
break;
}
if ( V_163 -> V_167 & V_176 )
V_165 |= V_177 ;
if ( V_163 -> V_167 & V_178 )
V_165 |= V_179 ;
if ( ! ( V_163 -> V_167 & V_180 ) )
V_165 |= V_181 ;
if ( V_163 -> V_167 & V_182 )
V_165 |= V_183 ;
V_20 = F_63 ( V_4 , V_163 , V_164 , 0 , V_4 -> V_23 / 13 ) ;
V_166 = F_11 ( V_4 , V_20 ) ;
V_2 -> V_184 = ( V_185 * V_2 -> V_4 . V_56 ) / ( V_20 / 8 ) ;
V_2 -> V_161 = V_2 -> V_184 ;
F_64 ( & V_2 -> V_159 ) ;
V_2 -> V_186 = V_166 & 0xff ;
V_2 -> V_187 = V_166 >> 8 ;
V_2 -> V_188 = V_189 ;
V_2 -> V_42 = V_190 | V_191 |
V_9 ;
F_15 ( V_2 -> V_14 ) ;
F_31 ( & V_2 -> V_4 . V_63 , V_32 ) ;
F_65 ( V_4 , V_163 -> V_167 , V_20 ) ;
V_2 -> V_4 . V_45 = V_91 | V_192 | V_46 ;
if ( V_163 -> V_193 & V_194 )
V_2 -> V_4 . V_45 |= V_84 | V_85 ;
if ( V_163 -> V_193 & ( V_195 | V_196 ) )
V_2 -> V_4 . V_45 |= V_82 ;
V_2 -> V_4 . V_197 = 0 ;
if ( V_163 -> V_193 & V_198 )
V_2 -> V_4 . V_197 |= V_85 | V_84 ;
if ( V_163 -> V_193 & V_199 ) {
V_2 -> V_4 . V_197 |= V_82 ;
if ( V_163 -> V_193 & V_198 )
V_2 -> V_4 . V_197 |= V_91 ;
}
if ( ( V_163 -> V_167 & V_200 ) == 0 )
V_2 -> V_4 . V_197 |= V_46 ;
V_2 -> V_27 &= ~ V_28 ;
if ( F_66 ( & V_2 -> V_4 , V_163 -> V_167 ) )
V_2 -> V_27 |= V_28 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_138 , V_165 ) ;
V_2 -> V_126 = V_165 ;
V_2 -> V_34 = 0 ;
F_3 ( V_2 , V_138 , V_201 ) ;
F_3 ( V_2 , V_202 , 0 ) ;
F_3 ( V_2 , V_203 , 0 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
V_2 -> V_141 = F_1 ( V_2 , V_143 ) & ~ V_204 ;
V_2 -> V_141 &= ~ V_205 ;
F_3 ( V_2 , V_143 , V_2 -> V_141 | V_204 ) ;
F_3 ( V_2 , V_138 , V_201 ) ;
V_2 -> V_124 = F_1 ( V_2 , V_137 ) & ~ V_206 ;
F_3 ( V_2 , V_137 , V_2 -> V_124 | V_206 ) ;
V_2 -> V_34 |= V_207 ;
V_2 -> V_42 &= ~ V_208 ;
V_2 -> V_42 &= ~ V_209 ;
V_2 -> V_42 |= V_210 | V_211 |
V_9 ;
F_3 ( V_2 , V_8 , V_2 -> V_42 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_36 , V_2 -> V_34 ) ;
F_3 ( V_2 , V_138 , V_201 ) ;
F_3 ( V_2 , V_137 , V_2 -> V_124 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_141 ) ;
F_3 ( V_2 , V_138 , V_201 ) ;
if ( V_2 -> V_212 & V_213 )
F_67 ( V_2 , V_2 -> V_188 ) ;
else
F_3 ( V_2 , V_214 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_141 | V_204 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_202 , V_2 -> V_186 ) ;
F_3 ( V_2 , V_203 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_141 ) ;
F_3 ( V_2 , V_138 , V_165 ) ;
if ( ! F_10 ( V_4 , V_20 ) )
V_2 -> V_188 = V_215 ;
else
V_2 -> V_188 = V_216 ;
if ( V_2 -> V_212 & V_213 )
F_67 ( V_2 , V_2 -> V_188 ) ;
else
F_3 ( V_2 , V_214 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_217 , V_163 -> V_218 [ V_219 ] ) ;
F_3 ( V_2 , V_220 , V_163 -> V_218 [ V_221 ] ) ;
F_3 ( V_2 , V_143 , V_2 -> V_141 | V_204 ) ;
F_3 ( V_2 , V_138 , V_201 ) ;
F_3 ( V_2 , V_137 , V_2 -> V_124 | V_206 ) ;
F_3 ( V_2 , V_222 , V_223 ) ;
V_2 -> V_4 . V_64 &= ~ ( V_224 | V_140 | V_225 ) ;
if ( V_163 -> V_167 & V_226 && V_2 -> V_4 . V_32 & V_227 ) {
V_2 -> V_4 . V_64 |= V_224 | V_140 ;
V_2 -> V_141 |= V_228 ;
} else {
V_2 -> V_141 &= ~ ( V_228 | V_142 ) ;
}
if ( V_2 -> V_4 . V_32 & V_229 ) {
V_2 -> V_141 &= V_230 ;
if ( V_163 -> V_193 & V_231 )
V_2 -> V_141 |= V_232 ;
if ( V_163 -> V_193 & V_233 ) {
V_2 -> V_4 . V_64 |= V_225 ;
V_2 -> V_141 |= V_234 ;
}
if ( V_163 -> V_193 & V_235 )
V_2 -> V_124 |= V_236 ;
else
V_2 -> V_124 &= ~ V_236 ;
}
F_3 ( V_2 , V_137 , V_2 -> V_124 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_141 ) ;
F_3 ( V_2 , V_138 , V_2 -> V_126 ) ;
F_51 ( & V_2 -> V_4 , V_2 -> V_4 . V_123 ) ;
F_32 ( & V_2 -> V_4 . V_63 , V_32 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_8 , V_2 -> V_4 . line ) ;
}
static void
F_68 ( struct V_19 * V_4 , unsigned int V_50 ,
unsigned int V_237 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned char V_141 ;
F_14 ( V_2 -> V_4 . V_14 , L_9 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
V_141 = F_1 ( V_2 , V_143 ) ;
F_3 ( V_2 , V_143 , V_141 | V_204 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_29 , ( V_50 != 0 ) ? V_238 : 0 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_143 , V_141 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_69 ( struct V_19 * V_4 )
{
F_14 ( V_4 -> V_14 , L_10 ) ;
}
static int F_70 ( struct V_19 * V_4 )
{
F_14 ( V_4 -> V_14 , L_11 ) ;
return 0 ;
}
static void F_71 ( struct V_19 * V_4 , int V_32 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_12 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . type = V_239 ;
V_2 -> V_4 . V_32 |= V_229 | V_227 ;
}
static int
F_72 ( struct V_19 * V_4 , struct V_240 * V_241 )
{
F_14 ( V_4 -> V_14 , L_13 ) ;
return - V_16 ;
}
static const char *
F_73 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_14 , V_2 -> V_4 . line ) ;
return V_2 -> V_148 ;
}
static void T_2 F_74 ( struct V_1 * V_2 )
{
unsigned int V_64 , V_242 = 10000 ;
do {
V_64 = F_1 ( V_2 , V_105 ) ;
if ( V_64 & V_82 )
V_2 -> V_95 = V_82 ;
if ( -- V_242 == 0 )
break;
F_75 ( 1 ) ;
} while ( ( V_64 & V_243 ) != V_243 );
if ( V_2 -> V_4 . V_32 & V_244 ) {
V_242 = 1000000 ;
for ( V_242 = 1000000 ; V_242 ; V_242 -- ) {
unsigned int V_245 = F_1 ( V_2 , V_65 ) ;
V_2 -> V_66 |= V_245 & V_246 ;
if ( V_245 & V_75 )
break;
F_75 ( 1 ) ;
}
}
}
static void F_76 ( struct V_19 * V_4 , unsigned char V_78 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_15 ( V_2 -> V_14 ) ;
F_74 ( V_2 ) ;
F_3 ( V_2 , V_53 , V_78 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static int F_77 ( struct V_19 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned int V_64 ;
F_15 ( V_2 -> V_14 ) ;
V_64 = F_1 ( V_2 , V_105 ) ;
if ( ! ( V_64 & V_46 ) ) {
V_64 = V_247 ;
goto V_248;
}
V_64 = F_1 ( V_2 , V_79 ) ;
V_248:
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
return V_64 ;
}
static unsigned int F_78 ( struct V_19 * V_4 , int V_3 )
{
V_3 <<= V_4 -> V_5 ;
return F_2 ( V_4 -> V_6 + V_3 ) ;
}
static void F_79 ( struct V_19 * V_4 , int V_3 ,
int V_7 )
{
V_3 <<= V_4 -> V_5 ;
F_4 ( V_7 , V_4 -> V_6 + V_3 ) ;
}
static void F_80 ( struct V_19 * V_4 , int V_249 )
{
unsigned int V_64 ;
for (; ; ) {
V_64 = F_78 ( V_4 , V_105 ) ;
if ( ( V_64 & V_243 ) == V_243 )
break;
F_81 () ;
}
F_79 ( V_4 , V_53 , V_249 ) ;
}
static void F_82 ( struct V_250 * V_250 , const char * V_251 ,
unsigned int V_51 )
{
struct V_252 * V_253 = V_250 -> V_254 ;
struct V_19 * V_4 = & V_253 -> V_4 ;
F_83 ( V_4 , V_251 , V_51 , F_80 ) ;
}
static int T_3 F_84 ( struct V_252 * V_253 ,
const char * V_255 )
{
struct V_19 * V_4 = & V_253 -> V_4 ;
if ( ! ( V_253 -> V_4 . V_6 || V_253 -> V_4 . V_256 ) )
return - V_257 ;
V_4 -> V_5 = 2 ;
V_253 -> V_258 -> V_259 = F_82 ;
return 0 ;
}
static void F_85 ( struct V_19 * V_4 , int V_78 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_74 ( V_2 ) ;
F_3 ( V_2 , V_53 , V_78 ) ;
}
static void
F_86 ( struct V_250 * V_260 , const char * V_251 ,
unsigned int V_51 )
{
struct V_1 * V_2 = V_261 [ V_260 -> V_94 ] ;
unsigned long V_32 ;
unsigned int V_27 ;
int V_262 = 1 ;
F_15 ( V_2 -> V_14 ) ;
F_87 ( V_32 ) ;
if ( V_2 -> V_4 . V_263 )
V_262 = 0 ;
else if ( V_264 )
V_262 = F_88 ( & V_2 -> V_4 . V_63 ) ;
else
F_46 ( & V_2 -> V_4 . V_63 ) ;
V_27 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_83 ( & V_2 -> V_4 , V_251 , V_51 , F_85 ) ;
F_74 ( V_2 ) ;
F_3 ( V_2 , V_29 , V_27 ) ;
if ( V_2 -> V_66 )
F_34 ( V_2 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
if ( V_262 )
F_47 ( & V_2 -> V_4 . V_63 ) ;
F_89 ( V_32 ) ;
}
static int T_3
F_90 ( struct V_250 * V_260 , char * V_255 )
{
struct V_1 * V_2 ;
int V_20 = 115200 ;
int V_265 = 8 ;
int V_88 = 'n' ;
int V_266 = 'n' ;
if ( V_261 [ V_260 -> V_94 ] == NULL )
return - V_257 ;
V_2 = V_261 [ V_260 -> V_94 ] ;
if ( V_255 )
F_91 ( V_255 , & V_20 , & V_88 , & V_265 , & V_266 ) ;
return F_92 ( & V_2 -> V_4 , V_260 , V_20 , V_88 , V_265 , V_266 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
V_261 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_93 ( struct V_1 * V_2 )
{}
static int
F_94 ( struct V_19 * V_4 , struct V_267 * V_31 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned int V_21 ;
int V_268 ;
F_15 ( V_2 -> V_14 ) ;
V_21 = V_2 -> V_27 ;
V_2 -> V_27 = 0 ;
F_3 ( V_2 , V_29 , 0 ) ;
V_31 -> V_62 = F_95 ( V_31 -> V_62 , 100U ) ;
V_31 -> V_39 = F_95 ( V_31 -> V_39 , 100U ) ;
V_4 -> V_31 = * V_31 ;
if ( F_96 ( V_2 -> V_38 ) ) {
V_268 = ( V_4 -> V_31 . V_32 & V_33 ) ?
V_37 : V_61 ;
V_268 = ( V_4 -> V_31 . V_32 & V_268 ) ? 1 : 0 ;
F_21 ( V_2 -> V_38 , V_268 ) ;
} else
V_4 -> V_31 . V_32 &= ~ V_33 ;
V_2 -> V_27 = V_21 ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
if ( ! ( V_4 -> V_31 . V_32 & V_33 ) &&
( V_2 -> V_34 & V_35 ) ) {
V_2 -> V_34 &= ~ V_35 ;
F_3 ( V_2 , V_36 , V_2 -> V_34 ) ;
}
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
return 0 ;
}
static int F_97 ( struct V_253 * V_14 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
V_2 -> V_269 = true ;
return 0 ;
}
static void F_99 ( struct V_253 * V_14 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
V_2 -> V_269 = false ;
}
static int F_100 ( struct V_253 * V_14 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
F_101 ( & V_270 , & V_2 -> V_4 ) ;
F_102 ( & V_2 -> V_159 ) ;
if ( F_103 ( V_14 ) )
F_8 ( V_2 , true ) ;
else
F_8 ( V_2 , false ) ;
return 0 ;
}
static int F_104 ( struct V_253 * V_14 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
if ( F_103 ( V_14 ) )
F_8 ( V_2 , false ) ;
F_105 ( & V_270 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
T_4 V_271 , V_272 ;
T_5 V_273 , V_274 , V_275 ;
V_271 = F_107 ( V_2 -> V_4 . V_6 + ( V_276 << V_2 -> V_4 . V_5 ) ) ;
V_272 = V_271 >> V_277 ;
switch ( V_272 ) {
case 0 :
V_274 = ( V_271 & V_278 ) >>
V_279 ;
V_275 = ( V_271 & V_280 ) ;
break;
case 1 :
V_274 = ( V_271 & V_281 ) >>
V_282 ;
V_275 = ( V_271 & V_283 ) ;
break;
default:
F_108 ( V_2 -> V_14 ,
L_15 ,
V_2 -> V_148 ) ;
V_274 = 0xff ;
V_275 = 0xff ;
}
V_273 = F_109 ( V_274 , V_275 ) ;
switch ( V_273 ) {
case V_284 :
V_2 -> V_212 |= ( V_213 |
V_285 ) ;
break;
case V_286 :
V_2 -> V_212 |= ( V_213 |
V_285 ) ;
V_2 -> V_153 |= V_154 ;
break;
case V_287 :
V_2 -> V_212 |= V_213 ;
V_2 -> V_153 |= V_154 ;
break;
default:
break;
}
}
static struct V_12 * F_110 ( struct V_253 * V_14 )
{
struct V_12 * V_288 ;
V_288 = F_111 ( V_14 , sizeof( * V_288 ) , V_289 ) ;
if ( ! V_288 )
return NULL ;
F_112 ( V_14 -> V_290 , L_16 ,
& V_288 -> V_23 ) ;
V_288 -> V_32 = V_291 ;
return V_288 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_292 * V_293 )
{
struct V_267 * V_294 = & V_2 -> V_4 . V_31 ;
T_4 V_295 [ 2 ] ;
enum V_296 V_32 ;
int V_99 ;
V_294 -> V_32 = 0 ;
V_2 -> V_38 = - V_16 ;
if ( ! V_293 )
return 0 ;
if ( F_114 ( V_293 , L_17 ) )
V_294 -> V_32 |= V_61 ;
else
V_294 -> V_32 |= V_37 ;
V_2 -> V_38 = F_115 ( V_293 , L_18 , 0 , & V_32 ) ;
if ( F_96 ( V_2 -> V_38 ) ) {
V_99 = F_116 ( V_2 -> V_14 , V_2 -> V_38 , L_19 ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_117 ( V_2 -> V_38 ,
V_32 & V_37 ) ;
if ( V_99 < 0 )
return V_99 ;
} else if ( V_2 -> V_38 == - V_297 ) {
return - V_297 ;
} else {
V_2 -> V_38 = - V_16 ;
}
if ( F_118 ( V_293 , L_20 ,
V_295 , 2 ) == 0 ) {
V_294 -> V_62 = V_295 [ 0 ] ;
V_294 -> V_39 = V_295 [ 1 ] ;
}
if ( F_114 ( V_293 , L_21 ) )
V_294 -> V_32 |= V_41 ;
if ( F_114 ( V_293 , L_22 ) )
V_294 -> V_32 |= V_33 ;
return 0 ;
}
static int F_119 ( struct V_298 * V_299 )
{
struct V_12 * V_288 = F_7 ( & V_299 -> V_14 ) ;
struct V_1 * V_2 ;
struct V_300 * V_301 ;
void T_6 * V_302 ;
int V_303 = 0 ;
int V_149 = 0 ;
int V_99 ;
if ( V_299 -> V_14 . V_290 ) {
V_303 = F_120 ( V_299 -> V_14 . V_290 , 0 ) ;
if ( ! V_303 )
return - V_297 ;
V_149 = F_120 ( V_299 -> V_14 . V_290 , 1 ) ;
V_288 = F_110 ( & V_299 -> V_14 ) ;
V_299 -> V_14 . V_304 = V_288 ;
} else {
V_303 = F_121 ( V_299 , 0 ) ;
if ( V_303 < 0 )
return - V_297 ;
}
V_2 = F_111 ( & V_299 -> V_14 , sizeof( * V_2 ) , V_289 ) ;
if ( ! V_2 )
return - V_305 ;
V_301 = F_122 ( V_299 , V_306 , 0 ) ;
V_302 = F_123 ( & V_299 -> V_14 , V_301 ) ;
if ( F_124 ( V_302 ) )
return F_125 ( V_302 ) ;
V_2 -> V_14 = & V_299 -> V_14 ;
V_2 -> V_4 . V_14 = & V_299 -> V_14 ;
V_2 -> V_4 . type = V_239 ;
V_2 -> V_4 . V_307 = V_308 ;
V_2 -> V_4 . V_96 = V_303 ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_56 = 64 ;
V_2 -> V_4 . V_309 = & V_310 ;
if ( V_299 -> V_14 . V_290 )
V_99 = F_126 ( V_299 -> V_14 . V_290 , L_23 ) ;
else
V_99 = V_299 -> V_311 ;
if ( V_99 < 0 ) {
F_127 ( & V_299 -> V_14 , L_24 ,
V_99 ) ;
goto V_312;
}
V_2 -> V_4 . line = V_99 ;
if ( V_2 -> V_4 . line >= V_313 ) {
F_127 ( & V_299 -> V_14 , L_25 , V_2 -> V_4 . line ,
V_313 ) ;
V_99 = - V_314 ;
goto V_312;
}
V_2 -> V_149 = V_149 ;
if ( ! V_2 -> V_149 )
F_128 ( V_2 -> V_4 . V_14 , L_26 ,
V_2 -> V_4 . line ) ;
V_99 = F_113 ( V_2 , V_299 -> V_14 . V_290 ) ;
if ( V_99 < 0 )
goto V_315;
sprintf ( V_2 -> V_148 , L_27 , V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_316 = V_301 -> V_317 ;
V_2 -> V_4 . V_6 = V_302 ;
V_2 -> V_4 . V_32 = V_288 -> V_32 ;
V_2 -> V_4 . V_23 = V_288 -> V_23 ;
V_2 -> V_4 . V_318 = F_94 ;
if ( ! V_2 -> V_4 . V_23 ) {
V_2 -> V_4 . V_23 = V_319 ;
F_108 ( & V_299 -> V_14 ,
L_28 ,
V_319 ) ;
}
V_2 -> V_161 = V_320 ;
V_2 -> V_184 = V_320 ;
F_129 ( & V_2 -> V_160 ,
V_321 , V_2 -> V_161 ) ;
F_130 ( & V_2 -> V_159 , F_59 ) ;
F_131 ( V_299 , V_2 ) ;
if ( V_288 -> V_322 == 0 )
V_288 -> V_322 = - 1 ;
F_132 ( V_2 -> V_14 , true ) ;
F_133 ( & V_299 -> V_14 ) ;
F_134 ( & V_299 -> V_14 ,
V_288 -> V_322 ) ;
F_135 ( & V_299 -> V_14 ) ;
F_136 ( & V_299 -> V_14 ) ;
F_15 ( & V_299 -> V_14 ) ;
F_106 ( V_2 ) ;
V_323 [ V_2 -> V_4 . line ] = V_2 ;
F_93 ( V_2 ) ;
V_99 = F_137 ( & V_270 , & V_2 -> V_4 ) ;
if ( V_99 != 0 )
goto V_324;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
return 0 ;
V_324:
F_138 ( & V_299 -> V_14 ) ;
F_139 ( & V_299 -> V_14 ) ;
F_140 ( & V_299 -> V_14 ) ;
F_141 ( & V_2 -> V_160 ) ;
F_132 ( V_2 -> V_14 , false ) ;
V_315:
V_312:
return V_99 ;
}
static int F_142 ( struct V_298 * V_14 )
{
struct V_1 * V_2 = F_143 ( V_14 ) ;
F_15 ( V_2 -> V_14 ) ;
F_144 ( & V_270 , & V_2 -> V_4 ) ;
F_138 ( V_2 -> V_14 ) ;
F_139 ( V_2 -> V_14 ) ;
F_140 ( V_2 -> V_14 ) ;
F_141 ( & V_2 -> V_160 ) ;
F_132 ( & V_14 -> V_14 , false ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , T_7 V_188 )
{
T_7 V_325 = 255 ;
F_3 ( V_2 , V_214 , V_188 ) ;
F_75 ( 2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_42 | V_11 |
V_10 ) ;
while ( V_192 != ( F_1 ( V_2 , V_105 ) &
( V_192 | V_46 ) ) ) {
V_325 -- ;
if ( ! V_325 ) {
F_145 ( V_2 -> V_14 , L_29 ,
F_1 ( V_2 , V_105 ) ) ;
break;
}
F_75 ( 1 ) ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
if ( V_2 -> V_212 & V_213 )
F_67 ( V_2 , V_189 ) ;
else
F_3 ( V_2 , V_214 , V_189 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_143 , V_204 ) ;
F_3 ( V_2 , V_138 , 0x0 ) ;
F_3 ( V_2 , V_29 , 0x0 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_202 , V_2 -> V_186 ) ;
F_3 ( V_2 , V_203 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_138 , 0x0 ) ;
F_3 ( V_2 , V_29 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_42 ) ;
F_3 ( V_2 , V_138 , V_201 ) ;
F_3 ( V_2 , V_137 , V_2 -> V_124 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_3 ( V_2 , V_36 , V_2 -> V_34 ) ;
F_3 ( V_2 , V_143 , V_2 -> V_141 ) ;
F_3 ( V_2 , V_138 , V_2 -> V_126 ) ;
if ( V_2 -> V_212 & V_213 )
F_67 ( V_2 , V_2 -> V_188 ) ;
else
F_3 ( V_2 , V_214 , V_2 -> V_188 ) ;
F_3 ( V_2 , V_156 , V_2 -> V_151 ) ;
}
static int F_147 ( struct V_253 * V_14 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
if ( ! V_2 )
return - V_16 ;
if ( V_2 -> V_269 && ! V_326 &&
F_148 ( & V_2 -> V_4 ) )
return - V_327 ;
V_2 -> V_328 = F_6 ( V_2 ) ;
F_8 ( V_2 , true ) ;
V_2 -> V_161 = V_320 ;
F_64 ( & V_2 -> V_159 ) ;
return 0 ;
}
static int F_149 ( struct V_253 * V_14 )
{
struct V_1 * V_2 = F_98 ( V_14 ) ;
int V_329 = F_6 ( V_2 ) ;
F_8 ( V_2 , false ) ;
if ( V_329 < 0 ) {
F_14 ( V_14 , L_30 ,
V_329 ) ;
F_146 ( V_2 ) ;
} else if ( V_2 -> V_328 != V_329 ) {
F_146 ( V_2 ) ;
}
V_2 -> V_161 = V_2 -> V_184 ;
F_64 ( & V_2 -> V_159 ) ;
return 0 ;
}
static int T_3 F_150 ( void )
{
int V_99 ;
V_99 = F_151 ( & V_270 ) ;
if ( V_99 != 0 )
return V_99 ;
V_99 = F_152 ( & V_330 ) ;
if ( V_99 != 0 )
F_153 ( & V_270 ) ;
return V_99 ;
}
static void T_8 F_154 ( void )
{
F_155 ( & V_330 ) ;
F_153 ( & V_270 ) ;
}
