static int F_1 ( void T_1 * V_1 , unsigned V_2 )
{
T_2 V_3 , V_4 ;
V_3 = V_2 % V_5 ;
V_4 = ( V_2 / V_5 ) * 4 ;
return ! ! ( F_2 ( V_1 + V_4 ) & F_3 ( V_3 ) ) ;
}
static void F_4 ( void T_1 * V_1 , unsigned V_2 , int V_6 )
{
T_2 V_7 , V_3 , V_4 ;
V_3 = V_2 % V_5 ;
V_4 = ( V_2 / V_5 ) * 4 ;
V_7 = F_2 ( V_1 + V_4 ) ;
if ( V_6 )
V_7 |= F_3 ( V_3 ) ;
else
V_7 &= ~ F_3 ( V_3 ) ;
F_5 ( V_7 , V_1 + V_4 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
unsigned long V_14 ;
F_9 ( & V_13 -> V_15 , V_14 ) ;
F_4 ( V_13 -> V_16 , V_9 -> V_17 , 0x0 ) ;
F_10 ( V_9 -> V_17 , V_13 -> V_18 ) ;
F_11 ( & V_13 -> V_15 , V_14 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
unsigned long V_14 ;
F_9 ( & V_13 -> V_15 , V_14 ) ;
F_4 ( V_13 -> V_16 , V_9 -> V_17 , 0x0 ) ;
F_4 ( V_13 -> V_19 , V_9 -> V_17 , 0x1 ) ;
F_10 ( V_9 -> V_17 , V_13 -> V_18 ) ;
F_11 ( & V_13 -> V_15 , V_14 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
unsigned long V_14 ;
F_9 ( & V_13 -> V_15 , V_14 ) ;
F_4 ( V_13 -> V_16 , V_9 -> V_17 , 0x1 ) ;
F_14 ( V_9 -> V_17 , V_13 -> V_18 ) ;
F_11 ( & V_13 -> V_15 , V_14 ) ;
}
static int F_15 ( struct V_8 * V_9 , unsigned int type )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
int V_20 , V_21 ;
switch ( type ) {
case V_22 :
V_21 = V_23 ;
V_20 = V_24 ;
break;
case V_25 :
V_21 = V_23 ;
V_20 = V_26 ;
break;
case V_27 :
V_21 = V_28 ;
V_20 = V_24 ;
break;
case V_29 :
V_21 = V_28 ;
V_20 = V_26 ;
break;
default:
return - V_30 ;
}
F_4 ( V_13 -> V_31 , V_9 -> V_17 , V_21 ) ;
F_4 ( V_13 -> V_32 , V_9 -> V_17 , V_20 ) ;
return 0 ;
}
static void F_16 ( struct V_33 * V_34 )
{
struct V_12 * V_13 = F_17 ( V_34 ) ;
struct V_35 * V_36 = F_18 ( V_34 ) ;
int V_2 , V_37 ;
T_2 V_38 ;
V_37 = - 1 ;
V_38 = 0 ;
F_19 ( V_36 , V_34 ) ;
F_20 (gpio, priv->gpio_enabled_mask, XLP_MAX_NR_GPIO) {
if ( V_37 != V_2 / V_5 ) {
V_37 = V_2 / V_5 ;
V_38 = F_2 ( V_13 -> V_19 + V_37 * 4 ) ;
}
if ( V_38 & F_3 ( V_2 % V_5 ) )
F_21 ( F_22 (
V_13 -> V_39 . V_40 , V_2 ) ) ;
}
F_23 ( V_36 , V_34 ) ;
}
static int F_24 ( struct V_10 * V_11 , unsigned V_2 , int V_6 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
F_25 ( V_2 >= V_11 -> V_41 ) ;
F_4 ( V_13 -> V_42 , V_2 , 0x1 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 , unsigned V_2 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
F_25 ( V_2 >= V_11 -> V_41 ) ;
F_4 ( V_13 -> V_42 , V_2 , 0x0 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 , unsigned V_2 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
F_25 ( V_2 >= V_11 -> V_41 ) ;
return F_1 ( V_13 -> V_43 , V_2 ) ;
}
static void F_28 ( struct V_10 * V_11 , unsigned V_2 , int V_6 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
F_25 ( V_2 >= V_11 -> V_41 ) ;
F_4 ( V_13 -> V_43 , V_2 , V_6 ) ;
}
static int F_29 ( struct V_44 * V_45 )
{
struct V_10 * V_11 ;
struct V_46 * V_47 ;
struct V_12 * V_13 ;
void T_1 * V_48 ;
int V_49 , V_50 , V_51 ;
int V_41 ;
T_2 V_52 ;
V_47 = F_30 ( V_45 , V_53 , 0 ) ;
if ( ! V_47 )
return - V_54 ;
V_13 = F_31 ( & V_45 -> V_55 , sizeof( * V_13 ) , V_56 ) ;
if ( ! V_13 )
return - V_57 ;
V_48 = F_32 ( & V_45 -> V_55 , V_47 ) ;
if ( F_33 ( V_48 ) )
return F_34 ( V_48 ) ;
V_50 = F_35 ( V_45 , 0 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_45 -> V_55 . V_58 ) {
const struct V_59 * V_60 ;
V_60 = F_36 ( V_61 , & V_45 -> V_55 ) ;
if ( ! V_60 ) {
F_37 ( & V_45 -> V_55 , L_1 ) ;
return - V_54 ;
}
V_52 = ( V_62 ) V_60 -> V_63 ;
} else {
const struct V_64 * V_65 ;
V_65 = F_38 ( V_45 -> V_55 . V_66 -> V_67 ,
& V_45 -> V_55 ) ;
if ( ! V_65 || ! V_65 -> V_68 ) {
F_37 ( & V_45 -> V_55 , L_2 ) ;
return - V_54 ;
}
V_52 = ( V_62 ) V_65 -> V_68 ;
}
switch ( V_52 ) {
case V_69 :
V_13 -> V_42 = V_48 + V_70 ;
V_13 -> V_43 = V_48 + V_71 ;
V_13 -> V_19 = V_48 + V_72 ;
V_13 -> V_31 = V_48 + V_73 ;
V_13 -> V_32 = V_48 + V_74 ;
V_13 -> V_16 = V_48 + V_75 ;
V_41 = 41 ;
break;
case V_76 :
case V_77 :
V_13 -> V_42 = V_48 + V_70 ;
V_13 -> V_43 = V_48 + V_71 ;
V_13 -> V_19 = V_48 + V_78 ;
V_13 -> V_31 = V_48 + V_79 ;
V_13 -> V_32 = V_48 + V_80 ;
V_13 -> V_16 = V_48 + V_81 ;
V_41 = ( V_52 == V_76 ) ? 42 : 57 ;
break;
case V_82 :
case V_83 :
case V_84 :
V_13 -> V_42 = V_48 + V_85 ;
V_13 -> V_43 = V_48 + V_86 ;
V_13 -> V_19 = V_48 + V_87 ;
V_13 -> V_31 = V_48 + V_88 ;
V_13 -> V_32 = V_48 + V_89 ;
V_13 -> V_16 = V_48 + V_90 ;
if ( V_52 == V_82 )
V_41 = 66 ;
else if ( V_52 == V_83 )
V_41 = 67 ;
else
V_41 = 70 ;
break;
default:
F_37 ( & V_45 -> V_55 , L_3 ) ;
return - V_54 ;
}
F_39 ( V_13 -> V_18 , V_91 ) ;
V_11 = & V_13 -> V_39 ;
V_11 -> V_92 = V_93 ;
V_11 -> V_94 = F_40 ( & V_45 -> V_55 ) ;
V_11 -> V_95 = 0 ;
V_11 -> V_96 = & V_45 -> V_55 ;
V_11 -> V_41 = V_41 ;
V_11 -> V_58 = V_45 -> V_55 . V_58 ;
V_11 -> V_97 = F_24 ;
V_11 -> V_98 = F_26 ;
V_11 -> V_99 = F_28 ;
V_11 -> V_100 = F_27 ;
F_41 ( & V_13 -> V_15 ) ;
if ( V_52 != V_84 ) {
V_49 = F_42 ( - 1 , V_101 , V_11 -> V_41 , 0 ) ;
if ( V_49 < 0 ) {
F_37 ( & V_45 -> V_55 , L_4 ) ;
return V_49 ;
}
} else {
V_49 = 0 ;
}
V_51 = F_43 ( V_11 , V_13 ) ;
if ( V_51 < 0 )
goto V_102;
V_51 = F_44 ( V_11 , & V_103 , V_49 ,
V_104 , V_105 ) ;
if ( V_51 ) {
F_37 ( & V_45 -> V_55 , L_5 ) ;
goto V_106;
}
F_45 ( V_11 , & V_103 , V_50 ,
F_16 ) ;
F_46 ( & V_45 -> V_55 , L_6 , V_11 -> V_41 ) ;
return 0 ;
V_106:
F_47 ( V_11 ) ;
V_102:
F_48 ( V_49 , V_11 -> V_41 ) ;
return V_51 ;
}
