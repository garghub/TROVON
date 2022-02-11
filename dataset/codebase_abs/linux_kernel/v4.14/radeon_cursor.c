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
if ( V_8 -> V_28 )
return;
if ( F_3 ( V_5 ) ) {
F_5 ( V_29 + V_8 -> V_11 ,
F_13 ( V_8 -> V_30 ) ) ;
F_5 ( V_31 + V_8 -> V_11 ,
F_14 ( V_8 -> V_30 ) ) ;
F_5 ( V_32 , V_17 + V_8 -> V_11 ) ;
F_5 ( V_33 , V_34 |
F_9 ( V_18 ) |
F_10 ( V_19 ) ) ;
} else if ( F_6 ( V_5 ) ) {
if ( V_5 -> V_35 >= V_36 ) {
if ( V_8 -> V_24 )
F_5 ( V_37 ,
F_13 ( V_8 -> V_30 ) ) ;
else
F_5 ( V_38 ,
F_13 ( V_8 -> V_30 ) ) ;
}
F_5 ( V_39 + V_8 -> V_11 ,
F_14 ( V_8 -> V_30 ) ) ;
F_5 ( V_32 , V_20 + V_8 -> V_11 ) ;
F_5 ( V_33 , V_40 |
( V_21 << V_22 ) ) ;
} else {
F_5 ( V_15 + V_8 -> V_11 ,
V_8 -> V_30 - V_8 -> V_41 ) ;
switch ( V_8 -> V_24 ) {
case 0 :
F_5 ( V_32 , V_25 ) ;
break;
case 1 :
F_5 ( V_32 , V_26 ) ;
break;
default:
return;
}
F_15 ( V_33 , ( V_27 |
( V_42 << V_43 ) ) ,
~ ( V_27 | V_44 ) ) ;
}
}
static int F_16 ( struct V_1 * V_2 , int V_45 , int V_46 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_47 = 0 , V_48 = 0 ;
int V_49 = V_8 -> V_50 ;
V_8 -> V_51 = V_45 ;
V_8 -> V_52 = V_46 ;
if ( F_6 ( V_5 ) ) {
V_45 += V_2 -> V_45 ;
V_46 += V_2 -> V_46 ;
}
if ( V_45 < 0 )
V_47 = F_17 ( - V_45 , V_8 -> V_53 - 1 ) ;
if ( V_46 < 0 )
V_48 = F_17 ( - V_46 , V_8 -> V_54 - 1 ) ;
if ( ! F_6 ( V_5 ) ) {
V_45 += V_2 -> V_45 ;
V_46 += V_2 -> V_46 ;
}
F_18 ( L_1 , V_45 , V_46 , V_2 -> V_45 , V_2 -> V_46 ) ;
if ( F_6 ( V_5 ) && ! F_19 ( V_5 ) ) {
int V_55 = 0 ;
struct V_1 * V_56 ;
F_20 (crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if ( V_56 -> V_57 )
V_55 ++ ;
}
if ( V_55 > 1 ) {
int V_58 , V_59 ;
V_58 = V_45 + V_49 ;
V_59 = V_2 -> V_45 + V_2 -> V_60 . V_61 ;
if ( V_58 >= V_59 ) {
V_49 = V_49 - ( V_58 - V_59 ) ;
if ( ! ( V_59 & 0x7f ) )
V_49 -- ;
} else if ( V_58 <= 0 ) {
goto V_62;
} else if ( ! ( V_58 & 0x7f ) ) {
V_49 -- ;
}
if ( V_49 <= 0 ) {
goto V_62;
}
}
}
if ( V_45 <= ( V_2 -> V_45 - V_49 ) || V_46 <= ( V_2 -> V_46 - V_8 -> V_63 ) ||
V_45 >= ( V_2 -> V_45 + V_2 -> V_60 . V_64 ) ||
V_46 >= ( V_2 -> V_46 + V_2 -> V_60 . V_65 ) )
goto V_62;
V_45 += V_47 ;
V_46 += V_48 ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_66 + V_8 -> V_11 , ( V_45 << 16 ) | V_46 ) ;
F_5 ( V_67 + V_8 -> V_11 , ( V_47 << 16 ) | V_48 ) ;
F_5 ( V_68 + V_8 -> V_11 ,
( ( V_49 - 1 ) << 16 ) | ( V_8 -> V_63 - 1 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_69 + V_8 -> V_11 , ( V_45 << 16 ) | V_46 ) ;
F_5 ( V_70 + V_8 -> V_11 , ( V_47 << 16 ) | V_48 ) ;
F_5 ( V_71 + V_8 -> V_11 ,
( ( V_49 - 1 ) << 16 ) | ( V_8 -> V_63 - 1 ) ) ;
} else {
V_45 -= V_2 -> V_45 ;
V_46 -= V_2 -> V_46 ;
if ( V_2 -> V_60 . V_72 & V_73 )
V_46 *= 2 ;
F_5 ( V_74 + V_8 -> V_11 ,
( V_16
| ( V_47 << 16 )
| V_48 ) ) ;
F_5 ( V_75 + V_8 -> V_11 ,
( V_16
| ( V_45 << 16 )
| V_46 ) ) ;
F_5 ( V_15 + V_8 -> V_11 ,
V_8 -> V_30 - V_8 -> V_41 +
V_48 * 256 ) ;
}
if ( V_8 -> V_28 ) {
V_8 -> V_28 = false ;
if ( V_8 -> V_76 )
F_12 ( V_2 ) ;
}
return 0 ;
V_62:
if ( ! V_8 -> V_28 ) {
F_7 ( V_2 ) ;
V_8 -> V_28 = true ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
int V_45 , int V_46 )
{
int V_77 ;
F_1 ( V_2 , true ) ;
V_77 = F_16 ( V_2 , V_45 , V_46 ) ;
F_1 ( V_2 , false ) ;
return V_77 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_78 * V_79 ,
T_1 V_80 ,
T_1 V_81 ,
T_1 V_82 ,
T_3 V_83 ,
T_3 V_84 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
int V_77 ;
if ( ! V_80 ) {
F_7 ( V_2 ) ;
V_86 = NULL ;
goto V_89;
}
if ( ( V_81 > V_8 -> V_53 ) ||
( V_82 > V_8 -> V_54 ) ) {
F_23 ( L_2 , V_81 , V_82 ) ;
return - V_90 ;
}
V_86 = F_24 ( V_79 , V_80 ) ;
if ( ! V_86 ) {
F_23 ( L_3 , V_80 , V_8 -> V_24 ) ;
return - V_91 ;
}
V_88 = F_25 ( V_86 ) ;
V_77 = F_26 ( V_88 , false ) ;
if ( V_77 != 0 ) {
F_27 ( V_86 ) ;
return V_77 ;
}
V_77 = F_28 ( V_88 , V_92 ,
F_6 ( V_5 ) ? 0 : 1 << 27 ,
& V_8 -> V_30 ) ;
F_29 ( V_88 ) ;
if ( V_77 ) {
F_23 ( L_4 , V_77 ) ;
F_27 ( V_86 ) ;
return V_77 ;
}
F_1 ( V_2 , true ) ;
if ( V_81 != V_8 -> V_50 ||
V_82 != V_8 -> V_63 ||
V_83 != V_8 -> V_93 ||
V_84 != V_8 -> V_94 ) {
int V_45 , V_46 ;
V_45 = V_8 -> V_51 + V_8 -> V_93 - V_83 ;
V_46 = V_8 -> V_52 + V_8 -> V_94 - V_84 ;
V_8 -> V_50 = V_81 ;
V_8 -> V_63 = V_82 ;
V_8 -> V_93 = V_83 ;
V_8 -> V_94 = V_84 ;
F_16 ( V_2 , V_45 , V_46 ) ;
}
F_12 ( V_2 ) ;
F_1 ( V_2 , false ) ;
V_89:
if ( V_8 -> V_76 ) {
struct V_87 * V_88 = F_25 ( V_8 -> V_76 ) ;
V_77 = F_26 ( V_88 , false ) ;
if ( F_30 ( V_77 == 0 ) ) {
F_31 ( V_88 ) ;
F_29 ( V_88 ) ;
}
F_27 ( V_8 -> V_76 ) ;
}
V_8 -> V_76 = V_86 ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_76 ) {
F_1 ( V_2 , true ) ;
F_16 ( V_2 , V_8 -> V_51 ,
V_8 -> V_52 ) ;
F_12 ( V_2 ) ;
F_1 ( V_2 , false ) ;
}
}
