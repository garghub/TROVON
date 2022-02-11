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
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_33 * V_34 ;
struct V_50 * V_51 ;
T_2 V_35 ;
int V_52 ;
if ( ! V_47 ) {
F_7 ( V_2 ) ;
V_34 = NULL ;
goto V_53;
}
if ( ( V_48 > V_54 ) || ( V_49 > V_55 ) ) {
F_14 ( L_1 , V_48 , V_49 ) ;
return - V_56 ;
}
V_34 = F_15 ( V_2 -> V_6 , V_46 , V_47 ) ;
if ( ! V_34 ) {
F_14 ( L_2 , V_47 , V_8 -> V_24 ) ;
return - V_57 ;
}
V_51 = F_16 ( V_34 ) ;
V_52 = F_17 ( V_51 , false ) ;
if ( F_18 ( V_52 != 0 ) )
goto V_58;
V_52 = F_19 ( V_51 , V_59 ,
F_6 ( V_5 ) ? 0 : 1 << 27 ,
& V_35 ) ;
F_20 ( V_51 ) ;
if ( V_52 )
goto V_58;
V_8 -> V_60 = V_48 ;
V_8 -> V_61 = V_49 ;
F_1 ( V_2 , true ) ;
F_11 ( V_2 , V_34 , V_35 ) ;
F_10 ( V_2 ) ;
F_1 ( V_2 , false ) ;
V_53:
if ( V_8 -> V_62 ) {
V_51 = F_16 ( V_8 -> V_62 ) ;
V_52 = F_17 ( V_51 , false ) ;
if ( F_21 ( V_52 == 0 ) ) {
F_22 ( V_51 ) ;
F_20 ( V_51 ) ;
}
F_23 ( V_8 -> V_62 ) ;
}
V_8 -> V_62 = V_34 ;
return 0 ;
V_58:
F_23 ( V_34 ) ;
return V_52 ;
}
int F_24 ( struct V_1 * V_2 ,
int V_63 , int V_64 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_65 = 0 , V_66 = 0 ;
int V_67 = V_8 -> V_60 ;
if ( F_6 ( V_5 ) ) {
V_63 += V_2 -> V_63 ;
V_64 += V_2 -> V_64 ;
}
F_25 ( L_3 , V_63 , V_64 , V_2 -> V_63 , V_2 -> V_64 ) ;
if ( V_63 < 0 ) {
V_65 = F_26 ( - V_63 , V_54 - 1 ) ;
V_63 = 0 ;
}
if ( V_64 < 0 ) {
V_66 = F_26 ( - V_64 , V_55 - 1 ) ;
V_64 = 0 ;
}
if ( F_6 ( V_5 ) ) {
int V_68 = 0 ;
struct V_1 * V_69 ;
F_27 (crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if ( V_69 -> V_70 )
V_68 ++ ;
}
if ( V_68 > 1 ) {
int V_71 , V_72 ;
V_71 = V_63 - V_65 + V_67 ;
V_72 = V_2 -> V_63 + V_2 -> V_73 . V_74 ;
if ( V_71 >= V_72 ) {
V_67 = V_67 - ( V_71 - V_72 ) ;
if ( ! ( V_72 & 0x7f ) )
V_67 -- ;
} else {
if ( ! ( V_71 & 0x7f ) )
V_67 -- ;
}
if ( V_67 <= 0 )
V_67 = 1 ;
}
}
F_1 ( V_2 , true ) ;
if ( F_3 ( V_5 ) ) {
F_5 ( V_75 + V_8 -> V_11 , ( V_63 << 16 ) | V_64 ) ;
F_5 ( V_76 + V_8 -> V_11 , ( V_65 << 16 ) | V_66 ) ;
F_5 ( V_77 + V_8 -> V_11 ,
( ( V_67 - 1 ) << 16 ) | ( V_8 -> V_61 - 1 ) ) ;
} else if ( F_6 ( V_5 ) ) {
F_5 ( V_78 + V_8 -> V_11 , ( V_63 << 16 ) | V_64 ) ;
F_5 ( V_79 + V_8 -> V_11 , ( V_65 << 16 ) | V_66 ) ;
F_5 ( V_80 + V_8 -> V_11 ,
( ( V_67 - 1 ) << 16 ) | ( V_8 -> V_61 - 1 ) ) ;
} else {
if ( V_2 -> V_73 . V_81 & V_82 )
V_64 *= 2 ;
F_5 ( V_83 + V_8 -> V_11 ,
( V_16
| ( V_65 << 16 )
| V_66 ) ) ;
F_5 ( V_84 + V_8 -> V_11 ,
( V_16
| ( V_63 << 16 )
| V_64 ) ) ;
F_5 ( V_15 + V_8 -> V_11 , ( V_8 -> V_43 +
( V_66 * 256 ) ) ) ;
}
F_1 ( V_2 , false ) ;
return 0 ;
}
