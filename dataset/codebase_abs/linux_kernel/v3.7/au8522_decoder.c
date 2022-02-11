static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , int V_5 )
{
int V_6 ;
F_4 ( V_4 , V_7 , 0x00 ) ;
F_4 ( V_4 , V_8 , 0x00 ) ;
F_4 ( V_4 , V_9 , 0x00 ) ;
F_4 ( V_4 , V_10 , 0x00 ) ;
F_4 ( V_4 , V_11 , 0x00 ) ;
F_4 ( V_4 , V_12 , 0x00 ) ;
F_4 ( V_4 , V_13 , 0x00 ) ;
F_4 ( V_4 , V_14 , 0x00 ) ;
F_4 ( V_4 , V_15 , 0x00 ) ;
F_4 ( V_4 , V_16 ,
0x00 ) ;
F_4 ( V_4 , V_17 ,
0x00 ) ;
F_4 ( V_4 , V_18 ,
0x00 ) ;
for ( V_6 = 0x30 ; V_6 < 0x60 ; V_6 ++ )
F_4 ( V_4 , V_6 , 0x40 ) ;
F_4 ( V_4 , 0x44 , 0x60 ) ;
F_4 ( V_4 , V_7 ,
V_19 ) ;
}
static void F_5 ( struct V_1 * V_4 , T_1 V_20 )
{
int V_6 ;
int V_21 ;
F_4 ( V_4 , V_22 , 0x07 ) ;
F_4 ( V_4 , V_23 , 0xed ) ;
V_4 -> V_24 = 0xed - 128 ;
F_4 ( V_4 , V_25 , 0x79 ) ;
V_4 -> V_26 = 0x79 ;
F_4 ( V_4 , V_27 , 0x80 ) ;
F_4 ( V_4 , V_28 , 0x80 ) ;
V_4 -> V_29 = 0x80 ;
F_4 ( V_4 , V_30 , 0x00 ) ;
F_4 ( V_4 , V_31 , 0x00 ) ;
V_4 -> V_32 = 0x00 ;
F_4 ( V_4 , V_33 , 0x00 ) ;
if ( V_20 == 0x23 ) {
F_4 ( V_4 , V_34 , 0x04 ) ;
} else {
F_4 ( V_4 , V_34 , 0x00 ) ;
}
F_4 ( V_4 , V_35 ,
V_36 ) ;
F_4 ( V_4 , V_37 ,
V_38 ) ;
F_4 ( V_4 , V_39 ,
V_40 ) ;
F_4 ( V_4 , V_41 ,
V_42 |
V_43 |
V_44 ) ;
F_4 ( V_4 , V_45 ,
V_46 ) ;
F_4 ( V_4 , V_47 ,
V_48 ) ;
F_4 ( V_4 , V_49 ,
V_50 ) ;
F_4 ( V_4 , V_51 ,
V_52 ) ;
F_4 ( V_4 , V_53 ,
V_54 ) ;
F_4 ( V_4 , V_55 ,
V_56 ) ;
F_4 ( V_4 , V_57 ,
V_58 ) ;
F_4 ( V_4 , V_59 ,
V_60 ) ;
F_4 ( V_4 , V_61 ,
V_62 ) ;
F_4 ( V_4 , V_63 ,
V_64 ) ;
if ( V_20 == V_65 ||
V_20 == V_66 ) {
F_4 ( V_4 , V_67 ,
V_68 ) ;
F_4 ( V_4 , V_69 ,
V_70 ) ;
} else {
F_4 ( V_4 , V_67 ,
V_71 ) ;
F_4 ( V_4 , V_69 ,
V_72 ) ;
}
F_4 ( V_4 , V_73 ,
V_74 ) ;
F_4 ( V_4 , V_75 ,
V_76 ) ;
F_4 ( V_4 , V_77 ,
V_78 ) ;
F_4 ( V_4 , V_79 , V_80 ) ;
F_4 ( V_4 , V_81 , V_82 ) ;
F_4 ( V_4 , V_83 ,
V_84 ) ;
F_4 ( V_4 , V_85 , V_86 ) ;
F_4 ( V_4 , V_87 , V_88 ) ;
F_4 ( V_4 , V_89 ,
V_90 ) ;
F_4 ( V_4 , V_91 ,
V_92 ) ;
F_4 ( V_4 , V_93 ,
V_94 ) ;
F_4 ( V_4 , V_95 ,
V_96 ) ;
F_4 ( V_4 , V_97 ,
V_98 ) ;
F_4 ( V_4 , V_99 ,
V_100 ) ;
F_4 ( V_4 , V_101 ,
V_102 ) ;
F_4 ( V_4 , V_103 , V_104 ) ;
F_3 ( V_4 , 0 ) ;
if ( V_20 == V_65 ||
V_20 == V_66 ) {
V_21 = 5 ;
} else {
V_21 = 5 ;
}
for ( V_6 = 0 ; V_6 < V_105 ; V_6 ++ ) {
F_4 ( V_4 , V_106 [ V_6 ] . V_107 ,
V_106 [ V_6 ] . V_108 [ V_21 ] ) ;
}
F_4 ( V_4 , V_109 , 0x87 ) ;
F_4 ( V_4 , V_110 , 0xa2 ) ;
F_4 ( V_4 , V_111 , 0xbf ) ;
F_4 ( V_4 , V_112 , 0xcb ) ;
F_4 ( V_4 , V_113 , 0xa1 ) ;
F_4 ( V_4 , V_114 , 0x41 ) ;
F_4 ( V_4 , V_115 , 0x88 ) ;
F_4 ( V_4 , V_116 , 0xc2 ) ;
F_4 ( V_4 , V_117 , 0x3c ) ;
}
static void F_6 ( struct V_1 * V_4 )
{
F_4 ( V_4 , V_118 ,
V_119 ) ;
F_4 ( V_4 , V_120 , 0x00 ) ;
F_4 ( V_4 , V_121 , 0x00 ) ;
F_4 ( V_4 , V_122 ,
V_123 ) ;
F_5 ( V_4 , V_123 ) ;
F_4 ( V_4 , V_124 ,
V_125 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
F_4 ( V_4 , V_118 ,
V_119 ) ;
F_4 ( V_4 , V_120 , 0x00 ) ;
F_4 ( V_4 , V_121 , 0x0e ) ;
F_4 ( V_4 , V_120 , 0x10 ) ;
F_4 ( V_4 , V_122 ,
V_126 ) ;
F_5 ( V_4 ,
V_126 ) ;
F_4 ( V_4 , V_124 ,
V_125 ) ;
}
static void F_8 ( struct V_1 * V_4 )
{
F_4 ( V_4 , V_118 ,
V_127 ) ;
F_4 ( V_4 , V_122 ,
V_65 ) ;
F_4 ( V_4 , V_120 , 0x00 ) ;
F_4 ( V_4 , V_121 , 0x00 ) ;
F_5 ( V_4 ,
V_65 ) ;
F_4 ( V_4 , V_124 ,
V_125 ) ;
}
static void F_9 ( struct V_1 * V_4 )
{
F_4 ( V_4 , V_128 , 0x00 ) ;
F_4 ( V_4 , V_129 , 0x00 ) ;
F_4 ( V_4 , V_130 , 0x00 ) ;
F_4 ( V_4 , V_131 , 0x04 ) ;
F_4 ( V_4 , V_132 , 0x02 ) ;
F_4 ( V_4 , V_124 ,
V_133 ) ;
}
static void F_10 ( struct V_1 * V_4 , int V_5 )
{
int V_6 ;
if ( V_5 == V_134 ) {
F_9 ( V_4 ) ;
return;
}
if ( V_5 != V_135 ) {
F_11 ( V_136 L_1 ,
V_5 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_137 ; V_6 ++ ) {
F_4 ( V_4 , V_138 [ V_6 ] . V_107 ,
V_138 [ V_6 ] . V_108 [ 0 ] ) ;
}
F_4 ( V_4 , V_128 , 0x00 ) ;
F_4 ( V_4 , V_129 , 0x00 ) ;
F_4 ( V_4 , V_130 , 0x00 ) ;
F_4 ( V_4 , V_139 , 0x80 ) ;
F_4 ( V_4 , V_140 , 0x84 ) ;
F_12 ( 150 ) ;
F_4 ( V_4 , V_124 , 0x00 ) ;
F_12 ( 1 ) ;
F_4 ( V_4 , V_124 , 0x9d ) ;
F_12 ( 50 ) ;
F_4 ( V_4 , V_128 , 0x7F ) ;
F_4 ( V_4 , V_129 , 0x7F ) ;
F_4 ( V_4 , V_130 , 0xff ) ;
F_12 ( 80 ) ;
F_4 ( V_4 , V_128 , 0x7F ) ;
F_4 ( V_4 , V_129 , 0x7F ) ;
F_4 ( V_4 , V_141 , V_142 ) ;
F_4 ( V_4 , V_143 , 0x82 ) ;
F_12 ( 70 ) ;
F_4 ( V_4 , V_131 , 0x09 ) ;
F_4 ( V_4 , V_144 , 0x03 ) ;
F_4 ( V_4 , V_132 , 0xc2 ) ;
}
static int F_13 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_146 -> V_147 ) {
case V_148 :
V_4 -> V_24 = V_146 -> V_149 ;
F_4 ( V_4 , V_23 ,
V_146 -> V_149 - 128 ) ;
break;
case V_150 :
V_4 -> V_26 = V_146 -> V_149 ;
F_4 ( V_4 , V_25 ,
V_146 -> V_149 ) ;
break;
case V_151 :
V_4 -> V_29 = V_146 -> V_149 ;
F_4 ( V_4 , V_27 ,
V_146 -> V_149 ) ;
F_4 ( V_4 , V_28 ,
V_146 -> V_149 ) ;
break;
case V_152 :
V_4 -> V_32 = V_146 -> V_149 ;
F_4 ( V_4 , V_30 ,
V_146 -> V_149 >> 8 ) ;
F_4 ( V_4 , V_31 ,
V_146 -> V_149 & 0xFF ) ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
default:
return - V_158 ;
}
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_146 -> V_147 ) {
case V_148 :
V_146 -> V_149 = V_4 -> V_24 ;
break;
case V_150 :
V_146 -> V_149 = V_4 -> V_26 ;
break;
case V_151 :
V_146 -> V_149 = V_4 -> V_29 ;
break;
case V_152 :
V_146 -> V_149 = V_4 -> V_32 ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
default:
return - V_158 ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_159 * V_160 )
{
struct V_161 * V_162 = F_16 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! F_17 ( V_162 , & V_160 -> V_163 ) )
return - V_158 ;
if ( ! F_18 ( V_164 ) )
return - V_165 ;
V_160 -> V_166 = F_19 ( V_4 , V_160 -> V_160 & 0xffff ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_159 * V_160 )
{
struct V_161 * V_162 = F_16 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! F_17 ( V_162 , & V_160 -> V_163 ) )
return - V_158 ;
if ( ! F_18 ( V_164 ) )
return - V_165 ;
F_4 ( V_4 , V_160 -> V_160 , V_160 -> V_166 & 0xff ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , int V_167 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_167 ) {
F_4 ( V_4 , V_124 ,
0x01 ) ;
F_12 ( 1 ) ;
F_4 ( V_4 , V_124 ,
V_125 ) ;
} else {
F_4 ( V_4 , V_124 ,
1 << 5 ) ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_168 * V_169 )
{
switch ( V_169 -> V_147 ) {
case V_150 :
return F_23 ( V_169 , 0 , 255 , 1 ,
V_170 ) ;
case V_148 :
return F_23 ( V_169 , 0 , 255 , 1 , 109 ) ;
case V_151 :
return F_23 ( V_169 , 0 , 255 , 1 , 128 ) ;
case V_152 :
return F_23 ( V_169 , - 32768 , 32768 , 1 , 0 ) ;
default:
break;
}
V_169 -> type = 0 ;
return - V_158 ;
}
static int F_24 ( struct V_2 * V_3 , T_2 V_166 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_171 = V_172 ;
V_4 -> V_173 = 0 ;
F_4 ( V_4 , 0xa4 , 1 << 5 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
T_2 V_174 , T_2 V_175 , T_2 V_176 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_24 ( V_3 , 0 ) ;
if ( V_174 == V_177 ) {
F_6 ( V_4 ) ;
} else if ( V_174 == V_178 ) {
F_8 ( V_4 ) ;
} else if ( V_174 == V_179 ) {
F_7 ( V_4 ) ;
} else {
F_11 ( V_136 L_2 ) ;
return - V_158 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
T_2 V_174 , T_2 V_175 , T_2 V_176 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_10 ( V_4 , V_174 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_180 * V_181 )
{
int V_166 = 0 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_182 ;
V_182 = F_19 ( V_4 , 0x00 ) ;
if ( V_182 == 0xa2 )
V_181 -> signal = 0xffff ;
else
V_181 -> signal = 0x00 ;
V_181 -> V_183 |=
V_184 | V_185 |
V_186 | V_187 ;
V_166 = V_188 ;
V_181 -> V_189 = V_166 ;
V_181 -> V_190 = V_191 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_192 * V_193 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_161 * V_162 = F_16 ( V_3 ) ;
return F_29 ( V_162 , V_193 , V_4 -> V_147 , V_4 -> V_194 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_31 ( struct V_161 * V_162 ,
const struct V_195 * V_196 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
int V_197 ;
struct V_198 * V_199 ;
if ( ! F_32 ( V_162 -> V_200 ,
V_201 ) ) {
return - V_202 ;
}
V_197 = F_33 ( & V_4 , V_162 -> V_200 , V_162 -> V_203 ) ;
switch ( V_197 ) {
case 0 :
F_11 ( V_136 L_3 ) ;
return - V_202 ;
case 1 :
F_11 ( V_204 L_4 ) ;
break;
default:
F_11 ( V_204 L_5 ) ;
break;
}
V_199 = F_34 ( sizeof( struct V_198 ) , V_205 ) ;
if ( V_199 == NULL ) {
if ( V_197 == 1 )
F_35 ( V_4 ) ;
return - V_206 ;
}
V_199 -> V_207 = 0x8e >> 1 ;
V_4 -> V_176 = V_199 ;
V_4 -> V_208 = V_162 -> V_200 ;
V_3 = & V_4 -> V_3 ;
F_36 ( V_3 , V_162 , & V_209 ) ;
V_4 -> V_210 = V_162 ;
V_4 -> V_211 = V_177 ;
V_4 -> V_5 = V_134 ;
V_4 -> V_147 = 8522 ;
V_4 -> V_194 = 0 ;
F_4 ( V_4 , 0x106 , 1 ) ;
return 0 ;
}
static int F_37 ( struct V_161 * V_162 )
{
struct V_2 * V_3 = F_38 ( V_162 ) ;
F_39 ( V_3 ) ;
F_40 ( F_1 ( V_3 ) ) ;
return 0 ;
}
