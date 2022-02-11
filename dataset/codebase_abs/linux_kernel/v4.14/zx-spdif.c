static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( V_2 , V_4 ) ;
V_4 -> V_6 . V_7 = V_4 -> V_8 + V_9 ;
V_4 -> V_6 . V_10 = 8 ;
F_4 ( V_2 , & V_4 -> V_6 , NULL ) ;
return 0 ;
}
static int F_5 ( void T_1 * V_11 , unsigned int V_12 )
{
T_2 V_13 ;
switch ( V_12 ) {
case 22050 :
V_13 = V_14 ;
break;
case 24000 :
V_13 = V_15 ;
break;
case 32000 :
V_13 = V_16 ;
break;
case 44100 :
V_13 = V_17 ;
break;
case 48000 :
V_13 = V_18 ;
break;
case 88200 :
V_13 = V_19 ;
break;
case 96000 :
V_13 = V_20 ;
break;
case 176400 :
V_13 = V_21 ;
break;
case 192000 :
V_13 = V_22 ;
break;
default:
return - V_23 ;
}
V_13 = V_13 << 24 ;
V_13 |= V_24 ;
F_6 ( V_13 , V_11 + V_25 ) ;
return 0 ;
}
static int F_7 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_1 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_30 -> V_5 ) ;
struct V_3 * V_31 = F_8 ( V_30 ) ;
struct V_32 * V_6 = & V_4 -> V_6 ;
T_2 V_33 , V_34 , V_12 ;
int V_35 ;
V_6 = F_9 ( V_30 , V_27 ) ;
V_6 -> V_36 = F_10 ( V_29 ) >> 3 ;
V_33 = F_11 ( V_4 -> V_37 + V_38 ) ;
V_33 &= ~ V_39 ;
switch ( F_12 ( V_29 ) ) {
case V_40 :
V_33 |= V_41 ;
break;
case V_42 :
V_33 |= V_43 ;
break;
case V_44 :
V_33 |= V_45 ;
break;
case V_46 :
V_33 |= V_47 ;
break;
default:
F_13 ( V_30 -> V_5 , L_1 ) ;
return - V_23 ;
}
V_34 = F_14 ( V_29 ) ;
if ( V_34 == 2 )
V_33 |= V_48 ;
else
V_33 |= V_49 ;
F_6 ( V_33 , V_4 -> V_37 + V_38 ) ;
V_33 = F_11 ( V_4 -> V_37 + V_50 ) ;
V_33 &= ~ V_51 ;
if ( V_34 == 2 )
V_33 |= V_52 ;
else
V_33 |= V_53 ;
F_6 ( V_33 , V_4 -> V_37 + V_50 ) ;
V_12 = F_15 ( V_29 ) ;
V_35 = F_5 ( V_4 -> V_37 , V_12 ) ;
if ( V_35 )
return V_35 ;
return F_16 ( V_31 -> V_54 , V_12 * V_34 * V_55 ) ;
}
static void F_17 ( void T_1 * V_11 , int V_56 )
{
T_2 V_33 ;
V_33 = F_11 ( V_11 + V_38 ) ;
V_33 &= ~ ( V_57 | V_58 ) ;
V_33 |= V_56 ? V_59 : V_60 ;
F_6 ( V_33 , V_11 + V_38 ) ;
V_33 = F_11 ( V_11 + V_61 ) ;
V_33 &= ~ V_62 ;
if ( V_56 )
V_33 |= V_63 ;
F_6 ( V_33 , V_11 + V_61 ) ;
}
static int F_18 ( struct V_26 * V_27 , int V_64 ,
struct V_1 * V_2 )
{
T_2 V_33 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_35 = 0 ;
switch ( V_64 ) {
case V_65 :
V_33 = F_11 ( V_4 -> V_37 + V_61 ) ;
V_33 |= V_66 ;
F_6 ( V_33 , V_4 -> V_37 + V_61 ) ;
case V_67 :
case V_68 :
F_17 ( V_4 -> V_37 , true ) ;
break;
case V_69 :
case V_70 :
case V_71 :
F_17 ( V_4 -> V_37 , false ) ;
break;
default:
V_35 = - V_23 ;
break;
}
return V_35 ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
return F_20 ( V_4 -> V_54 ) ;
}
static void F_21 ( struct V_26 * V_27 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_22 ( V_4 -> V_54 ) ;
}
static void F_23 ( void T_1 * V_11 )
{
T_2 V_33 ;
F_6 ( 0 , V_11 + V_38 ) ;
F_6 ( 0 , V_11 + V_72 ) ;
F_6 ( 0xf , V_11 + V_73 ) ;
F_6 ( 0x1 , V_11 + V_61 ) ;
V_33 = F_11 ( V_11 + V_61 ) ;
V_33 &= ~ ( V_74 | V_75 ) ;
V_33 |= F_24 ( 8 ) ;
F_6 ( V_33 , V_11 + V_61 ) ;
}
static int F_25 ( struct V_76 * V_77 )
{
struct V_78 * V_79 ;
struct V_3 * V_4 ;
int V_35 ;
V_4 = F_26 ( & V_77 -> V_5 , sizeof( * V_4 ) , V_80 ) ;
if ( ! V_4 )
return - V_81 ;
V_4 -> V_54 = F_27 ( & V_77 -> V_5 , L_2 ) ;
if ( F_28 ( V_4 -> V_54 ) ) {
F_13 ( & V_77 -> V_5 , L_3 ) ;
return F_29 ( V_4 -> V_54 ) ;
}
V_79 = F_30 ( V_77 , V_82 , 0 ) ;
V_4 -> V_8 = V_79 -> V_83 ;
V_4 -> V_37 = F_31 ( & V_77 -> V_5 , V_79 ) ;
if ( F_28 ( V_4 -> V_37 ) ) {
F_13 ( & V_77 -> V_5 , L_4 ) ;
return F_29 ( V_4 -> V_37 ) ;
}
F_23 ( V_4 -> V_37 ) ;
F_32 ( V_77 , V_4 ) ;
V_35 = F_33 ( & V_77 -> V_5 , & V_84 ,
& V_85 , 1 ) ;
if ( V_35 ) {
F_13 ( & V_77 -> V_5 , L_5 , V_35 ) ;
return V_35 ;
}
V_35 = F_34 ( & V_77 -> V_5 , NULL , 0 ) ;
if ( V_35 )
F_13 ( & V_77 -> V_5 , L_6 , V_35 ) ;
return V_35 ;
}
