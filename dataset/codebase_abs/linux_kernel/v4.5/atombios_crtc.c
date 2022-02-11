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
T_5 V_78 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_14 ( V_9 ) ) {
V_78 = F_15 ( V_79 [ V_11 -> V_18 ] ) ;
F_16 ( V_79 [ V_11 -> V_18 ] , V_78 | 1 ) ;
}
args . V_17 = V_11 -> V_18 ;
args . V_80 = V_74 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
if ( F_14 ( V_9 ) ) {
F_16 ( V_79 [ V_11 -> V_18 ] , V_78 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , int V_74 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_81 ) ;
T_6 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_82 = V_11 -> V_18 ;
args . V_63 = V_74 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
void F_18 ( struct V_1 * V_2 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_83 :
V_11 -> V_84 = true ;
F_11 ( V_2 , V_85 ) ;
if ( F_19 ( V_9 ) && ! F_20 ( V_9 ) )
F_12 ( V_2 , V_85 ) ;
F_13 ( V_2 , V_86 ) ;
F_21 ( V_7 , V_11 -> V_18 ) ;
F_22 ( V_2 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
F_23 ( V_7 , V_11 -> V_18 ) ;
if ( V_11 -> V_84 )
F_13 ( V_2 , V_85 ) ;
if ( F_19 ( V_9 ) && ! F_20 ( V_9 ) )
F_12 ( V_2 , V_86 ) ;
F_11 ( V_2 , V_86 ) ;
V_11 -> V_84 = false ;
break;
}
F_24 ( V_9 ) ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_7 args ;
int V_12 = F_3 ( V_13 , V_90 ) ;
T_8 V_91 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_92 = F_4 ( V_4 -> V_25 - ( V_11 -> V_29 * 2 ) ) ;
args . V_93 =
F_4 ( V_4 -> V_94 - V_4 -> V_25 + ( V_11 -> V_29 * 2 ) ) ;
args . V_95 = F_4 ( V_4 -> V_22 - ( V_11 -> V_30 * 2 ) ) ;
args . V_96 =
F_4 ( V_4 -> V_97 - V_4 -> V_22 + ( V_11 -> V_30 * 2 ) ) ;
args . V_98 =
F_4 ( V_4 -> V_99 - V_4 -> V_25 + V_11 -> V_29 ) ;
args . V_100 =
F_4 ( V_4 -> V_101 - V_4 -> V_99 ) ;
args . V_102 =
F_4 ( V_4 -> V_103 - V_4 -> V_22 + V_11 -> V_30 ) ;
args . V_104 =
F_4 ( V_4 -> V_105 - V_4 -> V_103 ) ;
args . V_106 = V_11 -> V_29 ;
args . V_107 = V_11 -> V_30 ;
if ( V_4 -> V_108 & V_109 )
V_91 |= V_110 ;
if ( V_4 -> V_108 & V_111 )
V_91 |= V_112 ;
if ( V_4 -> V_108 & V_113 )
V_91 |= V_114 ;
if ( V_4 -> V_108 & V_115 )
V_91 |= V_116 ;
if ( V_4 -> V_108 & V_117 )
V_91 |= V_118 ;
if ( V_4 -> V_108 & V_119 )
V_91 |= V_120 | V_121 ;
args . V_122 . V_123 = F_4 ( V_91 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_9 args ;
int V_12 = F_3 ( V_13 , V_124 ) ;
T_8 V_91 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_125 = F_4 ( V_4 -> V_126 ) ;
args . V_127 = F_4 ( V_4 -> V_25 ) ;
args . V_128 = F_4 ( V_4 -> V_99 ) ;
args . V_100 =
F_4 ( V_4 -> V_101 - V_4 -> V_99 ) ;
args . V_129 = F_4 ( V_4 -> V_130 ) ;
args . V_131 = F_4 ( V_4 -> V_22 ) ;
args . V_132 = F_4 ( V_4 -> V_103 ) ;
args . V_104 =
F_4 ( V_4 -> V_105 - V_4 -> V_103 ) ;
args . V_133 = V_11 -> V_29 ;
args . V_134 = V_11 -> V_29 ;
args . V_135 = V_11 -> V_30 ;
args . V_136 = V_11 -> V_30 ;
if ( V_4 -> V_108 & V_109 )
V_91 |= V_110 ;
if ( V_4 -> V_108 & V_111 )
V_91 |= V_112 ;
if ( V_4 -> V_108 & V_113 )
V_91 |= V_114 ;
if ( V_4 -> V_108 & V_115 )
V_91 |= V_116 ;
if ( V_4 -> V_108 & V_117 )
V_91 |= V_118 ;
if ( V_4 -> V_108 & V_119 )
V_91 |= V_120 | V_121 ;
args . V_122 . V_123 = F_4 ( V_91 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_27 ( struct V_8 * V_9 , int V_137 )
{
T_5 V_138 ;
if ( F_28 ( V_9 ) ) {
switch ( V_137 ) {
case V_139 :
V_138 = F_15 ( V_140 ) ;
V_138 &= ~ V_141 ;
F_16 ( V_140 , V_138 ) ;
break;
case V_142 :
V_138 = F_15 ( V_143 ) ;
V_138 &= ~ V_141 ;
F_16 ( V_143 , V_138 ) ;
break;
case V_144 :
case V_145 :
return;
}
} else if ( F_8 ( V_9 ) ) {
switch ( V_137 ) {
case V_139 :
V_138 = F_15 ( V_146 ) ;
V_138 &= ~ 1 ;
F_16 ( V_146 , V_138 ) ;
break;
case V_142 :
V_138 = F_15 ( V_147 ) ;
V_138 &= ~ 1 ;
F_16 ( V_147 , V_138 ) ;
break;
case V_144 :
case V_145 :
return;
}
}
}
static void F_29 ( struct V_8 * V_9 ,
int V_148 ,
int V_137 ,
int V_18 ,
struct V_149 * V_150 )
{
unsigned V_151 ;
int V_12 = F_3 ( V_13 , V_152 ) ;
union V_153 args ;
if ( V_148 ) {
if ( V_150 -> V_154 == 0 )
return;
if ( V_150 -> type & V_155 )
return;
} else {
for ( V_151 = 0 ; V_151 < V_9 -> V_156 ; V_151 ++ ) {
if ( V_9 -> V_31 . V_157 [ V_151 ] &&
V_9 -> V_31 . V_157 [ V_151 ] -> V_84 &&
V_151 != V_18 &&
V_137 == V_9 -> V_31 . V_157 [ V_151 ] -> V_137 ) {
return;
}
}
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_30 ( V_9 ) ) {
args . V_158 . V_159 = F_4 ( 0 ) ;
args . V_158 . V_160 = V_150 -> type & V_161 ;
switch ( V_137 ) {
case V_139 :
args . V_158 . V_160 |= V_162 ;
break;
case V_142 :
args . V_158 . V_160 |= V_163 ;
break;
case V_144 :
args . V_158 . V_160 |= V_164 ;
break;
case V_145 :
return;
}
args . V_158 . V_165 = F_4 ( V_150 -> V_166 ) ;
args . V_158 . V_167 = F_4 ( V_150 -> V_168 ) ;
args . V_158 . V_63 = V_148 ;
} else if ( F_28 ( V_9 ) ) {
args . V_169 . V_170 = F_4 ( V_150 -> V_154 ) ;
args . V_169 . V_160 = V_150 -> type & V_161 ;
switch ( V_137 ) {
case V_139 :
args . V_169 . V_160 |= V_171 ;
break;
case V_142 :
args . V_169 . V_160 |= V_172 ;
break;
case V_144 :
args . V_169 . V_160 |= V_173 ;
break;
case V_145 :
return;
}
args . V_169 . V_165 = F_4 ( V_150 -> V_166 ) ;
args . V_169 . V_167 = F_4 ( V_150 -> V_168 ) ;
args . V_169 . V_63 = V_148 ;
} else if ( F_19 ( V_9 ) ) {
args . V_174 . V_170 = F_4 ( V_150 -> V_154 ) ;
args . V_174 . V_160 = V_150 -> type & V_161 ;
args . V_174 . V_175 = V_150 -> V_168 ;
args . V_174 . V_176 = V_150 -> V_177 ;
args . V_174 . V_178 = V_150 -> V_179 ;
args . V_174 . V_180 = V_137 ;
args . V_174 . V_63 = V_148 ;
} else if ( F_8 ( V_9 ) ) {
if ( ( V_148 == V_86 ) || ( V_150 -> V_154 == 0 ) ||
( V_150 -> type & V_155 ) ) {
F_27 ( V_9 , V_137 ) ;
return;
}
args . V_181 . V_170 = F_4 ( V_150 -> V_154 ) ;
args . V_181 . V_160 = V_150 -> type & V_161 ;
args . V_181 . V_175 = V_150 -> V_168 ;
args . V_181 . V_176 = V_150 -> V_177 ;
args . V_181 . V_178 = V_150 -> V_179 ;
args . V_181 . V_63 = V_148 ;
} else {
if ( V_148 == V_86 ) {
F_27 ( V_9 , V_137 ) ;
return;
}
args . V_182 . V_170 = F_4 ( V_150 -> V_154 ) ;
args . V_182 . V_160 = V_150 -> type & V_161 ;
args . V_182 . V_183 = ( V_150 -> V_168 & 3 ) << 2 ;
args . V_182 . V_183 |= ( V_150 -> V_177 & 7 ) << 4 ;
args . V_182 . V_63 = V_148 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_5 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_184 * V_36 = V_11 -> V_36 ;
struct V_35 * V_35 = F_7 ( V_36 ) ;
struct V_185 * V_186 = F_32 ( V_36 ) ;
T_5 V_187 = V_4 -> clock ;
int V_188 = F_33 ( V_36 ) ;
T_5 V_189 = V_4 -> clock ;
T_5 clock = V_4 -> clock ;
int V_190 = V_11 -> V_190 ;
bool V_191 = F_34 ( V_36 , V_4 -> clock ) ;
V_11 -> V_192 = 0 ;
if ( F_8 ( V_9 ) ) {
if ( ( V_9 -> V_69 == V_193 ) ||
( V_9 -> V_69 == V_194 ) ||
( V_9 -> V_69 == V_195 ) )
V_11 -> V_192 |= (
V_196 ) ;
if ( F_35 ( V_9 ) && V_4 -> clock > 200000 )
V_11 -> V_192 |= V_197 ;
else
V_11 -> V_192 |= V_198 ;
if ( V_9 -> V_69 < V_199 )
V_11 -> V_192 |= V_200 ;
if ( F_36 ( V_9 ) || F_37 ( V_9 ) || F_14 ( V_9 ) )
V_11 -> V_192 |= V_201 ;
if ( ( V_9 -> V_69 == V_202 ) || ( V_9 -> V_69 == V_203 ) )
V_11 -> V_192 |= V_201 ;
if ( F_35 ( V_9 ) && V_4 -> clock > 165000 )
V_11 -> V_192 |= V_201 ;
} else {
V_11 -> V_192 |= V_204 ;
if ( V_4 -> clock > 200000 )
V_11 -> V_192 |= V_197 ;
else
V_11 -> V_192 |= V_198 ;
}
if ( ( V_35 -> V_205 & ( V_206 | V_207 ) ) ||
( F_38 ( V_36 ) != V_208 ) ) {
if ( V_186 ) {
struct V_209 * V_209 = F_39 ( V_186 ) ;
struct V_210 * V_211 =
V_209 -> V_212 ;
V_189 = V_211 -> V_189 ;
}
}
if ( V_35 -> V_213 ) {
struct V_214 * V_215 = V_35 -> V_46 ;
struct V_210 * V_211 = V_215 -> V_186 -> V_212 ;
V_189 = V_211 -> V_189 ;
}
if ( V_35 -> V_205 & ( V_206 ) ) {
if ( V_11 -> V_216 ) {
if ( V_11 -> V_150 . V_217 ) {
V_11 -> V_192 |= V_218 ;
V_11 -> V_219 = V_11 -> V_150 . V_217 ;
if ( F_8 ( V_9 ) )
V_11 -> V_192 |= V_201 ;
}
}
}
if ( F_8 ( V_9 ) ) {
if ( V_35 -> V_220 == V_221 )
V_187 = V_4 -> clock * 2 ;
if ( V_35 -> V_42 & ( V_43 ) )
V_11 -> V_192 |= V_196 ;
if ( V_35 -> V_205 & ( V_206 ) )
V_11 -> V_192 |= V_222 ;
} else {
if ( V_36 -> V_223 != V_224 )
V_11 -> V_192 |= V_225 ;
if ( V_36 -> V_223 == V_226 )
V_11 -> V_192 |= V_218 ;
}
if ( V_188 == V_227 ) {
switch ( V_190 ) {
case 8 :
default:
break;
case 10 :
clock = ( clock * 5 ) / 4 ;
break;
case 12 :
clock = ( clock * 3 ) / 2 ;
break;
case 16 :
clock = clock * 2 ;
break;
}
}
if ( F_19 ( V_9 ) ) {
union V_228 args ;
T_10 V_229 , V_230 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_231 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_229 ,
& V_230 ) )
return V_187 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_229 ) {
case 1 :
switch ( V_230 ) {
case 1 :
case 2 :
args . V_174 . V_232 = F_4 ( clock / 10 ) ;
args . V_174 . V_233 = V_35 -> V_220 ;
args . V_174 . V_234 = V_188 ;
if ( V_11 -> V_216 && V_11 -> V_150 . V_154 )
args . V_174 . V_235 |=
V_236 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_187 = F_41 ( args . V_174 . V_232 ) * 10 ;
break;
case 3 :
args . V_158 . V_237 . V_232 = F_4 ( clock / 10 ) ;
args . V_158 . V_237 . V_233 = V_35 -> V_220 ;
args . V_158 . V_237 . V_234 = V_188 ;
args . V_158 . V_237 . V_238 = 0 ;
if ( V_11 -> V_216 && V_11 -> V_150 . V_154 )
args . V_158 . V_237 . V_238 |=
V_239 ;
if ( F_42 ( V_188 ) ) {
args . V_158 . V_237 . V_238 |=
V_240 ;
args . V_158 . V_237 . V_232 = F_4 ( V_189 / 10 ) ;
} else if ( V_35 -> V_205 & ( V_207 ) ) {
struct V_241 * V_242 = V_35 -> V_46 ;
if ( V_242 -> V_243 )
args . V_158 . V_237 . V_238 |=
V_240 ;
if ( V_191 )
args . V_158 . V_237 . V_238 |=
V_244 ;
}
if ( F_38 ( V_36 ) !=
V_208 )
args . V_158 . V_237 . V_245 =
F_38 ( V_36 ) ;
else
args . V_158 . V_237 . V_245 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_187 = F_43 ( args . V_158 . V_246 . V_247 ) * 10 ;
if ( args . V_158 . V_246 . V_248 ) {
V_11 -> V_192 |= V_201 ;
V_11 -> V_192 |= V_218 ;
V_11 -> V_219 = args . V_158 . V_246 . V_248 ;
}
if ( args . V_158 . V_246 . V_249 ) {
V_11 -> V_192 |= V_201 ;
V_11 -> V_192 |= V_250 ;
V_11 -> V_251 = args . V_158 . V_246 . V_249 ;
}
break;
default:
F_44 ( L_1 , V_229 , V_230 ) ;
return V_187 ;
}
break;
default:
F_44 ( L_1 , V_229 , V_230 ) ;
return V_187 ;
}
}
return V_187 ;
}
static void F_45 ( struct V_8 * V_9 ,
T_5 V_252 )
{
T_10 V_229 , V_230 ;
int V_12 ;
union V_253 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_254 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_229 ,
& V_230 ) )
return;
switch ( V_229 ) {
case 1 :
switch ( V_230 ) {
case 5 :
args . V_255 . V_17 = V_256 ;
args . V_255 . V_232 = F_4 ( V_252 ) ;
args . V_255 . V_180 = V_144 ;
break;
case 6 :
args . V_257 . V_258 = F_46 ( V_252 ) ;
if ( F_37 ( V_9 ) || F_14 ( V_9 ) )
args . V_257 . V_180 = V_259 ;
else if ( F_20 ( V_9 ) )
args . V_257 . V_180 = V_260 ;
else
args . V_257 . V_180 = V_144 ;
break;
default:
F_44 ( L_1 , V_229 , V_230 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_229 , V_230 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_5 V_18 ,
int V_137 ,
T_5 V_188 ,
T_5 V_220 ,
T_5 clock ,
T_5 V_261 ,
T_5 V_262 ,
T_5 V_263 ,
T_5 V_264 ,
int V_190 ,
bool V_216 ,
struct V_149 * V_150 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_10 V_229 , V_230 ;
int V_12 = F_3 ( V_13 , V_254 ) ;
union V_253 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_229 ,
& V_230 ) )
return;
switch ( V_229 ) {
case 1 :
switch ( V_230 ) {
case 1 :
if ( clock == V_86 )
return;
args . V_174 . V_232 = F_4 ( clock / 10 ) ;
args . V_174 . V_265 = F_4 ( V_261 ) ;
args . V_174 . V_266 = F_4 ( V_262 ) ;
args . V_174 . V_267 = V_263 ;
args . V_174 . V_249 = V_264 ;
args . V_174 . V_180 = V_137 ;
args . V_174 . V_17 = V_18 ;
args . V_174 . V_268 = 1 ;
break;
case 2 :
args . V_169 . V_232 = F_4 ( clock / 10 ) ;
args . V_169 . V_265 = F_4 ( V_261 ) ;
args . V_169 . V_266 = F_4 ( V_262 ) ;
args . V_169 . V_267 = V_263 ;
args . V_169 . V_249 = V_264 ;
args . V_169 . V_180 = V_137 ;
args . V_169 . V_17 = V_18 ;
args . V_169 . V_268 = 1 ;
break;
case 3 :
args . V_158 . V_232 = F_4 ( clock / 10 ) ;
args . V_158 . V_265 = F_4 ( V_261 ) ;
args . V_158 . V_266 = F_4 ( V_262 ) ;
args . V_158 . V_267 = V_263 ;
args . V_158 . V_249 = V_264 ;
args . V_158 . V_180 = V_137 ;
if ( V_18 == V_269 )
args . V_158 . V_270 = V_271 ;
else
args . V_158 . V_270 = V_272 ;
if ( V_216 && ( V_150 -> type & V_155 ) )
args . V_158 . V_270 |= V_273 ;
args . V_158 . V_274 = V_220 ;
args . V_158 . V_275 = V_188 ;
break;
case 5 :
args . V_255 . V_17 = V_18 ;
args . V_255 . V_232 = F_4 ( clock / 10 ) ;
args . V_255 . V_248 = V_261 ;
args . V_255 . V_266 = F_4 ( V_262 ) ;
args . V_255 . V_276 = F_46 ( V_263 * 100000 ) ;
args . V_255 . V_249 = V_264 ;
args . V_255 . V_270 = 0 ;
if ( V_216 && ( V_150 -> type & V_155 ) )
args . V_255 . V_270 |= V_277 ;
if ( V_188 == V_227 ) {
switch ( V_190 ) {
case 8 :
default:
args . V_255 . V_270 |= V_278 ;
break;
case 10 :
args . V_255 . V_270 |= V_279 ;
break;
case 12 :
args . V_255 . V_270 |= V_280 ;
break;
}
}
args . V_255 . V_233 = V_220 ;
args . V_255 . V_275 = V_188 ;
args . V_255 . V_180 = V_137 ;
break;
case 6 :
args . V_257 . V_258 = F_46 ( V_18 << 24 | clock / 10 ) ;
args . V_257 . V_248 = V_261 ;
args . V_257 . V_266 = F_4 ( V_262 ) ;
args . V_257 . V_276 = F_46 ( V_263 * 100000 ) ;
args . V_257 . V_249 = V_264 ;
args . V_257 . V_270 = 0 ;
if ( V_216 && ( V_150 -> type & V_155 ) )
args . V_257 . V_270 |= V_281 ;
if ( V_188 == V_227 ) {
switch ( V_190 ) {
case 8 :
default:
args . V_257 . V_270 |= V_282 ;
break;
case 10 :
args . V_257 . V_270 |= V_283 ;
break;
case 12 :
args . V_257 . V_270 |= V_284 ;
break;
case 16 :
args . V_257 . V_270 |= V_285 ;
break;
}
}
args . V_257 . V_233 = V_220 ;
args . V_257 . V_275 = V_188 ;
args . V_257 . V_180 = V_137 ;
break;
default:
F_44 ( L_1 , V_229 , V_230 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_229 , V_230 ) ;
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
int V_188 = F_33 ( V_11 -> V_36 ) ;
V_11 -> V_190 = 8 ;
V_11 -> V_216 = false ;
if ( V_35 -> V_213 ) {
F_49 ( V_2 , V_4 ) ;
} else if ( ( V_35 -> V_42 & ( V_206 | V_207 ) ) ||
( F_38 ( V_11 -> V_36 ) != V_208 ) ) {
struct V_241 * V_242 = V_35 -> V_46 ;
struct V_185 * V_186 =
F_32 ( V_11 -> V_36 ) ;
struct V_209 * V_209 =
F_39 ( V_186 ) ;
struct V_210 * V_211 =
V_209 -> V_212 ;
int V_189 ;
V_209 -> V_286 = V_4 -> clock ;
V_11 -> V_190 = F_50 ( V_186 ) ;
switch ( V_188 ) {
case V_287 :
case V_288 :
V_189 = V_211 -> V_189 / 10 ;
if ( F_28 ( V_9 ) )
V_11 -> V_216 =
F_51 ( V_9 , & V_11 -> V_150 ,
V_289 ,
V_189 ) ;
else {
if ( V_189 == 16200 ) {
V_11 -> V_216 =
F_52 ( V_9 ,
& V_11 -> V_150 ,
V_290 ) ;
if ( ! V_11 -> V_216 )
V_11 -> V_216 =
F_52 ( V_9 ,
& V_11 -> V_150 ,
V_291 ) ;
} else {
V_11 -> V_216 =
F_52 ( V_9 ,
& V_11 -> V_150 ,
V_291 ) ;
}
V_11 -> V_216 = false ;
}
break;
case V_292 :
if ( F_28 ( V_9 ) )
V_11 -> V_216 =
F_51 ( V_9 ,
& V_11 -> V_150 ,
V_242 -> V_293 ,
V_4 -> clock / 10 ) ;
else
V_11 -> V_216 =
F_52 ( V_9 ,
& V_11 -> V_150 ,
V_242 -> V_293 ) ;
break;
case V_294 :
if ( F_28 ( V_9 ) )
V_11 -> V_216 =
F_51 ( V_9 ,
& V_11 -> V_150 ,
V_295 ,
V_4 -> clock / 10 ) ;
break;
case V_227 :
if ( F_28 ( V_9 ) )
V_11 -> V_216 =
F_51 ( V_9 ,
& V_11 -> V_150 ,
V_296 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_11 -> V_187 = F_31 ( V_2 , V_4 ) ;
return true ;
}
static void F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_5 V_297 = V_4 -> clock ;
T_5 clock = V_4 -> clock ;
T_5 V_261 = 0 , V_262 = 0 , V_263 = 0 , V_264 = 0 ;
struct V_298 * V_299 ;
int V_188 = F_33 ( V_11 -> V_36 ) ;
if ( F_30 ( V_9 ) &&
( V_188 == V_227 ) &&
( V_11 -> V_190 > 8 ) )
clock = V_11 -> V_187 ;
switch ( V_11 -> V_137 ) {
case V_139 :
V_299 = & V_9 -> clock . V_300 ;
break;
case V_142 :
V_299 = & V_9 -> clock . V_301 ;
break;
case V_144 :
case V_145 :
default:
V_299 = & V_9 -> clock . V_302 ;
break;
}
V_299 -> V_108 = V_11 -> V_192 ;
V_299 -> V_303 = V_11 -> V_219 ;
V_299 -> V_264 = V_11 -> V_251 ;
if ( V_35 -> V_42 & ( V_43 ) )
F_54 ( V_299 , V_11 -> V_187 , & V_297 ,
& V_262 , & V_263 , & V_261 , & V_264 ) ;
else if ( F_8 ( V_9 ) )
F_55 ( V_299 , V_11 -> V_187 , & V_297 ,
& V_262 , & V_263 , & V_261 , & V_264 ) ;
else
F_54 ( V_299 , V_11 -> V_187 , & V_297 ,
& V_262 , & V_263 , & V_261 , & V_264 ) ;
F_29 ( V_9 , V_86 , V_11 -> V_137 ,
V_11 -> V_18 , & V_11 -> V_150 ) ;
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_137 ,
V_188 , V_35 -> V_220 , clock ,
V_261 , V_262 , V_263 , V_264 ,
V_11 -> V_190 , V_11 -> V_216 , & V_11 -> V_150 ) ;
if ( V_11 -> V_216 ) {
if ( F_28 ( V_9 ) ) {
T_5 V_304 ;
T_5 V_166 = ( ( ( V_262 * 10 ) + V_263 ) *
( T_5 ) V_11 -> V_150 . V_154 ) /
( 100 * ( T_5 ) V_11 -> V_150 . V_305 ) ;
V_11 -> V_150 . V_166 = ( V_166 / 10 ) & V_306 ;
V_11 -> V_150 . V_166 |= ( ( V_166 - ( V_166 / 10 ) ) << V_307 ) &
V_308 ;
if ( V_11 -> V_150 . type & V_309 )
V_304 = ( 4 * V_166 * V_261 * ( ( T_5 ) V_11 -> V_150 . V_310 * 2048 ) ) /
( 125 * 25 * V_299 -> V_311 / 100 ) ;
else
V_304 = ( 2 * V_166 * V_261 * ( ( T_5 ) V_11 -> V_150 . V_310 * 2048 ) ) /
( 125 * 25 * V_299 -> V_311 / 100 ) ;
V_11 -> V_150 . V_168 = V_304 ;
}
F_29 ( V_9 , V_85 , V_11 -> V_137 ,
V_11 -> V_18 , & V_11 -> V_150 ) ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_312 * V_313 ,
int V_314 , int V_315 , int V_316 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_317 * V_318 ;
struct V_312 * V_319 ;
struct V_320 * V_321 ;
struct V_322 * V_323 ;
T_11 V_324 ;
V_33 V_325 , V_326 , V_327 ;
unsigned V_328 , V_329 , V_330 , V_331 ;
T_5 V_332 = F_57 ( V_333 ) ;
T_5 V_334 , V_335 , V_336 ;
int V_337 ;
bool V_338 = false ;
if ( ! V_316 && ! V_2 -> V_339 -> V_313 ) {
F_58 ( L_2 ) ;
return 0 ;
}
if ( V_316 ) {
V_318 = F_59 ( V_313 ) ;
V_319 = V_313 ;
}
else {
V_318 = F_59 ( V_2 -> V_339 -> V_313 ) ;
V_319 = V_2 -> V_339 -> V_313 ;
}
V_321 = V_318 -> V_321 ;
V_323 = F_60 ( V_321 ) ;
V_337 = F_61 ( V_323 , false ) ;
if ( F_62 ( V_337 != 0 ) )
return V_337 ;
if ( V_316 )
V_324 = F_63 ( V_323 ) ;
else {
V_337 = F_64 ( V_323 , V_340 , & V_324 ) ;
if ( F_62 ( V_337 != 0 ) ) {
F_65 ( V_323 ) ;
return - V_341 ;
}
}
F_66 ( V_323 , & V_327 , NULL ) ;
F_65 ( V_323 ) ;
switch ( V_319 -> V_342 ) {
case V_343 :
V_325 = ( F_67 ( V_344 ) |
F_68 ( V_345 ) ) ;
break;
case V_346 :
case V_347 :
V_325 = ( F_67 ( V_348 ) |
F_68 ( V_349 ) ) ;
#ifdef F_69
V_332 = F_57 ( V_350 ) ;
#endif
break;
case V_351 :
case V_352 :
V_325 = ( F_67 ( V_348 ) |
F_68 ( V_353 ) ) ;
#ifdef F_69
V_332 = F_57 ( V_350 ) ;
#endif
break;
case V_354 :
case V_355 :
V_325 = ( F_67 ( V_348 ) |
F_68 ( V_356 ) ) ;
#ifdef F_69
V_332 = F_57 ( V_350 ) ;
#endif
break;
case V_357 :
V_325 = ( F_67 ( V_348 ) |
F_68 ( V_358 ) ) ;
#ifdef F_69
V_332 = F_57 ( V_350 ) ;
#endif
break;
case V_359 :
case V_360 :
V_325 = ( F_67 ( V_361 ) |
F_68 ( V_362 ) ) ;
#ifdef F_69
V_332 = F_57 ( V_363 ) ;
#endif
break;
case V_364 :
case V_365 :
V_325 = ( F_67 ( V_361 ) |
F_68 ( V_366 ) ) ;
#ifdef F_69
V_332 = F_57 ( V_363 ) ;
#endif
V_338 = true ;
break;
case V_367 :
case V_368 :
V_325 = ( F_67 ( V_361 ) |
F_68 ( V_369 ) ) ;
#ifdef F_69
V_332 = F_57 ( V_363 ) ;
#endif
V_338 = true ;
break;
default:
F_44 ( L_3 ,
F_70 ( V_319 -> V_342 ) ) ;
return - V_341 ;
}
if ( V_327 & V_370 ) {
F_71 ( V_327 , & V_328 , & V_329 , & V_330 , & V_331 ) ;
if ( V_9 -> V_69 >= V_371 ) {
unsigned V_12 , V_372 ;
if ( V_9 -> V_69 >= V_373 ) {
unsigned V_374 , V_375 ;
V_375 = 64 << V_331 ;
V_374 = 8 * 8 * V_319 -> V_376 / 8 ;
V_374 = F_72 ( V_375 , V_374 ) ;
for ( V_12 = 0 ; V_374 > 64 ; V_12 ++ )
V_374 >>= 1 ;
if ( V_12 >= 16 ) {
F_44 ( L_4 ,
V_319 -> V_376 , V_331 ) ;
return - V_341 ;
}
V_372 = ( V_9 -> V_377 . V_378 . V_379 [ V_12 ] >> 6 ) & 0x3 ;
} else {
switch ( V_319 -> V_376 ) {
case 8 :
V_12 = 10 ;
break;
case 16 :
V_12 = V_380 ;
break;
default:
case 32 :
V_12 = V_381 ;
break;
}
V_372 = ( V_9 -> V_377 . V_382 . V_383 [ V_12 ] >> 20 ) & 0x3 ;
}
V_325 |= F_73 ( V_372 ) ;
} else {
if ( V_9 -> V_69 >= V_384 )
V_334 = V_9 -> V_377 . V_385 . V_386 ;
else
V_334 = V_9 -> V_377 . V_387 . V_386 ;
switch ( ( V_334 & 0xf0 ) >> 4 ) {
case 0 :
V_325 |= F_73 ( V_388 ) ;
break;
case 1 :
default:
V_325 |= F_73 ( V_389 ) ;
break;
case 2 :
V_325 |= F_73 ( V_390 ) ;
break;
}
}
V_325 |= F_74 ( V_391 ) ;
V_325 |= F_75 ( V_331 ) ;
V_325 |= F_76 ( V_328 ) ;
V_325 |= F_77 ( V_329 ) ;
V_325 |= F_78 ( V_330 ) ;
if ( V_9 -> V_69 >= V_373 ) {
V_325 |= F_79 ( V_392 ) ;
}
} else if ( V_327 & V_393 )
V_325 |= F_74 ( V_394 ) ;
if ( V_9 -> V_69 >= V_373 ) {
T_5 V_395 = ( V_9 -> V_377 . V_378 . V_383 [ 10 ] >> 6 ) & 0x1f ;
V_325 |= F_80 ( V_395 ) ;
} else if ( ( V_9 -> V_69 == V_371 ) ||
( V_9 -> V_69 == V_396 ) )
V_325 |= F_81 ( V_397 ) ;
else if ( ( V_9 -> V_69 == V_398 ) ||
( V_9 -> V_69 == V_399 ) ||
( V_9 -> V_69 == V_400 ) )
V_325 |= F_81 ( V_401 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_16 ( V_402 , 0 ) ;
break;
case 1 :
F_16 ( V_403 , 0 ) ;
break;
case 2 :
F_16 ( V_404 , 0 ) ;
break;
case 3 :
F_16 ( V_405 , 0 ) ;
break;
case 4 :
F_16 ( V_406 , 0 ) ;
break;
case 5 :
F_16 ( V_407 , 0 ) ;
break;
default:
break;
}
F_16 ( V_408 + V_11 -> V_409 ,
F_82 ( V_324 ) ) ;
F_16 ( V_410 + V_11 -> V_409 ,
F_82 ( V_324 ) ) ;
F_16 ( V_411 + V_11 -> V_409 ,
( T_5 ) V_324 & V_412 ) ;
F_16 ( V_413 + V_11 -> V_409 ,
( T_5 ) V_324 & V_412 ) ;
F_16 ( V_414 + V_11 -> V_409 , V_325 ) ;
F_16 ( V_415 + V_11 -> V_409 , V_332 ) ;
F_83 ( V_416 + V_11 -> V_409 ,
( V_338 ? V_417 : 0 ) ,
~ V_417 ) ;
if ( V_338 )
F_58 ( L_5 ) ;
F_16 ( V_418 + V_11 -> V_409 , 0 ) ;
F_16 ( V_419 + V_11 -> V_409 , 0 ) ;
F_16 ( V_420 + V_11 -> V_409 , 0 ) ;
F_16 ( V_421 + V_11 -> V_409 , 0 ) ;
F_16 ( V_422 + V_11 -> V_409 , V_319 -> V_423 ) ;
F_16 ( V_424 + V_11 -> V_409 , V_319 -> V_425 ) ;
V_326 = V_319 -> V_426 [ 0 ] / ( V_319 -> V_376 / 8 ) ;
F_16 ( V_427 + V_11 -> V_409 , V_326 ) ;
F_16 ( V_428 + V_11 -> V_409 , 1 ) ;
if ( V_9 -> V_69 >= V_373 )
F_16 ( V_429 + V_11 -> V_409 ,
V_319 -> V_425 ) ;
else
F_16 ( V_430 + V_11 -> V_409 ,
V_319 -> V_425 ) ;
V_314 &= ~ 3 ;
V_315 &= ~ 1 ;
F_16 ( V_431 + V_11 -> V_409 ,
( V_314 << 16 ) | V_315 ) ;
V_335 = V_2 -> V_4 . V_432 ;
V_336 = ( V_2 -> V_4 . V_433 + 1 ) & ~ 1 ;
if ( ( V_9 -> V_69 >= V_373 ) &&
( V_2 -> V_4 . V_108 & V_115 ) )
V_336 *= 2 ;
F_16 ( V_434 + V_11 -> V_409 ,
( V_335 << 16 ) | V_336 ) ;
V_334 = F_15 ( V_435 + V_11 -> V_409 ) ;
V_334 &= ~ V_436 ;
F_16 ( V_435 + V_11 -> V_409 , V_334 ) ;
F_16 ( V_437 + V_11 -> V_409 , 3 ) ;
if ( ! V_316 && V_313 && V_313 != V_2 -> V_339 -> V_313 ) {
V_318 = F_59 ( V_313 ) ;
V_323 = F_60 ( V_318 -> V_321 ) ;
V_337 = F_61 ( V_323 , false ) ;
if ( F_62 ( V_337 != 0 ) )
return V_337 ;
F_84 ( V_323 ) ;
F_65 ( V_323 ) ;
}
F_85 ( V_9 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_312 * V_313 ,
int V_314 , int V_315 , int V_316 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_317 * V_318 ;
struct V_320 * V_321 ;
struct V_322 * V_323 ;
struct V_312 * V_319 ;
T_11 V_324 ;
V_33 V_325 , V_326 , V_327 ;
T_5 V_332 = V_438 ;
T_5 V_334 , V_335 , V_336 ;
int V_337 ;
bool V_338 = false ;
if ( ! V_316 && ! V_2 -> V_339 -> V_313 ) {
F_58 ( L_2 ) ;
return 0 ;
}
if ( V_316 ) {
V_318 = F_59 ( V_313 ) ;
V_319 = V_313 ;
}
else {
V_318 = F_59 ( V_2 -> V_339 -> V_313 ) ;
V_319 = V_2 -> V_339 -> V_313 ;
}
V_321 = V_318 -> V_321 ;
V_323 = F_60 ( V_321 ) ;
V_337 = F_61 ( V_323 , false ) ;
if ( F_62 ( V_337 != 0 ) )
return V_337 ;
if ( V_316 )
V_324 = F_63 ( V_323 ) ;
else {
V_337 = F_64 ( V_323 , V_340 , & V_324 ) ;
if ( F_62 ( V_337 != 0 ) ) {
F_65 ( V_323 ) ;
return - V_341 ;
}
}
F_66 ( V_323 , & V_327 , NULL ) ;
F_65 ( V_323 ) ;
switch ( V_319 -> V_342 ) {
case V_343 :
V_325 =
V_439 |
V_440 ;
break;
case V_346 :
case V_347 :
V_325 =
V_441 |
V_442 ;
#ifdef F_69
V_332 = V_443 ;
#endif
break;
case V_351 :
V_325 =
V_441 |
V_444 ;
#ifdef F_69
V_332 = V_443 ;
#endif
break;
case V_357 :
V_325 =
V_441 |
V_445 ;
#ifdef F_69
V_332 = V_443 ;
#endif
break;
case V_359 :
case V_360 :
V_325 =
V_446 |
V_447 ;
#ifdef F_69
V_332 = V_448 ;
#endif
break;
case V_364 :
case V_365 :
V_325 =
V_446 |
V_449 ;
#ifdef F_69
V_332 = V_448 ;
#endif
V_338 = true ;
break;
default:
F_44 ( L_3 ,
F_70 ( V_319 -> V_342 ) ) ;
return - V_341 ;
}
if ( V_9 -> V_69 >= V_450 ) {
if ( V_327 & V_370 )
V_325 |= V_451 ;
else if ( V_327 & V_393 )
V_325 |= V_452 ;
} else {
if ( V_327 & V_370 )
V_325 |= V_453 ;
if ( V_327 & V_393 )
V_325 |= V_454 ;
}
if ( V_11 -> V_18 == 0 )
F_16 ( V_402 , 0 ) ;
else
F_16 ( V_403 , 0 ) ;
if ( V_9 -> V_69 >= V_199 ) {
if ( V_11 -> V_18 ) {
F_16 ( V_455 , F_82 ( V_324 ) ) ;
F_16 ( V_456 , F_82 ( V_324 ) ) ;
} else {
F_16 ( V_457 , F_82 ( V_324 ) ) ;
F_16 ( V_458 , F_82 ( V_324 ) ) ;
}
}
F_16 ( V_459 + V_11 -> V_409 ,
( T_5 ) V_324 ) ;
F_16 ( V_460 +
V_11 -> V_409 , ( T_5 ) V_324 ) ;
F_16 ( V_461 + V_11 -> V_409 , V_325 ) ;
if ( V_9 -> V_69 >= V_450 )
F_16 ( V_462 + V_11 -> V_409 , V_332 ) ;
F_83 ( V_463 + V_11 -> V_409 ,
( V_338 ? V_464 : 0 ) , ~ V_464 ) ;
if ( V_338 )
F_58 ( L_5 ) ;
F_16 ( V_465 + V_11 -> V_409 , 0 ) ;
F_16 ( V_466 + V_11 -> V_409 , 0 ) ;
F_16 ( V_467 + V_11 -> V_409 , 0 ) ;
F_16 ( V_468 + V_11 -> V_409 , 0 ) ;
F_16 ( V_469 + V_11 -> V_409 , V_319 -> V_423 ) ;
F_16 ( V_470 + V_11 -> V_409 , V_319 -> V_425 ) ;
V_326 = V_319 -> V_426 [ 0 ] / ( V_319 -> V_376 / 8 ) ;
F_16 ( V_471 + V_11 -> V_409 , V_326 ) ;
F_16 ( V_472 + V_11 -> V_409 , 1 ) ;
F_16 ( V_473 + V_11 -> V_409 ,
V_319 -> V_425 ) ;
V_314 &= ~ 3 ;
V_315 &= ~ 1 ;
F_16 ( V_474 + V_11 -> V_409 ,
( V_314 << 16 ) | V_315 ) ;
V_335 = V_2 -> V_4 . V_432 ;
V_336 = ( V_2 -> V_4 . V_433 + 1 ) & ~ 1 ;
F_16 ( V_475 + V_11 -> V_409 ,
( V_335 << 16 ) | V_336 ) ;
V_334 = F_15 ( V_476 + V_11 -> V_409 ) ;
V_334 &= ~ V_477 ;
F_16 ( V_476 + V_11 -> V_409 , V_334 ) ;
F_16 ( V_478 + V_11 -> V_409 , 3 ) ;
if ( ! V_316 && V_313 && V_313 != V_2 -> V_339 -> V_313 ) {
V_318 = F_59 ( V_313 ) ;
V_323 = F_60 ( V_318 -> V_321 ) ;
V_337 = F_61 ( V_323 , false ) ;
if ( F_62 ( V_337 != 0 ) )
return V_337 ;
F_84 ( V_323 ) ;
F_65 ( V_323 ) ;
}
F_85 ( V_9 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , int V_314 , int V_315 ,
struct V_312 * V_479 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_56 ( V_2 , V_479 , V_314 , V_315 , 0 ) ;
else if ( F_8 ( V_9 ) )
return F_86 ( V_2 , V_479 , V_314 , V_315 , 0 ) ;
else
return F_88 ( V_2 , V_479 , V_314 , V_315 , 0 ) ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_312 * V_313 ,
int V_314 , int V_315 , enum V_480 V_74 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_56 ( V_2 , V_313 , V_314 , V_315 , 1 ) ;
else if ( F_8 ( V_9 ) )
return F_86 ( V_2 , V_313 , V_314 , V_315 , 1 ) ;
else
return F_88 ( V_2 , V_313 , V_314 , V_315 , 1 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_5 V_481 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_481 = F_15 ( V_482 ) ;
V_481 &= ~ V_483 ;
F_16 ( V_482 , V_481 ) ;
break;
case 1 :
V_481 = F_15 ( V_484 ) ;
V_481 &= ~ V_485 ;
F_16 ( V_484 , V_481 ) ;
F_16 ( V_486 , F_15 ( V_487 ) ) ;
F_16 ( V_488 , F_15 ( V_489 ) ) ;
break;
}
}
static T_5 F_91 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_490 ;
struct V_11 * V_491 ;
T_5 V_492 = 0 ;
F_92 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_490 )
continue;
V_491 = F_2 ( V_490 ) ;
if ( V_491 -> V_137 != V_145 )
V_492 |= ( 1 << V_491 -> V_137 ) ;
}
return V_492 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_490 ;
struct V_11 * V_491 ;
F_92 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_490 )
continue;
V_491 = F_2 ( V_490 ) ;
if ( V_491 -> V_36 &&
F_42 ( F_33 ( V_491 -> V_36 ) ) ) {
if ( V_491 -> V_137 != V_145 )
return V_491 -> V_137 ;
}
}
return V_145 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_490 ;
struct V_11 * V_491 ;
T_5 V_187 , V_493 ;
V_187 = V_11 -> V_187 ;
if ( V_187 == 0 )
return V_145 ;
F_92 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_490 )
continue;
V_491 = F_2 ( V_490 ) ;
if ( V_491 -> V_36 &&
! F_42 ( F_33 ( V_491 -> V_36 ) ) ) {
if ( V_491 -> V_186 == V_11 -> V_186 ) {
if ( V_491 -> V_137 != V_145 )
return V_491 -> V_137 ;
}
V_493 = V_491 -> V_187 ;
if ( ( V_2 -> V_4 . clock == V_490 -> V_4 . clock ) &&
( V_187 == V_493 ) &&
( V_11 -> V_216 == V_491 -> V_216 ) &&
( V_491 -> V_137 != V_145 ) )
return V_491 -> V_137 ;
}
}
return V_145 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_5 V_492 ;
int V_299 ;
if ( F_14 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_145 ;
else {
V_299 = F_93 ( V_2 ) ;
if ( V_299 != V_145 )
return V_299 ;
}
} else {
V_299 = F_94 ( V_2 ) ;
if ( V_299 != V_145 )
return V_299 ;
}
if ( ( V_9 -> V_69 == V_495 ) ||
( V_9 -> V_69 == V_496 ) ) {
V_492 = F_91 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_142 ) ) )
return V_142 ;
if ( ! ( V_492 & ( 1 << V_139 ) ) )
return V_139 ;
F_44 ( L_6 ) ;
return V_145 ;
} else {
V_492 = F_91 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_142 ) ) )
return V_142 ;
if ( ! ( V_492 & ( 1 << V_139 ) ) )
return V_139 ;
if ( ! ( V_492 & ( 1 << V_260 ) ) )
return V_260 ;
F_44 ( L_6 ) ;
return V_145 ;
}
} else if ( F_37 ( V_9 ) ) {
struct V_241 * V_242 =
V_35 -> V_46 ;
if ( ( V_35 -> V_220 == V_497 ) &&
( V_242 -> V_498 == false ) )
return V_142 ;
else if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_145 ;
else {
V_299 = F_93 ( V_2 ) ;
if ( V_299 != V_145 )
return V_299 ;
}
} else {
V_299 = F_94 ( V_2 ) ;
if ( V_299 != V_145 )
return V_299 ;
}
V_492 = F_91 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_260 ) ) )
return V_260 ;
if ( ! ( V_492 & ( 1 << V_139 ) ) )
return V_139 ;
F_44 ( L_6 ) ;
return V_145 ;
} else if ( F_36 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_145 ;
}
V_492 = F_91 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_139 ) ) )
return V_139 ;
if ( ! ( V_492 & ( 1 << V_142 ) ) )
return V_142 ;
F_44 ( L_6 ) ;
return V_145 ;
} else if ( F_28 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_145 ;
else if ( F_20 ( V_9 ) )
return V_260 ;
else if ( F_30 ( V_9 ) )
return V_144 ;
else {
V_299 = F_93 ( V_2 ) ;
if ( V_299 != V_145 )
return V_299 ;
}
} else {
V_299 = F_94 ( V_2 ) ;
if ( V_299 != V_145 )
return V_299 ;
}
V_492 = F_91 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_139 ) ) )
return V_139 ;
if ( ! ( V_492 & ( 1 << V_142 ) ) )
return V_142 ;
F_44 ( L_6 ) ;
return V_145 ;
} else {
return V_11 -> V_18 ;
}
}
void F_96 ( struct V_8 * V_9 )
{
if ( F_20 ( V_9 ) )
F_45 ( V_9 , V_9 -> clock . V_499 ) ;
else if ( F_28 ( V_9 ) ) {
struct V_149 V_150 ;
bool V_216 = F_51 ( V_9 , & V_150 ,
V_500 ,
V_9 -> clock . V_499 ) ;
if ( V_216 )
F_29 ( V_9 , V_86 , V_144 , - 1 , & V_150 ) ;
F_45 ( V_9 , V_9 -> clock . V_499 ) ;
if ( V_216 )
F_29 ( V_9 , V_85 , V_144 , - 1 , & V_150 ) ;
}
}
int F_97 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_314 , int V_315 , struct V_312 * V_479 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
bool V_501 = false ;
if ( V_35 -> V_42 &
( V_43 | V_502 ) )
V_501 = true ;
if ( ! V_11 -> V_187 )
return - V_341 ;
F_53 ( V_2 , V_5 ) ;
if ( F_28 ( V_9 ) )
F_25 ( V_2 , V_5 ) ;
else if ( F_8 ( V_9 ) ) {
if ( V_501 )
F_26 ( V_2 , V_5 ) ;
else
F_25 ( V_2 , V_5 ) ;
} else {
F_26 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_25 ( V_2 , V_5 ) ;
F_90 ( V_2 ) ;
}
F_87 ( V_2 , V_314 , V_315 , V_479 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
F_98 ( V_2 ) ;
V_11 -> V_503 = * V_5 ;
return 0 ;
}
static bool F_99 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_184 * V_36 ;
F_92 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_36 -> V_2 == V_2 ) {
V_11 -> V_36 = V_36 ;
V_11 -> V_186 = F_32 ( V_36 ) ;
break;
}
}
if ( ( V_11 -> V_36 == NULL ) || ( V_11 -> V_186 == NULL ) ) {
V_11 -> V_36 = NULL ;
V_11 -> V_186 = NULL ;
return false ;
}
if ( V_11 -> V_36 ) {
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
V_11 -> V_504 = V_35 -> V_504 ;
}
if ( ! F_100 ( V_2 , V_4 , V_5 ) )
return false ;
if ( ! F_48 ( V_2 , V_5 ) )
return false ;
V_11 -> V_137 = F_95 ( V_2 ) ;
if ( ( V_11 -> V_137 == V_145 ) &&
! F_42 ( F_33 ( V_11 -> V_36 ) ) )
return false ;
return true ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_86 ) ;
F_10 ( V_2 , V_85 ) ;
F_18 ( V_2 , V_89 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_83 ) ;
F_10 ( V_2 , V_86 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_149 V_150 ;
int V_151 ;
F_18 ( V_2 , V_89 ) ;
if ( V_2 -> V_339 -> V_313 ) {
int V_337 ;
struct V_317 * V_318 ;
struct V_322 * V_323 ;
V_318 = F_59 ( V_2 -> V_339 -> V_313 ) ;
V_323 = F_60 ( V_318 -> V_321 ) ;
V_337 = F_61 ( V_323 , false ) ;
if ( F_62 ( V_337 ) )
F_44 ( L_7 ) ;
else {
F_84 ( V_323 ) ;
F_65 ( V_323 ) ;
}
}
if ( F_28 ( V_9 ) )
F_16 ( V_428 + V_11 -> V_409 , 0 ) ;
else if ( F_8 ( V_9 ) )
F_16 ( V_472 + V_11 -> V_409 , 0 ) ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_85 ) ;
for ( V_151 = 0 ; V_151 < V_9 -> V_156 ; V_151 ++ ) {
if ( V_9 -> V_31 . V_157 [ V_151 ] &&
V_9 -> V_31 . V_157 [ V_151 ] -> V_84 &&
V_151 != V_11 -> V_18 &&
V_11 -> V_137 == V_9 -> V_31 . V_157 [ V_151 ] -> V_137 ) {
goto V_505;
}
}
switch ( V_11 -> V_137 ) {
case V_139 :
case V_142 :
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_137 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_150 ) ;
break;
case V_260 :
if ( ( V_9 -> V_69 == V_506 ) ||
( V_9 -> V_69 == V_507 ) ||
( V_9 -> V_69 == V_373 ) ||
( V_9 -> V_69 == V_508 ) )
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_137 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_150 ) ;
break;
default:
break;
}
V_505:
V_11 -> V_137 = V_145 ;
V_11 -> V_187 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_186 = NULL ;
}
void F_104 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_409 = V_509 ;
break;
case 1 :
V_11 -> V_409 = V_510 ;
break;
case 2 :
V_11 -> V_409 = V_511 ;
break;
case 3 :
V_11 -> V_409 = V_512 ;
break;
case 4 :
V_11 -> V_409 = V_513 ;
break;
case 5 :
V_11 -> V_409 = V_514 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_409 =
V_515 - V_516 ;
else
V_11 -> V_409 = 0 ;
}
V_11 -> V_137 = V_145 ;
V_11 -> V_187 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_186 = NULL ;
F_105 ( & V_11 -> V_517 , & V_518 ) ;
}
