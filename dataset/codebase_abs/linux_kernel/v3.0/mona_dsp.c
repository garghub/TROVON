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
V_12 | V_13 ;
V_2 -> V_14 =
V_15 |
V_16 |
V_17 ;
if ( V_2 -> V_3 == V_18 )
V_2 -> V_19 = V_20 ;
else
V_2 -> V_19 = V_21 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_8 = FALSE ;
F_2 ( ( L_3 ) ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = FALSE ;
V_2 -> V_25 = TRUE ;
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_26 , V_27 ;
V_26 = F_9 ( V_2 -> V_28 -> V_29 ) ;
V_27 = V_10 ;
if ( V_26 & V_30 )
V_27 |= V_11 ;
if ( V_26 & V_31 )
V_27 |= V_13 ;
if ( V_26 & V_32 )
V_27 |= V_12 ;
return V_27 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_33 ;
int V_5 ;
short V_34 ;
if ( V_2 -> V_35 )
return 0 ;
F_11 ( 10 ) ;
if ( V_2 -> V_3 == V_18 )
V_34 = V_36 ;
else
V_34 = V_37 ;
V_5 = F_12 ( V_2 , V_38 , V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_39 = V_34 ;
F_11 ( 10 ) ;
V_5 = F_12 ( V_2 , V_40 ,
V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
F_11 ( 10 ) ;
V_5 = F_13 ( V_2 ) ;
if ( ! V_5 ) {
V_33 = V_42 | V_43 ;
V_5 = F_14 ( V_2 , V_33 , TRUE ) ;
}
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 , char V_44 )
{
int V_5 ;
short V_34 ;
if ( V_2 -> V_3 == V_18 ) {
if ( V_44 )
V_34 = V_45 ;
else
V_34 = V_36 ;
} else {
if ( V_44 )
V_34 = V_46 ;
else
V_34 = V_37 ;
}
if ( V_34 != V_2 -> V_39 ) {
V_5 = F_12 ( V_2 , V_38 ,
V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_39 = V_34 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_47 )
{
T_2 V_33 , clock ;
short V_34 ;
char V_48 ;
if ( V_2 -> V_49 != V_50 ) {
F_17 ( ( L_4
L_5 ) ) ;
V_2 -> V_28 -> V_51 = F_18 ( V_47 ) ;
V_2 -> V_51 = V_47 ;
return 0 ;
}
if ( V_47 >= 88200 ) {
if ( V_2 -> V_22 == V_52 )
return - V_53 ;
if ( V_2 -> V_3 == V_18 )
V_34 = V_45 ;
else
V_34 = V_46 ;
} else {
if ( V_2 -> V_3 == V_18 )
V_34 = V_36 ;
else
V_34 = V_37 ;
}
V_48 = 0 ;
if ( V_34 != V_2 -> V_39 ) {
int V_5 ;
F_19 ( & V_2 -> V_54 ) ;
V_5 = F_12 ( V_2 , V_38 ,
V_34 ) ;
F_20 ( & V_2 -> V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_39 = V_34 ;
V_48 = 1 ;
}
clock = 0 ;
V_33 = F_9 ( V_2 -> V_28 -> V_55 ) ;
V_33 &= V_56 ;
V_33 &= V_57 ;
switch ( V_47 ) {
case 96000 :
clock = V_58 ;
break;
case 88200 :
clock = V_59 ;
break;
case 48000 :
clock = V_43 | V_60 ;
break;
case 44100 :
clock = V_61 ;
if ( V_33 & V_62 )
clock |= V_63 ;
break;
case 32000 :
clock = V_64 | V_63 |
V_60 ;
break;
case 22050 :
clock = V_65 ;
break;
case 16000 :
clock = V_66 ;
break;
case 11025 :
clock = V_67 ;
break;
case 8000 :
clock = V_68 ;
break;
default:
F_17 ( ( L_6 , V_47 ) ) ;
return - V_53 ;
}
V_33 |= clock ;
V_2 -> V_28 -> V_51 = F_18 ( V_47 ) ;
V_2 -> V_51 = V_47 ;
F_17 ( ( L_7 , V_47 , clock ) ) ;
return F_14 ( V_2 , V_33 , V_48 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 clock )
{
T_2 V_33 , V_26 ;
int V_5 ;
F_17 ( ( L_8 ) ) ;
if ( F_22 ( & V_2 -> V_69 ) )
return - V_70 ;
V_33 = F_9 ( V_2 -> V_28 -> V_55 ) &
V_56 ;
V_26 = F_9 ( V_2 -> V_28 -> V_29 ) ;
switch ( clock ) {
case V_50 :
F_17 ( ( L_9 ) ) ;
V_2 -> V_49 = V_50 ;
return F_16 ( V_2 , V_2 -> V_51 ) ;
case V_71 :
if ( V_2 -> V_22 == V_52 )
return - V_70 ;
F_19 ( & V_2 -> V_54 ) ;
V_5 = F_15 ( V_2 , V_26 &
V_72 ) ;
F_20 ( & V_2 -> V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
F_17 ( ( L_10 ) ) ;
V_33 |= V_73 ;
if ( V_26 & V_72 )
V_33 |= V_74 ;
else
V_33 &= ~ V_74 ;
break;
case V_75 :
F_17 ( ( L_11 ) ) ;
F_19 ( & V_2 -> V_54 ) ;
V_5 = F_15 ( V_2 , V_26 &
V_76 ) ;
F_20 ( & V_2 -> V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_33 |= V_77 ;
if ( V_26 & V_76 )
V_33 |= V_74 ;
else
V_33 &= ~ V_74 ;
break;
case V_78 :
F_17 ( ( L_12 ) ) ;
if ( V_2 -> V_22 != V_52 )
return - V_70 ;
V_33 |= V_79 ;
V_33 &= ~ V_74 ;
break;
default:
F_17 ( ( L_13 , clock ) ) ;
return - V_53 ;
}
V_2 -> V_49 = clock ;
return F_14 ( V_2 , V_33 , TRUE ) ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_80 )
{
T_2 V_33 ;
int V_5 , V_81 ;
V_81 = FALSE ;
switch ( V_80 ) {
case V_82 :
case V_23 :
if ( V_2 -> V_49 == V_78 )
V_81 = TRUE ;
break;
case V_52 :
if ( V_2 -> V_49 == V_71 )
V_81 = TRUE ;
break;
default:
F_17 ( ( L_14 , V_80 ) ) ;
return - V_53 ;
}
F_20 ( & V_2 -> V_54 ) ;
if ( V_81 ) {
V_2 -> V_51 = 48000 ;
F_21 ( V_2 , V_50 ) ;
}
V_33 = F_9 ( V_2 -> V_28 -> V_55 ) ;
V_33 &= V_83 ;
switch ( V_80 ) {
case V_82 :
V_33 |= V_84 ;
break;
case V_23 :
break;
case V_52 :
if ( V_2 -> V_39 == V_45 ||
V_2 -> V_39 == V_46 ) {
F_16 ( V_2 , 48000 ) ;
}
V_33 |= V_85 ;
V_33 &= ~ V_74 ;
break;
}
V_5 = F_14 ( V_2 , V_33 , FALSE ) ;
F_19 ( & V_2 -> V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_22 = V_80 ;
F_17 ( ( L_15 , V_80 ) ) ;
return V_81 ;
}
