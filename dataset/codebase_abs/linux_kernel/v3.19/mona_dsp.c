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
V_14 | V_15 ;
V_2 -> V_16 =
V_17 |
V_18 |
V_19 ;
if ( V_2 -> V_3 == V_20 )
V_2 -> V_21 = V_22 ;
else
V_2 -> V_21 = V_23 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_10 = FALSE ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = FALSE ;
V_2 -> V_27 = TRUE ;
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_28 , V_29 ;
V_28 = F_9 ( V_2 -> V_30 -> V_31 ) ;
V_29 = V_12 ;
if ( V_28 & V_32 )
V_29 |= V_13 ;
if ( V_28 & V_33 )
V_29 |= V_15 ;
if ( V_28 & V_34 )
V_29 |= V_14 ;
return V_29 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_35 ;
int V_5 ;
short V_36 ;
if ( V_2 -> V_37 )
return 0 ;
F_11 ( 10 ) ;
if ( V_2 -> V_3 == V_20 )
V_36 = V_38 ;
else
V_36 = V_39 ;
V_5 = F_12 ( V_2 , V_40 , V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_41 = V_36 ;
F_11 ( 10 ) ;
V_5 = F_12 ( V_2 , V_42 ,
V_43 ) ;
if ( V_5 < 0 )
return V_5 ;
F_11 ( 10 ) ;
V_5 = F_13 ( V_2 ) ;
if ( ! V_5 ) {
V_35 = V_44 | V_45 ;
V_5 = F_14 ( V_2 , V_35 , TRUE ) ;
}
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 , char V_46 )
{
int V_5 ;
short V_36 ;
if ( V_2 -> V_3 == V_20 ) {
if ( V_46 )
V_36 = V_47 ;
else
V_36 = V_38 ;
} else {
if ( V_46 )
V_36 = V_48 ;
else
V_36 = V_39 ;
}
if ( V_36 != V_2 -> V_41 ) {
V_5 = F_12 ( V_2 , V_40 ,
V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_41 = V_36 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_49 )
{
T_2 V_35 , clock ;
short V_36 ;
char V_50 ;
if ( V_2 -> V_51 != V_52 ) {
F_17 ( V_2 -> V_8 -> V_9 ,
L_2 ) ;
V_2 -> V_30 -> V_53 = F_18 ( V_49 ) ;
V_2 -> V_53 = V_49 ;
return 0 ;
}
if ( V_49 >= 88200 ) {
if ( V_2 -> V_24 == V_54 )
return - V_55 ;
if ( V_2 -> V_3 == V_20 )
V_36 = V_47 ;
else
V_36 = V_48 ;
} else {
if ( V_2 -> V_3 == V_20 )
V_36 = V_38 ;
else
V_36 = V_39 ;
}
V_50 = 0 ;
if ( V_36 != V_2 -> V_41 ) {
int V_5 ;
F_19 ( & V_2 -> V_56 ) ;
V_5 = F_12 ( V_2 , V_40 ,
V_36 ) ;
F_20 ( & V_2 -> V_56 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_41 = V_36 ;
V_50 = 1 ;
}
clock = 0 ;
V_35 = F_9 ( V_2 -> V_30 -> V_57 ) ;
V_35 &= V_58 ;
V_35 &= V_59 ;
switch ( V_49 ) {
case 96000 :
clock = V_60 ;
break;
case 88200 :
clock = V_61 ;
break;
case 48000 :
clock = V_45 | V_62 ;
break;
case 44100 :
clock = V_63 ;
if ( V_35 & V_64 )
clock |= V_65 ;
break;
case 32000 :
clock = V_66 | V_65 |
V_62 ;
break;
case 22050 :
clock = V_67 ;
break;
case 16000 :
clock = V_68 ;
break;
case 11025 :
clock = V_69 ;
break;
case 8000 :
clock = V_70 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_3 , V_49 ) ;
return - V_55 ;
}
V_35 |= clock ;
V_2 -> V_30 -> V_53 = F_18 ( V_49 ) ;
V_2 -> V_53 = V_49 ;
F_17 ( V_2 -> V_8 -> V_9 ,
L_4 , V_49 , clock ) ;
return F_14 ( V_2 , V_35 , V_50 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 clock )
{
T_2 V_35 , V_28 ;
int V_5 ;
if ( F_22 ( & V_2 -> V_71 ) )
return - V_72 ;
V_35 = F_9 ( V_2 -> V_30 -> V_57 ) &
V_58 ;
V_28 = F_9 ( V_2 -> V_30 -> V_31 ) ;
switch ( clock ) {
case V_52 :
V_2 -> V_51 = V_52 ;
return F_16 ( V_2 , V_2 -> V_53 ) ;
case V_73 :
if ( V_2 -> V_24 == V_54 )
return - V_72 ;
F_19 ( & V_2 -> V_56 ) ;
V_5 = F_15 ( V_2 , V_28 &
V_74 ) ;
F_20 ( & V_2 -> V_56 ) ;
if ( V_5 < 0 )
return V_5 ;
V_35 |= V_75 ;
if ( V_28 & V_74 )
V_35 |= V_76 ;
else
V_35 &= ~ V_76 ;
break;
case V_77 :
F_19 ( & V_2 -> V_56 ) ;
V_5 = F_15 ( V_2 , V_28 &
V_78 ) ;
F_20 ( & V_2 -> V_56 ) ;
if ( V_5 < 0 )
return V_5 ;
V_35 |= V_79 ;
if ( V_28 & V_78 )
V_35 |= V_76 ;
else
V_35 &= ~ V_76 ;
break;
case V_80 :
F_17 ( V_2 -> V_8 -> V_9 , L_5 ) ;
if ( V_2 -> V_24 != V_54 )
return - V_72 ;
V_35 |= V_81 ;
V_35 &= ~ V_76 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_6 , clock ) ;
return - V_55 ;
}
V_2 -> V_51 = clock ;
return F_14 ( V_2 , V_35 , TRUE ) ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_82 )
{
T_2 V_35 ;
int V_5 , V_83 ;
V_83 = FALSE ;
switch ( V_82 ) {
case V_84 :
case V_25 :
if ( V_2 -> V_51 == V_80 )
V_83 = TRUE ;
break;
case V_54 :
if ( V_2 -> V_51 == V_73 )
V_83 = TRUE ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_7 , V_82 ) ;
return - V_55 ;
}
F_20 ( & V_2 -> V_56 ) ;
if ( V_83 ) {
V_2 -> V_53 = 48000 ;
F_21 ( V_2 , V_52 ) ;
}
V_35 = F_9 ( V_2 -> V_30 -> V_57 ) ;
V_35 &= V_85 ;
switch ( V_82 ) {
case V_84 :
V_35 |= V_86 ;
break;
case V_25 :
break;
case V_54 :
if ( V_2 -> V_41 == V_47 ||
V_2 -> V_41 == V_48 ) {
F_16 ( V_2 , 48000 ) ;
}
V_35 |= V_87 ;
V_35 &= ~ V_76 ;
break;
}
V_5 = F_14 ( V_2 , V_35 , FALSE ) ;
F_19 ( & V_2 -> V_56 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_24 = V_82 ;
F_17 ( V_2 -> V_8 -> V_9 , L_8 , V_82 ) ;
return V_83 ;
}
