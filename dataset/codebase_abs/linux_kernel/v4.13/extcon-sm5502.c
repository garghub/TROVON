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
if ( V_71 == V_72 )
F_9 ( V_7 -> V_75 , V_76 ,
V_10 ) ;
return 0 ;
}
static void F_10 ( struct V_77 * V_78 )
{
struct V_6 * V_7 = F_11 ( V_78 ,
struct V_6 , V_79 ) ;
int V_11 = 0 ;
if ( ! V_7 -> V_75 )
return;
F_12 ( & V_7 -> V_80 ) ;
if ( V_7 -> V_81 ) {
V_11 = F_8 ( V_7 , true ) ;
V_7 -> V_81 = false ;
}
if ( V_7 -> V_82 ) {
V_11 = F_8 ( V_7 , false ) ;
V_7 -> V_82 = false ;
}
if ( V_11 < 0 )
F_4 ( V_7 -> V_2 , L_10 ) ;
F_13 ( & V_7 -> V_80 ) ;
}
static int F_14 ( struct V_6 * V_7 , int V_83 )
{
switch ( V_83 ) {
case V_84 :
V_7 -> V_81 = true ;
break;
case V_85 :
V_7 -> V_82 = true ;
break;
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
case V_97 :
default:
break;
}
return 0 ;
}
static T_1 F_15 ( int V_98 , void * V_99 )
{
struct V_6 * V_7 = V_99 ;
int V_100 , V_83 = - 1 , V_11 ;
for ( V_100 = 0 ; V_100 < V_7 -> V_101 ; V_100 ++ )
if ( V_98 == V_7 -> V_102 [ V_100 ] . V_103 )
V_83 = V_7 -> V_102 [ V_100 ] . V_98 ;
V_11 = F_14 ( V_7 , V_83 ) ;
if ( V_11 < 0 ) {
F_16 ( V_7 -> V_2 , L_11 ,
V_83 ) ;
return V_104 ;
}
F_17 ( & V_7 -> V_79 ) ;
return V_104 ;
}
static void F_18 ( struct V_77 * V_78 )
{
struct V_6 * V_7 = F_11 ( F_19 ( V_78 ) ,
struct V_6 , V_105 ) ;
int V_11 ;
V_11 = F_8 ( V_7 , true ) ;
if ( V_11 < 0 )
F_16 ( V_7 -> V_2 , L_12 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
unsigned int V_106 , V_107 , V_108 ;
int V_100 , V_11 ;
V_11 = F_6 ( V_7 -> V_17 , V_109 , & V_106 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 ,
L_13 , V_11 ) ;
return;
}
V_107 = ( ( V_106 & V_110 ) >>
V_111 ) ;
V_108 = ( ( V_106 & V_112 ) >>
V_113 ) ;
F_21 ( V_7 -> V_2 , L_14 ,
V_108 , V_107 ) ;
for ( V_100 = 0 ; V_100 < V_7 -> V_114 ; V_100 ++ ) {
unsigned int V_115 = 0 ;
if ( ! V_7 -> V_106 [ V_100 ] . V_116 )
V_115 |= ~ V_7 -> V_106 [ V_100 ] . V_115 ;
else
V_115 = V_7 -> V_106 [ V_100 ] . V_115 ;
F_22 ( V_7 -> V_17 , V_7 -> V_106 [ V_100 ] . V_3 , V_115 ) ;
}
}
static int F_23 ( struct V_117 * V_118 ,
const struct V_119 * V_71 )
{
struct V_120 * V_121 = V_118 -> V_2 . V_122 ;
struct V_6 * V_7 ;
int V_100 , V_11 , V_123 ;
if ( ! V_121 )
return - V_21 ;
V_7 = F_24 ( & V_118 -> V_2 , sizeof( * V_7 ) , V_124 ) ;
if ( ! V_7 )
return - V_125 ;
F_25 ( V_118 , V_7 ) ;
V_7 -> V_2 = & V_118 -> V_2 ;
V_7 -> V_118 = V_118 ;
V_7 -> V_98 = V_118 -> V_98 ;
V_7 -> V_102 = V_126 ;
V_7 -> V_101 = F_26 ( V_126 ) ;
V_7 -> V_106 = V_127 ;
V_7 -> V_114 = F_26 ( V_127 ) ;
F_27 ( & V_7 -> V_80 ) ;
F_28 ( & V_7 -> V_79 , F_10 ) ;
V_7 -> V_17 = F_29 ( V_118 , & V_128 ) ;
if ( F_30 ( V_7 -> V_17 ) ) {
V_11 = F_31 ( V_7 -> V_17 ) ;
F_4 ( V_7 -> V_2 , L_15 ,
V_11 ) ;
return V_11 ;
}
V_123 = V_129 | V_130 | V_131 ;
V_11 = F_32 ( V_7 -> V_17 , V_7 -> V_98 , V_123 , 0 ,
& V_132 , & V_7 -> V_133 ) ;
if ( V_11 != 0 ) {
F_4 ( V_7 -> V_2 , L_16 ,
V_7 -> V_98 , V_11 ) ;
return V_11 ;
}
for ( V_100 = 0 ; V_100 < V_7 -> V_101 ; V_100 ++ ) {
struct V_134 * V_134 = & V_7 -> V_102 [ V_100 ] ;
int V_103 = 0 ;
V_103 = F_33 ( V_7 -> V_133 , V_134 -> V_98 ) ;
if ( V_103 <= 0 )
return - V_21 ;
V_134 -> V_103 = V_103 ;
V_11 = F_34 ( V_7 -> V_2 , V_103 , NULL ,
F_15 ,
V_135 ,
V_134 -> V_136 , V_7 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 ,
L_17 ,
V_134 -> V_98 , V_11 ) ;
return V_11 ;
}
}
V_7 -> V_75 = F_35 ( V_7 -> V_2 , V_137 ) ;
if ( F_30 ( V_7 -> V_75 ) ) {
F_4 ( V_7 -> V_2 , L_18 ) ;
return - V_125 ;
}
V_11 = F_36 ( V_7 -> V_2 , V_7 -> V_75 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 , L_19 ) ;
return V_11 ;
}
F_37 ( & V_7 -> V_105 , F_18 ) ;
F_38 ( V_138 , & V_7 -> V_105 ,
F_39 ( V_139 ) ) ;
F_20 ( V_7 ) ;
return 0 ;
}
static int F_40 ( struct V_117 * V_118 )
{
struct V_6 * V_7 = F_41 ( V_118 ) ;
F_42 ( V_7 -> V_98 , V_7 -> V_133 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = F_44 ( V_2 ) ;
struct V_6 * V_7 = F_41 ( V_118 ) ;
F_45 ( V_7 -> V_98 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = F_44 ( V_2 ) ;
struct V_6 * V_7 = F_41 ( V_118 ) ;
F_47 ( V_7 -> V_98 ) ;
return 0 ;
}
static int T_2 F_48 ( void )
{
return F_49 ( & V_140 ) ;
}
