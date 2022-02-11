static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_4 ;
T_2 V_5 , V_6 ;
V_6 = F_2 ( V_4 + V_7 ) ;
V_5 = F_2 ( V_4 + V_8 ) ;
V_5 &= ~ ( V_9
<< V_10 ) ;
if ( V_3 ) {
V_5 |= V_11 ;
V_5 |= V_12 ;
V_5 |= V_13 ;
V_5 |= ( 0x4 << V_10 ) ;
V_6 |= V_14 ;
} else {
V_5 &= ~ V_11 ;
V_5 &= ~ V_12 ;
if ( ! ( V_5 & V_15 ) ) {
V_5 &= ~ V_13 ;
if ( ! V_2 -> V_16 )
V_6 |= V_14 ;
}
}
F_3 ( V_6 , V_4 + V_7 ) ;
F_3 ( V_5 , V_4 + V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_4 ;
T_2 V_5 , V_6 ;
V_5 = F_2 ( V_4 + V_8 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
V_5 &= ~ ( V_17
<< V_18 ) ;
if ( V_3 ) {
V_5 |= V_19 ;
V_5 |= V_15 ;
V_5 |= V_13 ;
V_5 |= ( 0x20 << V_18 ) ;
V_6 |= V_14 ;
} else {
V_5 &= ~ V_19 ;
V_5 &= ~ V_15 ;
if ( ! ( V_5 & V_12 ) ) {
V_5 &= ~ V_13 ;
if ( ! V_2 -> V_16 )
V_6 |= V_14 ;
}
}
F_3 ( V_6 , V_4 + V_7 ) ;
F_3 ( V_5 , V_4 + V_8 ) ;
}
static int F_5 ( struct V_20 * V_21 , int V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
struct V_1 * V_2 = F_6 ( V_26 -> V_28 ) ;
unsigned long V_29 ;
F_7 ( V_2 -> V_30 , L_1 , V_31 ) ;
switch ( V_22 ) {
case V_32 :
case V_33 :
case V_34 :
F_8 ( & V_2 -> V_35 , V_29 ) ;
if ( V_21 -> V_36 == V_37 )
F_4 ( V_2 , 1 ) ;
else
F_1 ( V_2 , 1 ) ;
F_9 ( & V_2 -> V_35 , V_29 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
F_8 ( & V_2 -> V_35 , V_29 ) ;
if ( V_21 -> V_36 == V_37 )
F_4 ( V_2 , 0 ) ;
else
F_1 ( V_2 , 0 ) ;
F_9 ( & V_2 -> V_35 , V_29 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_42 * V_43 ,
struct V_23 * V_44 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
struct V_1 * V_2 = F_6 ( V_26 -> V_28 ) ;
struct V_45 * V_46 ;
void T_1 * V_4 = V_2 -> V_4 ;
struct V_47 * V_47 ;
int V_48 , V_49 ;
unsigned long V_29 ;
T_2 V_6 ;
F_7 ( V_2 -> V_30 , L_1 , V_31 ) ;
if ( V_21 -> V_36 == V_50 )
V_46 = V_2 -> V_51 ;
else
V_46 = V_2 -> V_52 ;
F_11 ( V_26 -> V_28 , V_21 , V_46 ) ;
switch ( F_12 ( V_43 ) ) {
case V_53 :
break;
default:
return - V_41 ;
}
F_8 ( & V_2 -> V_35 , V_29 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_6 & V_54 )
V_47 = V_2 -> V_55 ;
else
V_47 = V_2 -> V_56 ;
V_48 = F_13 ( V_47 ) / V_2 -> V_57 /
F_14 ( V_43 ) / 2 - 1 ;
V_6 &= ~ ( V_58
<< V_59 ) ;
V_6 |= ( ( V_48 & V_58 )
<< V_59 ) ;
V_49 = V_2 -> V_57 - 1 ;
V_6 &= ~ ( V_60
<< V_61 ) ;
V_6 |= ( ( V_49 & V_60 )
<< V_61 ) ;
F_3 ( V_6 , V_4 + V_7 ) ;
F_9 ( & V_2 -> V_35 , V_29 ) ;
F_7 ( V_2 -> V_30 , L_2 ,
F_13 ( V_47 ) , V_2 -> V_57 ,
V_48 , V_49 ) ;
return 0 ;
}
static int F_15 ( struct V_23 * V_28 ,
unsigned int V_62 )
{
struct V_1 * V_2 = F_6 ( V_28 ) ;
void T_1 * V_4 = V_2 -> V_4 ;
unsigned long V_29 ;
int V_63 = 0 ;
T_2 V_5 ;
F_7 ( V_2 -> V_30 , L_1 , V_31 ) ;
F_8 ( & V_2 -> V_35 , V_29 ) ;
V_5 = F_2 ( V_4 + V_8 ) ;
switch ( V_62 & V_64 ) {
case V_65 :
break;
default:
F_16 ( V_2 -> V_30 , L_3 ) ;
V_63 = - V_41 ;
goto exit;
}
switch ( V_62 & V_66 ) {
case V_67 :
break;
default:
F_16 ( V_2 -> V_30 , L_4 ) ;
V_63 = - V_41 ;
goto exit;
}
switch ( V_62 & V_68 ) {
case V_69 :
V_2 -> V_16 = 1 ;
break;
case V_70 :
V_2 -> V_16 = 0 ;
break;
default:
F_16 ( V_2 -> V_30 , L_5 ) ;
V_63 = - V_41 ;
goto exit;
}
switch ( V_62 & V_71 ) {
case V_72 :
V_5 |= V_73 ;
V_5 |= V_74 ;
break;
case V_75 :
V_5 &= ~ V_73 ;
V_5 &= ~ V_74 ;
break;
default:
F_16 ( V_2 -> V_30 , L_6 ) ;
V_63 = - V_41 ;
goto exit;
}
F_3 ( V_5 , V_4 + V_8 ) ;
exit:
F_9 ( & V_2 -> V_35 , V_29 ) ;
return V_63 ;
}
static int F_17 ( struct V_23 * V_28 ,
int V_76 , int div )
{
struct V_1 * V_2 = F_6 ( V_28 ) ;
switch ( V_76 ) {
case V_77 :
V_2 -> V_57 = div ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_18 ( struct V_23 * V_28 ,
int V_78 , unsigned int V_79 , int V_80 )
{
struct V_1 * V_2 = F_6 ( V_28 ) ;
void T_1 * V_4 = V_2 -> V_4 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
switch ( V_78 ) {
case V_81 :
V_6 |= V_54 ;
break;
case V_82 :
V_6 &= ~ V_54 ;
if ( F_13 ( V_2 -> V_56 ) != V_79 )
F_19 ( V_2 -> V_56 , V_79 ) ;
break;
default:
return - V_41 ;
}
F_3 ( V_6 , V_4 + V_7 ) ;
return 0 ;
}
static T_3 int F_20 ( struct V_83 * V_84 )
{
struct V_1 * V_2 ;
struct V_85 * V_86 , * V_87 , * V_88 ;
struct V_89 * V_90 ;
int V_63 ;
if ( ( V_84 -> V_91 < 0 ) || V_84 -> V_91 >= F_21 ( V_92 ) ) {
F_16 ( & V_84 -> V_30 , L_7 , V_84 -> V_91 ) ;
return - V_41 ;
}
V_90 = V_84 -> V_30 . V_93 ;
V_87 = F_22 ( V_84 , V_94 , 0 ) ;
if ( ! V_87 ) {
F_16 ( & V_84 -> V_30 , L_8 ) ;
return - V_95 ;
}
V_88 = F_22 ( V_84 , V_94 , 1 ) ;
if ( ! V_88 ) {
F_16 ( & V_84 -> V_30 , L_9 ) ;
return - V_95 ;
}
V_86 = F_22 ( V_84 , V_96 , 0 ) ;
if ( ! V_86 ) {
F_16 ( & V_84 -> V_30 , L_10 ) ;
return - V_95 ;
}
if ( V_90 && V_90 -> V_97 && V_90 -> V_97 ( V_84 ) ) {
F_16 ( & V_84 -> V_30 , L_11 ) ;
return - V_41 ;
}
V_2 = & V_92 [ V_84 -> V_91 ] ;
V_2 -> V_30 = & V_84 -> V_30 ;
F_23 ( & V_2 -> V_35 ) ;
V_2 -> V_57 = 128 ;
V_2 -> V_56 = F_24 ( & V_84 -> V_30 , L_12 ) ;
if ( F_25 ( V_2 -> V_56 ) ) {
F_16 ( & V_84 -> V_30 , L_13 ) ;
V_63 = F_26 ( V_2 -> V_56 ) ;
goto V_98;
}
F_27 ( V_2 -> V_56 ) ;
F_28 ( & V_84 -> V_30 , V_2 ) ;
if ( ! F_29 ( V_86 -> V_99 ,
F_30 ( V_86 ) , L_14 ) ) {
F_16 ( & V_84 -> V_30 , L_15 ) ;
V_63 = - V_100 ;
goto V_101;
}
V_2 -> V_4 = F_31 ( V_86 -> V_99 , 0x100 ) ;
if ( V_2 -> V_4 == NULL ) {
F_16 ( & V_84 -> V_30 , L_16 ) ;
V_63 = - V_95 ;
goto V_102;
}
V_2 -> V_55 = F_24 ( & V_84 -> V_30 , L_17 ) ;
if ( F_25 ( V_2 -> V_55 ) ) {
F_16 ( & V_84 -> V_30 , L_18 ) ;
V_63 = - V_103 ;
goto V_104;
}
F_27 ( V_2 -> V_55 ) ;
V_105 [ V_84 -> V_91 ] . V_106 = V_86 -> V_99
+ V_107 ;
V_108 [ V_84 -> V_91 ] . V_106 = V_86 -> V_99
+ V_109 ;
V_105 [ V_84 -> V_91 ] . V_110 = V_88 -> V_99 ;
V_108 [ V_84 -> V_91 ] . V_110 = V_87 -> V_99 ;
V_2 -> V_52 = & V_105 [ V_84 -> V_91 ] ;
V_2 -> V_51 = & V_108 [ V_84 -> V_91 ] ;
F_32 ( & V_84 -> V_30 ) ;
V_63 = F_33 ( & V_84 -> V_30 , & V_111 [ V_84 -> V_91 ] ) ;
if ( V_63 != 0 ) {
F_16 ( & V_84 -> V_30 , L_19 , V_63 ) ;
goto V_112;
}
return 0 ;
V_112:
F_34 ( V_2 -> V_55 ) ;
F_35 ( V_2 -> V_55 ) ;
V_104:
F_36 ( V_2 -> V_4 ) ;
V_102:
F_37 ( V_86 -> V_99 , F_30 ( V_86 ) ) ;
V_101:
F_34 ( V_2 -> V_56 ) ;
F_35 ( V_2 -> V_56 ) ;
V_98:
return V_63 ;
}
static T_4 int F_38 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = & V_92 [ V_84 -> V_91 ] ;
struct V_85 * V_86 ;
F_39 ( & V_84 -> V_30 ) ;
F_40 ( & V_84 -> V_30 ) ;
F_36 ( V_2 -> V_4 ) ;
V_86 = F_22 ( V_84 , V_96 , 0 ) ;
F_37 ( V_86 -> V_99 , F_30 ( V_86 ) ) ;
F_34 ( V_2 -> V_56 ) ;
F_34 ( V_2 -> V_55 ) ;
F_35 ( V_2 -> V_55 ) ;
F_35 ( V_2 -> V_56 ) ;
return 0 ;
}
