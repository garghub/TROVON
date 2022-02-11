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
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return;
V_39 = F_13 ( sizeof( struct V_38 ) , V_47 ) ;
if ( ! V_39 ) {
F_14 ( L_1 ) ;
goto error;
}
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_48 = V_37 ;
V_35 . type = V_49 ;
snprintf ( V_42 , sizeof( V_42 ) ,
L_2 , V_10 -> V_50 -> V_51 ) ;
V_34 = F_15 ( V_42 , V_40 -> V_52 ,
V_39 , & V_53 , & V_35 ) ;
if ( F_16 ( V_34 ) ) {
F_14 ( L_3 ) ;
goto error;
}
V_39 -> V_18 = V_8 ;
V_3 = F_1 ( V_2 ) ;
V_20 = V_8 -> V_23 ;
V_20 -> V_54 = V_34 ;
V_34 -> V_35 . V_36 = F_11 ( V_34 ) ;
V_34 -> V_35 . V_55 = V_56 ;
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
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return;
V_20 = V_8 -> V_23 ;
V_34 = V_20 -> V_54 ;
V_20 -> V_54 = NULL ;
if ( V_34 ) {
struct V_57 * V_39 ;
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
case V_58 :
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
const struct V_59 * V_60 ,
struct V_59 * V_61 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
F_25 ( V_18 ) ;
F_26 ( V_61 , 0 ) ;
if ( ( V_60 -> V_62 & V_63 )
&& ( V_60 -> V_64 < ( V_60 -> V_65 + 2 ) ) )
V_61 -> V_64 = V_61 -> V_65 + 2 ;
if ( V_60 -> V_64 == V_60 -> V_65 )
V_61 -> V_64 ++ ;
if ( V_8 -> V_66 & ( V_22 ) )
F_27 ( V_18 , V_61 ) ;
else if ( V_8 -> V_67 != V_68 )
F_27 ( V_18 , V_61 ) ;
if ( ( V_8 -> V_66 & ( V_69 | V_22 ) ) ||
( F_28 ( V_18 ) != V_70 ) ) {
struct V_40 * V_71 = F_29 ( V_18 ) ;
F_30 ( V_71 , V_61 ) ;
}
return true ;
}
static void
F_31 ( struct V_17 * V_18 , int V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
T_3 args ;
int V_51 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_24 ) {
case V_73 :
case V_74 :
V_51 = F_32 ( V_75 , V_76 ) ;
break;
case V_77 :
case V_78 :
V_51 = F_32 ( V_75 , V_79 ) ;
break;
}
args . V_80 = V_72 ;
args . V_81 = V_82 ;
args . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
}
static T_1 F_35 ( struct V_17 * V_18 )
{
int V_87 = 8 ;
if ( V_18 -> V_88 ) {
struct V_89 * V_89 = F_36 ( V_18 -> V_88 ) ;
V_87 = V_89 -> V_87 ;
}
switch ( V_87 ) {
case 0 :
return V_90 ;
case 6 :
return V_91 ;
case 8 :
default:
return V_92 ;
case 10 :
return V_93 ;
case 12 :
return V_94 ;
case 16 :
return V_95 ;
}
}
static void
F_37 ( struct V_17 * V_18 , int V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
union V_96 args ;
int V_51 = F_32 ( V_75 , V_97 ) ;
T_4 V_98 , V_99 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_85 , V_51 , & V_98 , & V_99 ) )
return;
switch ( V_98 ) {
case 1 :
switch ( V_99 ) {
case 1 :
args . V_100 . V_101 . V_102 = V_72 ;
if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_100 . V_101 . V_103 |= V_104 ;
args . V_100 . V_101 . V_103 |= V_105 ;
break;
case 2 :
args . V_106 . V_107 . V_80 = V_72 ;
args . V_106 . V_107 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
args . V_106 . V_107 . V_108 = V_109 ;
if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_106 . V_107 . V_110 . V_111 . V_112 |= V_104 ;
break;
case 3 :
args . V_113 . V_80 = V_72 ;
args . V_113 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
args . V_113 . V_114 = 0 ;
break;
case 4 :
args . V_115 . V_80 = V_72 ;
args . V_115 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
args . V_115 . V_114 = 0 ;
args . V_115 . V_116 = F_35 ( V_18 ) ;
break;
default:
F_14 ( L_6 , V_98 , V_99 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_98 , V_99 ) ;
break;
}
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
}
int F_40 ( struct V_17 * V_18 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_40 * V_71 ;
struct V_117 * V_117 ;
struct V_118 * V_119 ;
if ( F_28 ( V_18 ) != V_70 )
return V_120 ;
if ( ( V_8 -> V_24 == V_121 ) ||
( V_8 -> V_24 == V_58 ) )
return V_122 ;
V_71 = F_29 ( V_18 ) ;
if ( ! V_71 )
V_71 = F_41 ( V_18 ) ;
V_117 = F_42 ( V_71 ) ;
switch ( V_71 -> V_123 ) {
case V_124 :
case V_125 :
if ( V_126 != 0 ) {
if ( V_117 -> V_127 &&
( V_117 -> V_128 == V_129 ) )
return V_130 ;
else if ( F_43 ( F_44 ( V_71 ) ) &&
( V_117 -> V_128 == V_131 ) )
return V_130 ;
else if ( V_117 -> V_127 )
return V_132 ;
else
return V_133 ;
} else if ( V_117 -> V_127 ) {
return V_132 ;
} else {
return V_133 ;
}
break;
case V_134 :
case V_135 :
default:
if ( V_126 != 0 ) {
if ( V_117 -> V_128 == V_129 )
return V_130 ;
else if ( F_43 ( F_44 ( V_71 ) ) &&
( V_117 -> V_128 == V_131 ) )
return V_130 ;
else
return V_132 ;
} else {
return V_132 ;
}
break;
case V_136 :
return V_137 ;
break;
case V_138 :
V_119 = V_117 -> V_139 ;
if ( ( V_119 -> V_140 == V_141 ) ||
( V_119 -> V_140 == V_142 ) ) {
return V_120 ;
} else if ( V_126 != 0 ) {
if ( V_117 -> V_128 == V_129 )
return V_130 ;
else if ( F_43 ( F_44 ( V_71 ) ) &&
( V_117 -> V_128 == V_131 ) )
return V_130 ;
else
return V_132 ;
} else {
return V_132 ;
}
break;
case V_143 :
return V_120 ;
case V_144 :
case V_145 :
return V_133 ;
break;
case V_146 :
case V_147 :
case V_148 :
return V_149 ;
break;
}
}
void
F_45 ( struct V_17 * V_18 ,
int V_72 , int V_150 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_40 * V_71 = F_29 ( V_18 ) ;
union V_151 args ;
int V_51 = F_32 ( V_75 , V_152 ) ;
T_4 V_98 , V_99 ;
int V_153 = 0 ;
int V_154 = 0 ;
int V_155 = V_156 ;
if ( V_71 ) {
struct V_117 * V_117 = F_42 ( V_71 ) ;
struct V_118 * V_119 =
V_117 -> V_139 ;
V_153 = V_119 -> V_153 ;
V_154 = V_119 -> V_154 ;
V_155 = V_117 -> V_157 . V_157 ;
}
if ( V_20 -> V_158 == - 1 )
return;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_85 , V_51 , & V_98 , & V_99 ) )
return;
switch ( V_98 ) {
case 1 :
switch ( V_99 ) {
case 1 :
args . V_159 . V_80 = V_72 ;
args . V_159 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
if ( V_72 == V_160 )
args . V_161 . V_162 = V_150 ;
else
args . V_159 . V_163 = F_40 ( V_18 ) ;
if ( F_46 ( args . V_159 . V_163 ) )
args . V_159 . V_164 = V_154 ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_159 . V_164 = 8 ;
else
args . V_159 . V_164 = 4 ;
if ( F_46 ( args . V_159 . V_163 ) && ( V_153 == 270000 ) )
args . V_159 . V_165 |= V_166 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_159 . V_165 = V_167 ;
break;
case V_27 :
case V_26 :
args . V_159 . V_165 = V_168 ;
break;
case V_28 :
args . V_159 . V_165 = V_169 ;
break;
}
if ( V_20 -> V_170 )
args . V_159 . V_165 |= V_171 ;
else
args . V_159 . V_165 |= V_172 ;
break;
case 2 :
case 3 :
args . V_161 . V_80 = V_72 ;
args . V_161 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
if ( V_72 == V_160 )
args . V_161 . V_162 = V_150 ;
else
args . V_161 . V_163 = F_40 ( V_18 ) ;
if ( F_46 ( args . V_161 . V_163 ) )
args . V_161 . V_164 = V_154 ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_161 . V_164 = 8 ;
else
args . V_161 . V_164 = 4 ;
if ( F_46 ( args . V_161 . V_163 ) && ( V_153 == 270000 ) )
args . V_159 . V_165 |= V_173 ;
args . V_161 . V_174 . V_175 = V_20 -> V_158 ;
args . V_161 . V_116 = F_35 ( V_18 ) ;
break;
case 4 :
args . V_176 . V_80 = V_72 ;
args . V_176 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
if ( V_72 == V_160 )
args . V_176 . V_162 = V_150 ;
else
args . V_176 . V_163 = F_40 ( V_18 ) ;
if ( F_46 ( args . V_176 . V_163 ) )
args . V_176 . V_164 = V_154 ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_176 . V_164 = 8 ;
else
args . V_176 . V_164 = 4 ;
if ( F_46 ( args . V_176 . V_163 ) ) {
if ( V_153 == 540000 )
args . V_159 . V_165 |= V_177 ;
else if ( V_153 == 324000 )
args . V_159 . V_165 |= V_178 ;
else if ( V_153 == 270000 )
args . V_159 . V_165 |= V_179 ;
else
args . V_159 . V_165 |= V_180 ;
}
args . V_176 . V_174 . V_175 = V_20 -> V_158 ;
args . V_176 . V_116 = F_35 ( V_18 ) ;
if ( V_155 == V_156 )
args . V_176 . V_181 = 0 ;
else
args . V_176 . V_181 = V_155 + 1 ;
break;
case 5 :
switch ( V_72 ) {
case V_160 :
args . V_182 . V_183 . V_80 = V_72 ;
args . V_182 . V_183 . V_162 = V_150 ;
args . V_182 . V_183 . V_184 = V_20 -> V_158 ;
break;
case V_185 :
args . V_182 . V_186 . V_80 = V_72 ;
args . V_182 . V_186 . V_184 = V_20 -> V_158 ;
args . V_182 . V_186 . V_187 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_182 . V_186 . V_187 ) )
args . V_182 . V_186 . V_164 = V_154 ;
else if ( F_39 ( V_18 ,
V_8 -> V_84 ) )
args . V_182 . V_186 . V_164 = 8 ;
else
args . V_182 . V_186 . V_164 = 4 ;
args . V_182 . V_186 . V_188 =
F_47 ( V_8 -> V_84 / 10 ) ;
args . V_182 . V_186 . V_116 =
F_35 ( V_18 ) ;
args . V_182 . V_186 . V_189 = V_153 / 27000 ;
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
args . V_182 . V_198 . V_80 = V_72 ;
args . V_182 . V_198 . V_184 = V_20 -> V_158 ;
break;
default:
F_14 ( L_7 , V_72 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_98 , V_99 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_98 , V_99 ) ;
break;
}
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
}
void
F_7 ( struct V_17 * V_18 , int V_72 ,
T_4 V_199 , T_4 V_200 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_40 * V_71 ;
union V_201 args ;
int V_51 = 0 ;
T_4 V_98 , V_99 ;
bool V_202 = false ;
int V_203 = 0 ;
int V_153 = 0 ;
int V_154 = 0 ;
int V_204 = 0 ;
int V_205 = 0 ;
int V_158 = V_20 -> V_158 ;
int V_155 = V_156 ;
if ( V_72 == V_206 ) {
V_71 = F_41 ( V_18 ) ;
V_158 = 0 ;
} else
V_71 = F_29 ( V_18 ) ;
if ( V_71 ) {
struct V_117 * V_117 = F_42 ( V_71 ) ;
struct V_118 * V_119 =
V_117 -> V_139 ;
V_155 = V_117 -> V_157 . V_157 ;
V_153 = V_119 -> V_153 ;
V_154 = V_119 -> V_154 ;
V_204 =
( V_117 -> V_204 & V_207 ) >> V_208 ;
}
if ( V_18 -> V_88 ) {
struct V_89 * V_89 = F_36 ( V_18 -> V_88 ) ;
V_203 = V_89 -> V_203 ;
}
if ( V_158 == - 1 )
return;
if ( F_46 ( F_40 ( V_18 ) ) )
V_202 = true ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_24 ) {
case V_58 :
V_51 = F_32 ( V_75 , V_209 ) ;
break;
case V_25 :
case V_27 :
case V_28 :
case V_29 :
V_51 = F_32 ( V_75 , V_210 ) ;
break;
case V_26 :
V_51 = F_32 ( V_75 , V_211 ) ;
break;
}
if ( ! F_38 ( V_2 -> V_13 . V_85 , V_51 , & V_98 , & V_99 ) )
return;
switch ( V_98 ) {
case 1 :
switch ( V_99 ) {
case 1 :
args . V_159 . V_80 = V_72 ;
if ( V_72 == V_206 ) {
args . V_159 . V_212 = F_33 ( V_204 ) ;
} else if ( V_72 == V_213 ) {
args . V_159 . V_214 . V_215 = V_199 ;
args . V_159 . V_214 . V_216 = V_200 ;
} else {
if ( V_202 )
args . V_159 . V_83 = F_33 ( V_153 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_159 . V_83 = F_33 ( ( V_8 -> V_84 / 2 ) / 10 ) ;
else
args . V_159 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
}
args . V_159 . V_165 = V_217 ;
if ( V_158 )
args . V_159 . V_165 |= V_218 ;
else
args . V_159 . V_165 |= V_219 ;
if ( ( V_2 -> V_62 & V_220 ) &&
( V_8 -> V_24 == V_25 ) ) {
if ( V_202 ||
! F_39 ( V_18 , V_8 -> V_84 ) ) {
if ( V_205 & 0x1 )
args . V_159 . V_165 |= V_221 ;
else if ( V_205 & 0x2 )
args . V_159 . V_165 |= V_222 ;
else if ( V_205 & 0x4 )
args . V_159 . V_165 |= V_223 ;
else if ( V_205 & 0x8 )
args . V_159 . V_165 |= V_224 ;
} else {
if ( V_205 & 0x3 )
args . V_159 . V_165 |= V_225 ;
else if ( V_205 & 0xc )
args . V_159 . V_165 |= V_226 ;
}
}
if ( V_20 -> V_170 )
args . V_159 . V_165 |= V_227 ;
else
args . V_159 . V_165 |= V_228 ;
if ( V_202 )
args . V_159 . V_165 |= V_229 ;
else if ( V_8 -> V_21 & ( V_69 ) ) {
if ( V_20 -> V_230 )
args . V_159 . V_165 |= V_229 ;
if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_159 . V_165 |= V_231 ;
}
break;
case 2 :
args . V_232 . V_80 = V_72 ;
if ( V_72 == V_206 ) {
args . V_232 . V_212 = F_33 ( V_204 ) ;
} else if ( V_72 == V_213 ) {
args . V_232 . V_214 . V_215 = V_199 ;
args . V_232 . V_214 . V_216 = V_200 ;
} else {
if ( V_202 )
args . V_232 . V_83 = F_33 ( V_153 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_232 . V_83 = F_33 ( ( V_8 -> V_84 / 2 ) / 10 ) ;
else
args . V_232 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
}
args . V_232 . V_174 . V_233 = V_158 ;
if ( V_20 -> V_170 )
args . V_232 . V_174 . V_234 = 1 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_232 . V_174 . V_235 = 0 ;
break;
case V_27 :
args . V_232 . V_174 . V_235 = 1 ;
break;
case V_28 :
args . V_232 . V_174 . V_235 = 2 ;
break;
}
if ( V_202 ) {
args . V_232 . V_174 . V_236 = 1 ;
args . V_232 . V_174 . V_237 = 1 ;
} else if ( V_8 -> V_21 & ( V_69 ) ) {
if ( V_20 -> V_230 )
args . V_232 . V_174 . V_236 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_232 . V_174 . V_238 = 1 ;
}
break;
case 3 :
args . V_161 . V_80 = V_72 ;
if ( V_72 == V_206 ) {
args . V_161 . V_212 = F_33 ( V_204 ) ;
} else if ( V_72 == V_213 ) {
args . V_161 . V_214 . V_215 = V_199 ;
args . V_161 . V_214 . V_216 = V_200 ;
} else {
if ( V_202 )
args . V_161 . V_83 = F_33 ( V_153 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_161 . V_83 = F_33 ( ( V_8 -> V_84 / 2 ) / 10 ) ;
else
args . V_161 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
}
if ( V_202 )
args . V_161 . V_164 = V_154 ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_161 . V_164 = 8 ;
else
args . V_161 . V_164 = 4 ;
if ( V_20 -> V_170 )
args . V_161 . V_174 . V_234 = 1 ;
if ( V_158 & 1 )
args . V_161 . V_174 . V_233 = 1 ;
if ( V_202 && V_2 -> clock . V_239 )
args . V_161 . V_174 . V_240 = 2 ;
else
args . V_161 . V_174 . V_240 = V_203 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_161 . V_174 . V_235 = 0 ;
break;
case V_27 :
args . V_161 . V_174 . V_235 = 1 ;
break;
case V_28 :
args . V_161 . V_174 . V_235 = 2 ;
break;
}
if ( V_202 )
args . V_161 . V_174 . V_236 = 1 ;
else if ( V_8 -> V_21 & ( V_69 ) ) {
if ( V_20 -> V_230 )
args . V_161 . V_174 . V_236 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_161 . V_174 . V_238 = 1 ;
}
break;
case 4 :
args . V_176 . V_80 = V_72 ;
if ( V_72 == V_206 ) {
args . V_176 . V_212 = F_33 ( V_204 ) ;
} else if ( V_72 == V_213 ) {
args . V_176 . V_214 . V_215 = V_199 ;
args . V_176 . V_214 . V_216 = V_200 ;
} else {
if ( V_202 )
args . V_176 . V_83 = F_33 ( V_153 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_176 . V_83 = F_33 ( ( V_8 -> V_84 / 2 ) / 10 ) ;
else
args . V_176 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
}
if ( V_202 )
args . V_176 . V_164 = V_154 ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_176 . V_164 = 8 ;
else
args . V_176 . V_164 = 4 ;
if ( V_20 -> V_170 )
args . V_176 . V_174 . V_234 = 1 ;
if ( V_158 & 1 )
args . V_176 . V_174 . V_233 = 1 ;
if ( V_202 ) {
if ( V_2 -> clock . V_239 )
args . V_176 . V_174 . V_240 = V_241 ;
else
args . V_176 . V_174 . V_240 = V_242 ;
} else
args . V_176 . V_174 . V_240 = V_203 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_176 . V_174 . V_235 = 0 ;
break;
case V_27 :
args . V_176 . V_174 . V_235 = 1 ;
break;
case V_28 :
args . V_176 . V_174 . V_235 = 2 ;
break;
}
if ( V_202 )
args . V_176 . V_174 . V_236 = 1 ;
else if ( V_8 -> V_21 & ( V_69 ) ) {
if ( V_20 -> V_230 )
args . V_176 . V_174 . V_236 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_176 . V_174 . V_238 = 1 ;
}
break;
case 5 :
args . V_182 . V_80 = V_72 ;
if ( V_202 )
args . V_182 . V_243 = F_33 ( V_153 / 10 ) ;
else
args . V_182 . V_243 = F_33 ( V_8 -> V_84 / 10 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
if ( V_20 -> V_170 )
args . V_182 . V_244 = V_245 ;
else
args . V_182 . V_244 = V_246 ;
break;
case V_27 :
if ( V_20 -> V_170 )
args . V_182 . V_244 = V_247 ;
else
args . V_182 . V_244 = V_248 ;
break;
case V_28 :
if ( V_20 -> V_170 )
args . V_182 . V_244 = V_249 ;
else
args . V_182 . V_244 = V_250 ;
break;
case V_29 :
args . V_182 . V_244 = V_251 ;
break;
}
if ( V_202 )
args . V_182 . V_164 = V_154 ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_182 . V_164 = 8 ;
else
args . V_182 . V_164 = 4 ;
args . V_182 . V_252 = V_204 ;
args . V_182 . V_187 = F_40 ( V_18 ) ;
if ( V_202 && V_2 -> clock . V_239 )
args . V_182 . V_253 . V_254 = V_241 ;
else
args . V_182 . V_253 . V_254 = V_203 ;
if ( V_202 )
args . V_182 . V_253 . V_255 = 1 ;
else if ( V_8 -> V_21 & ( V_69 ) ) {
if ( V_20 -> V_230 )
args . V_182 . V_253 . V_255 = 1 ;
}
if ( V_155 == V_156 )
args . V_182 . V_253 . V_256 = 0 ;
else
args . V_182 . V_253 . V_256 = V_155 + 1 ;
args . V_182 . V_257 = 1 << V_158 ;
args . V_182 . V_258 = V_200 ;
break;
case 6 :
args . V_259 . V_80 = V_72 ;
if ( V_202 )
args . V_259 . V_260 = F_47 ( V_153 / 10 ) ;
else
args . V_259 . V_260 = F_47 ( V_8 -> V_84 / 10 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
if ( V_20 -> V_170 )
args . V_259 . V_244 = V_245 ;
else
args . V_259 . V_244 = V_246 ;
break;
case V_27 :
if ( V_20 -> V_170 )
args . V_259 . V_244 = V_247 ;
else
args . V_259 . V_244 = V_248 ;
break;
case V_28 :
if ( V_20 -> V_170 )
args . V_259 . V_244 = V_249 ;
else
args . V_259 . V_244 = V_250 ;
break;
case V_29 :
args . V_259 . V_244 = V_251 ;
break;
}
if ( V_202 )
args . V_259 . V_164 = V_154 ;
else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_259 . V_164 = 8 ;
else
args . V_259 . V_164 = 4 ;
args . V_259 . V_252 = V_204 ;
if ( V_72 == V_213 )
args . V_259 . V_258 = V_200 ;
else
args . V_259 . V_187 = F_40 ( V_18 ) ;
if ( V_155 == V_156 )
args . V_259 . V_256 = 0 ;
else
args . V_259 . V_256 = V_155 + 1 ;
args . V_259 . V_257 = 1 << V_158 ;
break;
default:
F_14 ( L_6 , V_98 , V_99 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_98 , V_99 ) ;
break;
}
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
}
bool
F_48 ( struct V_40 * V_71 ,
int V_72 )
{
struct V_117 * V_117 = F_42 ( V_71 ) ;
struct V_9 * V_10 = V_117 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
union V_201 args ;
int V_51 = F_32 ( V_75 , V_210 ) ;
T_4 V_98 , V_99 ;
if ( V_71 -> V_123 != V_143 )
goto V_261;
if ( ( V_72 != V_262 ) &&
( V_72 != V_263 ) )
goto V_261;
if ( ! F_38 ( V_2 -> V_13 . V_85 , V_51 , & V_98 , & V_99 ) )
goto V_261;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_159 . V_80 = V_72 ;
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
if ( V_72 == V_262 ) {
int V_264 ;
for ( V_264 = 0 ; V_264 < 300 ; V_264 ++ ) {
if ( F_49 ( V_2 , V_117 -> V_157 . V_157 ) )
return true ;
F_50 ( 1 ) ;
}
return false ;
}
V_261:
return true ;
}
static void
F_51 ( struct V_17 * V_18 ,
struct V_17 * V_265 ,
int V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_8 * V_266 = F_23 ( V_265 ) ;
union V_267 args ;
struct V_40 * V_71 ;
int V_51 = F_32 ( V_75 , V_268 ) ;
T_1 V_98 , V_99 ;
int V_153 = 0 ;
int V_154 = 0 ;
int V_204 = 0 ;
T_2 V_269 = ( V_266 -> V_270 & V_271 ) >> V_272 ;
if ( V_72 == V_273 )
V_71 = F_41 ( V_18 ) ;
else
V_71 = F_29 ( V_18 ) ;
if ( V_71 ) {
struct V_117 * V_117 = F_42 ( V_71 ) ;
struct V_118 * V_119 =
V_117 -> V_139 ;
V_153 = V_119 -> V_153 ;
V_154 = V_119 -> V_154 ;
V_204 =
( V_117 -> V_204 & V_207 ) >> V_208 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_85 , V_51 , & V_98 , & V_99 ) )
return;
switch ( V_98 ) {
case 1 :
break;
case 2 :
switch ( V_99 ) {
case 1 :
case 2 :
args . V_159 . V_274 . V_80 = V_72 ;
args . V_159 . V_274 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
args . V_159 . V_274 . V_163 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_159 . V_274 . V_163 ) ) {
if ( V_153 == 270000 )
args . V_159 . V_274 . V_165 |= V_166 ;
args . V_159 . V_274 . V_164 = V_154 ;
} else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_159 . V_274 . V_164 = 8 ;
else
args . V_159 . V_274 . V_164 = 4 ;
break;
case 3 :
args . V_161 . V_275 . V_80 = V_72 ;
if ( V_72 == V_273 )
args . V_161 . V_275 . V_276 = F_33 ( V_204 ) ;
else
args . V_161 . V_275 . V_83 = F_33 ( V_8 -> V_84 / 10 ) ;
args . V_161 . V_275 . V_163 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_161 . V_275 . V_163 ) ) {
if ( V_153 == 270000 )
args . V_161 . V_275 . V_165 |= V_277 ;
else if ( V_153 == 540000 )
args . V_161 . V_275 . V_165 |= V_278 ;
args . V_161 . V_275 . V_164 = V_154 ;
} else if ( F_39 ( V_18 , V_8 -> V_84 ) )
args . V_161 . V_275 . V_164 = 8 ;
else
args . V_161 . V_275 . V_164 = 4 ;
switch ( V_269 ) {
case V_279 :
args . V_161 . V_275 . V_165 |= V_280 ;
break;
case V_281 :
args . V_161 . V_275 . V_165 |= V_282 ;
break;
case V_283 :
args . V_161 . V_275 . V_165 |= V_284 ;
break;
}
args . V_161 . V_275 . V_116 = F_35 ( V_18 ) ;
break;
default:
F_14 ( L_8 , V_98 , V_99 ) ;
return;
}
break;
default:
F_14 ( L_8 , V_98 , V_99 ) ;
return;
}
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
}
static void
F_52 ( struct V_17 * V_18 , int V_72 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_17 * V_265 = F_53 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_40 * V_71 = F_29 ( V_18 ) ;
struct V_117 * V_117 = NULL ;
struct V_118 * V_285 = NULL ;
if ( V_71 ) {
V_117 = F_42 ( V_71 ) ;
V_285 = V_117 -> V_139 ;
}
if ( V_72 == V_286 ) {
if ( ! V_71 )
V_20 -> V_150 = V_287 ;
else
V_20 -> V_150 = F_54 ( V_18 , V_71 ) ;
F_45 ( V_18 , V_288 , 0 ) ;
F_45 ( V_18 ,
V_160 ,
V_20 -> V_150 ) ;
if ( V_265 )
F_51 ( V_18 , V_265 ,
V_289 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_71 ) {
if ( V_71 -> V_123 == V_143 ) {
F_48 ( V_71 ,
V_262 ) ;
V_285 -> V_290 = true ;
}
}
F_7 ( V_18 ,
V_291 ,
0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_71 ) {
F_55 ( V_18 , V_71 ) ;
F_45 ( V_18 , V_197 , 0 ) ;
}
if ( V_8 -> V_21 & ( V_22 ) )
F_6 ( V_8 , V_20 -> V_3 ) ;
if ( V_265 )
F_51 ( V_18 , V_265 , V_286 ) ;
} else {
if ( F_46 ( F_40 ( V_18 ) ) &&
V_71 )
F_45 ( V_18 ,
V_196 , 0 ) ;
if ( V_265 )
F_51 ( V_18 , V_265 , V_292 ) ;
if ( V_8 -> V_21 & ( V_22 ) )
F_7 ( V_18 ,
V_30 , 0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_71 )
F_56 ( V_71 , V_293 ) ;
F_7 ( V_18 ,
V_294 , 0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_71 ) {
if ( V_71 -> V_123 == V_143 ) {
F_48 ( V_71 ,
V_263 ) ;
V_285 -> V_290 = false ;
}
}
}
}
void
F_57 ( struct V_17 * V_18 , int V_60 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
F_58 ( L_9 ,
V_8 -> V_24 , V_60 , V_8 -> V_21 ,
V_8 -> V_66 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
switch ( V_60 ) {
case V_295 :
F_52 ( V_18 , V_286 ) ;
break;
case V_296 :
case V_297 :
case V_298 :
F_52 ( V_18 , V_292 ) ;
break;
}
break;
case V_58 :
switch ( V_60 ) {
case V_295 :
F_37 ( V_18 , V_286 ) ;
break;
case V_296 :
case V_297 :
case V_298 :
F_37 ( V_18 , V_292 ) ;
break;
}
break;
case V_74 :
switch ( V_60 ) {
case V_295 :
F_31 ( V_18 , V_286 ) ;
break;
case V_296 :
case V_297 :
case V_298 :
F_31 ( V_18 , V_292 ) ;
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
struct V_89 * V_89 = F_36 ( V_18 -> V_88 ) ;
union V_299 args ;
int V_51 = F_32 ( V_75 , V_300 ) ;
T_4 V_98 , V_99 ;
struct V_19 * V_20 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_85 , V_51 , & V_98 , & V_99 ) )
return;
switch ( V_98 ) {
case 1 :
switch ( V_99 ) {
case 1 :
default:
args . V_159 . V_301 = V_89 -> V_302 ;
switch ( V_8 -> V_24 ) {
case V_303 :
case V_304 :
args . V_159 . V_305 = V_109 ;
break;
case V_306 :
case V_307 :
if ( V_8 -> V_21 & V_308 )
args . V_159 . V_305 = V_309 ;
else
args . V_159 . V_305 = V_310 ;
break;
case V_121 :
case V_311 :
case V_58 :
args . V_159 . V_305 = V_312 ;
break;
case V_73 :
case V_74 :
if ( V_8 -> V_66 & ( V_313 ) )
args . V_159 . V_305 = V_314 ;
else if ( V_8 -> V_66 & ( V_315 ) )
args . V_159 . V_305 = V_316 ;
else
args . V_159 . V_305 = V_317 ;
break;
case V_77 :
case V_78 :
if ( V_8 -> V_66 & ( V_313 ) )
args . V_159 . V_305 = V_314 ;
else if ( V_8 -> V_66 & ( V_315 ) )
args . V_159 . V_305 = V_316 ;
else
args . V_159 . V_305 = V_318 ;
break;
}
break;
case 2 :
args . V_232 . V_301 = V_89 -> V_302 ;
if ( F_28 ( V_18 ) != V_70 ) {
struct V_40 * V_71 = F_29 ( V_18 ) ;
if ( V_71 -> V_123 == V_136 )
args . V_232 . V_319 = V_137 ;
else if ( V_71 -> V_123 == V_145 )
args . V_232 . V_319 = V_133 ;
else
args . V_232 . V_319 = F_40 ( V_18 ) ;
} else if ( V_8 -> V_21 & ( V_22 ) ) {
args . V_232 . V_319 = V_137 ;
} else {
args . V_232 . V_319 = F_40 ( V_18 ) ;
}
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
case V_26 :
V_20 = V_8 -> V_23 ;
switch ( V_20 -> V_158 ) {
case 0 :
args . V_232 . V_320 = V_321 ;
break;
case 1 :
args . V_232 . V_320 = V_322 ;
break;
case 2 :
args . V_232 . V_320 = V_323 ;
break;
case 3 :
args . V_232 . V_320 = V_324 ;
break;
case 4 :
args . V_232 . V_320 = V_325 ;
break;
case 5 :
args . V_232 . V_320 = V_326 ;
break;
case 6 :
args . V_232 . V_320 = V_327 ;
break;
}
break;
case V_58 :
args . V_232 . V_320 = V_328 ;
break;
case V_74 :
if ( V_8 -> V_66 & ( V_313 ) )
args . V_232 . V_320 = V_329 ;
else if ( V_8 -> V_66 & ( V_315 ) )
args . V_232 . V_320 = V_329 ;
else
args . V_232 . V_320 = V_330 ;
break;
case V_78 :
if ( V_8 -> V_66 & ( V_313 ) )
args . V_232 . V_320 = V_329 ;
else if ( V_8 -> V_66 & ( V_315 ) )
args . V_232 . V_320 = V_329 ;
else
args . V_232 . V_320 = V_331 ;
break;
}
break;
case 3 :
args . V_161 . V_301 = V_89 -> V_302 ;
if ( F_28 ( V_18 ) != V_70 ) {
struct V_40 * V_71 = F_29 ( V_18 ) ;
if ( V_71 -> V_123 == V_136 )
args . V_232 . V_319 = V_137 ;
else if ( V_71 -> V_123 == V_145 )
args . V_232 . V_319 = V_133 ;
else
args . V_232 . V_319 = F_40 ( V_18 ) ;
} else if ( V_8 -> V_21 & ( V_22 ) ) {
args . V_232 . V_319 = V_137 ;
} else {
args . V_232 . V_319 = F_40 ( V_18 ) ;
}
args . V_161 . V_332 = F_35 ( V_18 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
case V_26 :
V_20 = V_8 -> V_23 ;
switch ( V_20 -> V_158 ) {
case 0 :
args . V_161 . V_320 = V_321 ;
break;
case 1 :
args . V_161 . V_320 = V_322 ;
break;
case 2 :
args . V_161 . V_320 = V_323 ;
break;
case 3 :
args . V_161 . V_320 = V_324 ;
break;
case 4 :
args . V_161 . V_320 = V_325 ;
break;
case 5 :
args . V_161 . V_320 = V_326 ;
break;
case 6 :
args . V_161 . V_320 = V_327 ;
break;
}
break;
case V_58 :
args . V_161 . V_320 = V_328 ;
break;
case V_74 :
if ( V_8 -> V_66 & ( V_313 ) )
args . V_161 . V_320 = V_329 ;
else if ( V_8 -> V_66 & ( V_315 ) )
args . V_161 . V_320 = V_329 ;
else
args . V_161 . V_320 = V_330 ;
break;
case V_78 :
if ( V_8 -> V_66 & ( V_313 ) )
args . V_161 . V_320 = V_329 ;
else if ( V_8 -> V_66 & ( V_315 ) )
args . V_161 . V_320 = V_329 ;
else
args . V_161 . V_320 = V_331 ;
break;
}
break;
}
break;
default:
F_14 ( L_8 , V_98 , V_99 ) ;
return;
}
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
}
void
F_60 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_333 ;
struct V_17 * V_18 ;
F_61 (encoder, &dev->mode_config.encoder_list, head) {
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_17 * V_265 = F_53 ( V_18 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_29 :
F_7 ( V_18 , V_206 ,
0 , 0 ) ;
break;
}
if ( V_265 )
F_51 ( V_18 , V_265 ,
V_273 ) ;
}
}
static bool
F_62 ( struct V_17 * V_18 ,
struct V_40 * V_71 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_117 * V_117 = F_42 ( V_71 ) ;
if ( V_8 -> V_21 & ( V_313 |
V_315 |
V_334 ) ) {
T_5 args ;
int V_51 = F_32 ( V_75 , V_335 ) ;
T_4 V_98 , V_99 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_85 , V_51 , & V_98 , & V_99 ) )
return false ;
args . V_336 . V_103 = 0 ;
if ( ( V_8 -> V_24 == V_73 ) ||
( V_8 -> V_24 == V_74 ) )
args . V_336 . V_337 = V_338 ;
else
args . V_336 . V_337 = V_339 ;
if ( V_117 -> V_21 & V_340 )
args . V_336 . V_341 = F_33 ( V_340 ) ;
else if ( V_117 -> V_21 & V_342 )
args . V_336 . V_341 = F_33 ( V_342 ) ;
else if ( V_117 -> V_21 & V_315 ) {
args . V_336 . V_341 = F_33 ( V_315 ) ;
if ( V_99 >= 3 )
args . V_336 . V_103 = V_343 ;
} else if ( V_117 -> V_21 & V_344 ) {
args . V_336 . V_341 = F_33 ( V_344 ) ;
if ( V_99 >= 3 )
args . V_336 . V_103 = V_343 ;
}
F_34 ( V_2 -> V_13 . V_85 , V_51 , ( V_86 * ) & args ) ;
return true ;
} else
return false ;
}
enum V_345
F_63 ( struct V_17 * V_18 ,
struct V_40 * V_71 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_117 * V_117 = F_42 ( V_71 ) ;
V_86 V_346 ;
if ( ! F_62 ( V_18 , V_71 ) ) {
F_58 ( L_10 ) ;
return V_347 ;
}
V_346 = F_2 ( V_348 ) ;
F_58 ( L_11 , V_346 , V_8 -> V_21 ) ;
if ( V_117 -> V_21 & V_340 ) {
if ( V_346 & V_349 )
return V_350 ;
}
if ( V_117 -> V_21 & V_342 ) {
if ( V_346 & V_351 )
return V_350 ;
}
if ( V_117 -> V_21 & V_315 ) {
if ( V_346 & ( V_352 | V_353 ) )
return V_350 ;
}
if ( V_117 -> V_21 & V_344 ) {
if ( V_346 & ( V_354 | V_355 ) )
return V_350 ;
else if ( V_346 & ( V_356 | V_357 ) )
return V_350 ;
}
return V_358 ;
}
enum V_345
F_64 ( struct V_17 * V_18 ,
struct V_40 * V_71 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_117 * V_117 = F_42 ( V_71 ) ;
struct V_17 * V_265 = F_53 ( V_18 ) ;
T_2 V_346 ;
if ( ! V_265 )
return V_347 ;
if ( ( V_117 -> V_21 & V_334 ) == 0 )
return V_347 ;
F_51 ( V_18 , V_265 ,
V_359 ) ;
V_346 = F_2 ( V_348 ) ;
F_58 ( L_11 , V_346 , V_8 -> V_21 ) ;
if ( V_117 -> V_21 & V_340 ) {
if ( V_346 & V_349 )
return V_350 ;
}
if ( V_117 -> V_21 & V_342 ) {
if ( V_346 & V_351 )
return V_350 ;
}
if ( V_117 -> V_21 & V_315 ) {
if ( V_346 & ( V_352 | V_353 ) )
return V_350 ;
}
if ( V_117 -> V_21 & V_344 ) {
if ( V_346 & ( V_354 | V_355 ) )
return V_350 ;
else if ( V_346 & ( V_356 | V_357 ) )
return V_350 ;
}
return V_358 ;
}
void
F_65 ( struct V_17 * V_18 )
{
struct V_17 * V_265 = F_53 ( V_18 ) ;
if ( V_265 )
F_51 ( V_18 , V_265 ,
V_360 ) ;
}
void
F_66 ( struct V_40 * V_71 ,
struct V_17 * V_18 ,
bool V_361 )
{
struct V_9 * V_10 = V_71 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_117 * V_117 =
F_42 ( V_71 ) ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
V_86 V_346 , V_362 , V_363 ;
V_346 = F_2 ( V_348 ) ;
V_362 = F_2 ( V_364 ) ;
V_363 = F_2 ( V_365 ) ;
if ( ( V_8 -> V_21 & V_308 ) &&
( V_117 -> V_21 & V_308 ) ) {
if ( V_361 ) {
F_58 ( L_12 ) ;
V_346 |= V_366 ;
V_362 |= V_367 ;
V_363 |= V_368 ;
} else {
F_58 ( L_13 ) ;
V_346 &= ~ V_366 ;
V_362 &= ~ V_367 ;
V_363 &= ~ V_368 ;
}
}
if ( ( V_8 -> V_21 & V_340 ) &&
( V_117 -> V_21 & V_340 ) ) {
if ( V_361 ) {
F_58 ( L_14 ) ;
V_346 |= V_369 ;
V_362 |= V_370 ;
V_363 |= V_371 ;
} else {
F_58 ( L_15 ) ;
V_346 &= ~ V_349 ;
V_362 &= ~ V_370 ;
V_363 &= ~ V_371 ;
}
}
if ( ( V_8 -> V_21 & V_342 ) &&
( V_117 -> V_21 & V_342 ) ) {
if ( V_361 ) {
F_58 ( L_16 ) ;
V_346 |= V_372 ;
V_362 |= V_373 ;
V_363 |= V_374 ;
} else {
F_58 ( L_17 ) ;
V_346 &= ~ V_351 ;
V_362 &= ~ V_373 ;
V_363 &= ~ V_374 ;
}
}
if ( ( V_8 -> V_21 & V_375 ) &&
( V_117 -> V_21 & V_375 ) ) {
if ( V_361 ) {
F_58 ( L_18 ) ;
V_346 |= V_376 ;
V_362 |= V_377 ;
V_363 |= V_378 ;
} else {
F_58 ( L_19 ) ;
V_346 &= ~ V_376 ;
V_362 &= ~ V_377 ;
V_363 &= ~ V_378 ;
}
}
if ( ( V_8 -> V_21 & V_379 ) &&
( V_117 -> V_21 & V_379 ) ) {
if ( V_361 ) {
F_58 ( L_20 ) ;
V_346 |= V_380 ;
V_362 |= V_381 ;
V_363 |= V_382 ;
} else {
F_58 ( L_21 ) ;
V_346 &= ~ V_380 ;
V_362 &= ~ V_381 ;
V_363 &= ~ V_382 ;
}
}
if ( ( V_8 -> V_21 & V_383 ) &&
( V_117 -> V_21 & V_383 ) ) {
if ( V_361 ) {
F_58 ( L_22 ) ;
V_346 |= V_384 ;
V_362 |= V_385 ;
V_363 |= V_386 ;
} else {
F_58 ( L_23 ) ;
V_346 &= ~ V_384 ;
V_362 &= ~ V_385 ;
V_363 &= ~ V_386 ;
}
}
if ( ( V_8 -> V_21 & V_387 ) &&
( V_117 -> V_21 & V_387 ) ) {
if ( V_361 ) {
F_58 ( L_24 ) ;
V_346 |= V_388 ;
V_362 |= V_389 ;
V_363 |= V_390 ;
} else {
F_58 ( L_25 ) ;
V_346 &= ~ V_388 ;
V_362 &= ~ V_389 ;
V_363 &= ~ V_390 ;
}
}
if ( ( V_8 -> V_21 & V_391 ) &&
( V_117 -> V_21 & V_391 ) ) {
if ( V_361 ) {
F_58 ( L_26 ) ;
V_346 |= V_392 ;
V_362 |= V_393 ;
V_363 |= V_394 ;
} else {
F_58 ( L_27 ) ;
V_346 &= ~ V_392 ;
V_362 &= ~ V_393 ;
V_363 &= ~ V_394 ;
}
}
if ( ( V_8 -> V_21 & V_395 ) &&
( V_117 -> V_21 & V_395 ) ) {
if ( V_361 ) {
F_58 ( L_28 ) ;
V_346 |= V_396 ;
V_362 |= V_397 ;
V_363 |= V_398 ;
} else {
F_58 ( L_29 ) ;
V_346 &= ~ V_396 ;
V_362 &= ~ V_397 ;
V_363 &= ~ V_398 ;
}
}
F_4 ( V_348 , V_346 ) ;
F_4 ( V_364 , V_362 ) ;
F_4 ( V_365 , V_363 ) ;
}
struct V_19 *
F_67 ( struct V_8 * V_18 )
{
struct V_9 * V_10 = V_18 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_399 * V_13 = & V_2 -> V_13 ;
int V_51 = F_32 ( V_400 , V_401 ) ;
T_6 V_402 , V_403 ;
union V_404 * V_404 ;
T_4 V_98 , V_99 ;
struct V_19 * V_405 = NULL ;
int V_270 = ( V_18 -> V_270 & V_271 ) >> V_272 ;
if ( F_68 ( V_13 -> V_85 , V_51 , NULL ,
& V_98 , & V_99 , & V_402 ) ) {
V_404 =
(union V_404 * ) ( V_13 -> V_85 -> V_406 + V_402 ) ;
V_405 =
F_69 ( sizeof( struct V_19 ) , V_47 ) ;
if ( ! V_405 )
return NULL ;
V_405 -> V_407 . clock =
F_70 ( V_404 -> V_408 . V_409 . V_410 ) * 10 ;
V_405 -> V_407 . V_411 =
F_70 ( V_404 -> V_408 . V_409 . V_412 ) ;
V_405 -> V_407 . V_413 =
F_70 ( V_404 -> V_408 . V_409 . V_414 ) ;
V_405 -> V_407 . V_415 = V_405 -> V_407 . V_411 +
F_70 ( V_404 -> V_408 . V_409 . V_416 ) ;
V_405 -> V_407 . V_417 = V_405 -> V_407 . V_411 +
F_70 ( V_404 -> V_408 . V_409 . V_418 ) ;
V_405 -> V_407 . V_419 = V_405 -> V_407 . V_417 +
F_70 ( V_404 -> V_408 . V_409 . V_420 ) ;
V_405 -> V_407 . V_421 = V_405 -> V_407 . V_413 +
F_70 ( V_404 -> V_408 . V_409 . V_422 ) ;
V_405 -> V_407 . V_423 = V_405 -> V_407 . V_413 +
F_70 ( V_404 -> V_408 . V_409 . V_424 ) ;
V_405 -> V_407 . V_425 = V_405 -> V_407 . V_423 +
F_70 ( V_404 -> V_408 . V_409 . V_426 ) ;
V_405 -> V_427 =
F_70 ( V_404 -> V_408 . V_428 ) ;
V_405 -> V_429 = V_404 -> V_408 . V_430 ;
V_403 = F_70 ( V_404 -> V_408 . V_409 . V_431 . V_432 ) ;
if ( V_403 & V_433 )
V_405 -> V_407 . V_62 |= V_434 ;
if ( V_403 & V_435 )
V_405 -> V_407 . V_62 |= V_436 ;
if ( V_403 & V_437 )
V_405 -> V_407 . V_62 |= V_438 ;
if ( V_403 & V_439 )
V_405 -> V_407 . V_62 |= V_63 ;
if ( V_403 & V_440 )
V_405 -> V_407 . V_62 |= V_441 ;
V_405 -> V_407 . V_442 = F_70 ( V_404 -> V_408 . V_409 . V_443 ) ;
V_405 -> V_407 . V_444 = F_70 ( V_404 -> V_408 . V_409 . V_445 ) ;
F_26 ( & V_405 -> V_407 , V_446 ) ;
V_405 -> V_447 = V_404 -> V_408 . V_448 ;
V_18 -> V_407 = V_405 -> V_407 ;
if ( V_270 == 2 )
V_405 -> V_170 = true ;
else
V_405 -> V_170 = false ;
if ( F_70 ( V_404 -> V_408 . V_449 ) ) {
T_7 * V_450 ;
T_8 * V_451 ;
bool V_452 = false ;
T_1 * V_453 ;
if ( ( V_98 == 1 ) && ( V_99 < 2 ) )
V_453 = ( T_1 * ) ( V_13 -> V_85 -> V_406 +
F_70 ( V_404 -> V_408 . V_449 ) ) ;
else
V_453 = ( T_1 * ) ( V_13 -> V_85 -> V_406 +
V_402 +
F_70 ( V_404 -> V_408 . V_449 ) ) ;
while ( * V_453 != V_454 ) {
switch ( * V_453 ) {
case V_455 :
V_453 += sizeof( V_456 ) ;
break;
case V_457 :
V_453 += sizeof( V_458 ) ;
break;
case V_459 :
V_453 += sizeof( V_460 ) ;
break;
case V_461 :
V_450 = ( T_7 * ) V_453 ;
if ( V_450 -> V_462 ) {
struct V_463 * V_463 ;
int V_464 =
F_71 ( ( int ) V_465 , ( int ) V_450 -> V_462 ) ;
V_463 = F_13 ( V_464 , V_47 ) ;
if ( V_463 ) {
memcpy ( ( T_1 * ) V_463 , ( T_1 * ) & V_450 -> V_466 [ 0 ] ,
V_450 -> V_462 ) ;
if ( F_72 ( V_463 ) ) {
V_2 -> V_13 . V_467 = V_463 ;
V_2 -> V_13 . V_468 = V_464 ;
} else
F_19 ( V_463 ) ;
}
}
V_453 += V_450 -> V_462 ?
V_450 -> V_462 + 2 :
sizeof( T_7 ) ;
break;
case V_469 :
V_451 = ( T_8 * ) V_453 ;
V_405 -> V_407 . V_442 = V_451 -> V_470 ;
V_405 -> V_407 . V_444 = V_451 -> V_471 ;
V_453 += sizeof( T_8 ) ;
break;
default:
F_14 ( L_30 , * V_453 ) ;
V_452 = true ;
break;
}
if ( V_452 )
break;
}
}
}
return V_405 ;
}
struct V_19 *
F_73 ( struct V_8 * V_8 )
{
int V_270 = ( V_8 -> V_270 & V_271 ) >> V_272 ;
struct V_19 * V_20 = F_69 ( sizeof( struct V_19 ) , V_47 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_230 = true ;
V_20 -> V_158 = - 1 ;
if ( V_270 == 2 )
V_20 -> V_170 = true ;
else
V_20 -> V_170 = false ;
return V_20 ;
}
