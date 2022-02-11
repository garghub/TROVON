static int F_1 ( struct V_1 * V_2 ,
enum V_3 time )
{
int V_4 ;
switch ( time ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
V_4 = F_2 ( V_2 -> V_9 ,
V_10 ,
time << V_11 ,
V_12 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
return V_4 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_2 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_15 , bool V_16 )
{
int V_4 = 0 ;
T_1 V_17 , V_18 = 0 ;
if ( V_16 )
V_17 = V_15 ;
else
V_17 = V_19 ;
V_4 = F_2 ( V_2 -> V_9 ,
V_20 , V_17 , V_21 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
if ( V_16 )
V_18 |= V_22 ;
else
V_18 |= V_23 ;
V_4 = F_2 ( V_2 -> V_9 ,
V_24 , V_18 ,
V_23 | V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
return V_4 ;
}
F_5 ( V_2 -> V_13 ,
L_4 ,
V_17 , V_18 , V_16 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_25 V_26 , bool * V_16 )
{
int V_27 = 0 ;
int V_28 ;
int V_29 ;
switch ( V_26 ) {
case V_30 :
V_28 = V_2 -> V_31 [ 0 ] & V_32 ;
V_28 >>= V_33 ;
if ( V_28 == V_34 ) {
* V_16 = false ;
V_27 = V_2 -> V_35 ;
V_2 -> V_35 = V_34 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_35 = V_28 ;
}
break;
case V_36 :
V_29 = V_2 -> V_31 [ 1 ] & V_37 ;
V_29 >>= V_38 ;
if ( V_29 == V_39 ) {
* V_16 = false ;
V_27 = V_2 -> V_40 ;
V_2 -> V_40 = V_39 ;
} else {
* V_16 = true ;
V_27 = V_2 -> V_40 = V_29 ;
}
break;
default:
F_3 ( V_2 -> V_13 , L_7 , V_26 ) ;
V_27 = - V_14 ;
break;
}
return V_27 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_41 V_42 , bool V_16 )
{
int V_4 = 0 ;
if ( V_42 == V_43 ) {
V_4 = F_4 ( V_2 , V_2 -> V_44 , V_16 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
}
switch ( V_42 ) {
case V_43 :
F_8 ( V_2 -> V_45 , V_46 , V_16 ) ;
break;
case V_47 :
F_8 ( V_2 -> V_45 , V_48 , V_16 ) ;
F_8 ( V_2 -> V_45 , V_49 ,
V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_9 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_27 , bool V_16 )
{
int V_4 = 0 ;
V_4 = F_4 ( V_2 , V_50 , V_16 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
switch ( V_27 ) {
case V_51 :
case V_52 :
F_8 ( V_2 -> V_45 , V_53 , V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 , L_10 ,
V_16 ? L_5 : L_6 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
bool V_16 )
{
int V_4 = 0 ;
V_4 = F_4 ( V_2 , V_2 -> V_54 , V_16 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return V_4 ;
}
F_8 ( V_2 -> V_45 , V_55 , V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_27 ;
bool V_16 ;
int V_4 = 0 ;
V_27 = F_6 ( V_2 ,
V_30 , & V_16 ) ;
switch ( V_27 ) {
case V_56 :
V_4 = F_7 ( V_2 , V_43 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_57 :
F_8 ( V_2 -> V_45 , V_58 , V_16 ) ;
break;
case V_59 :
case V_60 :
V_4 = F_7 ( V_2 ,
V_47 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_51 :
case V_52 :
V_4 = F_9 ( V_2 , V_27 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_61 :
V_4 = F_10 ( V_2 , V_16 ) ;
break;
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
F_5 ( V_2 -> V_13 ,
L_11 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_86 ;
default:
F_3 ( V_2 -> V_13 ,
L_12 ,
V_16 ? L_5 : L_6 , V_27 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_29 ;
bool V_16 ;
int V_28 ;
V_29 = F_6 ( V_2 ,
V_36 , & V_16 ) ;
switch ( V_29 ) {
case V_39 :
break;
case V_87 :
V_28 = V_2 -> V_31 [ 0 ] & V_32 ;
V_28 >>= V_33 ;
if ( ( V_28 & V_32 ) == V_34 ) {
F_7 ( V_2 ,
V_47 , V_16 ) ;
}
break;
case V_88 :
F_8 ( V_2 -> V_45 , V_89 ,
V_16 ) ;
break;
case V_90 :
F_8 ( V_2 -> V_45 , V_91 ,
V_16 ) ;
break;
case V_92 :
F_8 ( V_2 -> V_45 , V_93 ,
V_16 ) ;
break;
case V_94 :
F_8 ( V_2 -> V_45 , V_95 ,
V_16 ) ;
break;
default:
F_3 ( V_2 -> V_13 ,
L_13 ,
V_16 ? L_5 : L_6 , V_29 ) ;
return - V_14 ;
}
return 0 ;
}
static void F_13 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_14 ( V_97 ,
struct V_1 , V_98 ) ;
int V_99 = 0 ;
int V_100 , V_4 ;
if ( ! V_2 -> V_45 )
return;
F_15 ( & V_2 -> V_101 ) ;
for ( V_100 = 0 ; V_100 < F_16 ( V_102 ) ; V_100 ++ )
if ( V_2 -> V_103 == V_102 [ V_100 ] . V_104 )
V_99 = V_102 [ V_100 ] . V_103 ;
V_4 = F_17 ( V_2 -> V_9 , V_105 ,
2 , V_2 -> V_31 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_14 ) ;
F_18 ( & V_2 -> V_101 ) ;
return;
}
switch ( V_99 ) {
case V_106 :
case V_107 :
case V_108 :
V_4 = F_11 ( V_2 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_4 = F_12 ( V_2 ) ;
break;
case V_114 :
break;
default:
F_5 ( V_2 -> V_13 , L_15 ,
V_99 ) ;
F_18 ( & V_2 -> V_101 ) ;
return;
}
if ( V_4 < 0 )
F_3 ( V_2 -> V_13 , L_16 ) ;
F_18 ( & V_2 -> V_101 ) ;
}
static T_2 F_19 ( int V_103 , void * V_115 )
{
struct V_1 * V_2 = V_115 ;
F_20 ( V_2 -> V_13 , L_17 , V_103 ) ;
V_2 -> V_103 = V_103 ;
F_21 ( & V_2 -> V_98 ) ;
return V_116 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_28 ;
int V_29 ;
bool V_16 ;
F_15 ( & V_2 -> V_101 ) ;
V_4 = F_17 ( V_2 -> V_9 ,
V_105 , 2 , V_2 -> V_31 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_13 , L_18 ) ;
F_18 ( & V_2 -> V_101 ) ;
return V_4 ;
}
V_28 = F_6 ( V_2 , V_30 ,
& V_16 ) ;
if ( V_16 && V_28 != V_34 ) {
V_4 = F_11 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_19 ) ;
F_18 ( & V_2 -> V_101 ) ;
return V_4 ;
}
}
V_29 = F_6 ( V_2 , V_36 ,
& V_16 ) ;
if ( V_16 && V_29 != V_39 ) {
V_4 = F_12 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_13 , L_20 ) ;
F_18 ( & V_2 -> V_101 ) ;
return V_4 ;
}
}
F_18 ( & V_2 -> V_101 ) ;
return 0 ;
}
static void F_23 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_14 ( F_24 ( V_97 ) ,
struct V_1 , V_117 ) ;
int V_4 ;
V_4 = F_22 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( V_2 -> V_13 , L_21 ) ;
}
static int F_25 ( struct V_118 * V_119 )
{
struct V_120 * V_121 = F_26 ( V_119 -> V_13 . V_122 ) ;
struct V_123 * V_124 = F_27 ( V_121 -> V_13 ) ;
struct V_1 * V_2 ;
int V_125 ;
int V_4 , V_100 ;
V_2 = F_28 ( & V_119 -> V_13 , sizeof( struct V_1 ) ,
V_126 ) ;
if ( ! V_2 )
return - V_127 ;
V_2 -> V_13 = & V_119 -> V_13 ;
V_2 -> V_9 = V_121 -> V_9 ;
F_29 ( V_119 , V_2 ) ;
F_30 ( & V_2 -> V_101 ) ;
F_31 ( & V_2 -> V_98 , F_13 ) ;
for ( V_100 = 0 ; V_100 < F_16 ( V_102 ) ; V_100 ++ ) {
struct V_128 * V_129 = & V_102 [ V_100 ] ;
unsigned int V_104 = 0 ;
V_104 = F_32 ( V_121 -> V_130 , V_129 -> V_103 ) ;
if ( ! V_104 ) {
V_4 = - V_14 ;
goto V_131;
}
V_129 -> V_104 = V_104 ;
V_4 = F_33 ( V_104 , NULL ,
F_19 ,
V_132 ,
V_129 -> V_133 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_119 -> V_13 ,
L_22 ,
V_129 -> V_103 , V_4 ) ;
goto V_131;
}
}
V_2 -> V_45 = F_34 ( & V_119 -> V_13 , V_134 ) ;
if ( F_35 ( V_2 -> V_45 ) ) {
F_3 ( & V_119 -> V_13 , L_23 ) ;
V_4 = - V_127 ;
goto V_131;
}
V_4 = F_36 ( & V_119 -> V_13 , V_2 -> V_45 ) ;
if ( V_4 ) {
F_3 ( & V_119 -> V_13 , L_24 ) ;
goto V_131;
}
if ( V_124 && V_124 -> V_135 ) {
struct V_136 * V_135
= V_124 -> V_135 ;
for ( V_100 = 0 ; V_100 < V_135 -> V_137 ; V_100 ++ ) {
F_37 ( V_2 -> V_9 ,
V_135 -> V_138 [ V_100 ] . V_139 ,
V_135 -> V_138 [ V_100 ] . V_115 ) ;
}
if ( V_135 -> V_54 )
V_2 -> V_54 = V_135 -> V_54 ;
else
V_2 -> V_54 = V_140 ;
if ( V_135 -> V_44 )
V_2 -> V_44 = V_135 -> V_44 ;
else
V_2 -> V_44 = V_141 ;
if ( V_135 -> V_142 )
V_125 =
F_38 ( V_135 -> V_142 ) ;
else
V_125 = F_38 ( V_143 ) ;
} else {
V_2 -> V_54 = V_140 ;
V_2 -> V_44 = V_141 ;
V_125 = F_38 ( V_143 ) ;
}
F_4 ( V_2 , V_2 -> V_54 , true ) ;
F_1 ( V_2 , V_7 ) ;
F_39 ( & V_2 -> V_117 , F_23 ) ;
F_40 ( V_144 , & V_2 -> V_117 ,
V_125 ) ;
return 0 ;
V_131:
while ( -- V_100 >= 0 )
F_41 ( V_102 [ V_100 ] . V_104 , V_2 ) ;
return V_4 ;
}
static int F_42 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_43 ( V_119 ) ;
int V_100 ;
for ( V_100 = 0 ; V_100 < F_16 ( V_102 ) ; V_100 ++ )
F_41 ( V_102 [ V_100 ] . V_104 , V_2 ) ;
F_44 ( & V_2 -> V_98 ) ;
return 0 ;
}
