static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == & V_6 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 -> V_7 & V_8 ) ;
}
static inline void F_5 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 , int V_13 )
{
void T_2 * V_14 = V_10 -> V_15 + ( V_13 & ~ 0x3 ) ;
T_1 V_16 = ( V_13 & 0x3 ) * 8 ;
F_6 ( ( ( F_7 ( V_14 ) & ~ ( V_11 << V_16 ) ) | ( V_12 << V_16 ) ) , V_14 ) ;
}
static T_1 F_8 ( struct V_9 * V_10 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_12 = F_7 ( V_10 -> V_15 + V_13 ) ;
if ( F_10 ( V_13 == V_21 ) ) {
T_1 V_22 = V_12 ;
V_12 = V_22 & 0x000FFFFF ;
V_12 |= ( V_22 & 0x0F000000 ) >> 4 ;
V_12 |= ( V_22 & 0x00800000 ) << 1 ;
}
if ( F_10 ( V_13 == V_23 ) ) {
if ( V_19 -> V_3 -> V_7 & V_24 )
V_12 &= 0xffff0000 ;
if ( V_12 & V_25 ) {
V_12 &= ~ V_25 ;
V_12 |= V_26 ;
}
}
if ( F_10 ( V_13 == V_27 ) ) {
if ( F_4 ( V_19 ) ) {
if ( V_19 -> V_3 -> V_7 & V_24 )
V_12 = F_7 ( V_10 -> V_15 + V_23 ) & 0xFFFF ;
else
V_12 = V_28 | V_29
| V_30
| V_31 ;
}
}
if ( F_10 ( V_13 == V_32 ) && F_4 ( V_19 ) ) {
V_12 = 0 ;
V_12 |= 0xFF << V_33 ;
V_12 |= 0xFF << V_34 ;
V_12 |= 0xFF << V_35 ;
}
if ( F_10 ( V_13 == V_36 ) ) {
if ( V_12 & V_37 ) {
V_12 &= ~ V_37 ;
V_12 |= V_38 ;
}
if ( ( V_19 -> V_39 == V_40 ) &&
( ( V_12 & V_41 ) == V_41 ) ) {
V_12 &= ~ V_41 ;
F_6 ( V_41 , V_10 -> V_15 +
V_36 ) ;
V_19 -> V_39 = V_42 ;
}
}
return V_12 ;
}
static void F_11 ( struct V_9 * V_10 , T_1 V_12 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_2 ;
if ( F_10 ( V_13 == V_43 || V_13 == V_44 ) ) {
if ( V_12 & V_45 ) {
V_2 = F_7 ( V_10 -> V_15 + V_46 ) ;
V_2 &= ~ V_47 ;
F_6 ( V_2 , V_10 -> V_15 + V_46 ) ;
V_2 |= V_47 ;
F_6 ( V_2 , V_10 -> V_15 + V_46 ) ;
}
}
if ( F_10 ( ( V_19 -> V_3 -> V_7 & V_48 )
&& ( V_13 == V_36 )
&& ( V_12 & V_49 ) ) ) {
T_1 V_50 ;
V_50 = F_7 ( V_10 -> V_15 + V_51 ) ;
V_50 &= ~ V_52 ;
F_6 ( V_50 , V_10 -> V_15 + V_51 ) ;
if ( V_19 -> V_39 == V_53 )
{
V_2 = V_54 << 24 |
V_55 << 16 ;
F_6 ( V_2 , V_10 -> V_15 + V_56 ) ;
V_19 -> V_39 = V_40 ;
}
}
if ( F_10 ( V_13 == V_43 || V_13 == V_44 ) ) {
if ( V_12 & V_38 ) {
V_12 &= ~ V_38 ;
V_12 |= V_37 ;
}
}
F_6 ( V_12 , V_10 -> V_15 + V_13 ) ;
}
static T_3 F_12 ( struct V_9 * V_10 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_3 V_57 = 0 ;
T_1 V_12 ;
if ( F_10 ( V_13 == V_58 ) ) {
V_13 ^= 2 ;
if ( F_4 ( V_19 ) ) {
return V_59 ;
}
}
if ( F_10 ( V_13 == V_60 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_51 ) ;
if ( V_12 & V_61 )
V_57 |= V_62 ;
if ( F_4 ( V_19 ) ) {
if ( V_19 -> V_3 -> V_7 & V_63 )
V_12 = F_7 ( V_10 -> V_15 + V_64 ) ;
else if ( V_19 -> V_3 -> V_7 & V_65 )
V_12 = F_7 ( V_10 -> V_15 + V_66 ) ;
}
if ( V_12 & V_67 )
V_57 |= V_68 ;
if ( V_12 & V_69 )
V_57 |= V_70 ;
V_57 |= ( V_19 -> V_71 & V_72 ) ;
V_57 &= ~ V_73 ;
return V_57 ;
}
return F_13 ( V_10 -> V_15 + V_13 ) ;
}
static void F_14 ( struct V_9 * V_10 , T_3 V_12 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_74 = 0 ;
switch ( V_13 ) {
case V_75 :
V_74 = F_7 ( V_10 -> V_15 + V_51 ) ;
if ( V_12 & V_76 )
V_74 |= V_77 ;
else
V_74 &= ~ V_77 ;
F_6 ( V_74 , V_10 -> V_15 + V_51 ) ;
return;
case V_60 :
V_74 = F_7 ( V_10 -> V_15 + V_51 ) ;
if ( V_12 & V_62 )
V_74 |= V_61 ;
else
V_74 &= ~ V_61 ;
F_6 ( V_74 , V_10 -> V_15 + V_51 ) ;
V_19 -> V_71 = V_12 & V_72 ;
if ( V_19 -> V_3 -> V_7 & V_63 ) {
V_74 = F_7 ( V_10 -> V_15 + V_64 ) ;
if ( V_12 & V_70 )
V_74 |= V_69 ;
else
V_74 &= ~ V_69 ;
F_6 ( V_74 , V_10 -> V_15 + V_64 ) ;
} else if ( V_19 -> V_3 -> V_7 & V_65 ) {
T_1 V_50 = F_7 ( V_10 -> V_15 + V_66 ) ;
T_1 V_78 = F_7 ( V_10 -> V_15 + V_64 ) ;
V_74 = F_7 ( V_10 -> V_15 + V_79 ) ;
if ( V_12 & V_68 ) {
V_74 |= V_80 |
V_81 ;
V_50 |= V_67 ;
V_78 |= V_82 ;
} else {
V_74 &= ~ V_80 ;
V_50 &= ~ V_67 ;
V_78 &= ~ V_82 ;
}
if ( V_12 & V_70 )
V_50 |= V_69 ;
else
V_50 &= ~ V_69 ;
F_6 ( V_74 , V_10 -> V_15 + V_79 ) ;
F_6 ( V_50 , V_10 -> V_15 + V_66 ) ;
F_6 ( V_78 , V_10 -> V_15 + V_64 ) ;
}
return;
case V_56 :
if ( ( V_19 -> V_3 -> V_7 & V_48 )
&& ( V_10 -> V_83 -> V_84 == V_85 )
&& ( V_10 -> V_83 -> V_2 -> V_86 > 1 )
&& ( V_10 -> V_83 -> V_2 -> V_7 & V_87 ) ) {
T_1 V_50 ;
V_50 = F_7 ( V_10 -> V_15 + V_51 ) ;
V_50 |= V_52 ;
F_6 ( V_50 , V_10 -> V_15 + V_51 ) ;
}
if ( F_4 ( V_19 ) ) {
T_1 V_78 = F_7 ( V_10 -> V_15 + V_64 ) ;
if ( V_12 & V_88 ) {
V_12 &= ~ V_88 ;
V_12 |= V_89 ;
}
V_78 = V_12 | ( V_78 & ~ V_90 ) ;
F_6 ( V_78 , V_10 -> V_15 + V_64 ) ;
} else {
V_19 -> V_91 = V_12 ;
}
return;
case V_92 :
if ( V_10 -> V_83 -> V_84 == V_54 )
V_12 |= V_55 ;
if ( ( V_10 -> V_83 -> V_84 == V_93 ) &&
( V_19 -> V_3 -> V_7 & V_48 ) )
V_19 -> V_39 = V_53 ;
if ( F_4 ( V_19 ) )
F_6 ( V_12 << 16 ,
V_10 -> V_15 + V_56 ) ;
else
F_6 ( V_12 << 16 | V_19 -> V_91 ,
V_10 -> V_15 + V_56 ) ;
return;
case V_94 :
V_12 &= ~ F_15 ( 0x7 , 0 ) ;
break;
}
F_5 ( V_10 , 0xffff , V_12 , V_13 ) ;
}
static void F_16 ( struct V_9 * V_10 , T_4 V_12 , int V_13 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_74 ;
T_1 V_11 ;
switch ( V_13 ) {
case V_95 :
return;
case V_46 :
V_74 = V_12 & V_96 ;
V_74 |= V_97 ;
if ( ! F_1 ( V_19 ) ) {
V_74 |= ( V_12 & V_98 ) << 5 ;
}
V_11 = 0xffff & ~ ( V_99 | V_47 ) ;
F_5 ( V_10 , V_11 , V_74 , V_13 ) ;
return;
}
F_5 ( V_10 , 0xff , V_12 , V_13 ) ;
if ( ( V_13 == V_100 ) && ( V_12 & 1 ) ) {
F_5 ( V_10 , 0x7 , 0x7 , V_101 ) ;
if ( F_4 ( V_19 ) ) {
F_6 ( 0 , V_10 -> V_15 + V_64 ) ;
V_19 -> V_102 = 0 ;
}
}
}
static unsigned int F_17 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_103 * V_104 = & V_19 -> V_104 ;
T_1 V_105 = F_18 ( V_18 -> V_106 ) ;
if ( V_104 -> V_107 && ( V_104 -> V_107 < V_105 ) )
return V_104 -> V_107 ;
else
return V_105 ;
}
static unsigned int F_19 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
return F_18 ( V_18 -> V_106 ) / 256 / 16 ;
}
static inline void F_20 ( struct V_9 * V_10 ,
unsigned int clock )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
unsigned int V_108 = F_18 ( V_18 -> V_106 ) ;
int V_109 = 2 ;
int div = 1 ;
T_1 V_110 , V_12 ;
if ( clock == 0 ) {
if ( F_4 ( V_19 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_51 ) ;
F_6 ( V_12 & ~ V_77 ,
V_10 -> V_15 + V_51 ) ;
}
goto V_111;
}
if ( F_4 ( V_19 ) && ! V_19 -> V_102 )
V_109 = 1 ;
V_110 = F_21 ( V_10 , V_101 ) ;
V_110 &= ~ ( V_112 | V_113 | V_114
| V_115 ) ;
F_22 ( V_10 , V_110 , V_101 ) ;
while ( V_108 / V_109 / 16 > clock && V_109 < 256 )
V_109 *= 2 ;
while ( V_108 / V_109 / div > clock && div < 16 )
div ++ ;
V_10 -> V_116 -> V_117 = V_108 / V_109 / div ;
F_23 ( F_24 ( V_10 -> V_116 ) , L_1 ,
clock , V_10 -> V_116 -> V_117 ) ;
if ( V_19 -> V_102 )
V_109 >>= 2 ;
else
V_109 >>= 1 ;
div -- ;
V_110 = F_21 ( V_10 , V_101 ) ;
V_110 |= ( V_112 | V_113 | V_114
| ( div << V_118 )
| ( V_109 << V_119 ) ) ;
F_22 ( V_10 , V_110 , V_101 ) ;
if ( F_4 ( V_19 ) ) {
V_12 = F_7 ( V_10 -> V_15 + V_51 ) ;
F_6 ( V_12 | V_77 ,
V_10 -> V_15 + V_51 ) ;
}
F_25 ( 1 ) ;
V_111:
V_10 -> clock = clock ;
}
static unsigned int F_26 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_103 * V_104 = & V_19 -> V_104 ;
switch ( V_104 -> V_120 ) {
case V_121 :
return F_27 ( V_10 -> V_116 ) ;
case V_122 :
return ! ( F_7 ( V_10 -> V_15 + V_21 ) &
V_123 ) ;
case V_124 :
break;
}
return - V_125 ;
}
static int F_28 ( struct V_9 * V_10 , int V_126 )
{
T_1 V_127 ;
switch ( V_126 ) {
case V_128 :
V_127 = V_129 ;
break;
case V_130 :
V_127 = V_131 ;
break;
default:
V_127 = 0 ;
break;
}
F_5 ( V_10 , V_99 , V_127 ,
V_46 ) ;
return 0 ;
}
static void F_29 ( struct V_9 * V_10 , T_1 V_12 )
{
T_1 V_13 ;
F_25 ( 1 ) ;
V_13 = F_7 ( V_10 -> V_15 + V_64 ) ;
V_13 |= V_67 | V_69 |
V_82 ;
F_6 ( V_13 , V_10 -> V_15 + V_64 ) ;
F_6 ( V_12 << 8 , V_10 -> V_15 + V_132 ) ;
F_23 ( F_24 ( V_10 -> V_116 ) ,
L_2 ,
V_12 , F_7 ( V_10 -> V_15 + V_132 ) ) ;
}
static void F_30 ( struct V_133 * V_134 )
{
F_31 ( & V_134 -> V_135 ) ;
}
static int F_32 ( struct V_9 * V_10 , T_1 V_84 )
{
struct V_136 V_83 = { 0 } ;
struct V_133 V_134 = { 0 } ;
struct V_137 V_2 = { 0 } ;
struct V_138 V_139 ;
char V_140 [ V_141 ] ;
V_83 . V_84 = V_84 ;
V_83 . V_142 = 0 ;
V_83 . V_7 = V_143 | V_144 ;
V_2 . V_145 = V_141 ;
V_2 . V_86 = 1 ;
V_2 . V_7 = V_87 ;
V_2 . V_139 = & V_139 ;
V_2 . V_146 = 1 ;
F_33 ( & V_139 , V_140 , sizeof( V_140 ) ) ;
V_134 . V_83 = & V_83 ;
V_134 . V_83 -> V_134 = & V_134 ;
V_134 . V_2 = & V_2 ;
V_134 . V_2 -> V_134 = & V_134 ;
V_134 . V_83 -> V_2 = V_134 . V_2 ;
V_134 . V_147 = F_30 ;
F_34 ( & ( V_134 . V_135 ) ) ;
F_35 ( V_10 -> V_148 ) ;
F_36 ( & V_10 -> V_149 ) ;
V_10 -> V_134 = & V_134 ;
F_37 ( V_10 , V_134 . V_83 ) ;
F_38 ( & V_10 -> V_149 ) ;
F_39 ( V_10 -> V_148 ) ;
F_40 ( & V_134 . V_135 ) ;
if ( V_83 . error )
return V_83 . error ;
if ( V_2 . error )
return V_2 . error ;
return 0 ;
}
static void F_41 ( struct V_9 * V_10 )
{
T_1 V_13 ;
V_13 = F_7 ( V_10 -> V_15 + V_64 ) ;
V_13 &= ~ V_67 ;
F_6 ( V_13 , V_10 -> V_15 + V_64 ) ;
}
static int F_42 ( struct V_9 * V_10 , T_1 V_84 )
{
int V_150 , V_151 , V_152 , V_57 ;
V_150 = V_153 ;
while ( V_150 < V_154 ) {
F_29 ( V_10 , V_150 ) ;
if ( ! F_32 ( V_10 , V_84 ) )
break;
V_150 += V_155 ;
}
V_151 = V_150 + V_155 ;
while ( V_151 < V_154 ) {
F_29 ( V_10 , V_151 ) ;
if ( F_32 ( V_10 , V_84 ) ) {
V_151 -= V_155 ;
break;
}
V_151 += V_155 ;
}
V_152 = ( V_150 + V_151 ) / 2 ;
F_29 ( V_10 , V_152 ) ;
V_57 = F_32 ( V_10 , V_84 ) ;
F_41 ( V_10 ) ;
F_23 ( F_24 ( V_10 -> V_116 ) , L_3 ,
V_57 ? L_4 : L_5 , V_152 , V_57 ) ;
return V_57 ;
}
static int F_43 ( struct V_9 * V_10 ,
unsigned int V_156 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_157 * V_158 ;
F_23 ( F_24 ( V_10 -> V_116 ) , L_6 , V_156 ) ;
if ( F_44 ( V_19 -> V_158 ) ||
F_44 ( V_19 -> V_159 ) ||
F_44 ( V_19 -> V_160 ) ||
F_44 ( V_19 -> V_161 ) )
return - V_162 ;
switch ( V_156 ) {
case V_163 :
V_158 = V_19 -> V_160 ;
break;
case V_164 :
V_158 = V_19 -> V_161 ;
break;
default:
V_158 = V_19 -> V_159 ;
}
return F_45 ( V_19 -> V_158 , V_158 ) ;
}
static int F_46 ( struct V_9 * V_10 , unsigned int V_156 )
{
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_103 * V_104 = & V_19 -> V_104 ;
switch ( V_156 ) {
case V_165 :
V_19 -> V_71 = V_166 ;
break;
case V_167 :
V_19 -> V_71 = V_168 ;
break;
case V_163 :
V_19 -> V_71 = V_169 ;
break;
case V_164 :
V_19 -> V_71 = V_170 ;
break;
case V_171 :
V_19 -> V_71 = V_172 ;
F_6 ( F_7 ( V_10 -> V_15 + V_64 ) |
V_173 ,
V_10 -> V_15 + V_64 ) ;
V_19 -> V_102 = 1 ;
if ( V_104 -> V_174 ) {
T_1 V_50 ;
V_50 = V_104 -> V_174 <<
V_175 |
( 1 << V_176 ) ;
if ( F_2 ( V_19 ) )
V_50 <<= 1 ;
F_6 ( V_50 , V_10 -> V_15 + V_177 ) ;
}
break;
}
return F_43 ( V_10 , V_156 ) ;
}
static int
F_47 ( struct V_178 * V_179 ,
struct V_103 * V_104 )
{
struct V_180 * V_181 = V_179 -> V_182 . V_183 ;
if ( ! V_181 )
return - V_184 ;
if ( F_48 ( V_181 , L_7 , NULL ) )
V_104 -> V_185 = V_186 ;
if ( F_48 ( V_181 , L_8 , NULL ) )
V_104 -> V_185 = V_187 ;
if ( F_48 ( V_181 , L_9 , NULL ) )
V_104 -> V_120 = V_122 ;
V_104 -> V_188 = F_49 ( V_181 , L_10 , 0 ) ;
if ( F_50 ( V_104 -> V_188 ) )
V_104 -> V_185 = V_189 ;
V_104 -> V_190 = F_49 ( V_181 , L_11 , 0 ) ;
if ( F_50 ( V_104 -> V_190 ) )
V_104 -> V_120 = V_121 ;
F_51 ( V_181 , L_12 , & V_104 -> V_191 ) ;
F_51 ( V_181 , L_13 , & V_104 -> V_107 ) ;
if ( F_52 ( V_181 , L_14 , NULL ) )
V_104 -> V_192 = false ;
else
V_104 -> V_192 = true ;
if ( F_51 ( V_181 , L_15 , & V_104 -> V_174 ) )
V_104 -> V_174 = 0 ;
return 0 ;
}
static inline int
F_47 ( struct V_178 * V_179 ,
struct V_103 * V_104 )
{
return - V_184 ;
}
static int F_53 ( struct V_178 * V_179 )
{
const struct V_193 * V_194 =
F_54 ( V_195 , & V_179 -> V_182 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 ;
struct V_103 * V_104 ;
int V_196 ;
struct V_1 * V_19 ;
V_10 = F_55 ( V_179 , & V_197 , 0 ) ;
if ( F_44 ( V_10 ) )
return F_56 ( V_10 ) ;
V_18 = F_9 ( V_10 ) ;
V_19 = F_57 ( & V_179 -> V_182 , sizeof( * V_19 ) , V_198 ) ;
if ( ! V_19 ) {
V_196 = - V_199 ;
goto V_200;
}
V_19 -> V_3 = V_194 ? V_194 -> V_2 : (struct V_201 * )
V_179 -> V_202 -> V_203 ;
V_18 -> V_20 = V_19 ;
V_19 -> V_204 = F_58 ( & V_179 -> V_182 , L_16 ) ;
if ( F_44 ( V_19 -> V_204 ) ) {
V_196 = F_56 ( V_19 -> V_204 ) ;
goto V_200;
}
V_19 -> V_205 = F_58 ( & V_179 -> V_182 , L_17 ) ;
if ( F_44 ( V_19 -> V_205 ) ) {
V_196 = F_56 ( V_19 -> V_205 ) ;
goto V_200;
}
V_19 -> V_206 = F_58 ( & V_179 -> V_182 , L_18 ) ;
if ( F_44 ( V_19 -> V_206 ) ) {
V_196 = F_56 ( V_19 -> V_206 ) ;
goto V_200;
}
V_18 -> V_106 = V_19 -> V_206 ;
F_59 ( V_19 -> V_206 ) ;
F_59 ( V_19 -> V_204 ) ;
F_59 ( V_19 -> V_205 ) ;
V_19 -> V_158 = F_60 ( & V_179 -> V_182 ) ;
if ( F_44 ( V_19 -> V_158 ) ) {
V_196 = F_56 ( V_19 -> V_158 ) ;
goto V_207;
}
V_19 -> V_159 = F_61 ( V_19 -> V_158 ,
V_208 ) ;
if ( F_44 ( V_19 -> V_159 ) ) {
V_196 = F_56 ( V_19 -> V_159 ) ;
F_62 ( F_24 ( V_10 -> V_116 ) , L_19 ) ;
goto V_207;
}
V_10 -> V_209 |= V_210 ;
if ( V_19 -> V_3 -> V_7 & V_211 )
V_10 -> V_209 |= V_212
| V_213 ;
if ( F_4 ( V_19 ) ) {
F_6 ( 0x08100810 , V_10 -> V_15 + V_214 ) ;
V_10 -> V_215 |= V_216 ;
}
if ( V_19 -> V_3 -> V_7 & V_63 )
V_217 . V_218 =
F_42 ;
V_104 = & V_19 -> V_104 ;
if ( F_47 ( V_179 , V_104 ) < 0 ) {
if ( ! V_10 -> V_116 -> V_219 -> V_220 ) {
F_62 ( F_24 ( V_10 -> V_116 ) , L_20 ) ;
V_196 = - V_162 ;
goto V_207;
}
V_19 -> V_104 = * ( (struct V_103 * )
V_10 -> V_116 -> V_219 -> V_220 ) ;
}
if ( V_104 -> V_120 == V_121 ) {
V_196 = F_63 ( V_10 -> V_116 , V_104 -> V_190 ) ;
if ( V_196 ) {
F_62 ( F_24 ( V_10 -> V_116 ) ,
L_21 ) ;
goto V_207;
}
V_10 -> V_116 -> V_221 |= V_222 ;
}
switch ( V_104 -> V_185 ) {
case V_189 :
V_196 = F_64 ( V_10 -> V_116 , V_104 -> V_188 , 0 ) ;
if ( V_196 ) {
F_62 ( F_24 ( V_10 -> V_116 ) ,
L_22 ) ;
goto V_207;
}
case V_187 :
V_10 -> V_209 &= ~ V_223 ;
break;
case V_186 :
V_10 -> V_116 -> V_224 = V_225 ;
break;
case V_226 :
break;
}
switch ( V_104 -> V_191 ) {
case 8 :
V_10 -> V_116 -> V_224 |= V_227 | V_228 ;
break;
case 4 :
V_10 -> V_116 -> V_224 |= V_228 ;
break;
case 1 :
default:
V_10 -> V_209 |= V_229 ;
break;
}
if ( ( V_104 -> V_192 ) && F_4 ( V_19 ) ) {
V_19 -> V_160 = F_61 ( V_19 -> V_158 ,
V_230 ) ;
V_19 -> V_161 = F_61 ( V_19 -> V_158 ,
V_231 ) ;
if ( F_44 ( V_19 -> V_160 ) ||
F_44 ( V_19 -> V_161 ) ) {
F_65 ( F_24 ( V_10 -> V_116 ) ,
L_23 ) ;
V_10 -> V_215 |= V_232 ;
}
} else {
V_10 -> V_215 |= V_232 ;
}
V_196 = F_66 ( V_10 ) ;
if ( V_196 )
goto V_207;
return 0 ;
V_207:
F_67 ( V_19 -> V_206 ) ;
F_67 ( V_19 -> V_204 ) ;
F_67 ( V_19 -> V_205 ) ;
V_200:
F_68 ( V_179 ) ;
return V_196 ;
}
static int F_69 ( struct V_178 * V_179 )
{
struct V_9 * V_10 = F_70 ( V_179 ) ;
struct V_17 * V_18 = F_9 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
int V_233 = ( F_7 ( V_10 -> V_15 + V_36 ) == 0xffffffff ) ;
F_71 ( V_10 , V_233 ) ;
F_67 ( V_19 -> V_206 ) ;
F_67 ( V_19 -> V_204 ) ;
F_67 ( V_19 -> V_205 ) ;
F_68 ( V_179 ) ;
return 0 ;
}
