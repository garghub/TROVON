static inline int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 || V_2 -> V_3 == V_5 ;
}
static int F_2 ( struct V_6 * V_7 , int V_8 )
{
if ( V_9 ++ == 0 )
F_3 ( V_7 -> V_10 , 1 ) ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 )
{
if ( -- V_9 == 0 )
F_3 ( V_7 -> V_10 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 , long V_11 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
long V_12 = F_6 ( V_2 -> V_13 , V_14 ) & 0x3f ;
V_12 = ( 14318 * V_12 ) >> 3 ;
F_7 ( V_7 -> V_15 , L_1 , V_12 ) ;
if ( abs ( V_11 - V_12 ) < 250 ) {
F_7 ( V_7 -> V_15 , L_2 ) ;
return 1 ;
} else if ( abs ( V_11 - ( V_12 / 2 ) ) < 250 ) {
F_7 ( V_7 -> V_15 , L_3 ) ;
return 2 ;
}
return 0 ;
}
static int F_8 ( const struct V_16 * V_17 ,
struct V_6 * V_7 )
{
long V_11 ;
long V_18 ;
struct V_1 * V_2 = V_7 -> V_10 ;
unsigned V_19 = V_17 -> V_20 >> 3 ;
V_11 = F_9 ( V_17 -> V_21 ) ;
F_7 ( V_7 -> V_15 , L_4 , V_11 ) ;
V_18 = V_22 [ V_2 -> V_3 ] . V_18 [ V_19 ] ;
V_2 -> V_23 = 0 ;
if ( V_11 > V_18 ) {
F_10 ( V_7 -> V_15 ,
L_5 ,
V_18 ) ;
return - V_24 ;
}
if ( V_17 -> V_20 == 8 ) {
switch ( V_2 -> V_3 ) {
case V_25 :
case V_26 :
case V_27 :
if ( V_11 > 85500 )
V_2 -> V_23 = 1 ;
break;
case V_28 :
if ( V_11 > 135100 )
V_2 -> V_23 = 1 ;
break;
default:
break;
}
}
V_2 -> V_29 = 0 ;
if ( V_2 -> V_3 == V_26 && V_7 -> V_30 . V_31 <= V_32 &&
V_17 -> V_20 == 16 ) {
V_2 -> V_29 = 1 ;
}
return 0 ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_6 * V_7 )
{
int V_33 ;
unsigned V_34 = V_7 -> V_35 * 8 / V_17 -> V_20 ;
struct V_1 * V_2 = V_7 -> V_10 ;
switch ( V_17 -> V_20 ) {
case 1 :
V_17 -> V_36 . V_37 = 0 ;
V_17 -> V_36 . V_38 = 1 ;
V_17 -> V_39 = V_17 -> V_36 ;
V_17 -> V_40 = V_17 -> V_36 ;
break;
case 8 :
V_17 -> V_36 . V_37 = 0 ;
V_17 -> V_36 . V_38 = 8 ;
V_17 -> V_39 = V_17 -> V_36 ;
V_17 -> V_40 = V_17 -> V_36 ;
break;
case 16 :
V_17 -> V_36 . V_37 = 11 ;
V_17 -> V_39 . V_37 = 5 ;
V_17 -> V_40 . V_37 = 0 ;
V_17 -> V_36 . V_38 = 5 ;
V_17 -> V_39 . V_38 = 6 ;
V_17 -> V_40 . V_38 = 5 ;
break;
case 24 :
V_17 -> V_36 . V_37 = 16 ;
V_17 -> V_39 . V_37 = 8 ;
V_17 -> V_40 . V_37 = 0 ;
V_17 -> V_36 . V_38 = 8 ;
V_17 -> V_39 . V_38 = 8 ;
V_17 -> V_40 . V_38 = 8 ;
break;
default:
F_7 ( V_7 -> V_15 ,
L_6 , V_17 -> V_20 ) ;
return - V_24 ;
}
if ( V_17 -> V_41 < V_17 -> V_42 )
V_17 -> V_41 = V_17 -> V_42 ;
if ( V_17 -> V_43 == - 1 ) {
V_17 -> V_43 = V_34 / V_17 -> V_41 ;
F_12 ( V_7 -> V_15 ,
L_7 ,
V_17 -> V_41 , V_17 -> V_43 ) ;
}
if ( V_17 -> V_43 < V_17 -> V_33 )
V_17 -> V_43 = V_17 -> V_33 ;
if ( V_17 -> V_41 * V_17 -> V_43 > V_34 ) {
F_10 ( V_7 -> V_15 , L_8
L_9 ,
V_17 -> V_41 , V_17 -> V_43 ,
V_17 -> V_20 ) ;
return - V_24 ;
}
if ( V_17 -> V_44 > V_17 -> V_41 - V_17 -> V_42 )
V_17 -> V_44 = V_17 -> V_41 - V_17 -> V_42 - 1 ;
if ( V_17 -> V_45 > V_17 -> V_43 - V_17 -> V_33 )
V_17 -> V_45 = V_17 -> V_43 - V_17 -> V_33 - 1 ;
V_17 -> V_36 . V_46 =
V_17 -> V_39 . V_46 =
V_17 -> V_40 . V_46 =
V_17 -> V_47 . V_37 =
V_17 -> V_47 . V_38 =
V_17 -> V_47 . V_46 = 0 ;
V_33 = V_17 -> V_33 ;
if ( V_17 -> V_48 & V_49 )
V_33 *= 2 ;
else if ( V_17 -> V_48 & V_50 )
V_33 = ( V_33 + 1 ) / 2 ;
if ( V_33 >= 1280 ) {
F_10 ( V_7 -> V_15 , L_10
L_11 ) ;
return - V_24 ;
}
if ( F_8 ( V_17 , V_7 ) )
return - V_24 ;
if ( ! F_1 ( V_2 ) )
V_17 -> V_51 = V_52 ;
return 0 ;
}
static void F_13 ( const struct V_6 * V_7 , int div )
{
struct V_1 * V_2 = V_7 -> V_10 ;
unsigned char V_53 , V_54 ;
assert ( V_2 != NULL ) ;
V_53 = F_6 ( V_2 -> V_13 , V_14 ) & ~ 0x40 ;
if ( div ) {
F_7 ( V_7 -> V_15 , L_12 ,
( div == 2 ) ? L_13 : L_14 ) ;
V_53 |= 0x40 ;
V_54 = F_6 ( V_2 -> V_13 , V_55 ) & ~ 0x1 ;
if ( div == 2 )
V_54 |= 1 ;
F_14 ( V_2 -> V_13 , V_55 , V_54 ) ;
}
F_14 ( V_2 -> V_13 , V_14 , V_53 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_16 * V_17 = & V_7 -> V_17 ;
T_1 T_2 * V_13 = V_2 -> V_13 ;
unsigned char V_56 ;
int V_57 ;
const struct V_58 * V_59 ;
int V_60 , V_61 , V_62 , V_63 ;
int V_33 , V_64 , V_65 , V_66 , V_67 ;
long V_11 ;
int V_68 , V_69 , div ;
unsigned int V_70 = 0 , V_71 = 0 , V_72 = 0 ;
F_7 ( V_7 -> V_15 , L_15 ,
V_17 -> V_42 , V_17 -> V_33 , V_17 -> V_20 ) ;
switch ( V_17 -> V_20 ) {
case 1 :
V_7 -> V_30 . V_73 = V_17 -> V_41 / 8 ;
V_7 -> V_30 . V_74 = V_75 ;
break;
case 8 :
V_7 -> V_30 . V_73 = V_17 -> V_41 ;
V_7 -> V_30 . V_74 = V_76 ;
break;
case 16 :
case 24 :
V_7 -> V_30 . V_73 = V_17 -> V_41 *
V_17 -> V_20 >> 3 ;
V_7 -> V_30 . V_74 = V_77 ;
break;
}
V_7 -> V_30 . type = V_78 ;
F_16 ( V_7 ) ;
V_59 = & V_22 [ V_2 -> V_3 ] ;
V_61 = V_17 -> V_42 + V_17 -> V_79 ;
V_62 = V_61 + V_17 -> V_80 ;
V_63 = ( V_62 + V_17 -> V_81 ) / 8 ;
V_60 = V_17 -> V_42 / 8 ;
V_61 = V_61 / 8 ;
V_62 = V_62 / 8 ;
V_64 = V_17 -> V_33 ;
V_65 = V_64 + V_17 -> V_82 ;
V_66 = V_65 + V_17 -> V_83 ;
V_67 = V_66 + V_17 -> V_84 ;
if ( V_17 -> V_48 & V_49 ) {
V_64 *= 2 ;
V_65 *= 2 ;
V_66 *= 2 ;
V_67 *= 2 ;
} else if ( V_17 -> V_48 & V_50 ) {
V_64 = ( V_64 + 1 ) / 2 ;
V_65 = ( V_65 + 1 ) / 2 ;
V_66 = ( V_66 + 1 ) / 2 ;
V_67 = ( V_67 + 1 ) / 2 ;
}
V_33 = V_64 ;
if ( V_33 >= 1024 ) {
V_67 /= 2 ;
V_65 /= 2 ;
V_66 /= 2 ;
V_64 /= 2 ;
}
V_64 -= 1 ;
V_65 -= 1 ;
V_66 -= 1 ;
V_67 -= 2 ;
if ( V_2 -> V_23 ) {
V_63 /= 2 ;
V_61 /= 2 ;
V_62 /= 2 ;
V_60 /= 2 ;
}
V_63 -= 5 ;
V_60 -= 1 ;
V_61 += 1 ;
V_62 += 1 ;
F_17 ( V_13 , V_85 , 0x20 ) ;
F_7 ( V_7 -> V_15 , L_16 , V_63 ) ;
F_17 ( V_13 , V_86 , V_63 ) ;
F_7 ( V_7 -> V_15 , L_17 , V_60 ) ;
F_17 ( V_13 , V_87 , V_60 ) ;
F_7 ( V_7 -> V_15 , L_18 , V_17 -> V_42 / 8 ) ;
F_17 ( V_13 , V_88 , V_17 -> V_42 / 8 ) ;
F_7 ( V_7 -> V_15 , L_19 , ( V_63 + 5 ) % 32 ) ;
F_17 ( V_13 , V_89 ,
128 + ( ( V_63 + 5 ) % 32 ) ) ;
F_7 ( V_7 -> V_15 , L_20 , V_61 ) ;
F_17 ( V_13 , V_90 , V_61 ) ;
V_56 = V_62 % 32 ;
if ( ( V_63 + 5 ) & 32 )
V_56 += 128 ;
F_7 ( V_7 -> V_15 , L_21 , V_56 ) ;
F_17 ( V_13 , V_91 , V_56 ) ;
F_7 ( V_7 -> V_15 , L_22 , V_67 & 0xff ) ;
F_17 ( V_13 , V_92 , V_67 & 0xff ) ;
V_56 = 16 ;
if ( V_67 & 256 )
V_56 |= 1 ;
if ( V_64 & 256 )
V_56 |= 2 ;
if ( V_65 & 256 )
V_56 |= 4 ;
if ( ( V_64 + 1 ) & 256 )
V_56 |= 8 ;
if ( V_67 & 512 )
V_56 |= 32 ;
if ( V_64 & 512 )
V_56 |= 64 ;
if ( V_65 & 512 )
V_56 |= 128 ;
F_7 ( V_7 -> V_15 , L_23 , V_56 ) ;
F_17 ( V_13 , V_93 , V_56 ) ;
V_56 = 0x40 ;
if ( ( V_64 + 1 ) & 512 )
V_56 |= 0x20 ;
if ( V_17 -> V_48 & V_49 )
V_56 |= 0x80 ;
F_7 ( V_7 -> V_15 , L_24 , V_56 ) ;
F_17 ( V_13 , V_94 , V_56 ) ;
F_7 ( V_7 -> V_15 , L_25 , V_65 & 0xff ) ;
F_17 ( V_13 , V_95 , V_65 & 0xff ) ;
F_7 ( V_7 -> V_15 , L_26 , V_66 % 16 ) ;
F_17 ( V_13 , V_85 , V_66 % 16 + 64 + 32 ) ;
F_7 ( V_7 -> V_15 , L_27 , V_64 & 0xff ) ;
F_17 ( V_13 , V_96 , V_64 & 0xff ) ;
F_7 ( V_7 -> V_15 , L_28 , ( V_64 + 1 ) & 0xff ) ;
F_17 ( V_13 , V_97 , ( V_64 + 1 ) & 0xff ) ;
F_7 ( V_7 -> V_15 , L_29 , V_67 & 0xff ) ;
F_17 ( V_13 , V_98 , V_67 & 0xff ) ;
F_7 ( V_7 -> V_15 , L_30 ) ;
F_17 ( V_13 , V_99 , 0xff ) ;
V_56 = 0 ;
if ( V_17 -> V_48 & V_50 )
V_56 |= 1 ;
if ( ( V_63 + 5 ) & 64 )
V_56 |= 16 ;
if ( ( V_63 + 5 ) & 128 )
V_56 |= 32 ;
if ( V_67 & 256 )
V_56 |= 64 ;
if ( V_67 & 512 )
V_56 |= 128 ;
F_7 ( V_7 -> V_15 , L_31 , V_56 ) ;
F_17 ( V_13 , V_100 , V_56 ) ;
V_11 = F_9 ( V_17 -> V_21 ) ;
if ( V_17 -> V_20 == 24 )
if ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_26 )
V_11 *= 3 ;
if ( V_2 -> V_23 )
V_11 /= 2 ;
if ( V_2 -> V_29 )
V_11 *= 2 ;
F_18 ( V_11 , & V_68 , & V_69 , & div ) ;
F_7 ( V_7 -> V_15 , L_32 ,
V_11 , V_68 , V_69 , div ) ;
if ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_27 ||
V_2 -> V_3 == V_26 ) {
int V_101 = F_5 ( V_7 , V_11 ) ;
if ( V_101 )
V_68 = 0 ;
F_13 ( V_7 , V_101 ) ;
}
if ( F_1 ( V_2 ) ) {
long V_102 = F_19 ( V_2 -> V_103 + 0x3fc ) ;
unsigned char V_104 = F_20 ( V_2 -> V_103 + 0x407 ) ;
unsigned short V_105 ;
if ( V_2 -> V_3 == V_5 ) {
V_105 = F_21 ( V_2 -> V_103 + 0x2c4 ) ;
V_105 &= ~ 0x80 ;
F_22 ( V_105 , V_2 -> V_103 + 0x2c4 ) ;
}
F_23 ( V_102 | 0x10000000l , V_2 -> V_103 + 0x3fc ) ;
F_24 ( V_104 & 0x3f , V_2 -> V_103 + 0x407 ) ;
V_70 = F_21 ( V_2 -> V_103 + 0x402 ) ;
V_72 = F_21 ( V_2 -> V_103 + 0xea ) ;
V_70 &= ~ 0x6800 ;
V_71 = 0 ;
V_72 &= 0xffc0 & 0x3fbf ;
}
if ( V_68 ) {
V_56 = V_69 << 1 ;
if ( div != 0 )
V_56 |= 1 ;
if ( ( V_2 -> V_3 == V_26 ) ||
( V_2 -> V_3 == V_25 ) ||
( V_2 -> V_3 == V_28 ) )
V_56 |= 0x80 ;
if ( F_1 ( V_2 ) ) {
F_14 ( V_13 , V_106 , V_56 ) ;
F_14 ( V_13 , V_55 , V_68 ) ;
} else {
F_14 ( V_13 , V_106 , V_68 ) ;
F_14 ( V_13 , V_55 , V_56 ) ;
}
}
if ( V_33 >= 1024 )
F_17 ( V_13 , V_107 , 0xc7 ) ;
else
F_17 ( V_13 , V_107 , 0xc3 ) ;
if ( V_17 -> V_48 & V_50 )
F_17 ( V_13 , V_108 , V_63 / 2 ) ;
else
F_17 ( V_13 , V_108 , 0x00 ) ;
V_56 = 0x03 | 0xc ;
if ( V_17 -> V_109 & V_110 )
V_56 |= 0x40 ;
if ( V_17 -> V_109 & V_111 )
V_56 |= 0x80 ;
F_25 ( V_2 , V_112 , V_56 ) ;
F_17 ( V_13 , V_113 , 0 ) ;
F_17 ( V_13 , V_114 , 31 ) ;
if ( V_17 -> V_20 == 1 ) {
F_7 ( V_7 -> V_15 , L_33 ) ;
F_26 ( V_13 , V_115 , 0 ) ;
switch ( V_2 -> V_3 ) {
case V_26 :
case V_116 :
case V_117 :
case V_118 :
case V_27 :
case V_25 :
case V_28 :
F_14 ( V_13 , V_119 ,
V_2 -> V_23 ?
V_59 -> V_120 : V_59 -> V_121 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_119 ,
F_6 ( V_13 , V_119 ) & ~ 0x01 ) ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
switch ( V_2 -> V_3 ) {
case V_116 :
case V_118 :
F_14 ( V_13 , V_122 , 0xb0 ) ;
break;
case V_117 :
F_14 ( V_13 , V_122 , 0xd0 ) ;
break;
case V_26 :
case V_27 :
case V_25 :
case V_28 :
case V_4 :
case V_5 :
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
F_25 ( V_2 , V_123 , 0x01 ) ;
if ( V_2 -> V_23 )
F_28 ( V_2 , 0x4a ) ;
else
F_28 ( V_2 , 0 ) ;
F_14 ( V_13 , V_124 , 0x06 ) ;
F_14 ( V_13 , V_125 , 0x01 ) ;
}
else if ( V_17 -> V_20 == 8 ) {
F_7 ( V_7 -> V_15 , L_35 ) ;
switch ( V_2 -> V_3 ) {
case V_26 :
case V_116 :
case V_117 :
case V_118 :
case V_27 :
case V_25 :
case V_28 :
F_14 ( V_13 , V_119 ,
V_2 -> V_23 ?
V_59 -> V_126 : V_59 -> V_127 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_119 ,
F_6 ( V_13 , V_119 ) | 0x01 ) ;
V_72 |= 0x10 ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
switch ( V_2 -> V_3 ) {
case V_116 :
case V_117 :
case V_118 :
F_14 ( V_13 , V_122 , 0xb0 ) ;
break;
case V_27 :
#ifdef F_29
F_14 ( V_13 , V_122 , 0xb8 ) ;
#endif
case V_25 :
case V_26 :
case V_28 :
case V_4 :
case V_5 :
break;
default:
F_27 ( V_7 -> V_15 , L_36 ) ;
break;
}
F_26 ( V_13 , V_115 , 64 ) ;
if ( V_2 -> V_23 )
F_28 ( V_2 , 0x4a ) ;
else
F_28 ( V_2 , 0 ) ;
}
else if ( V_17 -> V_20 == 16 ) {
F_7 ( V_7 -> V_15 , L_37 ) ;
switch ( V_2 -> V_3 ) {
case V_116 :
case V_118 :
F_14 ( V_13 , V_119 , 0x87 ) ;
F_14 ( V_13 , V_122 , 0xb0 ) ;
break;
case V_117 :
F_14 ( V_13 , V_119 , 0x27 ) ;
F_14 ( V_13 , V_122 , 0xb0 ) ;
break;
case V_26 :
case V_27 :
case V_25 :
F_14 ( V_13 , V_119 ,
V_2 -> V_29 ? 0xa3 : 0xa7 ) ;
break;
case V_28 :
F_14 ( V_13 , V_119 , 0x17 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_119 ,
F_6 ( V_13 , V_119 ) & ~ 0x01 ) ;
V_70 |= 0x2000 ;
V_71 |= 0x1400 ;
V_72 |= 0x10 ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
F_26 ( V_13 , V_115 , 64 ) ;
#ifdef F_30
F_28 ( V_2 , V_2 -> V_29 ? 0xe1 : 0xc1 ) ;
#elif F_31 ( F_29 )
F_28 ( V_2 , 0xa0 ) ;
#endif
}
else if ( V_17 -> V_20 == 24 ) {
F_7 ( V_7 -> V_15 , L_38 ) ;
switch ( V_2 -> V_3 ) {
case V_116 :
case V_118 :
F_14 ( V_13 , V_119 , 0x85 ) ;
F_14 ( V_13 , V_122 , 0xb0 ) ;
break;
case V_117 :
F_14 ( V_13 , V_119 , 0x25 ) ;
F_14 ( V_13 , V_122 , 0xb0 ) ;
break;
case V_26 :
case V_27 :
case V_25 :
F_14 ( V_13 , V_119 , 0xa5 ) ;
break;
case V_28 :
F_14 ( V_13 , V_119 , 0x15 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_119 ,
F_6 ( V_13 , V_119 ) & ~ 0x01 ) ;
V_70 |= 0x4000 ;
V_71 |= 0x2400 ;
V_72 |= 0x20 ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
F_26 ( V_13 , V_115 , 64 ) ;
F_28 ( V_2 , 0xc5 ) ;
}
else
F_10 ( V_7 -> V_15 ,
L_39 ,
V_17 -> V_20 ) ;
V_57 = V_7 -> V_30 . V_73 >> 3 ;
F_17 ( V_13 , V_128 , V_57 & 0xff ) ;
V_56 = 0x22 ;
if ( V_57 & 0x100 )
V_56 |= 0x10 ;
F_17 ( V_13 , V_129 , V_56 ) ;
if ( V_22 [ V_2 -> V_3 ] . V_130 )
F_17 ( V_13 , V_131 , ( V_57 >> 9 ) & 1 ) ;
if ( F_1 ( V_2 ) ) {
V_56 = 0 ;
if ( ( V_63 + 5 ) & 256 )
V_56 |= 128 ;
if ( V_60 & 256 )
V_56 |= 64 ;
if ( V_61 & 256 )
V_56 |= 48 ;
if ( V_67 & 1024 )
V_56 |= 8 ;
if ( V_64 & 1024 )
V_56 |= 4 ;
if ( V_65 & 1024 )
V_56 |= 3 ;
F_17 ( V_13 , V_132 , V_56 ) ;
F_7 ( V_7 -> V_15 , L_40 , V_56 ) ;
}
F_32 ( V_13 , V_133 , 0 ) ;
F_33 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_22 ( V_70 | 0x1000 , V_2 -> V_103 + 0x402 ) ;
F_22 ( V_71 , V_2 -> V_103 + 0xc0 ) ;
F_22 ( V_72 , V_2 -> V_103 + 0xea ) ;
}
V_56 = 0x01 ;
F_14 ( V_13 , V_134 , V_56 ) ;
F_7 ( V_7 -> V_15 , L_41 , V_56 ) ;
#ifdef F_34
F_35 ( V_7 , NULL ) ;
#endif
return 0 ;
}
static int F_36 ( struct V_6 * V_7 )
{
F_15 ( V_7 ) ;
return F_15 ( V_7 ) ;
}
static int F_37 ( unsigned V_135 , unsigned V_36 , unsigned V_39 ,
unsigned V_40 , unsigned V_47 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
if ( V_135 > 255 )
return - V_24 ;
if ( V_7 -> V_30 . V_74 == V_77 ) {
T_3 V_136 ;
V_36 >>= ( 16 - V_7 -> V_17 . V_36 . V_38 ) ;
V_39 >>= ( 16 - V_7 -> V_17 . V_39 . V_38 ) ;
V_40 >>= ( 16 - V_7 -> V_17 . V_40 . V_38 ) ;
if ( V_135 >= 16 )
return 1 ;
V_136 = ( V_36 << V_7 -> V_17 . V_36 . V_37 ) |
( V_39 << V_7 -> V_17 . V_39 . V_37 ) |
( V_40 << V_7 -> V_17 . V_40 . V_37 ) ;
V_2 -> V_137 [ V_135 ] = V_136 ;
return 0 ;
}
if ( V_7 -> V_17 . V_20 == 8 )
F_38 ( V_2 , V_135 , V_36 >> 10 , V_39 >> 10 , V_40 >> 10 ) ;
return 0 ;
}
static int F_39 ( struct V_16 * V_17 ,
struct V_6 * V_7 )
{
int V_44 ;
unsigned long V_138 ;
unsigned char V_56 , V_139 ;
struct V_1 * V_2 = V_7 -> V_10 ;
if ( V_17 -> V_48 & V_140 )
return - V_24 ;
V_44 = V_17 -> V_44 * V_7 -> V_17 . V_20 / 8 ;
V_138 = V_17 -> V_45 * V_7 -> V_30 . V_73 + V_44 ;
if ( V_7 -> V_17 . V_20 == 1 ) {
V_139 = ( unsigned char ) ( V_17 -> V_44 % 8 ) ;
} else {
V_138 /= 4 ;
V_139 = ( unsigned char ) ( ( V_44 % 4 ) * 2 ) ;
}
if ( ! F_1 ( V_2 ) )
F_40 ( V_2 -> V_13 ) ;
F_17 ( V_2 -> V_13 , V_141 , V_138 & 0xff ) ;
F_17 ( V_2 -> V_13 , V_142 , ( V_138 >> 8 ) & 0xff ) ;
V_56 = F_41 ( V_2 -> V_13 , V_129 ) & 0xf2 ;
if ( V_138 & 0x10000 )
V_56 |= 0x01 ;
if ( V_138 & 0x20000 )
V_56 |= 0x04 ;
if ( V_138 & 0x40000 )
V_56 |= 0x08 ;
F_17 ( V_2 -> V_13 , V_129 , V_56 ) ;
if ( V_22 [ V_2 -> V_3 ] . V_130 ) {
V_56 = F_41 ( V_2 -> V_13 , V_131 ) ;
if ( F_1 ( V_2 ) )
V_56 = ( V_56 & ~ 0x18 ) | ( ( V_138 >> 16 ) & 0x18 ) ;
else
V_56 = ( V_56 & ~ 0x80 ) | ( ( V_138 >> 12 ) & 0x80 ) ;
F_17 ( V_2 -> V_13 , V_131 , V_56 ) ;
}
if ( V_7 -> V_17 . V_20 == 1 )
F_32 ( V_2 -> V_13 , V_133 , V_139 ) ;
return 0 ;
}
static int F_42 ( int V_143 , struct V_6 * V_7 )
{
unsigned char V_144 ;
struct V_1 * V_2 = V_7 -> V_10 ;
int V_145 = V_2 -> V_143 ;
F_7 ( V_7 -> V_15 , L_42 , V_143 ) ;
if ( V_7 -> V_146 != V_147 ||
V_145 == V_143 ) {
F_7 ( V_7 -> V_15 , L_43 ) ;
return 0 ;
}
if ( V_145 == V_148 ||
V_145 == V_149 )
V_144 = 0 ;
else
V_144 = 0x20 ;
V_144 |= F_6 ( V_2 -> V_13 , V_134 ) & 0xdf ;
F_14 ( V_2 -> V_13 , V_134 , V_144 ) ;
switch ( V_143 ) {
case V_149 :
case V_148 :
V_144 = 0x00 ;
break;
case V_150 :
V_144 = 0x04 ;
break;
case V_151 :
V_144 = 0x02 ;
break;
case V_152 :
V_144 = 0x06 ;
break;
default:
F_7 ( V_7 -> V_15 , L_44 ) ;
return 1 ;
}
F_26 ( V_2 -> V_13 , V_153 , V_144 ) ;
V_2 -> V_143 = V_143 ;
F_7 ( V_7 -> V_15 , L_43 ) ;
return ( V_143 == V_148 ) ? 1 : 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
const struct V_58 * V_59 ;
assert ( V_2 != NULL ) ;
V_59 = & V_22 [ V_2 -> V_3 ] ;
switch ( V_2 -> V_3 ) {
case V_116 :
F_43 ( V_2 , 0x01 ) ;
F_44 ( 500 ) ;
F_43 ( V_2 , 0x51 ) ;
F_44 ( 500 ) ;
break;
case V_117 :
F_45 ( V_2 , 0xff ) ;
F_44 ( 500 ) ;
break;
case V_26 :
case V_118 :
F_43 ( V_2 , 0x1f ) ;
F_44 ( 500 ) ;
F_43 ( V_2 , 0x4f ) ;
F_44 ( 500 ) ;
break;
case V_27 :
F_17 ( V_2 -> V_13 , V_154 , 0x00 ) ;
F_46 ( 100 ) ;
F_26 ( V_2 -> V_13 , V_155 , 0x00 ) ;
case V_28 :
F_26 ( V_2 -> V_13 , V_156 , 0x00 ) ;
case V_25 :
F_26 ( V_2 -> V_13 , V_157 , 0x00 ) ;
break;
case V_4 :
case V_5 :
break;
default:
F_10 ( V_7 -> V_15 , L_45 ) ;
break;
}
assert ( V_7 -> V_35 > 0 ) ;
if ( V_2 -> V_3 != V_27 ) {
F_25 ( V_2 , V_158 , 0x10 ) ;
F_25 ( V_2 , V_159 , 0x01 ) ;
F_25 ( V_2 , V_158 , 0x08 ) ;
if ( V_2 -> V_3 != V_26 )
F_25 ( V_2 , V_160 , 0x01 ) ;
F_14 ( V_2 -> V_13 , V_161 , 0x03 ) ;
F_14 ( V_2 -> V_13 , V_134 , 0x21 ) ;
F_14 ( V_2 -> V_13 , V_162 , 0x12 ) ;
switch ( V_2 -> V_3 ) {
case V_28 :
F_14 ( V_2 -> V_13 , V_122 , 0x98 ) ;
break;
case V_25 :
case V_4 :
case V_5 :
break;
case V_26 :
#ifdef F_29
F_14 ( V_2 -> V_13 , V_122 , 0xb8 ) ;
#endif
break;
default:
F_14 ( V_2 -> V_13 , V_163 , 0x0f ) ;
F_14 ( V_2 -> V_13 , V_122 , 0xb0 ) ;
break;
}
}
F_14 ( V_2 -> V_13 , V_125 , 0xff ) ;
F_14 ( V_2 -> V_13 , V_164 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_124 , 0x0a ) ;
if ( V_59 -> V_165 )
F_14 ( V_2 -> V_13 , V_119 , V_59 -> V_166 ) ;
F_14 ( V_2 -> V_13 , V_167 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_168 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_169 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_170 , 0x00 ) ;
if ( V_2 -> V_3 != V_27 ) {
F_14 ( V_2 -> V_13 , V_171 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_172 , 0x02 ) ;
}
F_17 ( V_2 -> V_13 , V_173 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_113 , 0x20 ) ;
F_17 ( V_2 -> V_13 , V_114 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_174 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_175 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_176 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_129 , 0x02 ) ;
F_26 ( V_2 -> V_13 , V_177 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_178 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_179 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_180 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_181 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_115 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_182 , 0x01 ) ;
F_26 ( V_2 -> V_13 , V_183 , 0x0f ) ;
F_26 ( V_2 -> V_13 , V_184 , 0xff ) ;
if ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_26 ||
F_1 ( V_2 ) )
F_26 ( V_2 -> V_13 , V_185 , 0x20 ) ;
else
F_26 ( V_2 -> V_13 , V_185 , 0x28 ) ;
F_26 ( V_2 -> V_13 , V_186 , 0xff ) ;
F_26 ( V_2 -> V_13 , V_187 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_153 , 0x00 ) ;
F_32 ( V_2 -> V_13 , V_188 , 0x00 ) ;
F_32 ( V_2 -> V_13 , V_189 , 0x01 ) ;
F_32 ( V_2 -> V_13 , V_190 , 0x02 ) ;
F_32 ( V_2 -> V_13 , V_191 , 0x03 ) ;
F_32 ( V_2 -> V_13 , V_192 , 0x04 ) ;
F_32 ( V_2 -> V_13 , V_193 , 0x05 ) ;
F_32 ( V_2 -> V_13 , V_194 , 0x06 ) ;
F_32 ( V_2 -> V_13 , V_195 , 0x07 ) ;
F_32 ( V_2 -> V_13 , V_196 , 0x08 ) ;
F_32 ( V_2 -> V_13 , V_197 , 0x09 ) ;
F_32 ( V_2 -> V_13 , V_198 , 0x0a ) ;
F_32 ( V_2 -> V_13 , V_199 , 0x0b ) ;
F_32 ( V_2 -> V_13 , V_200 , 0x0c ) ;
F_32 ( V_2 -> V_13 , V_201 , 0x0d ) ;
F_32 ( V_2 -> V_13 , V_202 , 0x0e ) ;
F_32 ( V_2 -> V_13 , V_203 , 0x0f ) ;
F_32 ( V_2 -> V_13 , V_204 , 0x01 ) ;
F_32 ( V_2 -> V_13 , V_205 , 0x00 ) ;
F_32 ( V_2 -> V_13 , V_206 , 0x0f ) ;
F_32 ( V_2 -> V_13 , V_207 , 0x00 ) ;
F_25 ( V_2 , V_123 , 0xff ) ;
F_26 ( V_2 -> V_13 , V_155 , 0x04 ) ;
F_26 ( V_2 -> V_13 , V_155 , 0x00 ) ;
F_28 ( V_2 , 0 ) ;
return;
}
static void F_3 ( struct V_1 * V_2 , int V_208 )
{
#ifdef F_29
static int V_209 = 0 ;
if ( V_2 -> V_3 == V_27 )
return;
if ( V_2 -> V_3 == V_25 )
return;
if ( V_2 -> V_3 == V_28 )
return;
if ( V_2 -> V_3 == V_117 ) {
if ( ( V_208 && ! V_209 ) || ( ! V_208 && V_209 ) )
F_43 ( V_2 , 0xff ) ;
return;
}
if ( V_208 ) {
switch ( V_2 -> V_3 ) {
case V_26 :
F_43 ( V_2 , V_2 -> V_210 | 0x21 ) ;
break;
case V_116 :
F_43 ( V_2 , V_2 -> V_210 | 0x28 ) ;
break;
case V_118 :
F_43 ( V_2 , 0x6f ) ;
break;
default: break;
}
} else {
switch ( V_2 -> V_3 ) {
case V_26 :
F_43 ( V_2 , V_2 -> V_210 & 0xde ) ;
break;
case V_116 :
F_43 ( V_2 , V_2 -> V_210 & 0xd7 ) ;
break;
case V_118 :
F_43 ( V_2 , 0x4f ) ;
break;
default:
break;
}
}
#endif
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
if ( ! F_1 ( V_2 ) ) {
while ( F_48 ( V_2 -> V_13 , V_155 ) & 0x03 )
F_49 () ;
}
return 0 ;
}
static void F_50 ( struct V_6 * V_7 ,
const struct V_211 * V_212 )
{
struct V_211 V_213 ;
int V_214 , V_215 ;
struct V_1 * V_2 = V_7 -> V_10 ;
int V_216 = V_7 -> V_17 . V_20 ;
T_3 V_217 = ( V_7 -> V_30 . V_74 == V_77 ) ?
V_2 -> V_137 [ V_212 -> V_217 ] : V_212 -> V_217 ;
if ( V_7 -> V_146 != V_147 )
return;
if ( V_7 -> V_218 & V_219 ) {
F_51 ( V_7 , V_212 ) ;
return;
}
V_214 = V_7 -> V_17 . V_41 ;
V_215 = V_7 -> V_17 . V_43 ;
memcpy ( & V_213 , V_212 , sizeof( struct V_211 ) ) ;
if ( ! V_213 . V_220 || ! V_213 . V_221 ||
V_213 . V_222 >= V_214 || V_213 . V_223 >= V_215 )
return;
if ( V_213 . V_222 + V_213 . V_220 > V_214 )
V_213 . V_220 = V_214 - V_213 . V_222 ;
if ( V_213 . V_223 + V_213 . V_221 > V_215 )
V_213 . V_221 = V_215 - V_213 . V_223 ;
F_52 ( V_2 -> V_13 ,
V_7 -> V_17 . V_20 ,
( V_212 -> V_222 * V_216 ) / 8 , V_212 -> V_223 ,
( V_212 -> V_220 * V_216 ) / 8 , V_212 -> V_221 ,
V_217 , V_217 ,
V_7 -> V_30 . V_73 , 0x40 ) ;
}
static void F_53 ( struct V_6 * V_7 ,
const struct V_224 * V_225 )
{
struct V_224 V_213 ;
T_3 V_214 , V_215 ;
struct V_1 * V_2 = V_7 -> V_10 ;
int V_216 = V_7 -> V_17 . V_20 ;
if ( V_7 -> V_146 != V_147 )
return;
if ( V_7 -> V_218 & V_219 ) {
F_54 ( V_7 , V_225 ) ;
return;
}
V_214 = V_7 -> V_17 . V_41 ;
V_215 = V_7 -> V_17 . V_43 ;
memcpy ( & V_213 , V_225 , sizeof( struct V_224 ) ) ;
if ( ! V_213 . V_220 || ! V_213 . V_221 ||
V_213 . V_226 >= V_214 || V_213 . V_227 >= V_215 ||
V_213 . V_222 >= V_214 || V_213 . V_223 >= V_215 )
return;
if ( V_213 . V_226 + V_213 . V_220 > V_214 )
V_213 . V_220 = V_214 - V_213 . V_226 ;
if ( V_213 . V_222 + V_213 . V_220 > V_214 )
V_213 . V_220 = V_214 - V_213 . V_222 ;
if ( V_213 . V_227 + V_213 . V_221 > V_215 )
V_213 . V_221 = V_215 - V_213 . V_227 ;
if ( V_213 . V_223 + V_213 . V_221 > V_215 )
V_213 . V_221 = V_215 - V_213 . V_223 ;
F_55 ( V_2 -> V_13 , V_7 -> V_17 . V_20 ,
( V_225 -> V_226 * V_216 ) / 8 , V_225 -> V_227 ,
( V_225 -> V_222 * V_216 ) / 8 , V_225 -> V_223 ,
( V_225 -> V_220 * V_216 ) / 8 , V_225 -> V_221 ,
V_7 -> V_30 . V_73 ) ;
}
static void F_56 ( struct V_6 * V_7 ,
const struct V_228 * V_229 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
unsigned char V_230 = ( V_7 -> V_17 . V_20 == 24 ) ? 0xc : 0x4 ;
if ( V_7 -> V_146 != V_147 )
return;
if ( V_7 -> V_218 & V_219 || V_229 -> V_231 != 1 )
F_57 ( V_7 , V_229 ) ;
else if ( ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_26 ) &&
V_230 == 0xc )
F_57 ( V_7 , V_229 ) ;
else {
unsigned V_232 = ( ( V_229 -> V_220 + 7 ) >> 3 ) * V_229 -> V_221 ;
int V_216 = V_7 -> V_17 . V_20 ;
T_3 V_233 , V_234 ;
if ( V_7 -> V_17 . V_20 == 8 ) {
V_233 = V_229 -> V_235 ;
V_234 = V_229 -> V_236 ;
} else {
V_233 = ( ( T_3 * ) ( V_7 -> V_137 ) ) [ V_229 -> V_235 ] ;
V_234 = ( ( T_3 * ) ( V_7 -> V_137 ) ) [ V_229 -> V_236 ] ;
}
if ( V_7 -> V_17 . V_20 == 24 ) {
F_52 ( V_2 -> V_13 ,
V_7 -> V_17 . V_20 ,
( V_229 -> V_222 * V_216 ) / 8 , V_229 -> V_223 ,
( V_229 -> V_220 * V_216 ) / 8 ,
V_229 -> V_221 ,
V_234 , V_234 ,
V_7 -> V_30 . V_73 , 0x40 ) ;
}
F_52 ( V_2 -> V_13 ,
V_7 -> V_17 . V_20 ,
( V_229 -> V_222 * V_216 ) / 8 , V_229 -> V_223 ,
( V_229 -> V_220 * V_216 ) / 8 , V_229 -> V_221 ,
V_233 , V_234 ,
V_7 -> V_30 . V_73 , V_230 ) ;
memcpy ( V_7 -> V_237 , V_229 -> V_238 , V_232 ) ;
}
}
static unsigned int F_58 ( struct V_6 * V_7 ,
T_1 T_2 * V_13 )
{
unsigned long V_239 ;
struct V_1 * V_2 = V_7 -> V_10 ;
if ( F_1 ( V_2 ) ) {
unsigned char V_240 = F_6 ( V_13 , V_241 ) ;
V_239 = ( ( V_240 & 7 ) + 1 ) << 20 ;
} else {
unsigned char V_242 = F_6 ( V_13 , V_122 ) ;
switch ( ( V_242 & 0x18 ) ) {
case 0x08 :
V_239 = 512 * 1024 ;
break;
case 0x10 :
V_239 = 1024 * 1024 ;
break;
case 0x18 :
V_239 = 2048 * 1024 ;
break;
default:
F_27 ( V_7 -> V_15 , L_46 ) ;
V_239 = 1024 * 1024 ;
}
if ( V_2 -> V_3 != V_25 && ( V_242 & 0x80 ) != 0 )
V_239 *= 2 ;
}
return V_239 ;
}
static void F_59 ( const struct V_243 * V_244 ,
unsigned long * V_245 , unsigned long * V_246 )
{
assert ( V_244 != NULL ) ;
assert ( V_245 != NULL ) ;
assert ( V_246 != NULL ) ;
* V_245 = 0 ;
* V_246 = 0 ;
if ( F_60 ( V_244 , 0 ) & V_247 ) {
* V_245 = F_61 ( V_244 , 1 ) ;
* V_246 = F_61 ( V_244 , 0 ) ;
} else {
* V_245 = F_61 ( V_244 , 0 ) ;
* V_246 = F_61 ( V_244 , 1 ) ;
}
assert ( * V_245 != 0 ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
struct V_243 * V_244 = F_63 ( V_7 -> V_15 ) ;
struct V_1 * V_2 = V_7 -> V_10 ;
if ( V_2 -> V_103 == NULL )
F_64 ( V_2 -> V_103 ) ;
F_64 ( V_7 -> V_237 ) ;
#if 0
release_mem_region(0xA0000, 65535);
#endif
if ( V_248 )
F_65 ( 0x3C0 , 32 ) ;
F_66 ( V_244 ) ;
}
static void F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_249 * V_250 = F_68 ( V_7 -> V_15 ) ;
if ( V_7 -> V_30 . V_251 > 16 * V_32 )
F_64 ( V_7 -> V_237 ) ;
if ( V_7 -> V_30 . V_252 > 16 * V_32 )
F_64 ( V_2 -> V_13 ) ;
F_69 ( V_250 ) ;
}
static int F_70 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_16 * V_17 = & V_7 -> V_17 ;
V_7 -> V_137 = V_2 -> V_137 ;
V_7 -> V_218 = V_253
| V_254
| V_255
| V_256
| V_257
| V_258 ;
if ( V_259 || F_1 ( V_2 ) ) {
V_7 -> V_218 |= V_219 ;
V_7 -> V_30 . V_260 = V_261 ;
} else
V_7 -> V_30 . V_260 = V_262 ;
V_7 -> V_263 = & V_264 ;
if ( V_2 -> V_3 == V_28 ) {
if ( V_17 -> V_20 == 16 )
V_7 -> V_237 += 1 * V_32 ;
if ( V_17 -> V_20 == 32 )
V_7 -> V_237 += 2 * V_32 ;
}
F_71 ( V_7 -> V_30 . V_265 , V_22 [ V_2 -> V_3 ] . V_266 ,
sizeof( V_7 -> V_30 . V_265 ) ) ;
V_7 -> V_30 . V_31 = V_7 -> V_35 ;
if ( V_17 -> V_20 == 1 )
V_7 -> V_30 . V_31 /= 4 ;
V_7 -> V_30 . V_267 = 0 ;
V_7 -> V_30 . V_268 = 1 ;
V_7 -> V_30 . V_269 = 1 ;
V_7 -> V_30 . V_270 = 0 ;
V_7 -> V_30 . V_271 = 0 ;
F_72 ( & V_7 -> V_272 , 256 , 0 ) ;
return 0 ;
}
static int F_73 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
int V_273 ;
assert ( V_2 -> V_3 != V_274 ) ;
F_70 ( V_7 ) ;
F_7 ( V_7 -> V_15 , L_47 , V_7 -> V_237 ) ;
V_273 = F_74 ( & V_7 -> V_17 , V_7 , V_275 , NULL , 0 , NULL , 8 ) ;
if ( ! V_273 ) {
F_7 ( V_7 -> V_15 , L_48 ) ;
V_273 = - V_24 ;
goto V_276;
}
V_7 -> V_17 . V_277 = V_278 ;
V_273 = F_11 ( & V_7 -> V_17 , V_7 ) ;
if ( V_273 < 0 ) {
F_7 ( V_7 -> V_15 ,
L_49 ) ;
goto V_276;
}
V_273 = F_75 ( V_7 ) ;
if ( V_273 < 0 ) {
F_10 ( V_7 -> V_15 ,
L_50 , V_273 ) ;
goto V_276;
}
return 0 ;
V_276:
F_76 ( & V_7 -> V_272 ) ;
return V_273 ;
}
static void F_77 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
F_3 ( V_2 , 0 ) ;
F_78 ( V_7 ) ;
F_76 ( & V_7 -> V_272 ) ;
F_7 ( V_7 -> V_15 , L_51 ) ;
V_2 -> V_279 ( V_7 ) ;
F_79 ( V_7 ) ;
}
static int F_80 ( struct V_243 * V_244 ,
const struct V_280 * V_281 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
unsigned long V_282 , V_283 ;
int V_284 ;
V_284 = F_81 ( V_244 ) ;
if ( V_284 < 0 ) {
F_82 ( V_285 L_52 ) ;
goto V_286;
}
V_7 = F_83 ( sizeof( struct V_1 ) , & V_244 -> V_287 ) ;
if ( ! V_7 ) {
F_82 ( V_285 L_53 ) ;
V_284 = - V_288 ;
goto V_286;
}
V_2 = V_7 -> V_10 ;
V_2 -> V_3 = (enum V_289 ) V_281 -> V_290 ;
F_7 ( V_7 -> V_15 ,
L_54 ,
( unsigned long long ) V_244 -> V_291 [ 0 ] . V_292 , V_2 -> V_3 ) ;
F_7 ( V_7 -> V_15 , L_55 ,
( unsigned long long ) V_244 -> V_291 [ 1 ] . V_292 ) ;
F_7 ( V_7 -> V_15 ,
L_56 ) ;
F_59 ( V_244 , & V_282 , & V_7 -> V_30 . V_252 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_103 = F_84 ( V_7 -> V_30 . V_252 , 0x1000 ) ;
F_7 ( V_7 -> V_15 , L_57 ,
V_282 , V_7 -> V_30 . V_252 ) ;
V_283 = ( V_2 -> V_3 == V_28 ) ?
32 * V_32 : F_58 ( V_7 , V_2 -> V_13 ) ;
V_284 = F_85 ( V_244 , L_58 ) ;
if ( V_284 < 0 ) {
F_10 ( V_7 -> V_15 , L_59 ,
V_282 ) ;
goto V_293;
}
#if 0
if (!request_mem_region(0xA0000, 65535, "cirrusfb")) {
dev_err(info->device, "cannot reserve region 0x%lx, abort\n",
0xA0000L);
ret = -EBUSY;
goto err_release_regions;
}
#endif
if ( F_86 ( 0x3C0 , 32 , L_58 ) )
V_248 = 1 ;
V_7 -> V_237 = F_84 ( V_282 , V_283 ) ;
if ( ! V_7 -> V_237 ) {
V_284 = - V_294 ;
goto V_295;
}
V_7 -> V_30 . V_251 = V_282 ;
V_7 -> V_35 = V_283 ;
V_2 -> V_279 = F_62 ;
F_12 ( V_7 -> V_15 ,
L_60 ,
V_7 -> V_35 >> 10 , V_282 ) ;
F_87 ( V_244 , V_7 ) ;
V_284 = F_73 ( V_7 ) ;
if ( ! V_284 )
return 0 ;
F_64 ( V_7 -> V_237 ) ;
V_295:
if ( V_248 )
F_65 ( 0x3C0 , 32 ) ;
#if 0
release_mem_region(0xA0000, 65535);
err_release_regions:
#endif
F_66 ( V_244 ) ;
V_293:
if ( V_2 -> V_103 != NULL )
F_64 ( V_2 -> V_103 ) ;
F_79 ( V_7 ) ;
V_286:
return V_284 ;
}
static void F_88 ( struct V_243 * V_244 )
{
struct V_6 * V_7 = F_89 ( V_244 ) ;
F_77 ( V_7 ) ;
}
static int F_90 ( struct V_249 * V_296 ,
const struct V_297 * V_281 )
{
struct V_6 * V_7 ;
int error ;
const struct V_298 * V_299 ;
enum V_289 V_3 ;
unsigned long V_13 , V_300 , V_301 ;
struct V_1 * V_2 ;
V_7 = F_83 ( sizeof( struct V_1 ) , & V_296 -> V_287 ) ;
if ( ! V_7 ) {
F_82 ( V_285 L_53 ) ;
return - V_288 ;
}
V_299 = ( const struct V_298 * ) V_281 -> V_290 ;
V_3 = V_299 -> type ;
V_13 = F_91 ( V_296 ) + V_299 -> V_302 ;
V_300 = V_299 -> V_300 ;
if ( V_300 ) {
V_301 = F_91 ( V_296 ) + V_299 -> V_303 ;
if ( F_92 ( V_296 ) == 64 * V_32 ) {
V_301 += V_299 -> V_303 ;
}
} else {
struct V_249 * V_304 = F_93 ( V_299 -> V_305 , NULL ) ;
if ( ! V_304 || ! F_92 ( V_304 ) ) {
F_10 ( V_7 -> V_15 , L_61 ) ;
error = - V_306 ;
goto V_293;
}
V_301 = F_91 ( V_304 ) ;
V_300 = F_92 ( V_304 ) ;
if ( V_299 -> V_307 &&
( V_304 = F_93 ( V_299 -> V_307 , NULL ) ) ) {
if ( F_91 ( V_304 ) != V_301 + V_300 ) {
F_27 ( V_7 -> V_15 ,
L_62 ,
& V_304 -> V_291 ) ;
} else {
V_300 += F_92 ( V_304 ) ;
}
}
}
F_12 ( V_7 -> V_15 ,
L_63 ,
V_22 [ V_3 ] . V_266 , V_13 , V_300 / V_32 ,
V_301 ) ;
if ( ! F_94 ( V_296 , L_58 ) ) {
F_10 ( V_7 -> V_15 , L_64 , & V_296 -> V_291 ) ;
error = - V_308 ;
goto V_293;
}
V_2 = V_7 -> V_10 ;
V_2 -> V_3 = V_3 ;
V_7 -> V_30 . V_252 = V_13 ;
V_2 -> V_13 = V_13 > 16 * V_32 ? F_84 ( V_13 , 64 * 1024 )
: F_95 ( V_13 ) ;
if ( ! V_2 -> V_13 ) {
F_10 ( V_7 -> V_15 , L_65 ) ;
error = - V_294 ;
goto V_309;
}
V_7 -> V_30 . V_251 = V_301 ;
V_7 -> V_35 = V_300 ;
V_7 -> V_237 = V_301 > 16 * V_32 ? F_84 ( V_301 , V_300 )
: F_95 ( V_301 ) ;
if ( ! V_7 -> V_237 ) {
F_10 ( V_7 -> V_15 , L_66 ) ;
error = - V_294 ;
goto V_310;
}
V_2 -> V_279 = F_67 ;
F_12 ( V_7 -> V_15 ,
L_67 ,
V_300 / V_32 , V_301 ) ;
if ( V_22 [ V_3 ] . V_311 )
F_14 ( V_2 -> V_13 , V_14 ,
V_22 [ V_3 ] . V_312 ) ;
error = F_73 ( V_7 ) ;
if ( error ) {
F_10 ( V_7 -> V_15 , L_68 ,
error ) ;
goto V_313;
}
F_96 ( V_296 , V_7 ) ;
return 0 ;
V_313:
if ( V_301 > 16 * V_32 )
F_64 ( V_7 -> V_237 ) ;
V_310:
if ( V_13 > 16 * V_32 )
F_64 ( V_2 -> V_13 ) ;
V_309:
F_69 ( V_296 ) ;
V_293:
F_79 ( V_7 ) ;
return error ;
}
void F_97 ( struct V_249 * V_296 )
{
struct V_6 * V_7 = F_98 ( V_296 ) ;
F_77 ( V_7 ) ;
F_96 ( V_296 , NULL ) ;
}
static int T_4 F_99 ( char * V_314 )
{
char * V_315 ;
if ( ! V_314 || ! * V_314 )
return 0 ;
while ( ( V_315 = F_100 ( & V_314 , L_69 ) ) != NULL ) {
if ( ! * V_315 )
continue;
if ( ! strcmp ( V_315 , L_70 ) )
V_259 = 1 ;
else if ( ! strncmp ( V_315 , L_71 , 5 ) )
V_275 = V_315 + 5 ;
else
V_275 = V_315 ;
}
return 0 ;
}
static int T_4 F_101 ( void )
{
int error = 0 ;
#ifndef F_102
char * V_316 = NULL ;
if ( F_103 ( L_58 , & V_316 ) )
return - V_306 ;
F_99 ( V_316 ) ;
#endif
#ifdef F_29
error |= F_104 ( & V_317 ) ;
#endif
#ifdef F_30
error |= F_105 ( & V_318 ) ;
#endif
return error ;
}
static void T_5 F_106 ( void )
{
#ifdef F_30
F_107 ( & V_318 ) ;
#endif
#ifdef F_29
F_108 ( & V_317 ) ;
#endif
}
static void F_25 ( const struct V_1 * V_2 ,
int V_319 , unsigned char V_144 )
{
unsigned long V_320 = 0 ;
if ( V_2 -> V_3 == V_117 ) {
if ( V_319 == V_321 || V_319 == V_322 )
V_320 = 0xfff ;
}
F_109 ( V_2 -> V_13 , V_320 + V_319 , V_144 ) ;
}
static unsigned char F_110 ( const struct V_1 * V_2 , int V_319 )
{
unsigned long V_320 = 0 ;
if ( V_2 -> V_3 == V_117 ) {
if ( V_319 == V_321 || V_319 == V_322 )
V_320 = 0xfff ;
}
return F_111 ( V_2 -> V_13 , V_320 + V_319 ) ;
}
static void F_33 ( const struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
if ( F_41 ( V_2 -> V_13 , V_323 ) & 0x80 ) {
F_109 ( V_2 -> V_13 , V_324 ,
F_111 ( V_2 -> V_13 , V_325 ) ) ;
}
F_109 ( V_2 -> V_13 , V_324 , 0x33 ) ;
F_109 ( V_2 -> V_13 , V_324 , 0x00 ) ;
}
static void F_28 ( const struct V_1 * V_2 , unsigned char V_144 )
{
unsigned char V_326 ;
if ( F_1 ( V_2 ) )
return;
if ( V_2 -> V_3 == V_117 ) {
F_25 ( V_2 , V_123 , 0x00 ) ;
F_44 ( 200 ) ;
V_326 = F_110 ( V_2 , V_327 ) ;
F_44 ( 200 ) ;
}
V_326 = F_110 ( V_2 , V_123 ) ;
F_44 ( 200 ) ;
V_326 = F_110 ( V_2 , V_123 ) ;
F_44 ( 200 ) ;
V_326 = F_110 ( V_2 , V_123 ) ;
F_44 ( 200 ) ;
V_326 = F_110 ( V_2 , V_123 ) ;
F_44 ( 200 ) ;
F_25 ( V_2 , V_123 , V_144 ) ;
F_44 ( 200 ) ;
if ( V_2 -> V_3 == V_117 ) {
V_326 = F_110 ( V_2 , V_327 ) ;
F_44 ( 200 ) ;
F_25 ( V_2 , V_123 , 0xff ) ;
F_44 ( 200 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , unsigned char V_144 )
{
#ifdef F_29
assert ( V_2 -> V_13 != NULL ) ;
V_2 -> V_210 = V_144 ;
F_112 ( V_144 , V_2 -> V_13 + 0x8000 ) ;
#endif
}
static void F_45 ( struct V_1 * V_2 , unsigned char V_144 )
{
#ifdef F_29
assert ( V_2 -> V_13 != NULL ) ;
V_2 -> V_210 = V_144 ;
F_112 ( V_144 , V_2 -> V_13 + 0x9000 ) ;
#endif
}
static void F_38 ( struct V_1 * V_2 , unsigned char V_319 , unsigned char V_36 ,
unsigned char V_39 , unsigned char V_40 )
{
unsigned int V_238 = V_322 ;
F_109 ( V_2 -> V_13 , V_327 , V_319 ) ;
if ( V_2 -> V_3 == V_117 || V_2 -> V_3 == V_27 ||
V_2 -> V_3 == V_25 || V_2 -> V_3 == V_28 ||
V_2 -> V_3 == V_26 || F_1 ( V_2 ) ) {
if ( V_2 -> V_3 == V_117 )
V_238 += 0xfff ;
F_109 ( V_2 -> V_13 , V_238 , V_36 ) ;
F_109 ( V_2 -> V_13 , V_238 , V_39 ) ;
F_109 ( V_2 -> V_13 , V_238 , V_40 ) ;
} else {
F_109 ( V_2 -> V_13 , V_238 , V_40 ) ;
F_109 ( V_2 -> V_13 , V_238 , V_39 ) ;
F_109 ( V_2 -> V_13 , V_238 , V_36 ) ;
}
}
static void F_40 ( T_1 T_2 * V_13 )
{
while ( F_48 ( V_13 , V_155 ) & 0x08 )
F_49 () ;
}
static void F_113 ( T_1 T_2 * V_13 ,
T_6 V_328 , T_6 V_329 ,
T_7 V_330 , T_7 V_331 ,
T_6 V_332 , T_6 V_73 )
{
F_26 ( V_13 , V_333 , V_73 & 0xff ) ;
F_26 ( V_13 , V_334 , V_73 >> 8 ) ;
F_26 ( V_13 , V_335 , V_73 & 0xff ) ;
F_26 ( V_13 , V_336 , V_73 >> 8 ) ;
F_26 ( V_13 , V_337 , V_328 & 0xff ) ;
F_26 ( V_13 , V_338 , V_328 >> 8 ) ;
F_26 ( V_13 , V_339 , V_329 & 0xff ) ;
F_26 ( V_13 , V_340 , V_329 >> 8 ) ;
F_26 ( V_13 , V_341 , ( V_342 ) ( V_331 & 0xff ) ) ;
F_26 ( V_13 , V_343 , ( V_342 ) ( V_331 >> 8 ) ) ;
F_26 ( V_13 , V_344 , ( V_342 ) ( V_331 >> 16 ) ) ;
F_26 ( V_13 , V_345 , ( V_342 ) ( V_330 & 0xff ) ) ;
F_26 ( V_13 , V_346 , ( V_342 ) ( V_330 >> 8 ) ) ;
F_26 ( V_13 , V_347 , ( V_342 ) ( V_330 >> 16 ) ) ;
F_26 ( V_13 , V_348 , V_332 ) ;
F_26 ( V_13 , V_349 , 0x0d ) ;
F_26 ( V_13 , V_155 , 0x02 ) ;
}
static void F_55 ( T_1 T_2 * V_13 , int V_20 ,
T_6 V_350 , T_6 V_351 ,
T_6 V_352 , T_6 V_353 ,
T_6 V_220 , T_6 V_221 ,
T_6 V_73 )
{
T_6 V_328 = V_220 - 1 ;
T_6 V_329 = V_221 - 1 ;
T_7 V_330 , V_331 ;
V_342 V_332 ;
V_332 = 0x00 ;
if ( V_351 <= V_353 ) {
if ( V_351 == V_353 ) {
if ( V_350 < V_352 )
V_332 |= 0x01 ;
} else
V_332 |= 0x01 ;
}
V_330 = ( V_351 * V_73 ) + V_350 ;
V_331 = ( V_353 * V_73 ) + V_352 ;
if ( V_332 ) {
V_330 += V_329 * V_73 + V_328 ;
V_331 += V_329 * V_73 + V_328 ;
}
F_40 ( V_13 ) ;
F_113 ( V_13 , V_328 , V_329 ,
V_330 , V_331 , V_332 , V_73 ) ;
}
static void F_52 ( T_1 T_2 * V_13 , int V_20 ,
T_6 V_354 , T_6 V_355 , T_6 V_220 , T_6 V_221 ,
T_3 V_235 , T_3 V_236 , T_6 V_73 ,
V_342 V_356 )
{
T_7 V_331 = ( V_355 * V_73 ) + V_354 ;
V_342 V_230 ;
F_40 ( V_13 ) ;
F_26 ( V_13 , V_177 , V_236 ) ;
F_26 ( V_13 , V_178 , V_235 ) ;
V_230 = 0x80 ;
if ( V_20 >= 16 ) {
F_26 ( V_13 , V_357 , V_236 >> 8 ) ;
F_26 ( V_13 , V_358 , V_235 >> 8 ) ;
V_230 = 0x90 ;
}
if ( V_20 >= 24 ) {
F_26 ( V_13 , V_359 , V_236 >> 16 ) ;
F_26 ( V_13 , V_360 , V_235 >> 16 ) ;
V_230 = 0xa0 ;
}
if ( V_20 == 32 ) {
F_26 ( V_13 , V_361 , V_236 >> 24 ) ;
F_26 ( V_13 , V_362 , V_235 >> 24 ) ;
V_230 = 0xb0 ;
}
F_113 ( V_13 , V_220 - 1 , V_221 - 1 ,
0 , V_331 , V_230 | V_356 , V_73 ) ;
}
static void F_18 ( long V_11 , int * V_68 , int * V_69 , int * div )
{
int V_363 , V_364 ;
long V_365 , V_366 ;
assert ( V_68 != NULL ) ;
assert ( V_69 != NULL ) ;
assert ( div != NULL ) ;
* V_68 = 0 ;
* V_69 = 0 ;
* div = 0 ;
if ( V_11 < 8000 )
V_11 = 8000 ;
V_366 = V_11 ;
for ( V_363 = 32 ; V_363 < 128 ; V_363 ++ ) {
int V_367 = 0 ;
V_364 = ( 14318 * V_363 ) / V_11 ;
if ( ( V_364 >= 7 ) && ( V_364 <= 63 ) ) {
int V_368 = V_364 ;
if ( V_368 > 31 ) {
V_367 = 1 ;
V_368 >>= 1 ;
}
V_365 = ( ( 14318 * V_363 ) / V_368 ) >> V_367 ;
V_365 = V_365 > V_11 ? V_365 - V_11 : V_11 - V_365 ;
if ( V_365 < V_366 ) {
V_366 = V_365 ;
* V_68 = V_363 ;
* V_69 = V_368 ;
* div = V_367 ;
}
}
V_364 ++ ;
if ( ( V_364 >= 7 ) && ( V_364 <= 63 ) ) {
if ( V_364 > 31 ) {
V_367 = 1 ;
V_364 >>= 1 ;
}
V_365 = ( ( 14318 * V_363 ) / V_364 ) >> V_367 ;
V_365 = V_365 > V_11 ? V_365 - V_11 : V_11 - V_365 ;
if ( V_365 < V_366 ) {
V_366 = V_365 ;
* V_68 = V_363 ;
* V_69 = V_364 ;
* div = V_367 ;
}
}
}
}
static void F_114 ( struct V_6 * V_7 ,
T_8 V_13 ,
enum V_369 V_370 , ... )
{
T_9 V_371 ;
unsigned char V_144 = 0 ;
unsigned V_372 ;
char * V_266 ;
va_start ( V_371 , V_370 ) ;
V_266 = va_arg ( V_371 , char * ) ;
while ( V_266 != NULL ) {
V_372 = va_arg ( V_371 , int ) ;
switch ( V_370 ) {
case V_373 :
V_144 = F_41 ( V_13 , ( unsigned char ) V_372 ) ;
break;
case V_374 :
V_144 = F_6 ( V_13 , ( unsigned char ) V_372 ) ;
break;
default:
assert ( false ) ;
break;
}
F_7 ( V_7 -> V_15 , L_72 , V_266 , V_144 ) ;
V_266 = va_arg ( V_371 , char * ) ;
}
va_end ( V_371 ) ;
}
static void F_35 ( struct V_6 * V_7 , T_8 V_13 )
{
F_7 ( V_7 -> V_15 , L_73 ) ;
F_114 ( V_7 , V_13 , V_373 ,
L_74 , 0x00 ,
L_75 , 0x01 ,
L_76 , 0x02 ,
L_77 , 0x03 ,
L_78 , 0x04 ,
L_79 , 0x05 ,
L_80 , 0x06 ,
L_81 , 0x07 ,
L_82 , 0x08 ,
L_83 , 0x09 ,
L_84 , 0x0A ,
L_85 , 0x0B ,
L_86 , 0x0C ,
L_87 , 0x0D ,
L_88 , 0x0E ,
L_89 , 0x0F ,
L_90 , 0x10 ,
L_91 , 0x11 ,
L_92 , 0x12 ,
L_93 , 0x13 ,
L_94 , 0x14 ,
L_95 , 0x15 ,
L_96 , 0x16 ,
L_97 , 0x17 ,
L_98 , 0x18 ,
L_99 , 0x22 ,
L_100 , 0x24 ,
L_101 , 0x26 ,
L_102 , 0x2D ,
L_103 , 0x2E ,
L_104 , 0x2F ,
L_105 , 0x30 ,
L_106 , 0x31 ,
L_107 , 0x32 ,
L_108 , 0x33 ,
L_109 , 0x34 ,
L_110 , 0x35 ,
L_111 , 0x36 ,
L_112 , 0x37 ,
L_113 , 0x38 ,
L_114 , 0x39 ,
L_115 , 0x3A ,
L_116 , 0x3B ,
L_117 , 0x3C ,
L_118 , 0x3D ,
L_119 , 0x3E ,
L_120 , 0x3F ,
NULL ) ;
F_7 ( V_7 -> V_15 , L_121 ) ;
F_7 ( V_7 -> V_15 , L_122 ) ;
F_114 ( V_7 , V_13 , V_374 ,
L_123 , 0x00 ,
L_124 , 0x01 ,
L_125 , 0x02 ,
L_126 , 0x03 ,
L_127 , 0x04 ,
L_128 , 0x08 ,
L_129 , 0x09 ,
L_130 , 0x0A ,
L_131 , 0x0B ,
L_132 , 0x0D ,
L_133 , 0x10 ,
L_134 , 0x11 ,
L_135 , 0x12 ,
L_136 , 0x13 ,
L_137 , 0x14 ,
L_138 , 0x15 ,
L_139 , 0x16 ,
L_140 , 0x17 ,
L_141 , 0x18 ,
L_142 , 0x19 ,
L_143 , 0x1A ,
L_144 , 0x1B ,
L_145 , 0x1C ,
L_146 , 0x1D ,
L_147 , 0x1E ,
L_148 , 0x1F ,
NULL ) ;
F_7 ( V_7 -> V_15 , L_121 ) ;
}
