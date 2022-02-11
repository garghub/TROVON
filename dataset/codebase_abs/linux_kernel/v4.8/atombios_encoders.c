static T_1
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_4 = F_2 ( V_5 ) ;
V_3 = ( ( V_4 & V_6 ) >>
V_7 ) ;
return V_3 ;
}
static void
F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_5 ) ;
V_4 &= ~ V_6 ;
V_4 |= ( ( V_3 << V_7 ) &
V_6 ) ;
F_4 ( V_5 , V_4 ) ;
}
T_1
F_5 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return 0 ;
return F_1 ( V_2 ) ;
}
void
F_6 ( struct V_8 * V_8 ,
T_1 V_16 )
{
struct V_17 * V_18 = & V_8 -> V_11 ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_19 * V_20 ;
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return;
if ( ( V_8 -> V_21 & ( V_22 ) ) &&
V_8 -> V_23 ) {
V_20 = V_8 -> V_23 ;
V_20 -> V_3 = V_16 ;
F_3 ( V_2 , V_20 -> V_3 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
if ( V_20 -> V_3 == 0 )
F_7 ( V_18 ,
V_30 , 0 , 0 ) ;
else {
F_7 ( V_18 ,
V_31 , 0 , 0 ) ;
F_7 ( V_18 ,
V_32 , 0 , 0 ) ;
}
break;
default:
break;
}
}
}
static T_1 F_8 ( struct V_33 * V_34 )
{
T_1 V_16 ;
if ( V_34 -> V_35 . V_36 < 0 )
V_16 = 0 ;
else if ( V_34 -> V_35 . V_36 > V_37 )
V_16 = V_37 ;
else
V_16 = V_34 -> V_35 . V_36 ;
return V_16 ;
}
static int F_9 ( struct V_33 * V_34 )
{
struct V_38 * V_39 = F_10 ( V_34 ) ;
struct V_8 * V_8 = V_39 -> V_18 ;
F_6 ( V_8 ,
F_8 ( V_34 ) ) ;
return 0 ;
}
static int
F_11 ( struct V_33 * V_34 )
{
struct V_38 * V_39 = F_10 ( V_34 ) ;
struct V_8 * V_8 = V_39 -> V_18 ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
return F_1 ( V_2 ) ;
}
void F_12 ( struct V_8 * V_8 ,
struct V_40 * V_40 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_33 * V_34 ;
struct V_41 V_35 ;
struct V_38 * V_39 ;
struct V_19 * V_20 ;
T_1 V_3 ;
char V_42 [ 16 ] ;
if ( ( V_2 -> V_43 -> V_44 == V_45 ) &&
( V_2 -> V_43 -> V_46 == 0x6741 ) )
return;
if ( ! V_8 -> V_23 )
return;
if ( ! V_2 -> V_47 )
return;
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return;
V_39 = F_13 ( sizeof( struct V_38 ) , V_48 ) ;
if ( ! V_39 ) {
F_14 ( L_1 ) ;
goto error;
}
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_49 = V_37 ;
V_35 . type = V_50 ;
snprintf ( V_42 , sizeof( V_42 ) ,
L_2 , V_10 -> V_51 -> V_52 ) ;
V_34 = F_15 ( V_42 , V_40 -> V_53 ,
V_39 , & V_54 , & V_35 ) ;
if ( F_16 ( V_34 ) ) {
F_14 ( L_3 ) ;
goto error;
}
V_39 -> V_18 = V_8 ;
V_3 = F_1 ( V_2 ) ;
V_20 = V_8 -> V_23 ;
V_20 -> V_55 = V_34 ;
V_34 -> V_35 . V_36 = F_11 ( V_34 ) ;
V_34 -> V_35 . V_56 = V_57 ;
F_17 ( V_34 ) ;
F_18 ( L_4 ) ;
return;
error:
F_19 ( V_39 ) ;
return;
}
void
F_20 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_33 * V_34 = NULL ;
struct V_19 * V_20 ;
if ( ! V_8 -> V_23 )
return;
if ( ! V_2 -> V_47 )
return;
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return;
V_20 = V_8 -> V_23 ;
V_34 = V_20 -> V_55 ;
V_20 -> V_55 = NULL ;
if ( V_34 ) {
struct V_58 * V_39 ;
V_39 = F_10 ( V_34 ) ;
F_21 ( V_34 ) ;
F_19 ( V_39 ) ;
F_18 ( L_5 ) ;
}
}
void F_12 ( struct V_8 * V_18 )
{
}
void F_20 ( struct V_8 * V_18 )
{
}
bool F_22 ( struct V_17 * V_18 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
switch ( V_8 -> V_24 ) {
case V_59 :
case V_25 :
case V_27 :
case V_28 :
case V_29 :
return true ;
default:
return false ;
}
}
bool F_24 ( struct V_17 * V_18 ,
const struct V_60 * V_61 ,
struct V_60 * V_62 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
F_25 ( V_18 ) ;
F_26 ( V_62 , 0 ) ;
if ( ( V_61 -> V_63 & V_64 )
&& ( V_61 -> V_65 < ( V_61 -> V_66 + 2 ) ) )
V_62 -> V_65 = V_62 -> V_66 + 2 ;
if ( V_61 -> V_65 == V_61 -> V_66 )
V_62 -> V_65 ++ ;
if ( V_8 -> V_67 & ( V_22 ) )
F_27 ( V_18 , V_62 ) ;
else if ( V_8 -> V_68 != V_69 )
F_27 ( V_18 , V_62 ) ;
if ( ( V_8 -> V_67 & ( V_70 | V_22 ) ) ||
( F_28 ( V_18 ) != V_71 ) ) {
struct V_40 * V_72 = F_29 ( V_18 ) ;
F_30 ( V_72 , V_62 ) ;
}
return true ;
}
static void
F_31 ( struct V_17 * V_18 , int V_73 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
T_3 args ;
int V_52 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_24 ) {
case V_74 :
case V_75 :
V_52 = F_32 ( V_76 , V_77 ) ;
break;
case V_78 :
case V_79 :
V_52 = F_32 ( V_76 , V_80 ) ;
break;
}
args . V_81 = V_73 ;
args . V_82 = V_83 ;
args . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
}
static T_1 F_35 ( struct V_17 * V_18 )
{
int V_88 = 8 ;
if ( V_18 -> V_89 ) {
struct V_90 * V_90 = F_36 ( V_18 -> V_89 ) ;
V_88 = V_90 -> V_88 ;
}
switch ( V_88 ) {
case 0 :
return V_91 ;
case 6 :
return V_92 ;
case 8 :
default:
return V_93 ;
case 10 :
return V_94 ;
case 12 :
return V_95 ;
case 16 :
return V_96 ;
}
}
static void
F_37 ( struct V_17 * V_18 , int V_73 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
union V_97 args ;
int V_52 = F_32 ( V_76 , V_98 ) ;
T_4 V_99 , V_100 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_52 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
switch ( V_100 ) {
case 1 :
args . V_101 . V_102 . V_103 = V_73 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_101 . V_102 . V_104 |= V_105 ;
args . V_101 . V_102 . V_104 |= V_106 ;
break;
case 2 :
args . V_107 . V_108 . V_81 = V_73 ;
args . V_107 . V_108 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
args . V_107 . V_108 . V_109 = V_110 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_107 . V_108 . V_111 . V_112 . V_113 |= V_105 ;
break;
case 3 :
args . V_114 . V_81 = V_73 ;
args . V_114 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
args . V_114 . V_115 = 0 ;
break;
case 4 :
args . V_116 . V_81 = V_73 ;
args . V_116 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
args . V_116 . V_115 = 0 ;
args . V_116 . V_117 = F_35 ( V_18 ) ;
break;
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
}
int F_40 ( struct V_17 * V_18 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_40 * V_72 ;
struct V_118 * V_118 ;
struct V_119 * V_120 ;
if ( F_28 ( V_18 ) != V_71 )
return V_121 ;
if ( ( V_8 -> V_24 == V_122 ) ||
( V_8 -> V_24 == V_59 ) )
return V_123 ;
V_72 = F_29 ( V_18 ) ;
if ( ! V_72 )
V_72 = F_41 ( V_18 ) ;
V_118 = F_42 ( V_72 ) ;
switch ( V_72 -> V_124 ) {
case V_125 :
case V_126 :
if ( V_127 != 0 ) {
if ( V_118 -> V_128 &&
( V_118 -> V_129 == V_130 ) )
return V_131 ;
else if ( F_43 ( F_44 ( V_72 ) ) &&
( V_118 -> V_129 == V_132 ) )
return V_131 ;
else if ( V_118 -> V_128 )
return V_133 ;
else
return V_134 ;
} else if ( V_118 -> V_128 ) {
return V_133 ;
} else {
return V_134 ;
}
break;
case V_135 :
case V_136 :
default:
if ( V_127 != 0 ) {
if ( V_118 -> V_129 == V_130 )
return V_131 ;
else if ( F_43 ( F_44 ( V_72 ) ) &&
( V_118 -> V_129 == V_132 ) )
return V_131 ;
else
return V_133 ;
} else {
return V_133 ;
}
break;
case V_137 :
return V_138 ;
break;
case V_139 :
V_120 = V_118 -> V_140 ;
if ( ( V_120 -> V_141 == V_142 ) ||
( V_120 -> V_141 == V_143 ) ) {
return V_121 ;
} else if ( V_127 != 0 ) {
if ( V_118 -> V_129 == V_130 )
return V_131 ;
else if ( F_43 ( F_44 ( V_72 ) ) &&
( V_118 -> V_129 == V_132 ) )
return V_131 ;
else
return V_133 ;
} else {
return V_133 ;
}
break;
case V_144 :
return V_121 ;
case V_145 :
case V_146 :
return V_134 ;
break;
case V_147 :
case V_148 :
case V_149 :
return V_150 ;
break;
}
}
void
F_45 ( struct V_17 * V_18 ,
int V_73 , int V_151 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_40 * V_72 = F_29 ( V_18 ) ;
union V_152 args ;
int V_52 = F_32 ( V_76 , V_153 ) ;
T_4 V_99 , V_100 ;
int V_154 = 0 ;
int V_155 = 0 ;
int V_156 = V_157 ;
if ( V_72 ) {
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_119 * V_120 =
V_118 -> V_140 ;
V_154 = V_120 -> V_154 ;
V_155 = V_120 -> V_155 ;
V_156 = V_118 -> V_158 . V_158 ;
}
if ( V_20 -> V_159 == - 1 )
return;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_52 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
switch ( V_100 ) {
case 1 :
args . V_160 . V_81 = V_73 ;
args . V_160 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
if ( V_73 == V_161 )
args . V_162 . V_163 = V_151 ;
else
args . V_160 . V_164 = F_40 ( V_18 ) ;
if ( F_46 ( args . V_160 . V_164 ) )
args . V_160 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_160 . V_165 = 8 ;
else
args . V_160 . V_165 = 4 ;
if ( F_46 ( args . V_160 . V_164 ) && ( V_154 == 270000 ) )
args . V_160 . V_166 |= V_167 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_160 . V_166 = V_168 ;
break;
case V_27 :
case V_26 :
args . V_160 . V_166 = V_169 ;
break;
case V_28 :
args . V_160 . V_166 = V_170 ;
break;
}
if ( V_20 -> V_171 )
args . V_160 . V_166 |= V_172 ;
else
args . V_160 . V_166 |= V_173 ;
break;
case 2 :
case 3 :
args . V_162 . V_81 = V_73 ;
args . V_162 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
if ( V_73 == V_161 )
args . V_162 . V_163 = V_151 ;
else
args . V_162 . V_164 = F_40 ( V_18 ) ;
if ( F_46 ( args . V_162 . V_164 ) )
args . V_162 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_165 = 8 ;
else
args . V_162 . V_165 = 4 ;
if ( F_46 ( args . V_162 . V_164 ) && ( V_154 == 270000 ) )
args . V_160 . V_166 |= V_174 ;
args . V_162 . V_175 . V_176 = V_20 -> V_159 ;
args . V_162 . V_117 = F_35 ( V_18 ) ;
break;
case 4 :
args . V_177 . V_81 = V_73 ;
args . V_177 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
if ( V_73 == V_161 )
args . V_177 . V_163 = V_151 ;
else
args . V_177 . V_164 = F_40 ( V_18 ) ;
if ( F_46 ( args . V_177 . V_164 ) )
args . V_177 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_177 . V_165 = 8 ;
else
args . V_177 . V_165 = 4 ;
if ( F_46 ( args . V_177 . V_164 ) ) {
if ( V_154 == 540000 )
args . V_160 . V_166 |= V_178 ;
else if ( V_154 == 324000 )
args . V_160 . V_166 |= V_179 ;
else if ( V_154 == 270000 )
args . V_160 . V_166 |= V_180 ;
else
args . V_160 . V_166 |= V_181 ;
}
args . V_177 . V_175 . V_176 = V_20 -> V_159 ;
args . V_177 . V_117 = F_35 ( V_18 ) ;
if ( V_156 == V_157 )
args . V_177 . V_182 = 0 ;
else
args . V_177 . V_182 = V_156 + 1 ;
break;
case 5 :
switch ( V_73 ) {
case V_161 :
args . V_183 . V_184 . V_81 = V_73 ;
args . V_183 . V_184 . V_163 = V_151 ;
args . V_183 . V_184 . V_185 = V_20 -> V_159 ;
break;
case V_186 :
args . V_183 . V_187 . V_81 = V_73 ;
args . V_183 . V_187 . V_185 = V_20 -> V_159 ;
args . V_183 . V_187 . V_188 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_183 . V_187 . V_188 ) )
args . V_183 . V_187 . V_165 = V_155 ;
else if ( F_39 ( V_18 ,
V_8 -> V_85 ) )
args . V_183 . V_187 . V_165 = 8 ;
else
args . V_183 . V_187 . V_165 = 4 ;
args . V_183 . V_187 . V_189 =
F_47 ( V_8 -> V_85 / 10 ) ;
args . V_183 . V_187 . V_117 =
F_35 ( V_18 ) ;
args . V_183 . V_187 . V_190 = V_154 / 27000 ;
break;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
args . V_183 . V_199 . V_81 = V_73 ;
args . V_183 . V_199 . V_185 = V_20 -> V_159 ;
break;
default:
F_14 ( L_7 , V_73 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
}
void
F_7 ( struct V_17 * V_18 , int V_73 ,
T_4 V_200 , T_4 V_201 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_40 * V_72 ;
union V_202 args ;
int V_52 = 0 ;
T_4 V_99 , V_100 ;
bool V_203 = false ;
int V_204 = 0 ;
int V_154 = 0 ;
int V_155 = 0 ;
int V_205 = 0 ;
int V_206 = 0 ;
int V_159 = V_20 -> V_159 ;
int V_156 = V_157 ;
if ( V_73 == V_207 ) {
V_72 = F_41 ( V_18 ) ;
V_159 = 0 ;
} else
V_72 = F_29 ( V_18 ) ;
if ( V_72 ) {
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_119 * V_120 =
V_118 -> V_140 ;
V_156 = V_118 -> V_158 . V_158 ;
V_154 = V_120 -> V_154 ;
V_155 = V_120 -> V_155 ;
V_205 =
( V_118 -> V_205 & V_208 ) >> V_209 ;
}
if ( V_18 -> V_89 ) {
struct V_90 * V_90 = F_36 ( V_18 -> V_89 ) ;
V_204 = V_90 -> V_204 ;
}
if ( V_159 == - 1 )
return;
if ( F_46 ( F_40 ( V_18 ) ) )
V_203 = true ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_24 ) {
case V_59 :
V_52 = F_32 ( V_76 , V_210 ) ;
break;
case V_25 :
case V_27 :
case V_28 :
case V_29 :
V_52 = F_32 ( V_76 , V_211 ) ;
break;
case V_26 :
V_52 = F_32 ( V_76 , V_212 ) ;
break;
}
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_52 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
switch ( V_100 ) {
case 1 :
args . V_160 . V_81 = V_73 ;
if ( V_73 == V_207 ) {
args . V_160 . V_213 = F_33 ( V_205 ) ;
} else if ( V_73 == V_214 ) {
args . V_160 . V_215 . V_216 = V_200 ;
args . V_160 . V_215 . V_217 = V_201 ;
} else {
if ( V_203 )
args . V_160 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_160 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_160 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
args . V_160 . V_166 = V_218 ;
if ( V_159 )
args . V_160 . V_166 |= V_219 ;
else
args . V_160 . V_166 |= V_220 ;
if ( ( V_2 -> V_63 & V_221 ) &&
( V_8 -> V_24 == V_25 ) ) {
if ( V_203 ||
! F_39 ( V_18 , V_8 -> V_85 ) ) {
if ( V_206 & 0x1 )
args . V_160 . V_166 |= V_222 ;
else if ( V_206 & 0x2 )
args . V_160 . V_166 |= V_223 ;
else if ( V_206 & 0x4 )
args . V_160 . V_166 |= V_224 ;
else if ( V_206 & 0x8 )
args . V_160 . V_166 |= V_225 ;
} else {
if ( V_206 & 0x3 )
args . V_160 . V_166 |= V_226 ;
else if ( V_206 & 0xc )
args . V_160 . V_166 |= V_227 ;
}
}
if ( V_20 -> V_171 )
args . V_160 . V_166 |= V_228 ;
else
args . V_160 . V_166 |= V_229 ;
if ( V_203 )
args . V_160 . V_166 |= V_230 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_231 )
args . V_160 . V_166 |= V_230 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_160 . V_166 |= V_232 ;
}
break;
case 2 :
args . V_233 . V_81 = V_73 ;
if ( V_73 == V_207 ) {
args . V_233 . V_213 = F_33 ( V_205 ) ;
} else if ( V_73 == V_214 ) {
args . V_233 . V_215 . V_216 = V_200 ;
args . V_233 . V_215 . V_217 = V_201 ;
} else {
if ( V_203 )
args . V_233 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_233 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_233 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
args . V_233 . V_175 . V_234 = V_159 ;
if ( V_20 -> V_171 )
args . V_233 . V_175 . V_235 = 1 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_233 . V_175 . V_236 = 0 ;
break;
case V_27 :
args . V_233 . V_175 . V_236 = 1 ;
break;
case V_28 :
args . V_233 . V_175 . V_236 = 2 ;
break;
}
if ( V_203 ) {
args . V_233 . V_175 . V_237 = 1 ;
args . V_233 . V_175 . V_238 = 1 ;
} else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_231 )
args . V_233 . V_175 . V_237 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_233 . V_175 . V_239 = 1 ;
}
break;
case 3 :
args . V_162 . V_81 = V_73 ;
if ( V_73 == V_207 ) {
args . V_162 . V_213 = F_33 ( V_205 ) ;
} else if ( V_73 == V_214 ) {
args . V_162 . V_215 . V_216 = V_200 ;
args . V_162 . V_215 . V_217 = V_201 ;
} else {
if ( V_203 )
args . V_162 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_162 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
if ( V_203 )
args . V_162 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_165 = 8 ;
else
args . V_162 . V_165 = 4 ;
if ( V_20 -> V_171 )
args . V_162 . V_175 . V_235 = 1 ;
if ( V_159 & 1 )
args . V_162 . V_175 . V_234 = 1 ;
if ( V_203 && V_2 -> clock . V_240 )
args . V_162 . V_175 . V_241 = 2 ;
else
args . V_162 . V_175 . V_241 = V_204 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_162 . V_175 . V_236 = 0 ;
break;
case V_27 :
args . V_162 . V_175 . V_236 = 1 ;
break;
case V_28 :
args . V_162 . V_175 . V_236 = 2 ;
break;
}
if ( V_203 )
args . V_162 . V_175 . V_237 = 1 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_231 )
args . V_162 . V_175 . V_237 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_175 . V_239 = 1 ;
}
break;
case 4 :
args . V_177 . V_81 = V_73 ;
if ( V_73 == V_207 ) {
args . V_177 . V_213 = F_33 ( V_205 ) ;
} else if ( V_73 == V_214 ) {
args . V_177 . V_215 . V_216 = V_200 ;
args . V_177 . V_215 . V_217 = V_201 ;
} else {
if ( V_203 )
args . V_177 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_177 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_177 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
if ( V_203 )
args . V_177 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_177 . V_165 = 8 ;
else
args . V_177 . V_165 = 4 ;
if ( V_20 -> V_171 )
args . V_177 . V_175 . V_235 = 1 ;
if ( V_159 & 1 )
args . V_177 . V_175 . V_234 = 1 ;
if ( V_203 ) {
if ( V_2 -> clock . V_240 )
args . V_177 . V_175 . V_241 = V_242 ;
else
args . V_177 . V_175 . V_241 = V_243 ;
} else
args . V_177 . V_175 . V_241 = V_204 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_177 . V_175 . V_236 = 0 ;
break;
case V_27 :
args . V_177 . V_175 . V_236 = 1 ;
break;
case V_28 :
args . V_177 . V_175 . V_236 = 2 ;
break;
}
if ( V_203 )
args . V_177 . V_175 . V_237 = 1 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_231 )
args . V_177 . V_175 . V_237 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_177 . V_175 . V_239 = 1 ;
}
break;
case 5 :
args . V_183 . V_81 = V_73 ;
if ( V_203 )
args . V_183 . V_244 = F_33 ( V_154 / 10 ) ;
else
args . V_183 . V_244 = F_33 ( V_8 -> V_85 / 10 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
if ( V_20 -> V_171 )
args . V_183 . V_245 = V_246 ;
else
args . V_183 . V_245 = V_247 ;
break;
case V_27 :
if ( V_20 -> V_171 )
args . V_183 . V_245 = V_248 ;
else
args . V_183 . V_245 = V_249 ;
break;
case V_28 :
if ( V_20 -> V_171 )
args . V_183 . V_245 = V_250 ;
else
args . V_183 . V_245 = V_251 ;
break;
case V_29 :
args . V_183 . V_245 = V_252 ;
break;
}
if ( V_203 )
args . V_183 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_183 . V_165 = 8 ;
else
args . V_183 . V_165 = 4 ;
args . V_183 . V_253 = V_205 ;
args . V_183 . V_188 = F_40 ( V_18 ) ;
if ( V_203 && V_2 -> clock . V_240 )
args . V_183 . V_254 . V_255 = V_242 ;
else
args . V_183 . V_254 . V_255 = V_204 ;
if ( V_203 )
args . V_183 . V_254 . V_256 = 1 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_231 )
args . V_183 . V_254 . V_256 = 1 ;
}
if ( V_156 == V_157 )
args . V_183 . V_254 . V_257 = 0 ;
else
args . V_183 . V_254 . V_257 = V_156 + 1 ;
args . V_183 . V_258 = 1 << V_159 ;
args . V_183 . V_259 = V_201 ;
break;
case 6 :
args . V_260 . V_81 = V_73 ;
if ( V_203 )
args . V_260 . V_261 = F_47 ( V_154 / 10 ) ;
else
args . V_260 . V_261 = F_47 ( V_8 -> V_85 / 10 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
if ( V_20 -> V_171 )
args . V_260 . V_245 = V_246 ;
else
args . V_260 . V_245 = V_247 ;
break;
case V_27 :
if ( V_20 -> V_171 )
args . V_260 . V_245 = V_248 ;
else
args . V_260 . V_245 = V_249 ;
break;
case V_28 :
if ( V_20 -> V_171 )
args . V_260 . V_245 = V_250 ;
else
args . V_260 . V_245 = V_251 ;
break;
case V_29 :
args . V_260 . V_245 = V_252 ;
break;
}
if ( V_203 )
args . V_260 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_260 . V_165 = 8 ;
else
args . V_260 . V_165 = 4 ;
args . V_260 . V_253 = V_205 ;
if ( V_73 == V_214 )
args . V_260 . V_259 = V_201 ;
else
args . V_260 . V_188 = F_40 ( V_18 ) ;
if ( V_156 == V_157 )
args . V_260 . V_257 = 0 ;
else
args . V_260 . V_257 = V_156 + 1 ;
args . V_260 . V_258 = 1 << V_159 ;
break;
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
}
bool
F_48 ( struct V_40 * V_72 ,
int V_73 )
{
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_9 * V_10 = V_118 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
union V_202 args ;
int V_52 = F_32 ( V_76 , V_211 ) ;
T_4 V_99 , V_100 ;
if ( V_72 -> V_124 != V_144 )
goto V_262;
if ( ( V_73 != V_263 ) &&
( V_73 != V_264 ) )
goto V_262;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_52 , & V_99 , & V_100 ) )
goto V_262;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_160 . V_81 = V_73 ;
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
if ( V_73 == V_263 ) {
int V_265 ;
for ( V_265 = 0 ; V_265 < 300 ; V_265 ++ ) {
if ( F_49 ( V_2 , V_118 -> V_158 . V_158 ) )
return true ;
F_50 ( 1 ) ;
}
return false ;
}
V_262:
return true ;
}
static void
F_51 ( struct V_17 * V_18 ,
struct V_17 * V_266 ,
int V_73 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_8 * V_267 = F_23 ( V_266 ) ;
union V_268 args ;
struct V_40 * V_72 ;
int V_52 = F_32 ( V_76 , V_269 ) ;
T_1 V_99 , V_100 ;
int V_154 = 0 ;
int V_155 = 0 ;
int V_205 = 0 ;
T_2 V_270 = ( V_267 -> V_271 & V_272 ) >> V_273 ;
if ( V_73 == V_274 )
V_72 = F_41 ( V_18 ) ;
else
V_72 = F_29 ( V_18 ) ;
if ( V_72 ) {
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_119 * V_120 =
V_118 -> V_140 ;
V_154 = V_120 -> V_154 ;
V_155 = V_120 -> V_155 ;
V_205 =
( V_118 -> V_205 & V_208 ) >> V_209 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_52 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
break;
case 2 :
switch ( V_100 ) {
case 1 :
case 2 :
args . V_160 . V_275 . V_81 = V_73 ;
args . V_160 . V_275 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
args . V_160 . V_275 . V_164 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_160 . V_275 . V_164 ) ) {
if ( V_154 == 270000 )
args . V_160 . V_275 . V_166 |= V_167 ;
args . V_160 . V_275 . V_165 = V_155 ;
} else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_160 . V_275 . V_165 = 8 ;
else
args . V_160 . V_275 . V_165 = 4 ;
break;
case 3 :
args . V_162 . V_276 . V_81 = V_73 ;
if ( V_73 == V_274 )
args . V_162 . V_276 . V_277 = F_33 ( V_205 ) ;
else
args . V_162 . V_276 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
args . V_162 . V_276 . V_164 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_162 . V_276 . V_164 ) ) {
if ( V_154 == 270000 )
args . V_162 . V_276 . V_166 |= V_278 ;
else if ( V_154 == 540000 )
args . V_162 . V_276 . V_166 |= V_279 ;
args . V_162 . V_276 . V_165 = V_155 ;
} else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_276 . V_165 = 8 ;
else
args . V_162 . V_276 . V_165 = 4 ;
switch ( V_270 ) {
case V_280 :
args . V_162 . V_276 . V_166 |= V_281 ;
break;
case V_282 :
args . V_162 . V_276 . V_166 |= V_283 ;
break;
case V_284 :
args . V_162 . V_276 . V_166 |= V_285 ;
break;
}
args . V_162 . V_276 . V_117 = F_35 ( V_18 ) ;
break;
default:
F_14 ( L_8 , V_99 , V_100 ) ;
return;
}
break;
default:
F_14 ( L_8 , V_99 , V_100 ) ;
return;
}
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
}
static void
F_52 ( struct V_17 * V_18 , int V_73 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_17 * V_266 = F_53 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_40 * V_72 = F_29 ( V_18 ) ;
struct V_118 * V_118 = NULL ;
struct V_119 * V_286 = NULL ;
if ( V_72 ) {
V_118 = F_42 ( V_72 ) ;
V_286 = V_118 -> V_140 ;
}
if ( V_73 == V_287 ) {
if ( ! V_72 )
V_20 -> V_151 = V_288 ;
else
V_20 -> V_151 = F_54 ( V_18 , V_72 ) ;
F_45 ( V_18 , V_289 , 0 ) ;
F_45 ( V_18 ,
V_161 ,
V_20 -> V_151 ) ;
if ( V_266 )
F_51 ( V_18 , V_266 ,
V_290 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 ) {
if ( V_72 -> V_124 == V_144 ) {
F_48 ( V_72 ,
V_263 ) ;
V_286 -> V_291 = true ;
}
}
F_7 ( V_18 ,
V_292 ,
0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 ) {
F_55 ( V_18 , V_72 ) ;
F_45 ( V_18 , V_198 , 0 ) ;
}
if ( V_8 -> V_21 & ( V_22 ) )
F_6 ( V_8 , V_20 -> V_3 ) ;
if ( V_266 )
F_51 ( V_18 , V_266 , V_287 ) ;
} else {
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 )
F_45 ( V_18 ,
V_197 , 0 ) ;
if ( V_266 )
F_51 ( V_18 , V_266 , V_293 ) ;
if ( V_8 -> V_21 & ( V_22 ) )
F_7 ( V_18 ,
V_30 , 0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 )
F_56 ( V_72 , V_294 ) ;
F_7 ( V_18 ,
V_295 , 0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 ) {
if ( V_72 -> V_124 == V_144 ) {
F_48 ( V_72 ,
V_264 ) ;
V_286 -> V_291 = false ;
}
}
}
}
void
F_57 ( struct V_17 * V_18 , int V_61 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
F_58 ( L_9 ,
V_8 -> V_24 , V_61 , V_8 -> V_21 ,
V_8 -> V_67 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
switch ( V_61 ) {
case V_296 :
F_52 ( V_18 , V_287 ) ;
break;
case V_297 :
case V_298 :
case V_299 :
F_52 ( V_18 , V_293 ) ;
break;
}
break;
case V_59 :
switch ( V_61 ) {
case V_296 :
F_37 ( V_18 , V_287 ) ;
break;
case V_297 :
case V_298 :
case V_299 :
F_37 ( V_18 , V_293 ) ;
break;
}
break;
case V_75 :
switch ( V_61 ) {
case V_296 :
F_31 ( V_18 , V_287 ) ;
break;
case V_297 :
case V_298 :
case V_299 :
F_31 ( V_18 , V_293 ) ;
break;
}
break;
default:
return;
}
}
void
F_59 ( struct V_17 * V_18 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_90 * V_90 = F_36 ( V_18 -> V_89 ) ;
union V_300 args ;
int V_52 = F_32 ( V_76 , V_301 ) ;
T_4 V_99 , V_100 ;
struct V_19 * V_20 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_52 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
switch ( V_100 ) {
case 1 :
default:
args . V_160 . V_302 = V_90 -> V_303 ;
switch ( V_8 -> V_24 ) {
case V_304 :
case V_305 :
args . V_160 . V_306 = V_110 ;
break;
case V_307 :
case V_308 :
if ( V_8 -> V_21 & V_309 )
args . V_160 . V_306 = V_310 ;
else
args . V_160 . V_306 = V_311 ;
break;
case V_122 :
case V_312 :
case V_59 :
args . V_160 . V_306 = V_313 ;
break;
case V_74 :
case V_75 :
if ( V_8 -> V_67 & ( V_314 ) )
args . V_160 . V_306 = V_315 ;
else if ( V_8 -> V_67 & ( V_316 ) )
args . V_160 . V_306 = V_317 ;
else
args . V_160 . V_306 = V_318 ;
break;
case V_78 :
case V_79 :
if ( V_8 -> V_67 & ( V_314 ) )
args . V_160 . V_306 = V_315 ;
else if ( V_8 -> V_67 & ( V_316 ) )
args . V_160 . V_306 = V_317 ;
else
args . V_160 . V_306 = V_319 ;
break;
}
break;
case 2 :
args . V_233 . V_302 = V_90 -> V_303 ;
if ( F_28 ( V_18 ) != V_71 ) {
struct V_40 * V_72 = F_29 ( V_18 ) ;
if ( V_72 -> V_124 == V_137 )
args . V_233 . V_320 = V_138 ;
else if ( V_72 -> V_124 == V_146 )
args . V_233 . V_320 = V_134 ;
else
args . V_233 . V_320 = F_40 ( V_18 ) ;
} else if ( V_8 -> V_21 & ( V_22 ) ) {
args . V_233 . V_320 = V_138 ;
} else {
args . V_233 . V_320 = F_40 ( V_18 ) ;
}
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
case V_26 :
V_20 = V_8 -> V_23 ;
switch ( V_20 -> V_159 ) {
case 0 :
args . V_233 . V_321 = V_322 ;
break;
case 1 :
args . V_233 . V_321 = V_323 ;
break;
case 2 :
args . V_233 . V_321 = V_324 ;
break;
case 3 :
args . V_233 . V_321 = V_325 ;
break;
case 4 :
args . V_233 . V_321 = V_326 ;
break;
case 5 :
args . V_233 . V_321 = V_327 ;
break;
case 6 :
args . V_233 . V_321 = V_328 ;
break;
}
break;
case V_59 :
args . V_233 . V_321 = V_329 ;
break;
case V_75 :
if ( V_8 -> V_67 & ( V_314 ) )
args . V_233 . V_321 = V_330 ;
else if ( V_8 -> V_67 & ( V_316 ) )
args . V_233 . V_321 = V_330 ;
else
args . V_233 . V_321 = V_331 ;
break;
case V_79 :
if ( V_8 -> V_67 & ( V_314 ) )
args . V_233 . V_321 = V_330 ;
else if ( V_8 -> V_67 & ( V_316 ) )
args . V_233 . V_321 = V_330 ;
else
args . V_233 . V_321 = V_332 ;
break;
}
break;
case 3 :
args . V_162 . V_302 = V_90 -> V_303 ;
if ( F_28 ( V_18 ) != V_71 ) {
struct V_40 * V_72 = F_29 ( V_18 ) ;
if ( V_72 -> V_124 == V_137 )
args . V_233 . V_320 = V_138 ;
else if ( V_72 -> V_124 == V_146 )
args . V_233 . V_320 = V_134 ;
else
args . V_233 . V_320 = F_40 ( V_18 ) ;
} else if ( V_8 -> V_21 & ( V_22 ) ) {
args . V_233 . V_320 = V_138 ;
} else {
args . V_233 . V_320 = F_40 ( V_18 ) ;
}
args . V_162 . V_333 = F_35 ( V_18 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
case V_26 :
V_20 = V_8 -> V_23 ;
switch ( V_20 -> V_159 ) {
case 0 :
args . V_162 . V_321 = V_322 ;
break;
case 1 :
args . V_162 . V_321 = V_323 ;
break;
case 2 :
args . V_162 . V_321 = V_324 ;
break;
case 3 :
args . V_162 . V_321 = V_325 ;
break;
case 4 :
args . V_162 . V_321 = V_326 ;
break;
case 5 :
args . V_162 . V_321 = V_327 ;
break;
case 6 :
args . V_162 . V_321 = V_328 ;
break;
}
break;
case V_59 :
args . V_162 . V_321 = V_329 ;
break;
case V_75 :
if ( V_8 -> V_67 & ( V_314 ) )
args . V_162 . V_321 = V_330 ;
else if ( V_8 -> V_67 & ( V_316 ) )
args . V_162 . V_321 = V_330 ;
else
args . V_162 . V_321 = V_331 ;
break;
case V_79 :
if ( V_8 -> V_67 & ( V_314 ) )
args . V_162 . V_321 = V_330 ;
else if ( V_8 -> V_67 & ( V_316 ) )
args . V_162 . V_321 = V_330 ;
else
args . V_162 . V_321 = V_332 ;
break;
}
break;
}
break;
default:
F_14 ( L_8 , V_99 , V_100 ) ;
return;
}
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
}
void
F_60 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_334 ;
struct V_17 * V_18 ;
F_61 (encoder, &dev->mode_config.encoder_list, head) {
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_17 * V_266 = F_53 ( V_18 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
F_7 ( V_18 , V_207 ,
0 , 0 ) ;
break;
}
if ( V_266 )
F_51 ( V_18 , V_266 ,
V_274 ) ;
}
}
static bool
F_62 ( struct V_17 * V_18 ,
struct V_40 * V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_118 * V_118 = F_42 ( V_72 ) ;
if ( V_8 -> V_21 & ( V_314 |
V_316 |
V_335 ) ) {
T_5 args ;
int V_52 = F_32 ( V_76 , V_336 ) ;
T_4 V_99 , V_100 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_52 , & V_99 , & V_100 ) )
return false ;
args . V_337 . V_104 = 0 ;
if ( ( V_8 -> V_24 == V_74 ) ||
( V_8 -> V_24 == V_75 ) )
args . V_337 . V_338 = V_339 ;
else
args . V_337 . V_338 = V_340 ;
if ( V_118 -> V_21 & V_341 )
args . V_337 . V_342 = F_33 ( V_341 ) ;
else if ( V_118 -> V_21 & V_343 )
args . V_337 . V_342 = F_33 ( V_343 ) ;
else if ( V_118 -> V_21 & V_316 ) {
args . V_337 . V_342 = F_33 ( V_316 ) ;
if ( V_100 >= 3 )
args . V_337 . V_104 = V_344 ;
} else if ( V_118 -> V_21 & V_345 ) {
args . V_337 . V_342 = F_33 ( V_345 ) ;
if ( V_100 >= 3 )
args . V_337 . V_104 = V_344 ;
}
F_34 ( V_2 -> V_13 . V_86 , V_52 , ( V_87 * ) & args ) ;
return true ;
} else
return false ;
}
enum V_346
F_63 ( struct V_17 * V_18 ,
struct V_40 * V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_118 * V_118 = F_42 ( V_72 ) ;
V_87 V_347 ;
if ( ! F_62 ( V_18 , V_72 ) ) {
F_58 ( L_10 ) ;
return V_348 ;
}
V_347 = F_2 ( V_349 ) ;
F_58 ( L_11 , V_347 , V_8 -> V_21 ) ;
if ( V_118 -> V_21 & V_341 ) {
if ( V_347 & V_350 )
return V_351 ;
}
if ( V_118 -> V_21 & V_343 ) {
if ( V_347 & V_352 )
return V_351 ;
}
if ( V_118 -> V_21 & V_316 ) {
if ( V_347 & ( V_353 | V_354 ) )
return V_351 ;
}
if ( V_118 -> V_21 & V_345 ) {
if ( V_347 & ( V_355 | V_356 ) )
return V_351 ;
else if ( V_347 & ( V_357 | V_358 ) )
return V_351 ;
}
return V_359 ;
}
enum V_346
F_64 ( struct V_17 * V_18 ,
struct V_40 * V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_17 * V_266 = F_53 ( V_18 ) ;
T_2 V_347 ;
if ( ! V_266 )
return V_348 ;
if ( ( V_118 -> V_21 & V_335 ) == 0 )
return V_348 ;
F_51 ( V_18 , V_266 ,
V_360 ) ;
V_347 = F_2 ( V_349 ) ;
F_58 ( L_11 , V_347 , V_8 -> V_21 ) ;
if ( V_118 -> V_21 & V_341 ) {
if ( V_347 & V_350 )
return V_351 ;
}
if ( V_118 -> V_21 & V_343 ) {
if ( V_347 & V_352 )
return V_351 ;
}
if ( V_118 -> V_21 & V_316 ) {
if ( V_347 & ( V_353 | V_354 ) )
return V_351 ;
}
if ( V_118 -> V_21 & V_345 ) {
if ( V_347 & ( V_355 | V_356 ) )
return V_351 ;
else if ( V_347 & ( V_357 | V_358 ) )
return V_351 ;
}
return V_359 ;
}
void
F_65 ( struct V_17 * V_18 )
{
struct V_17 * V_266 = F_53 ( V_18 ) ;
if ( V_266 )
F_51 ( V_18 , V_266 ,
V_361 ) ;
}
void
F_66 ( struct V_40 * V_72 ,
struct V_17 * V_18 ,
bool V_362 )
{
struct V_9 * V_10 = V_72 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_118 * V_118 =
F_42 ( V_72 ) ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
V_87 V_347 , V_363 , V_364 ;
V_347 = F_2 ( V_349 ) ;
V_363 = F_2 ( V_365 ) ;
V_364 = F_2 ( V_366 ) ;
if ( ( V_8 -> V_21 & V_309 ) &&
( V_118 -> V_21 & V_309 ) ) {
if ( V_362 ) {
F_58 ( L_12 ) ;
V_347 |= V_367 ;
V_363 |= V_368 ;
V_364 |= V_369 ;
} else {
F_58 ( L_13 ) ;
V_347 &= ~ V_367 ;
V_363 &= ~ V_368 ;
V_364 &= ~ V_369 ;
}
}
if ( ( V_8 -> V_21 & V_341 ) &&
( V_118 -> V_21 & V_341 ) ) {
if ( V_362 ) {
F_58 ( L_14 ) ;
V_347 |= V_370 ;
V_363 |= V_371 ;
V_364 |= V_372 ;
} else {
F_58 ( L_15 ) ;
V_347 &= ~ V_350 ;
V_363 &= ~ V_371 ;
V_364 &= ~ V_372 ;
}
}
if ( ( V_8 -> V_21 & V_343 ) &&
( V_118 -> V_21 & V_343 ) ) {
if ( V_362 ) {
F_58 ( L_16 ) ;
V_347 |= V_373 ;
V_363 |= V_374 ;
V_364 |= V_375 ;
} else {
F_58 ( L_17 ) ;
V_347 &= ~ V_352 ;
V_363 &= ~ V_374 ;
V_364 &= ~ V_375 ;
}
}
if ( ( V_8 -> V_21 & V_376 ) &&
( V_118 -> V_21 & V_376 ) ) {
if ( V_362 ) {
F_58 ( L_18 ) ;
V_347 |= V_377 ;
V_363 |= V_378 ;
V_364 |= V_379 ;
} else {
F_58 ( L_19 ) ;
V_347 &= ~ V_377 ;
V_363 &= ~ V_378 ;
V_364 &= ~ V_379 ;
}
}
if ( ( V_8 -> V_21 & V_380 ) &&
( V_118 -> V_21 & V_380 ) ) {
if ( V_362 ) {
F_58 ( L_20 ) ;
V_347 |= V_381 ;
V_363 |= V_382 ;
V_364 |= V_383 ;
} else {
F_58 ( L_21 ) ;
V_347 &= ~ V_381 ;
V_363 &= ~ V_382 ;
V_364 &= ~ V_383 ;
}
}
if ( ( V_8 -> V_21 & V_384 ) &&
( V_118 -> V_21 & V_384 ) ) {
if ( V_362 ) {
F_58 ( L_22 ) ;
V_347 |= V_385 ;
V_363 |= V_386 ;
V_364 |= V_387 ;
} else {
F_58 ( L_23 ) ;
V_347 &= ~ V_385 ;
V_363 &= ~ V_386 ;
V_364 &= ~ V_387 ;
}
}
if ( ( V_8 -> V_21 & V_388 ) &&
( V_118 -> V_21 & V_388 ) ) {
if ( V_362 ) {
F_58 ( L_24 ) ;
V_347 |= V_389 ;
V_363 |= V_390 ;
V_364 |= V_391 ;
} else {
F_58 ( L_25 ) ;
V_347 &= ~ V_389 ;
V_363 &= ~ V_390 ;
V_364 &= ~ V_391 ;
}
}
if ( ( V_8 -> V_21 & V_392 ) &&
( V_118 -> V_21 & V_392 ) ) {
if ( V_362 ) {
F_58 ( L_26 ) ;
V_347 |= V_393 ;
V_363 |= V_394 ;
V_364 |= V_395 ;
} else {
F_58 ( L_27 ) ;
V_347 &= ~ V_393 ;
V_363 &= ~ V_394 ;
V_364 &= ~ V_395 ;
}
}
if ( ( V_8 -> V_21 & V_396 ) &&
( V_118 -> V_21 & V_396 ) ) {
if ( V_362 ) {
F_58 ( L_28 ) ;
V_347 |= V_397 ;
V_363 |= V_398 ;
V_364 |= V_399 ;
} else {
F_58 ( L_29 ) ;
V_347 &= ~ V_397 ;
V_363 &= ~ V_398 ;
V_364 &= ~ V_399 ;
}
}
F_4 ( V_349 , V_347 ) ;
F_4 ( V_365 , V_363 ) ;
F_4 ( V_366 , V_364 ) ;
}
struct V_19 *
F_67 ( struct V_8 * V_18 )
{
struct V_9 * V_10 = V_18 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_400 * V_13 = & V_2 -> V_13 ;
int V_52 = F_32 ( V_401 , V_402 ) ;
T_6 V_403 , V_404 ;
union V_405 * V_405 ;
T_4 V_99 , V_100 ;
struct V_19 * V_406 = NULL ;
int V_271 = ( V_18 -> V_271 & V_272 ) >> V_273 ;
if ( F_68 ( V_13 -> V_86 , V_52 , NULL ,
& V_99 , & V_100 , & V_403 ) ) {
V_405 =
(union V_405 * ) ( V_13 -> V_86 -> V_407 + V_403 ) ;
V_406 =
F_69 ( sizeof( struct V_19 ) , V_48 ) ;
if ( ! V_406 )
return NULL ;
V_406 -> V_408 . clock =
F_70 ( V_405 -> V_409 . V_410 . V_411 ) * 10 ;
V_406 -> V_408 . V_412 =
F_70 ( V_405 -> V_409 . V_410 . V_413 ) ;
V_406 -> V_408 . V_414 =
F_70 ( V_405 -> V_409 . V_410 . V_415 ) ;
V_406 -> V_408 . V_416 = V_406 -> V_408 . V_412 +
F_70 ( V_405 -> V_409 . V_410 . V_417 ) ;
V_406 -> V_408 . V_418 = V_406 -> V_408 . V_412 +
F_70 ( V_405 -> V_409 . V_410 . V_419 ) ;
V_406 -> V_408 . V_420 = V_406 -> V_408 . V_418 +
F_70 ( V_405 -> V_409 . V_410 . V_421 ) ;
V_406 -> V_408 . V_422 = V_406 -> V_408 . V_414 +
F_70 ( V_405 -> V_409 . V_410 . V_423 ) ;
V_406 -> V_408 . V_424 = V_406 -> V_408 . V_414 +
F_70 ( V_405 -> V_409 . V_410 . V_425 ) ;
V_406 -> V_408 . V_426 = V_406 -> V_408 . V_424 +
F_70 ( V_405 -> V_409 . V_410 . V_427 ) ;
V_406 -> V_428 =
F_70 ( V_405 -> V_409 . V_429 ) ;
V_406 -> V_430 = V_405 -> V_409 . V_431 ;
V_404 = F_70 ( V_405 -> V_409 . V_410 . V_432 . V_433 ) ;
if ( V_404 & V_434 )
V_406 -> V_408 . V_63 |= V_435 ;
if ( V_404 & V_436 )
V_406 -> V_408 . V_63 |= V_437 ;
if ( V_404 & V_438 )
V_406 -> V_408 . V_63 |= V_439 ;
if ( V_404 & V_440 )
V_406 -> V_408 . V_63 |= V_64 ;
if ( V_404 & V_441 )
V_406 -> V_408 . V_63 |= V_442 ;
V_406 -> V_408 . V_443 = F_70 ( V_405 -> V_409 . V_410 . V_444 ) ;
V_406 -> V_408 . V_445 = F_70 ( V_405 -> V_409 . V_410 . V_446 ) ;
F_26 ( & V_406 -> V_408 , V_447 ) ;
V_406 -> V_448 = V_405 -> V_409 . V_449 ;
V_18 -> V_408 = V_406 -> V_408 ;
if ( V_271 == 2 )
V_406 -> V_171 = true ;
else
V_406 -> V_171 = false ;
if ( F_70 ( V_405 -> V_409 . V_450 ) ) {
T_7 * V_451 ;
T_8 * V_452 ;
bool V_453 = false ;
T_1 * V_454 ;
if ( ( V_99 == 1 ) && ( V_100 < 2 ) )
V_454 = ( T_1 * ) ( V_13 -> V_86 -> V_407 +
F_70 ( V_405 -> V_409 . V_450 ) ) ;
else
V_454 = ( T_1 * ) ( V_13 -> V_86 -> V_407 +
V_403 +
F_70 ( V_405 -> V_409 . V_450 ) ) ;
while ( * V_454 != V_455 ) {
switch ( * V_454 ) {
case V_456 :
V_454 += sizeof( V_457 ) ;
break;
case V_458 :
V_454 += sizeof( V_459 ) ;
break;
case V_460 :
V_454 += sizeof( V_461 ) ;
break;
case V_462 :
V_451 = ( T_7 * ) V_454 ;
if ( V_451 -> V_463 ) {
struct V_464 * V_464 ;
int V_465 =
F_71 ( ( int ) V_466 , ( int ) V_451 -> V_463 ) ;
V_464 = F_13 ( V_465 , V_48 ) ;
if ( V_464 ) {
memcpy ( ( T_1 * ) V_464 , ( T_1 * ) & V_451 -> V_467 [ 0 ] ,
V_451 -> V_463 ) ;
if ( F_72 ( V_464 ) ) {
V_2 -> V_13 . V_468 = V_464 ;
V_2 -> V_13 . V_469 = V_465 ;
} else
F_19 ( V_464 ) ;
}
}
V_454 += V_451 -> V_463 ?
V_451 -> V_463 + 2 :
sizeof( T_7 ) ;
break;
case V_470 :
V_452 = ( T_8 * ) V_454 ;
V_406 -> V_408 . V_443 = V_452 -> V_471 ;
V_406 -> V_408 . V_445 = V_452 -> V_472 ;
V_454 += sizeof( T_8 ) ;
break;
default:
F_14 ( L_30 , * V_454 ) ;
V_453 = true ;
break;
}
if ( V_453 )
break;
}
}
}
return V_406 ;
}
struct V_19 *
F_73 ( struct V_8 * V_8 )
{
int V_271 = ( V_8 -> V_271 & V_272 ) >> V_273 ;
struct V_19 * V_20 = F_69 ( sizeof( struct V_19 ) , V_48 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_231 = true ;
V_20 -> V_159 = - 1 ;
if ( V_271 == 2 )
V_20 -> V_171 = true ;
else
V_20 -> V_171 = false ;
return V_20 ;
}
