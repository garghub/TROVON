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
V_8 [ F_31 ( 0 ) ] = F_29 ( V_8 , V_70 ) ;
F_17 ( V_2 , V_71 , V_69 ) ;
F_12 ( V_2 , V_3 , V_8 , V_70 ) ;
F_16 ( V_2 , V_71 , V_69 ) ;
}
static void
F_32 ( struct V_1 * V_2 , struct V_72 * V_20 )
{
T_4 V_8 [ F_31 ( V_73 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_33 ( 0 ) ] = V_74 ;
V_8 [ F_33 ( 1 ) ] = 0x01 ;
V_8 [ F_33 ( 2 ) ] = V_73 ;
V_8 [ F_31 ( 1 ) ] = V_20 -> V_75 [ 1 ] & 0x07 ;
V_8 [ F_31 ( 2 ) ] = V_20 -> V_75 [ 2 ] & 0x1c ;
V_8 [ F_31 ( 4 ) ] = V_20 -> V_75 [ 4 ] ;
V_8 [ F_31 ( 5 ) ] = V_20 -> V_75 [ 5 ] & 0xf8 ;
F_30 ( V_2 , V_76 , V_77 , V_8 ,
sizeof( V_8 ) ) ;
}
static void
F_34 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
T_4 V_8 [ F_31 ( V_80 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_33 ( 0 ) ] = V_81 ;
V_8 [ F_33 ( 1 ) ] = 0x02 ;
V_8 [ F_33 ( 2 ) ] = V_80 ;
V_8 [ F_31 ( 1 ) ] = V_82 ;
V_8 [ F_31 ( 2 ) ] = V_83 ;
V_8 [ F_31 ( 3 ) ] = V_84 << 2 ;
V_8 [ F_31 ( 4 ) ] = F_35 ( V_79 ) ;
F_30 ( V_2 , V_85 , V_86 , V_8 ,
sizeof( V_8 ) ) ;
}
static void F_36 ( struct V_1 * V_2 , bool V_87 )
{
if ( V_87 ) {
F_16 ( V_2 , V_22 , V_23 ) ;
F_17 ( V_2 , V_22 , V_23 ) ;
F_16 ( V_2 , V_88 , V_89 ) ;
} else {
F_17 ( V_2 , V_88 , V_89 ) ;
}
}
static void
F_37 ( struct V_1 * V_2 ,
struct V_78 * V_79 , struct V_72 * V_20 )
{
T_2 V_8 [ 6 ] , V_90 , V_91 , V_92 , V_93 ;
T_6 V_94 ;
F_14 ( V_2 , V_95 , V_20 -> V_96 ) ;
F_14 ( V_2 , V_97 , V_20 -> V_98 ) ;
switch ( V_20 -> V_99 ) {
case V_100 :
F_14 ( V_2 , V_101 , V_102 ) ;
V_90 = V_103 ;
V_91 = V_104 ;
V_92 = F_38 ( 3 ) | F_39 ( 3 ) ;
break;
case V_105 :
F_14 ( V_2 , V_101 , V_106 ) ;
V_90 = V_107 ;
V_91 = V_108 ;
V_92 = F_38 ( 3 ) | F_39 ( 3 ) ;
break;
default:
F_40 () ;
return;
}
F_14 ( V_2 , V_109 , V_90 ) ;
F_17 ( V_2 , V_88 , V_110 |
V_111 ) ;
F_14 ( V_2 , V_112 , V_92 ) ;
V_93 = V_34 ;
if ( V_79 -> clock > 100000 )
V_93 ++ ;
if ( V_20 -> V_99 == V_100 )
V_93 ++ ;
F_14 ( V_2 , V_33 , V_93 ) ;
V_94 = 128 * V_20 -> V_113 / 1000 ;
V_8 [ 0 ] = 0x44 ;
V_8 [ 1 ] = 0x42 ;
V_8 [ 2 ] = 0x01 ;
V_8 [ 3 ] = V_94 ;
V_8 [ 4 ] = V_94 >> 8 ;
V_8 [ 5 ] = V_94 >> 16 ;
F_12 ( V_2 , V_114 , V_8 , 6 ) ;
F_14 ( V_2 , V_109 , V_90 | V_91 ) ;
F_16 ( V_2 , V_88 , V_115 ) ;
F_17 ( V_2 , V_88 , V_115 ) ;
V_8 [ 0 ] = V_116 ;
V_8 [ 1 ] = 0x00 ;
V_8 [ 2 ] = V_117 ;
V_8 [ 3 ] = V_118 |
V_119 ;
F_12 ( V_2 , F_41 ( 0 ) , V_8 , 4 ) ;
F_36 ( V_2 , true ) ;
F_19 ( 20 ) ;
F_36 ( V_2 , false ) ;
F_32 ( V_2 , V_20 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_72 * V_20 )
{
V_2 -> V_120 = F_43 ( V_20 -> V_121 ) |
( V_20 -> V_122 ? V_123 : 0 ) |
F_44 ( V_20 -> V_124 ) |
( V_20 -> V_125 ? V_126 : 0 ) ;
V_2 -> V_127 = F_45 ( V_20 -> V_128 ) |
( V_20 -> V_129 ? V_130 : 0 ) |
F_46 ( V_20 -> V_131 ) |
( V_20 -> V_132 ? V_133 : 0 ) ;
V_2 -> V_134 = F_47 ( V_20 -> V_135 ) |
( V_20 -> V_136 ? V_137 : 0 ) |
F_48 ( V_20 -> V_138 ) |
( V_20 -> V_139 ? V_140 : 0 ) ;
V_2 -> V_141 = * V_20 ;
}
static void F_49 ( struct V_1 * V_2 , int V_79 )
{
if ( V_79 != V_142 )
V_79 = V_143 ;
if ( V_79 == V_2 -> V_144 )
return;
switch ( V_79 ) {
case V_142 :
F_14 ( V_2 , V_145 , 0xff ) ;
F_14 ( V_2 , V_146 , 0xff ) ;
F_14 ( V_2 , V_147 , 0xff ) ;
F_14 ( V_2 , V_148 , V_2 -> V_120 ) ;
F_14 ( V_2 , V_149 , V_2 -> V_127 ) ;
F_14 ( V_2 , V_150 , V_2 -> V_134 ) ;
break;
case V_143 :
F_14 ( V_2 , V_145 , 0x00 ) ;
F_14 ( V_2 , V_146 , 0x00 ) ;
F_14 ( V_2 , V_147 , 0x00 ) ;
break;
}
V_2 -> V_144 = V_79 ;
}
static void
F_50 ( struct V_151 * V_48 )
{
F_51 ( L_7 ) ;
}
static void
F_52 ( struct V_151 * V_48 )
{
F_51 ( L_7 ) ;
}
static bool
F_53 ( struct V_151 * V_48 ,
const struct V_78 * V_79 ,
struct V_78 * V_152 )
{
return true ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
if ( V_79 -> clock > 150000 )
return V_153 ;
if ( V_79 -> V_154 >= F_55 ( 13 ) )
return V_155 ;
if ( V_79 -> V_156 >= F_55 ( 11 ) )
return V_157 ;
return V_158 ;
}
static void
F_56 ( struct V_1 * V_2 ,
struct V_78 * V_79 ,
struct V_78 * V_152 )
{
T_1 V_159 , V_160 , V_161 , V_162 ;
T_1 V_163 , V_164 ;
T_1 V_165 , V_166 , V_167 , V_168 ;
T_1 V_169 , V_170 , V_171 , V_172 ;
T_1 V_173 , V_174 ;
T_1 V_175 , V_176 ;
T_1 V_177 , V_178 ;
T_2 V_12 , div , V_179 ;
V_161 = V_79 -> V_154 ;
V_162 = V_79 -> V_156 ;
V_164 = V_79 -> V_180 - V_79 -> V_181 ;
V_163 = V_79 -> V_182 - V_79 -> V_181 ;
V_178 = V_79 -> V_154 ;
V_177 = V_79 -> V_154 - V_79 -> V_181 ;
V_159 = 3 + V_163 ;
if ( V_152 -> V_183 & V_184 )
V_159 += V_152 -> V_185 ;
if ( ( V_79 -> V_183 & V_186 ) == 0 ) {
V_160 = 1 + V_79 -> V_187 - V_79 -> V_188 ;
V_173 = V_79 -> V_156 - V_79 -> V_188 - 1 ;
V_174 = V_173 + V_79 -> V_188 ;
V_165 = V_166 = V_163 ;
V_167 = V_79 -> V_187 - V_79 -> V_188 ;
V_168 = V_167 +
V_79 -> V_189 - V_79 -> V_187 ;
V_175 = V_176 = 0 ;
V_169 = V_170 = 0 ;
V_171 = V_172 = 0 ;
} else {
V_160 = 1 + ( V_79 -> V_187 - V_79 -> V_188 ) / 2 ;
V_173 = ( V_79 -> V_156 - V_79 -> V_188 ) / 2 ;
V_174 = V_173 + V_79 -> V_188 / 2 ;
V_165 = V_166 = V_163 ;
V_167 = ( V_79 -> V_187 - V_79 -> V_188 ) / 2 ;
V_168 = V_167 +
( V_79 -> V_189 - V_79 -> V_187 ) / 2 ;
V_175 = V_173 + V_79 -> V_156 / 2 ;
V_176 = V_175 + V_79 -> V_188 / 2 ;
V_169 = V_170 = V_163 + V_79 -> V_154 / 2 ;
V_171 = V_167 + V_79 -> V_156 / 2 ;
V_172 = V_171 +
( V_79 -> V_189 - V_79 -> V_187 ) / 2 ;
}
div = 148500 / V_79 -> clock ;
if ( div != 0 ) {
div -- ;
if ( div > 3 )
div = 3 ;
}
F_16 ( V_2 , V_88 , V_89 ) ;
F_14 ( V_2 , V_190 , V_191 ) ;
F_17 ( V_2 , V_192 , V_193 ) ;
F_14 ( V_2 , V_194 , F_57 ( 0 ) ) ;
F_14 ( V_2 , V_195 , F_58 ( 0 ) |
F_59 ( 0 ) ) ;
F_14 ( V_2 , V_196 , F_60 ( 0 ) ) ;
F_14 ( V_2 , V_197 , F_61 ( 0 ) |
F_62 ( 0 ) ) ;
F_17 ( V_2 , V_27 , V_198 ) ;
F_17 ( V_2 , V_29 , V_199 |
V_200 ) ;
F_14 ( V_2 , V_30 , 0 ) ;
F_14 ( V_2 , V_201 , F_63 ( 0 ) ) ;
V_179 = 0 ;
F_14 ( V_2 , V_202 , 0 ) ;
F_14 ( V_2 , V_35 , F_64 ( 0 ) |
V_36 | V_37 ) ;
F_14 ( V_2 , V_28 , F_20 ( div ) |
F_65 ( V_179 ) ) ;
F_14 ( V_2 , V_203 , V_204 |
F_66 ( 1 ) ) ;
F_14 ( V_2 , V_205 , 0x09 ) ;
V_12 = V_206 ;
if ( V_79 -> V_183 & V_207 )
V_12 |= V_208 ;
if ( V_79 -> V_183 & V_209 )
V_12 |= V_210 ;
F_14 ( V_2 , V_211 , V_12 ) ;
F_14 ( V_2 , V_212 , 0x00 ) ;
F_15 ( V_2 , V_213 , V_159 ) ;
F_15 ( V_2 , V_214 , V_160 ) ;
F_15 ( V_2 , V_215 , V_161 ) ;
F_15 ( V_2 , V_216 , V_162 ) ;
F_15 ( V_2 , V_217 , V_167 ) ;
F_15 ( V_2 , V_218 , V_165 ) ;
F_15 ( V_2 , V_219 , V_168 ) ;
F_15 ( V_2 , V_220 , V_166 ) ;
F_15 ( V_2 , V_221 , V_171 ) ;
F_15 ( V_2 , V_222 , V_169 ) ;
F_15 ( V_2 , V_223 , V_172 ) ;
F_15 ( V_2 , V_224 , V_170 ) ;
F_15 ( V_2 , V_225 , V_163 ) ;
F_15 ( V_2 , V_226 , V_164 ) ;
F_15 ( V_2 , V_227 , V_173 ) ;
F_15 ( V_2 , V_228 , V_174 ) ;
F_15 ( V_2 , V_229 , V_175 ) ;
F_15 ( V_2 , V_230 , V_176 ) ;
F_15 ( V_2 , V_231 , V_177 ) ;
F_15 ( V_2 , V_232 , V_178 ) ;
if ( V_2 -> V_233 == V_234 ) {
F_14 ( V_2 , V_235 , 0x00 ) ;
}
V_12 = V_191 | V_236 ;
if ( V_79 -> V_183 & V_207 )
V_12 |= V_237 ;
if ( V_79 -> V_183 & V_209 )
V_12 |= V_238 ;
F_14 ( V_2 , V_190 , V_12 ) ;
F_14 ( V_2 , V_239 , 0 ) ;
if ( V_2 -> V_240 ) {
V_12 &= ~ V_191 ;
F_14 ( V_2 , V_190 , V_12 ) ;
F_14 ( V_2 , V_194 , F_57 ( 1 ) ) ;
F_16 ( V_2 , V_192 , V_193 ) ;
F_34 ( V_2 , V_152 ) ;
if ( V_2 -> V_141 . V_96 )
F_37 ( V_2 , V_152 ,
& V_2 -> V_141 ) ;
}
}
static enum V_241
F_67 ( struct V_1 * V_2 )
{
T_2 V_4 = F_4 ( V_2 , V_59 ) ;
return ( V_4 & V_242 ) ? V_243 :
V_244 ;
}
static int F_68 ( void * V_50 , T_4 * V_8 , unsigned int V_245 , T_5 V_246 )
{
struct V_1 * V_2 = V_50 ;
T_2 V_247 , V_248 ;
int V_9 , V_249 ;
V_247 = ( V_245 & 1 ) ? 128 : 0 ;
V_248 = V_245 / 2 ;
F_14 ( V_2 , V_250 , 0xa0 ) ;
F_14 ( V_2 , V_251 , V_247 ) ;
F_14 ( V_2 , V_252 , 0x60 ) ;
F_14 ( V_2 , V_253 , V_248 ) ;
V_2 -> V_64 = 1 ;
F_14 ( V_2 , V_254 , 0x1 ) ;
F_14 ( V_2 , V_254 , 0x0 ) ;
if ( V_2 -> V_14 -> V_49 ) {
V_249 = F_69 ( V_2 -> V_65 ,
! V_2 -> V_64 ,
F_70 ( 100 ) ) ;
if ( V_249 < 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_8 , V_249 ) ;
return V_249 ;
}
} else {
for ( V_249 = 100 ; V_249 > 0 ; V_249 -- ) {
F_19 ( 1 ) ;
V_9 = F_13 ( V_2 , V_62 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & V_63 )
break;
}
}
if ( V_249 == 0 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_9 ) ;
return - V_255 ;
}
V_9 = F_8 ( V_2 , V_256 , V_8 , V_246 ) ;
if ( V_9 != V_246 ) {
F_3 ( & V_2 -> V_14 -> V_10 , L_10 ,
V_245 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int
F_71 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
struct V_259 * V_259 ;
int V_94 ;
if ( V_2 -> V_233 == V_234 )
F_17 ( V_2 , V_260 , V_261 ) ;
V_259 = F_72 ( V_258 , F_68 , V_2 ) ;
if ( V_2 -> V_233 == V_234 )
F_16 ( V_2 , V_260 , V_261 ) ;
if ( ! V_259 ) {
F_73 ( & V_2 -> V_14 -> V_10 , L_11 ) ;
return 0 ;
}
F_74 ( V_258 , V_259 ) ;
V_94 = F_75 ( V_258 , V_259 ) ;
V_2 -> V_240 = F_76 ( V_259 ) ;
F_77 ( V_259 ) ;
return V_94 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_257 * V_258 )
{
if ( V_2 -> V_14 -> V_49 )
V_258 -> V_262 = V_263 ;
else
V_258 -> V_262 = V_264 |
V_265 ;
}
static int
F_79 ( struct V_151 * V_48 ,
struct V_257 * V_258 ,
struct V_266 * V_267 ,
T_7 V_4 )
{
F_51 ( L_7 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_268 , 0 ) ;
F_17 ( V_2 , V_62 , V_63 ) ;
if ( V_2 -> V_14 -> V_49 ) {
F_81 ( V_2 -> V_14 -> V_49 , V_2 ) ;
F_82 ( & V_2 -> V_47 ) ;
}
F_83 ( V_2 -> V_7 ) ;
}
static void
F_84 ( struct V_151 * V_48 , void * V_141 )
{
F_42 ( F_85 ( V_48 ) , V_141 ) ;
}
static void F_86 ( struct V_151 * V_48 )
{
struct V_1 * V_2 = F_85 ( V_48 ) ;
F_80 ( V_2 ) ;
F_87 ( V_48 ) ;
F_77 ( V_2 ) ;
}
static void F_88 ( struct V_151 * V_48 , int V_79 )
{
F_49 ( F_85 ( V_48 ) , V_79 ) ;
}
static int F_89 ( struct V_151 * V_48 ,
struct V_78 * V_79 )
{
return F_54 ( F_85 ( V_48 ) , V_79 ) ;
}
static void
F_90 ( struct V_151 * V_48 ,
struct V_78 * V_79 ,
struct V_78 * V_152 )
{
F_56 ( F_85 ( V_48 ) , V_79 , V_152 ) ;
}
static enum V_241
F_91 ( struct V_151 * V_48 ,
struct V_257 * V_258 )
{
return F_67 ( F_85 ( V_48 ) ) ;
}
static int F_92 ( struct V_151 * V_48 ,
struct V_257 * V_258 )
{
return F_71 ( F_85 ( V_48 ) , V_258 ) ;
}
static int
F_93 ( struct V_151 * V_48 ,
struct V_257 * V_258 )
{
F_78 ( F_85 ( V_48 ) , V_258 ) ;
return 0 ;
}
static int F_94 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_269 * V_270 = V_6 -> V_10 . V_271 ;
T_8 V_272 ;
int V_273 , V_274 , V_9 ;
unsigned short V_275 ;
V_2 -> V_120 = F_43 ( 2 ) | F_44 ( 3 ) ;
V_2 -> V_127 = F_45 ( 0 ) | F_46 ( 1 ) ;
V_2 -> V_134 = F_47 ( 4 ) | F_48 ( 5 ) ;
V_2 -> V_13 = 0xff ;
V_2 -> V_14 = V_6 ;
V_275 = 0x34 + ( V_6 -> V_3 & 0x03 ) ;
V_2 -> V_7 = F_95 ( V_6 -> V_276 , V_275 ) ;
if ( ! V_2 -> V_7 )
return - V_277 ;
V_2 -> V_144 = V_143 ;
F_96 ( & V_2 -> V_18 ) ;
F_1 ( V_2 , V_278 ,
V_279 | V_280 ) ;
F_18 ( V_2 ) ;
V_273 = F_13 ( V_2 , V_281 ) ;
V_274 = F_13 ( V_2 , V_282 ) ;
if ( V_273 < 0 || V_274 < 0 ) {
V_9 = V_273 < 0 ? V_273 : V_274 ;
goto V_11;
}
V_2 -> V_233 = V_273 | V_274 << 8 ;
V_2 -> V_233 &= ~ 0x30 ;
switch ( V_2 -> V_233 ) {
case V_283 :
F_97 ( & V_6 -> V_10 , L_12 ) ;
break;
case V_284 :
F_97 ( & V_6 -> V_10 , L_13 ) ;
break;
case V_285 :
F_97 ( & V_6 -> V_10 , L_14 ) ;
break;
case V_234 :
F_97 ( & V_6 -> V_10 , L_15 ) ;
break;
default:
F_3 ( & V_6 -> V_10 , L_16 ,
V_2 -> V_233 ) ;
goto V_11;
}
F_14 ( V_2 , V_286 , 0x00 ) ;
F_14 ( V_2 , V_287 , 39 ) ;
if ( V_2 -> V_233 == V_284 )
F_16 ( V_2 , V_288 , V_289 ) ;
F_1 ( V_2 , V_290 ,
V_291 | V_292 ) ;
if ( V_6 -> V_49 ) {
int V_293 ;
F_98 ( & V_2 -> V_65 ) ;
F_99 ( & V_2 -> V_47 , F_21 ) ;
F_13 ( V_2 , V_60 ) ;
F_13 ( V_2 , V_61 ) ;
F_13 ( V_2 , V_62 ) ;
V_293 =
F_100 ( F_101 ( V_6 -> V_49 ) ) ;
V_9 = F_102 ( V_6 -> V_49 , NULL ,
F_25 ,
V_293 | V_294 ,
L_17 , V_2 ) ;
if ( V_9 ) {
F_3 ( & V_6 -> V_10 ,
L_18 ,
V_6 -> V_49 , V_9 ) ;
goto V_11;
}
F_1 ( V_2 , V_268 , V_242 ) ;
}
F_16 ( V_2 , V_62 , V_63 ) ;
if ( ! V_270 )
return 0 ;
V_9 = F_103 ( V_270 , L_19 , & V_272 ) ;
if ( V_9 == 0 ) {
V_2 -> V_120 = V_272 >> 16 ;
V_2 -> V_127 = V_272 >> 8 ;
V_2 -> V_134 = V_272 ;
}
return 0 ;
V_11:
if ( V_2 -> V_7 )
F_83 ( V_2 -> V_7 ) ;
return - V_295 ;
}
static int F_104 ( struct V_5 * V_6 ,
struct V_296 * V_10 ,
struct V_297 * V_298 )
{
struct V_1 * V_2 ;
int V_9 ;
V_2 = F_105 ( sizeof( * V_2 ) , V_299 ) ;
if ( ! V_2 )
return - V_300 ;
V_2 -> V_48 = & V_298 -> V_301 ;
V_9 = F_94 ( V_6 , V_2 ) ;
if ( V_9 ) {
F_77 ( V_2 ) ;
return V_9 ;
}
V_298 -> V_302 = V_2 ;
V_298 -> V_303 = & V_304 ;
return 0 ;
}
static void F_106 ( struct V_151 * V_48 , int V_79 )
{
struct V_305 * V_2 = F_107 ( V_48 ) ;
F_49 ( & V_2 -> V_301 , V_79 ) ;
}
static void F_108 ( struct V_151 * V_48 )
{
F_106 ( V_48 , V_143 ) ;
}
static void F_109 ( struct V_151 * V_48 )
{
F_106 ( V_48 , V_142 ) ;
}
static void F_110 ( struct V_151 * V_48 ,
struct V_78 * V_79 ,
struct V_78 * V_152 )
{
struct V_305 * V_2 = F_107 ( V_48 ) ;
F_56 ( & V_2 -> V_301 , V_79 , V_152 ) ;
}
static void F_111 ( struct V_151 * V_48 )
{
struct V_305 * V_2 = F_107 ( V_48 ) ;
F_80 ( & V_2 -> V_301 ) ;
F_112 ( V_48 ) ;
}
static int F_113 ( struct V_257 * V_258 )
{
struct V_305 * V_2 = F_114 ( V_258 ) ;
return F_71 ( & V_2 -> V_301 , V_258 ) ;
}
static int F_115 ( struct V_257 * V_258 ,
struct V_78 * V_79 )
{
struct V_305 * V_2 = F_114 ( V_258 ) ;
return F_54 ( & V_2 -> V_301 , V_79 ) ;
}
static struct V_151 *
F_116 ( struct V_257 * V_258 )
{
struct V_305 * V_2 = F_114 ( V_258 ) ;
return & V_2 -> V_48 ;
}
static enum V_241
F_117 ( struct V_257 * V_258 , bool V_306 )
{
struct V_305 * V_2 = F_114 ( V_258 ) ;
return F_67 ( & V_2 -> V_301 ) ;
}
static void F_118 ( struct V_257 * V_258 )
{
F_119 ( V_258 ) ;
F_120 ( V_258 ) ;
}
static int F_121 ( struct V_307 * V_10 , struct V_307 * V_308 , void * V_50 )
{
struct V_72 * V_141 = V_10 -> V_309 ;
struct V_5 * V_6 = F_122 ( V_10 ) ;
struct V_296 * V_310 = V_50 ;
struct V_305 * V_2 ;
T_6 V_311 = 0 ;
int V_9 ;
V_2 = F_123 ( V_10 , sizeof( * V_2 ) , V_299 ) ;
if ( ! V_2 )
return - V_300 ;
F_124 ( V_10 , V_2 ) ;
if ( V_10 -> V_271 )
V_311 = F_125 ( V_310 , V_10 -> V_271 ) ;
if ( V_311 == 0 ) {
F_73 ( V_10 , L_20 ) ;
V_311 = 1 << 0 ;
}
V_2 -> V_301 . V_48 = & V_2 -> V_48 ;
V_2 -> V_258 . V_312 = 1 ;
V_2 -> V_48 . V_313 = V_311 ;
V_9 = F_94 ( V_6 , & V_2 -> V_301 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_10 -> V_271 && V_141 )
F_42 ( & V_2 -> V_301 , V_141 ) ;
F_78 ( & V_2 -> V_301 , & V_2 -> V_258 ) ;
F_126 ( & V_2 -> V_48 , & V_314 ) ;
V_9 = F_127 ( V_310 , & V_2 -> V_48 , & V_315 ,
V_316 ) ;
if ( V_9 )
goto V_317;
F_128 ( & V_2 -> V_258 ,
& V_318 ) ;
V_9 = F_129 ( V_310 , & V_2 -> V_258 ,
& V_319 ,
V_320 ) ;
if ( V_9 )
goto V_321;
V_9 = F_130 ( & V_2 -> V_258 ) ;
if ( V_9 )
goto V_322;
V_2 -> V_258 . V_48 = & V_2 -> V_48 ;
F_131 ( & V_2 -> V_258 , & V_2 -> V_48 ) ;
return 0 ;
V_322:
F_120 ( & V_2 -> V_258 ) ;
V_321:
F_112 ( & V_2 -> V_48 ) ;
V_317:
F_80 ( & V_2 -> V_301 ) ;
return V_9 ;
}
static void F_132 ( struct V_307 * V_10 , struct V_307 * V_308 ,
void * V_50 )
{
struct V_305 * V_2 = F_133 ( V_10 ) ;
F_120 ( & V_2 -> V_258 ) ;
F_112 ( & V_2 -> V_48 ) ;
F_80 ( & V_2 -> V_301 ) ;
}
static int
F_134 ( struct V_5 * V_6 , const struct V_323 * V_324 )
{
return F_135 ( & V_6 -> V_10 , & V_325 ) ;
}
static int F_136 ( struct V_5 * V_6 )
{
F_137 ( & V_6 -> V_10 , & V_325 ) ;
return 0 ;
}
static int T_9
F_138 ( void )
{
F_51 ( L_7 ) ;
return F_139 ( V_326 , & V_327 ) ;
}
static void T_10
F_140 ( void )
{
F_51 ( L_7 ) ;
F_141 ( & V_327 ) ;
}
