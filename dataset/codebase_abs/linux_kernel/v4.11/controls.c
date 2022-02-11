static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
V_8 . V_13 = V_4 -> V_14 ;
V_8 . V_15 = 100 ;
return F_2 ( V_2 -> V_16 , V_10 ,
V_6 -> V_17 ,
& V_8 ,
sizeof( V_8 ) ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_18 ;
struct V_9 * V_10 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
V_18 = V_4 -> V_14 ;
return F_2 ( V_2 -> V_16 , V_10 ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_18 ;
struct V_9 * V_10 ;
if ( V_4 -> V_14 > V_6 -> V_19 || V_4 -> V_14 < V_6 -> V_20 )
return 1 ;
if ( V_4 -> V_21 == V_22 )
V_2 -> V_23 = V_24 [ V_4 -> V_14 ] ;
else if ( V_4 -> V_21 == V_25 )
V_2 -> V_26 =
( V_4 -> V_14 == V_27 ?
true :
false ) ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
if ( V_2 -> V_26 )
V_18 = V_2 -> V_23 ;
else
V_18 = 0 ;
return F_2 ( V_2 -> V_16 , V_10 ,
V_28 ,
& V_18 , sizeof( V_18 ) ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_2 V_29 ;
struct V_9 * V_10 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
V_29 = ( V_4 -> V_14 - 12 ) * 2 ;
return F_2 ( V_2 -> V_16 , V_10 ,
V_6 -> V_17 ,
& V_29 , sizeof( V_29 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_30 ;
T_1 V_18 ;
struct V_31 * V_32 ;
V_32 = V_2 -> V_11 [ V_12 ] ;
V_18 = ( ( V_4 -> V_14 % 360 ) / 90 ) * 90 ;
V_30 = F_2 ( V_2 -> V_16 , & V_32 -> V_33 [ 0 ] ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_2 ( V_2 -> V_16 , & V_32 -> V_33 [ 1 ] ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_2 ( V_2 -> V_16 , & V_32 -> V_33 [ 2 ] ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
return V_30 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_30 ;
T_1 V_18 ;
struct V_31 * V_32 ;
if ( V_4 -> V_21 == V_34 )
V_2 -> V_35 = V_4 -> V_14 ;
else
V_2 -> V_36 = V_4 -> V_14 ;
V_32 = V_2 -> V_11 [ V_12 ] ;
if ( V_2 -> V_35 && V_2 -> V_36 )
V_18 = V_37 ;
else if ( V_2 -> V_35 )
V_18 = V_38 ;
else if ( V_2 -> V_36 )
V_18 = V_39 ;
else
V_18 = V_40 ;
V_30 = F_2 ( V_2 -> V_16 , & V_32 -> V_33 [ 0 ] ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_2 ( V_2 -> V_16 , & V_32 -> V_33 [ 1 ] ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_2 ( V_2 -> V_16 , & V_32 -> V_33 [ 2 ] ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
return V_30 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
enum V_41 V_42 = V_2 -> V_43 ;
T_1 V_44 = 0 ;
struct V_9 * V_10 ;
int V_30 = 0 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
if ( V_6 -> V_17 == V_45 ) {
V_2 -> V_46 = V_4 -> V_14 * 100 ;
} else if ( V_6 -> V_17 == V_47 ) {
switch ( V_4 -> V_14 ) {
case V_48 :
V_42 = V_49 ;
break;
case V_50 :
V_42 = V_51 ;
break;
}
V_2 -> V_43 = V_42 ;
V_2 -> V_52 = V_4 -> V_14 ;
} else if ( V_6 -> V_21 == V_53 ) {
V_2 -> V_54 = V_4 -> V_14 ;
}
if ( V_2 -> V_55 == V_56 ) {
if ( V_42 == V_51 )
V_44 = V_2 -> V_46 ;
V_30 = F_2 ( V_2 -> V_16 ,
V_10 ,
V_45 ,
& V_44 ,
sizeof( V_44 ) ) ;
V_30 += F_2 ( V_2 -> V_16 ,
V_10 ,
V_47 ,
& V_42 ,
sizeof( T_1 ) ) ;
V_2 -> V_57 = V_42 ;
}
V_30 += F_9 ( V_2 ) ;
return V_30 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
switch ( V_4 -> V_14 ) {
case V_58 :
V_2 -> V_59 = V_60 ;
break;
case V_61 :
V_2 -> V_59 = V_62 ;
break;
case V_63 :
V_2 -> V_59 = V_64 ;
break;
}
if ( V_2 -> V_55 == V_56 ) {
struct V_9 * V_10 ;
T_1 V_18 = V_2 -> V_59 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
return F_2 ( V_2 -> V_16 , V_10 ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
} else
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_18 ;
struct V_9 * V_10 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
switch ( V_4 -> V_14 ) {
case V_65 :
V_18 = V_66 ;
break;
case V_67 :
V_18 = V_68 ;
break;
case V_69 :
V_18 = V_70 ;
break;
case V_71 :
V_18 = V_72 ;
break;
}
return F_2 ( V_2 -> V_16 , V_10 ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_18 ;
struct V_9 * V_10 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
switch ( V_4 -> V_14 ) {
case V_73 :
V_18 = V_74 ;
break;
case V_75 :
V_18 = V_76 ;
break;
case V_77 :
V_18 = V_78 ;
break;
case V_79 :
V_18 = V_80 ;
break;
case V_81 :
V_18 = V_82 ;
break;
case V_83 :
V_18 = V_84 ;
break;
case V_85 :
V_18 = V_86 ;
break;
case V_87 :
V_18 = V_88 ;
break;
case V_89 :
V_18 = V_90 ;
break;
case V_91 :
V_18 = V_92 ;
break;
}
return F_2 ( V_2 -> V_16 , V_10 ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_93 V_94 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
if ( V_4 -> V_21 == V_95 )
V_2 -> V_96 = V_4 -> V_14 ;
else if ( V_4 -> V_21 == V_97 )
V_2 -> V_98 = V_4 -> V_14 ;
V_94 . V_99 . V_13 = V_2 -> V_96 ;
V_94 . V_100 . V_13 = V_2 -> V_98 ;
V_94 . V_99 . V_15 = V_94 . V_100 . V_15 = 1000 ;
return F_2 ( V_2 -> V_16 , V_10 ,
V_6 -> V_17 ,
& V_94 , sizeof( V_94 ) ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_30 = - V_101 ;
int V_102 , V_103 ;
struct V_9 * V_10 ;
struct V_104 V_105 ;
for ( V_102 = 0 ; V_102 < F_15 ( V_106 ) ; V_102 ++ ) {
if ( V_4 -> V_14 == V_106 [ V_102 ] . V_107 ) {
V_105 . V_108 =
V_106 [ V_102 ] . V_109 ;
V_105 . V_110 =
V_106 [ V_102 ] . V_110 ;
if ( V_105 . V_110 > V_111 )
V_105 . V_110 = V_111 ;
for ( V_103 = 0 ; V_103 < V_105 . V_110 ; V_103 ++ )
V_105 . V_112 [ V_103 ] =
V_106 [ V_102 ] . V_113 [ V_103 ] ;
V_2 -> V_114 . V_115 =
V_106 [ V_102 ] . V_116 ;
if ( ! V_106 [ V_102 ] . V_117 ) {
V_2 -> V_114 . V_118 =
V_106 [ V_102 ] . V_118 ;
V_2 -> V_114 . V_119 =
V_106 [ V_102 ] . V_119 ;
}
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
V_30 = F_2 (
V_2 -> V_16 , V_10 ,
V_120 ,
& V_105 , sizeof( V_105 ) ) ;
if ( V_30 )
goto exit;
V_30 = F_2 (
V_2 -> V_16 , V_10 ,
V_121 ,
& V_2 -> V_114 , sizeof( V_2 -> V_114 ) ) ;
}
}
exit:
F_16 ( 1 , V_122 , & V_2 -> V_123 ,
L_1 ,
V_6 , V_4 -> V_21 , V_4 -> V_14 , V_105 . V_108 ,
V_2 -> V_114 . V_115 ? L_2 : L_3 ,
V_2 -> V_114 . V_118 , V_2 -> V_114 . V_119 ,
V_30 , ( V_30 == 0 ? 0 : - V_101 ) ) ;
return ( V_30 == 0 ? 0 : V_101 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_30 = - V_101 ;
struct V_9 * V_10 ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
V_2 -> V_114 . V_115 = ( V_4 -> V_14 & 0xff00 ) >> 8 ;
V_2 -> V_114 . V_115 = V_4 -> V_14 & 0xff ;
V_30 = F_2 ( V_2 -> V_16 , V_10 ,
V_121 ,
& V_2 -> V_114 ,
sizeof( V_2 -> V_114 ) ) ;
F_16 ( 1 , V_122 , & V_2 -> V_123 ,
L_4 ,
V_124 , V_6 , V_4 -> V_21 , V_4 -> V_14 , V_30 ,
( V_30 == 0 ? 0 : - V_101 ) ) ;
return ( V_30 == 0 ? 0 : V_101 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_30 ;
struct V_9 * V_125 ;
V_2 -> V_126 . V_127 = V_4 -> V_14 ;
V_125 = & V_2 -> V_11 [ V_128 ] -> V_33 [ 0 ] ;
V_30 = F_2 ( V_2 -> V_16 , V_125 ,
V_6 -> V_17 ,
& V_4 -> V_14 , sizeof( V_4 -> V_14 ) ) ;
V_30 = 0 ;
return V_30 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_129 ;
struct V_9 * V_125 ;
V_125 = & V_2 -> V_11 [ V_128 ] -> V_33 [ 0 ] ;
V_2 -> V_126 . V_130 = V_4 -> V_14 ;
switch ( V_4 -> V_14 ) {
default:
case V_131 :
V_129 = V_132 ;
break;
case V_133 :
V_129 = V_134 ;
break;
}
F_2 ( V_2 -> V_16 , V_125 ,
V_6 -> V_17 ,
& V_129 ,
sizeof( V_129 ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_18 ;
struct V_9 * V_135 ;
V_135 = & V_2 -> V_11 [ V_136 ] -> V_33 [ 0 ] ;
V_18 = V_4 -> V_14 ;
return F_2 ( V_2 -> V_16 , V_135 ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_1 V_18 ;
struct V_9 * V_137 ;
V_137 = & V_2 -> V_11 [ V_128 ] -> V_33 [ 0 ] ;
V_18 = V_4 -> V_14 ;
return F_2 ( V_2 -> V_16 , V_137 ,
V_6 -> V_17 ,
& V_18 , sizeof( V_18 ) ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_138 V_139 ;
int V_30 = 0 ;
if ( V_4 -> V_21 == V_140 ) {
switch ( V_4 -> V_14 ) {
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_2 -> V_126 . V_145 = V_4 -> V_14 ;
break;
default:
V_30 = - V_101 ;
break;
}
} else if ( V_4 -> V_21 == V_146 ) {
switch ( V_4 -> V_14 ) {
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
V_2 -> V_126 . V_159 = V_4 -> V_14 ;
break;
default:
V_30 = - V_101 ;
break;
}
}
if ( ! V_30 ) {
switch ( V_2 -> V_126 . V_145 ) {
case V_141 :
V_139 . V_160 = V_161 ;
break;
case V_142 :
V_139 . V_160 =
V_162 ;
break;
case V_143 :
V_139 . V_160 = V_163 ;
break;
case V_144 :
V_139 . V_160 = V_164 ;
break;
default:
break;
}
switch ( V_2 -> V_126 . V_159 ) {
case V_147 :
V_139 . V_165 = V_166 ;
break;
case V_148 :
V_139 . V_165 = V_167 ;
break;
case V_149 :
V_139 . V_165 = V_168 ;
break;
case V_150 :
V_139 . V_165 = V_169 ;
break;
case V_151 :
V_139 . V_165 = V_170 ;
break;
case V_152 :
V_139 . V_165 = V_171 ;
break;
case V_153 :
V_139 . V_165 = V_172 ;
break;
case V_154 :
V_139 . V_165 = V_173 ;
break;
case V_155 :
V_139 . V_165 = V_174 ;
break;
case V_156 :
V_139 . V_165 = V_175 ;
break;
case V_157 :
V_139 . V_165 = V_176 ;
break;
case V_158 :
V_139 . V_165 = V_177 ;
break;
default:
break;
}
V_30 = F_2 ( V_2 -> V_16 ,
& V_2 -> V_11 [ V_128 ] -> V_33 [ 0 ] ,
V_6 -> V_17 ,
& V_139 , sizeof( V_139 ) ) ;
}
return V_30 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_30 = 0 ;
int V_44 ;
struct V_9 * V_10 ;
F_16 ( 0 , V_122 , & V_2 -> V_123 ,
L_5 , V_4 -> V_14 ,
V_2 -> V_55 ) ;
V_10 = & V_2 -> V_11 [ V_12 ] -> V_10 ;
if ( V_4 -> V_14 == V_2 -> V_55 )
return 0 ;
if ( V_4 -> V_14 == V_56 ) {
V_2 -> V_55 = V_56 ;
if ( V_2 -> V_43 == V_51 )
V_44 = V_2 -> V_46 ;
else
V_44 = 0 ;
F_16 ( 0 , V_122 , & V_2 -> V_123 ,
L_6 ,
V_124 , V_44 , V_2 -> V_43 ,
V_2 -> V_59 ) ;
V_30 = F_2 ( V_2 -> V_16 ,
V_10 ,
V_45 ,
& V_44 ,
sizeof( V_44 ) ) ;
V_30 += F_2 ( V_2 -> V_16 ,
V_10 ,
V_47 ,
& V_2 -> V_43 ,
sizeof( T_1 ) ) ;
V_2 -> V_57 = V_2 -> V_43 ;
V_30 += F_2 ( V_2 -> V_16 ,
V_10 ,
V_178 ,
& V_2 -> V_59 ,
sizeof( T_1 ) ) ;
V_30 += F_9 ( V_2 ) ;
} else {
int V_102 ;
const struct V_179 * V_180 = NULL ;
int V_44 ;
enum V_41 V_181 ;
enum V_182 V_59 ;
for ( V_102 = 0 ; V_102 < F_15 ( V_183 ) ; V_102 ++ ) {
if ( V_183 [ V_102 ] . V_184 ==
V_4 -> V_14 ) {
V_180 = & V_183 [ V_102 ] ;
break;
}
}
if ( ! V_180 )
return - V_101 ;
if ( V_102 >= F_15 ( V_183 ) )
return - V_101 ;
V_2 -> V_55 = V_4 -> V_14 ;
if ( V_180 -> V_181 == V_51 )
V_44 = V_2 -> V_46 ;
else
V_44 = 0 ;
V_181 = V_180 -> V_181 ;
V_59 = V_180 -> V_59 ;
F_16 ( 1 , V_122 , & V_2 -> V_123 ,
L_6 ,
V_124 , V_44 , V_181 , V_59 ) ;
V_30 = F_2 ( V_2 -> V_16 , V_10 ,
V_45 ,
& V_44 ,
sizeof( V_44 ) ) ;
V_30 += F_2 ( V_2 -> V_16 , V_10 ,
V_47 ,
& V_181 ,
sizeof( T_1 ) ) ;
V_2 -> V_57 = V_181 ;
V_30 += F_2 ( V_2 -> V_16 , V_10 ,
V_47 ,
& V_181 ,
sizeof( T_1 ) ) ;
V_30 += F_2 ( V_2 -> V_16 , V_10 ,
V_178 ,
& V_59 ,
sizeof( T_1 ) ) ;
V_30 += F_9 ( V_2 ) ;
}
if ( V_30 ) {
F_16 ( 1 , V_122 , & V_2 -> V_123 ,
L_7 ,
V_124 , V_4 -> V_14 , V_30 ) ;
V_30 = - V_101 ;
}
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
F_25 ( V_4 -> V_185 , struct V_1 ,
V_186 ) ;
const struct V_5 * V_6 = V_4 -> V_187 ;
int V_30 ;
if ( ( V_6 == NULL ) ||
( V_6 -> V_21 != V_4 -> V_21 ) ||
( V_6 -> V_188 == NULL ) ) {
F_26 ( L_8 , V_6 , V_4 -> V_21 ) ;
return - V_101 ;
}
V_30 = V_6 -> V_188 ( V_2 , V_4 , V_6 ) ;
if ( V_30 )
F_26 ( L_9 ,
V_4 -> V_21 , V_6 -> V_17 , V_30 ) ;
if ( V_6 -> V_189 )
V_30 = 0 ;
return V_30 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_190 ;
int V_30 = 0 ;
for ( V_190 = 0 ; V_190 < V_191 ; V_190 ++ ) {
if ( ( V_2 -> V_192 [ V_190 ] ) && ( V_193 [ V_190 ] . V_188 ) ) {
V_30 = V_193 [ V_190 ] . V_188 ( V_2 , V_2 -> V_192 [ V_190 ] ,
& V_193 [ V_190 ] ) ;
if ( ! V_193 [ V_190 ] . V_189 && V_30 ) {
F_16 ( 1 , V_122 , & V_2 -> V_123 ,
L_10 ,
V_190 ) ;
break;
}
}
}
return V_30 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_194 V_195 ;
int V_30 ;
if ( ( V_2 -> V_57 != V_51 ) &&
( V_2 -> V_54 ) ) {
V_195 . V_196 . V_13 = 1 ;
V_195 . V_196 . V_15 = 1 ;
V_195 . V_197 . V_13 = V_2 -> V_126 . V_198 . V_199 ;
V_195 . V_197 . V_15 = V_2 -> V_126 . V_198 . V_200 ;
} else {
V_195 . V_196 . V_13 = V_195 . V_197 . V_13 =
V_2 -> V_126 . V_198 . V_199 ;
V_195 . V_196 . V_15 = V_195 . V_197 . V_15 =
V_2 -> V_126 . V_198 . V_200 ;
}
F_16 ( 1 , V_122 , & V_2 -> V_123 ,
L_11 ,
V_195 . V_196 . V_13 ,
V_195 . V_196 . V_15 ,
V_195 . V_197 . V_13 ,
V_195 . V_197 . V_15 ) ;
V_30 = F_2 ( V_2 -> V_16 ,
& V_2 -> V_11 [ V_12 ] ->
V_33 [ V_201 ] ,
V_202 ,
& V_195 , sizeof( V_195 ) ) ;
V_30 += F_2 ( V_2 -> V_16 ,
& V_2 -> V_11 [ V_12 ] ->
V_33 [ V_203 ] ,
V_202 ,
& V_195 , sizeof( V_195 ) ) ;
V_30 += F_2 ( V_2 -> V_16 ,
& V_2 -> V_11 [ V_12 ] ->
V_33 [ V_204 ] ,
V_202 ,
& V_195 , sizeof( V_195 ) ) ;
if ( V_30 )
F_16 ( 0 , V_122 , & V_2 -> V_123 ,
L_12 , V_30 ) ;
return V_30 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_205 * V_206 )
{
int V_190 ;
const struct V_5 * V_4 ;
F_29 ( V_206 , V_191 ) ;
for ( V_190 = 0 ; V_190 < V_191 ; V_190 ++ ) {
V_4 = & V_193 [ V_190 ] ;
switch ( V_4 -> type ) {
case V_207 :
V_2 -> V_192 [ V_190 ] = F_30 ( V_206 ,
& V_208 , V_4 -> V_21 ,
V_4 -> V_20 , V_4 -> V_19 , V_4 -> V_209 , V_4 -> V_210 ) ;
break;
case V_211 :
{
int V_212 = V_4 -> V_20 ;
if ( V_4 -> V_21 == V_213 ) {
int V_102 ;
V_212 = 1 << V_56 ;
for ( V_102 = 0 ;
V_102 < F_15 ( V_183 ) ;
V_102 ++ ) {
V_212 |= 1 << V_183 [ V_102 ] . V_184 ;
}
V_212 = ~ V_212 ;
}
V_2 -> V_192 [ V_190 ] = F_31 ( V_206 ,
& V_208 , V_4 -> V_21 ,
V_4 -> V_19 , V_212 , V_4 -> V_210 ) ;
break;
}
case V_214 :
V_2 -> V_192 [ V_190 ] = F_32 ( V_206 ,
& V_208 , V_4 -> V_21 ,
V_4 -> V_19 , V_4 -> V_210 , V_4 -> V_215 ) ;
break;
case V_216 :
continue;
}
if ( V_206 -> error )
break;
V_2 -> V_192 [ V_190 ] -> V_187 = ( void * ) V_4 ;
}
if ( V_206 -> error ) {
F_33 ( L_13 , V_190 ,
V_191 , V_4 -> V_21 ) ;
return V_206 -> error ;
}
for ( V_190 = 0 ; V_190 < V_191 ; V_190 ++ ) {
V_4 = & V_193 [ V_190 ] ;
switch ( V_4 -> type ) {
case V_216 :
F_34 ( V_4 -> V_20 ,
& V_2 -> V_192 [ V_190 + 1 ] ,
V_4 -> V_19 ,
V_4 -> V_210 ) ;
break;
case V_207 :
case V_211 :
case V_214 :
break;
}
}
return 0 ;
}
