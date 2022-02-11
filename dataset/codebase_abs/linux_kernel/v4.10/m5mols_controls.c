int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 V_7 = V_8 [ V_3 ] ;
int V_9 ;
if ( V_3 > V_10 )
return - V_11 ;
V_9 = F_2 ( V_2 -> V_12 , 0 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_13 , V_3 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_14 , V_3 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_15 , V_7 . V_16 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_17 , V_7 . V_18 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_19 , V_7 . V_20 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_21 , V_7 . V_22 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_23 , V_7 . V_24 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_25 , V_7 . V_26 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_27 , V_7 . V_28 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_29 , V_7 . V_30 ) ;
if ( ! V_9 && F_4 ( V_2 ) )
V_9 = F_3 ( V_5 , V_31 , V_7 . V_32 ) ;
if ( ! V_9 && F_4 ( V_2 ) )
V_9 = F_3 ( V_5 , V_33 , V_7 . V_34 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_35 , V_7 . V_36 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_37 , V_7 . V_38 ) ;
if ( ! V_9 )
V_9 = F_5 ( V_2 , V_39 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_40 , V_7 . V_41 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_42 , V_7 . V_43 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_44 , V_7 . V_45 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_46 , V_7 . V_47 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_48 , V_7 . V_49 ) ;
if ( ! V_9 )
V_9 = F_5 ( V_2 , V_50 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
bool V_53 = V_52 -> V_54 & V_55 ;
int V_9 = 0 ;
if ( ( V_52 -> V_54 ^ V_52 -> V_56 . V_54 ) & V_57 ) {
bool V_58 = V_52 -> V_54 & V_57 ;
V_9 = F_3 ( & V_2 -> V_5 , V_59 , V_58 ?
V_60 : V_61 ) ;
if ( V_9 )
return V_9 ;
}
if ( ( ( V_52 -> V_54 ^ V_52 -> V_56 . V_54 ) & V_62 )
&& V_2 -> V_63 -> V_54 ) {
bool V_64 = V_52 -> V_54 & V_62 ;
V_9 = F_3 ( & V_2 -> V_5 , V_65 , V_64 ?
V_66 : V_67 ) ;
if ( V_9 )
return V_9 ;
}
if ( ! V_2 -> V_68 . V_69 || ! V_53 )
return V_9 ;
if ( ( V_52 -> V_54 ^ V_52 -> V_56 . V_54 ) & V_55 )
V_9 = F_3 ( & V_2 -> V_5 , V_70 , V_71 ) ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_16 ;
switch ( V_3 ) {
case V_72 :
V_16 = V_73 ;
break;
case V_74 :
V_16 = V_75 ;
break;
default:
V_16 = V_76 ;
break;
}
return F_3 ( & V_2 -> V_5 , V_15 , V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_77 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_9 = 0 ;
if ( V_77 == V_78 ) {
V_2 -> V_12 -> V_54 &= ~ V_57 ;
F_6 ( V_2 , V_2 -> V_12 ) ;
V_9 = F_7 ( V_2 , V_2 -> V_16 -> V_54 ) ;
if ( V_9 < 0 )
return V_9 ;
F_9 ( 1 , V_79 , V_5 ,
L_1 ,
V_80 , V_2 -> V_81 -> V_54 ,
V_2 -> V_16 -> V_54 ) ;
return F_3 ( V_5 , V_17 , V_2 -> V_81 -> V_54 ) ;
}
if ( V_77 == V_82 ) {
V_9 = F_3 ( V_5 , V_15 , V_83 ) ;
if ( V_9 == 0 )
V_9 = F_3 ( V_5 , V_84 ,
V_2 -> V_77 -> V_54 ) ;
if ( V_9 == 0 )
V_9 = F_3 ( V_5 , V_85 ,
V_2 -> V_77 -> V_54 ) ;
F_9 ( 1 , V_79 , V_5 , L_2 ,
V_80 , V_2 -> V_77 -> V_54 ) ;
}
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 , int V_54 )
{
static const unsigned short V_86 [] [ 2 ] = {
{ V_87 , V_88 } ,
{ V_89 , V_90 } ,
{ V_91 , V_92 } ,
{ V_93 , V_94 } ,
{ V_95 , V_96 } ,
{ V_97 , V_98 } ,
{ V_99 , V_100 } ,
{ V_101 , V_102 } ,
{ V_103 , V_104 } ,
} ;
int V_105 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_9 = - V_11 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_86 ) ; V_105 ++ ) {
int V_106 ;
if ( V_86 [ V_105 ] [ 0 ] != V_54 )
continue;
F_9 ( 1 , V_79 , V_5 ,
L_3 , V_86 [ V_105 ] [ 0 ] ) ;
V_106 = V_86 [ V_105 ] [ 0 ] == V_103 ;
V_9 = F_3 ( V_5 , V_19 , V_106 ? V_104 :
V_107 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_106 )
V_9 = F_3 ( V_5 , V_21 , V_86 [ V_105 ] [ 1 ] ) ;
}
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 , int V_54 )
{
int V_9 = F_3 ( & V_2 -> V_5 , V_25 , V_54 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( & V_2 -> V_5 , V_23 , V_108 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_54 )
{
unsigned int V_109 = V_110 ;
unsigned int V_111 = V_112 ;
unsigned int V_113 = 0 , V_114 = 0 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_9 = 0 ;
switch ( V_54 ) {
case V_115 :
V_109 = V_116 ;
break;
case V_117 :
V_111 = V_118 ;
break;
case V_119 :
V_111 = V_120 ;
break;
case V_121 :
V_109 = V_116 ;
V_113 = V_122 ;
V_114 = V_123 ;
break;
}
V_9 = F_3 ( V_5 , V_124 , V_111 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_125 , V_109 ) ;
if ( V_9 == 0 && V_109 == V_116 ) {
V_9 = F_3 ( V_5 , V_126 , V_113 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_5 , V_127 , V_114 ) ;
}
F_9 ( 1 , V_79 , V_5 ,
L_4 ,
V_111 , V_109 , V_113 , V_114 , V_9 ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , int V_128 )
{
T_2 V_38 = V_128 ? 0 : V_2 -> V_38 -> V_54 + 1 ;
return F_3 ( & V_2 -> V_5 , V_37 , V_38 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_41 )
{
int V_9 ;
V_9 = F_3 ( & V_2 -> V_5 , V_35 , V_41 ? 9 : 5 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_5 ( V_2 , V_39 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( & V_2 -> V_5 , V_40 , V_41 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_54 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
unsigned int V_129 = V_54 ? 0xe : 0x0 ;
int V_9 ;
V_9 = F_3 ( V_5 , V_13 , V_129 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( V_5 , V_14 , V_129 ) ;
}
static int F_17 ( struct V_51 * V_52 )
{
struct V_4 * V_5 = F_18 ( V_52 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_9 = 0 ;
T_1 V_130 = V_131 ;
F_9 ( 1 , V_79 , V_5 , L_5 ,
V_80 , V_52 -> V_132 , V_2 -> V_133 ) ;
if ( ! V_2 -> V_133 )
return - V_134 ;
switch ( V_52 -> V_135 ) {
case V_136 :
V_9 = F_20 ( V_5 , V_37 , & V_130 ) ;
if ( V_9 == 0 )
V_52 -> V_54 = ! V_130 ;
if ( V_130 != V_131 )
V_2 -> V_38 -> V_54 = V_130 - 1 ;
break;
case V_137 :
V_52 -> V_54 &= ~ 0x7 ;
V_9 = F_20 ( V_5 , V_59 , & V_130 ) ;
if ( V_9 )
return V_9 ;
if ( V_130 )
V_2 -> V_12 -> V_54 |= V_57 ;
V_9 = F_20 ( V_5 , V_65 , & V_130 ) ;
if ( V_9 )
return V_9 ;
if ( V_130 )
V_2 -> V_12 -> V_54 |= V_57 ;
V_9 = F_20 ( V_5 , V_70 , & V_130 ) ;
if ( ! V_130 )
V_2 -> V_12 -> V_54 |= V_57 ;
break;
}
return V_9 ;
}
static int F_21 ( struct V_51 * V_52 )
{
unsigned int V_138 = F_22 ( V_52 ) ;
struct V_4 * V_5 = F_18 ( V_52 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_139 = V_2 -> V_3 ;
int V_9 = 0 ;
if ( ! V_2 -> V_133 ) {
V_2 -> V_140 = 0 ;
return 0 ;
}
F_9 ( 1 , V_79 , V_5 , L_6 ,
V_80 , V_52 -> V_132 , V_52 -> V_54 , V_52 -> V_141 ) ;
if ( V_138 && V_138 != V_2 -> V_3 ) {
V_9 = F_5 ( V_2 , V_138 ) ;
if ( V_9 < 0 )
return V_9 ;
}
switch ( V_52 -> V_135 ) {
case V_137 :
V_9 = F_6 ( V_2 , V_52 ) ;
break;
case V_142 :
V_9 = F_3 ( V_5 , V_143 , V_52 -> V_54 ) ;
break;
case V_144 :
V_9 = F_8 ( V_2 , V_52 -> V_54 ) ;
break;
case V_145 :
V_9 = F_14 ( V_2 , V_52 -> V_54 ) ;
break;
case V_146 :
V_9 = F_10 ( V_2 , V_52 -> V_54 ) ;
break;
case V_147 :
V_9 = F_12 ( V_2 , V_52 -> V_54 ) ;
break;
case V_148 :
V_9 = F_13 ( V_2 , V_52 -> V_54 ) ;
break;
case V_149 :
V_9 = F_15 ( V_2 , V_52 -> V_54 ) ;
break;
case V_150 :
V_9 = F_16 ( V_2 , V_52 -> V_54 ) ;
break;
case V_151 :
V_9 = F_3 ( V_5 , V_152 , V_52 -> V_54 ) ;
break;
}
if ( V_9 == 0 && V_2 -> V_3 != V_139 )
V_9 = F_5 ( V_2 , V_139 ) ;
return V_9 ;
}
int F_23 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_19 ( V_5 ) ;
T_3 V_153 ;
T_3 V_154 ;
int V_9 ;
V_9 = F_24 ( V_5 , V_155 , & V_153 ) ;
if ( V_9 < 0 )
return V_9 ;
V_154 = F_25 ( V_2 , V_156 ) ? 31 : 1 ;
F_26 ( & V_2 -> V_157 , 20 ) ;
V_2 -> V_63 = F_27 ( & V_2 -> V_157 ,
& V_158 , V_146 ,
9 , ~ 0x3fe , V_103 ) ;
V_2 -> V_159 = F_27 ( & V_2 -> V_157 ,
& V_158 , V_144 ,
1 , ~ 0x03 , V_78 ) ;
V_2 -> V_77 = F_28 ( & V_2 -> V_157 ,
& V_158 , V_160 ,
0 , V_153 , 1 , V_153 / 2 ) ;
V_2 -> V_81 = F_29 ( & V_2 -> V_157 ,
& V_158 , V_161 ,
F_11 ( V_162 ) - 1 ,
F_11 ( V_162 ) / 2 - 1 ,
V_162 ) ;
V_2 -> V_16 = F_27 ( & V_2 -> V_157 ,
& V_158 , V_163 ,
2 , ~ 0x7 , V_164 ) ;
V_2 -> V_128 = F_27 ( & V_2 -> V_157 , & V_158 ,
V_136 , 1 , ~ 0x03 , 1 ) ;
V_2 -> V_38 = F_29 ( & V_2 -> V_157 , & V_158 ,
V_145 , F_11 ( V_165 ) - 1 ,
F_11 ( V_165 ) / 2 - 1 , V_165 ) ;
V_2 -> V_166 = F_28 ( & V_2 -> V_157 , & V_158 ,
V_147 , 1 , 5 , 1 , 3 ) ;
V_2 -> V_167 = F_28 ( & V_2 -> V_157 , & V_158 ,
V_142 , 1 , 70 , V_154 , 1 ) ;
V_2 -> V_168 = F_27 ( & V_2 -> V_157 , & V_158 ,
V_148 , 4 , 0 , V_169 ) ;
V_2 -> V_41 = F_28 ( & V_2 -> V_157 , & V_158 ,
V_149 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_170 = F_28 ( & V_2 -> V_157 , & V_158 ,
V_150 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_171 = F_28 ( & V_2 -> V_157 , & V_158 ,
V_151 , 1 , 100 , 1 , 80 ) ;
V_2 -> V_12 = F_28 ( & V_2 -> V_157 , & V_158 ,
V_137 , 0 , 0x7 , 0 , 0 ) ;
if ( V_2 -> V_157 . error ) {
int V_9 = V_2 -> V_157 . error ;
F_30 ( V_5 , L_7 , V_9 ) ;
F_31 ( & V_2 -> V_157 ) ;
return V_9 ;
}
F_32 ( 4 , & V_2 -> V_159 , 1 , false ) ;
V_2 -> V_128 -> V_172 |= V_173 |
V_174 ;
F_32 ( 2 , & V_2 -> V_128 , 0 , false ) ;
V_2 -> V_12 -> V_172 |= V_173 ;
F_33 ( V_2 -> V_159 , V_175 ) ;
F_33 ( V_2 -> V_63 , V_175 ) ;
F_33 ( V_2 -> V_168 , V_50 ) ;
V_5 -> V_176 = & V_2 -> V_157 ;
return 0 ;
}
