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
V_2 -> V_9 =
V_10 | V_11 |
V_12 | V_13 |
V_14 ;
if ( V_2 -> V_3 == V_15 ) {
V_2 -> V_16 = V_17 ;
V_2 -> V_18 =
V_19 |
V_20 |
V_21 ;
} else {
V_2 -> V_16 = V_22 ;
V_2 -> V_18 =
V_19 |
V_20 |
V_21 |
V_23 ;
}
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_8 = FALSE ;
F_2 ( ( L_3 ) ) ;
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
V_29 = V_10 ;
if ( V_28 & V_32 )
V_29 |= V_11 ;
if ( V_28 & V_33 )
V_29 |= V_14 ;
if ( V_28 & V_34 )
V_29 |= V_12 | V_13 ;
return V_29 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_35 ;
int V_5 ;
short V_36 ;
if ( V_2 -> V_37 )
return 1 ;
F_11 ( 10 ) ;
if ( V_2 -> V_3 == V_15 )
V_36 = V_38 ;
else
V_36 = V_39 ;
V_5 = F_12 ( V_2 , V_40 , V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_41 = V_36 ;
F_11 ( 10 ) ;
V_5 = F_13 ( V_2 ) ;
if ( ! V_5 ) {
V_35 = V_42 | V_43 ;
V_5 = F_14 ( V_2 , V_35 , TRUE ) ;
}
F_2 ( ( L_4 ) ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_44 )
{
T_2 V_35 , clock ;
if ( F_3 ( V_44 >= 50000 &&
V_2 -> V_24 == V_45 ) )
return - V_46 ;
if ( V_2 -> V_47 != V_48 ) {
F_16 ( ( L_5
L_6 ) ) ;
V_2 -> V_30 -> V_49 = F_17 ( V_44 ) ;
V_2 -> V_49 = V_44 ;
return 0 ;
}
clock = 0 ;
V_35 = F_9 ( V_2 -> V_30 -> V_50 ) ;
V_35 &= V_51 & V_52 ;
switch ( V_44 ) {
case 96000 :
clock = V_53 ;
break;
case 88200 :
clock = V_54 ;
break;
case 48000 :
clock = V_43 | V_55 ;
break;
case 44100 :
clock = V_56 ;
if ( V_35 & V_57 )
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
F_16 ( ( L_7 , V_44 ) ) ;
return - V_46 ;
}
V_35 |= clock ;
V_2 -> V_30 -> V_49 = F_17 ( V_44 ) ;
V_2 -> V_49 = V_44 ;
F_16 ( ( L_8 , V_44 , clock ) ) ;
return F_14 ( V_2 , V_35 , FALSE ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 clock )
{
T_2 V_35 , V_28 ;
F_16 ( ( L_9 ) ) ;
V_35 = F_9 ( V_2 -> V_30 -> V_50 ) &
V_51 ;
V_28 = F_9 ( V_2 -> V_30 -> V_31 ) ;
switch ( clock ) {
case V_48 :
F_16 ( ( L_10 ) ) ;
V_2 -> V_47 = V_48 ;
return F_15 ( V_2 , V_2 -> V_49 ) ;
case V_64 :
if ( V_2 -> V_24 == V_45 )
return - V_65 ;
F_16 ( ( L_11 ) ) ;
V_35 |= V_66 ;
if ( V_28 & V_67 )
V_35 |= V_68 ;
else
V_35 &= ~ V_68 ;
break;
case V_69 :
if ( V_2 -> V_24 != V_45 )
return - V_65 ;
F_16 ( ( L_12 ) ) ;
V_35 |= V_70 ;
V_35 &= ~ V_68 ;
break;
case V_71 :
F_16 ( ( L_13 ) ) ;
V_35 |= V_72 ;
V_35 &= ~ V_68 ;
break;
case V_73 :
F_16 ( ( L_14 ) ) ;
V_35 |= V_72 | V_68 ;
break;
default:
F_16 ( ( L_15 , clock ) ) ;
return - V_46 ;
}
V_2 -> V_47 = clock ;
return F_14 ( V_2 , V_35 , TRUE ) ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_74 )
{
T_2 V_35 ;
int V_5 , V_75 ;
V_75 = FALSE ;
switch ( V_74 ) {
case V_76 :
case V_77 :
case V_25 :
if ( V_2 -> V_47 == V_69 )
V_75 = TRUE ;
break;
case V_45 :
if ( V_2 -> V_47 == V_64 )
V_75 = TRUE ;
break;
default:
F_16 ( ( L_16 , V_74 ) ) ;
return - V_46 ;
}
F_20 ( & V_2 -> V_78 ) ;
if ( V_75 ) {
V_2 -> V_49 = 48000 ;
F_18 ( V_2 , V_48 ) ;
}
V_35 = F_9 ( V_2 -> V_30 -> V_50 ) ;
V_35 &= V_79 ;
switch ( V_74 ) {
case V_76 :
V_35 |= V_80 ;
break;
case V_77 :
if ( V_2 -> V_3 == V_81 )
V_35 |= V_82 ;
break;
case V_25 :
break;
case V_45 :
V_35 |= V_83 ;
V_35 &= ~ V_68 ;
break;
}
V_5 = F_14 ( V_2 , V_35 , TRUE ) ;
F_21 ( & V_2 -> V_78 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_24 = V_74 ;
F_16 ( ( L_17 , V_2 -> V_24 ) ) ;
return V_75 ;
}
