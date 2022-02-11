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
static void F_23 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_8 V_131 ;
if ( F_24 ( V_9 ) ) {
switch ( V_11 -> V_132 ) {
case V_133 :
V_131 = F_25 ( V_134 ) ;
V_131 &= ~ V_135 ;
F_26 ( V_134 , V_131 ) ;
break;
case V_136 :
V_131 = F_25 ( V_137 ) ;
V_131 &= ~ V_135 ;
F_26 ( V_137 , V_131 ) ;
break;
case V_138 :
case V_139 :
return;
}
} else if ( F_7 ( V_9 ) ) {
switch ( V_11 -> V_132 ) {
case V_133 :
V_131 = F_25 ( V_140 ) ;
V_131 &= ~ 1 ;
F_26 ( V_140 , V_131 ) ;
break;
case V_136 :
V_131 = F_25 ( V_141 ) ;
V_131 &= ~ 1 ;
F_26 ( V_141 , V_131 ) ;
break;
case V_138 :
case V_139 :
return;
}
}
}
static void F_27 ( struct V_1 * V_2 ,
int V_142 ,
int V_132 ,
struct V_143 * V_144 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_145 ) ;
union V_146 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_28 ( V_9 ) ) {
args . V_147 . V_148 = F_4 ( 0 ) ;
args . V_147 . V_149 = V_144 -> type & V_150 ;
switch ( V_132 ) {
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
switch ( V_132 ) {
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
if ( ( V_144 -> V_158 == 0 ) || ( V_144 -> type & V_159 ) )
args . V_160 . V_64 = V_83 ;
} else if ( F_17 ( V_9 ) ) {
args . V_165 . V_161 = F_4 ( V_144 -> V_158 ) ;
args . V_165 . V_149 = V_144 -> type & V_150 ;
args . V_165 . V_166 = V_144 -> V_155 ;
args . V_165 . V_167 = V_144 -> V_168 ;
args . V_165 . V_169 = V_144 -> V_170 ;
args . V_165 . V_171 = V_132 ;
args . V_165 . V_64 = V_142 ;
} else if ( F_7 ( V_9 ) ) {
if ( ( V_142 == V_83 ) || ( V_144 -> V_158 == 0 ) ||
( V_144 -> type & V_159 ) ) {
F_23 ( V_2 ) ;
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
F_23 ( V_2 ) ;
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
static T_8 F_29 ( struct V_1 * V_2 ,
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
V_176 -> V_105 = 0 ;
if ( F_7 ( V_9 ) ) {
if ( ( V_9 -> V_70 == V_184 ) ||
( V_9 -> V_70 == V_185 ) ||
( V_9 -> V_70 == V_186 ) )
V_176 -> V_105 |= (
V_187 ) ;
if ( F_30 ( V_9 ) && V_4 -> clock > 200000 )
V_176 -> V_105 |= V_188 ;
else
V_176 -> V_105 |= V_189 ;
if ( V_9 -> V_70 < V_190 )
V_176 -> V_105 |= V_191 ;
} else {
V_176 -> V_105 |= V_192 ;
if ( V_4 -> clock > 200000 )
V_176 -> V_105 |= V_188 ;
else
V_176 -> V_105 |= V_189 ;
}
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_179 = F_31 ( V_41 ) ;
if ( V_179 )
V_183 = V_179 -> V_193 . V_183 ;
V_181 = F_32 ( V_41 ) ;
if ( ( V_42 -> V_194 & ( V_195 | V_196 ) ) ||
F_33 ( V_41 ) ) {
if ( V_179 ) {
struct V_197 * V_197 = F_34 ( V_179 ) ;
struct V_198 * V_199 =
V_197 -> V_200 ;
V_182 = V_199 -> V_182 ;
}
}
if ( V_42 -> V_194 & ( V_195 ) ) {
if ( V_177 ) {
if ( V_144 -> V_201 ) {
V_176 -> V_105 |= V_202 ;
V_176 -> V_203 = V_144 -> V_201 ;
if ( F_7 ( V_9 ) )
V_176 -> V_105 |= V_204 ;
}
}
}
if ( F_7 ( V_9 ) ) {
if ( V_42 -> V_205 == V_206 )
V_180 = V_4 -> clock * 2 ;
if ( V_42 -> V_43 & ( V_44 ) )
V_176 -> V_105 |= V_187 ;
if ( V_42 -> V_194 & ( V_195 ) )
V_176 -> V_105 |= V_207 ;
} else {
if ( V_41 -> V_208 != V_209 )
V_176 -> V_105 |= V_210 ;
if ( V_41 -> V_208 == V_211 )
V_176 -> V_105 |= V_202 ;
}
break;
}
}
if ( F_17 ( V_9 ) ) {
union V_212 args ;
T_9 V_213 , V_214 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_215 ) ;
if ( ! F_35 ( V_9 -> V_31 . V_32 , V_12 , & V_213 ,
& V_214 ) )
return V_180 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_213 ) {
case 1 :
switch ( V_214 ) {
case 1 :
case 2 :
args . V_165 . V_216 = F_4 ( V_4 -> clock / 10 ) ;
args . V_165 . V_217 = V_42 -> V_205 ;
args . V_165 . V_218 = V_181 ;
if ( V_177 && V_144 -> V_158 )
args . V_165 . V_219 |=
V_220 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_180 = F_36 ( args . V_165 . V_216 ) * 10 ;
break;
case 3 :
args . V_147 . V_221 . V_216 = F_4 ( V_4 -> clock / 10 ) ;
args . V_147 . V_221 . V_217 = V_42 -> V_205 ;
args . V_147 . V_221 . V_218 = V_181 ;
args . V_147 . V_221 . V_222 = 0 ;
if ( V_177 && V_144 -> V_158 )
args . V_147 . V_221 . V_222 |=
V_223 ;
if ( V_42 -> V_194 & ( V_196 ) ||
F_33 ( V_41 ) ) {
struct V_224 * V_225 = V_42 -> V_47 ;
if ( V_181 == V_226 ) {
args . V_147 . V_221 . V_222 |=
V_227 ;
args . V_147 . V_221 . V_216 = F_4 ( V_182 / 10 ) ;
} else {
if ( V_181 == V_228 ) {
args . V_147 . V_221 . V_216 =
F_4 ( ( V_4 -> clock * V_183 / 8 ) / 10 ) ;
}
if ( V_225 -> V_229 )
args . V_147 . V_221 . V_222 |=
V_227 ;
if ( V_4 -> clock > 165000 )
args . V_147 . V_221 . V_222 |=
V_230 ;
}
} else if ( V_42 -> V_194 & ( V_195 ) ) {
if ( V_181 == V_226 ) {
args . V_147 . V_221 . V_222 |=
V_227 ;
args . V_147 . V_221 . V_216 = F_4 ( V_182 / 10 ) ;
} else if ( V_181 != V_231 ) {
if ( V_4 -> clock > 165000 )
args . V_147 . V_221 . V_222 |=
V_230 ;
}
}
if ( F_33 ( V_41 ) ) {
struct V_40 * V_232 = F_37 ( V_41 ) ;
struct V_42 * V_233 = F_9 ( V_232 ) ;
args . V_147 . V_221 . V_234 = V_233 -> V_205 ;
} else
args . V_147 . V_221 . V_234 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_180 = F_38 ( args . V_147 . V_235 . V_236 ) * 10 ;
if ( args . V_147 . V_235 . V_237 ) {
V_176 -> V_105 |= V_204 ;
V_176 -> V_105 |= V_202 ;
V_176 -> V_203 = args . V_147 . V_235 . V_237 ;
}
if ( args . V_147 . V_235 . V_238 ) {
V_176 -> V_105 |= V_204 ;
V_176 -> V_105 |= V_239 ;
V_176 -> V_240 = args . V_147 . V_235 . V_238 ;
}
break;
default:
F_39 ( L_1 , V_213 , V_214 ) ;
return V_180 ;
}
break;
default:
F_39 ( L_1 , V_213 , V_214 ) ;
return V_180 ;
}
}
return V_180 ;
}
static void F_40 ( struct V_1 * V_2 ,
T_8 V_241 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_9 V_213 , V_214 ;
int V_12 ;
union V_242 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_243 ) ;
if ( ! F_35 ( V_9 -> V_31 . V_32 , V_12 , & V_213 ,
& V_214 ) )
return;
switch ( V_213 ) {
case 1 :
switch ( V_214 ) {
case 5 :
args . V_244 . V_17 = V_245 ;
args . V_244 . V_216 = F_4 ( V_241 ) ;
args . V_244 . V_171 = V_138 ;
break;
case 6 :
args . V_246 . V_247 = F_41 ( V_241 ) ;
args . V_246 . V_171 = V_138 ;
break;
default:
F_39 ( L_1 , V_213 , V_214 ) ;
return;
}
break;
default:
F_39 ( L_1 , V_213 , V_214 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_42 ( struct V_1 * V_2 ,
int V_18 ,
int V_132 ,
T_8 V_181 ,
T_8 V_205 ,
T_8 clock ,
T_8 V_248 ,
T_8 V_249 ,
T_8 V_250 ,
T_8 V_240 ,
int V_183 ,
bool V_177 ,
struct V_143 * V_144 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_9 V_213 , V_214 ;
int V_12 = F_3 ( V_13 , V_243 ) ;
union V_242 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_35 ( V_9 -> V_31 . V_32 , V_12 , & V_213 ,
& V_214 ) )
return;
switch ( V_213 ) {
case 1 :
switch ( V_214 ) {
case 1 :
if ( clock == V_83 )
return;
args . V_165 . V_216 = F_4 ( clock / 10 ) ;
args . V_165 . V_251 = F_4 ( V_248 ) ;
args . V_165 . V_252 = F_4 ( V_249 ) ;
args . V_165 . V_253 = V_250 ;
args . V_165 . V_238 = V_240 ;
args . V_165 . V_171 = V_132 ;
args . V_165 . V_17 = V_18 ;
args . V_165 . V_254 = 1 ;
break;
case 2 :
args . V_160 . V_216 = F_4 ( clock / 10 ) ;
args . V_160 . V_251 = F_4 ( V_248 ) ;
args . V_160 . V_252 = F_4 ( V_249 ) ;
args . V_160 . V_253 = V_250 ;
args . V_160 . V_238 = V_240 ;
args . V_160 . V_171 = V_132 ;
args . V_160 . V_17 = V_18 ;
args . V_160 . V_254 = 1 ;
break;
case 3 :
args . V_147 . V_216 = F_4 ( clock / 10 ) ;
args . V_147 . V_251 = F_4 ( V_248 ) ;
args . V_147 . V_252 = F_4 ( V_249 ) ;
args . V_147 . V_253 = V_250 ;
args . V_147 . V_238 = V_240 ;
args . V_147 . V_171 = V_132 ;
args . V_147 . V_255 = ( V_132 << 2 ) ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_147 . V_255 |= V_256 ;
args . V_147 . V_257 = V_205 ;
args . V_147 . V_258 = V_181 ;
break;
case 5 :
args . V_244 . V_17 = V_18 ;
args . V_244 . V_216 = F_4 ( clock / 10 ) ;
args . V_244 . V_237 = V_248 ;
args . V_244 . V_252 = F_4 ( V_249 ) ;
args . V_244 . V_259 = F_41 ( V_250 * 100000 ) ;
args . V_244 . V_238 = V_240 ;
args . V_244 . V_255 = 0 ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_244 . V_255 |= V_260 ;
switch ( V_183 ) {
case 8 :
default:
args . V_244 . V_255 |= V_261 ;
break;
case 10 :
args . V_244 . V_255 |= V_262 ;
break;
}
args . V_244 . V_217 = V_205 ;
args . V_244 . V_258 = V_181 ;
args . V_244 . V_171 = V_132 ;
break;
case 6 :
args . V_246 . V_263 . V_17 = V_18 ;
args . V_246 . V_263 . V_264 = F_41 ( clock / 10 ) ;
args . V_246 . V_237 = V_248 ;
args . V_246 . V_252 = F_4 ( V_249 ) ;
args . V_246 . V_259 = F_41 ( V_250 * 100000 ) ;
args . V_246 . V_238 = V_240 ;
args . V_246 . V_255 = 0 ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_246 . V_255 |= V_265 ;
switch ( V_183 ) {
case 8 :
default:
args . V_246 . V_255 |= V_266 ;
break;
case 10 :
args . V_246 . V_255 |= V_267 ;
break;
case 12 :
args . V_246 . V_255 |= V_268 ;
break;
case 16 :
args . V_246 . V_255 |= V_269 ;
break;
}
args . V_246 . V_217 = V_205 ;
args . V_246 . V_258 = V_181 ;
args . V_246 . V_171 = V_132 ;
break;
default:
F_39 ( L_1 , V_213 , V_214 ) ;
return;
}
break;
default:
F_39 ( L_1 , V_213 , V_214 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_42 = NULL ;
T_8 V_270 = V_4 -> clock ;
T_8 V_248 = 0 , V_249 = 0 , V_250 = 0 , V_240 = 0 ;
struct V_175 * V_176 ;
T_8 V_180 ;
int V_181 = 0 ;
struct V_143 V_144 ;
bool V_177 = false ;
int V_183 = 8 ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_181 = F_32 ( V_41 ) ;
break;
}
}
if ( ! V_42 )
return;
switch ( V_11 -> V_132 ) {
case V_133 :
V_176 = & V_9 -> clock . V_271 ;
break;
case V_136 :
V_176 = & V_9 -> clock . V_272 ;
break;
case V_138 :
case V_139 :
default:
V_176 = & V_9 -> clock . V_273 ;
break;
}
if ( V_42 -> V_43 &
( V_195 | V_196 ) ) {
struct V_224 * V_225 = V_42 -> V_47 ;
struct V_178 * V_179 =
F_31 ( V_41 ) ;
struct V_197 * V_197 =
F_34 ( V_179 ) ;
struct V_198 * V_199 =
V_197 -> V_200 ;
int V_182 ;
V_183 = V_179 -> V_193 . V_183 ;
switch ( V_181 ) {
case V_226 :
V_182 = V_199 -> V_182 / 10 ;
if ( F_24 ( V_9 ) )
V_177 =
F_44 ( V_9 , & V_144 ,
V_274 ,
V_182 ) ;
else {
if ( V_182 == 16200 ) {
V_177 =
F_45 ( V_9 , & V_144 ,
V_275 ) ;
if ( ! V_177 )
V_177 =
F_45 ( V_9 , & V_144 ,
V_276 ) ;
} else
V_177 =
F_45 ( V_9 , & V_144 ,
V_276 ) ;
}
break;
case V_231 :
if ( F_24 ( V_9 ) )
V_177 = F_44 ( V_9 , & V_144 ,
V_225 -> V_277 ,
V_4 -> clock / 10 ) ;
else
V_177 = F_45 ( V_9 , & V_144 ,
V_225 -> V_277 ) ;
break;
case V_278 :
if ( F_24 ( V_9 ) )
V_177 =
F_44 ( V_9 , & V_144 ,
V_279 ,
V_4 -> clock / 10 ) ;
break;
case V_228 :
if ( F_24 ( V_9 ) )
V_177 =
F_44 ( V_9 , & V_144 ,
V_280 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_180 = F_29 ( V_2 , V_4 , V_176 , V_177 , & V_144 ) ;
if ( V_42 -> V_43 & ( V_44 ) )
F_46 ( V_176 , V_180 , & V_270 , & V_249 , & V_250 ,
& V_248 , & V_240 ) ;
else if ( F_7 ( V_9 ) )
F_47 ( V_176 , V_180 , & V_270 , & V_249 , & V_250 ,
& V_248 , & V_240 ) ;
else
F_46 ( V_176 , V_180 , & V_270 , & V_249 , & V_250 ,
& V_248 , & V_240 ) ;
F_27 ( V_2 , V_83 , V_11 -> V_132 , & V_144 ) ;
F_42 ( V_2 , V_11 -> V_18 , V_11 -> V_132 ,
V_181 , V_42 -> V_205 , V_4 -> clock ,
V_248 , V_249 , V_250 , V_240 , V_183 , V_177 , & V_144 ) ;
if ( V_177 ) {
if ( F_24 ( V_9 ) ) {
T_8 V_281 ;
T_8 V_153 = ( ( ( V_249 * 10 ) + V_250 ) * V_144 . V_158 ) / 10000 ;
V_144 . V_153 = ( V_153 / 10 ) & V_282 ;
V_144 . V_153 |= ( ( V_153 - ( V_153 / 10 ) ) << V_283 ) &
V_284 ;
if ( V_144 . type & V_285 )
V_281 = ( 4 * V_153 * V_248 * ( V_144 . V_286 * 2048 ) ) /
( 125 * 25 * V_176 -> V_287 / 100 ) ;
else
V_281 = ( 2 * V_153 * V_248 * ( V_144 . V_286 * 2048 ) ) /
( 125 * 25 * V_176 -> V_287 / 100 ) ;
V_144 . V_155 = V_281 ;
}
F_27 ( V_2 , V_82 , V_11 -> V_132 , & V_144 ) ;
}
}
static int F_48 ( struct V_1 * V_2 ,
struct V_288 * V_289 ,
int V_290 , int V_291 , int V_292 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_293 * V_294 ;
struct V_288 * V_295 ;
struct V_296 * V_297 ;
struct V_298 * V_299 ;
T_10 V_300 ;
V_33 V_301 , V_302 , V_303 ;
T_8 V_304 = F_49 ( V_305 ) ;
T_8 V_306 , V_307 , V_308 ;
int V_309 ;
if ( ! V_292 && ! V_2 -> V_289 ) {
F_50 ( L_2 ) ;
return 0 ;
}
if ( V_292 ) {
V_294 = F_51 ( V_289 ) ;
V_295 = V_289 ;
}
else {
V_294 = F_51 ( V_2 -> V_289 ) ;
V_295 = V_2 -> V_289 ;
}
V_297 = V_294 -> V_297 ;
V_299 = F_52 ( V_297 ) ;
V_309 = F_53 ( V_299 , false ) ;
if ( F_54 ( V_309 != 0 ) )
return V_309 ;
if ( V_292 )
V_300 = F_55 ( V_299 ) ;
else {
V_309 = F_56 ( V_299 , V_310 , & V_300 ) ;
if ( F_54 ( V_309 != 0 ) ) {
F_57 ( V_299 ) ;
return - V_311 ;
}
}
F_58 ( V_299 , & V_303 , NULL ) ;
F_57 ( V_299 ) ;
switch ( V_295 -> V_312 ) {
case 8 :
V_301 = ( F_59 ( V_313 ) |
F_60 ( V_314 ) ) ;
break;
case 15 :
V_301 = ( F_59 ( V_315 ) |
F_60 ( V_316 ) ) ;
break;
case 16 :
V_301 = ( F_59 ( V_315 ) |
F_60 ( V_317 ) ) ;
#ifdef F_61
V_304 = F_49 ( V_318 ) ;
#endif
break;
case 24 :
case 32 :
V_301 = ( F_59 ( V_319 ) |
F_60 ( V_320 ) ) ;
#ifdef F_61
V_304 = F_49 ( V_321 ) ;
#endif
break;
default:
F_39 ( L_3 ,
V_295 -> V_312 ) ;
return - V_311 ;
}
if ( V_303 & V_322 )
V_301 |= F_62 ( V_323 ) ;
else if ( V_303 & V_324 )
V_301 |= F_62 ( V_325 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_26 ( V_326 , 0 ) ;
break;
case 1 :
F_26 ( V_327 , 0 ) ;
break;
case 2 :
F_26 ( V_328 , 0 ) ;
break;
case 3 :
F_26 ( V_329 , 0 ) ;
break;
case 4 :
F_26 ( V_330 , 0 ) ;
break;
case 5 :
F_26 ( V_331 , 0 ) ;
break;
default:
break;
}
F_26 ( V_332 + V_11 -> V_333 ,
F_63 ( V_300 ) ) ;
F_26 ( V_334 + V_11 -> V_333 ,
F_63 ( V_300 ) ) ;
F_26 ( V_335 + V_11 -> V_333 ,
( T_8 ) V_300 & V_336 ) ;
F_26 ( V_337 + V_11 -> V_333 ,
( T_8 ) V_300 & V_336 ) ;
F_26 ( V_338 + V_11 -> V_333 , V_301 ) ;
F_26 ( V_339 + V_11 -> V_333 , V_304 ) ;
F_26 ( V_340 + V_11 -> V_333 , 0 ) ;
F_26 ( V_341 + V_11 -> V_333 , 0 ) ;
F_26 ( V_342 + V_11 -> V_333 , 0 ) ;
F_26 ( V_343 + V_11 -> V_333 , 0 ) ;
F_26 ( V_344 + V_11 -> V_333 , V_295 -> V_345 ) ;
F_26 ( V_346 + V_11 -> V_333 , V_295 -> V_347 ) ;
V_302 = V_295 -> V_348 / ( V_295 -> V_312 / 8 ) ;
F_26 ( V_349 + V_11 -> V_333 , V_302 ) ;
F_26 ( V_350 + V_11 -> V_333 , 1 ) ;
F_26 ( V_351 + V_11 -> V_333 ,
V_2 -> V_4 . V_352 ) ;
V_290 &= ~ 3 ;
V_291 &= ~ 1 ;
F_26 ( V_353 + V_11 -> V_333 ,
( V_290 << 16 ) | V_291 ) ;
V_307 = V_2 -> V_4 . V_354 ;
V_308 = ( V_2 -> V_4 . V_352 + 1 ) & ~ 1 ;
F_26 ( V_355 + V_11 -> V_333 ,
( V_307 << 16 ) | V_308 ) ;
V_306 = F_25 ( V_356 + V_11 -> V_333 ) ;
V_306 &= ~ V_357 ;
F_26 ( V_356 + V_11 -> V_333 , V_306 ) ;
F_26 ( V_358 + V_11 -> V_333 , 0 ) ;
if ( ! V_292 && V_289 && V_289 != V_2 -> V_289 ) {
V_294 = F_51 ( V_289 ) ;
V_299 = F_52 ( V_294 -> V_297 ) ;
V_309 = F_53 ( V_299 , false ) ;
if ( F_54 ( V_309 != 0 ) )
return V_309 ;
F_64 ( V_299 ) ;
F_57 ( V_299 ) ;
}
F_65 ( V_9 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_288 * V_289 ,
int V_290 , int V_291 , int V_292 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_293 * V_294 ;
struct V_296 * V_297 ;
struct V_298 * V_299 ;
struct V_288 * V_295 ;
T_10 V_300 ;
V_33 V_301 , V_302 , V_303 ;
T_8 V_304 = V_359 ;
T_8 V_306 , V_307 , V_308 ;
int V_309 ;
if ( ! V_292 && ! V_2 -> V_289 ) {
F_50 ( L_2 ) ;
return 0 ;
}
if ( V_292 ) {
V_294 = F_51 ( V_289 ) ;
V_295 = V_289 ;
}
else {
V_294 = F_51 ( V_2 -> V_289 ) ;
V_295 = V_2 -> V_289 ;
}
V_297 = V_294 -> V_297 ;
V_299 = F_52 ( V_297 ) ;
V_309 = F_53 ( V_299 , false ) ;
if ( F_54 ( V_309 != 0 ) )
return V_309 ;
if ( V_292 )
V_300 = F_55 ( V_299 ) ;
else {
V_309 = F_56 ( V_299 , V_310 , & V_300 ) ;
if ( F_54 ( V_309 != 0 ) ) {
F_57 ( V_299 ) ;
return - V_311 ;
}
}
F_58 ( V_299 , & V_303 , NULL ) ;
F_57 ( V_299 ) ;
switch ( V_295 -> V_312 ) {
case 8 :
V_301 =
V_360 |
V_361 ;
break;
case 15 :
V_301 =
V_362 |
V_363 ;
break;
case 16 :
V_301 =
V_362 |
V_364 ;
#ifdef F_61
V_304 = V_365 ;
#endif
break;
case 24 :
case 32 :
V_301 =
V_366 |
V_367 ;
#ifdef F_61
V_304 = V_368 ;
#endif
break;
default:
F_39 ( L_3 ,
V_295 -> V_312 ) ;
return - V_311 ;
}
if ( V_9 -> V_70 >= V_369 ) {
if ( V_303 & V_322 )
V_301 |= V_370 ;
else if ( V_303 & V_324 )
V_301 |= V_371 ;
} else {
if ( V_303 & V_322 )
V_301 |= V_372 ;
if ( V_303 & V_324 )
V_301 |= V_373 ;
}
if ( V_11 -> V_18 == 0 )
F_26 ( V_326 , 0 ) ;
else
F_26 ( V_327 , 0 ) ;
if ( V_9 -> V_70 >= V_190 ) {
if ( V_11 -> V_18 ) {
F_26 ( V_374 , F_63 ( V_300 ) ) ;
F_26 ( V_375 , F_63 ( V_300 ) ) ;
} else {
F_26 ( V_376 , F_63 ( V_300 ) ) ;
F_26 ( V_377 , F_63 ( V_300 ) ) ;
}
}
F_26 ( V_378 + V_11 -> V_333 ,
( T_8 ) V_300 ) ;
F_26 ( V_379 +
V_11 -> V_333 , ( T_8 ) V_300 ) ;
F_26 ( V_380 + V_11 -> V_333 , V_301 ) ;
if ( V_9 -> V_70 >= V_369 )
F_26 ( V_381 + V_11 -> V_333 , V_304 ) ;
F_26 ( V_382 + V_11 -> V_333 , 0 ) ;
F_26 ( V_383 + V_11 -> V_333 , 0 ) ;
F_26 ( V_384 + V_11 -> V_333 , 0 ) ;
F_26 ( V_385 + V_11 -> V_333 , 0 ) ;
F_26 ( V_386 + V_11 -> V_333 , V_295 -> V_345 ) ;
F_26 ( V_387 + V_11 -> V_333 , V_295 -> V_347 ) ;
V_302 = V_295 -> V_348 / ( V_295 -> V_312 / 8 ) ;
F_26 ( V_388 + V_11 -> V_333 , V_302 ) ;
F_26 ( V_389 + V_11 -> V_333 , 1 ) ;
F_26 ( V_390 + V_11 -> V_333 ,
V_2 -> V_4 . V_352 ) ;
V_290 &= ~ 3 ;
V_291 &= ~ 1 ;
F_26 ( V_391 + V_11 -> V_333 ,
( V_290 << 16 ) | V_291 ) ;
V_307 = V_2 -> V_4 . V_354 ;
V_308 = ( V_2 -> V_4 . V_352 + 1 ) & ~ 1 ;
F_26 ( V_392 + V_11 -> V_333 ,
( V_307 << 16 ) | V_308 ) ;
V_306 = F_25 ( V_393 + V_11 -> V_333 ) ;
V_306 &= ~ V_394 ;
F_26 ( V_393 + V_11 -> V_333 , V_306 ) ;
F_26 ( V_395 + V_11 -> V_333 , 0 ) ;
if ( ! V_292 && V_289 && V_289 != V_2 -> V_289 ) {
V_294 = F_51 ( V_289 ) ;
V_299 = F_52 ( V_294 -> V_297 ) ;
V_309 = F_53 ( V_299 , false ) ;
if ( F_54 ( V_309 != 0 ) )
return V_309 ;
F_64 ( V_299 ) ;
F_57 ( V_299 ) ;
}
F_65 ( V_9 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 , int V_290 , int V_291 ,
struct V_288 * V_396 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) )
return F_48 ( V_2 , V_396 , V_290 , V_291 , 0 ) ;
else if ( F_7 ( V_9 ) )
return F_66 ( V_2 , V_396 , V_290 , V_291 , 0 ) ;
else
return F_68 ( V_2 , V_396 , V_290 , V_291 , 0 ) ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_288 * V_289 ,
int V_290 , int V_291 , enum V_397 V_75 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) )
return F_48 ( V_2 , V_289 , V_290 , V_291 , 1 ) ;
else if ( F_7 ( V_9 ) )
return F_66 ( V_2 , V_289 , V_290 , V_291 , 1 ) ;
else
return F_68 ( V_2 , V_289 , V_290 , V_291 , 1 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_8 V_398 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_398 = F_25 ( V_399 ) ;
V_398 &= ~ V_400 ;
F_26 ( V_399 , V_398 ) ;
break;
case 1 :
V_398 = F_25 ( V_401 ) ;
V_398 &= ~ V_402 ;
F_26 ( V_401 , V_398 ) ;
F_26 ( V_403 , F_25 ( V_404 ) ) ;
F_26 ( V_405 , F_25 ( V_406 ) ) ;
break;
}
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_407 ;
struct V_1 * V_408 ;
V_33 V_409 = 0 ;
if ( F_24 ( V_9 ) ) {
F_8 (test_encoder, &dev->mode_config.encoder_list, head) {
if ( V_407 -> V_2 && ( V_407 -> V_2 == V_2 ) ) {
if ( F_32 ( V_407 ) == V_226 ) {
if ( F_28 ( V_9 ) || V_9 -> clock . V_410 )
return V_139 ;
}
}
}
F_8 (test_crtc, &dev->mode_config.crtc_list, head) {
struct V_11 * V_411 ;
if ( V_2 == V_408 )
continue;
V_411 = F_2 ( V_408 ) ;
if ( ( V_411 -> V_132 >= V_133 ) &&
( V_411 -> V_132 <= V_136 ) )
V_409 |= ( 1 << V_411 -> V_132 ) ;
}
if ( ! ( V_409 & 1 ) )
return V_133 ;
return V_136 ;
} else
return V_11 -> V_18 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_290 , int V_291 , struct V_288 * V_396 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 ;
bool V_412 = false ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
struct V_42 * V_42 = F_9 ( V_41 ) ;
if ( V_42 -> V_43 &
( V_44 | V_413 ) )
V_412 = true ;
}
}
if ( F_24 ( V_9 ) ) {
struct V_143 V_144 ;
bool V_177 = F_44 ( V_9 , & V_144 ,
V_414 ,
V_9 -> clock . V_415 ) ;
if ( V_177 )
F_27 ( V_2 , V_83 , V_138 , & V_144 ) ;
F_40 ( V_2 , V_9 -> clock . V_415 ) ;
if ( V_177 )
F_27 ( V_2 , V_82 , V_138 , & V_144 ) ;
}
F_43 ( V_2 , V_5 ) ;
if ( F_24 ( V_9 ) )
F_21 ( V_2 , V_5 ) ;
else if ( F_7 ( V_9 ) ) {
if ( V_412 )
F_22 ( V_2 , V_5 ) ;
else
F_21 ( V_2 , V_5 ) ;
} else {
F_22 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_21 ( V_2 , V_5 ) ;
F_70 ( V_2 ) ;
}
F_67 ( V_2 , V_290 , V_291 , V_396 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_16 ( V_9 ) ;
if ( ! F_74 ( V_2 , V_4 , V_5 ) )
return false ;
return true ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
V_11 -> V_132 = F_71 ( V_2 ) ;
F_11 ( V_2 , V_82 ) ;
F_15 ( V_2 , V_86 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_80 ) ;
F_11 ( V_2 , V_83 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_143 V_144 ;
F_15 ( V_2 , V_86 ) ;
switch ( V_11 -> V_132 ) {
case V_133 :
case V_136 :
F_42 ( V_2 , V_11 -> V_18 , V_11 -> V_132 ,
0 , 0 , V_83 , 0 , 0 , 0 , 0 , 0 , false , & V_144 ) ;
break;
default:
break;
}
V_11 -> V_132 = - 1 ;
}
void F_78 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_333 = V_416 ;
break;
case 1 :
V_11 -> V_333 = V_417 ;
break;
case 2 :
V_11 -> V_333 = V_418 ;
break;
case 3 :
V_11 -> V_333 = V_419 ;
break;
case 4 :
V_11 -> V_333 = V_420 ;
break;
case 5 :
V_11 -> V_333 = V_421 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_333 =
V_422 - V_423 ;
else
V_11 -> V_333 = 0 ;
}
V_11 -> V_132 = - 1 ;
F_79 ( & V_11 -> V_424 , & V_425 ) ;
}
