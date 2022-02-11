static inline bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
switch ( V_3 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_16 * V_18 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
F_4 ( V_2 ) ;
F_5 ( V_18 , 0 ) ;
if ( ( V_17 -> V_24 & V_25 )
&& ( V_17 -> V_26 < ( V_17 -> V_27 + 2 ) ) )
V_18 -> V_26 = V_18 -> V_27 + 2 ;
if ( V_3 -> V_28 & ( V_29 ) )
F_6 ( V_2 , V_18 ) ;
if ( V_3 -> V_28 & ( V_30 ) ) {
struct V_31 * V_32 = V_3 -> V_33 ;
if ( V_32 ) {
if ( V_32 -> V_34 == V_35 ||
V_32 -> V_34 == V_36 ||
V_32 -> V_34 == V_37 )
F_7 ( V_22 , 0 , V_18 ) ;
else
F_7 ( V_22 , 1 , V_18 ) ;
}
}
if ( F_8 ( V_22 ) &&
( ( V_3 -> V_28 & ( V_38 | V_29 ) ) ||
( F_9 ( V_2 ) != V_39 ) ) ) {
struct V_40 * V_41 = F_10 ( V_2 ) ;
F_11 ( V_41 , V_17 ) ;
}
return true ;
}
static void
F_12 ( struct V_1 * V_2 , int V_42 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 args ;
int V_43 = 0 ;
struct V_31 * V_44 = V_3 -> V_33 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_45 :
case V_46 :
V_43 = F_13 ( V_47 , V_48 ) ;
break;
case V_49 :
case V_50 :
V_43 = F_13 ( V_47 , V_51 ) ;
break;
}
args . V_52 = V_42 ;
if ( V_3 -> V_28 & ( V_53 ) )
args . V_54 = V_55 ;
else if ( V_3 -> V_28 & ( V_56 ) )
args . V_54 = V_57 ;
else {
switch ( V_44 -> V_34 ) {
case V_58 :
case V_37 :
case V_59 :
case V_60 :
case V_61 :
args . V_54 = V_62 ;
break;
case V_35 :
case V_36 :
case V_63 :
default:
args . V_54 = V_64 ;
break;
}
}
args . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
static void
F_16 ( struct V_1 * V_2 , int V_42 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 args ;
int V_43 = 0 ;
struct V_31 * V_44 = V_3 -> V_33 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_43 = F_13 ( V_47 , V_70 ) ;
args . V_71 . V_52 = V_42 ;
if ( V_3 -> V_28 & ( V_56 ) )
args . V_71 . V_72 = V_73 ;
else {
switch ( V_44 -> V_34 ) {
case V_35 :
args . V_71 . V_72 = V_74 ;
break;
case V_58 :
args . V_71 . V_72 = V_75 ;
break;
case V_37 :
args . V_71 . V_72 = V_76 ;
break;
case V_63 :
args . V_71 . V_72 = V_77 ;
break;
case V_36 :
args . V_71 . V_72 = V_78 ;
break;
case V_59 :
args . V_71 . V_72 = V_75 ;
break;
case V_60 :
args . V_71 . V_72 = V_79 ;
break;
case V_61 :
args . V_71 . V_72 = V_80 ;
break;
default:
args . V_71 . V_72 = V_74 ;
break;
}
}
args . V_71 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
void
F_17 ( struct V_1 * V_2 , int V_42 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
union V_81 args ;
int V_43 = F_13 ( V_47 , V_82 ) ;
T_3 V_83 , V_84 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
return;
switch ( V_83 ) {
case 1 :
switch ( V_84 ) {
case 1 :
args . V_85 . V_86 . V_87 = V_42 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_85 . V_86 . V_88 |= V_89 ;
args . V_85 . V_86 . V_88 |= V_90 ;
break;
case 2 :
args . V_91 . V_92 . V_52 = V_42 ;
args . V_91 . V_92 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
args . V_91 . V_92 . V_93 = V_94 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_91 . V_92 . V_95 . V_96 . V_97 |= V_89 ;
break;
case 3 :
args . V_98 . V_52 = V_42 ;
args . V_98 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
args . V_98 . V_99 = 0 ;
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
void
F_21 ( struct V_1 * V_2 , int V_42 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_100 * V_101 = V_3 -> V_33 ;
union V_102 args ;
int V_43 = 0 ;
int V_103 = 0 ;
T_3 V_83 , V_84 ;
if ( ! V_101 )
return;
if ( F_22 ( V_2 ) == V_104 )
V_103 = 1 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_5 :
V_43 = F_13 ( V_47 , V_105 ) ;
break;
case V_6 :
case V_7 :
V_43 = F_13 ( V_47 , V_106 ) ;
break;
case V_8 :
if ( V_3 -> V_107 & ( V_29 ) )
V_43 = F_13 ( V_47 , V_105 ) ;
else
V_43 = F_13 ( V_47 , V_108 ) ;
break;
}
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
return;
switch ( V_83 ) {
case 1 :
case 2 :
switch ( V_84 ) {
case 1 :
args . V_109 . V_88 = 0 ;
args . V_109 . V_52 = V_42 ;
if ( V_103 )
args . V_109 . V_88 |= V_110 ;
args . V_109 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
if ( V_3 -> V_107 & ( V_29 ) ) {
if ( V_101 -> V_111 & V_112 )
args . V_109 . V_88 |= V_89 ;
if ( V_101 -> V_111 & V_90 )
args . V_109 . V_88 |= V_90 ;
} else {
if ( V_101 -> V_113 )
args . V_109 . V_88 |= V_114 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_109 . V_88 |= V_89 ;
args . V_109 . V_88 |= V_90 ;
}
break;
case 2 :
case 3 :
args . V_115 . V_88 = 0 ;
args . V_115 . V_52 = V_42 ;
if ( V_84 == 3 ) {
if ( V_101 -> V_116 )
args . V_115 . V_88 |= V_117 ;
}
if ( V_103 )
args . V_115 . V_88 |= V_110 ;
args . V_115 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
args . V_115 . V_118 = 0 ;
args . V_115 . V_119 = 0 ;
args . V_115 . V_120 = 0 ;
args . V_115 . V_121 = 0 ;
if ( V_3 -> V_107 & ( V_29 ) ) {
if ( V_101 -> V_111 & V_112 )
args . V_115 . V_88 |= V_89 ;
if ( V_101 -> V_111 & V_122 ) {
args . V_115 . V_119 = V_123 ;
if ( V_101 -> V_111 & V_90 )
args . V_115 . V_119 |= V_124 ;
}
if ( V_101 -> V_111 & V_125 ) {
args . V_115 . V_120 = V_126 ;
if ( V_101 -> V_111 & V_90 )
args . V_115 . V_120 |= V_127 ;
if ( ( ( V_101 -> V_111 >> V_128 ) & 0x3 ) == 2 )
args . V_115 . V_120 |= V_129 ;
}
} else {
if ( V_101 -> V_113 )
args . V_115 . V_88 |= V_114 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_115 . V_88 |= V_89 ;
}
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
int
F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_40 * V_41 ;
struct V_130 * V_130 ;
struct V_131 * V_132 ;
if ( F_9 ( V_2 ) != V_39 )
return V_133 ;
if ( V_3 -> V_4 == V_134 )
return V_134 ;
V_41 = F_10 ( V_2 ) ;
if ( ! V_41 )
V_41 = F_23 ( V_2 ) ;
V_130 = F_24 ( V_41 ) ;
switch ( V_41 -> V_135 ) {
case V_136 :
case V_137 :
if ( F_25 ( V_130 -> V_138 ) &&
V_139 )
return V_104 ;
else if ( V_130 -> V_140 )
return V_141 ;
else
return V_142 ;
break;
case V_143 :
case V_144 :
default:
if ( F_25 ( V_130 -> V_138 ) &&
V_139 )
return V_104 ;
else
return V_141 ;
break;
case V_145 :
return V_146 ;
break;
case V_147 :
V_132 = V_130 -> V_148 ;
if ( ( V_132 -> V_149 == V_150 ) ||
( V_132 -> V_149 == V_151 ) )
return V_133 ;
else if ( F_25 ( V_130 -> V_138 ) &&
V_139 )
return V_104 ;
else
return V_141 ;
break;
case V_152 :
return V_133 ;
case V_153 :
case V_154 :
return V_142 ;
break;
case V_155 :
case V_156 :
case V_157 :
return V_158 ;
break;
}
}
void
F_26 ( struct V_1 * V_2 , int V_42 , int V_159 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_100 * V_101 = V_3 -> V_33 ;
struct V_40 * V_41 = F_10 ( V_2 ) ;
union V_160 args ;
int V_43 = 0 ;
T_3 V_83 , V_84 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_163 = V_164 ;
int V_165 = 8 ;
if ( V_41 ) {
struct V_130 * V_130 = F_24 ( V_41 ) ;
struct V_131 * V_132 =
V_130 -> V_148 ;
V_161 = V_132 -> V_161 ;
V_162 = V_132 -> V_162 ;
V_163 = V_130 -> V_166 . V_166 ;
V_165 = V_41 -> V_167 . V_165 ;
}
if ( V_101 -> V_168 == - 1 )
return;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_27 ( V_22 ) )
V_43 = F_13 ( V_47 , V_169 ) ;
else {
if ( V_101 -> V_168 )
V_43 = F_13 ( V_47 , V_170 ) ;
else
V_43 = F_13 ( V_47 , V_171 ) ;
}
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
return;
switch ( V_83 ) {
case 1 :
switch ( V_84 ) {
case 1 :
args . V_109 . V_52 = V_42 ;
args . V_109 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
if ( V_42 == V_172 )
args . V_173 . V_174 = V_159 ;
else
args . V_109 . V_175 = F_22 ( V_2 ) ;
if ( F_28 ( args . V_109 . V_175 ) )
args . V_109 . V_176 = V_162 ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_109 . V_176 = 8 ;
else
args . V_109 . V_176 = 4 ;
if ( F_28 ( args . V_109 . V_175 ) && ( V_161 == 270000 ) )
args . V_109 . V_177 |= V_178 ;
switch ( V_3 -> V_4 ) {
case V_12 :
args . V_109 . V_177 = V_179 ;
break;
case V_14 :
case V_13 :
args . V_109 . V_177 = V_180 ;
break;
case V_15 :
args . V_109 . V_177 = V_181 ;
break;
}
if ( V_101 -> V_113 )
args . V_109 . V_177 |= V_182 ;
else
args . V_109 . V_177 |= V_183 ;
break;
case 2 :
case 3 :
args . V_173 . V_52 = V_42 ;
args . V_173 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
if ( V_42 == V_172 )
args . V_173 . V_174 = V_159 ;
else
args . V_173 . V_175 = F_22 ( V_2 ) ;
if ( F_28 ( args . V_109 . V_175 ) )
args . V_173 . V_176 = V_162 ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_173 . V_176 = 8 ;
else
args . V_173 . V_176 = 4 ;
if ( F_28 ( args . V_109 . V_175 ) && ( V_161 == 270000 ) )
args . V_109 . V_177 |= V_184 ;
args . V_173 . V_185 . V_186 = V_101 -> V_168 ;
switch ( V_165 ) {
case 0 :
args . V_173 . V_187 = V_188 ;
break;
case 6 :
args . V_173 . V_187 = V_189 ;
break;
case 8 :
default:
args . V_173 . V_187 = V_190 ;
break;
case 10 :
args . V_173 . V_187 = V_191 ;
break;
case 12 :
args . V_173 . V_187 = V_192 ;
break;
case 16 :
args . V_173 . V_187 = V_193 ;
break;
}
break;
case 4 :
args . V_194 . V_52 = V_42 ;
args . V_194 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
if ( V_42 == V_172 )
args . V_194 . V_174 = V_159 ;
else
args . V_194 . V_175 = F_22 ( V_2 ) ;
if ( F_28 ( args . V_109 . V_175 ) )
args . V_194 . V_176 = V_162 ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_194 . V_176 = 8 ;
else
args . V_194 . V_176 = 4 ;
if ( F_28 ( args . V_109 . V_175 ) ) {
if ( V_161 == 270000 )
args . V_109 . V_177 |= V_195 ;
else if ( V_161 == 540000 )
args . V_109 . V_177 |= V_196 ;
}
args . V_194 . V_185 . V_186 = V_101 -> V_168 ;
switch ( V_165 ) {
case 0 :
args . V_194 . V_187 = V_188 ;
break;
case 6 :
args . V_194 . V_187 = V_189 ;
break;
case 8 :
default:
args . V_194 . V_187 = V_190 ;
break;
case 10 :
args . V_194 . V_187 = V_191 ;
break;
case 12 :
args . V_194 . V_187 = V_192 ;
break;
case 16 :
args . V_194 . V_187 = V_193 ;
break;
}
if ( V_163 == V_164 )
args . V_194 . V_197 = 0 ;
else
args . V_194 . V_197 = V_163 + 1 ;
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
void
F_29 ( struct V_1 * V_2 , int V_42 , T_3 V_198 , T_3 V_199 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_100 * V_101 = V_3 -> V_33 ;
struct V_40 * V_41 ;
union V_200 args ;
int V_43 = 0 ;
T_3 V_83 , V_84 ;
bool V_201 = false ;
int V_202 = 0 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_203 = 0 ;
int V_204 = 0 ;
int V_168 = V_101 -> V_168 ;
if ( V_42 == V_205 ) {
V_41 = F_23 ( V_2 ) ;
V_168 = 0 ;
} else
V_41 = F_10 ( V_2 ) ;
if ( V_41 ) {
struct V_130 * V_130 = F_24 ( V_41 ) ;
struct V_131 * V_132 =
V_130 -> V_148 ;
V_161 = V_132 -> V_161 ;
V_162 = V_132 -> V_162 ;
V_203 =
( V_130 -> V_203 & V_206 ) >> V_207 ;
V_204 = V_132 -> V_204 ;
}
if ( V_2 -> V_208 ) {
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
V_202 = V_209 -> V_202 ;
}
if ( V_168 == - 1 )
return;
if ( F_28 ( F_22 ( V_2 ) ) )
V_201 = true ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_10 :
V_43 = F_13 ( V_47 , V_210 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
V_43 = F_13 ( V_47 , V_211 ) ;
break;
case V_13 :
V_43 = F_13 ( V_47 , V_212 ) ;
break;
}
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
return;
switch ( V_83 ) {
case 1 :
switch ( V_84 ) {
case 1 :
args . V_109 . V_52 = V_42 ;
if ( V_42 == V_205 ) {
args . V_109 . V_213 = F_14 ( V_203 ) ;
} else if ( V_42 == V_214 ) {
args . V_109 . V_215 . V_216 = V_198 ;
args . V_109 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_109 . V_65 =
F_14 ( V_161 / 10 ) ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_109 . V_65 = F_14 ( ( V_3 -> V_66 / 2 ) / 10 ) ;
else
args . V_109 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
}
args . V_109 . V_177 = V_218 ;
if ( V_168 )
args . V_109 . V_177 |= V_219 ;
else
args . V_109 . V_177 |= V_220 ;
if ( ( V_22 -> V_24 & V_221 ) &&
( V_3 -> V_4 == V_12 ) ) {
if ( V_201 ||
! F_19 ( V_2 , V_3 -> V_66 ) ) {
if ( V_204 & 0x1 )
args . V_109 . V_177 |= V_222 ;
else if ( V_204 & 0x2 )
args . V_109 . V_177 |= V_223 ;
else if ( V_204 & 0x4 )
args . V_109 . V_177 |= V_224 ;
else if ( V_204 & 0x8 )
args . V_109 . V_177 |= V_225 ;
} else {
if ( V_204 & 0x3 )
args . V_109 . V_177 |= V_226 ;
else if ( V_204 & 0xc )
args . V_109 . V_177 |= V_227 ;
}
}
if ( V_101 -> V_113 )
args . V_109 . V_177 |= V_228 ;
else
args . V_109 . V_177 |= V_229 ;
if ( V_201 )
args . V_109 . V_177 |= V_230 ;
else if ( V_3 -> V_107 & ( V_38 ) ) {
if ( V_101 -> V_116 )
args . V_109 . V_177 |= V_230 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_109 . V_177 |= V_231 ;
}
break;
case 2 :
args . V_115 . V_52 = V_42 ;
if ( V_42 == V_205 ) {
args . V_115 . V_213 = F_14 ( V_203 ) ;
} else if ( V_42 == V_214 ) {
args . V_115 . V_215 . V_216 = V_198 ;
args . V_115 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_115 . V_65 =
F_14 ( V_161 / 10 ) ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_115 . V_65 = F_14 ( ( V_3 -> V_66 / 2 ) / 10 ) ;
else
args . V_115 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
}
args . V_115 . V_185 . V_232 = V_168 ;
if ( V_101 -> V_113 )
args . V_115 . V_185 . V_233 = 1 ;
switch ( V_3 -> V_4 ) {
case V_12 :
args . V_115 . V_185 . V_234 = 0 ;
break;
case V_14 :
args . V_115 . V_185 . V_234 = 1 ;
break;
case V_15 :
args . V_115 . V_185 . V_234 = 2 ;
break;
}
if ( V_201 ) {
args . V_115 . V_185 . V_235 = 1 ;
args . V_115 . V_185 . V_236 = 1 ;
} else if ( V_3 -> V_107 & ( V_38 ) ) {
if ( V_101 -> V_116 )
args . V_115 . V_185 . V_235 = 1 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_115 . V_185 . V_237 = 1 ;
}
break;
case 3 :
args . V_173 . V_52 = V_42 ;
if ( V_42 == V_205 ) {
args . V_173 . V_213 = F_14 ( V_203 ) ;
} else if ( V_42 == V_214 ) {
args . V_173 . V_215 . V_216 = V_198 ;
args . V_173 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_173 . V_65 =
F_14 ( V_161 / 10 ) ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_173 . V_65 = F_14 ( ( V_3 -> V_66 / 2 ) / 10 ) ;
else
args . V_173 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
}
if ( V_201 )
args . V_173 . V_176 = V_162 ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_173 . V_176 = 8 ;
else
args . V_173 . V_176 = 4 ;
if ( V_101 -> V_113 )
args . V_173 . V_185 . V_233 = 1 ;
if ( V_168 & 1 )
args . V_173 . V_185 . V_232 = 1 ;
if ( V_201 && V_22 -> clock . V_238 )
args . V_173 . V_185 . V_239 = 2 ;
else
args . V_173 . V_185 . V_239 = V_202 ;
switch ( V_3 -> V_4 ) {
case V_12 :
args . V_173 . V_185 . V_234 = 0 ;
break;
case V_14 :
args . V_173 . V_185 . V_234 = 1 ;
break;
case V_15 :
args . V_173 . V_185 . V_234 = 2 ;
break;
}
if ( V_201 )
args . V_173 . V_185 . V_235 = 1 ;
else if ( V_3 -> V_107 & ( V_38 ) ) {
if ( V_101 -> V_116 )
args . V_173 . V_185 . V_235 = 1 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_173 . V_185 . V_237 = 1 ;
}
break;
case 4 :
args . V_194 . V_52 = V_42 ;
if ( V_42 == V_205 ) {
args . V_194 . V_213 = F_14 ( V_203 ) ;
} else if ( V_42 == V_214 ) {
args . V_194 . V_215 . V_216 = V_198 ;
args . V_194 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_194 . V_65 =
F_14 ( V_161 / 10 ) ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_194 . V_65 = F_14 ( ( V_3 -> V_66 / 2 ) / 10 ) ;
else
args . V_194 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
}
if ( V_201 )
args . V_194 . V_176 = V_162 ;
else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_194 . V_176 = 8 ;
else
args . V_194 . V_176 = 4 ;
if ( V_101 -> V_113 )
args . V_194 . V_185 . V_233 = 1 ;
if ( V_168 & 1 )
args . V_194 . V_185 . V_232 = 1 ;
if ( V_201 ) {
if ( V_22 -> clock . V_238 )
args . V_194 . V_185 . V_239 = V_240 ;
else
args . V_194 . V_185 . V_239 = V_241 ;
} else
args . V_194 . V_185 . V_239 = V_202 ;
switch ( V_3 -> V_4 ) {
case V_12 :
args . V_194 . V_185 . V_234 = 0 ;
break;
case V_14 :
args . V_194 . V_185 . V_234 = 1 ;
break;
case V_15 :
args . V_194 . V_185 . V_234 = 2 ;
break;
}
if ( V_201 )
args . V_194 . V_185 . V_235 = 1 ;
else if ( V_3 -> V_107 & ( V_38 ) ) {
if ( V_101 -> V_116 )
args . V_194 . V_185 . V_235 = 1 ;
if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_194 . V_185 . V_237 = 1 ;
}
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
break;
default:
F_20 ( L_1 , V_83 , V_84 ) ;
break;
}
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
bool
F_31 ( struct V_40 * V_41 , int V_42 )
{
struct V_130 * V_130 = F_24 ( V_41 ) ;
struct V_19 * V_20 = V_130 -> V_242 . V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
union V_200 args ;
int V_43 = F_13 ( V_47 , V_211 ) ;
T_3 V_83 , V_84 ;
if ( V_41 -> V_135 != V_152 )
goto V_243;
if ( ! F_27 ( V_22 ) )
goto V_243;
if ( ( V_42 != V_244 ) &&
( V_42 != V_245 ) )
goto V_243;
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
goto V_243;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_109 . V_52 = V_42 ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
if ( V_42 == V_244 ) {
int V_246 ;
for ( V_246 = 0 ; V_246 < 300 ; V_246 ++ ) {
if ( F_32 ( V_22 , V_130 -> V_166 . V_166 ) )
return true ;
F_33 ( 1 ) ;
}
return false ;
}
V_243:
return true ;
}
static void
F_34 ( struct V_1 * V_2 ,
struct V_1 * V_247 ,
int V_42 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_3 * V_248 = F_2 ( V_247 ) ;
union V_249 args ;
struct V_40 * V_41 ;
int V_43 = F_13 ( V_47 , V_250 ) ;
T_4 V_83 , V_84 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_203 = 0 ;
T_5 V_251 = ( V_248 -> V_252 & V_253 ) >> V_254 ;
int V_165 = 8 ;
if ( V_42 == V_255 )
V_41 = F_23 ( V_2 ) ;
else
V_41 = F_10 ( V_2 ) ;
if ( V_41 ) {
struct V_130 * V_130 = F_24 ( V_41 ) ;
struct V_131 * V_132 =
V_130 -> V_148 ;
V_161 = V_132 -> V_161 ;
V_162 = V_132 -> V_162 ;
V_203 =
( V_130 -> V_203 & V_206 ) >> V_207 ;
V_165 = V_41 -> V_167 . V_165 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
return;
switch ( V_83 ) {
case 1 :
break;
case 2 :
switch ( V_84 ) {
case 1 :
case 2 :
args . V_109 . V_256 . V_52 = V_42 ;
args . V_109 . V_256 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
args . V_109 . V_256 . V_175 = F_22 ( V_2 ) ;
if ( F_28 ( args . V_109 . V_256 . V_175 ) ) {
if ( V_161 == 270000 )
args . V_109 . V_256 . V_177 |= V_178 ;
args . V_109 . V_256 . V_176 = V_162 ;
} else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_109 . V_256 . V_176 = 8 ;
else
args . V_109 . V_256 . V_176 = 4 ;
break;
case 3 :
args . V_173 . V_257 . V_52 = V_42 ;
if ( V_42 == V_255 )
args . V_173 . V_257 . V_258 = F_14 ( V_203 ) ;
else
args . V_173 . V_257 . V_65 = F_14 ( V_3 -> V_66 / 10 ) ;
args . V_173 . V_257 . V_175 = F_22 ( V_2 ) ;
if ( F_28 ( args . V_173 . V_257 . V_175 ) ) {
if ( V_161 == 270000 )
args . V_173 . V_257 . V_177 |= V_259 ;
else if ( V_161 == 540000 )
args . V_173 . V_257 . V_177 |= V_260 ;
args . V_173 . V_257 . V_176 = V_162 ;
} else if ( F_19 ( V_2 , V_3 -> V_66 ) )
args . V_173 . V_257 . V_176 = 8 ;
else
args . V_173 . V_257 . V_176 = 4 ;
switch ( V_251 ) {
case V_261 :
args . V_173 . V_257 . V_177 |= V_262 ;
break;
case V_263 :
args . V_173 . V_257 . V_177 |= V_264 ;
break;
case V_265 :
args . V_173 . V_257 . V_177 |= V_266 ;
break;
}
switch ( V_165 ) {
case 0 :
args . V_173 . V_257 . V_187 = V_188 ;
break;
case 6 :
args . V_173 . V_257 . V_187 = V_189 ;
break;
case 8 :
default:
args . V_173 . V_257 . V_187 = V_190 ;
break;
case 10 :
args . V_173 . V_257 . V_187 = V_191 ;
break;
case 12 :
args . V_173 . V_257 . V_187 = V_192 ;
break;
case 16 :
args . V_173 . V_257 . V_187 = V_193 ;
break;
}
break;
default:
F_20 ( L_2 , V_83 , V_84 ) ;
return;
}
break;
default:
F_20 ( L_2 , V_83 , V_84 ) ;
return;
}
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
static void
F_35 ( struct V_1 * V_2 , bool V_267 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
T_6 args ;
int V_43 = F_13 ( V_47 , V_268 ) ;
V_69 V_269 , V_270 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( V_22 -> V_271 >= V_272 )
V_270 = V_273 ;
else
V_270 = V_274 ;
V_269 = F_36 ( V_270 ) ;
if ( V_3 -> V_28 & ( V_30 ) )
F_37 ( V_270 , ( V_275 |
( V_209 -> V_276 << 18 ) ) ) ;
else if ( V_3 -> V_28 & ( V_56 ) )
F_37 ( V_270 , ( V_277 | ( V_209 -> V_276 << 24 ) ) ) ;
else
F_37 ( V_270 , 0 ) ;
if ( V_267 )
args . V_87 = V_278 ;
args . V_279 = V_209 -> V_276 ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
F_37 ( V_270 , V_269 ) ;
}
static void
F_38 ( struct V_1 * V_2 , int V_17 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_7 args ;
int V_43 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
V_43 = F_13 ( V_47 , V_280 ) ;
break;
case V_9 :
case V_11 :
case V_10 :
V_43 = F_13 ( V_47 , V_210 ) ;
break;
case V_5 :
V_43 = F_13 ( V_47 , V_281 ) ;
break;
case V_8 :
if ( V_3 -> V_107 & ( V_29 ) )
V_43 = F_13 ( V_47 , V_281 ) ;
else
V_43 = F_13 ( V_47 , V_282 ) ;
break;
case V_45 :
case V_46 :
if ( V_3 -> V_28 & ( V_30 ) )
V_43 = F_13 ( V_47 , V_283 ) ;
else if ( V_3 -> V_28 & ( V_56 ) )
V_43 = F_13 ( V_47 , V_284 ) ;
else
V_43 = F_13 ( V_47 , V_285 ) ;
break;
case V_49 :
case V_50 :
if ( V_3 -> V_28 & ( V_30 ) )
V_43 = F_13 ( V_47 , V_283 ) ;
else if ( V_3 -> V_28 & ( V_56 ) )
V_43 = F_13 ( V_47 , V_284 ) ;
else
V_43 = F_13 ( V_47 , V_286 ) ;
break;
default:
return;
}
switch ( V_17 ) {
case V_287 :
args . V_52 = V_278 ;
if ( V_3 -> V_4 == V_11 ) {
T_5 V_270 = F_36 ( V_274 ) ;
F_37 ( V_274 , V_270 & ~ V_288 ) ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
F_37 ( V_274 , V_270 ) ;
} else
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
if ( V_3 -> V_107 & ( V_29 ) ) {
args . V_52 = V_289 ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
break;
case V_290 :
case V_291 :
case V_292 :
args . V_52 = V_293 ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
if ( V_3 -> V_107 & ( V_29 ) ) {
args . V_52 = V_294 ;
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
}
break;
}
}
static void
F_39 ( struct V_1 * V_2 , int V_17 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_40 * V_41 = F_10 ( V_2 ) ;
struct V_130 * V_130 = NULL ;
struct V_131 * V_295 = NULL ;
if ( V_41 ) {
V_130 = F_24 ( V_41 ) ;
V_295 = V_130 -> V_148 ;
}
switch ( V_17 ) {
case V_287 :
if ( ( V_22 -> V_271 == V_296 ) || ( V_22 -> V_271 == V_297 ) ||
F_40 ( V_22 ) || F_41 ( V_22 ) )
F_29 ( V_2 , V_298 , 0 , 0 ) ;
else
F_29 ( V_2 , V_299 , 0 , 0 ) ;
if ( F_28 ( F_22 ( V_2 ) ) && V_41 ) {
if ( V_41 -> V_135 == V_152 ) {
F_31 ( V_41 ,
V_244 ) ;
V_295 -> V_300 = true ;
}
F_42 ( V_2 , V_41 ) ;
if ( F_27 ( V_22 ) )
F_26 ( V_2 , V_301 , 0 ) ;
}
if ( V_3 -> V_107 & ( V_29 ) )
F_29 ( V_2 , V_302 , 0 , 0 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
if ( F_40 ( V_22 ) || F_41 ( V_22 ) )
F_29 ( V_2 , V_303 , 0 , 0 ) ;
else
F_29 ( V_2 , V_304 , 0 , 0 ) ;
if ( F_28 ( F_22 ( V_2 ) ) && V_41 ) {
if ( F_27 ( V_22 ) )
F_26 ( V_2 , V_305 , 0 ) ;
if ( V_41 -> V_135 == V_152 ) {
F_31 ( V_41 ,
V_245 ) ;
V_295 -> V_300 = false ;
}
}
if ( V_3 -> V_107 & ( V_29 ) )
F_29 ( V_2 , V_306 , 0 , 0 ) ;
break;
}
}
static void
F_43 ( struct V_1 * V_2 ,
struct V_1 * V_247 ,
int V_17 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
switch ( V_17 ) {
case V_287 :
default:
if ( F_40 ( V_22 ) ) {
F_34 ( V_2 , V_247 ,
V_307 ) ;
F_34 ( V_2 , V_247 ,
V_308 ) ;
} else
F_34 ( V_2 , V_247 , V_278 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
if ( F_40 ( V_22 ) ) {
F_34 ( V_2 , V_247 ,
V_309 ) ;
F_34 ( V_2 , V_247 ,
V_310 ) ;
} else
F_34 ( V_2 , V_247 , V_293 ) ;
break;
}
}
static void
F_44 ( struct V_1 * V_2 , int V_17 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_247 = F_45 ( V_2 ) ;
F_46 ( L_3 ,
V_3 -> V_4 , V_17 , V_3 -> V_107 ,
V_3 -> V_28 ) ;
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
case V_5 :
case V_8 :
case V_9 :
case V_11 :
case V_49 :
case V_50 :
F_38 ( V_2 , V_17 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_13 :
F_39 ( V_2 , V_17 ) ;
break;
case V_10 :
if ( F_41 ( V_22 ) ) {
switch ( V_17 ) {
case V_287 :
F_17 ( V_2 , V_278 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
F_17 ( V_2 , V_293 ) ;
break;
}
} else if ( F_8 ( V_22 ) )
F_39 ( V_2 , V_17 ) ;
else
F_38 ( V_2 , V_17 ) ;
break;
case V_45 :
case V_46 :
if ( F_41 ( V_22 ) ) {
switch ( V_17 ) {
case V_287 :
F_12 ( V_2 , V_278 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
F_12 ( V_2 , V_293 ) ;
break;
}
} else
F_38 ( V_2 , V_17 ) ;
break;
default:
return;
}
if ( V_247 )
F_43 ( V_2 , V_247 , V_17 ) ;
F_47 ( V_2 , ( V_17 == V_287 ) ? true : false ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
union V_311 args ;
int V_43 = F_13 ( V_47 , V_312 ) ;
T_3 V_83 , V_84 ;
struct V_100 * V_101 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
return;
switch ( V_83 ) {
case 1 :
switch ( V_84 ) {
case 1 :
default:
if ( F_49 ( V_22 ) )
args . V_109 . V_279 = V_209 -> V_276 ;
else {
if ( V_3 -> V_4 == V_45 ) {
args . V_109 . V_279 = V_209 -> V_276 ;
} else {
args . V_109 . V_279 = V_209 -> V_276 << 2 ;
}
}
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
args . V_109 . V_313 = V_94 ;
break;
case V_5 :
case V_8 :
if ( V_3 -> V_107 & V_314 )
args . V_109 . V_313 = V_315 ;
else
args . V_109 . V_313 = V_316 ;
break;
case V_9 :
case V_11 :
case V_10 :
args . V_109 . V_313 = V_317 ;
break;
case V_45 :
case V_46 :
if ( V_3 -> V_28 & ( V_30 ) )
args . V_109 . V_313 = V_318 ;
else if ( V_3 -> V_28 & ( V_56 ) )
args . V_109 . V_313 = V_319 ;
else
args . V_109 . V_313 = V_320 ;
break;
case V_49 :
case V_50 :
if ( V_3 -> V_28 & ( V_30 ) )
args . V_109 . V_313 = V_318 ;
else if ( V_3 -> V_28 & ( V_56 ) )
args . V_109 . V_313 = V_319 ;
else
args . V_109 . V_313 = V_321 ;
break;
}
break;
case 2 :
args . V_115 . V_279 = V_209 -> V_276 ;
if ( F_9 ( V_2 ) != V_39 ) {
struct V_40 * V_41 = F_10 ( V_2 ) ;
if ( V_41 -> V_135 == V_145 )
args . V_115 . V_322 = V_146 ;
else if ( V_41 -> V_135 == V_154 )
args . V_115 . V_322 = V_142 ;
else
args . V_115 . V_322 = F_22 ( V_2 ) ;
} else
args . V_115 . V_322 = F_22 ( V_2 ) ;
switch ( V_3 -> V_4 ) {
case V_12 :
case V_14 :
case V_15 :
case V_13 :
V_101 = V_3 -> V_33 ;
switch ( V_101 -> V_168 ) {
case 0 :
args . V_115 . V_323 = V_324 ;
break;
case 1 :
args . V_115 . V_323 = V_325 ;
break;
case 2 :
args . V_115 . V_323 = V_326 ;
break;
case 3 :
args . V_115 . V_323 = V_327 ;
break;
case 4 :
args . V_115 . V_323 = V_328 ;
break;
case 5 :
args . V_115 . V_323 = V_329 ;
break;
}
break;
case V_10 :
args . V_115 . V_323 = V_330 ;
break;
case V_46 :
if ( V_3 -> V_28 & ( V_30 ) )
args . V_115 . V_323 = V_331 ;
else if ( V_3 -> V_28 & ( V_56 ) )
args . V_115 . V_323 = V_331 ;
else
args . V_115 . V_323 = V_332 ;
break;
case V_50 :
if ( V_3 -> V_28 & ( V_30 ) )
args . V_115 . V_323 = V_331 ;
else if ( V_3 -> V_28 & ( V_56 ) )
args . V_115 . V_323 = V_331 ;
else
args . V_115 . V_323 = V_333 ;
break;
}
break;
}
break;
default:
F_20 ( L_2 , V_83 , V_84 ) ;
return;
}
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
F_50 ( V_2 , V_209 -> V_276 ) ;
}
static void
F_51 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
if ( ( V_20 -> V_334 -> V_335 == 0x71C5 ) &&
( V_20 -> V_334 -> V_336 == 0x106b ) &&
( V_20 -> V_334 -> V_337 == 0x0080 ) ) {
if ( V_3 -> V_107 & V_314 ) {
V_69 V_338 = F_36 ( V_339 ) ;
V_338 &= ~ V_340 ;
V_338 &= ~ V_341 ;
F_37 ( V_339 , V_338 ) ;
}
}
if ( F_49 ( V_22 ) &&
( ! ( V_3 -> V_28 & ( V_30 ) ) ) ) {
if ( F_27 ( V_22 ) ) {
if ( V_17 -> V_24 & V_25 )
F_37 ( V_342 + V_209 -> V_343 ,
V_344 ) ;
else
F_37 ( V_342 + V_209 -> V_343 , 0 ) ;
} else {
if ( V_17 -> V_24 & V_25 )
F_37 ( V_345 + V_209 -> V_343 ,
V_346 ) ;
else
F_37 ( V_345 + V_209 -> V_343 , 0 ) ;
}
}
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_347 ;
struct V_100 * V_101 ;
V_69 V_348 = 0 ;
if ( F_27 ( V_22 ) ) {
V_101 = V_3 -> V_33 ;
if ( F_40 ( V_22 ) ) {
if ( V_22 -> V_271 == V_349 ) {
if ( V_101 -> V_113 )
return 1 ;
else
return 0 ;
} else
return V_209 -> V_276 ;
} else {
switch ( V_3 -> V_4 ) {
case V_12 :
if ( V_101 -> V_113 )
return 1 ;
else
return 0 ;
break;
case V_14 :
if ( V_101 -> V_113 )
return 3 ;
else
return 2 ;
break;
case V_15 :
if ( V_101 -> V_113 )
return 5 ;
else
return 4 ;
break;
}
}
}
if ( F_53 ( V_22 ) ) {
return V_209 -> V_276 ;
}
F_54 (test_encoder, &dev->mode_config.encoder_list, head) {
struct V_3 * V_350 ;
if ( V_2 == V_347 )
continue;
if ( ! F_1 ( V_347 ) )
continue;
V_350 = F_2 ( V_347 ) ;
V_101 = V_350 -> V_33 ;
if ( V_101 -> V_168 >= 0 )
V_348 |= ( 1 << V_101 -> V_168 ) ;
}
if ( V_3 -> V_4 == V_13 ) {
if ( V_348 & 0x2 )
F_20 ( L_4 ) ;
return 1 ;
}
if ( ! ( V_348 & 1 ) )
return 0 ;
return 1 ;
}
void
F_55 ( struct V_21 * V_22 )
{
struct V_19 * V_20 = V_22 -> V_351 ;
struct V_1 * V_2 ;
F_54 (encoder, &dev->mode_config.encoder_list, head) {
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_247 = F_45 ( V_2 ) ;
switch ( V_3 -> V_4 ) {
case V_12 :
case V_14 :
case V_15 :
case V_13 :
F_29 ( V_2 , V_205 , 0 , 0 ) ;
break;
default:
break;
}
if ( V_247 && F_40 ( V_22 ) )
F_34 ( V_2 , V_247 ,
V_255 ) ;
}
}
static void
F_56 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_16 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_247 = F_45 ( V_2 ) ;
V_3 -> V_66 = V_18 -> clock ;
if ( F_49 ( V_22 ) && ! F_27 ( V_22 ) ) {
if ( V_3 -> V_28 & ( V_56 | V_30 ) )
F_35 ( V_2 , true ) ;
else
F_35 ( V_2 , false ) ;
}
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
case V_5 :
case V_8 :
F_21 ( V_2 , V_352 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_13 :
if ( F_40 ( V_22 ) || F_41 ( V_22 ) ) {
struct V_40 * V_41 = F_10 ( V_2 ) ;
struct V_100 * V_101 = V_3 -> V_33 ;
if ( ! V_41 )
V_101 -> V_159 = V_353 ;
else
V_101 -> V_159 = F_57 ( V_2 , V_41 ) ;
F_26 ( V_2 , V_354 , 0 ) ;
F_26 ( V_2 ,
V_172 ,
V_101 -> V_159 ) ;
} else if ( F_27 ( V_22 ) ) {
F_29 ( V_2 , V_303 , 0 , 0 ) ;
F_26 ( V_2 , V_354 , 0 ) ;
F_29 ( V_2 , V_298 , 0 , 0 ) ;
} else {
F_29 ( V_2 , V_303 , 0 , 0 ) ;
F_26 ( V_2 , V_293 , 0 ) ;
F_26 ( V_2 , V_278 , 0 ) ;
F_29 ( V_2 , V_355 , 0 , 0 ) ;
F_29 ( V_2 , V_298 , 0 , 0 ) ;
}
break;
case V_11 :
case V_9 :
case V_10 :
F_17 ( V_2 , V_278 ) ;
break;
case V_45 :
case V_46 :
case V_49 :
case V_50 :
F_12 ( V_2 , V_278 ) ;
if ( V_3 -> V_107 & ( V_30 | V_56 ) ) {
if ( V_3 -> V_28 & ( V_30 | V_56 ) )
F_16 ( V_2 , V_278 ) ;
else
F_16 ( V_2 , V_293 ) ;
}
break;
}
if ( V_247 ) {
if ( F_40 ( V_22 ) )
F_34 ( V_2 , V_247 ,
V_356 ) ;
else
F_34 ( V_2 , V_247 , V_278 ) ;
}
F_51 ( V_2 , V_18 ) ;
if ( F_22 ( V_2 ) == V_104 ) {
F_58 ( V_2 ) ;
F_59 ( V_2 , V_18 ) ;
}
}
static bool
F_60 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_130 * V_130 = F_24 ( V_41 ) ;
if ( V_3 -> V_107 & ( V_30 |
V_56 |
V_53 ) ) {
T_8 args ;
int V_43 = F_13 ( V_47 , V_357 ) ;
T_3 V_83 , V_84 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_18 ( V_22 -> V_67 . V_68 , V_43 , & V_83 , & V_84 ) )
return false ;
args . V_358 . V_88 = 0 ;
if ( ( V_3 -> V_4 == V_45 ) ||
( V_3 -> V_4 == V_46 ) )
args . V_358 . V_359 = V_360 ;
else
args . V_358 . V_359 = V_361 ;
if ( V_130 -> V_107 & V_362 )
args . V_358 . V_363 = F_14 ( V_362 ) ;
else if ( V_130 -> V_107 & V_364 )
args . V_358 . V_363 = F_14 ( V_364 ) ;
else if ( V_130 -> V_107 & V_56 ) {
args . V_358 . V_363 = F_14 ( V_56 ) ;
if ( V_84 >= 3 )
args . V_358 . V_88 = V_365 ;
} else if ( V_130 -> V_107 & V_366 ) {
args . V_358 . V_363 = F_14 ( V_366 ) ;
if ( V_84 >= 3 )
args . V_358 . V_88 = V_365 ;
}
F_15 ( V_22 -> V_67 . V_68 , V_43 , ( V_69 * ) & args ) ;
return true ;
} else
return false ;
}
static enum V_367
F_61 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_130 * V_130 = F_24 ( V_41 ) ;
V_69 V_368 ;
if ( ! F_60 ( V_2 , V_41 ) ) {
F_46 ( L_5 ) ;
return V_369 ;
}
if ( V_22 -> V_271 >= V_272 )
V_368 = F_36 ( V_370 ) ;
else
V_368 = F_36 ( V_371 ) ;
F_46 ( L_6 , V_368 , V_3 -> V_107 ) ;
if ( V_130 -> V_107 & V_362 ) {
if ( V_368 & V_372 )
return V_373 ;
}
if ( V_130 -> V_107 & V_364 ) {
if ( V_368 & V_374 )
return V_373 ;
}
if ( V_130 -> V_107 & V_56 ) {
if ( V_368 & ( V_375 | V_376 ) )
return V_373 ;
}
if ( V_130 -> V_107 & V_366 ) {
if ( V_368 & ( V_377 | V_378 ) )
return V_373 ;
else if ( V_368 & ( V_379 | V_380 ) )
return V_373 ;
}
return V_381 ;
}
static enum V_367
F_62 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_130 * V_130 = F_24 ( V_41 ) ;
struct V_1 * V_247 = F_45 ( V_2 ) ;
T_5 V_368 ;
if ( ! F_27 ( V_22 ) )
return V_369 ;
if ( ! V_247 )
return V_369 ;
if ( ( V_130 -> V_107 & V_53 ) == 0 )
return V_369 ;
F_34 ( V_2 , V_247 ,
V_382 ) ;
V_368 = F_36 ( V_370 ) ;
F_46 ( L_6 , V_368 , V_3 -> V_107 ) ;
if ( V_130 -> V_107 & V_362 ) {
if ( V_368 & V_372 )
return V_373 ;
}
if ( V_130 -> V_107 & V_364 ) {
if ( V_368 & V_374 )
return V_373 ;
}
if ( V_130 -> V_107 & V_56 ) {
if ( V_368 & ( V_375 | V_376 ) )
return V_373 ;
}
if ( V_130 -> V_107 & V_366 ) {
if ( V_368 & ( V_377 | V_378 ) )
return V_373 ;
else if ( V_368 & ( V_379 | V_380 ) )
return V_373 ;
}
return V_381 ;
}
void
F_63 ( struct V_1 * V_2 )
{
struct V_1 * V_247 = F_45 ( V_2 ) ;
if ( V_247 )
F_34 ( V_2 , V_247 ,
V_383 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_40 * V_41 = F_10 ( V_2 ) ;
if ( ( V_3 -> V_28 &
( V_38 | V_29 ) ) ||
( F_9 ( V_2 ) !=
V_39 ) ) {
struct V_100 * V_101 = V_3 -> V_33 ;
if ( V_101 )
V_101 -> V_168 = F_52 ( V_2 ) ;
}
F_65 ( V_2 , true ) ;
F_44 ( V_2 , V_292 ) ;
if ( V_41 ) {
struct V_130 * V_130 = F_24 ( V_41 ) ;
if ( V_130 -> V_384 . V_385 )
F_66 ( V_130 ) ;
if ( V_41 -> V_135 == V_152 )
F_31 ( V_41 ,
V_244 ) ;
}
F_48 ( V_2 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_44 ( V_2 , V_287 ) ;
F_65 ( V_2 , false ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_100 * V_101 ;
if ( ! F_8 ( V_22 ) ) {
struct V_1 * V_386 ;
struct V_3 * V_387 ;
F_54 (other_encoder, &dev->mode_config.encoder_list, head) {
V_387 = F_2 ( V_386 ) ;
if ( ( V_3 -> V_4 == V_387 -> V_4 ) &&
F_69 ( V_386 ) )
goto V_388;
}
}
F_44 ( V_2 , V_292 ) ;
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
case V_5 :
case V_8 :
F_21 ( V_2 , V_389 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_13 :
if ( F_27 ( V_22 ) )
F_29 ( V_2 , V_303 , 0 , 0 ) ;
else {
F_29 ( V_2 , V_303 , 0 , 0 ) ;
F_26 ( V_2 , V_293 , 0 ) ;
}
break;
case V_11 :
case V_9 :
case V_10 :
F_17 ( V_2 , V_293 ) ;
break;
case V_45 :
case V_46 :
case V_49 :
case V_50 :
F_12 ( V_2 , V_293 ) ;
if ( V_3 -> V_107 & ( V_30 | V_56 ) )
F_16 ( V_2 , V_293 ) ;
break;
}
V_388:
if ( F_1 ( V_2 ) ) {
if ( F_22 ( V_2 ) == V_104 )
F_70 ( V_2 ) ;
V_101 = V_3 -> V_33 ;
V_101 -> V_168 = - 1 ;
}
V_3 -> V_28 = 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
}
static void F_72 ( struct V_1 * V_2 )
{
}
static void
F_73 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_16 * V_18 )
{
}
static void F_74 ( struct V_1 * V_2 )
{
}
static void
F_75 ( struct V_1 * V_2 , int V_17 )
{
}
static bool F_76 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_16 * V_18 )
{
return true ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_78 ( V_3 -> V_33 ) ;
F_79 ( V_2 ) ;
F_78 ( V_3 ) ;
}
struct V_31 *
F_80 ( struct V_3 * V_3 )
{
struct V_19 * V_20 = V_3 -> V_242 . V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_31 * V_390 = F_81 ( sizeof( struct V_31 ) , V_391 ) ;
if ( ! V_390 )
return NULL ;
V_390 -> V_34 = F_82 ( V_22 ) ;
return V_390 ;
}
struct V_100 *
F_83 ( struct V_3 * V_3 )
{
int V_252 = ( V_3 -> V_252 & V_253 ) >> V_254 ;
struct V_100 * V_101 = F_81 ( sizeof( struct V_100 ) , V_391 ) ;
if ( ! V_101 )
return NULL ;
V_101 -> V_116 = true ;
V_101 -> V_168 = - 1 ;
if ( V_252 == 2 )
V_101 -> V_113 = true ;
else
V_101 -> V_113 = false ;
return V_101 ;
}
void
F_84 ( struct V_19 * V_20 ,
V_69 V_252 ,
V_69 V_392 ,
T_9 V_393 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
F_54 (encoder, &dev->mode_config.encoder_list, head) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_252 == V_252 ) {
V_3 -> V_107 |= V_392 ;
return;
}
}
V_3 = F_81 ( sizeof( struct V_3 ) , V_391 ) ;
if ( ! V_3 )
return;
V_2 = & V_3 -> V_242 ;
switch ( V_22 -> V_394 ) {
case 1 :
V_2 -> V_395 = 0x1 ;
break;
case 2 :
default:
V_2 -> V_395 = 0x3 ;
break;
case 4 :
V_2 -> V_395 = 0xf ;
break;
case 6 :
V_2 -> V_395 = 0x3f ;
break;
}
V_3 -> V_33 = NULL ;
V_3 -> V_252 = V_252 ;
V_3 -> V_4 = ( V_252 & V_206 ) >> V_207 ;
V_3 -> V_107 = V_392 ;
V_3 -> V_396 = V_397 ;
V_3 -> V_398 = V_399 ;
V_3 -> V_400 = false ;
V_3 -> V_393 = V_393 ;
switch ( V_3 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
if ( V_3 -> V_107 & ( V_29 ) ) {
V_3 -> V_396 = V_401 ;
F_85 ( V_20 , V_2 , & V_402 , V_403 ) ;
V_3 -> V_33 = F_86 ( V_3 ) ;
} else {
F_85 ( V_20 , V_2 , & V_402 , V_404 ) ;
V_3 -> V_33 = F_83 ( V_3 ) ;
}
F_87 ( V_2 , & V_405 ) ;
break;
case V_45 :
F_85 ( V_20 , V_2 , & V_402 , V_406 ) ;
V_3 -> V_33 = F_80 ( V_3 ) ;
F_87 ( V_2 , & V_407 ) ;
break;
case V_49 :
case V_46 :
case V_50 :
F_85 ( V_20 , V_2 , & V_402 , V_408 ) ;
V_3 -> V_33 = F_80 ( V_3 ) ;
F_87 ( V_2 , & V_407 ) ;
break;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
if ( V_3 -> V_107 & ( V_29 ) ) {
V_3 -> V_396 = V_401 ;
F_85 ( V_20 , V_2 , & V_402 , V_403 ) ;
V_3 -> V_33 = F_86 ( V_3 ) ;
} else if ( V_3 -> V_107 & ( V_53 ) ) {
F_85 ( V_20 , V_2 , & V_402 , V_406 ) ;
V_3 -> V_33 = F_83 ( V_3 ) ;
} else {
F_85 ( V_20 , V_2 , & V_402 , V_404 ) ;
V_3 -> V_33 = F_83 ( V_3 ) ;
}
F_87 ( V_2 , & V_405 ) ;
break;
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
V_3 -> V_400 = true ;
if ( V_3 -> V_107 & ( V_29 ) )
F_85 ( V_20 , V_2 , & V_402 , V_403 ) ;
else if ( V_3 -> V_107 & ( V_53 ) )
F_85 ( V_20 , V_2 , & V_402 , V_406 ) ;
else
F_85 ( V_20 , V_2 , & V_402 , V_404 ) ;
F_87 ( V_2 , & V_418 ) ;
break;
}
}
