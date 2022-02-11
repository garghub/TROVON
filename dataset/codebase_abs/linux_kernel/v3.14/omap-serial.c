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
static inline void F_8 ( struct V_1 * V_2 ,
bool V_17 )
{
if ( ! V_2 -> V_18 )
return;
if ( V_17 )
F_9 ( V_2 -> V_18 ) ;
else
F_10 ( V_2 -> V_18 ) ;
}
static void F_11 ( struct V_1 * V_2 , bool V_17 )
{
struct V_12 * V_13 = F_7 ( V_2 -> V_14 ) ;
F_8 ( V_2 , V_17 ) ;
if ( ! V_13 || ! V_13 -> V_19 )
return;
V_13 -> V_19 ( V_2 -> V_14 , V_17 ) ;
}
static bool
F_12 ( struct V_20 * V_4 , unsigned int V_21 )
{
unsigned int V_22 = V_4 -> V_23 / ( 13 * V_21 ) ;
unsigned int V_24 = V_4 -> V_23 / ( 16 * V_21 ) ;
int V_25 = V_21 - ( V_4 -> V_23 / ( 13 * V_22 ) ) ;
int V_26 = V_21 - ( V_4 -> V_23 / ( 16 * V_24 ) ) ;
if ( V_25 < 0 )
V_25 = - V_25 ;
if ( V_26 < 0 )
V_26 = - V_26 ;
return ( V_25 >= V_26 ) ;
}
static unsigned int
F_13 ( struct V_20 * V_4 , unsigned int V_21 )
{
unsigned int V_27 ;
if ( ! F_12 ( V_4 , V_21 ) )
V_27 = 13 ;
else
V_27 = 16 ;
return V_4 -> V_23 / ( V_27 * V_21 ) ;
}
static void F_14 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
F_16 ( V_2 -> V_4 . V_14 , L_1 , V_2 -> V_4 . line ) ;
F_17 ( V_2 -> V_14 ) ;
V_2 -> V_28 |= V_29 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static void F_20 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
int V_31 ;
F_17 ( V_2 -> V_14 ) ;
if ( V_2 -> V_32 . V_33 & V_34 ) {
if ( V_2 -> V_35 & V_36 ) {
V_2 -> V_35 &= ~ V_36 ;
F_3 ( V_2 , V_37 , V_2 -> V_35 ) ;
V_31 = ( V_2 -> V_32 . V_33 & V_38 ) ? 1 : 0 ;
if ( F_21 ( V_2 -> V_39 ) != V_31 ) {
if ( V_2 -> V_32 . V_40 > 0 )
F_22 ( V_2 -> V_32 . V_40 ) ;
F_23 ( V_2 -> V_39 , V_31 ) ;
}
} else {
V_2 -> V_35 |= V_36 ;
F_3 ( V_2 , V_37 , V_2 -> V_35 ) ;
return;
}
}
if ( V_2 -> V_28 & V_41 ) {
V_2 -> V_28 &= ~ V_41 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
if ( ( V_2 -> V_32 . V_33 & V_34 ) &&
! ( V_2 -> V_32 . V_33 & V_42 ) ) {
V_2 -> V_28 = V_43 | V_44 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static void F_24 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
F_17 ( V_2 -> V_14 ) ;
V_2 -> V_28 &= ~ V_43 ;
V_2 -> V_4 . V_45 &= ~ V_46 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_47 )
{
struct V_48 * V_49 = & V_2 -> V_4 . V_50 -> V_49 ;
int V_51 ;
if ( V_2 -> V_4 . V_52 ) {
F_3 ( V_2 , V_53 , V_2 -> V_4 . V_52 ) ;
V_2 -> V_4 . V_54 . V_55 ++ ;
V_2 -> V_4 . V_52 = 0 ;
return;
}
if ( F_26 ( V_49 ) || F_27 ( & V_2 -> V_4 ) ) {
F_20 ( & V_2 -> V_4 ) ;
return;
}
V_51 = V_2 -> V_4 . V_56 / 4 ;
do {
F_3 ( V_2 , V_53 , V_49 -> V_57 [ V_49 -> V_58 ] ) ;
V_49 -> V_58 = ( V_49 -> V_58 + 1 ) & ( V_59 - 1 ) ;
V_2 -> V_4 . V_54 . V_55 ++ ;
if ( F_26 ( V_49 ) )
break;
} while ( -- V_51 > 0 );
if ( F_28 ( V_49 ) < V_60 ) {
F_29 ( & V_2 -> V_4 . V_61 ) ;
F_30 ( & V_2 -> V_4 ) ;
F_31 ( & V_2 -> V_4 . V_61 ) ;
}
if ( F_26 ( V_49 ) )
F_20 ( & V_2 -> V_4 ) ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_28 & V_41 ) ) {
V_2 -> V_28 |= V_41 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
}
static void F_33 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
int V_31 ;
F_17 ( V_2 -> V_14 ) ;
if ( V_2 -> V_32 . V_33 & V_34 ) {
V_2 -> V_35 &= ~ V_36 ;
F_3 ( V_2 , V_37 , V_2 -> V_35 ) ;
V_31 = ( V_2 -> V_32 . V_33 & V_62 ) ? 1 : 0 ;
if ( F_21 ( V_2 -> V_39 ) != V_31 ) {
F_23 ( V_2 -> V_39 , V_31 ) ;
if ( V_2 -> V_32 . V_63 > 0 )
F_22 ( V_2 -> V_32 . V_63 ) ;
}
}
if ( ( V_2 -> V_32 . V_33 & V_34 ) &&
! ( V_2 -> V_32 . V_33 & V_42 ) )
F_24 ( V_4 ) ;
F_32 ( V_2 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static void F_34 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned long V_33 ;
F_17 ( V_2 -> V_14 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
V_2 -> V_28 &= ~ ( V_43 | V_44 ) ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static void F_37 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned long V_33 ;
F_17 ( V_2 -> V_14 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
V_2 -> V_28 |= V_43 | V_44 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static unsigned int F_38 ( struct V_1 * V_2 )
{
unsigned int V_64 ;
V_64 = F_1 ( V_2 , V_65 ) ;
V_64 |= V_2 -> V_66 ;
V_2 -> V_66 = 0 ;
if ( ( V_64 & V_67 ) == 0 )
return V_64 ;
if ( V_64 & V_67 && V_2 -> V_28 & V_29 &&
V_2 -> V_4 . V_50 != NULL ) {
if ( V_64 & V_68 )
V_2 -> V_4 . V_54 . V_69 ++ ;
if ( V_64 & V_70 )
V_2 -> V_4 . V_54 . V_71 ++ ;
if ( V_64 & V_72 )
F_39
( & V_2 -> V_4 , V_64 & V_73 ) ;
if ( V_64 & V_74 )
F_40
( & V_2 -> V_4 , V_64 & V_75 ) ;
F_41 ( & V_2 -> V_4 . V_50 -> V_4 . V_76 ) ;
}
return V_64 ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned int V_77 ;
unsigned char V_78 = 0 ;
if ( F_43 ( V_47 & V_46 ) )
V_78 = F_1 ( V_2 , V_79 ) ;
V_2 -> V_4 . V_54 . V_80 ++ ;
V_77 = V_81 ;
if ( V_47 & V_82 ) {
V_77 = V_83 ;
V_47 &= ~ ( V_84 | V_85 ) ;
V_2 -> V_4 . V_54 . V_86 ++ ;
if ( F_44 ( & V_2 -> V_4 ) )
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
#ifdef F_45
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_93 -> V_94 ) {
V_47 |= V_2 -> V_95 ;
}
#endif
F_46 ( & V_2 -> V_4 , V_47 , V_91 , 0 , V_77 ) ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned char V_78 = 0 ;
unsigned int V_77 ;
if ( ! ( V_47 & V_46 ) )
return;
V_78 = F_1 ( V_2 , V_79 ) ;
V_77 = V_81 ;
V_2 -> V_4 . V_54 . V_80 ++ ;
if ( F_48 ( & V_2 -> V_4 , V_78 ) )
return;
F_46 ( & V_2 -> V_4 , V_47 , V_91 , V_78 , V_77 ) ;
}
static T_1 F_49 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
unsigned int V_98 , V_47 ;
unsigned int type ;
T_1 V_99 = V_100 ;
int V_101 = 256 ;
F_31 ( & V_2 -> V_4 . V_61 ) ;
F_17 ( V_2 -> V_14 ) ;
do {
V_98 = F_1 ( V_2 , V_102 ) ;
if ( V_98 & V_103 )
break;
V_99 = V_104 ;
V_47 = F_1 ( V_2 , V_105 ) ;
type = V_98 & 0x3e ;
switch ( type ) {
case V_106 :
F_38 ( V_2 ) ;
break;
case V_107 :
F_25 ( V_2 , V_47 ) ;
break;
case V_108 :
case V_109 :
F_47 ( V_2 , V_47 ) ;
break;
case V_110 :
F_42 ( V_2 , V_47 ) ;
break;
case V_111 :
break;
case V_112 :
default:
break;
}
} while ( ! ( V_98 & V_103 ) && V_101 -- );
F_29 ( & V_2 -> V_4 . V_61 ) ;
F_50 ( & V_2 -> V_4 . V_50 -> V_4 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
V_2 -> V_113 = V_114 ;
return V_99 ;
}
static unsigned int F_51 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned long V_33 = 0 ;
unsigned int V_99 = 0 ;
F_17 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_4 . V_14 , L_2 , V_2 -> V_4 . line ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
V_99 = F_1 ( V_2 , V_105 ) & V_115 ? V_116 : 0 ;
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
return V_99 ;
}
static unsigned int F_52 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned int V_64 ;
unsigned int V_99 = 0 ;
F_17 ( V_2 -> V_14 ) ;
V_64 = F_38 ( V_2 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_4 . V_14 , L_3 , V_2 -> V_4 . line ) ;
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
static void F_53 ( struct V_20 * V_4 , unsigned int V_123 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned char V_124 = 0 , V_125 ;
F_16 ( V_2 -> V_4 . V_14 , L_4 , V_2 -> V_4 . line ) ;
if ( V_123 & V_126 )
V_124 |= V_127 ;
if ( V_123 & V_128 )
V_124 |= V_129 ;
if ( V_123 & V_130 )
V_124 |= V_131 ;
if ( V_123 & V_132 )
V_124 |= V_133 ;
if ( V_123 & V_134 )
V_124 |= V_135 ;
F_17 ( V_2 -> V_14 ) ;
V_125 = F_1 ( V_2 , V_136 ) ;
V_125 &= ~ ( V_135 | V_133 | V_131 |
V_129 | V_127 ) ;
V_2 -> V_124 = V_125 | V_124 ;
F_3 ( V_2 , V_136 , V_2 -> V_124 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
if ( F_54 ( V_2 -> V_137 ) &&
! ! ( V_123 & V_128 ) != V_2 -> V_138 ) {
V_2 -> V_138 = ! V_2 -> V_138 ;
if ( F_55 ( V_2 -> V_137 ) )
F_56 ( & V_2 -> V_139 ) ;
else
F_23 ( V_2 -> V_137 ,
V_2 -> V_138 != V_2 -> V_140 ) ;
}
}
static void F_57 ( struct V_20 * V_4 , int V_141 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned long V_33 = 0 ;
F_16 ( V_2 -> V_4 . V_14 , L_5 , V_2 -> V_4 . line ) ;
F_17 ( V_2 -> V_14 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
if ( V_141 == - 1 )
V_2 -> V_142 |= V_143 ;
else
V_2 -> V_142 &= ~ V_143 ;
F_3 ( V_2 , V_144 , V_2 -> V_142 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static int F_58 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned long V_33 = 0 ;
int V_145 ;
V_145 = F_59 ( V_2 -> V_4 . V_96 , F_49 , V_2 -> V_4 . V_146 ,
V_2 -> V_147 , V_2 ) ;
if ( V_145 )
return V_145 ;
if ( V_2 -> V_18 ) {
V_145 = F_59 ( V_2 -> V_18 , F_49 ,
V_2 -> V_4 . V_146 , V_2 -> V_147 , V_2 ) ;
if ( V_145 ) {
F_60 ( V_2 -> V_4 . V_96 , V_2 ) ;
return V_145 ;
}
F_10 ( V_2 -> V_18 ) ;
}
F_16 ( V_2 -> V_4 . V_14 , L_6 , V_2 -> V_4 . line ) ;
F_17 ( V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_136 , V_127 ) ;
( void ) F_1 ( V_2 , V_105 ) ;
if ( F_1 ( V_2 , V_105 ) & V_46 )
( void ) F_1 ( V_2 , V_79 ) ;
( void ) F_1 ( V_2 , V_102 ) ;
( void ) F_1 ( V_2 , V_65 ) ;
F_3 ( V_2 , V_144 , V_148 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
V_2 -> V_4 . V_123 |= V_132 ;
F_53 ( & V_2 -> V_4 , V_2 -> V_4 . V_123 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
V_2 -> V_66 = 0 ;
V_2 -> V_28 = V_43 | V_44 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
V_2 -> V_149 = V_150 ;
if ( V_2 -> V_151 & V_152 )
V_2 -> V_149 |= V_153 ;
F_3 ( V_2 , V_154 , V_2 -> V_149 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
V_2 -> V_113 = V_114 ;
return 0 ;
}
static void F_61 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned long V_33 = 0 ;
F_16 ( V_2 -> V_4 . V_14 , L_7 , V_2 -> V_4 . line ) ;
F_17 ( V_2 -> V_14 ) ;
V_2 -> V_28 = 0 ;
F_3 ( V_2 , V_30 , 0 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
V_2 -> V_4 . V_123 &= ~ V_132 ;
F_53 ( & V_2 -> V_4 , V_2 -> V_4 . V_123 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_3 ( V_2 , V_144 , F_1 ( V_2 , V_144 ) & ~ V_143 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_105 ) & V_46 )
( void ) F_1 ( V_2 , V_79 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
F_60 ( V_2 -> V_4 . V_96 , V_2 ) ;
if ( V_2 -> V_18 )
F_60 ( V_2 -> V_18 , V_2 ) ;
}
static void F_62 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = F_63 ( V_156 , struct V_1 ,
V_139 ) ;
F_64 ( & V_2 -> V_157 , V_2 -> V_158 ) ;
if ( F_54 ( V_2 -> V_137 ) )
F_65 ( V_2 -> V_137 ,
V_2 -> V_138 != V_2 -> V_140 ) ;
}
static void
F_66 ( struct V_20 * V_4 , struct V_159 * V_160 ,
struct V_159 * V_161 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned char V_162 = 0 ;
unsigned long V_33 = 0 ;
unsigned int V_21 , V_163 ;
switch ( V_160 -> V_164 & V_165 ) {
case V_166 :
V_162 = V_167 ;
break;
case V_168 :
V_162 = V_169 ;
break;
case V_170 :
V_162 = V_171 ;
break;
default:
case V_172 :
V_162 = V_148 ;
break;
}
if ( V_160 -> V_164 & V_173 )
V_162 |= V_174 ;
if ( V_160 -> V_164 & V_175 )
V_162 |= V_176 ;
if ( ! ( V_160 -> V_164 & V_177 ) )
V_162 |= V_178 ;
if ( V_160 -> V_164 & V_179 )
V_162 |= V_180 ;
V_21 = F_67 ( V_4 , V_160 , V_161 , 0 , V_4 -> V_23 / 13 ) ;
V_163 = F_13 ( V_4 , V_21 ) ;
V_2 -> V_181 = ( V_182 * V_2 -> V_4 . V_56 ) / ( V_21 / 8 ) ;
V_2 -> V_158 = V_2 -> V_181 ;
F_56 ( & V_2 -> V_139 ) ;
V_2 -> V_183 = V_163 & 0xff ;
V_2 -> V_184 = V_163 >> 8 ;
V_2 -> V_185 = V_186 ;
V_2 -> V_187 = V_188 | V_189 |
V_9 ;
F_17 ( V_2 -> V_14 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_68 ( V_4 , V_160 -> V_164 , V_21 ) ;
V_2 -> V_4 . V_45 = V_91 | V_190 | V_46 ;
if ( V_160 -> V_191 & V_192 )
V_2 -> V_4 . V_45 |= V_84 | V_85 ;
if ( V_160 -> V_191 & ( V_193 | V_194 ) )
V_2 -> V_4 . V_45 |= V_82 ;
V_2 -> V_4 . V_195 = 0 ;
if ( V_160 -> V_191 & V_196 )
V_2 -> V_4 . V_195 |= V_85 | V_84 ;
if ( V_160 -> V_191 & V_197 ) {
V_2 -> V_4 . V_195 |= V_82 ;
if ( V_160 -> V_191 & V_196 )
V_2 -> V_4 . V_195 |= V_91 ;
}
if ( ( V_160 -> V_164 & V_198 ) == 0 )
V_2 -> V_4 . V_195 |= V_46 ;
V_2 -> V_28 &= ~ V_29 ;
if ( F_69 ( & V_2 -> V_4 , V_160 -> V_164 ) )
V_2 -> V_28 |= V_29 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_3 ( V_2 , V_144 , V_162 ) ;
V_2 -> V_142 = V_162 ;
V_2 -> V_35 = 0 ;
F_3 ( V_2 , V_144 , V_199 ) ;
F_3 ( V_2 , V_200 , 0 ) ;
F_3 ( V_2 , V_201 , 0 ) ;
F_3 ( V_2 , V_144 , 0 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
V_2 -> V_203 = F_1 ( V_2 , V_204 ) & ~ V_205 ;
V_2 -> V_203 &= ~ V_206 ;
F_3 ( V_2 , V_204 , V_2 -> V_203 | V_205 ) ;
F_3 ( V_2 , V_144 , V_199 ) ;
V_2 -> V_124 = F_1 ( V_2 , V_136 ) & ~ V_207 ;
F_3 ( V_2 , V_136 , V_2 -> V_124 | V_207 ) ;
V_2 -> V_35 |= V_208 ;
V_2 -> V_187 &= ~ V_209 ;
V_2 -> V_187 &= ~ V_210 ;
V_2 -> V_187 |= V_211 | V_212 |
V_9 ;
F_3 ( V_2 , V_8 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_37 , V_2 -> V_35 ) ;
F_3 ( V_2 , V_144 , V_199 ) ;
F_3 ( V_2 , V_136 , V_2 -> V_124 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_204 , V_2 -> V_203 ) ;
F_3 ( V_2 , V_144 , V_199 ) ;
if ( V_2 -> V_213 & V_214 )
F_70 ( V_2 , V_2 -> V_185 ) ;
else
F_3 ( V_2 , V_215 , V_2 -> V_185 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_204 , V_2 -> V_203 | V_205 ) ;
F_3 ( V_2 , V_144 , 0 ) ;
F_3 ( V_2 , V_30 , 0 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_200 , V_2 -> V_183 ) ;
F_3 ( V_2 , V_201 , V_2 -> V_184 ) ;
F_3 ( V_2 , V_144 , 0 ) ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_204 , V_2 -> V_203 ) ;
F_3 ( V_2 , V_144 , V_162 ) ;
if ( ! F_12 ( V_4 , V_21 ) )
V_2 -> V_185 = V_216 ;
else
V_2 -> V_185 = V_217 ;
if ( V_2 -> V_213 & V_214 )
F_70 ( V_2 , V_2 -> V_185 ) ;
else
F_3 ( V_2 , V_215 , V_2 -> V_185 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_218 , V_160 -> V_219 [ V_220 ] ) ;
F_3 ( V_2 , V_221 , V_160 -> V_219 [ V_222 ] ) ;
F_3 ( V_2 , V_204 , V_2 -> V_203 | V_205 ) ;
F_3 ( V_2 , V_144 , V_199 ) ;
F_3 ( V_2 , V_136 , V_2 -> V_124 | V_207 ) ;
F_3 ( V_2 , V_223 , V_224 ) ;
if ( V_160 -> V_164 & V_225 && V_2 -> V_4 . V_33 & V_226 ) {
V_2 -> V_203 |= V_227 | V_228 ;
V_2 -> V_124 |= V_127 ;
} else {
V_2 -> V_203 &= ~ ( V_227 | V_228 ) ;
}
if ( V_2 -> V_4 . V_33 & V_229 ) {
V_2 -> V_203 &= V_230 ;
if ( V_160 -> V_191 & V_231 )
V_2 -> V_203 |= V_232 ;
if ( V_160 -> V_191 & V_233 )
V_2 -> V_203 |= V_234 ;
if ( V_160 -> V_191 & V_235 )
V_2 -> V_124 |= V_236 ;
else
V_2 -> V_124 &= ~ V_236 ;
}
F_3 ( V_2 , V_136 , V_2 -> V_124 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_204 , V_2 -> V_203 ) ;
F_3 ( V_2 , V_144 , V_2 -> V_142 ) ;
F_53 ( & V_2 -> V_4 , V_2 -> V_4 . V_123 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
F_16 ( V_2 -> V_4 . V_14 , L_8 , V_2 -> V_4 . line ) ;
}
static void
F_71 ( struct V_20 * V_4 , unsigned int V_50 ,
unsigned int V_237 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned char V_203 ;
F_16 ( V_2 -> V_4 . V_14 , L_9 , V_2 -> V_4 . line ) ;
F_17 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
V_203 = F_1 ( V_2 , V_204 ) ;
F_3 ( V_2 , V_204 , V_203 | V_205 ) ;
F_3 ( V_2 , V_144 , 0 ) ;
F_3 ( V_2 , V_30 , ( V_50 != 0 ) ? V_238 : 0 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_204 , V_203 ) ;
F_3 ( V_2 , V_144 , 0 ) ;
if ( ! F_72 ( V_2 -> V_14 ) ) {
if ( ! V_50 )
F_73 ( V_2 -> V_14 ) ;
else
F_74 ( V_2 -> V_14 ) ;
}
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static void F_75 ( struct V_20 * V_4 )
{
F_16 ( V_4 -> V_14 , L_10 ) ;
}
static int F_76 ( struct V_20 * V_4 )
{
F_16 ( V_4 -> V_14 , L_11 ) ;
return 0 ;
}
static void F_77 ( struct V_20 * V_4 , int V_33 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
F_16 ( V_2 -> V_4 . V_14 , L_12 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . type = V_239 ;
V_2 -> V_4 . V_33 |= V_229 | V_226 ;
}
static int
F_78 ( struct V_20 * V_4 , struct V_240 * V_241 )
{
F_16 ( V_4 -> V_14 , L_13 ) ;
return - V_16 ;
}
static const char *
F_79 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
F_16 ( V_2 -> V_4 . V_14 , L_14 , V_2 -> V_4 . line ) ;
return V_2 -> V_147 ;
}
static inline void F_80 ( struct V_1 * V_2 )
{
unsigned int V_64 , V_242 = 10000 ;
do {
V_64 = F_1 ( V_2 , V_105 ) ;
if ( V_64 & V_82 )
V_2 -> V_95 = V_82 ;
if ( -- V_242 == 0 )
break;
F_81 ( 1 ) ;
} while ( ( V_64 & V_243 ) != V_243 );
if ( V_2 -> V_4 . V_33 & V_244 ) {
V_242 = 1000000 ;
for ( V_242 = 1000000 ; V_242 ; V_242 -- ) {
unsigned int V_245 = F_1 ( V_2 , V_65 ) ;
V_2 -> V_66 |= V_245 & V_246 ;
if ( V_245 & V_75 )
break;
F_81 ( 1 ) ;
}
}
}
static void F_82 ( struct V_20 * V_4 , unsigned char V_78 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
F_17 ( V_2 -> V_14 ) ;
F_80 ( V_2 ) ;
F_3 ( V_2 , V_53 , V_78 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static int F_83 ( struct V_20 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned int V_64 ;
F_17 ( V_2 -> V_14 ) ;
V_64 = F_1 ( V_2 , V_105 ) ;
if ( ! ( V_64 & V_46 ) ) {
V_64 = V_247 ;
goto V_248;
}
V_64 = F_1 ( V_2 , V_79 ) ;
V_248:
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
return V_64 ;
}
static void F_84 ( struct V_20 * V_4 , int V_78 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
F_80 ( V_2 ) ;
F_3 ( V_2 , V_53 , V_78 ) ;
}
static void
F_85 ( struct V_249 * V_250 , const char * V_251 ,
unsigned int V_51 )
{
struct V_1 * V_2 = V_252 [ V_250 -> V_94 ] ;
unsigned long V_33 ;
unsigned int V_28 ;
int V_253 = 1 ;
F_17 ( V_2 -> V_14 ) ;
F_86 ( V_33 ) ;
if ( V_2 -> V_4 . V_254 )
V_253 = 0 ;
else if ( V_255 )
V_253 = F_87 ( & V_2 -> V_4 . V_61 ) ;
else
F_31 ( & V_2 -> V_4 . V_61 ) ;
V_28 = F_1 ( V_2 , V_30 ) ;
F_3 ( V_2 , V_30 , 0 ) ;
F_88 ( & V_2 -> V_4 , V_251 , V_51 , F_84 ) ;
F_80 ( V_2 ) ;
F_3 ( V_2 , V_30 , V_28 ) ;
if ( V_2 -> V_66 )
F_38 ( V_2 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
if ( V_253 )
F_29 ( & V_2 -> V_4 . V_61 ) ;
F_89 ( V_33 ) ;
}
static int T_2
F_90 ( struct V_249 * V_250 , char * V_256 )
{
struct V_1 * V_2 ;
int V_21 = 115200 ;
int V_257 = 8 ;
int V_88 = 'n' ;
int V_258 = 'n' ;
if ( V_252 [ V_250 -> V_94 ] == NULL )
return - V_259 ;
V_2 = V_252 [ V_250 -> V_94 ] ;
if ( V_256 )
F_91 ( V_256 , & V_21 , & V_88 , & V_257 , & V_258 ) ;
return F_92 ( & V_2 -> V_4 , V_250 , V_21 , V_88 , V_257 , V_258 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
V_252 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_93 ( struct V_1 * V_2 )
{}
static void
F_94 ( struct V_20 * V_4 , struct V_260 * V_261 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
unsigned long V_33 ;
unsigned int V_27 ;
int V_262 ;
F_17 ( V_2 -> V_14 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_33 ) ;
V_27 = V_2 -> V_28 ;
V_2 -> V_28 = 0 ;
F_3 ( V_2 , V_30 , 0 ) ;
V_2 -> V_32 = * V_261 ;
if ( F_54 ( V_2 -> V_39 ) ) {
V_262 = ( V_2 -> V_32 . V_33 & V_34 ) ?
V_38 : V_62 ;
V_262 = ( V_2 -> V_32 . V_33 & V_262 ) ? 1 : 0 ;
F_23 ( V_2 -> V_39 , V_262 ) ;
} else
V_2 -> V_32 . V_33 &= ~ V_34 ;
V_2 -> V_28 = V_27 ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
if ( ! ( V_2 -> V_32 . V_33 & V_34 ) &&
( V_2 -> V_35 & V_36 ) ) {
V_2 -> V_35 &= ~ V_36 ;
F_3 ( V_2 , V_37 , V_2 -> V_35 ) ;
}
F_36 ( & V_2 -> V_4 . V_61 , V_33 ) ;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
}
static int
F_95 ( struct V_20 * V_4 , unsigned int V_263 , unsigned long V_264 )
{
struct V_260 V_261 ;
switch ( V_263 ) {
case V_265 :
if ( F_96 ( & V_261 , (struct V_260 * ) V_264 ,
sizeof( V_261 ) ) )
return - V_266 ;
F_94 ( V_4 , & V_261 ) ;
break;
case V_267 :
if ( F_97 ( (struct V_260 * ) V_264 ,
& ( F_15 ( V_4 ) -> V_32 ) ,
sizeof( V_261 ) ) )
return - V_266 ;
break;
default:
return - V_268 ;
}
return 0 ;
}
static int F_98 ( struct V_269 * V_14 )
{
struct V_1 * V_2 = F_99 ( V_14 ) ;
V_2 -> V_270 = true ;
return 0 ;
}
static void F_100 ( struct V_269 * V_14 )
{
struct V_1 * V_2 = F_99 ( V_14 ) ;
V_2 -> V_270 = false ;
}
static int F_101 ( struct V_269 * V_14 )
{
struct V_1 * V_2 = F_99 ( V_14 ) ;
F_102 ( & V_271 , & V_2 -> V_4 ) ;
F_103 ( & V_2 -> V_139 ) ;
return 0 ;
}
static int F_104 ( struct V_269 * V_14 )
{
struct V_1 * V_2 = F_99 ( V_14 ) ;
F_105 ( & V_271 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
T_3 V_272 , V_273 ;
T_4 V_274 , V_275 , V_276 ;
V_272 = F_107 ( V_2 -> V_4 . V_6 + ( V_277 << V_2 -> V_4 . V_5 ) ) ;
V_273 = V_272 >> V_278 ;
switch ( V_273 ) {
case 0 :
V_275 = ( V_272 & V_279 ) >>
V_280 ;
V_276 = ( V_272 & V_281 ) ;
break;
case 1 :
V_275 = ( V_272 & V_282 ) >>
V_283 ;
V_276 = ( V_272 & V_284 ) ;
break;
default:
F_108 ( V_2 -> V_14 ,
L_15 ,
V_2 -> V_147 ) ;
V_275 = 0xff ;
V_276 = 0xff ;
}
V_274 = F_109 ( V_275 , V_276 ) ;
switch ( V_274 ) {
case V_285 :
V_2 -> V_213 |= ( V_214 |
V_286 ) ;
break;
case V_287 :
V_2 -> V_213 |= ( V_214 |
V_286 ) ;
V_2 -> V_151 |= V_152 ;
break;
case V_288 :
V_2 -> V_213 |= V_214 ;
V_2 -> V_151 |= V_152 ;
break;
default:
break;
}
}
static struct V_12 * F_110 ( struct V_269 * V_14 )
{
struct V_12 * V_289 ;
V_289 = F_111 ( V_14 , sizeof( * V_289 ) , V_290 ) ;
if ( ! V_289 )
return NULL ;
F_112 ( V_14 -> V_291 , L_16 ,
& V_289 -> V_23 ) ;
return V_289 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_292 * V_293 )
{
struct V_260 * V_261 = & V_2 -> V_32 ;
T_3 V_294 [ 2 ] ;
enum V_295 V_33 ;
int V_99 ;
V_261 -> V_33 = 0 ;
V_2 -> V_39 = - V_16 ;
if ( ! V_293 )
return 0 ;
if ( F_114 ( V_293 , L_17 ) )
V_261 -> V_33 |= V_62 ;
else
V_261 -> V_33 |= V_38 ;
V_2 -> V_39 = F_115 ( V_293 , L_18 , 0 , & V_33 ) ;
if ( F_54 ( V_2 -> V_39 ) ) {
V_99 = F_116 ( V_2 -> V_39 , L_19 ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_117 ( V_2 -> V_39 ,
V_33 & V_38 ) ;
if ( V_99 < 0 )
return V_99 ;
} else if ( V_2 -> V_39 == - V_296 ) {
return - V_296 ;
} else {
V_2 -> V_39 = - V_16 ;
}
if ( F_118 ( V_293 , L_20 ,
V_294 , 2 ) == 0 ) {
V_261 -> V_63 = V_294 [ 0 ] ;
V_261 -> V_40 = V_294 [ 1 ] ;
}
if ( F_114 ( V_293 , L_21 ) )
V_261 -> V_33 |= V_42 ;
if ( F_114 ( V_293 , L_22 ) )
V_261 -> V_33 |= V_34 ;
return 0 ;
}
static int F_119 ( struct V_297 * V_298 )
{
struct V_1 * V_2 ;
struct V_299 * V_300 , * V_96 ;
struct V_12 * V_289 = F_7 ( & V_298 -> V_14 ) ;
int V_99 , V_301 = 0 , V_18 = 0 ;
if ( V_298 -> V_14 . V_291 ) {
V_301 = F_120 ( V_298 -> V_14 . V_291 , 0 ) ;
if ( ! V_301 )
return - V_296 ;
V_18 = F_120 ( V_298 -> V_14 . V_291 , 1 ) ;
V_289 = F_110 ( & V_298 -> V_14 ) ;
V_298 -> V_14 . V_302 = V_289 ;
} else {
V_96 = F_121 ( V_298 , V_303 , 0 ) ;
if ( ! V_96 ) {
F_122 ( & V_298 -> V_14 , L_23 ) ;
return - V_259 ;
}
V_301 = V_96 -> V_304 ;
}
V_300 = F_121 ( V_298 , V_305 , 0 ) ;
if ( ! V_300 ) {
F_122 ( & V_298 -> V_14 , L_24 ) ;
return - V_259 ;
}
if ( ! F_123 ( & V_298 -> V_14 , V_300 -> V_304 , F_124 ( V_300 ) ,
V_298 -> V_14 . V_306 -> V_147 ) ) {
F_122 ( & V_298 -> V_14 , L_25 ) ;
return - V_307 ;
}
if ( F_54 ( V_289 -> V_137 ) &&
V_289 -> V_308 ) {
V_99 = F_116 ( V_289 -> V_137 , L_19 ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_117 ( V_289 -> V_137 ,
V_289 -> V_140 ) ;
if ( V_99 < 0 )
return V_99 ;
}
V_2 = F_111 ( & V_298 -> V_14 , sizeof( * V_2 ) , V_290 ) ;
if ( ! V_2 )
return - V_309 ;
if ( F_54 ( V_289 -> V_137 ) &&
V_289 -> V_308 ) {
V_2 -> V_137 = V_289 -> V_137 ;
V_2 -> V_140 = V_289 -> V_140 ;
} else
V_2 -> V_137 = - V_16 ;
V_2 -> V_138 = 0 ;
V_2 -> V_14 = & V_298 -> V_14 ;
V_2 -> V_4 . V_14 = & V_298 -> V_14 ;
V_2 -> V_4 . type = V_239 ;
V_2 -> V_4 . V_310 = V_311 ;
V_2 -> V_4 . V_96 = V_301 ;
V_2 -> V_18 = V_18 ;
if ( ! V_2 -> V_18 )
F_125 ( V_2 -> V_4 . V_14 , L_26 ,
V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_56 = 64 ;
V_2 -> V_4 . V_312 = & V_313 ;
if ( V_298 -> V_14 . V_291 )
V_2 -> V_4 . line = F_126 ( V_298 -> V_14 . V_291 , L_27 ) ;
else
V_2 -> V_4 . line = V_298 -> V_314 ;
if ( V_2 -> V_4 . line < 0 ) {
F_122 ( & V_298 -> V_14 , L_28 ,
V_2 -> V_4 . line ) ;
V_99 = - V_259 ;
goto V_315;
}
V_99 = F_113 ( V_2 , V_298 -> V_14 . V_291 ) ;
if ( V_99 < 0 )
goto V_316;
sprintf ( V_2 -> V_147 , L_29 , V_2 -> V_4 . line ) ;
V_2 -> V_4 . V_317 = V_300 -> V_304 ;
V_2 -> V_4 . V_6 = F_127 ( & V_298 -> V_14 , V_300 -> V_304 ,
F_124 ( V_300 ) ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_122 ( & V_298 -> V_14 , L_30 ) ;
V_99 = - V_309 ;
goto V_318;
}
V_2 -> V_4 . V_33 = V_289 -> V_33 ;
V_2 -> V_4 . V_23 = V_289 -> V_23 ;
if ( ! V_2 -> V_4 . V_23 ) {
V_2 -> V_4 . V_23 = V_319 ;
F_108 ( & V_298 -> V_14 ,
L_31 ,
V_319 ) ;
}
V_2 -> V_158 = V_320 ;
V_2 -> V_181 = V_320 ;
F_128 ( & V_2 -> V_157 ,
V_321 , V_2 -> V_158 ) ;
V_322 = F_129 ( V_2 -> V_147 ) ;
F_130 ( & V_2 -> V_139 , F_62 ) ;
F_131 ( V_298 , V_2 ) ;
if ( V_289 -> V_323 == 0 )
V_289 -> V_323 = - 1 ;
F_132 ( V_2 -> V_14 , true ) ;
F_133 ( & V_298 -> V_14 ) ;
F_134 ( & V_298 -> V_14 ,
V_289 -> V_323 ) ;
F_135 ( & V_298 -> V_14 ) ;
F_136 ( & V_298 -> V_14 ) ;
F_17 ( & V_298 -> V_14 ) ;
F_106 ( V_2 ) ;
V_324 [ V_2 -> V_4 . line ] = V_2 ;
F_93 ( V_2 ) ;
V_99 = F_137 ( & V_271 , & V_2 -> V_4 ) ;
if ( V_99 != 0 )
goto V_325;
F_18 ( V_2 -> V_14 ) ;
F_19 ( V_2 -> V_14 ) ;
return 0 ;
V_325:
F_138 ( & V_298 -> V_14 ) ;
F_139 ( & V_298 -> V_14 ) ;
V_318:
V_316:
V_315:
F_122 ( & V_298 -> V_14 , L_32 ,
V_298 -> V_314 , V_326 , V_99 ) ;
return V_99 ;
}
static int F_140 ( struct V_297 * V_14 )
{
struct V_1 * V_2 = F_141 ( V_14 ) ;
F_142 ( V_2 -> V_14 ) ;
F_139 ( V_2 -> V_14 ) ;
F_143 ( & V_271 , & V_2 -> V_4 ) ;
F_144 ( & V_2 -> V_157 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , T_5 V_185 )
{
T_5 V_327 = 255 ;
F_3 ( V_2 , V_215 , V_185 ) ;
F_81 ( 2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_187 | V_11 |
V_10 ) ;
while ( V_190 != ( F_1 ( V_2 , V_105 ) &
( V_190 | V_46 ) ) ) {
V_327 -- ;
if ( ! V_327 ) {
F_145 ( V_2 -> V_14 , L_33 ,
F_1 ( V_2 , V_105 ) ) ;
break;
}
F_81 ( 1 ) ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
if ( V_2 -> V_213 & V_214 )
F_70 ( V_2 , V_186 ) ;
else
F_3 ( V_2 , V_215 , V_186 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_204 , V_205 ) ;
F_3 ( V_2 , V_144 , 0x0 ) ;
F_3 ( V_2 , V_30 , 0x0 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_200 , V_2 -> V_183 ) ;
F_3 ( V_2 , V_201 , V_2 -> V_184 ) ;
F_3 ( V_2 , V_144 , 0x0 ) ;
F_3 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_187 ) ;
F_3 ( V_2 , V_144 , V_199 ) ;
F_3 ( V_2 , V_136 , V_2 -> V_124 ) ;
F_3 ( V_2 , V_144 , V_202 ) ;
F_3 ( V_2 , V_37 , V_2 -> V_35 ) ;
F_3 ( V_2 , V_204 , V_2 -> V_203 ) ;
F_3 ( V_2 , V_144 , V_2 -> V_142 ) ;
if ( V_2 -> V_213 & V_214 )
F_70 ( V_2 , V_2 -> V_185 ) ;
else
F_3 ( V_2 , V_215 , V_2 -> V_185 ) ;
F_3 ( V_2 , V_154 , V_2 -> V_149 ) ;
}
static int F_147 ( struct V_269 * V_14 )
{
struct V_1 * V_2 = F_99 ( V_14 ) ;
if ( ! V_2 )
return - V_16 ;
if ( V_2 -> V_270 && ! V_328 &&
F_148 ( & V_2 -> V_4 ) )
return - V_307 ;
V_2 -> V_329 = F_6 ( V_2 ) ;
if ( F_72 ( V_14 ) ) {
if ( ! V_2 -> V_330 ) {
F_11 ( V_2 , true ) ;
V_2 -> V_330 = true ;
}
} else {
if ( V_2 -> V_330 ) {
F_11 ( V_2 , false ) ;
V_2 -> V_330 = false ;
}
}
V_2 -> V_158 = V_320 ;
F_56 ( & V_2 -> V_139 ) ;
return 0 ;
}
static int F_149 ( struct V_269 * V_14 )
{
struct V_1 * V_2 = F_99 ( V_14 ) ;
int V_331 = F_6 ( V_2 ) ;
if ( V_331 < 0 ) {
F_16 ( V_14 , L_34 ,
V_331 ) ;
F_146 ( V_2 ) ;
} else if ( V_2 -> V_329 != V_331 ) {
F_146 ( V_2 ) ;
}
V_2 -> V_158 = V_2 -> V_181 ;
F_56 ( & V_2 -> V_139 ) ;
return 0 ;
}
static int T_2 F_150 ( void )
{
int V_99 ;
V_99 = F_151 ( & V_271 ) ;
if ( V_99 != 0 )
return V_99 ;
V_99 = F_152 ( & V_332 ) ;
if ( V_99 != 0 )
F_153 ( & V_271 ) ;
return V_99 ;
}
static void T_6 F_154 ( void )
{
F_155 ( & V_332 ) ;
F_153 ( & V_271 ) ;
}
