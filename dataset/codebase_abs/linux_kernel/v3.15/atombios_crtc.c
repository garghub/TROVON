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
if ( F_19 ( V_9 ) ) {
union V_221 args ;
T_10 V_222 , V_223 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_224 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_222 ,
& V_223 ) )
return V_184 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_222 ) {
case 1 :
switch ( V_223 ) {
case 1 :
case 2 :
args . V_171 . V_225 = F_4 ( V_4 -> clock / 10 ) ;
args . V_171 . V_226 = V_35 -> V_214 ;
args . V_171 . V_227 = V_185 ;
if ( V_11 -> V_210 && V_11 -> V_147 . V_151 )
args . V_171 . V_228 |=
V_229 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_184 = F_41 ( args . V_171 . V_225 ) * 10 ;
break;
case 3 :
args . V_155 . V_230 . V_225 = F_4 ( V_4 -> clock / 10 ) ;
args . V_155 . V_230 . V_226 = V_35 -> V_214 ;
args . V_155 . V_230 . V_227 = V_185 ;
args . V_155 . V_230 . V_231 = 0 ;
if ( V_11 -> V_210 && V_11 -> V_147 . V_151 )
args . V_155 . V_230 . V_231 |=
V_232 ;
if ( F_42 ( V_185 ) ) {
args . V_155 . V_230 . V_231 |=
V_233 ;
args . V_155 . V_230 . V_225 = F_4 ( V_186 / 10 ) ;
} else if ( V_35 -> V_202 & ( V_204 ) ) {
struct V_234 * V_235 = V_35 -> V_46 ;
if ( V_185 == V_236 )
args . V_155 . V_230 . V_225 =
F_4 ( ( V_4 -> clock * V_187 / 8 ) / 10 ) ;
if ( V_235 -> V_237 )
args . V_155 . V_230 . V_231 |=
V_233 ;
if ( V_188 )
args . V_155 . V_230 . V_231 |=
V_238 ;
}
if ( F_38 ( V_36 ) !=
V_205 )
args . V_155 . V_230 . V_239 =
F_38 ( V_36 ) ;
else
args . V_155 . V_230 . V_239 = 0 ;
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
F_44 ( L_1 , V_222 , V_223 ) ;
return V_184 ;
}
break;
default:
F_44 ( L_1 , V_222 , V_223 ) ;
return V_184 ;
}
}
return V_184 ;
}
static void F_45 ( struct V_8 * V_9 ,
T_5 V_246 )
{
T_10 V_222 , V_223 ;
int V_12 ;
union V_247 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_248 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_222 ,
& V_223 ) )
return;
switch ( V_222 ) {
case 1 :
switch ( V_223 ) {
case 5 :
args . V_249 . V_17 = V_250 ;
args . V_249 . V_225 = F_4 ( V_246 ) ;
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
F_44 ( L_1 , V_222 , V_223 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_222 , V_223 ) ;
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
T_10 V_222 , V_223 ;
int V_12 = F_3 ( V_13 , V_248 ) ;
union V_247 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_222 ,
& V_223 ) )
return;
switch ( V_222 ) {
case 1 :
switch ( V_223 ) {
case 1 :
if ( clock == V_86 )
return;
args . V_171 . V_225 = F_4 ( clock / 10 ) ;
args . V_171 . V_259 = F_4 ( V_255 ) ;
args . V_171 . V_260 = F_4 ( V_256 ) ;
args . V_171 . V_261 = V_257 ;
args . V_171 . V_243 = V_258 ;
args . V_171 . V_177 = V_134 ;
args . V_171 . V_17 = V_18 ;
args . V_171 . V_262 = 1 ;
break;
case 2 :
args . V_166 . V_225 = F_4 ( clock / 10 ) ;
args . V_166 . V_259 = F_4 ( V_255 ) ;
args . V_166 . V_260 = F_4 ( V_256 ) ;
args . V_166 . V_261 = V_257 ;
args . V_166 . V_243 = V_258 ;
args . V_166 . V_177 = V_134 ;
args . V_166 . V_17 = V_18 ;
args . V_166 . V_262 = 1 ;
break;
case 3 :
args . V_155 . V_225 = F_4 ( clock / 10 ) ;
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
args . V_249 . V_225 = F_4 ( clock / 10 ) ;
args . V_249 . V_242 = V_255 ;
args . V_249 . V_260 = F_4 ( V_256 ) ;
args . V_249 . V_270 = F_46 ( V_257 * 100000 ) ;
args . V_249 . V_243 = V_258 ;
args . V_249 . V_264 = 0 ;
if ( V_210 && ( V_147 -> type & V_152 ) )
args . V_249 . V_264 |= V_271 ;
switch ( V_187 ) {
case 8 :
default:
args . V_249 . V_264 |= V_272 ;
break;
case 10 :
args . V_249 . V_264 |= V_273 ;
break;
}
args . V_249 . V_226 = V_214 ;
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
args . V_251 . V_264 |= V_274 ;
switch ( V_187 ) {
case 8 :
default:
args . V_251 . V_264 |= V_275 ;
break;
case 10 :
args . V_251 . V_264 |= V_276 ;
break;
case 12 :
args . V_251 . V_264 |= V_277 ;
break;
case 16 :
args . V_251 . V_264 |= V_278 ;
break;
}
args . V_251 . V_226 = V_214 ;
args . V_251 . V_269 = V_185 ;
args . V_251 . V_177 = V_134 ;
break;
default:
F_44 ( L_1 , V_222 , V_223 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_222 , V_223 ) ;
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
struct V_234 * V_235 = V_35 -> V_46 ;
struct V_182 * V_183 =
F_32 ( V_11 -> V_36 ) ;
struct V_206 * V_206 =
F_39 ( V_183 ) ;
struct V_207 * V_208 =
V_206 -> V_209 ;
int V_186 ;
V_11 -> V_187 = F_49 ( V_183 ) ;
switch ( V_185 ) {
case V_279 :
case V_280 :
V_186 = V_208 -> V_186 / 10 ;
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 , & V_11 -> V_147 ,
V_281 ,
V_186 ) ;
else {
if ( V_186 == 16200 ) {
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_282 ) ;
if ( ! V_11 -> V_210 )
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_283 ) ;
} else {
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_283 ) ;
}
V_11 -> V_210 = false ;
}
break;
case V_284 :
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 ,
& V_11 -> V_147 ,
V_235 -> V_285 ,
V_4 -> clock / 10 ) ;
else
V_11 -> V_210 =
F_51 ( V_9 ,
& V_11 -> V_147 ,
V_235 -> V_285 ) ;
break;
case V_286 :
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 ,
& V_11 -> V_147 ,
V_287 ,
V_4 -> clock / 10 ) ;
break;
case V_236 :
if ( F_28 ( V_9 ) )
V_11 -> V_210 =
F_50 ( V_9 ,
& V_11 -> V_147 ,
V_288 ,
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
T_5 V_289 = V_4 -> clock ;
T_5 V_255 = 0 , V_256 = 0 , V_257 = 0 , V_258 = 0 ;
struct V_290 * V_291 ;
int V_185 = F_33 ( V_11 -> V_36 ) ;
switch ( V_11 -> V_134 ) {
case V_136 :
V_291 = & V_9 -> clock . V_292 ;
break;
case V_139 :
V_291 = & V_9 -> clock . V_293 ;
break;
case V_141 :
case V_142 :
default:
V_291 = & V_9 -> clock . V_294 ;
break;
}
V_291 -> V_108 = V_11 -> V_189 ;
V_291 -> V_295 = V_11 -> V_213 ;
V_291 -> V_258 = V_11 -> V_245 ;
if ( V_35 -> V_42 & ( V_43 ) )
F_53 ( V_291 , V_11 -> V_184 , & V_289 ,
& V_256 , & V_257 , & V_255 , & V_258 ) ;
else if ( F_8 ( V_9 ) )
F_54 ( V_291 , V_11 -> V_184 , & V_289 ,
& V_256 , & V_257 , & V_255 , & V_258 ) ;
else
F_53 ( V_291 , V_11 -> V_184 , & V_289 ,
& V_256 , & V_257 , & V_255 , & V_258 ) ;
F_29 ( V_9 , V_86 , V_11 -> V_134 ,
V_11 -> V_18 , & V_11 -> V_147 ) ;
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
V_185 , V_35 -> V_214 , V_4 -> clock ,
V_255 , V_256 , V_257 , V_258 ,
V_11 -> V_187 , V_11 -> V_210 , & V_11 -> V_147 ) ;
if ( V_11 -> V_210 ) {
if ( F_28 ( V_9 ) ) {
T_5 V_296 ;
T_5 V_163 = ( ( ( V_256 * 10 ) + V_257 ) *
( T_5 ) V_11 -> V_147 . V_151 ) /
( 100 * ( T_5 ) V_11 -> V_147 . V_297 ) ;
V_11 -> V_147 . V_163 = ( V_163 / 10 ) & V_298 ;
V_11 -> V_147 . V_163 |= ( ( V_163 - ( V_163 / 10 ) ) << V_299 ) &
V_300 ;
if ( V_11 -> V_147 . type & V_301 )
V_296 = ( 4 * V_163 * V_255 * ( ( T_5 ) V_11 -> V_147 . V_302 * 2048 ) ) /
( 125 * 25 * V_291 -> V_303 / 100 ) ;
else
V_296 = ( 2 * V_163 * V_255 * ( ( T_5 ) V_11 -> V_147 . V_302 * 2048 ) ) /
( 125 * 25 * V_291 -> V_303 / 100 ) ;
V_11 -> V_147 . V_165 = V_296 ;
}
F_29 ( V_9 , V_85 , V_11 -> V_134 ,
V_11 -> V_18 , & V_11 -> V_147 ) ;
}
}
static int F_55 ( struct V_1 * V_2 ,
struct V_304 * V_305 ,
int V_306 , int V_307 , int V_308 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_309 * V_310 ;
struct V_304 * V_311 ;
struct V_312 * V_313 ;
struct V_314 * V_315 ;
T_11 V_316 ;
V_33 V_317 , V_318 , V_319 ;
unsigned V_320 , V_321 , V_322 , V_323 ;
T_5 V_324 = F_56 ( V_325 ) ;
T_5 V_326 , V_327 , V_328 ;
int V_329 ;
if ( ! V_308 && ! V_2 -> V_330 -> V_305 ) {
F_57 ( L_2 ) ;
return 0 ;
}
if ( V_308 ) {
V_310 = F_58 ( V_305 ) ;
V_311 = V_305 ;
}
else {
V_310 = F_58 ( V_2 -> V_330 -> V_305 ) ;
V_311 = V_2 -> V_330 -> V_305 ;
}
V_313 = V_310 -> V_313 ;
V_315 = F_59 ( V_313 ) ;
V_329 = F_60 ( V_315 , false ) ;
if ( F_61 ( V_329 != 0 ) )
return V_329 ;
if ( V_308 )
V_316 = F_62 ( V_315 ) ;
else {
V_329 = F_63 ( V_315 , V_331 , & V_316 ) ;
if ( F_61 ( V_329 != 0 ) ) {
F_64 ( V_315 ) ;
return - V_332 ;
}
}
F_65 ( V_315 , & V_319 , NULL ) ;
F_64 ( V_315 ) ;
switch ( V_311 -> V_333 ) {
case 8 :
V_317 = ( F_66 ( V_334 ) |
F_67 ( V_335 ) ) ;
break;
case 15 :
V_317 = ( F_66 ( V_336 ) |
F_67 ( V_337 ) ) ;
break;
case 16 :
V_317 = ( F_66 ( V_336 ) |
F_67 ( V_338 ) ) ;
#ifdef F_68
V_324 = F_56 ( V_339 ) ;
#endif
break;
case 24 :
case 32 :
V_317 = ( F_66 ( V_340 ) |
F_67 ( V_341 ) ) ;
#ifdef F_68
V_324 = F_56 ( V_342 ) ;
#endif
break;
default:
F_44 ( L_3 ,
V_311 -> V_333 ) ;
return - V_332 ;
}
if ( V_319 & V_343 ) {
F_69 ( V_319 , & V_320 , & V_321 , & V_322 , & V_323 ) ;
if ( V_9 -> V_69 >= V_344 ) {
unsigned V_12 , V_345 ;
if ( V_9 -> V_69 >= V_346 ) {
unsigned V_347 , V_348 ;
V_348 = 64 << V_323 ;
V_347 = 8 * 8 * V_311 -> V_333 / 8 ;
V_347 = F_70 ( V_348 , V_347 ) ;
for ( V_12 = 0 ; V_347 > 64 ; V_12 ++ )
V_347 >>= 1 ;
if ( V_12 >= 16 ) {
F_44 ( L_4 ,
V_311 -> V_333 , V_323 ) ;
return - V_332 ;
}
V_345 = ( V_9 -> V_349 . V_350 . V_351 [ V_12 ] >> 6 ) & 0x3 ;
} else {
switch ( V_311 -> V_333 ) {
case 8 :
V_12 = 10 ;
break;
case 16 :
V_12 = V_352 ;
break;
default:
case 32 :
V_12 = V_353 ;
break;
}
V_345 = ( V_9 -> V_349 . V_354 . V_355 [ V_12 ] >> 20 ) & 0x3 ;
}
V_317 |= F_71 ( V_345 ) ;
} else {
if ( V_9 -> V_69 >= V_356 )
V_326 = V_9 -> V_349 . V_357 . V_358 ;
else
V_326 = V_9 -> V_349 . V_359 . V_358 ;
switch ( ( V_326 & 0xf0 ) >> 4 ) {
case 0 :
V_317 |= F_71 ( V_360 ) ;
break;
case 1 :
default:
V_317 |= F_71 ( V_361 ) ;
break;
case 2 :
V_317 |= F_71 ( V_362 ) ;
break;
}
}
V_317 |= F_72 ( V_363 ) ;
V_317 |= F_73 ( V_323 ) ;
V_317 |= F_74 ( V_320 ) ;
V_317 |= F_75 ( V_321 ) ;
V_317 |= F_76 ( V_322 ) ;
if ( V_9 -> V_69 >= V_346 ) {
V_317 |= F_77 ( V_364 ) ;
}
} else if ( V_319 & V_365 )
V_317 |= F_72 ( V_366 ) ;
if ( V_9 -> V_69 >= V_346 ) {
T_5 V_367 = ( V_9 -> V_349 . V_350 . V_355 [ 10 ] >> 6 ) & 0x1f ;
V_317 |= F_78 ( V_367 ) ;
} else if ( ( V_9 -> V_69 == V_344 ) ||
( V_9 -> V_69 == V_368 ) )
V_317 |= F_79 ( V_369 ) ;
else if ( ( V_9 -> V_69 == V_370 ) ||
( V_9 -> V_69 == V_371 ) ||
( V_9 -> V_69 == V_372 ) )
V_317 |= F_79 ( V_373 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_16 ( V_374 , 0 ) ;
break;
case 1 :
F_16 ( V_375 , 0 ) ;
break;
case 2 :
F_16 ( V_376 , 0 ) ;
break;
case 3 :
F_16 ( V_377 , 0 ) ;
break;
case 4 :
F_16 ( V_378 , 0 ) ;
break;
case 5 :
F_16 ( V_379 , 0 ) ;
break;
default:
break;
}
F_16 ( V_380 + V_11 -> V_381 ,
F_80 ( V_316 ) ) ;
F_16 ( V_382 + V_11 -> V_381 ,
F_80 ( V_316 ) ) ;
F_16 ( V_383 + V_11 -> V_381 ,
( T_5 ) V_316 & V_384 ) ;
F_16 ( V_385 + V_11 -> V_381 ,
( T_5 ) V_316 & V_384 ) ;
F_16 ( V_386 + V_11 -> V_381 , V_317 ) ;
F_16 ( V_387 + V_11 -> V_381 , V_324 ) ;
F_16 ( V_388 + V_11 -> V_381 , 0 ) ;
F_16 ( V_389 + V_11 -> V_381 , 0 ) ;
F_16 ( V_390 + V_11 -> V_381 , 0 ) ;
F_16 ( V_391 + V_11 -> V_381 , 0 ) ;
F_16 ( V_392 + V_11 -> V_381 , V_311 -> V_393 ) ;
F_16 ( V_394 + V_11 -> V_381 , V_311 -> V_395 ) ;
V_318 = V_311 -> V_396 [ 0 ] / ( V_311 -> V_333 / 8 ) ;
F_16 ( V_397 + V_11 -> V_381 , V_318 ) ;
F_16 ( V_398 + V_11 -> V_381 , 1 ) ;
if ( V_9 -> V_69 >= V_346 )
F_16 ( V_399 + V_11 -> V_381 ,
V_311 -> V_395 ) ;
else
F_16 ( V_400 + V_11 -> V_381 ,
V_311 -> V_395 ) ;
V_306 &= ~ 3 ;
V_307 &= ~ 1 ;
F_16 ( V_401 + V_11 -> V_381 ,
( V_306 << 16 ) | V_307 ) ;
V_327 = V_2 -> V_4 . V_402 ;
V_328 = ( V_2 -> V_4 . V_403 + 1 ) & ~ 1 ;
F_16 ( V_404 + V_11 -> V_381 ,
( V_327 << 16 ) | V_328 ) ;
V_326 = F_15 ( V_405 + V_11 -> V_381 ) ;
V_326 &= ~ V_406 ;
F_16 ( V_405 + V_11 -> V_381 , V_326 ) ;
F_16 ( V_407 + V_11 -> V_381 , 0 ) ;
if ( ! V_308 && V_305 && V_305 != V_2 -> V_330 -> V_305 ) {
V_310 = F_58 ( V_305 ) ;
V_315 = F_59 ( V_310 -> V_313 ) ;
V_329 = F_60 ( V_315 , false ) ;
if ( F_61 ( V_329 != 0 ) )
return V_329 ;
F_81 ( V_315 ) ;
F_64 ( V_315 ) ;
}
F_82 ( V_9 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_304 * V_305 ,
int V_306 , int V_307 , int V_308 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_309 * V_310 ;
struct V_312 * V_313 ;
struct V_314 * V_315 ;
struct V_304 * V_311 ;
T_11 V_316 ;
V_33 V_317 , V_318 , V_319 ;
T_5 V_324 = V_408 ;
T_5 V_326 , V_327 , V_328 ;
int V_329 ;
if ( ! V_308 && ! V_2 -> V_330 -> V_305 ) {
F_57 ( L_2 ) ;
return 0 ;
}
if ( V_308 ) {
V_310 = F_58 ( V_305 ) ;
V_311 = V_305 ;
}
else {
V_310 = F_58 ( V_2 -> V_330 -> V_305 ) ;
V_311 = V_2 -> V_330 -> V_305 ;
}
V_313 = V_310 -> V_313 ;
V_315 = F_59 ( V_313 ) ;
V_329 = F_60 ( V_315 , false ) ;
if ( F_61 ( V_329 != 0 ) )
return V_329 ;
if ( V_308 )
V_316 = F_62 ( V_315 ) ;
else {
V_329 = F_63 ( V_315 , V_331 , & V_316 ) ;
if ( F_61 ( V_329 != 0 ) ) {
F_64 ( V_315 ) ;
return - V_332 ;
}
}
F_65 ( V_315 , & V_319 , NULL ) ;
F_64 ( V_315 ) ;
switch ( V_311 -> V_333 ) {
case 8 :
V_317 =
V_409 |
V_410 ;
break;
case 15 :
V_317 =
V_411 |
V_412 ;
break;
case 16 :
V_317 =
V_411 |
V_413 ;
#ifdef F_68
V_324 = V_414 ;
#endif
break;
case 24 :
case 32 :
V_317 =
V_415 |
V_416 ;
#ifdef F_68
V_324 = V_417 ;
#endif
break;
default:
F_44 ( L_3 ,
V_311 -> V_333 ) ;
return - V_332 ;
}
if ( V_9 -> V_69 >= V_418 ) {
if ( V_319 & V_343 )
V_317 |= V_419 ;
else if ( V_319 & V_365 )
V_317 |= V_420 ;
} else {
if ( V_319 & V_343 )
V_317 |= V_421 ;
if ( V_319 & V_365 )
V_317 |= V_422 ;
}
if ( V_11 -> V_18 == 0 )
F_16 ( V_374 , 0 ) ;
else
F_16 ( V_375 , 0 ) ;
if ( V_9 -> V_69 >= V_196 ) {
if ( V_11 -> V_18 ) {
F_16 ( V_423 , F_80 ( V_316 ) ) ;
F_16 ( V_424 , F_80 ( V_316 ) ) ;
} else {
F_16 ( V_425 , F_80 ( V_316 ) ) ;
F_16 ( V_426 , F_80 ( V_316 ) ) ;
}
}
F_16 ( V_427 + V_11 -> V_381 ,
( T_5 ) V_316 ) ;
F_16 ( V_428 +
V_11 -> V_381 , ( T_5 ) V_316 ) ;
F_16 ( V_429 + V_11 -> V_381 , V_317 ) ;
if ( V_9 -> V_69 >= V_418 )
F_16 ( V_430 + V_11 -> V_381 , V_324 ) ;
F_16 ( V_431 + V_11 -> V_381 , 0 ) ;
F_16 ( V_432 + V_11 -> V_381 , 0 ) ;
F_16 ( V_433 + V_11 -> V_381 , 0 ) ;
F_16 ( V_434 + V_11 -> V_381 , 0 ) ;
F_16 ( V_435 + V_11 -> V_381 , V_311 -> V_393 ) ;
F_16 ( V_436 + V_11 -> V_381 , V_311 -> V_395 ) ;
V_318 = V_311 -> V_396 [ 0 ] / ( V_311 -> V_333 / 8 ) ;
F_16 ( V_437 + V_11 -> V_381 , V_318 ) ;
F_16 ( V_438 + V_11 -> V_381 , 1 ) ;
F_16 ( V_439 + V_11 -> V_381 ,
V_311 -> V_395 ) ;
V_306 &= ~ 3 ;
V_307 &= ~ 1 ;
F_16 ( V_440 + V_11 -> V_381 ,
( V_306 << 16 ) | V_307 ) ;
V_327 = V_2 -> V_4 . V_402 ;
V_328 = ( V_2 -> V_4 . V_403 + 1 ) & ~ 1 ;
F_16 ( V_441 + V_11 -> V_381 ,
( V_327 << 16 ) | V_328 ) ;
V_326 = F_15 ( V_442 + V_11 -> V_381 ) ;
V_326 &= ~ V_443 ;
F_16 ( V_442 + V_11 -> V_381 , V_326 ) ;
F_16 ( V_444 + V_11 -> V_381 , 0 ) ;
if ( ! V_308 && V_305 && V_305 != V_2 -> V_330 -> V_305 ) {
V_310 = F_58 ( V_305 ) ;
V_315 = F_59 ( V_310 -> V_313 ) ;
V_329 = F_60 ( V_315 , false ) ;
if ( F_61 ( V_329 != 0 ) )
return V_329 ;
F_81 ( V_315 ) ;
F_64 ( V_315 ) ;
}
F_82 ( V_9 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , int V_306 , int V_307 ,
struct V_304 * V_445 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_55 ( V_2 , V_445 , V_306 , V_307 , 0 ) ;
else if ( F_8 ( V_9 ) )
return F_83 ( V_2 , V_445 , V_306 , V_307 , 0 ) ;
else
return F_85 ( V_2 , V_445 , V_306 , V_307 , 0 ) ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_304 * V_305 ,
int V_306 , int V_307 , enum V_446 V_74 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_55 ( V_2 , V_305 , V_306 , V_307 , 1 ) ;
else if ( F_8 ( V_9 ) )
return F_83 ( V_2 , V_305 , V_306 , V_307 , 1 ) ;
else
return F_85 ( V_2 , V_305 , V_306 , V_307 , 1 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_5 V_447 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_447 = F_15 ( V_448 ) ;
V_447 &= ~ V_449 ;
F_16 ( V_448 , V_447 ) ;
break;
case 1 :
V_447 = F_15 ( V_450 ) ;
V_447 &= ~ V_451 ;
F_16 ( V_450 , V_447 ) ;
F_16 ( V_452 , F_15 ( V_453 ) ) ;
F_16 ( V_454 , F_15 ( V_455 ) ) ;
break;
}
}
static T_5 F_88 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_456 ;
struct V_11 * V_457 ;
T_5 V_458 = 0 ;
F_89 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_456 )
continue;
V_457 = F_2 ( V_456 ) ;
if ( V_457 -> V_134 != V_142 )
V_458 |= ( 1 << V_457 -> V_134 ) ;
}
return V_458 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_456 ;
struct V_11 * V_457 ;
F_89 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_456 )
continue;
V_457 = F_2 ( V_456 ) ;
if ( V_457 -> V_36 &&
F_42 ( F_33 ( V_457 -> V_36 ) ) ) {
if ( V_457 -> V_134 != V_142 )
return V_457 -> V_134 ;
}
}
return V_142 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_456 ;
struct V_11 * V_457 ;
T_5 V_184 , V_459 ;
V_184 = V_11 -> V_184 ;
if ( V_184 == 0 )
return V_142 ;
F_89 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_456 )
continue;
V_457 = F_2 ( V_456 ) ;
if ( V_457 -> V_36 &&
! F_42 ( F_33 ( V_457 -> V_36 ) ) ) {
if ( V_457 -> V_183 == V_11 -> V_183 ) {
if ( V_457 -> V_134 != V_142 )
return V_457 -> V_134 ;
}
V_459 = V_457 -> V_184 ;
if ( ( V_2 -> V_4 . clock == V_456 -> V_4 . clock ) &&
( V_184 == V_459 ) &&
( V_11 -> V_210 == V_457 -> V_210 ) &&
( V_457 -> V_134 != V_142 ) )
return V_457 -> V_134 ;
}
}
return V_142 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_5 V_458 ;
int V_291 ;
if ( F_14 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_460 )
return V_142 ;
else {
V_291 = F_90 ( V_2 ) ;
if ( V_291 != V_142 )
return V_291 ;
}
} else {
V_291 = F_91 ( V_2 ) ;
if ( V_291 != V_142 )
return V_291 ;
}
if ( ( V_9 -> V_69 == V_461 ) ||
( V_9 -> V_69 == V_462 ) ||
( V_9 -> V_69 == V_463 ) ) {
V_458 = F_88 ( V_2 ) ;
if ( ! ( V_458 & ( 1 << V_139 ) ) )
return V_139 ;
if ( ! ( V_458 & ( 1 << V_136 ) ) )
return V_136 ;
F_44 ( L_5 ) ;
return V_142 ;
} else {
V_458 = F_88 ( V_2 ) ;
if ( ! ( V_458 & ( 1 << V_139 ) ) )
return V_139 ;
if ( ! ( V_458 & ( 1 << V_136 ) ) )
return V_136 ;
if ( ! ( V_458 & ( 1 << V_254 ) ) )
return V_254 ;
F_44 ( L_5 ) ;
return V_142 ;
}
} else if ( F_37 ( V_9 ) ) {
struct V_234 * V_235 =
V_35 -> V_46 ;
if ( ( V_35 -> V_214 == V_464 ) &&
( V_235 -> V_465 == false ) )
return V_139 ;
else if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_460 )
return V_142 ;
else {
V_291 = F_90 ( V_2 ) ;
if ( V_291 != V_142 )
return V_291 ;
}
} else {
V_291 = F_91 ( V_2 ) ;
if ( V_291 != V_142 )
return V_291 ;
}
V_458 = F_88 ( V_2 ) ;
if ( ! ( V_458 & ( 1 << V_254 ) ) )
return V_254 ;
if ( ! ( V_458 & ( 1 << V_136 ) ) )
return V_136 ;
F_44 ( L_5 ) ;
return V_142 ;
} else if ( F_36 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_460 )
return V_142 ;
}
V_458 = F_88 ( V_2 ) ;
if ( ! ( V_458 & ( 1 << V_136 ) ) )
return V_136 ;
if ( ! ( V_458 & ( 1 << V_139 ) ) )
return V_139 ;
F_44 ( L_5 ) ;
return V_142 ;
} else if ( F_28 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_460 )
return V_142 ;
else if ( F_20 ( V_9 ) )
return V_254 ;
else if ( F_30 ( V_9 ) )
return V_141 ;
else {
V_291 = F_90 ( V_2 ) ;
if ( V_291 != V_142 )
return V_291 ;
}
} else {
V_291 = F_91 ( V_2 ) ;
if ( V_291 != V_142 )
return V_291 ;
}
V_458 = F_88 ( V_2 ) ;
if ( ! ( V_458 & ( 1 << V_136 ) ) )
return V_136 ;
if ( ! ( V_458 & ( 1 << V_139 ) ) )
return V_139 ;
F_44 ( L_5 ) ;
return V_142 ;
} else {
return V_11 -> V_18 ;
}
}
void F_93 ( struct V_8 * V_9 )
{
if ( F_20 ( V_9 ) )
F_45 ( V_9 , V_9 -> clock . V_466 ) ;
else if ( F_28 ( V_9 ) ) {
struct V_146 V_147 ;
bool V_210 = F_50 ( V_9 , & V_147 ,
V_467 ,
V_9 -> clock . V_466 ) ;
if ( V_210 )
F_29 ( V_9 , V_86 , V_141 , - 1 , & V_147 ) ;
F_45 ( V_9 , V_9 -> clock . V_466 ) ;
if ( V_210 )
F_29 ( V_9 , V_85 , V_141 , - 1 , & V_147 ) ;
}
}
int F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_306 , int V_307 , struct V_304 * V_445 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
bool V_468 = false ;
if ( V_35 -> V_42 &
( V_43 | V_469 ) )
V_468 = true ;
if ( ! V_11 -> V_184 )
return - V_332 ;
F_52 ( V_2 , V_5 ) ;
if ( F_28 ( V_9 ) )
F_25 ( V_2 , V_5 ) ;
else if ( F_8 ( V_9 ) ) {
if ( V_468 )
F_26 ( V_2 , V_5 ) ;
else
F_25 ( V_2 , V_5 ) ;
} else {
F_26 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_25 ( V_2 , V_5 ) ;
F_87 ( V_2 ) ;
}
F_84 ( V_2 , V_306 , V_307 , V_445 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
V_11 -> V_470 = * V_5 ;
return 0 ;
}
static bool F_95 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_181 * V_36 ;
F_89 (encoder, &dev->mode_config.encoder_list, head) {
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
if ( ! F_96 ( V_2 , V_4 , V_5 ) )
return false ;
if ( ! F_48 ( V_2 , V_5 ) )
return false ;
V_11 -> V_134 = F_92 ( V_2 ) ;
if ( ( V_11 -> V_134 == V_142 ) &&
! F_42 ( F_33 ( V_11 -> V_36 ) ) )
return false ;
return true ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_86 ) ;
F_10 ( V_2 , V_85 ) ;
F_18 ( V_2 , V_89 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_83 ) ;
F_10 ( V_2 , V_86 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_146 V_147 ;
int V_148 ;
F_18 ( V_2 , V_89 ) ;
if ( V_2 -> V_330 -> V_305 ) {
int V_329 ;
struct V_309 * V_310 ;
struct V_314 * V_315 ;
V_310 = F_58 ( V_2 -> V_330 -> V_305 ) ;
V_315 = F_59 ( V_310 -> V_313 ) ;
V_329 = F_60 ( V_315 , false ) ;
if ( F_61 ( V_329 ) )
F_44 ( L_6 ) ;
else {
F_81 ( V_315 ) ;
F_64 ( V_315 ) ;
}
}
if ( F_28 ( V_9 ) )
F_16 ( V_398 + V_11 -> V_381 , 0 ) ;
else if ( F_8 ( V_9 ) )
F_16 ( V_438 + V_11 -> V_381 , 0 ) ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_85 ) ;
for ( V_148 = 0 ; V_148 < V_9 -> V_153 ; V_148 ++ ) {
if ( V_9 -> V_31 . V_154 [ V_148 ] &&
V_9 -> V_31 . V_154 [ V_148 ] -> V_84 &&
V_148 != V_11 -> V_18 &&
V_11 -> V_134 == V_9 -> V_31 . V_154 [ V_148 ] -> V_134 ) {
goto V_471;
}
}
switch ( V_11 -> V_134 ) {
case V_136 :
case V_139 :
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_147 ) ;
break;
case V_254 :
if ( ( V_9 -> V_69 == V_472 ) ||
( V_9 -> V_69 == V_346 ) ||
( V_9 -> V_69 == V_473 ) )
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_147 ) ;
break;
default:
break;
}
V_471:
V_11 -> V_134 = V_142 ;
V_11 -> V_184 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_183 = NULL ;
}
void F_100 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_381 = V_474 ;
break;
case 1 :
V_11 -> V_381 = V_475 ;
break;
case 2 :
V_11 -> V_381 = V_476 ;
break;
case 3 :
V_11 -> V_381 = V_477 ;
break;
case 4 :
V_11 -> V_381 = V_478 ;
break;
case 5 :
V_11 -> V_381 = V_479 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_381 =
V_480 - V_481 ;
else
V_11 -> V_381 = 0 ;
}
V_11 -> V_134 = V_142 ;
V_11 -> V_184 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_183 = NULL ;
F_101 ( & V_11 -> V_482 , & V_483 ) ;
}
