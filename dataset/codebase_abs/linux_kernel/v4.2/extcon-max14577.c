static int F_1 ( struct V_1 * V_2 ,
enum V_3 time )
{
T_1 V_4 ;
switch ( time ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_11 ,
V_12 ,
time << V_13 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_1 ) ;
return V_4 ;
}
break;
default:
F_3 ( V_2 -> V_14 , L_2 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_16 , bool V_17 )
{
int V_4 = 0 ;
T_1 V_18 , V_19 = 0 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_20 ,
V_21 , V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return V_4 ;
}
if ( V_17 )
V_18 = V_16 ;
else
V_18 = V_22 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_20 ,
V_21 , V_18 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return V_4 ;
}
if ( V_17 )
V_19 |= V_23 ;
else
V_19 |= V_24 ;
V_4 = F_2 ( V_2 -> V_9 -> V_10 ,
V_25 ,
V_24 | V_23 , V_19 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_3 ) ;
return V_4 ;
}
F_5 ( V_2 -> V_14 ,
L_4 ,
V_18 , V_19 , V_17 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_26 V_27 , bool * V_17 )
{
int V_28 = 0 ;
int V_29 ;
int V_30 ;
switch ( V_27 ) {
case V_31 :
V_29 = V_2 -> V_32 [ V_33 ] & V_34 ;
V_29 >>= V_35 ;
if ( V_29 == V_36 ) {
* V_17 = false ;
V_28 = V_2 -> V_37 ;
V_2 -> V_37 = V_36 ;
} else {
* V_17 = true ;
V_28 = V_2 -> V_37 = V_29 ;
}
break;
case V_38 :
V_30 = V_2 -> V_32 [ V_39 ] &
V_40 ;
V_30 >>= V_41 ;
if ( V_30 == V_42 ) {
* V_17 = false ;
V_28 = V_2 -> V_43 ;
V_2 -> V_43 = V_42 ;
} else {
* V_17 = true ;
V_28 = V_2 -> V_43 = V_30 ;
}
break;
default:
F_3 ( V_2 -> V_14 , L_7 , V_27 ) ;
V_28 = - V_15 ;
break;
}
return V_28 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_28 , bool V_17 )
{
int V_4 = 0 ;
T_1 V_44 = V_22 ;
F_5 ( V_2 -> V_14 ,
L_8 ,
V_17 ? L_5 : L_6 , V_28 ) ;
switch ( V_28 ) {
case V_45 :
case V_46 :
V_44 = V_47 ;
break;
case V_48 :
V_44 = V_49 ;
break;
default:
F_3 ( V_2 -> V_14 , L_9 ,
V_17 ? L_5 : L_6 ) ;
return - V_15 ;
}
V_4 = F_4 ( V_2 , V_44 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_8 ( V_2 -> V_50 , V_51 , V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_28 ;
bool V_17 ;
int V_4 = 0 ;
V_28 = F_6 ( V_2 ,
V_31 , & V_17 ) ;
F_5 ( V_2 -> V_14 ,
L_10 ,
V_17 ? L_5 : L_6 , V_28 ,
V_2 -> V_37 ) ;
switch ( V_28 ) {
case V_45 :
case V_46 :
case V_48 :
V_4 = F_7 ( V_2 , V_28 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_52 :
case V_53 :
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
F_10 ( V_2 -> V_14 ,
L_11 ,
V_17 ? L_5 : L_6 , V_28 ) ;
return - V_80 ;
default:
F_3 ( V_2 -> V_14 ,
L_12 ,
V_17 ? L_5 : L_6 , V_28 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_30 ;
bool V_17 ;
int V_4 = 0 ;
V_30 = F_6 ( V_2 ,
V_38 , & V_17 ) ;
F_5 ( V_2 -> V_14 ,
L_13 ,
V_17 ? L_5 : L_6 ,
V_30 , V_2 -> V_43 ) ;
switch ( V_30 ) {
case V_81 :
V_4 = F_4 ( V_2 , V_2 -> V_82 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_8 ( V_2 -> V_50 , V_83 , V_17 ) ;
break;
case V_84 :
F_8 ( V_2 -> V_50 , V_85 , V_17 ) ;
break;
case V_86 :
F_8 ( V_2 -> V_50 , V_87 ,
V_17 ) ;
break;
case V_88 :
F_8 ( V_2 -> V_50 , V_89 ,
V_17 ) ;
break;
case V_90 :
F_8 ( V_2 -> V_50 , V_91 ,
V_17 ) ;
break;
case V_42 :
case V_92 :
break;
default:
F_3 ( V_2 -> V_14 ,
L_14 ,
V_17 ? L_5 : L_6 , V_30 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_12 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_13 ( V_94 ,
struct V_1 , V_95 ) ;
int V_4 = 0 ;
if ( ! V_2 -> V_50 )
return;
F_14 ( & V_2 -> V_96 ) ;
V_4 = F_15 ( V_2 -> V_9 -> V_10 ,
V_97 , V_2 -> V_32 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_15 ) ;
F_16 ( & V_2 -> V_96 ) ;
return;
}
if ( V_2 -> V_98 ) {
V_4 = F_9 ( V_2 ) ;
V_2 -> V_98 = false ;
}
if ( V_2 -> V_99 ) {
V_4 = F_11 ( V_2 ) ;
V_2 -> V_99 = false ;
}
if ( V_4 < 0 )
F_3 ( V_2 -> V_14 , L_16 ) ;
F_16 ( & V_2 -> V_96 ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_100 )
{
switch ( V_100 ) {
case V_101 :
case V_102 :
case V_103 :
V_2 -> V_98 = true ;
return 1 ;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_2 -> V_99 = true ;
return 1 ;
default:
return 0 ;
}
}
static int F_18 ( struct V_1 * V_2 , int V_100 )
{
if ( F_17 ( V_2 , V_100 ) )
return 1 ;
switch ( V_100 ) {
case V_109 :
V_2 -> V_98 = true ;
return 1 ;
case V_110 :
V_2 -> V_99 = true ;
return 1 ;
default:
return 0 ;
}
}
static T_2 F_19 ( int V_111 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
int V_113 , V_100 = - 1 ;
bool V_114 ;
for ( V_113 = 0 ; V_113 < V_2 -> V_115 ; V_113 ++ )
if ( V_111 == V_2 -> V_116 [ V_113 ] . V_117 )
V_100 = V_2 -> V_116 [ V_113 ] . V_111 ;
switch ( V_2 -> V_9 -> V_118 ) {
case V_119 :
V_114 = F_18 ( V_2 , V_100 ) ;
break;
case V_120 :
default:
V_114 = F_17 ( V_2 , V_100 ) ;
break;
}
if ( ! V_114 ) {
F_3 ( V_2 -> V_14 , L_17 ,
V_100 ) ;
return V_121 ;
}
F_20 ( & V_2 -> V_95 ) ;
return V_121 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
int V_29 ;
int V_30 ;
bool V_17 ;
F_14 ( & V_2 -> V_96 ) ;
V_4 = F_15 ( V_2 -> V_9 -> V_10 ,
V_97 , V_2 -> V_32 , 2 ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_14 , L_15 ) ;
F_16 ( & V_2 -> V_96 ) ;
return V_4 ;
}
V_29 = F_6 ( V_2 , V_31 ,
& V_17 ) ;
if ( V_17 && V_29 != V_36 ) {
V_4 = F_9 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_18 ) ;
F_16 ( & V_2 -> V_96 ) ;
return V_4 ;
}
}
V_30 = F_6 ( V_2 , V_38 ,
& V_17 ) ;
if ( V_17 && V_30 != V_42 ) {
V_4 = F_11 ( V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_14 , L_19 ) ;
F_16 ( & V_2 -> V_96 ) ;
return V_4 ;
}
}
F_16 ( & V_2 -> V_96 ) ;
return 0 ;
}
static void F_22 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_13 ( F_23 ( V_94 ) ,
struct V_1 , V_122 ) ;
F_21 ( V_2 ) ;
}
static int F_24 ( struct V_123 * V_124 )
{
struct V_9 * V_9 = F_25 ( V_124 -> V_14 . V_125 ) ;
struct V_1 * V_2 ;
int V_126 ;
int V_4 ;
int V_113 ;
T_1 V_127 ;
V_2 = F_26 ( & V_124 -> V_14 , sizeof( * V_2 ) , V_128 ) ;
if ( ! V_2 )
return - V_129 ;
V_2 -> V_14 = & V_124 -> V_14 ;
V_2 -> V_9 = V_9 ;
F_27 ( V_124 , V_2 ) ;
F_28 ( & V_2 -> V_96 ) ;
F_29 ( & V_2 -> V_95 , F_12 ) ;
switch ( V_9 -> V_118 ) {
case V_119 :
V_2 -> V_116 = V_130 ;
V_2 -> V_115 = F_30 ( V_130 ) ;
break;
case V_120 :
default:
V_2 -> V_116 = V_131 ;
V_2 -> V_115 = F_30 ( V_131 ) ;
}
for ( V_113 = 0 ; V_113 < V_2 -> V_115 ; V_113 ++ ) {
struct V_132 * V_133 = & V_2 -> V_116 [ V_113 ] ;
unsigned int V_117 = 0 ;
V_117 = F_31 ( V_9 -> V_134 , V_133 -> V_111 ) ;
if ( V_117 <= 0 )
return - V_15 ;
V_133 -> V_117 = V_117 ;
V_4 = F_32 ( & V_124 -> V_14 , V_117 , NULL ,
F_19 ,
V_135 ,
V_133 -> V_136 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_124 -> V_14 ,
L_20 ,
V_133 -> V_111 , V_4 ) ;
return V_4 ;
}
}
V_2 -> V_50 = F_33 ( & V_124 -> V_14 ,
V_137 ) ;
if ( F_34 ( V_2 -> V_50 ) ) {
F_3 ( & V_124 -> V_14 , L_21 ) ;
return - V_129 ;
}
V_4 = F_35 ( & V_124 -> V_14 , V_2 -> V_50 ) ;
if ( V_4 ) {
F_3 ( & V_124 -> V_14 , L_22 ) ;
return V_4 ;
}
V_2 -> V_82 = V_47 ;
V_2 -> V_138 = V_49 ;
V_126 = F_36 ( V_139 ) ;
F_4 ( V_2 , V_2 -> V_138 , true ) ;
V_4 = F_37 ( V_2 -> V_9 -> V_10 ,
V_140 , & V_127 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_124 -> V_14 , L_23 ) ;
return V_4 ;
}
F_10 ( V_2 -> V_14 , L_24 , V_127 ) ;
F_1 ( V_2 , V_7 ) ;
F_38 ( & V_2 -> V_122 , F_22 ) ;
F_39 ( V_141 , & V_2 -> V_122 ,
V_126 ) ;
return V_4 ;
}
static int F_40 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_41 ( V_124 ) ;
F_42 ( & V_2 -> V_95 ) ;
return 0 ;
}
