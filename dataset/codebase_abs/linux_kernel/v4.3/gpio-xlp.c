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
static T_3 F_17 ( int V_34 , void * V_35 )
{
struct V_1 * V_14 = V_35 ;
int V_6 , V_36 ;
T_2 V_37 ;
V_36 = - 1 ;
V_37 = 0 ;
F_18 (gpio, priv->gpio_enabled_mask, XLP_MAX_NR_GPIO) {
if ( V_36 != V_6 / V_9 ) {
V_36 = V_6 / V_9 ;
V_37 = F_4 ( V_14 -> V_20 + V_36 * 4 ) ;
}
if ( V_37 & F_5 ( V_6 % V_9 ) )
F_19 ( F_20 (
V_14 -> V_4 . V_38 , V_6 ) ) ;
}
return V_39 ;
}
static int F_21 ( struct V_2 * V_3 , unsigned V_6 , int V_10 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_22 ( V_6 >= V_3 -> V_40 ) ;
F_6 ( V_14 -> V_41 , V_6 , 0x1 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , unsigned V_6 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_22 ( V_6 >= V_3 -> V_40 ) ;
F_6 ( V_14 -> V_41 , V_6 , 0x0 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , unsigned V_6 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_22 ( V_6 >= V_3 -> V_40 ) ;
return F_3 ( V_14 -> V_42 , V_6 ) ;
}
static void F_25 ( struct V_2 * V_3 , unsigned V_6 , int V_10 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_22 ( V_6 >= V_3 -> V_40 ) ;
F_6 ( V_14 -> V_42 , V_6 , V_10 ) ;
}
static int F_26 ( struct V_43 * V_44 )
{
struct V_2 * V_3 ;
struct V_45 * V_46 ;
struct V_1 * V_14 ;
const struct V_47 * V_48 ;
void T_1 * V_49 ;
int V_50 , V_34 , V_51 ;
int V_40 ;
T_2 V_52 ;
V_46 = F_27 ( V_44 , V_53 , 0 ) ;
if ( ! V_46 )
return - V_54 ;
V_14 = F_28 ( & V_44 -> V_55 , sizeof( * V_14 ) , V_56 ) ;
if ( ! V_14 )
return - V_57 ;
V_49 = F_29 ( & V_44 -> V_55 , V_46 ) ;
if ( F_30 ( V_49 ) )
return F_31 ( V_49 ) ;
V_34 = F_32 ( V_44 , 0 ) ;
if ( V_34 < 0 )
return V_34 ;
V_48 = F_33 ( V_58 , & V_44 -> V_55 ) ;
if ( ! V_48 ) {
F_34 ( & V_44 -> V_55 , L_1 ) ;
return - V_54 ;
}
V_52 = ( V_59 ) V_48 -> V_35 ;
switch ( V_52 ) {
case V_60 :
V_14 -> V_41 = V_49 + V_61 ;
V_14 -> V_42 = V_49 + V_62 ;
V_14 -> V_20 = V_49 + V_63 ;
V_14 -> V_32 = V_49 + V_64 ;
V_14 -> V_33 = V_49 + V_65 ;
V_14 -> V_17 = V_49 + V_66 ;
V_40 = 41 ;
break;
case V_67 :
case V_68 :
V_14 -> V_41 = V_49 + V_61 ;
V_14 -> V_42 = V_49 + V_62 ;
V_14 -> V_20 = V_49 + V_69 ;
V_14 -> V_32 = V_49 + V_70 ;
V_14 -> V_33 = V_49 + V_71 ;
V_14 -> V_17 = V_49 + V_72 ;
V_40 = ( V_52 == V_67 ) ? 42 : 57 ;
break;
case V_73 :
case V_74 :
V_14 -> V_41 = V_49 + V_75 ;
V_14 -> V_42 = V_49 + V_76 ;
V_14 -> V_20 = V_49 + V_77 ;
V_14 -> V_32 = V_49 + V_78 ;
V_14 -> V_33 = V_49 + V_79 ;
V_14 -> V_17 = V_49 + V_80 ;
V_40 = ( V_52 == V_73 ) ? 66 : 67 ;
break;
default:
F_34 ( & V_44 -> V_55 , L_2 ) ;
return - V_54 ;
}
F_35 ( V_14 -> V_19 , V_81 ) ;
V_3 = & V_14 -> V_4 ;
V_3 -> V_82 = V_83 ;
V_3 -> V_84 = F_36 ( & V_44 -> V_55 ) ;
V_3 -> V_85 = 0 ;
V_3 -> V_55 = & V_44 -> V_55 ;
V_3 -> V_40 = V_40 ;
V_3 -> V_86 = V_44 -> V_55 . V_86 ;
V_3 -> V_87 = F_21 ;
V_3 -> V_88 = F_23 ;
V_3 -> V_89 = F_25 ;
V_3 -> V_90 = F_24 ;
F_37 ( & V_14 -> V_16 ) ;
V_51 = F_38 ( & V_44 -> V_55 , V_34 , F_17 ,
V_91 , V_44 -> V_92 , V_14 ) ;
if ( V_51 )
return V_51 ;
V_50 = F_39 ( - 1 , V_93 , V_3 -> V_40 , 0 ) ;
if ( V_50 < 0 ) {
F_34 ( & V_44 -> V_55 , L_3 ) ;
return - V_54 ;
}
V_51 = F_40 ( V_3 ) ;
if ( V_51 < 0 )
goto V_94;
V_51 = F_41 ( V_3 , & V_95 , V_50 ,
V_96 , V_91 ) ;
if ( V_51 ) {
F_34 ( & V_44 -> V_55 , L_4 ) ;
goto V_97;
}
F_42 ( & V_44 -> V_55 , L_5 , V_3 -> V_40 ) ;
return 0 ;
V_97:
F_43 ( V_3 ) ;
V_94:
F_44 ( V_50 , V_3 -> V_40 ) ;
return V_51 ;
}
