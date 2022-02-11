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
if ( ( V_144 -> V_158 == 0 ) || ( V_144 -> type & V_159 ) || F_29 ( V_9 ) )
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
V_176 -> V_105 = 0 ;
if ( F_7 ( V_9 ) ) {
if ( ( V_9 -> V_70 == V_184 ) ||
( V_9 -> V_70 == V_185 ) ||
( V_9 -> V_70 == V_186 ) )
V_176 -> V_105 |= (
V_187 ) ;
if ( F_31 ( V_9 ) && V_4 -> clock > 200000 )
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
V_179 = F_32 ( V_41 ) ;
if ( V_179 )
V_183 = V_179 -> V_193 . V_183 ;
V_181 = F_33 ( V_41 ) ;
if ( ( V_42 -> V_194 & ( V_195 | V_196 ) ) ||
( F_34 ( V_41 ) != V_197 ) ) {
if ( V_179 ) {
struct V_198 * V_198 = F_35 ( V_179 ) ;
struct V_199 * V_200 =
V_198 -> V_201 ;
V_182 = V_200 -> V_182 ;
}
}
if ( V_42 -> V_194 & ( V_195 ) ) {
if ( V_177 ) {
if ( V_144 -> V_202 ) {
V_176 -> V_105 |= V_203 ;
V_176 -> V_204 = V_144 -> V_202 ;
if ( F_7 ( V_9 ) )
V_176 -> V_105 |= V_205 ;
}
}
}
if ( F_7 ( V_9 ) ) {
if ( V_42 -> V_206 == V_207 )
V_180 = V_4 -> clock * 2 ;
if ( V_42 -> V_43 & ( V_44 ) )
V_176 -> V_105 |= V_187 ;
if ( V_42 -> V_194 & ( V_195 ) )
V_176 -> V_105 |= V_208 ;
} else {
if ( V_41 -> V_209 != V_210 )
V_176 -> V_105 |= V_211 ;
if ( V_41 -> V_209 == V_212 )
V_176 -> V_105 |= V_203 ;
}
break;
}
}
if ( F_17 ( V_9 ) ) {
union V_213 args ;
T_9 V_214 , V_215 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_216 ) ;
if ( ! F_36 ( V_9 -> V_31 . V_32 , V_12 , & V_214 ,
& V_215 ) )
return V_180 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_214 ) {
case 1 :
switch ( V_215 ) {
case 1 :
case 2 :
args . V_165 . V_217 = F_4 ( V_4 -> clock / 10 ) ;
args . V_165 . V_218 = V_42 -> V_206 ;
args . V_165 . V_219 = V_181 ;
if ( V_177 && V_144 -> V_158 )
args . V_165 . V_220 |=
V_221 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_180 = F_37 ( args . V_165 . V_217 ) * 10 ;
break;
case 3 :
args . V_147 . V_222 . V_217 = F_4 ( V_4 -> clock / 10 ) ;
args . V_147 . V_222 . V_218 = V_42 -> V_206 ;
args . V_147 . V_222 . V_219 = V_181 ;
args . V_147 . V_222 . V_223 = 0 ;
if ( V_177 && V_144 -> V_158 )
args . V_147 . V_222 . V_223 |=
V_224 ;
if ( F_38 ( V_181 ) ) {
args . V_147 . V_222 . V_223 |=
V_225 ;
args . V_147 . V_222 . V_217 = F_4 ( V_182 / 10 ) ;
} else if ( V_42 -> V_194 & ( V_196 ) ) {
struct V_226 * V_227 = V_42 -> V_47 ;
if ( V_181 == V_228 )
args . V_147 . V_222 . V_217 =
F_4 ( ( V_4 -> clock * V_183 / 8 ) / 10 ) ;
if ( V_227 -> V_229 )
args . V_147 . V_222 . V_223 |=
V_225 ;
if ( V_4 -> clock > 165000 )
args . V_147 . V_222 . V_223 |=
V_230 ;
}
if ( F_34 ( V_41 ) !=
V_197 )
args . V_147 . V_222 . V_231 =
F_34 ( V_41 ) ;
else
args . V_147 . V_222 . V_231 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_180 = F_39 ( args . V_147 . V_232 . V_233 ) * 10 ;
if ( args . V_147 . V_232 . V_234 ) {
V_176 -> V_105 |= V_205 ;
V_176 -> V_105 |= V_203 ;
V_176 -> V_204 = args . V_147 . V_232 . V_234 ;
}
if ( args . V_147 . V_232 . V_235 ) {
V_176 -> V_105 |= V_205 ;
V_176 -> V_105 |= V_236 ;
V_176 -> V_237 = args . V_147 . V_232 . V_235 ;
}
break;
default:
F_40 ( L_1 , V_214 , V_215 ) ;
return V_180 ;
}
break;
default:
F_40 ( L_1 , V_214 , V_215 ) ;
return V_180 ;
}
}
return V_180 ;
}
static void F_41 ( struct V_1 * V_2 ,
T_8 V_238 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_9 V_214 , V_215 ;
int V_12 ;
union V_239 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_240 ) ;
if ( ! F_36 ( V_9 -> V_31 . V_32 , V_12 , & V_214 ,
& V_215 ) )
return;
switch ( V_214 ) {
case 1 :
switch ( V_215 ) {
case 5 :
args . V_241 . V_17 = V_242 ;
args . V_241 . V_217 = F_4 ( V_238 ) ;
args . V_241 . V_171 = V_138 ;
break;
case 6 :
args . V_243 . V_244 = F_42 ( V_238 ) ;
args . V_243 . V_171 = V_138 ;
break;
default:
F_40 ( L_1 , V_214 , V_215 ) ;
return;
}
break;
default:
F_40 ( L_1 , V_214 , V_215 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_43 ( struct V_1 * V_2 ,
T_8 V_18 ,
int V_132 ,
T_8 V_181 ,
T_8 V_206 ,
T_8 clock ,
T_8 V_245 ,
T_8 V_246 ,
T_8 V_247 ,
T_8 V_237 ,
int V_183 ,
bool V_177 ,
struct V_143 * V_144 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_9 V_214 , V_215 ;
int V_12 = F_3 ( V_13 , V_240 ) ;
union V_239 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_36 ( V_9 -> V_31 . V_32 , V_12 , & V_214 ,
& V_215 ) )
return;
switch ( V_214 ) {
case 1 :
switch ( V_215 ) {
case 1 :
if ( clock == V_83 )
return;
args . V_165 . V_217 = F_4 ( clock / 10 ) ;
args . V_165 . V_248 = F_4 ( V_245 ) ;
args . V_165 . V_249 = F_4 ( V_246 ) ;
args . V_165 . V_250 = V_247 ;
args . V_165 . V_235 = V_237 ;
args . V_165 . V_171 = V_132 ;
args . V_165 . V_17 = V_18 ;
args . V_165 . V_251 = 1 ;
break;
case 2 :
args . V_160 . V_217 = F_4 ( clock / 10 ) ;
args . V_160 . V_248 = F_4 ( V_245 ) ;
args . V_160 . V_249 = F_4 ( V_246 ) ;
args . V_160 . V_250 = V_247 ;
args . V_160 . V_235 = V_237 ;
args . V_160 . V_171 = V_132 ;
args . V_160 . V_17 = V_18 ;
args . V_160 . V_251 = 1 ;
break;
case 3 :
args . V_147 . V_217 = F_4 ( clock / 10 ) ;
args . V_147 . V_248 = F_4 ( V_245 ) ;
args . V_147 . V_249 = F_4 ( V_246 ) ;
args . V_147 . V_250 = V_247 ;
args . V_147 . V_235 = V_237 ;
args . V_147 . V_171 = V_132 ;
args . V_147 . V_252 = ( V_132 << 2 ) ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_147 . V_252 |= V_253 ;
args . V_147 . V_254 = V_206 ;
args . V_147 . V_255 = V_181 ;
break;
case 5 :
args . V_241 . V_17 = V_18 ;
args . V_241 . V_217 = F_4 ( clock / 10 ) ;
args . V_241 . V_234 = V_245 ;
args . V_241 . V_249 = F_4 ( V_246 ) ;
args . V_241 . V_256 = F_42 ( V_247 * 100000 ) ;
args . V_241 . V_235 = V_237 ;
args . V_241 . V_252 = 0 ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_241 . V_252 |= V_257 ;
switch ( V_183 ) {
case 8 :
default:
args . V_241 . V_252 |= V_258 ;
break;
case 10 :
args . V_241 . V_252 |= V_259 ;
break;
}
args . V_241 . V_218 = V_206 ;
args . V_241 . V_255 = V_181 ;
args . V_241 . V_171 = V_132 ;
break;
case 6 :
args . V_243 . V_244 = F_42 ( V_18 << 24 | clock / 10 ) ;
args . V_243 . V_234 = V_245 ;
args . V_243 . V_249 = F_4 ( V_246 ) ;
args . V_243 . V_256 = F_42 ( V_247 * 100000 ) ;
args . V_243 . V_235 = V_237 ;
args . V_243 . V_252 = 0 ;
if ( V_177 && ( V_144 -> type & V_159 ) )
args . V_243 . V_252 |= V_260 ;
switch ( V_183 ) {
case 8 :
default:
args . V_243 . V_252 |= V_261 ;
break;
case 10 :
args . V_243 . V_252 |= V_262 ;
break;
case 12 :
args . V_243 . V_252 |= V_263 ;
break;
case 16 :
args . V_243 . V_252 |= V_264 ;
break;
}
args . V_243 . V_218 = V_206 ;
args . V_243 . V_255 = V_181 ;
args . V_243 . V_171 = V_132 ;
break;
default:
F_40 ( L_1 , V_214 , V_215 ) ;
return;
}
break;
default:
F_40 ( L_1 , V_214 , V_215 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_42 = NULL ;
T_8 V_265 = V_4 -> clock ;
T_8 V_245 = 0 , V_246 = 0 , V_247 = 0 , V_237 = 0 ;
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
switch ( V_11 -> V_132 ) {
case V_133 :
V_176 = & V_9 -> clock . V_266 ;
break;
case V_136 :
V_176 = & V_9 -> clock . V_267 ;
break;
case V_138 :
case V_139 :
default:
V_176 = & V_9 -> clock . V_268 ;
break;
}
if ( V_42 -> V_43 &
( V_195 | V_196 ) ) {
struct V_226 * V_227 = V_42 -> V_47 ;
struct V_178 * V_179 =
F_32 ( V_41 ) ;
struct V_198 * V_198 =
F_35 ( V_179 ) ;
struct V_199 * V_200 =
V_198 -> V_201 ;
int V_182 ;
V_183 = V_179 -> V_193 . V_183 ;
switch ( V_181 ) {
case V_269 :
case V_270 :
V_182 = V_200 -> V_182 / 10 ;
if ( F_24 ( V_9 ) )
V_177 =
F_45 ( V_9 , & V_144 ,
V_271 ,
V_182 ) ;
else {
if ( V_182 == 16200 ) {
V_177 =
F_46 ( V_9 , & V_144 ,
V_272 ) ;
if ( ! V_177 )
V_177 =
F_46 ( V_9 , & V_144 ,
V_273 ) ;
} else
V_177 =
F_46 ( V_9 , & V_144 ,
V_273 ) ;
}
break;
case V_274 :
if ( F_24 ( V_9 ) )
V_177 = F_45 ( V_9 , & V_144 ,
V_227 -> V_275 ,
V_4 -> clock / 10 ) ;
else
V_177 = F_46 ( V_9 , & V_144 ,
V_227 -> V_275 ) ;
break;
case V_276 :
if ( F_24 ( V_9 ) )
V_177 =
F_45 ( V_9 , & V_144 ,
V_277 ,
V_4 -> clock / 10 ) ;
break;
case V_228 :
if ( F_24 ( V_9 ) )
V_177 =
F_45 ( V_9 , & V_144 ,
V_278 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_180 = F_30 ( V_2 , V_4 , V_176 , V_177 , & V_144 ) ;
if ( V_42 -> V_43 & ( V_44 ) )
F_47 ( V_176 , V_180 , & V_265 , & V_246 , & V_247 ,
& V_245 , & V_237 ) ;
else if ( F_7 ( V_9 ) )
F_48 ( V_176 , V_180 , & V_265 , & V_246 , & V_247 ,
& V_245 , & V_237 ) ;
else
F_47 ( V_176 , V_180 , & V_265 , & V_246 , & V_247 ,
& V_245 , & V_237 ) ;
F_27 ( V_2 , V_83 , V_11 -> V_132 , & V_144 ) ;
F_43 ( V_2 , V_11 -> V_18 , V_11 -> V_132 ,
V_181 , V_42 -> V_206 , V_4 -> clock ,
V_245 , V_246 , V_247 , V_237 , V_183 , V_177 , & V_144 ) ;
if ( V_177 ) {
if ( F_24 ( V_9 ) ) {
T_8 V_279 ;
T_8 V_153 = ( ( ( V_246 * 10 ) + V_247 ) * V_144 . V_158 ) / 10000 ;
V_144 . V_153 = ( V_153 / 10 ) & V_280 ;
V_144 . V_153 |= ( ( V_153 - ( V_153 / 10 ) ) << V_281 ) &
V_282 ;
if ( V_144 . type & V_283 )
V_279 = ( 4 * V_153 * V_245 * ( V_144 . V_284 * 2048 ) ) /
( 125 * 25 * V_176 -> V_285 / 100 ) ;
else
V_279 = ( 2 * V_153 * V_245 * ( V_144 . V_284 * 2048 ) ) /
( 125 * 25 * V_176 -> V_285 / 100 ) ;
V_144 . V_155 = V_279 ;
}
F_27 ( V_2 , V_82 , V_11 -> V_132 , & V_144 ) ;
}
}
static int F_49 ( struct V_1 * V_2 ,
struct V_286 * V_287 ,
int V_288 , int V_289 , int V_290 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_291 * V_292 ;
struct V_286 * V_293 ;
struct V_294 * V_295 ;
struct V_296 * V_297 ;
T_10 V_298 ;
V_33 V_299 , V_300 , V_301 ;
T_8 V_302 = F_50 ( V_303 ) ;
T_8 V_304 , V_305 , V_306 ;
int V_307 ;
if ( ! V_290 && ! V_2 -> V_287 ) {
F_51 ( L_2 ) ;
return 0 ;
}
if ( V_290 ) {
V_292 = F_52 ( V_287 ) ;
V_293 = V_287 ;
}
else {
V_292 = F_52 ( V_2 -> V_287 ) ;
V_293 = V_2 -> V_287 ;
}
V_295 = V_292 -> V_295 ;
V_297 = F_53 ( V_295 ) ;
V_307 = F_54 ( V_297 , false ) ;
if ( F_55 ( V_307 != 0 ) )
return V_307 ;
if ( V_290 )
V_298 = F_56 ( V_297 ) ;
else {
V_307 = F_57 ( V_297 , V_308 , & V_298 ) ;
if ( F_55 ( V_307 != 0 ) ) {
F_58 ( V_297 ) ;
return - V_309 ;
}
}
F_59 ( V_297 , & V_301 , NULL ) ;
F_58 ( V_297 ) ;
switch ( V_293 -> V_310 ) {
case 8 :
V_299 = ( F_60 ( V_311 ) |
F_61 ( V_312 ) ) ;
break;
case 15 :
V_299 = ( F_60 ( V_313 ) |
F_61 ( V_314 ) ) ;
break;
case 16 :
V_299 = ( F_60 ( V_313 ) |
F_61 ( V_315 ) ) ;
#ifdef F_62
V_302 = F_50 ( V_316 ) ;
#endif
break;
case 24 :
case 32 :
V_299 = ( F_60 ( V_317 ) |
F_61 ( V_318 ) ) ;
#ifdef F_62
V_302 = F_50 ( V_319 ) ;
#endif
break;
default:
F_40 ( L_3 ,
V_293 -> V_310 ) ;
return - V_309 ;
}
if ( V_301 & V_320 ) {
if ( V_9 -> V_70 >= V_321 )
V_304 = V_9 -> V_322 . V_323 . V_324 ;
else
V_304 = V_9 -> V_322 . V_325 . V_324 ;
switch ( ( V_304 & 0xf0 ) >> 4 ) {
case 0 :
V_299 |= F_63 ( V_326 ) ;
break;
case 1 :
default:
V_299 |= F_63 ( V_327 ) ;
break;
case 2 :
V_299 |= F_63 ( V_328 ) ;
break;
}
switch ( ( V_304 & 0xf000 ) >> 12 ) {
case 0 :
default:
V_299 |= F_64 ( V_329 ) ;
break;
case 1 :
V_299 |= F_64 ( V_330 ) ;
break;
case 2 :
V_299 |= F_64 ( V_331 ) ;
break;
}
V_299 |= F_65 ( V_332 ) ;
} else if ( V_301 & V_333 )
V_299 |= F_65 ( V_334 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_26 ( V_335 , 0 ) ;
break;
case 1 :
F_26 ( V_336 , 0 ) ;
break;
case 2 :
F_26 ( V_337 , 0 ) ;
break;
case 3 :
F_26 ( V_338 , 0 ) ;
break;
case 4 :
F_26 ( V_339 , 0 ) ;
break;
case 5 :
F_26 ( V_340 , 0 ) ;
break;
default:
break;
}
F_26 ( V_341 + V_11 -> V_342 ,
F_66 ( V_298 ) ) ;
F_26 ( V_343 + V_11 -> V_342 ,
F_66 ( V_298 ) ) ;
F_26 ( V_344 + V_11 -> V_342 ,
( T_8 ) V_298 & V_345 ) ;
F_26 ( V_346 + V_11 -> V_342 ,
( T_8 ) V_298 & V_345 ) ;
F_26 ( V_347 + V_11 -> V_342 , V_299 ) ;
F_26 ( V_348 + V_11 -> V_342 , V_302 ) ;
F_26 ( V_349 + V_11 -> V_342 , 0 ) ;
F_26 ( V_350 + V_11 -> V_342 , 0 ) ;
F_26 ( V_351 + V_11 -> V_342 , 0 ) ;
F_26 ( V_352 + V_11 -> V_342 , 0 ) ;
F_26 ( V_353 + V_11 -> V_342 , V_293 -> V_354 ) ;
F_26 ( V_355 + V_11 -> V_342 , V_293 -> V_356 ) ;
V_300 = V_293 -> V_357 / ( V_293 -> V_310 / 8 ) ;
F_26 ( V_358 + V_11 -> V_342 , V_300 ) ;
F_26 ( V_359 + V_11 -> V_342 , 1 ) ;
F_26 ( V_360 + V_11 -> V_342 ,
V_2 -> V_4 . V_361 ) ;
V_288 &= ~ 3 ;
V_289 &= ~ 1 ;
F_26 ( V_362 + V_11 -> V_342 ,
( V_288 << 16 ) | V_289 ) ;
V_305 = V_2 -> V_4 . V_363 ;
V_306 = ( V_2 -> V_4 . V_361 + 1 ) & ~ 1 ;
F_26 ( V_364 + V_11 -> V_342 ,
( V_305 << 16 ) | V_306 ) ;
V_304 = F_25 ( V_365 + V_11 -> V_342 ) ;
V_304 &= ~ V_366 ;
F_26 ( V_365 + V_11 -> V_342 , V_304 ) ;
F_26 ( V_367 + V_11 -> V_342 , 0 ) ;
if ( ! V_290 && V_287 && V_287 != V_2 -> V_287 ) {
V_292 = F_52 ( V_287 ) ;
V_297 = F_53 ( V_292 -> V_295 ) ;
V_307 = F_54 ( V_297 , false ) ;
if ( F_55 ( V_307 != 0 ) )
return V_307 ;
F_67 ( V_297 ) ;
F_58 ( V_297 ) ;
}
F_68 ( V_9 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_286 * V_287 ,
int V_288 , int V_289 , int V_290 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_291 * V_292 ;
struct V_294 * V_295 ;
struct V_296 * V_297 ;
struct V_286 * V_293 ;
T_10 V_298 ;
V_33 V_299 , V_300 , V_301 ;
T_8 V_302 = V_368 ;
T_8 V_304 , V_305 , V_306 ;
int V_307 ;
if ( ! V_290 && ! V_2 -> V_287 ) {
F_51 ( L_2 ) ;
return 0 ;
}
if ( V_290 ) {
V_292 = F_52 ( V_287 ) ;
V_293 = V_287 ;
}
else {
V_292 = F_52 ( V_2 -> V_287 ) ;
V_293 = V_2 -> V_287 ;
}
V_295 = V_292 -> V_295 ;
V_297 = F_53 ( V_295 ) ;
V_307 = F_54 ( V_297 , false ) ;
if ( F_55 ( V_307 != 0 ) )
return V_307 ;
if ( V_290 )
V_298 = F_56 ( V_297 ) ;
else {
V_307 = F_57 ( V_297 , V_308 , & V_298 ) ;
if ( F_55 ( V_307 != 0 ) ) {
F_58 ( V_297 ) ;
return - V_309 ;
}
}
F_59 ( V_297 , & V_301 , NULL ) ;
F_58 ( V_297 ) ;
switch ( V_293 -> V_310 ) {
case 8 :
V_299 =
V_369 |
V_370 ;
break;
case 15 :
V_299 =
V_371 |
V_372 ;
break;
case 16 :
V_299 =
V_371 |
V_373 ;
#ifdef F_62
V_302 = V_374 ;
#endif
break;
case 24 :
case 32 :
V_299 =
V_375 |
V_376 ;
#ifdef F_62
V_302 = V_377 ;
#endif
break;
default:
F_40 ( L_3 ,
V_293 -> V_310 ) ;
return - V_309 ;
}
if ( V_9 -> V_70 >= V_378 ) {
if ( V_301 & V_320 )
V_299 |= V_379 ;
else if ( V_301 & V_333 )
V_299 |= V_380 ;
} else {
if ( V_301 & V_320 )
V_299 |= V_381 ;
if ( V_301 & V_333 )
V_299 |= V_382 ;
}
if ( V_11 -> V_18 == 0 )
F_26 ( V_335 , 0 ) ;
else
F_26 ( V_336 , 0 ) ;
if ( V_9 -> V_70 >= V_190 ) {
if ( V_11 -> V_18 ) {
F_26 ( V_383 , F_66 ( V_298 ) ) ;
F_26 ( V_384 , F_66 ( V_298 ) ) ;
} else {
F_26 ( V_385 , F_66 ( V_298 ) ) ;
F_26 ( V_386 , F_66 ( V_298 ) ) ;
}
}
F_26 ( V_387 + V_11 -> V_342 ,
( T_8 ) V_298 ) ;
F_26 ( V_388 +
V_11 -> V_342 , ( T_8 ) V_298 ) ;
F_26 ( V_389 + V_11 -> V_342 , V_299 ) ;
if ( V_9 -> V_70 >= V_378 )
F_26 ( V_390 + V_11 -> V_342 , V_302 ) ;
F_26 ( V_391 + V_11 -> V_342 , 0 ) ;
F_26 ( V_392 + V_11 -> V_342 , 0 ) ;
F_26 ( V_393 + V_11 -> V_342 , 0 ) ;
F_26 ( V_394 + V_11 -> V_342 , 0 ) ;
F_26 ( V_395 + V_11 -> V_342 , V_293 -> V_354 ) ;
F_26 ( V_396 + V_11 -> V_342 , V_293 -> V_356 ) ;
V_300 = V_293 -> V_357 / ( V_293 -> V_310 / 8 ) ;
F_26 ( V_397 + V_11 -> V_342 , V_300 ) ;
F_26 ( V_398 + V_11 -> V_342 , 1 ) ;
F_26 ( V_399 + V_11 -> V_342 ,
V_2 -> V_4 . V_361 ) ;
V_288 &= ~ 3 ;
V_289 &= ~ 1 ;
F_26 ( V_400 + V_11 -> V_342 ,
( V_288 << 16 ) | V_289 ) ;
V_305 = V_2 -> V_4 . V_363 ;
V_306 = ( V_2 -> V_4 . V_361 + 1 ) & ~ 1 ;
F_26 ( V_401 + V_11 -> V_342 ,
( V_305 << 16 ) | V_306 ) ;
V_304 = F_25 ( V_402 + V_11 -> V_342 ) ;
V_304 &= ~ V_403 ;
F_26 ( V_402 + V_11 -> V_342 , V_304 ) ;
F_26 ( V_404 + V_11 -> V_342 , 0 ) ;
if ( ! V_290 && V_287 && V_287 != V_2 -> V_287 ) {
V_292 = F_52 ( V_287 ) ;
V_297 = F_53 ( V_292 -> V_295 ) ;
V_307 = F_54 ( V_297 , false ) ;
if ( F_55 ( V_307 != 0 ) )
return V_307 ;
F_67 ( V_297 ) ;
F_58 ( V_297 ) ;
}
F_68 ( V_9 ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 , int V_288 , int V_289 ,
struct V_286 * V_405 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) )
return F_49 ( V_2 , V_405 , V_288 , V_289 , 0 ) ;
else if ( F_7 ( V_9 ) )
return F_69 ( V_2 , V_405 , V_288 , V_289 , 0 ) ;
else
return F_71 ( V_2 , V_405 , V_288 , V_289 , 0 ) ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_286 * V_287 ,
int V_288 , int V_289 , enum V_406 V_75 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) )
return F_49 ( V_2 , V_287 , V_288 , V_289 , 1 ) ;
else if ( F_7 ( V_9 ) )
return F_69 ( V_2 , V_287 , V_288 , V_289 , 1 ) ;
else
return F_71 ( V_2 , V_287 , V_288 , V_289 , 1 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_8 V_407 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_407 = F_25 ( V_408 ) ;
V_407 &= ~ V_409 ;
F_26 ( V_408 , V_407 ) ;
break;
case 1 :
V_407 = F_25 ( V_410 ) ;
V_407 &= ~ V_411 ;
F_26 ( V_410 , V_407 ) ;
F_26 ( V_412 , F_25 ( V_413 ) ) ;
F_26 ( V_414 , F_25 ( V_415 ) ) ;
break;
}
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_416 ;
struct V_1 * V_417 ;
V_33 V_418 = 0 ;
if ( F_24 ( V_9 ) ) {
F_8 (test_encoder, &dev->mode_config.encoder_list, head) {
if ( V_416 -> V_2 && ( V_416 -> V_2 == V_2 ) ) {
if ( F_38 ( F_33 ( V_416 ) ) ) {
if ( F_28 ( V_9 ) || V_9 -> clock . V_419 )
return V_139 ;
}
}
}
F_8 (test_crtc, &dev->mode_config.crtc_list, head) {
struct V_11 * V_420 ;
if ( V_2 == V_417 )
continue;
V_420 = F_2 ( V_417 ) ;
if ( ( V_420 -> V_132 >= V_133 ) &&
( V_420 -> V_132 <= V_136 ) )
V_418 |= ( 1 << V_420 -> V_132 ) ;
}
if ( ! ( V_418 & 1 ) )
return V_133 ;
return V_136 ;
} else
return V_11 -> V_18 ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_288 , int V_289 , struct V_286 * V_405 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 ;
bool V_421 = false ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
struct V_42 * V_42 = F_9 ( V_41 ) ;
if ( V_42 -> V_43 &
( V_44 | V_422 ) )
V_421 = true ;
}
}
if ( F_24 ( V_9 ) ) {
struct V_143 V_144 ;
bool V_177 = F_45 ( V_9 , & V_144 ,
V_423 ,
V_9 -> clock . V_424 ) ;
if ( V_177 )
F_27 ( V_2 , V_83 , V_138 , & V_144 ) ;
F_41 ( V_2 , V_9 -> clock . V_424 ) ;
if ( V_177 )
F_27 ( V_2 , V_82 , V_138 , & V_144 ) ;
}
F_44 ( V_2 , V_5 ) ;
if ( F_24 ( V_9 ) )
F_21 ( V_2 , V_5 ) ;
else if ( F_7 ( V_9 ) ) {
if ( V_421 )
F_22 ( V_2 , V_5 ) ;
else
F_21 ( V_2 , V_5 ) ;
} else {
F_22 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_21 ( V_2 , V_5 ) ;
F_73 ( V_2 ) ;
}
F_70 ( V_2 , V_288 , V_289 , V_405 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool F_76 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
if ( ! F_77 ( V_2 , V_4 , V_5 ) )
return false ;
return true ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
V_11 -> V_132 = F_74 ( V_2 ) ;
F_11 ( V_2 , V_82 ) ;
F_15 ( V_2 , V_86 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_80 ) ;
F_11 ( V_2 , V_83 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_143 V_144 ;
F_15 ( V_2 , V_86 ) ;
switch ( V_11 -> V_132 ) {
case V_133 :
case V_136 :
F_43 ( V_2 , V_11 -> V_18 , V_11 -> V_132 ,
0 , 0 , V_83 , 0 , 0 , 0 , 0 , 0 , false , & V_144 ) ;
break;
default:
break;
}
V_11 -> V_132 = - 1 ;
}
void F_81 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_24 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_342 = V_425 ;
break;
case 1 :
V_11 -> V_342 = V_426 ;
break;
case 2 :
V_11 -> V_342 = V_427 ;
break;
case 3 :
V_11 -> V_342 = V_428 ;
break;
case 4 :
V_11 -> V_342 = V_429 ;
break;
case 5 :
V_11 -> V_342 = V_430 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_342 =
V_431 - V_432 ;
else
V_11 -> V_342 = 0 ;
}
V_11 -> V_132 = - 1 ;
F_82 ( & V_11 -> V_433 , & V_434 ) ;
}
