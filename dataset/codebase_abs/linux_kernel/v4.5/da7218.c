static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
T_1 V_5 , V_6 ;
T_1 V_7 , V_8 , V_9 , V_10 ;
T_1 V_11 , V_12 ;
T_1 V_13 ;
int V_14 = 0 ;
bool V_15 = false ;
V_3 = F_2 ( V_2 , V_16 ) ;
V_4 = F_2 ( V_2 , V_17 ) ;
V_5 = F_2 ( V_2 , V_18 ) ;
V_6 = F_2 ( V_2 , V_19 ) ;
V_7 = F_2 ( V_2 , V_20 ) ;
V_8 = F_2 ( V_2 , V_21 ) ;
V_9 = F_2 ( V_2 , V_22 ) ;
V_10 = F_2 ( V_2 , V_23 ) ;
V_11 = F_2 ( V_2 , V_24 ) ;
V_12 = F_2 ( V_2 , V_25 ) ;
F_3 ( V_2 , V_16 , V_26 ,
V_26 ) ;
F_3 ( V_2 , V_17 , V_27 ,
V_27 ) ;
F_3 ( V_2 , V_16 ,
V_28 ,
V_28 ) ;
F_3 ( V_2 , V_17 ,
V_29 ,
V_29 ) ;
F_3 ( V_2 , V_18 ,
V_30 |
V_31 ,
V_30 ) ;
F_3 ( V_2 , V_19 ,
V_32 |
V_33 ,
V_32 ) ;
F_3 ( V_2 , V_20 ,
V_34 |
V_35 ,
V_34 ) ;
F_3 ( V_2 , V_21 ,
V_36 |
V_37 ,
V_36 ) ;
F_3 ( V_2 , V_22 ,
V_38 |
V_39 ,
V_38 ) ;
F_3 ( V_2 , V_23 ,
V_40 |
V_41 ,
V_40 ) ;
F_3 ( V_2 , V_24 ,
V_42 , 0 ) ;
F_3 ( V_2 , V_25 ,
V_43 , 0 ) ;
F_3 ( V_2 , V_44 , V_45 ,
V_45 ) ;
do {
V_13 = F_2 ( V_2 , V_44 ) ;
if ( V_13 & V_45 ) {
++ V_14 ;
F_4 ( V_46 ,
V_47 ) ;
} else {
V_15 = true ;
}
} while ( ( V_14 < V_48 ) && ( ! V_15 ) );
if ( ( ! V_15 ) || ( V_13 & V_49 ) ) {
F_5 ( V_2 -> V_50 ,
L_1 ,
( V_15 ) ? L_2 : L_3 ) ;
F_3 ( V_2 , V_44 ,
V_51 , 0 ) ;
F_3 ( V_2 , V_52 ,
V_53 , 0 ) ;
} else {
F_3 ( V_2 , V_44 ,
V_51 ,
V_51 ) ;
F_3 ( V_2 , V_52 ,
V_53 ,
V_54 |
V_55 ) ;
}
F_6 ( V_2 , V_24 , V_11 ) ;
F_6 ( V_2 , V_25 , V_12 ) ;
F_6 ( V_2 , V_20 , V_7 ) ;
F_6 ( V_2 , V_21 , V_8 ) ;
F_6 ( V_2 , V_22 , V_9 ) ;
F_6 ( V_2 , V_23 , V_10 ) ;
F_6 ( V_2 , V_18 , V_5 ) ;
F_6 ( V_2 , V_19 , V_6 ) ;
F_6 ( V_2 , V_16 , V_3 ) ;
F_6 ( V_2 , V_17 , V_4 ) ;
}
static int F_7 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
int V_62 ;
V_62 = F_10 ( V_57 , V_59 ) ;
if ( ( V_62 == 1 ) && ( V_61 -> V_63 ) )
F_1 ( V_2 ) ;
return V_62 ;
}
static int F_11 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_64 * V_65 =
(struct V_64 * ) V_57 -> V_66 ;
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
unsigned int V_67 = V_59 -> V_68 . integer . V_68 [ 0 ] ;
unsigned int V_69 = V_59 -> V_68 . integer . V_68 [ 1 ] ;
unsigned int V_70 = V_65 -> V_71 ;
unsigned int V_72 = V_65 -> V_72 ;
unsigned int V_73 = ( V_65 -> V_74 << V_70 ) | ( V_65 -> V_74 << V_72 ) ;
if ( ( V_67 || V_69 ) && ( ! V_61 -> V_63 ) )
F_1 ( V_2 ) ;
V_61 -> V_63 &= ~ V_73 ;
V_61 -> V_63 |= ( V_67 << V_70 ) | ( V_69 << V_72 ) ;
return F_10 ( V_57 , V_59 ) ;
}
static int F_12 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_64 * V_75 =
(struct V_64 * ) V_57 -> V_66 ;
unsigned int V_76 = V_75 -> V_76 ;
T_2 V_77 ;
int V_62 ;
V_62 = F_13 ( V_61 -> V_78 , V_76 , & V_77 , 2 ) ;
if ( V_62 )
return V_62 ;
V_59 -> V_68 . integer . V_68 [ 0 ] = F_14 ( V_77 ) ;
return 0 ;
}
static int F_15 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_64 * V_75 =
(struct V_64 * ) V_57 -> V_66 ;
unsigned int V_76 = V_75 -> V_76 ;
T_2 V_77 ;
V_77 = F_16 ( V_59 -> V_68 . integer . V_68 [ 0 ] ) ;
return F_17 ( V_61 -> V_78 , V_76 , & V_77 , 2 ) ;
}
static int F_18 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_64 * V_75 =
(struct V_64 * ) V_57 -> V_66 ;
unsigned int V_67 = V_59 -> V_68 . integer . V_68 [ 0 ] ;
unsigned int V_69 = V_59 -> V_68 . integer . V_68 [ 1 ] ;
unsigned int V_70 = V_75 -> V_71 ;
unsigned int V_72 = V_75 -> V_72 ;
unsigned int V_73 = ( V_75 -> V_74 << V_70 ) |
( V_75 -> V_74 << V_72 ) ;
V_61 -> V_79 &= ~ V_73 ;
V_61 -> V_79 |= ( V_67 << V_70 ) | ( V_69 << V_72 ) ;
return F_6 ( V_2 , V_75 -> V_76 ,
( V_61 -> V_80 & V_61 -> V_79 ) ) ;
}
static int F_19 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_64 * V_75 =
(struct V_64 * ) V_57 -> V_66 ;
unsigned int V_70 = V_75 -> V_71 ;
unsigned int V_72 = V_75 -> V_72 ;
unsigned int V_81 = ( V_75 -> V_74 << V_70 ) ;
unsigned int V_82 = ( V_75 -> V_74 << V_72 ) ;
V_59 -> V_68 . integer . V_68 [ 0 ] =
( V_61 -> V_79 & V_81 ) >> V_70 ;
V_59 -> V_68 . integer . V_68 [ 1 ] =
( V_61 -> V_79 & V_82 ) >> V_72 ;
return 0 ;
}
static int F_20 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_83 * V_84 =
(struct V_83 * ) V_57 -> V_66 ;
switch ( V_84 -> V_74 ) {
case V_85 :
memcpy ( V_59 -> V_68 . V_86 . V_87 , V_61 -> V_88 ,
V_84 -> V_74 ) ;
break;
case V_89 :
memcpy ( V_59 -> V_68 . V_86 . V_87 , V_61 -> V_90 ,
V_84 -> V_74 ) ;
break;
default:
return - V_91 ;
}
return 0 ;
}
static int F_21 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_8 ( V_57 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_83 * V_84 =
(struct V_83 * ) V_57 -> V_66 ;
T_1 V_76 , V_92 ;
T_1 V_93 [ V_94 ] ;
int V_14 ;
switch ( V_84 -> V_74 ) {
case V_85 :
V_76 = V_95 ;
memcpy ( V_61 -> V_88 , V_59 -> V_68 . V_86 . V_87 ,
V_84 -> V_74 ) ;
break;
case V_89 :
V_76 = V_96 ;
memcpy ( V_61 -> V_90 , V_59 -> V_68 . V_86 . V_87 ,
V_84 -> V_74 ) ;
break;
default:
return - V_91 ;
}
V_92 = F_2 ( V_2 , V_97 ) ;
F_6 ( V_2 , V_97 ,
V_92 | V_98 ) ;
for ( V_14 = 0 ; V_14 < V_84 -> V_74 ; ++ V_14 ) {
V_93 [ V_99 ] = V_59 -> V_68 . V_86 . V_87 [ V_14 ] ;
V_93 [ V_100 ] = V_14 ;
F_17 ( V_61 -> V_78 , V_76 , V_93 , V_94 ) ;
}
F_6 ( V_2 , V_97 , V_92 ) ;
return 0 ;
}
static int F_22 ( struct V_101 * V_102 ,
struct V_56 * V_57 , int V_103 )
{
struct V_1 * V_2 = F_23 ( V_102 -> V_104 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
T_1 V_73 ;
switch ( V_102 -> V_76 ) {
case V_20 :
V_73 = ( 1 << V_105 ) ;
break;
case V_21 :
V_73 = ( 1 << V_106 ) ;
break;
case V_22 :
V_73 = ( 1 << V_107 ) ;
break;
case V_23 :
V_73 = ( 1 << V_108 ) ;
break;
default:
return - V_91 ;
}
switch ( V_103 ) {
case V_109 :
V_61 -> V_80 |= V_73 ;
if ( V_73 & V_61 -> V_79 )
F_24 ( V_110 ) ;
break;
case V_111 :
V_61 -> V_80 &= ~ V_73 ;
break;
default:
return - V_91 ;
}
F_6 ( V_2 , V_112 ,
( V_61 -> V_80 & V_61 -> V_79 ) ) ;
return 0 ;
}
static int F_25 ( struct V_101 * V_102 ,
struct V_56 * V_57 , int V_103 )
{
struct V_1 * V_2 = F_23 ( V_102 -> V_104 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
T_1 V_113 , V_114 , V_115 ;
int V_14 ;
bool V_116 ;
switch ( V_103 ) {
case V_109 :
if ( V_61 -> V_117 )
F_3 ( V_2 , V_118 ,
V_119 ,
V_119 ) ;
F_6 ( V_2 , V_120 ,
V_121 ) ;
F_6 ( V_2 , V_120 ,
V_121 |
V_122 ) ;
V_14 = 0 ;
V_116 = false ;
do {
V_115 = F_2 ( V_2 , V_120 ) ;
if ( ! ( V_115 & V_121 ) ) {
V_116 = true ;
} else {
++ V_14 ;
F_4 ( V_123 ,
V_124 ) ;
}
} while ( ( V_14 < V_125 ) && ( ! V_116 ) );
if ( ! V_116 )
F_5 ( V_2 -> V_50 ,
L_4 ) ;
F_6 ( V_2 , V_126 ,
V_127 ) ;
V_113 = F_2 ( V_2 , V_128 ) ;
if ( ( V_113 & V_129 ) != V_130 )
return 0 ;
V_14 = 0 ;
V_116 = false ;
do {
V_114 = F_2 ( V_2 , V_131 ) ;
if ( V_114 & V_132 ) {
V_116 = true ;
} else {
++ V_14 ;
F_24 ( V_133 ) ;
}
} while ( ( V_14 < V_134 ) & ( ! V_116 ) );
if ( ! V_116 )
F_5 ( V_2 -> V_50 , L_5 ) ;
return 0 ;
case V_135 :
F_6 ( V_2 , V_126 , V_136 ) ;
if ( V_61 -> V_117 )
F_3 ( V_2 , V_118 ,
V_119 , 0 ) ;
return 0 ;
default:
return - V_91 ;
}
}
static int F_26 ( struct V_101 * V_102 ,
struct V_56 * V_57 , int V_103 )
{
struct V_1 * V_2 = F_23 ( V_102 -> V_104 ) ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
if ( V_61 -> V_137 )
return 0 ;
switch ( V_103 ) {
case V_138 :
F_3 ( V_2 , V_139 , V_140 ,
V_140 ) ;
return 0 ;
case V_111 :
F_3 ( V_2 , V_139 , V_140 ,
0 ) ;
return 0 ;
default:
return - V_91 ;
}
}
static int F_27 ( struct V_101 * V_102 ,
struct V_56 * V_57 , int V_103 )
{
struct V_1 * V_2 = F_23 ( V_102 -> V_104 ) ;
switch ( V_103 ) {
case V_109 :
F_3 ( V_2 , V_102 -> V_76 , V_141 ,
V_141 ) ;
return 0 ;
case V_111 :
F_3 ( V_2 , V_102 -> V_76 , V_141 , 0 ) ;
return 0 ;
default:
return - V_91 ;
}
}
static int F_28 ( struct V_142 * V_143 ,
int V_144 , unsigned int V_145 , int V_146 )
{
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
int V_62 ;
if ( V_61 -> V_147 == V_145 )
return 0 ;
if ( ( ( V_145 < 2000000 ) && ( V_145 != 32768 ) ) || ( V_145 > 54000000 ) ) {
F_29 ( V_143 -> V_50 , L_6 ,
V_145 ) ;
return - V_91 ;
}
switch ( V_144 ) {
case V_148 :
F_3 ( V_2 , V_128 ,
V_149 ,
V_149 ) ;
break;
case V_150 :
F_3 ( V_2 , V_128 ,
V_149 , 0 ) ;
break;
default:
F_29 ( V_143 -> V_50 , L_7 , V_144 ) ;
return - V_91 ;
}
if ( V_61 -> V_151 ) {
V_145 = F_30 ( V_61 -> V_151 , V_145 ) ;
V_62 = F_31 ( V_61 -> V_151 , V_145 ) ;
if ( V_62 ) {
F_29 ( V_143 -> V_50 , L_8 ,
V_145 ) ;
return V_62 ;
}
}
V_61 -> V_147 = V_145 ;
return 0 ;
}
static int F_32 ( struct V_142 * V_143 , int V_152 ,
int V_153 , unsigned int V_154 , unsigned int V_155 )
{
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
T_1 V_113 , V_156 , V_157 ;
T_1 V_158 , V_159 , V_160 ;
T_3 V_161 ;
T_4 V_162 ;
if ( V_61 -> V_147 == 32768 ) {
V_156 = V_163 ;
V_157 = V_164 ;
} else if ( V_61 -> V_147 < 2000000 ) {
F_29 ( V_2 -> V_50 , L_9 ,
V_61 -> V_147 ) ;
return - V_91 ;
} else if ( V_61 -> V_147 <= 5000000 ) {
V_156 = V_163 ;
V_157 = V_164 ;
} else if ( V_61 -> V_147 <= 10000000 ) {
V_156 = V_165 ;
V_157 = V_164 ;
} else if ( V_61 -> V_147 <= 20000000 ) {
V_156 = V_166 ;
V_157 = V_167 ;
} else if ( V_61 -> V_147 <= 40000000 ) {
V_156 = V_168 ;
V_157 = V_169 ;
} else if ( V_61 -> V_147 <= 54000000 ) {
V_156 = V_170 ;
V_157 = V_171 ;
} else {
F_29 ( V_2 -> V_50 , L_10 ,
V_61 -> V_147 ) ;
return - V_91 ;
}
V_161 = ( V_61 -> V_147 / V_157 ) ;
V_113 = V_156 ;
switch ( V_153 ) {
case V_172 :
V_113 |= V_173 ;
F_3 ( V_2 , V_128 ,
V_174 |
V_129 , V_113 ) ;
return 0 ;
case V_175 :
V_113 |= V_176 ;
break;
case V_177 :
V_113 |= V_130 ;
break;
case V_178 :
V_113 |= V_179 ;
break;
default:
F_29 ( V_2 -> V_50 , L_11 ) ;
return - V_91 ;
}
V_160 = V_155 / V_161 ;
V_162 = ( T_4 ) ( V_155 % V_161 ) * 8192ULL ;
F_33 ( V_162 , V_161 ) ;
V_158 = ( V_162 >> V_180 ) & V_181 ;
V_159 = ( V_162 ) & V_181 ;
F_6 ( V_2 , V_182 , V_158 ) ;
F_6 ( V_2 , V_183 , V_159 ) ;
F_6 ( V_2 , V_184 , V_160 ) ;
F_3 ( V_2 , V_128 ,
V_129 | V_174 ,
V_113 ) ;
return 0 ;
}
static int F_34 ( struct V_142 * V_143 , unsigned int V_185 )
{
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_60 * V_61 = F_9 ( V_2 ) ;
T_1 V_186 = 0 , V_187 = 0 ;
switch ( V_185 & V_188 ) {
case V_189 :
V_61 -> V_117 = true ;
break;
case V_190 :
V_61 -> V_117 = false ;
break;
default:
return - V_91 ;
}
switch ( V_185 & V_191 ) {
case V_192 :
case V_193 :
case V_194 :
switch ( V_185 & V_195 ) {
case V_196 :
break;
case V_197 :
V_186 |= V_198 ;
break;
case V_199 :
V_186 |= V_200 ;
break;
case V_201 :
V_186 |= V_198 |
V_200 ;
break;
default:
return - V_91 ;
}
break;
case V_202 :
switch ( V_185 & V_195 ) {
case V_196 :
V_186 |= V_200 ;
break;
case V_197 :
V_186 |= V_198 |
V_200 ;
break;
case V_199 :
break;
case V_201 :
V_186 |= V_198 ;
break;
default:
return - V_91 ;
}
break;
default:
return - V_91 ;
}
switch ( V_185 & V_191 ) {
case V_192 :
V_187 |= V_203 ;
break;
case V_193 :
V_187 |= V_204 ;
break;
case V_194 :
V_187 |= V_205 ;
break;
case V_202 :
V_187 |= V_206 ;
break;
default:
return - V_91 ;
}
V_186 |= V_207 ;
F_6 ( V_2 , V_118 , V_186 ) ;
F_3 ( V_2 , V_208 , V_209 ,
V_187 ) ;
return 0 ;
}
static int F_35 ( struct V_142 * V_210 ,
unsigned int V_211 , unsigned int V_212 ,
int V_213 , int V_214 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
T_1 V_215 ;
T_3 V_216 ;
if ( ! V_211 ) {
F_3 ( V_2 , V_217 ,
V_218 |
V_219 , 0 ) ;
F_3 ( V_2 , V_118 ,
V_220 ,
V_207 ) ;
return 0 ;
}
if ( F_36 ( V_211 ) > V_221 ) {
F_29 ( V_2 -> V_50 , L_12 ,
V_221 ) ;
return - V_91 ;
}
if ( V_212 >> V_222 ) {
F_29 ( V_2 -> V_50 , L_13 ,
V_223 ) ;
return - V_91 ;
}
V_216 = V_213 * V_214 ;
switch ( V_216 ) {
case 32 :
V_215 = V_224 ;
break;
case 64 :
V_215 = V_207 ;
break;
case 128 :
V_215 = V_225 ;
break;
case 256 :
V_215 = V_226 ;
break;
default:
F_29 ( V_2 -> V_50 , L_14 ) ;
return - V_91 ;
}
F_3 ( V_2 , V_118 ,
V_220 ,
V_215 ) ;
F_6 ( V_2 , V_227 ,
( V_212 & V_181 ) ) ;
F_6 ( V_2 , V_228 ,
( ( V_212 >> V_180 ) & V_181 ) ) ;
F_3 ( V_2 , V_217 ,
V_218 |
V_219 ,
( V_211 << V_229 ) |
V_219 ) ;
return 0 ;
}
static int F_37 ( struct V_230 * V_231 ,
struct V_232 * V_233 ,
struct V_142 * V_210 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
T_1 V_187 = 0 , V_234 ;
unsigned int V_235 ;
switch ( F_38 ( V_233 ) ) {
case 16 :
V_187 |= V_236 ;
break;
case 20 :
V_187 |= V_237 ;
break;
case 24 :
V_187 |= V_238 ;
break;
case 32 :
V_187 |= V_239 ;
break;
default:
return - V_91 ;
}
V_235 = F_39 ( V_233 ) ;
if ( ( V_235 < 1 ) || ( V_235 > V_240 ) ) {
F_29 ( V_2 -> V_50 ,
L_15 ,
V_240 ) ;
return - V_91 ;
}
V_187 |= V_235 << V_241 ;
switch ( F_40 ( V_233 ) ) {
case 8000 :
V_234 = V_242 ;
break;
case 11025 :
V_234 = V_243 ;
break;
case 12000 :
V_234 = V_244 ;
break;
case 16000 :
V_234 = V_245 ;
break;
case 22050 :
V_234 = V_246 ;
break;
case 24000 :
V_234 = V_247 ;
break;
case 32000 :
V_234 = V_248 ;
break;
case 44100 :
V_234 = V_249 ;
break;
case 48000 :
V_234 = V_250 ;
break;
case 88200 :
V_234 = V_251 ;
break;
case 96000 :
V_234 = V_252 ;
break;
default:
return - V_91 ;
}
F_3 ( V_2 , V_208 ,
V_253 | V_254 ,
V_187 ) ;
F_6 ( V_2 , V_255 ,
( V_234 << V_256 ) | ( V_234 << V_257 ) ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , struct V_258 * V_259 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
if ( V_61 -> V_260 == V_261 )
return - V_91 ;
V_61 -> V_259 = V_259 ;
F_3 ( V_2 , V_262 ,
V_263 ,
V_259 ? V_263 : 0 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
char * V_264 [] = {
L_16 ,
NULL ,
} ;
F_43 ( & V_2 -> V_50 -> V_265 , V_266 , V_264 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
T_1 V_267 ;
int V_268 ;
V_267 = F_2 ( V_2 , V_269 ) ;
if ( V_267 & V_270 )
V_268 = V_271 ;
else
V_268 = 0 ;
F_45 ( V_61 -> V_259 , V_268 , V_271 ) ;
}
static T_5 F_46 ( int V_272 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
T_1 V_273 ;
V_273 = F_2 ( V_2 , V_274 ) ;
if ( ! V_273 )
return V_275 ;
if ( V_273 & V_276 )
F_42 ( V_2 ) ;
if ( V_273 & V_277 )
F_44 ( V_2 ) ;
F_6 ( V_2 , V_274 , V_273 ) ;
return V_278 ;
}
static inline int F_47 ( struct V_279 * V_50 )
{
const struct V_280 * V_281 = F_48 ( V_282 , V_50 ) ;
if ( V_281 )
return ( V_283 ) V_281 -> V_87 ;
else
return - V_91 ;
}
static enum V_284
F_49 ( struct V_1 * V_2 , T_3 V_77 )
{
switch ( V_77 ) {
case 1200 :
return V_285 ;
case 1600 :
return V_286 ;
case 1800 :
return V_287 ;
case 2000 :
return V_288 ;
case 2200 :
return V_289 ;
case 2400 :
return V_290 ;
case 2600 :
return V_291 ;
case 2800 :
return V_292 ;
case 3000 :
return V_293 ;
default:
F_5 ( V_2 -> V_50 , L_17 ) ;
return V_286 ;
}
}
static enum V_294
F_50 ( struct V_1 * V_2 , const char * V_295 )
{
if ( ! strcmp ( V_295 , L_18 ) ) {
return V_296 ;
} else if ( ! strcmp ( V_295 , L_19 ) ) {
return V_297 ;
} else if ( ! strcmp ( V_295 , L_20 ) ) {
return V_298 ;
} else {
F_5 ( V_2 -> V_50 , L_21 ) ;
return V_296 ;
}
}
static enum V_299
F_51 ( struct V_1 * V_2 , const char * V_295 )
{
if ( ! strcmp ( V_295 , L_22 ) ) {
return V_300 ;
} else if ( ! strcmp ( V_295 , L_23 ) ) {
return V_301 ;
} else {
F_5 ( V_2 -> V_50 , L_24 ) ;
return V_300 ;
}
}
static enum V_302
F_52 ( struct V_1 * V_2 , const char * V_295 )
{
if ( ! strcmp ( V_295 , L_25 ) ) {
return V_303 ;
} else if ( ! strcmp ( V_295 , L_26 ) ) {
return V_304 ;
} else {
F_5 ( V_2 -> V_50 , L_27 ) ;
return V_303 ;
}
}
static enum V_305
F_53 ( struct V_1 * V_2 , T_3 V_77 )
{
switch ( V_77 ) {
case 1500000 :
return V_306 ;
case 3000000 :
return V_307 ;
default:
F_5 ( V_2 -> V_50 , L_28 ) ;
return V_307 ;
}
}
static enum V_308
F_54 ( struct V_1 * V_2 , T_3 V_77 )
{
switch ( V_77 ) {
case 5 :
return V_309 ;
case 10 :
return V_310 ;
case 20 :
return V_311 ;
case 40 :
return V_312 ;
case 80 :
return V_313 ;
case 160 :
return V_314 ;
case 320 :
return V_315 ;
case 640 :
return V_316 ;
default:
F_5 ( V_2 -> V_50 , L_29 ) ;
return V_312 ;
}
}
static enum V_317
F_55 ( struct V_1 * V_2 , T_3 V_77 )
{
switch ( V_77 ) {
case 0 :
return V_318 ;
case 2 :
return V_319 ;
case 3 :
return V_320 ;
case 4 :
return V_321 ;
default:
F_5 ( V_2 -> V_50 , L_30 ) ;
return V_319 ;
}
}
static enum V_322
F_56 ( struct V_1 * V_2 , T_3 V_77 )
{
switch ( V_77 ) {
case 84 :
return V_323 ;
case 88 :
return V_324 ;
case 92 :
return V_325 ;
case 96 :
return V_326 ;
default:
F_5 ( V_2 -> V_50 , L_31 ) ;
return V_323 ;
}
}
static struct V_327 * F_57 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_328 * V_329 = V_2 -> V_50 -> V_330 ;
struct V_328 * V_331 ;
struct V_327 * V_332 ;
struct V_333 * V_334 ;
const char * V_335 ;
T_3 V_336 ;
V_332 = F_58 ( V_2 -> V_50 , sizeof( * V_332 ) , V_337 ) ;
if ( ! V_332 ) {
F_5 ( V_2 -> V_50 , L_32 ) ;
return NULL ;
}
if ( F_59 ( V_329 , L_33 , & V_336 ) >= 0 )
V_332 -> V_338 = F_49 ( V_2 , V_336 ) ;
else
V_332 -> V_338 = V_286 ;
if ( F_59 ( V_329 , L_34 , & V_336 ) >= 0 )
V_332 -> V_339 = F_49 ( V_2 , V_336 ) ;
else
V_332 -> V_339 = V_286 ;
if ( ! F_60 ( V_329 , L_35 , & V_335 ) )
V_332 -> V_340 =
F_50 ( V_2 , V_335 ) ;
else
V_332 -> V_340 = V_296 ;
if ( ! F_60 ( V_329 , L_36 , & V_335 ) )
V_332 -> V_341 =
F_50 ( V_2 , V_335 ) ;
else
V_332 -> V_341 = V_296 ;
if ( ! F_60 ( V_329 , L_37 , & V_335 ) )
V_332 -> V_342 = F_51 ( V_2 , V_335 ) ;
else
V_332 -> V_342 = V_300 ;
if ( ! F_60 ( V_329 , L_38 , & V_335 ) )
V_332 -> V_343 =
F_52 ( V_2 , V_335 ) ;
else
V_332 -> V_343 = V_303 ;
if ( F_59 ( V_329 , L_39 , & V_336 ) >= 0 )
V_332 -> V_344 = F_53 ( V_2 , V_336 ) ;
else
V_332 -> V_344 = V_307 ;
if ( ! F_60 ( V_329 , L_40 , & V_335 ) )
V_332 -> V_345 = F_51 ( V_2 , V_335 ) ;
else
V_332 -> V_345 = V_300 ;
if ( ! F_60 ( V_329 , L_41 , & V_335 ) )
V_332 -> V_346 =
F_52 ( V_2 , V_335 ) ;
else
V_332 -> V_346 = V_303 ;
if ( F_59 ( V_329 , L_42 , & V_336 ) >= 0 )
V_332 -> V_347 = F_53 ( V_2 , V_336 ) ;
else
V_332 -> V_347 = V_307 ;
if ( V_61 -> V_260 == V_261 ) {
if ( F_61 ( V_329 , L_43 ) )
V_332 -> V_348 = true ;
}
if ( V_61 -> V_260 == V_349 ) {
V_331 = F_62 ( V_329 , L_44 ) ;
if ( ! V_331 )
return V_332 ;
V_334 = F_58 ( V_2 -> V_50 , sizeof( * V_334 ) ,
V_337 ) ;
if ( ! V_334 ) {
F_5 ( V_2 -> V_50 ,
L_45 ) ;
F_63 ( V_331 ) ;
return V_332 ;
}
V_332 -> V_334 = V_334 ;
if ( F_59 ( V_331 , L_46 ,
& V_336 ) >= 0 )
V_334 -> V_350 =
F_54 ( V_2 , V_336 ) ;
else
V_334 -> V_350 = V_312 ;
if ( F_59 ( V_331 , L_47 ,
& V_336 ) >= 0 )
V_334 -> V_351 =
F_55 ( V_2 , V_336 ) ;
else
V_334 -> V_351 =
V_319 ;
if ( F_59 ( V_331 , L_48 ,
& V_336 ) >= 0 )
V_334 -> V_352 =
F_56 ( V_2 , V_336 ) ;
else
V_334 -> V_352 = V_323 ;
if ( F_61 ( V_331 , L_49 ) )
V_334 -> V_353 = true ;
if ( F_61 ( V_331 , L_50 ) )
V_334 -> V_354 = true ;
if ( F_61 ( V_331 , L_51 ) )
V_334 -> V_355 = true ;
F_63 ( V_331 ) ;
}
return V_332 ;
}
static int F_64 ( struct V_1 * V_2 ,
enum V_356 V_357 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
int V_62 ;
switch ( V_357 ) {
case V_358 :
case V_359 :
break;
case V_360 :
if ( F_65 ( V_2 ) == V_361 ) {
if ( V_61 -> V_151 ) {
V_62 = F_66 ( V_61 -> V_151 ) ;
if ( V_62 ) {
F_29 ( V_2 -> V_50 ,
L_52 ) ;
return V_62 ;
}
}
F_3 ( V_2 , V_362 ,
V_363 ,
V_363 ) ;
F_3 ( V_2 , V_364 ,
V_365 ,
V_365 ) ;
}
break;
case V_361 :
if ( ! V_61 -> V_259 ) {
F_3 ( V_2 , V_364 ,
V_365 , 0 ) ;
F_3 ( V_2 , V_362 ,
V_363 , 0 ) ;
}
if ( V_61 -> V_151 )
F_67 ( V_61 -> V_151 ) ;
break;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_366 * V_367 ;
T_1 V_368 = V_369 ;
int V_14 , V_62 ;
for ( V_14 = 0 ; V_14 < V_370 ; ++ V_14 )
V_61 -> V_371 [ V_14 ] . V_372 = V_373 [ V_14 ] ;
V_62 = F_69 ( V_2 -> V_50 , V_370 ,
V_61 -> V_371 ) ;
if ( V_62 ) {
F_29 ( V_2 -> V_50 , L_53 ) ;
return V_62 ;
}
V_367 = V_61 -> V_371 [ V_374 ] . V_375 ;
V_62 = F_70 ( V_367 ) ;
if ( V_62 < 1500000 )
F_5 ( V_2 -> V_50 , L_54 ) ;
else if ( V_62 < 2500000 )
V_368 = V_376 ;
V_62 = F_71 ( V_370 , V_61 -> V_371 ) ;
if ( V_62 ) {
F_29 ( V_2 -> V_50 , L_55 ) ;
return V_62 ;
}
F_6 ( V_2 , V_377 , V_378 ) ;
F_6 ( V_2 , V_379 , V_368 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
struct V_327 * V_332 = V_61 -> V_332 ;
if ( V_332 ) {
T_1 V_380 = 0 , V_381 = 0 ;
switch ( V_332 -> V_338 ) {
case V_285 :
V_380 |= V_382 ;
break;
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
V_380 |= ( V_332 -> V_338 <<
V_383 ) ;
break;
}
switch ( V_332 -> V_339 ) {
case V_285 :
V_380 |= V_384 ;
break;
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
V_380 |= ( V_332 -> V_339 <<
V_385 ) ;
break;
}
F_6 ( V_2 , V_386 , V_380 ) ;
switch ( V_332 -> V_340 ) {
case V_296 :
case V_297 :
case V_298 :
F_6 ( V_2 , V_387 ,
V_332 -> V_340 ) ;
break;
}
switch ( V_332 -> V_341 ) {
case V_296 :
case V_297 :
case V_298 :
F_6 ( V_2 , V_388 ,
V_332 -> V_341 ) ;
break;
}
switch ( V_332 -> V_342 ) {
case V_301 :
case V_300 :
V_381 |= ( V_332 -> V_342 <<
V_389 ) ;
break;
}
switch ( V_332 -> V_343 ) {
case V_303 :
case V_304 :
V_381 |= ( V_332 -> V_343 <<
V_390 ) ;
break;
}
switch ( V_332 -> V_344 ) {
case V_307 :
case V_306 :
V_381 |= ( V_332 -> V_344 <<
V_391 ) ;
break;
}
F_3 ( V_2 , V_392 ,
V_393 |
V_394 |
V_395 , V_381 ) ;
V_381 = 0 ;
switch ( V_332 -> V_345 ) {
case V_301 :
case V_300 :
V_381 |= ( V_332 -> V_345 <<
V_396 ) ;
break;
}
switch ( V_332 -> V_346 ) {
case V_303 :
case V_304 :
V_381 |= ( V_332 -> V_346 <<
V_397 ) ;
break;
}
switch ( V_332 -> V_347 ) {
case V_307 :
case V_306 :
V_381 |= ( V_332 -> V_347 <<
V_398 ) ;
break;
}
F_3 ( V_2 , V_399 ,
V_400 |
V_401 |
V_402 , V_381 ) ;
if ( V_61 -> V_260 == V_261 ) {
V_61 -> V_137 =
V_332 -> V_348 ;
if ( V_61 -> V_137 ) {
F_6 ( V_2 , V_403 ,
V_404 ) ;
F_3 ( V_2 , V_405 ,
V_406 ,
V_406 ) ;
}
}
if ( ( V_61 -> V_260 == V_349 ) &&
( V_332 -> V_334 ) ) {
struct V_333 * V_334 =
V_332 -> V_334 ;
T_1 V_407 = 0 ;
switch ( V_334 -> V_350 ) {
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
V_407 |=
( V_334 -> V_350 <<
V_408 ) ;
break;
}
switch ( V_334 -> V_351 ) {
case V_318 :
case V_319 :
case V_320 :
case V_321 :
V_407 |=
( V_334 -> V_351 <<
V_409 ) ;
break;
}
switch ( V_334 -> V_352 ) {
case V_323 :
case V_324 :
case V_325 :
case V_326 :
V_407 |=
( V_334 -> V_352 <<
V_410 ) ;
break;
}
F_3 ( V_2 , V_262 ,
V_411 |
V_412 |
V_413 ,
V_407 ) ;
V_407 = 0 ;
if ( V_334 -> V_353 )
V_407 |= V_414 ;
if ( V_334 -> V_354 )
V_407 |= V_415 ;
if ( V_334 -> V_355 )
V_407 |= V_416 ;
F_6 ( V_2 , V_417 , V_407 ) ;
}
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
int V_62 ;
V_62 = F_68 ( V_2 ) ;
if ( V_62 )
return V_62 ;
if ( V_2 -> V_50 -> V_330 )
V_61 -> V_332 = F_57 ( V_2 ) ;
else
V_61 -> V_332 = F_74 ( V_2 -> V_50 ) ;
F_72 ( V_2 ) ;
V_61 -> V_151 = F_75 ( V_2 -> V_50 , L_56 ) ;
if ( F_76 ( V_61 -> V_151 ) ) {
if ( F_77 ( V_61 -> V_151 ) != - V_418 ) {
V_62 = F_77 ( V_61 -> V_151 ) ;
goto V_419;
} else {
V_61 -> V_151 = NULL ;
}
}
F_6 ( V_2 , V_126 , V_136 ) ;
F_6 ( V_2 , V_420 , 0 ) ;
F_6 ( V_2 , V_421 , 0 ) ;
F_3 ( V_2 , V_139 ,
V_422 , 0 ) ;
F_3 ( V_2 , V_18 ,
V_423 ,
V_423 ) ;
F_3 ( V_2 , V_19 ,
V_424 ,
V_424 ) ;
F_3 ( V_2 , V_20 ,
V_425 ,
V_425 ) ;
F_3 ( V_2 , V_21 ,
V_426 ,
V_426 ) ;
F_3 ( V_2 , V_22 ,
V_427 ,
V_427 ) ;
F_3 ( V_2 , V_23 ,
V_428 ,
V_428 ) ;
F_3 ( V_2 , V_429 ,
V_430 , V_430 ) ;
F_3 ( V_2 , V_97 ,
V_431 ,
V_431 ) ;
F_3 ( V_2 , V_432 ,
V_433 ,
V_433 ) ;
F_3 ( V_2 , V_434 ,
V_435 ,
V_435 ) ;
F_3 ( V_2 , V_436 ,
V_437 ,
V_437 ) ;
F_6 ( V_2 , V_438 , V_439 ) ;
if ( V_61 -> V_260 == V_261 ) {
F_3 ( V_2 , V_405 ,
V_440 ,
V_440 ) ;
F_6 ( V_2 , V_441 ,
V_442 ) ;
}
if ( V_61 -> V_272 ) {
V_62 = F_78 ( V_2 -> V_50 , V_61 -> V_272 , NULL ,
F_46 ,
V_443 | V_444 ,
L_57 , V_2 ) ;
if ( V_62 != 0 ) {
F_29 ( V_2 -> V_50 , L_58 ,
V_61 -> V_272 , V_62 ) ;
goto V_419;
}
}
return 0 ;
V_419:
F_79 ( V_370 , V_61 -> V_371 ) ;
return V_62 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
F_79 ( V_370 , V_61 -> V_371 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
F_64 ( V_2 , V_361 ) ;
if ( ! V_61 -> V_259 )
F_6 ( V_2 , V_377 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_9 ( V_2 ) ;
if ( ! V_61 -> V_259 )
F_6 ( V_2 , V_377 ,
V_378 ) ;
F_64 ( V_2 , V_360 ) ;
return 0 ;
}
static bool F_83 ( struct V_279 * V_50 , unsigned int V_76 )
{
switch ( V_76 ) {
case V_445 :
case V_446 :
case V_447 :
case V_44 :
case V_448 :
case V_449 :
case V_450 :
case V_451 :
case V_131 :
case V_120 :
case V_452 :
case V_453 :
case V_454 :
case V_455 :
case V_269 :
case V_274 :
return true ;
default:
return false ;
}
}
static int F_84 ( struct V_456 * V_457 ,
const struct V_458 * V_281 )
{
struct V_60 * V_61 ;
int V_62 ;
V_61 = F_58 ( & V_457 -> V_50 , sizeof( struct V_60 ) ,
V_337 ) ;
if ( ! V_61 )
return - V_459 ;
F_85 ( V_457 , V_61 ) ;
if ( V_457 -> V_50 . V_330 )
V_61 -> V_260 = F_47 ( & V_457 -> V_50 ) ;
else
V_61 -> V_260 = V_281 -> V_460 ;
if ( ( V_61 -> V_260 != V_261 ) &&
( V_61 -> V_260 != V_349 ) ) {
F_29 ( & V_457 -> V_50 , L_59 ) ;
return - V_91 ;
}
V_61 -> V_272 = V_457 -> V_272 ;
V_61 -> V_78 = F_86 ( V_457 , & V_461 ) ;
if ( F_76 ( V_61 -> V_78 ) ) {
V_62 = F_77 ( V_61 -> V_78 ) ;
F_29 ( & V_457 -> V_50 , L_60 , V_62 ) ;
return V_62 ;
}
V_62 = F_87 ( & V_457 -> V_50 ,
& V_462 , & V_463 , 1 ) ;
if ( V_62 < 0 ) {
F_29 ( & V_457 -> V_50 , L_61 ,
V_62 ) ;
}
return V_62 ;
}
static int F_88 ( struct V_456 * V_464 )
{
F_89 ( & V_464 -> V_50 ) ;
return 0 ;
}
