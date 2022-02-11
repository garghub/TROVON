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
static int F_3 ( struct V_100 * V_101 ,
struct V_102 * V_103 , int V_104 )
{
struct V_105 * V_106 = V_101 -> V_106 ;
struct V_107 * V_108 = F_4 ( V_106 ) ;
switch ( V_104 ) {
case V_109 :
V_108 -> V_110 = 150 ;
break;
default:
F_5 ( L_1 , V_104 ) ;
}
return 0 ;
}
static int F_6 ( struct V_100 * V_101 ,
struct V_102 * V_103 , int V_104 )
{
struct V_105 * V_106 = V_101 -> V_106 ;
struct V_107 * V_108 = F_4 ( V_106 ) ;
switch ( V_104 ) {
case V_109 :
if ( V_108 -> V_110 < 50 )
V_108 -> V_110 = 50 ;
break;
default:
F_5 ( L_1 , V_104 ) ;
}
return 0 ;
}
static int F_7 ( struct V_100 * V_101 ,
struct V_102 * V_103 , int V_104 )
{
struct V_105 * V_106 = V_101 -> V_106 ;
struct V_107 * V_108 = F_4 ( V_106 ) ;
switch ( V_104 ) {
case V_109 :
if ( V_108 -> V_110 < 30 )
V_108 -> V_110 = 30 ;
break;
default:
F_5 ( L_1 , V_104 ) ;
}
return 0 ;
}
static int F_8 ( int V_111 )
{
int V_112 ;
for ( V_112 = 0 ; V_112 < F_9 ( V_113 ) ; V_112 ++ ) {
if ( V_113 [ V_112 ] . V_111 == V_111 )
return V_112 ;
}
return - V_114 ;
}
static int F_10 ( int V_115 , int V_116 )
{
int V_112 ;
for ( V_112 = 0 ; V_112 < F_9 ( V_117 ) ; V_112 ++ ) {
if ( V_117 [ V_112 ] . V_115 == V_115 &&
V_117 [ V_112 ] . V_116 == V_116 )
return V_112 ;
}
return - V_114 ;
}
static int F_11 ( struct V_118 * V_119 , unsigned int V_120 )
{
struct V_105 * V_106 = V_119 -> V_106 ;
struct V_107 * V_108 = F_4 ( V_106 ) ;
int V_121 ;
T_1 V_115 = 0 ;
T_2 V_122 = 0 ;
V_121 = F_8 ( V_120 ) ;
if ( V_121 < 0 )
return V_121 ;
V_115 = V_113 [ V_121 ] . V_111 /
V_113 [ V_121 ] . V_123 ;
F_12 ( V_106 -> V_2 , L_2 ,
V_108 -> V_124 + 1 , V_113 [ V_121 ] . V_111 ,
V_115 ) ;
V_122 = ( V_108 -> V_124 << 4 ) |
( V_113 [ V_121 ] . V_125 << 1 ) ;
F_13 ( V_106 , V_15 , V_122 ) ;
V_108 -> V_126 = V_121 ;
V_108 -> V_115 = V_115 ;
return 0 ;
}
static int F_14 ( struct V_118 * V_119 ,
int V_127 , unsigned int V_120 , int V_128 )
{
struct V_105 * V_106 = V_119 -> V_106 ;
struct V_107 * V_108 = F_4 ( V_106 ) ;
switch ( V_127 ) {
case V_129 :
break;
case V_130 :
break;
default:
return - V_114 ;
}
if ( ( F_11 ( V_119 , V_120 ) ) < 0 ) {
F_15 ( V_106 -> V_2 , L_3 ,
V_119 -> V_131 ) ;
return - V_114 ;
}
V_108 -> V_124 = V_127 ;
return 0 ;
}
static int F_16 ( struct V_118 * V_132 , unsigned int V_133 )
{
struct V_105 * V_106 = V_132 -> V_106 ;
struct V_107 * V_108 = F_4 ( V_106 ) ;
T_2 V_134 = V_132 -> V_134 ;
unsigned int V_135 , V_136 ;
T_2 V_137 , V_138 ;
V_137 = F_17 ( V_106 , F_18 ( V_134 ) ) ;
V_138 = F_17 ( V_106 , F_19 ( V_134 ) ) ;
switch ( V_133 & V_139 ) {
case V_140 :
V_138 |= V_141 ;
break;
case V_142 :
V_138 &= ~ V_141 ;
break;
default:
return - V_114 ;
}
V_136 = ( V_133 & V_143 ) ;
V_135 = ( V_133 & V_144 ) ;
switch ( V_136 ) {
case V_145 :
V_137 &= ~ V_146 ;
break;
case V_147 :
case V_148 :
if ( V_138 & V_141 ) {
F_15 ( V_106 -> V_2 ,
L_4 ) ;
return - V_114 ;
}
if ( V_134 == V_149 ) {
F_15 ( V_106 -> V_2 ,
L_5 ) ;
return - V_114 ;
}
V_137 |= V_146 ;
break;
default:
return - V_114 ;
}
if ( V_137 & V_146 ) {
V_137 &= ~ ( V_150 | V_151 ) ;
switch ( V_136 ) {
case V_148 :
if ( V_135 == V_152 )
V_137 |= V_153 ;
if ( V_135 == V_154 )
V_137 |= V_155 ;
break;
case V_147 :
if ( V_135 == V_152 )
V_137 |= V_155 ;
break;
default:
return - V_114 ;
}
}
V_108 -> V_156 [ V_134 ] . V_137 = V_137 ;
V_108 -> V_156 [ V_134 ] . V_138 = V_138 ;
return 0 ;
}
static unsigned int F_20 ( T_1 V_157 )
{
int V_112 ;
for ( V_112 = 0 ; V_112 < F_9 ( V_158 ) ; V_112 ++ ) {
if ( V_158 [ V_112 ] == V_157 )
return V_112 + 1 ;
}
return 0 ;
}
static void F_21 ( struct V_105 * V_106 , int V_134 , int V_116 )
{
T_2 V_159 = 0 ;
if ( V_116 > 0 )
V_159 = F_20 ( V_116 ) ;
switch ( V_134 ) {
case V_160 :
F_22 ( V_106 , V_22 , 0x0f , V_159 ) ;
break;
case V_149 :
F_22 ( V_106 , V_18 , 0x3c , V_159 << 2 ) ;
break;
case V_161 :
F_22 ( V_106 , V_22 , 0xf0 , V_159 << 4 ) ;
break;
default:
break;
}
}
static int F_23 ( struct V_162 * V_163 ,
struct V_164 * V_165 ,
struct V_118 * V_119 )
{
struct V_105 * V_106 = V_119 -> V_106 ;
struct V_107 * V_108 = F_4 ( V_106 ) ;
int V_134 = V_119 -> V_134 ;
int V_166 ;
int V_116 = F_24 ( V_165 ) ;
if ( V_108 -> V_156 [ V_134 ] . V_138 & V_141 ) {
V_166 =
F_10 ( V_108 -> V_115 , V_116 ) ;
if ( V_166 < 0 )
return - V_114 ;
F_12 ( V_106 -> V_2 ,
L_6 ,
V_134 , V_108 -> V_115 , V_116 ,
V_117 [ V_166 ] . V_138 ) ;
V_108 -> V_156 [ V_134 ] . V_138 &= 0xC0 ;
V_108 -> V_156 [ V_134 ] . V_138 |= V_117 [ V_166 ] . V_138 ;
V_108 -> V_156 [ V_134 ] . V_137 &= 0xFC ;
V_108 -> V_156 [ V_134 ] . V_137 |= V_167 ;
} else {
V_108 -> V_156 [ V_134 ] . V_137 &= 0xFC ;
V_108 -> V_156 [ V_134 ] . V_137 |= V_168 ;
}
V_108 -> V_156 [ V_134 ] . V_116 = V_116 ;
F_13 ( V_106 , F_18 ( V_134 ) , V_108 -> V_156 [ V_134 ] . V_137 ) ;
F_13 ( V_106 , F_19 ( V_134 ) , V_108 -> V_156 [ V_134 ] . V_138 ) ;
F_21 ( V_106 , V_134 , V_116 ) ;
return 0 ;
}
static int F_25 ( struct V_105 * V_106 ,
enum V_169 V_170 )
{
struct V_107 * V_171 = F_4 ( V_106 ) ;
switch ( V_170 ) {
case V_172 :
F_22 ( V_106 , V_15 , V_173 , 0 ) ;
F_22 ( V_106 , V_10 , V_174 , 0 ) ;
break;
case V_175 :
break;
case V_176 :
if ( V_106 -> V_177 . V_178 == V_179 ) {
F_26 ( V_171 -> V_180 , false ) ;
F_27 ( V_171 -> V_180 ) ;
}
F_22 ( V_106 , V_10 , V_174 , 1 ) ;
break;
case V_179 :
F_22 ( V_106 , V_10 , V_174 , 1 ) ;
if ( V_171 -> V_110 > 0 ) {
F_28 ( V_171 -> V_110 ) ;
V_171 -> V_110 = 0 ;
} else {
F_28 ( 15 ) ;
}
F_22 ( V_106 , V_15 , V_173 , 1 ) ;
break;
}
V_106 -> V_177 . V_178 = V_170 ;
return 0 ;
}
static int F_29 ( struct V_118 * V_119 , int V_181 )
{
struct V_105 * V_106 = V_119 -> V_106 ;
int V_134 = V_119 -> V_134 ;
return F_22 ( V_106 , F_18 ( V_134 ) ,
0x7F , V_181 << 7 ) ;
}
static int F_30 ( struct V_162 * V_163 ,
struct V_118 * V_119 )
{
F_31 ( V_163 -> V_182 , 0 ,
V_183 ,
& V_184 ) ;
return 0 ;
}
static int F_32 ( struct V_105 * V_106 )
{
F_25 ( V_106 , V_179 ) ;
return 0 ;
}
static int F_33 ( struct V_105 * V_106 )
{
F_25 ( V_106 , V_176 ) ;
return 0 ;
}
static int F_34 ( struct V_105 * V_106 )
{
int V_185 ;
struct V_107 * V_171 = F_4 ( V_106 ) ;
V_106 -> V_186 = V_171 -> V_180 ;
V_185 = F_35 ( V_106 , 8 , 8 , V_187 ) ;
if ( V_185 < 0 ) {
F_15 ( V_106 -> V_2 , L_7 , V_185 ) ;
return V_185 ;
}
F_26 ( V_171 -> V_180 , true ) ;
F_25 ( V_106 , V_176 ) ;
V_171 -> V_124 = V_129 ;
V_171 -> V_115 = 0 ;
return V_185 ;
}
static int F_36 ( struct V_105 * V_106 )
{
F_25 ( V_106 , V_179 ) ;
return 0 ;
}
static int F_37 ( struct V_188 * V_188 ,
const struct V_189 * V_134 )
{
struct V_107 * V_171 ;
int V_185 ;
unsigned int V_190 = 0 ;
unsigned int V_3 ;
V_171 = F_38 ( & V_188 -> V_2 , sizeof( struct V_107 ) ,
V_191 ) ;
if ( ! V_171 ) {
F_15 ( & V_188 -> V_2 , L_8 ) ;
return - V_192 ;
}
F_39 ( V_188 , V_171 ) ;
V_171 -> V_180 = F_40 ( V_188 , & V_193 ) ;
if ( F_41 ( V_171 -> V_180 ) ) {
V_185 = F_42 ( V_171 -> V_180 ) ;
F_15 ( & V_188 -> V_2 , L_9 , V_185 ) ;
return V_185 ;
}
V_185 = F_43 ( V_171 -> V_180 , V_6 , & V_3 ) ;
V_190 = ( V_3 & 0xFF ) << 12 ;
V_185 = F_43 ( V_171 -> V_180 , V_7 , & V_3 ) ;
V_190 |= ( V_3 & 0xFF ) << 4 ;
V_185 = F_43 ( V_171 -> V_180 , V_8 , & V_3 ) ;
V_190 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_190 != V_194 ) {
V_185 = - V_195 ;
F_15 ( & V_188 -> V_2 ,
L_10 ,
V_190 , V_194 ) ;
return V_185 ;
}
V_185 = F_43 ( V_171 -> V_180 , V_9 , & V_3 ) ;
if ( V_185 < 0 ) {
F_15 ( & V_188 -> V_2 , L_11 ) ;
return V_185 ; ;
}
F_44 ( & V_188 -> V_2 ,
L_12 , V_3 & 0xFF ) ;
F_26 ( V_171 -> V_180 , true ) ;
V_185 = F_45 ( & V_188 -> V_2 ,
& V_196 , V_197 ,
F_9 ( V_197 ) ) ;
if ( V_185 < 0 )
return V_185 ;
return 0 ;
}
static int F_46 ( struct V_188 * V_198 )
{
F_47 ( & V_198 -> V_2 ) ;
return 0 ;
}
