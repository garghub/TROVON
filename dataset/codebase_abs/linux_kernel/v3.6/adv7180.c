static T_1 F_1 ( T_2 V_1 )
{
switch ( V_1 & V_2 ) {
case V_3 :
return V_4 ;
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
return V_16 | V_17 ;
case V_18 :
return V_14 ;
default:
return V_19 ;
}
}
static int F_2 ( T_1 V_20 )
{
if ( V_20 == V_10 )
return V_21 ;
if ( V_20 == V_6 )
return V_22 ;
if ( V_20 == V_17 )
return V_23 ;
if ( V_20 == V_8 )
return V_24 ;
if ( V_20 == V_16 )
return V_25 ;
if ( V_20 & V_12 )
return V_26 ;
if ( V_20 & V_4 )
return V_27 ;
if ( V_20 & V_14 )
return V_28 ;
return - V_29 ;
}
static T_3 F_3 ( T_2 V_1 )
{
if ( ! ( V_1 & V_30 ) )
return V_31 ;
return 0 ;
}
static int F_4 ( struct V_32 * V_33 , T_3 * V_34 ,
T_1 * V_20 )
{
int V_1 = F_5 ( V_33 , V_35 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( V_34 )
* V_34 = F_3 ( V_1 ) ;
if ( V_20 )
* V_20 = F_1 ( V_1 ) ;
return 0 ;
}
static inline struct V_36 * F_6 ( struct V_37 * V_38 )
{
return F_7 ( V_38 , struct V_36 , V_38 ) ;
}
static int F_8 ( struct V_37 * V_38 , T_1 * V_20 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_40 = F_9 ( & V_39 -> V_41 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_39 -> V_42 || V_39 -> V_43 > 0 )
* V_20 = V_39 -> V_44 ;
else
V_40 = F_4 ( F_10 ( V_38 ) , NULL , V_20 ) ;
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
static int F_15 ( struct V_37 * V_38 ,
struct V_52 * V_53 )
{
struct V_32 * V_33 = F_10 ( V_38 ) ;
return F_16 ( V_33 , V_53 , V_54 , 0 ) ;
}
static int F_17 ( struct V_37 * V_38 , T_1 V_20 )
{
struct V_36 * V_39 = F_6 ( V_38 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
int V_48 = F_9 ( & V_39 -> V_41 ) ;
if ( V_48 )
return V_48 ;
if ( V_20 == V_55 ) {
V_48 =
F_13 ( V_33 , V_51 ,
V_56
| V_39 -> V_45 ) ;
if ( V_48 < 0 )
goto V_50;
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
V_39 -> V_42 = true ;
} else {
V_48 = F_2 ( V_20 ) ;
if ( V_48 < 0 )
goto V_50;
V_48 = F_13 ( V_33 ,
V_51 ,
V_48 | V_39 -> V_45 ) ;
if ( V_48 < 0 )
goto V_50;
V_39 -> V_44 = V_20 ;
V_39 -> V_42 = false ;
}
V_48 = 0 ;
V_50:
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_18 ( struct V_57 * V_58 )
{
struct V_37 * V_38 = F_19 ( V_58 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
struct V_32 * V_33 = F_10 ( V_38 ) ;
int V_48 = F_9 ( & V_39 -> V_41 ) ;
int V_59 ;
if ( V_48 )
return V_48 ;
V_59 = V_58 -> V_59 ;
switch ( V_58 -> V_60 ) {
case V_61 :
V_48 = F_13 ( V_33 , V_62 , V_59 ) ;
break;
case V_63 :
V_48 = F_13 ( V_33 , V_64 , - V_59 ) ;
break;
case V_65 :
V_48 = F_13 ( V_33 , V_66 , V_59 ) ;
break;
case V_67 :
V_48 = F_13 ( V_33 , V_68 ,
V_59 ) ;
if ( V_48 < 0 )
break;
V_48 = F_13 ( V_33 , V_69 ,
V_59 ) ;
break;
default:
V_48 = - V_29 ;
}
F_11 ( & V_39 -> V_41 ) ;
return V_48 ;
}
static int F_20 ( struct V_36 * V_39 )
{
F_21 ( & V_39 -> V_70 , 4 ) ;
F_22 ( & V_39 -> V_70 , & V_71 ,
V_61 , V_72 ,
V_73 , 1 , V_74 ) ;
F_22 ( & V_39 -> V_70 , & V_71 ,
V_65 , V_75 ,
V_76 , 1 , V_77 ) ;
F_22 ( & V_39 -> V_70 , & V_71 ,
V_67 , V_78 ,
V_79 , 1 , V_80 ) ;
F_22 ( & V_39 -> V_70 , & V_71 ,
V_63 , V_81 ,
V_82 , 1 , V_83 ) ;
V_39 -> V_38 . V_84 = & V_39 -> V_70 ;
if ( V_39 -> V_70 . error ) {
int V_40 = V_39 -> V_70 . error ;
F_23 ( & V_39 -> V_70 ) ;
return V_40 ;
}
F_24 ( & V_39 -> V_70 ) ;
return 0 ;
}
static void F_25 ( struct V_36 * V_39 )
{
F_23 ( & V_39 -> V_70 ) ;
}
static void F_26 ( struct V_85 * V_86 )
{
struct V_36 * V_39 = F_7 ( V_86 , struct V_36 ,
V_86 ) ;
struct V_32 * V_33 = F_10 ( & V_39 -> V_38 ) ;
T_2 V_87 ;
F_27 ( & V_39 -> V_41 ) ;
F_13 ( V_33 , V_88 ,
V_89 ) ;
V_87 = F_5 ( V_33 , V_90 ) ;
F_13 ( V_33 , V_91 , V_87 ) ;
F_13 ( V_33 , V_88 , 0 ) ;
if ( V_87 & V_92 && V_39 -> V_42 )
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
F_11 ( & V_39 -> V_41 ) ;
F_28 ( V_39 -> V_43 ) ;
}
static T_4 F_29 ( int V_43 , void * V_93 )
{
struct V_36 * V_39 = V_93 ;
F_30 ( & V_39 -> V_86 ) ;
F_31 ( V_39 -> V_43 ) ;
return V_94 ;
}
static int F_32 ( struct V_32 * V_33 , struct V_36 * V_39 )
{
int V_48 ;
if ( V_39 -> V_42 ) {
V_48 =
F_13 ( V_33 , V_51 ,
V_56
| V_39 -> V_45 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 =
F_13 ( V_33 ,
V_95 ,
V_96 ) ;
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
V_97 ,
V_98 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 ,
V_99 ,
V_100 ) ;
if ( V_48 < 0 )
return V_48 ;
F_4 ( V_33 , NULL , & V_39 -> V_44 ) ;
if ( V_39 -> V_43 > 0 ) {
V_48 = F_33 ( V_39 -> V_43 , F_29 , 0 , V_101 ,
V_39 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_13 ( V_33 , V_88 ,
V_89 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_102 ,
V_103 |
V_104 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_105 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_106 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_107 ,
V_92 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_108 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_13 ( V_33 , V_88 ,
0 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static T_5 int F_34 ( struct V_32 * V_33 ,
const struct V_109 * V_60 )
{
struct V_36 * V_39 ;
struct V_37 * V_38 ;
int V_48 ;
if ( ! F_35 ( V_33 -> V_110 , V_111 ) )
return - V_112 ;
F_36 ( V_33 , L_1 ,
V_33 -> V_113 , V_33 -> V_110 -> V_114 ) ;
V_39 = F_37 ( sizeof( struct V_36 ) , V_115 ) ;
if ( V_39 == NULL ) {
V_48 = - V_116 ;
goto V_40;
}
V_39 -> V_43 = V_33 -> V_43 ;
F_38 ( & V_39 -> V_86 , F_26 ) ;
F_39 ( & V_39 -> V_41 ) ;
V_39 -> V_42 = true ;
V_39 -> V_45 = 0 ;
V_38 = & V_39 -> V_38 ;
F_40 ( V_38 , V_33 , & V_117 ) ;
V_48 = F_20 ( V_39 ) ;
if ( V_48 )
goto V_118;
V_48 = F_32 ( V_33 , V_39 ) ;
if ( V_48 )
goto V_119;
return 0 ;
V_119:
F_25 ( V_39 ) ;
V_118:
F_41 ( & V_39 -> V_41 ) ;
F_42 ( V_38 ) ;
F_43 ( V_39 ) ;
V_40:
F_44 (KERN_ERR KBUILD_MODNAME L_2 , ret) ;
return V_48 ;
}
static T_6 int F_45 ( struct V_32 * V_33 )
{
struct V_37 * V_38 = F_46 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
if ( V_39 -> V_43 > 0 ) {
F_47 ( V_33 -> V_43 , V_39 ) ;
if ( F_48 ( & V_39 -> V_86 ) ) {
F_28 ( V_39 -> V_43 ) ;
}
}
F_41 ( & V_39 -> V_41 ) ;
F_42 ( V_38 ) ;
F_43 ( F_6 ( V_38 ) ) ;
return 0 ;
}
static int F_49 ( struct V_32 * V_33 , T_7 V_39 )
{
int V_48 ;
V_48 = F_13 ( V_33 , V_120 ,
V_121 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_50 ( struct V_32 * V_33 )
{
struct V_37 * V_38 = F_46 ( V_33 ) ;
struct V_36 * V_39 = F_6 ( V_38 ) ;
int V_48 ;
V_48 = F_13 ( V_33 , V_120 ,
V_122 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_32 ( V_33 , V_39 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
