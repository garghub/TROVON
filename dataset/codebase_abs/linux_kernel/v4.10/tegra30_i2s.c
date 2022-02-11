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
unsigned int V_10 )
{
struct V_3 * V_4 = F_9 ( V_9 ) ;
unsigned int V_11 = 0 , V_12 = 0 ;
switch ( V_10 & V_13 ) {
case V_14 :
break;
default:
return - V_15 ;
}
V_11 |= V_16 ;
switch ( V_10 & V_17 ) {
case V_18 :
V_12 |= V_16 ;
break;
case V_19 :
break;
default:
return - V_15 ;
}
V_11 |= V_20 |
V_21 ;
switch ( V_10 & V_22 ) {
case V_23 :
V_12 |= V_24 ;
V_12 |= V_25 ;
break;
case V_26 :
V_12 |= V_24 ;
V_12 |= V_27 ;
break;
case V_28 :
V_12 |= V_29 ;
V_12 |= V_25 ;
break;
case V_30 :
V_12 |= V_29 ;
V_12 |= V_25 ;
break;
case V_31 :
V_12 |= V_29 ;
V_12 |= V_25 ;
break;
default:
return - V_15 ;
}
F_10 ( V_9 -> V_2 ) ;
F_11 ( V_4 -> V_5 , V_32 , V_11 , V_12 ) ;
F_12 ( V_9 -> V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = F_9 ( V_9 ) ;
unsigned int V_11 , V_12 , V_37 ;
int V_7 , V_38 , V_39 , V_40 , V_41 ;
struct V_42 V_43 ;
if ( F_14 ( V_36 ) != 2 )
return - V_15 ;
V_11 = V_44 ;
switch ( F_15 ( V_36 ) ) {
case V_45 :
V_12 = V_46 ;
V_38 = 16 ;
break;
default:
return - V_15 ;
}
F_11 ( V_4 -> V_5 , V_32 , V_11 , V_12 ) ;
V_39 = F_16 ( V_36 ) ;
V_40 = V_39 * F_14 ( V_36 ) * V_38 * 2 ;
V_41 = ( V_40 / ( 2 * V_39 ) ) - 1 ;
if ( V_41 < 0 || V_41 > V_47 )
return - V_15 ;
V_7 = F_17 ( V_4 -> V_6 , V_40 ) ;
if ( V_7 ) {
F_7 ( V_2 , L_2 , V_7 ) ;
return V_7 ;
}
V_12 = V_41 << V_48 ;
if ( V_40 % ( 2 * V_39 ) )
V_12 |= V_49 ;
F_18 ( V_4 -> V_5 , V_50 , V_12 ) ;
V_43 . V_51 = 0 ;
V_43 . V_52 = 2 ;
V_43 . V_53 = 2 ;
V_43 . V_54 = V_55 ;
V_43 . V_56 = V_55 ;
V_43 . V_57 = 0 ;
V_43 . V_58 = 0 ;
V_43 . V_59 = 0 ;
V_43 . V_60 = 0 ;
V_43 . V_61 = 0 ;
if ( V_34 -> V_62 == V_63 ) {
V_43 . V_64 = V_65 ;
V_37 = V_66 ;
} else {
V_43 . V_64 = V_67 ;
V_37 = V_68 ;
}
V_4 -> V_69 -> V_70 ( V_4 -> V_5 , V_37 , & V_43 ) ;
V_12 = ( 1 << V_71 ) |
( 1 << V_72 ) ;
F_18 ( V_4 -> V_5 , V_73 , V_12 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
F_20 ( V_4 -> V_74 ) ;
F_11 ( V_4 -> V_5 , V_32 ,
V_75 ,
V_75 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_22 ( V_4 -> V_74 ) ;
F_11 ( V_4 -> V_5 , V_32 ,
V_75 , 0 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
F_24 ( V_4 -> V_76 ) ;
F_11 ( V_4 -> V_5 , V_32 ,
V_77 ,
V_77 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
F_26 ( V_4 -> V_76 ) ;
F_11 ( V_4 -> V_5 , V_32 ,
V_77 , 0 ) ;
}
static int F_27 ( struct V_33 * V_34 , int V_78 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_9 ( V_9 ) ;
switch ( V_78 ) {
case V_79 :
case V_80 :
case V_81 :
if ( V_34 -> V_62 == V_63 )
F_19 ( V_4 ) ;
else
F_23 ( V_4 ) ;
break;
case V_82 :
case V_83 :
case V_84 :
if ( V_34 -> V_62 == V_63 )
F_21 ( V_4 ) ;
else
F_25 ( V_4 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_9 ( V_9 ) ;
V_9 -> V_85 = & V_4 -> V_85 ;
V_9 -> V_86 = & V_4 -> V_86 ;
return 0 ;
}
static bool F_29 ( struct V_1 * V_2 , unsigned int V_37 )
{
switch ( V_37 ) {
case V_32 :
case V_50 :
case V_73 :
case V_87 :
case V_88 :
case V_66 :
case V_68 :
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
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
return true ;
default:
return false ;
}
}
static bool F_30 ( struct V_1 * V_2 , unsigned int V_37 )
{
switch ( V_37 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
return true ;
default:
return false ;
}
}
static int F_31 ( struct V_104 * V_105 )
{
struct V_3 * V_4 ;
const struct V_106 * V_107 ;
T_1 V_108 [ 2 ] ;
struct V_109 * V_110 ;
void T_2 * V_111 ;
int V_7 ;
V_4 = F_32 ( & V_105 -> V_2 , sizeof( struct V_3 ) , V_112 ) ;
if ( ! V_4 ) {
F_7 ( & V_105 -> V_2 , L_3 ) ;
V_7 = - V_113 ;
goto V_114;
}
F_33 ( & V_105 -> V_2 , V_4 ) ;
V_107 = F_34 ( V_115 , & V_105 -> V_2 ) ;
if ( ! V_107 ) {
F_7 ( & V_105 -> V_2 , L_4 ) ;
V_7 = - V_116 ;
goto V_114;
}
V_4 -> V_69 = (struct V_117 * ) V_107 -> V_118 ;
V_4 -> V_9 = V_119 ;
V_4 -> V_9 . V_120 = F_35 ( & V_105 -> V_2 ) ;
V_7 = F_36 ( V_105 -> V_2 . V_121 ,
L_5 , V_108 ,
F_37 ( V_108 ) ) ;
if ( V_7 < 0 )
goto V_114;
V_4 -> V_122 = V_108 [ 0 ] ;
V_4 -> V_123 = V_108 [ 1 ] ;
V_4 -> V_6 = F_38 ( & V_105 -> V_2 , NULL ) ;
if ( F_39 ( V_4 -> V_6 ) ) {
F_7 ( & V_105 -> V_2 , L_6 ) ;
V_7 = F_40 ( V_4 -> V_6 ) ;
goto V_114;
}
V_110 = F_41 ( V_105 , V_124 , 0 ) ;
V_111 = F_42 ( & V_105 -> V_2 , V_110 ) ;
if ( F_39 ( V_111 ) ) {
V_7 = F_40 ( V_111 ) ;
goto V_125;
}
V_4 -> V_5 = F_43 ( & V_105 -> V_2 , V_111 ,
& V_126 ) ;
if ( F_39 ( V_4 -> V_5 ) ) {
F_7 ( & V_105 -> V_2 , L_7 ) ;
V_7 = F_40 ( V_4 -> V_5 ) ;
goto V_125;
}
F_3 ( V_4 -> V_5 , true ) ;
F_44 ( & V_105 -> V_2 ) ;
if ( ! F_45 ( & V_105 -> V_2 ) ) {
V_7 = F_5 ( & V_105 -> V_2 ) ;
if ( V_7 )
goto V_127;
}
V_4 -> V_86 . V_128 = V_129 ;
V_4 -> V_86 . V_130 = 4 ;
V_7 = F_46 ( & V_4 -> V_74 ,
V_4 -> V_131 ,
sizeof( V_4 -> V_131 ) ,
& V_4 -> V_86 . V_132 ) ;
if ( V_7 ) {
F_7 ( & V_105 -> V_2 , L_8 , V_7 ) ;
goto V_133;
}
V_7 = F_47 ( V_4 -> V_122 ,
V_4 -> V_74 ) ;
if ( V_7 ) {
F_7 ( & V_105 -> V_2 , L_9 , V_7 ) ;
goto V_134;
}
V_4 -> V_85 . V_128 = V_129 ;
V_4 -> V_85 . V_130 = 4 ;
V_7 = F_48 ( & V_4 -> V_76 ,
V_4 -> V_135 ,
sizeof( V_4 -> V_135 ) ,
& V_4 -> V_85 . V_132 ) ;
if ( V_7 ) {
F_7 ( & V_105 -> V_2 , L_10 , V_7 ) ;
goto V_136;
}
V_7 = F_47 ( V_4 -> V_76 ,
V_4 -> V_123 ) ;
if ( V_7 ) {
F_7 ( & V_105 -> V_2 , L_9 , V_7 ) ;
goto V_137;
}
V_7 = F_49 ( & V_105 -> V_2 , & V_138 ,
& V_4 -> V_9 , 1 ) ;
if ( V_7 ) {
F_7 ( & V_105 -> V_2 , L_11 , V_7 ) ;
V_7 = - V_113 ;
goto V_139;
}
V_7 = F_50 ( & V_105 -> V_2 ,
& V_4 -> V_140 , V_4 -> V_131 ,
V_4 -> V_135 ) ;
if ( V_7 ) {
F_7 ( & V_105 -> V_2 , L_12 , V_7 ) ;
goto V_141;
}
return 0 ;
V_141:
F_51 ( & V_105 -> V_2 ) ;
V_139:
F_52 ( V_4 -> V_76 ) ;
V_137:
F_53 ( V_4 -> V_76 ) ;
V_136:
F_52 ( V_4 -> V_122 ) ;
V_134:
F_54 ( V_4 -> V_74 ) ;
V_133:
if ( ! F_55 ( & V_105 -> V_2 ) )
F_1 ( & V_105 -> V_2 ) ;
V_127:
F_56 ( & V_105 -> V_2 ) ;
V_125:
F_57 ( V_4 -> V_6 ) ;
V_114:
return V_7 ;
}
static int F_58 ( struct V_104 * V_105 )
{
struct V_3 * V_4 = F_2 ( & V_105 -> V_2 ) ;
F_56 ( & V_105 -> V_2 ) ;
if ( ! F_55 ( & V_105 -> V_2 ) )
F_1 ( & V_105 -> V_2 ) ;
F_59 ( & V_105 -> V_2 ) ;
F_51 ( & V_105 -> V_2 ) ;
F_52 ( V_4 -> V_76 ) ;
F_53 ( V_4 -> V_76 ) ;
F_52 ( V_4 -> V_122 ) ;
F_54 ( V_4 -> V_74 ) ;
F_57 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_61 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_10 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_63 ( V_4 -> V_5 ) ;
F_12 ( V_2 ) ;
return V_7 ;
}
