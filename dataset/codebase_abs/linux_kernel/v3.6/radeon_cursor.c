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
F_5 ( V_17 , V_18 + V_8 -> V_11 ) ;
F_5 ( V_19 , F_8 ( V_20 ) |
F_9 ( V_21 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_17 , V_22 + V_8 -> V_11 ) ;
F_5 ( V_19 , ( V_23 << V_24 ) ) ;
} else {
switch ( V_8 -> V_25 ) {
case 0 :
F_5 ( V_17 , V_26 ) ;
break;
case 1 :
F_5 ( V_17 , V_27 ) ;
break;
default:
return;
}
F_10 ( V_19 , 0 , ~ V_28 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_17 , V_18 + V_8 -> V_11 ) ;
F_5 ( V_19 , V_29 |
F_8 ( V_20 ) |
F_9 ( V_21 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_17 , V_22 + V_8 -> V_11 ) ;
F_5 ( V_19 , V_30 |
( V_23 << V_24 ) ) ;
} else {
switch ( V_8 -> V_25 ) {
case 0 :
F_5 ( V_17 , V_26 ) ;
break;
case 1 :
F_5 ( V_17 , V_27 ) ;
break;
default:
return;
}
F_10 ( V_19 , ( V_28 |
( V_31 << V_32 ) ) ,
~ ( V_28 | V_33 ) ) ;
}
}
static void F_12 ( struct V_1 * V_2 , struct V_34 * V_35 ,
T_2 V_36 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_37 + V_8 -> V_11 ,
F_13 ( V_36 ) ) ;
F_5 ( V_38 + V_8 -> V_11 ,
V_36 & 0xffffffff ) ;
} else if ( F_6 ( V_5 ) ) {
if ( V_5 -> V_39 >= V_40 ) {
if ( V_8 -> V_25 )
F_5 ( V_41 , F_13 ( V_36 ) ) ;
else
F_5 ( V_42 , F_13 ( V_36 ) ) ;
}
F_5 ( V_43 + V_8 -> V_11 ,
V_36 & 0xffffffff ) ;
} else {
V_8 -> V_44 = V_36 - V_8 -> V_45 ;
F_5 ( V_15 + V_8 -> V_11 , V_8 -> V_44 ) ;
}
}
int F_14 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
T_1 V_48 ,
T_1 V_49 ,
T_1 V_50 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_34 * V_35 ;
struct V_51 * V_52 ;
T_2 V_36 ;
int V_53 ;
if ( ! V_48 ) {
F_7 ( V_2 ) ;
V_35 = NULL ;
goto V_54;
}
if ( ( V_49 > V_55 ) || ( V_50 > V_56 ) ) {
F_15 ( L_1 , V_49 , V_50 ) ;
return - V_57 ;
}
V_35 = F_16 ( V_2 -> V_6 , V_47 , V_48 ) ;
if ( ! V_35 ) {
F_15 ( L_2 , V_48 , V_8 -> V_25 ) ;
return - V_58 ;
}
V_52 = F_17 ( V_35 ) ;
V_53 = F_18 ( V_52 , false ) ;
if ( F_19 ( V_53 != 0 ) )
goto V_59;
V_53 = F_20 ( V_52 , V_60 ,
F_6 ( V_5 ) ? 0 : 1 << 27 ,
& V_36 ) ;
F_21 ( V_52 ) ;
if ( V_53 )
goto V_59;
V_8 -> V_61 = V_49 ;
V_8 -> V_62 = V_50 ;
F_1 ( V_2 , true ) ;
F_12 ( V_2 , V_35 , V_36 ) ;
F_11 ( V_2 ) ;
F_1 ( V_2 , false ) ;
V_54:
if ( V_8 -> V_63 ) {
V_52 = F_17 ( V_8 -> V_63 ) ;
V_53 = F_18 ( V_52 , false ) ;
if ( F_22 ( V_53 == 0 ) ) {
F_23 ( V_52 ) ;
F_21 ( V_52 ) ;
}
F_24 ( V_8 -> V_63 ) ;
}
V_8 -> V_63 = V_35 ;
return 0 ;
V_59:
F_24 ( V_35 ) ;
return V_53 ;
}
int F_25 ( struct V_1 * V_2 ,
int V_64 , int V_65 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_66 = 0 , V_67 = 0 ;
int V_68 = V_8 -> V_61 ;
if ( F_6 ( V_5 ) ) {
V_64 += V_2 -> V_64 ;
V_65 += V_2 -> V_65 ;
}
F_26 ( L_3 , V_64 , V_65 , V_2 -> V_64 , V_2 -> V_65 ) ;
if ( V_64 < 0 ) {
V_66 = F_27 ( - V_64 , V_55 - 1 ) ;
V_64 = 0 ;
}
if ( V_65 < 0 ) {
V_67 = F_27 ( - V_65 , V_56 - 1 ) ;
V_65 = 0 ;
}
if ( F_6 ( V_5 ) ) {
int V_69 = 0 ;
struct V_1 * V_70 ;
F_28 (crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if ( V_70 -> V_71 )
V_69 ++ ;
}
if ( V_69 > 1 ) {
int V_72 , V_73 ;
V_72 = V_64 - V_66 + V_68 ;
V_73 = V_2 -> V_64 + V_2 -> V_74 . V_75 ;
if ( V_72 >= V_73 ) {
V_68 = V_68 - ( V_72 - V_73 ) ;
if ( ! ( V_73 & 0x7f ) )
V_68 -- ;
} else {
if ( ! ( V_72 & 0x7f ) )
V_68 -- ;
}
if ( V_68 <= 0 ) {
V_68 = 1 ;
V_72 = V_64 - V_66 + V_68 ;
if ( ! ( V_72 & 0x7f ) ) {
V_64 -- ;
F_29 ( V_64 < 0 ) ;
}
}
}
}
F_1 ( V_2 , true ) ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_76 + V_8 -> V_11 , ( V_64 << 16 ) | V_65 ) ;
F_5 ( V_77 + V_8 -> V_11 , ( V_66 << 16 ) | V_67 ) ;
F_5 ( V_78 + V_8 -> V_11 ,
( ( V_68 - 1 ) << 16 ) | ( V_8 -> V_62 - 1 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_79 + V_8 -> V_11 , ( V_64 << 16 ) | V_65 ) ;
F_5 ( V_80 + V_8 -> V_11 , ( V_66 << 16 ) | V_67 ) ;
F_5 ( V_81 + V_8 -> V_11 ,
( ( V_68 - 1 ) << 16 ) | ( V_8 -> V_62 - 1 ) ) ;
} else {
if ( V_2 -> V_74 . V_82 & V_83 )
V_65 *= 2 ;
F_5 ( V_84 + V_8 -> V_11 ,
( V_16
| ( V_66 << 16 )
| V_67 ) ) ;
F_5 ( V_85 + V_8 -> V_11 ,
( V_16
| ( V_64 << 16 )
| V_65 ) ) ;
F_5 ( V_15 + V_8 -> V_11 , ( V_8 -> V_44 +
( V_67 * 256 ) ) ) ;
}
F_1 ( V_2 , false ) ;
return 0 ;
}
