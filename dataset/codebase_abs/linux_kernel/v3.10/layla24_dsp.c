static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_2 ( ( L_1 ) ) ;
if ( F_3 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_4 ( V_2 ) ) ) {
F_2 ( ( L_2 ) ) ;
return V_5 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = TRUE ;
V_2 -> V_9 = TRUE ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 =
V_13 | V_14 |
V_15 | V_16 ;
V_2 -> V_17 =
V_18 |
V_19 |
V_20 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_8 = FALSE ;
if ( ( V_5 = F_6 ( V_2 ) ) < 0 )
return V_5 ;
F_2 ( ( L_3 ) ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = FALSE ;
V_2 -> V_24 = TRUE ;
return F_6 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_25 , V_26 ;
V_25 = F_9 ( V_2 -> V_27 -> V_28 ) ;
V_26 = V_13 ;
if ( V_25 & V_29 )
V_26 |= V_14 ;
if ( V_25 & V_30 )
V_26 |= V_16 ;
if ( V_25 & V_31 )
V_26 |= V_15 ;
return V_26 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_32 )
return 1 ;
F_2 ( ( L_4 ) ) ;
F_11 ( 10 ) ;
V_5 = F_12 ( V_2 , V_33 ,
V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_35 = V_36 ;
F_11 ( 10 ) ;
V_5 = F_12 ( V_2 , V_37 ,
V_36 ) ;
if ( V_5 < 0 )
return FALSE ;
F_11 ( 10 ) ;
V_5 = F_13 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_14 ( V_2 , V_38 | V_39 ,
TRUE ) ;
F_2 ( ( L_5 ) ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_40 )
{
T_2 V_41 , clock , V_42 ;
if ( F_3 ( V_40 >= 50000 &&
V_2 -> V_21 == V_43 ) )
return - V_44 ;
if ( V_2 -> V_45 != V_46 ) {
F_16 ( ( L_6
L_7 ) ) ;
V_2 -> V_27 -> V_47 = F_17 ( V_40 ) ;
V_2 -> V_47 = V_40 ;
return 0 ;
}
V_41 = F_9 ( V_2 -> V_27 -> V_48 ) ;
V_41 &= V_49 & V_50 ;
clock = 0 ;
switch ( V_40 ) {
case 96000 :
clock = V_51 ;
break;
case 88200 :
clock = V_52 ;
break;
case 48000 :
clock = V_39 | V_53 ;
break;
case 44100 :
clock = V_54 ;
if ( V_41 & V_55 )
clock |= V_56 ;
break;
case 32000 :
clock = V_57 | V_56 |
V_53 ;
break;
case 22050 :
clock = V_58 ;
break;
case 16000 :
clock = V_59 ;
break;
case 11025 :
clock = V_60 ;
break;
case 8000 :
clock = V_61 ;
break;
default:
clock = V_62 ;
if ( V_40 > 50000 ) {
V_42 = V_40 >> 1 ;
V_41 |= V_63 ;
} else {
V_42 = V_40 ;
}
if ( V_42 < 25000 )
V_42 = 25000 ;
if ( F_18 ( V_2 ) )
return - V_64 ;
V_2 -> V_27 -> V_47 =
F_17 ( V_65 / V_42 - 2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 , V_66 ) ;
}
V_41 |= clock ;
V_2 -> V_27 -> V_47 = F_17 ( V_40 ) ;
V_2 -> V_47 = V_40 ;
F_16 ( ( L_8 , V_40 , V_41 ) ) ;
return F_14 ( V_2 , V_41 , FALSE ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 clock )
{
T_2 V_41 , V_25 ;
V_41 = F_9 ( V_2 -> V_27 -> V_48 ) &
V_49 ;
V_25 = F_9 ( V_2 -> V_27 -> V_28 ) ;
switch ( clock ) {
case V_46 :
F_16 ( ( L_9 ) ) ;
V_2 -> V_45 = V_46 ;
return F_15 ( V_2 , V_2 -> V_47 ) ;
case V_67 :
if ( V_2 -> V_21 == V_43 )
return - V_68 ;
V_41 |= V_69 ;
V_41 &= ~ V_63 ;
F_16 ( ( L_10 ) ) ;
break;
case V_70 :
V_41 |= V_71 ;
if ( V_25 & V_72 )
V_41 |= V_63 ;
else
V_41 &= ~ V_63 ;
F_16 ( ( L_11 ) ) ;
break;
case V_73 :
if ( V_2 -> V_21 != V_43 )
return - V_68 ;
V_41 |= V_74 ;
V_41 &= ~ V_63 ;
F_16 ( ( L_12 ) ) ;
break;
default:
F_16 ( ( L_13 , clock ) ) ;
return - V_44 ;
}
V_2 -> V_45 = clock ;
return F_14 ( V_2 , V_41 , TRUE ) ;
}
static int F_22 ( struct V_1 * V_2 , short V_75 )
{
T_3 * V_76 ;
if ( V_75 != V_2 -> V_35 ) {
V_76 = F_23 ( V_2 -> V_27 -> V_76 ,
V_77 , V_78 ) ;
if ( ! V_76 )
return - V_79 ;
memset ( V_2 -> V_27 -> V_76 , V_80 ,
V_77 ) ;
if ( F_12 ( V_2 , V_37 ,
V_75 ) < 0 ) {
memcpy ( V_2 -> V_27 -> V_76 , V_76 ,
V_77 ) ;
F_24 ( V_76 ) ;
return - V_64 ;
}
V_2 -> V_35 = V_75 ;
memcpy ( V_2 -> V_27 -> V_76 , V_76 , V_77 ) ;
F_24 ( V_76 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_4 V_81 )
{
T_2 V_41 ;
int V_5 , V_82 ;
short V_75 ;
V_82 = FALSE ;
switch ( V_81 ) {
case V_83 :
case V_22 :
if ( V_2 -> V_45 == V_73 )
V_82 = TRUE ;
V_75 = V_36 ;
break;
case V_43 :
if ( V_2 -> V_45 == V_67 )
V_82 = TRUE ;
V_75 = V_84 ;
break;
default:
F_16 ( ( L_14 , V_81 ) ) ;
return - V_44 ;
}
if ( V_82 ) {
V_2 -> V_47 = 48000 ;
F_26 ( & V_2 -> V_85 ) ;
F_21 ( V_2 , V_46 ) ;
F_27 ( & V_2 -> V_85 ) ;
}
if ( F_22 ( V_2 , V_75 ) < 0 )
return - V_64 ;
F_26 ( & V_2 -> V_85 ) ;
V_41 = F_9 ( V_2 -> V_27 -> V_48 ) ;
V_41 &= V_86 ;
switch ( V_81 ) {
case V_83 :
V_41 |= V_87 ;
break;
case V_22 :
break;
case V_43 :
V_41 |= V_88 ;
V_41 &= ~ V_63 ;
break;
}
V_5 = F_14 ( V_2 , V_41 , TRUE ) ;
F_27 ( & V_2 -> V_85 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_21 = V_81 ;
F_16 ( ( L_15 , V_81 ) ) ;
return V_82 ;
}
