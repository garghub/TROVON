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
F_11 ( V_2 , V_83 ) ;
if ( F_17 ( V_9 ) && ! F_18 ( V_9 ) )
F_12 ( V_2 , V_83 ) ;
F_13 ( V_2 , V_84 ) ;
F_19 ( V_7 , V_11 -> V_18 ) ;
F_20 ( V_2 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
F_21 ( V_7 , V_11 -> V_18 ) ;
if ( V_11 -> V_82 )
F_13 ( V_2 , V_83 ) ;
if ( F_17 ( V_9 ) && ! F_18 ( V_9 ) )
F_12 ( V_2 , V_84 ) ;
F_11 ( V_2 , V_84 ) ;
V_11 -> V_82 = false ;
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
int V_12 = F_3 ( V_13 , V_88 ) ;
T_7 V_89 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_90 = F_4 ( V_4 -> V_25 - ( V_11 -> V_29 * 2 ) ) ;
args . V_91 =
F_4 ( V_4 -> V_92 - V_4 -> V_25 + ( V_11 -> V_29 * 2 ) ) ;
args . V_93 = F_4 ( V_4 -> V_22 - ( V_11 -> V_30 * 2 ) ) ;
args . V_94 =
F_4 ( V_4 -> V_95 - V_4 -> V_22 + ( V_11 -> V_30 * 2 ) ) ;
args . V_96 =
F_4 ( V_4 -> V_97 - V_4 -> V_25 + V_11 -> V_29 ) ;
args . V_98 =
F_4 ( V_4 -> V_99 - V_4 -> V_97 ) ;
args . V_100 =
F_4 ( V_4 -> V_101 - V_4 -> V_22 + V_11 -> V_30 ) ;
args . V_102 =
F_4 ( V_4 -> V_103 - V_4 -> V_101 ) ;
args . V_104 = V_11 -> V_29 ;
args . V_105 = V_11 -> V_30 ;
if ( V_4 -> V_106 & V_107 )
V_89 |= V_108 ;
if ( V_4 -> V_106 & V_109 )
V_89 |= V_110 ;
if ( V_4 -> V_106 & V_111 )
V_89 |= V_112 ;
if ( V_4 -> V_106 & V_113 )
V_89 |= V_114 ;
if ( V_4 -> V_106 & V_115 )
V_89 |= V_116 ;
args . V_117 . V_118 = F_4 ( V_89 ) ;
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
int V_12 = F_3 ( V_13 , V_119 ) ;
T_7 V_89 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_120 = F_4 ( V_4 -> V_121 ) ;
args . V_122 = F_4 ( V_4 -> V_25 ) ;
args . V_123 = F_4 ( V_4 -> V_97 ) ;
args . V_98 =
F_4 ( V_4 -> V_99 - V_4 -> V_97 ) ;
args . V_124 = F_4 ( V_4 -> V_125 ) ;
args . V_126 = F_4 ( V_4 -> V_22 ) ;
args . V_127 = F_4 ( V_4 -> V_101 ) ;
args . V_102 =
F_4 ( V_4 -> V_103 - V_4 -> V_101 ) ;
args . V_128 = V_11 -> V_29 ;
args . V_129 = V_11 -> V_29 ;
args . V_130 = V_11 -> V_30 ;
args . V_131 = V_11 -> V_30 ;
if ( V_4 -> V_106 & V_107 )
V_89 |= V_108 ;
if ( V_4 -> V_106 & V_109 )
V_89 |= V_110 ;
if ( V_4 -> V_106 & V_111 )
V_89 |= V_112 ;
if ( V_4 -> V_106 & V_113 )
V_89 |= V_114 ;
if ( V_4 -> V_106 & V_115 )
V_89 |= V_116 ;
args . V_117 . V_118 = F_4 ( V_89 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_24 ( struct V_8 * V_9 , int V_132 )
{
T_9 V_133 ;
if ( F_25 ( V_9 ) ) {
switch ( V_132 ) {
case V_134 :
V_133 = F_26 ( V_135 ) ;
V_133 &= ~ V_136 ;
F_27 ( V_135 , V_133 ) ;
break;
case V_137 :
V_133 = F_26 ( V_138 ) ;
V_133 &= ~ V_136 ;
F_27 ( V_138 , V_133 ) ;
break;
case V_139 :
case V_140 :
return;
}
} else if ( F_8 ( V_9 ) ) {
switch ( V_132 ) {
case V_134 :
V_133 = F_26 ( V_141 ) ;
V_133 &= ~ 1 ;
F_27 ( V_141 , V_133 ) ;
break;
case V_137 :
V_133 = F_26 ( V_142 ) ;
V_133 &= ~ 1 ;
F_27 ( V_142 , V_133 ) ;
break;
case V_139 :
case V_140 :
return;
}
}
}
static void F_28 ( struct V_8 * V_9 ,
int V_143 ,
int V_132 ,
int V_18 ,
struct V_144 * V_145 )
{
unsigned V_146 ;
int V_12 = F_3 ( V_13 , V_147 ) ;
union V_148 args ;
if ( ! V_143 ) {
for ( V_146 = 0 ; V_146 < V_9 -> V_149 ; V_146 ++ ) {
if ( V_9 -> V_31 . V_150 [ V_146 ] &&
V_9 -> V_31 . V_150 [ V_146 ] -> V_82 &&
V_146 != V_18 &&
V_132 == V_9 -> V_31 . V_150 [ V_146 ] -> V_132 ) {
return;
}
}
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_29 ( V_9 ) ) {
args . V_151 . V_152 = F_4 ( 0 ) ;
args . V_151 . V_153 = V_145 -> type & V_154 ;
switch ( V_132 ) {
case V_134 :
args . V_151 . V_153 |= V_155 ;
break;
case V_137 :
args . V_151 . V_153 |= V_156 ;
break;
case V_139 :
args . V_151 . V_153 |= V_157 ;
break;
case V_140 :
return;
}
args . V_151 . V_158 = F_4 ( V_145 -> V_159 ) ;
args . V_151 . V_160 = F_4 ( V_145 -> V_161 ) ;
args . V_151 . V_63 = V_143 ;
if ( ( V_145 -> V_162 == 0 ) || ( V_145 -> type & V_163 ) || F_30 ( V_9 ) )
args . V_151 . V_63 = V_84 ;
} else if ( F_25 ( V_9 ) ) {
args . V_164 . V_165 = F_4 ( V_145 -> V_162 ) ;
args . V_164 . V_153 = V_145 -> type & V_154 ;
switch ( V_132 ) {
case V_134 :
args . V_164 . V_153 |= V_166 ;
break;
case V_137 :
args . V_164 . V_153 |= V_167 ;
break;
case V_139 :
args . V_164 . V_153 |= V_168 ;
break;
case V_140 :
return;
}
args . V_164 . V_158 = F_4 ( V_145 -> V_159 ) ;
args . V_164 . V_160 = F_4 ( V_145 -> V_161 ) ;
args . V_164 . V_63 = V_143 ;
if ( ( V_145 -> V_162 == 0 ) || ( V_145 -> type & V_163 ) || F_31 ( V_9 ) )
args . V_164 . V_63 = V_84 ;
} else if ( F_17 ( V_9 ) ) {
args . V_169 . V_165 = F_4 ( V_145 -> V_162 ) ;
args . V_169 . V_153 = V_145 -> type & V_154 ;
args . V_169 . V_170 = V_145 -> V_161 ;
args . V_169 . V_171 = V_145 -> V_172 ;
args . V_169 . V_173 = V_145 -> V_174 ;
args . V_169 . V_175 = V_132 ;
args . V_169 . V_63 = V_143 ;
} else if ( F_8 ( V_9 ) ) {
if ( ( V_143 == V_84 ) || ( V_145 -> V_162 == 0 ) ||
( V_145 -> type & V_163 ) ) {
F_24 ( V_9 , V_132 ) ;
return;
}
args . V_176 . V_165 = F_4 ( V_145 -> V_162 ) ;
args . V_176 . V_153 = V_145 -> type & V_154 ;
args . V_176 . V_170 = V_145 -> V_161 ;
args . V_176 . V_171 = V_145 -> V_172 ;
args . V_176 . V_173 = V_145 -> V_174 ;
args . V_176 . V_63 = V_143 ;
} else {
if ( ( V_143 == V_84 ) || ( V_145 -> V_162 == 0 ) ||
( V_145 -> type & V_163 ) ) {
F_24 ( V_9 , V_132 ) ;
return;
}
args . V_177 . V_165 = F_4 ( V_145 -> V_162 ) ;
args . V_177 . V_153 = V_145 -> type & V_154 ;
args . V_177 . V_178 = ( V_145 -> V_161 & 3 ) << 2 ;
args . V_177 . V_178 |= ( V_145 -> V_172 & 7 ) << 4 ;
args . V_177 . V_63 = V_143 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_9 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_179 * V_36 = V_11 -> V_36 ;
struct V_35 * V_35 = F_7 ( V_36 ) ;
struct V_180 * V_181 = F_33 ( V_36 ) ;
T_9 V_182 = V_4 -> clock ;
int V_183 = F_34 ( V_36 ) ;
T_9 V_184 = V_4 -> clock ;
int V_185 = F_35 ( V_181 ) ;
bool V_186 = F_36 ( V_36 , V_4 -> clock ) ;
V_11 -> V_187 = 0 ;
if ( F_8 ( V_9 ) ) {
if ( ( V_9 -> V_69 == V_188 ) ||
( V_9 -> V_69 == V_189 ) ||
( V_9 -> V_69 == V_190 ) )
V_11 -> V_187 |= (
V_191 ) ;
if ( F_37 ( V_9 ) && V_4 -> clock > 200000 )
V_11 -> V_187 |= V_192 ;
else
V_11 -> V_187 |= V_193 ;
if ( V_9 -> V_69 < V_194 )
V_11 -> V_187 |= V_195 ;
if ( F_31 ( V_9 ) || F_30 ( V_9 ) )
V_11 -> V_187 |= V_196 ;
if ( ( V_9 -> V_69 == V_197 ) || ( V_9 -> V_69 == V_198 ) )
V_11 -> V_187 |= V_196 ;
if ( F_37 ( V_9 ) && V_4 -> clock > 165000 )
V_11 -> V_187 |= V_196 ;
} else {
V_11 -> V_187 |= V_199 ;
if ( V_4 -> clock > 200000 )
V_11 -> V_187 |= V_192 ;
else
V_11 -> V_187 |= V_193 ;
}
if ( ( V_35 -> V_200 & ( V_201 | V_202 ) ) ||
( F_38 ( V_36 ) != V_203 ) ) {
if ( V_181 ) {
struct V_204 * V_204 = F_39 ( V_181 ) ;
struct V_205 * V_206 =
V_204 -> V_207 ;
V_184 = V_206 -> V_184 ;
}
}
if ( V_35 -> V_200 & ( V_201 ) ) {
if ( V_11 -> V_208 ) {
if ( V_11 -> V_145 . V_209 ) {
V_11 -> V_187 |= V_210 ;
V_11 -> V_211 = V_11 -> V_145 . V_209 ;
if ( F_8 ( V_9 ) )
V_11 -> V_187 |= V_196 ;
}
}
}
if ( F_8 ( V_9 ) ) {
if ( V_35 -> V_212 == V_213 )
V_182 = V_4 -> clock * 2 ;
if ( V_35 -> V_42 & ( V_43 ) )
V_11 -> V_187 |= V_191 ;
if ( V_35 -> V_200 & ( V_201 ) )
V_11 -> V_187 |= V_214 ;
} else {
if ( V_36 -> V_215 != V_216 )
V_11 -> V_187 |= V_217 ;
if ( V_36 -> V_215 == V_218 )
V_11 -> V_187 |= V_210 ;
}
if ( F_17 ( V_9 ) ) {
union V_219 args ;
T_10 V_220 , V_221 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_222 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_220 ,
& V_221 ) )
return V_182 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_220 ) {
case 1 :
switch ( V_221 ) {
case 1 :
case 2 :
args . V_169 . V_223 = F_4 ( V_4 -> clock / 10 ) ;
args . V_169 . V_224 = V_35 -> V_212 ;
args . V_169 . V_225 = V_183 ;
if ( V_11 -> V_208 && V_11 -> V_145 . V_162 )
args . V_169 . V_226 |=
V_227 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_182 = F_41 ( args . V_169 . V_223 ) * 10 ;
break;
case 3 :
args . V_151 . V_228 . V_223 = F_4 ( V_4 -> clock / 10 ) ;
args . V_151 . V_228 . V_224 = V_35 -> V_212 ;
args . V_151 . V_228 . V_225 = V_183 ;
args . V_151 . V_228 . V_229 = 0 ;
if ( V_11 -> V_208 && V_11 -> V_145 . V_162 )
args . V_151 . V_228 . V_229 |=
V_230 ;
if ( F_42 ( V_183 ) ) {
args . V_151 . V_228 . V_229 |=
V_231 ;
args . V_151 . V_228 . V_223 = F_4 ( V_184 / 10 ) ;
} else if ( V_35 -> V_200 & ( V_202 ) ) {
struct V_232 * V_233 = V_35 -> V_46 ;
if ( V_183 == V_234 )
args . V_151 . V_228 . V_223 =
F_4 ( ( V_4 -> clock * V_185 / 8 ) / 10 ) ;
if ( V_233 -> V_235 )
args . V_151 . V_228 . V_229 |=
V_231 ;
if ( V_186 )
args . V_151 . V_228 . V_229 |=
V_236 ;
}
if ( F_38 ( V_36 ) !=
V_203 )
args . V_151 . V_228 . V_237 =
F_38 ( V_36 ) ;
else
args . V_151 . V_228 . V_237 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_182 = F_43 ( args . V_151 . V_238 . V_239 ) * 10 ;
if ( args . V_151 . V_238 . V_240 ) {
V_11 -> V_187 |= V_196 ;
V_11 -> V_187 |= V_210 ;
V_11 -> V_211 = args . V_151 . V_238 . V_240 ;
}
if ( args . V_151 . V_238 . V_241 ) {
V_11 -> V_187 |= V_196 ;
V_11 -> V_187 |= V_242 ;
V_11 -> V_243 = args . V_151 . V_238 . V_241 ;
}
break;
default:
F_44 ( L_1 , V_220 , V_221 ) ;
return V_182 ;
}
break;
default:
F_44 ( L_1 , V_220 , V_221 ) ;
return V_182 ;
}
}
return V_182 ;
}
static void F_45 ( struct V_8 * V_9 ,
T_9 V_244 )
{
T_10 V_220 , V_221 ;
int V_12 ;
union V_245 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_246 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_220 ,
& V_221 ) )
return;
switch ( V_220 ) {
case 1 :
switch ( V_221 ) {
case 5 :
args . V_247 . V_17 = V_248 ;
args . V_247 . V_223 = F_4 ( V_244 ) ;
args . V_247 . V_175 = V_139 ;
break;
case 6 :
args . V_249 . V_250 = F_46 ( V_244 ) ;
if ( F_30 ( V_9 ) )
args . V_249 . V_175 = V_251 ;
else if ( F_18 ( V_9 ) )
args . V_249 . V_175 = V_252 ;
else
args . V_249 . V_175 = V_139 ;
break;
default:
F_44 ( L_1 , V_220 , V_221 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_220 , V_221 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_9 V_18 ,
int V_132 ,
T_9 V_183 ,
T_9 V_212 ,
T_9 clock ,
T_9 V_253 ,
T_9 V_254 ,
T_9 V_255 ,
T_9 V_256 ,
int V_185 ,
bool V_208 ,
struct V_144 * V_145 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_10 V_220 , V_221 ;
int V_12 = F_3 ( V_13 , V_246 ) ;
union V_245 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_220 ,
& V_221 ) )
return;
switch ( V_220 ) {
case 1 :
switch ( V_221 ) {
case 1 :
if ( clock == V_84 )
return;
args . V_169 . V_223 = F_4 ( clock / 10 ) ;
args . V_169 . V_257 = F_4 ( V_253 ) ;
args . V_169 . V_258 = F_4 ( V_254 ) ;
args . V_169 . V_259 = V_255 ;
args . V_169 . V_241 = V_256 ;
args . V_169 . V_175 = V_132 ;
args . V_169 . V_17 = V_18 ;
args . V_169 . V_260 = 1 ;
break;
case 2 :
args . V_164 . V_223 = F_4 ( clock / 10 ) ;
args . V_164 . V_257 = F_4 ( V_253 ) ;
args . V_164 . V_258 = F_4 ( V_254 ) ;
args . V_164 . V_259 = V_255 ;
args . V_164 . V_241 = V_256 ;
args . V_164 . V_175 = V_132 ;
args . V_164 . V_17 = V_18 ;
args . V_164 . V_260 = 1 ;
break;
case 3 :
args . V_151 . V_223 = F_4 ( clock / 10 ) ;
args . V_151 . V_257 = F_4 ( V_253 ) ;
args . V_151 . V_258 = F_4 ( V_254 ) ;
args . V_151 . V_259 = V_255 ;
args . V_151 . V_241 = V_256 ;
args . V_151 . V_175 = V_132 ;
if ( V_18 == V_261 )
args . V_151 . V_262 = V_263 ;
else
args . V_151 . V_262 = V_264 ;
if ( V_208 && ( V_145 -> type & V_163 ) )
args . V_151 . V_262 |= V_265 ;
args . V_151 . V_266 = V_212 ;
args . V_151 . V_267 = V_183 ;
break;
case 5 :
args . V_247 . V_17 = V_18 ;
args . V_247 . V_223 = F_4 ( clock / 10 ) ;
args . V_247 . V_240 = V_253 ;
args . V_247 . V_258 = F_4 ( V_254 ) ;
args . V_247 . V_268 = F_46 ( V_255 * 100000 ) ;
args . V_247 . V_241 = V_256 ;
args . V_247 . V_262 = 0 ;
if ( V_208 && ( V_145 -> type & V_163 ) )
args . V_247 . V_262 |= V_269 ;
switch ( V_185 ) {
case 8 :
default:
args . V_247 . V_262 |= V_270 ;
break;
case 10 :
args . V_247 . V_262 |= V_271 ;
break;
}
args . V_247 . V_224 = V_212 ;
args . V_247 . V_267 = V_183 ;
args . V_247 . V_175 = V_132 ;
break;
case 6 :
args . V_249 . V_250 = F_46 ( V_18 << 24 | clock / 10 ) ;
args . V_249 . V_240 = V_253 ;
args . V_249 . V_258 = F_4 ( V_254 ) ;
args . V_249 . V_268 = F_46 ( V_255 * 100000 ) ;
args . V_249 . V_241 = V_256 ;
args . V_249 . V_262 = 0 ;
if ( V_208 && ( V_145 -> type & V_163 ) )
args . V_249 . V_262 |= V_272 ;
switch ( V_185 ) {
case 8 :
default:
args . V_249 . V_262 |= V_273 ;
break;
case 10 :
args . V_249 . V_262 |= V_274 ;
break;
case 12 :
args . V_249 . V_262 |= V_275 ;
break;
case 16 :
args . V_249 . V_262 |= V_276 ;
break;
}
args . V_249 . V_224 = V_212 ;
args . V_249 . V_267 = V_183 ;
args . V_249 . V_175 = V_132 ;
break;
default:
F_44 ( L_1 , V_220 , V_221 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_220 , V_221 ) ;
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
int V_183 = F_34 ( V_11 -> V_36 ) ;
V_11 -> V_185 = 8 ;
V_11 -> V_208 = false ;
if ( ( V_35 -> V_42 & ( V_201 | V_202 ) ) ||
( F_38 ( V_11 -> V_36 ) != V_203 ) ) {
struct V_232 * V_233 = V_35 -> V_46 ;
struct V_180 * V_181 =
F_33 ( V_11 -> V_36 ) ;
struct V_204 * V_204 =
F_39 ( V_181 ) ;
struct V_205 * V_206 =
V_204 -> V_207 ;
int V_184 ;
V_11 -> V_185 = F_35 ( V_181 ) ;
switch ( V_183 ) {
case V_277 :
case V_278 :
V_184 = V_206 -> V_184 / 10 ;
if ( F_25 ( V_9 ) )
V_11 -> V_208 =
F_49 ( V_9 , & V_11 -> V_145 ,
V_279 ,
V_184 ) ;
else {
if ( V_184 == 16200 ) {
V_11 -> V_208 =
F_50 ( V_9 ,
& V_11 -> V_145 ,
V_280 ) ;
if ( ! V_11 -> V_208 )
V_11 -> V_208 =
F_50 ( V_9 ,
& V_11 -> V_145 ,
V_281 ) ;
} else
V_11 -> V_208 =
F_50 ( V_9 ,
& V_11 -> V_145 ,
V_281 ) ;
}
break;
case V_282 :
if ( F_25 ( V_9 ) )
V_11 -> V_208 =
F_49 ( V_9 ,
& V_11 -> V_145 ,
V_233 -> V_283 ,
V_4 -> clock / 10 ) ;
else
V_11 -> V_208 =
F_50 ( V_9 ,
& V_11 -> V_145 ,
V_233 -> V_283 ) ;
break;
case V_284 :
if ( F_25 ( V_9 ) )
V_11 -> V_208 =
F_49 ( V_9 ,
& V_11 -> V_145 ,
V_285 ,
V_4 -> clock / 10 ) ;
break;
case V_234 :
if ( F_25 ( V_9 ) )
V_11 -> V_208 =
F_49 ( V_9 ,
& V_11 -> V_145 ,
V_286 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_11 -> V_182 = F_32 ( V_2 , V_4 ) ;
return true ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_9 V_287 = V_4 -> clock ;
T_9 V_253 = 0 , V_254 = 0 , V_255 = 0 , V_256 = 0 ;
struct V_288 * V_289 ;
int V_183 = F_34 ( V_11 -> V_36 ) ;
switch ( V_11 -> V_132 ) {
case V_134 :
V_289 = & V_9 -> clock . V_290 ;
break;
case V_137 :
V_289 = & V_9 -> clock . V_291 ;
break;
case V_139 :
case V_140 :
default:
V_289 = & V_9 -> clock . V_292 ;
break;
}
V_289 -> V_106 = V_11 -> V_187 ;
V_289 -> V_293 = V_11 -> V_211 ;
V_289 -> V_256 = V_11 -> V_243 ;
if ( V_35 -> V_42 & ( V_43 ) )
F_52 ( V_289 , V_11 -> V_182 , & V_287 ,
& V_254 , & V_255 , & V_253 , & V_256 ) ;
else if ( F_8 ( V_9 ) )
F_53 ( V_289 , V_11 -> V_182 , & V_287 ,
& V_254 , & V_255 , & V_253 , & V_256 ) ;
else
F_52 ( V_289 , V_11 -> V_182 , & V_287 ,
& V_254 , & V_255 , & V_253 , & V_256 ) ;
F_28 ( V_9 , V_84 , V_11 -> V_132 ,
V_11 -> V_18 , & V_11 -> V_145 ) ;
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_132 ,
V_183 , V_35 -> V_212 , V_4 -> clock ,
V_253 , V_254 , V_255 , V_256 ,
V_11 -> V_185 , V_11 -> V_208 , & V_11 -> V_145 ) ;
if ( V_11 -> V_208 ) {
if ( F_25 ( V_9 ) ) {
T_9 V_294 ;
T_9 V_159 = ( ( ( V_254 * 10 ) + V_255 ) * V_11 -> V_145 . V_162 ) / 10000 ;
V_11 -> V_145 . V_159 = ( V_159 / 10 ) & V_295 ;
V_11 -> V_145 . V_159 |= ( ( V_159 - ( V_159 / 10 ) ) << V_296 ) &
V_297 ;
if ( V_11 -> V_145 . type & V_298 )
V_294 = ( 4 * V_159 * V_253 * ( V_11 -> V_145 . V_299 * 2048 ) ) /
( 125 * 25 * V_289 -> V_300 / 100 ) ;
else
V_294 = ( 2 * V_159 * V_253 * ( V_11 -> V_145 . V_299 * 2048 ) ) /
( 125 * 25 * V_289 -> V_300 / 100 ) ;
V_11 -> V_145 . V_161 = V_294 ;
}
F_28 ( V_9 , V_83 , V_11 -> V_132 ,
V_11 -> V_18 , & V_11 -> V_145 ) ;
}
}
static int F_54 ( struct V_1 * V_2 ,
struct V_301 * V_302 ,
int V_303 , int V_304 , int V_305 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_306 * V_307 ;
struct V_301 * V_308 ;
struct V_309 * V_310 ;
struct V_311 * V_312 ;
T_11 V_313 ;
V_33 V_314 , V_315 , V_316 ;
unsigned V_317 , V_318 , V_319 , V_320 ;
T_9 V_321 = F_55 ( V_322 ) ;
T_9 V_323 , V_324 , V_325 ;
int V_326 ;
if ( ! V_305 && ! V_2 -> V_302 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_305 ) {
V_307 = F_57 ( V_302 ) ;
V_308 = V_302 ;
}
else {
V_307 = F_57 ( V_2 -> V_302 ) ;
V_308 = V_2 -> V_302 ;
}
V_310 = V_307 -> V_310 ;
V_312 = F_58 ( V_310 ) ;
V_326 = F_59 ( V_312 , false ) ;
if ( F_60 ( V_326 != 0 ) )
return V_326 ;
if ( V_305 )
V_313 = F_61 ( V_312 ) ;
else {
V_326 = F_62 ( V_312 , V_327 , & V_313 ) ;
if ( F_60 ( V_326 != 0 ) ) {
F_63 ( V_312 ) ;
return - V_328 ;
}
}
F_64 ( V_312 , & V_316 , NULL ) ;
F_63 ( V_312 ) ;
switch ( V_308 -> V_329 ) {
case 8 :
V_314 = ( F_65 ( V_330 ) |
F_66 ( V_331 ) ) ;
break;
case 15 :
V_314 = ( F_65 ( V_332 ) |
F_66 ( V_333 ) ) ;
break;
case 16 :
V_314 = ( F_65 ( V_332 ) |
F_66 ( V_334 ) ) ;
#ifdef F_67
V_321 = F_55 ( V_335 ) ;
#endif
break;
case 24 :
case 32 :
V_314 = ( F_65 ( V_336 ) |
F_66 ( V_337 ) ) ;
#ifdef F_67
V_321 = F_55 ( V_338 ) ;
#endif
break;
default:
F_44 ( L_3 ,
V_308 -> V_329 ) ;
return - V_328 ;
}
if ( V_316 & V_339 ) {
if ( V_9 -> V_69 >= V_340 )
V_323 = V_9 -> V_341 . V_342 . V_343 ;
else if ( V_9 -> V_69 >= V_344 )
V_323 = V_9 -> V_341 . V_345 . V_343 ;
else
V_323 = V_9 -> V_341 . V_346 . V_343 ;
switch ( ( V_323 & 0xf0 ) >> 4 ) {
case 0 :
V_314 |= F_68 ( V_347 ) ;
break;
case 1 :
default:
V_314 |= F_68 ( V_348 ) ;
break;
case 2 :
V_314 |= F_68 ( V_349 ) ;
break;
}
V_314 |= F_69 ( V_350 ) ;
F_70 ( V_316 , & V_317 , & V_318 , & V_319 , & V_320 ) ;
V_314 |= F_71 ( V_320 ) ;
V_314 |= F_72 ( V_317 ) ;
V_314 |= F_73 ( V_318 ) ;
V_314 |= F_74 ( V_319 ) ;
} else if ( V_316 & V_351 )
V_314 |= F_69 ( V_352 ) ;
if ( ( V_9 -> V_69 == V_340 ) ||
( V_9 -> V_69 == V_353 ) )
V_314 |= F_75 ( V_354 ) ;
else if ( V_9 -> V_69 == V_355 )
V_314 |= F_75 ( V_356 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_27 ( V_357 , 0 ) ;
break;
case 1 :
F_27 ( V_358 , 0 ) ;
break;
case 2 :
F_27 ( V_359 , 0 ) ;
break;
case 3 :
F_27 ( V_360 , 0 ) ;
break;
case 4 :
F_27 ( V_361 , 0 ) ;
break;
case 5 :
F_27 ( V_362 , 0 ) ;
break;
default:
break;
}
F_27 ( V_363 + V_11 -> V_364 ,
F_76 ( V_313 ) ) ;
F_27 ( V_365 + V_11 -> V_364 ,
F_76 ( V_313 ) ) ;
F_27 ( V_366 + V_11 -> V_364 ,
( T_9 ) V_313 & V_367 ) ;
F_27 ( V_368 + V_11 -> V_364 ,
( T_9 ) V_313 & V_367 ) ;
F_27 ( V_369 + V_11 -> V_364 , V_314 ) ;
F_27 ( V_370 + V_11 -> V_364 , V_321 ) ;
F_27 ( V_371 + V_11 -> V_364 , 0 ) ;
F_27 ( V_372 + V_11 -> V_364 , 0 ) ;
F_27 ( V_373 + V_11 -> V_364 , 0 ) ;
F_27 ( V_374 + V_11 -> V_364 , 0 ) ;
F_27 ( V_375 + V_11 -> V_364 , V_308 -> V_376 ) ;
F_27 ( V_377 + V_11 -> V_364 , V_308 -> V_378 ) ;
V_315 = V_308 -> V_379 [ 0 ] / ( V_308 -> V_329 / 8 ) ;
F_27 ( V_380 + V_11 -> V_364 , V_315 ) ;
F_27 ( V_381 + V_11 -> V_364 , 1 ) ;
F_27 ( V_382 + V_11 -> V_364 ,
V_308 -> V_378 ) ;
V_303 &= ~ 3 ;
V_304 &= ~ 1 ;
F_27 ( V_383 + V_11 -> V_364 ,
( V_303 << 16 ) | V_304 ) ;
V_324 = V_2 -> V_4 . V_384 ;
V_325 = ( V_2 -> V_4 . V_385 + 1 ) & ~ 1 ;
F_27 ( V_386 + V_11 -> V_364 ,
( V_324 << 16 ) | V_325 ) ;
V_323 = F_26 ( V_387 + V_11 -> V_364 ) ;
V_323 &= ~ V_388 ;
F_27 ( V_387 + V_11 -> V_364 , V_323 ) ;
F_27 ( V_389 + V_11 -> V_364 , 0 ) ;
if ( ! V_305 && V_302 && V_302 != V_2 -> V_302 ) {
V_307 = F_57 ( V_302 ) ;
V_312 = F_58 ( V_307 -> V_310 ) ;
V_326 = F_59 ( V_312 , false ) ;
if ( F_60 ( V_326 != 0 ) )
return V_326 ;
F_77 ( V_312 ) ;
F_63 ( V_312 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_301 * V_302 ,
int V_303 , int V_304 , int V_305 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_306 * V_307 ;
struct V_309 * V_310 ;
struct V_311 * V_312 ;
struct V_301 * V_308 ;
T_11 V_313 ;
V_33 V_314 , V_315 , V_316 ;
T_9 V_321 = V_390 ;
T_9 V_323 , V_324 , V_325 ;
int V_326 ;
if ( ! V_305 && ! V_2 -> V_302 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_305 ) {
V_307 = F_57 ( V_302 ) ;
V_308 = V_302 ;
}
else {
V_307 = F_57 ( V_2 -> V_302 ) ;
V_308 = V_2 -> V_302 ;
}
V_310 = V_307 -> V_310 ;
V_312 = F_58 ( V_310 ) ;
V_326 = F_59 ( V_312 , false ) ;
if ( F_60 ( V_326 != 0 ) )
return V_326 ;
if ( V_305 )
V_313 = F_61 ( V_312 ) ;
else {
V_326 = F_62 ( V_312 , V_327 , & V_313 ) ;
if ( F_60 ( V_326 != 0 ) ) {
F_63 ( V_312 ) ;
return - V_328 ;
}
}
F_64 ( V_312 , & V_316 , NULL ) ;
F_63 ( V_312 ) ;
switch ( V_308 -> V_329 ) {
case 8 :
V_314 =
V_391 |
V_392 ;
break;
case 15 :
V_314 =
V_393 |
V_394 ;
break;
case 16 :
V_314 =
V_393 |
V_395 ;
#ifdef F_67
V_321 = V_396 ;
#endif
break;
case 24 :
case 32 :
V_314 =
V_397 |
V_398 ;
#ifdef F_67
V_321 = V_399 ;
#endif
break;
default:
F_44 ( L_3 ,
V_308 -> V_329 ) ;
return - V_328 ;
}
if ( V_9 -> V_69 >= V_400 ) {
if ( V_316 & V_339 )
V_314 |= V_401 ;
else if ( V_316 & V_351 )
V_314 |= V_402 ;
} else {
if ( V_316 & V_339 )
V_314 |= V_403 ;
if ( V_316 & V_351 )
V_314 |= V_404 ;
}
if ( V_11 -> V_18 == 0 )
F_27 ( V_357 , 0 ) ;
else
F_27 ( V_358 , 0 ) ;
if ( V_9 -> V_69 >= V_194 ) {
if ( V_11 -> V_18 ) {
F_27 ( V_405 , F_76 ( V_313 ) ) ;
F_27 ( V_406 , F_76 ( V_313 ) ) ;
} else {
F_27 ( V_407 , F_76 ( V_313 ) ) ;
F_27 ( V_408 , F_76 ( V_313 ) ) ;
}
}
F_27 ( V_409 + V_11 -> V_364 ,
( T_9 ) V_313 ) ;
F_27 ( V_410 +
V_11 -> V_364 , ( T_9 ) V_313 ) ;
F_27 ( V_411 + V_11 -> V_364 , V_314 ) ;
if ( V_9 -> V_69 >= V_400 )
F_27 ( V_412 + V_11 -> V_364 , V_321 ) ;
F_27 ( V_413 + V_11 -> V_364 , 0 ) ;
F_27 ( V_414 + V_11 -> V_364 , 0 ) ;
F_27 ( V_415 + V_11 -> V_364 , 0 ) ;
F_27 ( V_416 + V_11 -> V_364 , 0 ) ;
F_27 ( V_417 + V_11 -> V_364 , V_308 -> V_376 ) ;
F_27 ( V_418 + V_11 -> V_364 , V_308 -> V_378 ) ;
V_315 = V_308 -> V_379 [ 0 ] / ( V_308 -> V_329 / 8 ) ;
F_27 ( V_419 + V_11 -> V_364 , V_315 ) ;
F_27 ( V_420 + V_11 -> V_364 , 1 ) ;
F_27 ( V_421 + V_11 -> V_364 ,
V_308 -> V_378 ) ;
V_303 &= ~ 3 ;
V_304 &= ~ 1 ;
F_27 ( V_422 + V_11 -> V_364 ,
( V_303 << 16 ) | V_304 ) ;
V_324 = V_2 -> V_4 . V_384 ;
V_325 = ( V_2 -> V_4 . V_385 + 1 ) & ~ 1 ;
F_27 ( V_423 + V_11 -> V_364 ,
( V_324 << 16 ) | V_325 ) ;
V_323 = F_26 ( V_424 + V_11 -> V_364 ) ;
V_323 &= ~ V_425 ;
F_27 ( V_424 + V_11 -> V_364 , V_323 ) ;
F_27 ( V_426 + V_11 -> V_364 , 0 ) ;
if ( ! V_305 && V_302 && V_302 != V_2 -> V_302 ) {
V_307 = F_57 ( V_302 ) ;
V_312 = F_58 ( V_307 -> V_310 ) ;
V_326 = F_59 ( V_312 , false ) ;
if ( F_60 ( V_326 != 0 ) )
return V_326 ;
F_77 ( V_312 ) ;
F_63 ( V_312 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_303 , int V_304 ,
struct V_301 * V_427 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_25 ( V_9 ) )
return F_54 ( V_2 , V_427 , V_303 , V_304 , 0 ) ;
else if ( F_8 ( V_9 ) )
return F_79 ( V_2 , V_427 , V_303 , V_304 , 0 ) ;
else
return F_81 ( V_2 , V_427 , V_303 , V_304 , 0 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_301 * V_302 ,
int V_303 , int V_304 , enum V_428 V_74 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_25 ( V_9 ) )
return F_54 ( V_2 , V_302 , V_303 , V_304 , 1 ) ;
else if ( F_8 ( V_9 ) )
return F_79 ( V_2 , V_302 , V_303 , V_304 , 1 ) ;
else
return F_81 ( V_2 , V_302 , V_303 , V_304 , 1 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_9 V_429 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_429 = F_26 ( V_430 ) ;
V_429 &= ~ V_431 ;
F_27 ( V_430 , V_429 ) ;
break;
case 1 :
V_429 = F_26 ( V_432 ) ;
V_429 &= ~ V_433 ;
F_27 ( V_432 , V_429 ) ;
F_27 ( V_434 , F_26 ( V_435 ) ) ;
F_27 ( V_436 , F_26 ( V_437 ) ) ;
break;
}
}
static T_9 F_84 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_438 ;
struct V_11 * V_439 ;
T_9 V_440 = 0 ;
F_85 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_438 )
continue;
V_439 = F_2 ( V_438 ) ;
if ( V_439 -> V_132 != V_140 )
V_440 |= ( 1 << V_439 -> V_132 ) ;
}
return V_440 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_438 ;
struct V_11 * V_439 ;
F_85 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_438 )
continue;
V_439 = F_2 ( V_438 ) ;
if ( V_439 -> V_36 &&
F_42 ( F_34 ( V_439 -> V_36 ) ) ) {
if ( V_439 -> V_132 != V_140 )
return V_439 -> V_132 ;
}
}
return V_140 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_438 ;
struct V_11 * V_439 ;
T_9 V_182 , V_441 ;
V_182 = V_11 -> V_182 ;
if ( V_182 == 0 )
return V_140 ;
F_85 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_438 )
continue;
V_439 = F_2 ( V_438 ) ;
if ( V_439 -> V_36 &&
! F_42 ( F_34 ( V_439 -> V_36 ) ) ) {
if ( V_439 -> V_181 == V_11 -> V_181 ) {
if ( V_439 -> V_132 != V_140 )
return V_439 -> V_132 ;
}
V_441 = V_439 -> V_182 ;
if ( ( V_2 -> V_4 . clock == V_438 -> V_4 . clock ) &&
( V_182 == V_441 ) &&
( V_11 -> V_208 == V_439 -> V_208 ) &&
( V_439 -> V_132 != V_140 ) )
return V_439 -> V_132 ;
}
}
return V_140 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_9 V_440 ;
int V_289 ;
if ( F_30 ( V_9 ) ) {
struct V_232 * V_233 =
V_35 -> V_46 ;
if ( ( V_35 -> V_212 == V_442 ) &&
( V_233 -> V_443 == false ) )
return V_137 ;
else if ( F_42 ( F_34 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_444 )
return V_140 ;
else {
V_289 = F_86 ( V_2 ) ;
if ( V_289 != V_140 )
return V_289 ;
}
} else {
V_289 = F_87 ( V_2 ) ;
if ( V_289 != V_140 )
return V_289 ;
}
V_440 = F_84 ( V_2 ) ;
if ( ! ( V_440 & ( 1 << V_252 ) ) )
return V_252 ;
if ( ! ( V_440 & ( 1 << V_134 ) ) )
return V_134 ;
F_44 ( L_4 ) ;
return V_140 ;
} else if ( F_25 ( V_9 ) ) {
if ( F_42 ( F_34 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_444 )
return V_140 ;
else if ( F_18 ( V_9 ) )
return V_252 ;
else if ( F_29 ( V_9 ) )
return V_139 ;
else {
V_289 = F_86 ( V_2 ) ;
if ( V_289 != V_140 )
return V_289 ;
}
} else {
V_289 = F_87 ( V_2 ) ;
if ( V_289 != V_140 )
return V_289 ;
}
V_440 = F_84 ( V_2 ) ;
if ( ! ( V_440 & ( 1 << V_134 ) ) )
return V_134 ;
if ( ! ( V_440 & ( 1 << V_137 ) ) )
return V_137 ;
F_44 ( L_4 ) ;
return V_140 ;
} else {
return V_11 -> V_18 ;
}
}
void F_89 ( struct V_8 * V_9 )
{
if ( F_18 ( V_9 ) )
F_45 ( V_9 , V_9 -> clock . V_445 ) ;
else if ( F_25 ( V_9 ) ) {
struct V_144 V_145 ;
bool V_208 = F_49 ( V_9 , & V_145 ,
V_446 ,
V_9 -> clock . V_445 ) ;
if ( V_208 )
F_28 ( V_9 , V_84 , V_139 , - 1 , & V_145 ) ;
F_45 ( V_9 , V_9 -> clock . V_445 ) ;
if ( V_208 )
F_28 ( V_9 , V_83 , V_139 , - 1 , & V_145 ) ;
}
}
int F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_303 , int V_304 , struct V_301 * V_427 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
bool V_447 = false ;
if ( V_35 -> V_42 &
( V_43 | V_448 ) )
V_447 = true ;
F_51 ( V_2 , V_5 ) ;
if ( F_25 ( V_9 ) )
F_22 ( V_2 , V_5 ) ;
else if ( F_8 ( V_9 ) ) {
if ( V_447 )
F_23 ( V_2 , V_5 ) ;
else
F_22 ( V_2 , V_5 ) ;
} else {
F_23 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_22 ( V_2 , V_5 ) ;
F_83 ( V_2 ) ;
}
F_80 ( V_2 , V_303 , V_304 , V_427 ) ;
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
struct V_179 * V_36 ;
F_85 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_36 -> V_2 == V_2 ) {
V_11 -> V_36 = V_36 ;
V_11 -> V_181 = F_33 ( V_36 ) ;
break;
}
}
if ( ( V_11 -> V_36 == NULL ) || ( V_11 -> V_181 == NULL ) ) {
V_11 -> V_36 = NULL ;
V_11 -> V_181 = NULL ;
return false ;
}
if ( ! F_92 ( V_2 , V_4 , V_5 ) )
return false ;
if ( ! F_48 ( V_2 , V_5 ) )
return false ;
V_11 -> V_132 = F_88 ( V_2 ) ;
if ( ( V_11 -> V_132 == V_140 ) &&
! F_42 ( F_34 ( V_11 -> V_36 ) ) )
return false ;
return true ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_18 ( V_9 ) )
F_14 ( V_2 , V_84 ) ;
F_10 ( V_2 , V_83 ) ;
F_15 ( V_2 , V_87 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_81 ) ;
F_10 ( V_2 , V_84 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_144 V_145 ;
int V_146 ;
F_15 ( V_2 , V_87 ) ;
if ( F_18 ( V_9 ) )
F_14 ( V_2 , V_83 ) ;
for ( V_146 = 0 ; V_146 < V_9 -> V_149 ; V_146 ++ ) {
if ( V_9 -> V_31 . V_150 [ V_146 ] &&
V_9 -> V_31 . V_150 [ V_146 ] -> V_82 &&
V_146 != V_11 -> V_18 &&
V_11 -> V_132 == V_9 -> V_31 . V_150 [ V_146 ] -> V_132 ) {
goto V_449;
}
}
switch ( V_11 -> V_132 ) {
case V_134 :
case V_137 :
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_132 ,
0 , 0 , V_84 , 0 , 0 , 0 , 0 , 0 , false , & V_145 ) ;
break;
case V_252 :
if ( F_30 ( V_9 ) )
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_132 ,
0 , 0 , V_84 , 0 , 0 , 0 , 0 , 0 , false , & V_145 ) ;
break;
default:
break;
}
V_449:
V_11 -> V_132 = V_140 ;
V_11 -> V_182 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_181 = NULL ;
}
void F_96 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_25 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_364 = V_450 ;
break;
case 1 :
V_11 -> V_364 = V_451 ;
break;
case 2 :
V_11 -> V_364 = V_452 ;
break;
case 3 :
V_11 -> V_364 = V_453 ;
break;
case 4 :
V_11 -> V_364 = V_454 ;
break;
case 5 :
V_11 -> V_364 = V_455 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_364 =
V_456 - V_457 ;
else
V_11 -> V_364 = 0 ;
}
V_11 -> V_132 = V_140 ;
V_11 -> V_182 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_181 = NULL ;
F_97 ( & V_11 -> V_458 , & V_459 ) ;
}
