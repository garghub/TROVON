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
static struct V_16 *
F_3 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_16 * V_19 ;
struct V_20 * V_20 ;
F_4 (connector, &dev->mode_config.connector_list, head) {
V_20 = F_5 ( V_19 ) ;
if ( V_3 -> V_21 & V_20 -> V_21 )
return V_19 ;
}
return NULL ;
}
static bool F_6 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_24 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
F_7 ( V_2 ) ;
F_8 ( V_24 , 0 ) ;
if ( ( V_23 -> V_28 & V_29 )
&& ( V_23 -> V_30 < ( V_23 -> V_31 + 2 ) ) )
V_24 -> V_30 = V_24 -> V_31 + 2 ;
if ( V_3 -> V_32 & ( V_33 ) )
F_9 ( V_2 , V_24 ) ;
if ( V_3 -> V_32 & ( V_34 ) ) {
struct V_35 * V_36 = V_3 -> V_37 ;
if ( V_36 ) {
if ( V_36 -> V_38 == V_39 ||
V_36 -> V_38 == V_40 ||
V_36 -> V_38 == V_41 )
F_10 ( V_26 , 0 , V_24 ) ;
else
F_10 ( V_26 , 1 , V_24 ) ;
}
}
if ( F_11 ( V_26 ) &&
( ( V_3 -> V_32 & ( V_42 | V_33 ) ) ||
( F_12 ( V_2 ) != V_43 ) ) ) {
struct V_16 * V_19 = F_13 ( V_2 ) ;
F_14 ( V_19 , V_23 ) ;
}
return true ;
}
static void
F_15 ( struct V_1 * V_2 , int V_44 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 args ;
int V_45 = 0 ;
struct V_35 * V_46 = V_3 -> V_37 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_47 :
case V_48 :
V_45 = F_16 ( V_49 , V_50 ) ;
break;
case V_51 :
case V_52 :
V_45 = F_16 ( V_49 , V_53 ) ;
break;
}
args . V_54 = V_44 ;
if ( V_3 -> V_32 & ( V_55 ) )
args . V_56 = V_57 ;
else if ( V_3 -> V_32 & ( V_58 ) )
args . V_56 = V_59 ;
else {
switch ( V_46 -> V_38 ) {
case V_60 :
case V_41 :
case V_61 :
case V_62 :
case V_63 :
args . V_56 = V_64 ;
break;
case V_39 :
case V_40 :
case V_65 :
default:
args . V_56 = V_66 ;
break;
}
}
args . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
static void
F_19 ( struct V_1 * V_2 , int V_44 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 args ;
int V_45 = 0 ;
struct V_35 * V_46 = V_3 -> V_37 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_45 = F_16 ( V_49 , V_72 ) ;
args . V_73 . V_54 = V_44 ;
if ( V_3 -> V_32 & ( V_58 ) )
args . V_73 . V_74 = V_75 ;
else {
switch ( V_46 -> V_38 ) {
case V_39 :
args . V_73 . V_74 = V_76 ;
break;
case V_60 :
args . V_73 . V_74 = V_77 ;
break;
case V_41 :
args . V_73 . V_74 = V_78 ;
break;
case V_65 :
args . V_73 . V_74 = V_79 ;
break;
case V_40 :
args . V_73 . V_74 = V_80 ;
break;
case V_61 :
args . V_73 . V_74 = V_77 ;
break;
case V_62 :
args . V_73 . V_74 = V_81 ;
break;
case V_63 :
args . V_73 . V_74 = V_82 ;
break;
default:
args . V_73 . V_74 = V_76 ;
break;
}
}
args . V_73 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
void
F_20 ( struct V_1 * V_2 , int V_44 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
union V_83 args ;
int V_45 = F_16 ( V_49 , V_84 ) ;
T_3 V_85 , V_86 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
return;
switch ( V_85 ) {
case 1 :
switch ( V_86 ) {
case 1 :
args . V_87 . V_88 . V_89 = V_44 ;
if ( V_3 -> V_68 > 165000 )
args . V_87 . V_88 . V_90 |= V_91 ;
args . V_87 . V_88 . V_90 |= V_92 ;
break;
case 2 :
args . V_93 . V_94 . V_54 = V_44 ;
args . V_93 . V_94 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
args . V_93 . V_94 . V_95 = V_96 ;
if ( V_3 -> V_68 > 165000 )
args . V_93 . V_94 . V_97 . V_98 . V_99 |= V_91 ;
break;
case 3 :
args . V_100 . V_54 = V_44 ;
args . V_100 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
args . V_100 . V_101 = 0 ;
break;
default:
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
break;
default:
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
void
F_23 ( struct V_1 * V_2 , int V_44 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_102 * V_103 = V_3 -> V_37 ;
union V_104 args ;
int V_45 = 0 ;
int V_105 = 0 ;
T_3 V_85 , V_86 ;
if ( ! V_103 )
return;
if ( F_24 ( V_2 ) == V_106 )
V_105 = 1 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_5 :
V_45 = F_16 ( V_49 , V_107 ) ;
break;
case V_6 :
case V_7 :
V_45 = F_16 ( V_49 , V_108 ) ;
break;
case V_8 :
if ( V_3 -> V_21 & ( V_33 ) )
V_45 = F_16 ( V_49 , V_107 ) ;
else
V_45 = F_16 ( V_49 , V_109 ) ;
break;
}
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
return;
switch ( V_85 ) {
case 1 :
case 2 :
switch ( V_86 ) {
case 1 :
args . V_110 . V_90 = 0 ;
args . V_110 . V_54 = V_44 ;
if ( V_105 )
args . V_110 . V_90 |= V_111 ;
args . V_110 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
if ( V_3 -> V_21 & ( V_33 ) ) {
if ( V_103 -> V_112 & V_113 )
args . V_110 . V_90 |= V_91 ;
if ( V_103 -> V_112 & V_92 )
args . V_110 . V_90 |= V_92 ;
} else {
if ( V_103 -> V_114 )
args . V_110 . V_90 |= V_115 ;
if ( V_3 -> V_68 > 165000 )
args . V_110 . V_90 |= V_91 ;
args . V_110 . V_90 |= V_92 ;
}
break;
case 2 :
case 3 :
args . V_116 . V_90 = 0 ;
args . V_116 . V_54 = V_44 ;
if ( V_86 == 3 ) {
if ( V_103 -> V_117 )
args . V_116 . V_90 |= V_118 ;
}
if ( V_105 )
args . V_116 . V_90 |= V_111 ;
args . V_116 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
args . V_116 . V_119 = 0 ;
args . V_116 . V_120 = 0 ;
args . V_116 . V_121 = 0 ;
args . V_116 . V_122 = 0 ;
if ( V_3 -> V_21 & ( V_33 ) ) {
if ( V_103 -> V_112 & V_113 )
args . V_116 . V_90 |= V_91 ;
if ( V_103 -> V_112 & V_123 ) {
args . V_116 . V_120 = V_124 ;
if ( V_103 -> V_112 & V_92 )
args . V_116 . V_120 |= V_125 ;
}
if ( V_103 -> V_112 & V_126 ) {
args . V_116 . V_121 = V_127 ;
if ( V_103 -> V_112 & V_92 )
args . V_116 . V_121 |= V_128 ;
if ( ( ( V_103 -> V_112 >> V_129 ) & 0x3 ) == 2 )
args . V_116 . V_121 |= V_130 ;
}
} else {
if ( V_103 -> V_114 )
args . V_116 . V_90 |= V_115 ;
if ( V_3 -> V_68 > 165000 )
args . V_116 . V_90 |= V_91 ;
}
break;
default:
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
break;
default:
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
int
F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_16 * V_19 ;
struct V_20 * V_20 ;
struct V_131 * V_132 ;
if ( F_12 ( V_2 ) != V_43 )
return V_133 ;
if ( V_3 -> V_4 == V_134 )
return V_134 ;
V_19 = F_13 ( V_2 ) ;
if ( ! V_19 )
V_19 = F_3 ( V_2 ) ;
V_20 = F_5 ( V_19 ) ;
switch ( V_19 -> V_135 ) {
case V_136 :
case V_137 :
if ( F_25 ( V_20 -> V_138 ) && V_139 ) {
if ( F_26 ( V_26 ) )
return V_140 ;
else
return V_106 ;
} else if ( V_20 -> V_141 )
return V_140 ;
else
return V_142 ;
break;
case V_143 :
case V_144 :
default:
if ( F_25 ( V_20 -> V_138 ) && V_139 ) {
if ( F_26 ( V_26 ) )
return V_140 ;
else
return V_106 ;
} else
return V_140 ;
break;
case V_145 :
return V_146 ;
break;
case V_147 :
V_132 = V_20 -> V_148 ;
if ( ( V_132 -> V_149 == V_150 ) ||
( V_132 -> V_149 == V_151 ) )
return V_133 ;
else if ( F_25 ( V_20 -> V_138 ) && V_139 ) {
if ( F_26 ( V_26 ) )
return V_140 ;
else
return V_106 ;
} else
return V_140 ;
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
F_27 ( struct V_1 * V_2 , int V_44 , int V_159 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_102 * V_103 = V_3 -> V_37 ;
struct V_16 * V_19 = F_13 ( V_2 ) ;
union V_160 args ;
int V_45 = 0 ;
T_3 V_85 , V_86 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_163 = V_164 ;
int V_165 = 8 ;
if ( V_19 ) {
struct V_20 * V_20 = F_5 ( V_19 ) ;
struct V_131 * V_132 =
V_20 -> V_148 ;
V_161 = V_132 -> V_161 ;
V_162 = V_132 -> V_162 ;
V_163 = V_20 -> V_166 . V_166 ;
V_165 = V_19 -> V_167 . V_165 ;
}
if ( V_103 -> V_168 == - 1 )
return;
memset ( & args , 0 , sizeof( args ) ) ;
if ( F_26 ( V_26 ) )
V_45 = F_16 ( V_49 , V_169 ) ;
else {
if ( V_103 -> V_168 )
V_45 = F_16 ( V_49 , V_170 ) ;
else
V_45 = F_16 ( V_49 , V_171 ) ;
}
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
return;
switch ( V_85 ) {
case 1 :
switch ( V_86 ) {
case 1 :
args . V_110 . V_54 = V_44 ;
args . V_110 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
if ( V_44 == V_172 )
args . V_173 . V_174 = V_159 ;
else
args . V_110 . V_175 = F_24 ( V_2 ) ;
if ( F_28 ( args . V_110 . V_175 ) )
args . V_110 . V_176 = V_162 ;
else if ( V_3 -> V_68 > 165000 )
args . V_110 . V_176 = 8 ;
else
args . V_110 . V_176 = 4 ;
if ( F_28 ( args . V_110 . V_175 ) && ( V_161 == 270000 ) )
args . V_110 . V_177 |= V_178 ;
switch ( V_3 -> V_4 ) {
case V_12 :
args . V_110 . V_177 = V_179 ;
break;
case V_14 :
case V_13 :
args . V_110 . V_177 = V_180 ;
break;
case V_15 :
args . V_110 . V_177 = V_181 ;
break;
}
if ( V_103 -> V_114 )
args . V_110 . V_177 |= V_182 ;
else
args . V_110 . V_177 |= V_183 ;
break;
case 2 :
case 3 :
args . V_173 . V_54 = V_44 ;
args . V_173 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
if ( V_44 == V_172 )
args . V_173 . V_174 = V_159 ;
else
args . V_173 . V_175 = F_24 ( V_2 ) ;
if ( F_28 ( args . V_110 . V_175 ) )
args . V_173 . V_176 = V_162 ;
else if ( V_3 -> V_68 > 165000 )
args . V_173 . V_176 = 8 ;
else
args . V_173 . V_176 = 4 ;
if ( F_28 ( args . V_110 . V_175 ) && ( V_161 == 270000 ) )
args . V_110 . V_177 |= V_184 ;
args . V_173 . V_185 . V_186 = V_103 -> V_168 ;
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
args . V_194 . V_54 = V_44 ;
args . V_194 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
if ( V_44 == V_172 )
args . V_194 . V_174 = V_159 ;
else
args . V_194 . V_175 = F_24 ( V_2 ) ;
if ( F_28 ( args . V_110 . V_175 ) )
args . V_194 . V_176 = V_162 ;
else if ( V_3 -> V_68 > 165000 )
args . V_194 . V_176 = 8 ;
else
args . V_194 . V_176 = 4 ;
if ( F_28 ( args . V_110 . V_175 ) ) {
if ( V_161 == 270000 )
args . V_110 . V_177 |= V_195 ;
else if ( V_161 == 540000 )
args . V_110 . V_177 |= V_196 ;
}
args . V_194 . V_185 . V_186 = V_103 -> V_168 ;
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
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
break;
default:
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
void
F_29 ( struct V_1 * V_2 , int V_44 , T_3 V_198 , T_3 V_199 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_102 * V_103 = V_3 -> V_37 ;
struct V_16 * V_19 ;
union V_200 args ;
int V_45 = 0 ;
T_3 V_85 , V_86 ;
bool V_201 = false ;
int V_202 = 0 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_203 = 0 ;
int V_204 = 0 ;
int V_168 = V_103 -> V_168 ;
if ( V_44 == V_205 ) {
V_19 = F_3 ( V_2 ) ;
V_168 = 0 ;
} else
V_19 = F_13 ( V_2 ) ;
if ( V_19 ) {
struct V_20 * V_20 = F_5 ( V_19 ) ;
struct V_131 * V_132 =
V_20 -> V_148 ;
V_161 = V_132 -> V_161 ;
V_162 = V_132 -> V_162 ;
V_203 =
( V_20 -> V_203 & V_206 ) >> V_207 ;
V_204 = V_132 -> V_204 ;
}
if ( V_2 -> V_208 ) {
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
V_202 = V_209 -> V_202 ;
}
if ( V_168 == - 1 )
return;
if ( F_28 ( F_24 ( V_2 ) ) )
V_201 = true ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_10 :
V_45 = F_16 ( V_49 , V_210 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
V_45 = F_16 ( V_49 , V_211 ) ;
break;
case V_13 :
V_45 = F_16 ( V_49 , V_212 ) ;
break;
}
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
return;
switch ( V_85 ) {
case 1 :
switch ( V_86 ) {
case 1 :
args . V_110 . V_54 = V_44 ;
if ( V_44 == V_205 ) {
args . V_110 . V_213 = F_17 ( V_203 ) ;
} else if ( V_44 == V_214 ) {
args . V_110 . V_215 . V_216 = V_198 ;
args . V_110 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_110 . V_67 =
F_17 ( V_161 / 10 ) ;
else if ( V_3 -> V_68 > 165000 )
args . V_110 . V_67 = F_17 ( ( V_3 -> V_68 / 2 ) / 10 ) ;
else
args . V_110 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
}
args . V_110 . V_177 = V_218 ;
if ( V_168 )
args . V_110 . V_177 |= V_219 ;
else
args . V_110 . V_177 |= V_220 ;
if ( ( V_26 -> V_28 & V_221 ) &&
( V_3 -> V_4 == V_12 ) ) {
if ( V_201 || ( V_3 -> V_68 <= 165000 ) ) {
if ( V_204 & 0x1 )
args . V_110 . V_177 |= V_222 ;
else if ( V_204 & 0x2 )
args . V_110 . V_177 |= V_223 ;
else if ( V_204 & 0x4 )
args . V_110 . V_177 |= V_224 ;
else if ( V_204 & 0x8 )
args . V_110 . V_177 |= V_225 ;
} else {
if ( V_204 & 0x3 )
args . V_110 . V_177 |= V_226 ;
else if ( V_204 & 0xc )
args . V_110 . V_177 |= V_227 ;
}
}
if ( V_103 -> V_114 )
args . V_110 . V_177 |= V_228 ;
else
args . V_110 . V_177 |= V_229 ;
if ( V_201 )
args . V_110 . V_177 |= V_230 ;
else if ( V_3 -> V_21 & ( V_42 ) ) {
if ( V_103 -> V_117 )
args . V_110 . V_177 |= V_230 ;
if ( V_3 -> V_68 > 165000 )
args . V_110 . V_177 |= V_231 ;
}
break;
case 2 :
args . V_116 . V_54 = V_44 ;
if ( V_44 == V_205 ) {
args . V_116 . V_213 = F_17 ( V_203 ) ;
} else if ( V_44 == V_214 ) {
args . V_116 . V_215 . V_216 = V_198 ;
args . V_116 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_116 . V_67 =
F_17 ( V_161 / 10 ) ;
else if ( V_3 -> V_68 > 165000 )
args . V_116 . V_67 = F_17 ( ( V_3 -> V_68 / 2 ) / 10 ) ;
else
args . V_116 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
}
args . V_116 . V_185 . V_232 = V_168 ;
if ( V_103 -> V_114 )
args . V_116 . V_185 . V_233 = 1 ;
switch ( V_3 -> V_4 ) {
case V_12 :
args . V_116 . V_185 . V_234 = 0 ;
break;
case V_14 :
args . V_116 . V_185 . V_234 = 1 ;
break;
case V_15 :
args . V_116 . V_185 . V_234 = 2 ;
break;
}
if ( V_201 ) {
args . V_116 . V_185 . V_235 = 1 ;
args . V_116 . V_185 . V_236 = 1 ;
} else if ( V_3 -> V_21 & ( V_42 ) ) {
if ( V_103 -> V_117 )
args . V_116 . V_185 . V_235 = 1 ;
if ( V_3 -> V_68 > 165000 )
args . V_116 . V_185 . V_237 = 1 ;
}
break;
case 3 :
args . V_173 . V_54 = V_44 ;
if ( V_44 == V_205 ) {
args . V_173 . V_213 = F_17 ( V_203 ) ;
} else if ( V_44 == V_214 ) {
args . V_173 . V_215 . V_216 = V_198 ;
args . V_173 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_173 . V_67 =
F_17 ( V_161 / 10 ) ;
else if ( V_3 -> V_68 > 165000 )
args . V_173 . V_67 = F_17 ( ( V_3 -> V_68 / 2 ) / 10 ) ;
else
args . V_173 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
}
if ( V_201 )
args . V_173 . V_176 = V_162 ;
else if ( V_3 -> V_68 > 165000 )
args . V_173 . V_176 = 8 ;
else
args . V_173 . V_176 = 4 ;
if ( V_103 -> V_114 )
args . V_173 . V_185 . V_233 = 1 ;
if ( V_168 & 1 )
args . V_173 . V_185 . V_232 = 1 ;
if ( V_201 && V_26 -> clock . V_238 )
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
else if ( V_3 -> V_21 & ( V_42 ) ) {
if ( V_103 -> V_117 )
args . V_173 . V_185 . V_235 = 1 ;
if ( V_3 -> V_68 > 165000 )
args . V_173 . V_185 . V_237 = 1 ;
}
break;
case 4 :
args . V_194 . V_54 = V_44 ;
if ( V_44 == V_205 ) {
args . V_194 . V_213 = F_17 ( V_203 ) ;
} else if ( V_44 == V_214 ) {
args . V_194 . V_215 . V_216 = V_198 ;
args . V_194 . V_215 . V_217 = V_199 ;
} else {
if ( V_201 )
args . V_194 . V_67 =
F_17 ( V_161 / 10 ) ;
else if ( V_3 -> V_68 > 165000 )
args . V_194 . V_67 = F_17 ( ( V_3 -> V_68 / 2 ) / 10 ) ;
else
args . V_194 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
}
if ( V_201 )
args . V_194 . V_176 = V_162 ;
else if ( V_3 -> V_68 > 165000 )
args . V_194 . V_176 = 8 ;
else
args . V_194 . V_176 = 4 ;
if ( V_103 -> V_114 )
args . V_194 . V_185 . V_233 = 1 ;
if ( V_168 & 1 )
args . V_194 . V_185 . V_232 = 1 ;
if ( V_201 ) {
if ( V_26 -> clock . V_238 )
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
else if ( V_3 -> V_21 & ( V_42 ) ) {
if ( V_103 -> V_117 )
args . V_194 . V_185 . V_235 = 1 ;
if ( V_3 -> V_68 > 165000 )
args . V_194 . V_185 . V_237 = 1 ;
}
break;
default:
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
break;
default:
F_22 ( L_1 , V_85 , V_86 ) ;
break;
}
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
bool
F_31 ( struct V_16 * V_19 , int V_44 )
{
struct V_20 * V_20 = F_5 ( V_19 ) ;
struct V_17 * V_18 = V_20 -> V_242 . V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
union V_200 args ;
int V_45 = F_16 ( V_49 , V_211 ) ;
T_3 V_85 , V_86 ;
if ( V_19 -> V_135 != V_152 )
goto V_243;
if ( ! F_26 ( V_26 ) )
goto V_243;
if ( ( V_44 != V_244 ) &&
( V_44 != V_245 ) )
goto V_243;
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
goto V_243;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_110 . V_54 = V_44 ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
if ( V_44 == V_244 ) {
int V_246 ;
for ( V_246 = 0 ; V_246 < 300 ; V_246 ++ ) {
if ( F_32 ( V_26 , V_20 -> V_166 . V_166 ) )
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
int V_44 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_3 * V_248 = F_2 ( V_247 ) ;
union V_249 args ;
struct V_16 * V_19 ;
int V_45 = F_16 ( V_49 , V_250 ) ;
T_4 V_85 , V_86 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_203 = 0 ;
T_5 V_251 = ( V_248 -> V_252 & V_253 ) >> V_254 ;
int V_165 = 8 ;
if ( V_44 == V_255 )
V_19 = F_3 ( V_2 ) ;
else
V_19 = F_13 ( V_2 ) ;
if ( V_19 ) {
struct V_20 * V_20 = F_5 ( V_19 ) ;
struct V_131 * V_132 =
V_20 -> V_148 ;
V_161 = V_132 -> V_161 ;
V_162 = V_132 -> V_162 ;
V_203 =
( V_20 -> V_203 & V_206 ) >> V_207 ;
V_165 = V_19 -> V_167 . V_165 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
return;
switch ( V_85 ) {
case 1 :
break;
case 2 :
switch ( V_86 ) {
case 1 :
case 2 :
args . V_110 . V_256 . V_54 = V_44 ;
args . V_110 . V_256 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
args . V_110 . V_256 . V_175 = F_24 ( V_2 ) ;
if ( F_28 ( args . V_110 . V_256 . V_175 ) ) {
if ( V_161 == 270000 )
args . V_110 . V_256 . V_177 |= V_178 ;
args . V_110 . V_256 . V_176 = V_162 ;
} else if ( V_3 -> V_68 > 165000 )
args . V_110 . V_256 . V_176 = 8 ;
else
args . V_110 . V_256 . V_176 = 4 ;
break;
case 3 :
args . V_173 . V_257 . V_54 = V_44 ;
if ( V_44 == V_255 )
args . V_173 . V_257 . V_258 = F_17 ( V_203 ) ;
else
args . V_173 . V_257 . V_67 = F_17 ( V_3 -> V_68 / 10 ) ;
args . V_173 . V_257 . V_175 = F_24 ( V_2 ) ;
if ( F_28 ( args . V_173 . V_257 . V_175 ) ) {
if ( V_161 == 270000 )
args . V_173 . V_257 . V_177 |= V_259 ;
else if ( V_161 == 540000 )
args . V_173 . V_257 . V_177 |= V_260 ;
args . V_173 . V_257 . V_176 = V_162 ;
} else if ( V_3 -> V_68 > 165000 )
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
F_22 ( L_2 , V_85 , V_86 ) ;
return;
}
break;
default:
F_22 ( L_2 , V_85 , V_86 ) ;
return;
}
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
static void
F_35 ( struct V_1 * V_2 , bool V_267 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
T_6 args ;
int V_45 = F_16 ( V_49 , V_268 ) ;
V_71 V_269 , V_270 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( V_26 -> V_271 >= V_272 )
V_270 = V_273 ;
else
V_270 = V_274 ;
V_269 = F_36 ( V_270 ) ;
if ( V_3 -> V_32 & ( V_34 ) )
F_37 ( V_270 , ( V_275 |
( V_209 -> V_276 << 18 ) ) ) ;
else if ( V_3 -> V_32 & ( V_58 ) )
F_37 ( V_270 , ( V_277 | ( V_209 -> V_276 << 24 ) ) ) ;
else
F_37 ( V_270 , 0 ) ;
if ( V_267 )
args . V_89 = V_278 ;
args . V_279 = V_209 -> V_276 ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
F_37 ( V_270 , V_269 ) ;
}
static void
F_38 ( struct V_1 * V_2 , int V_23 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_7 args ;
int V_45 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
V_45 = F_16 ( V_49 , V_280 ) ;
break;
case V_9 :
case V_11 :
case V_10 :
V_45 = F_16 ( V_49 , V_210 ) ;
break;
case V_5 :
V_45 = F_16 ( V_49 , V_281 ) ;
break;
case V_8 :
if ( V_3 -> V_21 & ( V_33 ) )
V_45 = F_16 ( V_49 , V_281 ) ;
else
V_45 = F_16 ( V_49 , V_282 ) ;
break;
case V_47 :
case V_48 :
if ( V_3 -> V_32 & ( V_34 ) )
V_45 = F_16 ( V_49 , V_283 ) ;
else if ( V_3 -> V_32 & ( V_58 ) )
V_45 = F_16 ( V_49 , V_284 ) ;
else
V_45 = F_16 ( V_49 , V_285 ) ;
break;
case V_51 :
case V_52 :
if ( V_3 -> V_32 & ( V_34 ) )
V_45 = F_16 ( V_49 , V_283 ) ;
else if ( V_3 -> V_32 & ( V_58 ) )
V_45 = F_16 ( V_49 , V_284 ) ;
else
V_45 = F_16 ( V_49 , V_286 ) ;
break;
default:
return;
}
switch ( V_23 ) {
case V_287 :
args . V_54 = V_278 ;
if ( V_3 -> V_4 == V_11 ) {
T_5 V_270 = F_36 ( V_274 ) ;
F_37 ( V_274 , V_270 & ~ V_288 ) ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
F_37 ( V_274 , V_270 ) ;
} else
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
if ( V_3 -> V_21 & ( V_33 ) ) {
args . V_54 = V_289 ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
break;
case V_290 :
case V_291 :
case V_292 :
args . V_54 = V_293 ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
if ( V_3 -> V_21 & ( V_33 ) ) {
args . V_54 = V_294 ;
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
}
break;
}
}
static void
F_39 ( struct V_1 * V_2 , int V_23 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_16 * V_19 = F_13 ( V_2 ) ;
struct V_20 * V_20 = NULL ;
struct V_131 * V_295 = NULL ;
if ( V_19 ) {
V_20 = F_5 ( V_19 ) ;
V_295 = V_20 -> V_148 ;
}
switch ( V_23 ) {
case V_287 :
if ( ( V_26 -> V_271 == V_296 ) || ( V_26 -> V_271 == V_297 ) )
F_29 ( V_2 , V_298 , 0 , 0 ) ;
else
F_29 ( V_2 , V_299 , 0 , 0 ) ;
if ( F_28 ( F_24 ( V_2 ) ) && V_19 ) {
if ( V_19 -> V_135 == V_152 ) {
F_31 ( V_19 ,
V_244 ) ;
V_295 -> V_300 = true ;
}
if ( F_26 ( V_26 ) )
F_27 ( V_2 , V_301 , 0 ) ;
F_40 ( V_2 , V_19 ) ;
if ( F_26 ( V_26 ) )
F_27 ( V_2 , V_302 , 0 ) ;
}
if ( V_3 -> V_21 & ( V_33 ) )
F_29 ( V_2 , V_303 , 0 , 0 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
F_29 ( V_2 , V_304 , 0 , 0 ) ;
if ( F_28 ( F_24 ( V_2 ) ) && V_19 ) {
if ( F_26 ( V_26 ) )
F_27 ( V_2 , V_301 , 0 ) ;
if ( V_19 -> V_135 == V_152 ) {
F_31 ( V_19 ,
V_245 ) ;
V_295 -> V_300 = false ;
}
}
if ( V_3 -> V_21 & ( V_33 ) )
F_29 ( V_2 , V_305 , 0 , 0 ) ;
break;
}
}
static void
F_41 ( struct V_1 * V_2 ,
struct V_1 * V_247 ,
int V_23 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
switch ( V_23 ) {
case V_287 :
default:
if ( F_42 ( V_26 ) ) {
F_34 ( V_2 , V_247 ,
V_306 ) ;
F_34 ( V_2 , V_247 ,
V_307 ) ;
} else
F_34 ( V_2 , V_247 , V_278 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
if ( F_42 ( V_26 ) ) {
F_34 ( V_2 , V_247 ,
V_308 ) ;
F_34 ( V_2 , V_247 ,
V_309 ) ;
} else
F_34 ( V_2 , V_247 , V_293 ) ;
break;
}
}
static void
F_43 ( struct V_1 * V_2 , int V_23 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_247 = F_44 ( V_2 ) ;
F_45 ( L_3 ,
V_3 -> V_4 , V_23 , V_3 -> V_21 ,
V_3 -> V_32 ) ;
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
case V_5 :
case V_8 :
case V_9 :
case V_11 :
case V_51 :
case V_52 :
F_38 ( V_2 , V_23 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_13 :
F_39 ( V_2 , V_23 ) ;
break;
case V_10 :
if ( F_46 ( V_26 ) ) {
switch ( V_23 ) {
case V_287 :
F_20 ( V_2 , V_278 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
F_20 ( V_2 , V_293 ) ;
break;
}
} else if ( F_11 ( V_26 ) )
F_39 ( V_2 , V_23 ) ;
else
F_38 ( V_2 , V_23 ) ;
break;
case V_47 :
case V_48 :
if ( F_46 ( V_26 ) ) {
switch ( V_23 ) {
case V_287 :
F_15 ( V_2 , V_278 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
F_15 ( V_2 , V_293 ) ;
break;
}
} else
F_38 ( V_2 , V_23 ) ;
break;
default:
return;
}
if ( V_247 )
F_41 ( V_2 , V_247 , V_23 ) ;
F_47 ( V_2 , ( V_23 == V_287 ) ? true : false ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
union V_310 args ;
int V_45 = F_16 ( V_49 , V_311 ) ;
T_3 V_85 , V_86 ;
struct V_102 * V_103 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
return;
switch ( V_85 ) {
case 1 :
switch ( V_86 ) {
case 1 :
default:
if ( F_49 ( V_26 ) )
args . V_110 . V_279 = V_209 -> V_276 ;
else {
if ( V_3 -> V_4 == V_47 ) {
args . V_110 . V_279 = V_209 -> V_276 ;
} else {
args . V_110 . V_279 = V_209 -> V_276 << 2 ;
}
}
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
args . V_110 . V_312 = V_96 ;
break;
case V_5 :
case V_8 :
if ( V_3 -> V_21 & V_313 )
args . V_110 . V_312 = V_314 ;
else
args . V_110 . V_312 = V_315 ;
break;
case V_9 :
case V_11 :
case V_10 :
args . V_110 . V_312 = V_316 ;
break;
case V_47 :
case V_48 :
if ( V_3 -> V_32 & ( V_34 ) )
args . V_110 . V_312 = V_317 ;
else if ( V_3 -> V_32 & ( V_58 ) )
args . V_110 . V_312 = V_318 ;
else
args . V_110 . V_312 = V_319 ;
break;
case V_51 :
case V_52 :
if ( V_3 -> V_32 & ( V_34 ) )
args . V_110 . V_312 = V_317 ;
else if ( V_3 -> V_32 & ( V_58 ) )
args . V_110 . V_312 = V_318 ;
else
args . V_110 . V_312 = V_320 ;
break;
}
break;
case 2 :
args . V_116 . V_279 = V_209 -> V_276 ;
if ( F_12 ( V_2 ) != V_43 ) {
struct V_16 * V_19 = F_13 ( V_2 ) ;
if ( V_19 -> V_135 == V_145 )
args . V_116 . V_321 = V_146 ;
else if ( V_19 -> V_135 == V_154 )
args . V_116 . V_321 = V_142 ;
else
args . V_116 . V_321 = F_24 ( V_2 ) ;
} else
args . V_116 . V_321 = F_24 ( V_2 ) ;
switch ( V_3 -> V_4 ) {
case V_12 :
case V_14 :
case V_15 :
case V_13 :
V_103 = V_3 -> V_37 ;
switch ( V_103 -> V_168 ) {
case 0 :
args . V_116 . V_322 = V_323 ;
break;
case 1 :
args . V_116 . V_322 = V_324 ;
break;
case 2 :
args . V_116 . V_322 = V_325 ;
break;
case 3 :
args . V_116 . V_322 = V_326 ;
break;
case 4 :
args . V_116 . V_322 = V_327 ;
break;
case 5 :
args . V_116 . V_322 = V_328 ;
break;
}
break;
case V_10 :
args . V_116 . V_322 = V_329 ;
break;
case V_48 :
if ( V_3 -> V_32 & ( V_34 ) )
args . V_116 . V_322 = V_330 ;
else if ( V_3 -> V_32 & ( V_58 ) )
args . V_116 . V_322 = V_330 ;
else
args . V_116 . V_322 = V_331 ;
break;
case V_52 :
if ( V_3 -> V_32 & ( V_34 ) )
args . V_116 . V_322 = V_330 ;
else if ( V_3 -> V_32 & ( V_58 ) )
args . V_116 . V_322 = V_330 ;
else
args . V_116 . V_322 = V_332 ;
break;
}
break;
}
break;
default:
F_22 ( L_2 , V_85 , V_86 ) ;
return;
}
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
F_50 ( V_2 , V_209 -> V_276 ) ;
}
static void
F_51 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
if ( ( V_18 -> V_333 -> V_334 == 0x71C5 ) &&
( V_18 -> V_333 -> V_335 == 0x106b ) &&
( V_18 -> V_333 -> V_336 == 0x0080 ) ) {
if ( V_3 -> V_21 & V_313 ) {
V_71 V_337 = F_36 ( V_338 ) ;
V_337 &= ~ V_339 ;
V_337 &= ~ V_340 ;
F_37 ( V_338 , V_337 ) ;
}
}
if ( F_49 ( V_26 ) &&
( ! ( V_3 -> V_32 & ( V_34 ) ) ) ) {
if ( F_26 ( V_26 ) ) {
if ( V_23 -> V_28 & V_29 )
F_37 ( V_341 + V_209 -> V_342 ,
V_343 ) ;
else
F_37 ( V_341 + V_209 -> V_342 , 0 ) ;
} else {
if ( V_23 -> V_28 & V_29 )
F_37 ( V_344 + V_209 -> V_342 ,
V_345 ) ;
else
F_37 ( V_344 + V_209 -> V_342 , 0 ) ;
}
}
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_209 * V_209 = F_30 ( V_2 -> V_208 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_346 ;
struct V_102 * V_103 ;
V_71 V_347 = 0 ;
if ( F_26 ( V_26 ) ) {
V_103 = V_3 -> V_37 ;
if ( F_42 ( V_26 ) ) {
if ( V_26 -> V_271 == V_348 ) {
if ( V_103 -> V_114 )
return 1 ;
else
return 0 ;
} else
return V_209 -> V_276 ;
} else {
switch ( V_3 -> V_4 ) {
case V_12 :
if ( V_103 -> V_114 )
return 1 ;
else
return 0 ;
break;
case V_14 :
if ( V_103 -> V_114 )
return 3 ;
else
return 2 ;
break;
case V_15 :
if ( V_103 -> V_114 )
return 5 ;
else
return 4 ;
break;
}
}
}
if ( F_53 ( V_26 ) ) {
return V_209 -> V_276 ;
}
F_4 (test_encoder, &dev->mode_config.encoder_list, head) {
struct V_3 * V_349 ;
if ( V_2 == V_346 )
continue;
if ( ! F_1 ( V_346 ) )
continue;
V_349 = F_2 ( V_346 ) ;
V_103 = V_349 -> V_37 ;
if ( V_103 -> V_168 >= 0 )
V_347 |= ( 1 << V_103 -> V_168 ) ;
}
if ( V_3 -> V_4 == V_13 ) {
if ( V_347 & 0x2 )
F_22 ( L_4 ) ;
return 1 ;
}
if ( ! ( V_347 & 1 ) )
return 0 ;
return 1 ;
}
void
F_54 ( struct V_25 * V_26 )
{
struct V_17 * V_18 = V_26 -> V_350 ;
struct V_1 * V_2 ;
F_4 (encoder, &dev->mode_config.encoder_list, head) {
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_247 = F_44 ( V_2 ) ;
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
if ( V_247 && F_42 ( V_26 ) )
F_34 ( V_2 , V_247 ,
V_255 ) ;
}
}
static void
F_55 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_24 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_247 = F_44 ( V_2 ) ;
V_3 -> V_68 = V_24 -> clock ;
if ( F_49 ( V_26 ) && ! F_26 ( V_26 ) ) {
if ( V_3 -> V_32 & ( V_58 | V_34 ) )
F_35 ( V_2 , true ) ;
else
F_35 ( V_2 , false ) ;
}
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
case V_5 :
case V_8 :
F_23 ( V_2 , V_351 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_13 :
if ( F_26 ( V_26 ) ) {
F_29 ( V_2 , V_352 , 0 , 0 ) ;
F_27 ( V_2 , V_353 , 0 ) ;
F_29 ( V_2 , V_298 , 0 , 0 ) ;
} else {
F_29 ( V_2 , V_352 , 0 , 0 ) ;
F_27 ( V_2 , V_293 , 0 ) ;
F_27 ( V_2 , V_278 , 0 ) ;
F_29 ( V_2 , V_354 , 0 , 0 ) ;
F_29 ( V_2 , V_298 , 0 , 0 ) ;
}
break;
case V_11 :
case V_9 :
case V_10 :
F_20 ( V_2 , V_278 ) ;
break;
case V_47 :
case V_48 :
case V_51 :
case V_52 :
F_15 ( V_2 , V_278 ) ;
if ( V_3 -> V_21 & ( V_34 | V_58 ) ) {
if ( V_3 -> V_32 & ( V_34 | V_58 ) )
F_19 ( V_2 , V_278 ) ;
else
F_19 ( V_2 , V_293 ) ;
}
break;
}
if ( V_247 ) {
if ( F_42 ( V_26 ) )
F_34 ( V_2 , V_247 ,
V_355 ) ;
else
F_34 ( V_2 , V_247 , V_278 ) ;
}
F_51 ( V_2 , V_24 ) ;
if ( F_24 ( V_2 ) == V_106 ) {
F_56 ( V_2 ) ;
F_57 ( V_2 , V_24 ) ;
}
}
static bool
F_58 ( struct V_1 * V_2 , struct V_16 * V_19 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_20 * V_20 = F_5 ( V_19 ) ;
if ( V_3 -> V_21 & ( V_34 |
V_58 |
V_55 ) ) {
T_8 args ;
int V_45 = F_16 ( V_49 , V_356 ) ;
T_3 V_85 , V_86 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_21 ( V_26 -> V_69 . V_70 , V_45 , & V_85 , & V_86 ) )
return false ;
args . V_357 . V_90 = 0 ;
if ( ( V_3 -> V_4 == V_47 ) ||
( V_3 -> V_4 == V_48 ) )
args . V_357 . V_358 = V_359 ;
else
args . V_357 . V_358 = V_360 ;
if ( V_20 -> V_21 & V_361 )
args . V_357 . V_362 = F_17 ( V_361 ) ;
else if ( V_20 -> V_21 & V_363 )
args . V_357 . V_362 = F_17 ( V_363 ) ;
else if ( V_20 -> V_21 & V_58 ) {
args . V_357 . V_362 = F_17 ( V_58 ) ;
if ( V_86 >= 3 )
args . V_357 . V_90 = V_364 ;
} else if ( V_20 -> V_21 & V_365 ) {
args . V_357 . V_362 = F_17 ( V_365 ) ;
if ( V_86 >= 3 )
args . V_357 . V_90 = V_364 ;
}
F_18 ( V_26 -> V_69 . V_70 , V_45 , ( V_71 * ) & args ) ;
return true ;
} else
return false ;
}
static enum V_366
F_59 ( struct V_1 * V_2 , struct V_16 * V_19 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_20 * V_20 = F_5 ( V_19 ) ;
V_71 V_367 ;
if ( ! F_58 ( V_2 , V_19 ) ) {
F_45 ( L_5 ) ;
return V_368 ;
}
if ( V_26 -> V_271 >= V_272 )
V_367 = F_36 ( V_369 ) ;
else
V_367 = F_36 ( V_370 ) ;
F_45 ( L_6 , V_367 , V_3 -> V_21 ) ;
if ( V_20 -> V_21 & V_361 ) {
if ( V_367 & V_371 )
return V_372 ;
}
if ( V_20 -> V_21 & V_363 ) {
if ( V_367 & V_373 )
return V_372 ;
}
if ( V_20 -> V_21 & V_58 ) {
if ( V_367 & ( V_374 | V_375 ) )
return V_372 ;
}
if ( V_20 -> V_21 & V_365 ) {
if ( V_367 & ( V_376 | V_377 ) )
return V_372 ;
else if ( V_367 & ( V_378 | V_379 ) )
return V_372 ;
}
return V_380 ;
}
static enum V_366
F_60 ( struct V_1 * V_2 , struct V_16 * V_19 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_20 * V_20 = F_5 ( V_19 ) ;
struct V_1 * V_247 = F_44 ( V_2 ) ;
T_5 V_367 ;
if ( ! F_26 ( V_26 ) )
return V_368 ;
if ( ! V_247 )
return V_368 ;
if ( ( V_20 -> V_21 & V_55 ) == 0 )
return V_368 ;
F_34 ( V_2 , V_247 ,
V_381 ) ;
V_367 = F_36 ( V_369 ) ;
F_45 ( L_6 , V_367 , V_3 -> V_21 ) ;
if ( V_20 -> V_21 & V_361 ) {
if ( V_367 & V_371 )
return V_372 ;
}
if ( V_20 -> V_21 & V_363 ) {
if ( V_367 & V_373 )
return V_372 ;
}
if ( V_20 -> V_21 & V_58 ) {
if ( V_367 & ( V_374 | V_375 ) )
return V_372 ;
}
if ( V_20 -> V_21 & V_365 ) {
if ( V_367 & ( V_376 | V_377 ) )
return V_372 ;
else if ( V_367 & ( V_378 | V_379 ) )
return V_372 ;
}
return V_380 ;
}
void
F_61 ( struct V_1 * V_2 )
{
struct V_1 * V_247 = F_44 ( V_2 ) ;
if ( V_247 )
F_34 ( V_2 , V_247 ,
V_382 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_16 * V_19 = F_13 ( V_2 ) ;
if ( ( V_3 -> V_32 &
( V_42 | V_33 ) ) ||
( F_12 ( V_2 ) !=
V_43 ) ) {
struct V_102 * V_103 = V_3 -> V_37 ;
if ( V_103 )
V_103 -> V_168 = F_52 ( V_2 ) ;
}
F_63 ( V_2 , true ) ;
F_43 ( V_2 , V_292 ) ;
if ( V_19 ) {
struct V_20 * V_20 = F_5 ( V_19 ) ;
if ( V_20 -> V_383 . V_384 )
F_64 ( V_20 ) ;
if ( V_19 -> V_135 == V_152 )
F_31 ( V_19 ,
V_244 ) ;
}
F_48 ( V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_43 ( V_2 , V_287 ) ;
F_63 ( V_2 , false ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_102 * V_103 ;
if ( ! F_11 ( V_26 ) ) {
struct V_1 * V_385 ;
struct V_3 * V_386 ;
F_4 (other_encoder, &dev->mode_config.encoder_list, head) {
V_386 = F_2 ( V_385 ) ;
if ( ( V_3 -> V_4 == V_386 -> V_4 ) &&
F_67 ( V_385 ) )
goto V_387;
}
}
F_43 ( V_2 , V_292 ) ;
switch ( V_3 -> V_4 ) {
case V_6 :
case V_7 :
case V_5 :
case V_8 :
F_23 ( V_2 , V_388 ) ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_13 :
if ( F_26 ( V_26 ) )
F_29 ( V_2 , V_352 , 0 , 0 ) ;
else {
F_29 ( V_2 , V_352 , 0 , 0 ) ;
F_27 ( V_2 , V_293 , 0 ) ;
}
break;
case V_11 :
case V_9 :
case V_10 :
F_20 ( V_2 , V_293 ) ;
break;
case V_47 :
case V_48 :
case V_51 :
case V_52 :
F_15 ( V_2 , V_293 ) ;
if ( V_3 -> V_21 & ( V_34 | V_58 ) )
F_19 ( V_2 , V_293 ) ;
break;
}
V_387:
if ( F_1 ( V_2 ) ) {
if ( F_24 ( V_2 ) == V_106 )
F_68 ( V_2 ) ;
V_103 = V_3 -> V_37 ;
V_103 -> V_168 = - 1 ;
}
V_3 -> V_32 = 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
}
static void F_70 ( struct V_1 * V_2 )
{
}
static void
F_71 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_24 )
{
}
static void F_72 ( struct V_1 * V_2 )
{
}
static void
F_73 ( struct V_1 * V_2 , int V_23 )
{
}
static bool F_74 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_22 * V_24 )
{
return true ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_76 ( V_3 -> V_37 ) ;
F_77 ( V_2 ) ;
F_76 ( V_3 ) ;
}
struct V_35 *
F_78 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_242 . V_18 ;
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_35 * V_389 = F_79 ( sizeof( struct V_35 ) , V_390 ) ;
if ( ! V_389 )
return NULL ;
V_389 -> V_38 = F_80 ( V_26 ) ;
return V_389 ;
}
struct V_102 *
F_81 ( struct V_3 * V_3 )
{
int V_252 = ( V_3 -> V_252 & V_253 ) >> V_254 ;
struct V_102 * V_103 = F_79 ( sizeof( struct V_102 ) , V_390 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_117 = true ;
V_103 -> V_168 = - 1 ;
if ( V_252 == 2 )
V_103 -> V_114 = true ;
else
V_103 -> V_114 = false ;
return V_103 ;
}
void
F_82 ( struct V_17 * V_18 ,
V_71 V_252 ,
V_71 V_391 ,
T_9 V_392 )
{
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
F_4 (encoder, &dev->mode_config.encoder_list, head) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_252 == V_252 ) {
V_3 -> V_21 |= V_391 ;
return;
}
}
V_3 = F_79 ( sizeof( struct V_3 ) , V_390 ) ;
if ( ! V_3 )
return;
V_2 = & V_3 -> V_242 ;
switch ( V_26 -> V_393 ) {
case 1 :
V_2 -> V_394 = 0x1 ;
break;
case 2 :
default:
V_2 -> V_394 = 0x3 ;
break;
case 4 :
V_2 -> V_394 = 0xf ;
break;
case 6 :
V_2 -> V_394 = 0x3f ;
break;
}
V_3 -> V_37 = NULL ;
V_3 -> V_252 = V_252 ;
V_3 -> V_4 = ( V_252 & V_206 ) >> V_207 ;
V_3 -> V_21 = V_391 ;
V_3 -> V_395 = V_396 ;
V_3 -> V_397 = V_398 ;
V_3 -> V_399 = false ;
V_3 -> V_392 = V_392 ;
switch ( V_3 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
if ( V_3 -> V_21 & ( V_33 ) ) {
V_3 -> V_395 = V_400 ;
F_83 ( V_18 , V_2 , & V_401 , V_402 ) ;
V_3 -> V_37 = F_84 ( V_3 ) ;
} else {
F_83 ( V_18 , V_2 , & V_401 , V_403 ) ;
V_3 -> V_37 = F_81 ( V_3 ) ;
}
F_85 ( V_2 , & V_404 ) ;
break;
case V_47 :
F_83 ( V_18 , V_2 , & V_401 , V_405 ) ;
V_3 -> V_37 = F_78 ( V_3 ) ;
F_85 ( V_2 , & V_406 ) ;
break;
case V_51 :
case V_48 :
case V_52 :
F_83 ( V_18 , V_2 , & V_401 , V_407 ) ;
V_3 -> V_37 = F_78 ( V_3 ) ;
F_85 ( V_2 , & V_406 ) ;
break;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
if ( V_3 -> V_21 & ( V_33 ) ) {
V_3 -> V_395 = V_400 ;
F_83 ( V_18 , V_2 , & V_401 , V_402 ) ;
V_3 -> V_37 = F_84 ( V_3 ) ;
} else if ( V_3 -> V_21 & ( V_55 ) ) {
F_83 ( V_18 , V_2 , & V_401 , V_405 ) ;
V_3 -> V_37 = F_81 ( V_3 ) ;
} else {
F_83 ( V_18 , V_2 , & V_401 , V_403 ) ;
V_3 -> V_37 = F_81 ( V_3 ) ;
}
F_85 ( V_2 , & V_404 ) ;
break;
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
V_3 -> V_399 = true ;
if ( V_3 -> V_21 & ( V_33 ) )
F_83 ( V_18 , V_2 , & V_401 , V_402 ) ;
else if ( V_3 -> V_21 & ( V_55 ) )
F_83 ( V_18 , V_2 , & V_401 , V_405 ) ;
else
F_83 ( V_18 , V_2 , & V_401 , V_403 ) ;
F_85 ( V_2 , & V_417 ) ;
break;
}
}
