static T_1 F_1 ( const struct V_1 * V_2 ,
int V_3 , int V_4 ,
int V_5 , bool V_6 )
{
T_1 V_7 ;
T_1 V_8 , V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
T_1 V_16 , V_17 , V_18 , V_19 ;
T_1 V_20 , V_21 ;
T_1 V_22 ;
T_1 V_23 , V_24 ;
T_1 V_25 ;
T_1 V_26 ;
switch ( V_3 ) {
default:
case V_27 :
case V_28 :
V_7 = 24 ;
break;
case V_29 :
V_7 = 18 ;
break;
case V_30 :
V_7 = 16 ;
break;
}
V_8 = V_2 -> V_31 ;
V_9 = V_2 -> V_32 ;
V_10 = V_2 -> V_33 - V_2 -> V_31 ;
V_11 = V_2 -> V_34 - V_2 -> V_33 ;
V_12 = V_2 -> V_35 - V_2 -> V_34 ;
V_13 = V_2 -> V_36 - V_2 -> V_32 ;
V_14 = V_2 -> V_37 - V_2 -> V_36 ;
V_15 = V_2 -> V_38 - V_2 -> V_37 ;
V_16 = F_2 ( V_11 * V_7 , 8 ) ;
V_17 = F_2 ( V_12 * V_7 , 8 ) ;
V_18 = F_2 ( V_8 * V_7 , 8 ) ;
V_19 = F_2 ( V_10 * V_7 , 8 ) ;
V_20 = V_39 + V_16 +
V_40 + V_41 +
V_17 + V_42 +
V_18 + V_43 +
V_19 + V_44 ;
if ( V_6 && V_4 == V_45 )
V_20 += V_46 ;
V_21 = V_14 * V_20 + V_15 * V_20 +
V_9 * V_20 + V_13 * V_20 ;
if ( V_6 &&
( V_4 == V_47 ||
V_4 == V_48 ) )
V_21 += V_46 ;
V_22 = F_3 ( V_2 ) ;
V_23 = V_22 * V_21 ;
V_24 = V_23 / V_5 ;
V_25 = V_24 * 8 ;
V_26 = V_25 / 1000 ;
if ( V_6 && V_4 == V_45 )
V_26 *= 2 ;
return V_26 ;
}
static T_1 F_4 ( const struct V_1 * V_2 ,
int V_3 , int V_5 )
{
T_1 V_49 ;
T_1 V_7 ;
switch ( V_3 ) {
default:
case V_27 :
case V_28 :
V_7 = 24 ;
break;
case V_29 :
V_7 = 18 ;
break;
case V_30 :
V_7 = 16 ;
break;
}
V_49 = F_5 ( V_2 -> clock * V_7 , V_5 ) ;
return V_49 ;
}
static int F_6 ( T_1 V_26 , struct V_50 * V_50 )
{
T_1 V_51 , V_52 , V_53 ;
T_1 V_54 ;
T_1 error ;
T_1 V_55 ;
int V_56 ;
int V_57 ;
T_1 V_58 ;
T_1 V_59 ;
T_1 V_60 ;
if ( V_26 < 300000 || V_26 > 1150000 ) {
F_7 ( L_1 ) ;
return - V_61 ;
}
V_54 = 25000 ;
V_56 = V_26 ;
error = 0xFFFFFFFF ;
V_55 = 0xFFFFFFFF ;
V_58 = 0 ;
V_59 = 0 ;
for ( V_51 = 62 ; V_51 <= 92 ; V_51 ++ ) {
for ( V_53 = 2 ; V_53 <= 6 ; V_53 ++ ) {
V_57 = ( V_51 * V_54 ) / V_53 ;
if ( V_57 == V_56 ) {
V_58 = V_51 ;
V_59 = V_53 ;
error = 0 ;
break;
} else
V_55 = abs ( V_56 - V_57 ) ;
if ( V_55 < error ) {
error = V_55 ;
V_58 = V_51 ;
V_59 = V_53 ;
}
}
if ( error == 0 )
break;
}
V_60 = V_62 [ V_58 - 62 ] ;
V_52 = 1 ;
V_50 -> V_63 = 1 << ( V_64 + V_59 - 2 ) ;
V_50 -> V_65 = ( V_52 - 1 ) << V_66 |
V_60 << V_67 ;
return 0 ;
}
static void F_8 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = V_69 -> V_72 . V_73 -> V_74 ;
struct V_75 * V_75 = F_9 ( V_69 -> V_72 . V_76 ) ;
const struct V_1 * V_2 = & V_75 -> V_77 . V_78 ;
struct V_79 * V_79 = F_10 ( & V_69 -> V_72 ) ;
int V_80 ;
struct V_50 V_50 ;
T_1 V_26 ;
V_26 = F_4 ( V_2 , V_79 -> V_3 ,
V_79 -> V_5 ) ;
V_80 = F_6 ( V_26 , & V_50 ) ;
if ( V_80 ) {
F_11 ( L_2 ) ;
return;
}
V_50 . V_63 |= V_81 ;
F_11 ( L_3 ,
V_50 . V_65 , V_50 . V_63 ) ;
F_12 ( V_71 , V_82 , 0 ) ;
F_12 ( V_71 , V_83 , V_50 . V_65 ) ;
F_12 ( V_71 , V_82 , V_50 . V_63 ) ;
}
void F_13 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = V_69 -> V_72 . V_73 -> V_74 ;
T_1 V_84 ;
F_11 ( L_4 ) ;
F_14 ( & V_71 -> V_85 ) ;
F_8 ( V_69 ) ;
F_15 ( 1 , 10 ) ;
V_84 = F_16 ( V_71 , V_82 ) ;
V_84 |= V_86 ;
F_12 ( V_71 , V_82 , V_84 ) ;
F_17 ( & V_71 -> V_85 ) ;
if ( F_18 ( F_19 ( F_20 ( V_87 ) ) & V_88 , 20 ) ) {
F_7 ( L_5 ) ;
return;
}
F_11 ( L_6 ) ;
}
void F_21 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = V_69 -> V_72 . V_73 -> V_74 ;
T_1 V_84 ;
F_11 ( L_4 ) ;
F_14 ( & V_71 -> V_85 ) ;
V_84 = F_16 ( V_71 , V_82 ) ;
V_84 &= ~ V_86 ;
V_84 |= V_89 ;
F_12 ( V_71 , V_82 , V_84 ) ;
F_17 ( & V_71 -> V_85 ) ;
}
