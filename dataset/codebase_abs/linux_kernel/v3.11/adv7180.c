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
static int F_16 ( struct V_54 * V_55 )
{
struct V_37 * V_38 = F_17 ( V_55 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
int V_48 = F_9 ( & V_39 -> V_41 ) ;
int V_56 ;
if ( V_48 )
return V_48 ;
V_56 = V_55 -> V_56 ;
switch ( V_55 -> V_57 ) {
case V_58 :
V_48 = F_13 ( V_33 , V_59 , V_56 ) ;
break;
case V_60 :
V_48 = F_13 ( V_33 , V_61 , - V_56 ) ;
break;
case V_62 :
V_48 = F_13 ( V_33 , V_63 , V_56 ) ;
break;
case V_64 :
V_48 = F_13 ( V_33 , V_65 ,
V_56 ) ;
if ( V_48 < 0 )
break;
V_48 = F_13 ( V_33 , V_66 ,
V_56 ) ;
break;
default:
V_48 = - V_30 ;
}
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_18 ( struct V_36 * V_39 )
{
F_19 ( & V_39 -> V_67 , 4 ) ;
F_20 ( & V_39 -> V_67 , & V_68 ,
V_58 , V_69 ,
V_70 , 1 , V_71 ) ;
F_20 ( & V_39 -> V_67 , & V_68 ,
V_62 , V_72 ,
V_73 , 1 , V_74 ) ;
F_20 ( & V_39 -> V_67 , & V_68 ,
V_64 , V_75 ,
V_76 , 1 , V_77 ) ;
F_20 ( & V_39 -> V_67 , & V_68 ,
V_60 , V_78 ,
V_79 , 1 , V_80 ) ;
V_39 -> V_38 . V_81 = & V_39 -> V_67 ;
if ( V_39 -> V_67 . error ) {
int V_40 = V_39 -> V_67 . error ;
F_21 ( & V_39 -> V_67 ) ;
return V_40 ;
}
F_22 ( & V_39 -> V_67 ) ;
return 0 ;
}
static void F_23 ( struct V_36 * V_39 )
{
F_21 ( & V_39 -> V_67 ) ;
}
static int F_24 ( struct V_37 * V_38 , unsigned int V_82 ,
enum V_83 * V_84 )
{
if ( V_82 > 0 )
return - V_30 ;
* V_84 = V_85 ;
return 0 ;
}
static int F_25 ( struct V_37 * V_38 ,
struct V_86 * V_87 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
V_87 -> V_84 = V_85 ;
V_87 -> V_88 = V_89 ;
V_87 -> V_90 = V_91 ;
V_87 -> V_92 = 720 ;
V_87 -> V_93 = V_39 -> V_44 & V_94 ? 480 : 576 ;
return 0 ;
}
static int F_26 ( struct V_37 * V_38 ,
struct V_95 * V_96 )
{
V_96 -> V_97 = V_98 | V_99 |
V_100 ;
V_96 -> type = V_101 ;
return 0 ;
}
static void F_27 ( struct V_102 * V_103 )
{
struct V_36 * V_39 = F_7 ( V_103 , struct V_36 ,
V_103 ) ;
struct V_32 * V_33 = F_10 ( & V_39 -> V_38 ) ;
T_2 V_104 ;
F_28 ( & V_39 -> V_41 ) ;
F_13 ( V_33 , V_105 ,
V_106 ) ;
V_104 = F_5 ( V_33 , V_107 ) ;
F_13 ( V_33 , V_108 , V_104 ) ;
F_13 ( V_33 , V_105 , 0 ) ;
if ( V_104 & V_109 && V_39 -> V_42 )
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
F_11 ( & V_39 -> V_41 ) ;
F_29 ( V_39 -> V_43 ) ;
}
static T_4 F_30 ( int V_43 , void * V_110 )
{
struct V_36 * V_39 = V_110 ;
F_31 ( & V_39 -> V_103 ) ;
F_32 ( V_39 -> V_43 ) ;
return V_111 ;
}
static int F_33 ( struct V_32 * V_33 , struct V_36 * V_39 )
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
V_112 ,
V_113 ) ;
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
V_114 ,
V_115 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 ,
V_116 ,
V_117 ) ;
if ( V_48 < 0 )
return V_48 ;
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
if ( V_39 -> V_43 > 0 ) {
V_48 = F_34 ( V_39 -> V_43 , F_30 , 0 , V_118 ,
V_39 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_13 ( V_33 , V_105 ,
V_106 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_119 ,
V_120 |
V_121 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_122 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_123 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_124 ,
V_109 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_125 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_105 ,
0 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static int F_35 ( struct V_32 * V_33 ,
const struct V_126 * V_57 )
{
struct V_36 * V_39 ;
struct V_37 * V_38 ;
int V_48 ;
if ( ! F_36 ( V_33 -> V_127 , V_128 ) )
return - V_129 ;
F_37 ( V_33 , L_1 ,
V_33 -> V_130 , V_33 -> V_127 -> V_131 ) ;
V_39 = F_38 ( & V_33 -> V_132 , sizeof( * V_39 ) , V_133 ) ;
if ( V_39 == NULL ) {
V_48 = - V_134 ;
goto V_40;
}
V_39 -> V_43 = V_33 -> V_43 ;
F_39 ( & V_39 -> V_103 , F_27 ) ;
F_40 ( & V_39 -> V_41 ) ;
V_39 -> V_42 = true ;
V_39 -> V_45 = 0 ;
V_38 = & V_39 -> V_38 ;
F_41 ( V_38 , V_33 , & V_135 ) ;
V_48 = F_18 ( V_39 ) ;
if ( V_48 )
goto V_136;
V_48 = F_33 ( V_33 , V_39 ) ;
if ( V_48 )
goto V_137;
return 0 ;
V_137:
F_23 ( V_39 ) ;
V_136:
F_42 ( & V_39 -> V_41 ) ;
F_43 ( V_38 ) ;
V_40:
F_44 (KERN_ERR KBUILD_MODNAME L_2 , ret) ;
return V_48 ;
}
static int F_45 ( struct V_32 * V_33 )
{
struct V_37 * V_38 = F_46 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
if ( V_39 -> V_43 > 0 ) {
F_47 ( V_33 -> V_43 , V_39 ) ;
if ( F_48 ( & V_39 -> V_103 ) ) {
F_29 ( V_39 -> V_43 ) ;
}
}
F_42 ( & V_39 -> V_41 ) ;
F_43 ( V_38 ) ;
return 0 ;
}
static int F_49 ( struct V_138 * V_132 )
{
struct V_32 * V_33 = F_50 ( V_132 ) ;
int V_48 ;
V_48 = F_13 ( V_33 , V_139 ,
V_140 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_51 ( struct V_138 * V_132 )
{
struct V_32 * V_33 = F_50 ( V_132 ) ;
struct V_37 * V_38 = F_46 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_48 ;
V_48 = F_13 ( V_33 , V_139 ,
V_141 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_33 ( V_33 , V_39 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
