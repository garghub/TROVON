static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( void T_1 * V_5 , unsigned V_6 )
{
T_2 V_7 , V_8 ;
V_7 = V_6 % V_9 ;
V_8 = ( V_6 / V_9 ) * 4 ;
return ! ! ( F_4 ( V_5 + V_8 ) & F_5 ( V_7 ) ) ;
}
static void F_6 ( void T_1 * V_5 , unsigned V_6 , int V_10 )
{
T_2 V_11 , V_7 , V_8 ;
V_7 = V_6 % V_9 ;
V_8 = ( V_6 / V_9 ) * 4 ;
V_11 = F_4 ( V_5 + V_8 ) ;
if ( V_10 )
V_11 |= F_5 ( V_7 ) ;
else
V_11 &= ~ F_5 ( V_7 ) ;
F_7 ( V_11 , V_5 + V_8 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_9 ( V_13 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_15 ;
F_10 ( & V_14 -> V_16 , V_15 ) ;
F_6 ( V_14 -> V_17 , V_13 -> V_18 , 0x0 ) ;
F_11 ( V_13 -> V_18 , V_14 -> V_19 ) ;
F_12 ( & V_14 -> V_16 , V_15 ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_9 ( V_13 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_15 ;
F_10 ( & V_14 -> V_16 , V_15 ) ;
F_6 ( V_14 -> V_17 , V_13 -> V_18 , 0x0 ) ;
F_6 ( V_14 -> V_20 , V_13 -> V_18 , 0x1 ) ;
F_11 ( V_13 -> V_18 , V_14 -> V_19 ) ;
F_12 ( & V_14 -> V_16 , V_15 ) ;
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_9 ( V_13 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_15 ;
F_10 ( & V_14 -> V_16 , V_15 ) ;
F_6 ( V_14 -> V_17 , V_13 -> V_18 , 0x1 ) ;
F_15 ( V_13 -> V_18 , V_14 -> V_19 ) ;
F_12 ( & V_14 -> V_16 , V_15 ) ;
}
static int F_16 ( struct V_12 * V_13 , unsigned int type )
{
struct V_2 * V_3 = F_9 ( V_13 ) ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_21 , V_22 ;
switch ( type ) {
case V_23 :
V_22 = V_24 ;
V_21 = V_25 ;
break;
case V_26 :
V_22 = V_24 ;
V_21 = V_27 ;
break;
case V_28 :
V_22 = V_29 ;
V_21 = V_25 ;
break;
case V_30 :
V_22 = V_29 ;
V_21 = V_27 ;
break;
default:
return - V_31 ;
}
F_6 ( V_14 -> V_32 , V_13 -> V_18 , V_22 ) ;
F_6 ( V_14 -> V_33 , V_13 -> V_18 , V_21 ) ;
return 0 ;
}
static void F_17 ( struct V_34 * V_35 )
{
struct V_1 * V_14 = F_18 ( V_35 ) ;
struct V_36 * V_37 = F_19 ( V_35 ) ;
int V_6 , V_38 ;
T_2 V_39 ;
V_38 = - 1 ;
V_39 = 0 ;
F_20 ( V_37 , V_35 ) ;
F_21 (gpio, priv->gpio_enabled_mask, XLP_MAX_NR_GPIO) {
if ( V_38 != V_6 / V_9 ) {
V_38 = V_6 / V_9 ;
V_39 = F_4 ( V_14 -> V_20 + V_38 * 4 ) ;
}
if ( V_39 & F_5 ( V_6 % V_9 ) )
F_22 ( F_23 (
V_14 -> V_4 . V_40 , V_6 ) ) ;
}
F_24 ( V_37 , V_35 ) ;
}
static int F_25 ( struct V_2 * V_3 , unsigned V_6 , int V_10 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_26 ( V_6 >= V_3 -> V_41 ) ;
F_6 ( V_14 -> V_42 , V_6 , 0x1 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , unsigned V_6 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_26 ( V_6 >= V_3 -> V_41 ) ;
F_6 ( V_14 -> V_42 , V_6 , 0x0 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , unsigned V_6 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_26 ( V_6 >= V_3 -> V_41 ) ;
return F_3 ( V_14 -> V_43 , V_6 ) ;
}
static void F_29 ( struct V_2 * V_3 , unsigned V_6 , int V_10 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_26 ( V_6 >= V_3 -> V_41 ) ;
F_6 ( V_14 -> V_43 , V_6 , V_10 ) ;
}
static int F_30 ( struct V_44 * V_45 )
{
struct V_2 * V_3 ;
struct V_46 * V_47 ;
struct V_1 * V_14 ;
const struct V_48 * V_49 ;
void T_1 * V_50 ;
int V_51 , V_52 , V_53 ;
int V_41 ;
T_2 V_54 ;
V_47 = F_31 ( V_45 , V_55 , 0 ) ;
if ( ! V_47 )
return - V_56 ;
V_14 = F_32 ( & V_45 -> V_57 , sizeof( * V_14 ) , V_58 ) ;
if ( ! V_14 )
return - V_59 ;
V_50 = F_33 ( & V_45 -> V_57 , V_47 ) ;
if ( F_34 ( V_50 ) )
return F_35 ( V_50 ) ;
V_52 = F_36 ( V_45 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
V_49 = F_37 ( V_60 , & V_45 -> V_57 ) ;
if ( ! V_49 ) {
F_38 ( & V_45 -> V_57 , L_1 ) ;
return - V_56 ;
}
V_54 = ( V_61 ) V_49 -> V_62 ;
switch ( V_54 ) {
case V_63 :
V_14 -> V_42 = V_50 + V_64 ;
V_14 -> V_43 = V_50 + V_65 ;
V_14 -> V_20 = V_50 + V_66 ;
V_14 -> V_32 = V_50 + V_67 ;
V_14 -> V_33 = V_50 + V_68 ;
V_14 -> V_17 = V_50 + V_69 ;
V_41 = 41 ;
break;
case V_70 :
case V_71 :
V_14 -> V_42 = V_50 + V_64 ;
V_14 -> V_43 = V_50 + V_65 ;
V_14 -> V_20 = V_50 + V_72 ;
V_14 -> V_32 = V_50 + V_73 ;
V_14 -> V_33 = V_50 + V_74 ;
V_14 -> V_17 = V_50 + V_75 ;
V_41 = ( V_54 == V_70 ) ? 42 : 57 ;
break;
case V_76 :
case V_77 :
V_14 -> V_42 = V_50 + V_78 ;
V_14 -> V_43 = V_50 + V_79 ;
V_14 -> V_20 = V_50 + V_80 ;
V_14 -> V_32 = V_50 + V_81 ;
V_14 -> V_33 = V_50 + V_82 ;
V_14 -> V_17 = V_50 + V_83 ;
V_41 = ( V_54 == V_76 ) ? 66 : 67 ;
break;
default:
F_38 ( & V_45 -> V_57 , L_2 ) ;
return - V_56 ;
}
F_39 ( V_14 -> V_19 , V_84 ) ;
V_3 = & V_14 -> V_4 ;
V_3 -> V_85 = V_86 ;
V_3 -> V_87 = F_40 ( & V_45 -> V_57 ) ;
V_3 -> V_88 = 0 ;
V_3 -> V_57 = & V_45 -> V_57 ;
V_3 -> V_41 = V_41 ;
V_3 -> V_89 = V_45 -> V_57 . V_89 ;
V_3 -> V_90 = F_25 ;
V_3 -> V_91 = F_27 ;
V_3 -> V_92 = F_29 ;
V_3 -> V_93 = F_28 ;
F_41 ( & V_14 -> V_16 ) ;
V_51 = F_42 ( - 1 , V_94 , V_3 -> V_41 , 0 ) ;
if ( V_51 < 0 ) {
F_38 ( & V_45 -> V_57 , L_3 ) ;
return - V_56 ;
}
V_53 = F_43 ( V_3 ) ;
if ( V_53 < 0 )
goto V_95;
V_53 = F_44 ( V_3 , & V_96 , V_51 ,
V_97 , V_98 ) ;
if ( V_53 ) {
F_38 ( & V_45 -> V_57 , L_4 ) ;
goto V_99;
}
F_45 ( V_3 , & V_96 , V_52 ,
F_17 ) ;
F_46 ( & V_45 -> V_57 , L_5 , V_3 -> V_41 ) ;
return 0 ;
V_99:
F_47 ( V_3 ) ;
V_95:
F_48 ( V_51 , V_3 -> V_41 ) ;
return V_53 ;
}
