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
unsigned int V_8 , unsigned int V_9 ,
bool V_10 )
{
int V_11 ;
if ( ! V_10 ) {
V_8 = V_12 ;
V_9 = V_13 ;
}
switch ( V_8 ) {
case V_12 :
case V_14 :
case V_15 :
case V_16 :
V_11 = F_3 ( V_7 -> V_17 , V_18 ,
V_19 |
V_20 ,
V_8 ) ;
if ( V_11 < 0 ) {
F_4 ( V_7 -> V_2 ,
L_1 ) ;
return V_11 ;
}
break;
default:
F_4 ( V_7 -> V_2 , L_2 ,
V_8 ) ;
return - V_21 ;
} ;
switch ( V_9 ) {
case V_13 :
case V_22 :
case V_23 :
case V_24 :
V_11 = F_3 ( V_7 -> V_17 , V_18 ,
V_25 ,
V_9 ) ;
if ( V_11 < 0 ) {
F_4 ( V_7 -> V_2 ,
L_3 ) ;
return V_11 ;
}
break;
default:
F_4 ( V_7 -> V_2 , L_4 , V_9 ) ;
return - V_21 ;
} ;
return 0 ;
}
static unsigned int F_5 ( struct V_6 * V_7 )
{
unsigned int V_26 = - 1 , V_27 , V_28 ;
int V_11 ;
V_11 = F_6 ( V_7 -> V_17 , V_29 , & V_27 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 , L_5 ) ;
return V_11 ;
}
V_26 = V_27 & V_30 ;
if ( V_26 == V_31 )
return V_31 ;
switch ( V_26 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
break;
case V_61 :
break;
case V_62 :
V_11 = F_6 ( V_7 -> V_17 , V_63 ,
& V_28 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 , L_6 ) ;
return V_11 ;
}
switch ( V_28 ) {
case V_64 :
V_26 = V_65 ;
break;
case V_66 :
V_26 = V_67 ;
break;
case V_68 :
V_26 = V_69 ;
break;
default:
F_7 ( V_7 -> V_2 ,
L_7 ,
V_27 ) ;
return - V_21 ;
} ;
break;
default:
F_4 ( V_7 -> V_2 ,
L_8 , V_27 ) ;
return - V_21 ;
} ;
return V_26 ;
}
static int F_8 ( struct V_6 * V_7 ,
bool V_10 )
{
static unsigned int V_70 = V_31 ;
unsigned int V_26 = V_31 ;
unsigned int V_8 = V_12 ;
unsigned int V_9 = V_13 ;
unsigned int V_71 ;
int V_11 ;
if ( V_10 )
V_26 = F_5 ( V_7 ) ;
else
V_26 = V_70 ;
V_70 = V_26 ;
switch ( V_26 ) {
case V_65 :
V_71 = V_72 ;
V_8 = V_14 ;
V_9 = V_24 ;
break;
case V_67 :
V_71 = V_73 ;
V_8 = V_12 ;
V_9 = V_22 ;
break;
case V_69 :
V_71 = V_74 ;
V_8 = V_14 ;
V_9 = V_13 ;
break;
default:
F_7 ( V_7 -> V_2 ,
L_9 , V_26 ) ;
return 0 ;
} ;
V_11 = F_2 ( V_7 , V_8 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
F_9 ( V_7 -> V_75 , V_71 , V_10 ) ;
return 0 ;
}
static void F_10 ( struct V_76 * V_77 )
{
struct V_6 * V_7 = F_11 ( V_77 ,
struct V_6 , V_78 ) ;
int V_11 = 0 ;
if ( ! V_7 -> V_75 )
return;
F_12 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_80 ) {
V_11 = F_8 ( V_7 , true ) ;
V_7 -> V_80 = false ;
}
if ( V_7 -> V_81 ) {
V_11 = F_8 ( V_7 , false ) ;
V_7 -> V_81 = false ;
}
if ( V_11 < 0 )
F_4 ( V_7 -> V_2 , L_10 ) ;
F_13 ( & V_7 -> V_79 ) ;
}
static int F_14 ( struct V_6 * V_7 , int V_82 )
{
switch ( V_82 ) {
case V_83 :
V_7 -> V_80 = true ;
break;
case V_84 :
V_7 -> V_81 = true ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
default:
break;
}
return 0 ;
}
static T_1 F_15 ( int V_97 , void * V_98 )
{
struct V_6 * V_7 = V_98 ;
int V_99 , V_82 = - 1 , V_11 ;
for ( V_99 = 0 ; V_99 < V_7 -> V_100 ; V_99 ++ )
if ( V_97 == V_7 -> V_101 [ V_99 ] . V_102 )
V_82 = V_7 -> V_101 [ V_99 ] . V_97 ;
V_11 = F_14 ( V_7 , V_82 ) ;
if ( V_11 < 0 ) {
F_16 ( V_7 -> V_2 , L_11 ,
V_82 ) ;
return V_103 ;
}
F_17 ( & V_7 -> V_78 ) ;
return V_103 ;
}
static void F_18 ( struct V_76 * V_77 )
{
struct V_6 * V_7 = F_11 ( F_19 ( V_77 ) ,
struct V_6 , V_104 ) ;
int V_11 ;
V_11 = F_8 ( V_7 , true ) ;
if ( V_11 < 0 )
F_16 ( V_7 -> V_2 , L_12 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
unsigned int V_105 , V_106 , V_107 ;
int V_99 , V_11 ;
V_11 = F_6 ( V_7 -> V_17 , V_108 , & V_105 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 ,
L_13 , V_11 ) ;
return;
}
V_106 = ( ( V_105 & V_109 ) >>
V_110 ) ;
V_107 = ( ( V_105 & V_111 ) >>
V_112 ) ;
F_21 ( V_7 -> V_2 , L_14 ,
V_107 , V_106 ) ;
for ( V_99 = 0 ; V_99 < V_7 -> V_113 ; V_99 ++ ) {
unsigned int V_114 = 0 ;
if ( ! V_7 -> V_105 [ V_99 ] . V_115 )
V_114 |= ~ V_7 -> V_105 [ V_99 ] . V_114 ;
else
V_114 = V_7 -> V_105 [ V_99 ] . V_114 ;
F_22 ( V_7 -> V_17 , V_7 -> V_105 [ V_99 ] . V_3 , V_114 ) ;
}
}
static int F_23 ( struct V_116 * V_117 ,
const struct V_118 * V_71 )
{
struct V_119 * V_120 = V_117 -> V_2 . V_121 ;
struct V_6 * V_7 ;
int V_99 , V_11 , V_122 ;
if ( ! V_120 )
return - V_21 ;
V_7 = F_24 ( & V_117 -> V_2 , sizeof( * V_7 ) , V_123 ) ;
if ( ! V_7 )
return - V_124 ;
F_25 ( V_117 , V_7 ) ;
V_7 -> V_2 = & V_117 -> V_2 ;
V_7 -> V_117 = V_117 ;
V_7 -> V_97 = V_117 -> V_97 ;
V_7 -> V_101 = V_125 ;
V_7 -> V_100 = F_26 ( V_125 ) ;
V_7 -> V_105 = V_126 ;
V_7 -> V_113 = F_26 ( V_126 ) ;
F_27 ( & V_7 -> V_79 ) ;
F_28 ( & V_7 -> V_78 , F_10 ) ;
V_7 -> V_17 = F_29 ( V_117 , & V_127 ) ;
if ( F_30 ( V_7 -> V_17 ) ) {
V_11 = F_31 ( V_7 -> V_17 ) ;
F_4 ( V_7 -> V_2 , L_15 ,
V_11 ) ;
return V_11 ;
}
V_122 = V_128 | V_129 | V_130 ;
V_11 = F_32 ( V_7 -> V_17 , V_7 -> V_97 , V_122 , 0 ,
& V_131 , & V_7 -> V_132 ) ;
if ( V_11 != 0 ) {
F_4 ( V_7 -> V_2 , L_16 ,
V_7 -> V_97 , V_11 ) ;
return V_11 ;
}
for ( V_99 = 0 ; V_99 < V_7 -> V_100 ; V_99 ++ ) {
struct V_133 * V_133 = & V_7 -> V_101 [ V_99 ] ;
int V_102 = 0 ;
V_102 = F_33 ( V_7 -> V_132 , V_133 -> V_97 ) ;
if ( V_102 <= 0 )
return - V_21 ;
V_133 -> V_102 = V_102 ;
V_11 = F_34 ( V_7 -> V_2 , V_102 , NULL ,
F_15 ,
V_134 ,
V_133 -> V_135 , V_7 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 ,
L_17 ,
V_133 -> V_97 , V_11 ) ;
return V_11 ;
}
}
V_7 -> V_75 = F_35 ( V_7 -> V_2 , V_136 ) ;
if ( F_30 ( V_7 -> V_75 ) ) {
F_4 ( V_7 -> V_2 , L_18 ) ;
return - V_124 ;
}
V_11 = F_36 ( V_7 -> V_2 , V_7 -> V_75 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 , L_19 ) ;
return V_11 ;
}
F_37 ( & V_7 -> V_104 , F_18 ) ;
F_38 ( V_137 , & V_7 -> V_104 ,
F_39 ( V_138 ) ) ;
F_20 ( V_7 ) ;
return 0 ;
}
static int F_40 ( struct V_116 * V_117 )
{
struct V_6 * V_7 = F_41 ( V_117 ) ;
F_42 ( V_7 -> V_97 , V_7 -> V_132 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_116 * V_117 = F_11 ( V_2 , struct V_116 , V_2 ) ;
struct V_6 * V_7 = F_41 ( V_117 ) ;
F_44 ( V_7 -> V_97 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_116 * V_117 = F_11 ( V_2 , struct V_116 , V_2 ) ;
struct V_6 * V_7 = F_41 ( V_117 ) ;
F_46 ( V_7 -> V_97 ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
return F_48 ( & V_139 ) ;
}
