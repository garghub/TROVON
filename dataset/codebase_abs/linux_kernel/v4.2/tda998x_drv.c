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
F_3 ( & V_6 -> V_10 , L_3 , V_16 ,
V_12 , V_9 ) ;
return V_9 ;
}
V_2 -> V_13 = F_7 ( V_12 ) ;
}
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_12 , char * V_8 , int V_17 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_3 = F_9 ( V_12 ) ;
int V_9 ;
F_10 ( & V_2 -> V_18 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_2 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_5 ( V_6 , V_8 , V_17 ) ;
if ( V_9 < 0 )
goto V_11;
goto V_19;
V_11:
F_3 ( & V_6 -> V_10 , L_4 , V_9 , V_12 ) ;
V_19:
F_11 ( & V_2 -> V_18 ) ;
return V_9 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_12 , T_2 * V_20 , int V_17 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [ V_17 + 1 ] ;
int V_9 ;
V_8 [ 0 ] = F_9 ( V_12 ) ;
memcpy ( & V_8 [ 1 ] , V_20 , V_17 ) ;
F_10 ( & V_2 -> V_18 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_2 ( V_6 , V_8 , V_17 + 1 ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
V_19:
F_11 ( & V_2 -> V_18 ) ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 V_12 )
{
T_2 V_4 = 0 ;
int V_9 ;
V_9 = F_8 ( V_2 , V_12 , & V_4 , sizeof( V_4 ) ) ;
if ( V_9 < 0 )
return V_9 ;
return V_4 ;
}
static void
F_14 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [] = { F_9 ( V_12 ) , V_4 } ;
int V_9 ;
F_10 ( & V_2 -> V_18 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
V_19:
F_11 ( & V_2 -> V_18 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [] = { F_9 ( V_12 ) , V_4 >> 8 , V_4 } ;
int V_9 ;
F_10 ( & V_2 -> V_18 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
V_19:
F_11 ( & V_2 -> V_18 ) ;
}
static void
F_16 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
int V_21 ;
V_21 = F_13 ( V_2 , V_12 ) ;
if ( V_21 >= 0 )
F_14 ( V_2 , V_12 , V_21 | V_4 ) ;
}
static void
F_17 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
int V_21 ;
V_21 = F_13 ( V_2 , V_12 ) ;
if ( V_21 >= 0 )
F_14 ( V_2 , V_12 , V_21 & ~ V_4 ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_22 , V_23 | V_24 ) ;
F_19 ( 50 ) ;
F_14 ( V_2 , V_22 , 0 ) ;
F_19 ( 50 ) ;
F_16 ( V_2 , V_25 , V_26 ) ;
F_17 ( V_2 , V_25 , V_26 ) ;
F_14 ( V_2 , V_27 , 0x00 ) ;
F_14 ( V_2 , V_28 , F_20 ( 1 ) ) ;
F_14 ( V_2 , V_29 , 0x00 ) ;
F_14 ( V_2 , V_30 , 0x00 ) ;
F_14 ( V_2 , V_31 , 0x00 ) ;
F_14 ( V_2 , V_32 , 0x00 ) ;
F_14 ( V_2 , V_33 , V_34 ) ;
F_14 ( V_2 , V_35 , V_36 | V_37 ) ;
F_14 ( V_2 , V_38 , 0xfa ) ;
F_14 ( V_2 , V_39 , 0x00 ) ;
F_14 ( V_2 , V_40 , 0x5b ) ;
F_14 ( V_2 , V_41 , 0x00 ) ;
F_14 ( V_2 , V_42 , 0x10 ) ;
F_14 ( V_2 , V_43 , 0x24 ) ;
}
static void F_21 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_22 ( V_45 ) ;
struct V_1 * V_2 =
F_23 ( V_47 , struct V_1 , V_47 ) ;
if ( V_2 -> V_48 && V_2 -> V_48 -> V_10 )
F_24 ( V_2 -> V_48 -> V_10 ) ;
}
static T_3 F_25 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
T_4 V_51 , V_7 , V_52 , V_53 , V_54 , V_55 ;
if ( ! V_2 )
return V_56 ;
V_51 = F_4 ( V_2 , V_57 ) ;
V_7 = F_4 ( V_2 , V_58 ) ;
V_52 = F_4 ( V_2 , V_59 ) ;
V_53 = F_13 ( V_2 , V_60 ) ;
V_54 = F_13 ( V_2 , V_61 ) ;
V_55 = F_13 ( V_2 , V_62 ) ;
F_26 (
L_6 ,
V_51 , V_7 , V_52 , V_53 , V_54 , V_55 ) ;
if ( ( V_55 & V_63 ) && V_2 -> V_64 ) {
V_2 -> V_64 = 0 ;
F_27 ( & V_2 -> V_65 ) ;
} else if ( V_7 != 0 ) {
F_28 ( & V_2 -> V_47 , V_66 / 10 ) ;
}
return V_56 ;
}
static T_2 F_29 ( T_2 * V_8 , T_5 V_67 )
{
int V_68 = 0 ;
while ( V_67 -- )
V_68 -= * V_8 ++ ;
return V_68 ;
}
static void
F_30 ( struct V_1 * V_2 , T_2 V_69 , T_1 V_3 ,
T_2 * V_8 , T_5 V_70 )
{
F_17 ( V_2 , V_71 , V_69 ) ;
F_12 ( V_2 , V_3 , V_8 , V_70 ) ;
F_16 ( V_2 , V_71 , V_69 ) ;
}
static void
F_31 ( struct V_1 * V_2 , struct V_72 * V_20 )
{
T_4 V_8 [ F_32 ( V_73 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_33 ( 0 ) ] = V_74 ;
V_8 [ F_33 ( 1 ) ] = 0x01 ;
V_8 [ F_33 ( 2 ) ] = V_73 ;
V_8 [ F_32 ( 1 ) ] = V_20 -> V_75 [ 1 ] & 0x07 ;
V_8 [ F_32 ( 2 ) ] = V_20 -> V_75 [ 2 ] & 0x1c ;
V_8 [ F_32 ( 4 ) ] = V_20 -> V_75 [ 4 ] ;
V_8 [ F_32 ( 5 ) ] = V_20 -> V_75 [ 5 ] & 0xf8 ;
V_8 [ F_32 ( 0 ) ] = F_29 ( V_8 , sizeof( V_8 ) ) ;
F_30 ( V_2 , V_76 , V_77 , V_8 ,
sizeof( V_8 ) ) ;
}
static void
F_34 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_80 V_81 ;
T_4 V_8 [ V_82 + V_83 ] ;
T_6 V_84 ;
F_35 ( & V_81 , V_79 ) ;
V_81 . V_85 = V_86 ;
V_84 = F_36 ( & V_81 , V_8 , sizeof( V_8 ) ) ;
if ( V_84 < 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 ,
L_7 , V_84 ) ;
return;
}
F_30 ( V_2 , V_87 , V_88 , V_8 , V_84 ) ;
}
static void F_37 ( struct V_1 * V_2 , bool V_89 )
{
if ( V_89 ) {
F_16 ( V_2 , V_22 , V_23 ) ;
F_17 ( V_2 , V_22 , V_23 ) ;
F_16 ( V_2 , V_90 , V_91 ) ;
} else {
F_17 ( V_2 , V_90 , V_91 ) ;
}
}
static void
F_38 ( struct V_1 * V_2 ,
struct V_78 * V_79 , struct V_72 * V_20 )
{
T_2 V_8 [ 6 ] , V_92 , V_93 , V_94 , V_95 ;
T_7 V_96 ;
F_14 ( V_2 , V_97 , V_20 -> V_98 ) ;
F_14 ( V_2 , V_99 , V_20 -> V_100 ) ;
switch ( V_20 -> V_101 ) {
case V_102 :
F_14 ( V_2 , V_103 , V_104 ) ;
V_92 = V_105 ;
V_93 = V_106 ;
V_94 = F_39 ( 3 ) | F_40 ( 3 ) ;
break;
case V_107 :
F_14 ( V_2 , V_103 , V_108 ) ;
V_92 = V_109 ;
V_93 = V_110 ;
V_94 = F_39 ( 3 ) | F_40 ( 3 ) ;
break;
default:
F_41 () ;
return;
}
F_14 ( V_2 , V_111 , V_92 ) ;
F_17 ( V_2 , V_90 , V_112 |
V_113 ) ;
F_14 ( V_2 , V_114 , V_94 ) ;
V_95 = V_34 ;
if ( V_79 -> clock > 100000 )
V_95 ++ ;
if ( V_20 -> V_101 == V_102 )
V_95 ++ ;
F_14 ( V_2 , V_33 , V_95 ) ;
V_96 = 128 * V_20 -> V_115 / 1000 ;
V_8 [ 0 ] = 0x44 ;
V_8 [ 1 ] = 0x42 ;
V_8 [ 2 ] = 0x01 ;
V_8 [ 3 ] = V_96 ;
V_8 [ 4 ] = V_96 >> 8 ;
V_8 [ 5 ] = V_96 >> 16 ;
F_12 ( V_2 , V_116 , V_8 , 6 ) ;
F_14 ( V_2 , V_111 , V_92 | V_93 ) ;
F_16 ( V_2 , V_90 , V_117 ) ;
F_17 ( V_2 , V_90 , V_117 ) ;
V_8 [ 0 ] = V_118 ;
V_8 [ 1 ] = 0x00 ;
V_8 [ 2 ] = V_119 ;
V_8 [ 3 ] = V_120 |
V_121 ;
F_12 ( V_2 , F_42 ( 0 ) , V_8 , 4 ) ;
F_37 ( V_2 , true ) ;
F_19 ( 20 ) ;
F_37 ( V_2 , false ) ;
F_31 ( V_2 , V_20 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
const struct V_72 * V_20 )
{
V_2 -> V_122 = F_44 ( V_20 -> V_123 ) |
( V_20 -> V_124 ? V_125 : 0 ) |
F_45 ( V_20 -> V_126 ) |
( V_20 -> V_127 ? V_128 : 0 ) ;
V_2 -> V_129 = F_46 ( V_20 -> V_130 ) |
( V_20 -> V_131 ? V_132 : 0 ) |
F_47 ( V_20 -> V_133 ) |
( V_20 -> V_134 ? V_135 : 0 ) ;
V_2 -> V_136 = F_48 ( V_20 -> V_137 ) |
( V_20 -> V_138 ? V_139 : 0 ) |
F_49 ( V_20 -> V_140 ) |
( V_20 -> V_141 ? V_142 : 0 ) ;
V_2 -> V_143 = * V_20 ;
}
static void F_50 ( struct V_1 * V_2 , int V_79 )
{
if ( V_79 != V_144 )
V_79 = V_145 ;
if ( V_79 == V_2 -> V_146 )
return;
switch ( V_79 ) {
case V_144 :
F_14 ( V_2 , V_147 , 0xff ) ;
F_14 ( V_2 , V_148 , 0xff ) ;
F_14 ( V_2 , V_149 , 0xff ) ;
F_14 ( V_2 , V_150 , V_2 -> V_122 ) ;
F_14 ( V_2 , V_151 , V_2 -> V_129 ) ;
F_14 ( V_2 , V_152 , V_2 -> V_136 ) ;
break;
case V_145 :
F_14 ( V_2 , V_147 , 0x00 ) ;
F_14 ( V_2 , V_148 , 0x00 ) ;
F_14 ( V_2 , V_149 , 0x00 ) ;
break;
}
V_2 -> V_146 = V_79 ;
}
static void
F_51 ( struct V_153 * V_48 )
{
F_52 ( L_8 ) ;
}
static void
F_53 ( struct V_153 * V_48 )
{
F_52 ( L_8 ) ;
}
static bool
F_54 ( struct V_153 * V_48 ,
const struct V_78 * V_79 ,
struct V_78 * V_154 )
{
return true ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
if ( V_79 -> clock > 150000 )
return V_155 ;
if ( V_79 -> V_156 >= F_56 ( 13 ) )
return V_157 ;
if ( V_79 -> V_158 >= F_56 ( 11 ) )
return V_159 ;
return V_160 ;
}
static void
F_57 ( struct V_1 * V_2 ,
struct V_78 * V_79 ,
struct V_78 * V_154 )
{
T_1 V_161 , V_162 , V_163 , V_164 ;
T_1 V_165 , V_166 ;
T_1 V_167 , V_168 , V_169 , V_170 ;
T_1 V_171 , V_172 , V_173 , V_174 ;
T_1 V_175 , V_176 ;
T_1 V_177 , V_178 ;
T_1 V_179 , V_180 ;
T_2 V_12 , div , V_181 ;
V_163 = V_79 -> V_156 ;
V_164 = V_79 -> V_158 ;
V_166 = V_79 -> V_182 - V_79 -> V_183 ;
V_165 = V_79 -> V_184 - V_79 -> V_183 ;
V_180 = V_79 -> V_156 ;
V_179 = V_79 -> V_156 - V_79 -> V_183 ;
V_161 = 3 + V_165 ;
if ( V_154 -> V_185 & V_186 )
V_161 += V_154 -> V_187 ;
if ( ( V_79 -> V_185 & V_188 ) == 0 ) {
V_162 = 1 + V_79 -> V_189 - V_79 -> V_190 ;
V_175 = V_79 -> V_158 - V_79 -> V_190 - 1 ;
V_176 = V_175 + V_79 -> V_190 ;
V_167 = V_168 = V_165 ;
V_169 = V_79 -> V_189 - V_79 -> V_190 ;
V_170 = V_169 +
V_79 -> V_191 - V_79 -> V_189 ;
V_177 = V_178 = 0 ;
V_171 = V_172 = 0 ;
V_173 = V_174 = 0 ;
} else {
V_162 = 1 + ( V_79 -> V_189 - V_79 -> V_190 ) / 2 ;
V_175 = ( V_79 -> V_158 - V_79 -> V_190 ) / 2 ;
V_176 = V_175 + V_79 -> V_190 / 2 ;
V_167 = V_168 = V_165 ;
V_169 = ( V_79 -> V_189 - V_79 -> V_190 ) / 2 ;
V_170 = V_169 +
( V_79 -> V_191 - V_79 -> V_189 ) / 2 ;
V_177 = V_175 + V_79 -> V_158 / 2 ;
V_178 = V_177 + V_79 -> V_190 / 2 ;
V_171 = V_172 = V_165 + V_79 -> V_156 / 2 ;
V_173 = V_169 + V_79 -> V_158 / 2 ;
V_174 = V_173 +
( V_79 -> V_191 - V_79 -> V_189 ) / 2 ;
}
div = 148500 / V_79 -> clock ;
if ( div != 0 ) {
div -- ;
if ( div > 3 )
div = 3 ;
}
F_16 ( V_2 , V_90 , V_91 ) ;
F_14 ( V_2 , V_192 , V_193 ) ;
F_17 ( V_2 , V_194 , V_195 ) ;
F_14 ( V_2 , V_196 , F_58 ( 0 ) ) ;
F_14 ( V_2 , V_197 , F_59 ( 0 ) |
F_60 ( 0 ) ) ;
F_14 ( V_2 , V_198 , F_61 ( 0 ) ) ;
F_14 ( V_2 , V_199 , F_62 ( 0 ) |
F_63 ( 0 ) ) ;
F_17 ( V_2 , V_27 , V_200 ) ;
F_17 ( V_2 , V_29 , V_201 |
V_202 ) ;
F_14 ( V_2 , V_30 , 0 ) ;
F_14 ( V_2 , V_203 , F_64 ( 0 ) ) ;
V_181 = 0 ;
F_14 ( V_2 , V_204 , 0 ) ;
F_14 ( V_2 , V_35 , F_65 ( 0 ) |
V_36 | V_37 ) ;
F_14 ( V_2 , V_28 , F_20 ( div ) |
F_66 ( V_181 ) ) ;
F_14 ( V_2 , V_205 , V_206 |
F_67 ( 1 ) ) ;
F_14 ( V_2 , V_207 , 0x09 ) ;
V_12 = V_208 ;
if ( V_79 -> V_185 & V_209 )
V_12 |= V_210 ;
if ( V_79 -> V_185 & V_211 )
V_12 |= V_212 ;
F_14 ( V_2 , V_213 , V_12 ) ;
F_14 ( V_2 , V_214 , 0x00 ) ;
F_15 ( V_2 , V_215 , V_161 ) ;
F_15 ( V_2 , V_216 , V_162 ) ;
F_15 ( V_2 , V_217 , V_163 ) ;
F_15 ( V_2 , V_218 , V_164 ) ;
F_15 ( V_2 , V_219 , V_169 ) ;
F_15 ( V_2 , V_220 , V_167 ) ;
F_15 ( V_2 , V_221 , V_170 ) ;
F_15 ( V_2 , V_222 , V_168 ) ;
F_15 ( V_2 , V_223 , V_173 ) ;
F_15 ( V_2 , V_224 , V_171 ) ;
F_15 ( V_2 , V_225 , V_174 ) ;
F_15 ( V_2 , V_226 , V_172 ) ;
F_15 ( V_2 , V_227 , V_165 ) ;
F_15 ( V_2 , V_228 , V_166 ) ;
F_15 ( V_2 , V_229 , V_175 ) ;
F_15 ( V_2 , V_230 , V_176 ) ;
F_15 ( V_2 , V_231 , V_177 ) ;
F_15 ( V_2 , V_232 , V_178 ) ;
F_15 ( V_2 , V_233 , V_179 ) ;
F_15 ( V_2 , V_234 , V_180 ) ;
if ( V_2 -> V_235 == V_236 ) {
F_14 ( V_2 , V_237 , 0x00 ) ;
}
V_12 = V_193 | V_238 ;
if ( V_79 -> V_185 & V_209 )
V_12 |= V_239 ;
if ( V_79 -> V_185 & V_211 )
V_12 |= V_240 ;
F_14 ( V_2 , V_192 , V_12 ) ;
F_14 ( V_2 , V_241 , 0 ) ;
if ( V_2 -> V_242 ) {
V_12 &= ~ V_193 ;
F_14 ( V_2 , V_192 , V_12 ) ;
F_14 ( V_2 , V_196 , F_58 ( 1 ) ) ;
F_16 ( V_2 , V_194 , V_195 ) ;
F_34 ( V_2 , V_154 ) ;
if ( V_2 -> V_143 . V_98 )
F_38 ( V_2 , V_154 ,
& V_2 -> V_143 ) ;
}
}
static enum V_243
F_68 ( struct V_1 * V_2 )
{
T_2 V_4 = F_4 ( V_2 , V_59 ) ;
return ( V_4 & V_244 ) ? V_245 :
V_246 ;
}
static int F_69 ( void * V_50 , T_4 * V_8 , unsigned int V_247 , T_5 V_248 )
{
struct V_1 * V_2 = V_50 ;
T_2 V_249 , V_250 ;
int V_9 , V_251 ;
V_249 = ( V_247 & 1 ) ? 128 : 0 ;
V_250 = V_247 / 2 ;
F_14 ( V_2 , V_252 , 0xa0 ) ;
F_14 ( V_2 , V_253 , V_249 ) ;
F_14 ( V_2 , V_254 , 0x60 ) ;
F_14 ( V_2 , V_255 , V_250 ) ;
V_2 -> V_64 = 1 ;
F_14 ( V_2 , V_256 , 0x1 ) ;
F_14 ( V_2 , V_256 , 0x0 ) ;
if ( V_2 -> V_14 -> V_49 ) {
V_251 = F_70 ( V_2 -> V_65 ,
! V_2 -> V_64 ,
F_71 ( 100 ) ) ;
if ( V_251 < 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_9 , V_251 ) ;
return V_251 ;
}
} else {
for ( V_251 = 100 ; V_251 > 0 ; V_251 -- ) {
F_19 ( 1 ) ;
V_9 = F_13 ( V_2 , V_62 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & V_63 )
break;
}
}
if ( V_251 == 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_10 ) ;
return - V_257 ;
}
V_9 = F_8 ( V_2 , V_258 , V_8 , V_248 ) ;
if ( V_9 != V_248 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_11 ,
V_247 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int
F_72 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
struct V_261 * V_261 ;
int V_96 ;
if ( V_2 -> V_235 == V_236 )
F_17 ( V_2 , V_262 , V_263 ) ;
V_261 = F_73 ( V_260 , F_69 , V_2 ) ;
if ( V_2 -> V_235 == V_236 )
F_16 ( V_2 , V_262 , V_263 ) ;
if ( ! V_261 ) {
F_74 ( & V_2 -> V_14 -> V_10 , L_12 ) ;
return 0 ;
}
F_75 ( V_260 , V_261 ) ;
V_96 = F_76 ( V_260 , V_261 ) ;
V_2 -> V_242 = F_77 ( V_261 ) ;
F_78 ( V_261 ) ;
return V_96 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
if ( V_2 -> V_14 -> V_49 )
V_260 -> V_264 = V_265 ;
else
V_260 -> V_264 = V_266 |
V_267 ;
}
static int
F_80 ( struct V_153 * V_48 ,
struct V_259 * V_260 ,
struct V_268 * V_269 ,
T_8 V_4 )
{
F_52 ( L_8 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_270 , 0 ) ;
F_17 ( V_2 , V_62 , V_63 ) ;
if ( V_2 -> V_14 -> V_49 ) {
F_82 ( V_2 -> V_14 -> V_49 , V_2 ) ;
F_83 ( & V_2 -> V_47 ) ;
}
F_84 ( V_2 -> V_7 ) ;
}
static void
F_85 ( struct V_153 * V_48 , void * V_143 )
{
F_43 ( F_86 ( V_48 ) , V_143 ) ;
}
static void F_87 ( struct V_153 * V_48 )
{
struct V_1 * V_2 = F_86 ( V_48 ) ;
F_81 ( V_2 ) ;
F_88 ( V_48 ) ;
F_78 ( V_2 ) ;
}
static void F_89 ( struct V_153 * V_48 , int V_79 )
{
F_50 ( F_86 ( V_48 ) , V_79 ) ;
}
static int F_90 ( struct V_153 * V_48 ,
struct V_78 * V_79 )
{
return F_55 ( F_86 ( V_48 ) , V_79 ) ;
}
static void
F_91 ( struct V_153 * V_48 ,
struct V_78 * V_79 ,
struct V_78 * V_154 )
{
F_57 ( F_86 ( V_48 ) , V_79 , V_154 ) ;
}
static enum V_243
F_92 ( struct V_153 * V_48 ,
struct V_259 * V_260 )
{
return F_68 ( F_86 ( V_48 ) ) ;
}
static int F_93 ( struct V_153 * V_48 ,
struct V_259 * V_260 )
{
return F_72 ( F_86 ( V_48 ) , V_260 ) ;
}
static int
F_94 ( struct V_153 * V_48 ,
struct V_259 * V_260 )
{
F_79 ( F_86 ( V_48 ) , V_260 ) ;
return 0 ;
}
static int F_95 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_271 * V_272 = V_6 -> V_10 . V_273 ;
T_9 V_274 ;
int V_275 , V_276 , V_9 ;
unsigned short V_277 ;
V_2 -> V_122 = F_44 ( 2 ) | F_45 ( 3 ) ;
V_2 -> V_129 = F_46 ( 0 ) | F_47 ( 1 ) ;
V_2 -> V_136 = F_48 ( 4 ) | F_49 ( 5 ) ;
V_2 -> V_13 = 0xff ;
V_2 -> V_14 = V_6 ;
V_277 = 0x34 + ( V_6 -> V_3 & 0x03 ) ;
V_2 -> V_7 = F_96 ( V_6 -> V_278 , V_277 ) ;
if ( ! V_2 -> V_7 )
return - V_279 ;
V_2 -> V_146 = V_145 ;
F_97 ( & V_2 -> V_18 ) ;
F_1 ( V_2 , V_280 ,
V_281 | V_282 ) ;
F_18 ( V_2 ) ;
V_275 = F_13 ( V_2 , V_283 ) ;
V_276 = F_13 ( V_2 , V_284 ) ;
if ( V_275 < 0 || V_276 < 0 ) {
V_9 = V_275 < 0 ? V_275 : V_276 ;
goto V_11;
}
V_2 -> V_235 = V_275 | V_276 << 8 ;
V_2 -> V_235 &= ~ 0x30 ;
switch ( V_2 -> V_235 ) {
case V_285 :
F_98 ( & V_6 -> V_10 , L_13 ) ;
break;
case V_286 :
F_98 ( & V_6 -> V_10 , L_14 ) ;
break;
case V_287 :
F_98 ( & V_6 -> V_10 , L_15 ) ;
break;
case V_236 :
F_98 ( & V_6 -> V_10 , L_16 ) ;
break;
default:
F_3 ( & V_6 -> V_10 , L_17 ,
V_2 -> V_235 ) ;
goto V_11;
}
F_14 ( V_2 , V_288 , 0x00 ) ;
F_14 ( V_2 , V_289 , 39 ) ;
if ( V_2 -> V_235 == V_286 )
F_16 ( V_2 , V_290 , V_291 ) ;
F_1 ( V_2 , V_292 ,
V_293 | V_294 ) ;
if ( V_6 -> V_49 ) {
int V_295 ;
F_99 ( & V_2 -> V_65 ) ;
F_100 ( & V_2 -> V_47 , F_21 ) ;
F_13 ( V_2 , V_60 ) ;
F_13 ( V_2 , V_61 ) ;
F_13 ( V_2 , V_62 ) ;
V_295 =
F_101 ( F_102 ( V_6 -> V_49 ) ) ;
V_9 = F_103 ( V_6 -> V_49 , NULL ,
F_25 ,
V_295 | V_296 ,
L_18 , V_2 ) ;
if ( V_9 ) {
F_3 ( & V_6 -> V_10 ,
L_19 ,
V_6 -> V_49 , V_9 ) ;
goto V_11;
}
F_1 ( V_2 , V_270 , V_244 ) ;
}
F_16 ( V_2 , V_62 , V_63 ) ;
if ( ! V_272 )
return 0 ;
V_9 = F_104 ( V_272 , L_20 , & V_274 ) ;
if ( V_9 == 0 ) {
V_2 -> V_122 = V_274 >> 16 ;
V_2 -> V_129 = V_274 >> 8 ;
V_2 -> V_136 = V_274 ;
}
return 0 ;
V_11:
if ( V_2 -> V_7 )
F_84 ( V_2 -> V_7 ) ;
return - V_297 ;
}
static int F_105 ( struct V_5 * V_6 ,
struct V_298 * V_10 ,
struct V_299 * V_300 )
{
struct V_1 * V_2 ;
int V_9 ;
V_2 = F_106 ( sizeof( * V_2 ) , V_301 ) ;
if ( ! V_2 )
return - V_302 ;
V_2 -> V_48 = & V_300 -> V_303 ;
V_9 = F_95 ( V_6 , V_2 ) ;
if ( V_9 ) {
F_78 ( V_2 ) ;
return V_9 ;
}
V_300 -> V_304 = V_2 ;
V_300 -> V_305 = & V_306 ;
return 0 ;
}
static void F_107 ( struct V_153 * V_48 , int V_79 )
{
struct V_307 * V_2 = F_108 ( V_48 ) ;
F_50 ( & V_2 -> V_303 , V_79 ) ;
}
static void F_109 ( struct V_153 * V_48 )
{
F_107 ( V_48 , V_145 ) ;
}
static void F_110 ( struct V_153 * V_48 )
{
F_107 ( V_48 , V_144 ) ;
}
static void F_111 ( struct V_153 * V_48 ,
struct V_78 * V_79 ,
struct V_78 * V_154 )
{
struct V_307 * V_2 = F_108 ( V_48 ) ;
F_57 ( & V_2 -> V_303 , V_79 , V_154 ) ;
}
static void F_112 ( struct V_153 * V_48 )
{
struct V_307 * V_2 = F_108 ( V_48 ) ;
F_81 ( & V_2 -> V_303 ) ;
F_113 ( V_48 ) ;
}
static int F_114 ( struct V_259 * V_260 )
{
struct V_307 * V_2 = F_115 ( V_260 ) ;
return F_72 ( & V_2 -> V_303 , V_260 ) ;
}
static int F_116 ( struct V_259 * V_260 ,
struct V_78 * V_79 )
{
struct V_307 * V_2 = F_115 ( V_260 ) ;
return F_55 ( & V_2 -> V_303 , V_79 ) ;
}
static struct V_153 *
F_117 ( struct V_259 * V_260 )
{
struct V_307 * V_2 = F_115 ( V_260 ) ;
return & V_2 -> V_48 ;
}
static enum V_243
F_118 ( struct V_259 * V_260 , bool V_308 )
{
struct V_307 * V_2 = F_115 ( V_260 ) ;
return F_68 ( & V_2 -> V_303 ) ;
}
static void F_119 ( struct V_259 * V_260 )
{
F_120 ( V_260 ) ;
F_121 ( V_260 ) ;
}
static int F_122 ( struct V_309 * V_10 , struct V_309 * V_310 , void * V_50 )
{
struct V_72 * V_143 = V_10 -> V_311 ;
struct V_5 * V_6 = F_123 ( V_10 ) ;
struct V_298 * V_312 = V_50 ;
struct V_307 * V_2 ;
T_7 V_313 = 0 ;
int V_9 ;
V_2 = F_124 ( V_10 , sizeof( * V_2 ) , V_301 ) ;
if ( ! V_2 )
return - V_302 ;
F_125 ( V_10 , V_2 ) ;
if ( V_10 -> V_273 )
V_313 = F_126 ( V_312 , V_10 -> V_273 ) ;
if ( V_313 == 0 ) {
F_74 ( V_10 , L_21 ) ;
V_313 = 1 << 0 ;
}
V_2 -> V_303 . V_48 = & V_2 -> V_48 ;
V_2 -> V_260 . V_314 = 1 ;
V_2 -> V_48 . V_315 = V_313 ;
V_9 = F_95 ( V_6 , & V_2 -> V_303 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_10 -> V_273 && V_143 )
F_43 ( & V_2 -> V_303 , V_143 ) ;
F_79 ( & V_2 -> V_303 , & V_2 -> V_260 ) ;
F_127 ( & V_2 -> V_48 , & V_316 ) ;
V_9 = F_128 ( V_312 , & V_2 -> V_48 , & V_317 ,
V_318 ) ;
if ( V_9 )
goto V_319;
F_129 ( & V_2 -> V_260 ,
& V_320 ) ;
V_9 = F_130 ( V_312 , & V_2 -> V_260 ,
& V_321 ,
V_322 ) ;
if ( V_9 )
goto V_323;
V_9 = F_131 ( & V_2 -> V_260 ) ;
if ( V_9 )
goto V_324;
V_2 -> V_260 . V_48 = & V_2 -> V_48 ;
F_132 ( & V_2 -> V_260 , & V_2 -> V_48 ) ;
return 0 ;
V_324:
F_121 ( & V_2 -> V_260 ) ;
V_323:
F_113 ( & V_2 -> V_48 ) ;
V_319:
F_81 ( & V_2 -> V_303 ) ;
return V_9 ;
}
static void F_133 ( struct V_309 * V_10 , struct V_309 * V_310 ,
void * V_50 )
{
struct V_307 * V_2 = F_134 ( V_10 ) ;
F_121 ( & V_2 -> V_260 ) ;
F_113 ( & V_2 -> V_48 ) ;
F_81 ( & V_2 -> V_303 ) ;
}
static int
F_135 ( struct V_5 * V_6 , const struct V_325 * V_326 )
{
return F_136 ( & V_6 -> V_10 , & V_327 ) ;
}
static int F_137 ( struct V_5 * V_6 )
{
F_138 ( & V_6 -> V_10 , & V_327 ) ;
return 0 ;
}
static int T_10
F_139 ( void )
{
F_52 ( L_8 ) ;
return F_140 ( V_328 , & V_329 ) ;
}
static void T_11
F_141 ( void )
{
F_52 ( L_8 ) ;
F_142 ( & V_329 ) ;
}
