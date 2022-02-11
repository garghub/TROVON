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
static T_1 F_4 ( T_1 V_49 , int V_3 , int V_5 )
{
T_1 V_50 ;
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
V_50 = F_5 ( V_49 * V_7 , V_5 ) ;
return V_50 ;
}
static int F_6 ( T_1 V_26 , struct V_51 * V_51 )
{
T_1 V_52 , V_53 , V_54 ;
T_1 V_55 ;
T_1 error ;
T_1 V_56 ;
int V_57 ;
int V_58 ;
T_1 V_59 ;
T_1 V_60 ;
T_1 V_61 ;
if ( V_26 < 300000 || V_26 > 1150000 ) {
F_7 ( L_1 ) ;
return - V_62 ;
}
V_55 = 25000 ;
V_57 = V_26 ;
error = 0xFFFFFFFF ;
V_56 = 0xFFFFFFFF ;
V_59 = 0 ;
V_60 = 0 ;
for ( V_52 = 62 ; V_52 <= 92 ; V_52 ++ ) {
for ( V_54 = 2 ; V_54 <= 6 ; V_54 ++ ) {
V_58 = ( V_52 * V_55 ) / V_54 ;
if ( V_58 == V_57 ) {
V_59 = V_52 ;
V_60 = V_54 ;
error = 0 ;
break;
} else
V_56 = abs ( V_57 - V_58 ) ;
if ( V_56 < error ) {
error = V_56 ;
V_59 = V_52 ;
V_60 = V_54 ;
}
}
if ( error == 0 )
break;
}
V_61 = V_63 [ V_59 - 62 ] ;
V_53 = 1 ;
V_51 -> V_64 = 1 << ( V_65 + V_60 - 2 ) ;
V_51 -> V_66 = ( V_53 - 1 ) << V_67 |
V_61 << V_68 ;
return 0 ;
}
static void F_8 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = V_70 -> V_73 . V_74 -> V_75 ;
struct V_76 * V_76 = F_9 ( & V_70 -> V_73 ) ;
int V_77 ;
struct V_51 V_51 ;
T_1 V_26 ;
V_26 = F_4 ( V_76 -> V_49 , V_76 -> V_3 ,
V_76 -> V_5 ) ;
V_77 = F_6 ( V_26 , & V_51 ) ;
if ( V_77 ) {
F_10 ( L_2 ) ;
return;
}
if ( V_76 -> V_78 & ( 1 << V_79 ) )
V_51 . V_64 |= V_80 ;
if ( V_76 -> V_78 & ( 1 << V_81 ) )
V_51 . V_64 |= V_82 ;
F_10 ( L_3 ,
V_51 . V_66 , V_51 . V_64 ) ;
F_11 ( V_72 , V_83 , 0 ) ;
F_11 ( V_72 , V_84 , V_51 . V_66 ) ;
F_11 ( V_72 , V_83 , V_51 . V_64 ) ;
}
void F_12 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = V_70 -> V_73 . V_74 -> V_75 ;
T_1 V_85 ;
F_10 ( L_4 ) ;
F_13 ( & V_72 -> V_86 ) ;
F_8 ( V_70 ) ;
F_14 ( 1 , 10 ) ;
V_85 = F_15 ( V_72 , V_83 ) ;
V_85 |= V_87 ;
F_11 ( V_72 , V_83 , V_85 ) ;
if ( F_16 ( F_15 ( V_72 , V_83 ) &
V_88 , 20 ) ) {
F_17 ( & V_72 -> V_86 ) ;
F_7 ( L_5 ) ;
return;
}
F_17 ( & V_72 -> V_86 ) ;
F_10 ( L_6 ) ;
}
void F_18 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = V_70 -> V_73 . V_74 -> V_75 ;
T_1 V_85 ;
F_10 ( L_4 ) ;
F_13 ( & V_72 -> V_86 ) ;
V_85 = F_15 ( V_72 , V_83 ) ;
V_85 &= ~ V_87 ;
V_85 |= V_89 ;
F_11 ( V_72 , V_83 , V_85 ) ;
F_17 ( & V_72 -> V_86 ) ;
}
static void F_19 ( int V_3 , int V_90 )
{
int V_7 ;
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
F_20 ( V_7 != V_90 ,
L_7 ,
V_7 , V_90 ) ;
}
T_1 F_21 ( struct V_69 * V_70 , int V_90 )
{
struct V_71 * V_72 = V_70 -> V_73 . V_74 -> V_75 ;
struct V_76 * V_76 = F_9 ( & V_70 -> V_73 ) ;
T_1 V_91 , V_49 ;
T_1 V_92 , V_93 ;
T_1 V_52 = 0 , V_54 = 0 ;
int V_94 = 25000 ;
int V_95 ;
F_10 ( L_4 ) ;
F_13 ( & V_72 -> V_86 ) ;
V_92 = F_15 ( V_72 , V_83 ) ;
V_93 = F_15 ( V_72 , V_84 ) ;
F_17 ( & V_72 -> V_86 ) ;
V_92 &= V_96 ;
V_92 = V_92 >> ( V_65 - 2 ) ;
V_93 &= V_97 ;
V_93 = V_93 >> V_68 ;
while ( V_92 ) {
V_92 = V_92 >> 1 ;
V_54 ++ ;
}
V_54 -- ;
if ( ! V_54 ) {
F_7 ( L_8 ) ;
return 0 ;
}
for ( V_95 = 0 ; V_95 < F_22 ( V_63 ) ; V_95 ++ ) {
if ( V_63 [ V_95 ] == V_93 )
break;
}
if ( V_95 == F_22 ( V_63 ) ) {
F_7 ( L_9 ) ;
return 0 ;
}
V_52 = V_95 + 62 ;
V_91 = ( V_52 * V_94 ) / V_54 ;
F_19 ( V_76 -> V_3 , V_90 ) ;
V_49 = F_5 ( V_91 * V_76 -> V_5 , V_90 ) ;
return V_49 ;
}
