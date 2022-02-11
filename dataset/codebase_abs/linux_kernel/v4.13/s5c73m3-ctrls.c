static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
int V_7 = F_2 ( V_2 , V_8 , & V_5 ) ;
switch ( V_5 ) {
case V_9 :
case V_10 :
case V_11 :
V_4 -> V_12 = V_13 ;
break;
case V_14 :
case V_15 :
V_4 -> V_12 = V_16 ;
break;
default:
F_3 ( & V_2 -> V_17 , L_1 , V_5 ) ;
case V_18 :
case V_6 :
case V_19 :
V_4 -> V_12 = V_20 ;
break;
}
return V_7 ;
}
static int F_4 ( struct V_3 * V_4 )
{
struct V_21 * V_22 = F_5 ( V_4 ) ;
struct V_1 * V_2 = F_6 ( V_22 ) ;
int V_7 ;
if ( V_2 -> V_23 == 0 )
return - V_24 ;
switch ( V_4 -> V_25 ) {
case V_26 :
V_7 = F_1 ( V_2 , V_2 -> V_27 . V_28 ) ;
if ( V_7 )
return V_7 ;
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_12 )
{
static const unsigned short V_29 [] [ 2 ] = {
{ V_30 , V_31 } ,
{ V_32 , V_33 } ,
{ V_34 , V_35 } ,
{ V_36 , V_37 } ,
{ V_38 , V_39 } ,
} ;
int V_40 ;
for ( V_40 = 0 ; V_40 < F_8 ( V_29 ) ; V_40 ++ ) {
if ( V_29 [ V_40 ] [ 0 ] != V_12 )
continue;
F_9 ( 1 , V_41 , & V_2 -> V_17 ,
L_2 ,
F_10 ( V_2 -> V_27 . V_29 -> V_25 ) [ V_40 ] ) ;
return F_11 ( V_2 , V_42 ,
V_29 [ V_40 ] [ 1 ] ) ;
}
return - V_43 ;
}
static int F_12 ( struct V_1 * V_2 , int V_44 )
{
struct V_21 * V_22 = & V_2 -> V_17 ;
struct V_45 * V_27 = & V_2 -> V_27 ;
int V_7 = 0 ;
if ( V_27 -> V_46 -> V_47 ) {
T_1 V_48 ;
switch ( V_27 -> V_46 -> V_12 ) {
case V_49 :
V_48 = V_50 ;
break;
case V_51 :
V_48 = V_52 ;
break;
default:
V_48 = V_53 ;
break;
}
V_7 = F_11 ( V_2 , V_54 , V_48 ) ;
}
if ( ! V_7 && V_27 -> V_55 -> V_47 ) {
T_1 V_56 = V_27 -> V_55 -> V_12 ;
V_7 = F_11 ( V_2 , V_57 , V_56 ) ;
}
F_9 ( 1 , V_41 , V_22 ,
L_3 , V_58 ,
V_27 -> V_55 -> V_12 , V_27 -> V_46 -> V_12 , V_7 ) ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 , int V_12 )
{
static const unsigned short V_59 [] [ 2 ] = {
{ V_60 , V_61 } ,
{ V_62 , V_63 } ,
{ V_64 , V_65 } ,
{ V_66 , V_67 } ,
{ V_68 , V_69 } ,
{ V_70 , V_71 } ,
} ;
int V_40 ;
for ( V_40 = 0 ; V_40 < F_8 ( V_59 ) ; V_40 ++ ) {
if ( V_59 [ V_40 ] [ 0 ] != V_12 )
continue;
F_9 ( 1 , V_41 , & V_2 -> V_17 ,
L_4 ,
F_10 ( V_2 -> V_27 . V_72 -> V_25 ) [ V_40 ] ) ;
return F_11 ( V_2 , V_73 , V_59 [ V_40 ] [ 1 ] ) ;
}
return - V_43 ;
}
static int F_14 ( struct V_1 * V_2 , bool V_74 )
{
struct V_45 * V_75 = & V_2 -> V_27 ;
if ( ! V_74 )
return F_11 ( V_2 , V_76 ,
V_77 ) ;
if ( V_75 -> V_78 -> V_12 )
return F_11 ( V_2 , V_79 ,
V_80 ) ;
return F_11 ( V_2 , V_76 , V_81 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
bool V_82 = V_4 -> V_12 & V_83 ;
bool V_84 = V_4 -> V_12 & V_85 ;
bool V_86 = V_4 -> V_12 & V_87 ;
int V_7 = 0 ;
if ( ( V_4 -> V_12 ^ V_4 -> V_88 . V_12 ) & V_85 ) {
V_7 = F_11 ( V_2 , V_89 ,
V_84 ? V_90 : V_91 ) ;
if ( V_7 )
return V_7 ;
}
if ( ( ( V_4 -> V_12 ^ V_4 -> V_88 . V_12 ) & V_83 )
&& V_2 -> V_27 . V_72 -> V_12 ) {
V_7 = F_11 ( V_2 , V_92 ,
V_82 ? V_93 : V_94 ) ;
if ( V_7 )
return V_7 ;
}
if ( ( V_4 -> V_12 ^ V_4 -> V_88 . V_12 ) & V_87 )
V_7 = F_14 ( V_2 , ! V_86 ) ;
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 , int V_95 )
{
struct V_45 * V_75 = & V_2 -> V_27 ;
int V_7 = 1 ;
if ( V_75 -> V_96 -> V_47 ) {
T_1 V_97 = ( V_75 -> V_96 -> V_12 == V_98 )
? V_99 : V_100 ;
V_7 = F_11 ( V_2 , V_79 , V_97 ) ;
if ( V_7 != 0 )
return V_7 ;
}
if ( ! V_7 || ( V_75 -> V_78 -> V_47 && V_75 -> V_78 -> V_12 ) ||
V_75 -> V_101 -> V_47 )
V_7 = F_14 ( V_2 , 1 ) ;
else if ( ( V_75 -> V_78 -> V_47 && ! V_75 -> V_78 -> V_12 ) ||
V_75 -> V_102 -> V_47 )
V_7 = F_14 ( V_2 , 0 ) ;
else
V_7 = 0 ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_5 = ( V_12 < 0 ) ? - V_12 + 2 : V_12 ;
return F_11 ( V_2 , V_103 , V_5 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_5 = ( V_12 < 0 ) ? - V_12 + 2 : V_12 ;
return F_11 ( V_2 , V_104 , V_5 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_12 )
{
T_1 V_5 = ( V_12 < 0 ) ? - V_12 + 2 : V_12 ;
return F_11 ( V_2 , V_105 , V_5 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_12 )
{
T_2 V_106 ;
if ( V_12 == V_107 )
V_106 = V_2 -> V_27 . V_106 -> V_12 + 1 ;
else
V_106 = 0 ;
return F_11 ( V_2 , V_108 , V_106 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_12 )
{
struct V_21 * V_22 = & V_2 -> V_17 ;
F_9 ( 1 , V_41 , V_22 , L_5 , V_12 ) ;
return F_11 ( V_2 , V_109 , V_12 ?
V_110 : V_111 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_112 )
{
int V_5 ;
if ( V_112 <= 65 )
V_5 = V_113 ;
else if ( V_112 <= 75 )
V_5 = V_114 ;
else
V_5 = V_115 ;
return F_11 ( V_2 , V_116 , V_5 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_12 )
{
static const unsigned short V_117 [] = {
V_118 ,
V_119 ,
V_120 ,
V_121 ,
V_122 ,
V_123 ,
V_124 ,
V_125 ,
V_126 ,
V_127 ,
V_128 ,
V_129 ,
V_130 ,
V_131 ,
} ;
F_9 ( 1 , V_41 , & V_2 -> V_17 , L_6 ,
F_10 ( V_2 -> V_27 . V_132 -> V_25 ) [ V_12 ] ) ;
return F_11 ( V_2 , V_133 , V_117 [ V_12 ] ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_12 )
{
unsigned int V_134 = V_135 ;
switch ( V_12 ) {
case V_136 :
V_134 = V_135 ;
break;
case V_137 :
V_134 = V_138 ;
break;
case V_139 :
V_134 = V_140 ;
break;
default:
case V_141 :
V_134 = V_135 ;
}
return F_11 ( V_2 , V_142 , V_134 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_21 * V_22 = F_5 ( V_4 ) ;
struct V_1 * V_2 = F_6 ( V_22 ) ;
int V_7 = 0 ;
F_9 ( 1 , V_41 , V_22 , L_7 ,
V_4 -> V_143 , V_4 -> V_12 ) ;
F_26 ( & V_2 -> V_144 ) ;
if ( V_2 -> V_23 == 0 )
goto V_145;
if ( V_4 -> V_146 & V_147 ) {
V_7 = - V_43 ;
goto V_145;
}
switch ( V_4 -> V_25 ) {
case V_148 :
V_7 = F_15 ( V_2 , V_4 ) ;
break;
case V_149 :
V_7 = F_13 ( V_2 , V_4 -> V_12 ) ;
break;
case V_150 :
V_7 = F_17 ( V_2 , V_4 -> V_12 ) ;
break;
case V_151 :
V_7 = F_7 ( V_2 , V_4 -> V_12 ) ;
break;
case V_152 :
V_7 = F_12 ( V_2 , V_4 -> V_12 ) ;
break;
case V_26 :
V_7 = F_16 ( V_2 , V_4 -> V_12 ) ;
break;
case V_153 :
V_7 = F_21 ( V_2 , V_4 -> V_12 ) ;
break;
case V_154 :
V_7 = F_20 ( V_2 , V_4 -> V_12 ) ;
break;
case V_155 :
V_7 = F_22 ( V_2 , V_4 -> V_12 ) ;
break;
case V_156 :
V_7 = F_24 ( V_2 , V_4 -> V_12 ) ;
break;
case V_157 :
V_7 = F_18 ( V_2 , V_4 -> V_12 ) ;
break;
case V_158 :
V_7 = F_23 ( V_2 , V_4 -> V_12 ) ;
break;
case V_159 :
V_7 = F_19 ( V_2 , V_4 -> V_12 ) ;
break;
case V_160 :
V_7 = F_11 ( V_2 , V_161 , ! ! V_4 -> V_12 ) ;
break;
case V_162 :
V_7 = F_11 ( V_2 , V_163 , V_4 -> V_12 ) ;
break;
}
V_145:
F_27 ( & V_2 -> V_144 ) ;
return V_7 ;
}
int F_28 ( struct V_1 * V_2 )
{
const struct V_164 * V_165 = & V_166 ;
struct V_45 * V_27 = & V_2 -> V_27 ;
struct V_167 * V_168 = & V_27 -> V_169 ;
int V_7 = F_29 ( V_168 , 22 ) ;
if ( V_7 )
return V_7 ;
V_27 -> V_72 = F_30 ( V_168 , V_165 ,
V_149 ,
9 , ~ 0x15e , V_70 ) ;
V_27 -> V_170 = F_30 ( V_168 , V_165 ,
V_152 , 0 , ~ 0x01 , V_171 ) ;
V_27 -> V_55 = F_31 ( V_168 , V_165 ,
V_172 ,
F_8 ( V_173 ) - 1 ,
F_8 ( V_173 ) / 2 - 1 ,
V_173 ) ;
V_27 -> V_46 = F_30 ( V_168 , V_165 ,
V_174 ,
2 , ~ 0x7 , V_175 ) ;
V_27 -> V_78 = F_32 ( V_168 , V_165 ,
V_26 , 0 , 1 , 1 , 0 ) ;
V_27 -> V_101 = F_32 ( V_168 , V_165 ,
V_176 , 0 , 1 , 1 , 0 ) ;
V_27 -> V_102 = F_32 ( V_168 , V_165 ,
V_177 , 0 , 1 , 1 , 0 ) ;
V_27 -> V_28 = F_32 ( V_168 , V_165 ,
V_178 , 0 ,
( V_13 |
V_16 |
V_20 ) ,
0 , V_179 ) ;
V_27 -> V_96 = F_30 ( V_168 , V_165 ,
V_180 ,
V_98 ,
~ ( 1 << V_181 |
1 << V_98 ) ,
V_181 ) ;
V_27 -> V_182 = F_30 ( V_168 , V_165 ,
V_183 , 1 , 0 ,
V_184 ) ;
V_27 -> V_106 = F_31 ( V_168 , V_165 ,
V_154 , F_8 ( V_185 ) - 1 ,
F_8 ( V_185 ) / 2 - 1 , V_185 ) ;
V_27 -> V_186 = F_32 ( V_168 , V_165 ,
V_150 , - 2 , 2 , 1 , 0 ) ;
V_27 -> V_187 = F_32 ( V_168 , V_165 ,
V_157 , - 2 , 2 , 1 , 0 ) ;
V_27 -> V_188 = F_32 ( V_168 , V_165 ,
V_159 , - 2 , 2 , 1 , 0 ) ;
V_27 -> V_189 = F_32 ( V_168 , V_165 ,
V_162 , 0 , 30 , 1 , 0 ) ;
V_27 -> V_29 = F_30 ( V_168 , V_165 , V_151 ,
V_38 , ~ 0x40f , V_30 ) ;
V_27 -> V_190 = F_32 ( V_168 , V_165 ,
V_160 , 0 , 1 , 1 , 0 ) ;
V_27 -> V_191 = F_32 ( V_168 , V_165 ,
V_153 , 0 , 1 , 1 , 0 ) ;
F_30 ( V_168 , V_165 , V_156 ,
V_141 , 0 ,
V_141 ) ;
V_27 -> V_192 = F_32 ( V_168 , V_165 ,
V_155 , 1 , 100 , 1 , 80 ) ;
V_27 -> V_132 = F_30 ( V_168 , V_165 ,
V_158 , V_193 , ~ 0x3fff ,
V_194 ) ;
V_27 -> V_195 = F_32 ( V_168 , V_165 ,
V_148 , 0 , 0x7 , 0 , 0 ) ;
if ( V_168 -> error ) {
V_7 = V_168 -> error ;
F_33 ( V_168 ) ;
return V_7 ;
}
F_34 ( 3 , & V_27 -> V_170 , 0 , false ) ;
V_27 -> V_182 -> V_146 |= V_196 |
V_197 ;
F_34 ( 2 , & V_27 -> V_182 , 0 , false ) ;
V_27 -> V_28 -> V_146 |= V_196 ;
F_35 ( 6 , & V_27 -> V_78 ) ;
V_2 -> V_17 . V_198 = V_168 ;
return 0 ;
}
