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
static void F_15 ( struct V_1 * V_2 , int V_75 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_12 = F_3 ( V_13 , V_80 ) ;
T_5 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_81 = V_11 -> V_18 ;
args . V_64 = V_75 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
void F_16 ( struct V_1 * V_2 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_82 :
V_11 -> V_83 = true ;
F_17 ( V_9 ) ;
if ( F_18 ( V_9 ) && ! V_11 -> V_84 )
F_15 ( V_2 , V_85 ) ;
F_12 ( V_2 , V_86 ) ;
if ( F_19 ( V_9 ) && ! F_18 ( V_9 ) )
F_13 ( V_2 , V_86 ) ;
F_14 ( V_2 , V_85 ) ;
F_20 ( V_7 , V_11 -> V_18 ) ;
F_21 ( V_2 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
F_22 ( V_7 , V_11 -> V_18 ) ;
if ( V_11 -> V_83 )
F_14 ( V_2 , V_86 ) ;
if ( F_19 ( V_9 ) && ! F_18 ( V_9 ) )
F_13 ( V_2 , V_85 ) ;
F_12 ( V_2 , V_85 ) ;
V_11 -> V_83 = false ;
if ( F_18 ( V_9 ) && ! V_11 -> V_84 )
F_15 ( V_2 , V_86 ) ;
F_17 ( V_9 ) ;
break;
}
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_6 args ;
int V_12 = F_3 ( V_13 , V_90 ) ;
T_7 V_91 = 0 ;
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
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_8 args ;
int V_12 = F_3 ( V_13 , V_121 ) ;
T_7 V_91 = 0 ;
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
static void F_25 ( struct V_8 * V_9 , int V_134 )
{
T_9 V_135 ;
if ( F_26 ( V_9 ) ) {
switch ( V_134 ) {
case V_136 :
V_135 = F_27 ( V_137 ) ;
V_135 &= ~ V_138 ;
F_28 ( V_137 , V_135 ) ;
break;
case V_139 :
V_135 = F_27 ( V_140 ) ;
V_135 &= ~ V_138 ;
F_28 ( V_140 , V_135 ) ;
break;
case V_141 :
case V_142 :
return;
}
} else if ( F_7 ( V_9 ) ) {
switch ( V_134 ) {
case V_136 :
V_135 = F_27 ( V_143 ) ;
V_135 &= ~ 1 ;
F_28 ( V_143 , V_135 ) ;
break;
case V_139 :
V_135 = F_27 ( V_144 ) ;
V_135 &= ~ 1 ;
F_28 ( V_144 , V_135 ) ;
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
if ( ! V_145 ) {
for ( V_148 = 0 ; V_148 < V_9 -> V_151 ; V_148 ++ ) {
if ( V_9 -> V_31 . V_152 [ V_148 ] &&
V_9 -> V_31 . V_152 [ V_148 ] -> V_83 &&
V_148 != V_18 &&
V_134 == V_9 -> V_31 . V_152 [ V_148 ] -> V_134 ) {
return;
}
}
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_30 ( V_9 ) ) {
args . V_153 . V_154 = F_4 ( 0 ) ;
args . V_153 . V_155 = V_147 -> type & V_156 ;
switch ( V_134 ) {
case V_136 :
args . V_153 . V_155 |= V_157 ;
break;
case V_139 :
args . V_153 . V_155 |= V_158 ;
break;
case V_141 :
args . V_153 . V_155 |= V_159 ;
break;
case V_142 :
return;
}
args . V_153 . V_160 = F_4 ( V_147 -> V_161 ) ;
args . V_153 . V_162 = F_4 ( V_147 -> V_163 ) ;
args . V_153 . V_64 = V_145 ;
if ( ( V_147 -> V_164 == 0 ) || ( V_147 -> type & V_165 ) || F_31 ( V_9 ) )
args . V_153 . V_64 = V_85 ;
} else if ( F_26 ( V_9 ) ) {
args . V_166 . V_167 = F_4 ( V_147 -> V_164 ) ;
args . V_166 . V_155 = V_147 -> type & V_156 ;
switch ( V_134 ) {
case V_136 :
args . V_166 . V_155 |= V_168 ;
break;
case V_139 :
args . V_166 . V_155 |= V_169 ;
break;
case V_141 :
args . V_166 . V_155 |= V_170 ;
break;
case V_142 :
return;
}
args . V_166 . V_160 = F_4 ( V_147 -> V_161 ) ;
args . V_166 . V_162 = F_4 ( V_147 -> V_163 ) ;
args . V_166 . V_64 = V_145 ;
if ( ( V_147 -> V_164 == 0 ) || ( V_147 -> type & V_165 ) || F_32 ( V_9 ) )
args . V_166 . V_64 = V_85 ;
} else if ( F_19 ( V_9 ) ) {
args . V_171 . V_167 = F_4 ( V_147 -> V_164 ) ;
args . V_171 . V_155 = V_147 -> type & V_156 ;
args . V_171 . V_172 = V_147 -> V_163 ;
args . V_171 . V_173 = V_147 -> V_174 ;
args . V_171 . V_175 = V_147 -> V_176 ;
args . V_171 . V_177 = V_134 ;
args . V_171 . V_64 = V_145 ;
} else if ( F_7 ( V_9 ) ) {
if ( ( V_145 == V_85 ) || ( V_147 -> V_164 == 0 ) ||
( V_147 -> type & V_165 ) ) {
F_25 ( V_9 , V_134 ) ;
return;
}
args . V_178 . V_167 = F_4 ( V_147 -> V_164 ) ;
args . V_178 . V_155 = V_147 -> type & V_156 ;
args . V_178 . V_172 = V_147 -> V_163 ;
args . V_178 . V_173 = V_147 -> V_174 ;
args . V_178 . V_175 = V_147 -> V_176 ;
args . V_178 . V_64 = V_145 ;
} else {
if ( ( V_145 == V_85 ) || ( V_147 -> V_164 == 0 ) ||
( V_147 -> type & V_165 ) ) {
F_25 ( V_9 , V_134 ) ;
return;
}
args . V_179 . V_167 = F_4 ( V_147 -> V_164 ) ;
args . V_179 . V_155 = V_147 -> type & V_156 ;
args . V_179 . V_180 = ( V_147 -> V_163 & 3 ) << 2 ;
args . V_179 . V_180 |= ( V_147 -> V_174 & 7 ) << 4 ;
args . V_179 . V_64 = V_145 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_9 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_181 * V_182 ,
bool V_183 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_42 = NULL ;
struct V_184 * V_185 = NULL ;
T_9 V_186 = V_4 -> clock ;
int V_187 = 0 ;
T_9 V_188 = V_4 -> clock ;
int V_189 = 8 ;
bool V_190 = false ;
V_182 -> V_108 = 0 ;
if ( F_7 ( V_9 ) ) {
if ( ( V_9 -> V_70 == V_191 ) ||
( V_9 -> V_70 == V_192 ) ||
( V_9 -> V_70 == V_193 ) )
V_182 -> V_108 |= (
V_194 ) ;
if ( F_34 ( V_9 ) && V_4 -> clock > 200000 )
V_182 -> V_108 |= V_195 ;
else
V_182 -> V_108 |= V_196 ;
if ( V_9 -> V_70 < V_197 )
V_182 -> V_108 |= V_198 ;
if ( F_32 ( V_9 ) || F_31 ( V_9 ) )
V_182 -> V_108 |= V_199 ;
} else {
V_182 -> V_108 |= V_200 ;
if ( V_4 -> clock > 200000 )
V_182 -> V_108 |= V_195 ;
else
V_182 -> V_108 |= V_196 ;
}
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_185 = F_35 ( V_41 ) ;
V_189 = F_36 ( V_185 ) ;
V_187 = F_37 ( V_41 ) ;
V_190 = F_38 ( V_41 , V_4 -> clock ) ;
if ( ( V_42 -> V_201 & ( V_202 | V_203 ) ) ||
( F_39 ( V_41 ) != V_204 ) ) {
if ( V_185 ) {
struct V_205 * V_205 = F_40 ( V_185 ) ;
struct V_206 * V_207 =
V_205 -> V_208 ;
V_188 = V_207 -> V_188 ;
}
}
if ( V_42 -> V_201 & ( V_202 ) ) {
if ( V_183 ) {
if ( V_147 -> V_209 ) {
V_182 -> V_108 |= V_210 ;
V_182 -> V_211 = V_147 -> V_209 ;
if ( F_7 ( V_9 ) )
V_182 -> V_108 |= V_199 ;
}
}
}
if ( F_7 ( V_9 ) ) {
if ( V_42 -> V_212 == V_213 )
V_186 = V_4 -> clock * 2 ;
if ( V_42 -> V_43 & ( V_44 ) )
V_182 -> V_108 |= V_194 ;
if ( V_42 -> V_201 & ( V_202 ) )
V_182 -> V_108 |= V_214 ;
} else {
if ( V_41 -> V_215 != V_216 )
V_182 -> V_108 |= V_217 ;
if ( V_41 -> V_215 == V_218 )
V_182 -> V_108 |= V_210 ;
}
break;
}
}
if ( F_19 ( V_9 ) ) {
union V_219 args ;
T_10 V_220 , V_221 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_222 ) ;
if ( ! F_41 ( V_9 -> V_31 . V_32 , V_12 , & V_220 ,
& V_221 ) )
return V_186 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_220 ) {
case 1 :
switch ( V_221 ) {
case 1 :
case 2 :
args . V_171 . V_223 = F_4 ( V_4 -> clock / 10 ) ;
args . V_171 . V_224 = V_42 -> V_212 ;
args . V_171 . V_225 = V_187 ;
if ( V_183 && V_147 -> V_164 )
args . V_171 . V_226 |=
V_227 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_186 = F_42 ( args . V_171 . V_223 ) * 10 ;
break;
case 3 :
args . V_153 . V_228 . V_223 = F_4 ( V_4 -> clock / 10 ) ;
args . V_153 . V_228 . V_224 = V_42 -> V_212 ;
args . V_153 . V_228 . V_225 = V_187 ;
args . V_153 . V_228 . V_229 = 0 ;
if ( V_183 && V_147 -> V_164 )
args . V_153 . V_228 . V_229 |=
V_230 ;
if ( F_43 ( V_187 ) ) {
args . V_153 . V_228 . V_229 |=
V_231 ;
args . V_153 . V_228 . V_223 = F_4 ( V_188 / 10 ) ;
} else if ( V_42 -> V_201 & ( V_203 ) ) {
struct V_232 * V_233 = V_42 -> V_47 ;
if ( V_187 == V_234 )
args . V_153 . V_228 . V_223 =
F_4 ( ( V_4 -> clock * V_189 / 8 ) / 10 ) ;
if ( V_233 -> V_235 )
args . V_153 . V_228 . V_229 |=
V_231 ;
if ( V_190 )
args . V_153 . V_228 . V_229 |=
V_236 ;
}
if ( F_39 ( V_41 ) !=
V_204 )
args . V_153 . V_228 . V_237 =
F_39 ( V_41 ) ;
else
args . V_153 . V_228 . V_237 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_186 = F_44 ( args . V_153 . V_238 . V_239 ) * 10 ;
if ( args . V_153 . V_238 . V_240 ) {
V_182 -> V_108 |= V_199 ;
V_182 -> V_108 |= V_210 ;
V_182 -> V_211 = args . V_153 . V_238 . V_240 ;
}
if ( args . V_153 . V_238 . V_241 ) {
V_182 -> V_108 |= V_199 ;
V_182 -> V_108 |= V_242 ;
V_182 -> V_243 = args . V_153 . V_238 . V_241 ;
}
break;
default:
F_45 ( L_1 , V_220 , V_221 ) ;
return V_186 ;
}
break;
default:
F_45 ( L_1 , V_220 , V_221 ) ;
return V_186 ;
}
}
return V_186 ;
}
static void F_46 ( struct V_8 * V_9 ,
T_9 V_244 )
{
T_10 V_220 , V_221 ;
int V_12 ;
union V_245 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_246 ) ;
if ( ! F_41 ( V_9 -> V_31 . V_32 , V_12 , & V_220 ,
& V_221 ) )
return;
switch ( V_220 ) {
case 1 :
switch ( V_221 ) {
case 5 :
args . V_247 . V_17 = V_248 ;
args . V_247 . V_223 = F_4 ( V_244 ) ;
args . V_247 . V_177 = V_141 ;
break;
case 6 :
args . V_249 . V_250 = F_47 ( V_244 ) ;
if ( F_31 ( V_9 ) )
args . V_249 . V_177 = V_251 ;
else if ( F_18 ( V_9 ) )
args . V_249 . V_177 = V_252 ;
else
args . V_249 . V_177 = V_141 ;
break;
default:
F_45 ( L_1 , V_220 , V_221 ) ;
return;
}
break;
default:
F_45 ( L_1 , V_220 , V_221 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_48 ( struct V_1 * V_2 ,
T_9 V_18 ,
int V_134 ,
T_9 V_187 ,
T_9 V_212 ,
T_9 clock ,
T_9 V_253 ,
T_9 V_254 ,
T_9 V_255 ,
T_9 V_243 ,
int V_189 ,
bool V_183 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_10 V_220 , V_221 ;
int V_12 = F_3 ( V_13 , V_246 ) ;
union V_245 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_41 ( V_9 -> V_31 . V_32 , V_12 , & V_220 ,
& V_221 ) )
return;
switch ( V_220 ) {
case 1 :
switch ( V_221 ) {
case 1 :
if ( clock == V_85 )
return;
args . V_171 . V_223 = F_4 ( clock / 10 ) ;
args . V_171 . V_256 = F_4 ( V_253 ) ;
args . V_171 . V_257 = F_4 ( V_254 ) ;
args . V_171 . V_258 = V_255 ;
args . V_171 . V_241 = V_243 ;
args . V_171 . V_177 = V_134 ;
args . V_171 . V_17 = V_18 ;
args . V_171 . V_259 = 1 ;
break;
case 2 :
args . V_166 . V_223 = F_4 ( clock / 10 ) ;
args . V_166 . V_256 = F_4 ( V_253 ) ;
args . V_166 . V_257 = F_4 ( V_254 ) ;
args . V_166 . V_258 = V_255 ;
args . V_166 . V_241 = V_243 ;
args . V_166 . V_177 = V_134 ;
args . V_166 . V_17 = V_18 ;
args . V_166 . V_259 = 1 ;
break;
case 3 :
args . V_153 . V_223 = F_4 ( clock / 10 ) ;
args . V_153 . V_256 = F_4 ( V_253 ) ;
args . V_153 . V_257 = F_4 ( V_254 ) ;
args . V_153 . V_258 = V_255 ;
args . V_153 . V_241 = V_243 ;
args . V_153 . V_177 = V_134 ;
args . V_153 . V_260 = ( V_134 << 2 ) ;
if ( V_183 && ( V_147 -> type & V_165 ) )
args . V_153 . V_260 |= V_261 ;
args . V_153 . V_262 = V_212 ;
args . V_153 . V_263 = V_187 ;
break;
case 5 :
args . V_247 . V_17 = V_18 ;
args . V_247 . V_223 = F_4 ( clock / 10 ) ;
args . V_247 . V_240 = V_253 ;
args . V_247 . V_257 = F_4 ( V_254 ) ;
args . V_247 . V_264 = F_47 ( V_255 * 100000 ) ;
args . V_247 . V_241 = V_243 ;
args . V_247 . V_260 = 0 ;
if ( V_183 && ( V_147 -> type & V_165 ) )
args . V_247 . V_260 |= V_265 ;
switch ( V_189 ) {
case 8 :
default:
args . V_247 . V_260 |= V_266 ;
break;
case 10 :
args . V_247 . V_260 |= V_267 ;
break;
}
args . V_247 . V_224 = V_212 ;
args . V_247 . V_263 = V_187 ;
args . V_247 . V_177 = V_134 ;
break;
case 6 :
args . V_249 . V_250 = F_47 ( V_18 << 24 | clock / 10 ) ;
args . V_249 . V_240 = V_253 ;
args . V_249 . V_257 = F_4 ( V_254 ) ;
args . V_249 . V_264 = F_47 ( V_255 * 100000 ) ;
args . V_249 . V_241 = V_243 ;
args . V_249 . V_260 = 0 ;
if ( V_183 && ( V_147 -> type & V_165 ) )
args . V_249 . V_260 |= V_268 ;
switch ( V_189 ) {
case 8 :
default:
args . V_249 . V_260 |= V_269 ;
break;
case 10 :
args . V_249 . V_260 |= V_270 ;
break;
case 12 :
args . V_249 . V_260 |= V_271 ;
break;
case 16 :
args . V_249 . V_260 |= V_272 ;
break;
}
args . V_249 . V_224 = V_212 ;
args . V_249 . V_263 = V_187 ;
args . V_249 . V_177 = V_134 ;
break;
default:
F_45 ( L_1 , V_220 , V_221 ) ;
return;
}
break;
default:
F_45 ( L_1 , V_220 , V_221 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_42 = NULL ;
T_9 V_273 = V_4 -> clock ;
T_9 V_253 = 0 , V_254 = 0 , V_255 = 0 , V_243 = 0 ;
struct V_181 * V_182 ;
T_9 V_186 ;
int V_187 = 0 ;
struct V_146 V_147 ;
bool V_183 = false ;
int V_189 = 8 ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_187 = F_37 ( V_41 ) ;
break;
}
}
if ( ! V_42 )
return;
switch ( V_11 -> V_134 ) {
case V_136 :
V_182 = & V_9 -> clock . V_274 ;
break;
case V_139 :
V_182 = & V_9 -> clock . V_275 ;
break;
case V_141 :
case V_142 :
default:
V_182 = & V_9 -> clock . V_276 ;
break;
}
if ( ( V_42 -> V_43 & ( V_202 | V_203 ) ) ||
( F_39 ( V_41 ) != V_204 ) ) {
struct V_232 * V_233 = V_42 -> V_47 ;
struct V_184 * V_185 =
F_35 ( V_41 ) ;
struct V_205 * V_205 =
F_40 ( V_185 ) ;
struct V_206 * V_207 =
V_205 -> V_208 ;
int V_188 ;
V_189 = F_36 ( V_185 ) ;
switch ( V_187 ) {
case V_277 :
case V_278 :
V_188 = V_207 -> V_188 / 10 ;
if ( F_26 ( V_9 ) )
V_183 =
F_50 ( V_9 , & V_147 ,
V_279 ,
V_188 ) ;
else {
if ( V_188 == 16200 ) {
V_183 =
F_51 ( V_9 , & V_147 ,
V_280 ) ;
if ( ! V_183 )
V_183 =
F_51 ( V_9 , & V_147 ,
V_281 ) ;
} else
V_183 =
F_51 ( V_9 , & V_147 ,
V_281 ) ;
}
break;
case V_282 :
if ( F_26 ( V_9 ) )
V_183 = F_50 ( V_9 , & V_147 ,
V_233 -> V_283 ,
V_4 -> clock / 10 ) ;
else
V_183 = F_51 ( V_9 , & V_147 ,
V_233 -> V_283 ) ;
break;
case V_284 :
if ( F_26 ( V_9 ) )
V_183 =
F_50 ( V_9 , & V_147 ,
V_285 ,
V_4 -> clock / 10 ) ;
break;
case V_234 :
if ( F_26 ( V_9 ) )
V_183 =
F_50 ( V_9 , & V_147 ,
V_286 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_186 = F_33 ( V_2 , V_4 , V_182 , V_183 , & V_147 ) ;
if ( V_42 -> V_43 & ( V_44 ) )
F_52 ( V_182 , V_186 , & V_273 , & V_254 , & V_255 ,
& V_253 , & V_243 ) ;
else if ( F_7 ( V_9 ) )
F_53 ( V_182 , V_186 , & V_273 , & V_254 , & V_255 ,
& V_253 , & V_243 ) ;
else
F_52 ( V_182 , V_186 , & V_273 , & V_254 , & V_255 ,
& V_253 , & V_243 ) ;
F_29 ( V_9 , V_85 , V_11 -> V_134 , V_11 -> V_18 , & V_147 ) ;
F_48 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
V_187 , V_42 -> V_212 , V_4 -> clock ,
V_253 , V_254 , V_255 , V_243 , V_189 , V_183 , & V_147 ) ;
if ( V_183 ) {
if ( F_26 ( V_9 ) ) {
T_9 V_287 ;
T_9 V_161 = ( ( ( V_254 * 10 ) + V_255 ) * V_147 . V_164 ) / 10000 ;
V_147 . V_161 = ( V_161 / 10 ) & V_288 ;
V_147 . V_161 |= ( ( V_161 - ( V_161 / 10 ) ) << V_289 ) &
V_290 ;
if ( V_147 . type & V_291 )
V_287 = ( 4 * V_161 * V_253 * ( V_147 . V_292 * 2048 ) ) /
( 125 * 25 * V_182 -> V_293 / 100 ) ;
else
V_287 = ( 2 * V_161 * V_253 * ( V_147 . V_292 * 2048 ) ) /
( 125 * 25 * V_182 -> V_293 / 100 ) ;
V_147 . V_163 = V_287 ;
}
F_29 ( V_9 , V_86 , V_11 -> V_134 , V_11 -> V_18 , & V_147 ) ;
}
}
static int F_54 ( struct V_1 * V_2 ,
struct V_294 * V_295 ,
int V_296 , int V_297 , int V_298 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_299 * V_300 ;
struct V_294 * V_301 ;
struct V_302 * V_303 ;
struct V_304 * V_305 ;
T_11 V_306 ;
V_33 V_307 , V_308 , V_309 ;
unsigned V_310 , V_311 , V_312 , V_313 ;
T_9 V_314 = F_55 ( V_315 ) ;
T_9 V_316 , V_317 , V_318 ;
int V_319 ;
if ( ! V_298 && ! V_2 -> V_295 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_298 ) {
V_300 = F_57 ( V_295 ) ;
V_301 = V_295 ;
}
else {
V_300 = F_57 ( V_2 -> V_295 ) ;
V_301 = V_2 -> V_295 ;
}
V_303 = V_300 -> V_303 ;
V_305 = F_58 ( V_303 ) ;
V_319 = F_59 ( V_305 , false ) ;
if ( F_60 ( V_319 != 0 ) )
return V_319 ;
if ( V_298 )
V_306 = F_61 ( V_305 ) ;
else {
V_319 = F_62 ( V_305 , V_320 , & V_306 ) ;
if ( F_60 ( V_319 != 0 ) ) {
F_63 ( V_305 ) ;
return - V_321 ;
}
}
F_64 ( V_305 , & V_309 , NULL ) ;
F_63 ( V_305 ) ;
switch ( V_301 -> V_322 ) {
case 8 :
V_307 = ( F_65 ( V_323 ) |
F_66 ( V_324 ) ) ;
break;
case 15 :
V_307 = ( F_65 ( V_325 ) |
F_66 ( V_326 ) ) ;
break;
case 16 :
V_307 = ( F_65 ( V_325 ) |
F_66 ( V_327 ) ) ;
#ifdef F_67
V_314 = F_55 ( V_328 ) ;
#endif
break;
case 24 :
case 32 :
V_307 = ( F_65 ( V_329 ) |
F_66 ( V_330 ) ) ;
#ifdef F_67
V_314 = F_55 ( V_331 ) ;
#endif
break;
default:
F_45 ( L_3 ,
V_301 -> V_322 ) ;
return - V_321 ;
}
if ( V_309 & V_332 ) {
if ( V_9 -> V_70 >= V_333 )
V_316 = V_9 -> V_334 . V_335 . V_336 ;
else if ( V_9 -> V_70 >= V_337 )
V_316 = V_9 -> V_334 . V_338 . V_336 ;
else
V_316 = V_9 -> V_334 . V_339 . V_336 ;
switch ( ( V_316 & 0xf0 ) >> 4 ) {
case 0 :
V_307 |= F_68 ( V_340 ) ;
break;
case 1 :
default:
V_307 |= F_68 ( V_341 ) ;
break;
case 2 :
V_307 |= F_68 ( V_342 ) ;
break;
}
V_307 |= F_69 ( V_343 ) ;
F_70 ( V_309 , & V_310 , & V_311 , & V_312 , & V_313 ) ;
V_307 |= F_71 ( V_313 ) ;
V_307 |= F_72 ( V_310 ) ;
V_307 |= F_73 ( V_311 ) ;
V_307 |= F_74 ( V_312 ) ;
} else if ( V_309 & V_344 )
V_307 |= F_69 ( V_345 ) ;
if ( ( V_9 -> V_70 == V_333 ) ||
( V_9 -> V_70 == V_346 ) )
V_307 |= F_75 ( V_347 ) ;
else if ( V_9 -> V_70 == V_348 )
V_307 |= F_75 ( V_349 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_28 ( V_350 , 0 ) ;
break;
case 1 :
F_28 ( V_351 , 0 ) ;
break;
case 2 :
F_28 ( V_352 , 0 ) ;
break;
case 3 :
F_28 ( V_353 , 0 ) ;
break;
case 4 :
F_28 ( V_354 , 0 ) ;
break;
case 5 :
F_28 ( V_355 , 0 ) ;
break;
default:
break;
}
F_28 ( V_356 + V_11 -> V_357 ,
F_76 ( V_306 ) ) ;
F_28 ( V_358 + V_11 -> V_357 ,
F_76 ( V_306 ) ) ;
F_28 ( V_359 + V_11 -> V_357 ,
( T_9 ) V_306 & V_360 ) ;
F_28 ( V_361 + V_11 -> V_357 ,
( T_9 ) V_306 & V_360 ) ;
F_28 ( V_362 + V_11 -> V_357 , V_307 ) ;
F_28 ( V_363 + V_11 -> V_357 , V_314 ) ;
F_28 ( V_364 + V_11 -> V_357 , 0 ) ;
F_28 ( V_365 + V_11 -> V_357 , 0 ) ;
F_28 ( V_366 + V_11 -> V_357 , 0 ) ;
F_28 ( V_367 + V_11 -> V_357 , 0 ) ;
F_28 ( V_368 + V_11 -> V_357 , V_301 -> V_369 ) ;
F_28 ( V_370 + V_11 -> V_357 , V_301 -> V_371 ) ;
V_308 = V_301 -> V_372 [ 0 ] / ( V_301 -> V_322 / 8 ) ;
F_28 ( V_373 + V_11 -> V_357 , V_308 ) ;
F_28 ( V_374 + V_11 -> V_357 , 1 ) ;
F_28 ( V_375 + V_11 -> V_357 ,
V_301 -> V_371 ) ;
V_296 &= ~ 3 ;
V_297 &= ~ 1 ;
F_28 ( V_376 + V_11 -> V_357 ,
( V_296 << 16 ) | V_297 ) ;
V_317 = V_2 -> V_4 . V_377 ;
V_318 = ( V_2 -> V_4 . V_378 + 1 ) & ~ 1 ;
F_28 ( V_379 + V_11 -> V_357 ,
( V_317 << 16 ) | V_318 ) ;
V_316 = F_27 ( V_380 + V_11 -> V_357 ) ;
V_316 &= ~ V_381 ;
F_28 ( V_380 + V_11 -> V_357 , V_316 ) ;
F_28 ( V_382 + V_11 -> V_357 , 0 ) ;
if ( ! V_298 && V_295 && V_295 != V_2 -> V_295 ) {
V_300 = F_57 ( V_295 ) ;
V_305 = F_58 ( V_300 -> V_303 ) ;
V_319 = F_59 ( V_305 , false ) ;
if ( F_60 ( V_319 != 0 ) )
return V_319 ;
F_77 ( V_305 ) ;
F_63 ( V_305 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_294 * V_295 ,
int V_296 , int V_297 , int V_298 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_299 * V_300 ;
struct V_302 * V_303 ;
struct V_304 * V_305 ;
struct V_294 * V_301 ;
T_11 V_306 ;
V_33 V_307 , V_308 , V_309 ;
T_9 V_314 = V_383 ;
T_9 V_316 , V_317 , V_318 ;
int V_319 ;
if ( ! V_298 && ! V_2 -> V_295 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_298 ) {
V_300 = F_57 ( V_295 ) ;
V_301 = V_295 ;
}
else {
V_300 = F_57 ( V_2 -> V_295 ) ;
V_301 = V_2 -> V_295 ;
}
V_303 = V_300 -> V_303 ;
V_305 = F_58 ( V_303 ) ;
V_319 = F_59 ( V_305 , false ) ;
if ( F_60 ( V_319 != 0 ) )
return V_319 ;
if ( V_298 )
V_306 = F_61 ( V_305 ) ;
else {
V_319 = F_62 ( V_305 , V_320 , & V_306 ) ;
if ( F_60 ( V_319 != 0 ) ) {
F_63 ( V_305 ) ;
return - V_321 ;
}
}
F_64 ( V_305 , & V_309 , NULL ) ;
F_63 ( V_305 ) ;
switch ( V_301 -> V_322 ) {
case 8 :
V_307 =
V_384 |
V_385 ;
break;
case 15 :
V_307 =
V_386 |
V_387 ;
break;
case 16 :
V_307 =
V_386 |
V_388 ;
#ifdef F_67
V_314 = V_389 ;
#endif
break;
case 24 :
case 32 :
V_307 =
V_390 |
V_391 ;
#ifdef F_67
V_314 = V_392 ;
#endif
break;
default:
F_45 ( L_3 ,
V_301 -> V_322 ) ;
return - V_321 ;
}
if ( V_9 -> V_70 >= V_393 ) {
if ( V_309 & V_332 )
V_307 |= V_394 ;
else if ( V_309 & V_344 )
V_307 |= V_395 ;
} else {
if ( V_309 & V_332 )
V_307 |= V_396 ;
if ( V_309 & V_344 )
V_307 |= V_397 ;
}
if ( V_11 -> V_18 == 0 )
F_28 ( V_350 , 0 ) ;
else
F_28 ( V_351 , 0 ) ;
if ( V_9 -> V_70 >= V_197 ) {
if ( V_11 -> V_18 ) {
F_28 ( V_398 , F_76 ( V_306 ) ) ;
F_28 ( V_399 , F_76 ( V_306 ) ) ;
} else {
F_28 ( V_400 , F_76 ( V_306 ) ) ;
F_28 ( V_401 , F_76 ( V_306 ) ) ;
}
}
F_28 ( V_402 + V_11 -> V_357 ,
( T_9 ) V_306 ) ;
F_28 ( V_403 +
V_11 -> V_357 , ( T_9 ) V_306 ) ;
F_28 ( V_404 + V_11 -> V_357 , V_307 ) ;
if ( V_9 -> V_70 >= V_393 )
F_28 ( V_405 + V_11 -> V_357 , V_314 ) ;
F_28 ( V_406 + V_11 -> V_357 , 0 ) ;
F_28 ( V_407 + V_11 -> V_357 , 0 ) ;
F_28 ( V_408 + V_11 -> V_357 , 0 ) ;
F_28 ( V_409 + V_11 -> V_357 , 0 ) ;
F_28 ( V_410 + V_11 -> V_357 , V_301 -> V_369 ) ;
F_28 ( V_411 + V_11 -> V_357 , V_301 -> V_371 ) ;
V_308 = V_301 -> V_372 [ 0 ] / ( V_301 -> V_322 / 8 ) ;
F_28 ( V_412 + V_11 -> V_357 , V_308 ) ;
F_28 ( V_413 + V_11 -> V_357 , 1 ) ;
F_28 ( V_414 + V_11 -> V_357 ,
V_301 -> V_371 ) ;
V_296 &= ~ 3 ;
V_297 &= ~ 1 ;
F_28 ( V_415 + V_11 -> V_357 ,
( V_296 << 16 ) | V_297 ) ;
V_317 = V_2 -> V_4 . V_377 ;
V_318 = ( V_2 -> V_4 . V_378 + 1 ) & ~ 1 ;
F_28 ( V_416 + V_11 -> V_357 ,
( V_317 << 16 ) | V_318 ) ;
V_316 = F_27 ( V_417 + V_11 -> V_357 ) ;
V_316 &= ~ V_418 ;
F_28 ( V_417 + V_11 -> V_357 , V_316 ) ;
F_28 ( V_419 + V_11 -> V_357 , 0 ) ;
if ( ! V_298 && V_295 && V_295 != V_2 -> V_295 ) {
V_300 = F_57 ( V_295 ) ;
V_305 = F_58 ( V_300 -> V_303 ) ;
V_319 = F_59 ( V_305 , false ) ;
if ( F_60 ( V_319 != 0 ) )
return V_319 ;
F_77 ( V_305 ) ;
F_63 ( V_305 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_296 , int V_297 ,
struct V_294 * V_420 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_26 ( V_9 ) )
return F_54 ( V_2 , V_420 , V_296 , V_297 , 0 ) ;
else if ( F_7 ( V_9 ) )
return F_79 ( V_2 , V_420 , V_296 , V_297 , 0 ) ;
else
return F_81 ( V_2 , V_420 , V_296 , V_297 , 0 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_294 * V_295 ,
int V_296 , int V_297 , enum V_421 V_75 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_26 ( V_9 ) )
return F_54 ( V_2 , V_295 , V_296 , V_297 , 1 ) ;
else if ( F_7 ( V_9 ) )
return F_79 ( V_2 , V_295 , V_296 , V_297 , 1 ) ;
else
return F_81 ( V_2 , V_295 , V_296 , V_297 , 1 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_9 V_422 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_422 = F_27 ( V_423 ) ;
V_422 &= ~ V_424 ;
F_28 ( V_423 , V_422 ) ;
break;
case 1 :
V_422 = F_27 ( V_425 ) ;
V_422 &= ~ V_426 ;
F_28 ( V_425 , V_422 ) ;
F_28 ( V_427 , F_27 ( V_428 ) ) ;
F_28 ( V_429 , F_27 ( V_430 ) ) ;
break;
}
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_431 ;
struct V_1 * V_432 ;
V_33 V_433 = 0 ;
if ( F_31 ( V_9 ) ) {
F_8 (test_encoder, &dev->mode_config.encoder_list, head) {
if ( V_431 -> V_2 && ( V_431 -> V_2 == V_2 ) ) {
struct V_42 * V_434 =
F_9 ( V_431 ) ;
struct V_232 * V_233 =
V_434 -> V_47 ;
if ( ( V_434 -> V_212 ==
V_435 ) &&
( V_233 -> V_436 == false ) )
return V_139 ;
}
}
F_8 (test_crtc, &dev->mode_config.crtc_list, head) {
struct V_11 * V_437 ;
if ( V_2 == V_432 )
continue;
V_437 = F_2 ( V_432 ) ;
if ( ( V_437 -> V_134 == V_252 ) ||
( V_437 -> V_134 == V_136 ) )
V_433 |= ( 1 << V_437 -> V_134 ) ;
}
if ( ! ( V_433 & 4 ) )
return V_252 ;
return V_136 ;
} else if ( F_26 ( V_9 ) ) {
F_8 (test_encoder, &dev->mode_config.encoder_list, head) {
if ( V_431 -> V_2 && ( V_431 -> V_2 == V_2 ) ) {
if ( F_43 ( F_37 ( V_431 ) ) ) {
if ( V_9 -> clock . V_438 )
return V_142 ;
else if ( F_18 ( V_9 ) )
return V_252 ;
else if ( F_30 ( V_9 ) )
return V_141 ;
}
}
}
F_8 (test_crtc, &dev->mode_config.crtc_list, head) {
struct V_11 * V_437 ;
if ( V_2 == V_432 )
continue;
V_437 = F_2 ( V_432 ) ;
if ( ( V_437 -> V_134 >= V_136 ) &&
( V_437 -> V_134 <= V_139 ) )
V_433 |= ( 1 << V_437 -> V_134 ) ;
}
if ( ! ( V_433 & 1 ) )
return V_136 ;
return V_139 ;
} else
return V_11 -> V_18 ;
}
void F_85 ( struct V_8 * V_9 )
{
if ( F_18 ( V_9 ) )
F_46 ( V_9 , V_9 -> clock . V_439 ) ;
else if ( F_26 ( V_9 ) ) {
struct V_146 V_147 ;
bool V_183 = F_50 ( V_9 , & V_147 ,
V_440 ,
V_9 -> clock . V_439 ) ;
if ( V_183 )
F_29 ( V_9 , V_85 , V_141 , - 1 , & V_147 ) ;
F_46 ( V_9 , V_9 -> clock . V_439 ) ;
if ( V_183 )
F_29 ( V_9 , V_86 , V_141 , - 1 , & V_147 ) ;
}
}
int F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_296 , int V_297 , struct V_294 * V_420 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 ;
bool V_441 = false ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
struct V_42 * V_42 = F_9 ( V_41 ) ;
if ( V_42 -> V_43 &
( V_44 | V_442 ) )
V_441 = true ;
}
}
F_49 ( V_2 , V_5 ) ;
if ( F_26 ( V_9 ) )
F_23 ( V_2 , V_5 ) ;
else if ( F_7 ( V_9 ) ) {
if ( V_441 )
F_24 ( V_2 , V_5 ) ;
else
F_23 ( V_2 , V_5 ) ;
} else {
F_24 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_23 ( V_2 , V_5 ) ;
F_83 ( V_2 ) ;
}
F_80 ( V_2 , V_296 , V_297 , V_420 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool F_87 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
if ( ! F_88 ( V_2 , V_4 , V_5 ) )
return false ;
return true ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
V_11 -> V_84 = true ;
V_11 -> V_134 = F_84 ( V_2 ) ;
if ( F_18 ( V_9 ) )
F_15 ( V_2 , V_85 ) ;
F_11 ( V_2 , V_86 ) ;
F_16 ( V_2 , V_89 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
F_16 ( V_2 , V_82 ) ;
F_11 ( V_2 , V_85 ) ;
V_11 -> V_84 = false ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_146 V_147 ;
int V_148 ;
F_16 ( V_2 , V_89 ) ;
for ( V_148 = 0 ; V_148 < V_9 -> V_151 ; V_148 ++ ) {
if ( V_9 -> V_31 . V_152 [ V_148 ] &&
V_9 -> V_31 . V_152 [ V_148 ] -> V_83 &&
V_148 != V_11 -> V_18 &&
V_11 -> V_134 == V_9 -> V_31 . V_152 [ V_148 ] -> V_134 ) {
goto V_443;
}
}
switch ( V_11 -> V_134 ) {
case V_136 :
case V_139 :
F_48 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
0 , 0 , V_85 , 0 , 0 , 0 , 0 , 0 , false , & V_147 ) ;
break;
case V_252 :
if ( F_31 ( V_9 ) )
F_48 ( V_2 , V_11 -> V_18 , V_11 -> V_134 ,
0 , 0 , V_85 , 0 , 0 , 0 , 0 , 0 , false , & V_147 ) ;
break;
default:
break;
}
V_443:
V_11 -> V_134 = - 1 ;
}
void F_92 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_26 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_357 = V_444 ;
break;
case 1 :
V_11 -> V_357 = V_445 ;
break;
case 2 :
V_11 -> V_357 = V_446 ;
break;
case 3 :
V_11 -> V_357 = V_447 ;
break;
case 4 :
V_11 -> V_357 = V_448 ;
break;
case 5 :
V_11 -> V_357 = V_449 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_357 =
V_450 - V_451 ;
else
V_11 -> V_357 = 0 ;
}
V_11 -> V_134 = - 1 ;
F_93 ( & V_11 -> V_452 , & V_453 ) ;
}
