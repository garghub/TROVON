static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
if ( F_2 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_3 ( V_2 ) ) ) {
F_4 ( V_2 -> V_8 -> V_9 ,
L_1 ) ;
return V_5 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = TRUE ;
V_2 -> V_11 = TRUE ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 =
V_15 | V_16 |
V_17 | V_18 ;
V_2 -> V_19 =
V_20 |
V_21 |
V_22 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_10 = FALSE ;
if ( ( V_5 = F_6 ( V_2 ) ) < 0 )
return V_5 ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = FALSE ;
V_2 -> V_26 = TRUE ;
return F_6 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_27 , V_28 ;
V_27 = F_9 ( V_2 -> V_29 -> V_30 ) ;
V_28 = V_15 ;
if ( V_27 & V_31 )
V_28 |= V_16 ;
if ( V_27 & V_32 )
V_28 |= V_18 ;
if ( V_27 & V_33 )
V_28 |= V_17 ;
return V_28 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_34 )
return 1 ;
F_11 ( 10 ) ;
V_5 = F_12 ( V_2 , V_35 ,
V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_37 = V_38 ;
F_11 ( 10 ) ;
V_5 = F_12 ( V_2 , V_39 ,
V_38 ) ;
if ( V_5 < 0 )
return FALSE ;
F_11 ( 10 ) ;
V_5 = F_13 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_14 ( V_2 , V_40 | V_41 ,
TRUE ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_42 )
{
T_2 V_43 , clock , V_44 ;
if ( F_2 ( V_42 >= 50000 &&
V_2 -> V_23 == V_45 ) )
return - V_46 ;
if ( V_2 -> V_47 != V_48 ) {
F_16 ( V_2 -> V_8 -> V_9 ,
L_2 ) ;
V_2 -> V_29 -> V_49 = F_17 ( V_42 ) ;
V_2 -> V_49 = V_42 ;
return 0 ;
}
V_43 = F_9 ( V_2 -> V_29 -> V_50 ) ;
V_43 &= V_51 & V_52 ;
clock = 0 ;
switch ( V_42 ) {
case 96000 :
clock = V_53 ;
break;
case 88200 :
clock = V_54 ;
break;
case 48000 :
clock = V_41 | V_55 ;
break;
case 44100 :
clock = V_56 ;
if ( V_43 & V_57 )
clock |= V_58 ;
break;
case 32000 :
clock = V_59 | V_58 |
V_55 ;
break;
case 22050 :
clock = V_60 ;
break;
case 16000 :
clock = V_61 ;
break;
case 11025 :
clock = V_62 ;
break;
case 8000 :
clock = V_63 ;
break;
default:
clock = V_64 ;
if ( V_42 > 50000 ) {
V_44 = V_42 >> 1 ;
V_43 |= V_65 ;
} else {
V_44 = V_42 ;
}
if ( V_44 < 25000 )
V_44 = 25000 ;
if ( F_18 ( V_2 ) )
return - V_66 ;
V_2 -> V_29 -> V_49 =
F_17 ( V_67 / V_44 - 2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 , V_68 ) ;
}
V_43 |= clock ;
V_2 -> V_29 -> V_49 = F_17 ( V_42 ) ;
V_2 -> V_49 = V_42 ;
F_21 ( V_2 -> V_8 -> V_9 ,
L_3 , V_42 , V_43 ) ;
return F_14 ( V_2 , V_43 , FALSE ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 clock )
{
T_2 V_43 , V_27 ;
V_43 = F_9 ( V_2 -> V_29 -> V_50 ) &
V_51 ;
V_27 = F_9 ( V_2 -> V_29 -> V_30 ) ;
switch ( clock ) {
case V_48 :
V_2 -> V_47 = V_48 ;
return F_15 ( V_2 , V_2 -> V_49 ) ;
case V_69 :
if ( V_2 -> V_23 == V_45 )
return - V_70 ;
V_43 |= V_71 ;
V_43 &= ~ V_65 ;
break;
case V_72 :
V_43 |= V_73 ;
if ( V_27 & V_74 )
V_43 |= V_65 ;
else
V_43 &= ~ V_65 ;
break;
case V_75 :
if ( V_2 -> V_23 != V_45 )
return - V_70 ;
V_43 |= V_76 ;
V_43 &= ~ V_65 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_4 , clock ) ;
return - V_46 ;
}
V_2 -> V_47 = clock ;
return F_14 ( V_2 , V_43 , TRUE ) ;
}
static int F_23 ( struct V_1 * V_2 , short V_77 )
{
T_3 * V_78 ;
if ( V_77 != V_2 -> V_37 ) {
V_78 = F_24 ( V_2 -> V_29 -> V_78 ,
V_79 , V_80 ) ;
if ( ! V_78 )
return - V_81 ;
memset ( V_2 -> V_29 -> V_78 , V_82 ,
V_79 ) ;
if ( F_12 ( V_2 , V_39 ,
V_77 ) < 0 ) {
memcpy ( V_2 -> V_29 -> V_78 , V_78 ,
V_79 ) ;
F_25 ( V_78 ) ;
return - V_66 ;
}
V_2 -> V_37 = V_77 ;
memcpy ( V_2 -> V_29 -> V_78 , V_78 , V_79 ) ;
F_25 ( V_78 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_4 V_83 )
{
T_2 V_43 ;
int V_5 , V_84 ;
short V_77 ;
V_84 = FALSE ;
switch ( V_83 ) {
case V_85 :
case V_24 :
if ( V_2 -> V_47 == V_75 )
V_84 = TRUE ;
V_77 = V_38 ;
break;
case V_45 :
if ( V_2 -> V_47 == V_69 )
V_84 = TRUE ;
V_77 = V_86 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_5 , V_83 ) ;
return - V_46 ;
}
if ( V_84 ) {
V_2 -> V_49 = 48000 ;
F_27 ( & V_2 -> V_87 ) ;
F_22 ( V_2 , V_48 ) ;
F_28 ( & V_2 -> V_87 ) ;
}
if ( F_23 ( V_2 , V_77 ) < 0 )
return - V_66 ;
F_27 ( & V_2 -> V_87 ) ;
V_43 = F_9 ( V_2 -> V_29 -> V_50 ) ;
V_43 &= V_88 ;
switch ( V_83 ) {
case V_85 :
V_43 |= V_89 ;
break;
case V_24 :
break;
case V_45 :
V_43 |= V_90 ;
V_43 &= ~ V_65 ;
break;
}
V_5 = F_14 ( V_2 , V_43 , TRUE ) ;
F_28 ( & V_2 -> V_87 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_23 = V_83 ;
F_21 ( V_2 -> V_8 -> V_9 , L_6 , V_83 ) ;
return V_84 ;
}
