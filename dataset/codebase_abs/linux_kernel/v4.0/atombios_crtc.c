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
args . V_119 . V_120 = F_4 ( V_91 ) ;
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
int V_12 = F_3 ( V_13 , V_121 ) ;
T_8 V_91 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_122 = F_4 ( V_4 -> V_123 ) ;
args . V_124 = F_4 ( V_4 -> V_25 ) ;
args . V_125 = F_4 ( V_4 -> V_99 ) ;
args . V_100 =
F_4 ( V_4 -> V_101 - V_4 -> V_99 ) ;
args . V_126 = F_4 ( V_4 -> V_127 ) ;
args . V_128 = F_4 ( V_4 -> V_22 ) ;
args . V_129 = F_4 ( V_4 -> V_103 ) ;
args . V_104 =
F_4 ( V_4 -> V_105 - V_4 -> V_103 ) ;
args . V_130 = V_11 -> V_29 ;
args . V_131 = V_11 -> V_29 ;
args . V_132 = V_11 -> V_30 ;
args . V_133 = V_11 -> V_30 ;
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
args . V_119 . V_120 = F_4 ( V_91 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_27 ( struct V_8 * V_9 , int V_134 )
{
T_5 V_135 ;
if ( F_28 ( V_9 ) ) {
switch ( V_134 ) {
case V_136 :
V_135 = F_15 ( V_137 ) ;
V_135 &= ~ V_138 ;
F_16 ( V_137 , V_135 ) ;
break;
case V_139 :
V_135 = F_15 ( V_140 ) ;
V_135 &= ~ V_138 ;
F_16 ( V_140 , V_135 ) ;
break;
case V_141 :
case V_142 :
return;
}
} else if ( F_8 ( V_9 ) ) {
switch ( V_134 ) {
case V_136 :
V_135 = F_15 ( V_143 ) ;
V_135 &= ~ 1 ;
F_16 ( V_143 , V_135 ) ;
break;
case V_139 :
V_135 = F_15 ( V_144 ) ;
V_135 &= ~ 1 ;
F_16 ( V_144 , V_135 ) ;
break;
case V_141 :
case V_142 :
return;
}
}
}
static void F_29 ( struct V_8 * V_9 ,
int V_145 ,
int V_134 ,
int V_18 ,
struct V_146 * V_147 )
{
unsigned V_148 ;
int V_12 = F_3 ( V_13 , V_149 ) ;
union V_150 args ;
if ( V_145 ) {
if ( V_147 -> V_151 == 0 )
return;
if ( V_147 -> type & V_152 )
return;
} else {
for ( V_148 = 0 ; V_148 < V_9 -> V_153 ; V_148 ++ ) {
if ( V_9 -> V_31 . V_154 [ V_148 ] &&
V_9 -> V_31 . V_154 [ V_148 ] -> V_84 &&
V_148 != V_18 &&
V_134 == V_9 -> V_31 . V_154 [ V_148 ] -> V_134 ) {
return;
}
}
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_30 ( V_9 ) ) {
args . V_155 . V_156 = F_4 ( 0 ) ;
args . V_155 . V_157 = V_147 -> type & V_158 ;
switch ( V_134 ) {
case V_136 :
args . V_155 . V_157 |= V_159 ;
break;
case V_139 :
args . V_155 . V_157 |= V_160 ;
break;
case V_141 :
args . V_155 . V_157 |= V_161 ;
break;
case V_142 :
return;
}
args . V_155 . V_162 = F_4 ( V_147 -> V_163 ) ;
args . V_155 . V_164 = F_4 ( V_147 -> V_165 ) ;
args . V_155 . V_63 = V_145 ;
} else if ( F_28 ( V_9 ) ) {
args . V_166 . V_167 = F_4 ( V_147 -> V_151 ) ;
args . V_166 . V_157 = V_147 -> type & V_158 ;
switch ( V_134 ) {
case V_136 :
args . V_166 . V_157 |= V_168 ;
break;
case V_139 :
args . V_166 . V_157 |= V_169 ;
break;
case V_141 :
args . V_166 . V_157 |= V_170 ;
break;
case V_142 :
return;
}
args . V_166 . V_162 = F_4 ( V_147 -> V_163 ) ;
args . V_166 . V_164 = F_4 ( V_147 -> V_165 ) ;
args . V_166 . V_63 = V_145 ;
} else if ( F_19 ( V_9 ) ) {
args . V_171 . V_167 = F_4 ( V_147 -> V_151 ) ;
args . V_171 . V_157 = V_147 -> type & V_158 ;
args . V_171 . V_172 = V_147 -> V_165 ;
args . V_171 . V_173 = V_147 -> V_174 ;
args . V_171 . V_175 = V_147 -> V_176 ;
args . V_171 . V_177 = V_134 ;
args . V_171 . V_63 = V_145 ;
} else if ( F_8 ( V_9 ) ) {
if ( ( V_145 == V_86 ) || ( V_147 -> V_151 == 0 ) ||
( V_147 -> type & V_152 ) ) {
F_27 ( V_9 , V_134 ) ;
return;
}
args . V_178 . V_167 = F_4 ( V_147 -> V_151 ) ;
args . V_178 . V_157 = V_147 -> type & V_158 ;
args . V_178 . V_172 = V_147 -> V_165 ;
args . V_178 . V_173 = V_147 -> V_174 ;
args . V_178 . V_175 = V_147 -> V_176 ;
args . V_178 . V_63 = V_145 ;
} else {
if ( V_145 == V_86 ) {
F_27 ( V_9 , V_134 ) ;
return;
}
args . V_179 . V_167 = F_4 ( V_147 -> V_151 ) ;
args . V_179 . V_157 = V_147 -> type & V_158 ;
args . V_179 . V_180 = ( V_147 -> V_165 & 3 ) << 2 ;
args . V_179 . V_180 |= ( V_147 -> V_174 & 7 ) << 4 ;
args . V_179 . V_63 = V_145 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_5 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_181 * V_36 = V_11 -> V_36 ;
struct V_35 * V_35 = F_7 ( V_36 ) ;
struct V_182 * V_183 = F_32 ( V_36 ) ;
T_5 V_184 = V_4 -> clock ;
int V_185 = F_33 ( V_36 ) ;
T_5 V_186 = V_4 -> clock ;
T_5 clock = V_4 -> clock ;
int V_187 = V_11 -> V_187 ;
bool V_188 = F_34 ( V_36 , V_4 -> clock ) ;
V_11 -> V_189 = 0 ;
if ( F_8 ( V_9 ) ) {
if ( ( V_9 -> V_69 == V_190 ) ||
( V_9 -> V_69 == V_191 ) ||
( V_9 -> V_69 == V_192 ) )
V_11 -> V_189 |= (
V_193 ) ;
if ( F_35 ( V_9 ) && V_4 -> clock > 200000 )
V_11 -> V_189 |= V_194 ;
else
V_11 -> V_189 |= V_195 ;
if ( V_9 -> V_69 < V_196 )
V_11 -> V_189 |= V_197 ;
if ( F_36 ( V_9 ) || F_37 ( V_9 ) || F_14 ( V_9 ) )
V_11 -> V_189 |= V_198 ;
if ( ( V_9 -> V_69 == V_199 ) || ( V_9 -> V_69 == V_200 ) )
V_11 -> V_189 |= V_198 ;
if ( F_35 ( V_9 ) && V_4 -> clock > 165000 )
V_11 -> V_189 |= V_198 ;
} else {
V_11 -> V_189 |= V_201 ;
if ( V_4 -> clock > 200000 )
V_11 -> V_189 |= V_194 ;
else
V_11 -> V_189 |= V_195 ;
}
if ( ( V_35 -> V_202 & ( V_203 | V_204 ) ) ||
( F_38 ( V_36 ) != V_205 ) ) {
if ( V_183 ) {
struct V_206 * V_206 = F_39 ( V_183 ) ;
struct V_207 * V_208 =
V_206 -> V_209 ;
V_186 = V_208 -> V_186 ;
}
}
if ( V_35 -> V_202 & ( V_203 ) ) {
if ( V_11 -> V_210 ) {
if ( V_11 -> V_147 . V_211 ) {
V_11 -> V_189 |= V_212 ;
V_11 -> V_213 = V_11 -> V_147 . V_211 ;
if ( F_8 ( V_9 ) )
V_11 -> V_189 |= V_198 ;
}
}
}
if ( F_8 ( V_9 ) ) {
if ( V_35 -> V_214 == V_215 )
V_184 = V_4 -> clock * 2 ;
if ( V_35 -> V_42 & ( V_43 ) )
V_11 -> V_189 |= V_193 ;
if ( V_35 -> V_202 & ( V_203 ) )
V_11 -> V_189 |= V_216 ;
} else {
if ( V_36 -> V_217 != V_218 )
V_11 -> V_189 |= V_219 ;
if ( V_36 -> V_217 == V_220 )
V_11 -> V_189 |= V_212 ;
}
if ( V_185 == V_221 ) {
switch ( V_187 ) {
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
union V_222 args ;
T_10 V_223 , V_224 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_225 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_223 ,
& V_224 ) )
return V_184 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_223 ) {
case 1 :
switch ( V_224 ) {
case 1 :
case 2 :
args . V_171 . V_226 = F_4 ( clock / 10 ) ;
args . V_171 . V_227 = V_35 -> V_214 ;
args . V_171 . V_228 = V_185 ;
if ( V_11 -> V_210 && V_11 -> V_147 . V_151 )
args . V_171 . V_229 |=
V_230 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_184 = F_41 ( args . V_171 . V_226 ) * 10 ;
break;
case 3 :
args . V_155 . V_231 . V_226 = F_4 ( clock / 10 ) ;
args . V_155 . V_231 . V_227 = V_35 -> V_214 ;
args . V_155 . V_231 . V_228 = V_185 ;
args . V_155 . V_231 . V_232 = 0 ;
if ( V_11 -> V_210 && V_11 -> V_147 . V_151 )
args . V_155 . V_231 . V_232 |=
V_233 ;
if ( F_42 ( V_185 ) ) {
args . V_155 . V_231 . V_232 |=
V_234 ;
args . V_155 . V_231 . V_226 = F_4 ( V_186 / 10 ) ;
} else if ( V_35 -> V_202 & ( V_204 ) ) {
struct V_235 * V_236 = V_35 -> V_46 ;
if ( V_236 -> V_237 )
args . V_155 . V_231 . V_232 |=
V_234 ;
if ( V_188 )
args . V_155 . V_231 . V_232 |=
V_238 ;
}
if ( F_38 ( V_36 ) !=
V_205 )
args . V_155 . V_231 . V_239 =
F_38 ( V_36 ) ;
else
args . V_155 . V_231 . V_239 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_184 = F_43 ( args . V_155 . V_240 . V_241 ) * 10 ;
if ( args . V_155 . V_240 . V_242 ) {
V_11 -> V_189 |= V_198 ;
V_11 -> V_189 |= V_212 ;
V_11 -> V_213 = args . V_155 . V_240 . V_242 ;
}
if ( args . V_155 . V_240 . V_243 ) {
V_11 -> V_189 |= V_198 ;
V_11 -> V_189 |= V_244 ;
V_11 -> V_245 = args . V_155 . V_240 . V_243 ;
}
break;
default:
F_44 ( L_1 , V_223 , V_224 ) ;
return V_184 ;
}
break;
default:
F_44 ( L_1 , V_223 , V_224 ) ;
return V_184 ;
}
}
return V_184 ;
}
static void F_45 ( struct V_8 * V_9 ,
T_5 V_246 )
{
T_10 V_223 , V_224 ;
int V_12 ;
union V_247 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_248 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_223 ,
& V_224 ) )
return;
switch ( V_223 ) {
case 1 :
switch ( V_224 ) {
case 5 :
args . V_249 . V_17 = V_250 ;
args . V_249 . V_226 = F_4 ( V_246 ) ;
args . V_249 . V_177 = V_141 ;
break;
case 6 :
args . V_251 . V_252 = F_46 ( V_246 ) ;
if ( F_37 ( V_9 ) || F_14 ( V_9 ) )
args . V_251 . V_177 = V_253 ;
else if ( F_20 ( V_9 ) )
args . V_251 . V_177 = V_254 ;
else
args . V_251 . V_177 = V_141 ;
break;
default:
F_44 ( L_1 , V_223 , V_224 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_223 , V_224 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_5 V_18 ,
int V_134 ,
T_5 V_185 ,
T_5 V_214 ,
T_5 clock ,
T_5 V_255 ,
T_5 V_256 ,
T_5 V_257 ,
T_5 V_258 ,
int V_187 ,
bool V_210 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_10 V_223 , V_224 ;
int V_12 = F_3 ( V_13 , V_248 ) ;
union V_247 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_223 ,
& V_224 ) )
return;
switch ( V_223 ) {
case 1 :
switch ( V_224 ) {
case 1 :
if ( clock == V_86 )
return;
args . V_171 . V_226 = F_4 ( clock / 10 ) ;
args . V_171 . V_259 = F_4 ( V_255 ) ;
args . V_171 . V_260 = F_4 ( V_256 ) ;
args . V_171 . V_261 = V_257 ;
args . V_171 . V_243 = V_258 ;
args . V_171 . V_177 = V_134 ;
args . V_171 . V_17 = V_18 ;
args . V_171 . V_262 = 1 ;
break;
case 2 :
args . V_166 . V_226 = F_4 ( clock / 10 ) ;
args . V_166 . V_259 = F_4 ( V_255 ) ;
args . V_166 . V_260 = F_4 ( V_256 ) ;
args . V_166 . V_261 = V_257 ;
args . V_166 . V_243 = V_258 ;
args . V_166 . V_177 = V_134 ;
args . V_166 . V_17 = V_18 ;
args . V_166 . V_262 = 1 ;
break;
case 3 :
args . V_155 . V_226 = F_4 ( clock / 10 ) ;
args . V_155 . V_259 = F_4 ( V_255 ) ;
args . V_155 . V_260 = F_4 ( V_256 ) ;
args . V_155 . V_261 = V_257 ;
args . V_155 . V_243 = V_258 ;
args . V_155 . V_177 = V_134 ;
if ( V_18 == V_263 )
args . V_155 . V_264 = V_265 ;
else
args . V_155 . V_264 = V_266 ;
if ( V_210 && ( V_147 -> type & V_152 ) )
args . V_155 . V_264 |= V_267 ;
args . V_155 . V_268 = V_214 ;
args . V_155 . V_269 = V_185 ;
break;
case 5 :
args . V_249 . V_17 = V_18 ;
args . V_249 . V_226 = F_4 ( clock / 10 ) ;
args . V_249 . V_242 = V_255 ;
args . V_249 . V_260 = F_4 ( V_256 ) ;
args . V_249 . V_270 = F_46 ( V_257 * 100000 ) ;
args . V_249 . V_243 = V_258 ;
args . V_249 . V_264 = 0 ;
if ( V_210 && ( V_147 -> type & V_152 ) )
args . V_249 . V_264 |= V_271 ;
if ( V_185 == V_221 ) {
switch ( V_187 ) {
case 8 :
default:
args . V_249 . V_264 |= V_272 ;
break;
case 10 :
args . V_249 . V_264 |= V_273 ;
break;
case 12 :
args . V_249 . V_264 |= V_274 ;
break;
}
}
args . V_249 . V_227 = V_214 ;
args . V_249 . V_269 = V_185 ;
args . V_249 . V_177 = V_134 ;
break;
case 6 :
args . V_251 . V_252 = F_46 ( V_18 << 24 | clock / 10 ) ;
args . V_251 . V_242 = V_255 ;
args . V_251 . V_260 = F_4 ( V_256 ) ;
args . V_251 . V_270 = F_46 ( V_257 * 100000 ) ;
args . V_251 . V_243 = V_258 ;
args . V_251 . V_264 = 0 ;
if ( V_210 && ( V_147 -> type & V_152 ) )
args . V_251 . V_264 |= V_275 ;
if ( V_185 == V_221 ) {
switch ( V_187 ) {
case 8 :
default:
args . V_251 . V_264 |= V_276 ;
break;
case 10 :
args . V_251 . V_264 |= V_277 ;
break;
case 12 :
args . V_251 . V_264 |= V_278 ;
break;
case 16 :
args . V_251 . V_264 |= V_279 ;
break;
}
}
args . V_251 . V_227 = V_214 ;
args . V_251 . V_269 = V_185 ;
args . V_251 . V_177 = V_134 ;
break;
default:
F_44 ( L_1 , V_223 , V_224 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_223 , V_224 ) ;
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
int V_185 = F_33 ( V_11 -> V_36 ) ;
V_11 -> V_187 = 8 ;
V_11 -> V_210 = false ;
if ( ( V_35 -> V_42 & ( V_203 | V_204 ) ) ||
( F_38 ( V_11 -> V_36 ) != V_205 ) ) {
struct V_235 * V_236 = V_35 -> V_46 ;
struct V_182 * V_183 =
F_32 ( V_11 -> V_36 ) ;
struct V_206 * V_206 =
F_39 ( V_183 ) ;
struct V_207 * V_208 =
V_206 -> V_209 ;
int V_186 ;
V_206 -> V_280 = V_4 -> clock ;
V_11 -> V_187 = F_49 ( V_183 ) ;
switch ( V_185 ) {
case V_281 :
case V_282 :
V_186 = V_208 -> V_186 / 10 ;
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 , & V_11 -> V_147 ,
V_283 ,
V_186 ) ;
else {
if ( V_186 == 16200 ) {
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_284 ) ;
if ( ! V_11 -> V_210 )
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_285 ) ;
} else {
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_285 ) ;
}
V_11 -> V_210 = false ;
}
break;
case V_286 :
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 ,
& V_11 -> V_147 ,
V_236 -> V_287 ,
V_4 -> clock / 10 ) ;
else
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_236 -> V_287 ) ;
break;
case V_288 :
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 ,
& V_11 -> V_147 ,
V_289 ,
V_4 -> clock / 10 ) ;
break;
case V_221 :
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 ,
& V_11 -> V_147 ,
V_290 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_11 -> V_184 = F_31 ( V_2 , V_4 ) ;
return true ;
}
static void F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_5 V_291 = V_4 -> clock ;
T_5 clock = V_4 -> clock ;
T_5 V_255 = 0 , V_256 = 0 , V_257 = 0 , V_258 = 0 ;
struct V_292 * V_293 ;
int V_185 = F_33 ( V_11 -> V_36 ) ;
if ( F_30 ( V_9 ) &&
( V_185 == V_221 ) &&
( V_11 -> V_187 > 8 ) )
clock = V_11 -> V_184 ;
switch ( V_11 -> V_134 ) {
case V_136 :
V_293 = & V_9 -> clock . V_294 ;
break;
case V_139 :
V_293 = & V_9 -> clock . V_295 ;
break;
case V_141 :
case V_142 :
default:
V_293 = & V_9 -> clock . V_296 ;
break;
}
V_293 -> V_108 = V_11 -> V_189 ;
V_293 -> V_297 = V_11 -> V_213 ;
V_293 -> V_258 = V_11 -> V_245 ;
if ( V_35 -> V_42 & ( V_43 ) )
F_53 ( V_293 , V_11 -> V_184 , & V_291 ,
& V_256 , & V_257 , & V_255 , & V_258 ) ;
else if ( F_8 ( V_9 ) )
F_54 ( V_293 , V_11 -> V_184 , & V_291 ,
& V_256 , & V_257 , & V_255 , & V_258 ) ;
else
F_53 ( V_293 , V_11 -> V_184 , & V_291 ,
& V_256 , & V_257 , & V_255 , & V_258 ) ;
F_29 ( V_9 , V_86 , V_11 -> V_134 ,
V_11 -> V_18 , & V_11 -> V_147 ) ;
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
V_185 , V_35 -> V_214 , clock ,
V_255 , V_256 , V_257 , V_258 ,
V_11 -> V_187 , V_11 -> V_210 , & V_11 -> V_147 ) ;
if ( V_11 -> V_210 ) {
if ( F_28 ( V_9 ) ) {
T_5 V_298 ;
T_5 V_163 = ( ( ( V_256 * 10 ) + V_257 ) *
( T_5 ) V_11 -> V_147 . V_151 ) /
( 100 * ( T_5 ) V_11 -> V_147 . V_299 ) ;
V_11 -> V_147 . V_163 = ( V_163 / 10 ) & V_300 ;
V_11 -> V_147 . V_163 |= ( ( V_163 - ( V_163 / 10 ) ) << V_301 ) &
V_302 ;
if ( V_11 -> V_147 . type & V_303 )
V_298 = ( 4 * V_163 * V_255 * ( ( T_5 ) V_11 -> V_147 . V_304 * 2048 ) ) /
( 125 * 25 * V_293 -> V_305 / 100 ) ;
else
V_298 = ( 2 * V_163 * V_255 * ( ( T_5 ) V_11 -> V_147 . V_304 * 2048 ) ) /
( 125 * 25 * V_293 -> V_305 / 100 ) ;
V_11 -> V_147 . V_165 = V_298 ;
}
F_29 ( V_9 , V_85 , V_11 -> V_134 ,
V_11 -> V_18 , & V_11 -> V_147 ) ;
}
}
static int F_55 ( struct V_1 * V_2 ,
struct V_306 * V_307 ,
int V_308 , int V_309 , int V_310 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_311 * V_312 ;
struct V_306 * V_313 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
T_11 V_318 ;
V_33 V_319 , V_320 , V_321 ;
unsigned V_322 , V_323 , V_324 , V_325 ;
T_5 V_326 = F_56 ( V_327 ) ;
T_5 V_328 , V_329 , V_330 ;
int V_331 ;
bool V_332 = false ;
if ( ! V_310 && ! V_2 -> V_333 -> V_307 ) {
F_57 ( L_2 ) ;
return 0 ;
}
if ( V_310 ) {
V_312 = F_58 ( V_307 ) ;
V_313 = V_307 ;
}
else {
V_312 = F_58 ( V_2 -> V_333 -> V_307 ) ;
V_313 = V_2 -> V_333 -> V_307 ;
}
V_315 = V_312 -> V_315 ;
V_317 = F_59 ( V_315 ) ;
V_331 = F_60 ( V_317 , false ) ;
if ( F_61 ( V_331 != 0 ) )
return V_331 ;
if ( V_310 )
V_318 = F_62 ( V_317 ) ;
else {
V_331 = F_63 ( V_317 , V_334 , & V_318 ) ;
if ( F_61 ( V_331 != 0 ) ) {
F_64 ( V_317 ) ;
return - V_335 ;
}
}
F_65 ( V_317 , & V_321 , NULL ) ;
F_64 ( V_317 ) ;
switch ( V_313 -> V_336 ) {
case V_337 :
V_319 = ( F_66 ( V_338 ) |
F_67 ( V_339 ) ) ;
break;
case V_340 :
case V_341 :
V_319 = ( F_66 ( V_342 ) |
F_67 ( V_343 ) ) ;
#ifdef F_68
V_326 = F_56 ( V_344 ) ;
#endif
break;
case V_345 :
case V_346 :
V_319 = ( F_66 ( V_342 ) |
F_67 ( V_347 ) ) ;
#ifdef F_68
V_326 = F_56 ( V_344 ) ;
#endif
break;
case V_348 :
case V_349 :
V_319 = ( F_66 ( V_342 ) |
F_67 ( V_350 ) ) ;
#ifdef F_68
V_326 = F_56 ( V_344 ) ;
#endif
break;
case V_351 :
V_319 = ( F_66 ( V_342 ) |
F_67 ( V_352 ) ) ;
#ifdef F_68
V_326 = F_56 ( V_344 ) ;
#endif
break;
case V_353 :
case V_354 :
V_319 = ( F_66 ( V_355 ) |
F_67 ( V_356 ) ) ;
#ifdef F_68
V_326 = F_56 ( V_357 ) ;
#endif
break;
case V_358 :
case V_359 :
V_319 = ( F_66 ( V_355 ) |
F_67 ( V_360 ) ) ;
#ifdef F_68
V_326 = F_56 ( V_357 ) ;
#endif
V_332 = true ;
break;
case V_361 :
case V_362 :
V_319 = ( F_66 ( V_355 ) |
F_67 ( V_363 ) ) ;
#ifdef F_68
V_326 = F_56 ( V_357 ) ;
#endif
V_332 = true ;
break;
default:
F_44 ( L_3 ,
F_69 ( V_313 -> V_336 ) ) ;
return - V_335 ;
}
if ( V_321 & V_364 ) {
F_70 ( V_321 , & V_322 , & V_323 , & V_324 , & V_325 ) ;
if ( V_9 -> V_69 >= V_365 ) {
unsigned V_12 , V_366 ;
if ( V_9 -> V_69 >= V_367 ) {
unsigned V_368 , V_369 ;
V_369 = 64 << V_325 ;
V_368 = 8 * 8 * V_313 -> V_370 / 8 ;
V_368 = F_71 ( V_369 , V_368 ) ;
for ( V_12 = 0 ; V_368 > 64 ; V_12 ++ )
V_368 >>= 1 ;
if ( V_12 >= 16 ) {
F_44 ( L_4 ,
V_313 -> V_370 , V_325 ) ;
return - V_335 ;
}
V_366 = ( V_9 -> V_371 . V_372 . V_373 [ V_12 ] >> 6 ) & 0x3 ;
} else {
switch ( V_313 -> V_370 ) {
case 8 :
V_12 = 10 ;
break;
case 16 :
V_12 = V_374 ;
break;
default:
case 32 :
V_12 = V_375 ;
break;
}
V_366 = ( V_9 -> V_371 . V_376 . V_377 [ V_12 ] >> 20 ) & 0x3 ;
}
V_319 |= F_72 ( V_366 ) ;
} else {
if ( V_9 -> V_69 >= V_378 )
V_328 = V_9 -> V_371 . V_379 . V_380 ;
else
V_328 = V_9 -> V_371 . V_381 . V_380 ;
switch ( ( V_328 & 0xf0 ) >> 4 ) {
case 0 :
V_319 |= F_72 ( V_382 ) ;
break;
case 1 :
default:
V_319 |= F_72 ( V_383 ) ;
break;
case 2 :
V_319 |= F_72 ( V_384 ) ;
break;
}
}
V_319 |= F_73 ( V_385 ) ;
V_319 |= F_74 ( V_325 ) ;
V_319 |= F_75 ( V_322 ) ;
V_319 |= F_76 ( V_323 ) ;
V_319 |= F_77 ( V_324 ) ;
if ( V_9 -> V_69 >= V_367 ) {
V_319 |= F_78 ( V_386 ) ;
}
} else if ( V_321 & V_387 )
V_319 |= F_73 ( V_388 ) ;
if ( V_9 -> V_69 >= V_367 ) {
T_5 V_389 = ( V_9 -> V_371 . V_372 . V_377 [ 10 ] >> 6 ) & 0x1f ;
V_319 |= F_79 ( V_389 ) ;
} else if ( ( V_9 -> V_69 == V_365 ) ||
( V_9 -> V_69 == V_390 ) )
V_319 |= F_80 ( V_391 ) ;
else if ( ( V_9 -> V_69 == V_392 ) ||
( V_9 -> V_69 == V_393 ) ||
( V_9 -> V_69 == V_394 ) )
V_319 |= F_80 ( V_395 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_16 ( V_396 , 0 ) ;
break;
case 1 :
F_16 ( V_397 , 0 ) ;
break;
case 2 :
F_16 ( V_398 , 0 ) ;
break;
case 3 :
F_16 ( V_399 , 0 ) ;
break;
case 4 :
F_16 ( V_400 , 0 ) ;
break;
case 5 :
F_16 ( V_401 , 0 ) ;
break;
default:
break;
}
F_16 ( V_402 + V_11 -> V_403 ,
F_81 ( V_318 ) ) ;
F_16 ( V_404 + V_11 -> V_403 ,
F_81 ( V_318 ) ) ;
F_16 ( V_405 + V_11 -> V_403 ,
( T_5 ) V_318 & V_406 ) ;
F_16 ( V_407 + V_11 -> V_403 ,
( T_5 ) V_318 & V_406 ) ;
F_16 ( V_408 + V_11 -> V_403 , V_319 ) ;
F_16 ( V_409 + V_11 -> V_403 , V_326 ) ;
F_82 ( V_410 + V_11 -> V_403 ,
( V_332 ? V_411 : 0 ) ,
~ V_411 ) ;
if ( V_332 )
F_57 ( L_5 ) ;
F_16 ( V_412 + V_11 -> V_403 , 0 ) ;
F_16 ( V_413 + V_11 -> V_403 , 0 ) ;
F_16 ( V_414 + V_11 -> V_403 , 0 ) ;
F_16 ( V_415 + V_11 -> V_403 , 0 ) ;
F_16 ( V_416 + V_11 -> V_403 , V_313 -> V_417 ) ;
F_16 ( V_418 + V_11 -> V_403 , V_313 -> V_419 ) ;
V_320 = V_313 -> V_420 [ 0 ] / ( V_313 -> V_370 / 8 ) ;
F_16 ( V_421 + V_11 -> V_403 , V_320 ) ;
F_16 ( V_422 + V_11 -> V_403 , 1 ) ;
if ( V_9 -> V_69 >= V_367 )
F_16 ( V_423 + V_11 -> V_403 ,
V_313 -> V_419 ) ;
else
F_16 ( V_424 + V_11 -> V_403 ,
V_313 -> V_419 ) ;
V_308 &= ~ 3 ;
V_309 &= ~ 1 ;
F_16 ( V_425 + V_11 -> V_403 ,
( V_308 << 16 ) | V_309 ) ;
V_329 = V_2 -> V_4 . V_426 ;
V_330 = ( V_2 -> V_4 . V_427 + 1 ) & ~ 1 ;
if ( ( V_9 -> V_69 >= V_367 ) &&
( V_2 -> V_4 . V_108 & V_115 ) )
V_330 *= 2 ;
F_16 ( V_428 + V_11 -> V_403 ,
( V_329 << 16 ) | V_330 ) ;
V_328 = F_15 ( V_429 + V_11 -> V_403 ) ;
V_328 &= ~ V_430 ;
F_16 ( V_429 + V_11 -> V_403 , V_328 ) ;
F_16 ( V_431 + V_11 -> V_403 , 3 ) ;
if ( ! V_310 && V_307 && V_307 != V_2 -> V_333 -> V_307 ) {
V_312 = F_58 ( V_307 ) ;
V_317 = F_59 ( V_312 -> V_315 ) ;
V_331 = F_60 ( V_317 , false ) ;
if ( F_61 ( V_331 != 0 ) )
return V_331 ;
F_83 ( V_317 ) ;
F_64 ( V_317 ) ;
}
F_84 ( V_9 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_306 * V_307 ,
int V_308 , int V_309 , int V_310 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_311 * V_312 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
struct V_306 * V_313 ;
T_11 V_318 ;
V_33 V_319 , V_320 , V_321 ;
T_5 V_326 = V_432 ;
T_5 V_328 , V_329 , V_330 ;
int V_331 ;
bool V_332 = false ;
if ( ! V_310 && ! V_2 -> V_333 -> V_307 ) {
F_57 ( L_2 ) ;
return 0 ;
}
if ( V_310 ) {
V_312 = F_58 ( V_307 ) ;
V_313 = V_307 ;
}
else {
V_312 = F_58 ( V_2 -> V_333 -> V_307 ) ;
V_313 = V_2 -> V_333 -> V_307 ;
}
V_315 = V_312 -> V_315 ;
V_317 = F_59 ( V_315 ) ;
V_331 = F_60 ( V_317 , false ) ;
if ( F_61 ( V_331 != 0 ) )
return V_331 ;
if ( V_310 )
V_318 = F_62 ( V_317 ) ;
else {
V_331 = F_63 ( V_317 , V_334 , & V_318 ) ;
if ( F_61 ( V_331 != 0 ) ) {
F_64 ( V_317 ) ;
return - V_335 ;
}
}
F_65 ( V_317 , & V_321 , NULL ) ;
F_64 ( V_317 ) ;
switch ( V_313 -> V_336 ) {
case V_337 :
V_319 =
V_433 |
V_434 ;
break;
case V_340 :
case V_341 :
V_319 =
V_435 |
V_436 ;
#ifdef F_68
V_326 = V_437 ;
#endif
break;
case V_345 :
V_319 =
V_435 |
V_438 ;
#ifdef F_68
V_326 = V_437 ;
#endif
break;
case V_351 :
V_319 =
V_435 |
V_439 ;
#ifdef F_68
V_326 = V_437 ;
#endif
break;
case V_353 :
case V_354 :
V_319 =
V_440 |
V_441 ;
#ifdef F_68
V_326 = V_442 ;
#endif
break;
case V_358 :
case V_359 :
V_319 =
V_440 |
V_443 ;
#ifdef F_68
V_326 = V_442 ;
#endif
V_332 = true ;
break;
default:
F_44 ( L_3 ,
F_69 ( V_313 -> V_336 ) ) ;
return - V_335 ;
}
if ( V_9 -> V_69 >= V_444 ) {
if ( V_321 & V_364 )
V_319 |= V_445 ;
else if ( V_321 & V_387 )
V_319 |= V_446 ;
} else {
if ( V_321 & V_364 )
V_319 |= V_447 ;
if ( V_321 & V_387 )
V_319 |= V_448 ;
}
if ( V_11 -> V_18 == 0 )
F_16 ( V_396 , 0 ) ;
else
F_16 ( V_397 , 0 ) ;
if ( V_9 -> V_69 >= V_196 ) {
if ( V_11 -> V_18 ) {
F_16 ( V_449 , F_81 ( V_318 ) ) ;
F_16 ( V_450 , F_81 ( V_318 ) ) ;
} else {
F_16 ( V_451 , F_81 ( V_318 ) ) ;
F_16 ( V_452 , F_81 ( V_318 ) ) ;
}
}
F_16 ( V_453 + V_11 -> V_403 ,
( T_5 ) V_318 ) ;
F_16 ( V_454 +
V_11 -> V_403 , ( T_5 ) V_318 ) ;
F_16 ( V_455 + V_11 -> V_403 , V_319 ) ;
if ( V_9 -> V_69 >= V_444 )
F_16 ( V_456 + V_11 -> V_403 , V_326 ) ;
F_82 ( V_457 + V_11 -> V_403 ,
( V_332 ? V_458 : 0 ) , ~ V_458 ) ;
if ( V_332 )
F_57 ( L_5 ) ;
F_16 ( V_459 + V_11 -> V_403 , 0 ) ;
F_16 ( V_460 + V_11 -> V_403 , 0 ) ;
F_16 ( V_461 + V_11 -> V_403 , 0 ) ;
F_16 ( V_462 + V_11 -> V_403 , 0 ) ;
F_16 ( V_463 + V_11 -> V_403 , V_313 -> V_417 ) ;
F_16 ( V_464 + V_11 -> V_403 , V_313 -> V_419 ) ;
V_320 = V_313 -> V_420 [ 0 ] / ( V_313 -> V_370 / 8 ) ;
F_16 ( V_465 + V_11 -> V_403 , V_320 ) ;
F_16 ( V_466 + V_11 -> V_403 , 1 ) ;
F_16 ( V_467 + V_11 -> V_403 ,
V_313 -> V_419 ) ;
V_308 &= ~ 3 ;
V_309 &= ~ 1 ;
F_16 ( V_468 + V_11 -> V_403 ,
( V_308 << 16 ) | V_309 ) ;
V_329 = V_2 -> V_4 . V_426 ;
V_330 = ( V_2 -> V_4 . V_427 + 1 ) & ~ 1 ;
F_16 ( V_469 + V_11 -> V_403 ,
( V_329 << 16 ) | V_330 ) ;
V_328 = F_15 ( V_470 + V_11 -> V_403 ) ;
V_328 &= ~ V_471 ;
F_16 ( V_470 + V_11 -> V_403 , V_328 ) ;
F_16 ( V_472 + V_11 -> V_403 , 3 ) ;
if ( ! V_310 && V_307 && V_307 != V_2 -> V_333 -> V_307 ) {
V_312 = F_58 ( V_307 ) ;
V_317 = F_59 ( V_312 -> V_315 ) ;
V_331 = F_60 ( V_317 , false ) ;
if ( F_61 ( V_331 != 0 ) )
return V_331 ;
F_83 ( V_317 ) ;
F_64 ( V_317 ) ;
}
F_84 ( V_9 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , int V_308 , int V_309 ,
struct V_306 * V_473 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_55 ( V_2 , V_473 , V_308 , V_309 , 0 ) ;
else if ( F_8 ( V_9 ) )
return F_85 ( V_2 , V_473 , V_308 , V_309 , 0 ) ;
else
return F_87 ( V_2 , V_473 , V_308 , V_309 , 0 ) ;
}
int F_88 ( struct V_1 * V_2 ,
struct V_306 * V_307 ,
int V_308 , int V_309 , enum V_474 V_74 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_55 ( V_2 , V_307 , V_308 , V_309 , 1 ) ;
else if ( F_8 ( V_9 ) )
return F_85 ( V_2 , V_307 , V_308 , V_309 , 1 ) ;
else
return F_87 ( V_2 , V_307 , V_308 , V_309 , 1 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_5 V_475 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_475 = F_15 ( V_476 ) ;
V_475 &= ~ V_477 ;
F_16 ( V_476 , V_475 ) ;
break;
case 1 :
V_475 = F_15 ( V_478 ) ;
V_475 &= ~ V_479 ;
F_16 ( V_478 , V_475 ) ;
F_16 ( V_480 , F_15 ( V_481 ) ) ;
F_16 ( V_482 , F_15 ( V_483 ) ) ;
break;
}
}
static T_5 F_90 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_484 ;
struct V_11 * V_485 ;
T_5 V_486 = 0 ;
F_91 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_484 )
continue;
V_485 = F_2 ( V_484 ) ;
if ( V_485 -> V_134 != V_142 )
V_486 |= ( 1 << V_485 -> V_134 ) ;
}
return V_486 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_484 ;
struct V_11 * V_485 ;
F_91 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_484 )
continue;
V_485 = F_2 ( V_484 ) ;
if ( V_485 -> V_36 &&
F_42 ( F_33 ( V_485 -> V_36 ) ) ) {
if ( V_485 -> V_134 != V_142 )
return V_485 -> V_134 ;
}
}
return V_142 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_484 ;
struct V_11 * V_485 ;
T_5 V_184 , V_487 ;
V_184 = V_11 -> V_184 ;
if ( V_184 == 0 )
return V_142 ;
F_91 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_484 )
continue;
V_485 = F_2 ( V_484 ) ;
if ( V_485 -> V_36 &&
! F_42 ( F_33 ( V_485 -> V_36 ) ) ) {
if ( V_485 -> V_183 == V_11 -> V_183 ) {
if ( V_485 -> V_134 != V_142 )
return V_485 -> V_134 ;
}
V_487 = V_485 -> V_184 ;
if ( ( V_2 -> V_4 . clock == V_484 -> V_4 . clock ) &&
( V_184 == V_487 ) &&
( V_11 -> V_210 == V_485 -> V_210 ) &&
( V_485 -> V_134 != V_142 ) )
return V_485 -> V_134 ;
}
}
return V_142 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_5 V_486 ;
int V_293 ;
if ( F_14 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_488 )
return V_142 ;
else {
V_293 = F_92 ( V_2 ) ;
if ( V_293 != V_142 )
return V_293 ;
}
} else {
V_293 = F_93 ( V_2 ) ;
if ( V_293 != V_142 )
return V_293 ;
}
if ( ( V_9 -> V_69 == V_489 ) ||
( V_9 -> V_69 == V_490 ) ) {
V_486 = F_90 ( V_2 ) ;
if ( ! ( V_486 & ( 1 << V_139 ) ) )
return V_139 ;
if ( ! ( V_486 & ( 1 << V_136 ) ) )
return V_136 ;
F_44 ( L_6 ) ;
return V_142 ;
} else {
V_486 = F_90 ( V_2 ) ;
if ( ! ( V_486 & ( 1 << V_139 ) ) )
return V_139 ;
if ( ! ( V_486 & ( 1 << V_136 ) ) )
return V_136 ;
if ( ! ( V_486 & ( 1 << V_254 ) ) )
return V_254 ;
F_44 ( L_6 ) ;
return V_142 ;
}
} else if ( F_37 ( V_9 ) ) {
struct V_235 * V_236 =
V_35 -> V_46 ;
if ( ( V_35 -> V_214 == V_491 ) &&
( V_236 -> V_492 == false ) )
return V_139 ;
else if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_488 )
return V_142 ;
else {
V_293 = F_92 ( V_2 ) ;
if ( V_293 != V_142 )
return V_293 ;
}
} else {
V_293 = F_93 ( V_2 ) ;
if ( V_293 != V_142 )
return V_293 ;
}
V_486 = F_90 ( V_2 ) ;
if ( ! ( V_486 & ( 1 << V_254 ) ) )
return V_254 ;
if ( ! ( V_486 & ( 1 << V_136 ) ) )
return V_136 ;
F_44 ( L_6 ) ;
return V_142 ;
} else if ( F_36 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_488 )
return V_142 ;
}
V_486 = F_90 ( V_2 ) ;
if ( ! ( V_486 & ( 1 << V_136 ) ) )
return V_136 ;
if ( ! ( V_486 & ( 1 << V_139 ) ) )
return V_139 ;
F_44 ( L_6 ) ;
return V_142 ;
} else if ( F_28 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_488 )
return V_142 ;
else if ( F_20 ( V_9 ) )
return V_254 ;
else if ( F_30 ( V_9 ) )
return V_141 ;
else {
V_293 = F_92 ( V_2 ) ;
if ( V_293 != V_142 )
return V_293 ;
}
} else {
V_293 = F_93 ( V_2 ) ;
if ( V_293 != V_142 )
return V_293 ;
}
V_486 = F_90 ( V_2 ) ;
if ( ! ( V_486 & ( 1 << V_136 ) ) )
return V_136 ;
if ( ! ( V_486 & ( 1 << V_139 ) ) )
return V_139 ;
F_44 ( L_6 ) ;
return V_142 ;
} else {
return V_11 -> V_18 ;
}
}
void F_95 ( struct V_8 * V_9 )
{
if ( F_20 ( V_9 ) )
F_45 ( V_9 , V_9 -> clock . V_493 ) ;
else if ( F_28 ( V_9 ) ) {
struct V_146 V_147 ;
bool V_210 = F_50 ( V_9 , & V_147 ,
V_494 ,
V_9 -> clock . V_493 ) ;
if ( V_210 )
F_29 ( V_9 , V_86 , V_141 , - 1 , & V_147 ) ;
F_45 ( V_9 , V_9 -> clock . V_493 ) ;
if ( V_210 )
F_29 ( V_9 , V_85 , V_141 , - 1 , & V_147 ) ;
}
}
int F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_308 , int V_309 , struct V_306 * V_473 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
bool V_495 = false ;
if ( V_35 -> V_42 &
( V_43 | V_496 ) )
V_495 = true ;
if ( ! V_11 -> V_184 )
return - V_335 ;
F_52 ( V_2 , V_5 ) ;
if ( F_28 ( V_9 ) )
F_25 ( V_2 , V_5 ) ;
else if ( F_8 ( V_9 ) ) {
if ( V_495 )
F_26 ( V_2 , V_5 ) ;
else
F_25 ( V_2 , V_5 ) ;
} else {
F_26 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_25 ( V_2 , V_5 ) ;
F_89 ( V_2 ) ;
}
F_86 ( V_2 , V_308 , V_309 , V_473 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
F_97 ( V_2 ) ;
V_11 -> V_497 = * V_5 ;
return 0 ;
}
static bool F_98 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_181 * V_36 ;
F_91 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_36 -> V_2 == V_2 ) {
V_11 -> V_36 = V_36 ;
V_11 -> V_183 = F_32 ( V_36 ) ;
break;
}
}
if ( ( V_11 -> V_36 == NULL ) || ( V_11 -> V_183 == NULL ) ) {
V_11 -> V_36 = NULL ;
V_11 -> V_183 = NULL ;
return false ;
}
if ( ! F_99 ( V_2 , V_4 , V_5 ) )
return false ;
if ( ! F_48 ( V_2 , V_5 ) )
return false ;
V_11 -> V_134 = F_94 ( V_2 ) ;
if ( ( V_11 -> V_134 == V_142 ) &&
! F_42 ( F_33 ( V_11 -> V_36 ) ) )
return false ;
return true ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_86 ) ;
F_10 ( V_2 , V_85 ) ;
F_18 ( V_2 , V_89 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_83 ) ;
F_10 ( V_2 , V_86 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_146 V_147 ;
int V_148 ;
F_18 ( V_2 , V_89 ) ;
if ( V_2 -> V_333 -> V_307 ) {
int V_331 ;
struct V_311 * V_312 ;
struct V_316 * V_317 ;
V_312 = F_58 ( V_2 -> V_333 -> V_307 ) ;
V_317 = F_59 ( V_312 -> V_315 ) ;
V_331 = F_60 ( V_317 , false ) ;
if ( F_61 ( V_331 ) )
F_44 ( L_7 ) ;
else {
F_83 ( V_317 ) ;
F_64 ( V_317 ) ;
}
}
if ( F_28 ( V_9 ) )
F_16 ( V_422 + V_11 -> V_403 , 0 ) ;
else if ( F_8 ( V_9 ) )
F_16 ( V_466 + V_11 -> V_403 , 0 ) ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_85 ) ;
for ( V_148 = 0 ; V_148 < V_9 -> V_153 ; V_148 ++ ) {
if ( V_9 -> V_31 . V_154 [ V_148 ] &&
V_9 -> V_31 . V_154 [ V_148 ] -> V_84 &&
V_148 != V_11 -> V_18 &&
V_11 -> V_134 == V_9 -> V_31 . V_154 [ V_148 ] -> V_134 ) {
goto V_498;
}
}
switch ( V_11 -> V_134 ) {
case V_136 :
case V_139 :
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_147 ) ;
break;
case V_254 :
if ( ( V_9 -> V_69 == V_499 ) ||
( V_9 -> V_69 == V_500 ) ||
( V_9 -> V_69 == V_367 ) ||
( V_9 -> V_69 == V_501 ) )
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_147 ) ;
break;
default:
break;
}
V_498:
V_11 -> V_134 = V_142 ;
V_11 -> V_184 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_183 = NULL ;
}
void F_103 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_403 = V_502 ;
break;
case 1 :
V_11 -> V_403 = V_503 ;
break;
case 2 :
V_11 -> V_403 = V_504 ;
break;
case 3 :
V_11 -> V_403 = V_505 ;
break;
case 4 :
V_11 -> V_403 = V_506 ;
break;
case 5 :
V_11 -> V_403 = V_507 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_403 =
V_508 - V_509 ;
else
V_11 -> V_403 = 0 ;
}
V_11 -> V_134 = V_142 ;
V_11 -> V_184 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_183 = NULL ;
F_104 ( & V_11 -> V_510 , & V_511 ) ;
}
