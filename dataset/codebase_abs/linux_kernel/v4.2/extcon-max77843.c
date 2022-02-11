static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , bool V_4 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
unsigned int V_7 , V_8 ;
if ( V_4 )
V_7 = V_3 ;
else
V_7 = V_9 ;
V_6 = F_2 ( V_5 -> V_10 ,
V_11 ,
V_12 , V_7 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
return V_6 ;
}
if ( V_4 )
V_8 = V_14 ;
else
V_8 = V_15 ;
V_6 = F_2 ( V_5 -> V_10 ,
V_16 ,
V_15 |
V_14 , V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_2 ) ;
return V_6 ;
}
F_4 ( V_2 -> V_13 ,
L_3 ,
V_7 , V_8 , V_4 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_17 V_18 , bool * V_4 )
{
int V_19 , V_20 , V_21 , V_22 ;
V_19 = V_2 -> V_23 [ V_24 ] &
V_25 ;
V_19 >>= V_26 ;
switch ( V_18 ) {
case V_27 :
if ( V_19 == V_28 ) {
* V_4 = false ;
V_21 = V_2 -> V_29 ;
V_2 -> V_29 = V_28 ;
} else {
* V_4 = true ;
V_21 = V_2 -> V_29 = V_19 ;
}
break;
case V_30 :
V_20 = V_2 -> V_23 [ V_31 ] &
V_32 ;
if ( V_19 == V_33 ) {
if ( V_20 == V_34 ) {
* V_4 = false ;
V_21 = V_2 -> V_35 ;
V_2 -> V_35 = V_34 ;
} else {
* V_4 = true ;
V_21 = V_36 ;
V_2 -> V_35 = V_36 ;
}
break;
}
if ( V_20 == V_34 ) {
* V_4 = false ;
V_21 = V_2 -> V_35 ;
V_2 -> V_35 = V_34 ;
} else {
* V_4 = true ;
V_21 = V_2 -> V_35 = V_20 ;
}
break;
case V_37 :
if ( V_19 == V_28 ) {
* V_4 = false ;
V_21 = V_2 -> V_38 ;
V_2 -> V_38 = V_28 ;
} else {
* V_4 = true ;
V_22 = ( V_2 -> V_23 [ V_24 ] &
V_39 ) ;
V_22 |= ( V_2 -> V_23 [ V_31 ] &
V_40 ) ;
V_22 >>= V_41 ;
V_22 |= V_42 ;
V_21 = V_2 -> V_38 = V_22 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_6 , V_18 ) ;
V_21 = - V_43 ;
break;
}
return V_21 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_6 , V_44 ;
bool V_4 ;
V_44 = F_5 ( V_2 ,
V_37 , & V_4 ) ;
F_4 ( V_2 -> V_13 , L_7 ,
V_4 ? L_4 : L_5 , V_44 ) ;
switch ( V_44 ) {
case V_42 :
case V_45 :
V_6 = F_1 ( V_2 , V_46 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_48 , V_4 ) ;
break;
case V_49 :
case V_50 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_51 , V_4 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_8 ,
V_4 ? L_4 : L_5 , V_44 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_21 , bool V_4 )
{
int V_6 ;
T_1 V_52 = V_9 ;
F_4 ( V_2 -> V_13 , L_9 ,
V_4 ? L_4 : L_5 , V_21 ) ;
switch ( V_21 ) {
case V_53 :
case V_54 :
V_52 = V_46 ;
break;
case V_55 :
V_52 = V_56 ;
break;
default:
return - V_43 ;
}
V_6 = F_1 ( V_2 , V_52 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_57 , V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_6 , V_21 ;
bool V_4 ;
V_21 = F_5 ( V_2 ,
V_27 , & V_4 ) ;
F_4 ( V_2 -> V_13 ,
L_10 ,
V_4 ? L_4 : L_5 , V_21 ,
V_2 -> V_29 ) ;
switch ( V_21 ) {
case V_33 :
V_6 = F_6 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
case V_53 :
case V_54 :
case V_55 :
V_6 = F_8 ( V_2 , V_21 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
case V_58 :
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
case V_28 :
F_3 ( V_2 -> V_13 ,
L_11 ,
V_4 ? L_4 : L_5 , V_21 ) ;
return - V_85 ;
default:
F_3 ( V_2 -> V_13 ,
L_12 ,
V_4 ? L_4 : L_5 , V_21 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_6 , V_20 , V_22 ;
bool V_4 ;
V_20 = F_5 ( V_2 ,
V_30 , & V_4 ) ;
F_4 ( V_2 -> V_13 ,
L_13 ,
V_4 ? L_4 : L_5 ,
V_20 , V_2 -> V_35 ) ;
switch ( V_20 ) {
case V_86 :
V_6 = F_1 ( V_2 , V_46 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_87 , V_4 ) ;
break;
case V_88 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_89 ,
V_4 ) ;
break;
case V_90 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_91 , V_4 ) ;
break;
case V_92 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_93 ,
V_4 ) ;
break;
case V_94 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , V_95 ,
V_4 ) ;
break;
case V_36 :
V_22 = F_5 ( V_2 ,
V_37 , & V_4 ) ;
if ( V_22 == V_49 )
F_7 ( V_2 -> V_47 , V_91 , true ) ;
else if ( V_22 == V_50 )
F_7 ( V_2 -> V_47 , V_91 , false ) ;
break;
case V_34 :
break;
default:
F_3 ( V_2 -> V_13 ,
L_14 ,
V_4 ? L_4 : L_5 , V_20 ) ;
F_1 ( V_2 , V_9 , V_4 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_11 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_12 ( V_97 ,
struct V_1 , V_98 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
F_13 ( & V_2 -> V_99 ) ;
V_6 = F_14 ( V_5 -> V_10 ,
V_100 , V_2 -> V_23 ,
V_101 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_15 ) ;
F_15 ( & V_2 -> V_99 ) ;
return;
}
if ( V_2 -> V_102 ) {
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
F_3 ( V_2 -> V_13 , L_16 ) ;
V_2 -> V_102 = false ;
}
if ( V_2 -> V_103 ) {
V_6 = F_10 ( V_2 ) ;
if ( V_6 )
F_3 ( V_2 -> V_13 , L_17 ) ;
V_2 -> V_103 = false ;
}
F_15 ( & V_2 -> V_99 ) ;
}
static T_2 F_16 ( int V_104 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
int V_106 , V_107 = - 1 ;
for ( V_106 = 0 ; V_106 < F_17 ( V_108 ) ; V_106 ++ )
if ( V_104 == V_108 [ V_106 ] . V_109 )
V_107 = V_108 [ V_106 ] . V_104 ;
switch ( V_107 ) {
case V_110 :
case V_111 :
case V_112 :
V_2 -> V_102 = true ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_2 -> V_103 = true ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
break;
default:
F_3 ( V_2 -> V_13 , L_18 , V_107 ) ;
break;
}
F_18 ( & V_2 -> V_98 ) ;
return V_126 ;
}
static void F_19 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_12 ( F_20 ( V_97 ) ,
struct V_1 , V_127 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_20 , V_19 , V_6 ;
bool V_4 ;
F_13 ( & V_2 -> V_99 ) ;
V_6 = F_14 ( V_5 -> V_10 ,
V_100 , V_2 -> V_23 ,
V_101 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_15 ) ;
goto V_128;
}
V_19 = F_5 ( V_2 ,
V_27 , & V_4 ) ;
if ( V_4 && V_19 != V_28 ) {
V_6 = F_9 ( V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_19 ) ;
goto V_128;
}
}
V_20 = F_5 ( V_2 ,
V_30 , & V_4 ) ;
if ( V_4 && V_20 != V_34 ) {
V_6 = F_10 ( V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_20 ) ;
goto V_128;
}
}
V_128:
F_15 ( & V_2 -> V_99 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_129 time )
{
struct V_5 * V_5 = V_2 -> V_5 ;
int V_6 ;
switch ( time ) {
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_6 = F_2 ( V_5 -> V_10 ,
V_134 ,
V_135 ,
time << V_136 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_21 ) ;
return V_6 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_22 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_22 ( struct V_5 * V_5 )
{
int V_6 ;
V_5 -> V_137 = F_23 ( V_5 -> V_138 -> V_139 ,
V_140 ) ;
if ( ! V_5 -> V_137 ) {
F_3 ( & V_5 -> V_138 -> V_13 ,
L_23 ) ;
return - V_141 ;
}
F_24 ( V_5 -> V_137 , V_5 ) ;
V_5 -> V_10 = F_25 ( V_5 -> V_137 ,
& V_142 ) ;
if ( F_26 ( V_5 -> V_10 ) ) {
V_6 = F_27 ( V_5 -> V_10 ) ;
goto V_143;
}
V_6 = F_28 ( V_5 -> V_10 , V_5 -> V_104 ,
V_144 | V_145 | V_146 ,
0 , & V_147 , & V_5 -> V_148 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_5 -> V_138 -> V_13 , L_24 ) ;
goto V_143;
}
return 0 ;
V_143:
F_29 ( V_5 -> V_137 ) ;
return V_6 ;
}
static int F_30 ( struct V_149 * V_150 )
{
struct V_5 * V_5 = F_31 ( V_150 -> V_13 . V_151 ) ;
struct V_1 * V_2 ;
unsigned int V_152 ;
int V_106 , V_6 ;
V_2 = F_32 ( & V_150 -> V_13 , sizeof( * V_2 ) , V_153 ) ;
if ( ! V_2 )
return - V_141 ;
V_2 -> V_13 = & V_150 -> V_13 ;
V_2 -> V_5 = V_5 ;
F_33 ( V_150 , V_2 ) ;
F_34 ( & V_2 -> V_99 ) ;
V_6 = F_22 ( V_5 ) ;
if ( V_6 ) {
F_3 ( & V_150 -> V_13 , L_25 ) ;
return V_6 ;
}
V_6 = F_2 ( V_5 -> V_10 ,
V_134 ,
V_154 |
V_155 ,
V_156 ) ;
V_2 -> V_47 = F_35 ( & V_150 -> V_13 ,
V_157 ) ;
if ( F_26 ( V_2 -> V_47 ) ) {
F_3 ( & V_150 -> V_13 , L_26 ) ;
V_6 = - V_158 ;
goto V_159;
}
V_6 = F_36 ( & V_150 -> V_13 , V_2 -> V_47 ) ;
if ( V_6 ) {
F_3 ( & V_150 -> V_13 , L_27 ) ;
goto V_159;
}
F_21 ( V_2 , V_132 ) ;
F_1 ( V_2 , V_56 , true ) ;
V_6 = F_37 ( V_5 -> V_10 , V_160 , & V_152 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_150 -> V_13 , L_28 ) ;
goto V_159;
}
F_38 ( V_2 -> V_13 , L_29 , V_152 ) ;
F_39 ( & V_2 -> V_98 , F_11 ) ;
for ( V_106 = 0 ; V_106 < F_17 ( V_108 ) ; V_106 ++ ) {
struct V_161 * V_162 = & V_108 [ V_106 ] ;
unsigned int V_109 = 0 ;
V_109 = F_40 ( V_5 -> V_148 ,
V_162 -> V_104 ) ;
if ( V_109 <= 0 ) {
V_6 = - V_43 ;
goto V_159;
}
V_162 -> V_109 = V_109 ;
V_6 = F_41 ( & V_150 -> V_13 , V_109 , NULL ,
F_16 , V_163 ,
V_162 -> V_164 , V_2 ) ;
if ( V_6 ) {
F_3 ( & V_150 -> V_13 ,
L_30 ,
V_162 -> V_104 , V_6 ) ;
goto V_159;
}
}
F_42 ( & V_2 -> V_127 , F_19 ) ;
F_43 ( V_165 ,
& V_2 -> V_127 , F_44 ( V_166 ) ) ;
return 0 ;
V_159:
F_45 ( V_5 -> V_104 , V_5 -> V_148 ) ;
F_29 ( V_5 -> V_137 ) ;
return V_6 ;
}
static int F_46 ( struct V_149 * V_150 )
{
struct V_1 * V_2 = F_47 ( V_150 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
F_48 ( & V_2 -> V_98 ) ;
F_45 ( V_5 -> V_104 , V_5 -> V_148 ) ;
F_29 ( V_5 -> V_137 ) ;
return 0 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_167 ) ;
}
