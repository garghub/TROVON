static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
unsigned int V_8 , V_9 ;
if ( V_4 )
V_8 = V_3 ;
else
V_8 = V_10 ;
V_7 = F_2 ( V_6 -> V_11 ,
V_12 ,
V_13 , V_8 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_14 , L_1 ) ;
return V_7 ;
}
if ( V_4 )
V_9 = V_15 ;
else
V_9 = V_16 ;
V_7 = F_2 ( V_6 -> V_11 ,
V_17 ,
V_16 |
V_15 , V_9 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_14 , L_2 ) ;
return V_7 ;
}
F_4 ( V_2 -> V_14 ,
L_3 ,
V_8 , V_9 , V_4 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_18 V_19 , bool * V_4 )
{
int V_20 , V_21 , V_22 , V_23 ;
V_20 = V_2 -> V_24 [ V_25 ] &
V_26 ;
V_20 >>= V_27 ;
switch ( V_19 ) {
case V_28 :
if ( V_20 == V_29 ) {
* V_4 = false ;
V_22 = V_2 -> V_30 ;
V_2 -> V_30 = V_29 ;
} else {
* V_4 = true ;
V_22 = V_2 -> V_30 = V_20 ;
}
break;
case V_31 :
V_21 = V_2 -> V_24 [ V_32 ] &
V_33 ;
if ( V_20 == V_34 ) {
if ( V_21 == V_35 ) {
* V_4 = false ;
V_22 = V_2 -> V_36 ;
V_2 -> V_36 = V_35 ;
} else {
* V_4 = true ;
V_22 = V_37 ;
V_2 -> V_36 = V_37 ;
}
break;
}
if ( V_21 == V_35 ) {
* V_4 = false ;
V_22 = V_2 -> V_36 ;
V_2 -> V_36 = V_35 ;
} else {
* V_4 = true ;
V_22 = V_2 -> V_36 = V_21 ;
}
break;
case V_38 :
if ( V_20 == V_29 ) {
* V_4 = false ;
V_22 = V_2 -> V_39 ;
V_2 -> V_39 = V_29 ;
} else {
* V_4 = true ;
V_23 = ( V_2 -> V_24 [ V_25 ] &
V_40 ) ;
V_23 |= ( V_2 -> V_24 [ V_32 ] &
V_41 ) ;
V_23 >>= V_42 ;
V_23 |= V_43 ;
V_22 = V_2 -> V_39 = V_23 ;
}
break;
default:
F_3 ( V_2 -> V_14 , L_6 , V_19 ) ;
V_22 = - V_44 ;
break;
}
return V_22 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_7 , V_45 ;
bool V_4 ;
V_45 = F_5 ( V_2 ,
V_38 , & V_4 ) ;
F_4 ( V_2 -> V_14 , L_7 ,
V_4 ? L_4 : L_5 , V_45 ) ;
switch ( V_45 ) {
case V_43 :
case V_46 :
V_7 = F_1 ( V_2 ,
V_47 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_49 , V_4 ) ;
break;
case V_50 :
case V_51 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_52 , V_4 ) ;
break;
default:
F_3 ( V_2 -> V_14 , L_8 ,
V_4 ? L_4 : L_5 , V_45 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_22 , bool V_4 )
{
int V_7 ;
T_1 V_53 = V_10 ;
F_4 ( V_2 -> V_14 , L_9 ,
V_4 ? L_4 : L_5 , V_22 ) ;
switch ( V_22 ) {
case V_54 :
case V_55 :
V_53 = V_47 ;
break;
case V_56 :
V_53 = V_57 ;
break;
default:
return - V_44 ;
}
V_7 = F_1 ( V_2 , V_53 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_58 , V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_7 , V_22 ;
bool V_4 ;
V_22 = F_5 ( V_2 ,
V_28 , & V_4 ) ;
F_4 ( V_2 -> V_14 ,
L_10 ,
V_4 ? L_4 : L_5 , V_22 ,
V_2 -> V_30 ) ;
switch ( V_22 ) {
case V_34 :
V_7 = F_6 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
case V_54 :
case V_55 :
case V_56 :
V_7 = F_8 ( V_2 , V_22 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_29 :
F_3 ( V_2 -> V_14 ,
L_11 ,
V_4 ? L_4 : L_5 , V_22 ) ;
return - V_86 ;
default:
F_3 ( V_2 -> V_14 ,
L_12 ,
V_4 ? L_4 : L_5 , V_22 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_7 , V_21 , V_23 ;
bool V_4 ;
V_21 = F_5 ( V_2 ,
V_31 , & V_4 ) ;
F_4 ( V_2 -> V_14 ,
L_13 ,
V_4 ? L_4 : L_5 ,
V_21 , V_2 -> V_36 ) ;
switch ( V_21 ) {
case V_87 :
V_7 = F_1 ( V_2 ,
V_47 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_88 , V_4 ) ;
break;
case V_89 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_90 ,
V_4 ) ;
break;
case V_91 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_92 ,
V_4 ) ;
break;
case V_93 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_94 ,
V_4 ) ;
break;
case V_95 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_96 ,
V_4 ) ;
break;
case V_37 :
V_23 = F_5 ( V_2 ,
V_38 , & V_4 ) ;
if ( V_23 == V_50 )
F_7 ( V_2 -> V_48 , V_92 ,
true ) ;
else if ( V_23 == V_51 )
F_7 ( V_2 -> V_48 , V_92 ,
false ) ;
break;
case V_35 :
break;
default:
F_3 ( V_2 -> V_14 ,
L_14 ,
V_4 ? L_4 : L_5 , V_21 ) ;
F_1 ( V_2 , V_10 ,
V_4 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_11 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_12 ( V_98 ,
struct V_1 , V_99 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
F_13 ( & V_2 -> V_100 ) ;
V_7 = F_14 ( V_6 -> V_11 ,
V_101 , V_2 -> V_24 ,
V_102 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_14 , L_15 ) ;
F_15 ( & V_2 -> V_100 ) ;
return;
}
if ( V_2 -> V_103 ) {
V_7 = F_9 ( V_2 ) ;
if ( V_7 )
F_3 ( V_2 -> V_14 , L_16 ) ;
V_2 -> V_103 = false ;
}
if ( V_2 -> V_104 ) {
V_7 = F_10 ( V_2 ) ;
if ( V_7 )
F_3 ( V_2 -> V_14 , L_17 ) ;
V_2 -> V_104 = false ;
}
F_15 ( & V_2 -> V_100 ) ;
}
static T_2 F_16 ( int V_105 , void * V_106 )
{
struct V_1 * V_2 = V_106 ;
int V_107 , V_108 = - 1 ;
for ( V_107 = 0 ; V_107 < F_17 ( V_109 ) ; V_107 ++ )
if ( V_105 == V_109 [ V_107 ] . V_110 )
V_108 = V_109 [ V_107 ] . V_105 ;
switch ( V_108 ) {
case V_111 :
case V_112 :
case V_113 :
V_2 -> V_103 = true ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
V_2 -> V_104 = true ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
break;
default:
F_3 ( V_2 -> V_14 , L_18 , V_108 ) ;
break;
}
F_18 ( & V_2 -> V_99 ) ;
return V_127 ;
}
static void F_19 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_12 ( F_20 ( V_98 ) ,
struct V_1 , V_128 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_21 , V_20 , V_7 ;
bool V_4 ;
F_13 ( & V_2 -> V_100 ) ;
V_7 = F_14 ( V_6 -> V_11 ,
V_101 , V_2 -> V_24 ,
V_102 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_14 , L_15 ) ;
goto V_129;
}
V_20 = F_5 ( V_2 ,
V_28 , & V_4 ) ;
if ( V_4 && V_20 != V_29 ) {
V_7 = F_9 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_14 , L_19 ) ;
goto V_129;
}
}
V_21 = F_5 ( V_2 ,
V_31 , & V_4 ) ;
if ( V_4 && V_21 != V_35 ) {
V_7 = F_10 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_14 , L_20 ) ;
goto V_129;
}
}
V_129:
F_15 ( & V_2 -> V_100 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_130 time )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
switch ( time ) {
case V_131 :
case V_132 :
case V_133 :
case V_134 :
V_7 = F_2 ( V_6 -> V_11 ,
V_135 ,
V_136 ,
time << V_137 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_14 , L_21 ) ;
return V_7 ;
}
break;
default:
F_3 ( V_2 -> V_14 , L_22 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
int V_7 ;
V_6 -> V_138 = F_23 ( V_6 -> V_139 -> V_140 ,
V_141 ) ;
if ( ! V_6 -> V_138 ) {
F_3 ( & V_6 -> V_139 -> V_14 ,
L_23 ) ;
return - V_142 ;
}
F_24 ( V_6 -> V_138 , V_6 ) ;
V_6 -> V_11 = F_25 ( V_6 -> V_138 ,
& V_143 ) ;
if ( F_26 ( V_6 -> V_11 ) ) {
V_7 = F_27 ( V_6 -> V_11 ) ;
goto V_144;
}
V_7 = F_28 ( V_6 -> V_11 , V_6 -> V_105 ,
V_145 | V_146 | V_147 ,
0 , & V_148 , & V_6 -> V_149 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_139 -> V_14 , L_24 ) ;
goto V_144;
}
return 0 ;
V_144:
F_29 ( V_6 -> V_138 ) ;
return V_7 ;
}
static int F_30 ( struct V_150 * V_151 )
{
struct V_5 * V_6 = F_31 ( V_151 -> V_14 . V_152 ) ;
struct V_1 * V_2 ;
unsigned int V_153 ;
int V_107 , V_7 ;
V_2 = F_32 ( & V_151 -> V_14 , sizeof( * V_2 ) , V_154 ) ;
if ( ! V_2 )
return - V_142 ;
V_2 -> V_14 = & V_151 -> V_14 ;
V_2 -> V_6 = V_6 ;
F_33 ( V_151 , V_2 ) ;
F_34 ( & V_2 -> V_100 ) ;
V_7 = F_22 ( V_6 ) ;
if ( V_7 ) {
F_3 ( & V_151 -> V_14 , L_25 ) ;
return V_7 ;
}
V_7 = F_2 ( V_6 -> V_11 ,
V_135 ,
V_155 |
V_156 ,
V_157 ) ;
V_2 -> V_48 = F_35 ( & V_151 -> V_14 ,
V_158 ) ;
if ( F_26 ( V_2 -> V_48 ) ) {
F_3 ( & V_151 -> V_14 , L_26 ) ;
V_7 = - V_159 ;
goto V_160;
}
V_7 = F_36 ( & V_151 -> V_14 , V_2 -> V_48 ) ;
if ( V_7 ) {
F_3 ( & V_151 -> V_14 , L_27 ) ;
goto V_160;
}
F_21 ( V_2 , V_133 ) ;
F_1 ( V_2 , V_57 , true ) ;
V_7 = F_37 ( V_6 -> V_11 , V_161 , & V_153 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_151 -> V_14 , L_28 ) ;
goto V_160;
}
F_38 ( V_2 -> V_14 , L_29 , V_153 ) ;
F_39 ( & V_2 -> V_99 , F_11 ) ;
V_7 = F_14 ( V_6 -> V_11 ,
V_162 , V_2 -> V_24 ,
V_163 ) ;
if ( V_7 ) {
F_3 ( & V_151 -> V_14 , L_30 ) ;
goto V_160;
}
for ( V_107 = 0 ; V_107 < F_17 ( V_109 ) ; V_107 ++ ) {
struct V_164 * V_165 = & V_109 [ V_107 ] ;
int V_110 = 0 ;
V_110 = F_40 ( V_6 -> V_149 ,
V_165 -> V_105 ) ;
if ( V_110 <= 0 ) {
V_7 = - V_44 ;
goto V_160;
}
V_165 -> V_110 = V_110 ;
V_7 = F_41 ( & V_151 -> V_14 , V_110 , NULL ,
F_16 , V_166 ,
V_165 -> V_167 , V_2 ) ;
if ( V_7 ) {
F_3 ( & V_151 -> V_14 ,
L_31 ,
V_165 -> V_105 , V_7 ) ;
goto V_160;
}
}
F_42 ( & V_2 -> V_128 , F_19 ) ;
F_43 ( V_168 ,
& V_2 -> V_128 , F_44 ( V_169 ) ) ;
return 0 ;
V_160:
F_45 ( V_6 -> V_105 , V_6 -> V_149 ) ;
F_29 ( V_6 -> V_138 ) ;
return V_7 ;
}
static int F_46 ( struct V_150 * V_151 )
{
struct V_1 * V_2 = F_47 ( V_151 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_48 ( & V_2 -> V_99 ) ;
F_45 ( V_6 -> V_105 , V_6 -> V_149 ) ;
F_29 ( V_6 -> V_138 ) ;
return 0 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_170 ) ;
}
