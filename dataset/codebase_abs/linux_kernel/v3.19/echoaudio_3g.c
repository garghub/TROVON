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
F_7 ( V_2 -> V_11 -> V_12 , L_1 , V_3 ) ;
if ( V_3 == V_7 )
return - V_13 ;
V_2 -> V_8 = TRUE ;
return V_3 & V_14 ;
}
static inline T_1 F_8 ( struct V_1 * V_2 )
{
return F_6 ( V_2 -> V_5 -> V_15 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 ,
char V_18 )
{
if ( F_2 ( V_2 ) )
return - V_4 ;
F_7 ( V_2 -> V_11 -> V_12 ,
L_2 , V_16 , V_17 ) ;
V_16 = F_3 ( V_16 ) ;
V_17 = F_3 ( V_17 ) ;
if ( V_16 != V_2 -> V_5 -> V_19 ||
V_17 != V_2 -> V_5 -> V_15 || V_18 ) {
V_2 -> V_5 -> V_15 = V_17 ;
V_2 -> V_5 -> V_19 = V_16 ;
F_4 ( V_2 ) ;
return F_5 ( V_2 , V_20 ) ;
}
F_7 ( V_2 -> V_11 -> V_12 , L_3 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_21 )
{
T_2 V_22 ;
int V_23 , V_24 , V_25 ;
if ( F_11 ( V_2 -> V_26 ) )
return - V_27 ;
if ( F_11 ( ! ( V_2 -> V_28 & ( 1 << V_21 ) ) ) )
return - V_29 ;
V_22 = V_2 -> V_30 ;
V_23 = F_12 ( V_2 , V_21 ) ;
if ( V_23 >= 0 && V_22 != V_21 &&
( V_22 == V_31 || V_21 == V_31 ) ) {
F_13 ( & V_2 -> V_32 ) ;
for ( V_25 = 0 ; V_25 < F_14 ( V_2 ) ; V_25 ++ )
for ( V_24 = 0 ; V_24 < F_15 ( V_2 ) ; V_24 ++ )
F_16 ( V_2 , V_25 , V_24 ,
V_2 -> V_33 [ V_25 ] [ V_24 ] ) ;
#ifdef F_17
for ( V_24 = 0 ; V_24 < F_15 ( V_2 ) ; V_24 ++ )
F_18 ( V_2 , V_24 , V_2 -> V_34 [ V_24 ] ) ;
F_19 ( V_2 ) ;
#endif
for ( V_25 = 0 ; V_25 < F_14 ( V_2 ) ; V_25 ++ )
F_20 ( V_2 , V_25 , V_2 -> V_35 [ V_25 ] ) ;
F_21 ( V_2 ) ;
F_22 ( & V_2 -> V_32 ) ;
}
return V_23 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_36 , T_1 V_37 )
{
V_36 &= V_38 ;
switch ( V_37 ) {
case 32000 :
V_36 |= V_39 | V_40 ;
break;
case 44100 :
if ( V_2 -> V_41 )
V_36 |= V_39 ;
break;
case 48000 :
V_36 |= V_40 ;
break;
}
if ( V_2 -> V_41 )
V_36 |= V_42 ;
if ( V_2 -> V_43 )
V_36 |= V_44 ;
V_36 |= V_45 | V_46 |
V_47 ;
return V_36 ;
}
static int F_24 ( struct V_1 * V_2 , char V_48 )
{
T_1 V_36 ;
V_36 = F_6 ( V_2 -> V_5 -> V_19 ) ;
V_2 -> V_41 = V_48 ;
V_36 = F_23 ( V_2 , V_36 , V_2 -> V_49 ) ;
return F_9 ( V_2 , V_36 , F_8 ( V_2 ) , 0 ) ;
}
static T_1 F_25 ( const struct V_1 * V_2 )
{
T_1 V_50 , V_51 ;
V_50 = F_6 ( V_2 -> V_5 -> V_52 ) ;
V_51 = V_53 ;
if ( V_50 & V_54 )
V_51 |= V_55 ;
switch( V_2 -> V_30 ) {
case V_56 :
case V_57 :
if ( V_50 & V_58 )
V_51 |= V_59 ;
break;
case V_31 :
if ( V_50 & V_60 )
V_51 |= V_61 ;
break;
}
return V_51 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_62 , V_23 ;
if ( V_2 -> V_8 )
return 0 ;
F_27 ( 2 ) ;
V_23 = F_28 ( V_2 , V_63 , V_64 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_65 = V_64 ;
F_29 ( 1000 ) ;
V_62 = F_1 ( V_2 ) ;
if ( V_62 >= 0 ) {
V_23 = F_9 ( V_2 , V_66 ,
V_67 , TRUE ) ;
if ( V_23 < 0 )
return V_23 ;
}
return V_62 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_37 )
{
T_1 V_36 , clock , V_68 , V_69 ;
if ( V_2 -> V_70 != V_71 ) {
F_31 ( V_2 -> V_11 -> V_12 ,
L_4 ) ;
V_2 -> V_5 -> V_49 = F_3 ( V_37 ) ;
V_2 -> V_49 = V_37 ;
F_32 ( V_2 , V_2 -> V_70 ) ;
return 0 ;
}
if ( F_11 ( V_37 >= 50000 &&
V_2 -> V_30 == V_31 ) )
return - V_29 ;
clock = 0 ;
V_36 = F_6 ( V_2 -> V_5 -> V_19 ) ;
V_36 &= V_72 ;
switch ( V_37 ) {
case 96000 :
clock = V_73 ;
break;
case 88200 :
clock = V_74 ;
break;
case 48000 :
clock = V_66 ;
break;
case 44100 :
clock = V_75 ;
break;
case 32000 :
clock = V_76 ;
break;
default:
clock = V_77 ;
if ( V_37 > 50000 )
clock |= V_78 ;
break;
}
V_36 |= clock ;
V_36 = F_23 ( V_2 , V_36 , V_37 ) ;
V_68 = V_37 ;
if ( V_68 > 50000 )
V_68 /= 2 ;
if ( V_68 < 32000 )
V_68 = 32000 ;
V_69 = V_79 / V_68 - 2 ;
if ( V_69 > V_80 )
V_69 = V_80 ;
V_2 -> V_5 -> V_49 = F_3 ( V_37 ) ;
V_2 -> V_49 = V_37 ;
F_7 ( V_2 -> V_11 -> V_12 ,
L_5 , V_37 , V_36 ) ;
return F_9 ( V_2 , V_36 , V_69 , 0 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_3 clock )
{
T_1 V_36 , V_50 ;
V_36 = F_6 ( V_2 -> V_5 -> V_19 ) &
V_72 ;
V_50 = F_6 ( V_2 -> V_5 -> V_52 ) ;
switch ( clock ) {
case V_71 :
V_2 -> V_70 = V_71 ;
return F_30 ( V_2 , V_2 -> V_49 ) ;
case V_81 :
if ( V_2 -> V_30 == V_31 )
return - V_27 ;
V_36 |= V_82 ;
if ( V_50 & V_83 )
V_36 |= V_78 ;
else
V_36 &= ~ V_78 ;
break;
case V_84 :
if ( V_2 -> V_30 != V_31 )
return - V_27 ;
V_36 |= V_85 ;
V_36 &= ~ V_78 ;
break;
case V_86 :
V_36 |= V_87 ;
if ( V_50 & V_88 )
V_36 |= V_78 ;
else
V_36 &= ~ V_78 ;
break;
default:
F_33 ( V_2 -> V_11 -> V_12 ,
L_6 , clock ) ;
return - V_29 ;
}
V_2 -> V_70 = clock ;
return F_9 ( V_2 , V_36 , F_8 ( V_2 ) , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_21 )
{
T_1 V_36 ;
int V_23 , V_89 ;
V_89 = FALSE ;
switch ( V_21 ) {
case V_57 :
case V_56 :
if ( V_2 -> V_70 == V_84 )
V_89 = TRUE ;
break;
case V_31 :
if ( V_2 -> V_70 == V_81 )
V_89 = TRUE ;
break;
default:
F_33 ( V_2 -> V_11 -> V_12 ,
L_7 , V_21 ) ;
return - V_29 ;
}
F_13 ( & V_2 -> V_32 ) ;
if ( V_89 ) {
V_2 -> V_49 = 48000 ;
F_32 ( V_2 , V_71 ) ;
}
V_36 = F_6 ( V_2 -> V_5 -> V_19 ) ;
V_36 &= V_90 ;
switch ( V_21 ) {
case V_57 :
V_36 |= V_91 ;
break;
case V_56 :
break;
case V_31 :
V_36 |= V_92 ;
V_36 &= ~ V_78 ;
break;
}
V_23 = F_9 ( V_2 , V_36 , F_8 ( V_2 ) , 1 ) ;
F_22 ( & V_2 -> V_32 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_30 = V_21 ;
F_7 ( V_2 -> V_11 -> V_12 , L_8 , V_2 -> V_30 ) ;
return V_89 ;
}
