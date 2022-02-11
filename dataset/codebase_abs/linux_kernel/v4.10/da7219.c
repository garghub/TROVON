static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
F_4 ( & V_8 -> V_10 ) ;
V_9 = F_5 ( V_2 , V_4 ) ;
F_6 ( & V_8 -> V_10 ) ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
F_4 ( & V_8 -> V_10 ) ;
V_9 = F_8 ( V_2 , V_4 ) ;
F_6 ( & V_8 -> V_10 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
F_4 ( & V_8 -> V_10 ) ;
V_9 = F_10 ( V_2 , V_4 ) ;
F_6 ( & V_8 -> V_10 ) ;
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
F_4 ( & V_8 -> V_10 ) ;
V_9 = F_12 ( V_2 , V_4 ) ;
F_6 ( & V_8 -> V_10 ) ;
return V_9 ;
}
static void F_13 ( struct V_5 * V_6 )
{
T_1 V_11 , V_12 , V_13 , V_14 ;
V_11 = F_14 ( V_6 , V_15 ) ;
V_12 = F_14 ( V_6 , V_16 ) ;
V_13 = F_14 ( V_6 , V_17 ) ;
F_15 ( V_6 , V_15 , V_18 ,
V_18 ) ;
F_15 ( V_6 , V_15 ,
V_19 ,
V_19 ) ;
F_15 ( V_6 , V_16 ,
V_20 |
V_21 ,
V_20 ) ;
F_15 ( V_6 , V_17 ,
V_22 | V_23 ,
V_23 ) ;
F_15 ( V_6 , V_24 ,
V_25 ,
V_25 ) ;
do {
V_14 = F_14 ( V_6 , V_24 ) ;
} while ( V_14 & V_25 );
if ( V_14 & V_26 ) {
F_16 ( V_6 -> V_27 ,
L_1 ) ;
F_15 ( V_6 , V_24 ,
V_28 |
V_29 , 0 ) ;
} else {
F_15 ( V_6 , V_24 ,
V_28 |
V_29 ,
V_28 |
V_29 ) ;
}
F_17 ( V_6 , V_17 , V_13 ) ;
F_17 ( V_6 , V_16 , V_12 ) ;
F_17 ( V_6 , V_15 , V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
V_9 = F_8 ( V_2 , V_4 ) ;
if ( ( V_9 == 1 ) && ( V_8 -> V_30 ) )
F_13 ( V_6 ) ;
return V_9 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ( V_4 -> V_31 . integer . V_31 [ 0 ] ) && ( ! V_8 -> V_30 ) ) {
F_13 ( V_6 ) ;
V_8 -> V_30 = true ;
} else {
V_8 -> V_30 = false ;
}
return F_8 ( V_2 , V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_32 * V_33 =
(struct V_32 * ) V_2 -> V_34 ;
unsigned int V_35 = V_33 -> V_35 ;
T_2 V_36 ;
int V_9 ;
F_4 ( & V_8 -> V_10 ) ;
V_9 = F_21 ( V_8 -> V_37 , V_35 , & V_36 , sizeof( V_36 ) ) ;
F_6 ( & V_8 -> V_10 ) ;
if ( V_9 )
return V_9 ;
V_4 -> V_31 . integer . V_31 [ 0 ] = F_22 ( V_36 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_32 * V_33 =
(struct V_32 * ) V_2 -> V_34 ;
unsigned int V_35 = V_33 -> V_35 ;
T_2 V_36 ;
int V_9 ;
V_36 = F_24 ( V_4 -> V_31 . integer . V_31 [ 0 ] ) ;
F_4 ( & V_8 -> V_10 ) ;
V_9 = F_25 ( V_8 -> V_37 , V_35 , & V_36 , sizeof( V_36 ) ) ;
F_6 ( & V_8 -> V_10 ) ;
return V_9 ;
}
static int F_26 ( struct V_38 * V_39 ,
struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = F_27 ( V_39 -> V_41 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 , V_43 ;
int V_44 = 0 ;
bool V_45 = false ;
switch ( V_40 ) {
case V_46 :
if ( V_8 -> V_47 )
F_15 ( V_6 , V_48 ,
V_49 ,
V_49 ) ;
F_15 ( V_6 , V_50 ,
V_51 , 0 ) ;
V_42 = F_14 ( V_6 , V_52 ) ;
if ( ( V_42 & V_53 ) != V_54 )
return 0 ;
do {
V_43 = F_14 ( V_6 , V_55 ) ;
if ( V_43 & V_56 ) {
V_45 = true ;
} else {
++ V_44 ;
F_28 ( 50 ) ;
}
} while ( ( V_44 < V_57 ) && ( ! V_45 ) );
if ( ! V_45 )
F_16 ( V_6 -> V_27 , L_2 ) ;
return 0 ;
case V_58 :
F_15 ( V_6 , V_50 ,
V_51 ,
V_51 ) ;
if ( V_8 -> V_47 )
F_15 ( V_6 , V_48 ,
V_49 , 0 ) ;
return 0 ;
default:
return - V_59 ;
}
}
static int F_29 ( struct V_38 * V_39 ,
struct V_1 * V_2 , int V_40 )
{
switch ( V_40 ) {
case V_60 :
case V_58 :
F_28 ( V_61 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_30 ( struct V_38 * V_39 ,
struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = F_27 ( V_39 -> V_41 ) ;
T_1 V_62 , V_63 ;
switch ( V_39 -> V_35 ) {
case V_64 :
V_62 = V_65 ;
V_63 = V_66 ;
break;
case V_67 :
V_62 = V_68 ;
V_63 = V_69 ;
break;
default:
return - V_59 ;
}
switch ( V_40 ) {
case V_70 :
F_15 ( V_6 , V_62 , V_63 ,
V_63 ) ;
F_28 ( V_71 ) ;
break;
case V_60 :
F_15 ( V_6 , V_62 , V_63 , 0 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_38 * V_39 ,
struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = F_27 ( V_39 -> V_41 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_40 ) {
case V_46 :
case V_70 :
V_8 -> V_72 =
F_14 ( V_6 , V_73 ) ;
F_17 ( V_6 , V_73 ,
V_74 ) ;
break;
case V_60 :
case V_58 :
F_17 ( V_6 , V_73 ,
V_8 -> V_72 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_75 * V_76 ,
int V_77 , unsigned int V_78 , int V_79 )
{
struct V_5 * V_6 = V_76 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 = 0 ;
if ( ( V_8 -> V_80 == V_77 ) && ( V_8 -> V_81 == V_78 ) )
return 0 ;
if ( ( V_78 < 2000000 ) || ( V_78 > 54000000 ) ) {
F_33 ( V_76 -> V_27 , L_3 ,
V_78 ) ;
return - V_59 ;
}
switch ( V_77 ) {
case V_82 :
F_15 ( V_6 , V_52 ,
V_83 ,
V_83 ) ;
break;
case V_84 :
F_15 ( V_6 , V_52 ,
V_83 , 0 ) ;
break;
default:
F_33 ( V_76 -> V_27 , L_4 , V_77 ) ;
return - V_59 ;
}
V_8 -> V_80 = V_77 ;
if ( V_8 -> V_85 ) {
V_78 = F_34 ( V_8 -> V_85 , V_78 ) ;
V_9 = F_35 ( V_8 -> V_85 , V_78 ) ;
if ( V_9 ) {
F_33 ( V_76 -> V_27 , L_5 ,
V_78 ) ;
return V_9 ;
}
}
V_8 -> V_81 = V_78 ;
return 0 ;
}
static int F_36 ( struct V_75 * V_76 , int V_86 ,
int V_87 , unsigned int V_88 , unsigned int V_89 )
{
struct V_5 * V_6 = V_76 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 , V_90 , V_91 ;
T_1 V_92 , V_93 , V_94 ;
T_3 V_95 ;
T_4 V_96 ;
if ( V_8 -> V_81 < 2000000 ) {
F_33 ( V_6 -> V_27 , L_6 ,
V_8 -> V_81 ) ;
return - V_59 ;
} else if ( V_8 -> V_81 <= 4500000 ) {
V_90 = V_97 ;
V_91 = V_98 ;
} else if ( V_8 -> V_81 <= 9000000 ) {
V_90 = V_99 ;
V_91 = V_100 ;
} else if ( V_8 -> V_81 <= 18000000 ) {
V_90 = V_101 ;
V_91 = V_102 ;
} else if ( V_8 -> V_81 <= 36000000 ) {
V_90 = V_103 ;
V_91 = V_104 ;
} else if ( V_8 -> V_81 <= 54000000 ) {
V_90 = V_105 ;
V_91 = V_106 ;
} else {
F_33 ( V_6 -> V_27 , L_7 ,
V_8 -> V_81 ) ;
return - V_59 ;
}
V_95 = ( V_8 -> V_81 / V_91 ) ;
V_42 = V_90 ;
switch ( V_87 ) {
case V_107 :
V_42 |= V_108 ;
F_15 ( V_6 , V_52 ,
V_109 |
V_53 , V_42 ) ;
return 0 ;
case V_110 :
V_42 |= V_111 ;
break;
case V_112 :
V_42 |= V_54 ;
break;
default:
F_33 ( V_6 -> V_27 , L_8 ) ;
return - V_59 ;
}
V_94 = V_89 / V_95 ;
V_96 = ( T_4 ) ( V_89 % V_95 ) * 8192ULL ;
F_37 ( V_96 , V_95 ) ;
V_92 = ( V_96 >> V_113 ) & V_114 ;
V_93 = ( V_96 ) & V_114 ;
F_17 ( V_6 , V_115 , V_92 ) ;
F_17 ( V_6 , V_116 , V_93 ) ;
F_17 ( V_6 , V_117 , V_94 ) ;
F_15 ( V_6 , V_52 ,
V_109 | V_53 ,
V_42 ) ;
return 0 ;
}
static int F_38 ( struct V_75 * V_76 , unsigned int V_118 )
{
struct V_5 * V_6 = V_76 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_119 = 0 , V_120 = 0 ;
switch ( V_118 & V_121 ) {
case V_122 :
V_8 -> V_47 = true ;
break;
case V_123 :
V_8 -> V_47 = false ;
break;
default:
return - V_59 ;
}
switch ( V_118 & V_124 ) {
case V_125 :
case V_126 :
case V_127 :
switch ( V_118 & V_128 ) {
case V_129 :
break;
case V_130 :
V_119 |= V_131 ;
break;
case V_132 :
V_119 |= V_133 ;
break;
case V_134 :
V_119 |= V_131 |
V_133 ;
break;
default:
return - V_59 ;
}
break;
case V_135 :
switch ( V_118 & V_128 ) {
case V_129 :
V_119 |= V_133 ;
break;
case V_130 :
V_119 |= V_131 |
V_133 ;
break;
case V_132 :
break;
case V_134 :
V_119 |= V_131 ;
break;
default:
return - V_59 ;
}
break;
default:
return - V_59 ;
}
switch ( V_118 & V_124 ) {
case V_125 :
V_120 |= V_136 ;
break;
case V_126 :
V_120 |= V_137 ;
break;
case V_127 :
V_120 |= V_138 ;
break;
case V_135 :
V_120 |= V_139 ;
break;
default:
return - V_59 ;
}
V_119 |= V_140 ;
F_15 ( V_6 , V_48 ,
V_141 |
V_142 | V_143 ,
V_119 ) ;
F_15 ( V_6 , V_144 , V_145 ,
V_120 ) ;
return 0 ;
}
static int F_39 ( struct V_75 * V_146 ,
unsigned int V_147 , unsigned int V_148 ,
int V_149 , int V_150 )
{
struct V_5 * V_6 = V_146 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_151 ;
T_2 V_152 ;
T_3 V_153 ;
if ( ! V_147 ) {
F_15 ( V_6 , V_154 ,
V_155 |
V_156 , 0 ) ;
F_15 ( V_6 , V_48 ,
V_141 ,
V_140 ) ;
return 0 ;
}
if ( F_40 ( V_147 ) > V_157 ) {
F_33 ( V_6 -> V_27 , L_9 ,
V_157 ) ;
return - V_59 ;
}
if ( V_148 > V_158 ) {
F_33 ( V_6 -> V_27 , L_10 ,
V_158 ) ;
return - V_59 ;
}
V_153 = V_149 * V_150 ;
switch ( V_153 ) {
case 32 :
V_151 = V_159 ;
break;
case 64 :
V_151 = V_140 ;
break;
case 128 :
V_151 = V_160 ;
break;
case 256 :
V_151 = V_161 ;
break;
default:
F_33 ( V_6 -> V_27 , L_11 , V_153 ) ;
return - V_59 ;
}
F_15 ( V_6 , V_48 ,
V_141 ,
V_151 ) ;
V_152 = F_24 ( V_148 ) ;
F_41 ( V_8 -> V_37 , V_162 ,
& V_152 , sizeof( V_152 ) ) ;
F_15 ( V_6 , V_154 ,
V_155 |
V_156 ,
( V_147 << V_163 ) |
V_156 ) ;
return 0 ;
}
static int F_42 ( struct V_164 * V_165 ,
struct V_166 * V_167 ,
struct V_75 * V_146 )
{
struct V_5 * V_6 = V_146 -> V_6 ;
T_1 V_120 = 0 , V_168 ;
unsigned int V_169 ;
switch ( F_43 ( V_167 ) ) {
case 16 :
V_120 |= V_170 ;
break;
case 20 :
V_120 |= V_171 ;
break;
case 24 :
V_120 |= V_172 ;
break;
case 32 :
V_120 |= V_173 ;
break;
default:
return - V_59 ;
}
V_169 = F_44 ( V_167 ) ;
if ( ( V_169 < 1 ) || ( V_169 > V_174 ) ) {
F_33 ( V_6 -> V_27 ,
L_12 ,
V_174 ) ;
return - V_59 ;
}
V_120 |= V_169 << V_175 ;
switch ( F_45 ( V_167 ) ) {
case 8000 :
V_168 = V_176 ;
break;
case 11025 :
V_168 = V_177 ;
break;
case 12000 :
V_168 = V_178 ;
break;
case 16000 :
V_168 = V_179 ;
break;
case 22050 :
V_168 = V_180 ;
break;
case 24000 :
V_168 = V_181 ;
break;
case 32000 :
V_168 = V_182 ;
break;
case 44100 :
V_168 = V_183 ;
break;
case 48000 :
V_168 = V_184 ;
break;
case 88200 :
V_168 = V_185 ;
break;
case 96000 :
V_168 = V_186 ;
break;
default:
return - V_59 ;
}
F_15 ( V_6 , V_144 ,
V_187 |
V_188 ,
V_120 ) ;
F_17 ( V_6 , V_189 , V_168 ) ;
return 0 ;
}
static enum V_190
F_46 ( struct V_191 * V_27 , T_3 V_36 )
{
switch ( V_36 ) {
case 1600 :
return V_192 ;
case 1800 :
return V_193 ;
case 2000 :
return V_194 ;
case 2200 :
return V_195 ;
case 2400 :
return V_196 ;
case 2600 :
return V_197 ;
default:
F_16 ( V_27 , L_13 ) ;
return V_195 ;
}
}
static enum V_198
F_47 ( struct V_191 * V_27 , const char * V_199 )
{
if ( ! strcmp ( V_199 , L_14 ) ) {
return V_200 ;
} else if ( ! strcmp ( V_199 , L_15 ) ) {
return V_201 ;
} else if ( ! strcmp ( V_199 , L_16 ) ) {
return V_202 ;
} else {
F_16 ( V_27 , L_17 ) ;
return V_200 ;
}
}
static struct V_203 * F_48 ( struct V_5 * V_6 )
{
struct V_191 * V_27 = V_6 -> V_27 ;
struct V_203 * V_204 ;
const char * V_205 ;
T_3 V_206 ;
V_204 = F_49 ( V_27 , sizeof( * V_204 ) , V_207 ) ;
if ( ! V_204 )
return NULL ;
V_204 -> V_208 = F_50 ( V_27 , L_18 ) ;
if ( F_51 ( V_27 , L_19 , & V_206 ) >= 0 )
V_204 -> V_209 = F_46 ( V_27 , V_206 ) ;
else
V_204 -> V_209 = V_195 ;
if ( ! F_52 ( V_27 , L_20 , & V_205 ) )
V_204 -> V_210 = F_47 ( V_27 , V_205 ) ;
else
V_204 -> V_210 = V_200 ;
return V_204 ;
}
static int F_53 ( struct V_5 * V_6 ,
enum V_211 V_212 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
switch ( V_212 ) {
case V_213 :
break;
case V_214 :
if ( F_54 ( V_6 ) == V_215 ) {
if ( V_8 -> V_85 ) {
V_9 = F_55 ( V_8 -> V_85 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 ,
L_21 ) ;
return V_9 ;
}
}
}
break;
case V_215 :
if ( F_54 ( V_6 ) == V_216 )
F_15 ( V_6 , V_217 ,
V_218 ,
V_218 ) ;
if ( F_54 ( V_6 ) == V_214 ) {
if ( V_8 -> V_85 )
F_56 ( V_8 -> V_85 ) ;
}
break;
case V_216 :
if ( ! V_8 -> V_208 )
F_15 ( V_6 , V_217 ,
V_218 , 0 ) ;
break;
}
return 0 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_219 * V_220 ;
T_1 V_221 = V_222 ;
int V_44 , V_9 ;
for ( V_44 = 0 ; V_44 < V_223 ; ++ V_44 )
V_8 -> V_224 [ V_44 ] . V_225 = V_226 [ V_44 ] ;
V_9 = F_58 ( V_6 -> V_27 , V_223 ,
V_8 -> V_224 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_22 ) ;
return V_9 ;
}
V_220 = V_8 -> V_224 [ V_227 ] . V_228 ;
V_9 = F_59 ( V_220 ) ;
if ( V_9 < 1200000 )
F_16 ( V_6 -> V_27 , L_23 ) ;
else if ( V_9 < 2800000 )
V_221 = V_229 ;
V_9 = F_60 ( V_223 , V_8 -> V_224 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_24 ) ;
return V_9 ;
}
F_17 ( V_6 , V_230 , V_231 ) ;
F_17 ( V_6 , V_232 , V_221 ) ;
return 0 ;
}
static void F_61 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_203 * V_204 = V_8 -> V_204 ;
if ( V_204 ) {
T_1 V_209 = 0 ;
V_8 -> V_208 = V_204 -> V_208 ;
switch ( V_204 -> V_209 ) {
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
V_209 |= ( V_204 -> V_209 <<
V_233 ) ;
break;
}
F_17 ( V_6 , V_234 , V_209 ) ;
switch ( V_204 -> V_210 ) {
case V_200 :
case V_201 :
case V_202 :
F_17 ( V_6 , V_235 ,
V_204 -> V_210 ) ;
break;
}
}
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_236 ;
int V_9 ;
F_63 ( & V_8 -> V_10 ) ;
V_9 = F_57 ( V_6 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_64 ( V_8 -> V_37 , V_237 , & V_236 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_25 , V_9 ) ;
goto V_238;
}
switch ( V_236 & V_239 ) {
case 0 :
V_9 = F_65 ( V_8 -> V_37 , V_240 ,
F_66 ( V_240 ) ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_26 ,
V_9 ) ;
goto V_238;
}
break;
default:
break;
}
V_8 -> V_204 = F_67 ( V_6 -> V_27 ) ;
if ( ! V_8 -> V_204 )
V_8 -> V_204 = F_48 ( V_6 ) ;
F_61 ( V_6 ) ;
V_8 -> V_85 = F_68 ( V_6 -> V_27 , L_27 ) ;
if ( F_69 ( V_8 -> V_85 ) ) {
if ( F_70 ( V_8 -> V_85 ) != - V_241 ) {
V_9 = F_70 ( V_8 -> V_85 ) ;
goto V_238;
} else {
V_8 -> V_85 = NULL ;
}
}
F_15 ( V_6 , V_50 , V_51 ,
V_51 ) ;
F_15 ( V_6 , V_16 ,
V_242 ,
V_242 ) ;
F_15 ( V_6 , V_17 , V_243 ,
V_243 ) ;
F_15 ( V_6 , V_244 , V_245 ,
V_245 ) ;
F_15 ( V_6 , V_246 , V_247 ,
V_247 ) ;
F_15 ( V_6 , V_65 ,
V_248 ,
V_248 ) ;
F_15 ( V_6 , V_68 ,
V_249 ,
V_249 ) ;
F_15 ( V_6 , V_65 ,
V_66 ,
V_66 ) ;
F_15 ( V_6 , V_68 ,
V_69 ,
V_69 ) ;
F_17 ( V_6 , V_250 , V_251 ) ;
V_9 = F_71 ( V_6 ) ;
if ( V_9 )
goto V_238;
return 0 ;
V_238:
F_72 ( V_223 , V_8 -> V_224 ) ;
return V_9 ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_74 ( V_6 ) ;
return F_72 ( V_223 , V_8 -> V_224 ) ;
}
static int F_75 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ! V_8 -> V_208 )
F_76 ( V_6 ) ;
F_77 ( V_6 , V_216 ) ;
return 0 ;
}
static int F_78 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_77 ( V_6 , V_215 ) ;
if ( ! V_8 -> V_208 )
F_79 ( V_6 ) ;
return 0 ;
}
static bool F_80 ( struct V_191 * V_27 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_55 :
case V_24 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
return 1 ;
default:
return 0 ;
}
}
static int F_81 ( struct V_271 * V_272 ,
const struct V_273 * V_274 )
{
struct V_7 * V_8 ;
unsigned int V_275 , V_276 ;
int V_44 , V_9 ;
V_8 = F_49 ( & V_272 -> V_27 , sizeof( struct V_7 ) ,
V_207 ) ;
if ( ! V_8 )
return - V_277 ;
F_82 ( V_272 , V_8 ) ;
V_8 -> V_37 = F_83 ( V_272 , & V_278 ) ;
if ( F_69 ( V_8 -> V_37 ) ) {
V_9 = F_70 ( V_8 -> V_37 ) ;
F_33 ( & V_272 -> V_27 , L_28 , V_9 ) ;
return V_9 ;
}
F_84 ( V_8 -> V_37 , true ) ;
F_64 ( V_8 -> V_37 , V_230 , & V_275 ) ;
if ( V_275 ) {
F_85 ( V_8 -> V_37 , V_73 ,
V_74 ) ;
F_85 ( V_8 -> V_37 , V_260 , 0x00 ) ;
F_85 ( V_8 -> V_37 , V_261 , 0x01 ) ;
for ( V_44 = 0 ; V_44 < V_279 ; ++ V_44 ) {
F_64 ( V_8 -> V_37 , V_270 ,
& V_276 ) ;
if ( ! V_276 )
break;
F_28 ( V_280 ) ;
}
}
F_86 ( V_8 -> V_37 , V_281 ,
V_282 , 0 ) ;
F_86 ( V_8 -> V_37 , V_259 ,
V_283 ,
V_283 ) ;
F_86 ( V_8 -> V_37 , V_230 ,
V_231 , 0 ) ;
F_84 ( V_8 -> V_37 , false ) ;
V_9 = F_87 ( & V_272 -> V_27 , & V_284 ,
& V_285 , 1 ) ;
if ( V_9 < 0 ) {
F_33 ( & V_272 -> V_27 , L_29 ,
V_9 ) ;
}
return V_9 ;
}
static int F_88 ( struct V_271 * V_286 )
{
F_89 ( & V_286 -> V_27 ) ;
return 0 ;
}
