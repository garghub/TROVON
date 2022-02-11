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
V_2 -> V_11 =
V_12 | V_13 |
V_14 | V_15 |
V_16 ;
if ( V_2 -> V_3 == V_17 ) {
V_2 -> V_18 = V_19 ;
V_2 -> V_20 =
V_21 |
V_22 |
V_23 ;
} else {
V_2 -> V_18 = V_24 ;
V_2 -> V_20 =
V_21 |
V_22 |
V_23 |
V_25 ;
}
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_10 = FALSE ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_26 = V_27 ;
V_2 -> V_28 = FALSE ;
V_2 -> V_29 = TRUE ;
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_30 , V_31 ;
V_30 = F_9 ( V_2 -> V_32 -> V_33 ) ;
V_31 = V_12 ;
if ( V_30 & V_34 )
V_31 |= V_13 ;
if ( V_30 & V_35 )
V_31 |= V_16 ;
if ( V_30 & V_36 )
V_31 |= V_14 | V_15 ;
return V_31 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_37 ;
int V_5 ;
short V_38 ;
if ( V_2 -> V_39 )
return 1 ;
F_11 ( 10 ) ;
if ( V_2 -> V_3 == V_17 )
V_38 = V_40 ;
else
V_38 = V_41 ;
V_5 = F_12 ( V_2 , V_42 , V_38 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_43 = V_38 ;
F_11 ( 10 ) ;
V_5 = F_13 ( V_2 ) ;
if ( ! V_5 ) {
V_37 = V_44 | V_45 ;
V_5 = F_14 ( V_2 , V_37 , TRUE ) ;
}
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_46 )
{
T_2 V_37 , clock ;
if ( F_2 ( V_46 >= 50000 &&
V_2 -> V_26 == V_47 ) )
return - V_48 ;
if ( V_2 -> V_49 != V_50 ) {
F_16 ( V_2 -> V_8 -> V_9 ,
L_2 ) ;
V_2 -> V_32 -> V_51 = F_17 ( V_46 ) ;
V_2 -> V_51 = V_46 ;
return 0 ;
}
clock = 0 ;
V_37 = F_9 ( V_2 -> V_32 -> V_52 ) ;
V_37 &= V_53 & V_54 ;
switch ( V_46 ) {
case 96000 :
clock = V_55 ;
break;
case 88200 :
clock = V_56 ;
break;
case 48000 :
clock = V_45 | V_57 ;
break;
case 44100 :
clock = V_58 ;
if ( V_37 & V_59 )
clock |= V_60 ;
break;
case 32000 :
clock = V_61 | V_60 |
V_57 ;
break;
case 22050 :
clock = V_62 ;
break;
case 16000 :
clock = V_63 ;
break;
case 11025 :
clock = V_64 ;
break;
case 8000 :
clock = V_65 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_3 , V_46 ) ;
return - V_48 ;
}
V_37 |= clock ;
V_2 -> V_32 -> V_51 = F_17 ( V_46 ) ;
V_2 -> V_51 = V_46 ;
F_18 ( V_2 -> V_8 -> V_9 , L_4 , V_46 , clock ) ;
return F_14 ( V_2 , V_37 , FALSE ) ;
}
static int F_19 ( struct V_1 * V_2 , T_1 clock )
{
T_2 V_37 , V_30 ;
V_37 = F_9 ( V_2 -> V_32 -> V_52 ) &
V_53 ;
V_30 = F_9 ( V_2 -> V_32 -> V_33 ) ;
switch ( clock ) {
case V_50 :
V_2 -> V_49 = V_50 ;
return F_15 ( V_2 , V_2 -> V_51 ) ;
case V_66 :
if ( V_2 -> V_26 == V_47 )
return - V_67 ;
V_37 |= V_68 ;
if ( V_30 & V_69 )
V_37 |= V_70 ;
else
V_37 &= ~ V_70 ;
break;
case V_71 :
if ( V_2 -> V_26 != V_47 )
return - V_67 ;
V_37 |= V_72 ;
V_37 &= ~ V_70 ;
break;
case V_73 :
V_37 |= V_74 ;
V_37 &= ~ V_70 ;
break;
case V_75 :
V_37 |= V_74 | V_70 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_5 , clock ) ;
return - V_48 ;
}
V_2 -> V_49 = clock ;
return F_14 ( V_2 , V_37 , TRUE ) ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_76 )
{
T_2 V_37 ;
int V_5 , V_77 ;
V_77 = FALSE ;
switch ( V_76 ) {
case V_78 :
case V_79 :
case V_27 :
if ( V_2 -> V_49 == V_71 )
V_77 = TRUE ;
break;
case V_47 :
if ( V_2 -> V_49 == V_66 )
V_77 = TRUE ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_6 , V_76 ) ;
return - V_48 ;
}
F_21 ( & V_2 -> V_80 ) ;
if ( V_77 ) {
V_2 -> V_51 = 48000 ;
F_19 ( V_2 , V_50 ) ;
}
V_37 = F_9 ( V_2 -> V_32 -> V_52 ) ;
V_37 &= V_81 ;
switch ( V_76 ) {
case V_78 :
V_37 |= V_82 ;
break;
case V_79 :
if ( V_2 -> V_3 == V_83 )
V_37 |= V_84 ;
break;
case V_27 :
break;
case V_47 :
V_37 |= V_85 ;
V_37 &= ~ V_70 ;
break;
}
V_5 = F_14 ( V_2 , V_37 , TRUE ) ;
F_22 ( & V_2 -> V_80 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_26 = V_76 ;
F_18 ( V_2 -> V_8 -> V_9 ,
L_7 , V_2 -> V_26 ) ;
return V_77 ;
}
