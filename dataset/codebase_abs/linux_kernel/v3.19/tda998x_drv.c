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
F_10 ( & V_2 -> V_17 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_18;
V_9 = F_2 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_5 ( V_6 , V_8 , V_16 ) ;
if ( V_9 < 0 )
goto V_11;
goto V_18;
V_11:
F_3 ( & V_6 -> V_10 , L_4 , V_9 , V_12 ) ;
V_18:
F_11 ( & V_2 -> V_17 ) ;
return V_9 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_12 , T_2 * V_19 , int V_16 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [ V_16 + 1 ] ;
int V_9 ;
V_8 [ 0 ] = F_9 ( V_12 ) ;
memcpy ( & V_8 [ 1 ] , V_19 , V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_18;
V_9 = F_2 ( V_6 , V_8 , V_16 + 1 ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
V_18:
F_11 ( & V_2 -> V_17 ) ;
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
F_10 ( & V_2 -> V_17 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_18;
V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
V_18:
F_11 ( & V_2 -> V_17 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_14 ;
T_2 V_8 [] = { F_9 ( V_12 ) , V_4 >> 8 , V_4 } ;
int V_9 ;
F_10 ( & V_2 -> V_17 ) ;
V_9 = F_6 ( V_2 , V_12 ) ;
if ( V_9 < 0 )
goto V_18;
V_9 = F_2 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_3 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
V_18:
F_11 ( & V_2 -> V_17 ) ;
}
static void
F_16 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
int V_20 ;
V_20 = F_13 ( V_2 , V_12 ) ;
if ( V_20 >= 0 )
F_14 ( V_2 , V_12 , V_20 | V_4 ) ;
}
static void
F_17 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
int V_20 ;
V_20 = F_13 ( V_2 , V_12 ) ;
if ( V_20 >= 0 )
F_14 ( V_2 , V_12 , V_20 & ~ V_4 ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_21 , V_22 | V_23 ) ;
F_19 ( 50 ) ;
F_14 ( V_2 , V_21 , 0 ) ;
F_19 ( 50 ) ;
F_16 ( V_2 , V_24 , V_25 ) ;
F_17 ( V_2 , V_24 , V_25 ) ;
F_14 ( V_2 , V_26 , 0x00 ) ;
F_14 ( V_2 , V_27 , F_20 ( 1 ) ) ;
F_14 ( V_2 , V_28 , 0x00 ) ;
F_14 ( V_2 , V_29 , 0x00 ) ;
F_14 ( V_2 , V_30 , 0x00 ) ;
F_14 ( V_2 , V_31 , 0x00 ) ;
F_14 ( V_2 , V_32 , V_33 ) ;
F_14 ( V_2 , V_34 , V_35 | V_36 ) ;
F_14 ( V_2 , V_37 , 0xfa ) ;
F_14 ( V_2 , V_38 , 0x00 ) ;
F_14 ( V_2 , V_39 , 0x5b ) ;
F_14 ( V_2 , V_40 , 0x00 ) ;
F_14 ( V_2 , V_41 , 0x10 ) ;
F_14 ( V_2 , V_42 , 0x24 ) ;
}
static void F_21 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_22 ( V_44 ) ;
struct V_1 * V_2 =
F_23 ( V_46 , struct V_1 , V_46 ) ;
if ( V_2 -> V_47 && V_2 -> V_47 -> V_10 )
F_24 ( V_2 -> V_47 -> V_10 ) ;
}
static T_3 F_25 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
T_4 V_50 , V_7 , V_51 , V_52 , V_53 , V_54 ;
if ( ! V_2 )
return V_55 ;
V_50 = F_4 ( V_2 , V_56 ) ;
V_7 = F_4 ( V_2 , V_57 ) ;
V_51 = F_4 ( V_2 , V_58 ) ;
V_52 = F_13 ( V_2 , V_59 ) ;
V_53 = F_13 ( V_2 , V_60 ) ;
V_54 = F_13 ( V_2 , V_61 ) ;
F_26 (
L_6 ,
V_50 , V_7 , V_51 , V_52 , V_53 , V_54 ) ;
if ( ( V_54 & V_62 ) && V_2 -> V_63 ) {
V_2 -> V_63 = 0 ;
F_27 ( & V_2 -> V_64 ) ;
} else if ( V_7 != 0 ) {
F_28 ( & V_2 -> V_46 , V_65 / 10 ) ;
}
return V_55 ;
}
static T_2 F_29 ( T_2 * V_8 , T_5 V_66 )
{
int V_67 = 0 ;
while ( V_66 -- )
V_67 -= * V_8 ++ ;
return V_67 ;
}
static void
F_30 ( struct V_1 * V_2 , T_2 V_68 , T_1 V_3 ,
T_2 * V_8 , T_5 V_69 )
{
V_8 [ F_31 ( 0 ) ] = F_29 ( V_8 , V_69 ) ;
F_17 ( V_2 , V_70 , V_68 ) ;
F_12 ( V_2 , V_3 , V_8 , V_69 ) ;
F_16 ( V_2 , V_70 , V_68 ) ;
}
static void
F_32 ( struct V_1 * V_2 , struct V_71 * V_19 )
{
T_4 V_8 [ F_31 ( V_72 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_33 ( 0 ) ] = V_73 ;
V_8 [ F_33 ( 1 ) ] = 0x01 ;
V_8 [ F_33 ( 2 ) ] = V_72 ;
V_8 [ F_31 ( 1 ) ] = V_19 -> V_74 [ 1 ] & 0x07 ;
V_8 [ F_31 ( 2 ) ] = V_19 -> V_74 [ 2 ] & 0x1c ;
V_8 [ F_31 ( 4 ) ] = V_19 -> V_74 [ 4 ] ;
V_8 [ F_31 ( 5 ) ] = V_19 -> V_74 [ 5 ] & 0xf8 ;
F_30 ( V_2 , V_75 , V_76 , V_8 ,
sizeof( V_8 ) ) ;
}
static void
F_34 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
T_4 V_8 [ F_31 ( V_79 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_33 ( 0 ) ] = V_80 ;
V_8 [ F_33 ( 1 ) ] = 0x02 ;
V_8 [ F_33 ( 2 ) ] = V_79 ;
V_8 [ F_31 ( 1 ) ] = V_81 ;
V_8 [ F_31 ( 2 ) ] = V_82 ;
V_8 [ F_31 ( 3 ) ] = V_83 << 2 ;
V_8 [ F_31 ( 4 ) ] = F_35 ( V_78 ) ;
F_30 ( V_2 , V_84 , V_85 , V_8 ,
sizeof( V_8 ) ) ;
}
static void F_36 ( struct V_1 * V_2 , bool V_86 )
{
if ( V_86 ) {
F_16 ( V_2 , V_21 , V_22 ) ;
F_17 ( V_2 , V_21 , V_22 ) ;
F_16 ( V_2 , V_87 , V_88 ) ;
} else {
F_17 ( V_2 , V_87 , V_88 ) ;
}
}
static void
F_37 ( struct V_1 * V_2 ,
struct V_77 * V_78 , struct V_71 * V_19 )
{
T_2 V_8 [ 6 ] , V_89 , V_90 , V_91 , V_92 ;
T_6 V_93 ;
F_14 ( V_2 , V_94 , V_19 -> V_95 ) ;
F_14 ( V_2 , V_96 , V_19 -> V_97 ) ;
switch ( V_19 -> V_98 ) {
case V_99 :
F_14 ( V_2 , V_100 , V_101 ) ;
V_89 = V_102 ;
V_90 = V_103 ;
V_91 = F_38 ( 3 ) | F_39 ( 3 ) ;
break;
case V_104 :
F_14 ( V_2 , V_100 , V_105 ) ;
V_89 = V_106 ;
V_90 = V_107 ;
V_91 = F_38 ( 3 ) | F_39 ( 3 ) ;
break;
default:
F_40 () ;
return;
}
F_14 ( V_2 , V_108 , V_89 ) ;
F_17 ( V_2 , V_87 , V_109 |
V_110 ) ;
F_14 ( V_2 , V_111 , V_91 ) ;
V_92 = V_33 ;
if ( V_78 -> clock > 100000 )
V_92 ++ ;
if ( V_19 -> V_98 == V_99 )
V_92 ++ ;
F_14 ( V_2 , V_32 , V_92 ) ;
V_93 = 128 * V_19 -> V_112 / 1000 ;
V_8 [ 0 ] = 0x44 ;
V_8 [ 1 ] = 0x42 ;
V_8 [ 2 ] = 0x01 ;
V_8 [ 3 ] = V_93 ;
V_8 [ 4 ] = V_93 >> 8 ;
V_8 [ 5 ] = V_93 >> 16 ;
F_12 ( V_2 , V_113 , V_8 , 6 ) ;
F_14 ( V_2 , V_108 , V_89 | V_90 ) ;
F_16 ( V_2 , V_87 , V_114 ) ;
F_17 ( V_2 , V_87 , V_114 ) ;
V_8 [ 0 ] = V_115 ;
V_8 [ 1 ] = 0x00 ;
V_8 [ 2 ] = V_116 ;
V_8 [ 3 ] = V_117 |
V_118 ;
F_12 ( V_2 , F_41 ( 0 ) , V_8 , 4 ) ;
F_36 ( V_2 , true ) ;
F_19 ( 20 ) ;
F_36 ( V_2 , false ) ;
F_32 ( V_2 , V_19 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_71 * V_19 )
{
V_2 -> V_119 = F_43 ( V_19 -> V_120 ) |
( V_19 -> V_121 ? V_122 : 0 ) |
F_44 ( V_19 -> V_123 ) |
( V_19 -> V_124 ? V_125 : 0 ) ;
V_2 -> V_126 = F_45 ( V_19 -> V_127 ) |
( V_19 -> V_128 ? V_129 : 0 ) |
F_46 ( V_19 -> V_130 ) |
( V_19 -> V_131 ? V_132 : 0 ) ;
V_2 -> V_133 = F_47 ( V_19 -> V_134 ) |
( V_19 -> V_135 ? V_136 : 0 ) |
F_48 ( V_19 -> V_137 ) |
( V_19 -> V_138 ? V_139 : 0 ) ;
V_2 -> V_140 = * V_19 ;
}
static void F_49 ( struct V_1 * V_2 , int V_78 )
{
if ( V_78 != V_141 )
V_78 = V_142 ;
if ( V_78 == V_2 -> V_143 )
return;
switch ( V_78 ) {
case V_141 :
F_14 ( V_2 , V_144 , 0xff ) ;
F_14 ( V_2 , V_145 , 0xff ) ;
F_14 ( V_2 , V_146 , 0xff ) ;
F_14 ( V_2 , V_147 , V_2 -> V_119 ) ;
F_14 ( V_2 , V_148 , V_2 -> V_126 ) ;
F_14 ( V_2 , V_149 , V_2 -> V_133 ) ;
break;
case V_142 :
F_14 ( V_2 , V_144 , 0x00 ) ;
F_14 ( V_2 , V_145 , 0x00 ) ;
F_14 ( V_2 , V_146 , 0x00 ) ;
break;
}
V_2 -> V_143 = V_78 ;
}
static void
F_50 ( struct V_150 * V_47 )
{
F_51 ( L_7 ) ;
}
static void
F_52 ( struct V_150 * V_47 )
{
F_51 ( L_7 ) ;
}
static bool
F_53 ( struct V_150 * V_47 ,
const struct V_77 * V_78 ,
struct V_77 * V_151 )
{
return true ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
if ( V_78 -> clock > 150000 )
return V_152 ;
if ( V_78 -> V_153 >= F_55 ( 13 ) )
return V_154 ;
if ( V_78 -> V_155 >= F_55 ( 11 ) )
return V_156 ;
return V_157 ;
}
static void
F_56 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_77 * V_151 )
{
T_1 V_158 , V_159 , V_160 , V_161 ;
T_1 V_162 , V_163 ;
T_1 V_164 , V_165 , V_166 , V_167 ;
T_1 V_168 , V_169 , V_170 , V_171 ;
T_1 V_172 , V_173 ;
T_1 V_174 , V_175 ;
T_1 V_176 , V_177 ;
T_2 V_12 , div , V_178 ;
V_160 = V_78 -> V_153 ;
V_161 = V_78 -> V_155 ;
V_163 = V_78 -> V_179 - V_78 -> V_180 ;
V_162 = V_78 -> V_181 - V_78 -> V_180 ;
V_177 = V_78 -> V_153 ;
V_176 = V_78 -> V_153 - V_78 -> V_180 ;
V_158 = 3 + V_162 ;
if ( V_151 -> V_182 & V_183 )
V_158 += V_151 -> V_184 ;
if ( ( V_78 -> V_182 & V_185 ) == 0 ) {
V_159 = 1 + V_78 -> V_186 - V_78 -> V_187 ;
V_172 = V_78 -> V_155 - V_78 -> V_187 - 1 ;
V_173 = V_172 + V_78 -> V_187 ;
V_164 = V_165 = V_162 ;
V_166 = V_78 -> V_186 - V_78 -> V_187 ;
V_167 = V_166 +
V_78 -> V_188 - V_78 -> V_186 ;
V_174 = V_175 = 0 ;
V_168 = V_169 = 0 ;
V_170 = V_171 = 0 ;
} else {
V_159 = 1 + ( V_78 -> V_186 - V_78 -> V_187 ) / 2 ;
V_172 = ( V_78 -> V_155 - V_78 -> V_187 ) / 2 ;
V_173 = V_172 + V_78 -> V_187 / 2 ;
V_164 = V_165 = V_162 ;
V_166 = ( V_78 -> V_186 - V_78 -> V_187 ) / 2 ;
V_167 = V_166 +
( V_78 -> V_188 - V_78 -> V_186 ) / 2 ;
V_174 = V_172 + V_78 -> V_155 / 2 ;
V_175 = V_174 + V_78 -> V_187 / 2 ;
V_168 = V_169 = V_162 + V_78 -> V_153 / 2 ;
V_170 = V_166 + V_78 -> V_155 / 2 ;
V_171 = V_170 +
( V_78 -> V_188 - V_78 -> V_186 ) / 2 ;
}
div = 148500 / V_78 -> clock ;
if ( div != 0 ) {
div -- ;
if ( div > 3 )
div = 3 ;
}
F_16 ( V_2 , V_87 , V_88 ) ;
F_14 ( V_2 , V_189 , V_190 ) ;
F_17 ( V_2 , V_191 , V_192 ) ;
F_14 ( V_2 , V_193 , F_57 ( 0 ) ) ;
F_14 ( V_2 , V_194 , F_58 ( 0 ) |
F_59 ( 0 ) ) ;
F_14 ( V_2 , V_195 , F_60 ( 0 ) ) ;
F_14 ( V_2 , V_196 , F_61 ( 0 ) |
F_62 ( 0 ) ) ;
F_17 ( V_2 , V_26 , V_197 ) ;
F_17 ( V_2 , V_28 , V_198 |
V_199 ) ;
F_14 ( V_2 , V_29 , 0 ) ;
F_14 ( V_2 , V_200 , F_63 ( 0 ) ) ;
V_178 = 0 ;
F_14 ( V_2 , V_201 , 0 ) ;
F_14 ( V_2 , V_34 , F_64 ( 0 ) |
V_35 | V_36 ) ;
F_14 ( V_2 , V_27 , F_20 ( div ) |
F_65 ( V_178 ) ) ;
F_14 ( V_2 , V_202 , V_203 |
F_66 ( 1 ) ) ;
F_14 ( V_2 , V_204 , 0x09 ) ;
V_12 = V_205 ;
if ( V_78 -> V_182 & V_206 )
V_12 |= V_207 ;
if ( V_78 -> V_182 & V_208 )
V_12 |= V_209 ;
F_14 ( V_2 , V_210 , V_12 ) ;
F_14 ( V_2 , V_211 , 0x00 ) ;
F_15 ( V_2 , V_212 , V_158 ) ;
F_15 ( V_2 , V_213 , V_159 ) ;
F_15 ( V_2 , V_214 , V_160 ) ;
F_15 ( V_2 , V_215 , V_161 ) ;
F_15 ( V_2 , V_216 , V_166 ) ;
F_15 ( V_2 , V_217 , V_164 ) ;
F_15 ( V_2 , V_218 , V_167 ) ;
F_15 ( V_2 , V_219 , V_165 ) ;
F_15 ( V_2 , V_220 , V_170 ) ;
F_15 ( V_2 , V_221 , V_168 ) ;
F_15 ( V_2 , V_222 , V_171 ) ;
F_15 ( V_2 , V_223 , V_169 ) ;
F_15 ( V_2 , V_224 , V_162 ) ;
F_15 ( V_2 , V_225 , V_163 ) ;
F_15 ( V_2 , V_226 , V_172 ) ;
F_15 ( V_2 , V_227 , V_173 ) ;
F_15 ( V_2 , V_228 , V_174 ) ;
F_15 ( V_2 , V_229 , V_175 ) ;
F_15 ( V_2 , V_230 , V_176 ) ;
F_15 ( V_2 , V_231 , V_177 ) ;
if ( V_2 -> V_232 == V_233 ) {
F_14 ( V_2 , V_234 , 0x00 ) ;
}
V_12 = V_190 | V_235 ;
if ( V_78 -> V_182 & V_206 )
V_12 |= V_236 ;
if ( V_78 -> V_182 & V_208 )
V_12 |= V_237 ;
F_14 ( V_2 , V_189 , V_12 ) ;
F_14 ( V_2 , V_238 , 0 ) ;
if ( V_2 -> V_239 ) {
V_12 &= ~ V_190 ;
F_14 ( V_2 , V_189 , V_12 ) ;
F_14 ( V_2 , V_193 , F_57 ( 1 ) ) ;
F_16 ( V_2 , V_191 , V_192 ) ;
F_34 ( V_2 , V_151 ) ;
if ( V_2 -> V_140 . V_95 )
F_37 ( V_2 , V_151 ,
& V_2 -> V_140 ) ;
}
}
static enum V_240
F_67 ( struct V_1 * V_2 )
{
T_2 V_4 = F_4 ( V_2 , V_58 ) ;
return ( V_4 & V_241 ) ? V_242 :
V_243 ;
}
static int F_68 ( struct V_1 * V_2 , T_2 * V_8 , int V_244 )
{
T_2 V_245 , V_246 ;
int V_9 , V_247 ;
V_245 = ( V_244 & 1 ) ? 128 : 0 ;
V_246 = V_244 / 2 ;
F_14 ( V_2 , V_248 , 0xa0 ) ;
F_14 ( V_2 , V_249 , V_245 ) ;
F_14 ( V_2 , V_250 , 0x60 ) ;
F_14 ( V_2 , V_251 , V_246 ) ;
V_2 -> V_63 = 1 ;
F_14 ( V_2 , V_252 , 0x1 ) ;
F_14 ( V_2 , V_252 , 0x0 ) ;
if ( V_2 -> V_14 -> V_48 ) {
V_247 = F_69 ( V_2 -> V_64 ,
! V_2 -> V_63 ,
F_70 ( 100 ) ) ;
if ( V_247 < 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_8 , V_247 ) ;
return V_247 ;
}
} else {
for ( V_247 = 100 ; V_247 > 0 ; V_247 -- ) {
F_19 ( 1 ) ;
V_9 = F_13 ( V_2 , V_61 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & V_62 )
break;
}
}
if ( V_247 == 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_9 ) ;
return - V_253 ;
}
V_9 = F_8 ( V_2 , V_254 , V_8 , V_255 ) ;
if ( V_9 != V_255 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_10 ,
V_244 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static T_2 * F_71 ( struct V_1 * V_2 )
{
int V_256 , V_257 = 0 ;
T_2 * V_258 , * V_259 ;
bool V_260 = V_261 & V_262 ;
if ( ( V_258 = F_72 ( V_255 , V_263 ) ) == NULL )
return NULL ;
if ( V_2 -> V_232 == V_233 )
F_17 ( V_2 , V_264 , V_265 ) ;
if ( F_68 ( V_2 , V_258 , 0 ) )
goto V_11;
if ( ! F_73 ( V_258 , 0 , V_260 ) )
goto V_11;
if ( V_258 [ 0x7e ] == 0 )
goto V_266;
V_259 = F_74 ( V_258 , ( V_258 [ 0x7e ] + 1 ) * V_255 , V_263 ) ;
if ( ! V_259 )
goto V_11;
V_258 = V_259 ;
for ( V_256 = 1 ; V_256 <= V_258 [ 0x7e ] ; V_256 ++ ) {
T_2 * V_267 = V_258 + ( V_257 + 1 ) * V_255 ;
if ( F_68 ( V_2 , V_267 , V_256 ) )
goto V_11;
if ( ! F_73 ( V_267 , V_256 , V_260 ) )
goto V_11;
V_257 ++ ;
}
if ( V_257 != V_258 [ 0x7e ] ) {
V_258 [ V_255 - 1 ] += V_258 [ 0x7e ] - V_257 ;
V_258 [ 0x7e ] = V_257 ;
V_259 = F_74 ( V_258 , ( V_257 + 1 ) * V_255 , V_263 ) ;
if ( ! V_259 )
goto V_11;
V_258 = V_259 ;
}
V_266:
if ( V_2 -> V_232 == V_233 )
F_16 ( V_2 , V_264 , V_265 ) ;
return V_258 ;
V_11:
if ( V_2 -> V_232 == V_233 )
F_16 ( V_2 , V_264 , V_265 ) ;
F_75 ( & V_2 -> V_14 -> V_10 , L_11 ) ;
F_76 ( V_258 ) ;
return NULL ;
}
static int
F_77 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
struct V_270 * V_270 = (struct V_270 * ) F_71 ( V_2 ) ;
int V_93 = 0 ;
if ( V_270 ) {
F_78 ( V_269 , V_270 ) ;
V_93 = F_79 ( V_269 , V_270 ) ;
V_2 -> V_239 = F_80 ( V_270 ) ;
F_76 ( V_270 ) ;
}
return V_93 ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
if ( V_2 -> V_14 -> V_48 )
V_269 -> V_271 = V_272 ;
else
V_269 -> V_271 = V_273 |
V_274 ;
}
static int
F_82 ( struct V_150 * V_47 ,
struct V_268 * V_269 ,
struct V_275 * V_276 ,
T_7 V_4 )
{
F_51 ( L_7 ) ;
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_277 , 0 ) ;
F_17 ( V_2 , V_61 , V_62 ) ;
if ( V_2 -> V_14 -> V_48 ) {
F_84 ( V_2 -> V_14 -> V_48 , V_2 ) ;
F_85 ( & V_2 -> V_46 ) ;
}
F_86 ( V_2 -> V_7 ) ;
}
static void
F_87 ( struct V_150 * V_47 , void * V_140 )
{
F_42 ( F_88 ( V_47 ) , V_140 ) ;
}
static void F_89 ( struct V_150 * V_47 )
{
struct V_1 * V_2 = F_88 ( V_47 ) ;
F_83 ( V_2 ) ;
F_90 ( V_47 ) ;
F_76 ( V_2 ) ;
}
static void F_91 ( struct V_150 * V_47 , int V_78 )
{
F_49 ( F_88 ( V_47 ) , V_78 ) ;
}
static int F_92 ( struct V_150 * V_47 ,
struct V_77 * V_78 )
{
return F_54 ( F_88 ( V_47 ) , V_78 ) ;
}
static void
F_93 ( struct V_150 * V_47 ,
struct V_77 * V_78 ,
struct V_77 * V_151 )
{
F_56 ( F_88 ( V_47 ) , V_78 , V_151 ) ;
}
static enum V_240
F_94 ( struct V_150 * V_47 ,
struct V_268 * V_269 )
{
return F_67 ( F_88 ( V_47 ) ) ;
}
static int F_95 ( struct V_150 * V_47 ,
struct V_268 * V_269 )
{
return F_77 ( F_88 ( V_47 ) , V_269 ) ;
}
static int
F_96 ( struct V_150 * V_47 ,
struct V_268 * V_269 )
{
F_81 ( F_88 ( V_47 ) , V_269 ) ;
return 0 ;
}
static int F_97 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_278 * V_279 = V_6 -> V_10 . V_280 ;
T_8 V_281 ;
int V_282 , V_283 , V_9 ;
unsigned short V_284 ;
V_2 -> V_119 = F_43 ( 2 ) | F_44 ( 3 ) ;
V_2 -> V_126 = F_45 ( 0 ) | F_46 ( 1 ) ;
V_2 -> V_133 = F_47 ( 4 ) | F_48 ( 5 ) ;
V_2 -> V_13 = 0xff ;
V_2 -> V_14 = V_6 ;
V_284 = 0x34 + ( V_6 -> V_3 & 0x03 ) ;
V_2 -> V_7 = F_98 ( V_6 -> V_285 , V_284 ) ;
if ( ! V_2 -> V_7 )
return - V_286 ;
V_2 -> V_143 = V_142 ;
F_99 ( & V_2 -> V_17 ) ;
F_1 ( V_2 , V_287 ,
V_288 | V_289 ) ;
F_18 ( V_2 ) ;
V_282 = F_13 ( V_2 , V_290 ) ;
V_283 = F_13 ( V_2 , V_291 ) ;
if ( V_282 < 0 || V_283 < 0 ) {
V_9 = V_282 < 0 ? V_282 : V_283 ;
goto V_11;
}
V_2 -> V_232 = V_282 | V_283 << 8 ;
V_2 -> V_232 &= ~ 0x30 ;
switch ( V_2 -> V_232 ) {
case V_292 :
F_100 ( & V_6 -> V_10 , L_12 ) ;
break;
case V_293 :
F_100 ( & V_6 -> V_10 , L_13 ) ;
break;
case V_294 :
F_100 ( & V_6 -> V_10 , L_14 ) ;
break;
case V_233 :
F_100 ( & V_6 -> V_10 , L_15 ) ;
break;
default:
F_3 ( & V_6 -> V_10 , L_16 ,
V_2 -> V_232 ) ;
goto V_11;
}
F_14 ( V_2 , V_295 , 0x00 ) ;
F_14 ( V_2 , V_296 , 39 ) ;
if ( V_2 -> V_232 == V_293 )
F_16 ( V_2 , V_297 , V_298 ) ;
F_1 ( V_2 , V_299 ,
V_300 | V_301 ) ;
if ( V_6 -> V_48 ) {
int V_302 ;
F_101 ( & V_2 -> V_64 ) ;
F_102 ( & V_2 -> V_46 , F_21 ) ;
F_13 ( V_2 , V_59 ) ;
F_13 ( V_2 , V_60 ) ;
F_13 ( V_2 , V_61 ) ;
V_302 =
F_103 ( F_104 ( V_6 -> V_48 ) ) ;
V_9 = F_105 ( V_6 -> V_48 , NULL ,
F_25 ,
V_302 | V_303 ,
L_17 , V_2 ) ;
if ( V_9 ) {
F_3 ( & V_6 -> V_10 ,
L_18 ,
V_6 -> V_48 , V_9 ) ;
goto V_11;
}
F_1 ( V_2 , V_277 , V_241 ) ;
}
F_16 ( V_2 , V_61 , V_62 ) ;
if ( ! V_279 )
return 0 ;
V_9 = F_106 ( V_279 , L_19 , & V_281 ) ;
if ( V_9 == 0 ) {
V_2 -> V_119 = V_281 >> 16 ;
V_2 -> V_126 = V_281 >> 8 ;
V_2 -> V_133 = V_281 ;
}
return 0 ;
V_11:
if ( V_2 -> V_7 )
F_86 ( V_2 -> V_7 ) ;
return - V_304 ;
}
static int F_107 ( struct V_5 * V_6 ,
struct V_305 * V_10 ,
struct V_306 * V_307 )
{
struct V_1 * V_2 ;
int V_9 ;
V_2 = F_108 ( sizeof( * V_2 ) , V_263 ) ;
if ( ! V_2 )
return - V_308 ;
V_2 -> V_47 = & V_307 -> V_309 ;
V_9 = F_97 ( V_6 , V_2 ) ;
if ( V_9 ) {
F_76 ( V_2 ) ;
return V_9 ;
}
V_307 -> V_310 = V_2 ;
V_307 -> V_311 = & V_312 ;
return 0 ;
}
static void F_109 ( struct V_150 * V_47 , int V_78 )
{
struct V_313 * V_2 = F_110 ( V_47 ) ;
F_49 ( & V_2 -> V_309 , V_78 ) ;
}
static void F_111 ( struct V_150 * V_47 )
{
F_109 ( V_47 , V_142 ) ;
}
static void F_112 ( struct V_150 * V_47 )
{
F_109 ( V_47 , V_141 ) ;
}
static void F_113 ( struct V_150 * V_47 ,
struct V_77 * V_78 ,
struct V_77 * V_151 )
{
struct V_313 * V_2 = F_110 ( V_47 ) ;
F_56 ( & V_2 -> V_309 , V_78 , V_151 ) ;
}
static void F_114 ( struct V_150 * V_47 )
{
struct V_313 * V_2 = F_110 ( V_47 ) ;
F_83 ( & V_2 -> V_309 ) ;
F_115 ( V_47 ) ;
}
static int F_116 ( struct V_268 * V_269 )
{
struct V_313 * V_2 = F_117 ( V_269 ) ;
return F_77 ( & V_2 -> V_309 , V_269 ) ;
}
static int F_118 ( struct V_268 * V_269 ,
struct V_77 * V_78 )
{
struct V_313 * V_2 = F_117 ( V_269 ) ;
return F_54 ( & V_2 -> V_309 , V_78 ) ;
}
static struct V_150 *
F_119 ( struct V_268 * V_269 )
{
struct V_313 * V_2 = F_117 ( V_269 ) ;
return & V_2 -> V_47 ;
}
static enum V_240
F_120 ( struct V_268 * V_269 , bool V_314 )
{
struct V_313 * V_2 = F_117 ( V_269 ) ;
return F_67 ( & V_2 -> V_309 ) ;
}
static void F_121 ( struct V_268 * V_269 )
{
F_122 ( V_269 ) ;
F_123 ( V_269 ) ;
}
static int F_124 ( struct V_315 * V_10 , struct V_315 * V_316 , void * V_49 )
{
struct V_71 * V_140 = V_10 -> V_317 ;
struct V_5 * V_6 = F_125 ( V_10 ) ;
struct V_305 * V_318 = V_49 ;
struct V_313 * V_2 ;
int V_9 ;
V_2 = F_126 ( V_10 , sizeof( * V_2 ) , V_263 ) ;
if ( ! V_2 )
return - V_308 ;
F_127 ( V_10 , V_2 ) ;
V_2 -> V_309 . V_47 = & V_2 -> V_47 ;
V_2 -> V_269 . V_319 = 1 ;
V_2 -> V_47 . V_320 = 1 << 0 ;
V_9 = F_97 ( V_6 , & V_2 -> V_309 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_10 -> V_280 && V_140 )
F_42 ( & V_2 -> V_309 , V_140 ) ;
F_81 ( & V_2 -> V_309 , & V_2 -> V_269 ) ;
F_128 ( & V_2 -> V_47 , & V_321 ) ;
V_9 = F_129 ( V_318 , & V_2 -> V_47 , & V_322 ,
V_323 ) ;
if ( V_9 )
goto V_324;
F_130 ( & V_2 -> V_269 ,
& V_325 ) ;
V_9 = F_131 ( V_318 , & V_2 -> V_269 ,
& V_326 ,
V_327 ) ;
if ( V_9 )
goto V_328;
V_9 = F_132 ( & V_2 -> V_269 ) ;
if ( V_9 )
goto V_329;
V_2 -> V_269 . V_47 = & V_2 -> V_47 ;
F_133 ( & V_2 -> V_269 , & V_2 -> V_47 ) ;
return 0 ;
V_329:
F_123 ( & V_2 -> V_269 ) ;
V_328:
F_115 ( & V_2 -> V_47 ) ;
V_324:
F_83 ( & V_2 -> V_309 ) ;
return V_9 ;
}
static void F_134 ( struct V_315 * V_10 , struct V_315 * V_316 ,
void * V_49 )
{
struct V_313 * V_2 = F_135 ( V_10 ) ;
F_123 ( & V_2 -> V_269 ) ;
F_115 ( & V_2 -> V_47 ) ;
F_83 ( & V_2 -> V_309 ) ;
}
static int
F_136 ( struct V_5 * V_6 , const struct V_330 * V_331 )
{
return F_137 ( & V_6 -> V_10 , & V_332 ) ;
}
static int F_138 ( struct V_5 * V_6 )
{
F_139 ( & V_6 -> V_10 , & V_332 ) ;
return 0 ;
}
static int T_9
F_140 ( void )
{
F_51 ( L_7 ) ;
return F_141 ( V_333 , & V_334 ) ;
}
static void T_10
F_142 ( void )
{
F_51 ( L_7 ) ;
F_143 ( & V_334 ) ;
}
