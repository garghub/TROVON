T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
return F_3 ( V_2 , V_5 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 ,
T_1 V_8 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
F_6 ( V_2 , V_5 , V_7 , V_8 ) ;
}
void F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_7 , T_1 V_8 )
{
F_2 ( V_2 , V_9 , V_3 ) ;
F_3 ( V_2 , V_9 ) ;
F_6 ( V_2 , V_10 , V_7 , V_8 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 ,
T_1 V_8 )
{
F_2 ( V_2 , V_11 , V_3 ) ;
F_3 ( V_2 , V_11 ) ;
F_6 ( V_2 , V_12 , V_7 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
T_1 V_16 = 0 , V_17 = 0 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_20 :
V_16 = 0x200D ;
V_17 = 0xFFFF ;
break;
default:
F_10 ( V_14 , L_1 ,
V_14 -> V_18 . V_19 ) ;
}
if ( V_16 )
F_2 ( V_2 , V_21 , V_16 ) ;
if ( V_17 )
F_2 ( V_2 , V_22 , V_17 ) ;
F_11 ( 2 ) ;
}
void F_12 ( struct V_1 * V_2 , bool V_23 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
T_1 V_24 ;
V_24 = F_3 ( V_2 , V_25 ) ;
if ( V_23 ) {
V_24 |= V_26 ;
if ( V_14 -> V_18 . V_27 == 9 || V_14 -> V_18 . V_27 == 11 )
V_24 |= V_28 ;
else if ( V_14 -> V_18 . V_29 > 0 )
V_24 |= V_30 ;
} else {
V_24 &= ~ V_26 ;
V_24 &= ~ V_30 ;
V_24 &= ~ V_28 ;
}
F_2 ( V_2 , V_25 , V_24 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_20 :
F_7 ( V_2 , 0 ,
~ V_31 ,
V_31 ) ;
break;
case V_32 :
case V_33 :
F_12 ( V_2 , true ) ;
break;
case V_34 :
case V_35 :
if ( V_14 -> V_18 . V_29 == 0 ) {
F_6 ( V_2 , V_25 ,
~ V_36 ,
V_36 ) ;
F_7 ( V_2 , 0 ,
~ V_37 ,
V_37 ) ;
} else {
F_7 ( V_2 , 0 ,
~ V_38 ,
V_38 ) ;
}
break;
default:
F_10 ( V_14 , L_2 ,
V_14 -> V_18 . V_19 ) ;
}
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_39 ;
V_39 = F_3 ( V_2 , V_40 ) ;
V_2 -> V_41 . V_29 = ( V_39 & V_42 ) ;
F_10 ( V_2 -> V_15 -> V_14 , L_3 ,
V_2 -> V_41 . V_29 , V_39 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 . V_29 == 1 )
F_16 ( V_2 , V_43 ,
~ V_44 ) ;
else
F_17 ( V_2 , V_43 ,
V_44 ) ;
F_9 ( V_2 ) ;
F_13 ( V_2 ) ;
}
T_1 F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_20 :
case V_34 :
case V_45 :
case V_46 :
case V_47 :
case V_32 :
case V_35 :
case V_48 :
case V_33 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
return 20000 * 1000 ;
case V_56 :
case V_57 :
return 25000 * 1000 ;
case V_58 :
case V_59 :
case V_60 :
if ( V_2 -> V_61 & V_62 )
return 40000 * 1000 ;
else
return 20000 * 1000 ;
default:
F_19 ( V_14 , L_4 ,
V_14 -> V_18 . V_19 , V_2 -> V_41 . V_29 , V_63 ) ;
}
return V_63 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_1 V_64 , T_1 V_65 )
{
T_1 V_66 , div , V_67 , V_68 , V_69 , V_70 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
F_21 ( ( V_64 & 3 ) || ( V_64 > V_71 ) ) ;
F_21 ( ! V_65 || V_65 > 4 ) ;
if ( V_14 -> V_18 . V_19 == V_53 ||
V_14 -> V_18 . V_19 == V_52 ) {
V_66 = F_3 ( V_2 , V_72 ) ;
if ( V_66 & 0x40000 )
return 133 * 1000000 ;
}
V_66 = F_1 ( V_2 , V_64 + V_73 ) ;
V_68 = ( V_66 & V_74 ) >> V_75 ;
V_69 = ( V_66 & V_76 ) >> V_77 ;
V_66 = F_1 ( V_2 , V_64 + V_78 ) ;
div = ( V_66 >> ( ( V_65 - 1 ) * V_79 ) ) &
V_80 ;
V_66 = F_1 ( V_2 , V_64 + V_81 ) ;
V_67 = ( V_66 & V_82 ) >> V_83 ;
V_70 = F_18 ( V_2 ) / 1000000 ;
V_70 = ( V_68 * V_67 * V_70 ) / V_69 ;
return ( V_70 / div ) * 1000000 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_1 V_64 , T_1 V_65 )
{
T_1 V_66 , V_67 , V_84 , V_85 ;
T_1 clock ;
F_21 ( ! V_65 || V_65 > 4 ) ;
V_66 = F_1 ( V_2 , V_64 + V_86 ) ;
V_67 = ( V_66 & V_87 )
>> V_88 ;
V_84 = ( V_66 & V_89 )
>> V_90 ;
V_85 = ( V_66 & V_91 )
>> V_92 ;
V_66 = F_3 ( V_2 , V_72 ) ;
if ( V_66 & V_93 )
clock = ( 25000000 / 4 ) * V_67 * V_85 / V_84 ;
else
clock = ( 25000000 / 2 ) * V_67 * V_85 / V_84 ;
if ( V_65 == V_94 )
clock = clock / 4 ;
return clock ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_49 :
case V_51 :
case V_50 :
return F_20 ( V_2 , V_71 ,
V_94 ) ;
case V_57 :
return F_20 ( V_2 , V_95 ,
V_94 ) ;
case V_53 :
case V_52 :
return F_20 ( V_2 , V_96 ,
V_94 ) ;
case V_56 :
return F_22 ( V_2 ,
V_97 ,
V_94 ) ;
case V_54 :
return 75000000 ;
default:
F_19 ( V_14 , L_5 ,
V_14 -> V_18 . V_19 , V_2 -> V_41 . V_29 , V_98 ) ;
}
return V_98 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
if ( V_14 -> V_18 . V_19 == V_54 )
return 300000000 ;
if ( V_2 -> V_41 . V_29 >= 5 ) {
T_1 V_99 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_56 :
return F_22 ( V_2 ,
V_97 ,
V_100 ) ;
case V_57 :
V_99 = V_95 ;
break;
case V_53 :
case V_52 :
V_99 = V_96 ;
break;
default:
V_99 = V_71 ;
break;
}
return F_20 ( V_2 , V_99 , V_100 ) ;
}
return F_23 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
void F_26 ( struct V_1 * V_2 , int V_101 )
{
T_1 V_66 = 0 ;
T_2 V_102 = 0 ;
T_2 V_103 [] = { 0x1 , 0x5 , 0x5 } ;
T_2 V_104 [] = { 0x30 , 0xf6 , 0xfc } ;
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_53 :
case V_52 :
case V_54 :
V_102 = ( V_14 -> V_18 . V_19 == V_53 ||
V_14 -> V_18 . V_19 == V_52 ||
V_14 -> V_18 . V_19 == V_54 ) ? 6 : 0 ;
F_2 ( V_2 , V_4 ,
V_105 + V_102 ) ;
V_66 = F_3 ( V_2 , V_5 ) ;
V_66 &= ( ~ ( V_106 ) ) ;
V_66 |= ( V_103 [ V_101 ] << V_107 ) ;
F_2 ( V_2 , V_5 , V_66 ) ;
F_2 ( V_2 , V_4 ,
V_108 + V_102 ) ;
V_66 = F_3 ( V_2 , V_5 ) ;
V_66 &= ~ ( V_109 ) ;
V_66 |= ( V_104 [ V_101 ] ) << V_110 ;
F_2 ( V_2 , V_5 , V_66 ) ;
V_66 = V_111 ;
break;
case V_32 :
case V_33 :
if ( V_101 == 2 ) {
F_25 ( V_2 , V_105 ,
0x11500014 ) ;
F_25 ( V_2 , V_108 ,
0x0FC00a08 ) ;
} else if ( V_101 == 1 ) {
F_25 ( V_2 , V_105 ,
0x11500014 ) ;
F_25 ( V_2 , V_108 ,
0x0F600a08 ) ;
} else {
F_25 ( V_2 , V_105 ,
0x11100014 ) ;
F_25 ( V_2 , V_108 ,
0x03000a08 ) ;
}
V_66 = V_111 ;
break;
case V_34 :
case V_45 :
case V_35 :
if ( V_101 == 1 ) {
F_25 ( V_2 , V_105 ,
0x11500010 ) ;
F_25 ( V_2 , V_112 ,
0x000C0C06 ) ;
F_25 ( V_2 , V_108 ,
0x0F600a08 ) ;
F_25 ( V_2 , V_113 ,
0x00000000 ) ;
F_25 ( V_2 , V_114 ,
0x2001E920 ) ;
F_25 ( V_2 , V_115 ,
0x88888815 ) ;
} else {
F_25 ( V_2 , V_105 ,
0x11100010 ) ;
F_25 ( V_2 , V_112 ,
0x000c0c06 ) ;
F_25 ( V_2 , V_108 ,
0x03000a08 ) ;
F_25 ( V_2 , V_113 ,
0x00000000 ) ;
F_25 ( V_2 , V_114 ,
0x200005c0 ) ;
F_25 ( V_2 , V_115 ,
0x88888815 ) ;
}
V_66 = V_111 ;
break;
case V_49 :
case V_51 :
case V_50 :
if ( V_101 == 1 ) {
F_25 ( V_2 , V_105 ,
0x11500060 ) ;
F_25 ( V_2 , V_112 ,
0x080C0C06 ) ;
F_25 ( V_2 , V_108 ,
0x0F600000 ) ;
F_25 ( V_2 , V_113 ,
0x00000000 ) ;
F_25 ( V_2 , V_114 ,
0x2001E924 ) ;
F_25 ( V_2 , V_115 ,
0x88888815 ) ;
} else {
F_25 ( V_2 , V_105 ,
0x11100060 ) ;
F_25 ( V_2 , V_112 ,
0x080c0c06 ) ;
F_25 ( V_2 , V_108 ,
0x03000000 ) ;
F_25 ( V_2 , V_113 ,
0x00000000 ) ;
F_25 ( V_2 , V_114 ,
0x200005c0 ) ;
F_25 ( V_2 , V_115 ,
0x88888815 ) ;
}
V_66 = V_111 | V_44 ;
break;
case V_46 :
case V_47 :
case V_48 :
if ( V_101 == 1 ) {
F_25 ( V_2 , V_105 ,
0x01100014 ) ;
F_25 ( V_2 , V_112 ,
0x040C0C06 ) ;
F_25 ( V_2 , V_108 ,
0x03140A08 ) ;
F_25 ( V_2 , V_113 ,
0x00333333 ) ;
F_25 ( V_2 , V_114 ,
0x202C2820 ) ;
F_25 ( V_2 , V_115 ,
0x88888815 ) ;
} else {
F_25 ( V_2 , V_105 ,
0x11100014 ) ;
F_25 ( V_2 , V_112 ,
0x040c0c06 ) ;
F_25 ( V_2 , V_108 ,
0x03000a08 ) ;
F_25 ( V_2 , V_113 ,
0x00000000 ) ;
F_25 ( V_2 , V_114 ,
0x200005c0 ) ;
F_25 ( V_2 , V_115 ,
0x88888815 ) ;
}
V_66 = V_111 ;
break;
default:
F_27 ( V_14 , L_6 ,
V_14 -> V_18 . V_19 ) ;
break;
}
V_66 |= F_3 ( V_2 , V_43 ) ;
F_2 ( V_2 , V_43 , V_66 ) ;
}
