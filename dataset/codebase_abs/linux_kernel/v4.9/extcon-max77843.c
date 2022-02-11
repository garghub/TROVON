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
F_7 ( V_2 -> V_48 , V_89 ,
V_4 ) ;
break;
case V_90 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_91 ,
V_4 ) ;
break;
case V_92 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_93 ,
V_4 ) ;
break;
case V_94 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_95 ,
V_4 ) ;
break;
case V_96 :
V_7 = F_1 ( V_2 ,
V_10 ,
V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( V_2 -> V_48 , V_97 ,
V_4 ) ;
break;
case V_37 :
V_23 = F_5 ( V_2 ,
V_38 , & V_4 ) ;
if ( V_23 == V_50 )
F_7 ( V_2 -> V_48 , V_93 ,
true ) ;
else if ( V_23 == V_51 )
F_7 ( V_2 -> V_48 , V_93 ,
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
static void F_11 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_12 ( V_99 ,
struct V_1 , V_100 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
F_13 ( & V_2 -> V_101 ) ;
V_7 = F_14 ( V_6 -> V_11 ,
V_102 , V_2 -> V_24 ,
V_103 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_14 , L_15 ) ;
F_15 ( & V_2 -> V_101 ) ;
return;
}
if ( V_2 -> V_104 ) {
V_7 = F_9 ( V_2 ) ;
if ( V_7 )
F_3 ( V_2 -> V_14 , L_16 ) ;
V_2 -> V_104 = false ;
}
if ( V_2 -> V_105 ) {
V_7 = F_10 ( V_2 ) ;
if ( V_7 )
F_3 ( V_2 -> V_14 , L_17 ) ;
V_2 -> V_105 = false ;
}
F_15 ( & V_2 -> V_101 ) ;
}
static T_2 F_16 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
int V_108 , V_109 = - 1 ;
for ( V_108 = 0 ; V_108 < F_17 ( V_110 ) ; V_108 ++ )
if ( V_106 == V_110 [ V_108 ] . V_111 )
V_109 = V_110 [ V_108 ] . V_106 ;
switch ( V_109 ) {
case V_112 :
case V_113 :
case V_114 :
V_2 -> V_104 = true ;
break;
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_2 -> V_105 = true ;
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
break;
default:
F_3 ( V_2 -> V_14 , L_18 , V_109 ) ;
break;
}
F_18 ( & V_2 -> V_100 ) ;
return V_128 ;
}
static void F_19 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_12 ( F_20 ( V_99 ) ,
struct V_1 , V_129 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_21 , V_20 , V_7 ;
bool V_4 ;
F_13 ( & V_2 -> V_101 ) ;
V_7 = F_14 ( V_6 -> V_11 ,
V_102 , V_2 -> V_24 ,
V_103 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_14 , L_15 ) ;
goto V_130;
}
V_20 = F_5 ( V_2 ,
V_28 , & V_4 ) ;
if ( V_4 && V_20 != V_29 ) {
V_7 = F_9 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_14 , L_19 ) ;
goto V_130;
}
}
V_21 = F_5 ( V_2 ,
V_31 , & V_4 ) ;
if ( V_4 && V_21 != V_35 ) {
V_7 = F_10 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_14 , L_20 ) ;
goto V_130;
}
}
V_130:
F_15 ( & V_2 -> V_101 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_131 time )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
switch ( time ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
V_7 = F_2 ( V_6 -> V_11 ,
V_136 ,
V_137 ,
time << V_138 ) ;
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
V_6 -> V_139 = F_23 ( V_6 -> V_140 -> V_141 ,
V_142 ) ;
if ( ! V_6 -> V_139 ) {
F_3 ( & V_6 -> V_140 -> V_14 ,
L_23 ) ;
return - V_143 ;
}
F_24 ( V_6 -> V_139 , V_6 ) ;
V_6 -> V_11 = F_25 ( V_6 -> V_139 ,
& V_144 ) ;
if ( F_26 ( V_6 -> V_11 ) ) {
V_7 = F_27 ( V_6 -> V_11 ) ;
goto V_145;
}
V_7 = F_28 ( V_6 -> V_11 , V_6 -> V_106 ,
V_146 | V_147 | V_148 ,
0 , & V_149 , & V_6 -> V_150 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_140 -> V_14 , L_24 ) ;
goto V_145;
}
return 0 ;
V_145:
F_29 ( V_6 -> V_139 ) ;
return V_7 ;
}
static int F_30 ( struct V_151 * V_152 )
{
struct V_5 * V_6 = F_31 ( V_152 -> V_14 . V_153 ) ;
struct V_1 * V_2 ;
unsigned int V_154 ;
int V_108 , V_7 ;
V_2 = F_32 ( & V_152 -> V_14 , sizeof( * V_2 ) , V_155 ) ;
if ( ! V_2 )
return - V_143 ;
V_2 -> V_14 = & V_152 -> V_14 ;
V_2 -> V_6 = V_6 ;
F_33 ( V_152 , V_2 ) ;
F_34 ( & V_2 -> V_101 ) ;
V_7 = F_22 ( V_6 ) ;
if ( V_7 ) {
F_3 ( & V_152 -> V_14 , L_25 ) ;
return V_7 ;
}
V_7 = F_2 ( V_6 -> V_11 ,
V_136 ,
V_156 |
V_157 ,
V_158 ) ;
V_2 -> V_48 = F_35 ( & V_152 -> V_14 ,
V_159 ) ;
if ( F_26 ( V_2 -> V_48 ) ) {
F_3 ( & V_152 -> V_14 , L_26 ) ;
V_7 = - V_160 ;
goto V_161;
}
V_7 = F_36 ( & V_152 -> V_14 , V_2 -> V_48 ) ;
if ( V_7 ) {
F_3 ( & V_152 -> V_14 , L_27 ) ;
goto V_161;
}
F_21 ( V_2 , V_134 ) ;
F_1 ( V_2 , V_57 , true ) ;
V_7 = F_37 ( V_6 -> V_11 , V_162 , & V_154 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_152 -> V_14 , L_28 ) ;
goto V_161;
}
F_38 ( V_2 -> V_14 , L_29 , V_154 ) ;
F_39 ( & V_2 -> V_100 , F_11 ) ;
V_7 = F_14 ( V_6 -> V_11 ,
V_163 , V_2 -> V_24 ,
V_103 ) ;
if ( V_7 ) {
F_3 ( & V_152 -> V_14 , L_30 ) ;
goto V_161;
}
for ( V_108 = 0 ; V_108 < F_17 ( V_110 ) ; V_108 ++ ) {
struct V_164 * V_165 = & V_110 [ V_108 ] ;
int V_111 = 0 ;
V_111 = F_40 ( V_6 -> V_150 ,
V_165 -> V_106 ) ;
if ( V_111 <= 0 ) {
V_7 = - V_44 ;
goto V_161;
}
V_165 -> V_111 = V_111 ;
V_7 = F_41 ( & V_152 -> V_14 , V_111 , NULL ,
F_16 , V_166 ,
V_165 -> V_167 , V_2 ) ;
if ( V_7 ) {
F_3 ( & V_152 -> V_14 ,
L_31 ,
V_165 -> V_106 , V_7 ) ;
goto V_161;
}
}
F_42 ( & V_2 -> V_129 , F_19 ) ;
F_43 ( V_168 ,
& V_2 -> V_129 , F_44 ( V_169 ) ) ;
return 0 ;
V_161:
F_45 ( V_6 -> V_106 , V_6 -> V_150 ) ;
F_29 ( V_6 -> V_139 ) ;
return V_7 ;
}
static int F_46 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = F_47 ( V_152 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_48 ( & V_2 -> V_100 ) ;
F_45 ( V_6 -> V_106 , V_6 -> V_150 ) ;
F_29 ( V_6 -> V_139 ) ;
return 0 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_170 ) ;
}
