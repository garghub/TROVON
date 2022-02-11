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
V_2 -> V_62 = V_63 ;
break;
case V_130 :
F_8 ( V_131 , 0x80 ) ;
F_8 ( V_132 , 0x40 ) ;
V_2 -> V_62 = V_63 ;
break;
case V_133 :
F_2 ( L_9
L_10
L_11 ,
V_2 -> V_3 , V_2 -> V_3 , V_2 -> V_3 ) ;
break;
case V_134 :
F_4 ( V_20 >> 2 , 0x00040000 , 0x00040000 ) ;
F_4 ( V_7 >> 2 , 0x00040000 , 0x00000000 ) ;
break;
case V_135 :
F_8 ( V_136 , 0x80 ) ;
F_8 ( V_137 , 0x80 ) ;
break;
case V_138 :
F_4 ( V_20 >> 2 , 0x00040000 , 0x00040000 ) ;
F_4 ( V_7 >> 2 , 0x00040000 , 0x00000004 ) ;
break;
case V_139 :
F_8 ( V_131 , 0x08 ) ;
F_8 ( V_140 , 0x06 ) ;
break;
case V_141 :
case V_142 :
F_4 ( V_20 >> 2 , 0x08000000 , 0x08000000 ) ;
F_4 ( V_7 >> 2 , 0x08000000 , 0x00000000 ) ;
break;
case V_143 :
case V_144 :
F_4 ( V_20 >> 2 , 0xffffffff , 0 ) ;
F_4 ( V_7 >> 2 , 0xffffffff , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_20 >> 2 , 0xffffffff , 0xffffffff ) ;
F_4 ( V_7 >> 2 , 0xffffffff , 0xffffffff ) ;
F_6 ( 10 ) ;
break;
case V_145 :
F_4 ( V_20 >> 2 , 0x08400000 , 0x08400000 ) ;
F_4 ( V_7 >> 2 , 0x08400000 , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_20 >> 2 , 0x08400000 , 0x08400000 ) ;
F_4 ( V_7 >> 2 , 0x08400000 , 0x08400000 ) ;
F_6 ( 10 ) ;
V_2 -> V_62 = V_146 ;
break;
case V_9 :
F_5 ( V_2 , 23 , 0 ) ;
F_6 ( 10 ) ;
F_5 ( V_2 , 23 , 1 ) ;
V_2 -> V_62 = V_146 ;
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
case V_147 :
F_4 ( V_20 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_4 ( V_7 >> 2 , 0x000A8004 , 0 ) ;
F_6 ( 10 ) ;
F_4 ( V_20 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_4 ( V_7 >> 2 , 0x000A8004 , 0x000A8004 ) ;
F_6 ( 10 ) ;
V_2 -> V_62 = V_63 ;
break;
case V_148 :
F_8 ( V_149 , 0x00 ) ;
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
case V_165 :
case V_166 :
case V_15 :
case V_16 :
case V_17 :
case V_42 :
V_2 -> V_62 = V_146 ;
break;
case V_167 :
F_2 ( L_12
L_13
L_14 ,
V_2 -> V_3 , F_22 ( V_2 ) . V_3 , V_2 -> V_3 , V_2 -> V_3 ) ;
break;
case V_168 :
V_2 -> V_62 = V_63 ;
F_4 ( V_20 >> 2 , 0x8c040007 , 0x8c040007 ) ;
F_4 ( V_7 >> 2 , 0x0c0007cd , 0x0c0007cd ) ;
break;
case V_12 :
case V_169 :
F_4 ( V_20 >> 2 , 0x80040100 , 0x80040100 ) ;
F_4 ( V_7 >> 2 , 0x80040100 , 0x00040100 ) ;
break;
case V_170 :
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
struct V_171 V_172 ;
unsigned int V_173 = V_174 | V_175 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 . V_176 = F_17 ;
if ( V_177 [ V_2 -> V_8 ] . V_178 != V_179 ) {
V_172 . type = V_177 [ V_2 -> V_8 ] . V_178 ;
V_172 . V_180 = V_177 [ V_2 -> V_8 ] . V_181 ;
V_172 . V_173 = V_174 ;
F_24 ( V_2 , V_182 , V_183 , & V_172 ) ;
V_173 &= ~ V_174 ;
}
if ( ( V_2 -> V_46 != V_184 ) && ( V_2 -> V_46 != V_179 ) ) {
V_172 . type = V_2 -> V_46 ;
V_172 . V_180 = V_2 -> V_185 ;
V_172 . V_186 = V_177 [ V_2 -> V_8 ] . V_187 ;
V_172 . V_176 = F_17 ;
V_172 . V_173 = V_173 ;
F_24 ( V_2 , V_182 , V_183 , & V_172 ) ;
}
if ( V_2 -> V_188 ) {
struct V_189 V_190 ;
V_190 . V_182 = V_191 ;
V_190 . V_44 = & V_2 -> V_188 ;
F_24 ( V_2 , V_182 , V_192 , & V_190 ) ;
}
if ( V_2 -> V_46 == V_48 ) {
struct V_189 V_193 ;
struct V_194 V_195 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_196 = V_197 ;
V_195 . V_198 = 64 ;
switch ( V_2 -> V_8 ) {
case V_11 :
case V_9 :
case V_10 :
case V_12 :
V_195 . V_199 = V_200 ;
break;
default:
V_195 . V_199 = V_201 ;
V_195 . V_202 = 1 ;
}
V_193 . V_182 = V_48 ;
V_193 . V_44 = & V_195 ;
F_24 ( V_2 , V_182 , V_192 , & V_193 ) ;
}
}
int F_25 ( struct V_1 * V_2 )
{
unsigned char V_203 ;
int V_8 ;
switch ( V_2 -> V_8 ) {
case V_204 :
case V_205 :
V_2 -> V_54 . V_180 = 0x60 ;
V_8 = ( F_26 ( & V_2 -> V_54 , & V_203 , 0 ) < 0 )
? V_204
: V_205 ;
if ( V_8 == V_2 -> V_8 )
break;
V_2 -> V_8 = V_8 ;
F_2 ( L_15 , V_2 -> V_3 ,
V_177 [ V_2 -> V_8 ] . V_3 ) ;
V_2 -> V_46 = V_177 [ V_2 -> V_8 ] . V_46 ;
break;
case V_206 :
{
T_1 V_207 ;
T_1 V_208 [ 3 ] ;
int V_36 , V_209 ;
struct V_210 V_211 [] = { { . V_180 = 0x50 , . V_212 = 0 , . V_203 = & V_207 , . V_213 = 1 } ,
{ . V_180 = 0x50 , . V_212 = V_214 , . V_203 = V_208 , . V_213 = 3 } } ;
V_207 = 0x14 ;
V_209 = 0 ;
V_36 = F_27 ( & V_2 -> V_215 , V_211 , 2 ) ;
if ( V_36 != 2 ) {
F_2 ( V_50 L_16 ) ;
} else if ( ( V_208 [ 0 ] != 0 ) && ( V_208 [ 0 ] != 0xff ) ) {
V_207 = V_208 [ 0 ] + 2 ;
V_211 [ 1 ] . V_213 = 2 ;
F_27 ( & V_2 -> V_215 , V_211 , 2 ) ;
V_209 = ( V_208 [ 0 ] << 8 ) + V_208 [ 1 ] ;
switch ( V_209 ) {
case 0x0103 :
V_2 -> V_46 = V_216 ;
break;
case 0x010C :
V_2 -> V_46 = V_217 ;
break;
default:
F_2 ( V_50 L_17 , V_2 -> V_3 , V_209 ) ;
}
} else if ( ( V_208 [ 1 ] != 0 ) && ( V_208 [ 1 ] != 0xff ) ) {
V_207 = V_208 [ 1 ] + 1 ;
V_211 [ 1 ] . V_213 = 1 ;
F_27 ( & V_2 -> V_215 , V_211 , 2 ) ;
V_207 = V_208 [ 0 ] + 1 ;
V_211 [ 1 ] . V_213 = 2 ;
F_27 ( & V_2 -> V_215 , V_211 , 2 ) ;
V_209 = ( V_208 [ 1 ] << 8 ) + V_208 [ 0 ] ;
switch ( V_209 ) {
case 0x0005 :
V_2 -> V_46 = V_217 ;
break;
case 0x001d :
V_2 -> V_46 = V_218 ;
F_2 ( V_57 L_18 , V_2 -> V_3 ) ;
break;
default:
F_2 ( V_50 L_17 , V_2 -> V_3 , V_209 ) ;
}
} else {
F_2 ( V_50 L_19 , V_2 -> V_3 ) ;
}
F_2 ( V_57 L_20 , V_2 -> V_3 , V_2 -> V_46 ) ;
break;
}
case V_219 :
if ( V_2 -> V_220 && ( V_2 -> V_221 [ 0x41 ] == 0x1c ) ) {
V_2 -> V_8 = V_222 ;
V_2 -> V_46 = V_177 [ V_2 -> V_8 ] . V_46 ;
F_2 ( V_57 L_21 ,
V_2 -> V_3 , V_177 [ V_2 -> V_8 ] . V_3 ) ;
break;
}
case V_88 :
case V_223 :
case V_224 :
case V_225 :
{
T_1 V_208 [] = { 0x07 , 0x02 } ;
struct V_210 V_211 = { . V_180 = 0x08 , . V_212 = 0 , . V_203 = V_208 , . V_213 = sizeof( V_208 ) } ;
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
break;
}
case V_226 :
case V_227 :
{
T_1 V_208 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_210 V_211 = { . V_180 = 0x08 , . V_212 = 0 , . V_203 = V_208 , . V_213 = sizeof( V_208 ) } ;
if ( V_2 -> V_220 && ( V_2 -> V_221 [ 0x49 ] == 0x50 ) ) {
V_2 -> V_8 = V_227 ;
F_2 ( V_57 L_21 ,
V_2 -> V_3 , V_177 [ V_2 -> V_8 ] . V_3 ) ;
}
if ( V_2 -> V_8 == V_227 ) {
V_2 -> V_46 = V_47 ;
V_208 [ 2 ] = 0x68 ;
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
break;
}
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
break;
}
case V_228 :
if ( V_2 -> V_220 && ( V_2 -> V_221 [ 0x27 ] == 0x03 ) ) {
V_2 -> V_8 = V_101 ;
F_2 ( V_57 L_22
L_23 ,
V_2 -> V_3 , V_177 [ V_2 -> V_8 ] . V_3 ) ;
V_2 -> V_62 = V_63 ;
F_28 ( V_2 ) ;
}
break;
case V_38 :
case V_39 :
F_18 ( V_2 , V_2 -> V_221 + 0x80 ) ;
break;
case V_154 :
F_18 ( V_2 , V_2 -> V_221 + 0x80 ) ;
case V_151 :
case V_229 :
case V_230 :
case V_231 :
case V_99 :
case V_100 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
{
T_1 V_208 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_210 V_211 = { . V_180 = 0x08 , . V_212 = 0 , . V_203 = V_208 , . V_213 = sizeof( V_208 ) } ;
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
break;
}
case V_236 :
{
T_1 V_208 [] = { 0x3c , 0x33 , 0x60 } ;
struct V_210 V_211 = { . V_180 = 0x0b , . V_212 = 0 , . V_203 = V_208 ,
. V_213 = sizeof( V_208 ) } ;
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
break;
}
case V_237 :
{
T_1 V_238 = 0 ;
int V_239 ;
T_1 V_208 [] = { 0x3c , 0x33 , 0x62 } ;
struct V_210 V_211 = { . V_180 = 0x09 , . V_212 = 0 , . V_203 = V_208 , . V_213 = sizeof( V_208 ) } ;
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
V_211 . V_203 = & V_238 ;
V_211 . V_180 = 0x0b ;
V_211 . V_213 = 1 ;
if ( 1 != F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ) {
F_2 ( V_56 L_24
L_25 , V_2 -> V_3 ) ;
} else {
V_211 . V_212 = V_214 ;
V_239 = F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
F_2 ( V_57 L_26 ,
V_2 -> V_3 , V_211 . V_180 ,
( 1 == V_239 ) ? L_27 : L_28 ) ;
if ( V_239 == 1 )
V_2 -> V_62 = V_146 ;
}
break;
}
case V_141 :
case V_142 :
{
T_1 V_208 [] = { 0x3c , 0x33 , 0x6a } ;
struct V_210 V_211 = { . V_180 = 0x08 , . V_212 = 0 , . V_203 = V_208 , . V_213 = sizeof( V_208 ) } ;
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
break;
}
case V_240 :
case V_241 :
{
T_1 V_208 [] = { 0x3c , 0x33 , 0x68 } ;
struct V_210 V_211 = { . V_180 = 0x08 , . V_212 = 0 , . V_203 = V_208 , . V_213 = sizeof( V_208 ) } ;
F_27 ( & V_2 -> V_215 , & V_211 , 1 ) ;
break;
}
case V_89 :
case V_90 :
if ( ! V_2 -> V_220 || ( V_2 -> V_221 [ 0x41 ] == 0xd0 ) )
break;
if ( V_2 -> V_221 [ 0x41 ] == 0x02 ) {
V_2 -> V_8 = V_90 ;
V_2 -> V_46 = V_177 [ V_2 -> V_8 ] . V_46 ;
V_2 -> V_188 = V_177 [ V_2 -> V_8 ] . V_188 ;
F_2 ( V_57 L_21 ,
V_2 -> V_3 , V_177 [ V_2 -> V_8 ] . V_3 ) ;
} else {
F_2 ( V_56 L_29 ,
V_2 -> V_3 , V_2 -> V_221 [ 0x41 ] ) ;
break;
}
break;
case V_242 :
case V_243 :
{
struct V_210 V_211 = { . V_180 = 0x0a , . V_212 = 0 } ;
int V_244 ;
static T_1 V_245 [] [ 2 ] = {
{ 0x10 , 0x12 } ,
{ 0x13 , 0x04 } ,
{ 0x16 , 0x00 } ,
{ 0x14 , 0x04 } ,
{ 0x17 , 0x00 } ,
} ;
for ( V_244 = 0 ; V_244 < F_29 ( V_245 ) ; V_244 ++ ) {
V_211 . V_203 = & V_245 [ V_244 ] [ 0 ] ;
V_211 . V_213 = F_29 ( V_245 [ 0 ] ) ;
if ( F_27 ( & V_2 -> V_215 , & V_211 , 1 ) != 1 )
F_2 ( V_56
L_30 ,
V_2 -> V_3 , V_244 ) ;
}
break;
}
case V_166 :
{
T_1 V_208 [] = { 0x09 , 0x9f , 0x86 , 0x11 } ;
struct V_210 V_211 = { . V_180 = 0x61 , . V_212 = 0 , . V_203 = V_208 ,
. V_213 = sizeof( V_208 ) } ;
if ( F_27 ( & V_2 -> V_215 , & V_211 , 1 ) != 1 )
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
if ( V_184 != V_2 -> V_46 ) {
int V_246 = ( V_2 -> V_188 & V_247 ) ;
if ( V_2 -> V_178 != V_179 )
F_30 ( & V_2 -> V_248 ,
& V_2 -> V_215 , L_32 ,
V_2 -> V_181 , NULL ) ;
if ( V_246 )
F_30 ( & V_2 -> V_248 ,
& V_2 -> V_215 , L_32 ,
0 , F_31 ( V_249 ) ) ;
if ( V_2 -> V_185 == V_250 ) {
enum V_251 type =
V_246 ? V_252 : V_253 ;
F_30 ( & V_2 -> V_248 ,
& V_2 -> V_215 , L_32 ,
0 , F_31 ( type ) ) ;
} else {
F_30 ( & V_2 -> V_248 ,
& V_2 -> V_215 , L_32 ,
V_2 -> V_185 , NULL ) ;
}
}
F_23 ( V_2 ) ;
switch ( V_2 -> V_8 ) {
case V_147 :
case V_145 :
{
struct V_189 V_254 ;
struct V_255 V_195 ;
V_2 -> V_54 . V_180 = 0xC0 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_256 = V_257 ;
V_254 . V_182 = V_258 ;
V_254 . V_44 = & V_195 ;
F_24 ( V_2 , V_182 , V_192 , & V_254 ) ;
break;
}
}
return 0 ;
}
