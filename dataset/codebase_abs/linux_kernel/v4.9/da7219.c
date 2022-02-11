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
static int F_29 ( struct V_60 * V_61 ,
int V_62 , unsigned int V_63 , int V_64 )
{
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 = 0 ;
if ( ( V_8 -> V_65 == V_62 ) && ( V_8 -> V_66 == V_63 ) )
return 0 ;
if ( ( V_63 < 2000000 ) || ( V_63 > 54000000 ) ) {
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
} else if ( V_8 -> V_66 <= 4500000 ) {
V_75 = V_82 ;
V_76 = V_83 ;
} else if ( V_8 -> V_66 <= 9000000 ) {
V_75 = V_84 ;
V_76 = V_85 ;
} else if ( V_8 -> V_66 <= 18000000 ) {
V_75 = V_86 ;
V_76 = V_87 ;
} else if ( V_8 -> V_66 <= 36000000 ) {
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
F_43 ( struct V_176 * V_27 , T_3 V_36 )
{
switch ( V_36 ) {
case 1600 :
return V_177 ;
case 1800 :
return V_178 ;
case 2000 :
return V_179 ;
case 2200 :
return V_180 ;
case 2400 :
return V_181 ;
case 2600 :
return V_182 ;
default:
F_16 ( V_27 , L_13 ) ;
return V_180 ;
}
}
static enum V_183
F_44 ( struct V_176 * V_27 , const char * V_184 )
{
if ( ! strcmp ( V_184 , L_14 ) ) {
return V_185 ;
} else if ( ! strcmp ( V_184 , L_15 ) ) {
return V_186 ;
} else if ( ! strcmp ( V_184 , L_16 ) ) {
return V_187 ;
} else {
F_16 ( V_27 , L_17 ) ;
return V_185 ;
}
}
static struct V_188 * F_45 ( struct V_5 * V_6 )
{
struct V_176 * V_27 = V_6 -> V_27 ;
struct V_188 * V_189 ;
const char * V_190 ;
T_3 V_191 ;
V_189 = F_46 ( V_27 , sizeof( * V_189 ) , V_192 ) ;
if ( ! V_189 )
return NULL ;
V_189 -> V_193 = F_47 ( V_27 , L_18 ) ;
if ( F_48 ( V_27 , L_19 , & V_191 ) >= 0 )
V_189 -> V_194 = F_43 ( V_27 , V_191 ) ;
else
V_189 -> V_194 = V_180 ;
if ( ! F_49 ( V_27 , L_20 , & V_190 ) )
V_189 -> V_195 = F_44 ( V_27 , V_190 ) ;
else
V_189 -> V_195 = V_185 ;
return V_189 ;
}
static int F_50 ( struct V_5 * V_6 ,
enum V_196 V_197 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 ;
switch ( V_197 ) {
case V_198 :
break;
case V_199 :
if ( F_51 ( V_6 ) == V_200 ) {
if ( V_8 -> V_70 ) {
V_9 = F_52 ( V_8 -> V_70 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 ,
L_21 ) ;
return V_9 ;
}
}
}
break;
case V_200 :
if ( F_51 ( V_6 ) == V_201 )
F_15 ( V_6 , V_202 ,
V_203 ,
V_203 ) ;
if ( F_51 ( V_6 ) == V_199 ) {
if ( V_8 -> V_70 )
F_53 ( V_8 -> V_70 ) ;
}
break;
case V_201 :
if ( ! V_8 -> V_193 )
F_15 ( V_6 , V_202 ,
V_203 , 0 ) ;
break;
}
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_204 * V_205 ;
T_1 V_206 = V_207 ;
int V_44 , V_9 ;
for ( V_44 = 0 ; V_44 < V_208 ; ++ V_44 )
V_8 -> V_209 [ V_44 ] . V_210 = V_211 [ V_44 ] ;
V_9 = F_55 ( V_6 -> V_27 , V_208 ,
V_8 -> V_209 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_22 ) ;
return V_9 ;
}
V_205 = V_8 -> V_209 [ V_212 ] . V_213 ;
V_9 = F_56 ( V_205 ) ;
if ( V_9 < 1200000 )
F_16 ( V_6 -> V_27 , L_23 ) ;
else if ( V_9 < 2800000 )
V_206 = V_214 ;
V_9 = F_57 ( V_208 , V_8 -> V_209 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_24 ) ;
return V_9 ;
}
F_17 ( V_6 , V_215 , V_216 ) ;
F_17 ( V_6 , V_217 , V_206 ) ;
return 0 ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_188 * V_189 = V_8 -> V_189 ;
if ( V_189 ) {
T_1 V_194 = 0 ;
V_8 -> V_193 = V_189 -> V_193 ;
switch ( V_189 -> V_194 ) {
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
V_194 |= ( V_189 -> V_194 <<
V_218 ) ;
break;
}
F_17 ( V_6 , V_219 , V_194 ) ;
switch ( V_189 -> V_195 ) {
case V_185 :
case V_186 :
case V_187 :
F_17 ( V_6 , V_220 ,
V_189 -> V_195 ) ;
break;
}
}
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_221 ;
int V_9 ;
F_60 ( & V_8 -> V_10 ) ;
V_9 = F_54 ( V_6 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_61 ( V_8 -> V_37 , V_222 , & V_221 ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_25 , V_9 ) ;
goto V_223;
}
switch ( V_221 & V_224 ) {
case 0 :
V_9 = F_62 ( V_8 -> V_37 , V_225 ,
F_63 ( V_225 ) ) ;
if ( V_9 ) {
F_30 ( V_6 -> V_27 , L_26 ,
V_9 ) ;
goto V_223;
}
break;
default:
break;
}
V_8 -> V_189 = F_64 ( V_6 -> V_27 ) ;
if ( ! V_8 -> V_189 )
V_8 -> V_189 = F_45 ( V_6 ) ;
F_58 ( V_6 ) ;
V_8 -> V_70 = F_65 ( V_6 -> V_27 , L_27 ) ;
if ( F_66 ( V_8 -> V_70 ) ) {
if ( F_67 ( V_8 -> V_70 ) != - V_226 ) {
V_9 = F_67 ( V_8 -> V_70 ) ;
goto V_223;
} else {
V_8 -> V_70 = NULL ;
}
}
F_15 ( V_6 , V_50 , V_51 ,
V_51 ) ;
F_15 ( V_6 , V_16 ,
V_227 ,
V_227 ) ;
F_15 ( V_6 , V_17 , V_228 ,
V_228 ) ;
F_15 ( V_6 , V_229 , V_230 ,
V_230 ) ;
F_15 ( V_6 , V_231 , V_232 ,
V_232 ) ;
F_15 ( V_6 , V_233 ,
V_234 ,
V_234 ) ;
F_15 ( V_6 , V_235 ,
V_236 ,
V_236 ) ;
F_17 ( V_6 , V_237 , V_238 ) ;
V_9 = F_68 ( V_6 ) ;
if ( V_9 )
goto V_223;
return 0 ;
V_223:
F_69 ( V_208 , V_8 -> V_209 ) ;
return V_9 ;
}
static int F_70 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_71 ( V_6 ) ;
return F_69 ( V_208 , V_8 -> V_209 ) ;
}
static int F_72 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ! V_8 -> V_193 )
F_73 ( V_6 ) ;
F_74 ( V_6 , V_201 ) ;
return 0 ;
}
static int F_75 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_74 ( V_6 , V_200 ) ;
if ( ! V_8 -> V_193 )
F_76 ( V_6 ) ;
return 0 ;
}
static bool F_77 ( struct V_176 * V_27 , unsigned int V_35 )
{
switch ( V_35 ) {
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_55 :
case V_24 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
return 1 ;
default:
return 0 ;
}
}
static int F_78 ( struct V_258 * V_259 ,
const struct V_260 * V_261 )
{
struct V_7 * V_8 ;
unsigned int V_262 , V_263 ;
int V_44 , V_9 ;
V_8 = F_46 ( & V_259 -> V_27 , sizeof( struct V_7 ) ,
V_192 ) ;
if ( ! V_8 )
return - V_264 ;
F_79 ( V_259 , V_8 ) ;
V_8 -> V_37 = F_80 ( V_259 , & V_265 ) ;
if ( F_66 ( V_8 -> V_37 ) ) {
V_9 = F_67 ( V_8 -> V_37 ) ;
F_30 ( & V_259 -> V_27 , L_28 , V_9 ) ;
return V_9 ;
}
F_81 ( V_8 -> V_37 , true ) ;
F_61 ( V_8 -> V_37 , V_215 , & V_262 ) ;
if ( V_262 ) {
F_82 ( V_8 -> V_37 , V_266 ,
V_267 ) ;
F_82 ( V_8 -> V_37 , V_247 , 0x00 ) ;
F_82 ( V_8 -> V_37 , V_248 , 0x01 ) ;
for ( V_44 = 0 ; V_44 < V_268 ; ++ V_44 ) {
F_61 ( V_8 -> V_37 , V_257 ,
& V_263 ) ;
if ( ! V_263 )
break;
F_28 ( V_269 ) ;
}
}
F_83 ( V_8 -> V_37 , V_270 ,
V_271 , 0 ) ;
F_83 ( V_8 -> V_37 , V_246 ,
V_272 ,
V_272 ) ;
F_83 ( V_8 -> V_37 , V_215 ,
V_216 , 0 ) ;
F_81 ( V_8 -> V_37 , false ) ;
V_9 = F_84 ( & V_259 -> V_27 , & V_273 ,
& V_274 , 1 ) ;
if ( V_9 < 0 ) {
F_30 ( & V_259 -> V_27 , L_29 ,
V_9 ) ;
}
return V_9 ;
}
static int F_85 ( struct V_258 * V_275 )
{
F_86 ( & V_275 -> V_27 ) ;
return 0 ;
}
