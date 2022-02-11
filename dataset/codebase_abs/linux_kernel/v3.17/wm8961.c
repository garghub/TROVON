static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_4 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_6 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_5 :
case V_58 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_59 * V_60 ,
struct V_61 * V_62 , int V_63 )
{
struct V_64 * V_65 = V_60 -> V_65 ;
T_1 V_66 = F_4 ( V_65 , V_48 ) ;
T_1 V_67 = F_4 ( V_65 , V_50 ) ;
T_1 V_68 = F_4 ( V_65 , V_29 ) ;
T_1 V_69 = F_4 ( V_65 , V_6 ) ;
int V_70 = 500 ;
if ( V_63 & V_71 ) {
V_66 &= ~ ( V_72 | V_73 ) ;
F_5 ( V_65 , V_48 , V_66 ) ;
V_67 |= V_74 ;
F_5 ( V_65 , V_50 , V_67 ) ;
F_6 ( 5 ) ;
V_68 |= V_75 | V_76 ;
F_5 ( V_65 , V_29 , V_68 ) ;
V_66 |= V_77 | V_78 ;
F_5 ( V_65 , V_48 , V_66 ) ;
V_66 |= V_79 | V_80 ;
F_5 ( V_65 , V_48 , V_66 ) ;
V_69 |=
V_81 | V_82 |
V_83 | V_84 ;
F_7 ( V_65 -> V_2 , L_1 ) ;
F_5 ( V_65 , V_6 , V_69 ) ;
do {
F_8 ( 1 ) ;
V_69 = F_4 ( V_65 , V_6 ) ;
} while ( -- V_70 &&
V_69 & ( V_82 |
V_84 ) );
if ( V_69 & ( V_82 |
V_84 ) )
F_9 ( V_65 -> V_2 , L_2 ) ;
else
F_7 ( V_65 -> V_2 , L_3 ) ;
V_66 |= V_85 | V_86 ;
F_5 ( V_65 , V_48 , V_66 ) ;
V_66 |= V_72 | V_73 ;
F_5 ( V_65 , V_48 , V_66 ) ;
}
if ( V_63 & V_87 ) {
V_66 &= ~ ( V_72 | V_73 ) ;
F_5 ( V_65 , V_48 , V_66 ) ;
V_66 &= ~ ( V_85 | V_86 ) ;
F_5 ( V_65 , V_48 , V_66 ) ;
V_69 &= ~ ( V_81 |
V_83 ) ;
F_5 ( V_65 , V_6 , V_69 ) ;
V_66 &= ~ ( V_79 | V_77 |
V_80 | V_78 ) ;
F_5 ( V_65 , V_48 , V_66 ) ;
V_68 &= ~ ( V_75 | V_76 ) ;
F_5 ( V_65 , V_29 , V_68 ) ;
F_7 ( V_65 -> V_2 , L_4 ) ;
F_5 ( V_65 , V_50 ,
V_67 & ~ V_74 ) ;
}
return 0 ;
}
static int F_10 ( struct V_59 * V_60 ,
struct V_61 * V_62 , int V_63 )
{
struct V_64 * V_65 = V_60 -> V_65 ;
T_1 V_68 = F_4 ( V_65 , V_29 ) ;
T_1 V_88 = F_4 ( V_65 , V_39 ) ;
if ( V_63 & V_71 ) {
V_68 |= V_89 | V_90 ;
F_5 ( V_65 , V_29 , V_68 ) ;
V_88 |= V_91 | V_92 ;
F_5 ( V_65 , V_39 , V_88 ) ;
}
if ( V_63 & V_87 ) {
V_88 &= ~ ( V_91 | V_92 ) ;
F_5 ( V_65 , V_39 , V_88 ) ;
V_68 &= ~ ( V_89 | V_90 ) ;
F_5 ( V_65 , V_29 , V_68 ) ;
}
return 0 ;
}
static int F_11 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_64 * V_65 = V_98 -> V_65 ;
struct V_99 * V_100 = F_12 ( V_65 ) ;
int V_101 , V_102 , V_103 , V_104 ;
T_1 V_3 ;
V_104 = F_13 ( V_96 ) ;
if ( ! V_100 -> V_105 ) {
F_9 ( V_65 -> V_2 , L_5 ) ;
return - V_106 ;
}
V_102 = 0 ;
for ( V_101 = 0 ; V_101 < F_14 ( V_107 ) ; V_101 ++ ) {
if ( abs ( V_107 [ V_101 ] . V_108 - V_104 ) <
abs ( V_107 [ V_102 ] . V_108 - V_104 ) )
V_102 = V_101 ;
}
V_3 = F_4 ( V_65 , V_30 ) ;
V_3 &= ~ V_109 ;
V_3 |= V_107 [ V_102 ] . V_110 ;
F_5 ( V_65 , V_30 , V_3 ) ;
F_7 ( V_65 -> V_2 , L_6 ,
V_107 [ V_102 ] . V_108 , V_104 ) ;
V_103 = V_100 -> V_105 / V_104 ;
if ( V_94 -> V_111 == V_112 && V_103 < 64 ) {
F_9 ( V_65 -> V_2 ,
L_7 ) ;
return - V_106 ;
}
if ( V_94 -> V_111 == V_113 && V_103 < 256 ) {
F_9 ( V_65 -> V_2 ,
L_8 ) ;
return - V_106 ;
}
for ( V_101 = 0 ; V_101 < F_14 ( V_114 ) ; V_101 ++ ) {
if ( V_114 [ V_101 ] . V_115 >= V_103 )
break;
}
if ( V_101 == F_14 ( V_114 ) ) {
F_9 ( V_65 -> V_2 , L_9 ) ;
return - V_106 ;
}
F_7 ( V_65 -> V_2 , L_10 ,
V_114 [ V_101 ] . V_115 , V_100 -> V_105 , V_104 ,
V_100 -> V_105 / V_104 ) ;
V_3 = F_4 ( V_65 , V_41 ) ;
V_3 &= ~ V_116 ;
V_3 |= V_114 [ V_101 ] . V_110 << V_117 ;
F_5 ( V_65 , V_41 , V_3 ) ;
V_3 = F_4 ( V_65 , V_14 ) ;
V_3 &= ~ V_118 ;
switch ( F_15 ( V_96 ) ) {
case 16 :
break;
case 20 :
V_3 |= 1 << V_119 ;
break;
case 24 :
V_3 |= 2 << V_119 ;
break;
case 32 :
V_3 |= 3 << V_119 ;
break;
default:
return - V_106 ;
}
F_5 ( V_65 , V_14 , V_3 ) ;
V_3 = F_4 ( V_65 , V_13 ) ;
if ( V_104 <= 24000 )
V_3 |= V_120 ;
else
V_3 &= ~ V_120 ;
F_5 ( V_65 , V_13 , V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_97 * V_98 , int V_121 ,
unsigned int V_122 ,
int V_123 )
{
struct V_64 * V_65 = V_98 -> V_65 ;
struct V_99 * V_100 = F_12 ( V_65 ) ;
T_1 V_3 = F_4 ( V_65 , V_11 ) ;
if ( V_122 > 33000000 ) {
F_9 ( V_65 -> V_2 , L_11 ) ;
return - V_106 ;
}
if ( V_122 > 16500000 ) {
F_7 ( V_65 -> V_2 , L_12 , V_122 ) ;
V_3 |= V_124 ;
V_122 /= 2 ;
} else {
F_7 ( V_65 -> V_2 , L_13 , V_122 ) ;
V_3 &= ~ V_124 ;
}
F_5 ( V_65 , V_11 , V_3 ) ;
V_100 -> V_105 = V_122 ;
return 0 ;
}
static int F_17 ( struct V_97 * V_98 , unsigned int V_125 )
{
struct V_64 * V_65 = V_98 -> V_65 ;
T_1 V_126 = F_4 ( V_65 , V_14 ) ;
V_126 &= ~ ( V_127 | V_128 |
V_129 | V_130 ) ;
switch ( V_125 & V_131 ) {
case V_132 :
V_126 |= V_129 ;
break;
case V_133 :
break;
default:
return - V_106 ;
}
switch ( V_125 & V_134 ) {
case V_135 :
break;
case V_136 :
V_126 |= 1 ;
break;
case V_137 :
V_126 |= 2 ;
break;
case V_138 :
V_126 |= V_128 ;
case V_139 :
V_126 |= 3 ;
switch ( V_125 & V_140 ) {
case V_141 :
case V_142 :
break;
default:
return - V_106 ;
}
break;
default:
return - V_106 ;
}
switch ( V_125 & V_140 ) {
case V_141 :
break;
case V_143 :
V_126 |= V_128 ;
break;
case V_142 :
V_126 |= V_127 ;
break;
case V_144 :
V_126 |= V_127 | V_128 ;
break;
default:
return - V_106 ;
}
return F_5 ( V_65 , V_14 , V_126 ) ;
}
static int F_18 ( struct V_97 * V_98 , int V_145 )
{
struct V_64 * V_65 = V_98 -> V_65 ;
T_1 V_3 = F_4 ( V_65 , V_27 ) ;
if ( V_145 )
V_3 |= V_146 ;
else
V_3 &= ~ V_146 ;
return F_5 ( V_65 , V_27 , V_3 ) ;
}
static int F_19 ( struct V_97 * V_98 , int V_147 )
{
struct V_64 * V_65 = V_98 -> V_65 ;
T_1 V_3 = F_4 ( V_65 , V_12 ) ;
if ( V_147 )
V_3 |= V_148 ;
else
V_3 &= ~ V_148 ;
F_8 ( 17 ) ;
return F_5 ( V_65 , V_12 , V_3 ) ;
}
static int F_20 ( struct V_97 * V_98 , int V_149 , int div )
{
struct V_64 * V_65 = V_98 -> V_65 ;
T_1 V_3 ;
switch ( V_149 ) {
case V_150 :
V_3 = F_4 ( V_65 , V_15 ) ;
V_3 &= ~ V_151 ;
V_3 |= div ;
F_5 ( V_65 , V_15 , V_3 ) ;
break;
case V_152 :
V_3 = F_4 ( V_65 , V_19 ) ;
V_3 &= ~ V_153 ;
V_3 |= div ;
F_5 ( V_65 , V_19 , V_3 ) ;
break;
default:
return - V_106 ;
}
return 0 ;
}
static int F_21 ( struct V_64 * V_65 ,
enum V_154 V_155 )
{
T_1 V_3 ;
switch ( V_155 ) {
case V_156 :
break;
case V_157 :
if ( V_65 -> V_158 . V_159 == V_160 ) {
V_3 = F_4 ( V_65 , V_31 ) ;
V_3 |= V_161 | V_162 ;
F_5 ( V_65 , V_31 , V_3 ) ;
V_3 = F_4 ( V_65 , V_28 ) ;
V_3 &= ~ V_163 ;
V_3 |= ( 1 << V_164 ) | V_165 ;
F_5 ( V_65 , V_28 , V_3 ) ;
}
break;
case V_160 :
if ( V_65 -> V_158 . V_159 == V_157 ) {
V_3 = F_4 ( V_65 , V_28 ) ;
V_3 &= ~ V_165 ;
F_5 ( V_65 , V_28 , V_3 ) ;
V_3 = F_4 ( V_65 , V_31 ) ;
V_3 &= ~ ( V_161 | V_162 ) ;
F_5 ( V_65 , V_31 , V_3 ) ;
V_3 = F_4 ( V_65 , V_28 ) ;
V_3 &= ~ V_163 ;
F_5 ( V_65 , V_28 , V_3 ) ;
}
break;
case V_166 :
break;
}
V_65 -> V_158 . V_159 = V_155 ;
return 0 ;
}
static int F_22 ( struct V_64 * V_65 )
{
struct V_167 * V_158 = & V_65 -> V_158 ;
T_1 V_3 ;
V_3 = F_4 ( V_65 , V_51 ) ;
V_3 |= V_168 ;
F_5 ( V_65 , V_51 , V_3 ) ;
V_3 = F_4 ( V_65 , V_10 ) ;
F_5 ( V_65 , V_10 ,
V_3 | V_169 | V_170 ) ;
F_5 ( V_65 , V_9 , V_3 | V_169 ) ;
V_3 = F_4 ( V_65 , V_36 ) ;
F_5 ( V_65 , V_36 ,
V_3 | V_171 | V_172 ) ;
F_5 ( V_65 , V_35 , V_3 | V_173 ) ;
V_3 = F_4 ( V_65 , V_25 ) ;
F_5 ( V_65 , V_25 , V_3 | V_174 ) ;
V_3 = F_4 ( V_65 , V_8 ) ;
F_5 ( V_65 , V_8 , V_3 | V_175 ) ;
V_3 = F_4 ( V_65 , V_13 ) ;
V_3 |= V_176 ;
F_5 ( V_65 , V_13 , V_3 ) ;
V_3 = F_4 ( V_65 , V_32 ) ;
V_3 &= ~ V_177 ;
F_5 ( V_65 , V_32 , V_3 ) ;
F_21 ( V_65 , V_160 ) ;
F_23 ( V_65 , V_178 ,
F_14 ( V_178 ) ) ;
F_24 ( V_158 , V_179 ,
F_14 ( V_179 ) ) ;
F_25 ( V_158 , V_180 , F_14 ( V_180 ) ) ;
return 0 ;
}
static int F_26 ( struct V_64 * V_65 )
{
F_21 ( V_65 , V_166 ) ;
return 0 ;
}
static int F_27 ( struct V_64 * V_65 )
{
F_21 ( V_65 , V_166 ) ;
return 0 ;
}
static int F_28 ( struct V_64 * V_65 )
{
F_29 ( V_65 ) ;
F_21 ( V_65 , V_160 ) ;
return 0 ;
}
static int F_30 ( struct V_181 * V_182 ,
const struct V_183 * V_184 )
{
struct V_99 * V_100 ;
unsigned int V_110 ;
int V_185 ;
V_100 = F_31 ( & V_182 -> V_2 , sizeof( struct V_99 ) ,
V_186 ) ;
if ( V_100 == NULL )
return - V_187 ;
V_100 -> V_188 = F_32 ( V_182 , & V_189 ) ;
if ( F_33 ( V_100 -> V_188 ) )
return F_34 ( V_100 -> V_188 ) ;
V_185 = F_35 ( V_100 -> V_188 , V_4 , & V_110 ) ;
if ( V_185 != 0 ) {
F_9 ( & V_182 -> V_2 , L_14 , V_185 ) ;
return V_185 ;
}
if ( V_110 != 0x1801 ) {
F_9 ( & V_182 -> V_2 , L_15 , V_110 ) ;
return - V_106 ;
}
F_36 ( V_100 -> V_188 , true ) ;
V_185 = F_35 ( V_100 -> V_188 , V_8 , & V_110 ) ;
F_36 ( V_100 -> V_188 , false ) ;
if ( V_185 != 0 ) {
F_9 ( & V_182 -> V_2 , L_16 , V_185 ) ;
return V_185 ;
}
F_37 ( & V_182 -> V_2 , L_17 ,
( V_110 & V_190 ) >> V_191 ,
( ( V_110 & V_192 ) >> V_193 )
+ 'A' ) ;
V_185 = F_38 ( V_100 -> V_188 , V_4 , 0x1801 ) ;
if ( V_185 != 0 ) {
F_9 ( & V_182 -> V_2 , L_18 , V_185 ) ;
return V_185 ;
}
F_39 ( V_182 , V_100 ) ;
V_185 = F_40 ( & V_182 -> V_2 ,
& V_194 , & V_195 , 1 ) ;
return V_185 ;
}
static int F_41 ( struct V_181 * V_196 )
{
F_42 ( & V_196 -> V_2 ) ;
return 0 ;
}
