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
struct V_105 * V_106 = F_4 ( V_101 -> V_107 ) ;
struct V_108 * V_109 = F_5 ( V_106 ) ;
switch ( V_104 ) {
case V_110 :
V_109 -> V_111 = 150 ;
break;
default:
F_6 ( L_1 , V_104 ) ;
}
return 0 ;
}
static int F_7 ( struct V_100 * V_101 ,
struct V_102 * V_103 , int V_104 )
{
struct V_105 * V_106 = F_4 ( V_101 -> V_107 ) ;
struct V_108 * V_109 = F_5 ( V_106 ) ;
switch ( V_104 ) {
case V_110 :
if ( V_109 -> V_111 < 50 )
V_109 -> V_111 = 50 ;
break;
default:
F_6 ( L_1 , V_104 ) ;
}
return 0 ;
}
static int F_8 ( struct V_100 * V_101 ,
struct V_102 * V_103 , int V_104 )
{
struct V_105 * V_106 = F_4 ( V_101 -> V_107 ) ;
struct V_108 * V_109 = F_5 ( V_106 ) ;
switch ( V_104 ) {
case V_110 :
if ( V_109 -> V_111 < 30 )
V_109 -> V_111 = 30 ;
break;
default:
F_6 ( L_1 , V_104 ) ;
}
return 0 ;
}
static int F_9 ( int V_112 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < F_10 ( V_114 ) ; V_113 ++ ) {
if ( V_114 [ V_113 ] . V_112 == V_112 )
return V_113 ;
}
return - V_115 ;
}
static int F_11 ( int V_116 , int V_117 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < F_10 ( V_118 ) ; V_113 ++ ) {
if ( V_118 [ V_113 ] . V_116 == V_116 &&
V_118 [ V_113 ] . V_117 == V_117 )
return V_113 ;
}
return - V_115 ;
}
static int F_12 ( struct V_119 * V_120 , unsigned int V_121 )
{
struct V_105 * V_106 = V_120 -> V_106 ;
struct V_108 * V_109 = F_5 ( V_106 ) ;
int V_122 ;
T_1 V_116 = 0 ;
T_2 V_123 = 0 ;
V_122 = F_9 ( V_121 ) ;
if ( V_122 < 0 )
return V_122 ;
V_116 = V_114 [ V_122 ] . V_112 /
V_114 [ V_122 ] . V_124 ;
F_13 ( V_106 -> V_2 , L_2 ,
V_109 -> V_125 + 1 , V_114 [ V_122 ] . V_112 ,
V_116 ) ;
V_123 = ( V_109 -> V_125 << 4 ) |
( V_114 [ V_122 ] . V_126 << 1 ) ;
F_14 ( V_106 , V_15 , V_123 ) ;
V_109 -> V_127 = V_122 ;
V_109 -> V_116 = V_116 ;
return 0 ;
}
static int F_15 ( struct V_119 * V_120 ,
int V_128 , unsigned int V_121 , int V_129 )
{
struct V_105 * V_106 = V_120 -> V_106 ;
struct V_108 * V_109 = F_5 ( V_106 ) ;
switch ( V_128 ) {
case V_130 :
break;
case V_131 :
break;
default:
return - V_115 ;
}
if ( ( F_12 ( V_120 , V_121 ) ) < 0 ) {
F_16 ( V_106 -> V_2 , L_3 ,
V_120 -> V_132 ) ;
return - V_115 ;
}
V_109 -> V_125 = V_128 ;
return 0 ;
}
static int F_17 ( struct V_119 * V_133 , unsigned int V_134 )
{
struct V_105 * V_106 = V_133 -> V_106 ;
struct V_108 * V_109 = F_5 ( V_106 ) ;
T_2 V_135 = V_133 -> V_135 ;
unsigned int V_136 , V_137 ;
T_2 V_138 , V_139 ;
V_138 = F_18 ( V_106 , F_19 ( V_135 ) ) ;
V_139 = F_18 ( V_106 , F_20 ( V_135 ) ) ;
switch ( V_134 & V_140 ) {
case V_141 :
V_139 |= V_142 ;
break;
case V_143 :
V_139 &= ~ V_142 ;
break;
default:
return - V_115 ;
}
V_137 = ( V_134 & V_144 ) ;
V_136 = ( V_134 & V_145 ) ;
switch ( V_137 ) {
case V_146 :
V_138 &= ~ V_147 ;
break;
case V_148 :
case V_149 :
if ( V_139 & V_142 ) {
F_16 ( V_106 -> V_2 ,
L_4 ) ;
return - V_115 ;
}
if ( V_135 == V_150 ) {
F_16 ( V_106 -> V_2 ,
L_5 ) ;
return - V_115 ;
}
V_138 |= V_147 ;
break;
default:
return - V_115 ;
}
if ( V_138 & V_147 ) {
V_138 &= ~ ( V_151 | V_152 ) ;
switch ( V_137 ) {
case V_149 :
if ( V_136 == V_153 )
V_138 |= V_154 ;
if ( V_136 == V_155 )
V_138 |= V_156 ;
break;
case V_148 :
if ( V_136 == V_153 )
V_138 |= V_156 ;
break;
default:
return - V_115 ;
}
}
V_109 -> V_157 [ V_135 ] . V_138 = V_138 ;
V_109 -> V_157 [ V_135 ] . V_139 = V_139 ;
return 0 ;
}
static unsigned int F_21 ( T_1 V_158 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < F_10 ( V_159 ) ; V_113 ++ ) {
if ( V_159 [ V_113 ] == V_158 )
return V_113 + 1 ;
}
return 0 ;
}
static void F_22 ( struct V_105 * V_106 , int V_135 , int V_117 )
{
T_2 V_160 = 0 ;
if ( V_117 > 0 )
V_160 = F_21 ( V_117 ) ;
switch ( V_135 ) {
case V_161 :
F_23 ( V_106 , V_22 , 0x0f , V_160 ) ;
break;
case V_150 :
F_23 ( V_106 , V_18 , 0x3c , V_160 << 2 ) ;
break;
case V_162 :
F_23 ( V_106 , V_22 , 0xf0 , V_160 << 4 ) ;
break;
default:
break;
}
}
static int F_24 ( struct V_163 * V_164 ,
struct V_165 * V_166 ,
struct V_119 * V_120 )
{
struct V_105 * V_106 = V_120 -> V_106 ;
struct V_108 * V_109 = F_5 ( V_106 ) ;
int V_135 = V_120 -> V_135 ;
int V_167 ;
int V_117 = F_25 ( V_166 ) ;
if ( V_109 -> V_157 [ V_135 ] . V_139 & V_142 ) {
V_167 =
F_11 ( V_109 -> V_116 , V_117 ) ;
if ( V_167 < 0 )
return - V_115 ;
F_13 ( V_106 -> V_2 ,
L_6 ,
V_135 , V_109 -> V_116 , V_117 ,
V_118 [ V_167 ] . V_139 ) ;
V_109 -> V_157 [ V_135 ] . V_139 &= 0xC0 ;
V_109 -> V_157 [ V_135 ] . V_139 |= V_118 [ V_167 ] . V_139 ;
V_109 -> V_157 [ V_135 ] . V_138 &= 0xFC ;
if ( V_109 -> V_116 >= 6400000 )
V_109 -> V_157 [ V_135 ] . V_138 |= V_168 ;
else
V_109 -> V_157 [ V_135 ] . V_138 |= V_169 ;
} else {
V_109 -> V_157 [ V_135 ] . V_138 &= 0xFC ;
V_109 -> V_157 [ V_135 ] . V_138 |= V_168 ;
}
V_109 -> V_157 [ V_135 ] . V_117 = V_117 ;
F_14 ( V_106 , F_19 ( V_135 ) , V_109 -> V_157 [ V_135 ] . V_138 ) ;
F_14 ( V_106 , F_20 ( V_135 ) , V_109 -> V_157 [ V_135 ] . V_139 ) ;
F_22 ( V_106 , V_135 , V_117 ) ;
return 0 ;
}
static int F_26 ( struct V_105 * V_106 ,
enum V_170 V_171 )
{
struct V_108 * V_172 = F_5 ( V_106 ) ;
switch ( V_171 ) {
case V_173 :
F_23 ( V_106 , V_15 , V_174 , 0 ) ;
F_23 ( V_106 , V_10 , V_175 , 0 ) ;
break;
case V_176 :
break;
case V_177 :
if ( V_106 -> V_107 . V_178 == V_179 ) {
F_27 ( V_172 -> V_180 , false ) ;
F_28 ( V_172 -> V_180 ) ;
}
F_23 ( V_106 , V_10 , V_175 , 1 ) ;
break;
case V_179 :
F_23 ( V_106 , V_10 , V_175 , 1 ) ;
if ( V_172 -> V_111 > 0 ) {
F_29 ( V_172 -> V_111 ) ;
V_172 -> V_111 = 0 ;
} else {
F_29 ( 15 ) ;
}
F_23 ( V_106 , V_15 , V_174 , 1 ) ;
break;
}
V_106 -> V_107 . V_178 = V_171 ;
return 0 ;
}
static int F_30 ( struct V_119 * V_120 , int V_181 )
{
struct V_105 * V_106 = V_120 -> V_106 ;
int V_135 = V_120 -> V_135 ;
return F_23 ( V_106 , F_19 ( V_135 ) ,
0x7F , V_181 << 7 ) ;
}
static int F_31 ( struct V_163 * V_164 ,
struct V_119 * V_120 )
{
F_32 ( V_164 -> V_182 , 0 ,
V_183 ,
& V_184 ) ;
return 0 ;
}
static int F_33 ( struct V_105 * V_106 )
{
struct V_108 * V_172 = F_5 ( V_106 ) ;
if ( V_172 -> V_185 . V_186 )
F_23 ( V_106 , V_13 ,
V_187 ,
V_172 -> V_185 . V_186 << 4 ) ;
V_172 -> V_125 = V_130 ;
V_172 -> V_116 = 0 ;
return 0 ;
}
static int F_34 ( struct V_188 * V_188 ,
const struct V_189 * V_135 )
{
struct V_108 * V_172 ;
struct V_190 * V_185 = F_35 ( & V_188 -> V_2 ) ;
int V_191 ;
unsigned int V_192 = 0 ;
unsigned int V_3 ;
T_1 V_193 ;
V_172 = F_36 ( & V_188 -> V_2 , sizeof( struct V_108 ) ,
V_194 ) ;
if ( ! V_172 )
return - V_195 ;
V_172 -> V_180 = F_37 ( V_188 , & V_196 ) ;
if ( F_38 ( V_172 -> V_180 ) ) {
V_191 = F_39 ( V_172 -> V_180 ) ;
F_16 ( & V_188 -> V_2 , L_7 , V_191 ) ;
return V_191 ;
}
if ( V_185 ) {
V_172 -> V_185 = * V_185 ;
} else {
V_185 = F_36 ( & V_188 -> V_2 ,
sizeof( struct V_190 ) ,
V_194 ) ;
if ( ! V_185 ) {
F_16 ( & V_188 -> V_2 , L_8 ) ;
return - V_195 ;
}
if ( V_188 -> V_2 . V_197 ) {
if ( F_40 ( V_188 -> V_2 . V_197 ,
L_9 , & V_193 ) >= 0 )
V_185 -> V_186 = V_193 ;
}
V_185 -> V_198 = F_41 ( V_188 -> V_2 . V_197 ,
L_10 , 0 ) ;
V_172 -> V_185 = * V_185 ;
}
F_42 ( V_188 , V_172 ) ;
if ( V_172 -> V_185 . V_198 ) {
V_191 = F_43 ( & V_188 -> V_2 ,
V_172 -> V_185 . V_198 ,
V_199 ,
L_11 ) ;
if ( V_191 < 0 ) {
F_16 ( & V_188 -> V_2 , L_12 ,
V_172 -> V_185 . V_198 , V_191 ) ;
return V_191 ;
}
F_44 ( V_172 -> V_185 . V_198 , 0 ) ;
F_44 ( V_172 -> V_185 . V_198 , 1 ) ;
}
F_45 ( V_172 -> V_180 , true ) ;
V_191 = F_46 ( V_172 -> V_180 , V_6 , & V_3 ) ;
V_192 = ( V_3 & 0xFF ) << 12 ;
V_191 = F_46 ( V_172 -> V_180 , V_7 , & V_3 ) ;
V_192 |= ( V_3 & 0xFF ) << 4 ;
V_191 = F_46 ( V_172 -> V_180 , V_8 , & V_3 ) ;
V_192 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_192 != V_200 ) {
V_191 = - V_201 ;
F_16 ( & V_188 -> V_2 ,
L_13 ,
V_192 , V_200 ) ;
return V_191 ;
}
V_191 = F_46 ( V_172 -> V_180 , V_9 , & V_3 ) ;
if ( V_191 < 0 ) {
F_16 ( & V_188 -> V_2 , L_14 ) ;
return V_191 ; ;
}
F_47 ( & V_188 -> V_2 ,
L_15 , V_3 & 0xFF ) ;
F_45 ( V_172 -> V_180 , false ) ;
V_191 = F_48 ( & V_188 -> V_2 ,
& V_202 , V_203 ,
F_10 ( V_203 ) ) ;
if ( V_191 < 0 )
return V_191 ;
return 0 ;
}
static int F_49 ( struct V_188 * V_204 )
{
F_50 ( & V_204 -> V_2 ) ;
return 0 ;
}
