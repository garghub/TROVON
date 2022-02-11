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
F_5 ( V_28 + V_8 -> V_11 ,
F_13 ( V_8 -> V_29 ) ) ;
F_5 ( V_30 + V_8 -> V_11 ,
F_14 ( V_8 -> V_29 ) ) ;
F_5 ( V_31 , V_17 + V_8 -> V_11 ) ;
F_5 ( V_32 , V_33 |
F_9 ( V_18 ) |
F_10 ( V_19 ) ) ;
} else if ( F_6 ( V_5 ) ) {
if ( V_5 -> V_34 >= V_35 ) {
if ( V_8 -> V_24 )
F_5 ( V_36 ,
F_13 ( V_8 -> V_29 ) ) ;
else
F_5 ( V_37 ,
F_13 ( V_8 -> V_29 ) ) ;
}
F_5 ( V_38 + V_8 -> V_11 ,
F_14 ( V_8 -> V_29 ) ) ;
F_5 ( V_31 , V_20 + V_8 -> V_11 ) ;
F_5 ( V_32 , V_39 |
( V_21 << V_22 ) ) ;
} else {
F_5 ( V_15 + V_8 -> V_11 ,
V_8 -> V_29 - V_8 -> V_40 ) ;
switch ( V_8 -> V_24 ) {
case 0 :
F_5 ( V_31 , V_25 ) ;
break;
case 1 :
F_5 ( V_31 , V_26 ) ;
break;
default:
return;
}
F_15 ( V_32 , ( V_27 |
( V_41 << V_42 ) ) ,
~ ( V_27 | V_43 ) ) ;
}
}
static int F_16 ( struct V_1 * V_2 , int V_44 , int V_45 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_46 = 0 , V_47 = 0 ;
int V_48 = V_8 -> V_49 ;
if ( F_6 ( V_5 ) ) {
V_44 += V_2 -> V_44 ;
V_45 += V_2 -> V_45 ;
}
F_17 ( L_1 , V_44 , V_45 , V_2 -> V_44 , V_2 -> V_45 ) ;
if ( V_44 < 0 ) {
V_46 = F_18 ( - V_44 , V_8 -> V_50 - 1 ) ;
V_44 = 0 ;
}
if ( V_45 < 0 ) {
V_47 = F_18 ( - V_45 , V_8 -> V_51 - 1 ) ;
V_45 = 0 ;
}
if ( F_6 ( V_5 ) && ! F_19 ( V_5 ) ) {
int V_52 = 0 ;
struct V_1 * V_53 ;
F_20 (crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if ( V_53 -> V_54 )
V_52 ++ ;
}
if ( V_52 > 1 ) {
int V_55 , V_56 ;
V_55 = V_44 - V_46 + V_48 ;
V_56 = V_2 -> V_44 + V_2 -> V_57 . V_58 ;
if ( V_55 >= V_56 ) {
V_48 = V_48 - ( V_55 - V_56 ) ;
if ( ! ( V_56 & 0x7f ) )
V_48 -- ;
} else {
if ( ! ( V_55 & 0x7f ) )
V_48 -- ;
}
if ( V_48 <= 0 ) {
V_48 = 1 ;
V_55 = V_44 - V_46 + V_48 ;
if ( ! ( V_55 & 0x7f ) ) {
V_44 -- ;
F_21 ( V_44 < 0 ) ;
}
}
}
}
if ( F_3 ( V_5 ) ) {
F_5 ( V_59 + V_8 -> V_11 , ( V_44 << 16 ) | V_45 ) ;
F_5 ( V_60 + V_8 -> V_11 , ( V_46 << 16 ) | V_47 ) ;
F_5 ( V_61 + V_8 -> V_11 ,
( ( V_48 - 1 ) << 16 ) | ( V_8 -> V_62 - 1 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_63 + V_8 -> V_11 , ( V_44 << 16 ) | V_45 ) ;
F_5 ( V_64 + V_8 -> V_11 , ( V_46 << 16 ) | V_47 ) ;
F_5 ( V_65 + V_8 -> V_11 ,
( ( V_48 - 1 ) << 16 ) | ( V_8 -> V_62 - 1 ) ) ;
} else {
if ( V_2 -> V_57 . V_66 & V_67 )
V_45 *= 2 ;
F_5 ( V_68 + V_8 -> V_11 ,
( V_16
| ( V_46 << 16 )
| V_47 ) ) ;
F_5 ( V_69 + V_8 -> V_11 ,
( V_16
| ( V_44 << 16 )
| V_45 ) ) ;
F_5 ( V_15 + V_8 -> V_11 ,
V_8 -> V_29 - V_8 -> V_40 +
V_47 * 256 ) ;
}
V_8 -> V_70 = V_44 ;
V_8 -> V_71 = V_45 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
int V_44 , int V_45 )
{
int V_72 ;
F_1 ( V_2 , true ) ;
V_72 = F_16 ( V_2 , V_44 , V_45 ) ;
F_1 ( V_2 , false ) ;
return V_72 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
T_1 V_75 ,
T_1 V_76 ,
T_1 V_77 ,
T_3 V_78 ,
T_3 V_79 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
int V_72 ;
if ( ! V_75 ) {
F_7 ( V_2 ) ;
V_81 = NULL ;
goto V_84;
}
if ( ( V_76 > V_8 -> V_50 ) ||
( V_77 > V_8 -> V_51 ) ) {
F_24 ( L_2 , V_76 , V_77 ) ;
return - V_85 ;
}
V_81 = F_25 ( V_74 , V_75 ) ;
if ( ! V_81 ) {
F_24 ( L_3 , V_75 , V_8 -> V_24 ) ;
return - V_86 ;
}
V_83 = F_26 ( V_81 ) ;
V_72 = F_27 ( V_83 , false ) ;
if ( V_72 != 0 ) {
F_28 ( V_81 ) ;
return V_72 ;
}
V_72 = F_29 ( V_83 , V_87 ,
F_6 ( V_5 ) ? 0 : 1 << 27 ,
& V_8 -> V_29 ) ;
F_30 ( V_83 ) ;
if ( V_72 ) {
F_24 ( L_4 , V_72 ) ;
F_28 ( V_81 ) ;
return V_72 ;
}
V_8 -> V_49 = V_76 ;
V_8 -> V_62 = V_77 ;
F_1 ( V_2 , true ) ;
if ( V_78 != V_8 -> V_88 ||
V_79 != V_8 -> V_89 ) {
int V_44 , V_45 ;
V_44 = V_8 -> V_70 + V_8 -> V_88 - V_78 ;
V_45 = V_8 -> V_71 + V_8 -> V_89 - V_79 ;
F_16 ( V_2 , V_44 , V_45 ) ;
V_8 -> V_88 = V_78 ;
V_8 -> V_89 = V_79 ;
}
F_12 ( V_2 ) ;
F_1 ( V_2 , false ) ;
V_84:
if ( V_8 -> V_90 ) {
struct V_82 * V_83 = F_26 ( V_8 -> V_90 ) ;
V_72 = F_27 ( V_83 , false ) ;
if ( F_31 ( V_72 == 0 ) ) {
F_32 ( V_83 ) ;
F_30 ( V_83 ) ;
}
F_28 ( V_8 -> V_90 ) ;
}
V_8 -> V_90 = V_81 ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_90 ) {
F_1 ( V_2 , true ) ;
F_16 ( V_2 , V_8 -> V_70 ,
V_8 -> V_71 ) ;
F_12 ( V_2 ) ;
F_1 ( V_2 , false ) ;
}
}
