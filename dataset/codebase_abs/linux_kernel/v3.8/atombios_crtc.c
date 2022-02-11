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
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
enum V_37 V_38 = V_39 ;
bool V_40 = false , V_41 = false ;
if ( ! F_8 ( V_9 ) && V_11 -> V_18 )
return;
if ( V_35 -> V_42 & V_43 ) {
struct V_44 * V_45 = V_35 -> V_46 ;
V_38 = V_45 -> V_38 ;
V_40 = true ;
}
memset ( & args , 0 , sizeof( args ) ) ;
args . V_47 = V_11 -> V_18 ;
if ( V_40 ) {
switch ( V_38 ) {
case V_39 :
default:
args . V_48 = V_49 ;
break;
case V_50 :
args . V_48 = V_51 ;
break;
case V_52 :
args . V_48 = V_53 ;
break;
case V_54 :
args . V_48 = V_55 ;
break;
case V_56 :
args . V_48 = V_57 ;
break;
case V_58 :
args . V_48 = V_51 ;
break;
case V_59 :
args . V_48 = V_60 ;
break;
case V_61 :
args . V_48 = V_62 ;
break;
}
args . V_63 = V_64 ;
} else if ( V_41 ) {
args . V_48 = V_65 ;
args . V_63 = V_64 ;
} else {
switch ( V_11 -> V_19 ) {
case V_28 :
args . V_63 = V_66 ;
break;
case V_20 :
args . V_63 = V_67 ;
break;
case V_27 :
args . V_63 = V_66 ;
break;
default:
if ( F_8 ( V_9 ) )
args . V_63 = V_68 ;
else
args . V_63 = V_67 ;
break;
}
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
if ( ( V_40 || V_41 )
&& V_9 -> V_69 >= V_70 && V_9 -> V_69 <= V_71 ) {
F_9 ( V_9 , V_11 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , int V_72 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 =
F_3 ( V_13 , V_73 ) ;
T_3 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_63 = V_72 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_74 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_75 ) ;
T_3 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_63 = V_74 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_74 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_76 ) ;
T_3 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_63 = V_74 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_74 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_77 ) ;
T_4 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_17 = V_11 -> V_18 ;
args . V_78 = V_74 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_74 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_79 ) ;
T_5 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_80 = V_11 -> V_18 ;
args . V_63 = V_74 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
void F_15 ( struct V_1 * V_2 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_81 :
V_11 -> V_82 = true ;
F_16 ( V_9 ) ;
if ( F_17 ( V_9 ) && ! V_11 -> V_83 )
F_14 ( V_2 , V_84 ) ;
F_11 ( V_2 , V_85 ) ;
if ( F_18 ( V_9 ) && ! F_17 ( V_9 ) )
F_12 ( V_2 , V_85 ) ;
F_13 ( V_2 , V_84 ) ;
F_19 ( V_7 , V_11 -> V_18 ) ;
F_20 ( V_2 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
F_21 ( V_7 , V_11 -> V_18 ) ;
if ( V_11 -> V_82 )
F_13 ( V_2 , V_85 ) ;
if ( F_18 ( V_9 ) && ! F_17 ( V_9 ) )
F_12 ( V_2 , V_84 ) ;
F_11 ( V_2 , V_84 ) ;
V_11 -> V_82 = false ;
if ( F_17 ( V_9 ) && ! V_11 -> V_83 )
F_14 ( V_2 , V_85 ) ;
F_16 ( V_9 ) ;
break;
}
}
static void
F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_6 args ;
int V_12 = F_3 ( V_13 , V_89 ) ;
T_7 V_90 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_91 = F_4 ( V_4 -> V_25 - ( V_11 -> V_29 * 2 ) ) ;
args . V_92 =
F_4 ( V_4 -> V_93 - V_4 -> V_25 + ( V_11 -> V_29 * 2 ) ) ;
args . V_94 = F_4 ( V_4 -> V_22 - ( V_11 -> V_30 * 2 ) ) ;
args . V_95 =
F_4 ( V_4 -> V_96 - V_4 -> V_22 + ( V_11 -> V_30 * 2 ) ) ;
args . V_97 =
F_4 ( V_4 -> V_98 - V_4 -> V_25 + V_11 -> V_29 ) ;
args . V_99 =
F_4 ( V_4 -> V_100 - V_4 -> V_98 ) ;
args . V_101 =
F_4 ( V_4 -> V_102 - V_4 -> V_22 + V_11 -> V_30 ) ;
args . V_103 =
F_4 ( V_4 -> V_104 - V_4 -> V_102 ) ;
args . V_105 = V_11 -> V_29 ;
args . V_106 = V_11 -> V_30 ;
if ( V_4 -> V_107 & V_108 )
V_90 |= V_109 ;
if ( V_4 -> V_107 & V_110 )
V_90 |= V_111 ;
if ( V_4 -> V_107 & V_112 )
V_90 |= V_113 ;
if ( V_4 -> V_107 & V_114 )
V_90 |= V_115 ;
if ( V_4 -> V_107 & V_116 )
V_90 |= V_117 ;
args . V_118 . V_119 = F_4 ( V_90 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_8 args ;
int V_12 = F_3 ( V_13 , V_120 ) ;
T_7 V_90 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_121 = F_4 ( V_4 -> V_122 ) ;
args . V_123 = F_4 ( V_4 -> V_25 ) ;
args . V_124 = F_4 ( V_4 -> V_98 ) ;
args . V_99 =
F_4 ( V_4 -> V_100 - V_4 -> V_98 ) ;
args . V_125 = F_4 ( V_4 -> V_126 ) ;
args . V_127 = F_4 ( V_4 -> V_22 ) ;
args . V_128 = F_4 ( V_4 -> V_102 ) ;
args . V_103 =
F_4 ( V_4 -> V_104 - V_4 -> V_102 ) ;
args . V_129 = V_11 -> V_29 ;
args . V_130 = V_11 -> V_29 ;
args . V_131 = V_11 -> V_30 ;
args . V_132 = V_11 -> V_30 ;
if ( V_4 -> V_107 & V_108 )
V_90 |= V_109 ;
if ( V_4 -> V_107 & V_110 )
V_90 |= V_111 ;
if ( V_4 -> V_107 & V_112 )
V_90 |= V_113 ;
if ( V_4 -> V_107 & V_114 )
V_90 |= V_115 ;
if ( V_4 -> V_107 & V_116 )
V_90 |= V_117 ;
args . V_118 . V_119 = F_4 ( V_90 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_24 ( struct V_8 * V_9 , int V_133 )
{
T_9 V_134 ;
if ( F_25 ( V_9 ) ) {
switch ( V_133 ) {
case V_135 :
V_134 = F_26 ( V_136 ) ;
V_134 &= ~ V_137 ;
F_27 ( V_136 , V_134 ) ;
break;
case V_138 :
V_134 = F_26 ( V_139 ) ;
V_134 &= ~ V_137 ;
F_27 ( V_139 , V_134 ) ;
break;
case V_140 :
case V_141 :
return;
}
} else if ( F_8 ( V_9 ) ) {
switch ( V_133 ) {
case V_135 :
V_134 = F_26 ( V_142 ) ;
V_134 &= ~ 1 ;
F_27 ( V_142 , V_134 ) ;
break;
case V_138 :
V_134 = F_26 ( V_143 ) ;
V_134 &= ~ 1 ;
F_27 ( V_143 , V_134 ) ;
break;
case V_140 :
case V_141 :
return;
}
}
}
static void F_28 ( struct V_8 * V_9 ,
int V_144 ,
int V_133 ,
int V_18 ,
struct V_145 * V_146 )
{
unsigned V_147 ;
int V_12 = F_3 ( V_13 , V_148 ) ;
union V_149 args ;
if ( ! V_144 ) {
for ( V_147 = 0 ; V_147 < V_9 -> V_150 ; V_147 ++ ) {
if ( V_9 -> V_31 . V_151 [ V_147 ] &&
V_9 -> V_31 . V_151 [ V_147 ] -> V_82 &&
V_147 != V_18 &&
V_133 == V_9 -> V_31 . V_151 [ V_147 ] -> V_133 ) {
return;
}
}
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_29 ( V_9 ) ) {
args . V_152 . V_153 = F_4 ( 0 ) ;
args . V_152 . V_154 = V_146 -> type & V_155 ;
switch ( V_133 ) {
case V_135 :
args . V_152 . V_154 |= V_156 ;
break;
case V_138 :
args . V_152 . V_154 |= V_157 ;
break;
case V_140 :
args . V_152 . V_154 |= V_158 ;
break;
case V_141 :
return;
}
args . V_152 . V_159 = F_4 ( V_146 -> V_160 ) ;
args . V_152 . V_161 = F_4 ( V_146 -> V_162 ) ;
args . V_152 . V_63 = V_144 ;
if ( ( V_146 -> V_163 == 0 ) || ( V_146 -> type & V_164 ) || F_30 ( V_9 ) )
args . V_152 . V_63 = V_84 ;
} else if ( F_25 ( V_9 ) ) {
args . V_165 . V_166 = F_4 ( V_146 -> V_163 ) ;
args . V_165 . V_154 = V_146 -> type & V_155 ;
switch ( V_133 ) {
case V_135 :
args . V_165 . V_154 |= V_167 ;
break;
case V_138 :
args . V_165 . V_154 |= V_168 ;
break;
case V_140 :
args . V_165 . V_154 |= V_169 ;
break;
case V_141 :
return;
}
args . V_165 . V_159 = F_4 ( V_146 -> V_160 ) ;
args . V_165 . V_161 = F_4 ( V_146 -> V_162 ) ;
args . V_165 . V_63 = V_144 ;
if ( ( V_146 -> V_163 == 0 ) || ( V_146 -> type & V_164 ) || F_31 ( V_9 ) )
args . V_165 . V_63 = V_84 ;
} else if ( F_18 ( V_9 ) ) {
args . V_170 . V_166 = F_4 ( V_146 -> V_163 ) ;
args . V_170 . V_154 = V_146 -> type & V_155 ;
args . V_170 . V_171 = V_146 -> V_162 ;
args . V_170 . V_172 = V_146 -> V_173 ;
args . V_170 . V_174 = V_146 -> V_175 ;
args . V_170 . V_176 = V_133 ;
args . V_170 . V_63 = V_144 ;
} else if ( F_8 ( V_9 ) ) {
if ( ( V_144 == V_84 ) || ( V_146 -> V_163 == 0 ) ||
( V_146 -> type & V_164 ) ) {
F_24 ( V_9 , V_133 ) ;
return;
}
args . V_177 . V_166 = F_4 ( V_146 -> V_163 ) ;
args . V_177 . V_154 = V_146 -> type & V_155 ;
args . V_177 . V_171 = V_146 -> V_162 ;
args . V_177 . V_172 = V_146 -> V_173 ;
args . V_177 . V_174 = V_146 -> V_175 ;
args . V_177 . V_63 = V_144 ;
} else {
if ( ( V_144 == V_84 ) || ( V_146 -> V_163 == 0 ) ||
( V_146 -> type & V_164 ) ) {
F_24 ( V_9 , V_133 ) ;
return;
}
args . V_178 . V_166 = F_4 ( V_146 -> V_163 ) ;
args . V_178 . V_154 = V_146 -> type & V_155 ;
args . V_178 . V_179 = ( V_146 -> V_162 & 3 ) << 2 ;
args . V_178 . V_179 |= ( V_146 -> V_173 & 7 ) << 4 ;
args . V_178 . V_63 = V_144 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_9 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_180 * V_36 = V_11 -> V_36 ;
struct V_35 * V_35 = F_7 ( V_36 ) ;
struct V_181 * V_182 = F_33 ( V_36 ) ;
T_9 V_183 = V_4 -> clock ;
int V_184 = F_34 ( V_36 ) ;
T_9 V_185 = V_4 -> clock ;
int V_186 = F_35 ( V_182 ) ;
bool V_187 = F_36 ( V_36 , V_4 -> clock ) ;
V_11 -> V_188 = 0 ;
if ( F_8 ( V_9 ) ) {
if ( ( V_9 -> V_69 == V_189 ) ||
( V_9 -> V_69 == V_190 ) ||
( V_9 -> V_69 == V_191 ) )
V_11 -> V_188 |= (
V_192 ) ;
if ( F_37 ( V_9 ) && V_4 -> clock > 200000 )
V_11 -> V_188 |= V_193 ;
else
V_11 -> V_188 |= V_194 ;
if ( V_9 -> V_69 < V_195 )
V_11 -> V_188 |= V_196 ;
if ( F_31 ( V_9 ) || F_30 ( V_9 ) )
V_11 -> V_188 |= V_197 ;
if ( F_37 ( V_9 ) && V_4 -> clock > 165000 )
V_11 -> V_188 |= V_197 ;
} else {
V_11 -> V_188 |= V_198 ;
if ( V_4 -> clock > 200000 )
V_11 -> V_188 |= V_193 ;
else
V_11 -> V_188 |= V_194 ;
}
if ( ( V_35 -> V_199 & ( V_200 | V_201 ) ) ||
( F_38 ( V_36 ) != V_202 ) ) {
if ( V_182 ) {
struct V_203 * V_203 = F_39 ( V_182 ) ;
struct V_204 * V_205 =
V_203 -> V_206 ;
V_185 = V_205 -> V_185 ;
}
}
if ( V_35 -> V_199 & ( V_200 ) ) {
if ( V_11 -> V_207 ) {
if ( V_11 -> V_146 . V_208 ) {
V_11 -> V_188 |= V_209 ;
V_11 -> V_210 = V_11 -> V_146 . V_208 ;
if ( F_8 ( V_9 ) )
V_11 -> V_188 |= V_197 ;
}
}
}
if ( F_8 ( V_9 ) ) {
if ( V_35 -> V_211 == V_212 )
V_183 = V_4 -> clock * 2 ;
if ( V_35 -> V_42 & ( V_43 ) )
V_11 -> V_188 |= V_192 ;
if ( V_35 -> V_199 & ( V_200 ) )
V_11 -> V_188 |= V_213 ;
} else {
if ( V_36 -> V_214 != V_215 )
V_11 -> V_188 |= V_216 ;
if ( V_36 -> V_214 == V_217 )
V_11 -> V_188 |= V_209 ;
}
if ( F_18 ( V_9 ) ) {
union V_218 args ;
T_10 V_219 , V_220 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_221 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_219 ,
& V_220 ) )
return V_183 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_219 ) {
case 1 :
switch ( V_220 ) {
case 1 :
case 2 :
args . V_170 . V_222 = F_4 ( V_4 -> clock / 10 ) ;
args . V_170 . V_223 = V_35 -> V_211 ;
args . V_170 . V_224 = V_184 ;
if ( V_11 -> V_207 && V_11 -> V_146 . V_163 )
args . V_170 . V_225 |=
V_226 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_183 = F_41 ( args . V_170 . V_222 ) * 10 ;
break;
case 3 :
args . V_152 . V_227 . V_222 = F_4 ( V_4 -> clock / 10 ) ;
args . V_152 . V_227 . V_223 = V_35 -> V_211 ;
args . V_152 . V_227 . V_224 = V_184 ;
args . V_152 . V_227 . V_228 = 0 ;
if ( V_11 -> V_207 && V_11 -> V_146 . V_163 )
args . V_152 . V_227 . V_228 |=
V_229 ;
if ( F_42 ( V_184 ) ) {
args . V_152 . V_227 . V_228 |=
V_230 ;
args . V_152 . V_227 . V_222 = F_4 ( V_185 / 10 ) ;
} else if ( V_35 -> V_199 & ( V_201 ) ) {
struct V_231 * V_232 = V_35 -> V_46 ;
if ( V_184 == V_233 )
args . V_152 . V_227 . V_222 =
F_4 ( ( V_4 -> clock * V_186 / 8 ) / 10 ) ;
if ( V_232 -> V_234 )
args . V_152 . V_227 . V_228 |=
V_230 ;
if ( V_187 )
args . V_152 . V_227 . V_228 |=
V_235 ;
}
if ( F_38 ( V_36 ) !=
V_202 )
args . V_152 . V_227 . V_236 =
F_38 ( V_36 ) ;
else
args . V_152 . V_227 . V_236 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_183 = F_43 ( args . V_152 . V_237 . V_238 ) * 10 ;
if ( args . V_152 . V_237 . V_239 ) {
V_11 -> V_188 |= V_197 ;
V_11 -> V_188 |= V_209 ;
V_11 -> V_210 = args . V_152 . V_237 . V_239 ;
}
if ( args . V_152 . V_237 . V_240 ) {
V_11 -> V_188 |= V_197 ;
V_11 -> V_188 |= V_241 ;
V_11 -> V_242 = args . V_152 . V_237 . V_240 ;
}
break;
default:
F_44 ( L_1 , V_219 , V_220 ) ;
return V_183 ;
}
break;
default:
F_44 ( L_1 , V_219 , V_220 ) ;
return V_183 ;
}
}
return V_183 ;
}
static void F_45 ( struct V_8 * V_9 ,
T_9 V_243 )
{
T_10 V_219 , V_220 ;
int V_12 ;
union V_244 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_245 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_219 ,
& V_220 ) )
return;
switch ( V_219 ) {
case 1 :
switch ( V_220 ) {
case 5 :
args . V_246 . V_17 = V_247 ;
args . V_246 . V_222 = F_4 ( V_243 ) ;
args . V_246 . V_176 = V_140 ;
break;
case 6 :
args . V_248 . V_249 = F_46 ( V_243 ) ;
if ( F_30 ( V_9 ) )
args . V_248 . V_176 = V_250 ;
else if ( F_17 ( V_9 ) )
args . V_248 . V_176 = V_251 ;
else
args . V_248 . V_176 = V_140 ;
break;
default:
F_44 ( L_1 , V_219 , V_220 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_219 , V_220 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_9 V_18 ,
int V_133 ,
T_9 V_184 ,
T_9 V_211 ,
T_9 clock ,
T_9 V_252 ,
T_9 V_253 ,
T_9 V_254 ,
T_9 V_255 ,
int V_186 ,
bool V_207 ,
struct V_145 * V_146 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_10 V_219 , V_220 ;
int V_12 = F_3 ( V_13 , V_245 ) ;
union V_244 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_219 ,
& V_220 ) )
return;
switch ( V_219 ) {
case 1 :
switch ( V_220 ) {
case 1 :
if ( clock == V_84 )
return;
args . V_170 . V_222 = F_4 ( clock / 10 ) ;
args . V_170 . V_256 = F_4 ( V_252 ) ;
args . V_170 . V_257 = F_4 ( V_253 ) ;
args . V_170 . V_258 = V_254 ;
args . V_170 . V_240 = V_255 ;
args . V_170 . V_176 = V_133 ;
args . V_170 . V_17 = V_18 ;
args . V_170 . V_259 = 1 ;
break;
case 2 :
args . V_165 . V_222 = F_4 ( clock / 10 ) ;
args . V_165 . V_256 = F_4 ( V_252 ) ;
args . V_165 . V_257 = F_4 ( V_253 ) ;
args . V_165 . V_258 = V_254 ;
args . V_165 . V_240 = V_255 ;
args . V_165 . V_176 = V_133 ;
args . V_165 . V_17 = V_18 ;
args . V_165 . V_259 = 1 ;
break;
case 3 :
args . V_152 . V_222 = F_4 ( clock / 10 ) ;
args . V_152 . V_256 = F_4 ( V_252 ) ;
args . V_152 . V_257 = F_4 ( V_253 ) ;
args . V_152 . V_258 = V_254 ;
args . V_152 . V_240 = V_255 ;
args . V_152 . V_176 = V_133 ;
if ( V_18 == V_260 )
args . V_152 . V_261 = V_262 ;
else
args . V_152 . V_261 = V_263 ;
if ( V_207 && ( V_146 -> type & V_164 ) )
args . V_152 . V_261 |= V_264 ;
args . V_152 . V_265 = V_211 ;
args . V_152 . V_266 = V_184 ;
break;
case 5 :
args . V_246 . V_17 = V_18 ;
args . V_246 . V_222 = F_4 ( clock / 10 ) ;
args . V_246 . V_239 = V_252 ;
args . V_246 . V_257 = F_4 ( V_253 ) ;
args . V_246 . V_267 = F_46 ( V_254 * 100000 ) ;
args . V_246 . V_240 = V_255 ;
args . V_246 . V_261 = 0 ;
if ( V_207 && ( V_146 -> type & V_164 ) )
args . V_246 . V_261 |= V_268 ;
switch ( V_186 ) {
case 8 :
default:
args . V_246 . V_261 |= V_269 ;
break;
case 10 :
args . V_246 . V_261 |= V_270 ;
break;
}
args . V_246 . V_223 = V_211 ;
args . V_246 . V_266 = V_184 ;
args . V_246 . V_176 = V_133 ;
break;
case 6 :
args . V_248 . V_249 = F_46 ( V_18 << 24 | clock / 10 ) ;
args . V_248 . V_239 = V_252 ;
args . V_248 . V_257 = F_4 ( V_253 ) ;
args . V_248 . V_267 = F_46 ( V_254 * 100000 ) ;
args . V_248 . V_240 = V_255 ;
args . V_248 . V_261 = 0 ;
if ( V_207 && ( V_146 -> type & V_164 ) )
args . V_248 . V_261 |= V_271 ;
switch ( V_186 ) {
case 8 :
default:
args . V_248 . V_261 |= V_272 ;
break;
case 10 :
args . V_248 . V_261 |= V_273 ;
break;
case 12 :
args . V_248 . V_261 |= V_274 ;
break;
case 16 :
args . V_248 . V_261 |= V_275 ;
break;
}
args . V_248 . V_223 = V_211 ;
args . V_248 . V_266 = V_184 ;
args . V_248 . V_176 = V_133 ;
break;
default:
F_44 ( L_1 , V_219 , V_220 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_219 , V_220 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static bool F_48 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
int V_184 = F_34 ( V_11 -> V_36 ) ;
V_11 -> V_186 = 8 ;
V_11 -> V_207 = false ;
if ( ( V_35 -> V_42 & ( V_200 | V_201 ) ) ||
( F_38 ( V_11 -> V_36 ) != V_202 ) ) {
struct V_231 * V_232 = V_35 -> V_46 ;
struct V_181 * V_182 =
F_33 ( V_11 -> V_36 ) ;
struct V_203 * V_203 =
F_39 ( V_182 ) ;
struct V_204 * V_205 =
V_203 -> V_206 ;
int V_185 ;
V_11 -> V_186 = F_35 ( V_182 ) ;
switch ( V_184 ) {
case V_276 :
case V_277 :
V_185 = V_205 -> V_185 / 10 ;
if ( F_25 ( V_9 ) )
V_11 -> V_207 =
F_49 ( V_9 , & V_11 -> V_146 ,
V_278 ,
V_185 ) ;
else {
if ( V_185 == 16200 ) {
V_11 -> V_207 =
F_50 ( V_9 ,
& V_11 -> V_146 ,
V_279 ) ;
if ( ! V_11 -> V_207 )
V_11 -> V_207 =
F_50 ( V_9 ,
& V_11 -> V_146 ,
V_280 ) ;
} else
V_11 -> V_207 =
F_50 ( V_9 ,
& V_11 -> V_146 ,
V_280 ) ;
}
break;
case V_281 :
if ( F_25 ( V_9 ) )
V_11 -> V_207 =
F_49 ( V_9 ,
& V_11 -> V_146 ,
V_232 -> V_282 ,
V_4 -> clock / 10 ) ;
else
V_11 -> V_207 =
F_50 ( V_9 ,
& V_11 -> V_146 ,
V_232 -> V_282 ) ;
break;
case V_283 :
if ( F_25 ( V_9 ) )
V_11 -> V_207 =
F_49 ( V_9 ,
& V_11 -> V_146 ,
V_284 ,
V_4 -> clock / 10 ) ;
break;
case V_233 :
if ( F_25 ( V_9 ) )
V_11 -> V_207 =
F_49 ( V_9 ,
& V_11 -> V_146 ,
V_285 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_11 -> V_183 = F_32 ( V_2 , V_4 ) ;
return true ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_9 V_286 = V_4 -> clock ;
T_9 V_252 = 0 , V_253 = 0 , V_254 = 0 , V_255 = 0 ;
struct V_287 * V_288 ;
int V_184 = F_34 ( V_11 -> V_36 ) ;
switch ( V_11 -> V_133 ) {
case V_135 :
V_288 = & V_9 -> clock . V_289 ;
break;
case V_138 :
V_288 = & V_9 -> clock . V_290 ;
break;
case V_140 :
case V_141 :
default:
V_288 = & V_9 -> clock . V_291 ;
break;
}
V_288 -> V_107 = V_11 -> V_188 ;
V_288 -> V_292 = V_11 -> V_210 ;
V_288 -> V_255 = V_11 -> V_242 ;
if ( V_35 -> V_42 & ( V_43 ) )
F_52 ( V_288 , V_11 -> V_183 , & V_286 ,
& V_253 , & V_254 , & V_252 , & V_255 ) ;
else if ( F_8 ( V_9 ) )
F_53 ( V_288 , V_11 -> V_183 , & V_286 ,
& V_253 , & V_254 , & V_252 , & V_255 ) ;
else
F_52 ( V_288 , V_11 -> V_183 , & V_286 ,
& V_253 , & V_254 , & V_252 , & V_255 ) ;
F_28 ( V_9 , V_84 , V_11 -> V_133 ,
V_11 -> V_18 , & V_11 -> V_146 ) ;
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_133 ,
V_184 , V_35 -> V_211 , V_4 -> clock ,
V_252 , V_253 , V_254 , V_255 ,
V_11 -> V_186 , V_11 -> V_207 , & V_11 -> V_146 ) ;
if ( V_11 -> V_207 ) {
if ( F_25 ( V_9 ) ) {
T_9 V_293 ;
T_9 V_160 = ( ( ( V_253 * 10 ) + V_254 ) * V_11 -> V_146 . V_163 ) / 10000 ;
V_11 -> V_146 . V_160 = ( V_160 / 10 ) & V_294 ;
V_11 -> V_146 . V_160 |= ( ( V_160 - ( V_160 / 10 ) ) << V_295 ) &
V_296 ;
if ( V_11 -> V_146 . type & V_297 )
V_293 = ( 4 * V_160 * V_252 * ( V_11 -> V_146 . V_298 * 2048 ) ) /
( 125 * 25 * V_288 -> V_299 / 100 ) ;
else
V_293 = ( 2 * V_160 * V_252 * ( V_11 -> V_146 . V_298 * 2048 ) ) /
( 125 * 25 * V_288 -> V_299 / 100 ) ;
V_11 -> V_146 . V_162 = V_293 ;
}
F_28 ( V_9 , V_85 , V_11 -> V_133 ,
V_11 -> V_18 , & V_11 -> V_146 ) ;
}
}
static int F_54 ( struct V_1 * V_2 ,
struct V_300 * V_301 ,
int V_302 , int V_303 , int V_304 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_305 * V_306 ;
struct V_300 * V_307 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
T_11 V_312 ;
V_33 V_313 , V_314 , V_315 ;
unsigned V_316 , V_317 , V_318 , V_319 ;
T_9 V_320 = F_55 ( V_321 ) ;
T_9 V_322 , V_323 , V_324 ;
int V_325 ;
if ( ! V_304 && ! V_2 -> V_301 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_304 ) {
V_306 = F_57 ( V_301 ) ;
V_307 = V_301 ;
}
else {
V_306 = F_57 ( V_2 -> V_301 ) ;
V_307 = V_2 -> V_301 ;
}
V_309 = V_306 -> V_309 ;
V_311 = F_58 ( V_309 ) ;
V_325 = F_59 ( V_311 , false ) ;
if ( F_60 ( V_325 != 0 ) )
return V_325 ;
if ( V_304 )
V_312 = F_61 ( V_311 ) ;
else {
V_325 = F_62 ( V_311 , V_326 , & V_312 ) ;
if ( F_60 ( V_325 != 0 ) ) {
F_63 ( V_311 ) ;
return - V_327 ;
}
}
F_64 ( V_311 , & V_315 , NULL ) ;
F_63 ( V_311 ) ;
switch ( V_307 -> V_328 ) {
case 8 :
V_313 = ( F_65 ( V_329 ) |
F_66 ( V_330 ) ) ;
break;
case 15 :
V_313 = ( F_65 ( V_331 ) |
F_66 ( V_332 ) ) ;
break;
case 16 :
V_313 = ( F_65 ( V_331 ) |
F_66 ( V_333 ) ) ;
#ifdef F_67
V_320 = F_55 ( V_334 ) ;
#endif
break;
case 24 :
case 32 :
V_313 = ( F_65 ( V_335 ) |
F_66 ( V_336 ) ) ;
#ifdef F_67
V_320 = F_55 ( V_337 ) ;
#endif
break;
default:
F_44 ( L_3 ,
V_307 -> V_328 ) ;
return - V_327 ;
}
if ( V_315 & V_338 ) {
if ( V_9 -> V_69 >= V_339 )
V_322 = V_9 -> V_340 . V_341 . V_342 ;
else if ( V_9 -> V_69 >= V_343 )
V_322 = V_9 -> V_340 . V_344 . V_342 ;
else
V_322 = V_9 -> V_340 . V_345 . V_342 ;
switch ( ( V_322 & 0xf0 ) >> 4 ) {
case 0 :
V_313 |= F_68 ( V_346 ) ;
break;
case 1 :
default:
V_313 |= F_68 ( V_347 ) ;
break;
case 2 :
V_313 |= F_68 ( V_348 ) ;
break;
}
V_313 |= F_69 ( V_349 ) ;
F_70 ( V_315 , & V_316 , & V_317 , & V_318 , & V_319 ) ;
V_313 |= F_71 ( V_319 ) ;
V_313 |= F_72 ( V_316 ) ;
V_313 |= F_73 ( V_317 ) ;
V_313 |= F_74 ( V_318 ) ;
} else if ( V_315 & V_350 )
V_313 |= F_69 ( V_351 ) ;
if ( ( V_9 -> V_69 == V_339 ) ||
( V_9 -> V_69 == V_352 ) )
V_313 |= F_75 ( V_353 ) ;
else if ( V_9 -> V_69 == V_354 )
V_313 |= F_75 ( V_355 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_27 ( V_356 , 0 ) ;
break;
case 1 :
F_27 ( V_357 , 0 ) ;
break;
case 2 :
F_27 ( V_358 , 0 ) ;
break;
case 3 :
F_27 ( V_359 , 0 ) ;
break;
case 4 :
F_27 ( V_360 , 0 ) ;
break;
case 5 :
F_27 ( V_361 , 0 ) ;
break;
default:
break;
}
F_27 ( V_362 + V_11 -> V_363 ,
F_76 ( V_312 ) ) ;
F_27 ( V_364 + V_11 -> V_363 ,
F_76 ( V_312 ) ) ;
F_27 ( V_365 + V_11 -> V_363 ,
( T_9 ) V_312 & V_366 ) ;
F_27 ( V_367 + V_11 -> V_363 ,
( T_9 ) V_312 & V_366 ) ;
F_27 ( V_368 + V_11 -> V_363 , V_313 ) ;
F_27 ( V_369 + V_11 -> V_363 , V_320 ) ;
F_27 ( V_370 + V_11 -> V_363 , 0 ) ;
F_27 ( V_371 + V_11 -> V_363 , 0 ) ;
F_27 ( V_372 + V_11 -> V_363 , 0 ) ;
F_27 ( V_373 + V_11 -> V_363 , 0 ) ;
F_27 ( V_374 + V_11 -> V_363 , V_307 -> V_375 ) ;
F_27 ( V_376 + V_11 -> V_363 , V_307 -> V_377 ) ;
V_314 = V_307 -> V_378 [ 0 ] / ( V_307 -> V_328 / 8 ) ;
F_27 ( V_379 + V_11 -> V_363 , V_314 ) ;
F_27 ( V_380 + V_11 -> V_363 , 1 ) ;
F_27 ( V_381 + V_11 -> V_363 ,
V_307 -> V_377 ) ;
V_302 &= ~ 3 ;
V_303 &= ~ 1 ;
F_27 ( V_382 + V_11 -> V_363 ,
( V_302 << 16 ) | V_303 ) ;
V_323 = V_2 -> V_4 . V_383 ;
V_324 = ( V_2 -> V_4 . V_384 + 1 ) & ~ 1 ;
F_27 ( V_385 + V_11 -> V_363 ,
( V_323 << 16 ) | V_324 ) ;
V_322 = F_26 ( V_386 + V_11 -> V_363 ) ;
V_322 &= ~ V_387 ;
F_27 ( V_386 + V_11 -> V_363 , V_322 ) ;
F_27 ( V_388 + V_11 -> V_363 , 0 ) ;
if ( ! V_304 && V_301 && V_301 != V_2 -> V_301 ) {
V_306 = F_57 ( V_301 ) ;
V_311 = F_58 ( V_306 -> V_309 ) ;
V_325 = F_59 ( V_311 , false ) ;
if ( F_60 ( V_325 != 0 ) )
return V_325 ;
F_77 ( V_311 ) ;
F_63 ( V_311 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_300 * V_301 ,
int V_302 , int V_303 , int V_304 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_305 * V_306 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
struct V_300 * V_307 ;
T_11 V_312 ;
V_33 V_313 , V_314 , V_315 ;
T_9 V_320 = V_389 ;
T_9 V_322 , V_323 , V_324 ;
int V_325 ;
if ( ! V_304 && ! V_2 -> V_301 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_304 ) {
V_306 = F_57 ( V_301 ) ;
V_307 = V_301 ;
}
else {
V_306 = F_57 ( V_2 -> V_301 ) ;
V_307 = V_2 -> V_301 ;
}
V_309 = V_306 -> V_309 ;
V_311 = F_58 ( V_309 ) ;
V_325 = F_59 ( V_311 , false ) ;
if ( F_60 ( V_325 != 0 ) )
return V_325 ;
if ( V_304 )
V_312 = F_61 ( V_311 ) ;
else {
V_325 = F_62 ( V_311 , V_326 , & V_312 ) ;
if ( F_60 ( V_325 != 0 ) ) {
F_63 ( V_311 ) ;
return - V_327 ;
}
}
F_64 ( V_311 , & V_315 , NULL ) ;
F_63 ( V_311 ) ;
switch ( V_307 -> V_328 ) {
case 8 :
V_313 =
V_390 |
V_391 ;
break;
case 15 :
V_313 =
V_392 |
V_393 ;
break;
case 16 :
V_313 =
V_392 |
V_394 ;
#ifdef F_67
V_320 = V_395 ;
#endif
break;
case 24 :
case 32 :
V_313 =
V_396 |
V_397 ;
#ifdef F_67
V_320 = V_398 ;
#endif
break;
default:
F_44 ( L_3 ,
V_307 -> V_328 ) ;
return - V_327 ;
}
if ( V_9 -> V_69 >= V_399 ) {
if ( V_315 & V_338 )
V_313 |= V_400 ;
else if ( V_315 & V_350 )
V_313 |= V_401 ;
} else {
if ( V_315 & V_338 )
V_313 |= V_402 ;
if ( V_315 & V_350 )
V_313 |= V_403 ;
}
if ( V_11 -> V_18 == 0 )
F_27 ( V_356 , 0 ) ;
else
F_27 ( V_357 , 0 ) ;
if ( V_9 -> V_69 >= V_195 ) {
if ( V_11 -> V_18 ) {
F_27 ( V_404 , F_76 ( V_312 ) ) ;
F_27 ( V_405 , F_76 ( V_312 ) ) ;
} else {
F_27 ( V_406 , F_76 ( V_312 ) ) ;
F_27 ( V_407 , F_76 ( V_312 ) ) ;
}
}
F_27 ( V_408 + V_11 -> V_363 ,
( T_9 ) V_312 ) ;
F_27 ( V_409 +
V_11 -> V_363 , ( T_9 ) V_312 ) ;
F_27 ( V_410 + V_11 -> V_363 , V_313 ) ;
if ( V_9 -> V_69 >= V_399 )
F_27 ( V_411 + V_11 -> V_363 , V_320 ) ;
F_27 ( V_412 + V_11 -> V_363 , 0 ) ;
F_27 ( V_413 + V_11 -> V_363 , 0 ) ;
F_27 ( V_414 + V_11 -> V_363 , 0 ) ;
F_27 ( V_415 + V_11 -> V_363 , 0 ) ;
F_27 ( V_416 + V_11 -> V_363 , V_307 -> V_375 ) ;
F_27 ( V_417 + V_11 -> V_363 , V_307 -> V_377 ) ;
V_314 = V_307 -> V_378 [ 0 ] / ( V_307 -> V_328 / 8 ) ;
F_27 ( V_418 + V_11 -> V_363 , V_314 ) ;
F_27 ( V_419 + V_11 -> V_363 , 1 ) ;
F_27 ( V_420 + V_11 -> V_363 ,
V_307 -> V_377 ) ;
V_302 &= ~ 3 ;
V_303 &= ~ 1 ;
F_27 ( V_421 + V_11 -> V_363 ,
( V_302 << 16 ) | V_303 ) ;
V_323 = V_2 -> V_4 . V_383 ;
V_324 = ( V_2 -> V_4 . V_384 + 1 ) & ~ 1 ;
F_27 ( V_422 + V_11 -> V_363 ,
( V_323 << 16 ) | V_324 ) ;
V_322 = F_26 ( V_423 + V_11 -> V_363 ) ;
V_322 &= ~ V_424 ;
F_27 ( V_423 + V_11 -> V_363 , V_322 ) ;
F_27 ( V_425 + V_11 -> V_363 , 0 ) ;
if ( ! V_304 && V_301 && V_301 != V_2 -> V_301 ) {
V_306 = F_57 ( V_301 ) ;
V_311 = F_58 ( V_306 -> V_309 ) ;
V_325 = F_59 ( V_311 , false ) ;
if ( F_60 ( V_325 != 0 ) )
return V_325 ;
F_77 ( V_311 ) ;
F_63 ( V_311 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_302 , int V_303 ,
struct V_300 * V_426 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_25 ( V_9 ) )
return F_54 ( V_2 , V_426 , V_302 , V_303 , 0 ) ;
else if ( F_8 ( V_9 ) )
return F_79 ( V_2 , V_426 , V_302 , V_303 , 0 ) ;
else
return F_81 ( V_2 , V_426 , V_302 , V_303 , 0 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_300 * V_301 ,
int V_302 , int V_303 , enum V_427 V_74 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_25 ( V_9 ) )
return F_54 ( V_2 , V_301 , V_302 , V_303 , 1 ) ;
else if ( F_8 ( V_9 ) )
return F_79 ( V_2 , V_301 , V_302 , V_303 , 1 ) ;
else
return F_81 ( V_2 , V_301 , V_302 , V_303 , 1 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_9 V_428 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_428 = F_26 ( V_429 ) ;
V_428 &= ~ V_430 ;
F_27 ( V_429 , V_428 ) ;
break;
case 1 :
V_428 = F_26 ( V_431 ) ;
V_428 &= ~ V_432 ;
F_27 ( V_431 , V_428 ) ;
F_27 ( V_433 , F_26 ( V_434 ) ) ;
F_27 ( V_435 , F_26 ( V_436 ) ) ;
break;
}
}
static T_9 F_84 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_437 ;
struct V_11 * V_438 ;
T_9 V_439 = 0 ;
F_85 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_437 )
continue;
V_438 = F_2 ( V_437 ) ;
if ( V_438 -> V_133 != V_141 )
V_439 |= ( 1 << V_438 -> V_133 ) ;
}
return V_439 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_437 ;
struct V_11 * V_438 ;
F_85 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_437 )
continue;
V_438 = F_2 ( V_437 ) ;
if ( V_438 -> V_36 &&
F_42 ( F_34 ( V_438 -> V_36 ) ) ) {
if ( V_438 -> V_133 != V_141 )
return V_438 -> V_133 ;
}
}
return V_141 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_437 ;
struct V_11 * V_438 ;
T_9 V_183 , V_440 ;
V_183 = V_11 -> V_183 ;
if ( V_183 == 0 )
return V_141 ;
F_85 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_437 )
continue;
V_438 = F_2 ( V_437 ) ;
if ( V_438 -> V_36 &&
! F_42 ( F_34 ( V_438 -> V_36 ) ) ) {
if ( V_438 -> V_182 == V_11 -> V_182 ) {
if ( V_438 -> V_133 != V_141 )
return V_438 -> V_133 ;
}
V_440 = V_438 -> V_183 ;
if ( ( V_2 -> V_4 . clock == V_437 -> V_4 . clock ) &&
( V_183 == V_440 ) &&
( V_11 -> V_207 == V_438 -> V_207 ) &&
( V_438 -> V_133 != V_141 ) )
return V_438 -> V_133 ;
}
}
return V_141 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_9 V_439 ;
int V_288 ;
if ( F_30 ( V_9 ) ) {
struct V_231 * V_232 =
V_35 -> V_46 ;
if ( ( V_35 -> V_211 == V_441 ) &&
( V_232 -> V_442 == false ) )
return V_138 ;
else if ( F_42 ( F_34 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_443 )
return V_141 ;
else {
V_288 = F_86 ( V_2 ) ;
if ( V_288 != V_141 )
return V_288 ;
}
} else {
V_288 = F_87 ( V_2 ) ;
if ( V_288 != V_141 )
return V_288 ;
}
V_439 = F_84 ( V_2 ) ;
if ( ! ( V_439 & ( 1 << V_251 ) ) )
return V_251 ;
if ( ! ( V_439 & ( 1 << V_135 ) ) )
return V_135 ;
F_44 ( L_4 ) ;
return V_141 ;
} else if ( F_25 ( V_9 ) ) {
if ( F_42 ( F_34 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_443 )
return V_141 ;
else if ( F_17 ( V_9 ) )
return V_251 ;
else if ( F_29 ( V_9 ) )
return V_140 ;
else {
V_288 = F_86 ( V_2 ) ;
if ( V_288 != V_141 )
return V_288 ;
}
} else {
V_288 = F_87 ( V_2 ) ;
if ( V_288 != V_141 )
return V_288 ;
}
V_439 = F_84 ( V_2 ) ;
if ( ! ( V_439 & ( 1 << V_135 ) ) )
return V_135 ;
if ( ! ( V_439 & ( 1 << V_138 ) ) )
return V_138 ;
F_44 ( L_4 ) ;
return V_141 ;
} else {
return V_11 -> V_18 ;
}
}
void F_89 ( struct V_8 * V_9 )
{
if ( F_17 ( V_9 ) )
F_45 ( V_9 , V_9 -> clock . V_444 ) ;
else if ( F_25 ( V_9 ) ) {
struct V_145 V_146 ;
bool V_207 = F_49 ( V_9 , & V_146 ,
V_445 ,
V_9 -> clock . V_444 ) ;
if ( V_207 )
F_28 ( V_9 , V_84 , V_140 , - 1 , & V_146 ) ;
F_45 ( V_9 , V_9 -> clock . V_444 ) ;
if ( V_207 )
F_28 ( V_9 , V_85 , V_140 , - 1 , & V_146 ) ;
}
}
int F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_302 , int V_303 , struct V_300 * V_426 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
bool V_446 = false ;
if ( V_35 -> V_42 &
( V_43 | V_447 ) )
V_446 = true ;
F_51 ( V_2 , V_5 ) ;
if ( F_25 ( V_9 ) )
F_22 ( V_2 , V_5 ) ;
else if ( F_8 ( V_9 ) ) {
if ( V_446 )
F_23 ( V_2 , V_5 ) ;
else
F_22 ( V_2 , V_5 ) ;
} else {
F_23 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_22 ( V_2 , V_5 ) ;
F_83 ( V_2 ) ;
}
F_80 ( V_2 , V_302 , V_303 , V_426 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool F_91 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_180 * V_36 ;
F_85 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_36 -> V_2 == V_2 ) {
V_11 -> V_36 = V_36 ;
V_11 -> V_182 = F_33 ( V_36 ) ;
break;
}
}
if ( ( V_11 -> V_36 == NULL ) || ( V_11 -> V_182 == NULL ) ) {
V_11 -> V_36 = NULL ;
V_11 -> V_182 = NULL ;
return false ;
}
if ( ! F_92 ( V_2 , V_4 , V_5 ) )
return false ;
if ( ! F_48 ( V_2 , V_5 ) )
return false ;
V_11 -> V_133 = F_88 ( V_2 ) ;
if ( ( V_11 -> V_133 == V_141 ) &&
! F_42 ( F_34 ( V_11 -> V_36 ) ) )
return false ;
return true ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
V_11 -> V_83 = true ;
if ( F_17 ( V_9 ) )
F_14 ( V_2 , V_84 ) ;
F_10 ( V_2 , V_85 ) ;
F_15 ( V_2 , V_88 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
F_15 ( V_2 , V_81 ) ;
F_10 ( V_2 , V_84 ) ;
V_11 -> V_83 = false ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_145 V_146 ;
int V_147 ;
F_15 ( V_2 , V_88 ) ;
for ( V_147 = 0 ; V_147 < V_9 -> V_150 ; V_147 ++ ) {
if ( V_9 -> V_31 . V_151 [ V_147 ] &&
V_9 -> V_31 . V_151 [ V_147 ] -> V_82 &&
V_147 != V_11 -> V_18 &&
V_11 -> V_133 == V_9 -> V_31 . V_151 [ V_147 ] -> V_133 ) {
goto V_448;
}
}
switch ( V_11 -> V_133 ) {
case V_135 :
case V_138 :
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_133 ,
0 , 0 , V_84 , 0 , 0 , 0 , 0 , 0 , false , & V_146 ) ;
break;
case V_251 :
if ( F_30 ( V_9 ) )
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_133 ,
0 , 0 , V_84 , 0 , 0 , 0 , 0 , 0 , false , & V_146 ) ;
break;
default:
break;
}
V_448:
V_11 -> V_133 = V_141 ;
V_11 -> V_183 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_182 = NULL ;
}
void F_96 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_25 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_363 = V_449 ;
break;
case 1 :
V_11 -> V_363 = V_450 ;
break;
case 2 :
V_11 -> V_363 = V_451 ;
break;
case 3 :
V_11 -> V_363 = V_452 ;
break;
case 4 :
V_11 -> V_363 = V_453 ;
break;
case 5 :
V_11 -> V_363 = V_454 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_363 =
V_455 - V_456 ;
else
V_11 -> V_363 = 0 ;
}
V_11 -> V_133 = V_141 ;
V_11 -> V_183 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_182 = NULL ;
F_97 ( & V_11 -> V_457 , & V_458 ) ;
}
