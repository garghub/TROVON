static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 [] = { V_3 , V_4 } ;
int V_9 ;
V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_1 , V_9 , V_3 ) ;
}
static T_2
F_4 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_4 ;
int V_9 ;
V_9 = F_2 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_5 ( V_6 , & V_4 , sizeof( V_4 ) ) ;
if ( V_9 < 0 )
goto V_11;
return V_4 ;
V_11:
F_3 ( & V_6 -> V_10 , L_2 , V_9 , V_3 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_12 )
{
if ( F_7 ( V_12 ) != V_2 -> V_13 ) {
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [] = {
V_15 , F_7 (reg)
} ;
int V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 ) {
F_3 ( & V_6 -> V_10 , L_3 ,
V_12 , V_9 ) ;
return V_9 ;
}
V_2 -> V_13 = F_7 ( V_12 ) ;
}
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_12 , char * V_8 , int V_16 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_3 = F_9 ( V_12 ) ;
int V_9 ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_2 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_5 ( V_6 , V_8 , V_16 ) ;
if ( V_9 < 0 )
goto V_11;
return V_9 ;
V_11:
F_3 ( & V_6 -> V_10 , L_4 , V_9 , V_12 ) ;
return V_9 ;
}
static void
F_10 ( struct V_1 * V_2 , T_1 V_12 , T_2 * V_17 , int V_16 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [ V_16 + 1 ] ;
int V_9 ;
V_8 [ 0 ] = F_9 ( V_12 ) ;
memcpy ( & V_8 [ 1 ] , V_17 , V_16 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
return;
V_9 = F_2 ( V_6 , V_8 , V_16 + 1 ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static int
F_11 ( struct V_1 * V_2 , T_1 V_12 )
{
T_2 V_4 = 0 ;
int V_9 ;
V_9 = F_8 ( V_2 , V_12 , & V_4 , sizeof( V_4 ) ) ;
if ( V_9 < 0 )
return V_9 ;
return V_4 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [] = { F_9 ( V_12 ) , V_4 } ;
int V_9 ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
return;
V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static void
F_13 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [] = { F_9 ( V_12 ) , V_4 >> 8 , V_4 } ;
int V_9 ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
return;
V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static void
F_14 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
int V_18 ;
V_18 = F_11 ( V_2 , V_12 ) ;
if ( V_18 >= 0 )
F_12 ( V_2 , V_12 , V_18 | V_4 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
int V_18 ;
V_18 = F_11 ( V_2 , V_12 ) ;
if ( V_18 >= 0 )
F_12 ( V_2 , V_12 , V_18 & ~ V_4 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_19 , V_20 | V_21 ) ;
F_17 ( 50 ) ;
F_12 ( V_2 , V_19 , 0 ) ;
F_17 ( 50 ) ;
F_14 ( V_2 , V_22 , V_23 ) ;
F_15 ( V_2 , V_22 , V_23 ) ;
F_12 ( V_2 , V_24 , 0x00 ) ;
F_12 ( V_2 , V_25 , F_18 ( 1 ) ) ;
F_12 ( V_2 , V_26 , 0x00 ) ;
F_12 ( V_2 , V_27 , 0x00 ) ;
F_12 ( V_2 , V_28 , 0x00 ) ;
F_12 ( V_2 , V_29 , 0x00 ) ;
F_12 ( V_2 , V_30 , V_31 ) ;
F_12 ( V_2 , V_32 , V_33 | V_34 ) ;
F_12 ( V_2 , V_35 , 0xfa ) ;
F_12 ( V_2 , V_36 , 0x00 ) ;
F_12 ( V_2 , V_37 , 0x5b ) ;
F_12 ( V_2 , V_38 , 0x00 ) ;
F_12 ( V_2 , V_39 , 0x10 ) ;
F_12 ( V_2 , V_40 , 0x24 ) ;
}
static T_3 F_19 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
T_4 V_43 , V_7 , V_44 , V_45 , V_46 , V_47 ;
if ( ! V_2 )
return V_48 ;
V_43 = F_4 ( V_2 , V_49 ) ;
V_7 = F_4 ( V_2 , V_50 ) ;
V_44 = F_4 ( V_2 , V_51 ) ;
V_45 = F_11 ( V_2 , V_52 ) ;
V_46 = F_11 ( V_2 , V_53 ) ;
V_47 = F_11 ( V_2 , V_54 ) ;
F_20 (
L_6 ,
V_43 , V_7 , V_44 , V_45 , V_46 , V_47 ) ;
if ( ( V_47 & V_55 ) && V_2 -> V_56 ) {
V_2 -> V_56 = 0 ;
F_21 ( & V_2 -> V_57 ) ;
} else if ( V_7 != 0 ) {
if ( V_2 -> V_58 && V_2 -> V_58 -> V_10 )
F_22 ( V_2 -> V_58 -> V_10 ) ;
}
return V_48 ;
}
static T_2 F_23 ( T_2 * V_8 , T_5 V_59 )
{
int V_60 = 0 ;
while ( V_59 -- )
V_60 -= * V_8 ++ ;
return V_60 ;
}
static void
F_24 ( struct V_1 * V_2 , T_2 V_61 , T_1 V_3 ,
T_2 * V_8 , T_5 V_62 )
{
V_8 [ F_25 ( 0 ) ] = F_23 ( V_8 , V_62 ) ;
F_15 ( V_2 , V_63 , V_61 ) ;
F_10 ( V_2 , V_3 , V_8 , V_62 ) ;
F_14 ( V_2 , V_63 , V_61 ) ;
}
static void
F_26 ( struct V_1 * V_2 , struct V_64 * V_17 )
{
T_4 V_8 [ F_25 ( V_65 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_27 ( 0 ) ] = V_66 ;
V_8 [ F_27 ( 1 ) ] = 0x01 ;
V_8 [ F_27 ( 2 ) ] = V_65 ;
V_8 [ F_25 ( 1 ) ] = V_17 -> V_67 [ 1 ] & 0x07 ;
V_8 [ F_25 ( 2 ) ] = V_17 -> V_67 [ 2 ] & 0x1c ;
V_8 [ F_25 ( 4 ) ] = V_17 -> V_67 [ 4 ] ;
V_8 [ F_25 ( 5 ) ] = V_17 -> V_67 [ 5 ] & 0xf8 ;
F_24 ( V_2 , V_68 , V_69 , V_8 ,
sizeof( V_8 ) ) ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
T_4 V_8 [ F_25 ( V_72 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_27 ( 0 ) ] = V_73 ;
V_8 [ F_27 ( 1 ) ] = 0x02 ;
V_8 [ F_27 ( 2 ) ] = V_72 ;
V_8 [ F_25 ( 1 ) ] = V_74 ;
V_8 [ F_25 ( 2 ) ] = V_75 ;
V_8 [ F_25 ( 3 ) ] = V_76 << 2 ;
V_8 [ F_25 ( 4 ) ] = F_29 ( V_71 ) ;
F_24 ( V_2 , V_77 , V_78 , V_8 ,
sizeof( V_8 ) ) ;
}
static void F_30 ( struct V_1 * V_2 , bool V_79 )
{
if ( V_79 ) {
F_14 ( V_2 , V_19 , V_20 ) ;
F_15 ( V_2 , V_19 , V_20 ) ;
F_14 ( V_2 , V_80 , V_81 ) ;
} else {
F_15 ( V_2 , V_80 , V_81 ) ;
}
}
static void
F_31 ( struct V_1 * V_2 ,
struct V_70 * V_71 , struct V_64 * V_17 )
{
T_2 V_8 [ 6 ] , V_82 , V_83 , V_84 , V_85 ;
T_6 V_86 ;
F_12 ( V_2 , V_87 , V_17 -> V_88 ) ;
F_12 ( V_2 , V_89 , V_17 -> V_90 ) ;
switch ( V_17 -> V_91 ) {
case V_92 :
F_12 ( V_2 , V_93 , V_94 ) ;
V_82 = V_95 ;
V_83 = V_96 ;
V_84 = F_32 ( 3 ) | F_33 ( 3 ) ;
break;
case V_97 :
F_12 ( V_2 , V_93 , V_98 ) ;
V_82 = V_99 ;
V_83 = V_100 ;
V_84 = F_32 ( 3 ) | F_33 ( 3 ) ;
break;
default:
F_34 () ;
return;
}
F_12 ( V_2 , V_101 , V_82 ) ;
F_15 ( V_2 , V_80 , V_102 |
V_103 ) ;
F_12 ( V_2 , V_104 , V_84 ) ;
V_85 = V_31 ;
if ( V_71 -> clock > 100000 )
V_85 ++ ;
if ( V_17 -> V_91 == V_92 )
V_85 ++ ;
F_12 ( V_2 , V_30 , V_85 ) ;
V_86 = 128 * V_17 -> V_105 / 1000 ;
V_8 [ 0 ] = 0x44 ;
V_8 [ 1 ] = 0x42 ;
V_8 [ 2 ] = 0x01 ;
V_8 [ 3 ] = V_86 ;
V_8 [ 4 ] = V_86 >> 8 ;
V_8 [ 5 ] = V_86 >> 16 ;
F_10 ( V_2 , V_106 , V_8 , 6 ) ;
F_12 ( V_2 , V_101 , V_82 | V_83 ) ;
F_14 ( V_2 , V_80 , V_107 ) ;
F_15 ( V_2 , V_80 , V_107 ) ;
V_8 [ 0 ] = V_108 ;
V_8 [ 1 ] = 0x00 ;
V_8 [ 2 ] = V_109 ;
V_8 [ 3 ] = V_110 |
V_111 ;
F_10 ( V_2 , F_35 ( 0 ) , V_8 , 4 ) ;
F_30 ( V_2 , true ) ;
F_17 ( 20 ) ;
F_30 ( V_2 , false ) ;
F_26 ( V_2 , V_17 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
const struct V_64 * V_17 )
{
V_2 -> V_112 = F_37 ( V_17 -> V_113 ) |
( V_17 -> V_114 ? V_115 : 0 ) |
F_38 ( V_17 -> V_116 ) |
( V_17 -> V_117 ? V_118 : 0 ) ;
V_2 -> V_119 = F_39 ( V_17 -> V_120 ) |
( V_17 -> V_121 ? V_122 : 0 ) |
F_40 ( V_17 -> V_123 ) |
( V_17 -> V_124 ? V_125 : 0 ) ;
V_2 -> V_126 = F_41 ( V_17 -> V_127 ) |
( V_17 -> V_128 ? V_129 : 0 ) |
F_42 ( V_17 -> V_130 ) |
( V_17 -> V_131 ? V_132 : 0 ) ;
V_2 -> V_133 = * V_17 ;
}
static void F_43 ( struct V_1 * V_2 , int V_71 )
{
if ( V_71 != V_134 )
V_71 = V_135 ;
if ( V_71 == V_2 -> V_136 )
return;
switch ( V_71 ) {
case V_134 :
F_12 ( V_2 , V_137 , 0xff ) ;
F_12 ( V_2 , V_138 , 0xff ) ;
F_12 ( V_2 , V_139 , 0xff ) ;
F_12 ( V_2 , V_140 , V_2 -> V_112 ) ;
F_12 ( V_2 , V_141 , V_2 -> V_119 ) ;
F_12 ( V_2 , V_142 , V_2 -> V_126 ) ;
break;
case V_135 :
F_12 ( V_2 , V_137 , 0x00 ) ;
F_12 ( V_2 , V_138 , 0x00 ) ;
F_12 ( V_2 , V_139 , 0x00 ) ;
break;
}
V_2 -> V_136 = V_71 ;
}
static void
F_44 ( struct V_143 * V_58 )
{
F_45 ( L_7 ) ;
}
static void
F_46 ( struct V_143 * V_58 )
{
F_45 ( L_7 ) ;
}
static bool
F_47 ( struct V_143 * V_58 ,
const struct V_70 * V_71 ,
struct V_70 * V_144 )
{
return true ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
if ( V_71 -> clock > 150000 )
return V_145 ;
if ( V_71 -> V_146 >= F_49 ( 13 ) )
return V_147 ;
if ( V_71 -> V_148 >= F_49 ( 11 ) )
return V_149 ;
return V_150 ;
}
static void
F_50 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_70 * V_144 )
{
T_1 V_151 , V_152 , V_153 , V_154 ;
T_1 V_155 , V_156 ;
T_1 V_157 , V_158 , V_159 , V_160 ;
T_1 V_161 , V_162 , V_163 , V_164 ;
T_1 V_165 , V_166 ;
T_1 V_167 , V_168 ;
T_1 V_169 , V_170 ;
T_2 V_12 , div , V_171 ;
V_153 = V_71 -> V_146 ;
V_154 = V_71 -> V_148 ;
V_156 = V_71 -> V_172 - V_71 -> V_173 ;
V_155 = V_71 -> V_174 - V_71 -> V_173 ;
V_170 = V_71 -> V_146 ;
V_169 = V_71 -> V_146 - V_71 -> V_173 ;
V_151 = 3 + V_155 ;
if ( V_144 -> V_175 & V_176 )
V_151 += V_144 -> V_177 ;
if ( ( V_71 -> V_175 & V_178 ) == 0 ) {
V_152 = 1 + V_71 -> V_179 - V_71 -> V_180 ;
V_165 = V_71 -> V_148 - V_71 -> V_180 - 1 ;
V_166 = V_165 + V_71 -> V_180 ;
V_157 = V_158 = V_155 ;
V_159 = V_71 -> V_179 - V_71 -> V_180 ;
V_160 = V_159 +
V_71 -> V_181 - V_71 -> V_179 ;
V_167 = V_168 = 0 ;
V_161 = V_162 = 0 ;
V_163 = V_164 = 0 ;
} else {
V_152 = 1 + ( V_71 -> V_179 - V_71 -> V_180 ) / 2 ;
V_165 = ( V_71 -> V_148 - V_71 -> V_180 ) / 2 ;
V_166 = V_165 + V_71 -> V_180 / 2 ;
V_157 = V_158 = V_155 ;
V_159 = ( V_71 -> V_179 - V_71 -> V_180 ) / 2 ;
V_160 = V_159 +
( V_71 -> V_181 - V_71 -> V_179 ) / 2 ;
V_167 = V_165 + V_71 -> V_148 / 2 ;
V_168 = V_167 + V_71 -> V_180 / 2 ;
V_161 = V_162 = V_155 + V_71 -> V_146 / 2 ;
V_163 = V_159 + V_71 -> V_148 / 2 ;
V_164 = V_163 +
( V_71 -> V_181 - V_71 -> V_179 ) / 2 ;
}
div = 148500 / V_71 -> clock ;
if ( div != 0 ) {
div -- ;
if ( div > 3 )
div = 3 ;
}
F_14 ( V_2 , V_80 , V_81 ) ;
F_12 ( V_2 , V_182 , V_183 ) ;
F_15 ( V_2 , V_184 , V_185 ) ;
F_12 ( V_2 , V_186 , F_51 ( 0 ) ) ;
F_12 ( V_2 , V_187 , F_52 ( 0 ) |
F_53 ( 0 ) ) ;
F_12 ( V_2 , V_188 , F_54 ( 0 ) ) ;
F_12 ( V_2 , V_189 , F_55 ( 0 ) |
F_56 ( 0 ) ) ;
F_15 ( V_2 , V_24 , V_190 ) ;
F_15 ( V_2 , V_26 , V_191 |
V_192 ) ;
F_12 ( V_2 , V_27 , 0 ) ;
F_12 ( V_2 , V_193 , F_57 ( 0 ) ) ;
V_171 = 0 ;
F_12 ( V_2 , V_194 , 0 ) ;
F_12 ( V_2 , V_32 , F_58 ( 0 ) |
V_33 | V_34 ) ;
F_12 ( V_2 , V_25 , F_18 ( div ) |
F_59 ( V_171 ) ) ;
F_12 ( V_2 , V_195 , V_196 |
F_60 ( 1 ) ) ;
F_12 ( V_2 , V_197 , 0x09 ) ;
V_12 = V_198 ;
if ( V_71 -> V_175 & V_199 )
V_12 |= V_200 ;
if ( V_71 -> V_175 & V_201 )
V_12 |= V_202 ;
F_12 ( V_2 , V_203 , V_12 ) ;
F_12 ( V_2 , V_204 , 0x00 ) ;
F_13 ( V_2 , V_205 , V_151 ) ;
F_13 ( V_2 , V_206 , V_152 ) ;
F_13 ( V_2 , V_207 , V_153 ) ;
F_13 ( V_2 , V_208 , V_154 ) ;
F_13 ( V_2 , V_209 , V_159 ) ;
F_13 ( V_2 , V_210 , V_157 ) ;
F_13 ( V_2 , V_211 , V_160 ) ;
F_13 ( V_2 , V_212 , V_158 ) ;
F_13 ( V_2 , V_213 , V_163 ) ;
F_13 ( V_2 , V_214 , V_161 ) ;
F_13 ( V_2 , V_215 , V_164 ) ;
F_13 ( V_2 , V_216 , V_162 ) ;
F_13 ( V_2 , V_217 , V_155 ) ;
F_13 ( V_2 , V_218 , V_156 ) ;
F_13 ( V_2 , V_219 , V_165 ) ;
F_13 ( V_2 , V_220 , V_166 ) ;
F_13 ( V_2 , V_221 , V_167 ) ;
F_13 ( V_2 , V_222 , V_168 ) ;
F_13 ( V_2 , V_223 , V_169 ) ;
F_13 ( V_2 , V_224 , V_170 ) ;
if ( V_2 -> V_225 == V_226 ) {
F_12 ( V_2 , V_227 , 0x00 ) ;
}
V_12 = V_183 | V_228 ;
if ( V_71 -> V_175 & V_199 )
V_12 |= V_229 ;
if ( V_71 -> V_175 & V_201 )
V_12 |= V_230 ;
F_12 ( V_2 , V_182 , V_12 ) ;
F_12 ( V_2 , V_231 , 0 ) ;
if ( V_2 -> V_232 ) {
V_12 &= ~ V_183 ;
F_12 ( V_2 , V_182 , V_12 ) ;
F_12 ( V_2 , V_186 , F_51 ( 1 ) ) ;
F_14 ( V_2 , V_184 , V_185 ) ;
F_28 ( V_2 , V_144 ) ;
if ( V_2 -> V_133 . V_88 )
F_31 ( V_2 , V_144 ,
& V_2 -> V_133 ) ;
}
}
static enum V_233
F_61 ( struct V_1 * V_2 )
{
T_2 V_4 = F_4 ( V_2 , V_51 ) ;
return ( V_4 & V_234 ) ? V_235 :
V_236 ;
}
static int F_62 ( struct V_1 * V_2 , T_2 * V_8 , int V_237 )
{
T_2 V_238 , V_239 ;
int V_9 , V_240 ;
V_238 = ( V_237 & 1 ) ? 128 : 0 ;
V_239 = V_237 / 2 ;
F_12 ( V_2 , V_241 , 0xa0 ) ;
F_12 ( V_2 , V_242 , V_238 ) ;
F_12 ( V_2 , V_243 , 0x60 ) ;
F_12 ( V_2 , V_244 , V_239 ) ;
V_2 -> V_56 = 1 ;
F_12 ( V_2 , V_245 , 0x1 ) ;
F_12 ( V_2 , V_245 , 0x0 ) ;
if ( V_2 -> V_14 -> V_41 ) {
V_240 = F_63 ( V_2 -> V_57 ,
! V_2 -> V_56 ,
F_64 ( 100 ) ) ;
if ( V_240 < 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_8 , V_240 ) ;
return V_240 ;
}
} else {
for ( V_240 = 100 ; V_240 > 0 ; V_240 -- ) {
F_17 ( 1 ) ;
V_9 = F_11 ( V_2 , V_54 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & V_55 )
break;
}
}
if ( V_240 == 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_9 ) ;
return - V_246 ;
}
V_9 = F_8 ( V_2 , V_247 , V_8 , V_248 ) ;
if ( V_9 != V_248 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_10 ,
V_237 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static T_2 * F_65 ( struct V_1 * V_2 )
{
int V_249 , V_250 = 0 ;
T_2 * V_251 , * V_252 ;
bool V_253 = V_254 & V_255 ;
if ( ( V_251 = F_66 ( V_248 , V_256 ) ) == NULL )
return NULL ;
if ( V_2 -> V_225 == V_226 )
F_15 ( V_2 , V_257 , V_258 ) ;
if ( F_62 ( V_2 , V_251 , 0 ) )
goto V_11;
if ( ! F_67 ( V_251 , 0 , V_253 ) )
goto V_11;
if ( V_251 [ 0x7e ] == 0 )
goto V_259;
V_252 = F_68 ( V_251 , ( V_251 [ 0x7e ] + 1 ) * V_248 , V_256 ) ;
if ( ! V_252 )
goto V_11;
V_251 = V_252 ;
for ( V_249 = 1 ; V_249 <= V_251 [ 0x7e ] ; V_249 ++ ) {
T_2 * V_260 = V_251 + ( V_250 + 1 ) * V_248 ;
if ( F_62 ( V_2 , V_260 , V_249 ) )
goto V_11;
if ( ! F_67 ( V_260 , V_249 , V_253 ) )
goto V_11;
V_250 ++ ;
}
if ( V_250 != V_251 [ 0x7e ] ) {
V_251 [ V_248 - 1 ] += V_251 [ 0x7e ] - V_250 ;
V_251 [ 0x7e ] = V_250 ;
V_252 = F_68 ( V_251 , ( V_250 + 1 ) * V_248 , V_256 ) ;
if ( ! V_252 )
goto V_11;
V_251 = V_252 ;
}
V_259:
if ( V_2 -> V_225 == V_226 )
F_14 ( V_2 , V_257 , V_258 ) ;
return V_251 ;
V_11:
if ( V_2 -> V_225 == V_226 )
F_14 ( V_2 , V_257 , V_258 ) ;
F_69 ( & V_2 -> V_14 -> V_10 , L_11 ) ;
F_70 ( V_251 ) ;
return NULL ;
}
static int
F_71 ( struct V_1 * V_2 ,
struct V_261 * V_262 )
{
struct V_263 * V_263 = (struct V_263 * ) F_65 ( V_2 ) ;
int V_86 = 0 ;
if ( V_263 ) {
F_72 ( V_262 , V_263 ) ;
V_86 = F_73 ( V_262 , V_263 ) ;
V_2 -> V_232 = F_74 ( V_263 ) ;
F_70 ( V_263 ) ;
}
return V_86 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_261 * V_262 )
{
if ( V_2 -> V_14 -> V_41 )
V_262 -> V_264 = V_265 ;
else
V_262 -> V_264 = V_266 |
V_267 ;
}
static int
F_76 ( struct V_143 * V_58 ,
struct V_261 * V_262 ,
struct V_268 * V_269 ,
T_7 V_4 )
{
F_45 ( L_7 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_270 , 0 ) ;
F_15 ( V_2 , V_54 , V_55 ) ;
if ( V_2 -> V_14 -> V_41 )
F_78 ( V_2 -> V_14 -> V_41 , V_2 ) ;
F_79 ( V_2 -> V_7 ) ;
}
static void
F_80 ( struct V_143 * V_58 , void * V_133 )
{
F_36 ( F_81 ( V_58 ) , V_133 ) ;
}
static void F_82 ( struct V_143 * V_58 )
{
struct V_1 * V_2 = F_81 ( V_58 ) ;
F_77 ( V_2 ) ;
F_83 ( V_58 ) ;
F_70 ( V_2 ) ;
}
static void F_84 ( struct V_143 * V_58 , int V_71 )
{
F_43 ( F_81 ( V_58 ) , V_71 ) ;
}
static int F_85 ( struct V_143 * V_58 ,
struct V_70 * V_71 )
{
return F_48 ( F_81 ( V_58 ) , V_71 ) ;
}
static void
F_86 ( struct V_143 * V_58 ,
struct V_70 * V_71 ,
struct V_70 * V_144 )
{
F_50 ( F_81 ( V_58 ) , V_71 , V_144 ) ;
}
static enum V_233
F_87 ( struct V_143 * V_58 ,
struct V_261 * V_262 )
{
return F_61 ( F_81 ( V_58 ) ) ;
}
static int F_88 ( struct V_143 * V_58 ,
struct V_261 * V_262 )
{
return F_71 ( F_81 ( V_58 ) , V_262 ) ;
}
static int
F_89 ( struct V_143 * V_58 ,
struct V_261 * V_262 )
{
F_75 ( F_81 ( V_58 ) , V_262 ) ;
return 0 ;
}
static int F_90 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_271 * V_272 = V_6 -> V_10 . V_273 ;
T_8 V_274 ;
int V_275 , V_276 , V_9 ;
V_2 -> V_112 = F_37 ( 2 ) | F_38 ( 3 ) ;
V_2 -> V_119 = F_39 ( 0 ) | F_40 ( 1 ) ;
V_2 -> V_126 = F_41 ( 4 ) | F_42 ( 5 ) ;
V_2 -> V_13 = 0xff ;
V_2 -> V_14 = V_6 ;
V_2 -> V_7 = F_91 ( V_6 -> V_277 , 0x34 ) ;
if ( ! V_2 -> V_7 )
return - V_278 ;
V_2 -> V_136 = V_135 ;
F_1 ( V_2 , V_279 ,
V_280 | V_281 ) ;
F_16 ( V_2 ) ;
V_275 = F_11 ( V_2 , V_282 ) ;
V_276 = F_11 ( V_2 , V_283 ) ;
if ( V_275 < 0 || V_276 < 0 ) {
V_9 = V_275 < 0 ? V_275 : V_276 ;
goto V_11;
}
V_2 -> V_225 = V_275 | V_276 << 8 ;
V_2 -> V_225 &= ~ 0x30 ;
switch ( V_2 -> V_225 ) {
case V_284 :
F_92 ( & V_6 -> V_10 , L_12 ) ;
break;
case V_285 :
F_92 ( & V_6 -> V_10 , L_13 ) ;
break;
case V_286 :
F_92 ( & V_6 -> V_10 , L_14 ) ;
break;
case V_226 :
F_92 ( & V_6 -> V_10 , L_15 ) ;
break;
default:
F_3 ( & V_6 -> V_10 , L_16 ,
V_2 -> V_225 ) ;
goto V_11;
}
F_12 ( V_2 , V_287 , 0x00 ) ;
F_12 ( V_2 , V_288 , 39 ) ;
if ( V_2 -> V_225 == V_285 )
F_14 ( V_2 , V_289 , V_290 ) ;
F_1 ( V_2 , V_291 ,
V_292 | V_293 ) ;
if ( V_6 -> V_41 ) {
int V_294 ;
F_93 ( & V_2 -> V_57 ) ;
F_11 ( V_2 , V_52 ) ;
F_11 ( V_2 , V_53 ) ;
F_11 ( V_2 , V_54 ) ;
V_294 =
F_94 ( F_95 ( V_6 -> V_41 ) ) ;
V_9 = F_96 ( V_6 -> V_41 , NULL ,
F_19 ,
V_294 | V_295 ,
L_17 , V_2 ) ;
if ( V_9 ) {
F_3 ( & V_6 -> V_10 ,
L_18 ,
V_6 -> V_41 , V_9 ) ;
goto V_11;
}
F_1 ( V_2 , V_270 , V_234 ) ;
}
F_14 ( V_2 , V_54 , V_55 ) ;
if ( ! V_272 )
return 0 ;
V_9 = F_97 ( V_272 , L_19 , & V_274 ) ;
if ( V_9 == 0 ) {
V_2 -> V_112 = V_274 >> 16 ;
V_2 -> V_119 = V_274 >> 8 ;
V_2 -> V_126 = V_274 ;
}
return 0 ;
V_11:
if ( V_2 -> V_7 )
F_79 ( V_2 -> V_7 ) ;
return - V_296 ;
}
static int F_98 ( struct V_5 * V_6 ,
struct V_297 * V_10 ,
struct V_298 * V_299 )
{
struct V_1 * V_2 ;
int V_9 ;
V_2 = F_99 ( sizeof( * V_2 ) , V_256 ) ;
if ( ! V_2 )
return - V_300 ;
V_2 -> V_58 = & V_299 -> V_301 ;
V_9 = F_90 ( V_6 , V_2 ) ;
if ( V_9 ) {
F_70 ( V_2 ) ;
return V_9 ;
}
V_299 -> V_302 = V_2 ;
V_299 -> V_303 = & V_304 ;
return 0 ;
}
static void F_100 ( struct V_143 * V_58 , int V_71 )
{
struct V_305 * V_2 = F_101 ( V_58 ) ;
F_43 ( & V_2 -> V_301 , V_71 ) ;
}
static void F_102 ( struct V_143 * V_58 )
{
F_100 ( V_58 , V_135 ) ;
}
static void F_103 ( struct V_143 * V_58 )
{
F_100 ( V_58 , V_134 ) ;
}
static void F_104 ( struct V_143 * V_58 ,
struct V_70 * V_71 ,
struct V_70 * V_144 )
{
struct V_305 * V_2 = F_101 ( V_58 ) ;
F_50 ( & V_2 -> V_301 , V_71 , V_144 ) ;
}
static void F_105 ( struct V_143 * V_58 )
{
struct V_305 * V_2 = F_101 ( V_58 ) ;
F_77 ( & V_2 -> V_301 ) ;
F_106 ( V_58 ) ;
}
static int F_107 ( struct V_261 * V_262 )
{
struct V_305 * V_2 = F_108 ( V_262 ) ;
return F_71 ( & V_2 -> V_301 , V_262 ) ;
}
static int F_109 ( struct V_261 * V_262 ,
struct V_70 * V_71 )
{
struct V_305 * V_2 = F_108 ( V_262 ) ;
return F_48 ( & V_2 -> V_301 , V_71 ) ;
}
static struct V_143 *
F_110 ( struct V_261 * V_262 )
{
struct V_305 * V_2 = F_108 ( V_262 ) ;
return & V_2 -> V_58 ;
}
static enum V_233
F_111 ( struct V_261 * V_262 , bool V_306 )
{
struct V_305 * V_2 = F_108 ( V_262 ) ;
return F_61 ( & V_2 -> V_301 ) ;
}
static void F_112 ( struct V_261 * V_262 )
{
F_113 ( V_262 ) ;
F_114 ( V_262 ) ;
}
static int F_115 ( struct V_307 * V_10 , struct V_307 * V_308 , void * V_42 )
{
struct V_64 * V_133 = V_10 -> V_309 ;
struct V_5 * V_6 = F_116 ( V_10 ) ;
struct V_297 * V_310 = V_42 ;
struct V_305 * V_2 ;
int V_9 ;
V_2 = F_117 ( V_10 , sizeof( * V_2 ) , V_256 ) ;
if ( ! V_2 )
return - V_300 ;
F_118 ( V_10 , V_2 ) ;
V_2 -> V_301 . V_58 = & V_2 -> V_58 ;
V_2 -> V_262 . V_311 = 1 ;
V_2 -> V_58 . V_312 = 1 << 0 ;
V_9 = F_90 ( V_6 , & V_2 -> V_301 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_10 -> V_273 && V_133 )
F_36 ( & V_2 -> V_301 , V_133 ) ;
F_75 ( & V_2 -> V_301 , & V_2 -> V_262 ) ;
F_119 ( & V_2 -> V_58 , & V_313 ) ;
V_9 = F_120 ( V_310 , & V_2 -> V_58 , & V_314 ,
V_315 ) ;
if ( V_9 )
goto V_316;
F_121 ( & V_2 -> V_262 ,
& V_317 ) ;
V_9 = F_122 ( V_310 , & V_2 -> V_262 ,
& V_318 ,
V_319 ) ;
if ( V_9 )
goto V_320;
V_9 = F_123 ( & V_2 -> V_262 ) ;
if ( V_9 )
goto V_321;
V_2 -> V_262 . V_58 = & V_2 -> V_58 ;
F_124 ( & V_2 -> V_262 , & V_2 -> V_58 ) ;
return 0 ;
V_321:
F_114 ( & V_2 -> V_262 ) ;
V_320:
F_106 ( & V_2 -> V_58 ) ;
V_316:
F_77 ( & V_2 -> V_301 ) ;
return V_9 ;
}
static void F_125 ( struct V_307 * V_10 , struct V_307 * V_308 ,
void * V_42 )
{
struct V_305 * V_2 = F_126 ( V_10 ) ;
F_114 ( & V_2 -> V_262 ) ;
F_106 ( & V_2 -> V_58 ) ;
F_77 ( & V_2 -> V_301 ) ;
}
static int
F_127 ( struct V_5 * V_6 , const struct V_322 * V_323 )
{
return F_128 ( & V_6 -> V_10 , & V_324 ) ;
}
static int F_129 ( struct V_5 * V_6 )
{
F_130 ( & V_6 -> V_10 , & V_324 ) ;
return 0 ;
}
static int T_9
F_131 ( void )
{
F_45 ( L_7 ) ;
return F_132 ( V_325 , & V_326 ) ;
}
static void T_10
F_133 ( void )
{
F_45 ( L_7 ) ;
F_134 ( & V_326 ) ;
}
