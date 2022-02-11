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
static T_1 F_9 ( struct V_1 * V_2 )
{
T_1 V_13 , V_14 ;
if ( ! ( F_3 ( V_2 , V_15 ) &
V_16 ) )
return 0 ;
F_2 ( V_2 , V_17 ,
F_10 ( V_18 ) ) ;
F_11 ( 1000 , 2000 ) ;
V_13 = F_3 ( V_2 , V_17 ) ;
V_13 &= V_19 ;
F_2 ( V_2 , V_17 , 0 ) ;
V_14 = V_13 * 32768 / 4 ;
return ( V_14 + 50000 ) / 100000 * 100 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
T_1 V_24 = 0 , V_25 ;
T_1 V_26 , V_7 ;
switch ( V_22 -> V_27 . V_28 ) {
case V_29 :
switch ( V_20 ) {
case 12000 :
V_24 = 0x50D52 ;
break;
case 20000 :
V_24 = 0x307FE ;
break;
case 26000 :
V_24 = 0x254EA ;
break;
case 37400 :
V_24 = 0x19EF8 ;
break;
case 52000 :
V_24 = 0x12A75 ;
break;
}
break;
}
if ( ! V_24 ) {
F_13 ( V_22 , L_1 ,
V_20 ) ;
return;
}
V_26 = F_1 ( V_2 , V_30 ) ;
V_25 = ( V_26 & V_31 ) >>
V_32 ;
if ( V_25 == V_24 ) {
F_14 ( V_22 , L_2 ) ;
return;
}
switch ( V_22 -> V_27 . V_28 ) {
case V_29 :
V_7 = ( T_1 ) ~ ( V_33 |
V_34 ) ;
F_15 ( V_2 , V_35 , V_7 ) ;
F_15 ( V_2 , V_36 , V_7 ) ;
F_16 ( V_2 -> V_23 , V_37 ,
V_38 , 0 , 20000 ) ;
break;
}
V_26 &= ~ V_31 ;
V_26 |= V_24 << V_32 ;
F_4 ( V_2 , V_30 , V_26 ) ;
if ( V_2 -> V_39 . V_40 >= 2 )
F_17 ( V_2 , V_41 , V_42 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
T_1 V_20 = F_9 ( V_2 ) ;
switch ( V_22 -> V_27 . V_28 ) {
case V_29 :
if ( V_20 == 0 )
V_20 = 20000 ;
F_12 ( V_2 , V_20 ) ;
break;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
T_1 V_43 = 0 , V_44 = 0 ;
switch ( V_22 -> V_27 . V_28 ) {
case V_45 :
V_43 = 0x200D ;
V_44 = 0xFFFF ;
break;
case V_29 :
V_43 = V_46 |
V_47 |
V_48 |
V_49 |
V_50 |
V_51 |
V_52 |
V_53 |
V_54 |
V_55 |
V_56 |
V_57 |
V_58 |
V_59 |
V_60 |
V_61 ;
V_44 = 0x3FFFFFFF ;
break;
default:
F_14 ( V_22 , L_3 ,
V_22 -> V_27 . V_28 ) ;
}
if ( V_43 )
F_2 ( V_2 , V_35 , V_43 ) ;
if ( V_44 )
F_2 ( V_2 , V_36 , V_44 ) ;
F_20 ( 2 ) ;
}
void F_21 ( struct V_1 * V_2 , bool V_62 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
T_1 V_63 ;
V_63 = F_22 ( V_2 , V_64 ) ;
if ( V_62 ) {
V_63 |= V_65 ;
if ( V_22 -> V_27 . V_66 == 9 || V_22 -> V_27 . V_66 == 11 )
V_63 |= V_67 ;
else if ( V_22 -> V_27 . V_40 > 0 )
V_63 |= V_68 ;
} else {
V_63 &= ~ V_65 ;
V_63 &= ~ V_68 ;
V_63 &= ~ V_67 ;
}
F_23 ( V_2 , V_64 , V_63 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
switch ( V_22 -> V_27 . V_28 ) {
case V_45 :
F_7 ( V_2 , 0 ,
~ V_69 ,
V_69 ) ;
break;
case V_70 :
case V_71 :
F_21 ( V_2 , true ) ;
break;
case V_72 :
case V_73 :
if ( V_22 -> V_27 . V_40 == 0 ) {
F_25 ( V_2 , V_64 ,
~ V_74 ,
V_74 ) ;
F_7 ( V_2 , 0 ,
~ V_75 ,
V_75 ) ;
} else {
F_7 ( V_2 , 0 ,
~ V_76 ,
V_76 ) ;
}
break;
default:
F_14 ( V_22 , L_4 ,
V_22 -> V_27 . V_28 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
T_1 V_77 ;
if ( V_2 -> V_23 -> V_28 . V_40 >= 35 &&
V_2 -> V_78 & V_79 ) {
V_2 -> V_39 . V_23 = F_27 ( V_22 , V_80 ) ;
if ( ! V_2 -> V_39 . V_23 )
F_28 ( V_22 , L_5 ) ;
}
if ( ! V_2 -> V_39 . V_23 )
V_2 -> V_39 . V_23 = V_2 -> V_23 ;
V_77 = F_3 ( V_2 , V_81 ) ;
V_2 -> V_39 . V_40 = ( V_77 & V_82 ) ;
F_14 ( V_22 , L_6 , V_2 -> V_39 . V_40 ,
V_77 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 . V_40 == 1 )
F_15 ( V_2 , V_41 ,
~ V_83 ) ;
else
F_17 ( V_2 , V_41 ,
V_83 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_24 ( V_2 ) ;
}
T_1 F_30 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
switch ( V_22 -> V_27 . V_28 ) {
case V_45 :
case V_72 :
case V_84 :
case V_85 :
case V_86 :
case V_70 :
case V_73 :
case V_87 :
case V_71 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
return 20000 * 1000 ;
case V_95 :
case V_96 :
return 25000 * 1000 ;
case V_97 :
case V_98 :
case V_99 :
if ( V_2 -> V_100 & V_101 )
return 40000 * 1000 ;
else
return 20000 * 1000 ;
default:
F_28 ( V_22 , L_7 ,
V_22 -> V_27 . V_28 , V_2 -> V_39 . V_40 , V_102 ) ;
}
return V_102 ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_103 )
{
T_1 V_104 , div , V_105 , V_106 , V_107 , V_108 ;
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
F_32 ( ( V_26 & 3 ) || ( V_26 > V_109 ) ) ;
F_32 ( ! V_103 || V_103 > 4 ) ;
if ( V_22 -> V_27 . V_28 == V_92 ||
V_22 -> V_27 . V_28 == V_91 ) {
V_104 = F_22 ( V_2 , V_110 ) ;
if ( V_104 & 0x40000 )
return 133 * 1000000 ;
}
V_104 = F_1 ( V_2 , V_26 + V_111 ) ;
V_106 = ( V_104 & V_112 ) >> V_113 ;
V_107 = ( V_104 & V_114 ) >> V_115 ;
V_104 = F_1 ( V_2 , V_26 + V_116 ) ;
div = ( V_104 >> ( ( V_103 - 1 ) * V_117 ) ) &
V_118 ;
V_104 = F_1 ( V_2 , V_26 + V_119 ) ;
V_105 = ( V_104 & V_120 ) >> V_121 ;
V_108 = F_30 ( V_2 ) / 1000000 ;
V_108 = ( V_106 * V_105 * V_108 ) / V_107 ;
return ( V_108 / div ) * 1000000 ;
}
static T_1 F_33 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_103 )
{
T_1 V_104 , V_105 , V_122 , V_123 ;
T_1 clock ;
F_32 ( ! V_103 || V_103 > 4 ) ;
V_104 = F_1 ( V_2 , V_26 + V_124 ) ;
V_105 = ( V_104 & V_125 )
>> V_126 ;
V_122 = ( V_104 & V_127 )
>> V_128 ;
V_123 = ( V_104 & V_129 )
>> V_130 ;
V_104 = F_22 ( V_2 , V_110 ) ;
if ( V_104 & V_131 )
clock = ( 25000000 / 4 ) * V_105 * V_123 / V_122 ;
else
clock = ( 25000000 / 2 ) * V_105 * V_123 / V_122 ;
if ( V_103 == V_132 )
clock = clock / 4 ;
return clock ;
}
T_1 F_34 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
switch ( V_22 -> V_27 . V_28 ) {
case V_88 :
case V_90 :
case V_89 :
return F_31 ( V_2 , V_109 ,
V_132 ) ;
case V_96 :
return F_31 ( V_2 , V_133 ,
V_132 ) ;
case V_92 :
case V_91 :
return F_31 ( V_2 , V_134 ,
V_132 ) ;
case V_95 :
return F_33 ( V_2 ,
V_135 ,
V_132 ) ;
case V_93 :
return 75000000 ;
default:
F_28 ( V_22 , L_8 ,
V_22 -> V_27 . V_28 , V_2 -> V_39 . V_40 , V_136 ) ;
}
return V_136 ;
}
T_1 F_35 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
if ( V_22 -> V_27 . V_28 == V_93 )
return 300000000 ;
if ( V_2 -> V_39 . V_40 >= 5 ) {
T_1 V_137 ;
switch ( V_22 -> V_27 . V_28 ) {
case V_95 :
return F_33 ( V_2 ,
V_135 ,
V_138 ) ;
case V_96 :
V_137 = V_133 ;
break;
case V_92 :
case V_91 :
V_137 = V_134 ;
break;
default:
V_137 = V_109 ;
break;
}
return F_31 ( V_2 , V_137 , V_138 ) ;
}
return F_34 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
void F_37 ( struct V_1 * V_2 , int V_139 )
{
T_1 V_104 = 0 ;
T_2 V_140 = 0 ;
T_2 V_141 [] = { 0x1 , 0x5 , 0x5 } ;
T_2 V_142 [] = { 0x30 , 0xf6 , 0xfc } ;
struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
switch ( V_22 -> V_27 . V_28 ) {
case V_92 :
case V_91 :
case V_93 :
V_140 = ( V_22 -> V_27 . V_28 == V_92 ||
V_22 -> V_27 . V_28 == V_91 ||
V_22 -> V_27 . V_28 == V_93 ) ? 6 : 0 ;
F_2 ( V_2 , V_4 ,
V_143 + V_140 ) ;
V_104 = F_3 ( V_2 , V_5 ) ;
V_104 &= ( ~ ( V_144 ) ) ;
V_104 |= ( V_141 [ V_139 ] << V_145 ) ;
F_2 ( V_2 , V_5 , V_104 ) ;
F_2 ( V_2 , V_4 ,
V_146 + V_140 ) ;
V_104 = F_3 ( V_2 , V_5 ) ;
V_104 &= ~ ( V_147 ) ;
V_104 |= ( V_142 [ V_139 ] ) << V_148 ;
F_2 ( V_2 , V_5 , V_104 ) ;
V_104 = V_42 ;
break;
case V_70 :
case V_71 :
if ( V_139 == 2 ) {
F_36 ( V_2 , V_143 ,
0x11500014 ) ;
F_36 ( V_2 , V_146 ,
0x0FC00a08 ) ;
} else if ( V_139 == 1 ) {
F_36 ( V_2 , V_143 ,
0x11500014 ) ;
F_36 ( V_2 , V_146 ,
0x0F600a08 ) ;
} else {
F_36 ( V_2 , V_143 ,
0x11100014 ) ;
F_36 ( V_2 , V_146 ,
0x03000a08 ) ;
}
V_104 = V_42 ;
break;
case V_72 :
case V_84 :
case V_73 :
if ( V_139 == 1 ) {
F_36 ( V_2 , V_143 ,
0x11500010 ) ;
F_36 ( V_2 , V_149 ,
0x000C0C06 ) ;
F_36 ( V_2 , V_146 ,
0x0F600a08 ) ;
F_36 ( V_2 , V_150 ,
0x00000000 ) ;
F_36 ( V_2 , V_151 ,
0x2001E920 ) ;
F_36 ( V_2 , V_152 ,
0x88888815 ) ;
} else {
F_36 ( V_2 , V_143 ,
0x11100010 ) ;
F_36 ( V_2 , V_149 ,
0x000c0c06 ) ;
F_36 ( V_2 , V_146 ,
0x03000a08 ) ;
F_36 ( V_2 , V_150 ,
0x00000000 ) ;
F_36 ( V_2 , V_151 ,
0x200005c0 ) ;
F_36 ( V_2 , V_152 ,
0x88888815 ) ;
}
V_104 = V_42 ;
break;
case V_88 :
case V_90 :
case V_89 :
if ( V_139 == 1 ) {
F_36 ( V_2 , V_143 ,
0x11500060 ) ;
F_36 ( V_2 , V_149 ,
0x080C0C06 ) ;
F_36 ( V_2 , V_146 ,
0x0F600000 ) ;
F_36 ( V_2 , V_150 ,
0x00000000 ) ;
F_36 ( V_2 , V_151 ,
0x2001E924 ) ;
F_36 ( V_2 , V_152 ,
0x88888815 ) ;
} else {
F_36 ( V_2 , V_143 ,
0x11100060 ) ;
F_36 ( V_2 , V_149 ,
0x080c0c06 ) ;
F_36 ( V_2 , V_146 ,
0x03000000 ) ;
F_36 ( V_2 , V_150 ,
0x00000000 ) ;
F_36 ( V_2 , V_151 ,
0x200005c0 ) ;
F_36 ( V_2 , V_152 ,
0x88888815 ) ;
}
V_104 = V_42 | V_83 ;
break;
case V_153 :
case V_154 :
case V_85 :
case V_86 :
case V_87 :
if ( V_139 == 1 ) {
F_36 ( V_2 , V_143 ,
0x01100014 ) ;
F_36 ( V_2 , V_149 ,
0x040C0C06 ) ;
F_36 ( V_2 , V_146 ,
0x03140A08 ) ;
F_36 ( V_2 , V_150 ,
0x00333333 ) ;
F_36 ( V_2 , V_151 ,
0x202C2820 ) ;
F_36 ( V_2 , V_152 ,
0x88888815 ) ;
} else {
F_36 ( V_2 , V_143 ,
0x11100014 ) ;
F_36 ( V_2 , V_149 ,
0x040c0c06 ) ;
F_36 ( V_2 , V_146 ,
0x03000a08 ) ;
F_36 ( V_2 , V_150 ,
0x00000000 ) ;
F_36 ( V_2 , V_151 ,
0x200005c0 ) ;
F_36 ( V_2 , V_152 ,
0x88888815 ) ;
}
V_104 = V_42 ;
break;
default:
F_13 ( V_22 , L_9 ,
V_22 -> V_27 . V_28 ) ;
break;
}
V_104 |= F_3 ( V_2 , V_41 ) ;
F_2 ( V_2 , V_41 , V_104 ) ;
}
