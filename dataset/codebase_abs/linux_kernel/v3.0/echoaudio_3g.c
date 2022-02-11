static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_2 ( V_2 ) )
return - V_4 ;
V_2 -> V_5 -> V_6 = F_3 ( V_7 ) ;
V_2 -> V_8 = FALSE ;
F_4 ( V_2 ) ;
F_5 ( V_2 , V_9 ) ;
if ( F_2 ( V_2 ) ) {
V_2 -> V_10 = NULL ;
return - V_4 ;
}
V_3 = F_6 ( V_2 -> V_5 -> V_6 ) ;
F_7 ( ( L_1 , V_3 ) ) ;
if ( V_3 == V_7 )
return - V_11 ;
V_2 -> V_8 = TRUE ;
return V_3 & V_12 ;
}
static inline T_1 F_8 ( struct V_1 * V_2 )
{
return F_6 ( V_2 -> V_5 -> V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 ,
char V_16 )
{
if ( F_2 ( V_2 ) )
return - V_4 ;
F_10 ( ( L_2 , V_14 , V_15 ) ) ;
V_14 = F_3 ( V_14 ) ;
V_15 = F_3 ( V_15 ) ;
if ( V_14 != V_2 -> V_5 -> V_17 ||
V_15 != V_2 -> V_5 -> V_13 || V_16 ) {
V_2 -> V_5 -> V_13 = V_15 ;
V_2 -> V_5 -> V_17 = V_14 ;
F_4 ( V_2 ) ;
return F_5 ( V_2 , V_18 ) ;
}
F_10 ( ( L_3 ) ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_19 )
{
T_2 V_20 ;
int V_21 , V_22 , V_23 ;
if ( F_12 ( V_2 -> V_24 ) )
return - V_25 ;
if ( F_12 ( ! ( V_2 -> V_26 & ( 1 << V_19 ) ) ) )
return - V_27 ;
V_20 = V_2 -> V_28 ;
V_21 = F_13 ( V_2 , V_19 ) ;
if ( V_21 >= 0 && V_20 != V_19 &&
( V_20 == V_29 || V_19 == V_29 ) ) {
F_14 ( & V_2 -> V_30 ) ;
for ( V_23 = 0 ; V_23 < F_15 ( V_2 ) ; V_23 ++ )
for ( V_22 = 0 ; V_22 < F_16 ( V_2 ) ; V_22 ++ )
F_17 ( V_2 , V_23 , V_22 ,
V_2 -> V_31 [ V_23 ] [ V_22 ] ) ;
#ifdef F_18
for ( V_22 = 0 ; V_22 < F_16 ( V_2 ) ; V_22 ++ )
F_19 ( V_2 , V_22 , V_2 -> V_32 [ V_22 ] ) ;
F_20 ( V_2 ) ;
#endif
for ( V_23 = 0 ; V_23 < F_15 ( V_2 ) ; V_23 ++ )
F_21 ( V_2 , V_23 , V_2 -> V_33 [ V_23 ] ) ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_30 ) ;
}
return V_21 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_34 , T_1 V_35 )
{
V_34 &= V_36 ;
switch ( V_35 ) {
case 32000 :
V_34 |= V_37 | V_38 ;
break;
case 44100 :
if ( V_2 -> V_39 )
V_34 |= V_37 ;
break;
case 48000 :
V_34 |= V_38 ;
break;
}
if ( V_2 -> V_39 )
V_34 |= V_40 ;
if ( V_2 -> V_41 )
V_34 |= V_42 ;
V_34 |= V_43 | V_44 |
V_45 ;
return V_34 ;
}
static int F_25 ( struct V_1 * V_2 , char V_46 )
{
T_1 V_34 ;
V_34 = F_6 ( V_2 -> V_5 -> V_17 ) ;
V_2 -> V_39 = V_46 ;
V_34 = F_24 ( V_2 , V_34 , V_2 -> V_47 ) ;
return F_9 ( V_2 , V_34 , F_8 ( V_2 ) , 0 ) ;
}
static T_1 F_26 ( const struct V_1 * V_2 )
{
T_1 V_48 , V_49 ;
V_48 = F_6 ( V_2 -> V_5 -> V_50 ) ;
V_49 = V_51 ;
if ( V_48 & V_52 )
V_49 |= V_53 ;
switch( V_2 -> V_28 ) {
case V_54 :
case V_55 :
if ( V_48 & V_56 )
V_49 |= V_57 ;
break;
case V_29 :
if ( V_48 & V_58 )
V_49 |= V_59 ;
break;
}
return V_49 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_60 , V_21 ;
if ( V_2 -> V_8 )
return 0 ;
F_28 ( 2 ) ;
V_21 = F_29 ( V_2 , V_61 , V_62 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_63 = V_62 ;
F_30 ( 1000 ) ;
V_60 = F_1 ( V_2 ) ;
if ( V_60 >= 0 ) {
V_21 = F_9 ( V_2 , V_64 ,
V_65 , TRUE ) ;
if ( V_21 < 0 )
return V_21 ;
}
return V_60 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_35 )
{
T_1 V_34 , clock , V_66 , V_67 ;
if ( V_2 -> V_68 != V_69 ) {
F_10 ( ( L_4
L_5 ) ) ;
V_2 -> V_5 -> V_47 = F_3 ( V_35 ) ;
V_2 -> V_47 = V_35 ;
F_32 ( V_2 , V_2 -> V_68 ) ;
return 0 ;
}
if ( F_12 ( V_35 >= 50000 &&
V_2 -> V_28 == V_29 ) )
return - V_27 ;
clock = 0 ;
V_34 = F_6 ( V_2 -> V_5 -> V_17 ) ;
V_34 &= V_70 ;
switch ( V_35 ) {
case 96000 :
clock = V_71 ;
break;
case 88200 :
clock = V_72 ;
break;
case 48000 :
clock = V_64 ;
break;
case 44100 :
clock = V_73 ;
break;
case 32000 :
clock = V_74 ;
break;
default:
clock = V_75 ;
if ( V_35 > 50000 )
clock |= V_76 ;
break;
}
V_34 |= clock ;
V_34 = F_24 ( V_2 , V_34 , V_35 ) ;
V_66 = V_35 ;
if ( V_66 > 50000 )
V_66 /= 2 ;
if ( V_66 < 32000 )
V_66 = 32000 ;
V_67 = V_77 / V_66 - 2 ;
if ( V_67 > V_78 )
V_67 = V_78 ;
V_2 -> V_5 -> V_47 = F_3 ( V_35 ) ;
V_2 -> V_47 = V_35 ;
F_10 ( ( L_6 , V_35 , V_34 ) ) ;
return F_9 ( V_2 , V_34 , V_67 , 0 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_3 clock )
{
T_1 V_34 , V_48 ;
F_10 ( ( L_7 ) ) ;
V_34 = F_6 ( V_2 -> V_5 -> V_17 ) &
V_70 ;
V_48 = F_6 ( V_2 -> V_5 -> V_50 ) ;
switch ( clock ) {
case V_69 :
F_10 ( ( L_8 ) ) ;
V_2 -> V_68 = V_69 ;
return F_31 ( V_2 , V_2 -> V_47 ) ;
case V_79 :
if ( V_2 -> V_28 == V_29 )
return - V_25 ;
F_10 ( ( L_9 ) ) ;
V_34 |= V_80 ;
if ( V_48 & V_81 )
V_34 |= V_76 ;
else
V_34 &= ~ V_76 ;
break;
case V_82 :
if ( V_2 -> V_28 != V_29 )
return - V_25 ;
F_10 ( ( L_10 ) ) ;
V_34 |= V_83 ;
V_34 &= ~ V_76 ;
break;
case V_84 :
F_10 ( ( L_11 ) ) ;
V_34 |= V_85 ;
if ( V_48 & V_86 )
V_34 |= V_76 ;
else
V_34 &= ~ V_76 ;
break;
default:
F_10 ( ( L_12 , clock ) ) ;
return - V_27 ;
}
V_2 -> V_68 = clock ;
return F_9 ( V_2 , V_34 , F_8 ( V_2 ) , 1 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_19 )
{
T_1 V_34 ;
int V_21 , V_87 ;
V_87 = FALSE ;
switch ( V_19 ) {
case V_55 :
case V_54 :
if ( V_2 -> V_68 == V_82 )
V_87 = TRUE ;
break;
case V_29 :
if ( V_2 -> V_68 == V_79 )
V_87 = TRUE ;
break;
default:
F_10 ( ( L_13 , V_19 ) ) ;
return - V_27 ;
}
F_14 ( & V_2 -> V_30 ) ;
if ( V_87 ) {
V_2 -> V_47 = 48000 ;
F_32 ( V_2 , V_69 ) ;
}
V_34 = F_6 ( V_2 -> V_5 -> V_17 ) ;
V_34 &= V_88 ;
switch ( V_19 ) {
case V_55 :
V_34 |= V_89 ;
break;
case V_54 :
break;
case V_29 :
V_34 |= V_90 ;
V_34 &= ~ V_76 ;
break;
}
V_21 = F_9 ( V_2 , V_34 , F_8 ( V_2 ) , 1 ) ;
F_23 ( & V_2 -> V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_28 = V_19 ;
F_10 ( ( L_14 , V_2 -> V_28 ) ) ;
return V_87 ;
}
