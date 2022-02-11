static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_9 ;
T_1 V_10 = 0 ;
int V_11 ;
if ( V_6 -> V_12 >= V_13 )
return V_10 ;
if ( V_8 -> V_14 & V_15 )
return V_10 ;
if ( V_8 -> V_14 & V_16 )
return V_10 ;
V_11 = - 1 ;
F_3 (clone_encoder, &dev->mode_config.encoder_list, head) {
struct V_8 * V_17 = F_2 ( V_9 ) ;
V_11 ++ ;
if ( V_9 == V_2 )
continue;
if ( V_17 -> V_14 & ( V_15 ) )
continue;
if ( V_17 -> V_14 & V_16 )
continue;
else
V_10 |= ( 1 << V_11 ) ;
}
return V_10 ;
}
void F_4 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
V_2 -> V_18 = F_1 ( V_2 ) ;
}
}
T_1
F_5 ( struct V_3 * V_4 , T_1 V_19 , T_2 V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_21 = 0 ;
switch ( V_19 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
switch ( V_20 ) {
case 1 :
if ( ( V_6 -> V_12 == V_27 ) ||
( V_6 -> V_12 == V_28 ) ||
( V_6 -> V_12 == V_29 ) )
V_21 = V_30 ;
else if ( F_6 ( V_6 ) )
V_21 = V_31 ;
else
V_21 = V_32 ;
break;
case 2 :
if ( F_6 ( V_6 ) )
V_21 = V_33 ;
else {
V_21 = V_30 ;
}
break;
case 3 :
if ( F_6 ( V_6 ) )
V_21 = V_34 ;
else
V_21 = V_35 ;
break;
}
break;
case V_36 :
if ( F_6 ( V_6 ) )
V_21 = V_37 ;
else
V_21 = V_38 ;
break;
case V_39 :
if ( ( V_6 -> V_12 == V_27 ) ||
( V_6 -> V_12 == V_28 ) ||
( V_6 -> V_12 == V_29 ) )
V_21 = V_35 ;
else if ( F_6 ( V_6 ) )
V_21 = V_40 ;
else
V_21 = V_41 ;
break;
case V_42 :
case V_16 :
if ( ( V_6 -> V_12 == V_43 ) ||
( V_6 -> V_12 == V_44 ) ||
( V_6 -> V_12 == V_45 ) )
V_21 = V_46 ;
else if ( F_6 ( V_6 ) )
V_21 = V_34 ;
else
V_21 = V_35 ;
break;
case V_47 :
V_21 = V_37 ;
break;
}
return V_21 ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
switch ( V_8 -> V_48 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return true ;
default:
return false ;
}
}
void
F_8 ( struct V_3 * V_4 )
{
struct V_60 * V_61 ;
struct V_62 * V_62 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_62 = F_9 ( V_61 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_14 & V_62 -> V_14 )
F_10 ( V_61 , V_2 ) ;
}
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_60 * V_61 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( V_61 -> V_2 == V_2 ) {
struct V_62 * V_62 = F_9 ( V_61 ) ;
V_8 -> V_63 = V_8 -> V_14 & V_62 -> V_14 ;
F_12 ( L_1 ,
V_8 -> V_63 , V_8 -> V_14 ,
V_62 -> V_14 , V_2 -> V_64 ) ;
}
}
}
struct V_60 *
F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_60 * V_61 ;
struct V_62 * V_62 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_62 = F_9 ( V_61 ) ;
if ( V_8 -> V_63 & V_62 -> V_14 )
return V_61 ;
}
return NULL ;
}
static struct V_60 *
F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_60 * V_61 ;
struct V_62 * V_62 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_62 = F_9 ( V_61 ) ;
if ( V_8 -> V_14 & V_62 -> V_14 )
return V_61 ;
}
return NULL ;
}
struct V_1 * F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_65 ;
struct V_8 * V_66 ;
if ( V_8 -> V_67 )
return NULL ;
F_3 (other_encoder, &dev->mode_config.encoder_list, head) {
if ( V_65 == V_2 )
continue;
V_66 = F_2 ( V_65 ) ;
if ( V_66 -> V_67 &&
( V_8 -> V_14 & V_66 -> V_14 ) )
return V_65 ;
}
return NULL ;
}
bool F_16 ( struct V_1 * V_2 )
{
struct V_1 * V_65 = F_15 ( V_2 ) ;
if ( V_65 ) {
struct V_8 * V_8 = F_2 ( V_65 ) ;
switch ( V_8 -> V_48 ) {
case V_68 :
case V_69 :
return true ;
default:
return false ;
}
}
return false ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_70 * V_72 = & V_8 -> V_72 ;
unsigned V_73 = V_72 -> V_74 - V_72 -> V_75 ;
unsigned V_76 = V_72 -> V_77 - V_72 -> V_78 ;
unsigned V_79 = V_72 -> V_80 - V_72 -> V_75 ;
unsigned V_81 = V_72 -> V_82 - V_72 -> V_78 ;
unsigned V_83 = V_72 -> V_84 - V_72 -> V_80 ;
unsigned V_85 = V_72 -> V_86 - V_72 -> V_82 ;
V_71 -> clock = V_72 -> clock ;
V_71 -> V_87 = V_72 -> V_87 ;
if ( F_6 ( V_6 ) ) {
V_71 -> V_75 = V_72 -> V_75 ;
V_71 -> V_78 = V_72 -> V_78 ;
}
V_71 -> V_74 = V_72 -> V_75 + V_73 ;
V_71 -> V_80 = V_72 -> V_75 + V_79 ;
V_71 -> V_84 = V_71 -> V_80 + V_83 ;
V_71 -> V_77 = V_72 -> V_78 + V_76 ;
V_71 -> V_82 = V_72 -> V_78 + V_81 ;
V_71 -> V_86 = V_71 -> V_82 + V_85 ;
F_18 ( V_71 , V_88 ) ;
if ( F_6 ( V_6 ) ) {
V_71 -> V_89 = V_72 -> V_75 ;
V_71 -> V_90 = V_72 -> V_78 ;
}
V_71 -> V_91 = V_71 -> V_89 + V_73 ;
V_71 -> V_92 = V_71 -> V_89 + V_79 ;
V_71 -> V_93 = V_71 -> V_92 + V_83 ;
V_71 -> V_94 = V_71 -> V_90 + V_76 ;
V_71 -> V_95 = V_71 -> V_90 + V_81 ;
V_71 -> V_96 = V_71 -> V_95 + V_85 ;
}
static bool F_19 ( struct V_1 * V_2 ,
struct V_70 * V_97 ,
struct V_70 * V_71 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_11 ( V_2 ) ;
F_18 ( V_71 , 0 ) ;
if ( ( V_97 -> V_87 & V_98 )
&& ( V_97 -> V_95 < ( V_97 -> V_90 + 2 ) ) )
V_71 -> V_95 = V_71 -> V_90 + 2 ;
if ( V_8 -> V_63 & ( V_15 ) )
F_17 ( V_2 , V_71 ) ;
if ( V_8 -> V_63 & ( V_99 ) ) {
struct V_100 * V_101 = V_8 -> V_102 ;
if ( V_101 ) {
if ( V_101 -> V_103 == V_104 ||
V_101 -> V_103 == V_105 ||
V_101 -> V_103 == V_106 )
F_20 ( V_6 , 0 , V_71 ) ;
else
F_20 ( V_6 , 1 , V_71 ) ;
}
}
if ( F_21 ( V_6 ) &&
( ( V_8 -> V_63 & ( V_107 | V_15 ) ) ||
F_16 ( V_2 ) ) ) {
struct V_60 * V_61 = F_13 ( V_2 ) ;
F_22 ( V_61 , V_97 ) ;
}
return true ;
}
static void
F_23 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
T_3 args ;
int V_109 = 0 ;
struct V_100 * V_110 = V_8 -> V_102 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_48 ) {
case V_111 :
case V_112 :
V_109 = F_24 ( V_113 , V_114 ) ;
break;
case V_115 :
case V_116 :
V_109 = F_24 ( V_113 , V_117 ) ;
break;
}
args . V_118 = V_108 ;
if ( V_8 -> V_63 & ( V_119 ) )
args . V_120 = V_121 ;
else if ( V_8 -> V_63 & ( V_26 ) )
args . V_120 = V_122 ;
else {
switch ( V_110 -> V_103 ) {
case V_123 :
case V_106 :
case V_124 :
case V_125 :
case V_126 :
args . V_120 = V_127 ;
break;
case V_104 :
case V_105 :
case V_128 :
default:
args . V_120 = V_129 ;
break;
}
}
args . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
static void
F_27 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
T_4 args ;
int V_109 = 0 ;
struct V_100 * V_110 = V_8 -> V_102 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_109 = F_24 ( V_113 , V_134 ) ;
args . V_135 . V_118 = V_108 ;
if ( V_8 -> V_63 & ( V_26 ) )
args . V_135 . V_136 = V_137 ;
else {
switch ( V_110 -> V_103 ) {
case V_104 :
args . V_135 . V_136 = V_138 ;
break;
case V_123 :
args . V_135 . V_136 = V_139 ;
break;
case V_106 :
args . V_135 . V_136 = V_140 ;
break;
case V_128 :
args . V_135 . V_136 = V_141 ;
break;
case V_105 :
args . V_135 . V_136 = V_142 ;
break;
case V_124 :
args . V_135 . V_136 = V_139 ;
break;
case V_125 :
args . V_135 . V_136 = V_143 ;
break;
case V_126 :
args . V_135 . V_136 = V_144 ;
break;
default:
args . V_135 . V_136 = V_138 ;
break;
}
}
args . V_135 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
void
F_28 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
union V_145 args ;
int V_109 = F_24 ( V_113 , V_146 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_21 ( V_6 ) ) {
args . V_147 . V_118 = V_108 ;
args . V_147 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
args . V_147 . V_148 = 0 ;
} else if ( F_29 ( V_6 ) ) {
args . V_149 . V_150 . V_118 = V_108 ;
args . V_149 . V_150 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
args . V_149 . V_150 . V_151 = V_152 ;
if ( V_8 -> V_131 > 165000 )
args . V_149 . V_150 . V_153 . V_154 . V_155 |= V_156 ;
} else {
args . V_157 . V_158 . V_159 = V_108 ;
if ( V_8 -> V_131 > 165000 )
args . V_157 . V_158 . V_160 |= V_156 ;
args . V_157 . V_158 . V_160 |= V_161 ;
}
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
void
F_30 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_162 * V_163 = V_8 -> V_102 ;
union V_164 args ;
int V_109 = 0 ;
int V_165 = 0 ;
T_2 V_166 , V_167 ;
if ( ! V_163 )
return;
if ( F_31 ( V_2 ) == V_168 )
V_165 = 1 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_48 ) {
case V_49 :
V_109 = F_24 ( V_113 , V_169 ) ;
break;
case V_50 :
case V_51 :
V_109 = F_24 ( V_113 , V_170 ) ;
break;
case V_52 :
if ( V_8 -> V_14 & ( V_15 ) )
V_109 = F_24 ( V_113 , V_169 ) ;
else
V_109 = F_24 ( V_113 , V_171 ) ;
break;
}
if ( ! F_32 ( V_6 -> V_132 . V_133 , V_109 , & V_166 , & V_167 ) )
return;
switch ( V_166 ) {
case 1 :
case 2 :
switch ( V_167 ) {
case 1 :
args . V_172 . V_160 = 0 ;
args . V_172 . V_118 = V_108 ;
if ( V_165 )
args . V_172 . V_160 |= V_173 ;
args . V_172 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
if ( V_8 -> V_14 & ( V_15 ) ) {
if ( V_163 -> V_174 & V_175 )
args . V_172 . V_160 |= V_156 ;
if ( V_163 -> V_174 & V_161 )
args . V_172 . V_160 |= V_161 ;
} else {
if ( V_163 -> V_176 )
args . V_172 . V_160 |= V_177 ;
if ( V_8 -> V_131 > 165000 )
args . V_172 . V_160 |= V_156 ;
args . V_172 . V_160 |= V_161 ;
}
break;
case 2 :
case 3 :
args . V_178 . V_160 = 0 ;
args . V_178 . V_118 = V_108 ;
if ( V_167 == 3 ) {
if ( V_163 -> V_179 )
args . V_178 . V_160 |= V_180 ;
}
if ( V_165 )
args . V_178 . V_160 |= V_173 ;
args . V_178 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
args . V_178 . V_181 = 0 ;
args . V_178 . V_182 = 0 ;
args . V_178 . V_183 = 0 ;
args . V_178 . V_184 = 0 ;
if ( V_8 -> V_14 & ( V_15 ) ) {
if ( V_163 -> V_174 & V_175 )
args . V_178 . V_160 |= V_156 ;
if ( V_163 -> V_174 & V_185 ) {
args . V_178 . V_182 = V_186 ;
if ( V_163 -> V_174 & V_161 )
args . V_178 . V_182 |= V_187 ;
}
if ( V_163 -> V_174 & V_188 ) {
args . V_178 . V_183 = V_189 ;
if ( V_163 -> V_174 & V_161 )
args . V_178 . V_183 |= V_190 ;
if ( ( ( V_163 -> V_174 >> V_191 ) & 0x3 ) == 2 )
args . V_178 . V_183 |= V_192 ;
}
} else {
if ( V_163 -> V_176 )
args . V_178 . V_160 |= V_177 ;
if ( V_8 -> V_131 > 165000 )
args . V_178 . V_160 |= V_156 ;
}
break;
default:
F_33 ( L_2 , V_166 , V_167 ) ;
break;
}
break;
default:
F_33 ( L_2 , V_166 , V_167 ) ;
break;
}
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
int
F_31 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_60 * V_61 ;
struct V_62 * V_62 ;
struct V_193 * V_194 ;
if ( F_16 ( V_2 ) )
return V_195 ;
if ( V_8 -> V_48 == V_196 )
return V_196 ;
V_61 = F_13 ( V_2 ) ;
if ( ! V_61 )
V_61 = F_14 ( V_2 ) ;
V_62 = F_9 ( V_61 ) ;
switch ( V_61 -> V_197 ) {
case V_198 :
case V_199 :
if ( F_34 ( V_62 -> V_200 ) && V_201 ) {
if ( F_35 ( V_6 ) )
return V_202 ;
else
return V_168 ;
} else if ( V_62 -> V_203 )
return V_202 ;
else
return V_204 ;
break;
case V_205 :
case V_206 :
default:
if ( F_34 ( V_62 -> V_200 ) && V_201 ) {
if ( F_35 ( V_6 ) )
return V_202 ;
else
return V_168 ;
} else
return V_202 ;
break;
case V_207 :
return V_208 ;
break;
case V_209 :
V_194 = V_62 -> V_210 ;
if ( ( V_194 -> V_211 == V_212 ) ||
( V_194 -> V_211 == V_213 ) )
return V_195 ;
else if ( F_34 ( V_62 -> V_200 ) && V_201 ) {
if ( F_35 ( V_6 ) )
return V_202 ;
else
return V_168 ;
} else
return V_202 ;
break;
case V_214 :
return V_195 ;
case V_215 :
case V_216 :
return V_204 ;
break;
case V_217 :
case V_218 :
case V_219 :
return V_220 ;
break;
}
}
void
F_36 ( struct V_1 * V_2 , int V_108 , int V_221 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_162 * V_163 = V_8 -> V_102 ;
struct V_60 * V_61 = F_13 ( V_2 ) ;
union V_222 args ;
int V_109 = 0 ;
T_2 V_166 , V_167 ;
int V_223 = 0 ;
int V_224 = 0 ;
int V_225 = V_226 ;
int V_227 = 8 ;
if ( V_61 ) {
struct V_62 * V_62 = F_9 ( V_61 ) ;
struct V_193 * V_194 =
V_62 -> V_210 ;
V_223 = V_194 -> V_223 ;
V_224 = V_194 -> V_224 ;
V_225 = V_62 -> V_228 . V_228 ;
V_227 = V_61 -> V_229 . V_227 ;
}
if ( V_163 -> V_230 == - 1 )
return;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_35 ( V_6 ) )
V_109 = F_24 ( V_113 , V_231 ) ;
else {
if ( V_163 -> V_230 )
V_109 = F_24 ( V_113 , V_232 ) ;
else
V_109 = F_24 ( V_113 , V_233 ) ;
}
if ( ! F_32 ( V_6 -> V_132 . V_133 , V_109 , & V_166 , & V_167 ) )
return;
args . V_172 . V_118 = V_108 ;
args . V_172 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
if ( V_108 == V_234 )
args . V_235 . V_236 = V_221 ;
else
args . V_172 . V_237 = F_31 ( V_2 ) ;
if ( ( args . V_172 . V_237 == V_195 ) ||
( args . V_172 . V_237 == V_238 ) )
args . V_172 . V_239 = V_224 ;
else if ( V_8 -> V_131 > 165000 )
args . V_172 . V_239 = 8 ;
else
args . V_172 . V_239 = 4 ;
if ( F_37 ( V_6 ) ) {
if ( ( args . V_172 . V_237 == V_195 ) ||
( args . V_172 . V_237 == V_238 ) ) {
if ( V_223 == 270000 )
args . V_172 . V_240 |= V_241 ;
else if ( V_223 == 540000 )
args . V_172 . V_240 |= V_242 ;
}
args . V_243 . V_244 . V_245 = V_163 -> V_230 ;
switch ( V_227 ) {
case 0 :
args . V_243 . V_246 = V_247 ;
break;
case 6 :
args . V_243 . V_246 = V_248 ;
break;
case 8 :
default:
args . V_243 . V_246 = V_249 ;
break;
case 10 :
args . V_243 . V_246 = V_250 ;
break;
case 12 :
args . V_243 . V_246 = V_251 ;
break;
case 16 :
args . V_243 . V_246 = V_252 ;
break;
}
if ( V_225 == V_226 )
args . V_243 . V_253 = 0 ;
else
args . V_243 . V_253 = V_225 + 1 ;
} else if ( F_35 ( V_6 ) ) {
if ( ( args . V_172 . V_237 == V_195 ) && ( V_223 == 270000 ) )
args . V_172 . V_240 |= V_254 ;
args . V_235 . V_244 . V_245 = V_163 -> V_230 ;
switch ( V_227 ) {
case 0 :
args . V_235 . V_246 = V_247 ;
break;
case 6 :
args . V_235 . V_246 = V_248 ;
break;
case 8 :
default:
args . V_235 . V_246 = V_249 ;
break;
case 10 :
args . V_235 . V_246 = V_250 ;
break;
case 12 :
args . V_235 . V_246 = V_251 ;
break;
case 16 :
args . V_235 . V_246 = V_252 ;
break;
}
} else {
if ( ( args . V_172 . V_237 == V_195 ) && ( V_223 == 270000 ) )
args . V_172 . V_240 |= V_255 ;
switch ( V_8 -> V_48 ) {
case V_56 :
args . V_172 . V_240 = V_256 ;
break;
case V_58 :
case V_57 :
args . V_172 . V_240 = V_257 ;
break;
case V_59 :
args . V_172 . V_240 = V_258 ;
break;
}
if ( V_163 -> V_176 )
args . V_172 . V_240 |= V_259 ;
else
args . V_172 . V_240 |= V_260 ;
}
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
void
F_38 ( struct V_1 * V_2 , int V_108 , T_2 V_261 , T_2 V_262 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_162 * V_163 = V_8 -> V_102 ;
struct V_60 * V_61 ;
union V_263 args ;
int V_109 = 0 ;
T_2 V_166 , V_167 ;
bool V_264 = false ;
int V_265 = 0 ;
int V_223 = 0 ;
int V_224 = 0 ;
int V_266 = 0 ;
int V_267 = 0 ;
int V_230 = V_163 -> V_230 ;
if ( V_108 == V_268 ) {
V_61 = F_14 ( V_2 ) ;
V_230 = 0 ;
} else
V_61 = F_13 ( V_2 ) ;
if ( V_61 ) {
struct V_62 * V_62 = F_9 ( V_61 ) ;
struct V_193 * V_194 =
V_62 -> V_210 ;
V_223 = V_194 -> V_223 ;
V_224 = V_194 -> V_224 ;
V_266 =
( V_62 -> V_266 & V_269 ) >> V_270 ;
V_267 = V_194 -> V_267 ;
}
if ( V_230 == - 1 )
return;
if ( F_31 ( V_2 ) == V_195 )
V_264 = true ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_48 ) {
case V_54 :
V_109 = F_24 ( V_113 , V_271 ) ;
break;
case V_56 :
case V_58 :
case V_59 :
V_109 = F_24 ( V_113 , V_272 ) ;
break;
case V_57 :
V_109 = F_24 ( V_113 , V_273 ) ;
break;
}
if ( ! F_32 ( V_6 -> V_132 . V_133 , V_109 , & V_166 , & V_167 ) )
return;
args . V_172 . V_118 = V_108 ;
if ( V_108 == V_268 ) {
args . V_172 . V_274 = F_25 ( V_266 ) ;
} else if ( V_108 == V_275 ) {
args . V_172 . V_276 . V_277 = V_261 ;
args . V_172 . V_276 . V_278 = V_262 ;
} else {
if ( V_264 )
args . V_172 . V_130 =
F_25 ( V_223 / 10 ) ;
else if ( V_8 -> V_131 > 165000 )
args . V_172 . V_130 = F_25 ( ( V_8 -> V_131 / 2 ) / 10 ) ;
else
args . V_172 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
}
if ( F_35 ( V_6 ) ) {
if ( V_264 )
args . V_235 . V_239 = V_224 ;
else if ( V_8 -> V_131 > 165000 )
args . V_235 . V_239 = 8 ;
else
args . V_235 . V_239 = 4 ;
if ( V_163 -> V_176 )
args . V_235 . V_244 . V_279 = 1 ;
if ( V_230 & 1 )
args . V_235 . V_244 . V_280 = 1 ;
if ( V_2 -> V_281 ) {
struct V_282 * V_282 = F_39 ( V_2 -> V_281 ) ;
V_265 = V_282 -> V_265 ;
}
if ( F_37 ( V_6 ) ) {
if ( V_264 ) {
if ( V_6 -> clock . V_283 )
args . V_243 . V_244 . V_284 = V_285 ;
else
args . V_243 . V_244 . V_284 = V_286 ;
} else
args . V_243 . V_244 . V_284 = V_265 ;
} else {
if ( V_264 && V_6 -> clock . V_283 )
args . V_235 . V_244 . V_284 = 2 ;
else
args . V_235 . V_244 . V_284 = V_265 ;
}
switch ( V_8 -> V_48 ) {
case V_56 :
args . V_235 . V_244 . V_287 = 0 ;
break;
case V_58 :
args . V_235 . V_244 . V_287 = 1 ;
break;
case V_59 :
args . V_235 . V_244 . V_287 = 2 ;
break;
}
if ( V_264 )
args . V_235 . V_244 . V_288 = 1 ;
else if ( V_8 -> V_14 & ( V_107 ) ) {
if ( V_163 -> V_179 )
args . V_235 . V_244 . V_288 = 1 ;
if ( V_8 -> V_131 > 165000 )
args . V_235 . V_244 . V_289 = 1 ;
}
} else if ( F_40 ( V_6 ) ) {
args . V_178 . V_244 . V_280 = V_230 ;
if ( V_163 -> V_176 )
args . V_178 . V_244 . V_279 = 1 ;
switch ( V_8 -> V_48 ) {
case V_56 :
args . V_178 . V_244 . V_287 = 0 ;
break;
case V_58 :
args . V_178 . V_244 . V_287 = 1 ;
break;
case V_59 :
args . V_178 . V_244 . V_287 = 2 ;
break;
}
if ( V_264 ) {
args . V_178 . V_244 . V_288 = 1 ;
args . V_178 . V_244 . V_290 = 1 ;
} else if ( V_8 -> V_14 & ( V_107 ) ) {
if ( V_163 -> V_179 )
args . V_178 . V_244 . V_288 = 1 ;
if ( V_8 -> V_131 > 165000 )
args . V_178 . V_244 . V_289 = 1 ;
}
} else {
args . V_172 . V_240 = V_291 ;
if ( V_230 )
args . V_172 . V_240 |= V_292 ;
else
args . V_172 . V_240 |= V_293 ;
if ( ( V_6 -> V_87 & V_294 ) &&
( V_8 -> V_48 == V_56 ) ) {
if ( V_264 || ( V_8 -> V_131 <= 165000 ) ) {
if ( V_267 & 0x1 )
args . V_172 . V_240 |= V_295 ;
else if ( V_267 & 0x2 )
args . V_172 . V_240 |= V_296 ;
else if ( V_267 & 0x4 )
args . V_172 . V_240 |= V_297 ;
else if ( V_267 & 0x8 )
args . V_172 . V_240 |= V_298 ;
} else {
if ( V_267 & 0x3 )
args . V_172 . V_240 |= V_299 ;
else if ( V_267 & 0xc )
args . V_172 . V_240 |= V_300 ;
}
}
if ( V_163 -> V_176 )
args . V_172 . V_240 |= V_301 ;
else
args . V_172 . V_240 |= V_302 ;
if ( V_264 )
args . V_172 . V_240 |= V_303 ;
else if ( V_8 -> V_14 & ( V_107 ) ) {
if ( V_163 -> V_179 )
args . V_172 . V_240 |= V_303 ;
if ( V_8 -> V_131 > 165000 )
args . V_172 . V_240 |= V_304 ;
}
}
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
bool
F_41 ( struct V_60 * V_61 , int V_108 )
{
struct V_62 * V_62 = F_9 ( V_61 ) ;
struct V_3 * V_4 = V_62 -> V_305 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
union V_263 args ;
int V_109 = F_24 ( V_113 , V_272 ) ;
T_2 V_166 , V_167 ;
if ( V_61 -> V_197 != V_214 )
goto V_306;
if ( ! F_35 ( V_6 ) )
goto V_306;
if ( ( V_108 != V_307 ) &&
( V_108 != V_308 ) )
goto V_306;
if ( ! F_32 ( V_6 -> V_132 . V_133 , V_109 , & V_166 , & V_167 ) )
goto V_306;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_172 . V_118 = V_108 ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
if ( V_108 == V_307 ) {
int V_309 ;
for ( V_309 = 0 ; V_309 < 300 ; V_309 ++ ) {
if ( F_42 ( V_6 , V_62 -> V_228 . V_228 ) )
return true ;
F_43 ( 1 ) ;
}
return false ;
}
V_306:
return true ;
}
static void
F_44 ( struct V_1 * V_2 ,
struct V_1 * V_310 ,
int V_108 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_311 = F_2 ( V_310 ) ;
union V_312 args ;
struct V_60 * V_61 ;
int V_109 = F_24 ( V_113 , V_313 ) ;
T_5 V_166 , V_167 ;
int V_223 = 0 ;
int V_224 = 0 ;
int V_266 = 0 ;
T_6 V_314 = ( V_311 -> V_315 & V_316 ) >> V_317 ;
int V_227 = 8 ;
if ( V_108 == V_318 )
V_61 = F_14 ( V_2 ) ;
else
V_61 = F_13 ( V_2 ) ;
if ( V_61 ) {
struct V_62 * V_62 = F_9 ( V_61 ) ;
struct V_193 * V_194 =
V_62 -> V_210 ;
V_223 = V_194 -> V_223 ;
V_224 = V_194 -> V_224 ;
V_266 =
( V_62 -> V_266 & V_269 ) >> V_270 ;
V_227 = V_61 -> V_229 . V_227 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_32 ( V_6 -> V_132 . V_133 , V_109 , & V_166 , & V_167 ) )
return;
switch ( V_166 ) {
case 1 :
break;
case 2 :
switch ( V_167 ) {
case 1 :
case 2 :
args . V_172 . V_319 . V_118 = V_108 ;
args . V_172 . V_319 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
args . V_172 . V_319 . V_237 = F_31 ( V_2 ) ;
if ( args . V_172 . V_319 . V_237 == V_195 ) {
if ( V_223 == 270000 )
args . V_172 . V_319 . V_240 |= V_255 ;
args . V_172 . V_319 . V_239 = V_224 ;
} else if ( V_8 -> V_131 > 165000 )
args . V_172 . V_319 . V_239 = 8 ;
else
args . V_172 . V_319 . V_239 = 4 ;
break;
case 3 :
args . V_235 . V_320 . V_118 = V_108 ;
if ( V_108 == V_318 )
args . V_235 . V_320 . V_321 = F_25 ( V_266 ) ;
else
args . V_235 . V_320 . V_130 = F_25 ( V_8 -> V_131 / 10 ) ;
args . V_235 . V_320 . V_237 = F_31 ( V_2 ) ;
if ( args . V_235 . V_320 . V_237 == V_195 ) {
if ( V_223 == 270000 )
args . V_235 . V_320 . V_240 |= V_322 ;
else if ( V_223 == 540000 )
args . V_235 . V_320 . V_240 |= V_323 ;
args . V_235 . V_320 . V_239 = V_224 ;
} else if ( V_8 -> V_131 > 165000 )
args . V_235 . V_320 . V_239 = 8 ;
else
args . V_235 . V_320 . V_239 = 4 ;
switch ( V_314 ) {
case V_324 :
args . V_235 . V_320 . V_240 |= V_325 ;
break;
case V_326 :
args . V_235 . V_320 . V_240 |= V_327 ;
break;
case V_328 :
args . V_235 . V_320 . V_240 |= V_329 ;
break;
}
switch ( V_227 ) {
case 0 :
args . V_235 . V_320 . V_246 = V_247 ;
break;
case 6 :
args . V_235 . V_320 . V_246 = V_248 ;
break;
case 8 :
default:
args . V_235 . V_320 . V_246 = V_249 ;
break;
case 10 :
args . V_235 . V_320 . V_246 = V_250 ;
break;
case 12 :
args . V_235 . V_320 . V_246 = V_251 ;
break;
case 16 :
args . V_235 . V_320 . V_246 = V_252 ;
break;
}
break;
default:
F_33 ( L_3 , V_166 , V_167 ) ;
return;
}
break;
default:
F_33 ( L_3 , V_166 , V_167 ) ;
return;
}
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
static void
F_45 ( struct V_1 * V_2 , bool V_330 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_282 * V_282 = F_39 ( V_2 -> V_281 ) ;
T_7 args ;
int V_109 = F_24 ( V_113 , V_331 ) ;
T_1 V_332 , V_333 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( V_6 -> V_12 >= V_13 )
V_333 = V_334 ;
else
V_333 = V_335 ;
V_332 = F_46 ( V_333 ) ;
if ( V_8 -> V_63 & ( V_99 ) )
F_47 ( V_333 , ( V_336 |
( V_282 -> V_337 << 18 ) ) ) ;
else if ( V_8 -> V_63 & ( V_26 ) )
F_47 ( V_333 , ( V_338 | ( V_282 -> V_337 << 24 ) ) ) ;
else
F_47 ( V_333 , 0 ) ;
if ( V_330 )
args . V_159 = V_339 ;
args . V_340 = V_282 -> V_337 ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
F_47 ( V_333 , V_332 ) ;
}
static void
F_48 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_310 = F_15 ( V_2 ) ;
T_8 args ;
int V_109 = 0 ;
bool V_341 = false ;
bool V_342 = false ;
bool V_343 = false ;
memset ( & args , 0 , sizeof( args ) ) ;
F_12 ( L_4 ,
V_8 -> V_48 , V_97 , V_8 -> V_14 ,
V_8 -> V_63 ) ;
switch ( V_8 -> V_48 ) {
case V_50 :
case V_51 :
V_109 = F_24 ( V_113 , V_344 ) ;
break;
case V_56 :
case V_58 :
case V_59 :
case V_57 :
V_341 = true ;
break;
case V_53 :
case V_55 :
V_109 = F_24 ( V_113 , V_271 ) ;
break;
case V_54 :
if ( F_37 ( V_6 ) )
V_343 = true ;
else if ( F_21 ( V_6 ) )
V_341 = true ;
else
V_109 = F_24 ( V_113 , V_271 ) ;
break;
case V_49 :
V_109 = F_24 ( V_113 , V_345 ) ;
break;
case V_52 :
if ( V_8 -> V_14 & ( V_15 ) )
V_109 = F_24 ( V_113 , V_345 ) ;
else
V_109 = F_24 ( V_113 , V_346 ) ;
break;
case V_111 :
case V_112 :
if ( F_37 ( V_6 ) )
V_342 = true ;
else {
if ( V_8 -> V_63 & ( V_99 ) )
V_109 = F_24 ( V_113 , V_347 ) ;
else if ( V_8 -> V_63 & ( V_26 ) )
V_109 = F_24 ( V_113 , V_348 ) ;
else
V_109 = F_24 ( V_113 , V_349 ) ;
}
break;
case V_115 :
case V_116 :
if ( V_8 -> V_63 & ( V_99 ) )
V_109 = F_24 ( V_113 , V_347 ) ;
else if ( V_8 -> V_63 & ( V_26 ) )
V_109 = F_24 ( V_113 , V_348 ) ;
else
V_109 = F_24 ( V_113 , V_350 ) ;
break;
}
if ( V_341 ) {
switch ( V_97 ) {
case V_351 :
if ( ( V_6 -> V_12 == V_352 ) || ( V_6 -> V_12 == V_353 ) )
F_38 ( V_2 , V_354 , 0 , 0 ) ;
else
F_38 ( V_2 , V_355 , 0 , 0 ) ;
if ( F_31 ( V_2 ) == V_195 ) {
struct V_60 * V_61 = F_13 ( V_2 ) ;
if ( V_61 &&
( V_61 -> V_197 == V_214 ) ) {
struct V_62 * V_62 = F_9 ( V_61 ) ;
struct V_193 * V_356 =
V_62 -> V_210 ;
F_41 ( V_61 ,
V_307 ) ;
V_356 -> V_357 = true ;
}
if ( F_35 ( V_6 ) )
F_36 ( V_2 , V_358 , 0 ) ;
F_49 ( V_2 , V_61 ) ;
if ( F_35 ( V_6 ) )
F_36 ( V_2 , V_359 , 0 ) ;
}
if ( V_8 -> V_14 & ( V_15 ) )
F_38 ( V_2 , V_360 , 0 , 0 ) ;
break;
case V_361 :
case V_362 :
case V_363 :
F_38 ( V_2 , V_364 , 0 , 0 ) ;
if ( F_31 ( V_2 ) == V_195 ) {
struct V_60 * V_61 = F_13 ( V_2 ) ;
if ( F_35 ( V_6 ) )
F_36 ( V_2 , V_358 , 0 ) ;
if ( V_61 &&
( V_61 -> V_197 == V_214 ) ) {
struct V_62 * V_62 = F_9 ( V_61 ) ;
struct V_193 * V_356 =
V_62 -> V_210 ;
F_41 ( V_61 ,
V_308 ) ;
V_356 -> V_357 = false ;
}
}
if ( V_8 -> V_14 & ( V_15 ) )
F_38 ( V_2 , V_365 , 0 , 0 ) ;
break;
}
} else if ( V_342 ) {
switch ( V_97 ) {
case V_351 :
F_23 ( V_2 , V_339 ) ;
break;
case V_361 :
case V_362 :
case V_363 :
F_23 ( V_2 , V_366 ) ;
break;
}
} else if ( V_343 ) {
switch ( V_97 ) {
case V_351 :
F_28 ( V_2 , V_339 ) ;
break;
case V_361 :
case V_362 :
case V_363 :
F_28 ( V_2 , V_366 ) ;
break;
}
} else {
switch ( V_97 ) {
case V_351 :
args . V_118 = V_339 ;
if ( V_8 -> V_48 == V_55 ) {
T_6 V_333 = F_46 ( V_335 ) ;
F_47 ( V_335 , V_333 & ~ V_367 ) ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
F_47 ( V_335 , V_333 ) ;
} else
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
if ( V_8 -> V_14 & ( V_15 ) ) {
args . V_118 = V_368 ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
break;
case V_361 :
case V_362 :
case V_363 :
args . V_118 = V_366 ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
if ( V_8 -> V_14 & ( V_15 ) ) {
args . V_118 = V_369 ;
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
}
break;
}
}
if ( V_310 ) {
switch ( V_97 ) {
case V_351 :
default:
if ( F_50 ( V_6 ) ) {
F_44 ( V_2 , V_310 ,
V_370 ) ;
F_44 ( V_2 , V_310 ,
V_371 ) ;
} else
F_44 ( V_2 , V_310 , V_339 ) ;
break;
case V_361 :
case V_362 :
case V_363 :
if ( F_50 ( V_6 ) ) {
F_44 ( V_2 , V_310 ,
V_372 ) ;
F_44 ( V_2 , V_310 ,
V_373 ) ;
} else
F_44 ( V_2 , V_310 , V_366 ) ;
break;
}
}
F_51 ( V_2 , ( V_97 == V_351 ) ? true : false ) ;
}
static void
F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_282 * V_282 = F_39 ( V_2 -> V_281 ) ;
union V_374 args ;
int V_109 = F_24 ( V_113 , V_375 ) ;
T_2 V_166 , V_167 ;
struct V_162 * V_163 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_32 ( V_6 -> V_132 . V_133 , V_109 , & V_166 , & V_167 ) )
return;
switch ( V_166 ) {
case 1 :
switch ( V_167 ) {
case 1 :
default:
if ( F_6 ( V_6 ) )
args . V_172 . V_340 = V_282 -> V_337 ;
else {
if ( V_8 -> V_48 == V_111 ) {
args . V_172 . V_340 = V_282 -> V_337 ;
} else {
args . V_172 . V_340 = V_282 -> V_337 << 2 ;
}
}
switch ( V_8 -> V_48 ) {
case V_50 :
case V_51 :
args . V_172 . V_376 = V_152 ;
break;
case V_49 :
case V_52 :
if ( V_8 -> V_14 & V_36 )
args . V_172 . V_376 = V_377 ;
else
args . V_172 . V_376 = V_378 ;
break;
case V_53 :
case V_55 :
case V_54 :
args . V_172 . V_376 = V_379 ;
break;
case V_111 :
case V_112 :
if ( V_8 -> V_63 & ( V_99 ) )
args . V_172 . V_376 = V_380 ;
else if ( V_8 -> V_63 & ( V_26 ) )
args . V_172 . V_376 = V_381 ;
else
args . V_172 . V_376 = V_382 ;
break;
case V_115 :
case V_116 :
if ( V_8 -> V_63 & ( V_99 ) )
args . V_172 . V_376 = V_380 ;
else if ( V_8 -> V_63 & ( V_26 ) )
args . V_172 . V_376 = V_381 ;
else
args . V_172 . V_376 = V_383 ;
break;
}
break;
case 2 :
args . V_178 . V_340 = V_282 -> V_337 ;
if ( F_16 ( V_2 ) ) {
struct V_60 * V_61 = F_13 ( V_2 ) ;
if ( V_61 -> V_197 == V_207 )
args . V_178 . V_384 = V_208 ;
else if ( V_61 -> V_197 == V_216 )
args . V_178 . V_384 = V_204 ;
else
args . V_178 . V_384 = F_31 ( V_2 ) ;
} else
args . V_178 . V_384 = F_31 ( V_2 ) ;
switch ( V_8 -> V_48 ) {
case V_56 :
case V_58 :
case V_59 :
case V_57 :
V_163 = V_8 -> V_102 ;
switch ( V_163 -> V_230 ) {
case 0 :
args . V_178 . V_385 = V_386 ;
break;
case 1 :
args . V_178 . V_385 = V_387 ;
break;
case 2 :
args . V_178 . V_385 = V_388 ;
break;
case 3 :
args . V_178 . V_385 = V_389 ;
break;
case 4 :
args . V_178 . V_385 = V_390 ;
break;
case 5 :
args . V_178 . V_385 = V_391 ;
break;
}
break;
case V_54 :
args . V_178 . V_385 = V_392 ;
break;
case V_112 :
if ( V_8 -> V_63 & ( V_99 ) )
args . V_178 . V_385 = V_393 ;
else if ( V_8 -> V_63 & ( V_26 ) )
args . V_178 . V_385 = V_393 ;
else
args . V_178 . V_385 = V_394 ;
break;
case V_116 :
if ( V_8 -> V_63 & ( V_99 ) )
args . V_178 . V_385 = V_393 ;
else if ( V_8 -> V_63 & ( V_26 ) )
args . V_178 . V_385 = V_393 ;
else
args . V_178 . V_385 = V_395 ;
break;
}
break;
}
break;
default:
F_33 ( L_3 , V_166 , V_167 ) ;
return;
}
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
F_53 ( V_2 , V_282 -> V_337 ) ;
}
static void
F_54 ( struct V_1 * V_2 ,
struct V_70 * V_97 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_282 * V_282 = F_39 ( V_2 -> V_281 ) ;
if ( ( V_4 -> V_396 -> V_397 == 0x71C5 ) &&
( V_4 -> V_396 -> V_398 == 0x106b ) &&
( V_4 -> V_396 -> V_399 == 0x0080 ) ) {
if ( V_8 -> V_14 & V_36 ) {
T_1 V_400 = F_46 ( V_401 ) ;
V_400 &= ~ V_402 ;
V_400 &= ~ V_403 ;
F_47 ( V_401 , V_400 ) ;
}
}
if ( F_6 ( V_6 ) &&
( ! ( V_8 -> V_63 & ( V_99 ) ) ) ) {
if ( F_35 ( V_6 ) ) {
if ( V_97 -> V_87 & V_98 )
F_47 ( V_404 + V_282 -> V_405 ,
V_406 ) ;
else
F_47 ( V_404 + V_282 -> V_405 , 0 ) ;
} else {
if ( V_97 -> V_87 & V_98 )
F_47 ( V_407 + V_282 -> V_405 ,
V_408 ) ;
else
F_47 ( V_407 + V_282 -> V_405 , 0 ) ;
}
}
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_282 * V_282 = F_39 ( V_2 -> V_281 ) ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_409 ;
struct V_162 * V_163 ;
T_1 V_410 = 0 ;
if ( F_35 ( V_6 ) ) {
V_163 = V_8 -> V_102 ;
if ( F_50 ( V_6 ) ) {
if ( V_6 -> V_12 == V_411 ) {
if ( V_163 -> V_176 )
return 1 ;
else
return 0 ;
} else
return V_282 -> V_337 ;
} else {
switch ( V_8 -> V_48 ) {
case V_56 :
if ( V_163 -> V_176 )
return 1 ;
else
return 0 ;
break;
case V_58 :
if ( V_163 -> V_176 )
return 3 ;
else
return 2 ;
break;
case V_59 :
if ( V_163 -> V_176 )
return 5 ;
else
return 4 ;
break;
}
}
}
if ( F_40 ( V_6 ) ) {
return V_282 -> V_337 ;
}
F_3 (test_encoder, &dev->mode_config.encoder_list, head) {
struct V_8 * V_412 ;
if ( V_2 == V_409 )
continue;
if ( ! F_7 ( V_409 ) )
continue;
V_412 = F_2 ( V_409 ) ;
V_163 = V_412 -> V_102 ;
if ( V_163 -> V_230 >= 0 )
V_410 |= ( 1 << V_163 -> V_230 ) ;
}
if ( V_8 -> V_48 == V_57 ) {
if ( V_410 & 0x2 )
F_33 ( L_5 ) ;
return 1 ;
}
if ( ! ( V_410 & 1 ) )
return 0 ;
return 1 ;
}
void
F_56 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_413 ;
struct V_1 * V_2 ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_310 = F_15 ( V_2 ) ;
switch ( V_8 -> V_48 ) {
case V_56 :
case V_58 :
case V_59 :
case V_57 :
F_38 ( V_2 , V_268 , 0 , 0 ) ;
break;
default:
break;
}
if ( V_310 && F_50 ( V_6 ) )
F_44 ( V_2 , V_310 ,
V_318 ) ;
}
}
static void
F_57 ( struct V_1 * V_2 ,
struct V_70 * V_97 ,
struct V_70 * V_71 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_310 = F_15 ( V_2 ) ;
V_8 -> V_131 = V_71 -> clock ;
if ( F_6 ( V_6 ) && ! F_35 ( V_6 ) ) {
if ( V_8 -> V_63 & ( V_26 | V_99 ) )
F_45 ( V_2 , true ) ;
else
F_45 ( V_2 , false ) ;
}
switch ( V_8 -> V_48 ) {
case V_50 :
case V_51 :
case V_49 :
case V_52 :
F_30 ( V_2 , V_414 ) ;
break;
case V_56 :
case V_58 :
case V_59 :
case V_57 :
if ( F_35 ( V_6 ) ) {
F_38 ( V_2 , V_415 , 0 , 0 ) ;
F_36 ( V_2 , V_416 , 0 ) ;
F_38 ( V_2 , V_354 , 0 , 0 ) ;
} else {
F_38 ( V_2 , V_415 , 0 , 0 ) ;
F_36 ( V_2 , V_366 , 0 ) ;
F_36 ( V_2 , V_339 , 0 ) ;
F_38 ( V_2 , V_417 , 0 , 0 ) ;
F_38 ( V_2 , V_354 , 0 , 0 ) ;
}
break;
case V_55 :
case V_53 :
case V_54 :
F_28 ( V_2 , V_339 ) ;
break;
case V_111 :
case V_112 :
case V_115 :
case V_116 :
F_23 ( V_2 , V_339 ) ;
if ( V_8 -> V_14 & ( V_99 | V_26 ) ) {
if ( V_8 -> V_63 & ( V_99 | V_26 ) )
F_27 ( V_2 , V_339 ) ;
else
F_27 ( V_2 , V_366 ) ;
}
break;
}
if ( V_310 ) {
if ( F_50 ( V_6 ) )
F_44 ( V_2 , V_310 ,
V_418 ) ;
else
F_44 ( V_2 , V_310 , V_339 ) ;
}
F_54 ( V_2 , V_71 ) ;
if ( F_31 ( V_2 ) == V_168 ) {
F_58 ( V_2 ) ;
F_59 ( V_2 , V_71 ) ;
}
}
static bool
F_60 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_62 * V_62 = F_9 ( V_61 ) ;
if ( V_8 -> V_14 & ( V_99 |
V_26 |
V_119 ) ) {
T_9 args ;
int V_109 = F_24 ( V_113 , V_419 ) ;
T_2 V_166 , V_167 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_32 ( V_6 -> V_132 . V_133 , V_109 , & V_166 , & V_167 ) )
return false ;
args . V_420 . V_160 = 0 ;
if ( ( V_8 -> V_48 == V_111 ) ||
( V_8 -> V_48 == V_112 ) )
args . V_420 . V_421 = V_422 ;
else
args . V_420 . V_421 = V_423 ;
if ( V_62 -> V_14 & V_22 )
args . V_420 . V_424 = F_25 ( V_22 ) ;
else if ( V_62 -> V_14 & V_25 )
args . V_420 . V_424 = F_25 ( V_25 ) ;
else if ( V_62 -> V_14 & V_26 ) {
args . V_420 . V_424 = F_25 ( V_26 ) ;
if ( V_167 >= 3 )
args . V_420 . V_160 = V_425 ;
} else if ( V_62 -> V_14 & V_23 ) {
args . V_420 . V_424 = F_25 ( V_23 ) ;
if ( V_167 >= 3 )
args . V_420 . V_160 = V_425 ;
}
F_26 ( V_6 -> V_132 . V_133 , V_109 , ( T_1 * ) & args ) ;
return true ;
} else
return false ;
}
static enum V_426
F_61 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_62 * V_62 = F_9 ( V_61 ) ;
T_1 V_427 ;
if ( ! F_60 ( V_2 , V_61 ) ) {
F_12 ( L_6 ) ;
return V_428 ;
}
if ( V_6 -> V_12 >= V_13 )
V_427 = F_46 ( V_429 ) ;
else
V_427 = F_46 ( V_430 ) ;
F_12 ( L_7 , V_427 , V_8 -> V_14 ) ;
if ( V_62 -> V_14 & V_22 ) {
if ( V_427 & V_431 )
return V_432 ;
}
if ( V_62 -> V_14 & V_25 ) {
if ( V_427 & V_433 )
return V_432 ;
}
if ( V_62 -> V_14 & V_26 ) {
if ( V_427 & ( V_434 | V_435 ) )
return V_432 ;
}
if ( V_62 -> V_14 & V_23 ) {
if ( V_427 & ( V_436 | V_437 ) )
return V_432 ;
else if ( V_427 & ( V_438 | V_439 ) )
return V_432 ;
}
return V_440 ;
}
static enum V_426
F_62 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_62 * V_62 = F_9 ( V_61 ) ;
struct V_1 * V_310 = F_15 ( V_2 ) ;
T_6 V_427 ;
if ( ! F_35 ( V_6 ) )
return V_428 ;
if ( ! V_310 )
return V_428 ;
if ( ( V_62 -> V_14 & V_119 ) == 0 )
return V_428 ;
F_44 ( V_2 , V_310 ,
V_441 ) ;
V_427 = F_46 ( V_429 ) ;
F_12 ( L_7 , V_427 , V_8 -> V_14 ) ;
if ( V_62 -> V_14 & V_22 ) {
if ( V_427 & V_431 )
return V_432 ;
}
if ( V_62 -> V_14 & V_25 ) {
if ( V_427 & V_433 )
return V_432 ;
}
if ( V_62 -> V_14 & V_26 ) {
if ( V_427 & ( V_434 | V_435 ) )
return V_432 ;
}
if ( V_62 -> V_14 & V_23 ) {
if ( V_427 & ( V_436 | V_437 ) )
return V_432 ;
else if ( V_427 & ( V_438 | V_439 ) )
return V_432 ;
}
return V_440 ;
}
void
F_63 ( struct V_1 * V_2 )
{
struct V_1 * V_310 = F_15 ( V_2 ) ;
if ( V_310 )
F_44 ( V_2 , V_310 ,
V_442 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_60 * V_61 = F_13 ( V_2 ) ;
if ( ( V_8 -> V_63 &
( V_107 | V_15 ) ) ||
F_16 ( V_2 ) ) {
struct V_162 * V_163 = V_8 -> V_102 ;
if ( V_163 )
V_163 -> V_230 = F_55 ( V_2 ) ;
}
F_65 ( V_2 , true ) ;
F_48 ( V_2 , V_363 ) ;
if ( V_61 ) {
struct V_62 * V_62 = F_9 ( V_61 ) ;
if ( V_62 -> V_443 . V_444 )
F_66 ( V_62 ) ;
if ( V_61 -> V_197 == V_214 )
F_41 ( V_61 ,
V_307 ) ;
}
F_52 ( V_2 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_48 ( V_2 , V_351 ) ;
F_65 ( V_2 , false ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_162 * V_163 ;
if ( ! F_21 ( V_6 ) ) {
struct V_1 * V_65 ;
struct V_8 * V_66 ;
F_3 (other_encoder, &dev->mode_config.encoder_list, head) {
V_66 = F_2 ( V_65 ) ;
if ( ( V_8 -> V_48 == V_66 -> V_48 ) &&
F_69 ( V_65 ) )
goto V_445;
}
}
F_48 ( V_2 , V_363 ) ;
switch ( V_8 -> V_48 ) {
case V_50 :
case V_51 :
case V_49 :
case V_52 :
F_30 ( V_2 , V_446 ) ;
break;
case V_56 :
case V_58 :
case V_59 :
case V_57 :
if ( F_35 ( V_6 ) )
F_38 ( V_2 , V_415 , 0 , 0 ) ;
else {
F_38 ( V_2 , V_415 , 0 , 0 ) ;
F_36 ( V_2 , V_366 , 0 ) ;
}
break;
case V_55 :
case V_53 :
case V_54 :
F_28 ( V_2 , V_366 ) ;
break;
case V_111 :
case V_112 :
case V_115 :
case V_116 :
F_23 ( V_2 , V_366 ) ;
if ( V_8 -> V_14 & ( V_99 | V_26 ) )
F_27 ( V_2 , V_366 ) ;
break;
}
V_445:
if ( F_7 ( V_2 ) ) {
if ( F_31 ( V_2 ) == V_168 )
F_70 ( V_2 ) ;
V_163 = V_8 -> V_102 ;
V_163 -> V_230 = - 1 ;
}
V_8 -> V_63 = 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
}
static void F_72 ( struct V_1 * V_2 )
{
}
static void
F_73 ( struct V_1 * V_2 ,
struct V_70 * V_97 ,
struct V_70 * V_71 )
{
}
static void F_74 ( struct V_1 * V_2 )
{
}
static void
F_75 ( struct V_1 * V_2 , int V_97 )
{
}
static bool F_76 ( struct V_1 * V_2 ,
struct V_70 * V_97 ,
struct V_70 * V_71 )
{
return true ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
F_78 ( V_8 -> V_102 ) ;
F_79 ( V_2 ) ;
F_78 ( V_8 ) ;
}
struct V_100 *
F_80 ( struct V_8 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_305 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_100 * V_20 = F_81 ( sizeof( struct V_100 ) , V_447 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_103 = F_82 ( V_6 ) ;
return V_20 ;
}
struct V_162 *
F_83 ( struct V_8 * V_8 )
{
int V_315 = ( V_8 -> V_315 & V_316 ) >> V_317 ;
struct V_162 * V_163 = F_81 ( sizeof( struct V_162 ) , V_447 ) ;
if ( ! V_163 )
return NULL ;
V_163 -> V_179 = true ;
V_163 -> V_230 = - 1 ;
if ( V_315 == 2 )
V_163 -> V_176 = true ;
else
V_163 -> V_176 = false ;
return V_163 ;
}
void
F_84 ( struct V_3 * V_4 ,
T_1 V_315 ,
T_1 V_19 ,
T_10 V_448 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_315 == V_315 ) {
V_8 -> V_14 |= V_19 ;
return;
}
}
V_8 = F_81 ( sizeof( struct V_8 ) , V_447 ) ;
if ( ! V_8 )
return;
V_2 = & V_8 -> V_305 ;
switch ( V_6 -> V_449 ) {
case 1 :
V_2 -> V_450 = 0x1 ;
break;
case 2 :
default:
V_2 -> V_450 = 0x3 ;
break;
case 4 :
V_2 -> V_450 = 0xf ;
break;
case 6 :
V_2 -> V_450 = 0x3f ;
break;
}
V_8 -> V_102 = NULL ;
V_8 -> V_315 = V_315 ;
V_8 -> V_48 = ( V_315 & V_269 ) >> V_270 ;
V_8 -> V_14 = V_19 ;
V_8 -> V_451 = V_452 ;
V_8 -> V_453 = V_454 ;
V_8 -> V_67 = false ;
V_8 -> V_448 = V_448 ;
switch ( V_8 -> V_48 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
if ( V_8 -> V_14 & ( V_15 ) ) {
V_8 -> V_451 = V_455 ;
F_85 ( V_4 , V_2 , & V_456 , V_457 ) ;
V_8 -> V_102 = F_86 ( V_8 ) ;
} else {
F_85 ( V_4 , V_2 , & V_456 , V_458 ) ;
V_8 -> V_102 = F_83 ( V_8 ) ;
}
F_87 ( V_2 , & V_459 ) ;
break;
case V_111 :
F_85 ( V_4 , V_2 , & V_456 , V_460 ) ;
V_8 -> V_102 = F_80 ( V_8 ) ;
F_87 ( V_2 , & V_461 ) ;
break;
case V_115 :
case V_112 :
case V_116 :
F_85 ( V_4 , V_2 , & V_456 , V_462 ) ;
V_8 -> V_102 = F_80 ( V_8 ) ;
F_87 ( V_2 , & V_461 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
if ( V_8 -> V_14 & ( V_15 ) ) {
V_8 -> V_451 = V_455 ;
F_85 ( V_4 , V_2 , & V_456 , V_457 ) ;
V_8 -> V_102 = F_86 ( V_8 ) ;
} else if ( V_8 -> V_14 & ( V_119 ) ) {
F_85 ( V_4 , V_2 , & V_456 , V_460 ) ;
V_8 -> V_102 = F_83 ( V_8 ) ;
} else {
F_85 ( V_4 , V_2 , & V_456 , V_458 ) ;
V_8 -> V_102 = F_83 ( V_8 ) ;
}
F_87 ( V_2 , & V_459 ) ;
break;
case V_463 :
case V_464 :
case V_465 :
case V_466 :
case V_467 :
case V_468 :
case V_469 :
case V_68 :
case V_69 :
V_8 -> V_67 = true ;
if ( V_8 -> V_14 & ( V_15 ) )
F_85 ( V_4 , V_2 , & V_456 , V_457 ) ;
else if ( V_8 -> V_14 & ( V_119 ) )
F_85 ( V_4 , V_2 , & V_456 , V_460 ) ;
else
F_85 ( V_4 , V_2 , & V_456 , V_458 ) ;
F_87 ( V_2 , & V_470 ) ;
break;
}
}
