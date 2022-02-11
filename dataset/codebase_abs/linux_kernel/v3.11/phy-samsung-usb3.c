static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
V_4 = V_2 -> V_5 ;
V_3 = V_6 |
F_2 ( V_4 ) ;
switch ( V_4 ) {
case V_7 :
V_3 |= ( V_8 |
F_3 ( 0x00 ) ) ;
break;
case V_9 :
V_3 |= ( V_10 |
F_3 ( 0x00 ) ) ;
break;
case V_11 :
V_3 |= ( V_12 |
F_3 ( 0x88 ) ) ;
break;
case V_13 :
default:
V_3 |= ( V_14 |
F_3 ( 0x88 ) ) ;
break;
}
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
void T_2 * V_15 = V_2 -> V_15 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
T_1 V_19 ;
T_1 V_20 ;
T_1 V_21 ;
F_5 ( 0x0 , V_15 + V_22 ) ;
V_16 = F_6 ( V_15 + V_23 ) ;
V_16 &= ~ V_24 ;
V_16 &= ~ V_25 ;
V_16 |= V_26 ;
F_5 ( V_16 , V_15 + V_23 ) ;
F_5 ( 0x0 , V_15 + V_27 ) ;
V_18 = V_28 |
F_7 ( 0x20 ) ;
F_5 ( V_18 , V_15 + V_29 ) ;
V_17 = F_6 ( V_15 + V_30 ) ;
V_17 &= ~ V_31 ;
V_17 |= V_32 ;
F_5 ( V_17 , V_15 + V_30 ) ;
V_19 = F_6 ( V_15 + V_33 ) ;
V_19 |= V_34 ;
F_5 ( V_19 , V_15 + V_33 ) ;
V_20 = F_6 ( V_15 + V_35 ) ;
V_20 &= ~ ( V_36 |
V_37 ) ;
F_5 ( V_20 , V_15 + V_35 ) ;
F_5 ( V_38 , V_15 + V_39 ) ;
V_21 = F_1 ( V_2 ) ;
V_21 |= V_40 |
V_41 |
V_42 |
V_43 |
V_44 ;
F_5 ( V_21 , V_15 + V_45 ) ;
F_8 ( 10 ) ;
V_21 &= ~ ( V_40 ) ;
F_5 ( V_21 , V_15 + V_45 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_46 ;
T_1 V_21 ;
T_1 V_20 ;
void T_2 * V_15 = V_2 -> V_15 ;
V_46 = V_38 |
V_47 |
V_48 ;
F_5 ( V_46 , V_15 + V_39 ) ;
V_21 = F_6 ( V_15 + V_45 ) ;
V_21 &= ~ ( V_42 |
V_43 |
V_44 ) ;
F_5 ( V_21 , V_15 + V_45 ) ;
V_20 = F_6 ( V_15 + V_35 ) ;
V_20 |= ( V_36 |
V_37 ) ;
F_5 ( V_20 , V_15 + V_35 ) ;
}
static int F_10 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
unsigned long V_51 ;
int V_52 = 0 ;
V_2 = F_11 ( V_50 ) ;
V_52 = F_12 ( V_2 -> V_53 ) ;
if ( V_52 ) {
F_13 ( V_2 -> V_54 , L_1 , V_55 ) ;
return V_52 ;
}
F_14 ( & V_2 -> V_56 , V_51 ) ;
F_15 ( & V_2 -> V_50 , V_57 ) ;
if ( V_2 -> V_58 -> V_59 )
V_2 -> V_58 -> V_59 ( V_2 , false ) ;
V_2 -> V_58 -> V_60 ( V_2 ) ;
F_16 ( & V_2 -> V_56 , V_51 ) ;
F_17 ( V_2 -> V_53 ) ;
return V_52 ;
}
static void F_18 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
unsigned long V_51 ;
V_2 = F_11 ( V_50 ) ;
if ( F_12 ( V_2 -> V_53 ) ) {
F_13 ( V_2 -> V_54 , L_1 , V_55 ) ;
return;
}
F_14 ( & V_2 -> V_56 , V_51 ) ;
F_15 ( & V_2 -> V_50 , V_57 ) ;
V_2 -> V_58 -> V_61 ( V_2 ) ;
if ( V_2 -> V_58 -> V_59 )
V_2 -> V_58 -> V_59 ( V_2 , true ) ;
F_16 ( & V_2 -> V_56 , V_51 ) ;
F_17 ( V_2 -> V_53 ) ;
}
static int F_19 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 = V_63 -> V_54 . V_66 ;
struct V_67 * V_54 = & V_63 -> V_54 ;
struct V_68 * V_69 ;
void T_2 * V_70 ;
struct V_53 * V_53 ;
int V_52 ;
V_69 = F_20 ( V_63 , V_71 , 0 ) ;
V_70 = F_21 ( V_54 , V_69 ) ;
if ( F_22 ( V_70 ) )
return F_23 ( V_70 ) ;
V_2 = F_24 ( V_54 , sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_53 = F_25 ( V_54 , L_2 ) ;
if ( F_22 ( V_53 ) ) {
F_13 ( V_54 , L_3 ) ;
return F_23 ( V_53 ) ;
}
V_2 -> V_54 = V_54 ;
if ( V_54 -> V_74 ) {
V_52 = F_26 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
} else {
if ( ! V_65 ) {
F_13 ( V_54 , L_4 ) ;
return - V_75 ;
}
}
V_2 -> V_76 = V_65 ;
V_2 -> V_15 = V_70 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_50 . V_54 = V_2 -> V_54 ;
V_2 -> V_50 . V_77 = L_5 ;
V_2 -> V_50 . V_78 = F_10 ;
V_2 -> V_50 . V_79 = F_18 ;
V_2 -> V_58 = F_27 ( V_63 ) ;
V_2 -> V_5 = F_28 ( V_2 ) ;
if ( V_2 -> V_5 < 0 )
return - V_75 ;
F_29 ( & V_2 -> V_56 ) ;
F_30 ( V_63 , V_2 ) ;
return F_31 ( & V_2 -> V_50 , V_80 ) ;
}
static int F_32 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_33 ( V_63 ) ;
F_34 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_81 )
F_35 ( V_2 -> V_81 ) ;
if ( V_2 -> V_82 )
F_35 ( V_2 -> V_82 ) ;
return 0 ;
}
