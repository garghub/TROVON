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
const char * * V_34 = V_7 -> V_35 -> V_36 ;
unsigned int V_8 = V_12 ;
int V_10 , V_37 = 0 , V_22 ;
bool V_9 = false ;
if ( ! V_34 )
return 0 ;
switch ( V_32 ) {
case V_38 :
V_22 = F_5 ( V_7 ) ;
V_9 = true ;
break;
case V_39 :
V_22 = V_33 ;
V_9 = false ;
break;
case V_40 :
case V_41 :
F_8 ( V_7 -> V_2 ,
L_5 ,
V_32 == V_40 ? L_6 : L_7 ) ;
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
case V_42 :
V_37 = V_43 ;
V_8 = V_14 ;
break;
case V_30 :
V_37 = V_44 ;
V_8 = V_13 ;
break;
case V_45 :
V_37 = V_46 ;
V_8 = V_12 ;
break;
case V_47 :
V_37 = V_48 ;
V_8 = V_12 ;
break;
case V_49 :
V_37 = V_50 ;
V_8 = V_12 ;
break;
case V_51 :
V_37 = V_52 ;
V_8 = V_12 ;
break;
case V_28 :
V_37 = V_53 ;
V_8 = V_14 ;
break;
case V_26 :
return 0 ;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
F_8 ( V_7 -> V_2 ,
L_9 , V_22 ) ;
return 0 ;
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
F_8 ( V_7 -> V_2 ,
L_10 , V_22 ) ;
return 0 ;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
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
F_9 ( V_7 -> V_35 , V_34 [ V_37 ] , V_9 ) ;
return 0 ;
}
static void F_10 ( struct V_79 * V_80 )
{
struct V_6 * V_7 = F_11 ( V_80 ,
struct V_6 , V_81 ) ;
int V_10 = 0 ;
if ( ! V_7 -> V_35 )
return;
F_12 ( & V_7 -> V_82 ) ;
if ( V_7 -> V_83 ) {
V_10 = F_7 ( V_7 , V_38 ) ;
V_7 -> V_83 = false ;
}
if ( V_7 -> V_84 ) {
V_10 = F_7 ( V_7 , V_39 ) ;
V_7 -> V_84 = false ;
}
if ( V_7 -> V_85 ) {
V_10 = F_7 ( V_7 , V_40 ) ;
V_7 -> V_85 = false ;
}
if ( V_7 -> V_86 ) {
V_10 = F_7 ( V_7 , V_41 ) ;
V_7 -> V_86 = false ;
}
if ( V_10 < 0 )
F_4 ( V_7 -> V_2 , L_12 ) ;
F_13 ( & V_7 -> V_82 ) ;
}
static T_1 F_14 ( int V_87 , void * V_88 )
{
struct V_6 * V_7 = V_88 ;
int V_89 , V_90 = - 1 ;
for ( V_89 = 0 ; V_89 < V_7 -> V_91 ; V_89 ++ )
if ( V_87 == V_7 -> V_92 [ V_89 ] . V_93 )
V_90 = V_7 -> V_92 [ V_89 ] . V_87 ;
switch ( V_90 ) {
case V_94 :
V_7 -> V_83 = true ;
break;
case V_95 :
V_7 -> V_84 = true ;
break;
case V_96 :
V_7 -> V_85 = true ;
break;
case V_97 :
V_7 -> V_86 = true ;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
default:
F_15 ( V_7 -> V_2 ,
L_13 , V_90 ) ;
break;
}
F_16 ( & V_7 -> V_81 ) ;
return V_109 ;
}
static void F_17 ( struct V_79 * V_80 )
{
struct V_6 * V_7 = F_11 ( F_18 ( V_80 ) ,
struct V_6 , V_110 ) ;
int V_10 ;
V_10 = F_7 ( V_7 , V_38 ) ;
if ( V_10 < 0 )
F_8 ( V_7 -> V_2 , L_14 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
unsigned int V_88 , V_111 , V_112 ;
int V_89 , V_10 ;
V_10 = F_6 ( V_7 -> V_15 , V_113 , & V_88 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 ,
L_15 , V_10 ) ;
return;
}
V_111 = ( ( V_88 & V_114 ) >>
V_115 ) ;
V_112 = ( ( V_88 & V_116 ) >>
V_117 ) ;
F_20 ( V_7 -> V_2 , L_16 ,
V_112 , V_111 ) ;
for ( V_89 = 0 ; V_89 < V_7 -> V_118 ; V_89 ++ ) {
T_2 V_3 = V_7 -> V_119 [ V_89 ] . V_3 ;
T_2 V_120 = V_7 -> V_119 [ V_89 ] . V_120 ;
T_2 V_121 = 0 ;
if ( V_7 -> V_119 [ V_89 ] . V_122 )
V_121 = ~ V_7 -> V_119 [ V_89 ] . V_121 ;
else
V_121 = V_7 -> V_119 [ V_89 ] . V_121 ;
F_3 ( V_7 -> V_15 , V_3 , V_120 , V_121 ) ;
}
V_10 = F_6 ( V_7 -> V_15 , V_123 , & V_88 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 ,
L_17 , V_10 ) ;
return;
}
V_88 &= V_124 ;
if ( V_88 ) {
V_7 -> V_11 = true ;
F_20 ( V_7 -> V_2 ,
L_18 ) ;
}
}
static int F_21 ( struct V_125 * V_126 ,
const struct V_127 * V_128 )
{
struct V_129 * V_130 = V_126 -> V_2 . V_131 ;
struct V_6 * V_7 ;
int V_89 , V_10 , V_132 ;
if ( ! V_130 )
return - V_19 ;
V_7 = F_22 ( & V_126 -> V_2 , sizeof( * V_7 ) , V_133 ) ;
if ( ! V_7 )
return - V_134 ;
F_23 ( V_126 , V_7 ) ;
V_7 -> V_2 = & V_126 -> V_2 ;
V_7 -> V_126 = V_126 ;
V_7 -> V_87 = V_126 -> V_87 ;
V_7 -> V_92 = V_135 ;
V_7 -> V_91 = F_24 ( V_135 ) ;
V_7 -> V_119 = V_136 ;
V_7 -> V_118 = F_24 ( V_136 ) ;
F_25 ( & V_7 -> V_82 ) ;
F_26 ( & V_7 -> V_81 , F_10 ) ;
V_7 -> V_15 = F_27 ( V_126 , & V_137 ) ;
if ( F_28 ( V_7 -> V_15 ) ) {
V_10 = F_29 ( V_7 -> V_15 ) ;
F_4 ( V_7 -> V_2 , L_19 ,
V_10 ) ;
return V_10 ;
}
V_132 = V_138 | V_139 | V_140 ;
V_10 = F_30 ( V_7 -> V_15 , V_7 -> V_87 , V_132 , 0 ,
& V_141 , & V_7 -> V_142 ) ;
if ( V_10 != 0 ) {
F_4 ( V_7 -> V_2 , L_20 ,
V_7 -> V_87 , V_10 ) ;
return V_10 ;
}
for ( V_89 = 0 ; V_89 < V_7 -> V_91 ; V_89 ++ ) {
struct V_143 * V_143 = & V_7 -> V_92 [ V_89 ] ;
unsigned int V_93 = 0 ;
V_93 = F_31 ( V_7 -> V_142 , V_143 -> V_87 ) ;
if ( V_93 <= 0 )
return - V_19 ;
V_143 -> V_93 = V_93 ;
V_10 = F_32 ( V_7 -> V_2 , V_93 , NULL ,
F_14 ,
V_144 ,
V_143 -> V_145 , V_7 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 ,
L_21 ,
V_143 -> V_87 , V_10 ) ;
return V_10 ;
}
}
V_7 -> V_35 = F_33 ( V_7 -> V_2 , V_146 ) ;
if ( F_28 ( V_7 -> V_35 ) ) {
F_4 ( V_7 -> V_2 , L_22 ) ;
return - V_134 ;
}
V_7 -> V_35 -> V_145 = V_130 -> V_145 ;
V_10 = F_34 ( V_7 -> V_2 , V_7 -> V_35 ) ;
if ( V_10 ) {
F_4 ( V_7 -> V_2 , L_23 ) ;
return V_10 ;
}
F_35 ( & V_7 -> V_110 , F_17 ) ;
F_36 ( V_147 , & V_7 -> V_110 ,
F_37 ( V_148 ) ) ;
F_19 ( V_7 ) ;
return 0 ;
}
static int F_38 ( struct V_125 * V_126 )
{
struct V_6 * V_7 = F_39 ( V_126 ) ;
F_40 ( V_7 -> V_87 , V_7 -> V_142 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_125 * V_126 = F_11 ( V_2 , struct V_125 , V_2 ) ;
struct V_6 * V_7 = F_39 ( V_126 ) ;
F_42 ( V_7 -> V_87 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_125 * V_126 = F_11 ( V_2 , struct V_125 , V_2 ) ;
struct V_6 * V_7 = F_39 ( V_126 ) ;
F_44 ( V_7 -> V_87 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_149 ) ;
}
