static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
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
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_10 :
case V_49 :
case V_51 :
case V_52 :
case V_55 :
return 1 ;
default:
return 0 ;
}
}
static int F_3 ( int V_56 , int V_57 )
{
int V_58 , V_59 = - V_60 ;
T_1 V_61 , V_62 = 0 ;
for ( V_58 = 0 ; V_58 < F_4 ( V_63 ) ; V_58 ++ ) {
if ( V_63 [ V_58 ] . V_57 == V_57 ) {
V_61 = V_63 [ V_58 ] . V_56 ;
if ( abs ( V_56 - V_61 ) < abs ( V_56 - V_62 ) ) {
V_62 = V_61 ;
V_59 = V_58 ;
}
}
}
return V_59 ;
}
static int F_5 ( struct V_64 * V_65 ,
int V_66 , unsigned int V_67 , int V_68 )
{
struct V_69 * V_70 = V_65 -> V_70 ;
struct V_71 * V_72 = F_6 ( V_70 ) ;
if ( ( V_67 >= V_73 ) && ( V_67 <= V_74 ) ) {
V_72 -> V_75 = V_67 ;
} else {
F_7 ( V_70 -> V_2 , L_1 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_8 ( struct V_64 * V_65 , unsigned int V_76 )
{
struct V_69 * V_70 = V_65 -> V_70 ;
struct V_71 * V_72 = F_6 ( V_70 ) ;
T_2 V_77 = 0 ;
switch ( V_76 & V_78 ) {
case V_79 :
V_77 = V_80 ;
break;
case V_81 :
V_77 = V_82 ;
break;
default:
return - V_60 ;
}
switch ( V_76 & V_83 ) {
case V_84 :
V_77 |= V_85 |
V_86 ;
break;
case V_87 :
V_77 |= V_88 ;
break;
case V_89 :
V_77 |= V_90 |
V_91 ;
break;
case V_92 :
V_77 |= V_93 ;
break;
case V_94 :
break;
default:
return - V_60 ;
}
switch ( V_76 & V_95 ) {
case V_96 :
break;
case V_97 :
V_77 |= V_98 ;
break;
case V_99 :
V_77 |= V_98 ;
break;
case V_100 :
break;
default:
return - V_60 ;
}
V_72 -> V_101 . V_102 = V_77 ;
F_9 ( V_70 , V_9 , V_72 -> V_101 . V_102 ) ;
return 0 ;
}
static int F_10 ( struct V_64 * V_103 , int V_104 )
{
struct V_69 * V_70 = V_103 -> V_70 ;
if ( V_104 )
F_11 ( V_70 , V_16 ,
V_105 ,
V_106 ) ;
else
F_11 ( V_70 , V_16 ,
V_105 ,
V_107 ) ;
return 0 ;
}
static int F_12 ( struct V_108 * V_109 ,
struct V_110 * V_111 ,
struct V_64 * V_103 )
{
struct V_69 * V_70 = V_103 -> V_70 ;
struct V_71 * V_72 = F_6 ( V_70 ) ;
T_3 V_112 = 0 ;
int V_113 ;
V_113 = F_3 ( V_72 -> V_75 , F_13 ( V_111 ) ) ;
if ( V_113 >= 0 ) {
V_72 -> V_75 = V_63 [ V_113 ] . V_56 ;
V_112 |= ( V_63 [ V_113 ] . V_114 << V_115 ) |
( V_63 [ V_113 ] . V_116 << V_117 ) |
( V_63 [ V_113 ] . V_118 << V_119 ) |
( V_63 [ V_113 ] . V_120 << V_121 ) |
V_63 [ V_113 ] . V_122 ;
F_9 ( V_70 , V_8 , V_112 ) ;
} else {
F_7 ( V_70 -> V_2 , L_2 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_14 ( struct V_69 * V_70 ,
enum V_123 V_124 )
{
struct V_71 * V_72 = F_6 ( V_70 ) ;
switch ( V_124 ) {
case V_125 :
break;
case V_126 :
F_11 ( V_70 , V_5 ,
V_127 , 0 ) ;
break;
case V_128 :
if ( V_70 -> V_129 . V_130 == V_131 ) {
F_15 ( V_72 -> V_132 , false ) ;
F_16 ( V_72 -> V_132 ) ;
}
F_9 ( V_70 , V_5 , V_133 ) ;
break;
case V_131 :
F_9 ( V_70 , V_5 , V_133 ) ;
F_15 ( V_72 -> V_132 , true ) ;
break;
}
V_70 -> V_129 . V_130 = V_124 ;
return 0 ;
}
static int F_17 ( struct V_69 * V_70 )
{
F_14 ( V_70 , V_131 ) ;
return 0 ;
}
static int F_18 ( struct V_69 * V_70 )
{
F_14 ( V_70 , V_128 ) ;
return 0 ;
}
static void F_19 ( struct V_134 * V_135 )
{
struct V_71 * V_72 =
F_20 ( V_135 , struct V_71 , V_136 ) ;
struct V_69 * V_70 = V_72 -> V_70 ;
struct V_137 * V_129 = & V_70 -> V_129 ;
int V_58 ;
int V_138 = 0 ;
int V_139 = 0 ;
if ( V_72 -> V_140 ) {
for ( V_58 = 0 ; V_58 < F_4 ( V_141 ) ; V_58 ++ ) {
if ( abs ( V_72 -> V_140 - V_141 [ V_58 ] ) <
abs ( V_72 -> V_140 - V_141 [ V_139 ] ) )
V_139 = V_58 ;
}
F_21 ( V_70 -> V_2 , L_3 ,
V_141 [ V_139 ] , V_72 -> V_140 ) ;
V_138 = ( V_139 << V_142 ) ;
F_22 ( V_129 , L_4 ) ;
} else {
F_21 ( V_70 -> V_2 , L_5 ) ;
F_23 ( V_129 , L_4 ) ;
}
F_11 ( V_70 , V_31 ,
V_143 , V_138 ) ;
F_24 ( V_129 ) ;
}
static int F_25 ( struct V_144 * V_2 , unsigned int type ,
unsigned int V_145 , int V_146 )
{
struct V_69 * V_70 = F_26 ( V_2 ) ;
struct V_71 * V_72 = F_6 ( V_70 ) ;
F_21 ( V_70 -> V_2 , L_6 , V_145 , V_146 ) ;
switch ( V_145 ) {
case V_147 :
if ( V_146 )
V_146 = 261 ;
case V_148 :
break;
default:
return - 1 ;
}
V_72 -> V_140 = V_146 ;
F_27 ( & V_72 -> V_136 ) ;
return 0 ;
}
static T_4 F_28 ( struct V_1 * V_2 ,
struct V_149 * V_150 ,
const char * V_151 , T_5 V_152 )
{
struct V_71 * V_72 = F_29 ( V_2 ) ;
long int time ;
int V_59 ;
V_59 = F_30 ( V_151 , 10 , & time ) ;
if ( V_59 != 0 )
return V_59 ;
F_31 ( V_72 -> V_153 , V_154 , V_148 , time ) ;
return V_152 ;
}
static void F_32 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_6 ( V_70 ) ;
int V_59 ;
V_72 -> V_153 = F_33 ( V_70 -> V_2 ) ;
if ( ! V_72 -> V_153 ) {
F_7 ( V_70 -> V_2 , L_7 ) ;
return;
}
F_34 ( & V_72 -> V_136 , F_19 ) ;
V_72 -> V_140 = 0 ;
V_72 -> V_153 -> V_155 = L_8 ;
V_72 -> V_153 -> V_156 = F_35 ( V_70 -> V_2 ) ;
V_72 -> V_153 -> V_157 . V_158 = V_159 ;
V_72 -> V_153 -> V_160 [ 0 ] = F_36 ( V_154 ) ;
V_72 -> V_153 -> V_161 [ 0 ] = F_36 ( V_147 ) | F_36 ( V_148 ) ;
V_72 -> V_153 -> V_162 = F_25 ;
V_72 -> V_153 -> V_2 . V_163 = V_70 -> V_2 ;
F_37 ( V_72 -> V_153 , V_70 ) ;
V_59 = F_38 ( V_72 -> V_153 ) ;
if ( V_59 != 0 ) {
V_72 -> V_153 = NULL ;
F_7 ( V_70 -> V_2 , L_9 ) ;
}
V_59 = F_39 ( V_70 -> V_2 , & V_164 ) ;
if ( V_59 != 0 ) {
F_7 ( V_70 -> V_2 , L_10 ,
V_59 ) ;
}
}
static void F_40 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_6 ( V_70 ) ;
F_41 ( V_70 -> V_2 , & V_164 ) ;
F_42 ( & V_72 -> V_136 ) ;
V_72 -> V_153 = NULL ;
F_11 ( V_70 , V_33 ,
V_165 , 0 ) ;
}
static void F_32 ( struct V_69 * V_70 )
{
}
static void F_40 ( struct V_69 * V_70 )
{
}
static int F_43 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_6 ( V_70 ) ;
int V_59 ;
V_70 -> V_166 = V_72 -> V_132 ;
V_59 = F_44 ( V_70 , 8 , 8 , V_167 ) ;
if ( V_59 < 0 ) {
F_7 ( V_70 -> V_2 , L_11 , V_59 ) ;
return V_59 ;
}
F_15 ( V_72 -> V_132 , true ) ;
F_32 ( V_70 ) ;
F_14 ( V_70 , V_128 ) ;
V_72 -> V_75 = V_168 ;
V_72 -> V_101 . V_102 = V_169 ;
return V_59 ;
}
static int F_45 ( struct V_69 * V_70 )
{
F_40 ( V_70 ) ;
F_14 ( V_70 , V_131 ) ;
return 0 ;
}
static int F_46 ( struct V_170 * V_170 ,
const struct V_171 * V_157 )
{
struct V_71 * V_72 ;
struct V_172 * V_173 = F_47 ( & V_170 -> V_2 ) ;
int V_59 ;
unsigned int V_174 = 0 ;
unsigned int V_3 ;
V_72 = F_48 ( & V_170 -> V_2 , sizeof( struct V_71 ) ,
V_175 ) ;
if ( V_72 == NULL )
return - V_176 ;
V_72 -> V_2 = & V_170 -> V_2 ;
V_72 -> V_132 = F_49 ( V_170 , & V_177 ) ;
if ( F_50 ( V_72 -> V_132 ) ) {
V_59 = F_51 ( V_72 -> V_132 ) ;
F_7 ( & V_170 -> V_2 , L_12 , V_59 ) ;
return V_59 ;
}
if ( V_173 )
V_72 -> V_173 = * V_173 ;
if ( V_72 -> V_173 . V_178 ) {
V_59 = F_52 ( V_72 -> V_173 . V_178 ,
V_179 , L_13 ) ;
if ( V_59 < 0 ) {
F_7 ( & V_170 -> V_2 , L_14 ,
V_72 -> V_173 . V_178 , V_59 ) ;
return V_59 ;
}
F_53 ( V_72 -> V_173 . V_178 , 0 ) ;
F_53 ( V_72 -> V_173 . V_178 , 1 ) ;
}
F_54 ( V_170 , V_72 ) ;
V_59 = F_55 ( V_72 -> V_132 , V_180 ,
F_4 ( V_180 ) ) ;
if ( V_59 != 0 )
F_56 ( V_72 -> V_2 , L_15 ,
V_59 ) ;
V_59 = F_57 ( V_72 -> V_132 , V_4 , & V_3 ) ;
V_174 = V_3 & V_181 ;
if ( V_174 != V_182 ) {
V_59 = - V_183 ;
F_7 ( & V_170 -> V_2 ,
L_16 ,
V_174 , V_182 ) ;
return V_59 ;
}
F_58 ( & V_170 -> V_2 , L_17 ,
V_3 & 0xFF ) ;
if ( V_72 -> V_173 . V_184 )
F_59 ( V_72 -> V_132 , V_19 ,
V_185 ,
V_72 -> V_173 . V_184 <<
V_186 ) ;
if ( V_72 -> V_173 . V_187 )
F_59 ( V_72 -> V_132 , V_20 ,
V_185 ,
V_72 -> V_173 . V_187 <<
V_186 ) ;
if ( V_72 -> V_173 . V_188 )
F_59 ( V_72 -> V_132 , V_19 ,
V_189 ,
V_72 -> V_173 . V_188 <<
V_190 ) ;
if ( V_72 -> V_173 . V_191 )
F_59 ( V_72 -> V_132 , V_20 ,
V_189 ,
V_72 -> V_173 . V_191 <<
V_190 ) ;
if ( V_72 -> V_173 . V_192 )
F_59 ( V_72 -> V_132 , V_55 ,
V_193 ,
V_72 -> V_173 . V_192 <<
V_194 ) ;
if ( V_72 -> V_173 . V_195 )
F_59 ( V_72 -> V_132 , V_10 ,
V_196 ,
V_72 -> V_173 . V_195 ) ;
V_59 = F_60 ( & V_170 -> V_2 ,
& V_197 , & V_198 , 1 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
static int F_61 ( struct V_170 * V_199 )
{
F_62 ( & V_199 -> V_2 ) ;
return 0 ;
}
