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
static int F_14 ( struct V_1 * V_2 , int V_35 , int V_36 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_37 = 0 , V_38 = 0 ;
int V_39 = V_8 -> V_40 ;
if ( F_6 ( V_5 ) ) {
V_35 += V_2 -> V_35 ;
V_36 += V_2 -> V_36 ;
}
F_15 ( L_1 , V_35 , V_36 , V_2 -> V_35 , V_2 -> V_36 ) ;
if ( V_35 < 0 ) {
V_37 = F_16 ( - V_35 , V_8 -> V_41 - 1 ) ;
V_35 = 0 ;
}
if ( V_36 < 0 ) {
V_38 = F_16 ( - V_36 , V_8 -> V_42 - 1 ) ;
V_36 = 0 ;
}
if ( F_6 ( V_5 ) && ! F_17 ( V_5 ) ) {
int V_43 = 0 ;
struct V_1 * V_44 ;
F_18 (crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if ( V_44 -> V_45 )
V_43 ++ ;
}
if ( V_43 > 1 ) {
int V_46 , V_47 ;
V_46 = V_35 - V_37 + V_39 ;
V_47 = V_2 -> V_35 + V_2 -> V_48 . V_49 ;
if ( V_46 >= V_47 ) {
V_39 = V_39 - ( V_46 - V_47 ) ;
if ( ! ( V_47 & 0x7f ) )
V_39 -- ;
} else {
if ( ! ( V_46 & 0x7f ) )
V_39 -- ;
}
if ( V_39 <= 0 ) {
V_39 = 1 ;
V_46 = V_35 - V_37 + V_39 ;
if ( ! ( V_46 & 0x7f ) ) {
V_35 -- ;
F_19 ( V_35 < 0 ) ;
}
}
}
}
if ( F_3 ( V_5 ) ) {
F_5 ( V_50 + V_8 -> V_11 , ( V_35 << 16 ) | V_36 ) ;
F_5 ( V_51 + V_8 -> V_11 , ( V_37 << 16 ) | V_38 ) ;
F_5 ( V_52 + V_8 -> V_11 ,
( ( V_39 - 1 ) << 16 ) | ( V_8 -> V_53 - 1 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_54 + V_8 -> V_11 , ( V_35 << 16 ) | V_36 ) ;
F_5 ( V_55 + V_8 -> V_11 , ( V_37 << 16 ) | V_38 ) ;
F_5 ( V_56 + V_8 -> V_11 ,
( ( V_39 - 1 ) << 16 ) | ( V_8 -> V_53 - 1 ) ) ;
} else {
if ( V_2 -> V_48 . V_57 & V_58 )
V_36 *= 2 ;
F_5 ( V_59 + V_8 -> V_11 ,
( V_16
| ( V_37 << 16 )
| V_38 ) ) ;
F_5 ( V_60 + V_8 -> V_11 ,
( V_16
| ( V_35 << 16 )
| V_36 ) ) ;
F_5 ( V_15 + V_8 -> V_11 , ( V_8 -> V_61 +
( V_38 * 256 ) ) ) ;
}
V_8 -> V_62 = V_35 ;
V_8 -> V_63 = V_36 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
int V_35 , int V_36 )
{
int V_64 ;
F_1 ( V_2 , true ) ;
V_64 = F_14 ( V_2 , V_35 , V_36 ) ;
F_1 ( V_2 , false ) ;
return V_64 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_67 * V_68 = F_22 ( V_66 ) ;
T_3 V_69 ;
int V_64 ;
V_64 = F_23 ( V_68 , false ) ;
if ( F_24 ( V_64 != 0 ) )
goto V_70;
V_64 = F_25 ( V_68 , V_71 ,
F_6 ( V_5 ) ? 0 : 1 << 27 ,
& V_69 ) ;
F_26 ( V_68 ) ;
if ( V_64 )
goto V_70;
if ( F_3 ( V_5 ) ) {
F_5 ( V_72 + V_8 -> V_11 ,
F_27 ( V_69 ) ) ;
F_5 ( V_73 + V_8 -> V_11 ,
V_69 & 0xffffffff ) ;
} else if ( F_6 ( V_5 ) ) {
if ( V_5 -> V_74 >= V_75 ) {
if ( V_8 -> V_24 )
F_5 ( V_76 , F_27 ( V_69 ) ) ;
else
F_5 ( V_77 , F_27 ( V_69 ) ) ;
}
F_5 ( V_78 + V_8 -> V_11 ,
V_69 & 0xffffffff ) ;
} else {
V_8 -> V_61 = V_69 - V_8 -> V_79 ;
F_5 ( V_15 + V_8 -> V_11 , V_8 -> V_61 ) ;
}
return 0 ;
V_70:
F_28 ( V_66 ) ;
return V_64 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
T_1 V_82 ,
T_1 V_83 ,
T_1 V_84 ,
T_4 V_85 ,
T_4 V_86 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_65 * V_66 ;
int V_64 ;
if ( ! V_82 ) {
F_7 ( V_2 ) ;
V_66 = NULL ;
goto V_87;
}
if ( ( V_83 > V_8 -> V_41 ) ||
( V_84 > V_8 -> V_42 ) ) {
F_30 ( L_2 , V_83 , V_84 ) ;
return - V_88 ;
}
V_66 = F_31 ( V_2 -> V_6 , V_81 , V_82 ) ;
if ( ! V_66 ) {
F_30 ( L_3 , V_82 , V_8 -> V_24 ) ;
return - V_89 ;
}
V_8 -> V_40 = V_83 ;
V_8 -> V_53 = V_84 ;
F_1 ( V_2 , true ) ;
if ( V_85 != V_8 -> V_90 ||
V_86 != V_8 -> V_91 ) {
int V_35 , V_36 ;
V_35 = V_8 -> V_62 + V_8 -> V_90 - V_85 ;
V_36 = V_8 -> V_63 + V_8 -> V_91 - V_86 ;
F_14 ( V_2 , V_35 , V_36 ) ;
V_8 -> V_90 = V_85 ;
V_8 -> V_91 = V_86 ;
}
V_64 = F_21 ( V_2 , V_66 ) ;
if ( V_64 )
F_30 ( L_4 ,
V_64 ) ;
else
F_12 ( V_2 ) ;
F_1 ( V_2 , false ) ;
V_87:
if ( V_8 -> V_92 ) {
struct V_67 * V_68 = F_22 ( V_8 -> V_92 ) ;
V_64 = F_23 ( V_68 , false ) ;
if ( F_32 ( V_64 == 0 ) ) {
F_33 ( V_68 ) ;
F_26 ( V_68 ) ;
}
if ( V_8 -> V_92 != V_66 )
F_28 ( V_8 -> V_92 ) ;
}
V_8 -> V_92 = V_66 ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
int V_64 ;
if ( V_8 -> V_92 ) {
F_1 ( V_2 , true ) ;
F_14 ( V_2 , V_8 -> V_62 ,
V_8 -> V_63 ) ;
V_64 = F_21 ( V_2 , V_8 -> V_92 ) ;
if ( V_64 )
F_30 ( L_5
L_6 , V_64 ) ;
else
F_12 ( V_2 ) ;
F_1 ( V_2 , false ) ;
}
}
