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
case V_45 :
case V_46 :
case V_47 :
case V_20 :
case V_48 :
case V_49 :
case V_50 :
return 20000 * 1000 ;
case V_51 :
case V_52 :
return 25000 * 1000 ;
default:
F_19 ( V_14 , L_4 ,
V_14 -> V_18 . V_19 , V_2 -> V_41 . V_29 , V_53 ) ;
}
return V_53 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_1 V_54 , T_1 V_55 )
{
T_1 V_56 , div , V_57 , V_58 , V_59 , V_60 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
F_21 ( ( V_54 & 3 ) || ( V_54 > V_61 ) ) ;
F_21 ( ! V_55 || V_55 > 4 ) ;
if ( V_14 -> V_18 . V_19 == V_48 ||
V_14 -> V_18 . V_19 == V_49 ) {
V_56 = F_3 ( V_2 , V_62 ) ;
if ( V_56 & 0x40000 )
return 133 * 1000000 ;
}
V_56 = F_1 ( V_2 , V_54 + V_63 ) ;
V_58 = ( V_56 & V_64 ) >> V_65 ;
V_59 = ( V_56 & V_66 ) >> V_67 ;
V_56 = F_1 ( V_2 , V_54 + V_68 ) ;
div = ( V_56 >> ( ( V_55 - 1 ) * V_69 ) ) &
V_70 ;
V_56 = F_1 ( V_2 , V_54 + V_71 ) ;
V_57 = ( V_56 & V_72 ) >> V_73 ;
V_60 = F_18 ( V_2 ) / 1000000 ;
V_60 = ( V_58 * V_57 * V_60 ) / V_59 ;
return ( V_60 / div ) * 1000000 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_1 V_54 , T_1 V_55 )
{
T_1 V_56 , V_57 , V_74 , V_75 ;
T_1 clock ;
F_21 ( ! V_55 || V_55 > 4 ) ;
V_56 = F_1 ( V_2 , V_54 + V_76 ) ;
V_57 = ( V_56 & V_77 )
>> V_78 ;
V_74 = ( V_56 & V_79 )
>> V_80 ;
V_75 = ( V_56 & V_81 )
>> V_82 ;
V_56 = F_3 ( V_2 , V_62 ) ;
if ( V_56 & V_83 )
clock = ( 25000000 / 4 ) * V_57 * V_75 / V_74 ;
else
clock = ( 25000000 / 2 ) * V_57 * V_75 / V_74 ;
if ( V_55 == V_84 )
clock = clock / 4 ;
return clock ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_45 :
case V_46 :
case V_47 :
return F_20 ( V_2 , V_61 ,
V_84 ) ;
case V_51 :
return F_20 ( V_2 , V_85 ,
V_84 ) ;
case V_48 :
case V_49 :
return F_20 ( V_2 , V_86 ,
V_84 ) ;
case V_52 :
return F_22 ( V_2 ,
V_87 ,
V_84 ) ;
case V_50 :
return 75000000 ;
default:
F_19 ( V_14 , L_5 ,
V_14 -> V_18 . V_19 , V_2 -> V_41 . V_29 , V_88 ) ;
}
return V_88 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
if ( V_14 -> V_18 . V_19 == V_50 )
return 300000000 ;
if ( V_2 -> V_41 . V_29 >= 5 ) {
T_1 V_89 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_52 :
return F_22 ( V_2 ,
V_87 ,
V_90 ) ;
case V_51 :
V_89 = V_85 ;
break;
case V_48 :
case V_49 :
V_89 = V_86 ;
break;
default:
V_89 = V_61 ;
break;
}
return F_20 ( V_2 , V_89 , V_90 ) ;
}
return F_23 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
void F_26 ( struct V_1 * V_2 , int V_91 )
{
T_1 V_56 = 0 ;
T_2 V_92 = 0 ;
T_2 V_93 [] = { 0x1 , 0x5 , 0x5 } ;
T_2 V_94 [] = { 0x30 , 0xf6 , 0xfc } ;
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_18 . V_19 ) {
case V_48 :
case V_49 :
case V_50 :
V_92 = ( V_14 -> V_18 . V_19 == V_48 ||
V_14 -> V_18 . V_19 == V_49 ||
V_14 -> V_18 . V_19 == V_50 ) ? 6 : 0 ;
F_2 ( V_2 , V_4 ,
V_95 + V_92 ) ;
V_56 = F_3 ( V_2 , V_5 ) ;
V_56 &= ( ~ ( V_96 ) ) ;
V_56 |= ( V_93 [ V_91 ] << V_97 ) ;
F_2 ( V_2 , V_5 , V_56 ) ;
F_2 ( V_2 , V_4 ,
V_98 + V_92 ) ;
V_56 = F_3 ( V_2 , V_5 ) ;
V_56 &= ~ ( V_99 ) ;
V_56 |= ( V_94 [ V_91 ] ) << V_100 ;
F_2 ( V_2 , V_5 , V_56 ) ;
V_56 = 1 << 10 ;
break;
case V_32 :
case V_33 :
if ( V_91 == 2 ) {
F_25 ( V_2 , V_95 ,
0x11500014 ) ;
F_25 ( V_2 , V_98 ,
0x0FC00a08 ) ;
} else if ( V_91 == 1 ) {
F_25 ( V_2 , V_95 ,
0x11500014 ) ;
F_25 ( V_2 , V_98 ,
0x0F600a08 ) ;
} else {
F_25 ( V_2 , V_95 ,
0x11100014 ) ;
F_25 ( V_2 , V_98 ,
0x03000a08 ) ;
}
V_56 = 1 << 10 ;
break;
case V_34 :
case V_101 :
case V_35 :
if ( V_91 == 1 ) {
F_25 ( V_2 , V_95 ,
0x11500010 ) ;
F_25 ( V_2 , V_102 ,
0x000C0C06 ) ;
F_25 ( V_2 , V_98 ,
0x0F600a08 ) ;
F_25 ( V_2 , V_103 ,
0x00000000 ) ;
F_25 ( V_2 , V_104 ,
0x2001E920 ) ;
F_25 ( V_2 , V_105 ,
0x88888815 ) ;
} else {
F_25 ( V_2 , V_95 ,
0x11100010 ) ;
F_25 ( V_2 , V_102 ,
0x000c0c06 ) ;
F_25 ( V_2 , V_98 ,
0x03000a08 ) ;
F_25 ( V_2 , V_103 ,
0x00000000 ) ;
F_25 ( V_2 , V_104 ,
0x200005c0 ) ;
F_25 ( V_2 , V_105 ,
0x88888815 ) ;
}
V_56 = 1 << 10 ;
break;
case V_45 :
case V_46 :
case V_47 :
if ( V_91 == 1 ) {
F_25 ( V_2 , V_95 ,
0x11500060 ) ;
F_25 ( V_2 , V_102 ,
0x080C0C06 ) ;
F_25 ( V_2 , V_98 ,
0x0F600000 ) ;
F_25 ( V_2 , V_103 ,
0x00000000 ) ;
F_25 ( V_2 , V_104 ,
0x2001E924 ) ;
F_25 ( V_2 , V_105 ,
0x88888815 ) ;
} else {
F_25 ( V_2 , V_95 ,
0x11100060 ) ;
F_25 ( V_2 , V_102 ,
0x080c0c06 ) ;
F_25 ( V_2 , V_98 ,
0x03000000 ) ;
F_25 ( V_2 , V_103 ,
0x00000000 ) ;
F_25 ( V_2 , V_104 ,
0x200005c0 ) ;
F_25 ( V_2 , V_105 ,
0x88888815 ) ;
}
V_56 = 3 << 9 ;
break;
case V_106 :
case V_107 :
case V_108 :
if ( V_91 == 1 ) {
F_25 ( V_2 , V_95 ,
0x01100014 ) ;
F_25 ( V_2 , V_102 ,
0x040C0C06 ) ;
F_25 ( V_2 , V_98 ,
0x03140A08 ) ;
F_25 ( V_2 , V_103 ,
0x00333333 ) ;
F_25 ( V_2 , V_104 ,
0x202C2820 ) ;
F_25 ( V_2 , V_105 ,
0x88888815 ) ;
} else {
F_25 ( V_2 , V_95 ,
0x11100014 ) ;
F_25 ( V_2 , V_102 ,
0x040c0c06 ) ;
F_25 ( V_2 , V_98 ,
0x03000a08 ) ;
F_25 ( V_2 , V_103 ,
0x00000000 ) ;
F_25 ( V_2 , V_104 ,
0x200005c0 ) ;
F_25 ( V_2 , V_105 ,
0x88888815 ) ;
}
V_56 = 1 << 10 ;
break;
default:
F_27 ( V_14 , L_6 ,
V_14 -> V_18 . V_19 ) ;
break;
}
V_56 |= F_3 ( V_2 , V_43 ) ;
F_2 ( V_2 , V_43 , V_56 ) ;
}
