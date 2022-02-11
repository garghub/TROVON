static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
V_8 = F_3 ( V_6 , V_3 , V_4 ) ;
F_4 ( & V_6 -> V_9 , L_1 , V_3 , V_4 ,
V_8 < 0 ? L_2 : L_3 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
V_8 = F_6 ( V_6 , V_3 ) ;
F_4 ( & V_6 -> V_9 , L_4 , V_3 , V_8 ,
V_8 < 0 ? L_2 : L_3 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_10 ;
T_1 V_4 ;
V_4 = ( V_2 -> V_11 << V_12 )
| ( V_2 -> V_13 << V_14 )
| V_15 ;
V_10 = F_1 ( V_2 , V_16 , V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = F_8 ( V_2 -> V_17 / 1000 )
<< V_18 ;
V_4 |= ( V_2 -> V_19 -> V_20 << V_21 )
| ( ( V_2 -> V_22 ? V_2 -> V_22 - 1 : 0 )
<< V_23 ) ;
return F_1 ( V_2 , V_24 , V_4 ) ;
}
static int
F_9 ( struct V_1 * V_2 , enum V_25 V_26 , bool V_27 )
{
T_1 V_28 ;
V_28 = ( V_2 -> V_19 -> V_29 << V_30 )
| ( V_27 ? V_31 : 0 )
| V_26 ;
if ( V_2 -> V_32 == V_33 &&
V_2 -> V_34 == V_35 ) {
V_28 |= V_36
| V_37 ;
}
return F_1 ( V_2 , V_38 , V_28 ) ;
}
static int F_10 ( struct V_1 * V_2 , bool V_39 )
{
enum V_25 V_26 ;
bool V_27 ;
switch ( V_2 -> V_32 ) {
case V_40 :
V_27 = V_2 -> V_22 != 0 ;
V_26 = V_41 ;
break;
case V_42 :
V_27 = true ;
V_26 = V_43 ;
break;
case V_33 :
V_27 = V_39 ;
V_26 = V_44 ;
break;
default:
F_11 () ;
}
return F_9 ( V_2 , V_26 , V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_5 ( V_2 , V_38 ) ;
return V_10 < 0 ? V_10 : ! ! ( V_10 & V_31 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
V_8 = F_5 ( V_2 , V_45 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_46 )
F_4 ( & V_6 -> V_9 , L_5 ) ;
if ( V_8 & V_47 )
F_4 ( & V_6 -> V_9 ,
L_6 ) ;
F_4 ( & V_6 -> V_9 , L_7 ,
V_8 & V_48 ? 2 : 1 ) ;
if ( V_8 & V_49 )
F_4 ( & V_6 -> V_9 , L_8 ) ;
if ( V_8 & V_50 )
F_4 ( & V_6 -> V_9 , L_9 ) ;
if ( V_8 & V_51 )
F_4 ( & V_6 -> V_9 , L_10 ) ;
if ( V_8 & V_52 )
F_4 ( & V_6 -> V_9 ,
L_11 ) ;
return V_8 ;
}
static int F_14 ( struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_15 ( V_54 -> V_55 , struct V_1 , V_56 ) ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_57 ;
switch ( V_54 -> V_58 ) {
case V_59 :
V_57 = F_13 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
V_54 -> V_60 . V_4 = 0 ;
if ( V_57 & V_51 )
V_54 -> V_60 . V_4 |= V_61 ;
if ( V_57 & V_50 )
V_54 -> V_60 . V_4 |= V_62 ;
if ( V_57 & V_49 )
V_54 -> V_60 . V_4 |= V_63 ;
if ( V_57 & V_52 )
V_54 -> V_60 . V_4 |= V_64 ;
if ( V_57 & V_46 )
V_54 -> V_60 . V_4 |= V_65 ;
if ( V_57 & V_47 )
V_54 -> V_60 . V_4 |= V_66 ;
break;
case V_67 :
if ( V_2 -> V_32 != V_33 ) {
V_54 -> V_60 . V_4 = 0 ;
break;
}
V_57 = F_12 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
V_54 -> V_60 . V_4 = V_57 ;
break;
}
F_4 ( & V_6 -> V_9 , L_12 , V_54 -> V_58 , V_54 -> V_60 . V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_15 ( V_54 -> V_55 , struct V_1 , V_56 ) ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_10 ;
F_4 ( & V_6 -> V_9 , L_13 , V_54 -> V_58 , V_54 -> V_4 ) ;
switch ( V_54 -> V_58 ) {
case V_68 :
if ( V_2 -> V_22 )
return - V_69 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_32 = V_54 -> V_4 ;
return F_10 ( V_2 , false ) ;
case V_70 :
V_2 -> V_34 = V_54 -> V_4 ;
if ( V_2 -> V_32 != V_33 )
break;
return F_10 ( V_2 , false ) ;
case V_71 :
if ( V_2 -> V_32 != V_33 )
return - V_69 ;
return F_10 ( V_2 , true ) ;
case V_72 :
if ( V_2 -> V_32 != V_33 )
return - V_69 ;
return F_10 ( V_2 , false ) ;
case V_73 :
V_2 -> V_17 = V_54 -> V_4 ;
if ( V_2 -> V_32 != V_33 )
break;
return F_7 ( V_2 ) ;
case V_74 :
V_2 -> V_11 = ( V_54 -> V_4 - V_75 )
/ V_76 ;
if ( V_2 -> V_32 != V_33 )
break;
return F_7 ( V_2 ) ;
case V_77 :
V_2 -> V_13 =
( V_54 -> V_4 - V_78 )
/ V_79 ;
if ( V_2 -> V_32 != V_42 )
break;
return F_7 ( V_2 ) ;
case V_80 :
if ( V_2 -> V_32 != V_40 )
return - V_69 ;
V_2 -> V_22 =
( V_54 -> V_4 - V_81 )
/ V_82 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ( V_54 -> V_4 == 0 ) == ( V_54 -> V_60 . V_4 == 0 ) )
break;
return F_10 ( V_2 , false ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_10 ;
V_10 = F_5 ( V_2 , V_45 ) ;
if ( V_10 < 0 )
return V_10 ;
F_4 ( & V_6 -> V_9 , L_14 , V_10 ) ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_2 , false ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_4 ( & V_6 -> V_9 , L_15 ,
F_5 ( V_2 , V_24 ) ) ;
F_4 ( & V_6 -> V_9 , L_16 ,
F_5 ( V_2 , V_16 ) ) ;
F_4 ( & V_6 -> V_9 , L_17 ,
F_5 ( V_2 , V_38 ) ) ;
return V_10 & ~ V_48 ? - V_83 : 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_27 )
{
int V_10 ;
if ( ! V_27 )
F_9 ( V_2 , V_84 , false ) ;
if ( V_2 -> V_19 -> V_85 ) {
V_10 = V_2 -> V_19 -> V_85 ( & V_2 -> V_7 , V_27 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( ! V_27 )
return 0 ;
V_10 = F_17 ( V_2 ) ;
if ( V_10 < 0 ) {
if ( V_2 -> V_19 -> V_85 )
V_2 -> V_19 -> V_85 ( & V_2 -> V_7 , 0 ) ;
}
return V_10 ;
}
static int F_19 ( struct V_86 * V_87 , int V_27 )
{
struct V_1 * V_2 = F_20 ( V_87 ) ;
int V_10 = 0 ;
F_21 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_89 == ! V_27 ) {
V_10 = F_18 ( V_2 , ! ! V_27 ) ;
if ( V_10 < 0 )
goto V_90;
}
V_2 -> V_89 += V_27 ? 1 : - 1 ;
F_22 ( V_2 -> V_89 < 0 ) ;
V_90:
F_23 ( & V_2 -> V_88 ) ;
return V_10 ;
}
static int F_24 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_20 ( V_87 ) ;
struct V_5 * V_6 = F_2 ( V_87 ) ;
int V_8 , V_91 , V_92 , V_93 , V_94 ;
const char * V_95 ;
V_8 = F_19 ( & V_2 -> V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_5 ( V_2 , V_96 ) ;
if ( V_8 < 0 )
goto V_97;
V_91 = F_25 ( V_8 ) ;
V_92 = F_26 ( V_8 ) ;
V_8 = F_5 ( V_2 , V_98 ) ;
if ( V_8 < 0 )
goto V_97;
V_93 = F_27 ( V_8 ) ;
V_94 = F_28 ( V_8 ) ;
if ( V_92 != 0x01 || V_93 != 0x00 ) {
F_29 ( & V_6 -> V_9 ,
L_18 , V_92 , V_93 ) ;
V_8 = - V_99 ;
goto V_97;
}
switch ( V_91 ) {
case 1 :
V_95 = L_19 ;
break;
case 2 :
V_95 = L_20 ;
break;
case 3 :
V_95 = L_21 ;
break;
case 4 :
V_95 = L_22 ;
break;
case 5 :
V_95 = L_23 ;
break;
default:
V_95 = L_24 ;
}
F_30 ( & V_6 -> V_9 , L_25 , V_95 ,
V_91 , V_94 ) ;
V_8 = F_1 ( V_2 , V_100 , V_101 ) ;
if ( V_8 < 0 )
goto V_97;
V_8 = F_1 ( V_2 , V_102 , V_103 ) ;
if ( V_8 < 0 )
goto V_97;
V_8 = F_17 ( V_2 ) ;
V_97:
F_19 ( & V_2 -> V_7 , 0 ) ;
return V_8 ;
}
static int F_31 ( struct V_86 * V_87 , struct V_104 * V_105 )
{
return F_19 ( V_87 , 1 ) ;
}
static int F_32 ( struct V_86 * V_87 , struct V_104 * V_105 )
{
return F_19 ( V_87 , 0 ) ;
}
static int F_33 ( struct V_106 * V_9 )
{
struct V_5 * V_6 = F_34 ( V_9 ) ;
struct V_86 * V_7 = F_35 ( V_6 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
int V_8 ;
if ( V_2 -> V_89 == 0 )
return 0 ;
V_8 = F_18 ( V_2 , 0 ) ;
F_4 ( & V_6 -> V_9 , L_26 , V_8 < 0 ? L_27 : L_3 ) ;
return V_8 ;
}
static int F_36 ( struct V_106 * V_9 )
{
struct V_5 * V_6 = F_34 ( V_9 ) ;
struct V_86 * V_7 = F_35 ( V_6 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
int V_8 ;
if ( V_2 -> V_89 == 0 )
return 0 ;
V_8 = F_18 ( V_2 , 1 ) ;
F_4 ( & V_6 -> V_9 , L_28 , V_8 < 0 ? L_2 : L_3 ) ;
return V_8 ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_107 * V_19 = V_2 -> V_19 ;
struct V_53 * V_54 ;
int V_108 ;
F_38 ( & V_2 -> V_56 , 10 ) ;
F_39 ( & V_2 -> V_56 , & V_109 ,
V_68 , 2 , ~ 7 ,
V_40 ) ;
F_39 ( & V_2 -> V_56 , & V_109 ,
V_70 ,
V_19 -> V_110 ? 1 : 0 ,
V_19 -> V_110 ? ~ 3 : ~ 1 ,
V_111 ) ;
V_2 -> V_34 = V_111 ;
F_40 ( & V_2 -> V_56 , & V_109 ,
V_71 , 0 , 0 , 0 , 0 ) ;
F_40 ( & V_2 -> V_56 , & V_109 ,
V_72 , 0 , 0 , 0 , 0 ) ;
V_54 = F_40 ( & V_2 -> V_56 , & V_109 ,
V_67 , 0 , 1 , 1 , 1 ) ;
if ( V_54 != NULL )
V_54 -> V_112 |= V_113 ;
V_108 = V_19 -> V_114 ;
F_40 ( & V_2 -> V_56 , & V_109 ,
V_73 , V_115 ,
V_108 , V_116 , V_108 ) ;
V_2 -> V_17 = V_108 ;
V_108 = V_19 -> V_117 ;
F_40 ( & V_2 -> V_56 , & V_109 ,
V_74 , V_75 ,
V_108 , V_76 , V_108 ) ;
V_2 -> V_11 = ( V_108 - V_75 )
/ V_76 ;
V_108 = V_19 -> V_118 ;
F_40 ( & V_2 -> V_56 , & V_109 ,
V_77 ,
V_78 , V_108 ,
V_79 ,
V_78 ) ;
V_2 -> V_13 = 0 ;
F_40 ( & V_2 -> V_56 , & V_109 ,
V_80 ,
V_81 ,
V_119 ,
V_82 ,
V_81 ) ;
V_2 -> V_22 = 0 ;
V_54 = F_40 ( & V_2 -> V_56 , & V_109 ,
V_59 , 0 ,
V_64 |
V_63 |
V_62 |
V_61 , 0 , 0 ) ;
if ( V_54 != NULL )
V_54 -> V_112 |= V_113 ;
V_2 -> V_7 . V_120 = & V_2 -> V_56 ;
return V_2 -> V_56 . error ;
}
static int F_41 ( struct V_5 * V_6 ,
const struct V_121 * V_122 )
{
struct V_1 * V_2 ;
int V_10 ;
if ( V_6 -> V_9 . V_123 == NULL )
return - V_99 ;
V_2 = F_42 ( & V_6 -> V_9 , sizeof( * V_2 ) , V_124 ) ;
if ( V_2 == NULL )
return - V_125 ;
V_2 -> V_19 = V_6 -> V_9 . V_123 ;
F_43 ( & V_2 -> V_7 , V_6 , & V_126 ) ;
V_2 -> V_7 . V_127 = & V_128 ;
V_2 -> V_7 . V_112 |= V_129 ;
V_10 = F_37 ( V_2 ) ;
if ( V_10 < 0 )
goto V_90;
V_10 = F_44 ( & V_2 -> V_7 . V_130 , 0 , NULL ) ;
if ( V_10 < 0 )
goto V_90;
V_2 -> V_7 . V_130 . V_131 = V_132 ;
F_45 ( & V_2 -> V_88 ) ;
V_2 -> V_32 = V_40 ;
V_90:
if ( V_10 < 0 )
F_46 ( & V_2 -> V_56 ) ;
return V_10 ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_86 * V_7 = F_35 ( V_6 ) ;
struct V_1 * V_2 = F_20 ( V_7 ) ;
F_48 ( V_7 ) ;
F_46 ( & V_2 -> V_56 ) ;
F_49 ( & V_2 -> V_7 . V_130 ) ;
F_50 ( & V_2 -> V_88 ) ;
return 0 ;
}
