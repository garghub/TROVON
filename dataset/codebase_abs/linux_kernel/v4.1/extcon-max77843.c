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
F_7 ( V_2 -> V_47 , L_8 , V_4 ) ;
break;
case V_48 :
case V_49 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_9 , V_4 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_10 ,
V_4 ? L_4 : L_5 , V_44 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_21 , bool V_4 )
{
int V_6 ;
F_4 ( V_2 -> V_13 , L_11 ,
V_4 ? L_4 : L_5 , V_21 ) ;
switch ( V_21 ) {
case V_50 :
V_6 = F_1 ( V_2 , V_46 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_12 , V_4 ) ;
break;
case V_51 :
V_6 = F_1 ( V_2 , V_46 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_13 , V_4 ) ;
break;
case V_52 :
V_6 = F_1 ( V_2 , V_53 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_14 , V_4 ) ;
break;
default:
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_6 , V_21 ;
bool V_4 ;
V_21 = F_5 ( V_2 ,
V_27 , & V_4 ) ;
F_4 ( V_2 -> V_13 ,
L_15 ,
V_4 ? L_4 : L_5 , V_21 ,
V_2 -> V_29 ) ;
switch ( V_21 ) {
case V_33 :
V_6 = F_6 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
case V_50 :
case V_51 :
case V_52 :
V_6 = F_8 ( V_2 , V_21 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
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
case V_28 :
F_3 ( V_2 -> V_13 ,
L_16 ,
V_4 ? L_4 : L_5 , V_21 ) ;
return - V_81 ;
default:
F_3 ( V_2 -> V_13 ,
L_17 ,
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
L_18 ,
V_4 ? L_4 : L_5 ,
V_20 , V_2 -> V_35 ) ;
switch ( V_20 ) {
case V_82 :
V_6 = F_1 ( V_2 , V_46 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_19 , V_4 ) ;
break;
case V_83 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 ,
L_20 , V_4 ) ;
break;
case V_84 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_21 , V_4 ) ;
break;
case V_85 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_22 , V_4 ) ;
break;
case V_86 :
V_6 = F_1 ( V_2 , V_9 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_2 -> V_47 , L_23 , V_4 ) ;
break;
case V_36 :
V_22 = F_5 ( V_2 ,
V_37 , & V_4 ) ;
if ( V_22 == V_48 )
F_7 ( V_2 -> V_47 , L_24 , true ) ;
else if ( V_22 == V_49 )
F_7 ( V_2 -> V_47 , L_24 , false ) ;
break;
case V_34 :
break;
default:
F_3 ( V_2 -> V_13 ,
L_25 ,
V_4 ? L_4 : L_5 , V_20 ) ;
F_1 ( V_2 , V_9 , V_4 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_11 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_12 ( V_88 ,
struct V_1 , V_89 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
F_13 ( & V_2 -> V_90 ) ;
V_6 = F_14 ( V_5 -> V_10 ,
V_91 , V_2 -> V_23 ,
V_92 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_26 ) ;
F_15 ( & V_2 -> V_90 ) ;
return;
}
if ( V_2 -> V_93 ) {
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
F_3 ( V_2 -> V_13 , L_27 ) ;
V_2 -> V_93 = false ;
}
if ( V_2 -> V_94 ) {
V_6 = F_10 ( V_2 ) ;
if ( V_6 )
F_3 ( V_2 -> V_13 , L_28 ) ;
V_2 -> V_94 = false ;
}
F_15 ( & V_2 -> V_90 ) ;
}
static T_2 F_16 ( int V_95 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
int V_97 , V_98 = - 1 ;
for ( V_97 = 0 ; V_97 < F_17 ( V_99 ) ; V_97 ++ )
if ( V_95 == V_99 [ V_97 ] . V_100 )
V_98 = V_99 [ V_97 ] . V_95 ;
switch ( V_98 ) {
case V_101 :
case V_102 :
case V_103 :
V_2 -> V_93 = true ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_2 -> V_94 = true ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
break;
default:
F_3 ( V_2 -> V_13 , L_29 , V_98 ) ;
break;
}
F_18 ( & V_2 -> V_89 ) ;
return V_117 ;
}
static void F_19 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_12 ( F_20 ( V_88 ) ,
struct V_1 , V_118 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_20 , V_19 , V_6 ;
bool V_4 ;
F_13 ( & V_2 -> V_90 ) ;
V_6 = F_14 ( V_5 -> V_10 ,
V_91 , V_2 -> V_23 ,
V_92 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_26 ) ;
goto V_119;
}
V_19 = F_5 ( V_2 ,
V_27 , & V_4 ) ;
if ( V_4 && V_19 != V_28 ) {
V_6 = F_9 ( V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_30 ) ;
goto V_119;
}
}
V_20 = F_5 ( V_2 ,
V_30 , & V_4 ) ;
if ( V_4 && V_20 != V_34 ) {
V_6 = F_10 ( V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_31 ) ;
goto V_119;
}
}
V_119:
F_15 ( & V_2 -> V_90 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_120 time )
{
struct V_5 * V_5 = V_2 -> V_5 ;
int V_6 ;
switch ( time ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_6 = F_2 ( V_5 -> V_10 ,
V_125 ,
V_126 ,
time << V_127 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_13 , L_32 ) ;
return V_6 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_33 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_22 ( struct V_5 * V_5 )
{
int V_6 ;
V_5 -> V_128 = F_23 ( V_5 -> V_129 -> V_130 ,
V_131 ) ;
if ( ! V_5 -> V_128 ) {
F_3 ( & V_5 -> V_129 -> V_13 ,
L_34 ) ;
return - V_132 ;
}
F_24 ( V_5 -> V_128 , V_5 ) ;
V_5 -> V_10 = F_25 ( V_5 -> V_128 ,
& V_133 ) ;
if ( F_26 ( V_5 -> V_10 ) ) {
V_6 = F_27 ( V_5 -> V_10 ) ;
goto V_134;
}
V_6 = F_28 ( V_5 -> V_10 , V_5 -> V_95 ,
V_135 | V_136 | V_137 ,
0 , & V_138 , & V_5 -> V_139 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_5 -> V_129 -> V_13 , L_35 ) ;
goto V_134;
}
return 0 ;
V_134:
F_29 ( V_5 -> V_128 ) ;
return V_6 ;
}
static int F_30 ( struct V_140 * V_141 )
{
struct V_5 * V_5 = F_31 ( V_141 -> V_13 . V_142 ) ;
struct V_1 * V_2 ;
unsigned int V_143 ;
int V_97 , V_6 ;
V_2 = F_32 ( & V_141 -> V_13 , sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 )
return - V_132 ;
V_2 -> V_13 = & V_141 -> V_13 ;
V_2 -> V_5 = V_5 ;
F_33 ( V_141 , V_2 ) ;
F_34 ( & V_2 -> V_90 ) ;
V_6 = F_22 ( V_5 ) ;
if ( V_6 ) {
F_3 ( & V_141 -> V_13 , L_36 ) ;
return V_6 ;
}
V_6 = F_2 ( V_5 -> V_10 ,
V_125 ,
V_145 |
V_146 ,
V_147 ) ;
V_2 -> V_47 = F_35 ( & V_141 -> V_13 ,
V_148 ) ;
if ( F_26 ( V_2 -> V_47 ) ) {
F_3 ( & V_141 -> V_13 , L_37 ) ;
V_6 = - V_149 ;
goto V_150;
}
V_6 = F_36 ( & V_141 -> V_13 , V_2 -> V_47 ) ;
if ( V_6 ) {
F_3 ( & V_141 -> V_13 , L_38 ) ;
goto V_150;
}
F_21 ( V_2 , V_123 ) ;
F_1 ( V_2 , V_53 , true ) ;
V_6 = F_37 ( V_5 -> V_10 , V_151 , & V_143 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_141 -> V_13 , L_39 ) ;
goto V_150;
}
F_38 ( V_2 -> V_13 , L_40 , V_143 ) ;
F_39 ( & V_2 -> V_89 , F_11 ) ;
for ( V_97 = 0 ; V_97 < F_17 ( V_99 ) ; V_97 ++ ) {
struct V_152 * V_153 = & V_99 [ V_97 ] ;
unsigned int V_100 = 0 ;
V_100 = F_40 ( V_5 -> V_139 ,
V_153 -> V_95 ) ;
if ( V_100 <= 0 ) {
V_6 = - V_43 ;
goto V_150;
}
V_153 -> V_100 = V_100 ;
V_6 = F_41 ( & V_141 -> V_13 , V_100 , NULL ,
F_16 , V_154 ,
V_153 -> V_155 , V_2 ) ;
if ( V_6 ) {
F_3 ( & V_141 -> V_13 ,
L_41 ,
V_153 -> V_95 , V_6 ) ;
goto V_150;
}
}
F_42 ( & V_2 -> V_118 , F_19 ) ;
F_43 ( V_156 ,
& V_2 -> V_118 , F_44 ( V_157 ) ) ;
return 0 ;
V_150:
F_45 ( V_5 -> V_95 , V_5 -> V_139 ) ;
F_29 ( V_5 -> V_128 ) ;
return V_6 ;
}
static int F_46 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_47 ( V_141 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
F_48 ( & V_2 -> V_89 ) ;
F_45 ( V_5 -> V_95 , V_5 -> V_139 ) ;
F_29 ( V_5 -> V_128 ) ;
return 0 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_158 ) ;
}
