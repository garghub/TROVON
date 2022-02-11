static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , bool V_5 )
{
int V_6 ;
int V_7 ;
F_4 ( V_4 , V_8 , 0x07 ) ;
F_4 ( V_4 , V_9 , 0xed ) ;
F_4 ( V_4 , V_10 , 0x79 ) ;
F_4 ( V_4 , V_11 , 0x80 ) ;
F_4 ( V_4 , V_12 , 0x80 ) ;
F_4 ( V_4 , V_13 , 0x00 ) ;
F_4 ( V_4 , V_14 , 0x00 ) ;
F_4 ( V_4 , V_15 , 0x00 ) ;
if ( V_5 )
F_4 ( V_4 , V_16 , 0x04 ) ;
else
F_4 ( V_4 , V_16 , 0x00 ) ;
F_4 ( V_4 , V_17 ,
V_18 ) ;
F_4 ( V_4 , V_19 ,
V_20 ) ;
F_4 ( V_4 , V_21 ,
V_22 ) ;
if ( V_4 -> V_23 == V_24 ) {
F_4 ( V_4 , V_25 ,
V_26 |
V_27 |
V_28 ) ;
F_4 ( V_4 , V_29 ,
V_30 ) ;
} else {
F_4 ( V_4 , V_25 ,
V_26 |
V_27 |
V_31 ) ;
F_4 ( V_4 , V_29 ,
V_32 ) ;
}
F_4 ( V_4 , V_33 ,
V_34 ) ;
F_4 ( V_4 , V_35 ,
V_36 ) ;
F_4 ( V_4 , V_37 ,
V_38 ) ;
F_4 ( V_4 , V_39 ,
V_40 ) ;
F_4 ( V_4 , V_41 ,
V_42 ) ;
F_4 ( V_4 , V_43 ,
V_44 ) ;
F_4 ( V_4 , V_45 ,
V_46 ) ;
F_4 ( V_4 , V_47 ,
V_48 ) ;
F_4 ( V_4 , V_49 ,
V_50 ) ;
if ( V_5 ) {
F_4 ( V_4 , V_51 ,
V_52 ) ;
F_4 ( V_4 , V_53 ,
V_54 ) ;
} else {
F_4 ( V_4 , V_51 ,
V_55 ) ;
F_4 ( V_4 , V_53 ,
V_56 ) ;
}
F_4 ( V_4 , V_57 ,
V_58 ) ;
F_4 ( V_4 , V_59 ,
V_60 ) ;
F_4 ( V_4 , V_61 ,
V_62 ) ;
F_4 ( V_4 , V_63 , V_64 ) ;
F_4 ( V_4 , V_65 , V_66 ) ;
F_4 ( V_4 , V_67 ,
V_68 ) ;
F_4 ( V_4 , V_69 , V_70 ) ;
F_4 ( V_4 , V_71 , V_72 ) ;
F_4 ( V_4 , V_73 ,
V_74 ) ;
F_4 ( V_4 , V_75 ,
V_76 ) ;
F_4 ( V_4 , V_77 ,
V_78 ) ;
F_4 ( V_4 , V_79 ,
V_80 ) ;
F_4 ( V_4 , V_81 ,
V_82 ) ;
F_4 ( V_4 , V_83 ,
V_84 ) ;
F_4 ( V_4 , V_85 ,
V_86 ) ;
F_4 ( V_4 , V_87 , V_88 ) ;
if ( V_5 ) {
V_7 = 5 ;
} else {
V_7 = 5 ;
}
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
F_4 ( V_4 , V_90 [ V_6 ] . V_91 ,
V_90 [ V_6 ] . V_92 [ V_7 ] ) ;
}
F_4 ( V_4 , V_93 , 0x87 ) ;
F_4 ( V_4 , V_94 , 0xa2 ) ;
F_4 ( V_4 , V_95 , 0xbf ) ;
F_4 ( V_4 , V_96 , 0xcb ) ;
F_4 ( V_4 , V_97 , 0xa1 ) ;
F_4 ( V_4 , V_98 , 0x41 ) ;
F_4 ( V_4 , V_99 , 0x88 ) ;
F_4 ( V_4 , V_100 , 0xc2 ) ;
F_4 ( V_4 , V_101 , 0x3c ) ;
}
static void F_5 ( struct V_1 * V_4 , T_1 V_102 )
{
F_4 ( V_4 , V_103 ,
V_104 ) ;
F_4 ( V_4 , V_105 , 0x00 ) ;
F_4 ( V_4 , V_106 , 0x00 ) ;
F_4 ( V_4 , V_107 , V_102 ) ;
F_3 ( V_4 , false ) ;
F_4 ( V_4 , V_108 ,
V_109 ) ;
}
static void F_6 ( struct V_1 * V_4 ,
T_1 V_102 )
{
F_4 ( V_4 , V_103 ,
V_104 ) ;
F_4 ( V_4 , V_105 , 0x00 ) ;
F_4 ( V_4 , V_106 , 0x0e ) ;
F_4 ( V_4 , V_105 , 0x10 ) ;
F_4 ( V_4 , V_107 , V_102 ) ;
F_3 ( V_4 , false ) ;
F_4 ( V_4 , V_108 ,
V_109 ) ;
}
static void F_7 ( struct V_1 * V_4 ,
T_1 V_102 )
{
F_4 ( V_4 , V_103 ,
V_110 ) ;
F_4 ( V_4 , V_107 , V_102 ) ;
F_4 ( V_4 , V_105 , 0x00 ) ;
F_4 ( V_4 , V_106 , 0x00 ) ;
F_3 ( V_4 , true ) ;
F_4 ( V_4 , V_108 ,
V_109 ) ;
}
static void F_8 ( struct V_1 * V_4 )
{
F_4 ( V_4 , V_111 , 0x00 ) ;
F_4 ( V_4 , V_112 , 0x00 ) ;
F_4 ( V_4 , V_113 , 0x00 ) ;
F_4 ( V_4 , V_114 , 0x04 ) ;
F_4 ( V_4 , V_115 , 0x02 ) ;
F_4 ( V_4 , V_108 ,
V_116 ) ;
}
static void F_9 ( struct V_1 * V_4 )
{
int V_117 = V_4 -> V_117 ;
int V_6 ;
if ( V_117 == V_118 ) {
F_8 ( V_4 ) ;
return;
}
if ( V_117 != V_119 ) {
F_10 ( V_120 L_1 ,
V_117 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_121 ; V_6 ++ ) {
F_4 ( V_4 , V_122 [ V_6 ] . V_91 ,
V_122 [ V_6 ] . V_92 [ 0 ] ) ;
}
F_4 ( V_4 , V_111 , 0x7F ) ;
F_4 ( V_4 , V_112 , 0x7F ) ;
F_4 ( V_4 , V_113 , 0xff ) ;
F_4 ( V_4 , V_123 , V_124 ) ;
F_4 ( V_4 , V_125 , 0x82 ) ;
F_11 ( 70 ) ;
F_4 ( V_4 , V_108 , 0x9d ) ;
F_4 ( V_4 , V_126 , 0x03 ) ;
F_4 ( V_4 , V_115 , 0xc2 ) ;
F_4 ( V_4 , V_114 , 0x09 ) ;
}
static int F_12 ( struct V_127 * V_128 )
{
struct V_1 * V_4 =
F_2 ( V_128 -> V_129 , struct V_1 , V_130 ) ;
switch ( V_128 -> V_131 ) {
case V_132 :
F_4 ( V_4 , V_9 ,
V_128 -> V_133 - 128 ) ;
break;
case V_134 :
F_4 ( V_4 , V_10 ,
V_128 -> V_133 ) ;
break;
case V_135 :
F_4 ( V_4 , V_11 ,
V_128 -> V_133 ) ;
F_4 ( V_4 , V_12 ,
V_128 -> V_133 ) ;
break;
case V_136 :
F_4 ( V_4 , V_13 ,
V_128 -> V_133 >> 8 ) ;
F_4 ( V_4 , V_14 ,
V_128 -> V_133 & 0xFF ) ;
break;
default:
return - V_137 ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_138 * V_139 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_139 -> V_133 = F_14 ( V_4 , V_139 -> V_139 & 0xffff ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_138 * V_139 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 , V_139 -> V_139 , V_139 -> V_133 & 0xff ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_4 )
{
T_1 V_102 ;
F_4 ( V_4 , 0xa4 , 1 << 5 ) ;
switch ( V_4 -> V_140 ) {
case V_141 :
V_102 = V_142 ;
F_5 ( V_4 , V_102 ) ;
break;
case V_143 :
V_102 = V_144 ;
F_5 ( V_4 , V_102 ) ;
break;
case V_145 :
V_102 = V_146 ;
F_5 ( V_4 , V_102 ) ;
break;
case V_147 :
V_102 = V_148 ;
F_5 ( V_4 , V_102 ) ;
break;
case V_149 :
V_102 = V_150 ;
F_7 ( V_4 , V_102 ) ;
break;
case V_151 :
V_102 = V_152 ;
F_7 ( V_4 , V_102 ) ;
break;
default:
case V_153 :
V_102 = V_154 ;
F_6 ( V_4 , V_102 ) ;
break;
}
}
static int F_17 ( struct V_2 * V_3 , int V_155 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_155 ) {
V_4 -> V_156 = 0 ;
F_4 ( V_4 , V_108 ,
0x01 ) ;
F_11 ( 10 ) ;
F_16 ( V_4 ) ;
F_9 ( V_4 ) ;
V_4 -> V_157 = V_158 ;
} else {
F_4 ( V_4 , V_108 ,
1 << 5 ) ;
V_4 -> V_157 = V_159 ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
T_2 V_160 , T_2 V_161 , T_2 V_162 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch( V_160 ) {
case V_141 :
case V_149 :
case V_153 :
V_4 -> V_140 = V_160 ;
break;
default:
F_10 ( V_120 L_2 ) ;
return - V_137 ;
}
if ( V_4 -> V_157 == V_158 )
F_16 ( V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_3 V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ( V_23 & ( V_24 | V_163 ) ) == 0 )
return - V_137 ;
V_4 -> V_23 = V_23 ;
if ( V_4 -> V_157 == V_158 )
F_16 ( V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
T_2 V_160 , T_2 V_161 , T_2 V_162 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_117 = V_160 ;
if ( V_4 -> V_157 == V_158 )
F_9 ( V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_164 * V_165 )
{
int V_133 = 0 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_166 ;
T_1 V_167 ;
V_166 = F_14 ( V_4 , 0x00 ) ;
V_167 = F_14 ( V_4 , 0x7e ) ;
if ( ( V_166 == 0xa2 ) && ( V_167 & 0x10 ) )
V_165 -> signal = 0xffff ;
else
V_165 -> signal = 0x00 ;
V_165 -> V_168 |=
V_169 | V_170 |
V_171 | V_172 ;
V_133 = V_173 ;
V_165 -> V_174 = V_133 ;
V_165 -> V_175 = V_176 ;
return 0 ;
}
static int F_22 ( struct V_177 * V_178 ,
const struct V_179 * V_180 )
{
struct V_1 * V_4 ;
struct V_181 * V_130 ;
struct V_2 * V_3 ;
int V_182 ;
#ifdef F_23
int V_183 ;
#endif
if ( ! F_24 ( V_178 -> V_184 ,
V_185 ) ) {
return - V_186 ;
}
V_182 = F_25 ( & V_4 , V_178 -> V_184 , V_178 -> V_187 ) ;
switch ( V_182 ) {
case 0 :
F_10 ( V_120 L_3 ) ;
return - V_186 ;
case 1 :
F_10 ( V_188 L_4 ) ;
break;
default:
F_10 ( V_188 L_5 ) ;
break;
}
V_4 -> V_162 . V_189 = 0x8e >> 1 ;
V_4 -> V_190 = V_178 -> V_184 ;
V_3 = & V_4 -> V_3 ;
F_26 ( V_3 , V_178 , & V_191 ) ;
#if F_27 ( F_23 )
V_4 -> V_192 [ V_193 ] . V_194 = V_195 ;
V_4 -> V_192 [ V_196 ] . V_194 = V_197 ;
V_4 -> V_192 [ V_198 ] . V_194 = V_197 ;
V_4 -> V_192 [ V_199 ] . V_194 = V_197 ;
V_3 -> V_200 . V_201 = V_202 ;
V_183 = F_28 ( & V_3 -> V_200 , F_29 ( V_4 -> V_192 ) ,
V_4 -> V_192 ) ;
if ( V_183 < 0 ) {
F_30 ( V_178 , L_6 ) ;
return V_183 ;
}
#endif
V_130 = & V_4 -> V_130 ;
F_31 ( V_130 , 4 ) ;
F_32 ( V_130 , & V_203 ,
V_132 , 0 , 255 , 1 , 109 ) ;
F_32 ( V_130 , & V_203 ,
V_134 , 0 , 255 , 1 ,
V_204 ) ;
F_32 ( V_130 , & V_203 ,
V_135 , 0 , 255 , 1 , 128 ) ;
F_32 ( V_130 , & V_203 ,
V_136 , - 32768 , 32767 , 1 , 0 ) ;
V_3 -> V_205 = V_130 ;
if ( V_130 -> error ) {
int V_206 = V_130 -> error ;
F_33 ( V_130 ) ;
F_34 ( V_4 ) ;
return V_206 ;
}
V_4 -> V_207 = V_178 ;
V_4 -> V_23 = V_163 ;
V_4 -> V_140 = V_141 ;
V_4 -> V_117 = V_118 ;
V_4 -> V_131 = 8522 ;
V_4 -> V_208 = 0 ;
F_4 ( V_4 , 0x106 , 1 ) ;
return 0 ;
}
static int F_35 ( struct V_177 * V_178 )
{
struct V_2 * V_3 = F_36 ( V_178 ) ;
F_37 ( V_3 ) ;
F_33 ( V_3 -> V_205 ) ;
F_34 ( F_1 ( V_3 ) ) ;
return 0 ;
}
