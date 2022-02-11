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
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_4 ( V_57 ) ;
struct V_60 * V_61 = & V_59 -> V_61 ;
if ( ! V_61 -> V_62 )
F_5 ( V_57 , V_63 ,
F_6 ( V_63 ) ) ;
if ( ! V_61 -> V_64 )
F_5 ( V_57 , V_65 ,
F_6 ( V_65 ) ) ;
return 0 ;
}
static int F_7 ( int V_66 , int V_67 )
{
int V_68 , V_69 = - V_70 ;
T_1 V_71 , V_72 = 0 ;
for ( V_68 = 0 ; V_68 < F_6 ( V_73 ) ; V_68 ++ ) {
if ( V_73 [ V_68 ] . V_67 == V_67 ) {
V_71 = V_73 [ V_68 ] . V_66 ;
if ( abs ( V_66 - V_71 ) < abs ( V_66 - V_72 ) ) {
V_72 = V_71 ;
V_69 = V_68 ;
}
}
}
return V_69 ;
}
static int F_8 ( struct V_74 * V_75 ,
int V_76 , unsigned int V_77 , int V_78 )
{
struct V_56 * V_57 = V_75 -> V_57 ;
struct V_58 * V_59 = F_4 ( V_57 ) ;
if ( ( V_77 >= V_79 ) && ( V_77 <= V_80 ) ) {
V_59 -> V_81 = V_77 ;
} else {
F_9 ( V_57 -> V_2 , L_1 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_10 ( struct V_74 * V_75 , unsigned int V_82 )
{
struct V_56 * V_57 = V_75 -> V_57 ;
struct V_58 * V_59 = F_4 ( V_57 ) ;
T_2 V_83 = 0 ;
switch ( V_82 & V_84 ) {
case V_85 :
V_83 = V_86 ;
break;
case V_87 :
V_83 = V_88 ;
break;
default:
return - V_70 ;
}
switch ( V_82 & V_89 ) {
case V_90 :
V_83 |= V_91 |
V_92 ;
break;
case V_93 :
V_83 |= V_94 ;
break;
case V_95 :
V_83 |= V_96 |
V_97 ;
break;
case V_98 :
V_83 |= V_99 ;
break;
case V_100 :
break;
default:
return - V_70 ;
}
switch ( V_82 & V_101 ) {
case V_102 :
break;
case V_103 :
V_83 |= V_104 ;
break;
case V_105 :
V_83 |= V_104 ;
break;
case V_106 :
break;
default:
return - V_70 ;
}
V_59 -> V_107 . V_108 = V_83 ;
F_11 ( V_57 , V_9 , V_59 -> V_107 . V_108 ) ;
return 0 ;
}
static int F_12 ( struct V_74 * V_109 , int V_110 )
{
struct V_56 * V_57 = V_109 -> V_57 ;
if ( V_110 )
F_13 ( V_57 , V_16 ,
V_111 ,
V_112 ) ;
else
F_13 ( V_57 , V_16 ,
V_111 ,
V_113 ) ;
return 0 ;
}
static int F_14 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
struct V_74 * V_109 )
{
struct V_56 * V_57 = V_109 -> V_57 ;
struct V_58 * V_59 = F_4 ( V_57 ) ;
T_3 V_118 = 0 ;
int V_119 ;
V_119 = F_7 ( V_59 -> V_81 , F_15 ( V_117 ) ) ;
if ( V_119 >= 0 ) {
V_59 -> V_81 = V_73 [ V_119 ] . V_66 ;
V_118 |= ( V_73 [ V_119 ] . V_120 << V_121 ) |
( V_73 [ V_119 ] . V_122 << V_123 ) |
( V_73 [ V_119 ] . V_124 << V_125 ) |
( V_73 [ V_119 ] . V_126 << V_127 ) |
V_73 [ V_119 ] . V_128 ;
F_11 ( V_57 , V_8 , V_118 ) ;
} else {
F_9 ( V_57 -> V_2 , L_2 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_16 ( struct V_56 * V_57 ,
enum V_129 V_130 )
{
struct V_58 * V_59 = F_4 ( V_57 ) ;
switch ( V_130 ) {
case V_131 :
break;
case V_132 :
F_13 ( V_57 , V_5 ,
V_133 , 0 ) ;
break;
case V_134 :
if ( F_17 ( V_57 ) == V_135 ) {
F_18 ( V_59 -> V_136 , false ) ;
F_19 ( V_59 -> V_136 ) ;
}
F_11 ( V_57 , V_5 , V_137 ) ;
break;
case V_135 :
F_11 ( V_57 , V_5 , V_137 ) ;
F_18 ( V_59 -> V_136 , true ) ;
break;
}
return 0 ;
}
static void F_20 ( struct V_138 * V_139 )
{
struct V_58 * V_59 =
F_21 ( V_139 , struct V_58 , V_140 ) ;
struct V_56 * V_57 = V_59 -> V_57 ;
struct V_141 * V_142 = F_22 ( V_57 ) ;
int V_68 ;
int V_143 = 0 ;
int V_144 = 0 ;
if ( V_59 -> V_145 ) {
for ( V_68 = 0 ; V_68 < F_6 ( V_146 ) ; V_68 ++ ) {
if ( abs ( V_59 -> V_145 - V_146 [ V_68 ] ) <
abs ( V_59 -> V_145 - V_146 [ V_144 ] ) )
V_144 = V_68 ;
}
F_23 ( V_57 -> V_2 , L_3 ,
V_146 [ V_144 ] , V_59 -> V_145 ) ;
V_143 = ( V_144 << V_147 ) ;
F_24 ( V_142 , L_4 ) ;
} else {
F_23 ( V_57 -> V_2 , L_5 ) ;
F_25 ( V_142 , L_4 ) ;
}
F_13 ( V_57 , V_31 ,
V_148 , V_143 ) ;
F_26 ( V_142 ) ;
}
static int F_27 ( struct V_149 * V_2 , unsigned int type ,
unsigned int V_150 , int V_151 )
{
struct V_56 * V_57 = F_28 ( V_2 ) ;
struct V_58 * V_59 = F_4 ( V_57 ) ;
F_23 ( V_57 -> V_2 , L_6 , V_150 , V_151 ) ;
switch ( V_150 ) {
case V_152 :
if ( V_151 )
V_151 = 261 ;
case V_153 :
break;
default:
return - 1 ;
}
V_59 -> V_145 = V_151 ;
F_29 ( & V_59 -> V_140 ) ;
return 0 ;
}
static T_4 F_30 ( struct V_1 * V_2 ,
struct V_154 * V_155 ,
const char * V_156 , T_5 V_157 )
{
struct V_58 * V_59 = F_31 ( V_2 ) ;
long int time ;
int V_69 ;
V_69 = F_32 ( V_156 , 10 , & time ) ;
if ( V_69 != 0 )
return V_69 ;
F_33 ( V_59 -> V_158 , V_159 , V_153 , time ) ;
return V_157 ;
}
static void F_34 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_4 ( V_57 ) ;
int V_69 ;
V_59 -> V_158 = F_35 ( V_57 -> V_2 ) ;
if ( ! V_59 -> V_158 ) {
F_9 ( V_57 -> V_2 , L_7 ) ;
return;
}
F_36 ( & V_59 -> V_140 , F_20 ) ;
V_59 -> V_145 = 0 ;
V_59 -> V_158 -> V_160 = L_8 ;
V_59 -> V_158 -> V_161 = F_37 ( V_57 -> V_2 ) ;
V_59 -> V_158 -> V_162 . V_163 = V_164 ;
V_59 -> V_158 -> V_165 [ 0 ] = F_38 ( V_159 ) ;
V_59 -> V_158 -> V_166 [ 0 ] = F_38 ( V_152 ) | F_38 ( V_153 ) ;
V_59 -> V_158 -> V_167 = F_27 ;
V_59 -> V_158 -> V_2 . V_168 = V_57 -> V_2 ;
F_39 ( V_59 -> V_158 , V_57 ) ;
V_69 = F_40 ( V_59 -> V_158 ) ;
if ( V_69 != 0 ) {
V_59 -> V_158 = NULL ;
F_9 ( V_57 -> V_2 , L_9 ) ;
}
V_69 = F_41 ( V_57 -> V_2 , & V_169 ) ;
if ( V_69 != 0 ) {
F_9 ( V_57 -> V_2 , L_10 ,
V_69 ) ;
}
}
static void F_42 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_4 ( V_57 ) ;
F_43 ( V_57 -> V_2 , & V_169 ) ;
F_44 ( & V_59 -> V_140 ) ;
V_59 -> V_158 = NULL ;
F_13 ( V_57 , V_33 ,
V_170 , 0 ) ;
}
static int F_45 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_4 ( V_57 ) ;
F_18 ( V_59 -> V_136 , true ) ;
F_3 ( V_57 ) ;
F_34 ( V_57 ) ;
V_59 -> V_81 = V_171 ;
V_59 -> V_107 . V_108 = V_172 ;
return 0 ;
}
static int F_46 ( struct V_56 * V_57 )
{
F_42 ( V_57 ) ;
return 0 ;
}
static int F_47 ( struct V_173 * V_173 ,
const struct V_174 * V_162 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 = F_48 ( & V_173 -> V_2 ) ;
int V_69 ;
unsigned int V_175 = 0 ;
unsigned int V_3 ;
T_3 V_176 ;
V_59 = F_49 ( & V_173 -> V_2 , sizeof( struct V_58 ) ,
V_177 ) ;
if ( V_59 == NULL )
return - V_178 ;
V_59 -> V_2 = & V_173 -> V_2 ;
V_59 -> V_136 = F_50 ( V_173 , & V_179 ) ;
if ( F_51 ( V_59 -> V_136 ) ) {
V_69 = F_52 ( V_59 -> V_136 ) ;
F_9 ( & V_173 -> V_2 , L_11 , V_69 ) ;
return V_69 ;
}
if ( V_61 ) {
V_59 -> V_61 = * V_61 ;
} else {
V_61 = F_49 ( & V_173 -> V_2 ,
sizeof( struct V_60 ) ,
V_177 ) ;
if ( ! V_61 ) {
F_9 ( & V_173 -> V_2 , L_12 ) ;
return - V_178 ;
}
if ( V_173 -> V_2 . V_180 ) {
if ( F_53 ( V_173 -> V_2 . V_180 ,
L_13 ) )
V_61 -> V_62 = true ;
if ( F_53 ( V_173 -> V_2 . V_180 ,
L_14 ) )
V_61 -> V_64 = true ;
if ( F_54 ( V_173 -> V_2 . V_180 ,
L_15 , & V_176 ) >= 0 )
V_61 -> V_181 = V_176 ;
if ( F_54 ( V_173 -> V_2 . V_180 ,
L_16 , & V_176 ) >= 0 )
V_61 -> V_182 = V_176 ;
V_61 -> V_183 =
F_55 ( V_173 -> V_2 . V_180 ,
L_17 , 0 ) ;
}
V_59 -> V_61 = * V_61 ;
}
if ( V_59 -> V_61 . V_183 ) {
V_69 = F_56 ( & V_173 -> V_2 ,
V_59 -> V_61 . V_183 ,
V_184 ,
L_18 ) ;
if ( V_69 < 0 ) {
F_9 ( & V_173 -> V_2 , L_19 ,
V_59 -> V_61 . V_183 , V_69 ) ;
return V_69 ;
}
F_57 ( V_59 -> V_61 . V_183 , 0 ) ;
F_57 ( V_59 -> V_61 . V_183 , 1 ) ;
}
F_58 ( V_173 , V_59 ) ;
V_69 = F_59 ( V_59 -> V_136 , V_185 ,
F_6 ( V_185 ) ) ;
if ( V_69 != 0 )
F_60 ( V_59 -> V_2 , L_20 ,
V_69 ) ;
V_69 = F_61 ( V_59 -> V_136 , V_4 , & V_3 ) ;
V_175 = V_3 & V_186 ;
if ( V_175 != V_187 ) {
V_69 = - V_188 ;
F_9 ( & V_173 -> V_2 ,
L_21 ,
V_175 , V_187 ) ;
return V_69 ;
}
F_62 ( & V_173 -> V_2 , L_22 ,
V_3 & V_189 ) ;
if ( V_59 -> V_61 . V_62 )
F_63 ( V_59 -> V_136 , V_19 ,
V_190 ,
V_59 -> V_61 . V_62 <<
V_191 ) ;
if ( V_59 -> V_61 . V_64 )
F_63 ( V_59 -> V_136 , V_20 ,
V_190 ,
V_59 -> V_61 . V_64 <<
V_191 ) ;
if ( V_59 -> V_61 . V_182 )
F_63 ( V_59 -> V_136 , V_55 ,
V_192 ,
V_59 -> V_61 . V_182 <<
V_193 ) ;
if ( V_59 -> V_61 . V_181 )
F_63 ( V_59 -> V_136 , V_10 ,
V_194 ,
V_59 -> V_61 . V_181 ) ;
V_69 = F_64 ( & V_173 -> V_2 ,
& V_195 , & V_196 , 1 ) ;
if ( V_69 < 0 )
return V_69 ;
return 0 ;
}
static int F_65 ( struct V_173 * V_197 )
{
F_66 ( & V_197 -> V_2 ) ;
return 0 ;
}
