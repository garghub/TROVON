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
case V_12 :
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
struct V_16 * V_17 )
{
V_17 -> type = V_18 ;
V_17 -> V_19 = 2 ;
V_17 -> V_20 . integer . V_21 = 0 ;
V_17 -> V_20 . integer . V_22 = 0xfc - 0x3c ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
struct V_25 * V_7 = F_7 ( V_4 ) ;
int V_26 ;
int V_27 ;
int V_28 ;
V_26 = F_8 ( V_7 , V_29 ) ;
V_27 = ( V_26 & V_30 ) >> V_31 ;
V_28 = ( V_26 & V_32 ) >> V_33 ;
V_27 = F_9 ( V_27 , 0x3c , 0xfc ) ;
V_28 = F_9 ( V_28 , 0x3c , 0xfc ) ;
V_27 = 0xfc - V_27 ;
V_28 = 0xfc - V_28 ;
V_24 -> V_20 . integer . V_20 [ 0 ] = V_27 ;
V_24 -> V_20 . integer . V_20 [ 1 ] = V_28 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
struct V_25 * V_7 = F_7 ( V_4 ) ;
int V_26 ;
int V_27 ;
int V_28 ;
V_27 = V_24 -> V_20 . integer . V_20 [ 0 ] ;
V_28 = V_24 -> V_20 . integer . V_20 [ 1 ] ;
V_27 = F_9 ( V_27 , 0 , 0xfc - 0x3c ) ;
V_28 = F_9 ( V_28 , 0 , 0xfc - 0x3c ) ;
V_27 = 0xfc - V_27 ;
V_28 = 0xfc - V_28 ;
V_26 = V_27 << V_31 |
V_28 << V_33 ;
F_11 ( V_7 , V_29 , V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_34 * V_35 , int V_36 )
{
struct V_25 * V_7 = V_35 -> V_7 ;
T_1 V_37 = V_38 | V_39 ;
F_2 ( V_7 , V_40 ,
V_37 , V_36 ? V_37 : 0 ) ;
return 0 ;
}
static int F_13 ( struct V_34 * V_35 , unsigned int V_41 )
{
struct V_25 * V_7 = V_35 -> V_7 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
T_1 V_44 = 0 ;
V_43 -> V_45 = 0 ;
switch ( V_41 & V_46 ) {
case V_47 :
break;
case V_48 :
V_44 |= V_49 ;
V_43 -> V_45 = 1 ;
break;
default:
return - V_50 ;
}
switch ( V_41 & V_51 ) {
case V_52 :
V_44 |= V_53 ;
break;
case V_54 :
V_44 |= V_53 ;
V_44 |= V_55 ;
break;
case V_56 :
V_44 |= V_57 ;
break;
case V_58 :
V_44 |= V_59 ;
V_44 |= V_60 ;
break;
case V_61 :
V_44 |= V_57 ;
V_44 |= V_55 ;
break;
default:
return - V_50 ;
}
V_43 -> V_41 = V_41 & V_51 ;
switch ( V_41 & V_62 ) {
case V_63 :
break;
case V_64 :
V_44 |= V_65 ;
break;
default:
return - V_50 ;
}
F_11 ( V_7 , V_66 , V_44 ) ;
return 0 ;
}
static int F_15 ( struct V_34 * V_35 ,
int V_67 , unsigned int V_68 , int V_69 )
{
struct V_25 * V_7 = V_35 -> V_7 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
switch ( V_67 ) {
case V_70 :
V_43 -> V_71 = V_68 ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static int F_16 ( struct V_25 * V_7 , int V_72 )
{
struct V_42 * V_43 = F_14 ( V_7 ) ;
int V_73 = 0 ;
int V_74 ;
switch ( V_72 ) {
case 8000 :
case 16000 :
V_74 = 32000 ;
break;
case 11025 :
case 22050 :
V_74 = 44100 ;
break;
default:
V_74 = V_72 ;
break;
}
switch ( V_74 / V_72 ) {
case 4 :
V_73 |= V_75 << V_76 ;
break;
case 2 :
V_73 |= V_77 << V_76 ;
break;
case 1 :
V_73 |= V_78 << V_76 ;
break;
default:
return - V_50 ;
}
switch ( V_74 ) {
case 32000 :
V_73 |= V_79 << V_80 ;
break;
case 44100 :
V_73 |= V_81 << V_80 ;
break;
case 48000 :
V_73 |= V_82 << V_80 ;
break;
case 96000 :
V_73 |= V_83 << V_80 ;
break;
default:
F_17 ( V_7 -> V_84 , L_1 ,
V_72 ) ;
return - V_50 ;
}
switch ( V_43 -> V_71 / V_74 ) {
case 256 :
V_73 |= V_85 <<
V_86 ;
break;
case 384 :
V_73 |= V_87 <<
V_86 ;
break;
case 512 :
V_73 |= V_88 <<
V_86 ;
break;
default:
if ( V_43 -> V_45 ) {
V_73 |= V_89 <<
V_86 ;
} else {
F_17 ( V_7 -> V_84 ,
L_2 ) ;
return - V_50 ;
}
}
if ( ( V_73 & V_90 ) == V_89 ) {
T_2 V_91 , V_92 ;
int V_93 ;
int V_94 ;
unsigned int V_95 , V_96 , V_97 ;
if ( V_43 -> V_71 > 17000000 ) {
V_93 = 1 ;
V_95 = V_43 -> V_71 / 2 ;
} else {
V_93 = 0 ;
V_95 = V_43 -> V_71 ;
}
if ( V_74 == 44100 )
V_91 = 180633600 ;
else
V_91 = 196608000 ;
V_92 = F_18 ( V_91 , V_95 ) ;
V_96 = V_91 ;
V_92 *= 2048 ;
F_18 ( V_92 , V_95 ) ;
V_97 = V_92 ;
V_94 = V_96 << V_98 |
V_97 << V_99 ;
F_11 ( V_7 , V_100 , V_94 ) ;
if ( V_93 )
F_2 ( V_7 ,
V_101 ,
V_102 ,
V_102 ) ;
else
F_2 ( V_7 ,
V_101 ,
V_102 ,
0 ) ;
F_2 ( V_7 , V_14 ,
V_103 | V_104 ,
V_103 | V_104 ) ;
} else {
F_2 ( V_7 , V_14 ,
V_103 | V_104 ,
0 ) ;
}
F_11 ( V_7 , V_105 , V_73 ) ;
return 0 ;
}
static int F_19 ( struct V_106 * V_107 ,
struct V_108 * V_109 ,
struct V_34 * V_110 )
{
struct V_111 * V_112 = V_107 -> V_113 ;
struct V_25 * V_7 = V_112 -> V_7 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
int V_114 = F_20 ( V_109 ) ;
int V_115 = 0 ;
int V_116 ;
int V_117 ;
if ( ! V_43 -> V_71 ) {
F_17 ( V_7 -> V_84 , L_3 , V_118 ) ;
return - V_119 ;
}
if ( V_107 -> V_120 == V_121 )
V_116 = V_122 ;
else
V_116 = V_123 ;
F_2 ( V_7 , V_14 , V_116 ,
V_114 == 1 ? 0 : V_116 ) ;
V_117 = F_16 ( V_7 , F_21 ( V_109 ) ) ;
if ( V_117 )
return V_117 ;
switch ( F_22 ( V_109 ) ) {
case V_124 :
if ( V_43 -> V_41 == V_58 )
return - V_50 ;
V_115 |= V_125 << V_126 ;
V_115 |= V_127 <<
V_128 ;
break;
case V_129 :
V_115 |= V_130 << V_126 ;
V_115 |= V_131 <<
V_128 ;
break;
case V_132 :
V_115 |= V_133 << V_126 ;
V_115 |= V_131 <<
V_128 ;
break;
case V_134 :
if ( V_43 -> V_41 == V_58 )
return - V_50 ;
V_115 |= V_135 << V_126 ;
V_115 |= V_131 <<
V_128 ;
break;
default:
return - V_50 ;
}
F_2 ( V_7 , V_66 ,
V_136 | V_137 ,
V_115 ) ;
return 0 ;
}
static int F_23 ( struct V_138 * V_84 )
{
struct V_139 * V_140 = F_24 ( V_84 ) ;
return V_140 -> V_141 ;
}
static int F_25 ( struct V_138 * V_84 )
{
struct V_139 * V_140 = F_24 ( V_84 ) ;
struct V_25 * V_7 = (struct V_25 * ) V_140 -> V_142 ;
int V_26 ;
if ( F_23 ( V_84 ) )
return 0 ;
V_26 = ( 1600 - V_140 -> V_143 / 1000 ) / 50 ;
V_26 = F_9 ( V_26 , 0x0 , 0xf ) ;
V_140 -> V_143 = ( 1600 - V_26 * 50 ) * 1000 ;
F_2 ( V_7 , V_144 ,
V_145 , V_26 ) ;
F_2 ( V_7 , V_14 ,
V_146 ,
V_146 ) ;
F_2 ( V_7 , V_14 ,
V_147 ,
0 ) ;
V_140 -> V_141 = 1 ;
return 0 ;
}
static int F_26 ( struct V_138 * V_84 )
{
struct V_139 * V_140 = F_24 ( V_84 ) ;
struct V_25 * V_7 = (struct V_25 * ) V_140 -> V_142 ;
F_2 ( V_7 , V_14 ,
V_146 ,
0 ) ;
F_2 ( V_7 , V_144 ,
V_145 , 0 ) ;
V_140 -> V_141 = 0 ;
return 0 ;
}
static int F_27 ( struct V_138 * V_84 )
{
struct V_139 * V_140 = F_24 ( V_84 ) ;
return V_140 -> V_143 ;
}
static int F_28 ( struct V_25 * V_7 ,
struct V_148 * V_149 ,
int V_143 )
{
struct V_139 * V_140 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
V_140 = F_29 ( sizeof( struct V_139 ) , V_150 ) ;
if ( ! V_140 ) {
F_17 ( V_7 -> V_84 , L_4 ) ;
return - V_151 ;
}
V_140 -> V_152 . V_153 = F_30 ( F_31 ( V_7 -> V_84 ) , V_150 ) ;
if ( ! V_140 -> V_152 . V_153 ) {
F_32 ( V_140 ) ;
F_17 ( V_7 -> V_84 , L_5 ) ;
return - V_151 ;
}
V_140 -> V_152 . type = V_154 ;
V_140 -> V_152 . V_155 = V_156 ;
V_140 -> V_152 . V_157 = & V_158 ;
V_140 -> V_152 . V_159 = 1 ;
V_140 -> V_142 = V_7 ;
V_140 -> V_143 = V_143 ;
V_140 -> V_84 = F_33 ( & V_140 -> V_152 , V_7 -> V_84 ,
V_149 , V_140 , NULL ) ;
if ( F_34 ( V_140 -> V_84 ) ) {
int V_117 = F_35 ( V_140 -> V_84 ) ;
F_17 ( V_7 -> V_84 , L_6 ) ;
F_32 ( V_140 -> V_152 . V_153 ) ;
F_32 ( V_140 ) ;
return V_117 ;
}
V_43 -> V_140 = V_140 ;
return 0 ;
}
static int F_36 ( struct V_25 * V_7 )
{
struct V_42 * V_43 = F_14 ( V_7 ) ;
struct V_139 * V_140 = V_43 -> V_140 ;
if ( ! V_140 )
return 0 ;
F_37 ( V_140 -> V_84 ) ;
F_32 ( V_140 -> V_152 . V_153 ) ;
F_32 ( V_140 ) ;
return 0 ;
}
static int F_28 ( struct V_25 * V_7 ,
struct V_148 * V_149 ,
int V_143 )
{
F_17 ( V_7 -> V_84 , L_7 ) ;
return - V_50 ;
}
static int F_36 ( struct V_25 * V_7 )
{
return 0 ;
}
static int F_38 ( struct V_25 * V_7 ,
enum V_160 V_161 )
{
int V_117 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
switch ( V_161 ) {
case V_162 :
case V_163 :
break;
case V_164 :
if ( V_7 -> V_165 . V_166 == V_167 ) {
V_117 = F_39 (
F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
if ( V_117 )
return V_117 ;
F_41 ( 10 ) ;
}
break;
case V_167 :
F_42 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
break;
}
V_7 -> V_165 . V_166 = V_161 ;
return 0 ;
}
static int F_43 ( struct V_25 * V_7 ,
unsigned int V_26 )
{
switch ( V_26 ) {
case V_169 :
case V_40 :
case V_170 :
return 1 ;
}
return 0 ;
}
static int F_44 ( struct V_25 * V_7 )
{
F_38 ( V_7 , V_167 ) ;
return 0 ;
}
static int F_45 ( struct V_25 * V_7 )
{
T_1 * V_171 = V_7 -> V_172 ;
T_1 V_26 ;
for ( V_26 = 0 ; V_26 <= V_173 ; V_26 += 2 ) {
if ( V_26 == V_14 ||
V_26 == V_105 ||
V_26 == V_144 ||
V_26 == V_174 ||
V_26 == V_175 )
continue;
F_11 ( V_7 , V_26 , V_171 [ V_26 ] ) ;
}
for ( V_26 = V_176 ; V_26 < V_177 ; V_26 += 2 )
F_11 ( V_7 , V_26 , V_171 [ V_26 ] ) ;
F_11 ( V_7 , V_144 ,
V_171 [ V_144 ] ) ;
F_11 ( V_7 , V_14 ,
V_171 [ V_14 ] ) ;
F_11 ( V_7 , V_105 ,
V_171 [ V_105 ] ) ;
F_11 ( V_7 , V_175 ,
V_171 [ V_175 ] ) ;
F_11 ( V_7 , V_174 ,
V_171 [ V_174 ] ) ;
return 0 ;
}
static int F_46 ( struct V_25 * V_7 )
{
F_38 ( V_7 , V_164 ) ;
F_45 ( V_7 ) ;
return 0 ;
}
static int F_47 ( struct V_25 * V_7 )
{
int V_178 ;
int V_179 ;
int V_180 ;
T_1 V_181 ;
T_1 V_182 ;
int V_183 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
V_179 = F_48 ( V_43 -> V_168 [ V_184 ] . V_185 ) ;
V_180 = F_48 ( V_43 -> V_168 [ V_186 ] . V_185 ) ;
V_178 = F_48 ( V_43 -> V_168 [ V_187 ] . V_185 ) ;
V_179 = V_179 / 1000 ;
V_180 = V_180 / 1000 ;
V_178 = V_178 / 1000 ;
if ( V_179 <= 0 || V_180 <= 0 || V_178 < 0 ) {
F_17 ( V_7 -> V_84 , L_8 ) ;
return - V_50 ;
}
if ( V_179 > 3600 || V_180 > 3600 || V_178 > 1980 ) {
F_17 ( V_7 -> V_84 ,
L_9 ,
V_179 , V_180 , V_178 ) ;
return - V_50 ;
}
V_181 = F_8 ( V_7 , V_14 ) ;
V_181 |= V_122 |
V_123 |
V_188 ;
V_182 = F_8 ( V_7 , V_144 ) ;
if ( V_180 < 3100 && V_179 < 3100 ) {
F_2 ( V_7 , V_101 ,
V_189 ,
V_189 ) ;
V_181 |= V_190 ;
} else if ( V_180 >= 3100 && V_179 >= 3100 ) {
F_2 ( V_7 , V_14 ,
V_190 , 0 ) ;
V_182 |= V_191 ;
V_182 |= V_192 <<
V_193 ;
}
F_11 ( V_7 , V_144 , V_182 ) ;
F_11 ( V_7 , V_14 , V_181 ) ;
F_2 ( V_7 , V_144 ,
V_145 , 0x8 ) ;
if ( V_181 & V_146 )
F_2 ( V_7 , V_14 ,
V_147 ,
0 ) ;
else
F_2 ( V_7 , V_14 ,
V_147 |
V_194 ,
0 ) ;
V_183 = V_179 / 2 ;
if ( V_183 <= V_195 )
V_183 = 0 ;
else if ( V_183 >= V_195 + V_196 *
( V_197 >> V_198 ) )
V_183 = V_197 >> V_198 ;
else
V_183 = ( V_183 - V_195 ) / V_196 ;
F_2 ( V_7 , V_175 ,
V_197 , V_183 << V_198 ) ;
V_183 = V_180 / 2 ;
if ( V_183 <= V_199 )
V_183 = 0 ;
else if ( V_183 >= V_199 +
V_200 * V_201 )
V_183 = V_201 ;
else
V_183 = ( V_183 - V_199 ) /
V_200 ;
F_2 ( V_7 , V_174 ,
V_202 |
V_203 ,
V_183 << V_204 |
V_205 <<
V_206 ) ;
return 0 ;
}
static int F_49 ( struct V_25 * V_7 )
{
struct V_42 * V_43 = F_14 ( V_7 ) ;
int V_117 ;
V_117 = F_28 ( V_7 , & V_207 , V_208 ) ;
if ( V_117 ) {
F_17 ( V_7 -> V_84 ,
L_10 , V_117 ) ;
return V_117 ;
}
V_43 -> V_168 [ V_187 ] . V_209 = V_210 ;
V_117 = F_50 ( V_7 -> V_84 , F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
if ( V_117 ) {
F_36 ( V_7 ) ;
F_17 ( V_7 -> V_84 , L_11 , V_117 ) ;
return V_117 ;
}
F_51 ( V_7 -> V_84 , L_12 ) ;
return 0 ;
}
static int F_52 ( struct V_25 * V_7 )
{
T_1 V_26 ;
int V_117 ;
int V_211 ;
int V_212 ;
int V_213 = 0 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
for ( V_212 = 0 ; V_212 < F_40 ( V_43 -> V_168 ) ; V_212 ++ )
V_43 -> V_168 [ V_212 ] . V_209 = V_214 [ V_212 ] ;
V_117 = F_50 ( V_7 -> V_84 , F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
if ( ! V_117 )
V_213 = 1 ;
else {
V_117 = F_49 ( V_7 ) ;
if ( V_117 )
return V_117 ;
}
V_117 = F_39 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
if ( V_117 )
goto V_215;
F_41 ( 10 ) ;
V_26 = F_8 ( V_7 , V_169 ) ;
if ( ( ( V_26 & V_216 ) >> V_217 ) !=
V_218 ) {
F_17 ( V_7 -> V_84 ,
L_13 , V_26 ) ;
V_117 = - V_219 ;
goto V_220;
}
V_211 = ( V_26 & V_221 ) >> V_222 ;
F_51 ( V_7 -> V_84 , L_14 , V_211 ) ;
if ( V_213 && V_211 >= 0x11 ) {
F_42 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
F_53 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
V_117 = F_49 ( V_7 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_39 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
if ( V_117 )
goto V_215;
F_41 ( 10 ) ;
}
return 0 ;
V_220:
F_42 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
V_215:
F_53 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
if ( V_213 )
F_36 ( V_7 ) ;
return V_117 ;
}
static int F_54 ( struct V_25 * V_7 )
{
int V_117 ;
struct V_42 * V_43 = F_14 ( V_7 ) ;
V_117 = F_55 ( V_7 , 16 , 16 , V_223 ) ;
if ( V_117 < 0 ) {
F_17 ( V_7 -> V_84 , L_15 , V_117 ) ;
return V_117 ;
}
V_117 = F_52 ( V_7 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_47 ( V_7 ) ;
if ( V_117 )
goto V_224;
F_2 ( V_7 , V_175 ,
V_225 ,
V_225 ) ;
F_11 ( V_7 , V_173 , 0 ) ;
F_11 ( V_7 , V_226 ,
V_227 << V_228 ) ;
F_11 ( V_7 , V_229 ,
V_230 | V_231 ) ;
F_11 ( V_7 , V_40 ,
V_232 |
V_39 |
V_38 ) ;
F_11 ( V_7 , V_233 , 0x015f ) ;
F_11 ( V_7 , V_234 ,
V_235 |
V_236 ) ;
F_11 ( V_7 , V_8 , 0 ) ;
F_11 ( V_7 , V_237 , 0 ) ;
V_117 = F_38 ( V_7 , V_164 ) ;
if ( V_117 )
goto V_224;
F_56 ( V_7 , V_238 ,
F_40 ( V_238 ) ) ;
F_57 ( & V_7 -> V_165 , V_239 ,
F_40 ( V_239 ) ) ;
F_58 ( & V_7 -> V_165 , V_240 ,
F_40 ( V_240 ) ) ;
F_59 ( & V_7 -> V_165 ) ;
return 0 ;
V_224:
F_42 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
F_53 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
F_36 ( V_7 ) ;
return V_117 ;
}
static int F_60 ( struct V_25 * V_7 )
{
struct V_42 * V_43 = F_14 ( V_7 ) ;
F_38 ( V_7 , V_167 ) ;
F_42 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
F_53 ( F_40 ( V_43 -> V_168 ) ,
V_43 -> V_168 ) ;
F_36 ( V_7 ) ;
return 0 ;
}
static T_3 int F_61 ( struct V_241 * V_242 ,
const struct V_243 * V_244 )
{
struct V_42 * V_43 ;
int V_117 ;
V_43 = F_62 ( & V_242 -> V_84 , sizeof( struct V_42 ) ,
V_150 ) ;
if ( ! V_43 )
return - V_151 ;
F_63 ( V_242 , V_43 ) ;
V_117 = F_64 ( & V_242 -> V_84 ,
& V_245 , & V_246 , 1 ) ;
return V_117 ;
}
static T_4 int F_65 ( struct V_241 * V_242 )
{
F_66 ( & V_242 -> V_84 ) ;
return 0 ;
}
static int T_5 F_67 ( void )
{
return F_68 ( & V_247 ) ;
}
static void T_6 F_69 ( void )
{
F_70 ( & V_247 ) ;
}
