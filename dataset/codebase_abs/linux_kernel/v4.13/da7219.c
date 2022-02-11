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
} while ( ( V_44 < V_57 ) & ( ! V_45 ) );
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
F_4 ( & V_8 -> V_82 ) ;
switch ( V_77 ) {
case V_83 :
F_15 ( V_6 , V_52 ,
V_84 ,
V_84 ) ;
break;
case V_85 :
F_15 ( V_6 , V_52 ,
V_84 , 0 ) ;
break;
default:
F_33 ( V_76 -> V_27 , L_4 , V_77 ) ;
F_6 ( & V_8 -> V_82 ) ;
return - V_59 ;
}
V_8 -> V_80 = V_77 ;
if ( V_8 -> V_86 ) {
V_78 = F_34 ( V_8 -> V_86 , V_78 ) ;
V_9 = F_35 ( V_8 -> V_86 , V_78 ) ;
if ( V_9 ) {
F_33 ( V_76 -> V_27 , L_5 ,
V_78 ) ;
F_6 ( & V_8 -> V_82 ) ;
return V_9 ;
}
}
V_8 -> V_81 = V_78 ;
F_6 ( & V_8 -> V_82 ) ;
return 0 ;
}
int F_36 ( struct V_5 * V_6 , int V_87 , unsigned int V_88 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 , V_89 , V_90 ;
T_1 V_91 , V_92 , V_93 ;
T_3 V_94 ;
T_4 V_95 ;
if ( V_8 -> V_81 < 2000000 ) {
F_33 ( V_6 -> V_27 , L_6 ,
V_8 -> V_81 ) ;
return - V_59 ;
} else if ( V_8 -> V_81 <= 4500000 ) {
V_89 = V_96 ;
V_90 = V_97 ;
} else if ( V_8 -> V_81 <= 9000000 ) {
V_89 = V_98 ;
V_90 = V_99 ;
} else if ( V_8 -> V_81 <= 18000000 ) {
V_89 = V_100 ;
V_90 = V_101 ;
} else if ( V_8 -> V_81 <= 36000000 ) {
V_89 = V_102 ;
V_90 = V_103 ;
} else if ( V_8 -> V_81 <= 54000000 ) {
V_89 = V_104 ;
V_90 = V_105 ;
} else {
F_33 ( V_6 -> V_27 , L_7 ,
V_8 -> V_81 ) ;
return - V_59 ;
}
V_94 = ( V_8 -> V_81 / V_90 ) ;
V_42 = V_89 ;
switch ( V_87 ) {
case V_106 :
V_42 |= V_107 ;
F_15 ( V_6 , V_52 ,
V_108 |
V_53 , V_42 ) ;
return 0 ;
case V_109 :
V_42 |= V_110 ;
break;
case V_111 :
V_42 |= V_54 ;
break;
default:
F_33 ( V_6 -> V_27 , L_8 ) ;
return - V_59 ;
}
V_93 = V_88 / V_94 ;
V_95 = ( T_4 ) ( V_88 % V_94 ) * 8192ULL ;
F_37 ( V_95 , V_94 ) ;
V_91 = ( V_95 >> V_112 ) & V_113 ;
V_92 = ( V_95 ) & V_113 ;
F_17 ( V_6 , V_114 , V_91 ) ;
F_17 ( V_6 , V_115 , V_92 ) ;
F_17 ( V_6 , V_116 , V_93 ) ;
F_15 ( V_6 , V_52 ,
V_108 | V_53 ,
V_42 ) ;
return 0 ;
}
static int F_38 ( struct V_75 * V_76 , int V_117 ,
int V_87 , unsigned int V_118 , unsigned int V_88 )
{
struct V_5 * V_6 = V_76 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
F_4 ( & V_8 -> V_82 ) ;
V_9 = F_36 ( V_6 , V_87 , V_88 ) ;
F_6 ( & V_8 -> V_82 ) ;
return V_9 ;
}
static int F_39 ( struct V_75 * V_76 , unsigned int V_119 )
{
struct V_5 * V_6 = V_76 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_120 = 0 , V_121 = 0 ;
switch ( V_119 & V_122 ) {
case V_123 :
V_8 -> V_47 = true ;
break;
case V_124 :
V_8 -> V_47 = false ;
break;
default:
return - V_59 ;
}
switch ( V_119 & V_125 ) {
case V_126 :
case V_127 :
case V_128 :
switch ( V_119 & V_129 ) {
case V_130 :
break;
case V_131 :
V_120 |= V_132 ;
break;
case V_133 :
V_120 |= V_134 ;
break;
case V_135 :
V_120 |= V_132 |
V_134 ;
break;
default:
return - V_59 ;
}
break;
case V_136 :
switch ( V_119 & V_129 ) {
case V_130 :
V_120 |= V_134 ;
break;
case V_131 :
V_120 |= V_132 |
V_134 ;
break;
case V_133 :
break;
case V_135 :
V_120 |= V_132 ;
break;
default:
return - V_59 ;
}
break;
default:
return - V_59 ;
}
switch ( V_119 & V_125 ) {
case V_126 :
V_121 |= V_137 ;
break;
case V_127 :
V_121 |= V_138 ;
break;
case V_128 :
V_121 |= V_139 ;
break;
case V_136 :
V_121 |= V_140 ;
break;
default:
return - V_59 ;
}
V_120 |= V_141 ;
F_15 ( V_6 , V_48 ,
V_142 |
V_143 | V_144 ,
V_120 ) ;
F_15 ( V_6 , V_145 , V_146 ,
V_121 ) ;
return 0 ;
}
static int F_40 ( struct V_75 * V_147 ,
unsigned int V_148 , unsigned int V_149 ,
int V_150 , int V_151 )
{
struct V_5 * V_6 = V_147 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_152 ;
T_2 V_153 ;
T_3 V_154 ;
if ( ! V_148 ) {
F_15 ( V_6 , V_155 ,
V_156 |
V_157 , 0 ) ;
F_15 ( V_6 , V_48 ,
V_142 ,
V_141 ) ;
return 0 ;
}
if ( F_41 ( V_148 ) > V_158 ) {
F_33 ( V_6 -> V_27 , L_9 ,
V_158 ) ;
return - V_59 ;
}
if ( V_149 > V_159 ) {
F_33 ( V_6 -> V_27 , L_10 ,
V_159 ) ;
return - V_59 ;
}
V_154 = V_150 * V_151 ;
switch ( V_154 ) {
case 32 :
V_152 = V_160 ;
break;
case 64 :
V_152 = V_141 ;
break;
case 128 :
V_152 = V_161 ;
break;
case 256 :
V_152 = V_162 ;
break;
default:
F_33 ( V_6 -> V_27 , L_11 , V_154 ) ;
return - V_59 ;
}
F_15 ( V_6 , V_48 ,
V_142 ,
V_152 ) ;
V_153 = F_24 ( V_149 ) ;
F_42 ( V_8 -> V_37 , V_163 ,
& V_153 , sizeof( V_153 ) ) ;
F_15 ( V_6 , V_155 ,
V_156 |
V_157 ,
( V_148 << V_164 ) |
V_157 ) ;
return 0 ;
}
static int F_43 ( struct V_165 * V_166 ,
struct V_167 * V_168 ,
struct V_75 * V_147 )
{
struct V_5 * V_6 = V_147 -> V_6 ;
T_1 V_121 = 0 , V_169 ;
unsigned int V_170 ;
switch ( F_44 ( V_168 ) ) {
case 16 :
V_121 |= V_171 ;
break;
case 20 :
V_121 |= V_172 ;
break;
case 24 :
V_121 |= V_173 ;
break;
case 32 :
V_121 |= V_174 ;
break;
default:
return - V_59 ;
}
V_170 = F_45 ( V_168 ) ;
if ( ( V_170 < 1 ) || ( V_170 > V_175 ) ) {
F_33 ( V_6 -> V_27 ,
L_12 ,
V_175 ) ;
return - V_59 ;
}
V_121 |= V_170 << V_176 ;
switch ( F_46 ( V_168 ) ) {
case 8000 :
V_169 = V_177 ;
break;
case 11025 :
V_169 = V_178 ;
break;
case 12000 :
V_169 = V_179 ;
break;
case 16000 :
V_169 = V_180 ;
break;
case 22050 :
V_169 = V_181 ;
break;
case 24000 :
V_169 = V_182 ;
break;
case 32000 :
V_169 = V_183 ;
break;
case 44100 :
V_169 = V_184 ;
break;
case 48000 :
V_169 = V_185 ;
break;
case 88200 :
V_169 = V_186 ;
break;
case 96000 :
V_169 = V_187 ;
break;
default:
return - V_59 ;
}
F_15 ( V_6 , V_145 ,
V_188 |
V_189 ,
V_121 ) ;
F_17 ( V_6 , V_190 , V_169 ) ;
return 0 ;
}
static enum V_191
F_47 ( struct V_192 * V_27 , T_3 V_36 )
{
switch ( V_36 ) {
case 1600 :
return V_193 ;
case 1800 :
return V_194 ;
case 2000 :
return V_195 ;
case 2200 :
return V_196 ;
case 2400 :
return V_197 ;
case 2600 :
return V_198 ;
default:
F_16 ( V_27 , L_13 ) ;
return V_196 ;
}
}
static enum V_199
F_48 ( struct V_192 * V_27 , const char * V_200 )
{
if ( ! strcmp ( V_200 , L_14 ) ) {
return V_201 ;
} else if ( ! strcmp ( V_200 , L_15 ) ) {
return V_202 ;
} else if ( ! strcmp ( V_200 , L_16 ) ) {
return V_203 ;
} else {
F_16 ( V_27 , L_17 ) ;
return V_201 ;
}
}
static struct V_204 * F_49 ( struct V_5 * V_6 )
{
struct V_192 * V_27 = V_6 -> V_27 ;
struct V_204 * V_205 ;
const char * V_206 ;
T_3 V_207 ;
V_205 = F_50 ( V_27 , sizeof( * V_205 ) , V_208 ) ;
if ( ! V_205 )
return NULL ;
V_205 -> V_209 = F_51 ( V_27 , L_18 ) ;
if ( F_52 ( V_27 , L_19 , & V_207 ) >= 0 )
V_205 -> V_210 = F_47 ( V_27 , V_207 ) ;
else
V_205 -> V_210 = V_196 ;
if ( ! F_53 ( V_27 , L_20 , & V_206 ) )
V_205 -> V_211 = F_48 ( V_27 , V_206 ) ;
else
V_205 -> V_211 = V_201 ;
return V_205 ;
}
static int F_54 ( struct V_5 * V_6 ,
enum V_212 V_213 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
switch ( V_213 ) {
case V_214 :
break;
case V_215 :
if ( F_55 ( V_6 ) == V_216 ) {
if ( V_8 -> V_86 ) {
V_9 = F_56 ( V_8 -> V_86 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 ,
L_21 ) ;
return V_9 ;
}
}
}
break;
case V_216 :
if ( F_55 ( V_6 ) == V_217 )
F_15 ( V_6 , V_218 ,
V_219 ,
V_219 ) ;
if ( F_55 ( V_6 ) == V_215 ) {
if ( V_8 -> V_86 )
F_57 ( V_8 -> V_86 ) ;
}
break;
case V_217 :
if ( ! V_8 -> V_209 )
F_15 ( V_6 , V_218 ,
V_219 , 0 ) ;
break;
}
return 0 ;
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_220 * V_221 ;
T_1 V_222 = V_223 ;
int V_44 , V_9 ;
for ( V_44 = 0 ; V_44 < V_224 ; ++ V_44 )
V_8 -> V_225 [ V_44 ] . V_226 = V_227 [ V_44 ] ;
V_9 = F_59 ( V_6 -> V_27 , V_224 ,
V_8 -> V_225 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_22 ) ;
return V_9 ;
}
V_221 = V_8 -> V_225 [ V_228 ] . V_229 ;
V_9 = F_60 ( V_221 ) ;
if ( V_9 < 1200000 )
F_16 ( V_6 -> V_27 , L_23 ) ;
else if ( V_9 < 2800000 )
V_222 = V_230 ;
V_9 = F_61 ( V_224 , V_8 -> V_225 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_24 ) ;
return V_9 ;
}
F_17 ( V_6 , V_231 , V_232 ) ;
F_17 ( V_6 , V_233 , V_222 ) ;
return 0 ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_204 * V_205 = V_8 -> V_205 ;
if ( V_205 ) {
T_1 V_210 = 0 ;
V_8 -> V_209 = V_205 -> V_209 ;
switch ( V_205 -> V_210 ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
V_210 |= ( V_205 -> V_210 <<
V_234 ) ;
break;
}
F_17 ( V_6 , V_235 , V_210 ) ;
switch ( V_205 -> V_211 ) {
case V_201 :
case V_202 :
case V_203 :
F_17 ( V_6 , V_236 ,
V_205 -> V_211 ) ;
break;
}
}
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_237 ;
int V_9 ;
F_64 ( & V_8 -> V_10 ) ;
F_64 ( & V_8 -> V_82 ) ;
V_9 = F_58 ( V_6 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_65 ( V_8 -> V_37 , V_238 , & V_237 ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_25 , V_9 ) ;
goto V_239;
}
switch ( V_237 & V_240 ) {
case 0 :
V_9 = F_66 ( V_8 -> V_37 , V_241 ,
F_67 ( V_241 ) ) ;
if ( V_9 ) {
F_33 ( V_6 -> V_27 , L_26 ,
V_9 ) ;
goto V_239;
}
break;
default:
break;
}
V_8 -> V_205 = F_68 ( V_6 -> V_27 ) ;
if ( ! V_8 -> V_205 )
V_8 -> V_205 = F_49 ( V_6 ) ;
F_62 ( V_6 ) ;
V_8 -> V_86 = F_69 ( V_6 -> V_27 , L_27 ) ;
if ( F_70 ( V_8 -> V_86 ) ) {
if ( F_71 ( V_8 -> V_86 ) != - V_242 ) {
V_9 = F_71 ( V_8 -> V_86 ) ;
goto V_239;
} else {
V_8 -> V_86 = NULL ;
}
}
F_15 ( V_6 , V_50 , V_51 ,
V_51 ) ;
F_15 ( V_6 , V_16 ,
V_243 ,
V_243 ) ;
F_15 ( V_6 , V_17 , V_244 ,
V_244 ) ;
F_15 ( V_6 , V_245 , V_246 ,
V_246 ) ;
F_15 ( V_6 , V_247 , V_248 ,
V_248 ) ;
F_15 ( V_6 , V_65 ,
V_249 ,
V_249 ) ;
F_15 ( V_6 , V_68 ,
V_250 ,
V_250 ) ;
F_15 ( V_6 , V_65 ,
V_66 ,
V_66 ) ;
F_15 ( V_6 , V_68 ,
V_69 ,
V_69 ) ;
F_17 ( V_6 , V_251 , V_252 ) ;
V_9 = F_72 ( V_6 ) ;
if ( V_9 )
goto V_239;
return 0 ;
V_239:
F_73 ( V_224 , V_8 -> V_225 ) ;
return V_9 ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_75 ( V_6 ) ;
return F_73 ( V_224 , V_8 -> V_225 ) ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ! V_8 -> V_209 )
F_77 ( V_6 ) ;
F_78 ( V_6 , V_217 ) ;
return 0 ;
}
static int F_79 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_78 ( V_6 , V_216 ) ;
if ( ! V_8 -> V_209 )
F_80 ( V_6 ) ;
return 0 ;
}
static bool F_81 ( struct V_192 * V_27 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_55 :
case V_24 :
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
case V_271 :
return 1 ;
default:
return 0 ;
}
}
static int F_82 ( struct V_272 * V_273 ,
const struct V_274 * V_275 )
{
struct V_7 * V_8 ;
unsigned int V_276 , V_277 ;
int V_44 , V_9 ;
V_8 = F_50 ( & V_273 -> V_27 , sizeof( struct V_7 ) ,
V_208 ) ;
if ( ! V_8 )
return - V_278 ;
F_83 ( V_273 , V_8 ) ;
V_8 -> V_37 = F_84 ( V_273 , & V_279 ) ;
if ( F_70 ( V_8 -> V_37 ) ) {
V_9 = F_71 ( V_8 -> V_37 ) ;
F_33 ( & V_273 -> V_27 , L_28 , V_9 ) ;
return V_9 ;
}
F_85 ( V_8 -> V_37 , true ) ;
F_65 ( V_8 -> V_37 , V_231 , & V_276 ) ;
if ( V_276 ) {
F_86 ( V_8 -> V_37 , V_73 ,
V_74 ) ;
F_86 ( V_8 -> V_37 , V_261 , 0x00 ) ;
F_86 ( V_8 -> V_37 , V_262 , 0x01 ) ;
for ( V_44 = 0 ; V_44 < V_280 ; ++ V_44 ) {
F_65 ( V_8 -> V_37 , V_271 ,
& V_277 ) ;
if ( ! V_277 )
break;
F_28 ( V_281 ) ;
}
}
F_87 ( V_8 -> V_37 , V_282 ,
V_283 , 0 ) ;
F_87 ( V_8 -> V_37 , V_260 ,
V_284 ,
V_284 ) ;
F_87 ( V_8 -> V_37 , V_231 ,
V_232 , 0 ) ;
F_85 ( V_8 -> V_37 , false ) ;
V_9 = F_88 ( & V_273 -> V_27 , & V_285 ,
& V_286 , 1 ) ;
if ( V_9 < 0 ) {
F_33 ( & V_273 -> V_27 , L_29 ,
V_9 ) ;
}
return V_9 ;
}
static int F_89 ( struct V_272 * V_287 )
{
F_90 ( & V_287 -> V_27 ) ;
return 0 ;
}
