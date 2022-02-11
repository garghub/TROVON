static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return true ;
default:
break;
}
return false ;
}
static int F_2 ( struct V_6 * V_7 ,
unsigned int V_8 , bool V_9 )
{
int V_10 ;
if ( V_7 -> V_11 )
return 0 ;
if ( ! V_9 )
V_8 = V_12 ;
switch ( V_8 ) {
case V_13 :
case V_14 :
case V_12 :
V_10 = F_3 ( V_7 -> V_15 , V_16 ,
V_17 |
V_18 ,
V_8 ) ;
if ( V_10 < 0 ) {
F_4 ( V_7 -> V_2 ,
L_1 ) ;
return V_10 ;
}
break;
default:
F_4 ( V_7 -> V_2 , L_2 ,
V_8 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
unsigned int V_20 , V_21 ;
int V_10 , V_22 ;
V_10 = F_6 ( V_7 -> V_15 , V_23 , & V_20 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 , L_3 ) ;
return V_10 ;
}
V_22 = V_20 & V_24 ;
V_10 = F_6 ( V_7 -> V_15 , V_25 , & V_21 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 , L_4 ) ;
return V_10 ;
}
switch ( V_20 ) {
case V_26 :
if ( V_21 & V_27 )
V_22 = V_28 ;
else if ( V_21 & V_29 )
V_22 = V_30 ;
else
V_22 = V_26 ;
break;
default:
break;
}
return V_22 ;
}
static int F_7 ( struct V_6 * V_7 ,
enum V_31 V_32 )
{
static unsigned int V_33 ;
unsigned int V_8 = V_12 ;
int V_10 , V_22 ;
unsigned int V_34 ;
bool V_9 = false ;
switch ( V_32 ) {
case V_35 :
V_22 = F_5 ( V_7 ) ;
V_9 = true ;
break;
case V_36 :
V_22 = V_33 ;
V_9 = false ;
break;
case V_37 :
case V_38 :
F_8 ( V_7 -> V_2 ,
L_5 ,
V_32 == V_37 ? L_6 : L_7 ) ;
V_22 = V_33 ;
V_9 = false ;
break;
default:
F_4 ( V_7 -> V_2 ,
L_8 , V_32 ) ;
return - V_19 ;
}
V_33 = V_22 ;
switch ( V_22 ) {
case V_39 :
V_34 = V_40 ;
V_8 = V_14 ;
break;
case V_30 :
V_34 = V_41 ;
V_8 = V_13 ;
break;
case V_42 :
case V_43 :
V_34 = V_44 ;
V_8 = V_14 ;
break;
case V_45 :
case V_46 :
V_34 = V_44 ;
V_8 = V_12 ;
break;
case V_28 :
V_34 = V_47 ;
V_8 = V_14 ;
break;
case V_26 :
return 0 ;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_8 ( V_7 -> V_2 ,
L_9 , V_22 ) ;
return 0 ;
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
F_8 ( V_7 -> V_2 ,
L_10 , V_22 ) ;
return 0 ;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
return 0 ;
default:
F_4 ( V_7 -> V_2 ,
L_11 ,
V_22 ) ;
return - V_19 ;
}
V_10 = F_2 ( V_7 , V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
F_9 ( V_7 -> V_73 , V_34 , V_9 ) ;
if ( V_34 == V_47 )
F_9 ( V_7 -> V_73 , V_74 ,
V_9 ) ;
return 0 ;
}
static void F_10 ( struct V_75 * V_76 )
{
struct V_6 * V_7 = F_11 ( V_76 ,
struct V_6 , V_77 ) ;
int V_10 = 0 ;
if ( ! V_7 -> V_73 )
return;
F_12 ( & V_7 -> V_78 ) ;
if ( V_7 -> V_79 ) {
V_10 = F_7 ( V_7 , V_35 ) ;
V_7 -> V_79 = false ;
}
if ( V_7 -> V_80 ) {
V_10 = F_7 ( V_7 , V_36 ) ;
V_7 -> V_80 = false ;
}
if ( V_7 -> V_81 ) {
V_10 = F_7 ( V_7 , V_37 ) ;
V_7 -> V_81 = false ;
}
if ( V_7 -> V_82 ) {
V_10 = F_7 ( V_7 , V_38 ) ;
V_7 -> V_82 = false ;
}
if ( V_10 < 0 )
F_4 ( V_7 -> V_2 , L_12 ) ;
F_13 ( & V_7 -> V_78 ) ;
}
static T_1 F_14 ( int V_83 , void * V_84 )
{
struct V_6 * V_7 = V_84 ;
int V_85 , V_86 = - 1 ;
for ( V_85 = 0 ; V_85 < V_7 -> V_87 ; V_85 ++ )
if ( V_83 == V_7 -> V_88 [ V_85 ] . V_89 )
V_86 = V_7 -> V_88 [ V_85 ] . V_83 ;
switch ( V_86 ) {
case V_90 :
V_7 -> V_79 = true ;
break;
case V_91 :
V_7 -> V_80 = true ;
break;
case V_92 :
V_7 -> V_81 = true ;
break;
case V_93 :
V_7 -> V_82 = true ;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
default:
F_15 ( V_7 -> V_2 ,
L_13 , V_86 ) ;
break;
}
F_16 ( & V_7 -> V_77 ) ;
return V_105 ;
}
static void F_17 ( struct V_75 * V_76 )
{
struct V_6 * V_7 = F_11 ( F_18 ( V_76 ) ,
struct V_6 , V_106 ) ;
int V_10 ;
V_10 = F_7 ( V_7 , V_35 ) ;
if ( V_10 < 0 )
F_8 ( V_7 -> V_2 , L_14 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
unsigned int V_84 , V_107 , V_108 ;
int V_85 , V_10 ;
V_10 = F_6 ( V_7 -> V_15 , V_109 , & V_84 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 ,
L_15 , V_10 ) ;
return;
}
V_107 = ( ( V_84 & V_110 ) >>
V_111 ) ;
V_108 = ( ( V_84 & V_112 ) >>
V_113 ) ;
F_20 ( V_7 -> V_2 , L_16 ,
V_108 , V_107 ) ;
for ( V_85 = 0 ; V_85 < V_7 -> V_114 ; V_85 ++ ) {
T_2 V_3 = V_7 -> V_115 [ V_85 ] . V_3 ;
T_2 V_116 = V_7 -> V_115 [ V_85 ] . V_116 ;
T_2 V_117 = 0 ;
if ( V_7 -> V_115 [ V_85 ] . V_118 )
V_117 = ~ V_7 -> V_115 [ V_85 ] . V_117 ;
else
V_117 = V_7 -> V_115 [ V_85 ] . V_117 ;
F_3 ( V_7 -> V_15 , V_3 , V_116 , V_117 ) ;
}
V_10 = F_6 ( V_7 -> V_15 , V_119 , & V_84 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 ,
L_17 , V_10 ) ;
return;
}
V_84 &= V_120 ;
if ( V_84 ) {
V_7 -> V_11 = true ;
F_20 ( V_7 -> V_2 ,
L_18 ) ;
}
}
static int F_21 ( struct V_121 * V_122 ,
const struct V_123 * V_34 )
{
struct V_124 * V_125 = V_122 -> V_2 . V_126 ;
struct V_6 * V_7 ;
int V_85 , V_10 , V_127 ;
if ( ! V_125 )
return - V_19 ;
V_7 = F_22 ( & V_122 -> V_2 , sizeof( * V_7 ) , V_128 ) ;
if ( ! V_7 )
return - V_129 ;
F_23 ( V_122 , V_7 ) ;
V_7 -> V_2 = & V_122 -> V_2 ;
V_7 -> V_122 = V_122 ;
V_7 -> V_83 = V_122 -> V_83 ;
V_7 -> V_88 = V_130 ;
V_7 -> V_87 = F_24 ( V_130 ) ;
V_7 -> V_115 = V_131 ;
V_7 -> V_114 = F_24 ( V_131 ) ;
F_25 ( & V_7 -> V_78 ) ;
F_26 ( & V_7 -> V_77 , F_10 ) ;
V_7 -> V_15 = F_27 ( V_122 , & V_132 ) ;
if ( F_28 ( V_7 -> V_15 ) ) {
V_10 = F_29 ( V_7 -> V_15 ) ;
F_4 ( V_7 -> V_2 , L_19 ,
V_10 ) ;
return V_10 ;
}
V_127 = V_133 | V_134 | V_135 ;
V_10 = F_30 ( V_7 -> V_15 , V_7 -> V_83 , V_127 , 0 ,
& V_136 , & V_7 -> V_137 ) ;
if ( V_10 != 0 ) {
F_4 ( V_7 -> V_2 , L_20 ,
V_7 -> V_83 , V_10 ) ;
return V_10 ;
}
for ( V_85 = 0 ; V_85 < V_7 -> V_87 ; V_85 ++ ) {
struct V_138 * V_138 = & V_7 -> V_88 [ V_85 ] ;
int V_89 = 0 ;
V_89 = F_31 ( V_7 -> V_137 , V_138 -> V_83 ) ;
if ( V_89 <= 0 )
return - V_19 ;
V_138 -> V_89 = V_89 ;
V_10 = F_32 ( V_7 -> V_2 , V_89 , NULL ,
F_14 ,
V_139 | V_134 ,
V_138 -> V_140 , V_7 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 ,
L_21 ,
V_138 -> V_83 , V_10 ) ;
return V_10 ;
}
}
V_7 -> V_73 = F_33 ( V_7 -> V_2 , V_141 ) ;
if ( F_28 ( V_7 -> V_73 ) ) {
F_4 ( V_7 -> V_2 , L_22 ) ;
return - V_129 ;
}
V_10 = F_34 ( V_7 -> V_2 , V_7 -> V_73 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 , L_23 ) ;
return V_10 ;
}
F_35 ( & V_7 -> V_106 , F_17 ) ;
F_36 ( V_142 , & V_7 -> V_106 ,
F_37 ( V_143 ) ) ;
F_19 ( V_7 ) ;
return 0 ;
}
static int F_38 ( struct V_121 * V_122 )
{
struct V_6 * V_7 = F_39 ( V_122 ) ;
F_40 ( V_7 -> V_83 , V_7 -> V_137 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_121 * V_122 = F_42 ( V_2 ) ;
struct V_6 * V_7 = F_39 ( V_122 ) ;
F_43 ( V_7 -> V_83 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_121 * V_122 = F_42 ( V_2 ) ;
struct V_6 * V_7 = F_39 ( V_122 ) ;
F_45 ( V_7 -> V_83 ) ;
return 0 ;
}
static int T_3 F_46 ( void )
{
return F_47 ( & V_144 ) ;
}
