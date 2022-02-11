static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 ;
if ( F_3 ( V_5 ) ) {
V_9 = F_4 ( V_10 + V_8 -> V_11 ) ;
if ( V_3 )
V_9 |= V_12 ;
else
V_9 &= ~ V_12 ;
F_5 ( V_10 + V_8 -> V_11 , V_9 ) ;
} else if ( F_6 ( V_5 ) ) {
V_9 = F_4 ( V_13 + V_8 -> V_11 ) ;
if ( V_3 )
V_9 |= V_14 ;
else
V_9 &= ~ V_14 ;
F_5 ( V_13 + V_8 -> V_11 , V_9 ) ;
} else {
V_9 = F_4 ( V_15 + V_8 -> V_11 ) ;
if ( V_3 )
V_9 |= V_16 ;
else
V_9 &= ~ V_16 ;
F_5 ( V_15 + V_8 -> V_11 , V_9 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_3 ( V_5 ) ) {
F_8 ( V_17 + V_8 -> V_11 ,
F_9 ( V_18 ) |
F_10 ( V_19 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_8 ( V_20 + V_8 -> V_11 ,
( V_21 << V_22 ) ) ;
} else {
T_2 V_23 ;
switch ( V_8 -> V_24 ) {
case 0 :
V_23 = V_25 ;
break;
case 1 :
V_23 = V_26 ;
break;
default:
return;
}
F_8 ( V_23 , F_11 ( V_23 ) & ~ V_27 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_28 , V_17 + V_8 -> V_11 ) ;
F_5 ( V_29 , V_30 |
F_9 ( V_18 ) |
F_10 ( V_19 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_28 , V_20 + V_8 -> V_11 ) ;
F_5 ( V_29 , V_31 |
( V_21 << V_22 ) ) ;
} else {
switch ( V_8 -> V_24 ) {
case 0 :
F_5 ( V_28 , V_25 ) ;
break;
case 1 :
F_5 ( V_28 , V_26 ) ;
break;
default:
return;
}
F_13 ( V_29 , ( V_27 |
( V_32 << V_33 ) ) ,
~ ( V_27 | V_34 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 , struct V_35 * V_36 ,
T_3 V_37 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_38 + V_8 -> V_11 ,
F_15 ( V_37 ) ) ;
F_5 ( V_39 + V_8 -> V_11 ,
V_37 & 0xffffffff ) ;
} else if ( F_6 ( V_5 ) ) {
if ( V_5 -> V_40 >= V_41 ) {
if ( V_8 -> V_24 )
F_5 ( V_42 , F_15 ( V_37 ) ) ;
else
F_5 ( V_43 , F_15 ( V_37 ) ) ;
}
F_5 ( V_44 + V_8 -> V_11 ,
V_37 & 0xffffffff ) ;
} else {
V_8 -> V_45 = V_37 - V_8 -> V_46 ;
F_5 ( V_15 + V_8 -> V_11 , V_8 -> V_45 ) ;
}
}
int F_16 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
T_1 V_49 ,
T_1 V_50 ,
T_1 V_51 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_35 * V_36 ;
struct V_52 * V_53 ;
T_3 V_37 ;
int V_54 ;
if ( ! V_49 ) {
F_7 ( V_2 ) ;
V_36 = NULL ;
goto V_55;
}
if ( ( V_50 > V_56 ) || ( V_51 > V_57 ) ) {
F_17 ( L_1 , V_50 , V_51 ) ;
return - V_58 ;
}
V_36 = F_18 ( V_2 -> V_6 , V_48 , V_49 ) ;
if ( ! V_36 ) {
F_17 ( L_2 , V_49 , V_8 -> V_24 ) ;
return - V_59 ;
}
V_53 = F_19 ( V_36 ) ;
V_54 = F_20 ( V_53 , false ) ;
if ( F_21 ( V_54 != 0 ) )
goto V_60;
V_54 = F_22 ( V_53 , V_61 ,
F_6 ( V_5 ) ? 0 : 1 << 27 ,
& V_37 ) ;
F_23 ( V_53 ) ;
if ( V_54 )
goto V_60;
V_8 -> V_62 = V_50 ;
V_8 -> V_63 = V_51 ;
F_1 ( V_2 , true ) ;
F_14 ( V_2 , V_36 , V_37 ) ;
F_12 ( V_2 ) ;
F_1 ( V_2 , false ) ;
V_55:
if ( V_8 -> V_64 ) {
V_53 = F_19 ( V_8 -> V_64 ) ;
V_54 = F_20 ( V_53 , false ) ;
if ( F_24 ( V_54 == 0 ) ) {
F_25 ( V_53 ) ;
F_23 ( V_53 ) ;
}
F_26 ( V_8 -> V_64 ) ;
}
V_8 -> V_64 = V_36 ;
return 0 ;
V_60:
F_26 ( V_36 ) ;
return V_54 ;
}
int F_27 ( struct V_1 * V_2 ,
int V_65 , int V_66 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_67 = 0 , V_68 = 0 ;
int V_69 = V_8 -> V_62 ;
if ( F_6 ( V_5 ) ) {
V_65 += V_2 -> V_65 ;
V_66 += V_2 -> V_66 ;
}
F_28 ( L_3 , V_65 , V_66 , V_2 -> V_65 , V_2 -> V_66 ) ;
if ( V_65 < 0 ) {
V_67 = F_29 ( - V_65 , V_56 - 1 ) ;
V_65 = 0 ;
}
if ( V_66 < 0 ) {
V_68 = F_29 ( - V_66 , V_57 - 1 ) ;
V_66 = 0 ;
}
if ( F_6 ( V_5 ) && ! F_30 ( V_5 ) ) {
int V_70 = 0 ;
struct V_1 * V_71 ;
F_31 (crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if ( V_71 -> V_72 )
V_70 ++ ;
}
if ( V_70 > 1 ) {
int V_73 , V_74 ;
V_73 = V_65 - V_67 + V_69 ;
V_74 = V_2 -> V_65 + V_2 -> V_75 . V_76 ;
if ( V_73 >= V_74 ) {
V_69 = V_69 - ( V_73 - V_74 ) ;
if ( ! ( V_74 & 0x7f ) )
V_69 -- ;
} else {
if ( ! ( V_73 & 0x7f ) )
V_69 -- ;
}
if ( V_69 <= 0 ) {
V_69 = 1 ;
V_73 = V_65 - V_67 + V_69 ;
if ( ! ( V_73 & 0x7f ) ) {
V_65 -- ;
F_32 ( V_65 < 0 ) ;
}
}
}
}
F_1 ( V_2 , true ) ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_77 + V_8 -> V_11 , ( V_65 << 16 ) | V_66 ) ;
F_5 ( V_78 + V_8 -> V_11 , ( V_67 << 16 ) | V_68 ) ;
F_5 ( V_79 + V_8 -> V_11 ,
( ( V_69 - 1 ) << 16 ) | ( V_8 -> V_63 - 1 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_80 + V_8 -> V_11 , ( V_65 << 16 ) | V_66 ) ;
F_5 ( V_81 + V_8 -> V_11 , ( V_67 << 16 ) | V_68 ) ;
F_5 ( V_82 + V_8 -> V_11 ,
( ( V_69 - 1 ) << 16 ) | ( V_8 -> V_63 - 1 ) ) ;
} else {
if ( V_2 -> V_75 . V_83 & V_84 )
V_66 *= 2 ;
F_5 ( V_85 + V_8 -> V_11 ,
( V_16
| ( V_67 << 16 )
| V_68 ) ) ;
F_5 ( V_86 + V_8 -> V_11 ,
( V_16
| ( V_65 << 16 )
| V_66 ) ) ;
F_5 ( V_15 + V_8 -> V_11 , ( V_8 -> V_45 +
( V_68 * 256 ) ) ) ;
}
F_1 ( V_2 , false ) ;
return 0 ;
}
