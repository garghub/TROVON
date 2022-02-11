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
struct V_64 * V_65 = F_4 ( V_60 -> V_66 ) ;
T_1 V_67 = F_5 ( V_65 , V_48 ) ;
T_1 V_68 = F_5 ( V_65 , V_50 ) ;
T_1 V_69 = F_5 ( V_65 , V_29 ) ;
T_1 V_70 = F_5 ( V_65 , V_6 ) ;
int V_71 = 500 ;
if ( V_63 & V_72 ) {
V_67 &= ~ ( V_73 | V_74 ) ;
F_6 ( V_65 , V_48 , V_67 ) ;
V_68 |= V_75 ;
F_6 ( V_65 , V_50 , V_68 ) ;
F_7 ( 5 ) ;
V_69 |= V_76 | V_77 ;
F_6 ( V_65 , V_29 , V_69 ) ;
V_67 |= V_78 | V_79 ;
F_6 ( V_65 , V_48 , V_67 ) ;
V_67 |= V_80 | V_81 ;
F_6 ( V_65 , V_48 , V_67 ) ;
V_70 |=
V_82 | V_83 |
V_84 | V_85 ;
F_8 ( V_65 -> V_2 , L_1 ) ;
F_6 ( V_65 , V_6 , V_70 ) ;
do {
F_9 ( 1 ) ;
V_70 = F_5 ( V_65 , V_6 ) ;
} while ( -- V_71 &&
V_70 & ( V_83 |
V_85 ) );
if ( V_70 & ( V_83 |
V_85 ) )
F_10 ( V_65 -> V_2 , L_2 ) ;
else
F_8 ( V_65 -> V_2 , L_3 ) ;
V_67 |= V_86 | V_87 ;
F_6 ( V_65 , V_48 , V_67 ) ;
V_67 |= V_73 | V_74 ;
F_6 ( V_65 , V_48 , V_67 ) ;
}
if ( V_63 & V_88 ) {
V_67 &= ~ ( V_73 | V_74 ) ;
F_6 ( V_65 , V_48 , V_67 ) ;
V_67 &= ~ ( V_86 | V_87 ) ;
F_6 ( V_65 , V_48 , V_67 ) ;
V_70 &= ~ ( V_82 |
V_84 ) ;
F_6 ( V_65 , V_6 , V_70 ) ;
V_67 &= ~ ( V_80 | V_78 |
V_81 | V_79 ) ;
F_6 ( V_65 , V_48 , V_67 ) ;
V_69 &= ~ ( V_76 | V_77 ) ;
F_6 ( V_65 , V_29 , V_69 ) ;
F_8 ( V_65 -> V_2 , L_4 ) ;
F_6 ( V_65 , V_50 ,
V_68 & ~ V_75 ) ;
}
return 0 ;
}
static int F_11 ( struct V_59 * V_60 ,
struct V_61 * V_62 , int V_63 )
{
struct V_64 * V_65 = F_4 ( V_60 -> V_66 ) ;
T_1 V_69 = F_5 ( V_65 , V_29 ) ;
T_1 V_89 = F_5 ( V_65 , V_39 ) ;
if ( V_63 & V_72 ) {
V_69 |= V_90 | V_91 ;
F_6 ( V_65 , V_29 , V_69 ) ;
V_89 |= V_92 | V_93 ;
F_6 ( V_65 , V_39 , V_89 ) ;
}
if ( V_63 & V_88 ) {
V_89 &= ~ ( V_92 | V_93 ) ;
F_6 ( V_65 , V_39 , V_89 ) ;
V_69 &= ~ ( V_90 | V_91 ) ;
F_6 ( V_65 , V_29 , V_69 ) ;
}
return 0 ;
}
static int F_12 ( struct V_94 * V_95 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_64 * V_65 = V_99 -> V_65 ;
struct V_100 * V_101 = F_13 ( V_65 ) ;
int V_102 , V_103 , V_104 , V_105 ;
T_1 V_3 ;
V_105 = F_14 ( V_97 ) ;
if ( ! V_101 -> V_106 ) {
F_10 ( V_65 -> V_2 , L_5 ) ;
return - V_107 ;
}
V_103 = 0 ;
for ( V_102 = 0 ; V_102 < F_15 ( V_108 ) ; V_102 ++ ) {
if ( abs ( V_108 [ V_102 ] . V_109 - V_105 ) <
abs ( V_108 [ V_103 ] . V_109 - V_105 ) )
V_103 = V_102 ;
}
V_3 = F_5 ( V_65 , V_30 ) ;
V_3 &= ~ V_110 ;
V_3 |= V_108 [ V_103 ] . V_111 ;
F_6 ( V_65 , V_30 , V_3 ) ;
F_8 ( V_65 -> V_2 , L_6 ,
V_108 [ V_103 ] . V_109 , V_105 ) ;
V_104 = V_101 -> V_106 / V_105 ;
if ( V_95 -> V_112 == V_113 && V_104 < 64 ) {
F_10 ( V_65 -> V_2 ,
L_7 ) ;
return - V_107 ;
}
if ( V_95 -> V_112 == V_114 && V_104 < 256 ) {
F_10 ( V_65 -> V_2 ,
L_8 ) ;
return - V_107 ;
}
for ( V_102 = 0 ; V_102 < F_15 ( V_115 ) ; V_102 ++ ) {
if ( V_115 [ V_102 ] . V_116 >= V_104 )
break;
}
if ( V_102 == F_15 ( V_115 ) ) {
F_10 ( V_65 -> V_2 , L_9 ) ;
return - V_107 ;
}
F_8 ( V_65 -> V_2 , L_10 ,
V_115 [ V_102 ] . V_116 , V_101 -> V_106 , V_105 ,
V_101 -> V_106 / V_105 ) ;
V_3 = F_5 ( V_65 , V_41 ) ;
V_3 &= ~ V_117 ;
V_3 |= V_115 [ V_102 ] . V_111 << V_118 ;
F_6 ( V_65 , V_41 , V_3 ) ;
V_3 = F_5 ( V_65 , V_14 ) ;
V_3 &= ~ V_119 ;
switch ( F_16 ( V_97 ) ) {
case 16 :
break;
case 20 :
V_3 |= 1 << V_120 ;
break;
case 24 :
V_3 |= 2 << V_120 ;
break;
case 32 :
V_3 |= 3 << V_120 ;
break;
default:
return - V_107 ;
}
F_6 ( V_65 , V_14 , V_3 ) ;
V_3 = F_5 ( V_65 , V_13 ) ;
if ( V_105 <= 24000 )
V_3 |= V_121 ;
else
V_3 &= ~ V_121 ;
F_6 ( V_65 , V_13 , V_3 ) ;
return 0 ;
}
static int F_17 ( struct V_98 * V_99 , int V_122 ,
unsigned int V_123 ,
int V_124 )
{
struct V_64 * V_65 = V_99 -> V_65 ;
struct V_100 * V_101 = F_13 ( V_65 ) ;
T_1 V_3 = F_5 ( V_65 , V_11 ) ;
if ( V_123 > 33000000 ) {
F_10 ( V_65 -> V_2 , L_11 ) ;
return - V_107 ;
}
if ( V_123 > 16500000 ) {
F_8 ( V_65 -> V_2 , L_12 , V_123 ) ;
V_3 |= V_125 ;
V_123 /= 2 ;
} else {
F_8 ( V_65 -> V_2 , L_13 , V_123 ) ;
V_3 &= ~ V_125 ;
}
F_6 ( V_65 , V_11 , V_3 ) ;
V_101 -> V_106 = V_123 ;
return 0 ;
}
static int F_18 ( struct V_98 * V_99 , unsigned int V_126 )
{
struct V_64 * V_65 = V_99 -> V_65 ;
T_1 V_127 = F_5 ( V_65 , V_14 ) ;
V_127 &= ~ ( V_128 | V_129 |
V_130 | V_131 ) ;
switch ( V_126 & V_132 ) {
case V_133 :
V_127 |= V_130 ;
break;
case V_134 :
break;
default:
return - V_107 ;
}
switch ( V_126 & V_135 ) {
case V_136 :
break;
case V_137 :
V_127 |= 1 ;
break;
case V_138 :
V_127 |= 2 ;
break;
case V_139 :
V_127 |= V_129 ;
case V_140 :
V_127 |= 3 ;
switch ( V_126 & V_141 ) {
case V_142 :
case V_143 :
break;
default:
return - V_107 ;
}
break;
default:
return - V_107 ;
}
switch ( V_126 & V_141 ) {
case V_142 :
break;
case V_144 :
V_127 |= V_129 ;
break;
case V_143 :
V_127 |= V_128 ;
break;
case V_145 :
V_127 |= V_128 | V_129 ;
break;
default:
return - V_107 ;
}
return F_6 ( V_65 , V_14 , V_127 ) ;
}
static int F_19 ( struct V_98 * V_99 , int V_146 )
{
struct V_64 * V_65 = V_99 -> V_65 ;
T_1 V_3 = F_5 ( V_65 , V_27 ) ;
if ( V_146 )
V_3 |= V_147 ;
else
V_3 &= ~ V_147 ;
return F_6 ( V_65 , V_27 , V_3 ) ;
}
static int F_20 ( struct V_98 * V_99 , int V_148 )
{
struct V_64 * V_65 = V_99 -> V_65 ;
T_1 V_3 = F_5 ( V_65 , V_12 ) ;
if ( V_148 )
V_3 |= V_149 ;
else
V_3 &= ~ V_149 ;
F_9 ( 17 ) ;
return F_6 ( V_65 , V_12 , V_3 ) ;
}
static int F_21 ( struct V_98 * V_99 , int V_150 , int div )
{
struct V_64 * V_65 = V_99 -> V_65 ;
T_1 V_3 ;
switch ( V_150 ) {
case V_151 :
V_3 = F_5 ( V_65 , V_15 ) ;
V_3 &= ~ V_152 ;
V_3 |= div ;
F_6 ( V_65 , V_15 , V_3 ) ;
break;
case V_153 :
V_3 = F_5 ( V_65 , V_19 ) ;
V_3 &= ~ V_154 ;
V_3 |= div ;
F_6 ( V_65 , V_19 , V_3 ) ;
break;
default:
return - V_107 ;
}
return 0 ;
}
static int F_22 ( struct V_64 * V_65 ,
enum V_155 V_156 )
{
T_1 V_3 ;
switch ( V_156 ) {
case V_157 :
break;
case V_158 :
if ( V_65 -> V_66 . V_159 == V_160 ) {
V_3 = F_5 ( V_65 , V_31 ) ;
V_3 |= V_161 | V_162 ;
F_6 ( V_65 , V_31 , V_3 ) ;
V_3 = F_5 ( V_65 , V_28 ) ;
V_3 &= ~ V_163 ;
V_3 |= ( 1 << V_164 ) | V_165 ;
F_6 ( V_65 , V_28 , V_3 ) ;
}
break;
case V_160 :
if ( V_65 -> V_66 . V_159 == V_158 ) {
V_3 = F_5 ( V_65 , V_28 ) ;
V_3 &= ~ V_165 ;
F_6 ( V_65 , V_28 , V_3 ) ;
V_3 = F_5 ( V_65 , V_31 ) ;
V_3 &= ~ ( V_161 | V_162 ) ;
F_6 ( V_65 , V_31 , V_3 ) ;
V_3 = F_5 ( V_65 , V_28 ) ;
V_3 &= ~ V_163 ;
F_6 ( V_65 , V_28 , V_3 ) ;
}
break;
case V_166 :
break;
}
V_65 -> V_66 . V_159 = V_156 ;
return 0 ;
}
static int F_23 ( struct V_64 * V_65 )
{
T_1 V_3 ;
V_3 = F_5 ( V_65 , V_51 ) ;
V_3 |= V_167 ;
F_6 ( V_65 , V_51 , V_3 ) ;
V_3 = F_5 ( V_65 , V_10 ) ;
F_6 ( V_65 , V_10 ,
V_3 | V_168 | V_169 ) ;
F_6 ( V_65 , V_9 , V_3 | V_168 ) ;
V_3 = F_5 ( V_65 , V_36 ) ;
F_6 ( V_65 , V_36 ,
V_3 | V_170 | V_171 ) ;
F_6 ( V_65 , V_35 , V_3 | V_172 ) ;
V_3 = F_5 ( V_65 , V_25 ) ;
F_6 ( V_65 , V_25 , V_3 | V_173 ) ;
V_3 = F_5 ( V_65 , V_8 ) ;
F_6 ( V_65 , V_8 , V_3 | V_174 ) ;
V_3 = F_5 ( V_65 , V_13 ) ;
V_3 |= V_175 ;
F_6 ( V_65 , V_13 , V_3 ) ;
V_3 = F_5 ( V_65 , V_32 ) ;
V_3 &= ~ V_176 ;
F_6 ( V_65 , V_32 , V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_64 * V_65 )
{
F_25 ( V_65 ) ;
return 0 ;
}
static int F_26 ( struct V_177 * V_178 ,
const struct V_179 * V_180 )
{
struct V_100 * V_101 ;
unsigned int V_111 ;
int V_181 ;
V_101 = F_27 ( & V_178 -> V_2 , sizeof( struct V_100 ) ,
V_182 ) ;
if ( V_101 == NULL )
return - V_183 ;
V_101 -> V_184 = F_28 ( V_178 , & V_185 ) ;
if ( F_29 ( V_101 -> V_184 ) )
return F_30 ( V_101 -> V_184 ) ;
V_181 = F_31 ( V_101 -> V_184 , V_4 , & V_111 ) ;
if ( V_181 != 0 ) {
F_10 ( & V_178 -> V_2 , L_14 , V_181 ) ;
return V_181 ;
}
if ( V_111 != 0x1801 ) {
F_10 ( & V_178 -> V_2 , L_15 , V_111 ) ;
return - V_107 ;
}
F_32 ( V_101 -> V_184 , true ) ;
V_181 = F_31 ( V_101 -> V_184 , V_8 , & V_111 ) ;
F_32 ( V_101 -> V_184 , false ) ;
if ( V_181 != 0 ) {
F_10 ( & V_178 -> V_2 , L_16 , V_181 ) ;
return V_181 ;
}
F_33 ( & V_178 -> V_2 , L_17 ,
( V_111 & V_186 ) >> V_187 ,
( ( V_111 & V_188 ) >> V_189 )
+ 'A' ) ;
V_181 = F_34 ( V_101 -> V_184 , V_4 , 0x1801 ) ;
if ( V_181 != 0 ) {
F_10 ( & V_178 -> V_2 , L_18 , V_181 ) ;
return V_181 ;
}
F_35 ( V_178 , V_101 ) ;
V_181 = F_36 ( & V_178 -> V_2 ,
& V_190 , & V_191 , 1 ) ;
return V_181 ;
}
static int F_37 ( struct V_177 * V_192 )
{
F_38 ( & V_192 -> V_2 ) ;
return 0 ;
}
