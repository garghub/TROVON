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
if ( V_20 -> V_3 == 0 )
F_7 ( V_18 ,
V_29 , 0 , 0 ) ;
else {
F_7 ( V_18 ,
V_30 , 0 , 0 ) ;
F_7 ( V_18 ,
V_31 , 0 , 0 ) ;
}
break;
default:
break;
}
}
}
static T_1 F_8 ( struct V_32 * V_33 )
{
T_1 V_16 ;
if ( V_33 -> V_34 . V_35 < 0 )
V_16 = 0 ;
else if ( V_33 -> V_34 . V_35 > V_36 )
V_16 = V_36 ;
else
V_16 = V_33 -> V_34 . V_35 ;
return V_16 ;
}
static int F_9 ( struct V_32 * V_33 )
{
struct V_37 * V_38 = F_10 ( V_33 ) ;
struct V_8 * V_8 = V_38 -> V_18 ;
F_6 ( V_8 ,
F_8 ( V_33 ) ) ;
return 0 ;
}
static int
F_11 ( struct V_32 * V_33 )
{
struct V_37 * V_38 = F_10 ( V_33 ) ;
struct V_8 * V_8 = V_38 -> V_18 ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
return F_1 ( V_2 ) ;
}
void F_12 ( struct V_8 * V_8 ,
struct V_39 * V_39 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_32 * V_33 ;
struct V_40 V_34 ;
struct V_37 * V_38 ;
struct V_19 * V_20 ;
T_1 V_3 ;
char V_41 [ 16 ] ;
if ( ( V_2 -> V_42 -> V_43 == V_44 ) &&
( V_2 -> V_42 -> V_45 == 0x6741 ) )
return;
if ( ! V_8 -> V_23 )
return;
if ( ! V_2 -> V_46 )
return;
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return;
V_38 = F_13 ( sizeof( struct V_37 ) , V_47 ) ;
if ( ! V_38 ) {
F_14 ( L_1 ) ;
goto error;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_48 = V_36 ;
V_34 . type = V_49 ;
snprintf ( V_41 , sizeof( V_41 ) ,
L_2 , V_10 -> V_50 -> V_51 ) ;
V_33 = F_15 ( V_41 , V_39 -> V_52 ,
V_38 , & V_53 , & V_34 ) ;
if ( F_16 ( V_33 ) ) {
F_14 ( L_3 ) ;
goto error;
}
V_38 -> V_18 = V_8 ;
V_3 = F_1 ( V_2 ) ;
V_20 = V_8 -> V_23 ;
V_20 -> V_54 = V_33 ;
V_33 -> V_34 . V_35 = F_11 ( V_33 ) ;
V_33 -> V_34 . V_55 = V_56 ;
F_17 ( V_33 ) ;
F_18 ( L_4 ) ;
return;
error:
F_19 ( V_38 ) ;
return;
}
void
F_20 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_32 * V_33 = NULL ;
struct V_19 * V_20 ;
if ( ! V_8 -> V_23 )
return;
if ( ! V_2 -> V_46 )
return;
if ( ! ( V_2 -> V_13 . V_14 & V_15 ) )
return;
V_20 = V_8 -> V_23 ;
V_33 = V_20 -> V_54 ;
V_20 -> V_54 = NULL ;
if ( V_33 ) {
struct V_57 * V_38 ;
V_38 = F_10 ( V_33 ) ;
F_21 ( V_33 ) ;
F_19 ( V_38 ) ;
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
case V_59 :
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
if ( V_8 -> V_67 & ( V_22 ) )
F_27 ( V_18 , V_62 ) ;
else if ( V_8 -> V_68 != V_69 )
F_27 ( V_18 , V_62 ) ;
if ( ( V_8 -> V_67 & ( V_70 | V_22 ) ) ||
( F_28 ( V_18 ) != V_71 ) ) {
struct V_39 * V_72 = F_29 ( V_18 ) ;
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
int V_51 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_24 ) {
case V_74 :
case V_75 :
V_51 = F_32 ( V_76 , V_77 ) ;
break;
case V_78 :
case V_79 :
V_51 = F_32 ( V_76 , V_80 ) ;
break;
}
args . V_81 = V_73 ;
args . V_82 = V_83 ;
args . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
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
int V_51 = F_32 ( V_76 , V_98 ) ;
T_4 V_99 , V_100 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_51 , & V_99 , & V_100 ) )
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
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
}
int F_40 ( struct V_17 * V_18 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_39 * V_72 ;
struct V_118 * V_118 ;
struct V_119 * V_120 ;
if ( F_28 ( V_18 ) != V_71 )
return V_121 ;
if ( ( V_8 -> V_24 == V_122 ) ||
( V_8 -> V_24 == V_58 ) )
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
struct V_39 * V_72 = F_29 ( V_18 ) ;
union V_152 args ;
int V_51 = F_32 ( V_76 , V_153 ) ;
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
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_51 , & V_99 , & V_100 ) )
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
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
break;
default:
F_14 ( L_6 , V_99 , V_100 ) ;
break;
}
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
}
void
F_7 ( struct V_17 * V_18 , int V_73 ,
T_4 V_183 , T_4 V_184 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_39 * V_72 ;
union V_185 args ;
int V_51 = 0 ;
T_4 V_99 , V_100 ;
bool V_186 = false ;
int V_187 = 0 ;
int V_154 = 0 ;
int V_155 = 0 ;
int V_188 = 0 ;
int V_189 = 0 ;
int V_159 = V_20 -> V_159 ;
int V_156 = V_157 ;
if ( V_73 == V_190 ) {
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
V_188 =
( V_118 -> V_188 & V_191 ) >> V_192 ;
}
if ( V_18 -> V_89 ) {
struct V_90 * V_90 = F_36 ( V_18 -> V_89 ) ;
V_187 = V_90 -> V_187 ;
}
if ( V_159 == - 1 )
return;
if ( F_46 ( F_40 ( V_18 ) ) )
V_186 = true ;
memset ( & args , 0 , sizeof( args ) ) ;
switch ( V_8 -> V_24 ) {
case V_58 :
V_51 = F_32 ( V_76 , V_193 ) ;
break;
case V_25 :
case V_27 :
case V_28 :
case V_59 :
V_51 = F_32 ( V_76 , V_194 ) ;
break;
case V_26 :
V_51 = F_32 ( V_76 , V_195 ) ;
break;
}
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_51 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
switch ( V_100 ) {
case 1 :
args . V_160 . V_81 = V_73 ;
if ( V_73 == V_190 ) {
args . V_160 . V_196 = F_33 ( V_188 ) ;
} else if ( V_73 == V_197 ) {
args . V_160 . V_198 . V_199 = V_183 ;
args . V_160 . V_198 . V_200 = V_184 ;
} else {
if ( V_186 )
args . V_160 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_160 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_160 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
args . V_160 . V_166 = V_201 ;
if ( V_159 )
args . V_160 . V_166 |= V_202 ;
else
args . V_160 . V_166 |= V_203 ;
if ( ( V_2 -> V_63 & V_204 ) &&
( V_8 -> V_24 == V_25 ) ) {
if ( V_186 ||
! F_39 ( V_18 , V_8 -> V_85 ) ) {
if ( V_189 & 0x1 )
args . V_160 . V_166 |= V_205 ;
else if ( V_189 & 0x2 )
args . V_160 . V_166 |= V_206 ;
else if ( V_189 & 0x4 )
args . V_160 . V_166 |= V_207 ;
else if ( V_189 & 0x8 )
args . V_160 . V_166 |= V_208 ;
} else {
if ( V_189 & 0x3 )
args . V_160 . V_166 |= V_209 ;
else if ( V_189 & 0xc )
args . V_160 . V_166 |= V_210 ;
}
}
if ( V_20 -> V_171 )
args . V_160 . V_166 |= V_211 ;
else
args . V_160 . V_166 |= V_212 ;
if ( V_186 )
args . V_160 . V_166 |= V_213 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_214 )
args . V_160 . V_166 |= V_213 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_160 . V_166 |= V_215 ;
}
break;
case 2 :
args . V_216 . V_81 = V_73 ;
if ( V_73 == V_190 ) {
args . V_216 . V_196 = F_33 ( V_188 ) ;
} else if ( V_73 == V_197 ) {
args . V_216 . V_198 . V_199 = V_183 ;
args . V_216 . V_198 . V_200 = V_184 ;
} else {
if ( V_186 )
args . V_216 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_216 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_216 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
args . V_216 . V_175 . V_217 = V_159 ;
if ( V_20 -> V_171 )
args . V_216 . V_175 . V_218 = 1 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_216 . V_175 . V_219 = 0 ;
break;
case V_27 :
args . V_216 . V_175 . V_219 = 1 ;
break;
case V_28 :
args . V_216 . V_175 . V_219 = 2 ;
break;
}
if ( V_186 ) {
args . V_216 . V_175 . V_220 = 1 ;
args . V_216 . V_175 . V_221 = 1 ;
} else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_214 )
args . V_216 . V_175 . V_220 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_216 . V_175 . V_222 = 1 ;
}
break;
case 3 :
args . V_162 . V_81 = V_73 ;
if ( V_73 == V_190 ) {
args . V_162 . V_196 = F_33 ( V_188 ) ;
} else if ( V_73 == V_197 ) {
args . V_162 . V_198 . V_199 = V_183 ;
args . V_162 . V_198 . V_200 = V_184 ;
} else {
if ( V_186 )
args . V_162 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_162 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
if ( V_186 )
args . V_162 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_165 = 8 ;
else
args . V_162 . V_165 = 4 ;
if ( V_20 -> V_171 )
args . V_162 . V_175 . V_218 = 1 ;
if ( V_159 & 1 )
args . V_162 . V_175 . V_217 = 1 ;
if ( V_186 && V_2 -> clock . V_223 )
args . V_162 . V_175 . V_224 = 2 ;
else
args . V_162 . V_175 . V_224 = V_187 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_162 . V_175 . V_219 = 0 ;
break;
case V_27 :
args . V_162 . V_175 . V_219 = 1 ;
break;
case V_28 :
args . V_162 . V_175 . V_219 = 2 ;
break;
}
if ( V_186 )
args . V_162 . V_175 . V_220 = 1 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_214 )
args . V_162 . V_175 . V_220 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_175 . V_222 = 1 ;
}
break;
case 4 :
args . V_177 . V_81 = V_73 ;
if ( V_73 == V_190 ) {
args . V_177 . V_196 = F_33 ( V_188 ) ;
} else if ( V_73 == V_197 ) {
args . V_177 . V_198 . V_199 = V_183 ;
args . V_177 . V_198 . V_200 = V_184 ;
} else {
if ( V_186 )
args . V_177 . V_84 = F_33 ( V_154 / 10 ) ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_177 . V_84 = F_33 ( ( V_8 -> V_85 / 2 ) / 10 ) ;
else
args . V_177 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
}
if ( V_186 )
args . V_177 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_177 . V_165 = 8 ;
else
args . V_177 . V_165 = 4 ;
if ( V_20 -> V_171 )
args . V_177 . V_175 . V_218 = 1 ;
if ( V_159 & 1 )
args . V_177 . V_175 . V_217 = 1 ;
if ( V_186 ) {
if ( V_2 -> clock . V_223 )
args . V_177 . V_175 . V_224 = V_225 ;
else
args . V_177 . V_175 . V_224 = V_226 ;
} else
args . V_177 . V_175 . V_224 = V_187 ;
switch ( V_8 -> V_24 ) {
case V_25 :
args . V_177 . V_175 . V_219 = 0 ;
break;
case V_27 :
args . V_177 . V_175 . V_219 = 1 ;
break;
case V_28 :
args . V_177 . V_175 . V_219 = 2 ;
break;
}
if ( V_186 )
args . V_177 . V_175 . V_220 = 1 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_214 )
args . V_177 . V_175 . V_220 = 1 ;
if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_177 . V_175 . V_222 = 1 ;
}
break;
case 5 :
args . V_227 . V_81 = V_73 ;
if ( V_186 )
args . V_227 . V_228 = F_33 ( V_154 / 10 ) ;
else
args . V_227 . V_228 = F_33 ( V_8 -> V_85 / 10 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
if ( V_20 -> V_171 )
args . V_227 . V_229 = V_230 ;
else
args . V_227 . V_229 = V_231 ;
break;
case V_27 :
if ( V_20 -> V_171 )
args . V_227 . V_229 = V_232 ;
else
args . V_227 . V_229 = V_233 ;
break;
case V_28 :
if ( V_20 -> V_171 )
args . V_227 . V_229 = V_234 ;
else
args . V_227 . V_229 = V_235 ;
break;
case V_59 :
args . V_227 . V_229 = V_236 ;
break;
}
if ( V_186 )
args . V_227 . V_165 = V_155 ;
else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_227 . V_165 = 8 ;
else
args . V_227 . V_165 = 4 ;
args . V_227 . V_237 = V_188 ;
args . V_227 . V_238 = F_40 ( V_18 ) ;
if ( V_186 && V_2 -> clock . V_223 )
args . V_227 . V_239 . V_240 = V_225 ;
else
args . V_227 . V_239 . V_240 = V_187 ;
if ( V_186 )
args . V_227 . V_239 . V_241 = 1 ;
else if ( V_8 -> V_21 & ( V_70 ) ) {
if ( V_20 -> V_214 )
args . V_227 . V_239 . V_241 = 1 ;
}
if ( V_156 == V_157 )
args . V_227 . V_239 . V_242 = 0 ;
else
args . V_227 . V_239 . V_242 = V_156 + 1 ;
args . V_227 . V_243 = 1 << V_159 ;
args . V_227 . V_244 = V_184 ;
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
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
}
bool
F_47 ( struct V_39 * V_72 ,
int V_73 )
{
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_9 * V_10 = V_118 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
union V_185 args ;
int V_51 = F_32 ( V_76 , V_194 ) ;
T_4 V_99 , V_100 ;
if ( V_72 -> V_124 != V_144 )
goto V_245;
if ( ( V_73 != V_246 ) &&
( V_73 != V_247 ) )
goto V_245;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_51 , & V_99 , & V_100 ) )
goto V_245;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_160 . V_81 = V_73 ;
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
if ( V_73 == V_246 ) {
int V_248 ;
for ( V_248 = 0 ; V_248 < 300 ; V_248 ++ ) {
if ( F_48 ( V_2 , V_118 -> V_158 . V_158 ) )
return true ;
F_49 ( 1 ) ;
}
return false ;
}
V_245:
return true ;
}
static void
F_50 ( struct V_17 * V_18 ,
struct V_17 * V_249 ,
int V_73 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_8 * V_250 = F_23 ( V_249 ) ;
union V_251 args ;
struct V_39 * V_72 ;
int V_51 = F_32 ( V_76 , V_252 ) ;
T_1 V_99 , V_100 ;
int V_154 = 0 ;
int V_155 = 0 ;
int V_188 = 0 ;
T_2 V_253 = ( V_250 -> V_254 & V_255 ) >> V_256 ;
if ( V_73 == V_257 )
V_72 = F_41 ( V_18 ) ;
else
V_72 = F_29 ( V_18 ) ;
if ( V_72 ) {
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_119 * V_120 =
V_118 -> V_140 ;
V_154 = V_120 -> V_154 ;
V_155 = V_120 -> V_155 ;
V_188 =
( V_118 -> V_188 & V_191 ) >> V_192 ;
}
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_51 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
break;
case 2 :
switch ( V_100 ) {
case 1 :
case 2 :
args . V_160 . V_258 . V_81 = V_73 ;
args . V_160 . V_258 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
args . V_160 . V_258 . V_164 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_160 . V_258 . V_164 ) ) {
if ( V_154 == 270000 )
args . V_160 . V_258 . V_166 |= V_167 ;
args . V_160 . V_258 . V_165 = V_155 ;
} else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_160 . V_258 . V_165 = 8 ;
else
args . V_160 . V_258 . V_165 = 4 ;
break;
case 3 :
args . V_162 . V_259 . V_81 = V_73 ;
if ( V_73 == V_257 )
args . V_162 . V_259 . V_260 = F_33 ( V_188 ) ;
else
args . V_162 . V_259 . V_84 = F_33 ( V_8 -> V_85 / 10 ) ;
args . V_162 . V_259 . V_164 =
F_40 ( V_18 ) ;
if ( F_46 ( args . V_162 . V_259 . V_164 ) ) {
if ( V_154 == 270000 )
args . V_162 . V_259 . V_166 |= V_261 ;
else if ( V_154 == 540000 )
args . V_162 . V_259 . V_166 |= V_262 ;
args . V_162 . V_259 . V_165 = V_155 ;
} else if ( F_39 ( V_18 , V_8 -> V_85 ) )
args . V_162 . V_259 . V_165 = 8 ;
else
args . V_162 . V_259 . V_165 = 4 ;
switch ( V_253 ) {
case V_263 :
args . V_162 . V_259 . V_166 |= V_264 ;
break;
case V_265 :
args . V_162 . V_259 . V_166 |= V_266 ;
break;
case V_267 :
args . V_162 . V_259 . V_166 |= V_268 ;
break;
}
args . V_162 . V_259 . V_117 = F_35 ( V_18 ) ;
break;
default:
F_14 ( L_7 , V_99 , V_100 ) ;
return;
}
break;
default:
F_14 ( L_7 , V_99 , V_100 ) ;
return;
}
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
}
static void
F_51 ( struct V_17 * V_18 , int V_73 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_17 * V_249 = F_52 ( V_18 ) ;
struct V_19 * V_20 = V_8 -> V_23 ;
struct V_39 * V_72 = F_29 ( V_18 ) ;
struct V_118 * V_118 = NULL ;
struct V_119 * V_269 = NULL ;
if ( V_72 ) {
V_118 = F_42 ( V_72 ) ;
V_269 = V_118 -> V_140 ;
}
if ( V_73 == V_270 ) {
if ( ! V_72 )
V_20 -> V_151 = V_271 ;
else
V_20 -> V_151 = F_53 ( V_18 , V_72 ) ;
F_45 ( V_18 , V_272 , 0 ) ;
F_45 ( V_18 ,
V_161 ,
V_20 -> V_151 ) ;
if ( V_249 )
F_50 ( V_18 , V_249 ,
V_273 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 ) {
if ( V_72 -> V_124 == V_144 ) {
F_47 ( V_72 ,
V_246 ) ;
V_269 -> V_274 = true ;
}
}
F_7 ( V_18 ,
V_275 ,
0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 ) {
F_54 ( V_18 , V_72 ) ;
F_45 ( V_18 , V_276 , 0 ) ;
}
if ( V_8 -> V_21 & ( V_22 ) )
F_6 ( V_8 , V_20 -> V_3 ) ;
if ( V_249 )
F_50 ( V_18 , V_249 , V_270 ) ;
} else {
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 )
F_45 ( V_18 ,
V_277 , 0 ) ;
if ( V_249 )
F_50 ( V_18 , V_249 , V_278 ) ;
if ( V_8 -> V_21 & ( V_22 ) )
F_7 ( V_18 ,
V_29 , 0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 )
F_55 ( V_72 , V_279 ) ;
F_7 ( V_18 ,
V_280 , 0 , 0 ) ;
if ( F_46 ( F_40 ( V_18 ) ) &&
V_72 ) {
if ( V_72 -> V_124 == V_144 ) {
F_47 ( V_72 ,
V_247 ) ;
V_269 -> V_274 = false ;
}
}
}
}
void
F_56 ( struct V_17 * V_18 , int V_61 )
{
struct V_8 * V_8 = F_23 ( V_18 ) ;
F_57 ( L_8 ,
V_8 -> V_24 , V_61 , V_8 -> V_21 ,
V_8 -> V_67 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_59 :
switch ( V_61 ) {
case V_281 :
F_51 ( V_18 , V_270 ) ;
break;
case V_282 :
case V_283 :
case V_284 :
F_51 ( V_18 , V_278 ) ;
break;
}
break;
case V_58 :
switch ( V_61 ) {
case V_281 :
F_37 ( V_18 , V_270 ) ;
break;
case V_282 :
case V_283 :
case V_284 :
F_37 ( V_18 , V_278 ) ;
break;
}
break;
case V_75 :
switch ( V_61 ) {
case V_281 :
F_31 ( V_18 , V_270 ) ;
break;
case V_282 :
case V_283 :
case V_284 :
F_31 ( V_18 , V_278 ) ;
break;
}
break;
default:
return;
}
}
void
F_58 ( struct V_17 * V_18 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_90 * V_90 = F_36 ( V_18 -> V_89 ) ;
union V_285 args ;
int V_51 = F_32 ( V_76 , V_286 ) ;
T_4 V_99 , V_100 ;
struct V_19 * V_20 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_51 , & V_99 , & V_100 ) )
return;
switch ( V_99 ) {
case 1 :
switch ( V_100 ) {
case 1 :
default:
args . V_160 . V_287 = V_90 -> V_288 ;
switch ( V_8 -> V_24 ) {
case V_289 :
case V_290 :
args . V_160 . V_291 = V_110 ;
break;
case V_292 :
case V_293 :
if ( V_8 -> V_21 & V_294 )
args . V_160 . V_291 = V_295 ;
else
args . V_160 . V_291 = V_296 ;
break;
case V_122 :
case V_297 :
case V_58 :
args . V_160 . V_291 = V_298 ;
break;
case V_74 :
case V_75 :
if ( V_8 -> V_67 & ( V_299 ) )
args . V_160 . V_291 = V_300 ;
else if ( V_8 -> V_67 & ( V_301 ) )
args . V_160 . V_291 = V_302 ;
else
args . V_160 . V_291 = V_303 ;
break;
case V_78 :
case V_79 :
if ( V_8 -> V_67 & ( V_299 ) )
args . V_160 . V_291 = V_300 ;
else if ( V_8 -> V_67 & ( V_301 ) )
args . V_160 . V_291 = V_302 ;
else
args . V_160 . V_291 = V_304 ;
break;
}
break;
case 2 :
args . V_216 . V_287 = V_90 -> V_288 ;
if ( F_28 ( V_18 ) != V_71 ) {
struct V_39 * V_72 = F_29 ( V_18 ) ;
if ( V_72 -> V_124 == V_137 )
args . V_216 . V_305 = V_138 ;
else if ( V_72 -> V_124 == V_146 )
args . V_216 . V_305 = V_134 ;
else
args . V_216 . V_305 = F_40 ( V_18 ) ;
} else if ( V_8 -> V_21 & ( V_22 ) ) {
args . V_216 . V_305 = V_138 ;
} else {
args . V_216 . V_305 = F_40 ( V_18 ) ;
}
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_59 :
case V_26 :
V_20 = V_8 -> V_23 ;
switch ( V_20 -> V_159 ) {
case 0 :
args . V_216 . V_306 = V_307 ;
break;
case 1 :
args . V_216 . V_306 = V_308 ;
break;
case 2 :
args . V_216 . V_306 = V_309 ;
break;
case 3 :
args . V_216 . V_306 = V_310 ;
break;
case 4 :
args . V_216 . V_306 = V_311 ;
break;
case 5 :
args . V_216 . V_306 = V_312 ;
break;
case 6 :
args . V_216 . V_306 = V_313 ;
break;
}
break;
case V_58 :
args . V_216 . V_306 = V_314 ;
break;
case V_75 :
if ( V_8 -> V_67 & ( V_299 ) )
args . V_216 . V_306 = V_315 ;
else if ( V_8 -> V_67 & ( V_301 ) )
args . V_216 . V_306 = V_315 ;
else
args . V_216 . V_306 = V_316 ;
break;
case V_79 :
if ( V_8 -> V_67 & ( V_299 ) )
args . V_216 . V_306 = V_315 ;
else if ( V_8 -> V_67 & ( V_301 ) )
args . V_216 . V_306 = V_315 ;
else
args . V_216 . V_306 = V_317 ;
break;
}
break;
case 3 :
args . V_162 . V_287 = V_90 -> V_288 ;
if ( F_28 ( V_18 ) != V_71 ) {
struct V_39 * V_72 = F_29 ( V_18 ) ;
if ( V_72 -> V_124 == V_137 )
args . V_216 . V_305 = V_138 ;
else if ( V_72 -> V_124 == V_146 )
args . V_216 . V_305 = V_134 ;
else
args . V_216 . V_305 = F_40 ( V_18 ) ;
} else if ( V_8 -> V_21 & ( V_22 ) ) {
args . V_216 . V_305 = V_138 ;
} else {
args . V_216 . V_305 = F_40 ( V_18 ) ;
}
args . V_162 . V_318 = F_35 ( V_18 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_59 :
case V_26 :
V_20 = V_8 -> V_23 ;
switch ( V_20 -> V_159 ) {
case 0 :
args . V_162 . V_306 = V_307 ;
break;
case 1 :
args . V_162 . V_306 = V_308 ;
break;
case 2 :
args . V_162 . V_306 = V_309 ;
break;
case 3 :
args . V_162 . V_306 = V_310 ;
break;
case 4 :
args . V_162 . V_306 = V_311 ;
break;
case 5 :
args . V_162 . V_306 = V_312 ;
break;
case 6 :
args . V_162 . V_306 = V_313 ;
break;
}
break;
case V_58 :
args . V_162 . V_306 = V_314 ;
break;
case V_75 :
if ( V_8 -> V_67 & ( V_299 ) )
args . V_162 . V_306 = V_315 ;
else if ( V_8 -> V_67 & ( V_301 ) )
args . V_162 . V_306 = V_315 ;
else
args . V_162 . V_306 = V_316 ;
break;
case V_79 :
if ( V_8 -> V_67 & ( V_299 ) )
args . V_162 . V_306 = V_315 ;
else if ( V_8 -> V_67 & ( V_301 ) )
args . V_162 . V_306 = V_315 ;
else
args . V_162 . V_306 = V_317 ;
break;
}
break;
}
break;
default:
F_14 ( L_7 , V_99 , V_100 ) ;
return;
}
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
}
void
F_59 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_319 ;
struct V_17 * V_18 ;
F_60 (encoder, &dev->mode_config.encoder_list, head) {
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_17 * V_249 = F_52 ( V_18 ) ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_27 :
case V_28 :
case V_59 :
F_7 ( V_18 , V_190 ,
0 , 0 ) ;
break;
}
if ( V_249 )
F_50 ( V_18 , V_249 ,
V_257 ) ;
}
}
static bool
F_61 ( struct V_17 * V_18 ,
struct V_39 * V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_118 * V_118 = F_42 ( V_72 ) ;
if ( V_8 -> V_21 & ( V_299 |
V_301 |
V_320 ) ) {
T_5 args ;
int V_51 = F_32 ( V_76 , V_321 ) ;
T_4 V_99 , V_100 ;
memset ( & args , 0 , sizeof( args ) ) ;
if ( ! F_38 ( V_2 -> V_13 . V_86 , V_51 , & V_99 , & V_100 ) )
return false ;
args . V_322 . V_104 = 0 ;
if ( ( V_8 -> V_24 == V_74 ) ||
( V_8 -> V_24 == V_75 ) )
args . V_322 . V_323 = V_324 ;
else
args . V_322 . V_323 = V_325 ;
if ( V_118 -> V_21 & V_326 )
args . V_322 . V_327 = F_33 ( V_326 ) ;
else if ( V_118 -> V_21 & V_328 )
args . V_322 . V_327 = F_33 ( V_328 ) ;
else if ( V_118 -> V_21 & V_301 ) {
args . V_322 . V_327 = F_33 ( V_301 ) ;
if ( V_100 >= 3 )
args . V_322 . V_104 = V_329 ;
} else if ( V_118 -> V_21 & V_330 ) {
args . V_322 . V_327 = F_33 ( V_330 ) ;
if ( V_100 >= 3 )
args . V_322 . V_104 = V_329 ;
}
F_34 ( V_2 -> V_13 . V_86 , V_51 , ( V_87 * ) & args ) ;
return true ;
} else
return false ;
}
enum V_331
F_62 ( struct V_17 * V_18 ,
struct V_39 * V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_118 * V_118 = F_42 ( V_72 ) ;
V_87 V_332 ;
if ( ! F_61 ( V_18 , V_72 ) ) {
F_57 ( L_9 ) ;
return V_333 ;
}
V_332 = F_2 ( V_334 ) ;
F_57 ( L_10 , V_332 , V_8 -> V_21 ) ;
if ( V_118 -> V_21 & V_326 ) {
if ( V_332 & V_335 )
return V_336 ;
}
if ( V_118 -> V_21 & V_328 ) {
if ( V_332 & V_337 )
return V_336 ;
}
if ( V_118 -> V_21 & V_301 ) {
if ( V_332 & ( V_338 | V_339 ) )
return V_336 ;
}
if ( V_118 -> V_21 & V_330 ) {
if ( V_332 & ( V_340 | V_341 ) )
return V_336 ;
else if ( V_332 & ( V_342 | V_343 ) )
return V_336 ;
}
return V_344 ;
}
enum V_331
F_63 ( struct V_17 * V_18 ,
struct V_39 * V_72 )
{
struct V_9 * V_10 = V_18 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
struct V_118 * V_118 = F_42 ( V_72 ) ;
struct V_17 * V_249 = F_52 ( V_18 ) ;
T_2 V_332 ;
if ( ! V_249 )
return V_333 ;
if ( ( V_118 -> V_21 & V_320 ) == 0 )
return V_333 ;
F_50 ( V_18 , V_249 ,
V_345 ) ;
V_332 = F_2 ( V_334 ) ;
F_57 ( L_10 , V_332 , V_8 -> V_21 ) ;
if ( V_118 -> V_21 & V_326 ) {
if ( V_332 & V_335 )
return V_336 ;
}
if ( V_118 -> V_21 & V_328 ) {
if ( V_332 & V_337 )
return V_336 ;
}
if ( V_118 -> V_21 & V_301 ) {
if ( V_332 & ( V_338 | V_339 ) )
return V_336 ;
}
if ( V_118 -> V_21 & V_330 ) {
if ( V_332 & ( V_340 | V_341 ) )
return V_336 ;
else if ( V_332 & ( V_342 | V_343 ) )
return V_336 ;
}
return V_344 ;
}
void
F_64 ( struct V_17 * V_18 )
{
struct V_17 * V_249 = F_52 ( V_18 ) ;
if ( V_249 )
F_50 ( V_18 , V_249 ,
V_346 ) ;
}
void
F_65 ( struct V_39 * V_72 ,
struct V_17 * V_18 ,
bool V_347 )
{
struct V_9 * V_10 = V_72 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_118 * V_118 =
F_42 ( V_72 ) ;
struct V_8 * V_8 = F_23 ( V_18 ) ;
V_87 V_332 , V_348 , V_349 ;
V_332 = F_2 ( V_334 ) ;
V_348 = F_2 ( V_350 ) ;
V_349 = F_2 ( V_351 ) ;
if ( ( V_8 -> V_21 & V_294 ) &&
( V_118 -> V_21 & V_294 ) ) {
if ( V_347 ) {
F_57 ( L_11 ) ;
V_332 |= V_352 ;
V_348 |= V_353 ;
V_349 |= V_354 ;
} else {
F_57 ( L_12 ) ;
V_332 &= ~ V_352 ;
V_348 &= ~ V_353 ;
V_349 &= ~ V_354 ;
}
}
if ( ( V_8 -> V_21 & V_326 ) &&
( V_118 -> V_21 & V_326 ) ) {
if ( V_347 ) {
F_57 ( L_13 ) ;
V_332 |= V_355 ;
V_348 |= V_356 ;
V_349 |= V_357 ;
} else {
F_57 ( L_14 ) ;
V_332 &= ~ V_335 ;
V_348 &= ~ V_356 ;
V_349 &= ~ V_357 ;
}
}
if ( ( V_8 -> V_21 & V_328 ) &&
( V_118 -> V_21 & V_328 ) ) {
if ( V_347 ) {
F_57 ( L_15 ) ;
V_332 |= V_358 ;
V_348 |= V_359 ;
V_349 |= V_360 ;
} else {
F_57 ( L_16 ) ;
V_332 &= ~ V_337 ;
V_348 &= ~ V_359 ;
V_349 &= ~ V_360 ;
}
}
if ( ( V_8 -> V_21 & V_361 ) &&
( V_118 -> V_21 & V_361 ) ) {
if ( V_347 ) {
F_57 ( L_17 ) ;
V_332 |= V_362 ;
V_348 |= V_363 ;
V_349 |= V_364 ;
} else {
F_57 ( L_18 ) ;
V_332 &= ~ V_362 ;
V_348 &= ~ V_363 ;
V_349 &= ~ V_364 ;
}
}
if ( ( V_8 -> V_21 & V_365 ) &&
( V_118 -> V_21 & V_365 ) ) {
if ( V_347 ) {
F_57 ( L_19 ) ;
V_332 |= V_366 ;
V_348 |= V_367 ;
V_349 |= V_368 ;
} else {
F_57 ( L_20 ) ;
V_332 &= ~ V_366 ;
V_348 &= ~ V_367 ;
V_349 &= ~ V_368 ;
}
}
if ( ( V_8 -> V_21 & V_369 ) &&
( V_118 -> V_21 & V_369 ) ) {
if ( V_347 ) {
F_57 ( L_21 ) ;
V_332 |= V_370 ;
V_348 |= V_371 ;
V_349 |= V_372 ;
} else {
F_57 ( L_22 ) ;
V_332 &= ~ V_370 ;
V_348 &= ~ V_371 ;
V_349 &= ~ V_372 ;
}
}
if ( ( V_8 -> V_21 & V_373 ) &&
( V_118 -> V_21 & V_373 ) ) {
if ( V_347 ) {
F_57 ( L_23 ) ;
V_332 |= V_374 ;
V_348 |= V_375 ;
V_349 |= V_376 ;
} else {
F_57 ( L_24 ) ;
V_332 &= ~ V_374 ;
V_348 &= ~ V_375 ;
V_349 &= ~ V_376 ;
}
}
if ( ( V_8 -> V_21 & V_377 ) &&
( V_118 -> V_21 & V_377 ) ) {
if ( V_347 ) {
F_57 ( L_25 ) ;
V_332 |= V_378 ;
V_348 |= V_379 ;
V_349 |= V_380 ;
} else {
F_57 ( L_26 ) ;
V_332 &= ~ V_378 ;
V_348 &= ~ V_379 ;
V_349 &= ~ V_380 ;
}
}
if ( ( V_8 -> V_21 & V_381 ) &&
( V_118 -> V_21 & V_381 ) ) {
if ( V_347 ) {
F_57 ( L_27 ) ;
V_332 |= V_382 ;
V_348 |= V_383 ;
V_349 |= V_384 ;
} else {
F_57 ( L_28 ) ;
V_332 &= ~ V_382 ;
V_348 &= ~ V_383 ;
V_349 &= ~ V_384 ;
}
}
F_4 ( V_334 , V_332 ) ;
F_4 ( V_350 , V_348 ) ;
F_4 ( V_351 , V_349 ) ;
}
struct V_19 *
F_66 ( struct V_8 * V_18 )
{
struct V_9 * V_10 = V_18 -> V_11 . V_10 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_385 * V_13 = & V_2 -> V_13 ;
int V_51 = F_32 ( V_386 , V_387 ) ;
T_6 V_388 , V_389 ;
union V_390 * V_390 ;
T_4 V_99 , V_100 ;
struct V_19 * V_391 = NULL ;
int V_254 = ( V_18 -> V_254 & V_255 ) >> V_256 ;
if ( F_67 ( V_13 -> V_86 , V_51 , NULL ,
& V_99 , & V_100 , & V_388 ) ) {
V_390 =
(union V_390 * ) ( V_13 -> V_86 -> V_392 + V_388 ) ;
V_391 =
F_68 ( sizeof( struct V_19 ) , V_47 ) ;
if ( ! V_391 )
return NULL ;
V_391 -> V_393 . clock =
F_69 ( V_390 -> V_394 . V_395 . V_396 ) * 10 ;
V_391 -> V_393 . V_397 =
F_69 ( V_390 -> V_394 . V_395 . V_398 ) ;
V_391 -> V_393 . V_399 =
F_69 ( V_390 -> V_394 . V_395 . V_400 ) ;
V_391 -> V_393 . V_401 = V_391 -> V_393 . V_397 +
F_69 ( V_390 -> V_394 . V_395 . V_402 ) ;
V_391 -> V_393 . V_403 = V_391 -> V_393 . V_397 +
F_69 ( V_390 -> V_394 . V_395 . V_404 ) ;
V_391 -> V_393 . V_405 = V_391 -> V_393 . V_403 +
F_69 ( V_390 -> V_394 . V_395 . V_406 ) ;
V_391 -> V_393 . V_407 = V_391 -> V_393 . V_399 +
F_69 ( V_390 -> V_394 . V_395 . V_408 ) ;
V_391 -> V_393 . V_409 = V_391 -> V_393 . V_399 +
F_69 ( V_390 -> V_394 . V_395 . V_410 ) ;
V_391 -> V_393 . V_411 = V_391 -> V_393 . V_409 +
F_69 ( V_390 -> V_394 . V_395 . V_412 ) ;
V_391 -> V_413 =
F_69 ( V_390 -> V_394 . V_414 ) ;
V_391 -> V_415 = V_390 -> V_394 . V_416 ;
V_389 = F_69 ( V_390 -> V_394 . V_395 . V_417 . V_418 ) ;
if ( V_389 & V_419 )
V_391 -> V_393 . V_63 |= V_420 ;
if ( V_389 & V_421 )
V_391 -> V_393 . V_63 |= V_422 ;
if ( V_389 & V_423 )
V_391 -> V_393 . V_63 |= V_424 ;
if ( V_389 & V_425 )
V_391 -> V_393 . V_63 |= V_64 ;
if ( V_389 & V_426 )
V_391 -> V_393 . V_63 |= V_427 ;
V_391 -> V_393 . V_428 = F_69 ( V_390 -> V_394 . V_395 . V_429 ) ;
V_391 -> V_393 . V_430 = F_69 ( V_390 -> V_394 . V_395 . V_431 ) ;
F_26 ( & V_391 -> V_393 , V_432 ) ;
V_391 -> V_433 = V_390 -> V_394 . V_434 ;
V_18 -> V_393 = V_391 -> V_393 ;
if ( V_254 == 2 )
V_391 -> V_171 = true ;
else
V_391 -> V_171 = false ;
if ( F_69 ( V_390 -> V_394 . V_435 ) ) {
T_7 * V_436 ;
T_8 * V_437 ;
bool V_438 = false ;
T_1 * V_439 ;
if ( ( V_99 == 1 ) && ( V_100 < 2 ) )
V_439 = ( T_1 * ) ( V_13 -> V_86 -> V_392 +
F_69 ( V_390 -> V_394 . V_435 ) ) ;
else
V_439 = ( T_1 * ) ( V_13 -> V_86 -> V_392 +
V_388 +
F_69 ( V_390 -> V_394 . V_435 ) ) ;
while ( * V_439 != V_440 ) {
switch ( * V_439 ) {
case V_441 :
V_439 += sizeof( V_442 ) ;
break;
case V_443 :
V_439 += sizeof( V_444 ) ;
break;
case V_445 :
V_439 += sizeof( V_446 ) ;
break;
case V_447 :
V_436 = ( T_7 * ) V_439 ;
if ( V_436 -> V_448 ) {
struct V_449 * V_449 ;
int V_450 =
F_70 ( ( int ) V_451 , ( int ) V_436 -> V_448 ) ;
V_449 = F_13 ( V_450 , V_47 ) ;
if ( V_449 ) {
memcpy ( ( T_1 * ) V_449 , ( T_1 * ) & V_436 -> V_452 [ 0 ] ,
V_436 -> V_448 ) ;
if ( F_71 ( V_449 ) ) {
V_2 -> V_13 . V_453 = V_449 ;
V_2 -> V_13 . V_454 = V_450 ;
} else
F_19 ( V_449 ) ;
}
}
V_439 += V_436 -> V_448 ?
V_436 -> V_448 + 2 :
sizeof( T_7 ) ;
break;
case V_455 :
V_437 = ( T_8 * ) V_439 ;
V_391 -> V_393 . V_428 = V_437 -> V_456 ;
V_391 -> V_393 . V_430 = V_437 -> V_457 ;
V_439 += sizeof( T_8 ) ;
break;
default:
F_14 ( L_29 , * V_439 ) ;
V_438 = true ;
break;
}
if ( V_438 )
break;
}
}
}
return V_391 ;
}
struct V_19 *
F_72 ( struct V_8 * V_8 )
{
int V_254 = ( V_8 -> V_254 & V_255 ) >> V_256 ;
struct V_19 * V_20 = F_68 ( sizeof( struct V_19 ) , V_47 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_214 = true ;
V_20 -> V_159 = - 1 ;
if ( V_254 == 2 )
V_20 -> V_171 = true ;
else
V_20 -> V_171 = false ;
return V_20 ;
}
