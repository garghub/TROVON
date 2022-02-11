static T_1 F_1 ( T_2 V_1 )
{
if ( ! ( V_1 & V_2 ) )
return V_3 ;
switch ( V_1 & V_4 ) {
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 | V_19 ;
case V_20 :
return V_16 ;
default:
return V_3 ;
}
}
static int F_2 ( T_1 V_21 )
{
if ( V_21 == V_12 )
return V_22 ;
if ( V_21 == V_8 )
return V_23 ;
if ( V_21 == V_19 )
return V_24 ;
if ( V_21 == V_10 )
return V_25 ;
if ( V_21 == V_18 )
return V_26 ;
if ( V_21 & V_14 )
return V_27 ;
if ( V_21 & V_6 )
return V_28 ;
if ( V_21 & V_16 )
return V_29 ;
return - V_30 ;
}
static T_3 F_3 ( T_2 V_1 )
{
if ( ! ( V_1 & V_2 ) )
return V_31 ;
return 0 ;
}
static int F_4 ( struct V_32 * V_33 , T_3 * V_34 ,
T_1 * V_21 )
{
int V_1 = F_5 ( V_33 , V_35 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( V_34 )
* V_34 = F_3 ( V_1 ) ;
if ( V_21 )
* V_21 = F_1 ( V_1 ) ;
return 0 ;
}
static inline struct V_36 * F_6 ( struct V_37 * V_38 )
{
return F_7 ( V_38 , struct V_36 , V_38 ) ;
}
static int F_8 ( struct V_37 * V_38 , T_1 * V_21 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_40 = F_9 ( & V_39 -> V_41 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_39 -> V_42 || V_39 -> V_43 > 0 )
* V_21 = V_39 -> V_44 ;
else
V_40 = F_4 ( F_10 ( V_38 ) , NULL , V_21 ) ;
F_11 ( & V_39 -> V_41 ) ;
return V_40 ;
}
static int F_12 ( struct V_37 * V_38 , T_3 V_45 ,
T_3 V_46 , T_3 V_47 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_48 = F_9 ( & V_39 -> V_41 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
if ( V_48 )
return V_48 ;
if ( ( V_45 & V_49 ) != V_45 )
goto V_50;
V_48 = F_5 ( V_33 , V_51 ) ;
if ( V_48 < 0 )
goto V_50;
V_48 &= ~ V_49 ;
V_48 = F_13 ( V_33 ,
V_51 , V_48 | V_45 ) ;
V_39 -> V_45 = V_45 ;
V_50:
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_14 ( struct V_37 * V_38 , T_3 * V_34 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_48 = F_9 ( & V_39 -> V_41 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_4 ( F_10 ( V_38 ) , V_34 , NULL ) ;
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_15 ( struct V_37 * V_38 , T_1 V_21 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
int V_48 = F_9 ( & V_39 -> V_41 ) ;
if ( V_48 )
return V_48 ;
if ( V_21 == V_52 ) {
V_48 =
F_13 ( V_33 , V_51 ,
V_53
| V_39 -> V_45 ) ;
if ( V_48 < 0 )
goto V_50;
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
V_39 -> V_42 = true ;
} else {
V_48 = F_2 ( V_21 ) ;
if ( V_48 < 0 )
goto V_50;
V_48 = F_13 ( V_33 ,
V_51 ,
V_48 | V_39 -> V_45 ) ;
if ( V_48 < 0 )
goto V_50;
V_39 -> V_44 = V_21 ;
V_39 -> V_42 = false ;
}
V_48 = 0 ;
V_50:
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_16 ( struct V_36 * V_39 ,
struct V_32 * V_33 , bool V_54 )
{
T_2 V_55 ;
if ( V_54 )
V_55 = V_56 ;
else
V_55 = V_57 ;
return F_13 ( V_33 , V_58 , V_55 ) ;
}
static int F_17 ( struct V_37 * V_38 , int V_54 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
int V_48 ;
V_48 = F_9 ( & V_39 -> V_41 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_16 ( V_39 , V_33 , V_54 ) ;
if ( V_48 == 0 )
V_39 -> V_59 = V_54 ;
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_18 ( struct V_60 * V_61 )
{
struct V_37 * V_38 = F_19 ( V_61 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
int V_48 = F_9 ( & V_39 -> V_41 ) ;
int V_55 ;
if ( V_48 )
return V_48 ;
V_55 = V_61 -> V_55 ;
switch ( V_61 -> V_62 ) {
case V_63 :
V_48 = F_13 ( V_33 , V_64 , V_55 ) ;
break;
case V_65 :
V_48 = F_13 ( V_33 , V_66 , - V_55 ) ;
break;
case V_67 :
V_48 = F_13 ( V_33 , V_68 , V_55 ) ;
break;
case V_69 :
V_48 = F_13 ( V_33 , V_70 ,
V_55 ) ;
if ( V_48 < 0 )
break;
V_48 = F_13 ( V_33 , V_71 ,
V_55 ) ;
break;
default:
V_48 = - V_30 ;
}
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_20 ( struct V_36 * V_39 )
{
F_21 ( & V_39 -> V_72 , 4 ) ;
F_22 ( & V_39 -> V_72 , & V_73 ,
V_63 , V_74 ,
V_75 , 1 , V_76 ) ;
F_22 ( & V_39 -> V_72 , & V_73 ,
V_67 , V_77 ,
V_78 , 1 , V_79 ) ;
F_22 ( & V_39 -> V_72 , & V_73 ,
V_69 , V_80 ,
V_81 , 1 , V_82 ) ;
F_22 ( & V_39 -> V_72 , & V_73 ,
V_65 , V_83 ,
V_84 , 1 , V_85 ) ;
V_39 -> V_38 . V_86 = & V_39 -> V_72 ;
if ( V_39 -> V_72 . error ) {
int V_40 = V_39 -> V_72 . error ;
F_23 ( & V_39 -> V_72 ) ;
return V_40 ;
}
F_24 ( & V_39 -> V_72 ) ;
return 0 ;
}
static void F_25 ( struct V_36 * V_39 )
{
F_23 ( & V_39 -> V_72 ) ;
}
static int F_26 ( struct V_37 * V_38 , unsigned int V_87 ,
T_3 * V_88 )
{
if ( V_87 > 0 )
return - V_30 ;
* V_88 = V_89 ;
return 0 ;
}
static int F_27 ( struct V_37 * V_38 ,
struct V_90 * V_91 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
V_91 -> V_88 = V_89 ;
V_91 -> V_92 = V_93 ;
V_91 -> V_94 = V_95 ;
V_91 -> V_96 = 720 ;
V_91 -> V_97 = V_39 -> V_44 & V_98 ? 480 : 576 ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 ,
struct V_99 * V_100 )
{
V_100 -> V_101 = V_102 | V_103 |
V_104 ;
V_100 -> type = V_105 ;
return 0 ;
}
static T_4 F_29 ( int V_43 , void * V_106 )
{
struct V_36 * V_39 = V_106 ;
struct V_32 * V_33 = F_10 ( & V_39 -> V_38 ) ;
T_2 V_107 ;
F_30 ( & V_39 -> V_41 ) ;
F_13 ( V_33 , V_108 ,
V_109 ) ;
V_107 = F_5 ( V_33 , V_110 ) ;
F_13 ( V_33 , V_111 , V_107 ) ;
F_13 ( V_33 , V_108 , 0 ) ;
if ( V_107 & V_112 && V_39 -> V_42 )
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
F_11 ( & V_39 -> V_41 ) ;
return V_113 ;
}
static int F_31 ( struct V_32 * V_33 , struct V_36 * V_39 )
{
int V_48 ;
if ( V_39 -> V_42 ) {
V_48 =
F_13 ( V_33 , V_51 ,
V_53
| V_39 -> V_45 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 =
F_13 ( V_33 ,
V_114 ,
V_115 ) ;
if ( V_48 < 0 )
return V_48 ;
} else {
V_48 = F_2 ( V_39 -> V_44 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 =
F_13 ( V_33 , V_51 ,
V_48 | V_39 -> V_45 ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_48 = F_13 ( V_33 ,
V_116 ,
V_117 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 ,
V_118 ,
V_119 ) ;
if ( V_48 < 0 )
return V_48 ;
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
if ( V_39 -> V_43 > 0 ) {
V_48 = F_32 ( V_39 -> V_43 , NULL , F_29 ,
V_120 , V_121 , V_39 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_13 ( V_33 , V_108 ,
V_109 ) ;
if ( V_48 < 0 )
goto V_40;
V_48 = F_13 ( V_33 , V_122 ,
V_123 |
V_124 ) ;
if ( V_48 < 0 )
goto V_40;
V_48 = F_13 ( V_33 , V_125 , 0 ) ;
if ( V_48 < 0 )
goto V_40;
V_48 = F_13 ( V_33 , V_126 , 0 ) ;
if ( V_48 < 0 )
goto V_40;
V_48 = F_13 ( V_33 , V_127 ,
V_112 ) ;
if ( V_48 < 0 )
goto V_40;
V_48 = F_13 ( V_33 , V_128 , 0 ) ;
if ( V_48 < 0 )
goto V_40;
V_48 = F_13 ( V_33 , V_108 ,
0 ) ;
if ( V_48 < 0 )
goto V_40;
}
return 0 ;
V_40:
F_33 ( V_39 -> V_43 , V_39 ) ;
return V_48 ;
}
static int F_34 ( struct V_32 * V_33 ,
const struct V_129 * V_62 )
{
struct V_36 * V_39 ;
struct V_37 * V_38 ;
int V_48 ;
if ( ! F_35 ( V_33 -> V_130 , V_131 ) )
return - V_132 ;
F_36 ( V_33 , L_1 ,
V_33 -> V_133 , V_33 -> V_130 -> V_134 ) ;
V_39 = F_37 ( & V_33 -> V_135 , sizeof( * V_39 ) , V_136 ) ;
if ( V_39 == NULL ) {
V_48 = - V_137 ;
goto V_40;
}
V_39 -> V_43 = V_33 -> V_43 ;
F_38 ( & V_39 -> V_41 ) ;
V_39 -> V_42 = true ;
V_39 -> V_59 = true ;
V_39 -> V_45 = 0 ;
V_38 = & V_39 -> V_38 ;
F_39 ( V_38 , V_33 , & V_138 ) ;
V_48 = F_20 ( V_39 ) ;
if ( V_48 )
goto V_139;
V_48 = F_31 ( V_33 , V_39 ) ;
if ( V_48 )
goto V_140;
V_48 = F_40 ( V_38 ) ;
if ( V_48 )
goto V_141;
return 0 ;
V_141:
if ( V_39 -> V_43 > 0 )
F_33 ( V_33 -> V_43 , V_39 ) ;
V_140:
F_25 ( V_39 ) ;
V_139:
F_41 ( & V_39 -> V_41 ) ;
V_40:
return V_48 ;
}
static int F_42 ( struct V_32 * V_33 )
{
struct V_37 * V_38 = F_43 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
F_44 ( V_38 ) ;
if ( V_39 -> V_43 > 0 )
F_33 ( V_33 -> V_43 , V_39 ) ;
F_25 ( V_39 ) ;
F_41 ( & V_39 -> V_41 ) ;
return 0 ;
}
static int F_45 ( struct V_142 * V_135 )
{
struct V_32 * V_33 = F_46 ( V_135 ) ;
struct V_37 * V_38 = F_43 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
return F_16 ( V_39 , V_33 , false ) ;
}
static int F_47 ( struct V_142 * V_135 )
{
struct V_32 * V_33 = F_46 ( V_135 ) ;
struct V_37 * V_38 = F_43 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_48 ;
if ( V_39 -> V_59 ) {
V_48 = F_16 ( V_39 , V_33 , true ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_31 ( V_33 , V_39 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
