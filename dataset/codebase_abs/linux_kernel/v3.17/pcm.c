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
void T_1 * V_4 = V_2 -> V_4 ;
struct V_45 * V_45 ;
int V_46 , V_47 ;
unsigned long V_29 ;
T_2 V_6 ;
F_7 ( V_2 -> V_30 , L_1 , V_31 ) ;
switch ( F_11 ( V_43 ) ) {
case 16 :
break;
default:
return - V_41 ;
}
F_8 ( & V_2 -> V_35 , V_29 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_6 & V_48 )
V_45 = V_2 -> V_49 ;
else
V_45 = V_2 -> V_50 ;
V_46 = F_12 ( V_45 ) / V_2 -> V_51 /
F_13 ( V_43 ) / 2 - 1 ;
V_6 &= ~ ( V_52
<< V_53 ) ;
V_6 |= ( ( V_46 & V_52 )
<< V_53 ) ;
V_47 = V_2 -> V_51 - 1 ;
V_6 &= ~ ( V_54
<< V_55 ) ;
V_6 |= ( ( V_47 & V_54 )
<< V_55 ) ;
F_3 ( V_6 , V_4 + V_7 ) ;
F_9 ( & V_2 -> V_35 , V_29 ) ;
F_7 ( V_2 -> V_30 , L_2 ,
F_12 ( V_45 ) , V_2 -> V_51 ,
V_46 , V_47 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_28 ,
unsigned int V_56 )
{
struct V_1 * V_2 = F_6 ( V_28 ) ;
void T_1 * V_4 = V_2 -> V_4 ;
unsigned long V_29 ;
int V_57 = 0 ;
T_2 V_5 ;
F_7 ( V_2 -> V_30 , L_1 , V_31 ) ;
F_8 ( & V_2 -> V_35 , V_29 ) ;
V_5 = F_2 ( V_4 + V_8 ) ;
switch ( V_56 & V_58 ) {
case V_59 :
break;
default:
F_15 ( V_2 -> V_30 , L_3 ) ;
V_57 = - V_41 ;
goto exit;
}
switch ( V_56 & V_60 ) {
case V_61 :
break;
default:
F_15 ( V_2 -> V_30 , L_4 ) ;
V_57 = - V_41 ;
goto exit;
}
switch ( V_56 & V_62 ) {
case V_63 :
V_2 -> V_16 = 1 ;
break;
case V_64 :
V_2 -> V_16 = 0 ;
break;
default:
F_15 ( V_2 -> V_30 , L_5 ) ;
V_57 = - V_41 ;
goto exit;
}
switch ( V_56 & V_65 ) {
case V_66 :
V_5 |= V_67 ;
V_5 |= V_68 ;
break;
case V_69 :
V_5 &= ~ V_67 ;
V_5 &= ~ V_68 ;
break;
default:
F_15 ( V_2 -> V_30 , L_6 ) ;
V_57 = - V_41 ;
goto exit;
}
F_3 ( V_5 , V_4 + V_8 ) ;
exit:
F_9 ( & V_2 -> V_35 , V_29 ) ;
return V_57 ;
}
static int F_16 ( struct V_23 * V_28 ,
int V_70 , int div )
{
struct V_1 * V_2 = F_6 ( V_28 ) ;
switch ( V_70 ) {
case V_71 :
V_2 -> V_51 = div ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_17 ( struct V_23 * V_28 ,
int V_72 , unsigned int V_73 , int V_74 )
{
struct V_1 * V_2 = F_6 ( V_28 ) ;
void T_1 * V_4 = V_2 -> V_4 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
switch ( V_72 ) {
case V_75 :
V_6 |= V_48 ;
break;
case V_76 :
V_6 &= ~ V_48 ;
if ( F_12 ( V_2 -> V_50 ) != V_73 )
F_18 ( V_2 -> V_50 , V_73 ) ;
break;
default:
return - V_41 ;
}
F_3 ( V_6 , V_4 + V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
F_20 ( V_24 , V_2 -> V_77 , V_2 -> V_78 ) ;
return 0 ;
}
static int F_21 ( struct V_79 * V_80 )
{
struct V_1 * V_2 ;
struct V_81 * V_82 , * V_83 , * V_84 ;
struct V_85 * V_86 ;
int V_57 ;
if ( ( V_80 -> V_87 < 0 ) || V_80 -> V_87 >= F_22 ( V_88 ) ) {
F_15 ( & V_80 -> V_30 , L_7 , V_80 -> V_87 ) ;
return - V_41 ;
}
V_86 = V_80 -> V_30 . V_89 ;
V_83 = F_23 ( V_80 , V_90 , 0 ) ;
if ( ! V_83 ) {
F_15 ( & V_80 -> V_30 , L_8 ) ;
return - V_91 ;
}
V_84 = F_23 ( V_80 , V_90 , 1 ) ;
if ( ! V_84 ) {
F_15 ( & V_80 -> V_30 , L_9 ) ;
return - V_91 ;
}
V_82 = F_23 ( V_80 , V_92 , 0 ) ;
if ( ! V_82 ) {
F_15 ( & V_80 -> V_30 , L_10 ) ;
return - V_91 ;
}
if ( V_86 && V_86 -> V_93 && V_86 -> V_93 ( V_80 ) ) {
F_15 ( & V_80 -> V_30 , L_11 ) ;
return - V_41 ;
}
V_2 = & V_88 [ V_80 -> V_87 ] ;
V_2 -> V_30 = & V_80 -> V_30 ;
F_24 ( & V_2 -> V_35 ) ;
V_2 -> V_51 = 128 ;
V_2 -> V_50 = F_25 ( & V_80 -> V_30 , L_12 ) ;
if ( F_26 ( V_2 -> V_50 ) ) {
F_15 ( & V_80 -> V_30 , L_13 ) ;
V_57 = F_27 ( V_2 -> V_50 ) ;
goto V_94;
}
F_28 ( V_2 -> V_50 ) ;
F_29 ( & V_80 -> V_30 , V_2 ) ;
if ( ! F_30 ( V_82 -> V_95 ,
F_31 ( V_82 ) , L_14 ) ) {
F_15 ( & V_80 -> V_30 , L_15 ) ;
V_57 = - V_96 ;
goto V_97;
}
V_2 -> V_4 = F_32 ( V_82 -> V_95 , 0x100 ) ;
if ( V_2 -> V_4 == NULL ) {
F_15 ( & V_80 -> V_30 , L_16 ) ;
V_57 = - V_91 ;
goto V_98;
}
V_2 -> V_49 = F_25 ( & V_80 -> V_30 , L_17 ) ;
if ( F_26 ( V_2 -> V_49 ) ) {
F_15 ( & V_80 -> V_30 , L_18 ) ;
V_57 = - V_99 ;
goto V_100;
}
F_28 ( V_2 -> V_49 ) ;
V_101 [ V_80 -> V_87 ] . V_102 = V_82 -> V_95
+ V_103 ;
V_104 [ V_80 -> V_87 ] . V_102 = V_82 -> V_95
+ V_105 ;
V_101 [ V_80 -> V_87 ] . V_106 = V_84 -> V_95 ;
V_104 [ V_80 -> V_87 ] . V_106 = V_83 -> V_95 ;
V_2 -> V_78 = & V_101 [ V_80 -> V_87 ] ;
V_2 -> V_77 = & V_104 [ V_80 -> V_87 ] ;
F_33 ( & V_80 -> V_30 ) ;
V_57 = F_34 ( & V_80 -> V_30 , & V_107 ,
& V_108 [ V_80 -> V_87 ] , 1 ) ;
if ( V_57 != 0 ) {
F_15 ( & V_80 -> V_30 , L_19 , V_57 ) ;
goto V_109;
}
V_57 = F_35 ( & V_80 -> V_30 ) ;
if ( V_57 ) {
F_15 ( & V_80 -> V_30 , L_20 , V_57 ) ;
goto V_109;
}
return 0 ;
V_109:
F_36 ( V_2 -> V_49 ) ;
V_100:
F_37 ( V_2 -> V_4 ) ;
V_98:
F_38 ( V_82 -> V_95 , F_31 ( V_82 ) ) ;
V_97:
F_36 ( V_2 -> V_50 ) ;
V_94:
return V_57 ;
}
static int F_39 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = & V_88 [ V_80 -> V_87 ] ;
struct V_81 * V_82 ;
F_40 ( & V_80 -> V_30 ) ;
F_37 ( V_2 -> V_4 ) ;
V_82 = F_23 ( V_80 , V_92 , 0 ) ;
F_38 ( V_82 -> V_95 , F_31 ( V_82 ) ) ;
F_36 ( V_2 -> V_50 ) ;
F_36 ( V_2 -> V_49 ) ;
return 0 ;
}
