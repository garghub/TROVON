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
static int F_29 ( struct V_60 * V_61 ,
int V_62 , unsigned int V_63 , int V_64 )
{
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 = 0 ;
if ( ( V_8 -> V_65 == V_62 ) && ( V_8 -> V_66 == V_63 ) )
return 0 ;
if ( ( ( V_63 < 2000000 ) && ( V_63 != 32768 ) ) || ( V_63 > 54000000 ) ) {
F_30 ( V_61 -> V_27 , L_3 ,
V_63 ) ;
return - V_59 ;
}
switch ( V_62 ) {
case V_67 :
F_15 ( V_6 , V_52 ,
V_68 ,
V_68 ) ;
break;
case V_69 :
F_15 ( V_6 , V_52 ,
V_68 , 0 ) ;
break;
default:
F_30 ( V_61 -> V_27 , L_4 , V_62 ) ;
return - V_59 ;
}
V_8 -> V_65 = V_62 ;
if ( V_8 -> V_70 ) {
V_63 = F_31 ( V_8 -> V_70 , V_63 ) ;
V_9 = F_32 ( V_8 -> V_70 , V_63 ) ;
if ( V_9 ) {
F_30 ( V_61 -> V_27 , L_5 ,
V_63 ) ;
return V_9 ;
}
}
V_8 -> V_66 = V_63 ;
return 0 ;
}
static int F_33 ( struct V_60 * V_61 , int V_71 ,
int V_72 , unsigned int V_73 , unsigned int V_74 )
{
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_42 , V_75 , V_76 ;
T_1 V_77 , V_78 , V_79 ;
T_3 V_80 ;
T_4 V_81 ;
if ( V_8 -> V_66 < 2000000 ) {
F_30 ( V_6 -> V_27 , L_6 ,
V_8 -> V_66 ) ;
return - V_59 ;
} else if ( V_8 -> V_66 <= 5000000 ) {
V_75 = V_82 ;
V_76 = V_83 ;
} else if ( V_8 -> V_66 <= 10000000 ) {
V_75 = V_84 ;
V_76 = V_85 ;
} else if ( V_8 -> V_66 <= 20000000 ) {
V_75 = V_86 ;
V_76 = V_87 ;
} else if ( V_8 -> V_66 <= 40000000 ) {
V_75 = V_88 ;
V_76 = V_89 ;
} else if ( V_8 -> V_66 <= 54000000 ) {
V_75 = V_90 ;
V_76 = V_91 ;
} else {
F_30 ( V_6 -> V_27 , L_7 ,
V_8 -> V_66 ) ;
return - V_59 ;
}
V_80 = ( V_8 -> V_66 / V_76 ) ;
V_42 = V_75 ;
switch ( V_72 ) {
case V_92 :
V_42 |= V_93 ;
F_15 ( V_6 , V_52 ,
V_94 |
V_53 , V_42 ) ;
return 0 ;
case V_95 :
V_42 |= V_96 ;
break;
case V_97 :
V_42 |= V_54 ;
break;
default:
F_30 ( V_6 -> V_27 , L_8 ) ;
return - V_59 ;
}
V_79 = V_74 / V_80 ;
V_81 = ( T_4 ) ( V_74 % V_80 ) * 8192ULL ;
F_34 ( V_81 , V_80 ) ;
V_77 = ( V_81 >> V_98 ) & V_99 ;
V_78 = ( V_81 ) & V_99 ;
F_17 ( V_6 , V_100 , V_77 ) ;
F_17 ( V_6 , V_101 , V_78 ) ;
F_17 ( V_6 , V_102 , V_79 ) ;
F_15 ( V_6 , V_52 ,
V_94 | V_53 ,
V_42 ) ;
return 0 ;
}
static int F_35 ( struct V_60 * V_61 , unsigned int V_103 )
{
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_104 = 0 , V_105 = 0 ;
switch ( V_103 & V_106 ) {
case V_107 :
V_8 -> V_47 = true ;
break;
case V_108 :
V_8 -> V_47 = false ;
break;
default:
return - V_59 ;
}
switch ( V_103 & V_109 ) {
case V_110 :
case V_111 :
case V_112 :
switch ( V_103 & V_113 ) {
case V_114 :
break;
case V_115 :
V_104 |= V_116 ;
break;
case V_117 :
V_104 |= V_118 ;
break;
case V_119 :
V_104 |= V_116 |
V_118 ;
break;
default:
return - V_59 ;
}
break;
case V_120 :
switch ( V_103 & V_113 ) {
case V_114 :
V_104 |= V_118 ;
break;
case V_115 :
V_104 |= V_116 |
V_118 ;
break;
case V_117 :
break;
case V_119 :
V_104 |= V_116 ;
break;
default:
return - V_59 ;
}
break;
default:
return - V_59 ;
}
switch ( V_103 & V_109 ) {
case V_110 :
V_105 |= V_121 ;
break;
case V_111 :
V_105 |= V_122 ;
break;
case V_112 :
V_105 |= V_123 ;
break;
case V_120 :
V_105 |= V_124 ;
break;
default:
return - V_59 ;
}
V_104 |= V_125 ;
F_15 ( V_6 , V_48 ,
V_126 |
V_127 | V_128 ,
V_104 ) ;
F_15 ( V_6 , V_129 , V_130 ,
V_105 ) ;
return 0 ;
}
static int F_36 ( struct V_60 * V_131 ,
unsigned int V_132 , unsigned int V_133 ,
int V_134 , int V_135 )
{
struct V_5 * V_6 = V_131 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_136 ;
T_2 V_137 ;
T_3 V_138 ;
if ( ! V_132 ) {
F_15 ( V_6 , V_139 ,
V_140 |
V_141 , 0 ) ;
F_15 ( V_6 , V_48 ,
V_126 ,
V_125 ) ;
return 0 ;
}
if ( F_37 ( V_132 ) > V_142 ) {
F_30 ( V_6 -> V_27 , L_9 ,
V_142 ) ;
return - V_59 ;
}
if ( V_133 > V_143 ) {
F_30 ( V_6 -> V_27 , L_10 ,
V_143 ) ;
return - V_59 ;
}
V_138 = V_134 * V_135 ;
switch ( V_138 ) {
case 32 :
V_136 = V_144 ;
break;
case 64 :
V_136 = V_125 ;
break;
case 128 :
V_136 = V_145 ;
break;
case 256 :
V_136 = V_146 ;
break;
default:
F_30 ( V_6 -> V_27 , L_11 , V_138 ) ;
return - V_59 ;
}
F_15 ( V_6 , V_48 ,
V_126 ,
V_136 ) ;
V_137 = F_24 ( V_133 ) ;
F_38 ( V_8 -> V_37 , V_147 ,
& V_137 , sizeof( V_137 ) ) ;
F_15 ( V_6 , V_139 ,
V_140 |
V_141 ,
( V_132 << V_148 ) |
V_141 ) ;
return 0 ;
}
static int F_39 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
struct V_60 * V_131 )
{
struct V_5 * V_6 = V_131 -> V_6 ;
T_1 V_105 = 0 , V_153 ;
unsigned int V_154 ;
switch ( F_40 ( V_152 ) ) {
case 16 :
V_105 |= V_155 ;
break;
case 20 :
V_105 |= V_156 ;
break;
case 24 :
V_105 |= V_157 ;
break;
case 32 :
V_105 |= V_158 ;
break;
default:
return - V_59 ;
}
V_154 = F_41 ( V_152 ) ;
if ( ( V_154 < 1 ) || ( V_154 > V_159 ) ) {
F_30 ( V_6 -> V_27 ,
L_12 ,
V_159 ) ;
return - V_59 ;
}
V_105 |= V_154 << V_160 ;
switch ( F_42 ( V_152 ) ) {
case 8000 :
V_153 = V_161 ;
break;
case 11025 :
V_153 = V_162 ;
break;
case 12000 :
V_153 = V_163 ;
break;
case 16000 :
V_153 = V_164 ;
break;
case 22050 :
V_153 = V_165 ;
break;
case 24000 :
V_153 = V_166 ;
break;
case 32000 :
V_153 = V_167 ;
break;
case 44100 :
V_153 = V_168 ;
break;
case 48000 :
V_153 = V_169 ;
break;
case 88200 :
V_153 = V_170 ;
break;
case 96000 :
V_153 = V_171 ;
break;
default:
return - V_59 ;
}
F_15 ( V_6 , V_129 ,
V_172 |
V_173 ,
V_105 ) ;
F_17 ( V_6 , V_174 , V_153 ) ;
return 0 ;
}
static enum V_175
F_43 ( struct V_5 * V_6 , T_3 V_36 )
{
switch ( V_36 ) {
case 1600 :
return V_176 ;
case 1800 :
return V_177 ;
case 2000 :
return V_178 ;
case 2200 :
return V_179 ;
case 2400 :
return V_180 ;
case 2600 :
return V_181 ;
default:
F_16 ( V_6 -> V_27 , L_13 ) ;
return V_179 ;
}
}
static enum V_182
F_44 ( struct V_5 * V_6 , const char * V_183 )
{
if ( ! strcmp ( V_183 , L_14 ) ) {
return V_184 ;
} else if ( ! strcmp ( V_183 , L_15 ) ) {
return V_185 ;
} else if ( ! strcmp ( V_183 , L_16 ) ) {
return V_186 ;
} else {
F_16 ( V_6 -> V_27 , L_17 ) ;
return V_184 ;
}
}
static struct V_187 * F_45 ( struct V_5 * V_6 )
{
struct V_188 * V_189 = V_6 -> V_27 -> V_190 ;
struct V_187 * V_191 ;
const char * V_192 ;
T_3 V_193 ;
V_191 = F_46 ( V_6 -> V_27 , sizeof( * V_191 ) , V_194 ) ;
if ( ! V_191 )
return NULL ;
if ( F_47 ( V_189 , L_18 , & V_193 ) >= 0 )
V_191 -> V_195 = F_43 ( V_6 , V_193 ) ;
else
V_191 -> V_195 = V_179 ;
if ( ! F_48 ( V_189 , L_19 , & V_192 ) )
V_191 -> V_196 = F_44 ( V_6 , V_192 ) ;
else
V_191 -> V_196 = V_184 ;
return V_191 ;
}
static int F_49 ( struct V_5 * V_6 ,
enum V_197 V_198 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
switch ( V_198 ) {
case V_199 :
case V_200 :
break;
case V_201 :
if ( F_50 ( V_6 ) == V_202 ) {
if ( V_8 -> V_70 ) {
V_9 = F_51 ( V_8 -> V_70 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 ,
L_20 ) ;
return V_9 ;
}
}
F_15 ( V_6 , V_203 ,
V_204 ,
V_204 ) ;
}
break;
case V_202 :
if ( ! V_8 -> V_205 -> V_206 )
F_15 ( V_6 , V_203 ,
V_204 , 0 ) ;
if ( V_8 -> V_70 )
F_52 ( V_8 -> V_70 ) ;
break;
}
return 0 ;
}
static int F_53 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_207 * V_208 ;
T_1 V_209 = V_210 ;
int V_44 , V_9 ;
for ( V_44 = 0 ; V_44 < V_211 ; ++ V_44 )
V_8 -> V_212 [ V_44 ] . V_213 = V_214 [ V_44 ] ;
V_9 = F_54 ( V_6 -> V_27 , V_211 ,
V_8 -> V_212 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_21 ) ;
return V_9 ;
}
V_208 = V_8 -> V_212 [ V_215 ] . V_216 ;
V_9 = F_55 ( V_208 ) ;
if ( V_9 < 1200000 )
F_16 ( V_6 -> V_27 , L_22 ) ;
else if ( V_9 < 2800000 )
V_209 = V_217 ;
V_9 = F_56 ( V_211 , V_8 -> V_212 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_23 ) ;
return V_9 ;
}
F_17 ( V_6 , V_218 , V_219 ) ;
F_17 ( V_6 , V_220 , V_209 ) ;
return 0 ;
}
static void F_57 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_187 * V_191 = V_8 -> V_191 ;
if ( V_191 ) {
T_1 V_195 = 0 ;
switch ( V_191 -> V_195 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_195 |= ( V_191 -> V_195 <<
V_221 ) ;
break;
}
F_17 ( V_6 , V_222 , V_195 ) ;
switch ( V_191 -> V_196 ) {
case V_184 :
case V_185 :
case V_186 :
F_17 ( V_6 , V_223 ,
V_191 -> V_196 ) ;
break;
}
}
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_224 ;
int V_9 ;
F_59 ( & V_8 -> V_10 ) ;
V_9 = F_53 ( V_6 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_60 ( V_8 -> V_37 , V_225 , & V_224 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_24 , V_9 ) ;
goto V_226;
}
switch ( V_224 & V_227 ) {
case 0 :
V_9 = F_61 ( V_8 -> V_37 , V_228 ,
F_62 ( V_228 ) ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_25 ,
V_9 ) ;
goto V_226;
}
break;
default:
break;
}
if ( V_6 -> V_27 -> V_190 )
V_8 -> V_191 = F_45 ( V_6 ) ;
else
V_8 -> V_191 = F_63 ( V_6 -> V_27 ) ;
F_57 ( V_6 ) ;
V_8 -> V_70 = F_64 ( V_6 -> V_27 , L_26 ) ;
if ( F_65 ( V_8 -> V_70 ) ) {
if ( F_66 ( V_8 -> V_70 ) != - V_229 ) {
V_9 = F_66 ( V_8 -> V_70 ) ;
goto V_226;
} else {
V_8 -> V_70 = NULL ;
}
}
F_15 ( V_6 , V_50 , V_51 ,
V_51 ) ;
F_15 ( V_6 , V_16 ,
V_230 ,
V_230 ) ;
F_15 ( V_6 , V_17 , V_231 ,
V_231 ) ;
F_15 ( V_6 , V_232 , V_233 ,
V_233 ) ;
F_15 ( V_6 , V_234 , V_235 ,
V_235 ) ;
F_15 ( V_6 , V_236 ,
V_237 ,
V_237 ) ;
F_15 ( V_6 , V_238 ,
V_239 ,
V_239 ) ;
F_17 ( V_6 , V_240 , V_241 ) ;
V_9 = F_67 ( V_6 ) ;
if ( V_9 )
goto V_226;
return 0 ;
V_226:
F_68 ( V_211 , V_8 -> V_212 ) ;
return V_9 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_70 ( V_6 ) ;
return F_68 ( V_211 , V_8 -> V_212 ) ;
}
static int F_71 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_72 ( V_6 , V_202 ) ;
if ( ! V_8 -> V_205 -> V_206 )
F_17 ( V_6 , V_218 , 0 ) ;
return 0 ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ! V_8 -> V_205 -> V_206 )
F_17 ( V_6 , V_218 ,
V_219 ) ;
F_72 ( V_6 , V_201 ) ;
return 0 ;
}
static bool F_74 ( struct V_242 * V_27 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_55 :
case V_24 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
return 1 ;
default:
return 0 ;
}
}
static int F_75 ( struct V_262 * V_263 ,
const struct V_264 * V_265 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_46 ( & V_263 -> V_27 , sizeof( struct V_7 ) ,
V_194 ) ;
if ( ! V_8 )
return - V_266 ;
F_76 ( V_263 , V_8 ) ;
V_8 -> V_37 = F_77 ( V_263 , & V_267 ) ;
if ( F_65 ( V_8 -> V_37 ) ) {
V_9 = F_66 ( V_8 -> V_37 ) ;
F_30 ( & V_263 -> V_27 , L_27 , V_9 ) ;
return V_9 ;
}
V_9 = F_78 ( & V_263 -> V_27 , & V_268 ,
& V_269 , 1 ) ;
if ( V_9 < 0 ) {
F_30 ( & V_263 -> V_27 , L_28 ,
V_9 ) ;
}
return V_9 ;
}
static int F_79 ( struct V_262 * V_270 )
{
F_80 ( & V_270 -> V_27 ) ;
return 0 ;
}
