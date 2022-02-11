static inline T_1 F_1 ( struct V_1 * V_2 ,
const void T_2 * V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( F_3 ( V_2 -> V_5 ) )
V_4 = F_4 ( V_4 ) ;
else
V_4 = F_5 ( V_4 ) ;
F_6 () ;
return V_4 ;
}
static inline void F_7 ( struct V_1 * V_2 ,
T_1 V_4 , void T_2 * V_3 )
{
F_8 () ;
if ( F_3 ( V_2 -> V_5 ) )
V_4 = F_9 ( V_4 ) ;
else
V_4 = F_10 ( V_4 ) ;
F_11 ( V_4 , V_3 ) ;
}
static int F_12 ( struct V_6 * V_7 ,
int V_8 , unsigned int V_9 , int V_10 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
T_1 V_11 , V_12 ;
if ( V_10 == V_13 )
V_12 = V_14 ;
else
V_12 = V_15 ;
V_11 = F_1 ( V_2 , V_2 -> V_16 + V_12 ) ;
V_11 &= ~ V_17 ;
switch ( V_8 ) {
case V_18 :
V_11 |= V_19 ;
break;
case V_20 :
V_11 |= V_21 ;
break;
case V_22 :
V_11 |= V_23 ;
break;
case V_24 :
V_11 |= V_25 ;
break;
default:
return - V_26 ;
}
F_7 ( V_2 , V_11 , V_2 -> V_16 + V_12 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
int V_8 , unsigned int V_9 , int V_27 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
int V_28 ;
if ( V_27 == V_29 )
return 0 ;
V_28 = F_15 ( V_2 -> V_30 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( V_7 , V_8 , V_9 ,
V_13 ) ;
if ( V_28 ) {
F_16 ( V_7 -> V_31 , L_1 , V_28 ) ;
goto V_32;
}
V_28 = F_12 ( V_7 , V_8 , V_9 ,
V_33 ) ;
if ( V_28 ) {
F_16 ( V_7 -> V_31 , L_2 , V_28 ) ;
goto V_32;
}
V_32:
F_17 ( V_2 -> V_30 ) ;
return V_28 ;
}
static int F_18 ( struct V_6 * V_7 ,
unsigned int V_34 , int V_10 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
T_1 V_11 , V_35 , V_12 , V_36 ;
if ( V_10 == V_13 ) {
V_12 = V_14 ;
V_36 = V_37 ;
} else {
V_12 = V_15 ;
V_36 = V_38 ;
}
V_11 = F_1 ( V_2 , V_2 -> V_16 + V_12 ) ;
V_35 = F_1 ( V_2 , V_2 -> V_16 + V_36 ) ;
if ( V_2 -> V_39 )
V_35 &= ~ V_40 ;
else
V_35 |= V_40 ;
switch ( V_34 & V_41 ) {
case V_42 :
V_35 |= V_43 ;
break;
default:
return - V_26 ;
}
switch ( V_34 & V_44 ) {
case V_45 :
V_35 |= V_46 ;
V_11 &= ~ V_47 ;
break;
case V_48 :
V_35 &= ~ V_46 ;
V_11 &= ~ V_47 ;
break;
case V_49 :
V_35 |= V_46 ;
V_11 |= V_47 ;
break;
case V_50 :
V_35 &= ~ V_46 ;
V_11 |= V_47 ;
break;
default:
return - V_26 ;
}
switch ( V_34 & V_51 ) {
case V_52 :
V_11 |= V_53 ;
V_35 |= V_54 ;
break;
case V_55 :
V_11 &= ~ V_53 ;
V_35 &= ~ V_54 ;
break;
default:
return - V_26 ;
}
F_7 ( V_2 , V_11 , V_2 -> V_16 + V_12 ) ;
F_7 ( V_2 , V_35 , V_2 -> V_16 + V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , unsigned int V_34 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
int V_28 ;
V_28 = F_15 ( V_2 -> V_30 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_18 ( V_7 , V_34 , V_13 ) ;
if ( V_28 ) {
F_16 ( V_7 -> V_31 , L_3 , V_28 ) ;
goto V_32;
}
V_28 = F_18 ( V_7 , V_34 , V_33 ) ;
if ( V_28 ) {
F_16 ( V_7 -> V_31 , L_4 , V_28 ) ;
goto V_32;
}
V_32:
F_17 ( V_2 -> V_30 ) ;
return V_28 ;
}
static int F_20 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
T_1 V_35 , V_60 , V_61 , V_36 , V_62 , V_63 ;
unsigned int V_64 = F_21 ( V_59 ) ;
T_1 V_65 = F_22 ( F_23 ( V_59 ) ) ;
if ( V_57 -> V_66 == V_67 ) {
V_36 = V_37 ;
V_62 = V_68 ;
V_63 = V_69 ;
} else {
V_36 = V_38 ;
V_62 = V_70 ;
V_63 = V_71 ;
}
V_35 = F_1 ( V_2 , V_2 -> V_16 + V_36 ) ;
V_35 &= ~ V_72 ;
V_35 &= ~ V_73 ;
V_60 = F_1 ( V_2 , V_2 -> V_16 + V_62 ) ;
V_60 &= ~ V_74 ;
V_60 &= ~ V_75 ;
V_60 &= ~ V_76 ;
V_35 |= F_24 ( V_65 ) ;
V_60 |= F_25 ( V_65 ) ;
V_60 |= F_26 ( V_65 ) ;
V_60 &= ~ V_76 ;
if ( V_2 -> V_39 )
V_60 |= F_27 ( 0 ) ;
else
V_60 |= F_27 ( V_65 - 1 ) ;
V_35 |= F_28 ( V_64 ) ;
V_61 = ~ 0UL - ( ( 1 << V_64 ) - 1 ) ;
F_7 ( V_2 , V_35 , V_2 -> V_16 + V_36 ) ;
F_7 ( V_2 , V_60 , V_2 -> V_16 + V_62 ) ;
F_7 ( V_2 , V_61 , V_2 -> V_16 + V_63 ) ;
return 0 ;
}
static int F_29 ( struct V_56 * V_57 , int V_77 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
T_1 V_78 , V_79 , V_11 , V_80 , V_81 ;
V_11 = F_1 ( V_2 , V_2 -> V_16 + V_14 ) ;
V_11 &= ~ V_82 ;
F_7 ( V_2 , V_11 , V_2 -> V_16 + V_14 ) ;
V_11 = F_1 ( V_2 , V_2 -> V_16 + V_15 ) ;
V_11 |= V_82 ;
F_7 ( V_2 , V_11 , V_2 -> V_16 + V_15 ) ;
V_78 = F_1 ( V_2 , V_2 -> V_16 + V_83 ) ;
V_79 = F_1 ( V_2 , V_2 -> V_16 + V_84 ) ;
if ( V_57 -> V_66 == V_67 ) {
V_78 |= V_85 ;
V_79 &= ~ V_85 ;
V_81 = V_86 ;
} else {
V_79 |= V_85 ;
V_78 &= ~ V_85 ;
V_81 = V_87 ;
}
V_80 = F_1 ( V_2 , V_2 -> V_16 + V_81 ) ;
switch ( V_77 ) {
case V_88 :
case V_89 :
case V_90 :
V_78 |= V_91 ;
V_79 |= V_91 ;
V_80 |= V_92 ;
F_7 ( V_2 , V_80 , V_2 -> V_16 + V_81 ) ;
F_7 ( V_2 , V_79 , V_2 -> V_16 + V_84 ) ;
F_7 ( V_2 , V_78 , V_2 -> V_16 + V_83 ) ;
break;
case V_93 :
case V_94 :
case V_95 :
if ( ! ( V_7 -> V_96 || V_7 -> V_97 ) ) {
V_78 &= ~ V_91 ;
V_79 &= ~ V_91 ;
}
V_80 &= ~ V_92 ;
F_7 ( V_2 , V_78 , V_2 -> V_16 + V_83 ) ;
F_7 ( V_2 , V_79 , V_2 -> V_16 + V_84 ) ;
F_7 ( V_2 , V_80 , V_2 -> V_16 + V_81 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_30 ( struct V_56 * V_57 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
return F_15 ( V_2 -> V_30 ) ;
}
static void F_31 ( struct V_56 * V_57 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
F_17 ( V_2 -> V_30 ) ;
}
static int F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_33 ( V_7 -> V_31 ) ;
int V_28 ;
V_28 = F_15 ( V_2 -> V_30 ) ;
if ( V_28 )
return V_28 ;
F_7 ( V_2 , 0x0 , V_2 -> V_16 + V_84 ) ;
F_7 ( V_2 , 0x0 , V_2 -> V_16 + V_83 ) ;
F_7 ( V_2 , V_98 * 2 , V_2 -> V_16 + V_99 ) ;
F_7 ( V_2 , V_100 - 1 , V_2 -> V_16 + V_101 ) ;
F_17 ( V_2 -> V_30 ) ;
F_34 ( V_7 , & V_2 -> V_102 ,
& V_2 -> V_103 ) ;
F_35 ( V_7 , V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_104 * V_105 )
{
struct V_106 * V_107 = V_105 -> V_31 . V_108 ;
struct V_1 * V_2 ;
struct V_109 * V_110 ;
int V_28 ;
V_2 = F_37 ( & V_105 -> V_31 , sizeof( * V_2 ) , V_111 ) ;
if ( ! V_2 )
return - V_112 ;
V_110 = F_38 ( V_105 , V_113 , 0 ) ;
V_2 -> V_16 = F_39 ( & V_105 -> V_31 , V_110 ) ;
if ( F_40 ( V_2 -> V_16 ) )
return F_41 ( V_2 -> V_16 ) ;
V_2 -> V_30 = F_42 ( & V_105 -> V_31 , L_5 ) ;
if ( F_40 ( V_2 -> V_30 ) ) {
F_16 ( & V_105 -> V_31 , L_6 ) ;
return F_41 ( V_2 -> V_30 ) ;
}
V_2 -> V_103 . V_3 = V_110 -> V_114 + V_115 ;
V_2 -> V_102 . V_3 = V_110 -> V_114 + V_116 ;
V_2 -> V_103 . V_117 = V_100 ;
V_2 -> V_102 . V_117 = V_98 ;
V_2 -> V_5 = F_43 ( V_107 , L_7 ) ;
V_2 -> V_39 = F_43 ( V_107 , L_8 ) ;
F_44 ( V_105 , V_2 ) ;
V_28 = F_45 ( & V_105 -> V_31 , & V_118 ,
& V_119 , 1 ) ;
if ( V_28 )
return V_28 ;
return F_46 ( & V_105 -> V_31 , NULL ,
V_120 ) ;
}
