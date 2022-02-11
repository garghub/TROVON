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
if ( F_18 ( V_9 ) )
F_15 ( V_2 , V_84 ) ;
F_12 ( V_2 , V_85 ) ;
if ( F_19 ( V_9 ) && ! F_18 ( V_9 ) )
F_13 ( V_2 , V_85 ) ;
F_14 ( V_2 , V_84 ) ;
F_20 ( V_7 , V_11 -> V_18 ) ;
F_21 ( V_2 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
F_22 ( V_7 , V_11 -> V_18 ) ;
if ( V_11 -> V_83 )
F_14 ( V_2 , V_85 ) ;
if ( F_19 ( V_9 ) && ! F_18 ( V_9 ) )
F_13 ( V_2 , V_84 ) ;
F_12 ( V_2 , V_84 ) ;
V_11 -> V_83 = false ;
if ( F_18 ( V_9 ) ) {
struct V_1 * V_89 ;
struct V_11 * V_90 ;
F_8 (other_crtc, &rdev->ddev->mode_config.crtc_list, head) {
V_90 = F_2 ( V_89 ) ;
if ( ( ( V_11 -> V_18 == 0 ) && ( V_90 -> V_18 == 1 ) ) ||
( ( V_11 -> V_18 == 1 ) && ( V_90 -> V_18 == 0 ) ) ||
( ( V_11 -> V_18 == 2 ) && ( V_90 -> V_18 == 3 ) ) ||
( ( V_11 -> V_18 == 3 ) && ( V_90 -> V_18 == 2 ) ) ||
( ( V_11 -> V_18 == 4 ) && ( V_90 -> V_18 == 5 ) ) ||
( ( V_11 -> V_18 == 5 ) && ( V_90 -> V_18 == 4 ) ) ) {
if ( V_90 -> V_83 == false )
F_15 ( V_2 , V_85 ) ;
break;
}
}
}
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
int V_12 = F_3 ( V_13 , V_91 ) ;
T_7 V_92 = 0 ;
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
args . V_120 . V_121 = F_4 ( V_92 ) ;
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
int V_12 = F_3 ( V_13 , V_122 ) ;
T_7 V_92 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_123 = F_4 ( V_4 -> V_124 ) ;
args . V_125 = F_4 ( V_4 -> V_25 ) ;
args . V_126 = F_4 ( V_4 -> V_100 ) ;
args . V_101 =
F_4 ( V_4 -> V_102 - V_4 -> V_100 ) ;
args . V_127 = F_4 ( V_4 -> V_128 ) ;
args . V_129 = F_4 ( V_4 -> V_22 ) ;
args . V_130 = F_4 ( V_4 -> V_104 ) ;
args . V_105 =
F_4 ( V_4 -> V_106 - V_4 -> V_104 ) ;
args . V_131 = V_11 -> V_29 ;
args . V_132 = V_11 -> V_29 ;
args . V_133 = V_11 -> V_30 ;
args . V_134 = V_11 -> V_30 ;
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
args . V_120 . V_121 = F_4 ( V_92 ) ;
args . V_17 = V_11 -> V_18 ;
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_25 ( struct V_8 * V_9 , int V_135 )
{
T_9 V_136 ;
if ( F_26 ( V_9 ) ) {
switch ( V_135 ) {
case V_137 :
V_136 = F_27 ( V_138 ) ;
V_136 &= ~ V_139 ;
F_28 ( V_138 , V_136 ) ;
break;
case V_140 :
V_136 = F_27 ( V_141 ) ;
V_136 &= ~ V_139 ;
F_28 ( V_141 , V_136 ) ;
break;
case V_142 :
case V_143 :
return;
}
} else if ( F_7 ( V_9 ) ) {
switch ( V_135 ) {
case V_137 :
V_136 = F_27 ( V_144 ) ;
V_136 &= ~ 1 ;
F_28 ( V_144 , V_136 ) ;
break;
case V_140 :
V_136 = F_27 ( V_145 ) ;
V_136 &= ~ 1 ;
F_28 ( V_145 , V_136 ) ;
break;
case V_142 :
case V_143 :
return;
}
}
}
static void F_29 ( struct V_8 * V_9 ,
int V_146 ,
int V_135 ,
struct V_147 * V_148 )
{
int V_12 = F_3 ( V_13 , V_149 ) ;
union V_150 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_30 ( V_9 ) ) {
args . V_151 . V_152 = F_4 ( 0 ) ;
args . V_151 . V_153 = V_148 -> type & V_154 ;
switch ( V_135 ) {
case V_137 :
args . V_151 . V_153 |= V_155 ;
args . V_151 . V_156 = F_4 ( V_148 -> V_157 ) ;
args . V_151 . V_158 = F_4 ( V_148 -> V_159 ) ;
break;
case V_140 :
args . V_151 . V_153 |= V_160 ;
args . V_151 . V_156 = F_4 ( V_148 -> V_157 ) ;
args . V_151 . V_158 = F_4 ( V_148 -> V_159 ) ;
break;
case V_142 :
args . V_151 . V_153 |= V_161 ;
args . V_151 . V_156 = F_4 ( 0 ) ;
args . V_151 . V_158 = F_4 ( 0 ) ;
break;
case V_143 :
return;
}
args . V_151 . V_64 = V_146 ;
if ( ( V_148 -> V_162 == 0 ) || ( V_148 -> type & V_163 ) || F_31 ( V_9 ) )
args . V_151 . V_64 = V_84 ;
} else if ( F_26 ( V_9 ) ) {
args . V_164 . V_165 = F_4 ( V_148 -> V_162 ) ;
args . V_164 . V_153 = V_148 -> type & V_154 ;
switch ( V_135 ) {
case V_137 :
args . V_164 . V_153 |= V_166 ;
args . V_164 . V_156 = F_4 ( V_148 -> V_157 ) ;
args . V_164 . V_158 = F_4 ( V_148 -> V_159 ) ;
break;
case V_140 :
args . V_164 . V_153 |= V_167 ;
args . V_164 . V_156 = F_4 ( V_148 -> V_157 ) ;
args . V_164 . V_158 = F_4 ( V_148 -> V_159 ) ;
break;
case V_142 :
args . V_164 . V_153 |= V_168 ;
args . V_164 . V_156 = F_4 ( 0 ) ;
args . V_164 . V_158 = F_4 ( 0 ) ;
break;
case V_143 :
return;
}
args . V_164 . V_64 = V_146 ;
if ( ( V_148 -> V_162 == 0 ) || ( V_148 -> type & V_163 ) || F_32 ( V_9 ) )
args . V_164 . V_64 = V_84 ;
} else if ( F_19 ( V_9 ) ) {
args . V_169 . V_165 = F_4 ( V_148 -> V_162 ) ;
args . V_169 . V_153 = V_148 -> type & V_154 ;
args . V_169 . V_170 = V_148 -> V_159 ;
args . V_169 . V_171 = V_148 -> V_172 ;
args . V_169 . V_173 = V_148 -> V_174 ;
args . V_169 . V_175 = V_135 ;
args . V_169 . V_64 = V_146 ;
} else if ( F_7 ( V_9 ) ) {
if ( ( V_146 == V_84 ) || ( V_148 -> V_162 == 0 ) ||
( V_148 -> type & V_163 ) ) {
F_25 ( V_9 , V_135 ) ;
return;
}
args . V_176 . V_165 = F_4 ( V_148 -> V_162 ) ;
args . V_176 . V_153 = V_148 -> type & V_154 ;
args . V_176 . V_170 = V_148 -> V_159 ;
args . V_176 . V_171 = V_148 -> V_172 ;
args . V_176 . V_173 = V_148 -> V_174 ;
args . V_176 . V_64 = V_146 ;
} else {
if ( ( V_146 == V_84 ) || ( V_148 -> V_162 == 0 ) ||
( V_148 -> type & V_163 ) ) {
F_25 ( V_9 , V_135 ) ;
return;
}
args . V_177 . V_165 = F_4 ( V_148 -> V_162 ) ;
args . V_177 . V_153 = V_148 -> type & V_154 ;
args . V_177 . V_178 = ( V_148 -> V_159 & 3 ) << 2 ;
args . V_177 . V_178 |= ( V_148 -> V_172 & 7 ) << 4 ;
args . V_177 . V_64 = V_146 ;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static T_9 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_179 * V_180 ,
bool V_181 ,
struct V_147 * V_148 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_42 = NULL ;
struct V_182 * V_183 = NULL ;
T_9 V_184 = V_4 -> clock ;
int V_185 = 0 ;
T_9 V_186 = V_4 -> clock ;
int V_187 = 8 ;
bool V_188 = false ;
V_180 -> V_109 = 0 ;
if ( F_7 ( V_9 ) ) {
if ( ( V_9 -> V_70 == V_189 ) ||
( V_9 -> V_70 == V_190 ) ||
( V_9 -> V_70 == V_191 ) )
V_180 -> V_109 |= (
V_192 ) ;
if ( F_34 ( V_9 ) && V_4 -> clock > 200000 )
V_180 -> V_109 |= V_193 ;
else
V_180 -> V_109 |= V_194 ;
if ( V_9 -> V_70 < V_195 )
V_180 -> V_109 |= V_196 ;
if ( F_32 ( V_9 ) || F_31 ( V_9 ) )
V_180 -> V_109 |= V_197 ;
} else {
V_180 -> V_109 |= V_198 ;
if ( V_4 -> clock > 200000 )
V_180 -> V_109 |= V_193 ;
else
V_180 -> V_109 |= V_194 ;
}
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_183 = F_35 ( V_41 ) ;
V_187 = F_36 ( V_183 ) ;
V_185 = F_37 ( V_41 ) ;
V_188 = F_38 ( V_41 , V_4 -> clock ) ;
if ( ( V_42 -> V_199 & ( V_200 | V_201 ) ) ||
( F_39 ( V_41 ) != V_202 ) ) {
if ( V_183 ) {
struct V_203 * V_203 = F_40 ( V_183 ) ;
struct V_204 * V_205 =
V_203 -> V_206 ;
V_186 = V_205 -> V_186 ;
}
}
if ( V_42 -> V_199 & ( V_200 ) ) {
if ( V_181 ) {
if ( V_148 -> V_207 ) {
V_180 -> V_109 |= V_208 ;
V_180 -> V_209 = V_148 -> V_207 ;
if ( F_7 ( V_9 ) )
V_180 -> V_109 |= V_197 ;
}
}
}
if ( F_7 ( V_9 ) ) {
if ( V_42 -> V_210 == V_211 )
V_184 = V_4 -> clock * 2 ;
if ( V_42 -> V_43 & ( V_44 ) )
V_180 -> V_109 |= V_192 ;
if ( V_42 -> V_199 & ( V_200 ) )
V_180 -> V_109 |= V_212 ;
} else {
if ( V_41 -> V_213 != V_214 )
V_180 -> V_109 |= V_215 ;
if ( V_41 -> V_213 == V_216 )
V_180 -> V_109 |= V_208 ;
}
break;
}
}
if ( F_19 ( V_9 ) ) {
union V_217 args ;
T_10 V_218 , V_219 ;
int V_12 ;
V_12 = F_3 ( V_13 , V_220 ) ;
if ( ! F_41 ( V_9 -> V_31 . V_32 , V_12 , & V_218 ,
& V_219 ) )
return V_184 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_218 ) {
case 1 :
switch ( V_219 ) {
case 1 :
case 2 :
args . V_169 . V_221 = F_4 ( V_4 -> clock / 10 ) ;
args . V_169 . V_222 = V_42 -> V_210 ;
args . V_169 . V_223 = V_185 ;
if ( V_181 && V_148 -> V_162 )
args . V_169 . V_224 |=
V_225 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_184 = F_42 ( args . V_169 . V_221 ) * 10 ;
break;
case 3 :
args . V_151 . V_226 . V_221 = F_4 ( V_4 -> clock / 10 ) ;
args . V_151 . V_226 . V_222 = V_42 -> V_210 ;
args . V_151 . V_226 . V_223 = V_185 ;
args . V_151 . V_226 . V_227 = 0 ;
if ( V_181 && V_148 -> V_162 )
args . V_151 . V_226 . V_227 |=
V_228 ;
if ( F_43 ( V_185 ) ) {
args . V_151 . V_226 . V_227 |=
V_229 ;
args . V_151 . V_226 . V_221 = F_4 ( V_186 / 10 ) ;
} else if ( V_42 -> V_199 & ( V_201 ) ) {
struct V_230 * V_231 = V_42 -> V_47 ;
if ( V_185 == V_232 )
args . V_151 . V_226 . V_221 =
F_4 ( ( V_4 -> clock * V_187 / 8 ) / 10 ) ;
if ( V_231 -> V_233 )
args . V_151 . V_226 . V_227 |=
V_229 ;
if ( V_188 )
args . V_151 . V_226 . V_227 |=
V_234 ;
}
if ( F_39 ( V_41 ) !=
V_202 )
args . V_151 . V_226 . V_235 =
F_39 ( V_41 ) ;
else
args . V_151 . V_226 . V_235 = 0 ;
F_5 ( V_9 -> V_31 . V_32 ,
V_12 , ( V_33 * ) & args ) ;
V_184 = F_44 ( args . V_151 . V_236 . V_237 ) * 10 ;
if ( args . V_151 . V_236 . V_238 ) {
V_180 -> V_109 |= V_197 ;
V_180 -> V_109 |= V_208 ;
V_180 -> V_209 = args . V_151 . V_236 . V_238 ;
}
if ( args . V_151 . V_236 . V_239 ) {
V_180 -> V_109 |= V_197 ;
V_180 -> V_109 |= V_240 ;
V_180 -> V_241 = args . V_151 . V_236 . V_239 ;
}
break;
default:
F_45 ( L_1 , V_218 , V_219 ) ;
return V_184 ;
}
break;
default:
F_45 ( L_1 , V_218 , V_219 ) ;
return V_184 ;
}
}
return V_184 ;
}
static void F_46 ( struct V_8 * V_9 ,
T_9 V_242 )
{
T_10 V_218 , V_219 ;
int V_12 ;
union V_243 args ;
memset ( & args , 0 , sizeof( args ) ) ;
V_12 = F_3 ( V_13 , V_244 ) ;
if ( ! F_41 ( V_9 -> V_31 . V_32 , V_12 , & V_218 ,
& V_219 ) )
return;
switch ( V_218 ) {
case 1 :
switch ( V_219 ) {
case 5 :
args . V_245 . V_17 = V_246 ;
args . V_245 . V_221 = F_4 ( V_242 ) ;
args . V_245 . V_175 = V_142 ;
break;
case 6 :
args . V_247 . V_248 = F_47 ( V_242 ) ;
if ( F_31 ( V_9 ) )
args . V_247 . V_175 = V_249 ;
else if ( F_18 ( V_9 ) )
args . V_247 . V_175 = V_250 ;
else
args . V_247 . V_175 = V_142 ;
break;
default:
F_45 ( L_1 , V_218 , V_219 ) ;
return;
}
break;
default:
F_45 ( L_1 , V_218 , V_219 ) ;
return;
}
F_5 ( V_9 -> V_31 . V_32 , V_12 , ( V_33 * ) & args ) ;
}
static void F_48 ( struct V_1 * V_2 ,
T_9 V_18 ,
int V_135 ,
T_9 V_185 ,
T_9 V_210 ,
T_9 clock ,
T_9 V_251 ,
T_9 V_252 ,
T_9 V_253 ,
T_9 V_241 ,
int V_187 ,
bool V_181 ,
struct V_147 * V_148 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_10 V_218 , V_219 ;
int V_12 = F_3 ( V_13 , V_244 ) ;
union V_243 args ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_41 ( V_9 -> V_31 . V_32 , V_12 , & V_218 ,
& V_219 ) )
return;
switch ( V_218 ) {
case 1 :
switch ( V_219 ) {
case 1 :
if ( clock == V_84 )
return;
args . V_169 . V_221 = F_4 ( clock / 10 ) ;
args . V_169 . V_254 = F_4 ( V_251 ) ;
args . V_169 . V_255 = F_4 ( V_252 ) ;
args . V_169 . V_256 = V_253 ;
args . V_169 . V_239 = V_241 ;
args . V_169 . V_175 = V_135 ;
args . V_169 . V_17 = V_18 ;
args . V_169 . V_257 = 1 ;
break;
case 2 :
args . V_164 . V_221 = F_4 ( clock / 10 ) ;
args . V_164 . V_254 = F_4 ( V_251 ) ;
args . V_164 . V_255 = F_4 ( V_252 ) ;
args . V_164 . V_256 = V_253 ;
args . V_164 . V_239 = V_241 ;
args . V_164 . V_175 = V_135 ;
args . V_164 . V_17 = V_18 ;
args . V_164 . V_257 = 1 ;
break;
case 3 :
args . V_151 . V_221 = F_4 ( clock / 10 ) ;
args . V_151 . V_254 = F_4 ( V_251 ) ;
args . V_151 . V_255 = F_4 ( V_252 ) ;
args . V_151 . V_256 = V_253 ;
args . V_151 . V_239 = V_241 ;
args . V_151 . V_175 = V_135 ;
args . V_151 . V_258 = ( V_135 << 2 ) ;
if ( V_181 && ( V_148 -> type & V_163 ) )
args . V_151 . V_258 |= V_259 ;
args . V_151 . V_260 = V_210 ;
args . V_151 . V_261 = V_185 ;
break;
case 5 :
args . V_245 . V_17 = V_18 ;
args . V_245 . V_221 = F_4 ( clock / 10 ) ;
args . V_245 . V_238 = V_251 ;
args . V_245 . V_255 = F_4 ( V_252 ) ;
args . V_245 . V_262 = F_47 ( V_253 * 100000 ) ;
args . V_245 . V_239 = V_241 ;
args . V_245 . V_258 = 0 ;
if ( V_181 && ( V_148 -> type & V_163 ) )
args . V_245 . V_258 |= V_263 ;
switch ( V_187 ) {
case 8 :
default:
args . V_245 . V_258 |= V_264 ;
break;
case 10 :
args . V_245 . V_258 |= V_265 ;
break;
}
args . V_245 . V_222 = V_210 ;
args . V_245 . V_261 = V_185 ;
args . V_245 . V_175 = V_135 ;
break;
case 6 :
args . V_247 . V_248 = F_47 ( V_18 << 24 | clock / 10 ) ;
args . V_247 . V_238 = V_251 ;
args . V_247 . V_255 = F_4 ( V_252 ) ;
args . V_247 . V_262 = F_47 ( V_253 * 100000 ) ;
args . V_247 . V_239 = V_241 ;
args . V_247 . V_258 = 0 ;
if ( V_181 && ( V_148 -> type & V_163 ) )
args . V_247 . V_258 |= V_266 ;
switch ( V_187 ) {
case 8 :
default:
args . V_247 . V_258 |= V_267 ;
break;
case 10 :
args . V_247 . V_258 |= V_268 ;
break;
case 12 :
args . V_247 . V_258 |= V_269 ;
break;
case 16 :
args . V_247 . V_258 |= V_270 ;
break;
}
args . V_247 . V_222 = V_210 ;
args . V_247 . V_261 = V_185 ;
args . V_247 . V_175 = V_135 ;
break;
default:
F_45 ( L_1 , V_218 , V_219 ) ;
return;
}
break;
default:
F_45 ( L_1 , V_218 , V_219 ) ;
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
T_9 V_271 = V_4 -> clock ;
T_9 V_251 = 0 , V_252 = 0 , V_253 = 0 , V_241 = 0 ;
struct V_179 * V_180 ;
T_9 V_184 ;
int V_185 = 0 ;
struct V_147 V_148 ;
bool V_181 = false ;
int V_187 = 8 ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
V_42 = F_9 ( V_41 ) ;
V_185 = F_37 ( V_41 ) ;
break;
}
}
if ( ! V_42 )
return;
switch ( V_11 -> V_135 ) {
case V_137 :
V_180 = & V_9 -> clock . V_272 ;
break;
case V_140 :
V_180 = & V_9 -> clock . V_273 ;
break;
case V_142 :
case V_143 :
default:
V_180 = & V_9 -> clock . V_274 ;
break;
}
if ( ( V_42 -> V_43 & ( V_200 | V_201 ) ) ||
( F_39 ( V_41 ) != V_202 ) ) {
struct V_230 * V_231 = V_42 -> V_47 ;
struct V_182 * V_183 =
F_35 ( V_41 ) ;
struct V_203 * V_203 =
F_40 ( V_183 ) ;
struct V_204 * V_205 =
V_203 -> V_206 ;
int V_186 ;
V_187 = F_36 ( V_183 ) ;
switch ( V_185 ) {
case V_275 :
case V_276 :
V_186 = V_205 -> V_186 / 10 ;
if ( F_26 ( V_9 ) )
V_181 =
F_50 ( V_9 , & V_148 ,
V_277 ,
V_186 ) ;
else {
if ( V_186 == 16200 ) {
V_181 =
F_51 ( V_9 , & V_148 ,
V_278 ) ;
if ( ! V_181 )
V_181 =
F_51 ( V_9 , & V_148 ,
V_279 ) ;
} else
V_181 =
F_51 ( V_9 , & V_148 ,
V_279 ) ;
}
break;
case V_280 :
if ( F_26 ( V_9 ) )
V_181 = F_50 ( V_9 , & V_148 ,
V_231 -> V_281 ,
V_4 -> clock / 10 ) ;
else
V_181 = F_51 ( V_9 , & V_148 ,
V_231 -> V_281 ) ;
break;
case V_282 :
if ( F_26 ( V_9 ) )
V_181 =
F_50 ( V_9 , & V_148 ,
V_283 ,
V_4 -> clock / 10 ) ;
break;
case V_232 :
if ( F_26 ( V_9 ) )
V_181 =
F_50 ( V_9 , & V_148 ,
V_284 ,
V_4 -> clock / 10 ) ;
break;
default:
break;
}
}
V_184 = F_33 ( V_2 , V_4 , V_180 , V_181 , & V_148 ) ;
if ( V_42 -> V_43 & ( V_44 ) )
F_52 ( V_180 , V_184 , & V_271 , & V_252 , & V_253 ,
& V_251 , & V_241 ) ;
else if ( F_7 ( V_9 ) )
F_53 ( V_180 , V_184 , & V_271 , & V_252 , & V_253 ,
& V_251 , & V_241 ) ;
else
F_52 ( V_180 , V_184 , & V_271 , & V_252 , & V_253 ,
& V_251 , & V_241 ) ;
F_29 ( V_9 , V_84 , V_11 -> V_135 , & V_148 ) ;
F_48 ( V_2 , V_11 -> V_18 , V_11 -> V_135 ,
V_185 , V_42 -> V_210 , V_4 -> clock ,
V_251 , V_252 , V_253 , V_241 , V_187 , V_181 , & V_148 ) ;
if ( V_181 ) {
if ( F_26 ( V_9 ) ) {
T_9 V_285 ;
T_9 V_157 = ( ( ( V_252 * 10 ) + V_253 ) * V_148 . V_162 ) / 10000 ;
V_148 . V_157 = ( V_157 / 10 ) & V_286 ;
V_148 . V_157 |= ( ( V_157 - ( V_157 / 10 ) ) << V_287 ) &
V_288 ;
if ( V_148 . type & V_289 )
V_285 = ( 4 * V_157 * V_251 * ( V_148 . V_290 * 2048 ) ) /
( 125 * 25 * V_180 -> V_291 / 100 ) ;
else
V_285 = ( 2 * V_157 * V_251 * ( V_148 . V_290 * 2048 ) ) /
( 125 * 25 * V_180 -> V_291 / 100 ) ;
V_148 . V_159 = V_285 ;
}
F_29 ( V_9 , V_85 , V_11 -> V_135 , & V_148 ) ;
}
}
static int F_54 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
int V_294 , int V_295 , int V_296 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_297 * V_298 ;
struct V_292 * V_299 ;
struct V_300 * V_301 ;
struct V_302 * V_303 ;
T_11 V_304 ;
V_33 V_305 , V_306 , V_307 ;
unsigned V_308 , V_309 , V_310 , V_311 ;
T_9 V_312 = F_55 ( V_313 ) ;
T_9 V_314 , V_315 , V_316 ;
int V_317 ;
if ( ! V_296 && ! V_2 -> V_293 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_296 ) {
V_298 = F_57 ( V_293 ) ;
V_299 = V_293 ;
}
else {
V_298 = F_57 ( V_2 -> V_293 ) ;
V_299 = V_2 -> V_293 ;
}
V_301 = V_298 -> V_301 ;
V_303 = F_58 ( V_301 ) ;
V_317 = F_59 ( V_303 , false ) ;
if ( F_60 ( V_317 != 0 ) )
return V_317 ;
if ( V_296 )
V_304 = F_61 ( V_303 ) ;
else {
V_317 = F_62 ( V_303 , V_318 , & V_304 ) ;
if ( F_60 ( V_317 != 0 ) ) {
F_63 ( V_303 ) ;
return - V_319 ;
}
}
F_64 ( V_303 , & V_307 , NULL ) ;
F_63 ( V_303 ) ;
switch ( V_299 -> V_320 ) {
case 8 :
V_305 = ( F_65 ( V_321 ) |
F_66 ( V_322 ) ) ;
break;
case 15 :
V_305 = ( F_65 ( V_323 ) |
F_66 ( V_324 ) ) ;
break;
case 16 :
V_305 = ( F_65 ( V_323 ) |
F_66 ( V_325 ) ) ;
#ifdef F_67
V_312 = F_55 ( V_326 ) ;
#endif
break;
case 24 :
case 32 :
V_305 = ( F_65 ( V_327 ) |
F_66 ( V_328 ) ) ;
#ifdef F_67
V_312 = F_55 ( V_329 ) ;
#endif
break;
default:
F_45 ( L_3 ,
V_299 -> V_320 ) ;
return - V_319 ;
}
if ( V_307 & V_330 ) {
if ( V_9 -> V_70 >= V_331 )
V_314 = V_9 -> V_332 . V_333 . V_334 ;
else if ( V_9 -> V_70 >= V_335 )
V_314 = V_9 -> V_332 . V_336 . V_334 ;
else
V_314 = V_9 -> V_332 . V_337 . V_334 ;
switch ( ( V_314 & 0xf0 ) >> 4 ) {
case 0 :
V_305 |= F_68 ( V_338 ) ;
break;
case 1 :
default:
V_305 |= F_68 ( V_339 ) ;
break;
case 2 :
V_305 |= F_68 ( V_340 ) ;
break;
}
V_305 |= F_69 ( V_341 ) ;
F_70 ( V_307 , & V_308 , & V_309 , & V_310 , & V_311 ) ;
V_305 |= F_71 ( V_311 ) ;
V_305 |= F_72 ( V_308 ) ;
V_305 |= F_73 ( V_309 ) ;
V_305 |= F_74 ( V_310 ) ;
} else if ( V_307 & V_342 )
V_305 |= F_69 ( V_343 ) ;
if ( ( V_9 -> V_70 == V_331 ) ||
( V_9 -> V_70 == V_344 ) )
V_305 |= F_75 ( V_345 ) ;
else if ( V_9 -> V_70 == V_346 )
V_305 |= F_75 ( V_347 ) ;
switch ( V_11 -> V_18 ) {
case 0 :
F_28 ( V_348 , 0 ) ;
break;
case 1 :
F_28 ( V_349 , 0 ) ;
break;
case 2 :
F_28 ( V_350 , 0 ) ;
break;
case 3 :
F_28 ( V_351 , 0 ) ;
break;
case 4 :
F_28 ( V_352 , 0 ) ;
break;
case 5 :
F_28 ( V_353 , 0 ) ;
break;
default:
break;
}
F_28 ( V_354 + V_11 -> V_355 ,
F_76 ( V_304 ) ) ;
F_28 ( V_356 + V_11 -> V_355 ,
F_76 ( V_304 ) ) ;
F_28 ( V_357 + V_11 -> V_355 ,
( T_9 ) V_304 & V_358 ) ;
F_28 ( V_359 + V_11 -> V_355 ,
( T_9 ) V_304 & V_358 ) ;
F_28 ( V_360 + V_11 -> V_355 , V_305 ) ;
F_28 ( V_361 + V_11 -> V_355 , V_312 ) ;
F_28 ( V_362 + V_11 -> V_355 , 0 ) ;
F_28 ( V_363 + V_11 -> V_355 , 0 ) ;
F_28 ( V_364 + V_11 -> V_355 , 0 ) ;
F_28 ( V_365 + V_11 -> V_355 , 0 ) ;
F_28 ( V_366 + V_11 -> V_355 , V_299 -> V_367 ) ;
F_28 ( V_368 + V_11 -> V_355 , V_299 -> V_369 ) ;
V_306 = V_299 -> V_370 [ 0 ] / ( V_299 -> V_320 / 8 ) ;
F_28 ( V_371 + V_11 -> V_355 , V_306 ) ;
F_28 ( V_372 + V_11 -> V_355 , 1 ) ;
F_28 ( V_373 + V_11 -> V_355 ,
V_299 -> V_369 ) ;
V_294 &= ~ 3 ;
V_295 &= ~ 1 ;
F_28 ( V_374 + V_11 -> V_355 ,
( V_294 << 16 ) | V_295 ) ;
V_315 = V_2 -> V_4 . V_375 ;
V_316 = ( V_2 -> V_4 . V_376 + 1 ) & ~ 1 ;
F_28 ( V_377 + V_11 -> V_355 ,
( V_315 << 16 ) | V_316 ) ;
V_314 = F_27 ( V_378 + V_11 -> V_355 ) ;
V_314 &= ~ V_379 ;
F_28 ( V_378 + V_11 -> V_355 , V_314 ) ;
F_28 ( V_380 + V_11 -> V_355 , 0 ) ;
if ( ! V_296 && V_293 && V_293 != V_2 -> V_293 ) {
V_298 = F_57 ( V_293 ) ;
V_303 = F_58 ( V_298 -> V_301 ) ;
V_317 = F_59 ( V_303 , false ) ;
if ( F_60 ( V_317 != 0 ) )
return V_317 ;
F_77 ( V_303 ) ;
F_63 ( V_303 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
int V_294 , int V_295 , int V_296 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_297 * V_298 ;
struct V_300 * V_301 ;
struct V_302 * V_303 ;
struct V_292 * V_299 ;
T_11 V_304 ;
V_33 V_305 , V_306 , V_307 ;
T_9 V_312 = V_381 ;
T_9 V_314 , V_315 , V_316 ;
int V_317 ;
if ( ! V_296 && ! V_2 -> V_293 ) {
F_56 ( L_2 ) ;
return 0 ;
}
if ( V_296 ) {
V_298 = F_57 ( V_293 ) ;
V_299 = V_293 ;
}
else {
V_298 = F_57 ( V_2 -> V_293 ) ;
V_299 = V_2 -> V_293 ;
}
V_301 = V_298 -> V_301 ;
V_303 = F_58 ( V_301 ) ;
V_317 = F_59 ( V_303 , false ) ;
if ( F_60 ( V_317 != 0 ) )
return V_317 ;
if ( V_296 )
V_304 = F_61 ( V_303 ) ;
else {
V_317 = F_62 ( V_303 , V_318 , & V_304 ) ;
if ( F_60 ( V_317 != 0 ) ) {
F_63 ( V_303 ) ;
return - V_319 ;
}
}
F_64 ( V_303 , & V_307 , NULL ) ;
F_63 ( V_303 ) ;
switch ( V_299 -> V_320 ) {
case 8 :
V_305 =
V_382 |
V_383 ;
break;
case 15 :
V_305 =
V_384 |
V_385 ;
break;
case 16 :
V_305 =
V_384 |
V_386 ;
#ifdef F_67
V_312 = V_387 ;
#endif
break;
case 24 :
case 32 :
V_305 =
V_388 |
V_389 ;
#ifdef F_67
V_312 = V_390 ;
#endif
break;
default:
F_45 ( L_3 ,
V_299 -> V_320 ) ;
return - V_319 ;
}
if ( V_9 -> V_70 >= V_391 ) {
if ( V_307 & V_330 )
V_305 |= V_392 ;
else if ( V_307 & V_342 )
V_305 |= V_393 ;
} else {
if ( V_307 & V_330 )
V_305 |= V_394 ;
if ( V_307 & V_342 )
V_305 |= V_395 ;
}
if ( V_11 -> V_18 == 0 )
F_28 ( V_348 , 0 ) ;
else
F_28 ( V_349 , 0 ) ;
if ( V_9 -> V_70 >= V_195 ) {
if ( V_11 -> V_18 ) {
F_28 ( V_396 , F_76 ( V_304 ) ) ;
F_28 ( V_397 , F_76 ( V_304 ) ) ;
} else {
F_28 ( V_398 , F_76 ( V_304 ) ) ;
F_28 ( V_399 , F_76 ( V_304 ) ) ;
}
}
F_28 ( V_400 + V_11 -> V_355 ,
( T_9 ) V_304 ) ;
F_28 ( V_401 +
V_11 -> V_355 , ( T_9 ) V_304 ) ;
F_28 ( V_402 + V_11 -> V_355 , V_305 ) ;
if ( V_9 -> V_70 >= V_391 )
F_28 ( V_403 + V_11 -> V_355 , V_312 ) ;
F_28 ( V_404 + V_11 -> V_355 , 0 ) ;
F_28 ( V_405 + V_11 -> V_355 , 0 ) ;
F_28 ( V_406 + V_11 -> V_355 , 0 ) ;
F_28 ( V_407 + V_11 -> V_355 , 0 ) ;
F_28 ( V_408 + V_11 -> V_355 , V_299 -> V_367 ) ;
F_28 ( V_409 + V_11 -> V_355 , V_299 -> V_369 ) ;
V_306 = V_299 -> V_370 [ 0 ] / ( V_299 -> V_320 / 8 ) ;
F_28 ( V_410 + V_11 -> V_355 , V_306 ) ;
F_28 ( V_411 + V_11 -> V_355 , 1 ) ;
F_28 ( V_412 + V_11 -> V_355 ,
V_299 -> V_369 ) ;
V_294 &= ~ 3 ;
V_295 &= ~ 1 ;
F_28 ( V_413 + V_11 -> V_355 ,
( V_294 << 16 ) | V_295 ) ;
V_315 = V_2 -> V_4 . V_375 ;
V_316 = ( V_2 -> V_4 . V_376 + 1 ) & ~ 1 ;
F_28 ( V_414 + V_11 -> V_355 ,
( V_315 << 16 ) | V_316 ) ;
V_314 = F_27 ( V_415 + V_11 -> V_355 ) ;
V_314 &= ~ V_416 ;
F_28 ( V_415 + V_11 -> V_355 , V_314 ) ;
F_28 ( V_417 + V_11 -> V_355 , 0 ) ;
if ( ! V_296 && V_293 && V_293 != V_2 -> V_293 ) {
V_298 = F_57 ( V_293 ) ;
V_303 = F_58 ( V_298 -> V_301 ) ;
V_317 = F_59 ( V_303 , false ) ;
if ( F_60 ( V_317 != 0 ) )
return V_317 ;
F_77 ( V_303 ) ;
F_63 ( V_303 ) ;
}
F_78 ( V_9 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_294 , int V_295 ,
struct V_292 * V_418 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_26 ( V_9 ) )
return F_54 ( V_2 , V_418 , V_294 , V_295 , 0 ) ;
else if ( F_7 ( V_9 ) )
return F_79 ( V_2 , V_418 , V_294 , V_295 , 0 ) ;
else
return F_81 ( V_2 , V_418 , V_294 , V_295 , 0 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
int V_294 , int V_295 , enum V_419 V_75 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_26 ( V_9 ) )
return F_54 ( V_2 , V_293 , V_294 , V_295 , 1 ) ;
else if ( F_7 ( V_9 ) )
return F_79 ( V_2 , V_293 , V_294 , V_295 , 1 ) ;
else
return F_81 ( V_2 , V_293 , V_294 , V_295 , 1 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_11 = F_2 ( V_2 ) ;
T_9 V_420 ;
switch ( V_11 -> V_18 ) {
case 0 :
V_420 = F_27 ( V_421 ) ;
V_420 &= ~ V_422 ;
F_28 ( V_421 , V_420 ) ;
break;
case 1 :
V_420 = F_27 ( V_423 ) ;
V_420 &= ~ V_424 ;
F_28 ( V_423 , V_420 ) ;
F_28 ( V_425 , F_27 ( V_426 ) ) ;
F_28 ( V_427 , F_27 ( V_428 ) ) ;
break;
}
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_429 ;
struct V_1 * V_430 ;
V_33 V_431 = 0 ;
if ( F_31 ( V_9 ) ) {
F_8 (test_encoder, &dev->mode_config.encoder_list, head) {
if ( V_429 -> V_2 && ( V_429 -> V_2 == V_2 ) ) {
struct V_42 * V_432 =
F_9 ( V_429 ) ;
struct V_230 * V_231 =
V_432 -> V_47 ;
if ( ( V_432 -> V_210 ==
V_433 ) &&
( V_231 -> V_434 == false ) )
return V_140 ;
}
}
F_8 (test_crtc, &dev->mode_config.crtc_list, head) {
struct V_11 * V_435 ;
if ( V_2 == V_430 )
continue;
V_435 = F_2 ( V_430 ) ;
if ( ( V_435 -> V_135 == V_250 ) ||
( V_435 -> V_135 == V_137 ) )
V_431 |= ( 1 << V_435 -> V_135 ) ;
}
if ( ! ( V_431 & 4 ) )
return V_250 ;
return V_137 ;
} else if ( F_26 ( V_9 ) ) {
F_8 (test_encoder, &dev->mode_config.encoder_list, head) {
if ( V_429 -> V_2 && ( V_429 -> V_2 == V_2 ) ) {
if ( F_43 ( F_37 ( V_429 ) ) ) {
if ( F_30 ( V_9 ) || V_9 -> clock . V_436 )
return V_143 ;
}
}
}
F_8 (test_crtc, &dev->mode_config.crtc_list, head) {
struct V_11 * V_435 ;
if ( V_2 == V_430 )
continue;
V_435 = F_2 ( V_430 ) ;
if ( ( V_435 -> V_135 >= V_137 ) &&
( V_435 -> V_135 <= V_140 ) )
V_431 |= ( 1 << V_435 -> V_135 ) ;
}
if ( ! ( V_431 & 1 ) )
return V_137 ;
return V_140 ;
} else
return V_11 -> V_18 ;
}
void F_85 ( struct V_8 * V_9 )
{
if ( F_18 ( V_9 ) )
F_46 ( V_9 , V_9 -> clock . V_437 ) ;
else if ( F_26 ( V_9 ) ) {
struct V_147 V_148 ;
bool V_181 = F_50 ( V_9 , & V_148 ,
V_438 ,
V_9 -> clock . V_437 ) ;
if ( V_181 )
F_29 ( V_9 , V_84 , V_142 , & V_148 ) ;
F_46 ( V_9 , V_9 -> clock . V_437 ) ;
if ( V_181 )
F_29 ( V_9 , V_85 , V_142 , & V_148 ) ;
}
}
int F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
int V_294 , int V_295 , struct V_292 * V_418 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_41 ;
bool V_439 = false ;
F_8 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_41 -> V_2 == V_2 ) {
struct V_42 * V_42 = F_9 ( V_41 ) ;
if ( V_42 -> V_43 &
( V_44 | V_440 ) )
V_439 = true ;
}
}
F_49 ( V_2 , V_5 ) ;
if ( F_26 ( V_9 ) )
F_23 ( V_2 , V_5 ) ;
else if ( F_7 ( V_9 ) ) {
if ( V_439 )
F_24 ( V_2 , V_5 ) ;
else
F_23 ( V_2 , V_5 ) ;
} else {
F_24 ( V_2 , V_5 ) ;
if ( V_11 -> V_18 == 0 )
F_23 ( V_2 , V_5 ) ;
F_83 ( V_2 ) ;
}
F_80 ( V_2 , V_294 , V_295 , V_418 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
if ( ! F_88 ( V_2 , V_4 , V_5 ) )
return false ;
return true ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
V_11 -> V_135 = F_84 ( V_2 ) ;
F_11 ( V_2 , V_85 ) ;
F_16 ( V_2 , V_88 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_82 ) ;
F_11 ( V_2 , V_84 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_147 V_148 ;
F_16 ( V_2 , V_88 ) ;
switch ( V_11 -> V_135 ) {
case V_137 :
case V_140 :
F_48 ( V_2 , V_11 -> V_18 , V_11 -> V_135 ,
0 , 0 , V_84 , 0 , 0 , 0 , 0 , 0 , false , & V_148 ) ;
break;
case V_250 :
if ( F_31 ( V_9 ) )
F_48 ( V_2 , V_11 -> V_18 , V_11 -> V_135 ,
0 , 0 , V_84 , 0 , 0 , 0 , 0 , 0 , false , & V_148 ) ;
break;
default:
break;
}
V_11 -> V_135 = - 1 ;
}
void F_92 ( struct V_6 * V_7 ,
struct V_11 * V_11 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( F_26 ( V_9 ) ) {
switch ( V_11 -> V_18 ) {
case 0 :
default:
V_11 -> V_355 = V_441 ;
break;
case 1 :
V_11 -> V_355 = V_442 ;
break;
case 2 :
V_11 -> V_355 = V_443 ;
break;
case 3 :
V_11 -> V_355 = V_444 ;
break;
case 4 :
V_11 -> V_355 = V_445 ;
break;
case 5 :
V_11 -> V_355 = V_446 ;
break;
}
} else {
if ( V_11 -> V_18 == 1 )
V_11 -> V_355 =
V_447 - V_448 ;
else
V_11 -> V_355 = 0 ;
}
V_11 -> V_135 = - 1 ;
F_93 ( & V_11 -> V_449 , & V_450 ) ;
}
