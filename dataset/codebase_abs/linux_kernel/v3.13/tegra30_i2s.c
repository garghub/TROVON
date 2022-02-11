static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , true ) ;
F_4 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_6 ( V_4 -> V_6 ) ;
if ( V_7 ) {
F_7 ( V_2 , L_1 , V_7 ) ;
return V_7 ;
}
F_3 ( V_4 -> V_5 , false ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
int V_7 ;
if ( V_9 -> V_12 == V_13 ) {
V_7 = F_10 ( & V_4 -> V_14 ,
& V_4 -> V_15 . V_16 ,
& V_4 -> V_15 . V_17 ) ;
V_4 -> V_15 . V_18 = V_19 ;
V_4 -> V_15 . V_20 = 4 ;
F_11 ( V_4 -> V_21 ,
V_4 -> V_14 ) ;
} else {
V_7 = F_12 ( & V_4 -> V_22 ,
& V_4 -> V_23 . V_16 ,
& V_4 -> V_23 . V_17 ) ;
V_4 -> V_23 . V_18 = V_19 ;
V_4 -> V_23 . V_20 = 4 ;
F_11 ( V_4 -> V_22 ,
V_4 -> V_24 ) ;
}
return V_7 ;
}
static void F_13 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( V_9 -> V_12 == V_13 ) {
F_14 ( V_4 -> V_21 ) ;
F_15 ( V_4 -> V_14 ) ;
} else {
F_14 ( V_4 -> V_22 ) ;
F_16 ( V_4 -> V_22 ) ;
}
}
static int F_17 ( struct V_10 * V_11 ,
unsigned int V_25 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
unsigned int V_26 = 0 , V_27 = 0 ;
switch ( V_25 & V_28 ) {
case V_29 :
break;
default:
return - V_30 ;
}
V_26 |= V_31 ;
switch ( V_25 & V_32 ) {
case V_33 :
V_27 |= V_31 ;
break;
case V_34 :
break;
default:
return - V_30 ;
}
V_26 |= V_35 |
V_36 ;
switch ( V_25 & V_37 ) {
case V_38 :
V_27 |= V_39 ;
V_27 |= V_40 ;
break;
case V_41 :
V_27 |= V_39 ;
V_27 |= V_42 ;
break;
case V_43 :
V_27 |= V_44 ;
V_27 |= V_40 ;
break;
case V_45 :
V_27 |= V_44 ;
V_27 |= V_40 ;
break;
case V_46 :
V_27 |= V_44 ;
V_27 |= V_40 ;
break;
default:
return - V_30 ;
}
F_18 ( V_11 -> V_2 ) ;
F_19 ( V_4 -> V_5 , V_47 , V_26 , V_27 ) ;
F_20 ( V_11 -> V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_48 * V_49 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = F_9 ( V_11 ) ;
unsigned int V_26 , V_27 , V_50 ;
int V_7 , V_51 , V_52 , V_53 , V_54 ;
struct V_55 V_56 ;
if ( F_22 ( V_49 ) != 2 )
return - V_30 ;
V_26 = V_57 ;
switch ( F_23 ( V_49 ) ) {
case V_58 :
V_27 = V_59 ;
V_51 = 16 ;
break;
default:
return - V_30 ;
}
F_19 ( V_4 -> V_5 , V_47 , V_26 , V_27 ) ;
V_52 = F_24 ( V_49 ) ;
V_53 = V_52 * F_22 ( V_49 ) * V_51 * 2 ;
V_54 = ( V_53 / ( 2 * V_52 ) ) - 1 ;
if ( V_54 < 0 || V_54 > V_60 )
return - V_30 ;
V_7 = F_25 ( V_4 -> V_6 , V_53 ) ;
if ( V_7 ) {
F_7 ( V_2 , L_2 , V_7 ) ;
return V_7 ;
}
V_27 = V_54 << V_61 ;
if ( V_53 % ( 2 * V_52 ) )
V_27 |= V_62 ;
F_26 ( V_4 -> V_5 , V_63 , V_27 ) ;
V_56 . V_64 = 0 ;
V_56 . V_65 = 2 ;
V_56 . V_66 = 2 ;
V_56 . V_67 = V_68 ;
V_56 . V_69 = V_68 ;
V_56 . V_70 = 0 ;
V_56 . V_71 = 0 ;
V_56 . V_72 = 0 ;
V_56 . V_73 = 0 ;
V_56 . V_74 = 0 ;
if ( V_9 -> V_12 == V_13 ) {
V_56 . V_75 = V_76 ;
V_50 = V_77 ;
} else {
V_56 . V_75 = V_78 ;
V_50 = V_79 ;
}
V_4 -> V_80 -> V_81 ( V_4 -> V_5 , V_50 , & V_56 ) ;
V_27 = ( 1 << V_82 ) |
( 1 << V_83 ) ;
F_26 ( V_4 -> V_5 , V_84 , V_27 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_28 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_85 ,
V_85 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_30 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_85 , 0 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_22 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_86 ,
V_86 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
F_34 ( V_4 -> V_22 ) ;
F_19 ( V_4 -> V_5 , V_47 ,
V_86 , 0 ) ;
}
static int F_35 ( struct V_8 * V_9 , int V_87 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
switch ( V_87 ) {
case V_88 :
case V_89 :
case V_90 :
if ( V_9 -> V_12 == V_13 )
F_27 ( V_4 ) ;
else
F_31 ( V_4 ) ;
break;
case V_91 :
case V_92 :
case V_93 :
if ( V_9 -> V_12 == V_13 )
F_29 ( V_4 ) ;
else
F_33 ( V_4 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
V_11 -> V_23 = & V_4 -> V_23 ;
V_11 -> V_15 = & V_4 -> V_15 ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_2 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_47 :
case V_63 :
case V_84 :
case V_94 :
case V_95 :
case V_77 :
case V_79 :
case V_96 :
case V_97 :
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
case V_109 :
case V_110 :
return true ;
default:
return false ;
}
}
static bool F_38 ( struct V_1 * V_2 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_98 :
case V_99 :
case V_100 :
case V_101 :
return true ;
default:
return false ;
}
}
static int F_39 ( struct V_111 * V_112 )
{
struct V_3 * V_4 ;
const struct V_113 * V_114 ;
T_1 V_115 [ 2 ] ;
struct V_116 * V_117 , * V_118 ;
void T_2 * V_119 ;
int V_7 ;
V_4 = F_40 ( & V_112 -> V_2 , sizeof( struct V_3 ) , V_120 ) ;
if ( ! V_4 ) {
F_7 ( & V_112 -> V_2 , L_3 ) ;
V_7 = - V_121 ;
goto V_122;
}
F_41 ( & V_112 -> V_2 , V_4 ) ;
V_114 = F_42 ( V_123 , & V_112 -> V_2 ) ;
if ( ! V_114 ) {
F_7 ( & V_112 -> V_2 , L_4 ) ;
V_7 = - V_124 ;
goto V_122;
}
V_4 -> V_80 = (struct V_125 * ) V_114 -> V_126 ;
V_4 -> V_11 = V_127 ;
V_4 -> V_11 . V_128 = F_43 ( & V_112 -> V_2 ) ;
V_7 = F_44 ( V_112 -> V_2 . V_129 ,
L_5 , V_115 ,
F_45 ( V_115 ) ) ;
if ( V_7 < 0 )
goto V_122;
V_4 -> V_21 = V_115 [ 0 ] ;
V_4 -> V_24 = V_115 [ 1 ] ;
V_4 -> V_6 = F_46 ( & V_112 -> V_2 , NULL ) ;
if ( F_47 ( V_4 -> V_6 ) ) {
F_7 ( & V_112 -> V_2 , L_6 ) ;
V_7 = F_48 ( V_4 -> V_6 ) ;
goto V_122;
}
V_117 = F_49 ( V_112 , V_130 , 0 ) ;
if ( ! V_117 ) {
F_7 ( & V_112 -> V_2 , L_7 ) ;
V_7 = - V_124 ;
goto V_131;
}
V_118 = F_50 ( & V_112 -> V_2 , V_117 -> V_132 ,
F_51 ( V_117 ) , V_133 ) ;
if ( ! V_118 ) {
F_7 ( & V_112 -> V_2 , L_8 ) ;
V_7 = - V_134 ;
goto V_131;
}
V_119 = F_52 ( & V_112 -> V_2 , V_117 -> V_132 , F_51 ( V_117 ) ) ;
if ( ! V_119 ) {
F_7 ( & V_112 -> V_2 , L_9 ) ;
V_7 = - V_121 ;
goto V_131;
}
V_4 -> V_5 = F_53 ( & V_112 -> V_2 , V_119 ,
& V_135 ) ;
if ( F_47 ( V_4 -> V_5 ) ) {
F_7 ( & V_112 -> V_2 , L_10 ) ;
V_7 = F_48 ( V_4 -> V_5 ) ;
goto V_131;
}
F_3 ( V_4 -> V_5 , true ) ;
F_54 ( & V_112 -> V_2 ) ;
if ( ! F_55 ( & V_112 -> V_2 ) ) {
V_7 = F_5 ( & V_112 -> V_2 ) ;
if ( V_7 )
goto V_136;
}
V_7 = F_56 ( & V_112 -> V_2 , & V_137 ,
& V_4 -> V_11 , 1 ) ;
if ( V_7 ) {
F_7 ( & V_112 -> V_2 , L_11 , V_7 ) ;
V_7 = - V_121 ;
goto V_138;
}
V_7 = F_57 ( & V_112 -> V_2 ) ;
if ( V_7 ) {
F_7 ( & V_112 -> V_2 , L_12 , V_7 ) ;
goto V_139;
}
return 0 ;
V_139:
F_58 ( & V_112 -> V_2 ) ;
V_138:
if ( ! F_59 ( & V_112 -> V_2 ) )
F_1 ( & V_112 -> V_2 ) ;
V_136:
F_60 ( & V_112 -> V_2 ) ;
V_131:
F_61 ( V_4 -> V_6 ) ;
V_122:
return V_7 ;
}
static int F_62 ( struct V_111 * V_112 )
{
struct V_3 * V_4 = F_2 ( & V_112 -> V_2 ) ;
F_60 ( & V_112 -> V_2 ) ;
if ( ! F_59 ( & V_112 -> V_2 ) )
F_1 ( & V_112 -> V_2 ) ;
F_63 ( & V_112 -> V_2 ) ;
F_58 ( & V_112 -> V_2 ) ;
F_61 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_65 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_67 ( V_4 -> V_5 ) ;
F_20 ( V_2 ) ;
return V_7 ;
}
