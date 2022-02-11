static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
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
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
return true ;
default:
return false ;
}
}
static int F_3 ( int V_100 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < F_4 ( V_102 ) ; V_101 ++ ) {
if ( V_102 [ V_101 ] . V_100 == V_100 )
return V_101 ;
}
return - V_103 ;
}
static int F_5 ( int V_104 , int V_105 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < F_4 ( V_106 ) ; V_101 ++ ) {
if ( V_106 [ V_101 ] . V_104 == V_104 &&
V_106 [ V_101 ] . V_105 == V_105 )
return V_101 ;
}
return - V_103 ;
}
static int F_6 ( struct V_107 * V_108 , unsigned int V_109 )
{
struct V_110 * V_111 = V_108 -> V_111 ;
struct V_112 * V_113 = F_7 ( V_111 ) ;
int V_114 ;
T_1 V_104 = 0 ;
T_2 V_115 = 0 ;
V_114 = F_3 ( V_109 ) ;
if ( V_114 < 0 )
return V_114 ;
V_104 = V_102 [ V_114 ] . V_100 /
V_102 [ V_114 ] . V_116 ;
F_8 ( V_111 -> V_2 , L_1 ,
V_113 -> V_117 + 1 , V_102 [ V_114 ] . V_100 ,
V_104 ) ;
V_115 = ( V_113 -> V_117 << 4 ) |
( V_102 [ V_114 ] . V_118 << 1 ) ;
F_9 ( V_111 , V_15 , V_115 ) ;
V_113 -> V_119 = V_114 ;
V_113 -> V_104 = V_104 ;
return 0 ;
}
static int F_10 ( struct V_107 * V_108 ,
int V_120 , unsigned int V_109 , int V_121 )
{
struct V_110 * V_111 = V_108 -> V_111 ;
struct V_112 * V_113 = F_7 ( V_111 ) ;
switch ( V_120 ) {
case V_122 :
break;
case V_123 :
break;
default:
return - V_103 ;
}
if ( ( F_6 ( V_108 , V_109 ) ) < 0 ) {
F_11 ( V_111 -> V_2 , L_2 ,
V_108 -> V_124 ) ;
return - V_103 ;
}
V_113 -> V_117 = V_120 ;
return 0 ;
}
static int F_12 ( struct V_107 * V_125 , unsigned int V_126 )
{
struct V_110 * V_111 = V_125 -> V_111 ;
struct V_112 * V_113 = F_7 ( V_111 ) ;
T_2 V_127 = V_125 -> V_127 ;
unsigned int V_128 , V_129 ;
T_2 V_130 , V_131 ;
V_130 = F_13 ( V_111 , F_14 ( V_127 ) ) ;
V_131 = F_13 ( V_111 , F_15 ( V_127 ) ) ;
switch ( V_126 & V_132 ) {
case V_133 :
V_131 |= V_134 ;
break;
case V_135 :
V_131 &= ~ V_134 ;
break;
default:
return - V_103 ;
}
V_129 = ( V_126 & V_136 ) ;
V_128 = ( V_126 & V_137 ) ;
switch ( V_129 ) {
case V_138 :
V_130 &= ~ V_139 ;
break;
case V_140 :
case V_141 :
if ( V_131 & V_134 ) {
F_11 ( V_111 -> V_2 ,
L_3 ) ;
return - V_103 ;
}
if ( V_127 == V_142 ) {
F_11 ( V_111 -> V_2 ,
L_4 ) ;
return - V_103 ;
}
V_130 |= V_139 ;
break;
default:
return - V_103 ;
}
if ( V_130 & V_139 ) {
V_130 &= ~ ( V_143 | V_144 ) ;
switch ( V_129 ) {
case V_141 :
if ( V_128 == V_145 )
V_130 |= V_146 ;
if ( V_128 == V_147 )
V_130 |= V_148 ;
break;
case V_140 :
if ( V_128 == V_145 )
V_130 |= V_148 ;
break;
default:
return - V_103 ;
}
}
V_113 -> V_149 [ V_127 ] . V_130 = V_130 ;
V_113 -> V_149 [ V_127 ] . V_131 = V_131 ;
return 0 ;
}
static unsigned int F_16 ( T_1 V_150 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < F_4 ( V_151 ) ; V_101 ++ ) {
if ( V_151 [ V_101 ] == V_150 )
return V_101 + 1 ;
}
return 0 ;
}
static void F_17 ( struct V_110 * V_111 , int V_127 , int V_105 )
{
T_2 V_152 = 0 ;
if ( V_105 > 0 )
V_152 = F_16 ( V_105 ) ;
switch ( V_127 ) {
case V_153 :
F_18 ( V_111 , V_22 , 0x0f , V_152 ) ;
break;
case V_142 :
F_18 ( V_111 , V_18 , 0x3c , V_152 << 2 ) ;
break;
case V_154 :
F_18 ( V_111 , V_22 , 0xf0 , V_152 << 4 ) ;
break;
default:
break;
}
}
static int F_19 ( struct V_155 * V_156 ,
struct V_157 * V_158 ,
struct V_107 * V_108 )
{
struct V_110 * V_111 = V_108 -> V_111 ;
struct V_112 * V_113 = F_7 ( V_111 ) ;
int V_127 = V_108 -> V_127 ;
int V_159 ;
int V_105 = F_20 ( V_158 ) ;
if ( V_113 -> V_149 [ V_127 ] . V_131 & V_134 ) {
V_159 =
F_5 ( V_113 -> V_104 , V_105 ) ;
if ( V_159 < 0 )
return - V_103 ;
F_8 ( V_111 -> V_2 ,
L_5 ,
V_127 , V_113 -> V_104 , V_105 ,
V_106 [ V_159 ] . V_131 ) ;
V_113 -> V_149 [ V_127 ] . V_131 &= 0xC0 ;
V_113 -> V_149 [ V_127 ] . V_131 |= V_106 [ V_159 ] . V_131 ;
V_113 -> V_149 [ V_127 ] . V_130 &= 0xFC ;
V_113 -> V_149 [ V_127 ] . V_130 |= V_160 ;
} else {
V_113 -> V_149 [ V_127 ] . V_130 &= 0xFC ;
V_113 -> V_149 [ V_127 ] . V_130 |= V_161 ;
}
V_113 -> V_149 [ V_127 ] . V_105 = V_105 ;
F_9 ( V_111 , F_14 ( V_127 ) , V_113 -> V_149 [ V_127 ] . V_130 ) ;
F_9 ( V_111 , F_15 ( V_127 ) , V_113 -> V_149 [ V_127 ] . V_131 ) ;
F_17 ( V_111 , V_127 , V_105 ) ;
return 0 ;
}
static int F_21 ( struct V_110 * V_111 ,
enum V_162 V_163 )
{
struct V_112 * V_164 = F_7 ( V_111 ) ;
switch ( V_163 ) {
case V_165 :
F_18 ( V_111 , V_15 , V_166 , 0 ) ;
F_18 ( V_111 , V_10 , V_167 , 0 ) ;
break;
case V_168 :
break;
case V_169 :
if ( V_111 -> V_170 . V_171 == V_172 ) {
F_22 ( V_164 -> V_173 , false ) ;
F_23 ( V_164 -> V_173 ) ;
}
F_18 ( V_111 , V_10 , V_167 , 1 ) ;
break;
case V_172 :
F_18 ( V_111 , V_10 , V_167 , 1 ) ;
F_18 ( V_111 , V_15 , V_166 , 1 ) ;
break;
}
V_111 -> V_170 . V_171 = V_163 ;
return 0 ;
}
static int F_24 ( struct V_107 * V_108 , int V_174 )
{
struct V_110 * V_111 = V_108 -> V_111 ;
int V_127 = V_108 -> V_127 ;
return F_18 ( V_111 , F_14 ( V_127 ) ,
0x7F , V_174 << 7 ) ;
}
static int F_25 ( struct V_155 * V_156 ,
struct V_107 * V_108 )
{
F_26 ( V_156 -> V_175 , 0 ,
V_176 ,
& V_177 ) ;
return 0 ;
}
static int F_27 ( struct V_110 * V_111 )
{
F_21 ( V_111 , V_172 ) ;
return 0 ;
}
static int F_28 ( struct V_110 * V_111 )
{
F_21 ( V_111 , V_169 ) ;
return 0 ;
}
static int F_29 ( struct V_110 * V_111 )
{
int V_178 ;
struct V_112 * V_164 = F_7 ( V_111 ) ;
V_111 -> V_179 = V_164 -> V_173 ;
V_178 = F_30 ( V_111 , 8 , 8 , V_180 ) ;
if ( V_178 < 0 ) {
F_11 ( V_111 -> V_2 , L_6 , V_178 ) ;
return V_178 ;
}
F_22 ( V_164 -> V_173 , true ) ;
F_21 ( V_111 , V_169 ) ;
V_164 -> V_117 = V_122 ;
V_164 -> V_104 = 0 ;
return V_178 ;
}
static int F_31 ( struct V_110 * V_111 )
{
F_21 ( V_111 , V_172 ) ;
return 0 ;
}
static T_3 int F_32 ( struct V_181 * V_181 ,
const struct V_182 * V_127 )
{
struct V_112 * V_164 ;
int V_178 ;
unsigned int V_183 = 0 ;
unsigned int V_3 ;
V_164 = F_33 ( & V_181 -> V_2 , sizeof( struct V_112 ) ,
V_184 ) ;
if ( ! V_164 ) {
F_11 ( & V_181 -> V_2 , L_7 ) ;
return - V_185 ;
}
F_34 ( V_181 , V_164 ) ;
V_164 -> V_173 = F_35 ( V_181 , & V_186 ) ;
if ( F_36 ( V_164 -> V_173 ) ) {
V_178 = F_37 ( V_164 -> V_173 ) ;
F_11 ( & V_181 -> V_2 , L_8 , V_178 ) ;
return V_178 ;
}
V_178 = F_38 ( V_164 -> V_173 , V_6 , & V_3 ) ;
V_183 = ( V_3 & 0xFF ) << 12 ;
V_178 = F_38 ( V_164 -> V_173 , V_7 , & V_3 ) ;
V_183 |= ( V_3 & 0xFF ) << 4 ;
V_178 = F_38 ( V_164 -> V_173 , V_8 , & V_3 ) ;
V_183 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_183 != V_187 ) {
V_178 = - V_188 ;
F_11 ( & V_181 -> V_2 ,
L_9 ,
V_183 , V_187 ) ;
return V_178 ;
}
V_178 = F_38 ( V_164 -> V_173 , V_9 , & V_3 ) ;
if ( V_178 < 0 ) {
F_11 ( & V_181 -> V_2 , L_10 ) ;
return V_178 ; ;
}
F_39 ( & V_181 -> V_2 ,
L_11 , V_3 & 0xFF ) ;
F_22 ( V_164 -> V_173 , true ) ;
V_178 = F_40 ( & V_181 -> V_2 ,
& V_189 , V_190 ,
F_4 ( V_190 ) ) ;
if ( V_178 < 0 )
return V_178 ;
return 0 ;
}
static T_4 int F_41 ( struct V_181 * V_191 )
{
F_42 ( & V_191 -> V_2 ) ;
return 0 ;
}
