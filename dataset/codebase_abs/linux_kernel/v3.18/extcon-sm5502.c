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
L_7
L_8 , V_27 , V_28 ) ;
return - V_21 ;
} ;
break;
default:
F_4 ( V_7 -> V_2 ,
L_9 , V_27 ) ;
return - V_21 ;
} ;
return V_26 ;
}
static int F_8 ( struct V_6 * V_7 ,
bool V_10 )
{
static unsigned int V_70 = V_31 ;
const char * * V_71 = V_7 -> V_72 -> V_73 ;
unsigned int V_26 = V_31 ;
unsigned int V_8 = V_12 ;
unsigned int V_9 = V_13 ;
unsigned int V_74 = 0 ;
int V_11 ;
if ( ! V_71 )
return 0 ;
if ( V_10 )
V_26 = F_5 ( V_7 ) ;
else
V_26 = V_70 ;
V_70 = V_26 ;
switch ( V_26 ) {
case V_65 :
V_74 = V_75 ;
V_8 = V_14 ;
V_9 = V_24 ;
break;
case V_67 :
V_74 = V_76 ;
V_8 = V_12 ;
V_9 = V_22 ;
break;
case V_69 :
V_74 = V_77 ;
V_8 = V_14 ;
V_9 = V_13 ;
break;
default:
F_7 ( V_7 -> V_2 ,
L_10 , V_26 ) ;
return 0 ;
} ;
V_11 = F_2 ( V_7 , V_8 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
F_9 ( V_7 -> V_72 , V_71 [ V_74 ] , V_10 ) ;
return 0 ;
}
static void F_10 ( struct V_78 * V_79 )
{
struct V_6 * V_7 = F_11 ( V_79 ,
struct V_6 , V_80 ) ;
int V_11 = 0 ;
if ( ! V_7 -> V_72 )
return;
F_12 ( & V_7 -> V_81 ) ;
if ( V_7 -> V_82 ) {
V_11 = F_8 ( V_7 , true ) ;
V_7 -> V_82 = false ;
}
if ( V_7 -> V_83 ) {
V_11 = F_8 ( V_7 , false ) ;
V_7 -> V_83 = false ;
}
if ( V_11 < 0 )
F_4 ( V_7 -> V_2 , L_11 ) ;
F_13 ( & V_7 -> V_81 ) ;
}
static int F_14 ( struct V_6 * V_7 , int V_84 )
{
switch ( V_84 ) {
case V_85 :
V_7 -> V_82 = true ;
break;
case V_86 :
V_7 -> V_83 = true ;
break;
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
case V_98 :
default:
break;
}
return 0 ;
}
static T_1 F_15 ( int V_99 , void * V_100 )
{
struct V_6 * V_7 = V_100 ;
int V_101 , V_84 = - 1 , V_11 ;
for ( V_101 = 0 ; V_101 < V_7 -> V_102 ; V_101 ++ )
if ( V_99 == V_7 -> V_103 [ V_101 ] . V_104 )
V_84 = V_7 -> V_103 [ V_101 ] . V_99 ;
V_11 = F_14 ( V_7 , V_84 ) ;
if ( V_11 < 0 ) {
F_16 ( V_7 -> V_2 , L_12 ,
V_84 ) ;
return V_105 ;
}
F_17 ( & V_7 -> V_80 ) ;
return V_105 ;
}
static void F_18 ( struct V_78 * V_79 )
{
struct V_6 * V_7 = F_11 ( F_19 ( V_79 ) ,
struct V_6 , V_106 ) ;
int V_11 ;
V_11 = F_8 ( V_7 , true ) ;
if ( V_11 < 0 )
F_16 ( V_7 -> V_2 , L_13 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
unsigned int V_107 , V_108 , V_109 ;
int V_101 , V_11 ;
V_11 = F_6 ( V_7 -> V_17 , V_110 , & V_107 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 ,
L_14 , V_11 ) ;
return;
}
V_108 = ( ( V_107 & V_111 ) >>
V_112 ) ;
V_109 = ( ( V_107 & V_113 ) >>
V_114 ) ;
F_21 ( V_7 -> V_2 , L_15 ,
V_109 , V_108 ) ;
for ( V_101 = 0 ; V_101 < V_7 -> V_115 ; V_101 ++ ) {
unsigned int V_116 = 0 ;
if ( ! V_7 -> V_107 [ V_101 ] . V_117 )
V_116 |= ~ V_7 -> V_107 [ V_101 ] . V_116 ;
else
V_116 = V_7 -> V_107 [ V_101 ] . V_116 ;
F_22 ( V_7 -> V_17 , V_7 -> V_107 [ V_101 ] . V_3 , V_116 ) ;
}
}
static int F_23 ( struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
struct V_122 * V_123 = V_119 -> V_2 . V_124 ;
struct V_6 * V_7 ;
int V_101 , V_11 , V_125 ;
if ( ! V_123 )
return - V_21 ;
V_7 = F_24 ( & V_119 -> V_2 , sizeof( * V_7 ) , V_126 ) ;
if ( ! V_7 )
return - V_127 ;
F_25 ( V_119 , V_7 ) ;
V_7 -> V_2 = & V_119 -> V_2 ;
V_7 -> V_119 = V_119 ;
V_7 -> V_99 = V_119 -> V_99 ;
V_7 -> V_103 = V_128 ;
V_7 -> V_102 = F_26 ( V_128 ) ;
V_7 -> V_107 = V_129 ;
V_7 -> V_115 = F_26 ( V_129 ) ;
F_27 ( & V_7 -> V_81 ) ;
F_28 ( & V_7 -> V_80 , F_10 ) ;
V_7 -> V_17 = F_29 ( V_119 , & V_130 ) ;
if ( F_30 ( V_7 -> V_17 ) ) {
V_11 = F_31 ( V_7 -> V_17 ) ;
F_4 ( V_7 -> V_2 , L_16 ,
V_11 ) ;
return V_11 ;
}
V_125 = V_131 | V_132 | V_133 ;
V_11 = F_32 ( V_7 -> V_17 , V_7 -> V_99 , V_125 , 0 ,
& V_134 , & V_7 -> V_135 ) ;
if ( V_11 != 0 ) {
F_4 ( V_7 -> V_2 , L_17 ,
V_7 -> V_99 , V_11 ) ;
return V_11 ;
}
for ( V_101 = 0 ; V_101 < V_7 -> V_102 ; V_101 ++ ) {
struct V_136 * V_136 = & V_7 -> V_103 [ V_101 ] ;
unsigned int V_104 = 0 ;
V_104 = F_33 ( V_7 -> V_135 , V_136 -> V_99 ) ;
if ( V_104 <= 0 )
return - V_21 ;
V_136 -> V_104 = V_104 ;
V_11 = F_34 ( V_7 -> V_2 , V_104 , NULL ,
F_15 ,
V_137 ,
V_136 -> V_138 , V_7 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 ,
L_18 ,
V_136 -> V_99 , V_11 ) ;
return V_11 ;
}
}
V_7 -> V_72 = F_35 ( V_7 -> V_2 , V_139 ) ;
if ( F_30 ( V_7 -> V_72 ) ) {
F_4 ( V_7 -> V_2 , L_19 ) ;
return - V_127 ;
}
V_7 -> V_72 -> V_138 = V_123 -> V_138 ;
V_11 = F_36 ( V_7 -> V_2 , V_7 -> V_72 ) ;
if ( V_11 ) {
F_4 ( V_7 -> V_2 , L_20 ) ;
return V_11 ;
}
F_37 ( & V_7 -> V_106 , F_18 ) ;
F_38 ( V_140 , & V_7 -> V_106 ,
F_39 ( V_141 ) ) ;
F_20 ( V_7 ) ;
return 0 ;
}
static int F_40 ( struct V_118 * V_119 )
{
struct V_6 * V_7 = F_41 ( V_119 ) ;
F_42 ( V_7 -> V_99 , V_7 -> V_135 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_118 * V_119 = F_11 ( V_2 , struct V_118 , V_2 ) ;
struct V_6 * V_7 = F_41 ( V_119 ) ;
F_44 ( V_7 -> V_99 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_118 * V_119 = F_11 ( V_2 , struct V_118 , V_2 ) ;
struct V_6 * V_7 = F_41 ( V_119 ) ;
F_46 ( V_7 -> V_99 ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
return F_48 ( & V_142 ) ;
}
