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
if ( V_41 ) {
V_17 -> V_36 . V_37 = 2 ;
V_17 -> V_39 . V_37 = - 3 ;
V_17 -> V_40 . V_37 = 8 ;
} else {
V_17 -> V_36 . V_37 = 11 ;
V_17 -> V_39 . V_37 = 5 ;
V_17 -> V_40 . V_37 = 0 ;
}
V_17 -> V_36 . V_38 = 5 ;
V_17 -> V_39 . V_38 = 6 ;
V_17 -> V_40 . V_38 = 5 ;
break;
case 24 :
if ( V_41 ) {
V_17 -> V_36 . V_37 = 0 ;
V_17 -> V_39 . V_37 = 8 ;
V_17 -> V_40 . V_37 = 16 ;
} else {
V_17 -> V_36 . V_37 = 16 ;
V_17 -> V_39 . V_37 = 8 ;
V_17 -> V_40 . V_37 = 0 ;
}
V_17 -> V_36 . V_38 = 8 ;
V_17 -> V_39 . V_38 = 8 ;
V_17 -> V_40 . V_38 = 8 ;
break;
default:
F_7 ( V_7 -> V_15 ,
L_6 , V_17 -> V_20 ) ;
return - V_24 ;
}
if ( V_17 -> V_42 < V_17 -> V_43 )
V_17 -> V_42 = V_17 -> V_43 ;
if ( V_17 -> V_44 == - 1 ) {
V_17 -> V_44 = V_34 / V_17 -> V_42 ;
F_12 ( V_7 -> V_15 ,
L_7 ,
V_17 -> V_42 , V_17 -> V_44 ) ;
}
if ( V_17 -> V_44 < V_17 -> V_33 )
V_17 -> V_44 = V_17 -> V_33 ;
if ( V_17 -> V_42 * V_17 -> V_44 > V_34 ) {
F_10 ( V_7 -> V_15 , L_8
L_9 ,
V_17 -> V_42 , V_17 -> V_44 ,
V_17 -> V_20 ) ;
return - V_24 ;
}
if ( V_17 -> V_45 < 0 )
V_17 -> V_45 = 0 ;
if ( V_17 -> V_46 < 0 )
V_17 -> V_46 = 0 ;
if ( V_17 -> V_45 > V_17 -> V_42 - V_17 -> V_43 )
V_17 -> V_45 = V_17 -> V_42 - V_17 -> V_43 - 1 ;
if ( V_17 -> V_46 > V_17 -> V_44 - V_17 -> V_33 )
V_17 -> V_46 = V_17 -> V_44 - V_17 -> V_33 - 1 ;
V_17 -> V_36 . V_47 =
V_17 -> V_39 . V_47 =
V_17 -> V_40 . V_47 =
V_17 -> V_48 . V_37 =
V_17 -> V_48 . V_38 =
V_17 -> V_48 . V_47 = 0 ;
V_33 = V_17 -> V_33 ;
if ( V_17 -> V_49 & V_50 )
V_33 *= 2 ;
else if ( V_17 -> V_49 & V_51 )
V_33 = ( V_33 + 1 ) / 2 ;
if ( V_33 >= 1280 ) {
F_10 ( V_7 -> V_15 , L_10
L_11 ) ;
return - V_24 ;
}
if ( F_8 ( V_17 , V_7 ) )
return - V_24 ;
if ( ! F_1 ( V_2 ) )
V_17 -> V_52 = V_53 ;
return 0 ;
}
static void F_13 ( const struct V_6 * V_7 , int div )
{
struct V_1 * V_2 = V_7 -> V_10 ;
unsigned char V_54 , V_55 ;
assert ( V_2 != NULL ) ;
V_54 = F_6 ( V_2 -> V_13 , V_14 ) & ~ 0x40 ;
if ( div ) {
F_7 ( V_7 -> V_15 , L_12 ,
( div == 2 ) ? L_13 : L_14 ) ;
V_54 |= 0x40 ;
V_55 = F_6 ( V_2 -> V_13 , V_56 ) & ~ 0x1 ;
if ( div == 2 )
V_55 |= 1 ;
F_14 ( V_2 -> V_13 , V_56 , V_55 ) ;
}
F_14 ( V_2 -> V_13 , V_14 , V_54 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_16 * V_17 = & V_7 -> V_17 ;
T_1 T_2 * V_13 = V_2 -> V_13 ;
unsigned char V_57 ;
int V_58 ;
const struct V_59 * V_60 ;
int V_61 , V_62 , V_63 , V_64 ;
int V_33 , V_65 , V_66 , V_67 , V_68 ;
long V_11 ;
int V_69 , V_70 , div ;
unsigned int V_71 = 0 , V_72 = 0 , V_73 = 0 ;
F_7 ( V_7 -> V_15 , L_15 ,
V_17 -> V_43 , V_17 -> V_33 , V_17 -> V_20 ) ;
switch ( V_17 -> V_20 ) {
case 1 :
V_7 -> V_30 . V_74 = V_17 -> V_42 / 8 ;
V_7 -> V_30 . V_75 = V_76 ;
break;
case 8 :
V_7 -> V_30 . V_74 = V_17 -> V_42 ;
V_7 -> V_30 . V_75 = V_77 ;
break;
case 16 :
case 24 :
V_7 -> V_30 . V_74 = V_17 -> V_42 *
V_17 -> V_20 >> 3 ;
V_7 -> V_30 . V_75 = V_78 ;
break;
}
V_7 -> V_30 . type = V_79 ;
F_16 ( V_7 ) ;
V_60 = & V_22 [ V_2 -> V_3 ] ;
V_62 = V_17 -> V_43 + V_17 -> V_80 ;
V_63 = V_62 + V_17 -> V_81 ;
V_64 = ( V_63 + V_17 -> V_82 ) / 8 ;
V_61 = V_17 -> V_43 / 8 ;
V_62 = V_62 / 8 ;
V_63 = V_63 / 8 ;
V_65 = V_17 -> V_33 ;
V_66 = V_65 + V_17 -> V_83 ;
V_67 = V_66 + V_17 -> V_84 ;
V_68 = V_67 + V_17 -> V_85 ;
if ( V_17 -> V_49 & V_50 ) {
V_65 *= 2 ;
V_66 *= 2 ;
V_67 *= 2 ;
V_68 *= 2 ;
} else if ( V_17 -> V_49 & V_51 ) {
V_65 = ( V_65 + 1 ) / 2 ;
V_66 = ( V_66 + 1 ) / 2 ;
V_67 = ( V_67 + 1 ) / 2 ;
V_68 = ( V_68 + 1 ) / 2 ;
}
V_33 = V_65 ;
if ( V_33 >= 1024 ) {
V_68 /= 2 ;
V_66 /= 2 ;
V_67 /= 2 ;
V_65 /= 2 ;
}
V_65 -= 1 ;
V_66 -= 1 ;
V_67 -= 1 ;
V_68 -= 2 ;
if ( V_2 -> V_23 ) {
V_64 /= 2 ;
V_62 /= 2 ;
V_63 /= 2 ;
V_61 /= 2 ;
}
V_64 -= 5 ;
V_61 -= 1 ;
V_62 += 1 ;
V_63 += 1 ;
F_17 ( V_13 , V_86 , 0x20 ) ;
F_7 ( V_7 -> V_15 , L_16 , V_64 ) ;
F_17 ( V_13 , V_87 , V_64 ) ;
F_7 ( V_7 -> V_15 , L_17 , V_61 ) ;
F_17 ( V_13 , V_88 , V_61 ) ;
F_7 ( V_7 -> V_15 , L_18 , V_17 -> V_43 / 8 ) ;
F_17 ( V_13 , V_89 , V_17 -> V_43 / 8 ) ;
F_7 ( V_7 -> V_15 , L_19 , ( V_64 + 5 ) % 32 ) ;
F_17 ( V_13 , V_90 ,
128 + ( ( V_64 + 5 ) % 32 ) ) ;
F_7 ( V_7 -> V_15 , L_20 , V_62 ) ;
F_17 ( V_13 , V_91 , V_62 ) ;
V_57 = V_63 % 32 ;
if ( ( V_64 + 5 ) & 32 )
V_57 += 128 ;
F_7 ( V_7 -> V_15 , L_21 , V_57 ) ;
F_17 ( V_13 , V_92 , V_57 ) ;
F_7 ( V_7 -> V_15 , L_22 , V_68 & 0xff ) ;
F_17 ( V_13 , V_93 , V_68 & 0xff ) ;
V_57 = 16 ;
if ( V_68 & 256 )
V_57 |= 1 ;
if ( V_65 & 256 )
V_57 |= 2 ;
if ( V_66 & 256 )
V_57 |= 4 ;
if ( ( V_65 + 1 ) & 256 )
V_57 |= 8 ;
if ( V_68 & 512 )
V_57 |= 32 ;
if ( V_65 & 512 )
V_57 |= 64 ;
if ( V_66 & 512 )
V_57 |= 128 ;
F_7 ( V_7 -> V_15 , L_23 , V_57 ) ;
F_17 ( V_13 , V_94 , V_57 ) ;
V_57 = 0x40 ;
if ( ( V_65 + 1 ) & 512 )
V_57 |= 0x20 ;
if ( V_17 -> V_49 & V_50 )
V_57 |= 0x80 ;
F_7 ( V_7 -> V_15 , L_24 , V_57 ) ;
F_17 ( V_13 , V_95 , V_57 ) ;
F_7 ( V_7 -> V_15 , L_25 , V_66 & 0xff ) ;
F_17 ( V_13 , V_96 , V_66 & 0xff ) ;
F_7 ( V_7 -> V_15 , L_26 , V_67 % 16 ) ;
F_17 ( V_13 , V_86 , V_67 % 16 + 64 + 32 ) ;
F_7 ( V_7 -> V_15 , L_27 , V_65 & 0xff ) ;
F_17 ( V_13 , V_97 , V_65 & 0xff ) ;
F_7 ( V_7 -> V_15 , L_28 , ( V_65 + 1 ) & 0xff ) ;
F_17 ( V_13 , V_98 , ( V_65 + 1 ) & 0xff ) ;
F_7 ( V_7 -> V_15 , L_29 , V_68 & 0xff ) ;
F_17 ( V_13 , V_99 , V_68 & 0xff ) ;
F_7 ( V_7 -> V_15 , L_30 ) ;
F_17 ( V_13 , V_100 , 0xff ) ;
V_57 = 0 ;
if ( V_17 -> V_49 & V_51 )
V_57 |= 1 ;
if ( ( V_64 + 5 ) & 64 )
V_57 |= 16 ;
if ( ( V_64 + 5 ) & 128 )
V_57 |= 32 ;
if ( V_68 & 256 )
V_57 |= 64 ;
if ( V_68 & 512 )
V_57 |= 128 ;
F_7 ( V_7 -> V_15 , L_31 , V_57 ) ;
F_17 ( V_13 , V_101 , V_57 ) ;
V_11 = F_9 ( V_17 -> V_21 ) ;
if ( V_17 -> V_20 == 24 )
if ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_26 )
V_11 *= 3 ;
if ( V_2 -> V_23 )
V_11 /= 2 ;
if ( V_2 -> V_29 )
V_11 *= 2 ;
F_18 ( V_11 , & V_69 , & V_70 , & div ) ;
F_7 ( V_7 -> V_15 , L_32 ,
V_11 , V_69 , V_70 , div ) ;
if ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_27 ||
V_2 -> V_3 == V_26 ) {
int V_102 = F_5 ( V_7 , V_11 ) ;
if ( V_102 )
V_69 = 0 ;
F_13 ( V_7 , V_102 ) ;
}
if ( F_1 ( V_2 ) ) {
long V_103 = F_19 ( V_2 -> V_104 + 0x3fc ) ;
unsigned char V_105 = F_20 ( V_2 -> V_104 + 0x407 ) ;
unsigned short V_106 ;
if ( V_2 -> V_3 == V_5 ) {
V_106 = F_21 ( V_2 -> V_104 + 0x2c4 ) ;
V_106 &= ~ 0x80 ;
F_22 ( V_106 , V_2 -> V_104 + 0x2c4 ) ;
}
F_23 ( V_103 | 0x10000000l , V_2 -> V_104 + 0x3fc ) ;
F_24 ( V_105 & 0x3f , V_2 -> V_104 + 0x407 ) ;
V_71 = F_21 ( V_2 -> V_104 + 0x402 ) ;
V_73 = F_21 ( V_2 -> V_104 + 0xea ) ;
V_71 &= ~ 0x6800 ;
V_72 = 0 ;
V_73 &= 0xffc0 & 0x3fbf ;
}
if ( V_69 ) {
V_57 = V_70 << 1 ;
if ( div != 0 )
V_57 |= 1 ;
if ( ( V_2 -> V_3 == V_26 ) ||
( V_2 -> V_3 == V_25 ) ||
( V_2 -> V_3 == V_28 ) )
V_57 |= 0x80 ;
if ( F_1 ( V_2 ) ) {
F_14 ( V_13 , V_107 , V_57 ) ;
F_14 ( V_13 , V_56 , V_69 ) ;
} else {
F_14 ( V_13 , V_107 , V_69 ) ;
F_14 ( V_13 , V_56 , V_57 ) ;
}
}
if ( V_33 >= 1024 )
F_17 ( V_13 , V_108 , 0xc7 ) ;
else
F_17 ( V_13 , V_108 , 0xc3 ) ;
if ( V_17 -> V_49 & V_51 )
F_17 ( V_13 , V_109 , V_64 / 2 ) ;
else
F_17 ( V_13 , V_109 , 0x00 ) ;
V_57 = 0x03 | 0xc ;
if ( V_17 -> V_110 & V_111 )
V_57 |= 0x40 ;
if ( V_17 -> V_110 & V_112 )
V_57 |= 0x80 ;
F_25 ( V_2 , V_113 , V_57 ) ;
F_17 ( V_13 , V_114 , 0 ) ;
F_17 ( V_13 , V_115 , 31 ) ;
if ( V_17 -> V_20 == 1 ) {
F_7 ( V_7 -> V_15 , L_33 ) ;
F_26 ( V_13 , V_116 , 0 ) ;
switch ( V_2 -> V_3 ) {
case V_26 :
case V_117 :
case V_118 :
case V_119 :
case V_27 :
case V_25 :
case V_28 :
F_14 ( V_13 , V_120 ,
V_2 -> V_23 ?
V_60 -> V_121 : V_60 -> V_122 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_120 ,
F_6 ( V_13 , V_120 ) & ~ 0x01 ) ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
switch ( V_2 -> V_3 ) {
case V_117 :
case V_119 :
F_14 ( V_13 , V_123 , 0xb0 ) ;
break;
case V_118 :
F_14 ( V_13 , V_123 , 0xd0 ) ;
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
F_25 ( V_2 , V_124 , 0x01 ) ;
if ( V_2 -> V_23 )
F_28 ( V_2 , 0x4a ) ;
else
F_28 ( V_2 , 0 ) ;
F_14 ( V_13 , V_125 , 0x06 ) ;
F_14 ( V_13 , V_126 , 0x01 ) ;
}
else if ( V_17 -> V_20 == 8 ) {
F_7 ( V_7 -> V_15 , L_35 ) ;
switch ( V_2 -> V_3 ) {
case V_26 :
case V_117 :
case V_118 :
case V_119 :
case V_27 :
case V_25 :
case V_28 :
F_14 ( V_13 , V_120 ,
V_2 -> V_23 ?
V_60 -> V_127 : V_60 -> V_128 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_120 ,
F_6 ( V_13 , V_120 ) | 0x01 ) ;
V_73 |= 0x10 ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
switch ( V_2 -> V_3 ) {
case V_117 :
case V_118 :
case V_119 :
F_14 ( V_13 , V_123 , 0xb0 ) ;
break;
case V_27 :
#ifdef F_29
F_14 ( V_13 , V_123 , 0xb8 ) ;
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
F_26 ( V_13 , V_116 , 64 ) ;
if ( V_2 -> V_23 )
F_28 ( V_2 , 0x4a ) ;
else
F_28 ( V_2 , 0 ) ;
}
else if ( V_17 -> V_20 == 16 ) {
F_7 ( V_7 -> V_15 , L_37 ) ;
switch ( V_2 -> V_3 ) {
case V_117 :
case V_119 :
F_14 ( V_13 , V_120 , 0x87 ) ;
F_14 ( V_13 , V_123 , 0xb0 ) ;
break;
case V_118 :
F_14 ( V_13 , V_120 , 0x27 ) ;
F_14 ( V_13 , V_123 , 0xb0 ) ;
break;
case V_26 :
case V_27 :
case V_25 :
F_14 ( V_13 , V_120 ,
V_2 -> V_29 ? 0xa3 : 0xa7 ) ;
break;
case V_28 :
F_14 ( V_13 , V_120 , 0x17 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_120 ,
F_6 ( V_13 , V_120 ) & ~ 0x01 ) ;
V_71 |= 0x2000 ;
V_72 |= 0x1400 ;
V_73 |= 0x10 ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
F_26 ( V_13 , V_116 , 64 ) ;
#ifdef F_30
F_28 ( V_2 , V_2 -> V_29 ? 0xe1 : 0xc1 ) ;
#elif F_31 ( F_29 )
F_28 ( V_2 , 0xa0 ) ;
#endif
}
else if ( V_17 -> V_20 == 24 ) {
F_7 ( V_7 -> V_15 , L_38 ) ;
switch ( V_2 -> V_3 ) {
case V_117 :
case V_119 :
F_14 ( V_13 , V_120 , 0x85 ) ;
F_14 ( V_13 , V_123 , 0xb0 ) ;
break;
case V_118 :
F_14 ( V_13 , V_120 , 0x25 ) ;
F_14 ( V_13 , V_123 , 0xb0 ) ;
break;
case V_26 :
case V_27 :
case V_25 :
F_14 ( V_13 , V_120 , 0xa5 ) ;
break;
case V_28 :
F_14 ( V_13 , V_120 , 0x15 ) ;
break;
case V_4 :
case V_5 :
F_14 ( V_13 , V_120 ,
F_6 ( V_13 , V_120 ) & ~ 0x01 ) ;
V_71 |= 0x4000 ;
V_72 |= 0x2400 ;
V_73 |= 0x20 ;
break;
default:
F_27 ( V_7 -> V_15 , L_34 ) ;
break;
}
F_26 ( V_13 , V_116 , 64 ) ;
F_28 ( V_2 , 0xc5 ) ;
}
else
F_10 ( V_7 -> V_15 ,
L_39 ,
V_17 -> V_20 ) ;
V_58 = V_7 -> V_30 . V_74 >> 3 ;
F_17 ( V_13 , V_129 , V_58 & 0xff ) ;
V_57 = 0x22 ;
if ( V_58 & 0x100 )
V_57 |= 0x10 ;
F_17 ( V_13 , V_130 , V_57 ) ;
if ( V_22 [ V_2 -> V_3 ] . V_131 )
F_17 ( V_13 , V_132 , ( V_58 >> 9 ) & 1 ) ;
if ( F_1 ( V_2 ) ) {
V_57 = 0 ;
if ( ( V_64 + 5 ) & 256 )
V_57 |= 128 ;
if ( V_61 & 256 )
V_57 |= 64 ;
if ( V_62 & 256 )
V_57 |= 48 ;
if ( V_68 & 1024 )
V_57 |= 8 ;
if ( V_65 & 1024 )
V_57 |= 4 ;
if ( V_66 & 1024 )
V_57 |= 3 ;
F_17 ( V_13 , V_133 , V_57 ) ;
F_7 ( V_7 -> V_15 , L_40 , V_57 ) ;
}
F_32 ( V_13 , V_134 , 0 ) ;
F_33 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_22 ( V_71 | 0x1000 , V_2 -> V_104 + 0x402 ) ;
F_22 ( V_72 , V_2 -> V_104 + 0xc0 ) ;
F_22 ( V_73 , V_2 -> V_104 + 0xea ) ;
}
V_57 = 0x01 ;
F_14 ( V_13 , V_135 , V_57 ) ;
F_7 ( V_7 -> V_15 , L_41 , V_57 ) ;
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
static int F_37 ( unsigned V_136 , unsigned V_36 , unsigned V_39 ,
unsigned V_40 , unsigned V_48 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
if ( V_136 > 255 )
return - V_24 ;
if ( V_7 -> V_30 . V_75 == V_78 ) {
T_3 V_137 ;
V_36 >>= ( 16 - V_7 -> V_17 . V_36 . V_38 ) ;
V_39 >>= ( 16 - V_7 -> V_17 . V_39 . V_38 ) ;
V_40 >>= ( 16 - V_7 -> V_17 . V_40 . V_38 ) ;
if ( V_136 >= 16 )
return 1 ;
V_137 = ( V_36 << V_7 -> V_17 . V_36 . V_37 ) |
( V_39 << V_7 -> V_17 . V_39 . V_37 ) |
( V_40 << V_7 -> V_17 . V_40 . V_37 ) ;
V_2 -> V_138 [ V_136 ] = V_137 ;
return 0 ;
}
if ( V_7 -> V_17 . V_20 == 8 )
F_38 ( V_2 , V_136 , V_36 >> 10 , V_39 >> 10 , V_40 >> 10 ) ;
return 0 ;
}
static int F_39 ( struct V_16 * V_17 ,
struct V_6 * V_7 )
{
int V_45 ;
unsigned long V_139 ;
unsigned char V_57 , V_140 ;
struct V_1 * V_2 = V_7 -> V_10 ;
if ( V_17 -> V_49 & V_141 )
return - V_24 ;
V_45 = V_17 -> V_45 * V_7 -> V_17 . V_20 / 8 ;
V_139 = V_17 -> V_46 * V_7 -> V_30 . V_74 + V_45 ;
if ( V_7 -> V_17 . V_20 == 1 ) {
V_140 = ( unsigned char ) ( V_17 -> V_45 % 8 ) ;
} else {
V_139 /= 4 ;
V_140 = ( unsigned char ) ( ( V_45 % 4 ) * 2 ) ;
}
if ( ! F_1 ( V_2 ) )
F_40 ( V_2 -> V_13 ) ;
F_17 ( V_2 -> V_13 , V_142 , V_139 & 0xff ) ;
F_17 ( V_2 -> V_13 , V_143 , ( V_139 >> 8 ) & 0xff ) ;
V_57 = F_41 ( V_2 -> V_13 , V_130 ) & 0xf2 ;
if ( V_139 & 0x10000 )
V_57 |= 0x01 ;
if ( V_139 & 0x20000 )
V_57 |= 0x04 ;
if ( V_139 & 0x40000 )
V_57 |= 0x08 ;
F_17 ( V_2 -> V_13 , V_130 , V_57 ) ;
if ( V_22 [ V_2 -> V_3 ] . V_131 ) {
V_57 = F_41 ( V_2 -> V_13 , V_132 ) ;
if ( F_1 ( V_2 ) )
V_57 = ( V_57 & ~ 0x18 ) | ( ( V_139 >> 16 ) & 0x18 ) ;
else
V_57 = ( V_57 & ~ 0x80 ) | ( ( V_139 >> 12 ) & 0x80 ) ;
F_17 ( V_2 -> V_13 , V_132 , V_57 ) ;
}
if ( V_7 -> V_17 . V_20 == 1 )
F_32 ( V_2 -> V_13 , V_134 , V_140 ) ;
return 0 ;
}
static int F_42 ( int V_144 , struct V_6 * V_7 )
{
unsigned char V_145 ;
struct V_1 * V_2 = V_7 -> V_10 ;
int V_146 = V_2 -> V_144 ;
F_7 ( V_7 -> V_15 , L_42 , V_144 ) ;
if ( V_7 -> V_147 != V_148 ||
V_146 == V_144 ) {
F_7 ( V_7 -> V_15 , L_43 ) ;
return 0 ;
}
if ( V_146 == V_149 ||
V_146 == V_150 )
V_145 = 0 ;
else
V_145 = 0x20 ;
V_145 |= F_6 ( V_2 -> V_13 , V_135 ) & 0xdf ;
F_14 ( V_2 -> V_13 , V_135 , V_145 ) ;
switch ( V_144 ) {
case V_150 :
case V_149 :
V_145 = 0x00 ;
break;
case V_151 :
V_145 = 0x04 ;
break;
case V_152 :
V_145 = 0x02 ;
break;
case V_153 :
V_145 = 0x06 ;
break;
default:
F_7 ( V_7 -> V_15 , L_44 ) ;
return 1 ;
}
F_26 ( V_2 -> V_13 , V_154 , V_145 ) ;
V_2 -> V_144 = V_144 ;
F_7 ( V_7 -> V_15 , L_43 ) ;
return ( V_144 == V_149 ) ? 1 : 0 ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
const struct V_59 * V_60 ;
assert ( V_2 != NULL ) ;
V_60 = & V_22 [ V_2 -> V_3 ] ;
switch ( V_2 -> V_3 ) {
case V_117 :
F_43 ( V_2 , 0x01 ) ;
F_44 ( 500 ) ;
F_43 ( V_2 , 0x51 ) ;
F_44 ( 500 ) ;
break;
case V_118 :
F_45 ( V_2 , 0xff ) ;
F_44 ( 500 ) ;
break;
case V_26 :
case V_119 :
F_43 ( V_2 , 0x1f ) ;
F_44 ( 500 ) ;
F_43 ( V_2 , 0x4f ) ;
F_44 ( 500 ) ;
break;
case V_27 :
F_17 ( V_2 -> V_13 , V_155 , 0x00 ) ;
F_46 ( 100 ) ;
F_26 ( V_2 -> V_13 , V_156 , 0x00 ) ;
case V_28 :
F_26 ( V_2 -> V_13 , V_157 , 0x00 ) ;
case V_25 :
F_26 ( V_2 -> V_13 , V_158 , 0x00 ) ;
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
F_25 ( V_2 , V_159 , 0x10 ) ;
F_25 ( V_2 , V_160 , 0x01 ) ;
F_25 ( V_2 , V_159 , 0x08 ) ;
if ( V_2 -> V_3 != V_26 )
F_25 ( V_2 , V_161 , 0x01 ) ;
F_14 ( V_2 -> V_13 , V_162 , 0x03 ) ;
F_14 ( V_2 -> V_13 , V_135 , 0x21 ) ;
F_14 ( V_2 -> V_13 , V_163 , 0x12 ) ;
switch ( V_2 -> V_3 ) {
case V_28 :
F_14 ( V_2 -> V_13 , V_123 , 0x98 ) ;
break;
case V_25 :
case V_4 :
case V_5 :
break;
case V_26 :
#ifdef F_29
F_14 ( V_2 -> V_13 , V_123 , 0xb8 ) ;
#endif
break;
default:
F_14 ( V_2 -> V_13 , V_164 , 0x0f ) ;
F_14 ( V_2 -> V_13 , V_123 , 0xb0 ) ;
break;
}
}
F_14 ( V_2 -> V_13 , V_126 , 0xff ) ;
F_14 ( V_2 -> V_13 , V_165 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_125 , 0x0a ) ;
if ( V_60 -> V_166 )
F_14 ( V_2 -> V_13 , V_120 , V_60 -> V_167 ) ;
F_14 ( V_2 -> V_13 , V_168 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_169 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_170 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_171 , 0x00 ) ;
if ( V_2 -> V_3 != V_27 ) {
F_14 ( V_2 -> V_13 , V_172 , 0x00 ) ;
F_14 ( V_2 -> V_13 , V_173 , 0x02 ) ;
}
F_17 ( V_2 -> V_13 , V_174 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_114 , 0x20 ) ;
F_17 ( V_2 -> V_13 , V_115 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_175 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_176 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_177 , 0x00 ) ;
F_17 ( V_2 -> V_13 , V_130 , 0x02 ) ;
F_26 ( V_2 -> V_13 , V_178 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_179 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_180 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_181 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_182 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_116 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_183 , 0x01 ) ;
F_26 ( V_2 -> V_13 , V_184 , 0x0f ) ;
F_26 ( V_2 -> V_13 , V_185 , 0xff ) ;
if ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_26 ||
F_1 ( V_2 ) )
F_26 ( V_2 -> V_13 , V_186 , 0x20 ) ;
else
F_26 ( V_2 -> V_13 , V_186 , 0x28 ) ;
F_26 ( V_2 -> V_13 , V_187 , 0xff ) ;
F_26 ( V_2 -> V_13 , V_188 , 0x00 ) ;
F_26 ( V_2 -> V_13 , V_154 , 0x00 ) ;
F_32 ( V_2 -> V_13 , V_189 , 0x00 ) ;
F_32 ( V_2 -> V_13 , V_190 , 0x01 ) ;
F_32 ( V_2 -> V_13 , V_191 , 0x02 ) ;
F_32 ( V_2 -> V_13 , V_192 , 0x03 ) ;
F_32 ( V_2 -> V_13 , V_193 , 0x04 ) ;
F_32 ( V_2 -> V_13 , V_194 , 0x05 ) ;
F_32 ( V_2 -> V_13 , V_195 , 0x06 ) ;
F_32 ( V_2 -> V_13 , V_196 , 0x07 ) ;
F_32 ( V_2 -> V_13 , V_197 , 0x08 ) ;
F_32 ( V_2 -> V_13 , V_198 , 0x09 ) ;
F_32 ( V_2 -> V_13 , V_199 , 0x0a ) ;
F_32 ( V_2 -> V_13 , V_200 , 0x0b ) ;
F_32 ( V_2 -> V_13 , V_201 , 0x0c ) ;
F_32 ( V_2 -> V_13 , V_202 , 0x0d ) ;
F_32 ( V_2 -> V_13 , V_203 , 0x0e ) ;
F_32 ( V_2 -> V_13 , V_204 , 0x0f ) ;
F_32 ( V_2 -> V_13 , V_205 , 0x01 ) ;
F_32 ( V_2 -> V_13 , V_206 , 0x00 ) ;
F_32 ( V_2 -> V_13 , V_207 , 0x0f ) ;
F_32 ( V_2 -> V_13 , V_208 , 0x00 ) ;
F_25 ( V_2 , V_124 , 0xff ) ;
F_26 ( V_2 -> V_13 , V_156 , 0x04 ) ;
F_26 ( V_2 -> V_13 , V_156 , 0x00 ) ;
F_28 ( V_2 , 0 ) ;
return;
}
static void F_3 ( struct V_1 * V_2 , int V_209 )
{
#ifdef F_29
static int V_210 = 0 ;
if ( V_2 -> V_3 == V_27 )
return;
if ( V_2 -> V_3 == V_25 )
return;
if ( V_2 -> V_3 == V_28 )
return;
if ( V_2 -> V_3 == V_118 ) {
if ( ( V_209 && ! V_210 ) || ( ! V_209 && V_210 ) )
F_43 ( V_2 , 0xff ) ;
return;
}
if ( V_209 ) {
switch ( V_2 -> V_3 ) {
case V_26 :
F_43 ( V_2 , V_2 -> V_211 | 0x21 ) ;
break;
case V_117 :
F_43 ( V_2 , V_2 -> V_211 | 0x28 ) ;
break;
case V_119 :
F_43 ( V_2 , 0x6f ) ;
break;
default: break;
}
} else {
switch ( V_2 -> V_3 ) {
case V_26 :
F_43 ( V_2 , V_2 -> V_211 & 0xde ) ;
break;
case V_117 :
F_43 ( V_2 , V_2 -> V_211 & 0xd7 ) ;
break;
case V_119 :
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
while ( F_48 ( V_2 -> V_13 , V_156 ) & 0x03 )
F_49 () ;
}
return 0 ;
}
static void F_50 ( struct V_6 * V_7 ,
const struct V_212 * V_213 )
{
struct V_212 V_214 ;
int V_215 , V_216 ;
struct V_1 * V_2 = V_7 -> V_10 ;
int V_217 = V_7 -> V_17 . V_20 ;
T_3 V_218 = ( V_7 -> V_30 . V_75 == V_78 ) ?
V_2 -> V_138 [ V_213 -> V_218 ] : V_213 -> V_218 ;
if ( V_7 -> V_147 != V_148 )
return;
if ( V_7 -> V_219 & V_220 ) {
F_51 ( V_7 , V_213 ) ;
return;
}
V_215 = V_7 -> V_17 . V_42 ;
V_216 = V_7 -> V_17 . V_44 ;
memcpy ( & V_214 , V_213 , sizeof( struct V_212 ) ) ;
if ( ! V_214 . V_221 || ! V_214 . V_222 ||
V_214 . V_223 >= V_215 || V_214 . V_224 >= V_216 )
return;
if ( V_214 . V_223 + V_214 . V_221 > V_215 )
V_214 . V_221 = V_215 - V_214 . V_223 ;
if ( V_214 . V_224 + V_214 . V_222 > V_216 )
V_214 . V_222 = V_216 - V_214 . V_224 ;
F_52 ( V_2 -> V_13 ,
V_7 -> V_17 . V_20 ,
( V_213 -> V_223 * V_217 ) / 8 , V_213 -> V_224 ,
( V_213 -> V_221 * V_217 ) / 8 , V_213 -> V_222 ,
V_218 , V_218 ,
V_7 -> V_30 . V_74 , 0x40 ) ;
}
static void F_53 ( struct V_6 * V_7 ,
const struct V_225 * V_226 )
{
struct V_225 V_214 ;
T_3 V_215 , V_216 ;
struct V_1 * V_2 = V_7 -> V_10 ;
int V_217 = V_7 -> V_17 . V_20 ;
if ( V_7 -> V_147 != V_148 )
return;
if ( V_7 -> V_219 & V_220 ) {
F_54 ( V_7 , V_226 ) ;
return;
}
V_215 = V_7 -> V_17 . V_42 ;
V_216 = V_7 -> V_17 . V_44 ;
memcpy ( & V_214 , V_226 , sizeof( struct V_225 ) ) ;
if ( ! V_214 . V_221 || ! V_214 . V_222 ||
V_214 . V_227 >= V_215 || V_214 . V_228 >= V_216 ||
V_214 . V_223 >= V_215 || V_214 . V_224 >= V_216 )
return;
if ( V_214 . V_227 + V_214 . V_221 > V_215 )
V_214 . V_221 = V_215 - V_214 . V_227 ;
if ( V_214 . V_223 + V_214 . V_221 > V_215 )
V_214 . V_221 = V_215 - V_214 . V_223 ;
if ( V_214 . V_228 + V_214 . V_222 > V_216 )
V_214 . V_222 = V_216 - V_214 . V_228 ;
if ( V_214 . V_224 + V_214 . V_222 > V_216 )
V_214 . V_222 = V_216 - V_214 . V_224 ;
F_55 ( V_2 -> V_13 , V_7 -> V_17 . V_20 ,
( V_226 -> V_227 * V_217 ) / 8 , V_226 -> V_228 ,
( V_226 -> V_223 * V_217 ) / 8 , V_226 -> V_224 ,
( V_226 -> V_221 * V_217 ) / 8 , V_226 -> V_222 ,
V_7 -> V_30 . V_74 ) ;
}
static void F_56 ( struct V_6 * V_7 ,
const struct V_229 * V_230 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
unsigned char V_231 = ( V_7 -> V_17 . V_20 == 24 ) ? 0xc : 0x4 ;
if ( V_7 -> V_147 != V_148 )
return;
if ( V_7 -> V_219 & V_220 || V_230 -> V_232 != 1 )
F_57 ( V_7 , V_230 ) ;
else if ( ( V_2 -> V_3 == V_25 || V_2 -> V_3 == V_26 ) &&
V_231 == 0xc )
F_57 ( V_7 , V_230 ) ;
else {
unsigned V_233 = ( ( V_230 -> V_221 + 7 ) >> 3 ) * V_230 -> V_222 ;
int V_217 = V_7 -> V_17 . V_20 ;
T_3 V_234 , V_235 ;
if ( V_7 -> V_17 . V_20 == 8 ) {
V_234 = V_230 -> V_236 ;
V_235 = V_230 -> V_237 ;
} else {
V_234 = ( ( T_3 * ) ( V_7 -> V_138 ) ) [ V_230 -> V_236 ] ;
V_235 = ( ( T_3 * ) ( V_7 -> V_138 ) ) [ V_230 -> V_237 ] ;
}
if ( V_7 -> V_17 . V_20 == 24 ) {
F_52 ( V_2 -> V_13 ,
V_7 -> V_17 . V_20 ,
( V_230 -> V_223 * V_217 ) / 8 , V_230 -> V_224 ,
( V_230 -> V_221 * V_217 ) / 8 ,
V_230 -> V_222 ,
V_235 , V_235 ,
V_7 -> V_30 . V_74 , 0x40 ) ;
}
F_52 ( V_2 -> V_13 ,
V_7 -> V_17 . V_20 ,
( V_230 -> V_223 * V_217 ) / 8 , V_230 -> V_224 ,
( V_230 -> V_221 * V_217 ) / 8 , V_230 -> V_222 ,
V_234 , V_235 ,
V_7 -> V_30 . V_74 , V_231 ) ;
memcpy ( V_7 -> V_238 , V_230 -> V_239 , V_233 ) ;
}
}
static void F_58 ( unsigned long * V_240 , unsigned long * V_241 )
{
* V_240 = V_242 ;
* V_241 = ( unsigned long ) V_243 ;
}
static unsigned int T_4 F_59 ( struct V_6 * V_7 ,
T_1 T_2 * V_13 )
{
unsigned long V_244 ;
struct V_1 * V_2 = V_7 -> V_10 ;
if ( F_1 ( V_2 ) ) {
unsigned char V_245 = F_6 ( V_13 , V_246 ) ;
V_244 = ( ( V_245 & 7 ) + 1 ) << 20 ;
} else {
unsigned char V_247 = F_6 ( V_13 , V_123 ) ;
switch ( ( V_247 & 0x18 ) ) {
case 0x08 :
V_244 = 512 * 1024 ;
break;
case 0x10 :
V_244 = 1024 * 1024 ;
break;
case 0x18 :
V_244 = 2048 * 1024 ;
break;
default:
F_27 ( V_7 -> V_15 , L_46 ) ;
V_244 = 1024 * 1024 ;
}
if ( V_2 -> V_3 != V_25 && ( V_247 & 0x80 ) != 0 )
V_244 *= 2 ;
}
return V_244 ;
}
static void F_60 ( const struct V_248 * V_249 ,
unsigned long * V_240 , unsigned long * V_241 )
{
assert ( V_249 != NULL ) ;
assert ( V_240 != NULL ) ;
assert ( V_241 != NULL ) ;
* V_240 = 0 ;
* V_241 = 0 ;
if ( F_61 ( V_249 , 0 ) & V_250 ) {
* V_240 = F_62 ( V_249 , 1 ) ;
* V_241 = F_62 ( V_249 , 0 ) ;
} else {
* V_240 = F_62 ( V_249 , 0 ) ;
* V_241 = F_62 ( V_249 , 1 ) ;
}
assert ( * V_240 != 0 ) ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_248 * V_249 = F_64 ( V_7 -> V_15 ) ;
struct V_1 * V_2 = V_7 -> V_10 ;
if ( V_2 -> V_104 == NULL )
F_65 ( V_2 -> V_104 ) ;
F_65 ( V_7 -> V_238 ) ;
#if 0
release_mem_region(0xA0000, 65535);
#endif
if ( V_251 )
F_66 ( 0x3C0 , 32 ) ;
F_67 ( V_249 ) ;
}
static void F_68 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_252 * V_253 = F_69 ( V_7 -> V_15 ) ;
if ( V_7 -> V_30 . V_254 > 16 * V_32 )
F_65 ( V_7 -> V_238 ) ;
if ( V_7 -> V_30 . V_255 > 16 * V_32 )
F_65 ( V_2 -> V_13 ) ;
F_70 ( V_253 ) ;
}
static int T_4 F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_16 * V_17 = & V_7 -> V_17 ;
V_7 -> V_138 = V_2 -> V_138 ;
V_7 -> V_219 = V_256
| V_257
| V_258
| V_259
| V_260
| V_261 ;
if ( V_262 || F_1 ( V_2 ) ) {
V_7 -> V_219 |= V_220 ;
V_7 -> V_30 . V_263 = V_264 ;
} else
V_7 -> V_30 . V_263 = V_265 ;
V_7 -> V_266 = & V_267 ;
if ( V_2 -> V_3 == V_28 ) {
if ( V_17 -> V_20 == 16 )
V_7 -> V_238 += 1 * V_32 ;
if ( V_17 -> V_20 == 32 )
V_7 -> V_238 += 2 * V_32 ;
}
F_72 ( V_7 -> V_30 . V_268 , V_22 [ V_2 -> V_3 ] . V_269 ,
sizeof( V_7 -> V_30 . V_268 ) ) ;
V_7 -> V_30 . V_31 = V_7 -> V_35 ;
if ( V_17 -> V_20 == 1 )
V_7 -> V_30 . V_31 /= 4 ;
V_7 -> V_30 . V_270 = 0 ;
V_7 -> V_30 . V_271 = 1 ;
V_7 -> V_30 . V_272 = 1 ;
V_7 -> V_30 . V_273 = 0 ;
V_7 -> V_30 . V_274 = 0 ;
F_73 ( & V_7 -> V_275 , 256 , 0 ) ;
return 0 ;
}
static int T_4 F_74 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
int V_276 ;
assert ( V_2 -> V_3 != V_277 ) ;
F_71 ( V_7 ) ;
F_7 ( V_7 -> V_15 , L_47 , V_7 -> V_238 ) ;
V_276 = F_75 ( & V_7 -> V_17 , V_7 , V_278 , NULL , 0 , NULL , 8 ) ;
if ( ! V_276 ) {
F_7 ( V_7 -> V_15 , L_48 ) ;
V_276 = - V_24 ;
goto V_279;
}
V_7 -> V_17 . V_280 = V_281 ;
V_276 = F_11 ( & V_7 -> V_17 , V_7 ) ;
if ( V_276 < 0 ) {
F_7 ( V_7 -> V_15 ,
L_49 ) ;
goto V_279;
}
V_276 = F_76 ( V_7 ) ;
if ( V_276 < 0 ) {
F_10 ( V_7 -> V_15 ,
L_50 , V_276 ) ;
goto V_279;
}
return 0 ;
V_279:
F_77 ( & V_7 -> V_275 ) ;
return V_276 ;
}
static void T_5 F_78 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
F_3 ( V_2 , 0 ) ;
F_79 ( V_7 ) ;
F_77 ( & V_7 -> V_275 ) ;
F_7 ( V_7 -> V_15 , L_51 ) ;
V_2 -> V_282 ( V_7 ) ;
F_80 ( V_7 ) ;
}
static int T_4 F_81 ( struct V_248 * V_249 ,
const struct V_283 * V_284 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
unsigned long V_285 , V_286 ;
int V_287 ;
V_287 = F_82 ( V_249 ) ;
if ( V_287 < 0 ) {
F_83 ( V_288 L_52 ) ;
goto V_289;
}
V_7 = F_84 ( sizeof( struct V_1 ) , & V_249 -> V_290 ) ;
if ( ! V_7 ) {
F_83 ( V_288 L_53 ) ;
V_287 = - V_291 ;
goto V_289;
}
V_2 = V_7 -> V_10 ;
V_2 -> V_3 = (enum V_292 ) V_284 -> V_293 ;
F_7 ( V_7 -> V_15 ,
L_54 ,
( unsigned long long ) V_249 -> V_294 [ 0 ] . V_295 , V_2 -> V_3 ) ;
F_7 ( V_7 -> V_15 , L_55 ,
( unsigned long long ) V_249 -> V_294 [ 1 ] . V_295 ) ;
if ( V_41 ) {
F_85 ( V_249 , V_296 , 0x00000000 ) ;
#ifdef F_86
F_58 ( & V_285 , & V_7 -> V_30 . V_255 ) ;
#endif
V_2 -> V_13 = ( char T_2 * ) V_7 -> V_30 . V_255 ;
} else {
F_7 ( V_7 -> V_15 ,
L_56 ) ;
F_60 ( V_249 , & V_285 , & V_7 -> V_30 . V_255 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_104 = F_87 ( V_7 -> V_30 . V_255 , 0x1000 ) ;
}
F_7 ( V_7 -> V_15 , L_57 ,
V_285 , V_7 -> V_30 . V_255 ) ;
V_286 = ( V_2 -> V_3 == V_28 ) ?
32 * V_32 : F_59 ( V_7 , V_2 -> V_13 ) ;
V_287 = F_88 ( V_249 , L_58 ) ;
if ( V_287 < 0 ) {
F_10 ( V_7 -> V_15 , L_59 ,
V_285 ) ;
goto V_297;
}
#if 0
if (!request_mem_region(0xA0000, 65535, "cirrusfb")) {
dev_err(info->device, "cannot reserve region 0x%lx, abort\n",
0xA0000L);
ret = -EBUSY;
goto err_release_regions;
}
#endif
if ( F_89 ( 0x3C0 , 32 , L_58 ) )
V_251 = 1 ;
V_7 -> V_238 = F_87 ( V_285 , V_286 ) ;
if ( ! V_7 -> V_238 ) {
V_287 = - V_298 ;
goto V_299;
}
V_7 -> V_30 . V_254 = V_285 ;
V_7 -> V_35 = V_286 ;
V_2 -> V_282 = F_63 ;
F_12 ( V_7 -> V_15 ,
L_60 ,
V_7 -> V_35 >> 10 , V_285 ) ;
F_90 ( V_249 , V_7 ) ;
V_287 = F_74 ( V_7 ) ;
if ( ! V_287 )
return 0 ;
F_90 ( V_249 , NULL ) ;
F_65 ( V_7 -> V_238 ) ;
V_299:
if ( V_251 )
F_66 ( 0x3C0 , 32 ) ;
#if 0
release_mem_region(0xA0000, 65535);
err_release_regions:
#endif
F_67 ( V_249 ) ;
V_297:
if ( V_2 -> V_104 != NULL )
F_65 ( V_2 -> V_104 ) ;
F_80 ( V_7 ) ;
V_289:
return V_287 ;
}
static void T_5 F_91 ( struct V_248 * V_249 )
{
struct V_6 * V_7 = F_92 ( V_249 ) ;
F_78 ( V_7 ) ;
}
static int T_4 F_93 ( struct V_252 * V_300 ,
const struct V_301 * V_284 )
{
struct V_6 * V_7 ;
int error ;
const struct V_302 * V_303 ;
enum V_292 V_3 ;
unsigned long V_13 , V_304 , V_305 ;
struct V_1 * V_2 ;
V_7 = F_84 ( sizeof( struct V_1 ) , & V_300 -> V_290 ) ;
if ( ! V_7 ) {
F_83 ( V_288 L_53 ) ;
return - V_291 ;
}
V_303 = ( const struct V_302 * ) V_284 -> V_293 ;
V_3 = V_303 -> type ;
V_13 = F_94 ( V_300 ) + V_303 -> V_306 ;
V_304 = V_303 -> V_304 ;
if ( V_304 ) {
V_305 = F_94 ( V_300 ) + V_303 -> V_307 ;
if ( F_95 ( V_300 ) == 64 * V_32 ) {
V_305 += V_303 -> V_307 ;
}
} else {
struct V_252 * V_308 = F_96 ( V_303 -> V_309 , NULL ) ;
if ( ! V_308 || ! F_95 ( V_308 ) ) {
F_10 ( V_7 -> V_15 , L_61 ) ;
error = - V_310 ;
goto V_297;
}
V_305 = F_94 ( V_308 ) ;
V_304 = F_95 ( V_308 ) ;
if ( V_303 -> V_311 &&
( V_308 = F_96 ( V_303 -> V_311 , NULL ) ) ) {
if ( F_94 ( V_308 ) != V_305 + V_304 ) {
F_27 ( V_7 -> V_15 ,
L_62 ,
& V_308 -> V_294 ) ;
} else {
V_304 += F_95 ( V_308 ) ;
}
}
}
F_12 ( V_7 -> V_15 ,
L_63 ,
V_22 [ V_3 ] . V_269 , V_13 , V_304 / V_32 ,
V_305 ) ;
if ( ! F_97 ( V_300 , L_58 ) ) {
F_10 ( V_7 -> V_15 , L_64 , & V_300 -> V_294 ) ;
error = - V_312 ;
goto V_297;
}
V_2 = V_7 -> V_10 ;
V_2 -> V_3 = V_3 ;
V_7 -> V_30 . V_255 = V_13 ;
V_2 -> V_13 = V_13 > 16 * V_32 ? F_87 ( V_13 , 64 * 1024 )
: ( V_313 ) F_98 ( V_13 ) ;
if ( ! V_2 -> V_13 ) {
F_10 ( V_7 -> V_15 , L_65 ) ;
error = - V_298 ;
goto V_314;
}
V_7 -> V_30 . V_254 = V_305 ;
V_7 -> V_35 = V_304 ;
V_7 -> V_238 = V_305 > 16 * V_32 ? F_87 ( V_305 , V_304 )
: ( V_313 ) F_98 ( V_305 ) ;
if ( ! V_7 -> V_238 ) {
F_10 ( V_7 -> V_15 , L_66 ) ;
error = - V_298 ;
goto V_315;
}
V_2 -> V_282 = F_68 ;
F_12 ( V_7 -> V_15 ,
L_67 ,
V_304 / V_32 , V_305 ) ;
if ( V_22 [ V_3 ] . V_316 )
F_14 ( V_2 -> V_13 , V_14 ,
V_22 [ V_3 ] . V_317 ) ;
error = F_74 ( V_7 ) ;
if ( error ) {
F_10 ( V_7 -> V_15 , L_68 ,
error ) ;
goto V_318;
}
F_99 ( V_300 , V_7 ) ;
return 0 ;
V_318:
if ( V_305 > 16 * V_32 )
F_65 ( V_7 -> V_238 ) ;
V_315:
if ( V_13 > 16 * V_32 )
F_65 ( V_2 -> V_13 ) ;
V_314:
F_70 ( V_300 ) ;
V_297:
F_80 ( V_7 ) ;
return error ;
}
void T_5 F_100 ( struct V_252 * V_300 )
{
struct V_6 * V_7 = F_101 ( V_300 ) ;
F_78 ( V_7 ) ;
F_99 ( V_300 , NULL ) ;
}
static int T_6 F_102 ( char * V_319 )
{
char * V_320 ;
if ( ! V_319 || ! * V_319 )
return 0 ;
while ( ( V_320 = F_103 ( & V_319 , L_69 ) ) != NULL ) {
if ( ! * V_320 )
continue;
if ( ! strcmp ( V_320 , L_70 ) )
V_262 = 1 ;
else if ( ! strncmp ( V_320 , L_71 , 5 ) )
V_278 = V_320 + 5 ;
else
V_278 = V_320 ;
}
return 0 ;
}
static int T_6 F_104 ( void )
{
int error = 0 ;
#ifndef F_105
char * V_321 = NULL ;
if ( F_106 ( L_58 , & V_321 ) )
return - V_310 ;
F_102 ( V_321 ) ;
#endif
#ifdef F_29
error |= F_107 ( & V_322 ) ;
#endif
#ifdef F_30
error |= F_108 ( & V_323 ) ;
#endif
return error ;
}
static void T_7 F_109 ( void )
{
#ifdef F_30
F_110 ( & V_323 ) ;
#endif
#ifdef F_29
F_111 ( & V_322 ) ;
#endif
}
static void F_25 ( const struct V_1 * V_2 ,
int V_324 , unsigned char V_145 )
{
unsigned long V_325 = 0 ;
if ( V_2 -> V_3 == V_118 ) {
if ( V_324 == V_326 || V_324 == V_327 )
V_325 = 0xfff ;
}
F_112 ( V_2 -> V_13 , V_325 + V_324 , V_145 ) ;
}
static unsigned char F_113 ( const struct V_1 * V_2 , int V_324 )
{
unsigned long V_325 = 0 ;
if ( V_2 -> V_3 == V_118 ) {
if ( V_324 == V_326 || V_324 == V_327 )
V_325 = 0xfff ;
}
return F_114 ( V_2 -> V_13 , V_325 + V_324 ) ;
}
static void F_33 ( const struct V_1 * V_2 )
{
assert ( V_2 != NULL ) ;
if ( F_41 ( V_2 -> V_13 , V_328 ) & 0x80 ) {
F_112 ( V_2 -> V_13 , V_329 ,
F_114 ( V_2 -> V_13 , V_330 ) ) ;
}
F_112 ( V_2 -> V_13 , V_329 , 0x33 ) ;
F_112 ( V_2 -> V_13 , V_329 , 0x00 ) ;
}
static void F_28 ( const struct V_1 * V_2 , unsigned char V_145 )
{
unsigned char V_331 ;
if ( F_1 ( V_2 ) )
return;
if ( V_2 -> V_3 == V_118 ) {
F_25 ( V_2 , V_124 , 0x00 ) ;
F_44 ( 200 ) ;
V_331 = F_113 ( V_2 , V_332 ) ;
F_44 ( 200 ) ;
}
V_331 = F_113 ( V_2 , V_124 ) ;
F_44 ( 200 ) ;
V_331 = F_113 ( V_2 , V_124 ) ;
F_44 ( 200 ) ;
V_331 = F_113 ( V_2 , V_124 ) ;
F_44 ( 200 ) ;
V_331 = F_113 ( V_2 , V_124 ) ;
F_44 ( 200 ) ;
F_25 ( V_2 , V_124 , V_145 ) ;
F_44 ( 200 ) ;
if ( V_2 -> V_3 == V_118 ) {
V_331 = F_113 ( V_2 , V_332 ) ;
F_44 ( 200 ) ;
F_25 ( V_2 , V_124 , 0xff ) ;
F_44 ( 200 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , unsigned char V_145 )
{
#ifdef F_29
assert ( V_2 -> V_13 != NULL ) ;
V_2 -> V_211 = V_145 ;
F_115 ( V_145 , V_2 -> V_13 + 0x8000 ) ;
#endif
}
static void F_45 ( struct V_1 * V_2 , unsigned char V_145 )
{
#ifdef F_29
assert ( V_2 -> V_13 != NULL ) ;
V_2 -> V_211 = V_145 ;
F_115 ( V_145 , V_2 -> V_13 + 0x9000 ) ;
#endif
}
static void F_38 ( struct V_1 * V_2 , unsigned char V_324 , unsigned char V_36 ,
unsigned char V_39 , unsigned char V_40 )
{
unsigned int V_239 = V_327 ;
F_112 ( V_2 -> V_13 , V_332 , V_324 ) ;
if ( V_2 -> V_3 == V_118 || V_2 -> V_3 == V_27 ||
V_2 -> V_3 == V_25 || V_2 -> V_3 == V_28 ||
V_2 -> V_3 == V_26 || F_1 ( V_2 ) ) {
if ( V_2 -> V_3 == V_118 )
V_239 += 0xfff ;
F_112 ( V_2 -> V_13 , V_239 , V_36 ) ;
F_112 ( V_2 -> V_13 , V_239 , V_39 ) ;
F_112 ( V_2 -> V_13 , V_239 , V_40 ) ;
} else {
F_112 ( V_2 -> V_13 , V_239 , V_40 ) ;
F_112 ( V_2 -> V_13 , V_239 , V_39 ) ;
F_112 ( V_2 -> V_13 , V_239 , V_36 ) ;
}
}
static void F_40 ( T_1 T_2 * V_13 )
{
while ( F_48 ( V_13 , V_156 ) & 0x08 )
F_49 () ;
}
static void F_116 ( T_1 T_2 * V_13 ,
T_8 V_333 , T_8 V_334 ,
T_9 V_335 , T_9 V_336 ,
T_8 V_337 , T_8 V_74 )
{
F_26 ( V_13 , V_338 , V_74 & 0xff ) ;
F_26 ( V_13 , V_339 , V_74 >> 8 ) ;
F_26 ( V_13 , V_340 , V_74 & 0xff ) ;
F_26 ( V_13 , V_341 , V_74 >> 8 ) ;
F_26 ( V_13 , V_342 , V_333 & 0xff ) ;
F_26 ( V_13 , V_343 , V_333 >> 8 ) ;
F_26 ( V_13 , V_344 , V_334 & 0xff ) ;
F_26 ( V_13 , V_345 , V_334 >> 8 ) ;
F_26 ( V_13 , V_346 , ( V_347 ) ( V_336 & 0xff ) ) ;
F_26 ( V_13 , V_348 , ( V_347 ) ( V_336 >> 8 ) ) ;
F_26 ( V_13 , V_349 , ( V_347 ) ( V_336 >> 16 ) ) ;
F_26 ( V_13 , V_350 , ( V_347 ) ( V_335 & 0xff ) ) ;
F_26 ( V_13 , V_351 , ( V_347 ) ( V_335 >> 8 ) ) ;
F_26 ( V_13 , V_352 , ( V_347 ) ( V_335 >> 16 ) ) ;
F_26 ( V_13 , V_353 , V_337 ) ;
F_26 ( V_13 , V_354 , 0x0d ) ;
F_26 ( V_13 , V_156 , 0x02 ) ;
}
static void F_55 ( T_1 T_2 * V_13 , int V_20 ,
T_8 V_355 , T_8 V_356 ,
T_8 V_357 , T_8 V_358 ,
T_8 V_221 , T_8 V_222 ,
T_8 V_74 )
{
T_8 V_333 = V_221 - 1 ;
T_8 V_334 = V_222 - 1 ;
T_9 V_335 , V_336 ;
V_347 V_337 ;
V_337 = 0x00 ;
if ( V_356 <= V_358 ) {
if ( V_356 == V_358 ) {
if ( V_355 < V_357 )
V_337 |= 0x01 ;
} else
V_337 |= 0x01 ;
}
V_335 = ( V_356 * V_74 ) + V_355 ;
V_336 = ( V_358 * V_74 ) + V_357 ;
if ( V_337 ) {
V_335 += V_334 * V_74 + V_333 ;
V_336 += V_334 * V_74 + V_333 ;
}
F_40 ( V_13 ) ;
F_116 ( V_13 , V_333 , V_334 ,
V_335 , V_336 , V_337 , V_74 ) ;
}
static void F_52 ( T_1 T_2 * V_13 , int V_20 ,
T_8 V_359 , T_8 V_360 , T_8 V_221 , T_8 V_222 ,
T_3 V_236 , T_3 V_237 , T_8 V_74 ,
V_347 V_361 )
{
T_9 V_336 = ( V_360 * V_74 ) + V_359 ;
V_347 V_231 ;
F_40 ( V_13 ) ;
F_26 ( V_13 , V_178 , V_237 ) ;
F_26 ( V_13 , V_179 , V_236 ) ;
V_231 = 0x80 ;
if ( V_20 >= 16 ) {
F_26 ( V_13 , V_362 , V_237 >> 8 ) ;
F_26 ( V_13 , V_363 , V_236 >> 8 ) ;
V_231 = 0x90 ;
}
if ( V_20 >= 24 ) {
F_26 ( V_13 , V_364 , V_237 >> 16 ) ;
F_26 ( V_13 , V_365 , V_236 >> 16 ) ;
V_231 = 0xa0 ;
}
if ( V_20 == 32 ) {
F_26 ( V_13 , V_366 , V_237 >> 24 ) ;
F_26 ( V_13 , V_367 , V_236 >> 24 ) ;
V_231 = 0xb0 ;
}
F_116 ( V_13 , V_221 - 1 , V_222 - 1 ,
0 , V_336 , V_231 | V_361 , V_74 ) ;
}
static void F_18 ( long V_11 , int * V_69 , int * V_70 , int * div )
{
int V_368 , V_369 ;
long V_370 , V_371 ;
assert ( V_69 != NULL ) ;
assert ( V_70 != NULL ) ;
assert ( div != NULL ) ;
* V_69 = 0 ;
* V_70 = 0 ;
* div = 0 ;
if ( V_11 < 8000 )
V_11 = 8000 ;
V_371 = V_11 ;
for ( V_368 = 32 ; V_368 < 128 ; V_368 ++ ) {
int V_372 = 0 ;
V_369 = ( 14318 * V_368 ) / V_11 ;
if ( ( V_369 >= 7 ) && ( V_369 <= 63 ) ) {
int V_373 = V_369 ;
if ( V_373 > 31 ) {
V_372 = 1 ;
V_373 >>= 1 ;
}
V_370 = ( ( 14318 * V_368 ) / V_373 ) >> V_372 ;
V_370 = V_370 > V_11 ? V_370 - V_11 : V_11 - V_370 ;
if ( V_370 < V_371 ) {
V_371 = V_370 ;
* V_69 = V_368 ;
* V_70 = V_373 ;
* div = V_372 ;
}
}
V_369 ++ ;
if ( ( V_369 >= 7 ) && ( V_369 <= 63 ) ) {
if ( V_369 > 31 ) {
V_372 = 1 ;
V_369 >>= 1 ;
}
V_370 = ( ( 14318 * V_368 ) / V_369 ) >> V_372 ;
V_370 = V_370 > V_11 ? V_370 - V_11 : V_11 - V_370 ;
if ( V_370 < V_371 ) {
V_371 = V_370 ;
* V_69 = V_368 ;
* V_70 = V_369 ;
* div = V_372 ;
}
}
}
}
static void F_117 ( struct V_6 * V_7 ,
V_313 V_13 ,
enum V_374 V_375 , ... )
{
T_10 V_376 ;
unsigned char V_145 = 0 ;
unsigned V_377 ;
char * V_269 ;
va_start ( V_376 , V_375 ) ;
V_269 = va_arg ( V_376 , char * ) ;
while ( V_269 != NULL ) {
V_377 = va_arg ( V_376 , int ) ;
switch ( V_375 ) {
case V_378 :
V_145 = F_41 ( V_13 , ( unsigned char ) V_377 ) ;
break;
case V_379 :
V_145 = F_6 ( V_13 , ( unsigned char ) V_377 ) ;
break;
default:
assert ( false ) ;
break;
}
F_7 ( V_7 -> V_15 , L_72 , V_269 , V_145 ) ;
V_269 = va_arg ( V_376 , char * ) ;
}
va_end ( V_376 ) ;
}
static void F_35 ( struct V_6 * V_7 , V_313 V_13 )
{
F_7 ( V_7 -> V_15 , L_73 ) ;
F_117 ( V_7 , V_13 , V_378 ,
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
F_117 ( V_7 , V_13 , V_379 ,
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
