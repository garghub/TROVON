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
case V_13 :
F_5 ( V_2 , 20 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 20 , 1 ) ;
break;
}
return 0 ;
}
return - V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
switch ( V_2 -> V_8 ) {
case V_15 :
case V_16 :
case V_17 :
if ( V_4 == V_18 ) {
F_8 ( V_19 , 0x00 ) ;
F_6 ( 10 ) ;
F_8 ( V_19 , 0x01 ) ;
F_6 ( 10 ) ;
}
break;
default:
F_4 ( V_20 >> 2 , 0x06e20000 , 0x06e20000 ) ;
F_4 ( V_7 >> 2 , 0x06a20000 , 0x06a20000 ) ;
F_4 ( V_21 >> 2 , 0x02 , 0x02 ) ;
F_4 ( V_22 >> 2 , 0x81 , 0x81 ) ;
F_4 ( V_23 >> 2 , 0x03187de7 , 0x03187de7 ) ;
F_4 ( V_24 >> 2 , 0x03 , 0x03 ) ;
F_4 ( V_25 >> 2 ,
0x0001e000 , 0x0001e000 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
T_1 V_26 ;
switch ( V_4 ) {
case 0 :
F_5 ( V_2 , 22 , V_5 ) ;
break;
case 1 :
F_10 ( V_27 , 0x80 , 0x80 ) ;
F_10 ( V_28 , 0x0f , 0x03 ) ;
if ( V_5 == 1 )
V_26 = 11 ;
else
V_26 = 17 ;
F_8 ( V_29 , V_26 ) ;
F_8 ( V_30 , V_26 + 1 ) ;
F_10 ( V_31 , 0x03 , 0x00 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
switch ( V_33 ) {
case V_34 :
F_5 ( V_2 , 26 , 0 ) ;
break;
case V_35 :
F_5 ( V_2 , 26 , 1 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static inline int F_12 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
switch ( V_33 ) {
case V_34 :
F_13 ( V_20 >> 2 , 0x4000 ) ;
F_13 ( V_7 >> 2 , 0x4000 ) ;
F_6 ( 20 ) ;
break;
case V_35 :
F_13 ( V_20 >> 2 , 0x14000 ) ;
F_13 ( V_7 >> 2 , 0x14000 ) ;
F_6 ( 20 ) ;
F_13 ( V_20 >> 2 , 0x54000 ) ;
F_13 ( V_7 >> 2 , 0x54000 ) ;
F_6 ( 30 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
switch ( V_33 ) {
case V_34 :
F_5 ( V_2 , 18 , 0 ) ;
break;
case V_35 :
F_5 ( V_2 , 18 , 1 ) ;
F_6 ( 30 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
int V_36 = 0 ;
switch ( V_4 ) {
case V_37 :
switch ( V_2 -> V_8 ) {
case V_38 :
case V_39 :
case V_40 :
V_36 = F_11 ( V_2 , V_5 ) ;
break;
case V_41 :
V_36 = F_12 ( V_2 , V_5 ) ;
break;
case V_42 :
V_36 = F_14 ( V_2 , V_5 ) ;
break;
default:
break;
}
break;
default:
V_36 = - V_14 ;
break;
}
return V_36 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
int V_36 ;
switch ( V_2 -> V_8 ) {
case V_38 :
case V_39 :
case V_43 :
case V_41 :
case V_42 :
case V_40 :
V_36 = F_15 ( V_2 , V_4 , V_5 ) ;
break;
default:
V_36 = F_9 ( V_2 , V_4 , V_5 ) ;
break;
}
return V_36 ;
}
int F_17 ( void * V_44 , int V_45 , int V_4 , int V_5 )
{
struct V_1 * V_2 = V_44 ;
if ( V_2 != NULL ) {
switch ( V_2 -> V_46 ) {
case V_47 :
return F_16 ( V_2 , V_4 , V_5 ) ;
case V_48 :
return F_3 ( V_2 , V_4 , V_5 ) ;
case V_49 :
return F_7 ( V_2 , V_4 , V_5 ) ;
}
} else {
F_2 ( V_50 L_4 ) ;
return - V_14 ;
}
return - V_14 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 * V_51 )
{
struct V_52 V_53 ;
F_19 ( & V_2 -> V_54 , & V_53 , V_51 ) ;
switch ( V_53 . V_55 ) {
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
F_2 ( V_56 L_5
L_6 , V_2 -> V_3 , V_53 . V_55 ) ;
break;
}
F_2 ( V_57 L_7 ,
V_2 -> V_3 , V_53 . V_55 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
F_13 ( V_20 >> 2 , 0 ) ;
V_2 -> V_58 = F_21 ( V_7 >> 2 ) ;
F_2 ( V_57 L_8 , V_2 -> V_3 , V_2 -> V_58 ) ;
switch ( V_2 -> V_8 ) {
case V_59 :
case V_60 :
case V_61 :
V_2 -> V_62 = V_63 ;
F_1 ( V_2 ) ;
break;
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
case V_128 :
case V_129 :
case V_130 :
V_2 -> V_62 = V_63 ;
break;
case V_131 :
F_8 ( V_132 , 0x80 ) ;
F_8 ( V_133 , 0x40 ) ;
V_2 -> V_62 = V_63 ;
break;
case V_134 :
F_2 ( L_9
L_10
L_11 ,
V_2 -> V_3 , V_2 -> V_3 , V_2 -> V_3 ) ;
break;
case V_135 :
F_4 ( V_20 >> 2 , 0x00040000 , 0x00040000 ) ;
F_4 ( V_7 >> 2 , 0x00040000 , 0x00000000 ) ;
break;
case V_136 :
F_8 ( V_137 , 0x80 ) ;
F_8 ( V_138 , 0x80 ) ;
break;
case V_139 :
F_4 ( V_20 >> 2 , 0x00040000 , 0x00040000 ) ;
F_4 ( V_7 >> 2 , 0x00040000 , 0x00000004 ) ;
break;
case V_140 :
F_8 ( V_132 , 0x08 ) ;
F_8 ( V_141 , 0x06 ) ;
break;
case V_142 :
case V_143 :
F_4 ( V_20 >> 2 , 0x08000000 , 0x08000000 ) ;
F_4 ( V_7 >> 2 , 0x08000000 , 0x00000000 ) ;
break;
case V_144 :
case V_145 :
F_4 ( V_20 >> 2 , 0xffffffff , 0 ) ;
F_4 ( V_7 >> 2 , 0xffffffff , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_20 >> 2 , 0xffffffff , 0xffffffff ) ;
F_4 ( V_7 >> 2 , 0xffffffff , 0xffffffff ) ;
F_6 ( 10 ) ;
break;
case V_146 :
F_4 ( V_20 >> 2 , 0x08400000 , 0x08400000 ) ;
F_4 ( V_7 >> 2 , 0x08400000 , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_20 >> 2 , 0x08400000 , 0x08400000 ) ;
F_4 ( V_7 >> 2 , 0x08400000 , 0x08400000 ) ;
F_6 ( 10 ) ;
V_2 -> V_62 = V_147 ;
break;
case V_9 :
F_5 ( V_2 , 23 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 23 , 1 ) ;
V_2 -> V_62 = V_147 ;
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
V_2 -> V_62 = V_63 ;
break;
case V_148 :
F_4 ( V_20 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_4 ( V_7 >> 2 , 0x000A8004 , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_20 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_4 ( V_7 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_6 ( 10 ) ;
V_2 -> V_62 = V_63 ;
break;
case V_149 :
F_8 ( V_150 , 0x00 ) ;
break;
case V_38 :
case V_39 :
V_2 -> V_62 = V_63 ;
F_5 ( V_2 , 26 , 0 ) ;
F_6 ( 1 ) ;
F_5 ( V_2 , 22 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 22 , 1 ) ;
break;
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
case V_165 :
case V_166 :
case V_167 :
case V_15 :
case V_16 :
case V_17 :
case V_42 :
V_2 -> V_62 = V_147 ;
break;
case V_168 :
F_2 ( L_12
L_13
L_14 ,
V_2 -> V_3 , F_22 ( V_2 ) . V_3 , V_2 -> V_3 , V_2 -> V_3 ) ;
break;
case V_169 :
V_2 -> V_62 = V_63 ;
F_4 ( V_20 >> 2 , 0x8c040007 , 0x8c040007 ) ;
F_4 ( V_7 >> 2 , 0x0c0007cd , 0x0c0007cd ) ;
break;
case V_12 :
case V_170 :
F_4 ( V_20 >> 2 , 0x80040100 , 0x80040100 ) ;
F_4 ( V_7 >> 2 , 0x80040100 , 0x00040100 ) ;
break;
case V_171 :
F_5 ( V_2 , 12 , 3 ) ;
F_5 ( V_2 , 13 , 3 ) ;
V_2 -> V_62 = V_147 ;
F_5 ( V_2 , 23 , 1 ) ;
break;
case V_172 :
V_2 -> V_62 = V_63 ;
F_4 ( V_20 >> 2 , 0x0000C000 , 0x0000C000 ) ;
F_4 ( V_7 >> 2 , 0x0000C000 , 0x0000C000 ) ;
break;
case V_43 :
F_5 ( V_2 , 1 , 1 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 1 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 1 , 1 ) ;
V_2 -> V_62 = V_63 ;
break;
case V_40 :
F_4 ( V_20 >> 2 , 0x0e050000 , 0x0c050000 ) ;
F_4 ( V_7 >> 2 , 0x0e050000 , 0x0c050000 ) ;
break;
case V_13 :
F_4 ( V_20 >> 2 , 0x00008000 , 0x00008000 ) ;
F_4 ( V_7 >> 2 , 0x00008000 , 0x00008000 ) ;
break;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_173 V_174 ;
unsigned int V_175 = V_176 | V_177 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_174 . V_178 = F_17 ;
if ( V_179 [ V_2 -> V_8 ] . V_180 != V_181 ) {
V_174 . type = V_179 [ V_2 -> V_8 ] . V_180 ;
V_174 . V_182 = V_179 [ V_2 -> V_8 ] . V_183 ;
V_174 . V_175 = V_176 ;
F_24 ( V_2 , V_184 , V_185 , & V_174 ) ;
V_175 &= ~ V_176 ;
}
if ( ( V_2 -> V_46 != V_186 ) && ( V_2 -> V_46 != V_181 ) ) {
V_174 . type = V_2 -> V_46 ;
V_174 . V_182 = V_2 -> V_187 ;
V_174 . V_188 = & V_179 [ V_2 -> V_8 ] . V_189 ;
V_174 . V_178 = F_17 ;
V_174 . V_175 = V_175 ;
F_24 ( V_2 , V_184 , V_185 , & V_174 ) ;
}
if ( V_2 -> V_190 ) {
struct V_191 V_192 ;
V_192 . V_184 = V_193 ;
V_192 . V_44 = & V_2 -> V_190 ;
F_24 ( V_2 , V_184 , V_194 , & V_192 ) ;
}
if ( V_2 -> V_46 == V_48 ) {
struct V_191 V_195 ;
struct V_196 V_197 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_198 = V_199 ;
V_197 . V_200 = 64 ;
switch ( V_2 -> V_8 ) {
case V_11 :
case V_9 :
case V_10 :
case V_12 :
V_197 . V_201 = V_202 ;
break;
default:
V_197 . V_201 = V_203 ;
V_197 . V_204 = 1 ;
}
V_195 . V_184 = V_48 ;
V_195 . V_44 = & V_197 ;
F_24 ( V_2 , V_184 , V_194 , & V_195 ) ;
}
}
int F_25 ( struct V_1 * V_2 )
{
unsigned char V_205 ;
int V_8 ;
switch ( V_2 -> V_8 ) {
case V_206 :
case V_207 :
V_2 -> V_54 . V_182 = 0x60 ;
V_8 = ( F_26 ( & V_2 -> V_54 , & V_205 , 0 ) < 0 )
? V_206
: V_207 ;
if ( V_8 == V_2 -> V_8 )
break;
V_2 -> V_8 = V_8 ;
F_2 ( L_15 , V_2 -> V_3 ,
V_179 [ V_2 -> V_8 ] . V_3 ) ;
V_2 -> V_46 = V_179 [ V_2 -> V_8 ] . V_46 ;
break;
case V_208 :
{
T_1 V_209 ;
T_1 V_210 [ 3 ] ;
int V_36 , V_211 ;
struct V_212 V_213 [] = { { . V_182 = 0x50 , . V_214 = 0 , . V_205 = & V_209 , . V_215 = 1 } ,
{ . V_182 = 0x50 , . V_214 = V_216 , . V_205 = V_210 , . V_215 = 3 } } ;
V_209 = 0x14 ;
V_211 = 0 ;
V_36 = F_27 ( & V_2 -> V_217 , V_213 , 2 ) ;
if ( V_36 != 2 ) {
F_2 ( V_50 L_16 ) ;
} else if ( ( V_210 [ 0 ] != 0 ) && ( V_210 [ 0 ] != 0xff ) ) {
V_209 = V_210 [ 0 ] + 2 ;
V_213 [ 1 ] . V_215 = 2 ;
F_27 ( & V_2 -> V_217 , V_213 , 2 ) ;
V_211 = ( V_210 [ 0 ] << 8 ) + V_210 [ 1 ] ;
switch ( V_211 ) {
case 0x0103 :
V_2 -> V_46 = V_218 ;
break;
case 0x010C :
V_2 -> V_46 = V_219 ;
break;
default:
F_2 ( V_50 L_17 , V_2 -> V_3 , V_211 ) ;
}
} else if ( ( V_210 [ 1 ] != 0 ) && ( V_210 [ 1 ] != 0xff ) ) {
V_209 = V_210 [ 1 ] + 1 ;
V_213 [ 1 ] . V_215 = 1 ;
F_27 ( & V_2 -> V_217 , V_213 , 2 ) ;
V_209 = V_210 [ 0 ] + 1 ;
V_213 [ 1 ] . V_215 = 2 ;
F_27 ( & V_2 -> V_217 , V_213 , 2 ) ;
V_211 = ( V_210 [ 1 ] << 8 ) + V_210 [ 0 ] ;
switch ( V_211 ) {
case 0x0005 :
V_2 -> V_46 = V_219 ;
break;
case 0x001d :
V_2 -> V_46 = V_220 ;
F_2 ( V_57 L_18 , V_2 -> V_3 ) ;
break;
default:
F_2 ( V_50 L_17 , V_2 -> V_3 , V_211 ) ;
}
} else {
F_2 ( V_50 L_19 , V_2 -> V_3 ) ;
}
F_2 ( V_57 L_20 , V_2 -> V_3 , V_2 -> V_46 ) ;
break;
}
case V_221 :
if ( V_2 -> V_222 && ( V_2 -> V_223 [ 0x41 ] == 0x1c ) ) {
V_2 -> V_8 = V_224 ;
V_2 -> V_46 = V_179 [ V_2 -> V_8 ] . V_46 ;
F_2 ( V_57 L_21 ,
V_2 -> V_3 , V_179 [ V_2 -> V_8 ] . V_3 ) ;
break;
}
case V_88 :
case V_225 :
case V_226 :
case V_227 :
{
T_1 V_210 [] = { 0x07 , 0x02 } ;
struct V_212 V_213 = { . V_182 = 0x08 , . V_214 = 0 , . V_205 = V_210 , . V_215 = sizeof( V_210 ) } ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
case V_228 :
case V_229 :
{
T_1 V_210 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_212 V_213 = { . V_182 = 0x08 , . V_214 = 0 , . V_205 = V_210 , . V_215 = sizeof( V_210 ) } ;
if ( V_2 -> V_222 && ( V_2 -> V_223 [ 0x49 ] == 0x50 ) ) {
V_2 -> V_8 = V_229 ;
F_2 ( V_57 L_21 ,
V_2 -> V_3 , V_179 [ V_2 -> V_8 ] . V_3 ) ;
}
if ( V_2 -> V_8 == V_229 ) {
V_2 -> V_46 = V_47 ;
V_210 [ 2 ] = 0x68 ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
case V_230 :
if ( V_2 -> V_222 && ( V_2 -> V_223 [ 0x27 ] == 0x03 ) ) {
V_2 -> V_8 = V_102 ;
F_2 ( V_57 L_22
L_23 ,
V_2 -> V_3 , V_179 [ V_2 -> V_8 ] . V_3 ) ;
V_2 -> V_62 = V_63 ;
F_28 ( V_2 ) ;
}
break;
case V_38 :
case V_39 :
F_18 ( V_2 , V_2 -> V_223 + 0x80 ) ;
break;
case V_155 :
F_18 ( V_2 , V_2 -> V_223 + 0x80 ) ;
case V_152 :
case V_231 :
case V_232 :
case V_233 :
case V_100 :
case V_101 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
{
T_1 V_210 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_212 V_213 = { . V_182 = 0x08 , . V_214 = 0 , . V_205 = V_210 , . V_215 = sizeof( V_210 ) } ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
case V_238 :
{
T_1 V_210 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_212 V_213 = { . V_182 = 0x0b , . V_214 = 0 , . V_205 = V_210 ,
. V_215 = sizeof( V_210 ) } ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
case V_99 :
{
T_1 V_210 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_212 V_213 = { . V_182 = 0x0b , . V_214 = 0 , . V_205 = V_210 ,
. V_215 = sizeof( V_210 ) } ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
case V_239 :
{
T_1 V_240 = 0 ;
int V_241 ;
T_1 V_210 [] = { 0x3c , 0x33 , 0x62 } ;
struct V_212 V_213 = { . V_182 = 0x09 , . V_214 = 0 , . V_205 = V_210 , . V_215 = sizeof( V_210 ) } ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
V_213 . V_205 = & V_240 ;
V_213 . V_182 = 0x0b ;
V_213 . V_215 = 1 ;
if ( 1 != F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ) {
F_2 ( V_56 L_24
L_25 , V_2 -> V_3 ) ;
} else {
V_213 . V_214 = V_216 ;
V_241 = F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
F_2 ( V_57 L_26 ,
V_2 -> V_3 , V_213 . V_182 ,
( 1 == V_241 ) ? L_27 : L_28 ) ;
if ( V_241 == 1 )
V_2 -> V_62 = V_147 ;
}
break;
}
case V_142 :
case V_143 :
{
T_1 V_210 [] = { 0x3c , 0x33 , 0x6a } ;
struct V_212 V_213 = { . V_182 = 0x08 , . V_214 = 0 , . V_205 = V_210 , . V_215 = sizeof( V_210 ) } ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
case V_242 :
case V_243 :
{
T_1 V_210 [] = { 0x3c , 0x33 , 0x68 } ;
struct V_212 V_213 = { . V_182 = 0x08 , . V_214 = 0 , . V_205 = V_210 , . V_215 = sizeof( V_210 ) } ;
F_27 ( & V_2 -> V_217 , & V_213 , 1 ) ;
break;
}
case V_89 :
case V_90 :
if ( ! V_2 -> V_222 || ( V_2 -> V_223 [ 0x41 ] == 0xd0 ) )
break;
if ( V_2 -> V_223 [ 0x41 ] == 0x02 ) {
V_2 -> V_8 = V_90 ;
V_2 -> V_46 = V_179 [ V_2 -> V_8 ] . V_46 ;
V_2 -> V_190 = V_179 [ V_2 -> V_8 ] . V_190 ;
F_2 ( V_57 L_21 ,
V_2 -> V_3 , V_179 [ V_2 -> V_8 ] . V_3 ) ;
} else {
F_2 ( V_56 L_29 ,
V_2 -> V_3 , V_2 -> V_223 [ 0x41 ] ) ;
break;
}
break;
case V_244 :
case V_245 :
{
struct V_212 V_213 = { . V_182 = 0x0a , . V_214 = 0 } ;
int V_246 ;
static T_1 V_247 [] [ 2 ] = {
{ 0x10 , 0x12 } ,
{ 0x13 , 0x04 } ,
{ 0x16 , 0x00 } ,
{ 0x14 , 0x04 } ,
{ 0x17 , 0x00 } ,
} ;
for ( V_246 = 0 ; V_246 < F_29 ( V_247 ) ; V_246 ++ ) {
V_213 . V_205 = & V_247 [ V_246 ] [ 0 ] ;
V_213 . V_215 = F_29 ( V_247 [ 0 ] ) ;
if ( F_27 ( & V_2 -> V_217 , & V_213 , 1 ) != 1 )
F_2 ( V_56
L_30 ,
V_2 -> V_3 , V_246 ) ;
}
break;
}
case V_167 :
{
T_1 V_210 [] = { 0x09 , 0x9f , 0x86 , 0x11 } ;
struct V_212 V_213 = { . V_182 = 0x61 , . V_214 = 0 , . V_205 = V_210 ,
. V_215 = sizeof( V_210 ) } ;
if ( F_27 ( & V_2 -> V_217 , & V_213 , 1 ) != 1 )
F_2 ( V_56
L_31 ,
V_2 -> V_3 ) ;
break;
}
case V_41 :
F_13 ( V_20 >> 2 , 0x4000 ) ;
F_13 ( V_7 >> 2 , 0x4000 ) ;
F_5 ( V_2 , 27 , 0 ) ;
break;
}
if ( V_186 != V_2 -> V_46 ) {
int V_248 = ( V_2 -> V_190 & V_249 ) ;
if ( V_2 -> V_180 != V_181 )
F_30 ( & V_2 -> V_250 ,
& V_2 -> V_217 , L_32 ,
V_2 -> V_183 , NULL ) ;
if ( V_248 )
F_30 ( & V_2 -> V_250 ,
& V_2 -> V_217 , L_32 ,
0 , F_31 ( V_251 ) ) ;
if ( V_2 -> V_187 == V_252 ) {
enum V_253 type =
V_248 ? V_254 : V_255 ;
F_30 ( & V_2 -> V_250 ,
& V_2 -> V_217 , L_32 ,
0 , F_31 ( type ) ) ;
} else {
F_30 ( & V_2 -> V_250 ,
& V_2 -> V_217 , L_32 ,
V_2 -> V_187 , NULL ) ;
}
}
F_23 ( V_2 ) ;
switch ( V_2 -> V_8 ) {
case V_148 :
case V_146 :
{
struct V_191 V_256 ;
struct V_257 V_197 ;
V_2 -> V_54 . V_182 = 0xC0 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_258 = V_259 ;
V_256 . V_184 = V_260 ;
V_256 . V_44 = & V_197 ;
F_24 ( V_2 , V_184 , V_194 , & V_256 ) ;
break;
}
}
return 0 ;
}
