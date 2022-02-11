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
F_5 ( V_19 , F_8 ( V_20 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_17 , V_21 + V_8 -> V_11 ) ;
F_5 ( V_19 , ( V_22 << V_23 ) ) ;
} else {
switch ( V_8 -> V_24 ) {
case 0 :
F_5 ( V_17 , V_25 ) ;
break;
case 1 :
F_5 ( V_17 , V_26 ) ;
break;
default:
return;
}
F_9 ( V_19 , 0 , ~ V_27 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_17 , V_18 + V_8 -> V_11 ) ;
F_5 ( V_19 , V_28 |
F_8 ( V_20 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_17 , V_21 + V_8 -> V_11 ) ;
F_5 ( V_19 , V_29 |
( V_22 << V_23 ) ) ;
} else {
switch ( V_8 -> V_24 ) {
case 0 :
F_5 ( V_17 , V_25 ) ;
break;
case 1 :
F_5 ( V_17 , V_26 ) ;
break;
default:
return;
}
F_9 ( V_19 , ( V_27 |
( V_30 << V_31 ) ) ,
~ ( V_27 | V_32 ) ) ;
}
}
static void F_11 ( struct V_1 * V_2 , struct V_33 * V_34 ,
T_2 V_35 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_36 + V_8 -> V_11 ,
F_12 ( V_35 ) ) ;
F_5 ( V_37 + V_8 -> V_11 ,
V_35 & 0xffffffff ) ;
} else if ( F_6 ( V_5 ) ) {
if ( V_5 -> V_38 >= V_39 ) {
if ( V_8 -> V_24 )
F_5 ( V_40 , F_12 ( V_35 ) ) ;
else
F_5 ( V_41 , F_12 ( V_35 ) ) ;
}
F_5 ( V_42 + V_8 -> V_11 ,
V_35 & 0xffffffff ) ;
} else {
V_8 -> V_43 = V_35 - V_8 -> V_44 ;
F_5 ( V_15 + V_8 -> V_11 , V_8 -> V_43 ) ;
}
}
int F_13 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_1 V_47 ,
T_1 V_48 ,
T_1 V_49 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 ;
T_2 V_35 ;
int V_50 ;
if ( ! V_47 ) {
F_7 ( V_2 ) ;
V_34 = NULL ;
goto V_51;
}
if ( ( V_48 > V_52 ) || ( V_49 > V_53 ) ) {
F_14 ( L_1 , V_48 , V_49 ) ;
return - V_54 ;
}
V_34 = F_15 ( V_2 -> V_6 , V_46 , V_47 ) ;
if ( ! V_34 ) {
F_14 ( L_2 , V_47 , V_8 -> V_24 ) ;
return - V_55 ;
}
V_50 = F_16 ( V_34 , V_56 , & V_35 ) ;
if ( V_50 )
goto V_57;
V_8 -> V_58 = V_48 ;
V_8 -> V_59 = V_49 ;
F_1 ( V_2 , true ) ;
F_11 ( V_2 , V_34 , V_35 ) ;
F_10 ( V_2 ) ;
F_1 ( V_2 , false ) ;
V_51:
if ( V_8 -> V_60 ) {
F_17 ( V_8 -> V_60 ) ;
F_18 ( V_8 -> V_60 ) ;
}
V_8 -> V_60 = V_34 ;
return 0 ;
V_57:
F_18 ( V_34 ) ;
return V_50 ;
}
int F_19 ( struct V_1 * V_2 ,
int V_61 , int V_62 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_63 = 0 , V_64 = 0 ;
int V_65 = V_8 -> V_58 ;
if ( F_6 ( V_5 ) ) {
V_61 += V_2 -> V_61 ;
V_62 += V_2 -> V_62 ;
}
F_20 ( L_3 , V_61 , V_62 , V_2 -> V_61 , V_2 -> V_62 ) ;
if ( V_61 < 0 ) {
V_63 = F_21 ( - V_61 , V_52 - 1 ) ;
V_61 = 0 ;
}
if ( V_62 < 0 ) {
V_64 = F_21 ( - V_62 , V_53 - 1 ) ;
V_62 = 0 ;
}
if ( F_6 ( V_5 ) ) {
int V_66 = 0 ;
struct V_1 * V_67 ;
F_22 (crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if ( V_67 -> V_68 )
V_66 ++ ;
}
if ( V_66 > 1 ) {
int V_69 , V_70 ;
V_69 = V_61 - V_63 + V_65 ;
V_70 = V_2 -> V_61 + V_2 -> V_71 . V_72 ;
if ( V_69 >= V_70 ) {
V_65 = V_65 - ( V_69 - V_70 ) ;
if ( ! ( V_70 & 0x7f ) )
V_65 -- ;
} else {
if ( ! ( V_69 & 0x7f ) )
V_65 -- ;
}
if ( V_65 <= 0 )
V_65 = 1 ;
}
}
F_1 ( V_2 , true ) ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_73 + V_8 -> V_11 , ( V_61 << 16 ) | V_62 ) ;
F_5 ( V_74 + V_8 -> V_11 , ( V_63 << 16 ) | V_64 ) ;
F_5 ( V_75 + V_8 -> V_11 ,
( ( V_65 - 1 ) << 16 ) | ( V_8 -> V_59 - 1 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_76 + V_8 -> V_11 , ( V_61 << 16 ) | V_62 ) ;
F_5 ( V_77 + V_8 -> V_11 , ( V_63 << 16 ) | V_64 ) ;
F_5 ( V_78 + V_8 -> V_11 ,
( ( V_65 - 1 ) << 16 ) | ( V_8 -> V_59 - 1 ) ) ;
} else {
if ( V_2 -> V_71 . V_79 & V_80 )
V_62 *= 2 ;
F_5 ( V_81 + V_8 -> V_11 ,
( V_16
| ( V_63 << 16 )
| V_64 ) ) ;
F_5 ( V_82 + V_8 -> V_11 ,
( V_16
| ( V_61 << 16 )
| V_62 ) ) ;
F_5 ( V_15 + V_8 -> V_11 , ( V_8 -> V_43 +
( V_64 * 256 ) ) ) ;
}
F_1 ( V_2 , false ) ;
return 0 ;
}
