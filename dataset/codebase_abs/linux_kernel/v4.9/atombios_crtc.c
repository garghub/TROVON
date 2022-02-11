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
if ( V_7 -> V_87 > V_11 -> V_18 )
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_88 :
case V_89 :
case V_90 :
if ( V_7 -> V_87 > V_11 -> V_18 )
F_23 ( V_2 ) ;
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
int V_12 = F_3 ( V_13 , V_91 ) ;
T_8 V_92 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_93 = F_4 ( V_4 -> V_25 - ( V_11 -> V_29 * 2 ) ) ;
args . V_94 =
F_4 ( V_4 -> V_95 - V_4 -> V_25 + ( V_11 -> V_29 * 2 ) ) ;
args . V_96 = F_4 ( V_4 -> V_22 - ( V_11 -> V_30 * 2 ) ) ;
args . V_97 =
F_4 ( V_4 -> V_98 - V_4 -> V_22 + ( V_11 -> V_30 * 2 ) ) ;
args . V_99 =
F_4 ( V_4 -> V_100 - V_4 -> V_25 + V_11 -> V_29 ) ;
args . V_101 =
F_4 ( V_4 -> V_102 - V_4 -> V_100 ) ;
args . V_103 =
F_4 ( V_4 -> V_104 - V_4 -> V_22 + V_11 -> V_30 ) ;
args . V_105 =
F_4 ( V_4 -> V_106 - V_4 -> V_104 ) ;
args . V_107 = V_11 -> V_29 ;
args . V_108 = V_11 -> V_30 ;
if ( V_4 -> V_109 & V_110 )
V_92 |= V_111 ;
if ( V_4 -> V_109 & V_112 )
V_92 |= V_113 ;
if ( V_4 -> V_109 & V_114 )
V_92 |= V_115 ;
if ( V_4 -> V_109 & V_116 )
V_92 |= V_117 ;
if ( V_4 -> V_109 & V_118 )
V_92 |= V_119 ;
if ( V_4 -> V_109 & V_120 )
V_92 |= V_121 | V_122 ;
args . V_123 . V_124 = F_4 ( V_92 ) ;
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
int V_12 = F_3 ( V_13 , V_125 ) ;
T_8 V_92 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_126 = F_4 ( V_4 -> V_127 ) ;
args . V_128 = F_4 ( V_4 -> V_25 ) ;
args . V_129 = F_4 ( V_4 -> V_100 ) ;
args . V_101 =
F_4 ( V_4 -> V_102 - V_4 -> V_100 ) ;
args . V_130 = F_4 ( V_4 -> V_131 ) ;
args . V_132 = F_4 ( V_4 -> V_22 ) ;
args . V_133 = F_4 ( V_4 -> V_104 ) ;
args . V_105 =
F_4 ( V_4 -> V_106 - V_4 -> V_104 ) ;
args . V_134 = V_11 -> V_29 ;
args . V_135 = V_11 -> V_29 ;
args . V_136 = V_11 -> V_30 ;
args . V_137 = V_11 -> V_30 ;
if ( V_4 -> V_109 & V_110 )
V_92 |= V_111 ;
if ( V_4 -> V_109 & V_112 )
V_92 |= V_113 ;
if ( V_4 -> V_109 & V_114 )
V_92 |= V_115 ;
if ( V_4 -> V_109 & V_116 )
V_92 |= V_117 ;
if ( V_4 -> V_109 & V_118 )
V_92 |= V_119 ;
if ( V_4 -> V_109 & V_120 )
V_92 |= V_121 | V_122 ;
args . V_123 . V_124 = F_4 ( V_92 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_27 ( struct V_8 * V_9 , int V_138 )
{
T_5 V_139 ;
if ( F_28 ( V_9 ) ) {
switch ( V_138 ) {
case V_140 :
V_139 = F_15 ( V_141 ) ;
V_139 &= ~ V_142 ;
F_16 ( V_141 , V_139 ) ;
break;
case V_143 :
V_139 = F_15 ( V_144 ) ;
V_139 &= ~ V_142 ;
F_16 ( V_144 , V_139 ) ;
break;
case V_145 :
case V_146 :
return;
}
} else if ( F_8 ( V_9 ) ) {
switch ( V_138 ) {
case V_140 :
V_139 = F_15 ( V_147 ) ;
V_139 &= ~ 1 ;
F_16 ( V_147 , V_139 ) ;
break;
case V_143 :
V_139 = F_15 ( V_148 ) ;
V_139 &= ~ 1 ;
F_16 ( V_148 , V_139 ) ;
break;
case V_145 :
case V_146 :
return;
}
}
}
static void F_29 ( struct V_8 * V_9 ,
int V_149 ,
int V_138 ,
int V_18 ,
struct V_150 * V_151 )
{
unsigned V_152 ;
int V_12 = F_3 ( V_13 , V_153 ) ;
union V_154 args ;
if ( V_149 ) {
if ( V_151 -> V_155 == 0 )
return;
if ( V_151 -> type & V_156 )
return;
} else {
for ( V_152 = 0 ; V_152 < V_9 -> V_157 ; V_152 ++ ) {
if ( V_9 -> V_31 . V_158 [ V_152 ] &&
V_9 -> V_31 . V_158 [ V_152 ] -> V_84 &&
V_152 != V_18 &&
V_138 == V_9 -> V_31 . V_158 [ V_152 ] -> V_138 ) {
return;
}
}
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_30 ( V_9 ) ) {
args . V_159 . V_160 = F_4 ( 0 ) ;
args . V_159 . V_161 = V_151 -> type & V_162 ;
switch ( V_138 ) {
case V_140 :
args . V_159 . V_161 |= V_163 ;
break;
case V_143 :
args . V_159 . V_161 |= V_164 ;
break;
case V_145 :
args . V_159 . V_161 |= V_165 ;
break;
case V_146 :
return;
}
args . V_159 . V_166 = F_4 ( V_151 -> V_167 ) ;
args . V_159 . V_168 = F_4 ( V_151 -> V_169 ) ;
args . V_159 . V_63 = V_149 ;
} else if ( F_28 ( V_9 ) ) {
args . V_170 . V_171 = F_4 ( V_151 -> V_155 ) ;
args . V_170 . V_161 = V_151 -> type & V_162 ;
switch ( V_138 ) {
case V_140 :
args . V_170 . V_161 |= V_172 ;
break;
case V_143 :
args . V_170 . V_161 |= V_173 ;
break;
case V_145 :
args . V_170 . V_161 |= V_174 ;
break;
case V_146 :
return;
}
args . V_170 . V_166 = F_4 ( V_151 -> V_167 ) ;
args . V_170 . V_168 = F_4 ( V_151 -> V_169 ) ;
args . V_170 . V_63 = V_149 ;
} else if ( F_19 ( V_9 ) ) {
args . V_175 . V_171 = F_4 ( V_151 -> V_155 ) ;
args . V_175 . V_161 = V_151 -> type & V_162 ;
args . V_175 . V_176 = V_151 -> V_169 ;
args . V_175 . V_177 = V_151 -> V_178 ;
args . V_175 . V_179 = V_151 -> V_180 ;
args . V_175 . V_181 = V_138 ;
args . V_175 . V_63 = V_149 ;
} else if ( F_8 ( V_9 ) ) {
if ( ( V_149 == V_86 ) || ( V_151 -> V_155 == 0 ) ||
( V_151 -> type & V_156 ) ) {
F_27 ( V_9 , V_138 ) ;
return;
}
args . V_182 . V_171 = F_4 ( V_151 -> V_155 ) ;
args . V_182 . V_161 = V_151 -> type & V_162 ;
args . V_182 . V_176 = V_151 -> V_169 ;
args . V_182 . V_177 = V_151 -> V_178 ;
args . V_182 . V_179 = V_151 -> V_180 ;
args . V_182 . V_63 = V_149 ;
} else {
if ( V_149 == V_86 ) {
F_27 ( V_9 , V_138 ) ;
return;
}
args . V_183 . V_171 = F_4 ( V_151 -> V_155 ) ;
args . V_183 . V_161 = V_151 -> type & V_162 ;
args . V_183 . V_184 = ( V_151 -> V_169 & 3 ) << 2 ;
args . V_183 . V_184 |= ( V_151 -> V_178 & 7 ) << 4 ;
args . V_183 . V_63 = V_149 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_5 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_185 * V_36 = V_11 -> V_36 ;
struct V_35 * V_35 = F_7 ( V_36 ) ;
struct V_186 * V_187 = F_32 ( V_36 ) ;
T_5 V_188 = V_4 -> clock ;
int V_189 = F_33 ( V_36 ) ;
T_5 V_190 = V_4 -> clock ;
T_5 clock = V_4 -> clock ;
int V_191 = V_11 -> V_191 ;
bool V_192 = F_34 ( V_36 , V_4 -> clock ) ;
V_11 -> V_193 = 0 ;
if ( F_8 ( V_9 ) ) {
if ( ( V_9 -> V_69 == V_194 ) ||
( V_9 -> V_69 == V_195 ) ||
( V_9 -> V_69 == V_196 ) )
V_11 -> V_193 |= (
V_197 ) ;
if ( F_35 ( V_9 ) && V_4 -> clock > 200000 )
V_11 -> V_193 |= V_198 ;
else
V_11 -> V_193 |= V_199 ;
if ( V_9 -> V_69 < V_200 )
V_11 -> V_193 |= V_201 ;
if ( F_36 ( V_9 ) || F_37 ( V_9 ) || F_14 ( V_9 ) )
V_11 -> V_193 |= V_202 ;
if ( ( ( V_9 -> V_69 == V_203 ) || ( V_9 -> V_69 == V_204 ) )
&& ! V_11 -> V_205 )
V_11 -> V_193 |= V_202 ;
if ( F_35 ( V_9 ) && V_4 -> clock > 165000 )
V_11 -> V_193 |= V_202 ;
} else {
V_11 -> V_193 |= V_206 ;
if ( V_4 -> clock > 200000 )
V_11 -> V_193 |= V_198 ;
else
V_11 -> V_193 |= V_199 ;
}
if ( ( V_35 -> V_207 & ( V_208 | V_209 ) ) ||
( F_38 ( V_36 ) != V_210 ) ) {
if ( V_187 ) {
struct V_211 * V_211 = F_39 ( V_187 ) ;
struct V_212 * V_213 =
V_211 -> V_214 ;
V_190 = V_213 -> V_190 ;
}
}
if ( V_35 -> V_215 ) {
struct V_216 * V_217 = V_35 -> V_46 ;
struct V_212 * V_213 = V_217 -> V_187 -> V_214 ;
V_190 = V_213 -> V_190 ;
}
if ( V_35 -> V_207 & ( V_208 ) ) {
if ( V_11 -> V_205 ) {
if ( V_11 -> V_151 . V_218 ) {
V_11 -> V_193 |= V_219 ;
V_11 -> V_220 = V_11 -> V_151 . V_218 ;
if ( F_8 ( V_9 ) &&
V_9 -> V_69 != V_203 &&
V_9 -> V_69 != V_204 )
V_11 -> V_193 |= V_202 ;
}
}
}
if ( F_8 ( V_9 ) ) {
if ( V_35 -> V_221 == V_222 )
V_188 = V_4 -> clock * 2 ;
if ( V_35 -> V_42 & ( V_43 ) )
V_11 -> V_193 |= V_197 ;
if ( V_35 -> V_207 & ( V_208 ) )
V_11 -> V_193 |= V_223 ;
} else {
if ( V_36 -> V_224 != V_225 )
V_11 -> V_193 |= V_226 ;
if ( V_36 -> V_224 == V_227 )
V_11 -> V_193 |= V_219 ;
}
if ( V_189 == V_228 ) {
switch ( V_191 ) {
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
union V_229 args ;
T_10 V_230 , V_231 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_232 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_230 ,
& V_231 ) )
return V_188 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_230 ) {
case 1 :
switch ( V_231 ) {
case 1 :
case 2 :
args . V_175 . V_233 = F_4 ( clock / 10 ) ;
args . V_175 . V_234 = V_35 -> V_221 ;
args . V_175 . V_235 = V_189 ;
if ( V_11 -> V_205 && V_11 -> V_151 . V_155 )
args . V_175 . V_236 |=
V_237 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_188 = F_41 ( args . V_175 . V_233 ) * 10 ;
break;
case 3 :
args . V_159 . V_238 . V_233 = F_4 ( clock / 10 ) ;
args . V_159 . V_238 . V_234 = V_35 -> V_221 ;
args . V_159 . V_238 . V_235 = V_189 ;
args . V_159 . V_238 . V_239 = 0 ;
if ( V_11 -> V_205 && V_11 -> V_151 . V_155 )
args . V_159 . V_238 . V_239 |=
V_240 ;
if ( F_42 ( V_189 ) ) {
args . V_159 . V_238 . V_239 |=
V_241 ;
args . V_159 . V_238 . V_233 = F_4 ( V_190 / 10 ) ;
} else if ( V_35 -> V_207 & ( V_209 ) ) {
struct V_242 * V_243 = V_35 -> V_46 ;
if ( V_243 -> V_244 )
args . V_159 . V_238 . V_239 |=
V_241 ;
if ( V_192 )
args . V_159 . V_238 . V_239 |=
V_245 ;
}
if ( F_38 ( V_36 ) !=
V_210 )
args . V_159 . V_238 . V_246 =
F_38 ( V_36 ) ;
else
args . V_159 . V_238 . V_246 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_188 = F_43 ( args . V_159 . V_247 . V_248 ) * 10 ;
if ( args . V_159 . V_247 . V_249 ) {
V_11 -> V_193 |= V_202 ;
V_11 -> V_193 |= V_219 ;
V_11 -> V_220 = args . V_159 . V_247 . V_249 ;
}
if ( args . V_159 . V_247 . V_250 ) {
V_11 -> V_193 |= V_202 ;
V_11 -> V_193 |= V_251 ;
V_11 -> V_252 = args . V_159 . V_247 . V_250 ;
}
break;
default:
F_44 ( L_1 , V_230 , V_231 ) ;
return V_188 ;
}
break;
default:
F_44 ( L_1 , V_230 , V_231 ) ;
return V_188 ;
}
}
return V_188 ;
}
static void F_45 ( struct V_8 * V_9 ,
T_5 V_253 )
{
T_10 V_230 , V_231 ;
int V_12 ;
union V_254 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_255 ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_230 ,
& V_231 ) )
return;
switch ( V_230 ) {
case 1 :
switch ( V_231 ) {
case 5 :
args . V_256 . V_17 = V_257 ;
args . V_256 . V_233 = F_4 ( V_253 ) ;
args . V_256 . V_181 = V_145 ;
break;
case 6 :
args . V_258 . V_259 = F_46 ( V_253 ) ;
if ( F_37 ( V_9 ) || F_14 ( V_9 ) )
args . V_258 . V_181 = V_260 ;
else if ( F_20 ( V_9 ) )
args . V_258 . V_181 = V_261 ;
else
args . V_258 . V_181 = V_145 ;
break;
default:
F_44 ( L_1 , V_230 , V_231 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_230 , V_231 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_5 V_18 ,
int V_138 ,
T_5 V_189 ,
T_5 V_221 ,
T_5 clock ,
T_5 V_262 ,
T_5 V_263 ,
T_5 V_264 ,
T_5 V_265 ,
int V_191 ,
bool V_205 ,
struct V_150 * V_151 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_10 V_230 , V_231 ;
int V_12 = F_3 ( V_13 , V_255 ) ;
union V_254 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_40 ( V_9 -> V_31 . V_32 , V_12 , & V_230 ,
& V_231 ) )
return;
switch ( V_230 ) {
case 1 :
switch ( V_231 ) {
case 1 :
if ( clock == V_86 )
return;
args . V_175 . V_233 = F_4 ( clock / 10 ) ;
args . V_175 . V_266 = F_4 ( V_262 ) ;
args . V_175 . V_267 = F_4 ( V_263 ) ;
args . V_175 . V_268 = V_264 ;
args . V_175 . V_250 = V_265 ;
args . V_175 . V_181 = V_138 ;
args . V_175 . V_17 = V_18 ;
args . V_175 . V_269 = 1 ;
break;
case 2 :
args . V_170 . V_233 = F_4 ( clock / 10 ) ;
args . V_170 . V_266 = F_4 ( V_262 ) ;
args . V_170 . V_267 = F_4 ( V_263 ) ;
args . V_170 . V_268 = V_264 ;
args . V_170 . V_250 = V_265 ;
args . V_170 . V_181 = V_138 ;
args . V_170 . V_17 = V_18 ;
args . V_170 . V_269 = 1 ;
break;
case 3 :
args . V_159 . V_233 = F_4 ( clock / 10 ) ;
args . V_159 . V_266 = F_4 ( V_262 ) ;
args . V_159 . V_267 = F_4 ( V_263 ) ;
args . V_159 . V_268 = V_264 ;
args . V_159 . V_250 = V_265 ;
args . V_159 . V_181 = V_138 ;
if ( V_18 == V_270 )
args . V_159 . V_271 = V_272 ;
else
args . V_159 . V_271 = V_273 ;
if ( V_205 && ( V_151 -> type & V_156 ) )
args . V_159 . V_271 |= V_274 ;
args . V_159 . V_275 = V_221 ;
args . V_159 . V_276 = V_189 ;
break;
case 5 :
args . V_256 . V_17 = V_18 ;
args . V_256 . V_233 = F_4 ( clock / 10 ) ;
args . V_256 . V_249 = V_262 ;
args . V_256 . V_267 = F_4 ( V_263 ) ;
args . V_256 . V_277 = F_46 ( V_264 * 100000 ) ;
args . V_256 . V_250 = V_265 ;
args . V_256 . V_271 = 0 ;
if ( V_205 && ( V_151 -> type & V_156 ) )
args . V_256 . V_271 |= V_278 ;
if ( V_189 == V_228 ) {
switch ( V_191 ) {
case 8 :
default:
args . V_256 . V_271 |= V_279 ;
break;
case 10 :
args . V_256 . V_271 |= V_280 ;
break;
case 12 :
args . V_256 . V_271 |= V_281 ;
break;
}
}
args . V_256 . V_234 = V_221 ;
args . V_256 . V_276 = V_189 ;
args . V_256 . V_181 = V_138 ;
break;
case 6 :
args . V_258 . V_259 = F_46 ( V_18 << 24 | clock / 10 ) ;
args . V_258 . V_249 = V_262 ;
args . V_258 . V_267 = F_4 ( V_263 ) ;
args . V_258 . V_277 = F_46 ( V_264 * 100000 ) ;
args . V_258 . V_250 = V_265 ;
args . V_258 . V_271 = 0 ;
if ( V_205 && ( V_151 -> type & V_156 ) )
args . V_258 . V_271 |= V_282 ;
if ( V_189 == V_228 ) {
switch ( V_191 ) {
case 8 :
default:
args . V_258 . V_271 |= V_283 ;
break;
case 10 :
args . V_258 . V_271 |= V_284 ;
break;
case 12 :
args . V_258 . V_271 |= V_285 ;
break;
case 16 :
args . V_258 . V_271 |= V_286 ;
break;
}
}
args . V_258 . V_234 = V_221 ;
args . V_258 . V_276 = V_189 ;
args . V_258 . V_181 = V_138 ;
break;
default:
F_44 ( L_1 , V_230 , V_231 ) ;
return;
}
break;
default:
F_44 ( L_1 , V_230 , V_231 ) ;
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
int V_189 = F_33 ( V_11 -> V_36 ) ;
V_11 -> V_191 = 8 ;
V_11 -> V_205 = false ;
if ( V_35 -> V_215 ) {
F_49 ( V_2 , V_4 ) ;
} else if ( ( V_35 -> V_42 & ( V_208 | V_209 ) ) ||
( F_38 ( V_11 -> V_36 ) != V_210 ) ) {
struct V_242 * V_243 = V_35 -> V_46 ;
struct V_186 * V_187 =
F_32 ( V_11 -> V_36 ) ;
struct V_211 * V_211 =
F_39 ( V_187 ) ;
struct V_212 * V_213 =
V_211 -> V_214 ;
int V_190 ;
V_211 -> V_287 = V_4 -> clock ;
V_11 -> V_191 = F_50 ( V_187 ) ;
switch ( V_189 ) {
case V_288 :
case V_289 :
V_190 = V_213 -> V_190 / 10 ;
if ( F_28 ( V_9 ) )
V_11 -> V_205 =
F_51 ( V_9 , & V_11 -> V_151 ,
V_290 ,
V_190 ) ;
else {
if ( V_190 == 16200 ) {
V_11 -> V_205 =
F_52 ( V_9 ,
& V_11 -> V_151 ,
V_291 ) ;
if ( ! V_11 -> V_205 )
V_11 -> V_205 =
F_52 ( V_9 ,
& V_11 -> V_151 ,
V_292 ) ;
} else {
V_11 -> V_205 =
F_52 ( V_9 ,
& V_11 -> V_151 ,
V_292 ) ;
}
V_11 -> V_205 = false ;
}
break;
case V_293 :
if ( F_28 ( V_9 ) )
V_11 -> V_205 =
F_51 ( V_9 ,
& V_11 -> V_151 ,
V_243 -> V_294 ,
V_4 -> clock / 10 ) ;
else
V_11 -> V_205 =
F_52 ( V_9 ,
& V_11 -> V_151 ,
V_243 -> V_294 ) ;
break;
case V_295 :
if ( F_28 ( V_9 ) )
V_11 -> V_205 =
F_51 ( V_9 ,
& V_11 -> V_151 ,
V_296 ,
V_4 -> clock / 10 ) ;
break;
case V_228 :
if ( F_28 ( V_9 ) )
V_11 -> V_205 =
F_51 ( V_9 ,
& V_11 -> V_151 ,
V_297 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_11 -> V_188 = F_31 ( V_2 , V_4 ) ;
return true ;
}
static void F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_5 V_298 = V_4 -> clock ;
T_5 clock = V_4 -> clock ;
T_5 V_262 = 0 , V_263 = 0 , V_264 = 0 , V_265 = 0 ;
struct V_299 * V_300 ;
int V_189 = F_33 ( V_11 -> V_36 ) ;
if ( F_30 ( V_9 ) &&
( V_189 == V_228 ) &&
( V_11 -> V_191 > 8 ) )
clock = V_11 -> V_188 ;
switch ( V_11 -> V_138 ) {
case V_140 :
V_300 = & V_9 -> clock . V_301 ;
break;
case V_143 :
V_300 = & V_9 -> clock . V_302 ;
break;
case V_145 :
case V_146 :
default:
V_300 = & V_9 -> clock . V_303 ;
break;
}
V_300 -> V_109 = V_11 -> V_193 ;
V_300 -> V_304 = V_11 -> V_220 ;
V_300 -> V_265 = V_11 -> V_252 ;
if ( V_35 -> V_42 & ( V_43 ) )
F_54 ( V_300 , V_11 -> V_188 , & V_298 ,
& V_263 , & V_264 , & V_262 , & V_265 ) ;
else if ( F_8 ( V_9 ) )
F_55 ( V_300 , V_11 -> V_188 , & V_298 ,
& V_263 , & V_264 , & V_262 , & V_265 ) ;
else
F_54 ( V_300 , V_11 -> V_188 , & V_298 ,
& V_263 , & V_264 , & V_262 , & V_265 ) ;
F_29 ( V_9 , V_86 , V_11 -> V_138 ,
V_11 -> V_18 , & V_11 -> V_151 ) ;
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_138 ,
V_189 , V_35 -> V_221 , clock ,
V_262 , V_263 , V_264 , V_265 ,
V_11 -> V_191 , V_11 -> V_205 , & V_11 -> V_151 ) ;
if ( V_11 -> V_205 ) {
if ( F_28 ( V_9 ) ) {
T_5 V_305 ;
T_5 V_167 = ( ( ( V_263 * 10 ) + V_264 ) *
( T_5 ) V_11 -> V_151 . V_155 ) /
( 100 * ( T_5 ) V_11 -> V_151 . V_306 ) ;
V_11 -> V_151 . V_167 = ( V_167 / 10 ) & V_307 ;
V_11 -> V_151 . V_167 |= ( ( V_167 - ( V_167 / 10 ) ) << V_308 ) &
V_309 ;
if ( V_11 -> V_151 . type & V_310 )
V_305 = ( 4 * V_167 * V_262 * ( ( T_5 ) V_11 -> V_151 . V_311 * 2048 ) ) /
( 125 * 25 * V_300 -> V_312 / 100 ) ;
else
V_305 = ( 2 * V_167 * V_262 * ( ( T_5 ) V_11 -> V_151 . V_311 * 2048 ) ) /
( 125 * 25 * V_300 -> V_312 / 100 ) ;
V_11 -> V_151 . V_169 = V_305 ;
}
F_29 ( V_9 , V_85 , V_11 -> V_138 ,
V_11 -> V_18 , & V_11 -> V_151 ) ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_313 * V_314 ,
int V_315 , int V_316 , int V_317 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_318 * V_319 ;
struct V_313 * V_320 ;
struct V_321 * V_322 ;
struct V_323 * V_324 ;
T_11 V_325 ;
V_33 V_326 , V_327 , V_328 ;
unsigned V_329 , V_330 , V_331 , V_332 ;
T_5 V_333 = F_57 ( V_334 ) ;
T_5 V_335 , V_336 , V_337 ;
int V_338 ;
bool V_339 = false ;
char * V_340 ;
if ( ! V_317 && ! V_2 -> V_341 -> V_314 ) {
F_58 ( L_2 ) ;
return 0 ;
}
if ( V_317 ) {
V_319 = F_59 ( V_314 ) ;
V_320 = V_314 ;
}
else {
V_319 = F_59 ( V_2 -> V_341 -> V_314 ) ;
V_320 = V_2 -> V_341 -> V_314 ;
}
V_322 = V_319 -> V_322 ;
V_324 = F_60 ( V_322 ) ;
V_338 = F_61 ( V_324 , false ) ;
if ( F_62 ( V_338 != 0 ) )
return V_338 ;
if ( V_317 )
V_325 = F_63 ( V_324 ) ;
else {
V_338 = F_64 ( V_324 , V_342 , & V_325 ) ;
if ( F_62 ( V_338 != 0 ) ) {
F_65 ( V_324 ) ;
return - V_343 ;
}
}
F_66 ( V_324 , & V_328 , NULL ) ;
F_65 ( V_324 ) ;
switch ( V_320 -> V_344 ) {
case V_345 :
V_326 = ( F_67 ( V_346 ) |
F_68 ( V_347 ) ) ;
break;
case V_348 :
case V_349 :
V_326 = ( F_67 ( V_350 ) |
F_68 ( V_351 ) ) ;
#ifdef F_69
V_333 = F_57 ( V_352 ) ;
#endif
break;
case V_353 :
case V_354 :
V_326 = ( F_67 ( V_350 ) |
F_68 ( V_355 ) ) ;
#ifdef F_69
V_333 = F_57 ( V_352 ) ;
#endif
break;
case V_356 :
case V_357 :
V_326 = ( F_67 ( V_350 ) |
F_68 ( V_358 ) ) ;
#ifdef F_69
V_333 = F_57 ( V_352 ) ;
#endif
break;
case V_359 :
V_326 = ( F_67 ( V_350 ) |
F_68 ( V_360 ) ) ;
#ifdef F_69
V_333 = F_57 ( V_352 ) ;
#endif
break;
case V_361 :
case V_362 :
V_326 = ( F_67 ( V_363 ) |
F_68 ( V_364 ) ) ;
#ifdef F_69
V_333 = F_57 ( V_365 ) ;
#endif
break;
case V_366 :
case V_367 :
V_326 = ( F_67 ( V_363 ) |
F_68 ( V_368 ) ) ;
#ifdef F_69
V_333 = F_57 ( V_365 ) ;
#endif
V_339 = true ;
break;
case V_369 :
case V_370 :
V_326 = ( F_67 ( V_363 ) |
F_68 ( V_371 ) ) ;
#ifdef F_69
V_333 = F_57 ( V_365 ) ;
#endif
V_339 = true ;
break;
default:
V_340 = F_70 ( V_320 -> V_344 ) ;
F_44 ( L_3 , V_340 ) ;
F_71 ( V_340 ) ;
return - V_343 ;
}
if ( V_328 & V_372 ) {
F_72 ( V_328 , & V_329 , & V_330 , & V_331 , & V_332 ) ;
if ( V_9 -> V_69 >= V_373 ) {
unsigned V_12 , V_374 ;
if ( V_9 -> V_69 >= V_375 ) {
unsigned V_376 , V_377 ;
V_377 = 64 << V_332 ;
V_376 = 8 * 8 * V_320 -> V_378 / 8 ;
V_376 = F_73 ( V_377 , V_376 ) ;
for ( V_12 = 0 ; V_376 > 64 ; V_12 ++ )
V_376 >>= 1 ;
if ( V_12 >= 16 ) {
F_44 ( L_4 ,
V_320 -> V_378 , V_332 ) ;
return - V_343 ;
}
V_374 = ( V_9 -> V_379 . V_380 . V_381 [ V_12 ] >> 6 ) & 0x3 ;
} else {
switch ( V_320 -> V_378 ) {
case 8 :
V_12 = 10 ;
break;
case 16 :
V_12 = V_382 ;
break;
default:
case 32 :
V_12 = V_383 ;
break;
}
V_374 = ( V_9 -> V_379 . V_384 . V_385 [ V_12 ] >> 20 ) & 0x3 ;
}
V_326 |= F_74 ( V_374 ) ;
} else {
if ( V_9 -> V_69 >= V_386 )
V_335 = V_9 -> V_379 . V_387 . V_388 ;
else
V_335 = V_9 -> V_379 . V_389 . V_388 ;
switch ( ( V_335 & 0xf0 ) >> 4 ) {
case 0 :
V_326 |= F_74 ( V_390 ) ;
break;
case 1 :
default:
V_326 |= F_74 ( V_391 ) ;
break;
case 2 :
V_326 |= F_74 ( V_392 ) ;
break;
}
}
V_326 |= F_75 ( V_393 ) ;
V_326 |= F_76 ( V_332 ) ;
V_326 |= F_77 ( V_329 ) ;
V_326 |= F_78 ( V_330 ) ;
V_326 |= F_79 ( V_331 ) ;
if ( V_9 -> V_69 >= V_375 ) {
V_326 |= F_80 ( V_394 ) ;
}
} else if ( V_328 & V_395 )
V_326 |= F_75 ( V_396 ) ;
if ( V_9 -> V_69 >= V_375 ) {
T_5 V_397 = ( V_9 -> V_379 . V_380 . V_385 [ 10 ] >> 6 ) & 0x1f ;
V_326 |= F_81 ( V_397 ) ;
} else if ( ( V_9 -> V_69 == V_373 ) ||
( V_9 -> V_69 == V_398 ) )
V_326 |= F_82 ( V_399 ) ;
else if ( ( V_9 -> V_69 == V_400 ) ||
( V_9 -> V_69 == V_401 ) ||
( V_9 -> V_69 == V_402 ) )
V_326 |= F_82 ( V_403 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_16 ( V_404 , 0 ) ;
break;
case 1 :
F_16 ( V_405 , 0 ) ;
break;
case 2 :
F_16 ( V_406 , 0 ) ;
break;
case 3 :
F_16 ( V_407 , 0 ) ;
break;
case 4 :
F_16 ( V_408 , 0 ) ;
break;
case 5 :
F_16 ( V_409 , 0 ) ;
break;
default:
break;
}
F_16 ( V_410 + V_11 -> V_411 , 0 ) ;
F_16 ( V_412 + V_11 -> V_411 ,
F_83 ( V_325 ) ) ;
F_16 ( V_413 + V_11 -> V_411 ,
F_83 ( V_325 ) ) ;
F_16 ( V_414 + V_11 -> V_411 ,
( T_5 ) V_325 & V_415 ) ;
F_16 ( V_416 + V_11 -> V_411 ,
( T_5 ) V_325 & V_415 ) ;
F_16 ( V_417 + V_11 -> V_411 , V_326 ) ;
F_16 ( V_418 + V_11 -> V_411 , V_333 ) ;
F_84 ( V_419 + V_11 -> V_411 ,
( V_339 ? V_420 : 0 ) ,
~ V_420 ) ;
if ( V_339 )
F_58 ( L_5 ) ;
F_16 ( V_421 + V_11 -> V_411 , 0 ) ;
F_16 ( V_422 + V_11 -> V_411 , 0 ) ;
F_16 ( V_423 + V_11 -> V_411 , 0 ) ;
F_16 ( V_424 + V_11 -> V_411 , 0 ) ;
F_16 ( V_425 + V_11 -> V_411 , V_320 -> V_426 ) ;
F_16 ( V_427 + V_11 -> V_411 , V_320 -> V_428 ) ;
V_327 = V_320 -> V_429 [ 0 ] / ( V_320 -> V_378 / 8 ) ;
F_16 ( V_430 + V_11 -> V_411 , V_327 ) ;
F_16 ( V_431 + V_11 -> V_411 , 1 ) ;
if ( V_9 -> V_69 >= V_375 )
F_16 ( V_432 + V_11 -> V_411 ,
V_320 -> V_428 ) ;
else
F_16 ( V_433 + V_11 -> V_411 ,
V_320 -> V_428 ) ;
V_315 &= ~ 3 ;
V_316 &= ~ 1 ;
F_16 ( V_434 + V_11 -> V_411 ,
( V_315 << 16 ) | V_316 ) ;
V_336 = V_2 -> V_4 . V_435 ;
V_337 = ( V_2 -> V_4 . V_436 + 1 ) & ~ 1 ;
if ( ( V_9 -> V_69 >= V_375 ) &&
( V_2 -> V_4 . V_109 & V_116 ) )
V_337 *= 2 ;
F_16 ( V_437 + V_11 -> V_411 ,
( V_336 << 16 ) | V_337 ) ;
F_16 ( V_438 + V_11 -> V_411 , 0 ) ;
if ( ! V_317 && V_314 && V_314 != V_2 -> V_341 -> V_314 ) {
V_319 = F_59 ( V_314 ) ;
V_324 = F_60 ( V_319 -> V_322 ) ;
V_338 = F_61 ( V_324 , false ) ;
if ( F_62 ( V_338 != 0 ) )
return V_338 ;
F_85 ( V_324 ) ;
F_65 ( V_324 ) ;
}
F_86 ( V_9 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_313 * V_314 ,
int V_315 , int V_316 , int V_317 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_318 * V_319 ;
struct V_321 * V_322 ;
struct V_323 * V_324 ;
struct V_313 * V_320 ;
T_11 V_325 ;
V_33 V_326 , V_327 , V_328 ;
T_5 V_333 = V_439 ;
T_5 V_336 , V_337 ;
int V_338 ;
bool V_339 = false ;
char * V_340 ;
if ( ! V_317 && ! V_2 -> V_341 -> V_314 ) {
F_58 ( L_2 ) ;
return 0 ;
}
if ( V_317 ) {
V_319 = F_59 ( V_314 ) ;
V_320 = V_314 ;
}
else {
V_319 = F_59 ( V_2 -> V_341 -> V_314 ) ;
V_320 = V_2 -> V_341 -> V_314 ;
}
V_322 = V_319 -> V_322 ;
V_324 = F_60 ( V_322 ) ;
V_338 = F_61 ( V_324 , false ) ;
if ( F_62 ( V_338 != 0 ) )
return V_338 ;
if ( V_317 )
V_325 = F_63 ( V_324 ) ;
else {
V_338 = F_64 ( V_324 , V_342 , & V_325 ) ;
if ( F_62 ( V_338 != 0 ) ) {
F_65 ( V_324 ) ;
return - V_343 ;
}
}
F_66 ( V_324 , & V_328 , NULL ) ;
F_65 ( V_324 ) ;
switch ( V_320 -> V_344 ) {
case V_345 :
V_326 =
V_440 |
V_441 ;
break;
case V_348 :
case V_349 :
V_326 =
V_442 |
V_443 ;
#ifdef F_69
V_333 = V_444 ;
#endif
break;
case V_353 :
V_326 =
V_442 |
V_445 ;
#ifdef F_69
V_333 = V_444 ;
#endif
break;
case V_359 :
V_326 =
V_442 |
V_446 ;
#ifdef F_69
V_333 = V_444 ;
#endif
break;
case V_361 :
case V_362 :
V_326 =
V_447 |
V_448 ;
#ifdef F_69
V_333 = V_449 ;
#endif
break;
case V_366 :
case V_367 :
V_326 =
V_447 |
V_450 ;
#ifdef F_69
V_333 = V_449 ;
#endif
V_339 = true ;
break;
default:
V_340 = F_70 ( V_320 -> V_344 ) ;
F_44 ( L_3 , V_340 ) ;
F_71 ( V_340 ) ;
return - V_343 ;
}
if ( V_9 -> V_69 >= V_451 ) {
if ( V_328 & V_372 )
V_326 |= V_452 ;
else if ( V_328 & V_395 )
V_326 |= V_453 ;
} else {
if ( V_328 & V_372 )
V_326 |= V_454 ;
if ( V_328 & V_395 )
V_326 |= V_455 ;
}
if ( V_11 -> V_18 == 0 )
F_16 ( V_404 , 0 ) ;
else
F_16 ( V_405 , 0 ) ;
F_16 ( V_456 + V_11 -> V_411 , 0 ) ;
if ( V_9 -> V_69 >= V_200 ) {
if ( V_11 -> V_18 ) {
F_16 ( V_457 , F_83 ( V_325 ) ) ;
F_16 ( V_458 , F_83 ( V_325 ) ) ;
} else {
F_16 ( V_459 , F_83 ( V_325 ) ) ;
F_16 ( V_460 , F_83 ( V_325 ) ) ;
}
}
F_16 ( V_461 + V_11 -> V_411 ,
( T_5 ) V_325 ) ;
F_16 ( V_462 +
V_11 -> V_411 , ( T_5 ) V_325 ) ;
F_16 ( V_463 + V_11 -> V_411 , V_326 ) ;
if ( V_9 -> V_69 >= V_451 )
F_16 ( V_464 + V_11 -> V_411 , V_333 ) ;
F_84 ( V_465 + V_11 -> V_411 ,
( V_339 ? V_466 : 0 ) , ~ V_466 ) ;
if ( V_339 )
F_58 ( L_5 ) ;
F_16 ( V_467 + V_11 -> V_411 , 0 ) ;
F_16 ( V_468 + V_11 -> V_411 , 0 ) ;
F_16 ( V_469 + V_11 -> V_411 , 0 ) ;
F_16 ( V_470 + V_11 -> V_411 , 0 ) ;
F_16 ( V_471 + V_11 -> V_411 , V_320 -> V_426 ) ;
F_16 ( V_472 + V_11 -> V_411 , V_320 -> V_428 ) ;
V_327 = V_320 -> V_429 [ 0 ] / ( V_320 -> V_378 / 8 ) ;
F_16 ( V_473 + V_11 -> V_411 , V_327 ) ;
F_16 ( V_474 + V_11 -> V_411 , 1 ) ;
F_16 ( V_475 + V_11 -> V_411 ,
V_320 -> V_428 ) ;
V_315 &= ~ 3 ;
V_316 &= ~ 1 ;
F_16 ( V_476 + V_11 -> V_411 ,
( V_315 << 16 ) | V_316 ) ;
V_336 = V_2 -> V_4 . V_435 ;
V_337 = ( V_2 -> V_4 . V_436 + 1 ) & ~ 1 ;
F_16 ( V_477 + V_11 -> V_411 ,
( V_336 << 16 ) | V_337 ) ;
F_16 ( V_478 + V_11 -> V_411 , 3 ) ;
if ( ! V_317 && V_314 && V_314 != V_2 -> V_341 -> V_314 ) {
V_319 = F_59 ( V_314 ) ;
V_324 = F_60 ( V_319 -> V_322 ) ;
V_338 = F_61 ( V_324 , false ) ;
if ( F_62 ( V_338 != 0 ) )
return V_338 ;
F_85 ( V_324 ) ;
F_65 ( V_324 ) ;
}
F_86 ( V_9 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , int V_315 , int V_316 ,
struct V_313 * V_479 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_56 ( V_2 , V_479 , V_315 , V_316 , 0 ) ;
else if ( F_8 ( V_9 ) )
return F_87 ( V_2 , V_479 , V_315 , V_316 , 0 ) ;
else
return F_89 ( V_2 , V_479 , V_315 , V_316 , 0 ) ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_313 * V_314 ,
int V_315 , int V_316 , enum V_480 V_74 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) )
return F_56 ( V_2 , V_314 , V_315 , V_316 , 1 ) ;
else if ( F_8 ( V_9 ) )
return F_87 ( V_2 , V_314 , V_315 , V_316 , 1 ) ;
else
return F_89 ( V_2 , V_314 , V_315 , V_316 , 1 ) ;
}
static void F_91 ( struct V_1 * V_2 )
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
static T_5 F_92 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_490 ;
struct V_11 * V_491 ;
T_5 V_492 = 0 ;
F_93 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_490 )
continue;
V_491 = F_2 ( V_490 ) ;
if ( V_491 -> V_138 != V_146 )
V_492 |= ( 1 << V_491 -> V_138 ) ;
}
return V_492 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_490 ;
struct V_11 * V_491 ;
F_93 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_490 )
continue;
V_491 = F_2 ( V_490 ) ;
if ( V_491 -> V_36 &&
F_42 ( F_33 ( V_491 -> V_36 ) ) ) {
if ( F_37 ( V_9 ) && ! F_14 ( V_9 ) &&
V_491 -> V_138 == V_143 )
continue;
if ( V_491 -> V_138 != V_146 )
return V_491 -> V_138 ;
}
}
return V_146 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_490 ;
struct V_11 * V_491 ;
T_5 V_188 , V_493 ;
V_188 = V_11 -> V_188 ;
if ( V_188 == 0 )
return V_146 ;
F_93 (test_crtc, &dev->mode_config.crtc_list, head) {
if ( V_2 == V_490 )
continue;
V_491 = F_2 ( V_490 ) ;
if ( V_491 -> V_36 &&
! F_42 ( F_33 ( V_491 -> V_36 ) ) ) {
if ( F_37 ( V_9 ) && ! F_14 ( V_9 ) &&
V_491 -> V_138 == V_143 )
continue;
if ( V_491 -> V_187 == V_11 -> V_187 ) {
if ( V_491 -> V_138 != V_146 )
return V_491 -> V_138 ;
}
V_493 = V_491 -> V_188 ;
if ( ( V_2 -> V_4 . clock == V_490 -> V_4 . clock ) &&
( V_188 == V_493 ) &&
( V_11 -> V_205 == V_491 -> V_205 ) &&
( V_491 -> V_138 != V_146 ) )
return V_491 -> V_138 ;
}
}
return V_146 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
T_5 V_492 ;
int V_300 ;
if ( F_14 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_146 ;
else {
V_300 = F_94 ( V_2 ) ;
if ( V_300 != V_146 )
return V_300 ;
}
} else {
V_300 = F_95 ( V_2 ) ;
if ( V_300 != V_146 )
return V_300 ;
}
if ( ( V_9 -> V_69 == V_495 ) ||
( V_9 -> V_69 == V_496 ) ) {
V_492 = F_92 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_143 ) ) )
return V_143 ;
if ( ! ( V_492 & ( 1 << V_140 ) ) )
return V_140 ;
F_44 ( L_6 ) ;
return V_146 ;
} else {
V_492 = F_92 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_143 ) ) )
return V_143 ;
if ( ! ( V_492 & ( 1 << V_140 ) ) )
return V_140 ;
if ( ! ( V_492 & ( 1 << V_261 ) ) )
return V_261 ;
F_44 ( L_6 ) ;
return V_146 ;
}
} else if ( F_37 ( V_9 ) ) {
struct V_242 * V_243 =
V_35 -> V_46 ;
if ( ( V_35 -> V_221 == V_497 ) &&
( V_243 -> V_498 == false ) )
return V_143 ;
else if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_146 ;
else {
V_300 = F_94 ( V_2 ) ;
if ( V_300 != V_146 )
return V_300 ;
}
} else {
V_300 = F_95 ( V_2 ) ;
if ( V_300 != V_146 )
return V_300 ;
}
V_492 = F_92 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_261 ) ) )
return V_261 ;
if ( ! ( V_492 & ( 1 << V_140 ) ) )
return V_140 ;
F_44 ( L_6 ) ;
return V_146 ;
} else if ( F_36 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_146 ;
}
V_492 = F_92 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_140 ) ) )
return V_140 ;
if ( ! ( V_492 & ( 1 << V_143 ) ) )
return V_143 ;
F_44 ( L_6 ) ;
return V_146 ;
} else if ( F_28 ( V_9 ) ) {
if ( F_42 ( F_33 ( V_11 -> V_36 ) ) ) {
if ( V_9 -> clock . V_494 )
return V_146 ;
else if ( F_20 ( V_9 ) )
return V_261 ;
else if ( F_30 ( V_9 ) )
return V_145 ;
else {
V_300 = F_94 ( V_2 ) ;
if ( V_300 != V_146 )
return V_300 ;
}
} else {
V_300 = F_95 ( V_2 ) ;
if ( V_300 != V_146 )
return V_300 ;
}
V_492 = F_92 ( V_2 ) ;
if ( ! ( V_492 & ( 1 << V_140 ) ) )
return V_140 ;
if ( ! ( V_492 & ( 1 << V_143 ) ) )
return V_143 ;
F_44 ( L_6 ) ;
return V_146 ;
} else {
return V_11 -> V_18 ;
}
}
void F_97 ( struct V_8 * V_9 )
{
if ( F_20 ( V_9 ) )
F_45 ( V_9 , V_9 -> clock . V_499 ) ;
else if ( F_28 ( V_9 ) ) {
struct V_150 V_151 ;
bool V_205 = F_51 ( V_9 , & V_151 ,
V_500 ,
V_9 -> clock . V_499 ) ;
if ( V_205 )
F_29 ( V_9 , V_86 , V_145 , - 1 , & V_151 ) ;
F_45 ( V_9 , V_9 -> clock . V_499 ) ;
if ( V_205 )
F_29 ( V_9 , V_85 , V_145 , - 1 , & V_151 ) ;
}
}
int F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_315 , int V_316 , struct V_313 * V_479 )
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
if ( ! V_11 -> V_188 )
return - V_343 ;
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
F_91 ( V_2 ) ;
}
F_88 ( V_2 , V_315 , V_316 , V_479 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
F_99 ( V_2 ) ;
V_11 -> V_503 = * V_5 ;
return 0 ;
}
static bool F_100 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_185 * V_36 ;
F_93 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_36 -> V_2 == V_2 ) {
V_11 -> V_36 = V_36 ;
V_11 -> V_187 = F_32 ( V_36 ) ;
break;
}
}
if ( ( V_11 -> V_36 == NULL ) || ( V_11 -> V_187 == NULL ) ) {
V_11 -> V_36 = NULL ;
V_11 -> V_187 = NULL ;
return false ;
}
if ( V_11 -> V_36 ) {
struct V_35 * V_35 =
F_7 ( V_11 -> V_36 ) ;
V_11 -> V_504 = V_35 -> V_504 ;
}
if ( ! F_101 ( V_2 , V_4 , V_5 ) )
return false ;
if ( ! F_48 ( V_2 , V_5 ) )
return false ;
V_11 -> V_138 = F_96 ( V_2 ) ;
if ( ( V_11 -> V_138 == V_146 ) &&
! F_42 ( F_33 ( V_11 -> V_36 ) ) )
return false ;
return true ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_86 ) ;
F_10 ( V_2 , V_85 ) ;
F_18 ( V_2 , V_90 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_83 ) ;
F_10 ( V_2 , V_86 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_150 V_151 ;
int V_152 ;
F_18 ( V_2 , V_90 ) ;
if ( V_2 -> V_341 -> V_314 ) {
int V_338 ;
struct V_318 * V_319 ;
struct V_323 * V_324 ;
V_319 = F_59 ( V_2 -> V_341 -> V_314 ) ;
V_324 = F_60 ( V_319 -> V_322 ) ;
V_338 = F_61 ( V_324 , false ) ;
if ( F_62 ( V_338 ) )
F_44 ( L_7 ) ;
else {
F_85 ( V_324 ) ;
F_65 ( V_324 ) ;
}
}
if ( F_28 ( V_9 ) )
F_16 ( V_431 + V_11 -> V_411 , 0 ) ;
else if ( F_8 ( V_9 ) )
F_16 ( V_474 + V_11 -> V_411 , 0 ) ;
if ( F_20 ( V_9 ) )
F_17 ( V_2 , V_85 ) ;
for ( V_152 = 0 ; V_152 < V_9 -> V_157 ; V_152 ++ ) {
if ( V_9 -> V_31 . V_158 [ V_152 ] &&
V_9 -> V_31 . V_158 [ V_152 ] -> V_84 &&
V_152 != V_11 -> V_18 &&
V_11 -> V_138 == V_9 -> V_31 . V_158 [ V_152 ] -> V_138 ) {
goto V_505;
}
}
switch ( V_11 -> V_138 ) {
case V_140 :
case V_143 :
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_138 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_151 ) ;
break;
case V_261 :
if ( ( V_9 -> V_69 == V_506 ) ||
( V_9 -> V_69 == V_507 ) ||
( V_9 -> V_69 == V_375 ) ||
( V_9 -> V_69 == V_508 ) )
F_47 ( V_2 , V_11 -> V_18 , V_11 -> V_138 ,
0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , false , & V_151 ) ;
break;
default:
break;
}
V_505:
V_11 -> V_138 = V_146 ;
V_11 -> V_188 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_187 = NULL ;
}
void F_105 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_28 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_411 = V_509 ;
break;
case 1 :
V_11 -> V_411 = V_510 ;
break;
case 2 :
V_11 -> V_411 = V_511 ;
break;
case 3 :
V_11 -> V_411 = V_512 ;
break;
case 4 :
V_11 -> V_411 = V_513 ;
break;
case 5 :
V_11 -> V_411 = V_514 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_411 =
V_515 - V_516 ;
else
V_11 -> V_411 = 0 ;
}
V_11 -> V_138 = V_146 ;
V_11 -> V_188 = 0 ;
V_11 -> V_36 = NULL ;
V_11 -> V_187 = NULL ;
F_106 ( & V_11 -> V_517 , & V_518 ) ;
}
