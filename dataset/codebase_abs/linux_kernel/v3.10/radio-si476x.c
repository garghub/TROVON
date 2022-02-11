static inline bool F_1 ( T_1 V_1 , int V_2 )
{
return V_1 >= V_3 [ V_2 ] . V_4 &&
V_1 <= V_3 [ V_2 ] . V_5 ;
}
static inline bool F_2 ( T_1 V_6 , T_1 V_7 ,
int V_2 )
{
return V_6 >= V_3 [ V_2 ] . V_4 &&
V_7 <= V_3 [ V_2 ] . V_5 ;
}
static inline enum V_8
F_3 ( enum V_9 V_10 )
{
switch ( V_10 ) {
default:
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
case V_19 :
return V_20 ;
}
}
static inline enum V_9
F_4 ( enum V_8 V_21 )
{
static const int V_22 [] = {
[ V_12 ] = V_11 ,
[ V_14 ] = V_13 ,
[ V_16 ] = V_15 ,
[ V_18 ] = V_17 ,
[ V_20 ] = V_19 ,
} ;
return V_22 [ V_21 ] ;
}
static inline struct V_23 *
F_5 ( struct V_24 * V_25 )
{
return F_6 ( V_25 , struct V_23 , V_26 ) ;
}
static inline struct V_23 *
F_7 ( struct V_27 * V_25 )
{
return F_6 ( V_25 , struct V_23 , V_28 ) ;
}
static int F_8 ( struct V_29 * V_29 , void * V_30 ,
struct V_31 * V_32 )
{
struct V_23 * V_33 = F_9 ( V_29 ) ;
F_10 ( V_32 -> V_34 , V_33 -> V_26 . V_35 ,
sizeof( V_32 -> V_34 ) ) ;
F_10 ( V_32 -> V_36 , V_37 , sizeof( V_32 -> V_36 ) ) ;
snprintf ( V_32 -> V_38 , sizeof( V_32 -> V_38 ) ,
L_1 , V_33 -> V_26 . V_35 ) ;
V_32 -> V_39 = V_40
| V_41
| V_42 ;
F_11 ( V_33 -> V_43 ) ;
if ( ! F_12 ( V_33 -> V_43 ) )
V_32 -> V_39 |= V_44
| V_45 ;
F_13 ( V_33 -> V_43 ) ;
V_32 -> V_46 = V_32 -> V_39
| V_47 ;
return 0 ;
}
static int F_14 ( struct V_29 * V_29 , void * V_30 ,
struct V_48 * V_2 )
{
int V_49 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
if ( V_2 -> V_50 != 0 )
return - V_51 ;
switch ( V_33 -> V_43 -> V_52 ) {
case V_53 :
case V_54 :
if ( V_2 -> V_55 < F_15 ( V_3 ) ) {
* V_2 = V_3 [ V_2 -> V_55 ] ;
V_49 = 0 ;
} else {
V_49 = - V_51 ;
}
break;
case V_56 :
if ( V_2 -> V_55 == V_57 ) {
* V_2 = V_3 [ V_2 -> V_55 ] ;
V_49 = 0 ;
} else {
V_49 = - V_51 ;
}
break;
default:
V_49 = - V_51 ;
}
return V_49 ;
}
static int F_16 ( struct V_29 * V_29 , void * V_30 ,
struct V_58 * V_50 )
{
int V_49 ;
struct V_59 V_60 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
struct V_61 args = {
. V_62 = false ,
. V_63 = false ,
. V_64 = false ,
. V_65 = false ,
. V_66 = false ,
} ;
if ( V_50 -> V_55 != 0 )
return - V_51 ;
V_50 -> type = V_67 ;
V_50 -> V_32 = V_68
| V_69
| V_70
| V_71
| V_72 ;
F_11 ( V_33 -> V_43 ) ;
if ( F_12 ( V_33 -> V_43 ) ) {
F_10 ( V_50 -> V_35 , L_2 , sizeof( V_50 -> V_35 ) ) ;
V_50 -> V_73 = 0 ;
V_50 -> V_4 = V_3 [ V_57 ] . V_4 ;
} else if ( F_17 ( V_33 -> V_43 ) ) {
if ( F_18 ( V_33 -> V_43 ) )
F_10 ( V_50 -> V_35 , L_3 ,
sizeof( V_50 -> V_35 ) ) ;
else
F_10 ( V_50 -> V_35 , L_4 , sizeof( V_50 -> V_35 ) ) ;
V_50 -> V_73 = V_74 | V_75
| V_76 ;
V_50 -> V_32 |= V_77
| V_78
| V_79 ;
V_50 -> V_4 = V_3 [ V_80 ] . V_4 ;
} else {
F_10 ( V_50 -> V_35 , L_5 , sizeof( V_50 -> V_35 ) ) ;
V_50 -> V_73 = V_76 ;
V_50 -> V_32 |= V_77
| V_78
| V_79 ;
V_50 -> V_4 = V_3 [ V_57 ] . V_4 ;
}
V_50 -> V_81 = V_33 -> V_81 ;
V_50 -> V_82 = 1 ;
V_50 -> V_5 = V_3 [ V_57 ] . V_5 ;
V_49 = V_33 -> V_83 -> V_84 ( V_33 -> V_43 ,
& args , & V_60 ) ;
if ( V_49 < 0 ) {
V_50 -> signal = 0 ;
} else {
V_50 -> signal = ( V_60 . V_85 + 128 ) * 257 ;
}
F_13 ( V_33 -> V_43 ) ;
return V_49 ;
}
static int F_19 ( struct V_29 * V_29 , void * V_30 ,
const struct V_58 * V_50 )
{
struct V_23 * V_33 = F_9 ( V_29 ) ;
if ( V_50 -> V_55 != 0 )
return - V_51 ;
if ( V_50 -> V_81 == V_86 ||
V_50 -> V_81 == V_87 )
V_33 -> V_81 = V_50 -> V_81 ;
else
V_33 -> V_81 = V_87 ;
return 0 ;
}
static int F_20 ( struct V_23 * V_33 ,
enum V_88 V_89 )
{
static const struct V_90 V_91 = {
. V_92 = V_93 ,
. V_94 = V_95 ,
. V_84 = V_96 ,
. V_97 = V_98 ,
. V_99 = V_100 ,
. V_101 = V_102 ,
. V_103 = V_104 ,
. V_105 = V_106 ,
} ;
static const struct V_90 V_107 = {
. V_92 = V_108 ,
. V_94 = V_109 ,
. V_84 = V_110 ,
. V_97 = NULL ,
. V_99 = NULL ,
. V_101 = NULL ,
. V_103 = V_111 ,
. V_105 = NULL ,
} ;
switch ( V_89 ) {
case V_112 :
V_33 -> V_83 = & V_91 ;
return 0 ;
case V_113 :
V_33 -> V_83 = & V_107 ;
return 0 ;
default:
F_21 ( 1 , L_6 ) ;
return - V_51 ;
}
}
static int F_22 ( struct V_23 * V_33 ,
enum V_88 V_89 )
{
int V_114 ;
struct V_115 args = {
. V_116 = false ,
. V_117 = false ,
. V_118 = V_119 ,
. V_120 = V_121 ,
. V_122 = V_123 ,
. V_124 = 0 ,
} ;
switch ( V_89 ) {
case V_112 :
args . V_1 = F_23 ( V_33 -> V_43 ,
92 * V_125 ) ;
V_114 = V_33 -> V_83 -> V_92 ( V_33 -> V_43 , & args ) ;
break;
case V_113 :
args . V_1 = F_23 ( V_33 -> V_43 ,
0.6 * V_125 ) ;
V_114 = V_33 -> V_83 -> V_92 ( V_33 -> V_43 , & args ) ;
break;
default:
F_21 ( 1 , L_6 ) ;
V_114 = - V_51 ;
}
return V_114 ;
}
static int F_24 ( struct V_23 * V_33 ,
enum V_88 V_89 )
{
int V_49 ;
V_49 = F_25 ( V_33 -> V_43 -> V_126 ,
V_127 ,
V_128 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_25 ( V_33 -> V_43 -> V_126 ,
V_129 ,
V_130 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_25 ( V_33 -> V_43 -> V_126 ,
V_131 ,
V_131 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_25 ( V_33 -> V_43 -> V_126 ,
V_132 ,
V_132 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_25 ( V_33 -> V_43 -> V_126 ,
V_133 ,
V_134 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_89 == V_112 ) {
if ( F_26 ( V_33 -> V_43 ) ) {
V_49 = V_100 ( V_33 -> V_43 ,
V_33 -> V_43 -> V_135 ) ;
if ( V_49 < 0 )
return V_49 ;
}
V_49 = F_25 ( V_33 -> V_43 -> V_126 ,
V_136 ,
V_137 ) ;
if ( V_49 < 0 )
return V_49 ;
}
return F_20 ( V_33 , V_89 ) ;
}
static int F_27 ( struct V_23 * V_33 ,
enum V_88 V_89 )
{
int V_49 ;
bool V_138 ;
if ( V_89 == V_33 -> V_43 -> V_139 . V_89 )
return 0 ;
V_138 = true ;
V_49 = F_28 ( V_33 -> V_43 , V_138 ) ;
if ( V_49 < 0 ) {
V_138 = false ;
V_49 = F_28 ( V_33 -> V_43 , V_138 ) ;
if ( V_49 < 0 )
return V_49 ;
}
V_33 -> V_43 -> V_139 . V_89 = V_89 ;
V_49 = F_29 ( V_33 -> V_43 , V_138 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_89 != V_112 &&
V_89 != V_113 )
return V_49 ;
return F_24 ( V_33 , V_89 ) ;
}
static int F_30 ( struct V_29 * V_29 , void * V_30 ,
struct V_140 * V_141 )
{
int V_49 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
if ( V_141 -> V_50 != 0 ||
V_141 -> type != V_67 )
return - V_51 ;
F_11 ( V_33 -> V_43 ) ;
if ( V_33 -> V_83 -> V_84 ) {
struct V_59 V_60 ;
struct V_61 args = {
. V_62 = false ,
. V_63 = false ,
. V_64 = true ,
. V_65 = false ,
. V_66 = false ,
} ;
V_49 = V_33 -> V_83 -> V_84 ( V_33 -> V_43 , & args , & V_60 ) ;
if ( ! V_49 )
V_141 -> V_142 = F_31 ( V_33 -> V_43 ,
V_60 . V_143 ) ;
} else {
V_49 = - V_51 ;
}
F_13 ( V_33 -> V_43 ) ;
return V_49 ;
}
static int F_32 ( struct V_29 * V_29 , void * V_30 ,
const struct V_140 * V_141 )
{
int V_49 ;
T_1 V_1 = V_141 -> V_142 ;
struct V_115 args ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
const T_1 V_144 = ( V_3 [ V_80 ] . V_5 +
V_3 [ V_57 ] . V_4 ) / 2 ;
const int V_2 = ( V_1 > V_144 ) ?
V_57 : V_80 ;
const enum V_88 V_89 = ( V_2 == V_80 ) ?
V_113 : V_112 ;
if ( V_141 -> V_50 != 0 ||
V_141 -> type != V_67 )
return - V_51 ;
F_11 ( V_33 -> V_43 ) ;
V_1 = F_33 ( V_1 ,
V_3 [ V_2 ] . V_4 ,
V_3 [ V_2 ] . V_5 ) ;
if ( F_1 ( V_1 ,
V_80 ) &&
( ! F_17 ( V_33 -> V_43 ) ||
F_12 ( V_33 -> V_43 ) ) ) {
V_49 = - V_51 ;
goto V_145;
}
V_49 = F_27 ( V_33 , V_89 ) ;
if ( V_49 < 0 )
goto V_145;
args . V_116 = false ;
args . V_117 = false ;
args . V_118 = V_119 ;
args . V_1 = F_23 ( V_33 -> V_43 , V_1 ) ;
args . V_120 = V_121 ;
args . V_122 = V_123 ;
args . V_124 = 0 ;
V_49 = V_33 -> V_83 -> V_92 ( V_33 -> V_43 , & args ) ;
V_145:
F_13 ( V_33 -> V_43 ) ;
return V_49 ;
}
static int F_34 ( struct V_29 * V_29 , void * V_30 ,
const struct V_146 * V_147 )
{
int V_49 ;
enum V_88 V_89 ;
T_1 V_4 , V_5 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
if ( V_29 -> V_148 & V_149 )
return - V_150 ;
if ( V_147 -> V_50 != 0 ||
V_147 -> type != V_67 )
return - V_51 ;
F_11 ( V_33 -> V_43 ) ;
if ( ! V_147 -> V_4 ) {
V_49 = F_35 ( V_33 -> V_43 -> V_126 ,
V_151 ,
& V_4 ) ;
if ( ! V_49 )
V_4 = F_31 ( V_33 -> V_43 , V_4 ) ;
else
goto V_145;
}
if ( ! V_147 -> V_5 ) {
V_49 = F_35 ( V_33 -> V_43 -> V_126 ,
V_152 ,
& V_5 ) ;
if ( ! V_49 )
V_5 = F_31 ( V_33 -> V_43 , V_5 ) ;
else
goto V_145;
}
if ( V_4 > V_5 ) {
V_49 = - V_51 ;
goto V_145;
}
if ( F_2 ( V_4 , V_5 ,
V_57 ) ) {
V_89 = V_112 ;
} else if ( F_17 ( V_33 -> V_43 ) &&
F_2 ( V_4 , V_5 ,
V_80 ) ) {
V_89 = V_113 ;
} else {
V_49 = - V_51 ;
goto V_145;
}
V_49 = F_27 ( V_33 , V_89 ) ;
if ( V_49 < 0 )
goto V_145;
if ( V_147 -> V_5 ) {
V_49 = F_36 ( V_33 -> V_43 -> V_126 ,
V_152 ,
F_23 ( V_33 -> V_43 ,
V_147 -> V_5 ) ) ;
if ( V_49 )
goto V_145;
}
if ( V_147 -> V_4 ) {
V_49 = F_36 ( V_33 -> V_43 -> V_126 ,
V_151 ,
F_23 ( V_33 -> V_43 ,
V_147 -> V_4 ) ) ;
if ( V_49 )
goto V_145;
}
if ( V_147 -> V_153 ) {
V_49 = F_36 ( V_33 -> V_43 -> V_126 ,
V_154 ,
F_23 ( V_33 -> V_43 ,
V_147 -> V_153 ) ) ;
if ( V_49 )
goto V_145;
}
V_49 = V_33 -> V_83 -> V_94 ( V_33 -> V_43 ,
V_147 -> V_155 ,
V_147 -> V_156 ) ;
V_145:
F_13 ( V_33 -> V_43 ) ;
return V_49 ;
}
static int F_37 ( struct V_157 * V_158 )
{
int V_114 ;
struct V_23 * V_33 = F_7 ( V_158 -> V_159 ) ;
F_11 ( V_33 -> V_43 ) ;
switch ( V_158 -> V_160 ) {
case V_161 :
if ( F_26 ( V_33 -> V_43 ) ) {
if ( V_33 -> V_83 -> V_99 ) {
V_114 = V_33 -> V_83 -> V_101 ( V_33 -> V_43 ) ;
if ( V_114 < 0 )
break;
V_158 -> V_162 = ! ! F_38 ( V_114 ) ;
V_114 = 0 ;
break;
} else {
V_114 = - V_163 ;
break;
}
}
V_114 = - V_51 ;
break;
default:
V_114 = - V_51 ;
break;
}
F_13 ( V_33 -> V_43 ) ;
return V_114 ;
}
static int F_39 ( struct V_157 * V_158 )
{
int V_114 ;
enum V_9 V_10 ;
struct V_23 * V_33 = F_7 ( V_158 -> V_159 ) ;
F_11 ( V_33 -> V_43 ) ;
switch ( V_158 -> V_160 ) {
case V_164 :
V_114 = F_40 ( V_33 -> V_43 -> V_126 ,
V_130 ,
V_165 ,
V_158 -> V_162 ) ;
break;
case V_166 :
switch ( V_158 -> V_162 ) {
case V_167 :
V_114 = F_40 ( V_33 -> V_43 -> V_126 ,
V_130 ,
V_168 ,
0 ) ;
break;
case V_169 :
V_114 = F_40 ( V_33 -> V_43 -> V_126 ,
V_130 ,
V_170 ,
V_171 ) ;
break;
case V_172 :
V_114 = F_40 ( V_33 -> V_43 -> V_126 ,
V_130 ,
V_170 ,
V_173 ) ;
break;
default:
V_114 = - V_51 ;
break;
}
break;
case V_174 :
V_114 = F_36 ( V_33 -> V_43 -> V_126 ,
V_134 ,
V_158 -> V_162 ) ;
break;
case V_175 :
V_114 = F_36 ( V_33 -> V_43 -> V_126 ,
V_133 ,
V_158 -> V_162 ) ;
break;
case V_176 :
V_114 = F_36 ( V_33 -> V_43 -> V_126 ,
V_132 ,
V_158 -> V_162 ) ;
break;
case V_177 :
if ( F_41 ( V_33 -> V_43 ) )
F_42 ( V_33 -> V_43 -> V_126 , true ) ;
if ( V_158 -> V_162 ) {
V_114 = F_36 ( V_33 -> V_43 -> V_126 ,
V_178 ,
V_33 -> V_43 -> V_179 ) ;
if ( V_114 < 0 )
break;
if ( V_33 -> V_43 -> V_180 -> V_181 ) {
V_114 = F_36 ( V_33 -> V_43 -> V_126 ,
V_136 ,
V_182 ) ;
if ( V_114 < 0 )
break;
}
V_114 = F_43 ( V_33 -> V_43 ,
false ,
true ,
true ,
NULL ) ;
if ( V_114 < 0 )
break;
V_114 = F_40 ( V_33 -> V_43 -> V_126 ,
V_137 ,
V_183 ,
V_184 ) ;
} else {
V_114 = F_40 ( V_33 -> V_43 -> V_126 ,
V_137 ,
V_183 ,
! V_184 ) ;
}
if ( F_41 ( V_33 -> V_43 ) )
F_42 ( V_33 -> V_43 -> V_126 , false ) ;
break;
case V_185 :
V_114 = F_36 ( V_33 -> V_43 -> V_126 ,
V_129 ,
V_158 -> V_162 ) ;
break;
case V_186 :
V_10 = F_4 ( V_158 -> V_162 ) ;
if ( V_10 == V_33 -> V_43 -> V_135 ) {
V_114 = 0 ;
break;
}
if ( F_41 ( V_33 -> V_43 ) ) {
V_33 -> V_43 -> V_135 = V_10 ;
V_114 = 0 ;
} else {
V_114 = V_33 -> V_83 -> V_99 ( V_33 -> V_43 , V_10 ) ;
if ( ! V_114 )
V_33 -> V_43 -> V_135 = V_10 ;
}
break;
default:
V_114 = - V_51 ;
break;
}
F_13 ( V_33 -> V_43 ) ;
return V_114 ;
}
static int F_44 ( struct V_29 * V_29 , void * V_187 ,
struct V_188 * V_189 )
{
if ( V_189 -> V_190 . type == V_191 &&
F_45 ( & V_189 -> V_190 ) )
return 0 ;
return - V_51 ;
}
static int F_46 ( struct V_29 * V_29 , void * V_187 ,
struct V_192 * V_193 )
{
int V_49 ;
unsigned int V_194 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
F_11 ( V_33 -> V_43 ) ;
V_193 -> V_195 = 2 ;
V_49 = F_35 ( V_33 -> V_43 -> V_126 ,
( unsigned int ) V_193 -> V_193 , & V_194 ) ;
V_193 -> V_162 = V_194 ;
F_13 ( V_33 -> V_43 ) ;
return V_49 ;
}
static int F_47 ( struct V_29 * V_29 , void * V_187 ,
const struct V_192 * V_193 )
{
int V_49 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
F_11 ( V_33 -> V_43 ) ;
V_49 = F_36 ( V_33 -> V_43 -> V_126 ,
( unsigned int ) V_193 -> V_193 ,
( unsigned int ) V_193 -> V_162 ) ;
F_13 ( V_33 -> V_43 ) ;
return V_49 ;
}
static int F_48 ( struct V_29 * V_29 )
{
struct V_23 * V_33 = F_9 ( V_29 ) ;
int V_49 ;
V_49 = F_49 ( V_29 ) ;
if ( V_49 )
return V_49 ;
if ( F_50 ( V_29 ) ) {
F_11 ( V_33 -> V_43 ) ;
V_49 = F_51 ( V_33 -> V_43 ,
V_196 ) ;
if ( V_49 < 0 )
goto V_197;
V_49 = F_24 ( V_33 ,
V_33 -> V_43 -> V_139 . V_89 ) ;
if ( V_49 < 0 )
goto V_198;
V_49 = F_22 ( V_33 ,
V_33 -> V_43 -> V_139 . V_89 ) ;
if ( V_49 < 0 )
goto V_198;
F_13 ( V_33 -> V_43 ) ;
F_52 ( & V_33 -> V_28 ) ;
}
return V_49 ;
V_198:
F_51 ( V_33 -> V_43 ,
V_199 ) ;
V_197:
F_13 ( V_33 -> V_43 ) ;
F_53 ( V_29 ) ;
return V_49 ;
}
static int F_54 ( struct V_29 * V_29 )
{
int V_49 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
if ( F_50 ( V_29 ) &&
F_55 ( & V_33 -> V_43 -> V_200 ) )
F_51 ( V_33 -> V_43 ,
V_199 ) ;
V_49 = F_53 ( V_29 ) ;
return V_49 ;
}
static T_2 F_56 ( struct V_29 * V_29 , char T_3 * V_201 ,
T_4 V_202 , T_5 * V_203 )
{
T_2 V_204 ;
T_4 V_205 ;
unsigned int V_206 ;
struct V_23 * V_33 = F_9 ( V_29 ) ;
if ( F_57 ( & V_33 -> V_43 -> V_207 ) ) {
if ( V_29 -> V_148 & V_149 )
return - V_208 ;
V_204 = F_58 ( V_33 -> V_43 -> V_209 ,
( ! F_57 ( & V_33 -> V_43 -> V_207 ) ||
! F_55 ( & V_33 -> V_43 -> V_200 ) ) ) ;
if ( V_204 < 0 )
return - V_210 ;
if ( ! F_55 ( & V_33 -> V_43 -> V_200 ) )
return - V_211 ;
}
V_205 = F_59 ( & V_33 -> V_43 -> V_207 ) ;
if ( F_60 ( & V_33 -> V_43 -> V_207 , V_201 ,
F_61 ( V_205 , V_202 ) ,
& V_206 ) != 0 ) {
F_62 ( & V_33 -> V_212 . V_213 ,
L_7 ) ;
V_204 = - V_214 ;
} else {
V_204 = ( T_2 ) V_206 ;
}
return V_204 ;
}
static unsigned int F_63 ( struct V_29 * V_29 ,
struct V_215 * V_216 )
{
struct V_23 * V_33 = F_9 ( V_29 ) ;
unsigned long V_217 = F_64 ( V_216 ) ;
unsigned int V_49 = F_65 ( V_29 , V_216 ) ;
if ( V_217 & ( V_218 | V_219 ) ) {
if ( F_55 ( & V_33 -> V_43 -> V_200 ) )
F_66 ( V_29 , & V_33 -> V_43 -> V_209 , V_216 ) ;
if ( ! F_55 ( & V_33 -> V_43 -> V_200 ) )
V_49 = V_220 ;
if ( ! F_57 ( & V_33 -> V_43 -> V_207 ) )
V_49 = V_218 | V_219 ;
}
return V_49 ;
}
static T_2 F_67 ( struct V_29 * V_29 ,
char T_3 * V_221 ,
T_4 V_202 , T_5 * V_203 )
{
int V_49 ;
struct V_23 * V_33 = V_29 -> V_222 ;
struct V_223 V_60 ;
F_11 ( V_33 -> V_43 ) ;
if ( V_33 -> V_83 -> V_103 )
V_49 = V_33 -> V_83 -> V_103 ( V_33 -> V_43 , & V_60 ) ;
else
V_49 = - V_224 ;
F_13 ( V_33 -> V_43 ) ;
if ( V_49 < 0 )
return V_49 ;
return F_68 ( V_221 , V_202 , V_203 , & V_60 ,
sizeof( V_60 ) ) ;
}
static T_2 F_69 ( struct V_29 * V_29 ,
char T_3 * V_221 ,
T_4 V_202 , T_5 * V_203 )
{
int V_49 ;
struct V_23 * V_33 = V_29 -> V_222 ;
struct V_225 V_60 ;
F_11 ( V_33 -> V_43 ) ;
if ( V_33 -> V_83 -> V_97 )
V_49 = V_33 -> V_83 -> V_97 ( V_33 -> V_43 , true ,
& V_60 ) ;
else
V_49 = - V_224 ;
F_13 ( V_33 -> V_43 ) ;
if ( V_49 < 0 )
return V_49 ;
return F_68 ( V_221 , V_202 , V_203 , & V_60 ,
sizeof( V_60 ) ) ;
}
static T_2 F_70 ( struct V_29 * V_29 ,
char T_3 * V_221 ,
T_4 V_202 , T_5 * V_203 )
{
int V_49 ;
struct V_23 * V_33 = V_29 -> V_222 ;
struct V_226 V_60 ;
F_11 ( V_33 -> V_43 ) ;
if ( V_33 -> V_83 -> V_97 )
V_49 = V_33 -> V_83 -> V_105 ( V_33 -> V_43 , & V_60 ) ;
else
V_49 = - V_224 ;
F_13 ( V_33 -> V_43 ) ;
if ( V_49 < 0 )
return V_49 ;
return F_68 ( V_221 , V_202 , V_203 , & V_60 ,
sizeof( V_60 ) ) ;
}
static T_2 F_71 ( struct V_29 * V_29 ,
char T_3 * V_221 ,
T_4 V_202 , T_5 * V_203 )
{
int V_49 ;
struct V_23 * V_33 = V_29 -> V_222 ;
struct V_59 V_60 ;
struct V_61 args = {
. V_62 = false ,
. V_63 = false ,
. V_64 = false ,
. V_65 = false ,
. V_66 = false ,
} ;
F_11 ( V_33 -> V_43 ) ;
if ( V_33 -> V_83 -> V_97 )
V_49 = V_33 -> V_83 -> V_84 ( V_33 -> V_43 , & args , & V_60 ) ;
else
V_49 = - V_224 ;
F_13 ( V_33 -> V_43 ) ;
if ( V_49 < 0 )
return V_49 ;
return F_68 ( V_221 , V_202 , V_203 , & V_60 ,
sizeof( V_60 ) ) ;
}
static T_2 F_72 ( struct V_29 * V_29 ,
char T_3 * V_221 ,
T_4 V_202 , T_5 * V_203 )
{
int V_49 ;
struct V_23 * V_33 = V_29 -> V_222 ;
struct V_59 V_60 ;
struct V_61 args = {
. V_62 = true ,
. V_63 = false ,
. V_64 = false ,
. V_65 = false ,
. V_66 = false ,
} ;
F_11 ( V_33 -> V_43 ) ;
if ( V_33 -> V_83 -> V_97 )
V_49 = V_33 -> V_83 -> V_84 ( V_33 -> V_43 , & args , & V_60 ) ;
else
V_49 = - V_224 ;
F_13 ( V_33 -> V_43 ) ;
if ( V_49 < 0 )
return V_49 ;
return F_68 ( V_221 , V_202 , V_203 , & V_60 ,
sizeof( V_60 ) ) ;
}
static int F_73 ( struct V_23 * V_33 )
{
struct V_227 * V_227 ;
int V_228 ;
V_227 = F_74 ( F_75 ( V_33 -> V_26 . V_213 ) , NULL ) ;
if ( F_76 ( V_227 ) ) {
V_228 = F_77 ( V_227 ) ;
goto exit;
}
V_33 -> V_229 = V_227 ;
V_227 = F_78 ( L_8 , V_230 ,
V_33 -> V_229 , V_33 , & V_231 ) ;
if ( F_76 ( V_227 ) ) {
V_228 = F_77 ( V_227 ) ;
goto V_232;
}
V_227 = F_78 ( L_9 , V_230 ,
V_33 -> V_229 , V_33 ,
& V_233 ) ;
if ( F_76 ( V_227 ) ) {
V_228 = F_77 ( V_227 ) ;
goto V_232;
}
V_227 = F_78 ( L_10 , V_230 ,
V_33 -> V_229 , V_33 , & V_234 ) ;
if ( F_76 ( V_227 ) ) {
V_228 = F_77 ( V_227 ) ;
goto V_232;
}
V_227 = F_78 ( L_11 , V_230 ,
V_33 -> V_229 , V_33 , & V_235 ) ;
if ( F_76 ( V_227 ) ) {
V_228 = F_77 ( V_227 ) ;
goto V_232;
}
V_227 = F_78 ( L_12 , V_230 ,
V_33 -> V_229 , V_33 ,
& V_236 ) ;
if ( F_76 ( V_227 ) ) {
V_228 = F_77 ( V_227 ) ;
goto V_232;
}
return 0 ;
V_232:
F_79 ( V_33 -> V_229 ) ;
exit:
return V_228 ;
}
static int F_80 ( struct V_23 * V_33 ,
enum V_237 V_21 )
{
int V_204 ;
struct V_157 * V_158 ;
V_158 = F_81 ( & V_33 -> V_28 ,
& V_238 [ V_21 ] ,
NULL ) ;
V_204 = V_33 -> V_28 . error ;
if ( V_158 == NULL && V_204 )
F_82 ( V_33 -> V_26 . V_213 ,
L_13 ,
V_238 [ V_21 ] . V_35 , V_204 ) ;
return V_204 ;
}
static int F_83 ( struct V_239 * V_240 )
{
int V_204 ;
struct V_23 * V_33 ;
struct V_157 * V_158 ;
static T_6 V_241 = F_84 ( 0 ) ;
V_33 = F_85 ( & V_240 -> V_213 , sizeof( * V_33 ) , V_242 ) ;
if ( ! V_33 )
return - V_243 ;
V_33 -> V_43 = F_86 ( & V_240 -> V_213 ) ;
F_87 ( & V_33 -> V_26 , V_244 , & V_241 ) ;
V_204 = F_88 ( & V_240 -> V_213 , & V_33 -> V_26 ) ;
if ( V_204 ) {
F_82 ( & V_240 -> V_213 , L_14 ) ;
return V_204 ;
}
memcpy ( & V_33 -> V_212 , & V_245 ,
sizeof( struct V_246 ) ) ;
V_33 -> V_212 . V_247 = & V_33 -> V_26 ;
V_33 -> V_212 . V_248 = & V_249 ;
F_89 ( & V_33 -> V_212 , V_33 ) ;
F_90 ( V_240 , V_33 ) ;
F_91 ( V_250 , & V_33 -> V_212 . V_251 ) ;
V_33 -> V_26 . V_28 = & V_33 -> V_28 ;
F_92 ( & V_33 -> V_28 ,
1 + F_15 ( V_238 ) ) ;
if ( F_17 ( V_33 -> V_43 ) ) {
V_158 = F_93 ( & V_33 -> V_28 ,
& V_252 ,
V_166 ,
V_172 ,
0 , 0 ) ;
V_204 = V_33 -> V_28 . error ;
if ( V_158 == NULL && V_204 ) {
F_82 ( & V_240 -> V_213 , L_15 ,
V_204 ) ;
goto exit;
}
V_204 = F_80 ( V_33 ,
V_253 ) ;
if ( V_204 < 0 )
goto exit;
}
V_204 = F_80 ( V_33 , V_254 ) ;
if ( V_204 < 0 )
goto exit;
V_204 = F_80 ( V_33 , V_255 ) ;
if ( V_204 < 0 )
goto exit;
V_204 = F_80 ( V_33 , V_256 ) ;
if ( V_204 < 0 )
goto exit;
V_158 = F_93 ( & V_33 -> V_28 ,
& V_252 ,
V_185 ,
V_257 , 0 , 0 ) ;
V_204 = V_33 -> V_28 . error ;
if ( V_158 == NULL && V_204 ) {
F_82 ( & V_240 -> V_213 , L_16 ,
V_204 ) ;
goto exit;
}
V_158 = F_94 ( & V_33 -> V_28 , & V_252 ,
V_177 ,
0 , 1 , 1 , 1 ) ;
V_204 = V_33 -> V_28 . error ;
if ( V_158 == NULL && V_204 ) {
F_82 ( & V_240 -> V_213 , L_17 ,
V_204 ) ;
goto exit;
}
if ( F_26 ( V_33 -> V_43 ) ) {
V_238 [ V_258 ] . V_259 =
F_3 ( V_33 -> V_43 -> V_135 ) ;
F_80 ( V_33 , V_258 ) ;
if ( V_204 < 0 )
goto exit;
F_80 ( V_33 , V_260 ) ;
if ( V_204 < 0 )
goto exit;
}
V_204 = F_95 ( & V_33 -> V_212 , V_261 , - 1 ) ;
if ( V_204 < 0 ) {
F_82 ( & V_240 -> V_213 , L_18 ) ;
goto exit;
}
V_204 = F_73 ( V_33 ) ;
if ( V_204 < 0 ) {
F_82 ( & V_240 -> V_213 , L_19 ) ;
goto exit;
}
return 0 ;
exit:
F_96 ( V_33 -> V_212 . V_28 ) ;
return V_204 ;
}
static int F_97 ( struct V_239 * V_240 )
{
struct V_23 * V_33 = F_98 ( V_240 ) ;
F_96 ( V_33 -> V_212 . V_28 ) ;
F_99 ( & V_33 -> V_212 ) ;
F_100 ( & V_33 -> V_26 ) ;
F_79 ( V_33 -> V_229 ) ;
return 0 ;
}
