static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_1 args ;
int V_12 = F_3 ( V_13 , V_14 ) ;
int V_15 , V_16 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
switch ( V_11 -> V_19 ) {
case V_20 :
args . V_21 = F_4 ( ( V_5 -> V_22 - V_4 -> V_22 ) / 2 ) ;
args . V_23 = F_4 ( ( V_5 -> V_22 - V_4 -> V_22 ) / 2 ) ;
args . V_24 = F_4 ( ( V_5 -> V_25 - V_4 -> V_25 ) / 2 ) ;
args . V_26 = F_4 ( ( V_5 -> V_25 - V_4 -> V_25 ) / 2 ) ;
break;
case V_27 :
V_15 = V_4 -> V_22 * V_5 -> V_25 ;
V_16 = V_5 -> V_22 * V_4 -> V_25 ;
if ( V_15 > V_16 ) {
args . V_24 = F_4 ( ( V_5 -> V_25 - ( V_16 / V_4 -> V_22 ) ) / 2 ) ;
args . V_26 = F_4 ( ( V_5 -> V_25 - ( V_16 / V_4 -> V_22 ) ) / 2 ) ;
} else if ( V_16 > V_15 ) {
args . V_21 = F_4 ( ( V_5 -> V_22 - ( V_15 / V_4 -> V_25 ) ) / 2 ) ;
args . V_23 = F_4 ( ( V_5 -> V_22 - ( V_15 / V_4 -> V_25 ) ) / 2 ) ;
}
break;
case V_28 :
default:
args . V_26 = F_4 ( V_11 -> V_29 ) ;
args . V_24 = F_4 ( V_11 -> V_29 ) ;
args . V_23 = F_4 ( V_11 -> V_30 ) ;
args . V_21 = F_4 ( V_11 -> V_30 ) ;
break;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_2 args ;
int V_12 = F_3 ( V_13 , V_34 ) ;
enum V_35 V_36 = V_37 ;
bool V_38 = false , V_39 = false ;
struct V_40 * V_41 ;
if ( ! F_7 ( V_9 ) && V_11 -> V_18 )
return;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
struct V_42 * V_42 = F_9 ( V_41 ) ;
if ( V_42 -> V_43 & V_44 ) {
struct V_45 * V_46 = V_42 -> V_47 ;
V_36 = V_46 -> V_36 ;
V_38 = true ;
}
}
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_48 = V_11 -> V_18 ;
if ( V_38 ) {
switch ( V_36 ) {
case V_37 :
default:
args . V_49 = V_50 ;
break;
case V_51 :
args . V_49 = V_52 ;
break;
case V_53 :
args . V_49 = V_54 ;
break;
case V_55 :
args . V_49 = V_56 ;
break;
case V_57 :
args . V_49 = V_58 ;
break;
case V_59 :
args . V_49 = V_52 ;
break;
case V_60 :
args . V_49 = V_61 ;
break;
case V_62 :
args . V_49 = V_63 ;
break;
}
args . V_64 = V_65 ;
} else if ( V_39 ) {
args . V_49 = V_66 ;
args . V_64 = V_65 ;
} else {
switch ( V_11 -> V_19 ) {
case V_28 :
args . V_64 = V_67 ;
break;
case V_20 :
args . V_64 = V_68 ;
break;
case V_27 :
args . V_64 = V_67 ;
break;
default:
if ( F_7 ( V_9 ) )
args . V_64 = V_69 ;
else
args . V_64 = V_68 ;
break;
}
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
if ( ( V_38 || V_39 )
&& V_9 -> V_70 >= V_71 && V_9 -> V_70 <= V_72 ) {
F_10 ( V_9 , V_11 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_73 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 =
F_3 ( V_13 , V_74 ) ;
T_3 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_64 = V_73 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_75 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_76 ) ;
T_3 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_64 = V_75 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_75 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_77 ) ;
T_3 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_64 = V_75 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_75 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_78 ) ;
T_4 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_79 = V_75 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
void F_15 ( struct V_1 * V_2 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_80 :
V_11 -> V_81 = true ;
F_16 ( V_9 ) ;
F_12 ( V_2 , V_82 ) ;
if ( F_17 ( V_9 ) )
F_13 ( V_2 , V_82 ) ;
F_14 ( V_2 , V_83 ) ;
F_18 ( V_7 , V_11 -> V_18 ) ;
F_19 ( V_2 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
F_20 ( V_7 , V_11 -> V_18 ) ;
if ( V_11 -> V_81 )
F_14 ( V_2 , V_82 ) ;
if ( F_17 ( V_9 ) )
F_13 ( V_2 , V_83 ) ;
F_12 ( V_2 , V_83 ) ;
V_11 -> V_81 = false ;
F_16 ( V_9 ) ;
break;
}
}
static void
F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_5 args ;
int V_12 = F_3 ( V_13 , V_87 ) ;
T_6 V_88 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_89 = F_4 ( V_4 -> V_25 - ( V_11 -> V_29 * 2 ) ) ;
args . V_90 =
F_4 ( V_4 -> V_91 - V_4 -> V_25 + ( V_11 -> V_29 * 2 ) ) ;
args . V_92 = F_4 ( V_4 -> V_22 - ( V_11 -> V_30 * 2 ) ) ;
args . V_93 =
F_4 ( V_4 -> V_94 - V_4 -> V_22 + ( V_11 -> V_30 * 2 ) ) ;
args . V_95 =
F_4 ( V_4 -> V_96 - V_4 -> V_25 + V_11 -> V_29 ) ;
args . V_97 =
F_4 ( V_4 -> V_98 - V_4 -> V_96 ) ;
args . V_99 =
F_4 ( V_4 -> V_100 - V_4 -> V_22 + V_11 -> V_30 ) ;
args . V_101 =
F_4 ( V_4 -> V_102 - V_4 -> V_100 ) ;
args . V_103 = V_11 -> V_29 ;
args . V_104 = V_11 -> V_30 ;
if ( V_4 -> V_105 & V_106 )
V_88 |= V_107 ;
if ( V_4 -> V_105 & V_108 )
V_88 |= V_109 ;
if ( V_4 -> V_105 & V_110 )
V_88 |= V_111 ;
if ( V_4 -> V_105 & V_112 )
V_88 |= V_113 ;
if ( V_4 -> V_105 & V_114 )
V_88 |= V_115 ;
args . V_116 . V_117 = F_4 ( V_88 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_7 args ;
int V_12 = F_3 ( V_13 , V_118 ) ;
T_6 V_88 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_119 = F_4 ( V_4 -> V_120 ) ;
args . V_121 = F_4 ( V_4 -> V_25 ) ;
args . V_122 = F_4 ( V_4 -> V_96 ) ;
args . V_97 =
F_4 ( V_4 -> V_98 - V_4 -> V_96 ) ;
args . V_123 = F_4 ( V_4 -> V_124 ) ;
args . V_125 = F_4 ( V_4 -> V_22 ) ;
args . V_126 = F_4 ( V_4 -> V_100 ) ;
args . V_101 =
F_4 ( V_4 -> V_102 - V_4 -> V_100 ) ;
args . V_127 = V_11 -> V_29 ;
args . V_128 = V_11 -> V_29 ;
args . V_129 = V_11 -> V_30 ;
args . V_130 = V_11 -> V_30 ;
if ( V_4 -> V_105 & V_106 )
V_88 |= V_107 ;
if ( V_4 -> V_105 & V_108 )
V_88 |= V_109 ;
if ( V_4 -> V_105 & V_110 )
V_88 |= V_111 ;
if ( V_4 -> V_105 & V_112 )
V_88 |= V_113 ;
if ( V_4 -> V_105 & V_114 )
V_88 |= V_115 ;
args . V_116 . V_117 = F_4 ( V_88 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_23 ( struct V_8 * V_9 , int V_131 )
{
T_8 V_132 ;
if ( F_24 ( V_9 ) ) {
switch ( V_131 ) {
case V_133 :
V_132 = F_25 ( V_134 ) ;
V_132 &= ~ V_135 ;
F_26 ( V_134 , V_132 ) ;
break;
case V_136 :
V_132 = F_25 ( V_137 ) ;
V_132 &= ~ V_135 ;
F_26 ( V_137 , V_132 ) ;
break;
case V_138 :
case V_139 :
return;
}
} else if ( F_7 ( V_9 ) ) {
switch ( V_131 ) {
case V_133 :
V_132 = F_25 ( V_140 ) ;
V_132 &= ~ 1 ;
F_26 ( V_140 , V_132 ) ;
break;
case V_136 :
V_132 = F_25 ( V_141 ) ;
V_132 &= ~ 1 ;
F_26 ( V_141 , V_132 ) ;
break;
case V_138 :
case V_139 :
return;
}
}
}
static void F_27 ( struct V_8 * V_9 ,
int V_142 ,
int V_131 ,
struct V_143 * V_144 )
{
int V_12 = F_3 ( V_13 , V_145 ) ;
union V_146 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_28 ( V_9 ) ) {
args . V_147 . V_148 = F_4 ( 0 ) ;
args . V_147 . V_149 = V_144 -> type & V_150 ;
switch ( V_131 ) {
case V_133 :
args . V_147 . V_149 |= V_151 ;
args . V_147 . V_152 = F_4 ( V_144 -> V_153 ) ;
args . V_147 . V_154 = F_4 ( V_144 -> V_155 ) ;
break;
case V_136 :
args . V_147 . V_149 |= V_156 ;
args . V_147 . V_152 = F_4 ( V_144 -> V_153 ) ;
args . V_147 . V_154 = F_4 ( V_144 -> V_155 ) ;
break;
case V_138 :
args . V_147 . V_149 |= V_157 ;
args . V_147 . V_152 = F_4 ( 0 ) ;
args . V_147 . V_154 = F_4 ( 0 ) ;
break;
case V_139 :
return;
}
args . V_147 . V_64 = V_142 ;
if ( ( V_144 -> V_158 == 0 ) || ( V_144 -> type & V_159 ) )
args . V_147 . V_64 = V_83 ;
} else if ( F_24 ( V_9 ) ) {
args . V_160 . V_161 = F_4 ( V_144 -> V_158 ) ;
args . V_160 . V_149 = V_144 -> type & V_150 ;
switch ( V_131 ) {
case V_133 :
args . V_160 . V_149 |= V_162 ;
args . V_160 . V_152 = F_4 ( V_144 -> V_153 ) ;
args . V_160 . V_154 = F_4 ( V_144 -> V_155 ) ;
break;
case V_136 :
args . V_160 . V_149 |= V_163 ;
args . V_160 . V_152 = F_4 ( V_144 -> V_153 ) ;
args . V_160 . V_154 = F_4 ( V_144 -> V_155 ) ;
break;
case V_138 :
args . V_160 . V_149 |= V_164 ;
args . V_160 . V_152 = F_4 ( 0 ) ;
args . V_160 . V_154 = F_4 ( 0 ) ;
break;
case V_139 :
return;
}
args . V_160 . V_64 = V_142 ;
if ( ( V_144 -> V_158 == 0 ) || ( V_144 -> type & V_159 ) || F_29 ( V_9 ) )
args . V_160 . V_64 = V_83 ;
} else if ( F_17 ( V_9 ) ) {
args . V_165 . V_161 = F_4 ( V_144 -> V_158 ) ;
args . V_165 . V_149 = V_144 -> type & V_150 ;
args . V_165 . V_166 = V_144 -> V_155 ;
args . V_165 . V_167 = V_144 -> V_168 ;
args . V_165 . V_169 = V_144 -> V_170 ;
args . V_165 . V_171 = V_131 ;
args . V_165 . V_64 = V_142 ;
} else if ( F_7 ( V_9 ) ) {
if ( ( V_142 == V_83 ) || ( V_144 -> V_158 == 0 ) ||
( V_144 -> type & V_159 ) ) {
F_23 ( V_9 , V_131 ) ;
return;
}
args . V_172 . V_161 = F_4 ( V_144 -> V_158 ) ;
args . V_172 . V_149 = V_144 -> type & V_150 ;
args . V_172 . V_166 = V_144 -> V_155 ;
args . V_172 . V_167 = V_144 -> V_168 ;
args . V_172 . V_169 = V_144 -> V_170 ;
args . V_172 . V_64 = V_142 ;
} else {
if ( ( V_142 == V_83 ) || ( V_144 -> V_158 == 0 ) ||
( V_144 -> type & V_159 ) ) {
F_23 ( V_9 , V_131 ) ;
return;
}
args . V_173 . V_161 = F_4 ( V_144 -> V_158 ) ;
args . V_173 . V_149 = V_144 -> type & V_150 ;
args . V_173 . V_174 = ( V_144 -> V_155 & 3 ) << 2 ;
args . V_173 . V_174 |= ( V_144 -> V_168 & 7 ) << 4 ;
args . V_173 . V_64 = V_142 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_8 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_175 * V_176 ,
bool V_177 ,
struct V_143 * V_144 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_42 = NULL ;
struct V_178 * V_179 = NULL ;
T_8 V_180 = V_4 -> clock ;
int V_181 = 0 ;
T_8 V_182 = V_4 -> clock ;
int V_183 = 8 ;
bool V_184 = false ;
V_176 -> V_105 = 0 ;
if ( F_7 ( V_9 ) ) {
if ( ( V_9 -> V_70 == V_185 ) ||
( V_9 -> V_70 == V_186 ) ||
( V_9 -> V_70 == V_187 ) )
V_176 -> V_105 |= (
V_188 ) ;
if ( F_31 ( V_9 ) && V_4 -> clock > 200000 )
V_176 -> V_105 |= V_189 ;
else
V_176 -> V_105 |= V_190 ;
if ( V_9 -> V_70 < V_191 )
V_176 -> V_105 |= V_192 ;
} else {
V_176 -> V_105 |= V_193 ;
if ( V_4 -> clock > 200000 )
V_176 -> V_105 |= V_189 ;
else
V_176 -> V_105 |= V_190 ;
}
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_179 = F_32 ( V_41 ) ;
if ( V_179 && V_179 -> V_194 . V_183 )
V_183 = V_179 -> V_194 . V_183 ;
V_181 = F_33 ( V_41 ) ;
V_184 = F_34 ( V_41 , V_4 -> clock ) ;
if ( ( V_42 -> V_195 & ( V_196 | V_197 ) ) ||
( F_35 ( V_41 ) != V_198 ) ) {
if ( V_179 ) {
struct V_199 * V_199 = F_36 ( V_179 ) ;
struct V_200 * V_201 =
V_199 -> V_202 ;
V_182 = V_201 -> V_182 ;
}
}
if ( V_42 -> V_195 & ( V_196 ) ) {
if ( V_177 ) {
if ( V_144 -> V_203 ) {
V_176 -> V_105 |= V_204 ;
V_176 -> V_205 = V_144 -> V_203 ;
if ( F_7 ( V_9 ) )
V_176 -> V_105 |= V_206 ;
}
}
}
if ( F_7 ( V_9 ) ) {
if ( V_42 -> V_207 == V_208 )
V_180 = V_4 -> clock * 2 ;
if ( V_42 -> V_43 & ( V_44 ) )
V_176 -> V_105 |= V_188 ;
if ( V_42 -> V_195 & ( V_196 ) )
V_176 -> V_105 |= V_209 ;
} else {
if ( V_41 -> V_210 != V_211 )
V_176 -> V_105 |= V_212 ;
if ( V_41 -> V_210 == V_213 )
V_176 -> V_105 |= V_204 ;
}
break;
}
}
if ( F_17 ( V_9 ) ) {
union V_214 args ;
T_9 V_215 , V_216 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_217 ) ;
if ( ! F_37 ( V_9 -> V_31 . V_32 , V_12 , & V_215 ,
& V_216 ) )
return V_180 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_215 ) {
case 1 :
switch ( V_216 ) {
case 1 :
case 2 :
args . V_165 . V_218 = F_4 ( V_4 -> clock / 10 ) ;
args . V_165 . V_219 = V_42 -> V_207 ;
args . V_165 . V_220 = V_181 ;
if ( V_177 && V_144 -> V_158 )
args . V_165 . V_221 |=
V_222 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_180 = F_38 ( args . V_165 . V_218 ) * 10 ;
break;
case 3 :
args . V_147 . V_223 . V_218 = F_4 ( V_4 -> clock / 10 ) ;
args . V_147 . V_223 . V_219 = V_42 -> V_207 ;
args . V_147 . V_223 . V_220 = V_181 ;
args . V_147 . V_223 . V_224 = 0 ;
if ( V_177 && V_144 -> V_158 )
args . V_147 . V_223 . V_224 |=
V_225 ;
if ( F_39 ( V_181 ) ) {
args . V_147 . V_223 . V_224 |=
V_226 ;
args . V_147 . V_223 . V_218 = F_4 ( V_182 / 10 ) ;
} else if ( V_42 -> V_195 & ( V_197 ) ) {
struct V_227 * V_228 = V_42 -> V_47 ;
if ( V_181 == V_229 )
args . V_147 . V_223 . V_218 =
F_4 ( ( V_4 -> clock * V_183 / 8 ) / 10 ) ;
if ( V_228 -> V_230 )
args . V_147 . V_223 . V_224 |=
V_226 ;
if ( V_184 )
args . V_147 . V_223 . V_224 |=
V_231 ;
}
if ( F_35 ( V_41 ) !=
V_198 )
args . V_147 . V_223 . V_232 =
F_35 ( V_41 ) ;
else
args . V_147 . V_223 . V_232 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_180 = F_40 ( args . V_147 . V_233 . V_234 ) * 10 ;
if ( args . V_147 . V_233 . V_235 ) {
V_176 -> V_105 |= V_206 ;
V_176 -> V_105 |= V_204 ;
V_176 -> V_205 = args . V_147 . V_233 . V_235 ;
}
if ( args . V_147 . V_233 . V_236 ) {
V_176 -> V_105 |= V_206 ;
V_176 -> V_105 |= V_237 ;
V_176 -> V_238 = args . V_147 . V_233 . V_236 ;
}
break;
default:
F_41 ( L_1 , V_215 , V_216 ) ;
return V_180 ;
}
break;
default:
F_41 ( L_1 , V_215 , V_216 ) ;
return V_180 ;
}
}
return V_180 ;
}
static void F_42 ( struct V_8 * V_9 ,
T_8 V_239 )
{
T_9 V_215 , V_216 ;
int V_12 ;
union V_240 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_241 ) ;
if ( ! F_37 ( V_9 -> V_31 . V_32 , V_12 , & V_215 ,
& V_216 ) )
return;
switch ( V_215 ) {
case 1 :
switch ( V_216 ) {
case 5 :
args . V_242 . V_17 = V_243 ;
args . V_242 . V_218 = F_4 ( V_239 ) ;
args . V_242 . V_171 = V_138 ;
break;
case 6 :
args . V_244 . V_245 = F_43 ( V_239 ) ;
args . V_244 . V_171 = V_138 ;
break;
default:
F_41 ( L_1 , V_215 , V_216 ) ;
return;
}
break;
default:
F_41 ( L_1 , V_215 , V_216 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_44 ( struct V_1 * V_2 ,
T_8 V_18 ,
int V_131 ,
T_8 V_181 ,
T_8 V_207 ,
T_8 clock ,
T_8 V_246 ,
T_8 V_247 ,
T_8 V_248 ,
T_8 V_238 ,
int V_183 ,
bool V_177 ,
struct V_143 * V_144 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_9 V_215 , V_216 ;
int V_12 = F_3 ( V_13 , V_241 ) ;
union V_240 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_37 ( V_9 -> V_31 . V_32 , V_12 , & V_215 ,
& V_216 ) )
return;
switch ( V_215 ) {
case 1 :
switch ( V_216 ) {
case 1 :
if ( clock == V_83 )
return;
args . V_165 . V_218 = F_4 ( clock / 10 ) ;
args . V_165 . V_249 = F_4 ( V_246 ) ;
args . V_165 . V_250 = F_4 ( V_247 ) ;
args . V_165 . V_251 = V_248 ;
args . V_165 . V_236 = V_238 ;
args . V_165 . V_171 = V_131 ;
args . V_165 . V_17 = V_18 ;
args . V_165 . V_252 = 1 ;
break;
case 2 :
args . V_160 . V_218 = F_4 ( clock / 10 ) ;
args . V_160 . V_249 = F_4 ( V_246 ) ;
args . V_160 . V_250 = F_4 ( V_247 ) ;
args . V_160 . V_251 = V_248 ;
args . V_160 . V_236 = V_238 ;
args . V_160 . V_171 = V_131 ;
args . V_160 . V_17 = V_18 ;
args . V_160 . V_252 = 1 ;
break;
case 3 :
args . V_147 . V_218 = F_4 ( clock / 10 ) ;
args . V_147 . V_249 = F_4 ( V_246 ) ;
args . V_147 . V_250 = F_4 ( V_247 ) ;
args . V_147 . V_251 = V_248 ;
args . V_147 . V_236 = V_238 ;
args . V_147 . V_171 = V_131 ;
args . V_147 . V_253 = ( V_131 << 2 ) ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_147 . V_253 |= V_254 ;
args . V_147 . V_255 = V_207 ;
args . V_147 . V_256 = V_181 ;
break;
case 5 :
args . V_242 . V_17 = V_18 ;
args . V_242 . V_218 = F_4 ( clock / 10 ) ;
args . V_242 . V_235 = V_246 ;
args . V_242 . V_250 = F_4 ( V_247 ) ;
args . V_242 . V_257 = F_43 ( V_248 * 100000 ) ;
args . V_242 . V_236 = V_238 ;
args . V_242 . V_253 = 0 ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_242 . V_253 |= V_258 ;
switch ( V_183 ) {
case 8 :
default:
args . V_242 . V_253 |= V_259 ;
break;
case 10 :
args . V_242 . V_253 |= V_260 ;
break;
}
args . V_242 . V_219 = V_207 ;
args . V_242 . V_256 = V_181 ;
args . V_242 . V_171 = V_131 ;
break;
case 6 :
args . V_244 . V_245 = F_43 ( V_18 << 24 | clock / 10 ) ;
args . V_244 . V_235 = V_246 ;
args . V_244 . V_250 = F_4 ( V_247 ) ;
args . V_244 . V_257 = F_43 ( V_248 * 100000 ) ;
args . V_244 . V_236 = V_238 ;
args . V_244 . V_253 = 0 ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_244 . V_253 |= V_261 ;
switch ( V_183 ) {
case 8 :
default:
args . V_244 . V_253 |= V_262 ;
break;
case 10 :
args . V_244 . V_253 |= V_263 ;
break;
case 12 :
args . V_244 . V_253 |= V_264 ;
break;
case 16 :
args . V_244 . V_253 |= V_265 ;
break;
}
args . V_244 . V_219 = V_207 ;
args . V_244 . V_256 = V_181 ;
args . V_244 . V_171 = V_131 ;
break;
default:
F_41 ( L_1 , V_215 , V_216 ) ;
return;
}
break;
default:
F_41 ( L_1 , V_215 , V_216 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_42 = NULL ;
T_8 V_266 = V_4 -> clock ;
T_8 V_246 = 0 , V_247 = 0 , V_248 = 0 , V_238 = 0 ;
struct V_175 * V_176 ;
T_8 V_180 ;
int V_181 = 0 ;
struct V_143 V_144 ;
bool V_177 = false ;
int V_183 = 8 ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_181 = F_33 ( V_41 ) ;
break;
}
}
if ( ! V_42 )
return;
switch ( V_11 -> V_131 ) {
case V_133 :
V_176 = & V_9 -> clock . V_267 ;
break;
case V_136 :
V_176 = & V_9 -> clock . V_268 ;
break;
case V_138 :
case V_139 :
default:
V_176 = & V_9 -> clock . V_269 ;
break;
}
if ( V_42 -> V_43 &
( V_196 | V_197 ) ) {
struct V_227 * V_228 = V_42 -> V_47 ;
struct V_178 * V_179 =
F_32 ( V_41 ) ;
struct V_199 * V_199 =
F_36 ( V_179 ) ;
struct V_200 * V_201 =
V_199 -> V_202 ;
int V_182 ;
V_183 = V_179 -> V_194 . V_183 ;
switch ( V_181 ) {
case V_270 :
case V_271 :
V_182 = V_201 -> V_182 / 10 ;
if ( F_24 ( V_9 ) )
V_177 =
F_46 ( V_9 , & V_144 ,
V_272 ,
V_182 ) ;
else {
if ( V_182 == 16200 ) {
V_177 =
F_47 ( V_9 , & V_144 ,
V_273 ) ;
if ( ! V_177 )
V_177 =
F_47 ( V_9 , & V_144 ,
V_274 ) ;
} else
V_177 =
F_47 ( V_9 , & V_144 ,
V_274 ) ;
}
break;
case V_275 :
if ( F_24 ( V_9 ) )
V_177 = F_46 ( V_9 , & V_144 ,
V_228 -> V_276 ,
V_4 -> clock / 10 ) ;
else
V_177 = F_47 ( V_9 , & V_144 ,
V_228 -> V_276 ) ;
break;
case V_277 :
if ( F_24 ( V_9 ) )
V_177 =
F_46 ( V_9 , & V_144 ,
V_278 ,
V_4 -> clock / 10 ) ;
break;
case V_229 :
if ( F_24 ( V_9 ) )
V_177 =
F_46 ( V_9 , & V_144 ,
V_279 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_180 = F_30 ( V_2 , V_4 , V_176 , V_177 , & V_144 ) ;
if ( V_42 -> V_43 & ( V_44 ) )
F_48 ( V_176 , V_180 , & V_266 , & V_247 , & V_248 ,
& V_246 , & V_238 ) ;
else if ( F_7 ( V_9 ) )
F_49 ( V_176 , V_180 , & V_266 , & V_247 , & V_248 ,
& V_246 , & V_238 ) ;
else
F_48 ( V_176 , V_180 , & V_266 , & V_247 , & V_248 ,
& V_246 , & V_238 ) ;
F_27 ( V_9 , V_83 , V_11 -> V_131 , & V_144 ) ;
F_44 ( V_2 , V_11 -> V_18 , V_11 -> V_131 ,
V_181 , V_42 -> V_207 , V_4 -> clock ,
V_246 , V_247 , V_248 , V_238 , V_183 , V_177 , & V_144 ) ;
if ( V_177 ) {
if ( F_24 ( V_9 ) ) {
T_8 V_280 ;
T_8 V_153 = ( ( ( V_247 * 10 ) + V_248 ) * V_144 . V_158 ) / 10000 ;
V_144 . V_153 = ( V_153 / 10 ) & V_281 ;
V_144 . V_153 |= ( ( V_153 - ( V_153 / 10 ) ) << V_282 ) &
V_283 ;
if ( V_144 . type & V_284 )
V_280 = ( 4 * V_153 * V_246 * ( V_144 . V_285 * 2048 ) ) /
( 125 * 25 * V_176 -> V_286 / 100 ) ;
else
V_280 = ( 2 * V_153 * V_246 * ( V_144 . V_285 * 2048 ) ) /
( 125 * 25 * V_176 -> V_286 / 100 ) ;
V_144 . V_155 = V_280 ;
}
F_27 ( V_9 , V_82 , V_11 -> V_131 , & V_144 ) ;
}
}
static int F_50 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
int V_289 , int V_290 , int V_291 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_292 * V_293 ;
struct V_287 * V_294 ;
struct V_295 * V_296 ;
struct V_297 * V_298 ;
T_10 V_299 ;
V_33 V_300 , V_301 , V_302 ;
T_8 V_303 = F_51 ( V_304 ) ;
T_8 V_305 , V_306 , V_307 ;
int V_308 ;
if ( ! V_291 && ! V_2 -> V_288 ) {
F_52 ( L_2 ) ;
return 0 ;
}
if ( V_291 ) {
V_293 = F_53 ( V_288 ) ;
V_294 = V_288 ;
}
else {
V_293 = F_53 ( V_2 -> V_288 ) ;
V_294 = V_2 -> V_288 ;
}
V_296 = V_293 -> V_296 ;
V_298 = F_54 ( V_296 ) ;
V_308 = F_55 ( V_298 , false ) ;
if ( F_56 ( V_308 != 0 ) )
return V_308 ;
if ( V_291 )
V_299 = F_57 ( V_298 ) ;
else {
V_308 = F_58 ( V_298 , V_309 , & V_299 ) ;
if ( F_56 ( V_308 != 0 ) ) {
F_59 ( V_298 ) ;
return - V_310 ;
}
}
F_60 ( V_298 , & V_302 , NULL ) ;
F_59 ( V_298 ) ;
switch ( V_294 -> V_311 ) {
case 8 :
V_300 = ( F_61 ( V_312 ) |
F_62 ( V_313 ) ) ;
break;
case 15 :
V_300 = ( F_61 ( V_314 ) |
F_62 ( V_315 ) ) ;
break;
case 16 :
V_300 = ( F_61 ( V_314 ) |
F_62 ( V_316 ) ) ;
#ifdef F_63
V_303 = F_51 ( V_317 ) ;
#endif
break;
case 24 :
case 32 :
V_300 = ( F_61 ( V_318 ) |
F_62 ( V_319 ) ) ;
#ifdef F_63
V_303 = F_51 ( V_320 ) ;
#endif
break;
default:
F_41 ( L_3 ,
V_294 -> V_311 ) ;
return - V_310 ;
}
if ( V_302 & V_321 ) {
if ( V_9 -> V_70 >= V_322 )
V_305 = V_9 -> V_323 . V_324 . V_325 ;
else
V_305 = V_9 -> V_323 . V_326 . V_325 ;
switch ( ( V_305 & 0xf0 ) >> 4 ) {
case 0 :
V_300 |= F_64 ( V_327 ) ;
break;
case 1 :
default:
V_300 |= F_64 ( V_328 ) ;
break;
case 2 :
V_300 |= F_64 ( V_329 ) ;
break;
}
switch ( ( V_305 & 0xf000 ) >> 12 ) {
case 0 :
default:
V_300 |= F_65 ( V_330 ) ;
break;
case 1 :
V_300 |= F_65 ( V_331 ) ;
break;
case 2 :
V_300 |= F_65 ( V_332 ) ;
break;
}
V_300 |= F_66 ( V_333 ) ;
} else if ( V_302 & V_334 )
V_300 |= F_66 ( V_335 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_26 ( V_336 , 0 ) ;
break;
case 1 :
F_26 ( V_337 , 0 ) ;
break;
case 2 :
F_26 ( V_338 , 0 ) ;
break;
case 3 :
F_26 ( V_339 , 0 ) ;
break;
case 4 :
F_26 ( V_340 , 0 ) ;
break;
case 5 :
F_26 ( V_341 , 0 ) ;
break;
default:
break;
}
F_26 ( V_342 + V_11 -> V_343 ,
F_67 ( V_299 ) ) ;
F_26 ( V_344 + V_11 -> V_343 ,
F_67 ( V_299 ) ) ;
F_26 ( V_345 + V_11 -> V_343 ,
( T_8 ) V_299 & V_346 ) ;
F_26 ( V_347 + V_11 -> V_343 ,
( T_8 ) V_299 & V_346 ) ;
F_26 ( V_348 + V_11 -> V_343 , V_300 ) ;
F_26 ( V_349 + V_11 -> V_343 , V_303 ) ;
F_26 ( V_350 + V_11 -> V_343 , 0 ) ;
F_26 ( V_351 + V_11 -> V_343 , 0 ) ;
F_26 ( V_352 + V_11 -> V_343 , 0 ) ;
F_26 ( V_353 + V_11 -> V_343 , 0 ) ;
F_26 ( V_354 + V_11 -> V_343 , V_294 -> V_355 ) ;
F_26 ( V_356 + V_11 -> V_343 , V_294 -> V_357 ) ;
V_301 = V_294 -> V_358 [ 0 ] / ( V_294 -> V_311 / 8 ) ;
F_26 ( V_359 + V_11 -> V_343 , V_301 ) ;
F_26 ( V_360 + V_11 -> V_343 , 1 ) ;
F_26 ( V_361 + V_11 -> V_343 ,
V_294 -> V_357 ) ;
V_289 &= ~ 3 ;
V_290 &= ~ 1 ;
F_26 ( V_362 + V_11 -> V_343 ,
( V_289 << 16 ) | V_290 ) ;
V_306 = V_2 -> V_4 . V_363 ;
V_307 = ( V_2 -> V_4 . V_364 + 1 ) & ~ 1 ;
F_26 ( V_365 + V_11 -> V_343 ,
( V_306 << 16 ) | V_307 ) ;
V_305 = F_25 ( V_366 + V_11 -> V_343 ) ;
V_305 &= ~ V_367 ;
F_26 ( V_366 + V_11 -> V_343 , V_305 ) ;
F_26 ( V_368 + V_11 -> V_343 , 0 ) ;
if ( ! V_291 && V_288 && V_288 != V_2 -> V_288 ) {
V_293 = F_53 ( V_288 ) ;
V_298 = F_54 ( V_293 -> V_296 ) ;
V_308 = F_55 ( V_298 , false ) ;
if ( F_56 ( V_308 != 0 ) )
return V_308 ;
F_68 ( V_298 ) ;
F_59 ( V_298 ) ;
}
F_69 ( V_9 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
int V_289 , int V_290 , int V_291 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_292 * V_293 ;
struct V_295 * V_296 ;
struct V_297 * V_298 ;
struct V_287 * V_294 ;
T_10 V_299 ;
V_33 V_300 , V_301 , V_302 ;
T_8 V_303 = V_369 ;
T_8 V_305 , V_306 , V_307 ;
int V_308 ;
if ( ! V_291 && ! V_2 -> V_288 ) {
F_52 ( L_2 ) ;
return 0 ;
}
if ( V_291 ) {
V_293 = F_53 ( V_288 ) ;
V_294 = V_288 ;
}
else {
V_293 = F_53 ( V_2 -> V_288 ) ;
V_294 = V_2 -> V_288 ;
}
V_296 = V_293 -> V_296 ;
V_298 = F_54 ( V_296 ) ;
V_308 = F_55 ( V_298 , false ) ;
if ( F_56 ( V_308 != 0 ) )
return V_308 ;
if ( V_291 )
V_299 = F_57 ( V_298 ) ;
else {
V_308 = F_58 ( V_298 , V_309 , & V_299 ) ;
if ( F_56 ( V_308 != 0 ) ) {
F_59 ( V_298 ) ;
return - V_310 ;
}
}
F_60 ( V_298 , & V_302 , NULL ) ;
F_59 ( V_298 ) ;
switch ( V_294 -> V_311 ) {
case 8 :
V_300 =
V_370 |
V_371 ;
break;
case 15 :
V_300 =
V_372 |
V_373 ;
break;
case 16 :
V_300 =
V_372 |
V_374 ;
#ifdef F_63
V_303 = V_375 ;
#endif
break;
case 24 :
case 32 :
V_300 =
V_376 |
V_377 ;
#ifdef F_63
V_303 = V_378 ;
#endif
break;
default:
F_41 ( L_3 ,
V_294 -> V_311 ) ;
return - V_310 ;
}
if ( V_9 -> V_70 >= V_379 ) {
if ( V_302 & V_321 )
V_300 |= V_380 ;
else if ( V_302 & V_334 )
V_300 |= V_381 ;
} else {
if ( V_302 & V_321 )
V_300 |= V_382 ;
if ( V_302 & V_334 )
V_300 |= V_383 ;
}
if ( V_11 -> V_18 == 0 )
F_26 ( V_336 , 0 ) ;
else
F_26 ( V_337 , 0 ) ;
if ( V_9 -> V_70 >= V_191 ) {
if ( V_11 -> V_18 ) {
F_26 ( V_384 , F_67 ( V_299 ) ) ;
F_26 ( V_385 , F_67 ( V_299 ) ) ;
} else {
F_26 ( V_386 , F_67 ( V_299 ) ) ;
F_26 ( V_387 , F_67 ( V_299 ) ) ;
}
}
F_26 ( V_388 + V_11 -> V_343 ,
( T_8 ) V_299 ) ;
F_26 ( V_389 +
V_11 -> V_343 , ( T_8 ) V_299 ) ;
F_26 ( V_390 + V_11 -> V_343 , V_300 ) ;
if ( V_9 -> V_70 >= V_379 )
F_26 ( V_391 + V_11 -> V_343 , V_303 ) ;
F_26 ( V_392 + V_11 -> V_343 , 0 ) ;
F_26 ( V_393 + V_11 -> V_343 , 0 ) ;
F_26 ( V_394 + V_11 -> V_343 , 0 ) ;
F_26 ( V_395 + V_11 -> V_343 , 0 ) ;
F_26 ( V_396 + V_11 -> V_343 , V_294 -> V_355 ) ;
F_26 ( V_397 + V_11 -> V_343 , V_294 -> V_357 ) ;
V_301 = V_294 -> V_358 [ 0 ] / ( V_294 -> V_311 / 8 ) ;
F_26 ( V_398 + V_11 -> V_343 , V_301 ) ;
F_26 ( V_399 + V_11 -> V_343 , 1 ) ;
F_26 ( V_400 + V_11 -> V_343 ,
V_294 -> V_357 ) ;
V_289 &= ~ 3 ;
V_290 &= ~ 1 ;
F_26 ( V_401 + V_11 -> V_343 ,
( V_289 << 16 ) | V_290 ) ;
V_306 = V_2 -> V_4 . V_363 ;
V_307 = ( V_2 -> V_4 . V_364 + 1 ) & ~ 1 ;
F_26 ( V_402 + V_11 -> V_343 ,
( V_306 << 16 ) | V_307 ) ;
V_305 = F_25 ( V_403 + V_11 -> V_343 ) ;
V_305 &= ~ V_404 ;
F_26 ( V_403 + V_11 -> V_343 , V_305 ) ;
F_26 ( V_405 + V_11 -> V_343 , 0 ) ;
if ( ! V_291 && V_288 && V_288 != V_2 -> V_288 ) {
V_293 = F_53 ( V_288 ) ;
V_298 = F_54 ( V_293 -> V_296 ) ;
V_308 = F_55 ( V_298 , false ) ;
if ( F_56 ( V_308 != 0 ) )
return V_308 ;
F_68 ( V_298 ) ;
F_59 ( V_298 ) ;
}
F_69 ( V_9 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , int V_289 , int V_290 ,
struct V_287 * V_406 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) )
return F_50 ( V_2 , V_406 , V_289 , V_290 , 0 ) ;
else if ( F_7 ( V_9 ) )
return F_70 ( V_2 , V_406 , V_289 , V_290 , 0 ) ;
else
return F_72 ( V_2 , V_406 , V_289 , V_290 , 0 ) ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
int V_289 , int V_290 , enum V_407 V_75 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) )
return F_50 ( V_2 , V_288 , V_289 , V_290 , 1 ) ;
else if ( F_7 ( V_9 ) )
return F_70 ( V_2 , V_288 , V_289 , V_290 , 1 ) ;
else
return F_72 ( V_2 , V_288 , V_289 , V_290 , 1 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_8 V_408 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_408 = F_25 ( V_409 ) ;
V_408 &= ~ V_410 ;
F_26 ( V_409 , V_408 ) ;
break;
case 1 :
V_408 = F_25 ( V_411 ) ;
V_408 &= ~ V_412 ;
F_26 ( V_411 , V_408 ) ;
F_26 ( V_413 , F_25 ( V_414 ) ) ;
F_26 ( V_415 , F_25 ( V_416 ) ) ;
break;
}
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_417 ;
struct V_1 * V_418 ;
V_33 V_419 = 0 ;
if ( F_24 ( V_9 ) ) {
F_8 (test_encoder, &dev->mode_config.encoder_list, head) {
if ( V_417 -> V_2 && ( V_417 -> V_2 == V_2 ) ) {
if ( F_39 ( F_33 ( V_417 ) ) ) {
if ( F_28 ( V_9 ) || V_9 -> clock . V_420 )
return V_139 ;
}
}
}
F_8 (test_crtc, &dev->mode_config.crtc_list, head) {
struct V_11 * V_421 ;
if ( V_2 == V_418 )
continue;
V_421 = F_2 ( V_418 ) ;
if ( ( V_421 -> V_131 >= V_133 ) &&
( V_421 -> V_131 <= V_136 ) )
V_419 |= ( 1 << V_421 -> V_131 ) ;
}
if ( ! ( V_419 & 1 ) )
return V_133 ;
return V_136 ;
} else
return V_11 -> V_18 ;
}
void F_76 ( struct V_8 * V_9 )
{
if ( F_24 ( V_9 ) ) {
struct V_143 V_144 ;
bool V_177 = F_46 ( V_9 , & V_144 ,
V_422 ,
V_9 -> clock . V_423 ) ;
if ( V_177 )
F_27 ( V_9 , V_83 , V_138 , & V_144 ) ;
F_42 ( V_9 , V_9 -> clock . V_423 ) ;
if ( V_177 )
F_27 ( V_9 , V_82 , V_138 , & V_144 ) ;
}
}
int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_289 , int V_290 , struct V_287 * V_406 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 ;
bool V_424 = false ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
struct V_42 * V_42 = F_9 ( V_41 ) ;
if ( V_42 -> V_43 &
( V_44 | V_425 ) )
V_424 = true ;
}
}
F_45 ( V_2 , V_5 ) ;
if ( F_24 ( V_9 ) )
F_21 ( V_2 , V_5 ) ;
else if ( F_7 ( V_9 ) ) {
if ( V_424 )
F_22 ( V_2 , V_5 ) ;
else
F_21 ( V_2 , V_5 ) ;
} else {
F_22 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_21 ( V_2 , V_5 ) ;
F_74 ( V_2 ) ;
}
F_71 ( V_2 , V_289 , V_290 , V_406 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
if ( ! F_79 ( V_2 , V_4 , V_5 ) )
return false ;
return true ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
V_11 -> V_131 = F_75 ( V_2 ) ;
F_11 ( V_2 , V_82 ) ;
F_15 ( V_2 , V_86 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_80 ) ;
F_11 ( V_2 , V_83 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_143 V_144 ;
F_15 ( V_2 , V_86 ) ;
switch ( V_11 -> V_131 ) {
case V_133 :
case V_136 :
F_44 ( V_2 , V_11 -> V_18 , V_11 -> V_131 ,
0 , 0 , V_83 , 0 , 0 , 0 , 0 , 0 , false , & V_144 ) ;
break;
default:
break;
}
V_11 -> V_131 = - 1 ;
}
void F_83 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_343 = V_426 ;
break;
case 1 :
V_11 -> V_343 = V_427 ;
break;
case 2 :
V_11 -> V_343 = V_428 ;
break;
case 3 :
V_11 -> V_343 = V_429 ;
break;
case 4 :
V_11 -> V_343 = V_430 ;
break;
case 5 :
V_11 -> V_343 = V_431 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_343 =
V_432 - V_433 ;
else
V_11 -> V_343 = 0 ;
}
V_11 -> V_131 = - 1 ;
F_84 ( & V_11 -> V_434 , & V_435 ) ;
}
