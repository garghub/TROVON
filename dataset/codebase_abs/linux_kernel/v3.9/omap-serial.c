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
static bool
F_10 ( struct V_21 * V_4 , unsigned int V_22 )
{
unsigned int V_23 = V_4 -> V_24 / ( 13 * V_22 ) ;
unsigned int V_25 = V_4 -> V_24 / ( 16 * V_22 ) ;
int V_26 = V_22 - ( V_4 -> V_24 / ( 13 * V_23 ) ) ;
int V_27 = V_22 - ( V_4 -> V_24 / ( 16 * V_25 ) ) ;
if( V_26 < 0 )
V_26 = - V_26 ;
if( V_27 < 0 )
V_27 = - V_27 ;
return ( V_26 > V_27 ) ;
}
static unsigned int
F_11 ( struct V_21 * V_4 , unsigned int V_22 )
{
unsigned int V_28 ;
if ( ! F_10 ( V_4 , V_22 ) )
V_28 = 13 ;
else
V_28 = 16 ;
return V_4 -> V_24 / ( V_22 * V_28 ) ;
}
static void F_12 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_1 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_29 |= V_30 ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_18 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_15 ( V_2 -> V_14 ) ;
if ( V_2 -> V_29 & V_32 ) {
V_2 -> V_29 &= ~ V_32 ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
}
F_7 ( V_2 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_19 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_29 &= ~ V_33 ;
V_2 -> V_4 . V_34 &= ~ V_35 ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_36 )
{
struct V_37 * V_38 = & V_2 -> V_4 . V_39 -> V_38 ;
int V_40 ;
if ( V_2 -> V_4 . V_41 ) {
F_3 ( V_2 , V_42 , V_2 -> V_4 . V_41 ) ;
V_2 -> V_4 . V_43 . V_44 ++ ;
V_2 -> V_4 . V_41 = 0 ;
return;
}
if ( F_21 ( V_38 ) || F_22 ( & V_2 -> V_4 ) ) {
F_18 ( & V_2 -> V_4 ) ;
return;
}
V_40 = V_2 -> V_4 . V_45 / 4 ;
do {
F_3 ( V_2 , V_42 , V_38 -> V_46 [ V_38 -> V_47 ] ) ;
V_38 -> V_47 = ( V_38 -> V_47 + 1 ) & ( V_48 - 1 ) ;
V_2 -> V_4 . V_43 . V_44 ++ ;
if ( F_21 ( V_38 ) )
break;
} while ( -- V_40 > 0 );
if ( F_23 ( V_38 ) < V_49 ) {
F_24 ( & V_2 -> V_4 . V_50 ) ;
F_25 ( & V_2 -> V_4 ) ;
F_26 ( & V_2 -> V_4 . V_50 ) ;
}
if ( F_21 ( V_38 ) )
F_18 ( & V_2 -> V_4 ) ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_29 & V_32 ) ) {
V_2 -> V_29 |= V_32 ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
}
}
static void F_28 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_15 ( V_2 -> V_14 ) ;
F_27 ( V_2 ) ;
F_8 ( V_2 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_29 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_51 ;
F_15 ( V_2 -> V_14 ) ;
F_30 ( & V_2 -> V_4 . V_50 , V_51 ) ;
V_2 -> V_29 &= ~ ( V_33 | V_52 ) ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_31 ( & V_2 -> V_4 . V_50 , V_51 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_32 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_51 ;
F_15 ( V_2 -> V_14 ) ;
F_30 ( & V_2 -> V_4 . V_50 , V_51 ) ;
V_2 -> V_29 |= V_33 | V_52 ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_31 ( & V_2 -> V_4 . V_50 , V_51 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static unsigned int F_33 ( struct V_1 * V_2 )
{
unsigned int V_53 ;
V_53 = F_1 ( V_2 , V_54 ) ;
V_53 |= V_2 -> V_55 ;
V_2 -> V_55 = 0 ;
if ( ( V_53 & V_56 ) == 0 )
return V_53 ;
if ( V_53 & V_56 && V_2 -> V_29 & V_30 &&
V_2 -> V_4 . V_39 != NULL ) {
if ( V_53 & V_57 )
V_2 -> V_4 . V_43 . V_58 ++ ;
if ( V_53 & V_59 )
V_2 -> V_4 . V_43 . V_60 ++ ;
if ( V_53 & V_61 )
F_34
( & V_2 -> V_4 , V_53 & V_62 ) ;
if ( V_53 & V_63 )
F_35
( & V_2 -> V_4 , V_53 & V_64 ) ;
F_36 ( & V_2 -> V_4 . V_39 -> V_4 . V_65 ) ;
}
return V_53 ;
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_36 )
{
unsigned int V_66 ;
unsigned char V_67 = 0 ;
if ( F_38 ( V_36 & V_35 ) )
V_67 = F_1 ( V_2 , V_68 ) ;
V_2 -> V_4 . V_43 . V_69 ++ ;
V_66 = V_70 ;
if ( V_36 & V_71 ) {
V_66 = V_72 ;
V_36 &= ~ ( V_73 | V_74 ) ;
V_2 -> V_4 . V_43 . V_75 ++ ;
if ( F_39 ( & V_2 -> V_4 ) )
return;
}
if ( V_36 & V_74 ) {
V_66 = V_76 ;
V_2 -> V_4 . V_43 . V_77 ++ ;
}
if ( V_36 & V_73 ) {
V_66 = V_78 ;
V_2 -> V_4 . V_43 . V_79 ++ ;
}
if ( V_36 & V_80 )
V_2 -> V_4 . V_43 . V_81 ++ ;
#ifdef F_40
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_82 -> V_83 ) {
V_36 |= V_2 -> V_84 ;
}
#endif
F_41 ( & V_2 -> V_4 , V_36 , V_80 , 0 , V_66 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_36 )
{
unsigned char V_67 = 0 ;
unsigned int V_66 ;
if ( ! ( V_36 & V_35 ) )
return;
V_67 = F_1 ( V_2 , V_68 ) ;
V_66 = V_70 ;
V_2 -> V_4 . V_43 . V_69 ++ ;
if ( F_43 ( & V_2 -> V_4 , V_67 ) )
return;
F_41 ( & V_2 -> V_4 , V_36 , V_80 , V_67 , V_66 ) ;
}
static T_1 F_44 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
unsigned int V_87 , V_36 ;
unsigned int type ;
T_1 V_88 = V_89 ;
int V_90 = 256 ;
F_26 ( & V_2 -> V_4 . V_50 ) ;
F_15 ( V_2 -> V_14 ) ;
do {
V_87 = F_1 ( V_2 , V_91 ) ;
if ( V_87 & V_92 )
break;
V_88 = V_93 ;
V_36 = F_1 ( V_2 , V_94 ) ;
type = V_87 & 0x3e ;
switch ( type ) {
case V_95 :
F_33 ( V_2 ) ;
break;
case V_96 :
F_20 ( V_2 , V_36 ) ;
break;
case V_97 :
case V_98 :
F_42 ( V_2 , V_36 ) ;
break;
case V_99 :
F_37 ( V_2 , V_36 ) ;
break;
case V_100 :
break;
case V_101 :
default:
break;
}
} while ( ! ( V_87 & V_92 ) && V_90 -- );
F_24 ( & V_2 -> V_4 . V_50 ) ;
F_45 ( & V_2 -> V_4 . V_39 -> V_4 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
V_2 -> V_102 = V_103 ;
return V_88 ;
}
static unsigned int F_46 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_51 = 0 ;
unsigned int V_88 = 0 ;
F_15 ( V_2 -> V_14 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_2 , V_2 -> V_4 . line ) ;
F_30 ( & V_2 -> V_4 . V_50 , V_51 ) ;
V_88 = F_1 ( V_2 , V_94 ) & V_104 ? V_105 : 0 ;
F_31 ( & V_2 -> V_4 . V_50 , V_51 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
return V_88 ;
}
static unsigned int F_47 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned int V_53 ;
unsigned int V_88 = 0 ;
F_15 ( V_2 -> V_14 ) ;
V_53 = F_33 ( V_2 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_3 , V_2 -> V_4 . line ) ;
if ( V_53 & V_62 )
V_88 |= V_106 ;
if ( V_53 & V_107 )
V_88 |= V_108 ;
if ( V_53 & V_109 )
V_88 |= V_110 ;
if ( V_53 & V_64 )
V_88 |= V_111 ;
return V_88 ;
}
static void F_48 ( struct V_21 * V_4 , unsigned int V_112 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned char V_113 = 0 , V_114 ;
F_14 ( V_2 -> V_4 . V_14 , L_4 , V_2 -> V_4 . line ) ;
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
F_15 ( V_2 -> V_14 ) ;
V_114 = F_1 ( V_2 , V_125 ) ;
V_114 &= ~ ( V_124 | V_122 | V_120 |
V_118 | V_116 ) ;
V_2 -> V_113 = V_114 | V_113 ;
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
if ( F_49 ( V_2 -> V_126 ) &&
! ! ( V_112 & V_117 ) != V_2 -> V_127 ) {
V_2 -> V_127 = ! V_2 -> V_127 ;
if ( F_50 ( V_2 -> V_126 ) )
F_51 ( & V_2 -> V_128 ) ;
else
F_52 ( V_2 -> V_126 ,
V_2 -> V_127 != V_2 -> V_129 ) ;
}
}
static void F_53 ( struct V_21 * V_4 , int V_130 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_51 = 0 ;
F_14 ( V_2 -> V_4 . V_14 , L_5 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
F_30 ( & V_2 -> V_4 . V_50 , V_51 ) ;
if ( V_130 == - 1 )
V_2 -> V_131 |= V_132 ;
else
V_2 -> V_131 &= ~ V_132 ;
F_3 ( V_2 , V_133 , V_2 -> V_131 ) ;
F_31 ( & V_2 -> V_4 . V_50 , V_51 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static int F_54 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_51 = 0 ;
int V_134 ;
V_134 = F_55 ( V_2 -> V_4 . V_85 , F_44 , V_2 -> V_4 . V_135 ,
V_2 -> V_136 , V_2 ) ;
if ( V_134 )
return V_134 ;
F_14 ( V_2 -> V_4 . V_14 , L_6 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_125 , V_116 ) ;
( void ) F_1 ( V_2 , V_94 ) ;
if ( F_1 ( V_2 , V_94 ) & V_35 )
( void ) F_1 ( V_2 , V_68 ) ;
( void ) F_1 ( V_2 , V_91 ) ;
( void ) F_1 ( V_2 , V_54 ) ;
F_3 ( V_2 , V_133 , V_137 ) ;
F_30 ( & V_2 -> V_4 . V_50 , V_51 ) ;
V_2 -> V_4 . V_112 |= V_121 ;
F_48 ( & V_2 -> V_4 , V_2 -> V_4 . V_112 ) ;
F_31 ( & V_2 -> V_4 . V_50 , V_51 ) ;
V_2 -> V_55 = 0 ;
V_2 -> V_29 = V_33 | V_52 ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_3 ( V_2 , V_138 , V_139 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
V_2 -> V_102 = V_103 ;
return 0 ;
}
static void F_56 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned long V_51 = 0 ;
F_14 ( V_2 -> V_4 . V_14 , L_7 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
V_2 -> V_29 = 0 ;
F_3 ( V_2 , V_31 , 0 ) ;
F_30 ( & V_2 -> V_4 . V_50 , V_51 ) ;
V_2 -> V_4 . V_112 &= ~ V_121 ;
F_48 ( & V_2 -> V_4 , V_2 -> V_4 . V_112 ) ;
F_31 ( & V_2 -> V_4 . V_50 , V_51 ) ;
F_3 ( V_2 , V_133 , F_1 ( V_2 , V_133 ) & ~ V_132 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_94 ) & V_35 )
( void ) F_1 ( V_2 , V_68 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
F_57 ( V_2 -> V_4 . V_85 , V_2 ) ;
}
static void F_58 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_59 ( V_141 , struct V_1 ,
V_128 ) ;
F_60 ( & V_2 -> V_142 , V_2 -> V_143 ) ;
if ( F_49 ( V_2 -> V_126 ) )
F_61 ( V_2 -> V_126 ,
V_2 -> V_127 != V_2 -> V_129 ) ;
}
static void
F_62 ( struct V_21 * V_4 , struct V_144 * V_145 ,
struct V_144 * V_146 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned char V_147 = 0 ;
unsigned long V_51 = 0 ;
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
if ( V_145 -> V_149 & V_164 )
V_147 |= V_165 ;
V_22 = F_63 ( V_4 , V_145 , V_146 , 0 , V_4 -> V_24 / 13 ) ;
V_148 = F_11 ( V_4 , V_22 ) ;
V_2 -> V_166 = ( V_167 * V_2 -> V_4 . V_45 ) / ( V_22 / 8 ) ;
V_2 -> V_143 = V_2 -> V_166 ;
F_51 ( & V_2 -> V_128 ) ;
V_2 -> V_168 = V_148 & 0xff ;
V_2 -> V_169 = V_148 >> 8 ;
V_2 -> V_170 = V_171 ;
V_2 -> V_172 = V_173 | V_174 |
V_9 ;
F_15 ( V_2 -> V_14 ) ;
F_30 ( & V_2 -> V_4 . V_50 , V_51 ) ;
F_64 ( V_4 , V_145 -> V_149 , V_22 ) ;
V_2 -> V_4 . V_34 = V_80 | V_175 | V_35 ;
if ( V_145 -> V_176 & V_177 )
V_2 -> V_4 . V_34 |= V_73 | V_74 ;
if ( V_145 -> V_176 & ( V_178 | V_179 ) )
V_2 -> V_4 . V_34 |= V_71 ;
V_2 -> V_4 . V_180 = 0 ;
if ( V_145 -> V_176 & V_181 )
V_2 -> V_4 . V_180 |= V_74 | V_73 ;
if ( V_145 -> V_176 & V_182 ) {
V_2 -> V_4 . V_180 |= V_71 ;
if ( V_145 -> V_176 & V_181 )
V_2 -> V_4 . V_180 |= V_80 ;
}
if ( ( V_145 -> V_149 & V_183 ) == 0 )
V_2 -> V_4 . V_180 |= V_35 ;
V_2 -> V_29 &= ~ V_30 ;
if ( F_65 ( & V_2 -> V_4 , V_145 -> V_149 ) )
V_2 -> V_29 |= V_30 ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_3 ( V_2 , V_133 , V_147 ) ;
V_2 -> V_131 = V_147 ;
V_2 -> V_184 = 0 ;
F_3 ( V_2 , V_133 , V_185 ) ;
F_3 ( V_2 , V_186 , 0 ) ;
F_3 ( V_2 , V_187 , 0 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
V_2 -> V_189 = F_1 ( V_2 , V_190 ) & ~ V_191 ;
V_2 -> V_189 &= ~ V_192 ;
F_3 ( V_2 , V_190 , V_2 -> V_189 | V_191 ) ;
F_3 ( V_2 , V_133 , V_185 ) ;
V_2 -> V_113 = F_1 ( V_2 , V_125 ) & ~ V_193 ;
F_3 ( V_2 , V_125 , V_2 -> V_113 | V_193 ) ;
V_2 -> V_184 |= V_194 ;
V_2 -> V_172 &= ~ V_195 ;
V_2 -> V_172 &= ~ V_196 ;
V_2 -> V_172 |= V_197 | V_198 |
V_9 ;
F_3 ( V_2 , V_8 , V_2 -> V_172 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_199 , V_2 -> V_184 ) ;
F_3 ( V_2 , V_133 , V_185 ) ;
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_190 , V_2 -> V_189 ) ;
F_3 ( V_2 , V_133 , V_185 ) ;
if ( V_2 -> V_200 & V_201 )
F_66 ( V_2 , V_2 -> V_170 ) ;
else
F_3 ( V_2 , V_202 , V_2 -> V_170 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_190 , V_2 -> V_189 | V_191 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_31 , 0 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_186 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_187 , V_2 -> V_169 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_190 , V_2 -> V_189 ) ;
F_3 ( V_2 , V_133 , V_147 ) ;
if ( ! F_10 ( V_4 , V_22 ) )
V_2 -> V_170 = V_203 ;
else
V_2 -> V_170 = V_204 ;
if ( V_2 -> V_200 & V_201 )
F_66 ( V_2 , V_2 -> V_170 ) ;
else
F_3 ( V_2 , V_202 , V_2 -> V_170 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_205 , V_145 -> V_206 [ V_207 ] ) ;
F_3 ( V_2 , V_208 , V_145 -> V_206 [ V_209 ] ) ;
F_3 ( V_2 , V_190 , V_2 -> V_189 | V_191 ) ;
F_3 ( V_2 , V_133 , V_185 ) ;
F_3 ( V_2 , V_125 , V_2 -> V_113 | V_193 ) ;
F_3 ( V_2 , V_210 , V_211 ) ;
if ( V_145 -> V_149 & V_212 && V_2 -> V_4 . V_51 & V_213 ) {
V_2 -> V_189 |= V_214 | V_215 ;
V_2 -> V_113 |= V_116 ;
} else {
V_2 -> V_189 &= ~ ( V_214 | V_215 ) ;
}
if ( V_2 -> V_4 . V_51 & V_216 ) {
V_2 -> V_189 &= V_217 ;
if ( V_145 -> V_176 & V_218 )
V_2 -> V_189 |= V_219 ;
if ( V_145 -> V_176 & V_220 )
V_2 -> V_189 |= V_221 ;
if ( V_145 -> V_176 & V_222 )
V_2 -> V_113 |= V_223 ;
else
V_2 -> V_113 &= ~ V_223 ;
}
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_190 , V_2 -> V_189 ) ;
F_3 ( V_2 , V_133 , V_2 -> V_131 ) ;
F_48 ( & V_2 -> V_4 , V_2 -> V_4 . V_112 ) ;
F_31 ( & V_2 -> V_4 . V_50 , V_51 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_8 , V_2 -> V_4 . line ) ;
}
static int F_67 ( struct V_21 * V_4 , unsigned int V_39 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_9 ( V_2 , V_39 ) ;
return 0 ;
}
static void
F_68 ( struct V_21 * V_4 , unsigned int V_39 ,
unsigned int V_224 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned char V_189 ;
F_14 ( V_2 -> V_4 . V_14 , L_9 , V_2 -> V_4 . line ) ;
F_15 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
V_189 = F_1 ( V_2 , V_190 ) ;
F_3 ( V_2 , V_190 , V_189 | V_191 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
F_3 ( V_2 , V_31 , ( V_39 != 0 ) ? V_225 : 0 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_190 , V_189 ) ;
F_3 ( V_2 , V_133 , 0 ) ;
if ( ! F_69 ( V_2 -> V_14 ) ) {
if ( ! V_39 )
F_70 ( V_2 -> V_14 ) ;
else
F_71 ( V_2 -> V_14 ) ;
}
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static void F_72 ( struct V_21 * V_4 )
{
F_14 ( V_4 -> V_14 , L_10 ) ;
}
static int F_73 ( struct V_21 * V_4 )
{
F_14 ( V_4 -> V_14 , L_11 ) ;
return 0 ;
}
static void F_74 ( struct V_21 * V_4 , int V_51 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_12 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . type = V_226 ;
V_2 -> V_4 . V_51 |= V_216 | V_213 ;
}
static int
F_75 ( struct V_21 * V_4 , struct V_227 * V_228 )
{
F_14 ( V_4 -> V_14 , L_13 ) ;
return - V_229 ;
}
static const char *
F_76 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_14 ( V_2 -> V_4 . V_14 , L_14 , V_2 -> V_4 . line ) ;
return V_2 -> V_136 ;
}
static inline void F_77 ( struct V_1 * V_2 )
{
unsigned int V_53 , V_230 = 10000 ;
do {
V_53 = F_1 ( V_2 , V_94 ) ;
if ( V_53 & V_71 )
V_2 -> V_84 = V_71 ;
if ( -- V_230 == 0 )
break;
F_78 ( 1 ) ;
} while ( ( V_53 & V_231 ) != V_231 );
if ( V_2 -> V_4 . V_51 & V_232 ) {
V_230 = 1000000 ;
for ( V_230 = 1000000 ; V_230 ; V_230 -- ) {
unsigned int V_233 = F_1 ( V_2 , V_54 ) ;
V_2 -> V_55 |= V_233 & V_234 ;
if ( V_233 & V_64 )
break;
F_78 ( 1 ) ;
}
}
}
static void F_79 ( struct V_21 * V_4 , unsigned char V_67 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_15 ( V_2 -> V_14 ) ;
F_77 ( V_2 ) ;
F_3 ( V_2 , V_42 , V_67 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
}
static int F_80 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
unsigned int V_53 ;
F_15 ( V_2 -> V_14 ) ;
V_53 = F_1 ( V_2 , V_94 ) ;
if ( ! ( V_53 & V_35 ) ) {
V_53 = V_235 ;
goto V_236;
}
V_53 = F_1 ( V_2 , V_68 ) ;
V_236:
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
return V_53 ;
}
static void F_81 ( struct V_21 * V_4 , int V_67 )
{
struct V_1 * V_2 = F_13 ( V_4 ) ;
F_77 ( V_2 ) ;
F_3 ( V_2 , V_42 , V_67 ) ;
}
static void
F_82 ( struct V_237 * V_238 , const char * V_239 ,
unsigned int V_40 )
{
struct V_1 * V_2 = V_240 [ V_238 -> V_83 ] ;
unsigned long V_51 ;
unsigned int V_29 ;
int V_241 = 1 ;
F_15 ( V_2 -> V_14 ) ;
F_83 ( V_51 ) ;
if ( V_2 -> V_4 . V_242 )
V_241 = 0 ;
else if ( V_243 )
V_241 = F_84 ( & V_2 -> V_4 . V_50 ) ;
else
F_26 ( & V_2 -> V_4 . V_50 ) ;
V_29 = F_1 ( V_2 , V_31 ) ;
F_3 ( V_2 , V_31 , 0 ) ;
F_85 ( & V_2 -> V_4 , V_239 , V_40 , F_81 ) ;
F_77 ( V_2 ) ;
F_3 ( V_2 , V_31 , V_29 ) ;
if ( V_2 -> V_55 )
F_33 ( V_2 ) ;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
if ( V_241 )
F_24 ( & V_2 -> V_4 . V_50 ) ;
F_86 ( V_51 ) ;
}
static int T_2
F_87 ( struct V_237 * V_238 , char * V_244 )
{
struct V_1 * V_2 ;
int V_22 = 115200 ;
int V_245 = 8 ;
int V_77 = 'n' ;
int V_246 = 'n' ;
if ( V_240 [ V_238 -> V_83 ] == NULL )
return - V_247 ;
V_2 = V_240 [ V_238 -> V_83 ] ;
if ( V_244 )
F_88 ( V_244 , & V_22 , & V_77 , & V_245 , & V_246 ) ;
return F_89 ( & V_2 -> V_4 , V_238 , V_22 , V_77 , V_245 , V_246 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
V_240 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_90 ( struct V_1 * V_2 )
{}
static int F_91 ( struct V_248 * V_14 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
F_93 ( & V_249 , & V_2 -> V_4 ) ;
F_94 ( & V_2 -> V_128 ) ;
return 0 ;
}
static int F_95 ( struct V_248 * V_14 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
F_96 ( & V_249 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
T_3 V_250 , V_251 ;
T_4 V_252 , V_253 , V_254 ;
V_250 = F_1 ( V_2 , V_255 ) ;
V_251 = V_250 >> V_256 ;
switch ( V_251 ) {
case 0 :
V_253 = ( V_250 & V_257 ) >>
V_258 ;
V_254 = ( V_250 & V_259 ) ;
break;
case 1 :
V_253 = ( V_250 & V_260 ) >>
V_261 ;
V_254 = ( V_250 & V_262 ) ;
break;
default:
F_98 ( V_2 -> V_14 ,
L_15 ,
V_2 -> V_136 ) ;
V_253 = 0xff ;
V_254 = 0xff ;
}
V_252 = F_99 ( V_253 , V_254 ) ;
switch ( V_252 ) {
case V_263 :
V_2 -> V_200 |= ( V_201 |
V_264 ) ;
break;
case V_265 :
V_2 -> V_200 |= ( V_201 |
V_264 ) ;
break;
case V_266 :
V_2 -> V_200 |= V_201 ;
break;
default:
break;
}
}
static struct V_12 * F_100 ( struct V_248 * V_14 )
{
struct V_12 * V_267 ;
V_267 = F_101 ( V_14 , sizeof( * V_267 ) , V_268 ) ;
if ( ! V_267 )
return NULL ;
F_102 ( V_14 -> V_269 , L_16 ,
& V_267 -> V_24 ) ;
return V_267 ;
}
static int F_103 ( struct V_270 * V_271 )
{
struct V_1 * V_2 ;
struct V_272 * V_273 , * V_85 ;
struct V_12 * V_267 = V_271 -> V_14 . V_15 ;
int V_88 ;
if ( V_271 -> V_14 . V_269 )
V_267 = F_100 ( & V_271 -> V_14 ) ;
V_273 = F_104 ( V_271 , V_274 , 0 ) ;
if ( ! V_273 ) {
F_105 ( & V_271 -> V_14 , L_17 ) ;
return - V_247 ;
}
V_85 = F_104 ( V_271 , V_275 , 0 ) ;
if ( ! V_85 ) {
F_105 ( & V_271 -> V_14 , L_18 ) ;
return - V_247 ;
}
if ( ! F_106 ( & V_271 -> V_14 , V_273 -> V_276 , F_107 ( V_273 ) ,
V_271 -> V_14 . V_277 -> V_136 ) ) {
F_105 ( & V_271 -> V_14 , L_19 ) ;
return - V_278 ;
}
if ( F_49 ( V_267 -> V_126 ) &&
V_267 -> V_279 ) {
V_88 = F_108 ( V_267 -> V_126 , L_20 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = F_109 ( V_267 -> V_126 ,
V_267 -> V_129 ) ;
if ( V_88 < 0 )
return V_88 ;
}
V_2 = F_101 ( & V_271 -> V_14 , sizeof( * V_2 ) , V_268 ) ;
if ( ! V_2 )
return - V_280 ;
if ( F_49 ( V_267 -> V_126 ) &&
V_267 -> V_279 ) {
V_2 -> V_126 = V_267 -> V_126 ;
V_2 -> V_129 = V_267 -> V_129 ;
} else
V_2 -> V_126 = - V_229 ;
V_2 -> V_127 = 0 ;
V_2 -> V_14 = & V_271 -> V_14 ;
V_2 -> V_4 . V_14 = & V_271 -> V_14 ;
V_2 -> V_4 . type = V_226 ;
V_2 -> V_4 . V_281 = V_282 ;
V_2 -> V_4 . V_85 = V_85 -> V_276 ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_45 = 64 ;
V_2 -> V_4 . V_283 = & V_284 ;
if ( V_271 -> V_14 . V_269 )
V_2 -> V_4 . line = F_110 ( V_271 -> V_14 . V_269 , L_21 ) ;
else
V_2 -> V_4 . line = V_271 -> V_285 ;
if ( V_2 -> V_4 . line < 0 ) {
F_105 ( & V_271 -> V_14 , L_22 ,
V_2 -> V_4 . line ) ;
V_88 = - V_247 ;
goto V_286;
}
V_2 -> V_287 = F_111 ( & V_271 -> V_14 ) ;
if ( F_112 ( V_2 -> V_287 ) ) {
F_98 ( & V_271 -> V_14 , L_23 ,
V_2 -> V_4 . line , F_113 ( V_2 -> V_287 ) ) ;
V_2 -> V_287 = NULL ;
}
sprintf ( V_2 -> V_136 , L_24 , V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_288 = V_273 -> V_276 ;
V_2 -> V_4 . V_6 = F_114 ( & V_271 -> V_14 , V_273 -> V_276 ,
F_107 ( V_273 ) ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_105 ( & V_271 -> V_14 , L_25 ) ;
V_88 = - V_280 ;
goto V_289;
}
V_2 -> V_4 . V_51 = V_267 -> V_51 ;
V_2 -> V_4 . V_24 = V_267 -> V_24 ;
if ( ! V_2 -> V_4 . V_24 ) {
V_2 -> V_4 . V_24 = V_290 ;
F_98 ( & V_271 -> V_14 , L_26
L_27 , V_290 ) ;
}
V_2 -> V_143 = V_291 ;
V_2 -> V_166 = V_291 ;
F_115 ( & V_2 -> V_142 ,
V_292 , V_2 -> V_143 ) ;
V_293 = F_116 ( V_2 -> V_136 ) ;
F_117 ( & V_2 -> V_128 , F_58 ) ;
F_118 ( V_271 , V_2 ) ;
F_119 ( & V_271 -> V_14 ) ;
F_120 ( & V_271 -> V_14 ) ;
F_121 ( & V_271 -> V_14 ,
V_267 -> V_294 ) ;
F_122 ( & V_271 -> V_14 ) ;
F_15 ( & V_271 -> V_14 ) ;
F_97 ( V_2 ) ;
V_295 [ V_2 -> V_4 . line ] = V_2 ;
F_90 ( V_2 ) ;
V_88 = F_123 ( & V_249 , & V_2 -> V_4 ) ;
if ( V_88 != 0 )
goto V_296;
F_16 ( V_2 -> V_14 ) ;
F_17 ( V_2 -> V_14 ) ;
return 0 ;
V_296:
F_124 ( & V_271 -> V_14 ) ;
F_125 ( & V_271 -> V_14 ) ;
V_289:
V_286:
F_105 ( & V_271 -> V_14 , L_28 ,
V_271 -> V_285 , V_297 , V_88 ) ;
return V_88 ;
}
static int F_126 ( struct V_270 * V_14 )
{
struct V_1 * V_2 = F_127 ( V_14 ) ;
F_128 ( V_2 -> V_14 ) ;
F_125 ( V_2 -> V_14 ) ;
F_129 ( & V_249 , & V_2 -> V_4 ) ;
F_130 ( & V_2 -> V_142 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , T_5 V_170 )
{
T_5 V_298 = 255 ;
F_3 ( V_2 , V_202 , V_170 ) ;
F_78 ( 2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_172 | V_11 |
V_10 ) ;
while ( V_175 != ( F_1 ( V_2 , V_94 ) &
( V_175 | V_35 ) ) ) {
V_298 -- ;
if ( ! V_298 ) {
F_131 ( V_2 -> V_14 , L_29 ,
F_1 ( V_2 , V_94 ) ) ;
break;
}
F_78 ( 1 ) ;
}
}
static void F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_200 & V_201 )
F_66 ( V_2 , V_171 ) ;
else
F_3 ( V_2 , V_202 , V_171 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_190 , V_191 ) ;
F_3 ( V_2 , V_133 , 0x0 ) ;
F_3 ( V_2 , V_31 , 0x0 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_186 , V_2 -> V_168 ) ;
F_3 ( V_2 , V_187 , V_2 -> V_169 ) ;
F_3 ( V_2 , V_133 , 0x0 ) ;
F_3 ( V_2 , V_31 , V_2 -> V_29 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_172 ) ;
F_3 ( V_2 , V_133 , V_185 ) ;
F_3 ( V_2 , V_125 , V_2 -> V_113 ) ;
F_3 ( V_2 , V_133 , V_188 ) ;
F_3 ( V_2 , V_199 , V_2 -> V_184 ) ;
F_3 ( V_2 , V_190 , V_2 -> V_189 ) ;
F_3 ( V_2 , V_133 , V_2 -> V_131 ) ;
if ( V_2 -> V_200 & V_201 )
F_66 ( V_2 , V_2 -> V_170 ) ;
else
F_3 ( V_2 , V_202 , V_2 -> V_170 ) ;
}
static int F_133 ( struct V_248 * V_14 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
struct V_12 * V_13 = V_14 -> V_15 ;
if ( ! V_2 )
return - V_229 ;
if ( ! V_13 )
return 0 ;
V_2 -> V_299 = F_6 ( V_2 ) ;
if ( F_69 ( V_14 ) ) {
if ( ! V_2 -> V_300 ) {
F_9 ( V_2 , true ) ;
V_2 -> V_300 = true ;
}
} else {
if ( V_2 -> V_300 ) {
F_9 ( V_2 , false ) ;
V_2 -> V_300 = false ;
}
}
V_2 -> V_143 = V_291 ;
F_51 ( & V_2 -> V_128 ) ;
return 0 ;
}
static int F_134 ( struct V_248 * V_14 )
{
struct V_1 * V_2 = F_92 ( V_14 ) ;
int V_301 = F_6 ( V_2 ) ;
if ( V_301 < 0 ) {
F_105 ( V_14 , L_30 ,
V_301 ) ;
F_132 ( V_2 ) ;
} else if ( V_2 -> V_299 != V_301 ) {
F_132 ( V_2 ) ;
}
V_2 -> V_143 = V_2 -> V_166 ;
F_51 ( & V_2 -> V_128 ) ;
return 0 ;
}
static int T_2 F_135 ( void )
{
int V_88 ;
V_88 = F_136 ( & V_249 ) ;
if ( V_88 != 0 )
return V_88 ;
V_88 = F_137 ( & V_302 ) ;
if ( V_88 != 0 )
F_138 ( & V_249 ) ;
return V_88 ;
}
static void T_6 F_139 ( void )
{
F_140 ( & V_302 ) ;
F_138 ( & V_249 ) ;
}
