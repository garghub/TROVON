static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
F_2 ( V_2 -> V_7 , V_8 ,
V_9 ,
V_10 << V_11 ) ;
break;
case V_12 :
F_2 ( V_2 -> V_7 , V_8 ,
V_9 , 0 ) ;
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
switch ( V_5 ) {
case V_13 :
F_2 ( V_2 -> V_7 , V_14 ,
V_15 , V_15 ) ;
break;
case V_16 :
F_2 ( V_2 -> V_7 , V_14 ,
V_15 , 0 ) ;
F_4 ( 400 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
V_18 -> type = V_19 ;
V_18 -> V_20 = 2 ;
V_18 -> V_21 . integer . V_22 = 0 ;
V_18 -> V_21 . integer . V_23 = 0xfc - 0x3c ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_24 * V_25 )
{
struct V_26 * V_7 = F_7 ( V_4 ) ;
int V_27 ;
int V_28 ;
int V_29 ;
V_27 = F_8 ( V_7 , V_30 ) ;
V_28 = ( V_27 & V_31 ) >> V_32 ;
V_29 = ( V_27 & V_33 ) >> V_34 ;
V_28 = F_9 ( V_28 , 0x3c , 0xfc ) ;
V_29 = F_9 ( V_29 , 0x3c , 0xfc ) ;
V_28 = 0xfc - V_28 ;
V_29 = 0xfc - V_29 ;
V_25 -> V_21 . integer . V_21 [ 0 ] = V_28 ;
V_25 -> V_21 . integer . V_21 [ 1 ] = V_29 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_24 * V_25 )
{
struct V_26 * V_7 = F_7 ( V_4 ) ;
int V_27 ;
int V_28 ;
int V_29 ;
V_28 = V_25 -> V_21 . integer . V_21 [ 0 ] ;
V_29 = V_25 -> V_21 . integer . V_21 [ 1 ] ;
V_28 = F_9 ( V_28 , 0 , 0xfc - 0x3c ) ;
V_29 = F_9 ( V_29 , 0 , 0xfc - 0x3c ) ;
V_28 = 0xfc - V_28 ;
V_29 = 0xfc - V_29 ;
V_27 = V_28 << V_32 |
V_29 << V_34 ;
F_11 ( V_7 , V_30 , V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_35 * V_36 , int V_37 )
{
struct V_26 * V_7 = V_36 -> V_7 ;
T_1 V_38 = V_39 | V_40 ;
F_2 ( V_7 , V_41 ,
V_38 , V_37 ? V_38 : 0 ) ;
return 0 ;
}
static int F_13 ( struct V_35 * V_36 , unsigned int V_42 )
{
struct V_26 * V_7 = V_36 -> V_7 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
T_1 V_45 = 0 ;
V_44 -> V_46 = 0 ;
switch ( V_42 & V_47 ) {
case V_48 :
break;
case V_49 :
V_45 |= V_50 ;
V_44 -> V_46 = 1 ;
break;
default:
return - V_51 ;
}
switch ( V_42 & V_52 ) {
case V_53 :
V_45 |= V_54 ;
break;
case V_55 :
V_45 |= V_54 ;
V_45 |= V_56 ;
break;
case V_57 :
V_45 |= V_58 ;
break;
case V_59 :
V_45 |= V_60 ;
V_45 |= V_61 ;
break;
case V_62 :
V_45 |= V_58 ;
V_45 |= V_56 ;
break;
default:
return - V_51 ;
}
V_44 -> V_42 = V_42 & V_52 ;
switch ( V_42 & V_63 ) {
case V_64 :
break;
case V_65 :
V_45 |= V_66 ;
break;
default:
return - V_51 ;
}
F_11 ( V_7 , V_67 , V_45 ) ;
return 0 ;
}
static int F_15 ( struct V_35 * V_36 ,
int V_68 , unsigned int V_69 , int V_70 )
{
struct V_26 * V_7 = V_36 -> V_7 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
switch ( V_68 ) {
case V_71 :
V_44 -> V_72 = V_69 ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_16 ( struct V_26 * V_7 , int V_73 )
{
struct V_43 * V_44 = F_14 ( V_7 ) ;
int V_74 = 0 ;
int V_75 ;
switch ( V_73 ) {
case 8000 :
case 16000 :
V_75 = 32000 ;
break;
case 11025 :
case 22050 :
V_75 = 44100 ;
break;
default:
V_75 = V_73 ;
break;
}
switch ( V_75 / V_73 ) {
case 4 :
V_74 |= V_76 << V_77 ;
break;
case 2 :
V_74 |= V_78 << V_77 ;
break;
case 1 :
V_74 |= V_79 << V_77 ;
break;
default:
return - V_51 ;
}
switch ( V_75 ) {
case 32000 :
V_74 |= V_80 << V_81 ;
break;
case 44100 :
V_74 |= V_82 << V_81 ;
break;
case 48000 :
V_74 |= V_83 << V_81 ;
break;
case 96000 :
V_74 |= V_84 << V_81 ;
break;
default:
F_17 ( V_7 -> V_85 , L_1 ,
V_73 ) ;
return - V_51 ;
}
switch ( V_44 -> V_72 / V_75 ) {
case 256 :
V_74 |= V_86 <<
V_87 ;
break;
case 384 :
V_74 |= V_88 <<
V_87 ;
break;
case 512 :
V_74 |= V_89 <<
V_87 ;
break;
default:
if ( V_44 -> V_46 ) {
V_74 |= V_90 <<
V_87 ;
} else {
F_17 ( V_7 -> V_85 ,
L_2 ) ;
return - V_51 ;
}
}
if ( ( V_74 & V_91 ) == V_90 ) {
T_2 V_92 , V_93 ;
int V_94 ;
int V_95 ;
unsigned int V_96 , V_97 , V_98 ;
if ( V_44 -> V_72 > 17000000 ) {
V_94 = 1 ;
V_96 = V_44 -> V_72 / 2 ;
} else {
V_94 = 0 ;
V_96 = V_44 -> V_72 ;
}
if ( V_75 == 44100 )
V_92 = 180633600 ;
else
V_92 = 196608000 ;
V_93 = F_18 ( V_92 , V_96 ) ;
V_97 = V_92 ;
V_93 *= 2048 ;
F_18 ( V_93 , V_96 ) ;
V_98 = V_93 ;
V_95 = V_97 << V_99 |
V_98 << V_100 ;
F_11 ( V_7 , V_101 , V_95 ) ;
if ( V_94 )
F_2 ( V_7 ,
V_102 ,
V_103 ,
V_103 ) ;
else
F_2 ( V_7 ,
V_102 ,
V_103 ,
0 ) ;
F_2 ( V_7 , V_14 ,
V_104 | V_105 ,
V_104 | V_105 ) ;
} else {
F_2 ( V_7 , V_14 ,
V_104 | V_105 ,
0 ) ;
}
F_11 ( V_7 , V_106 , V_74 ) ;
return 0 ;
}
static int F_19 ( struct V_107 * V_108 ,
struct V_109 * V_110 ,
struct V_35 * V_111 )
{
struct V_26 * V_7 = V_111 -> V_7 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
int V_112 = F_20 ( V_110 ) ;
int V_113 = 0 ;
int V_114 ;
int V_115 ;
if ( ! V_44 -> V_72 ) {
F_17 ( V_7 -> V_85 , L_3 , V_116 ) ;
return - V_117 ;
}
if ( V_108 -> V_118 == V_119 )
V_114 = V_120 ;
else
V_114 = V_121 ;
F_2 ( V_7 , V_14 , V_114 ,
V_112 == 1 ? 0 : V_114 ) ;
V_115 = F_16 ( V_7 , F_21 ( V_110 ) ) ;
if ( V_115 )
return V_115 ;
switch ( F_22 ( V_110 ) ) {
case V_122 :
if ( V_44 -> V_42 == V_59 )
return - V_51 ;
V_113 |= V_123 << V_124 ;
V_113 |= V_125 <<
V_126 ;
break;
case V_127 :
V_113 |= V_128 << V_124 ;
V_113 |= V_129 <<
V_126 ;
break;
case V_130 :
V_113 |= V_131 << V_124 ;
V_113 |= V_129 <<
V_126 ;
break;
case V_132 :
if ( V_44 -> V_42 == V_59 )
return - V_51 ;
V_113 |= V_133 << V_124 ;
V_113 |= V_129 <<
V_126 ;
break;
default:
return - V_51 ;
}
F_2 ( V_7 , V_67 ,
V_134 | V_135 ,
V_113 ) ;
return 0 ;
}
static int F_23 ( struct V_136 * V_85 )
{
struct V_137 * V_138 = F_24 ( V_85 ) ;
return V_138 -> V_139 ;
}
static int F_25 ( struct V_136 * V_85 )
{
struct V_137 * V_138 = F_24 ( V_85 ) ;
struct V_26 * V_7 = (struct V_26 * ) V_138 -> V_140 ;
int V_27 ;
if ( F_23 ( V_85 ) )
return 0 ;
V_27 = ( 1600 - V_138 -> V_141 / 1000 ) / 50 ;
V_27 = F_9 ( V_27 , 0x0 , 0xf ) ;
V_138 -> V_141 = ( 1600 - V_27 * 50 ) * 1000 ;
F_2 ( V_7 , V_142 ,
V_143 , V_27 ) ;
F_2 ( V_7 , V_14 ,
V_144 ,
V_144 ) ;
F_2 ( V_7 , V_14 ,
V_145 ,
0 ) ;
V_138 -> V_139 = 1 ;
return 0 ;
}
static int F_26 ( struct V_136 * V_85 )
{
struct V_137 * V_138 = F_24 ( V_85 ) ;
struct V_26 * V_7 = (struct V_26 * ) V_138 -> V_140 ;
F_2 ( V_7 , V_14 ,
V_144 ,
0 ) ;
F_2 ( V_7 , V_142 ,
V_143 , 0 ) ;
V_138 -> V_139 = 0 ;
return 0 ;
}
static int F_27 ( struct V_136 * V_85 )
{
struct V_137 * V_138 = F_24 ( V_85 ) ;
return V_138 -> V_141 ;
}
static int F_28 ( struct V_26 * V_7 ,
struct V_146 * V_147 ,
int V_141 )
{
struct V_137 * V_138 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
struct V_148 V_149 = { } ;
V_138 = F_29 ( sizeof( struct V_137 ) , V_150 ) ;
if ( ! V_138 ) {
F_17 ( V_7 -> V_85 , L_4 ) ;
return - V_151 ;
}
V_138 -> V_152 . V_153 = F_30 ( F_31 ( V_7 -> V_85 ) , V_150 ) ;
if ( ! V_138 -> V_152 . V_153 ) {
F_32 ( V_138 ) ;
F_17 ( V_7 -> V_85 , L_5 ) ;
return - V_151 ;
}
V_138 -> V_152 . type = V_154 ;
V_138 -> V_152 . V_155 = V_156 ;
V_138 -> V_152 . V_157 = & V_158 ;
V_138 -> V_152 . V_159 = 1 ;
V_138 -> V_140 = V_7 ;
V_138 -> V_141 = V_141 ;
V_149 . V_85 = V_7 -> V_85 ;
V_149 . V_160 = V_138 ;
V_149 . V_147 = V_147 ;
V_138 -> V_85 = F_33 ( & V_138 -> V_152 , & V_149 ) ;
if ( F_34 ( V_138 -> V_85 ) ) {
int V_115 = F_35 ( V_138 -> V_85 ) ;
F_17 ( V_7 -> V_85 , L_6 ) ;
F_32 ( V_138 -> V_152 . V_153 ) ;
F_32 ( V_138 ) ;
return V_115 ;
}
V_44 -> V_138 = V_138 ;
return 0 ;
}
static int F_36 ( struct V_26 * V_7 )
{
struct V_43 * V_44 = F_14 ( V_7 ) ;
struct V_137 * V_138 = V_44 -> V_138 ;
if ( ! V_138 )
return 0 ;
F_37 ( V_138 -> V_85 ) ;
F_32 ( V_138 -> V_152 . V_153 ) ;
F_32 ( V_138 ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_7 ,
struct V_146 * V_147 ,
int V_141 )
{
F_17 ( V_7 -> V_85 , L_7 ) ;
return - V_51 ;
}
static int F_36 ( struct V_26 * V_7 )
{
return 0 ;
}
static int F_38 ( struct V_26 * V_7 ,
enum V_161 V_162 )
{
int V_115 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
switch ( V_162 ) {
case V_163 :
case V_164 :
break;
case V_165 :
if ( V_7 -> V_166 . V_167 == V_168 ) {
V_115 = F_39 (
F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
if ( V_115 )
return V_115 ;
F_41 ( 10 ) ;
}
break;
case V_168 :
F_42 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
break;
}
V_7 -> V_166 . V_167 = V_162 ;
return 0 ;
}
static int F_43 ( struct V_26 * V_7 ,
unsigned int V_27 )
{
switch ( V_27 ) {
case V_170 :
case V_41 :
case V_171 :
return 1 ;
}
return 0 ;
}
static int F_44 ( struct V_26 * V_7 )
{
F_38 ( V_7 , V_168 ) ;
return 0 ;
}
static int F_45 ( struct V_26 * V_7 )
{
T_1 * V_172 = V_7 -> V_173 ;
T_1 V_27 ;
for ( V_27 = 0 ; V_27 <= V_174 ; V_27 += 2 ) {
if ( V_27 == V_14 ||
V_27 == V_106 ||
V_27 == V_142 ||
V_27 == V_175 ||
V_27 == V_176 )
continue;
F_11 ( V_7 , V_27 , V_172 [ V_27 ] ) ;
}
for ( V_27 = V_177 ; V_27 < V_178 ; V_27 += 2 )
F_11 ( V_7 , V_27 , V_172 [ V_27 ] ) ;
F_11 ( V_7 , V_142 ,
V_172 [ V_142 ] ) ;
F_11 ( V_7 , V_14 ,
V_172 [ V_14 ] ) ;
F_11 ( V_7 , V_106 ,
V_172 [ V_106 ] ) ;
F_11 ( V_7 , V_176 ,
V_172 [ V_176 ] ) ;
F_11 ( V_7 , V_175 ,
V_172 [ V_175 ] ) ;
return 0 ;
}
static int F_46 ( struct V_26 * V_7 )
{
F_38 ( V_7 , V_165 ) ;
F_45 ( V_7 ) ;
return 0 ;
}
static int F_47 ( struct V_26 * V_7 )
{
int V_179 ;
int V_180 ;
int V_181 ;
T_1 V_182 ;
T_1 V_183 ;
int V_184 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
V_180 = F_48 ( V_44 -> V_169 [ V_185 ] . V_186 ) ;
V_181 = F_48 ( V_44 -> V_169 [ V_187 ] . V_186 ) ;
V_179 = F_48 ( V_44 -> V_169 [ V_188 ] . V_186 ) ;
V_180 = V_180 / 1000 ;
V_181 = V_181 / 1000 ;
V_179 = V_179 / 1000 ;
if ( V_180 <= 0 || V_181 <= 0 || V_179 < 0 ) {
F_17 ( V_7 -> V_85 , L_8 ) ;
return - V_51 ;
}
if ( V_180 > 3600 || V_181 > 3600 || V_179 > 1980 ) {
F_17 ( V_7 -> V_85 ,
L_9 ,
V_180 , V_181 , V_179 ) ;
return - V_51 ;
}
V_182 = F_8 ( V_7 , V_14 ) ;
V_182 |= V_120 |
V_121 |
V_189 ;
V_183 = F_8 ( V_7 , V_142 ) ;
if ( V_181 < 3100 && V_180 < 3100 ) {
F_2 ( V_7 , V_102 ,
V_190 ,
V_190 ) ;
V_182 |= V_191 ;
} else if ( V_181 >= 3100 && V_180 >= 3100 ) {
F_2 ( V_7 , V_14 ,
V_191 , 0 ) ;
V_183 |= V_192 ;
V_183 |= V_193 <<
V_194 ;
}
F_11 ( V_7 , V_142 , V_183 ) ;
F_11 ( V_7 , V_14 , V_182 ) ;
F_2 ( V_7 , V_142 ,
V_143 , 0x8 ) ;
if ( V_182 & V_144 )
F_2 ( V_7 , V_14 ,
V_145 ,
0 ) ;
else
F_2 ( V_7 , V_14 ,
V_145 |
V_195 ,
0 ) ;
V_184 = V_180 / 2 ;
if ( V_184 <= V_196 )
V_184 = 0 ;
else if ( V_184 >= V_196 + V_197 *
( V_198 >> V_199 ) )
V_184 = V_198 >> V_199 ;
else
V_184 = ( V_184 - V_196 ) / V_197 ;
F_2 ( V_7 , V_176 ,
V_198 , V_184 << V_199 ) ;
V_184 = V_181 / 2 ;
if ( V_184 <= V_200 )
V_184 = 0 ;
else if ( V_184 >= V_200 +
V_201 * V_202 )
V_184 = V_202 ;
else
V_184 = ( V_184 - V_200 ) /
V_201 ;
F_2 ( V_7 , V_175 ,
V_203 |
V_204 ,
V_184 << V_205 |
V_206 <<
V_207 ) ;
return 0 ;
}
static int F_49 ( struct V_26 * V_7 )
{
struct V_43 * V_44 = F_14 ( V_7 ) ;
int V_115 ;
V_115 = F_28 ( V_7 , & V_208 , V_209 ) ;
if ( V_115 ) {
F_17 ( V_7 -> V_85 ,
L_10 , V_115 ) ;
return V_115 ;
}
V_44 -> V_169 [ V_188 ] . V_210 = V_211 ;
V_115 = F_50 ( V_7 -> V_85 , F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
if ( V_115 ) {
F_36 ( V_7 ) ;
F_17 ( V_7 -> V_85 , L_11 , V_115 ) ;
return V_115 ;
}
F_51 ( V_7 -> V_85 , L_12 ) ;
return 0 ;
}
static int F_52 ( struct V_26 * V_7 )
{
T_1 V_27 ;
int V_115 ;
int V_212 ;
int V_213 ;
int V_214 = 0 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
for ( V_213 = 0 ; V_213 < F_40 ( V_44 -> V_169 ) ; V_213 ++ )
V_44 -> V_169 [ V_213 ] . V_210 = V_215 [ V_213 ] ;
V_115 = F_50 ( V_7 -> V_85 , F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
if ( ! V_115 )
V_214 = 1 ;
else {
V_115 = F_49 ( V_7 ) ;
if ( V_115 )
return V_115 ;
}
V_115 = F_39 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
if ( V_115 )
goto V_216;
F_41 ( 10 ) ;
V_27 = F_8 ( V_7 , V_170 ) ;
if ( ( ( V_27 & V_217 ) >> V_218 ) !=
V_219 ) {
F_17 ( V_7 -> V_85 ,
L_13 , V_27 ) ;
V_115 = - V_220 ;
goto V_221;
}
V_212 = ( V_27 & V_222 ) >> V_223 ;
F_51 ( V_7 -> V_85 , L_14 , V_212 ) ;
if ( V_214 && V_212 >= 0x11 ) {
F_42 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
F_53 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
V_115 = F_49 ( V_7 ) ;
if ( V_115 )
return V_115 ;
V_115 = F_39 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
if ( V_115 )
goto V_216;
F_41 ( 10 ) ;
}
return 0 ;
V_221:
F_42 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
V_216:
F_53 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
if ( V_214 )
F_36 ( V_7 ) ;
return V_115 ;
}
static int F_54 ( struct V_26 * V_7 )
{
int V_115 ;
struct V_43 * V_44 = F_14 ( V_7 ) ;
V_115 = F_55 ( V_7 , 16 , 16 , V_224 ) ;
if ( V_115 < 0 ) {
F_17 ( V_7 -> V_85 , L_15 , V_115 ) ;
return V_115 ;
}
V_115 = F_52 ( V_7 ) ;
if ( V_115 )
return V_115 ;
V_115 = F_47 ( V_7 ) ;
if ( V_115 )
goto V_225;
F_2 ( V_7 , V_176 ,
V_226 ,
V_226 ) ;
F_11 ( V_7 , V_174 , 0 ) ;
F_11 ( V_7 , V_227 ,
V_228 << V_229 ) ;
F_11 ( V_7 , V_230 ,
V_231 | V_232 ) ;
F_11 ( V_7 , V_41 ,
V_233 |
V_40 |
V_39 ) ;
F_11 ( V_7 , V_234 , 0x015f ) ;
F_11 ( V_7 , V_235 ,
V_236 |
V_237 ) ;
F_11 ( V_7 , V_8 , 0 ) ;
F_11 ( V_7 , V_238 , 0 ) ;
V_115 = F_38 ( V_7 , V_165 ) ;
if ( V_115 )
goto V_225;
return 0 ;
V_225:
F_42 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
F_53 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
F_36 ( V_7 ) ;
return V_115 ;
}
static int F_56 ( struct V_26 * V_7 )
{
struct V_43 * V_44 = F_14 ( V_7 ) ;
F_38 ( V_7 , V_168 ) ;
F_42 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
F_53 ( F_40 ( V_44 -> V_169 ) ,
V_44 -> V_169 ) ;
F_36 ( V_7 ) ;
return 0 ;
}
static T_3 int F_57 ( struct V_239 * V_240 ,
const struct V_241 * V_242 )
{
struct V_43 * V_44 ;
int V_115 ;
V_44 = F_58 ( & V_240 -> V_85 , sizeof( struct V_43 ) ,
V_150 ) ;
if ( ! V_44 )
return - V_151 ;
F_59 ( V_240 , V_44 ) ;
V_115 = F_60 ( & V_240 -> V_85 ,
& V_243 , & V_244 , 1 ) ;
return V_115 ;
}
static T_4 int F_61 ( struct V_239 * V_240 )
{
F_62 ( & V_240 -> V_85 ) ;
return 0 ;
}
