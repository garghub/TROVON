static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1
L_2
L_3 ,
V_2 -> V_3 , V_2 -> V_3 , V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
switch ( V_4 ) {
case V_6 :
F_4 ( V_7 >> 2 , 0x00008000 , 0x00000000 ) ;
F_4 ( V_7 >> 2 , 0x00008000 , 0x00008000 ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
case V_10 :
F_5 ( V_2 , 23 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 23 , 1 ) ;
break;
case V_11 :
F_5 ( V_2 , 21 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 21 , 1 ) ;
break;
case V_12 :
F_5 ( V_2 , 18 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 18 , 1 ) ;
break;
}
return 0 ;
}
return - V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
switch ( V_2 -> V_8 ) {
case V_14 :
case V_15 :
case V_16 :
if ( V_4 == V_17 ) {
F_8 ( V_18 , 0x00 ) ;
F_6 ( 10 ) ;
F_8 ( V_18 , 0x01 ) ;
F_6 ( 10 ) ;
}
break;
default:
F_4 ( V_19 >> 2 , 0x06e20000 , 0x06e20000 ) ;
F_4 ( V_7 >> 2 , 0x06a20000 , 0x06a20000 ) ;
F_4 ( V_20 >> 2 , 0x02 , 0x02 ) ;
F_4 ( V_21 >> 2 , 0x81 , 0x81 ) ;
F_4 ( V_22 >> 2 , 0x03187de7 , 0x03187de7 ) ;
F_4 ( V_23 >> 2 , 0x03 , 0x03 ) ;
F_4 ( V_24 >> 2 ,
0x0001e000 , 0x0001e000 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
T_1 V_25 ;
switch ( V_4 ) {
case 0 :
F_5 ( V_2 , 22 , V_5 ) ;
break;
case 1 :
F_10 ( V_26 , 0x80 , 0x80 ) ;
F_10 ( V_27 , 0x0f , 0x03 ) ;
if ( V_5 == 1 )
V_25 = 11 ;
else
V_25 = 17 ;
F_8 ( V_28 , V_25 ) ;
F_8 ( V_29 , V_25 + 1 ) ;
F_10 ( V_30 , 0x03 , 0x00 ) ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
enum V_31 V_32 )
{
switch ( V_32 ) {
case V_33 :
F_5 ( V_2 , 26 , 0 ) ;
break;
case V_34 :
F_5 ( V_2 , 26 , 1 ) ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static inline int F_12 ( struct V_1 * V_2 ,
enum V_31 V_32 )
{
switch ( V_32 ) {
case V_33 :
F_13 ( V_19 >> 2 , 0x4000 ) ;
F_13 ( V_7 >> 2 , 0x4000 ) ;
F_6 ( 20 ) ;
break;
case V_34 :
F_13 ( V_19 >> 2 , 0x14000 ) ;
F_13 ( V_7 >> 2 , 0x14000 ) ;
F_6 ( 20 ) ;
F_13 ( V_19 >> 2 , 0x54000 ) ;
F_13 ( V_7 >> 2 , 0x54000 ) ;
F_6 ( 30 ) ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
int V_35 = 0 ;
switch ( V_4 ) {
case V_36 :
switch ( V_2 -> V_8 ) {
case V_37 :
case V_38 :
case V_39 :
V_35 = F_11 ( V_2 , V_5 ) ;
break;
case V_40 :
V_35 = F_12 ( V_2 , V_5 ) ;
break;
default:
break;
}
break;
default:
V_35 = - V_13 ;
break;
}
return V_35 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
int V_35 ;
switch ( V_2 -> V_8 ) {
case V_37 :
case V_38 :
case V_41 :
case V_40 :
case V_39 :
V_35 = F_14 ( V_2 , V_4 , V_5 ) ;
break;
default:
V_35 = F_9 ( V_2 , V_4 , V_5 ) ;
break;
}
return V_35 ;
}
int F_16 ( void * V_42 , int V_43 , int V_4 , int V_5 )
{
struct V_1 * V_2 = V_42 ;
if ( V_2 != NULL ) {
switch ( V_2 -> V_44 ) {
case V_45 :
return F_15 ( V_2 , V_4 , V_5 ) ;
case V_46 :
return F_3 ( V_2 , V_4 , V_5 ) ;
case V_47 :
return F_7 ( V_2 , V_4 , V_5 ) ;
}
} else {
F_2 ( V_48 L_4 ) ;
return - V_13 ;
}
return - V_13 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 * V_49 )
{
struct V_50 V_51 ;
F_18 ( & V_2 -> V_52 , & V_51 , V_49 ) ;
switch ( V_51 . V_53 ) {
case 67019 :
case 67109 :
case 67201 :
case 67301 :
case 67209 :
case 67559 :
case 67569 :
case 67579 :
case 67589 :
case 67599 :
case 67651 :
case 67659 :
break;
default:
F_2 ( V_54 L_5
L_6 , V_2 -> V_3 , V_51 . V_53 ) ;
break;
}
F_2 ( V_55 L_7 ,
V_2 -> V_3 , V_51 . V_53 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
F_13 ( V_19 >> 2 , 0 ) ;
V_2 -> V_56 = F_20 ( V_7 >> 2 ) ;
F_2 ( V_55 L_8 , V_2 -> V_3 , V_2 -> V_56 ) ;
switch ( V_2 -> V_8 ) {
case V_57 :
case V_58 :
case V_59 :
V_2 -> V_60 = V_61 ;
F_1 ( V_2 ) ;
break;
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
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_2 -> V_60 = V_61 ;
break;
case V_128 :
F_8 ( V_129 , 0x80 ) ;
F_8 ( V_130 , 0x40 ) ;
V_2 -> V_60 = V_61 ;
break;
case V_131 :
F_2 ( L_9
L_10
L_11 ,
V_2 -> V_3 , V_2 -> V_3 , V_2 -> V_3 ) ;
break;
case V_132 :
F_4 ( V_19 >> 2 , 0x00040000 , 0x00040000 ) ;
F_4 ( V_7 >> 2 , 0x00040000 , 0x00000000 ) ;
break;
case V_133 :
F_8 ( V_134 , 0x80 ) ;
F_8 ( V_135 , 0x80 ) ;
break;
case V_136 :
F_4 ( V_19 >> 2 , 0x00040000 , 0x00040000 ) ;
F_4 ( V_7 >> 2 , 0x00040000 , 0x00000004 ) ;
break;
case V_137 :
F_8 ( V_129 , 0x08 ) ;
F_8 ( V_138 , 0x06 ) ;
break;
case V_139 :
case V_140 :
F_4 ( V_19 >> 2 , 0x08000000 , 0x08000000 ) ;
F_4 ( V_7 >> 2 , 0x08000000 , 0x00000000 ) ;
break;
case V_141 :
case V_142 :
F_4 ( V_19 >> 2 , 0xffffffff , 0 ) ;
F_4 ( V_7 >> 2 , 0xffffffff , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_19 >> 2 , 0xffffffff , 0xffffffff ) ;
F_4 ( V_7 >> 2 , 0xffffffff , 0xffffffff ) ;
F_6 ( 10 ) ;
break;
case V_143 :
F_4 ( V_19 >> 2 , 0x08400000 , 0x08400000 ) ;
F_4 ( V_7 >> 2 , 0x08400000 , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_19 >> 2 , 0x08400000 , 0x08400000 ) ;
F_4 ( V_7 >> 2 , 0x08400000 , 0x08400000 ) ;
F_6 ( 10 ) ;
V_2 -> V_60 = V_144 ;
break;
case V_9 :
F_5 ( V_2 , 23 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 23 , 1 ) ;
V_2 -> V_60 = V_144 ;
break;
case V_10 :
F_5 ( V_2 , 23 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 23 , 1 ) ;
break;
case V_11 :
F_5 ( V_2 , 21 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 21 , 1 ) ;
F_6 ( 1 ) ;
V_2 -> V_60 = V_61 ;
break;
case V_145 :
F_4 ( V_19 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_4 ( V_7 >> 2 , 0x000A8004 , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_19 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_4 ( V_7 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_6 ( 10 ) ;
V_2 -> V_60 = V_61 ;
break;
case V_146 :
F_8 ( V_147 , 0x00 ) ;
break;
case V_37 :
case V_38 :
V_2 -> V_60 = V_61 ;
F_5 ( V_2 , 26 , 0 ) ;
F_6 ( 1 ) ;
F_5 ( V_2 , 22 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 22 , 1 ) ;
break;
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_14 :
case V_15 :
case V_16 :
V_2 -> V_60 = V_144 ;
break;
case V_165 :
F_2 ( L_12
L_13
L_14 ,
V_2 -> V_3 , F_21 ( V_2 ) . V_3 , V_2 -> V_3 , V_2 -> V_3 ) ;
break;
case V_166 :
V_2 -> V_60 = V_61 ;
F_4 ( V_19 >> 2 , 0x8c040007 , 0x8c040007 ) ;
F_4 ( V_7 >> 2 , 0x0c0007cd , 0x0c0007cd ) ;
break;
case V_12 :
case V_167 :
F_4 ( V_19 >> 2 , 0x80040100 , 0x80040100 ) ;
F_4 ( V_7 >> 2 , 0x80040100 , 0x00040100 ) ;
break;
case V_168 :
V_2 -> V_60 = V_61 ;
F_4 ( V_19 >> 2 , 0x0000C000 , 0x0000C000 ) ;
F_4 ( V_7 >> 2 , 0x0000C000 , 0x0000C000 ) ;
break;
case V_41 :
F_5 ( V_2 , 1 , 1 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 1 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 1 , 1 ) ;
V_2 -> V_60 = V_61 ;
break;
case V_39 :
F_4 ( V_19 >> 2 , 0x0e050000 , 0x0c050000 ) ;
F_4 ( V_7 >> 2 , 0x0e050000 , 0x0c050000 ) ;
break;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_169 V_170 ;
unsigned int V_171 = V_172 | V_173 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_174 = F_16 ;
if ( V_175 [ V_2 -> V_8 ] . V_176 != V_177 ) {
V_170 . type = V_175 [ V_2 -> V_8 ] . V_176 ;
V_170 . V_178 = V_175 [ V_2 -> V_8 ] . V_179 ;
V_170 . V_171 = V_172 ;
F_23 ( V_2 , V_180 , V_181 , & V_170 ) ;
V_171 &= ~ V_172 ;
}
if ( ( V_2 -> V_44 != V_182 ) && ( V_2 -> V_44 != V_177 ) ) {
V_170 . type = V_2 -> V_44 ;
V_170 . V_178 = V_2 -> V_183 ;
V_170 . V_184 = V_175 [ V_2 -> V_8 ] . V_185 ;
V_170 . V_174 = F_16 ;
V_170 . V_171 = V_171 ;
F_23 ( V_2 , V_180 , V_181 , & V_170 ) ;
}
if ( V_2 -> V_186 ) {
struct V_187 V_188 ;
V_188 . V_180 = V_189 ;
V_188 . V_42 = & V_2 -> V_186 ;
F_23 ( V_2 , V_180 , V_190 , & V_188 ) ;
}
if ( V_2 -> V_44 == V_46 ) {
struct V_187 V_191 ;
struct V_192 V_193 ;
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_194 = V_195 ;
V_193 . V_196 = 64 ;
switch ( V_2 -> V_8 ) {
case V_11 :
case V_9 :
case V_10 :
case V_12 :
V_193 . V_197 = V_198 ;
break;
default:
V_193 . V_197 = V_199 ;
V_193 . V_200 = 1 ;
}
V_191 . V_180 = V_46 ;
V_191 . V_42 = & V_193 ;
F_23 ( V_2 , V_180 , V_190 , & V_191 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
unsigned char V_201 ;
int V_8 ;
switch ( V_2 -> V_8 ) {
case V_202 :
case V_203 :
V_2 -> V_52 . V_178 = 0x60 ;
V_8 = ( F_25 ( & V_2 -> V_52 , & V_201 , 0 ) < 0 )
? V_202
: V_203 ;
if ( V_8 == V_2 -> V_8 )
break;
V_2 -> V_8 = V_8 ;
F_2 ( L_15 , V_2 -> V_3 ,
V_175 [ V_2 -> V_8 ] . V_3 ) ;
V_2 -> V_44 = V_175 [ V_2 -> V_8 ] . V_44 ;
break;
case V_204 :
{
T_1 V_205 ;
T_1 V_206 [ 3 ] ;
int V_35 , V_207 ;
struct V_208 V_209 [] = { { . V_178 = 0x50 , . V_210 = 0 , . V_201 = & V_205 , . V_211 = 1 } ,
{ . V_178 = 0x50 , . V_210 = V_212 , . V_201 = V_206 , . V_211 = 3 } } ;
V_205 = 0x14 ;
V_207 = 0 ;
V_35 = F_26 ( & V_2 -> V_213 , V_209 , 2 ) ;
if ( V_35 != 2 ) {
F_2 ( V_48 L_16 ) ;
} else if ( ( V_206 [ 0 ] != 0 ) && ( V_206 [ 0 ] != 0xff ) ) {
V_205 = V_206 [ 0 ] + 2 ;
V_209 [ 1 ] . V_211 = 2 ;
F_26 ( & V_2 -> V_213 , V_209 , 2 ) ;
V_207 = ( V_206 [ 0 ] << 8 ) + V_206 [ 1 ] ;
switch ( V_207 ) {
case 0x0103 :
V_2 -> V_44 = V_214 ;
break;
case 0x010C :
V_2 -> V_44 = V_215 ;
break;
default:
F_2 ( V_48 L_17 , V_2 -> V_3 , V_207 ) ;
}
} else if ( ( V_206 [ 1 ] != 0 ) && ( V_206 [ 1 ] != 0xff ) ) {
V_205 = V_206 [ 1 ] + 1 ;
V_209 [ 1 ] . V_211 = 1 ;
F_26 ( & V_2 -> V_213 , V_209 , 2 ) ;
V_205 = V_206 [ 0 ] + 1 ;
V_209 [ 1 ] . V_211 = 2 ;
F_26 ( & V_2 -> V_213 , V_209 , 2 ) ;
V_207 = ( V_206 [ 1 ] << 8 ) + V_206 [ 0 ] ;
switch ( V_207 ) {
case 0x0005 :
V_2 -> V_44 = V_215 ;
break;
case 0x001d :
V_2 -> V_44 = V_216 ;
F_2 ( V_55 L_18 , V_2 -> V_3 ) ;
break;
default:
F_2 ( V_48 L_17 , V_2 -> V_3 , V_207 ) ;
}
} else {
F_2 ( V_48 L_19 , V_2 -> V_3 ) ;
}
F_2 ( V_55 L_20 , V_2 -> V_3 , V_2 -> V_44 ) ;
break;
}
case V_217 :
if ( V_2 -> V_218 && ( V_2 -> V_219 [ 0x41 ] == 0x1c ) ) {
V_2 -> V_8 = V_220 ;
V_2 -> V_44 = V_175 [ V_2 -> V_8 ] . V_44 ;
F_2 ( V_55 L_21 ,
V_2 -> V_3 , V_175 [ V_2 -> V_8 ] . V_3 ) ;
break;
}
case V_86 :
case V_221 :
case V_222 :
case V_223 :
{
T_1 V_206 [] = { 0x07 , 0x02 } ;
struct V_208 V_209 = { . V_178 = 0x08 , . V_210 = 0 , . V_201 = V_206 , . V_211 = sizeof( V_206 ) } ;
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
break;
}
case V_224 :
case V_225 :
{
T_1 V_206 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_208 V_209 = { . V_178 = 0x08 , . V_210 = 0 , . V_201 = V_206 , . V_211 = sizeof( V_206 ) } ;
if ( V_2 -> V_218 && ( V_2 -> V_219 [ 0x49 ] == 0x50 ) ) {
V_2 -> V_8 = V_225 ;
F_2 ( V_55 L_21 ,
V_2 -> V_3 , V_175 [ V_2 -> V_8 ] . V_3 ) ;
}
if ( V_2 -> V_8 == V_225 ) {
V_2 -> V_44 = V_45 ;
V_206 [ 2 ] = 0x68 ;
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
break;
}
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
break;
}
case V_226 :
if ( V_2 -> V_218 && ( V_2 -> V_219 [ 0x27 ] == 0x03 ) ) {
V_2 -> V_8 = V_99 ;
F_2 ( V_55 L_22
L_23 ,
V_2 -> V_3 , V_175 [ V_2 -> V_8 ] . V_3 ) ;
V_2 -> V_60 = V_61 ;
F_27 ( V_2 ) ;
}
break;
case V_37 :
case V_38 :
F_17 ( V_2 , V_2 -> V_219 + 0x80 ) ;
break;
case V_152 :
F_17 ( V_2 , V_2 -> V_219 + 0x80 ) ;
case V_149 :
case V_227 :
case V_228 :
case V_229 :
case V_97 :
case V_98 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
{
T_1 V_206 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_208 V_209 = { . V_178 = 0x08 , . V_210 = 0 , . V_201 = V_206 , . V_211 = sizeof( V_206 ) } ;
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
break;
}
case V_234 :
{
T_1 V_206 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_208 V_209 = { . V_178 = 0x0b , . V_210 = 0 , . V_201 = V_206 ,
. V_211 = sizeof( V_206 ) } ;
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
break;
}
case V_235 :
{
T_1 V_236 = 0 ;
int V_237 ;
T_1 V_206 [] = { 0x3c , 0x33 , 0x62 } ;
struct V_208 V_209 = { . V_178 = 0x09 , . V_210 = 0 , . V_201 = V_206 , . V_211 = sizeof( V_206 ) } ;
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
V_209 . V_201 = & V_236 ;
V_209 . V_178 = 0x0b ;
V_209 . V_211 = 1 ;
if ( 1 != F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ) {
F_2 ( V_54 L_24
L_25 , V_2 -> V_3 ) ;
} else {
V_209 . V_210 = V_212 ;
V_237 = F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
F_2 ( V_55 L_26 ,
V_2 -> V_3 , V_209 . V_178 ,
( 1 == V_237 ) ? L_27 : L_28 ) ;
if ( V_237 == 1 )
V_2 -> V_60 = V_144 ;
}
break;
}
case V_139 :
case V_140 :
{
T_1 V_206 [] = { 0x3c , 0x33 , 0x6a } ;
struct V_208 V_209 = { . V_178 = 0x08 , . V_210 = 0 , . V_201 = V_206 , . V_211 = sizeof( V_206 ) } ;
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
break;
}
case V_238 :
case V_239 :
{
T_1 V_206 [] = { 0x3c , 0x33 , 0x68 } ;
struct V_208 V_209 = { . V_178 = 0x08 , . V_210 = 0 , . V_201 = V_206 , . V_211 = sizeof( V_206 ) } ;
F_26 ( & V_2 -> V_213 , & V_209 , 1 ) ;
break;
}
case V_87 :
case V_88 :
if ( ! V_2 -> V_218 || ( V_2 -> V_219 [ 0x41 ] == 0xd0 ) )
break;
if ( V_2 -> V_219 [ 0x41 ] == 0x02 ) {
V_2 -> V_8 = V_88 ;
V_2 -> V_44 = V_175 [ V_2 -> V_8 ] . V_44 ;
V_2 -> V_186 = V_175 [ V_2 -> V_8 ] . V_186 ;
F_2 ( V_55 L_21 ,
V_2 -> V_3 , V_175 [ V_2 -> V_8 ] . V_3 ) ;
} else {
F_2 ( V_54 L_29 ,
V_2 -> V_3 , V_2 -> V_219 [ 0x41 ] ) ;
break;
}
break;
case V_240 :
case V_241 :
{
struct V_208 V_209 = { . V_178 = 0x0a , . V_210 = 0 } ;
int V_242 ;
static T_1 V_243 [] [ 2 ] = {
{ 0x10 , 0x12 } ,
{ 0x13 , 0x04 } ,
{ 0x16 , 0x00 } ,
{ 0x14 , 0x04 } ,
{ 0x17 , 0x00 } ,
} ;
for ( V_242 = 0 ; V_242 < F_28 ( V_243 ) ; V_242 ++ ) {
V_209 . V_201 = & V_243 [ V_242 ] [ 0 ] ;
V_209 . V_211 = F_28 ( V_243 [ 0 ] ) ;
if ( F_26 ( & V_2 -> V_213 , & V_209 , 1 ) != 1 )
F_2 ( V_54
L_30 ,
V_2 -> V_3 , V_242 ) ;
}
break;
}
case V_164 :
{
T_1 V_206 [] = { 0x09 , 0x9f , 0x86 , 0x11 } ;
struct V_208 V_209 = { . V_178 = 0x61 , . V_210 = 0 , . V_201 = V_206 ,
. V_211 = sizeof( V_206 ) } ;
if ( F_26 ( & V_2 -> V_213 , & V_209 , 1 ) != 1 )
F_2 ( V_54
L_31 ,
V_2 -> V_3 ) ;
break;
}
case V_40 :
F_13 ( V_19 >> 2 , 0x4000 ) ;
F_13 ( V_7 >> 2 , 0x4000 ) ;
F_5 ( V_2 , 27 , 0 ) ;
break;
}
if ( V_182 != V_2 -> V_44 ) {
int V_244 = ( V_2 -> V_186 & V_245 ) ;
if ( V_2 -> V_176 != V_177 )
F_29 ( & V_2 -> V_246 ,
& V_2 -> V_213 , L_32 ,
V_2 -> V_179 , NULL ) ;
if ( V_244 )
F_29 ( & V_2 -> V_246 ,
& V_2 -> V_213 , L_32 ,
0 , F_30 ( V_247 ) ) ;
if ( V_2 -> V_183 == V_248 ) {
enum V_249 type =
V_244 ? V_250 : V_251 ;
F_29 ( & V_2 -> V_246 ,
& V_2 -> V_213 , L_32 ,
0 , F_30 ( type ) ) ;
} else {
F_29 ( & V_2 -> V_246 ,
& V_2 -> V_213 , L_32 ,
V_2 -> V_183 , NULL ) ;
}
}
F_22 ( V_2 ) ;
switch ( V_2 -> V_8 ) {
case V_145 :
case V_143 :
{
struct V_187 V_252 ;
struct V_253 V_193 ;
V_2 -> V_52 . V_178 = 0xC0 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_254 = V_255 ;
V_252 . V_180 = V_256 ;
V_252 . V_42 = & V_193 ;
F_23 ( V_2 , V_180 , V_190 , & V_252 ) ;
break;
}
}
return 0 ;
}
