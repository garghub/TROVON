static int F_1 ( T_1 * V_1 )
{
return F_2 ( V_2 , V_3 ,
NULL , 0 , V_1 , 1 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
T_1 V_6 [ 3 ] ;
T_2 * V_7 = ( T_2 * ) & V_6 [ 1 ] ;
int V_8 = F_2 ( V_2 ,
V_9 , NULL , 0 , V_6 , 3 ) ;
V_5 -> V_10 = V_6 [ 0 ] ;
V_5 -> V_11 = * V_7 ++ ;
V_5 -> V_12 = * V_7 ++ ;
V_5 -> V_13 = * V_7 ++ ;
V_5 -> V_14 = * V_7 ++ ;
V_5 -> V_15 = * V_7 ++ ;
return V_8 ;
}
static int F_4 ( int V_16 )
{
return F_5 ( V_2 , V_16 ) ;
}
static void F_6 ( enum V_17 V_18 )
{
F_7 ( V_19 L_1 ) ;
switch ( V_18 ) {
case V_20 :
F_7 ( V_21 L_2 ) ;
break;
case V_22 :
F_7 ( V_21 L_3 ) ;
break;
case V_23 :
F_7 ( V_21 L_4 ) ;
break;
case V_24 :
F_7 ( V_21 L_5 ) ;
break;
default:
F_7 ( V_21 L_6 , V_18 ) ;
break;
}
}
static void F_8 ( struct V_25 * V_26 )
{
unsigned int V_27 ;
unsigned int V_28 ;
T_1 V_29 ;
T_2 V_30 ;
struct V_4 V_31 ;
int V_32 = 0 ;
int V_33 = 0 ;
int V_34 = 0 ;
if ( V_26 -> V_35 && F_9 ( V_36 , V_26 -> V_35 +
F_10 ( V_37 ) ) )
return;
V_27 = F_11 ( V_36 - V_26 -> V_35 ) ;
V_26 -> V_35 = V_36 ;
if ( F_1 ( & V_29 ) ) {
F_12 ( V_26 -> V_38 , L_7 ,
V_39 ) ;
return;
}
if ( F_13 ( V_40 , & V_30 ) ) {
F_12 ( V_26 -> V_38 , L_8 ,
V_39 ) ;
return;
}
if ( V_30 & V_41 ) {
V_26 -> V_42 = V_43 ;
V_32 = 1 ;
} else {
V_26 -> V_42 = V_44 ;
V_26 -> V_45 = V_46 ;
V_26 -> V_47 = V_48 ;
}
if ( V_32 ) {
if ( V_30 & V_49 ) {
V_26 -> V_45 = V_50 ;
V_26 -> V_47 = V_51 ;
F_6 ( V_20 ) ;
V_34 = 1 ;
} else if ( V_30 & V_52 ) {
V_26 -> V_45 = V_50 ;
V_26 -> V_47 = V_51 ;
F_6 ( V_24 ) ;
V_34 = 1 ;
} else if ( V_30 & V_53 ) {
V_26 -> V_45 = V_54 ;
V_26 -> V_47 = V_51 ;
F_6 ( V_23 ) ;
V_34 = 1 ;
} else {
V_26 -> V_45 = V_55 ;
}
}
if ( V_30 & V_56 ) {
V_26 -> V_57 = V_58 ;
V_33 = 1 ;
} else {
V_26 -> V_57 = V_59 ;
V_26 -> V_60 = V_46 ;
}
if ( V_33 ) {
if ( V_30 & V_61 ) {
V_26 -> V_60 = V_50 ;
F_6 ( V_22 ) ;
} else {
V_26 -> V_60 = V_55 ;
}
}
V_28 = V_29 & V_62 ;
if ( ! V_26 -> V_63 ) {
if ( F_3 ( & V_31 ) ) {
F_12 ( V_26 -> V_38 , L_7 ,
V_39 ) ;
return;
}
V_26 -> V_64 = V_31 . V_10 ;
}
if ( V_32 && ! V_34 ) {
if ( V_30 & V_65 ) {
V_26 -> V_47 = V_66 ;
V_26 -> V_64 = V_28 ;
} else if ( V_29 & V_67 ) {
V_26 -> V_47 = V_68 ;
} else {
V_26 -> V_47 = V_69 ;
}
}
if ( V_26 -> V_63 && V_32 && ! V_34 ) {
if ( V_26 -> V_47 == V_68 ) {
if ( V_26 -> V_70 - V_28 ) {
V_26 -> V_71 = ( ( V_26 -> V_70 -
V_28 ) * 1000 * 60 ) /
V_27 ;
}
} else if ( V_26 -> V_47 == V_69 ) {
if ( V_28 - V_26 -> V_70 ) {
V_26 -> V_71 = ( ( V_28 -
V_26 -> V_70 ) * 1000 * 60 ) /
V_27 ;
}
} else
V_26 -> V_71 = 0 ;
} else {
V_26 -> V_71 = - 1 ;
}
if ( V_32 && ! V_34 )
V_26 -> V_70 = V_28 ;
else
V_26 -> V_70 = - 1 ;
V_26 -> V_63 = V_72 ;
}
static int F_14 ( struct V_73 * V_74 ,
enum V_75 V_76 ,
union V_77 * V_78 )
{
struct V_25 * V_26 = F_15 ( V_74 ,
struct V_25 , V_79 ) ;
F_8 ( V_26 ) ;
switch ( V_76 ) {
case V_80 :
V_78 -> V_81 = V_26 -> V_57 ;
break;
case V_82 :
V_78 -> V_81 = V_26 -> V_60 ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static inline unsigned long F_16 ( unsigned long V_84 )
{
return ( V_84 * 1000 ) / 3600 ;
}
static int F_17 ( struct V_73 * V_74 ,
enum V_75 V_76 ,
union V_77 * V_78 )
{
struct V_25 * V_26 = F_15 ( V_74 ,
struct V_25 , V_85 ) ;
F_8 ( V_26 ) ;
switch ( V_76 ) {
case V_86 :
V_78 -> V_81 = V_26 -> V_47 ;
break;
case V_82 :
V_78 -> V_81 = V_26 -> V_45 ;
break;
case V_80 :
V_78 -> V_81 = V_26 -> V_42 ;
break;
case V_87 :
V_78 -> V_81 = F_16 ( V_26 -> V_70 ) ;
break;
case V_88 :
V_78 -> V_81 = F_16 ( V_26 -> V_64 ) ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static void F_18 ( struct V_89 * V_90 )
{
struct V_25 * V_26 = F_15 ( V_90 ,
struct V_25 , V_91 . V_90 ) ;
F_8 ( V_26 ) ;
F_19 ( V_26 -> V_92 , & V_26 -> V_91 , V_93 * 10 ) ;
}
static int F_20 ( struct V_25 * V_26 ,
enum V_94 V_95 )
{
int V_96 ;
switch ( V_95 ) {
case V_97 :
V_96 = F_4 ( V_98 ) ;
break;
case V_99 :
V_96 = F_4 ( V_100 ) ;
break;
default:
F_12 ( V_26 -> V_38 , L_9
L_10 , V_39 ) ;
return - V_83 ;
}
if ( V_96 ) {
F_12 ( V_26 -> V_38 , L_8 ,
V_39 ) ;
return V_96 ;
}
return 0 ;
}
static T_3 F_21 ( int V_101 , void * V_38 )
{
struct V_25 * V_26 = V_38 ;
F_22 ( & V_26 -> V_102 ) ;
return V_103 ;
}
static void F_23 ( struct V_89 * V_90 )
{
struct V_25 * V_26 = F_15 ( V_90 ,
struct V_25 , V_102 ) ;
enum V_94 V_95 ;
T_2 V_30 ;
if ( F_13 ( V_40 , & V_30 ) ) {
F_12 ( V_26 -> V_38 , L_8 ,
V_39 ) ;
return;
}
if ( V_30 & V_41 ) {
V_26 -> V_42 = V_43 ;
} else {
V_26 -> V_42 = V_44 ;
V_26 -> V_45 = V_46 ;
V_26 -> V_47 = V_48 ;
return;
}
if ( V_30 & V_104 ) {
V_26 -> V_45 = V_46 ;
V_26 -> V_47 = V_51 ;
V_26 -> V_60 = V_46 ;
F_6 ( V_105 ) ;
return;
} else {
V_26 -> V_45 = V_55 ;
V_26 -> V_60 = V_55 ;
}
if ( V_30 & V_65 ) {
T_1 V_29 ;
V_26 -> V_47 = V_66 ;
if ( F_1 ( & V_29 ) ) {
F_12 ( V_26 -> V_38 , L_11
L_12 , V_39 ) ;
return;
}
V_26 -> V_64 = V_29 &
V_62 ;
return;
}
if ( V_30 & V_56 ) {
V_26 -> V_57 = V_58 ;
} else {
V_26 -> V_57 = V_59 ;
V_26 -> V_60 = V_46 ;
return;
}
#if 0
retval = langwell_udc_maxpower(&power);
if (retval) {
dev_warn(pbi->dev,
"%s(): usb otg power query failed with error code %d\n",
__func__, retval);
return;
}
if (power >= 500)
chrg = BATT_USBOTG_500MA_CHARGE;
else
#endif
V_95 = V_99 ;
if ( F_20 ( V_26 , V_95 ) ) {
F_12 ( V_26 -> V_38 ,
L_13 , V_39 ) ;
return;
}
F_24 ( V_26 -> V_38 ,
L_14 ,
V_39 ) ;
}
static T_4 int F_25 ( int V_106 , struct V_107 * V_38 )
{
int V_96 = 0 ;
struct V_25 * V_26 ;
F_24 ( V_38 , L_15 ) ;
V_26 = F_26 ( sizeof( * V_26 ) , V_108 ) ;
if ( ! V_26 ) {
F_27 ( V_38 , L_16 ,
V_39 ) ;
return - V_109 ;
}
V_26 -> V_38 = V_38 ;
V_26 -> V_106 = V_106 ;
F_28 ( V_38 , V_26 ) ;
F_29 ( & V_26 -> V_102 , F_23 ) ;
F_30 ( & V_26 -> V_91 , F_18 ) ;
V_26 -> V_92 =
F_31 ( F_32 ( V_38 ) ) ;
if ( ! V_26 -> V_92 ) {
F_27 ( V_38 , L_17 , V_39 ) ;
V_96 = - V_110 ;
goto V_111;
}
V_96 = F_33 ( V_26 -> V_106 , F_21 ,
0 , V_112 , V_26 ) ;
if ( V_96 ) {
F_27 ( V_38 , L_18 , V_39 ) ;
goto V_113;
}
V_26 -> V_85 . V_114 = L_19 ;
V_26 -> V_85 . type = V_115 ;
V_26 -> V_85 . V_116 = V_117 ;
V_26 -> V_85 . V_118 = F_34 ( V_117 ) ;
V_26 -> V_85 . V_119 = F_17 ;
V_96 = F_35 ( V_38 , & V_26 -> V_85 ) ;
if ( V_96 ) {
F_27 ( V_38 ,
L_20 ,
V_39 ) ;
goto V_120;
}
F_24 ( V_38 , L_21
L_22 ,
V_39 ) ;
F_19 ( V_26 -> V_92 , & V_26 -> V_91 , V_93 * 1 ) ;
V_26 -> V_79 . V_114 = L_23 ;
V_26 -> V_79 . type = V_121 ;
V_26 -> V_79 . V_116 = V_122 ;
V_26 -> V_79 . V_118 = F_34 ( V_122 ) ;
V_26 -> V_79 . V_119 = F_14 ;
V_96 = F_35 ( V_38 , & V_26 -> V_79 ) ;
if ( V_96 ) {
F_27 ( V_38 ,
L_24 ,
V_39 ) ;
goto V_123;
}
if ( V_124 )
F_7 ( V_125 L_25
L_22 ,
V_39 ) ;
return V_96 ;
V_123:
F_36 ( & V_26 -> V_85 ) ;
V_120:
F_37 ( & V_26 -> V_91 ) ;
V_113:
F_38 ( V_26 -> V_92 ) ;
V_111:
F_39 ( V_26 ) ;
return V_96 ;
}
static int T_4 F_40 ( struct V_126 * V_127 )
{
return F_25 ( V_127 -> V_101 , & V_127 -> V_38 ) ;
}
static int T_5 F_41 ( struct V_126 * V_127 )
{
struct V_25 * V_26 = F_42 ( & V_127 -> V_38 ) ;
F_43 ( V_26 -> V_106 , V_26 ) ;
F_37 ( & V_26 -> V_91 ) ;
F_38 ( V_26 -> V_92 ) ;
F_36 ( & V_26 -> V_79 ) ;
F_36 ( & V_26 -> V_85 ) ;
F_44 ( & V_26 -> V_102 ) ;
F_39 ( V_26 ) ;
return 0 ;
}
static int T_6 F_45 ( void )
{
return F_46 ( & V_128 ) ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_128 ) ;
}
