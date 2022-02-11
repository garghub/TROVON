static void
F_1 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 , T_3 V_5 )
{
T_4 V_6 ;
T_3 V_7 ;
if ( V_3 == 0 )
return;
V_6 = ( V_5 == V_8 ) ;
V_7 = F_2 ( V_1 , V_2 ) & 0x07 ;
F_3 ( V_4 , V_1 , V_2 , 1 , L_1 ,
( V_6 ? L_2 : L_3 ) ,
V_7 ,
F_4 ( V_7 , V_9 , L_4 ) ) ;
}
static void
F_5 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_10 ;
T_3 V_11 ;
T_5 V_12 ;
T_5 V_13 , V_14 ;
if ( V_3 == 0 )
return;
V_10 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_15 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_10 == 0x40 ) {
if ( V_3 > 4 )
V_3 = 4 ;
F_6 ( V_4 , V_17 , V_1 , V_2 , V_3 , V_16 ) ;
return;
}
while ( V_3 >= 0 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
switch ( V_11 ) {
case 0x85 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_18 , V_1 , V_2 , 2 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x86 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_19 , V_1 , V_2 , 2 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x87 :
if ( V_3 < 3 )
return;
V_12 = F_8 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_20 , V_1 , V_2 , 3 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x88 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_21 , V_1 , V_2 , 2 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x89 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_22 , V_1 , V_2 , 2 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x8A :
if ( V_3 < 3 )
return;
V_12 = F_8 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_23 , V_1 , V_2 , 3 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x8B :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_9 ( V_4 , V_24 , V_1 , V_2 , 2 ,
V_12 , L_5 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x8C :
if ( V_3 < 3 )
return;
V_12 = F_8 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_25 , V_1 , V_2 , 3 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x81 :
if ( V_3 < 3 )
return;
V_12 = F_8 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_26 , V_1 , V_2 , 3 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x82 :
if ( V_3 < 5 )
return;
V_13 = F_8 ( V_1 , V_2 + 1 ) ;
V_14 = F_8 ( V_1 , V_2 + 3 ) ;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_6 , V_13 , V_14 ) ;
V_2 += 5 ;
V_3 -= 5 ;
break;
case 0x83 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_27 , V_1 , V_2 , 2 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x84 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_7 ( V_4 , V_28 , V_1 , V_2 , 2 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_7 ,
V_11 ) ;
return;
}
}
}
static void
F_10 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_11 ;
T_5 V_12 ;
while ( V_3 >= 0 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
switch ( V_11 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
if ( V_3 < 4 )
return;
V_12 = F_11 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 4 ,
L_8 ,
F_4 ( V_11 , V_41 ,
L_4 ) ,
V_12 , F_12 ( V_12 , L_9 , L_10 ) ) ;
V_2 += 4 ;
V_3 -= 4 ;
break;
case V_42 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_11 ,
F_4 ( V_11 , V_41 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
break;
case V_43 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_11 ,
F_4 ( V_11 , V_41 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_12 ,
( V_12 & 0x80 ) ? L_13 : L_14 ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_15 ,
( V_12 & 0x40 ) ? L_13 : L_14 ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_16 ,
( V_12 & 0x02 ) ? L_9 : L_17 ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_18 ,
( V_12 & 0x01 ) ? L_9 : L_17 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_19 ,
V_11 ) ;
return;
}
}
}
static void
F_13 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_44 ;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_45 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
if ( ! ( V_44 & V_46 ) ) {
F_6 ( V_4 , V_47 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_48 , V_1 , V_2 , 1 , V_16 ) ;
F_6 ( V_4 , V_49 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_14 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_50 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_15 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_44 ;
T_3 V_51 ;
T_3 V_52 ;
T_3 V_53 ;
T_5 V_54 ;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
if ( ( V_44 & 0x60 ) == 0x20 ) {
F_6 ( V_4 , V_55 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
if ( ( V_44 & 0x60 ) == 0x40 ) {
V_51 = V_44 & 0x1F ;
F_6 ( V_4 , V_56 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_44 & V_46 )
goto V_57;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
if ( V_51 == V_58 ) {
F_6 ( V_4 , V_59 , V_1 , V_2 , 1 , V_16 ) ;
} else {
F_6 ( V_4 , V_60 , V_1 , V_2 , 1 , V_16 ) ;
}
V_2 += 1 ;
V_3 -= 1 ;
if ( V_44 & V_46 )
goto V_57;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
F_9 ( V_4 , V_61 , V_1 , V_2 , 1 ,
V_44 & 0x7F , L_20 , V_44 & 0x7F ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
V_57:
;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
if ( ( V_44 & 0x60 ) == 0x60 ) {
V_52 = V_44 & 0x1F ;
F_6 ( V_4 , V_62 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_44 & V_46 )
goto V_63;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
switch ( V_52 ) {
case V_64 :
case V_65 :
case V_66 :
F_6 ( V_4 , V_60 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_44 & V_46 )
goto V_63;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_67 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_44 & V_46 )
goto V_63;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_68 , V_1 , V_2 , 1 , V_16 ) ;
break;
case V_69 :
F_9 ( V_4 , V_67 , V_1 , V_2 , 1 ,
1 << ( V_44 & 0x0F ) , L_5 , 1 << ( V_44 & 0x0F ) ) ;
break;
case V_70 :
V_53 = ( V_44 & 0x7F ) << 1 ;
if ( V_44 & V_46 )
goto V_63;
if ( V_3 < 2 )
return;
V_53 |= ( F_2 ( V_1 , V_2 + 1 ) & 0x40 ) >> 6 ;
F_7 ( V_4 , V_71 , V_1 , V_2 , 2 , V_53 ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_53 == V_72 ) {
if ( V_3 < 6 )
return;
V_2 += 1 ;
V_54 = F_11 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_73 , V_1 , V_2 , 3 , V_74 ) ;
V_2 += 3 ;
switch ( V_54 ) {
case V_75 :
F_6 ( V_4 , V_76 , V_1 , V_2 , 2 , V_74 ) ;
break;
case V_77 :
F_6 ( V_4 , V_78 , V_1 , V_2 , 2 , V_74 ) ;
break;
default:
F_6 ( V_4 , V_79 , V_1 , V_2 , 2 , V_74 ) ;
break;
}
}
break;
}
}
V_63:
;
}
static void
F_16 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_44 ;
T_3 V_80 ;
T_3 V_81 ;
T_3 V_5 ;
T_3 V_82 ;
T_6 V_83 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_84 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
V_80 = V_44 & 0x7F ;
F_6 ( V_4 , V_85 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_80 ) {
case V_86 :
case V_87 :
case V_88 :
V_44 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_21 ,
( V_44 & 0x80 ) ? L_22 : L_23 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_11 ,
( V_44 & 0x40 ) ? L_24 : L_25 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_26 ,
F_4 ( V_44 & 0x03 , V_89 ,
L_27 ) ) ;
break;
case V_90 :
V_81 = V_44 & 0x7C ;
F_6 ( V_4 , V_91 , V_1 , V_2 , 1 , V_16 ) ;
F_6 ( V_4 , V_92 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_81 ) {
case V_93 :
F_6 ( V_4 , V_94 , V_1 , V_2 , V_3 , V_16 ) ;
break;
case V_95 :
F_6 ( V_4 , V_96 , V_1 , V_2 , 1 , V_16 ) ;
break;
case V_97 :
F_6 ( V_4 , V_98 , V_1 , V_2 , 1 , V_16 ) ;
break;
default:
F_6 ( V_4 , V_99 , V_1 , V_2 , V_3 , V_16 ) ;
break;
}
break;
case V_100 :
V_5 = F_2 ( V_1 , V_2 ) ;
V_82 = F_2 ( V_1 , V_2 + 1 ) ;
V_83 = F_8 ( V_1 , V_2 + 2 ) ;
F_17 ( V_1 , V_2 , V_83 , V_4 ,
V_5 , V_82 ) ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
do {
F_6 ( V_4 , V_106 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( V_3 >= 0 );
break;
case V_107 :
do {
F_6 ( V_4 , V_108 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( V_3 >= 0 );
break;
case V_109 :
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_110 , V_1 , V_2 , 2 , V_74 ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_111 , V_1 , V_2 , 2 , V_74 ) ;
break;
case V_112 :
case V_113 :
F_6 ( V_4 , V_114 , V_1 , V_2 , 1 , V_16 ) ;
break;
case V_115 :
if ( V_3 < 3 )
return;
F_6 ( V_4 , V_116 , V_1 , V_2 , 3 , V_117 | V_16 ) ;
break;
default:
F_6 ( V_4 , V_99 , V_1 , V_2 , V_3 , V_16 ) ;
}
}
static void
F_18 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_118 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_19 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_44 ;
T_3 V_119 ;
T_2 * V_120 ;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_121 , V_1 , V_2 , 1 , V_16 ) ;
V_119 = V_44 & 0x0F ;
F_6 ( V_4 , V_122 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ! ( V_44 & V_46 ) ) {
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_123 , V_1 , V_2 , 1 , V_16 ) ;
F_6 ( V_4 , V_124 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
switch ( V_119 ) {
case V_125 :
F_6 ( V_4 , V_126 , V_1 , V_2 , V_3 , V_117 | V_16 ) ;
break;
case V_127 :
if ( V_3 < 20 ) {
F_3 ( V_4 , V_1 , V_2 , V_3 ,
L_28 ,
F_20 ( V_1 , V_2 , V_3 ) ) ;
return;
}
V_120 = F_21 ( V_4 , V_1 , V_2 , V_3 , V_128 , NULL , L_29 ) ;
F_22 ( V_1 , V_2 , V_3 , V_120 ) ;
break;
default:
F_6 ( V_4 , V_129 , V_1 , V_2 , V_3 , V_16 ) ;
break;
}
}
static void
F_23 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_130 , V_1 , V_2 , 1 , V_16 ) ;
F_6 ( V_4 , V_131 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_132 , V_1 , V_2 , V_3 , V_16 ) ;
}
static void
F_24 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_133 , V_1 , V_2 , 1 , V_16 ) ;
F_6 ( V_4 , V_134 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_135 , V_1 , V_2 , 2 , V_74 ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_136 , V_1 , V_2 , 2 , V_74 ) ;
}
static void
F_25 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_11 ;
T_6 V_12 ;
while ( V_3 >= 3 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
V_12 = F_8 ( V_1 , V_2 + 1 ) ;
V_3 -= 3 ;
switch ( V_11 ) {
case 0x01 :
F_9 ( V_4 , V_137 , V_1 , V_2 , 3 ,
V_12 , L_30 , V_12 ) ;
break;
case 0x03 :
if ( V_12 == 0xFFFF ) {
F_9 ( V_4 , V_138 , V_1 , V_2 , 3 ,
V_12 , L_31 ) ;
} else {
F_9 ( V_4 , V_138 , V_1 , V_2 , 3 ,
V_12 , L_30 , V_12 ) ;
}
break;
default:
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_32 ,
V_11 ) ;
return;
}
}
}
static void
F_26 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_139 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_140 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_27 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_141 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_28 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_142 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_29 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_11 ;
while ( V_3 >= 0 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
switch ( V_11 ) {
case 0xA1 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_33 ) ;
V_2 += 1 ;
V_3 -= 1 ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_34 ,
V_11 ) ;
return;
}
}
}
static void
F_30 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_143 , V_1 , V_2 , 1 , V_16 ) ;
F_6 ( V_4 , V_144 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_145 , V_1 , V_2 , V_3 , V_16 | V_117 ) ;
}
static void
F_31 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_44 ;
if ( V_3 == 0 )
return;
V_44 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_146 , V_1 , V_2 , 1 , V_16 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_35 ,
( V_44 & 0x10 ) ? L_36 : L_37 ) ;
F_6 ( V_4 , V_147 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_148 , V_1 , V_2 , 1 , V_16 ) ;
F_6 ( V_4 , V_149 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_32 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_6 V_12 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_150 , V_1 , V_2 , 1 , V_16 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 < 2 )
return;
V_12 = F_8 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_38 ,
( V_12 & 0x8000 ) ? L_39 :
L_40 ) ;
F_6 ( V_4 , V_151 , V_1 , V_2 , 2 , V_74 ) ;
}
static void
F_33 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_152 , V_1 , V_2 , 1 , V_16 ) ;
}
static void
F_34 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 , T_3 V_5 )
{
switch ( V_5 ) {
case V_153 :
case V_8 :
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_154 :
case V_155 :
F_35 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_156 :
F_36 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_157 :
F_37 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_158 :
F_5 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_159 :
F_10 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_160 :
F_13 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_161 :
F_14 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_162 :
F_15 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_163 :
F_18 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_164 :
case V_165 :
F_19 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_166 :
case V_167 :
F_23 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_168 :
F_16 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_169 :
F_24 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_170 :
F_25 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_171 :
F_26 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_172 :
F_27 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_173 :
F_28 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_174 :
F_29 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_175 :
F_30 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_176 :
F_31 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_177 :
F_32 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_178 :
F_33 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
}
}
static void
F_17 ( T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 ,
T_3 V_5 , T_3 V_82 )
{
T_7 * V_179 ;
T_2 * V_180 ;
T_2 * V_181 ;
V_180 = F_21 ( V_4 , V_1 , V_2 , 1 + 1 + 2 + V_3 , V_182 , NULL ,
F_38 ( V_5 , & V_183 ,
L_41 ) ) ;
F_7 ( V_180 , V_184 , V_1 , V_2 , 1 , V_5 ) ;
V_179 = F_7 ( V_180 , V_185 , V_1 , V_2 + 1 , 1 , V_82 ) ;
V_181 = F_39 ( V_179 , V_186 ) ;
F_6 ( V_181 , V_187 , V_1 , V_2 + 1 , 1 , V_74 ) ;
F_6 ( V_181 , V_188 , V_1 , V_2 + 1 , 1 , V_74 ) ;
if ( V_82 & V_189 ) {
F_6 ( V_181 , V_190 , V_1 , V_2 + 1 , 1 , V_74 ) ;
}
F_7 ( V_180 , V_191 , V_1 , V_2 + 2 , 2 , V_3 ) ;
if ( ( V_82 & V_192 )
== V_193 ) {
F_34 ( V_1 , V_2 + 4 ,
V_3 , V_180 , V_5 ) ;
} else {
F_6 ( V_180 , V_194 , V_1 , V_2 + 4 , V_3 , V_16 ) ;
}
}
static void
F_40 ( T_1 * V_1 , T_8 * V_195 , T_2 * V_4 )
{
int V_2 = 0 ;
T_2 * V_196 = NULL ;
T_7 * V_179 ;
T_2 * V_197 ;
T_3 V_198 ;
T_3 V_199 [ 15 ] ;
T_3 V_200 ;
T_3 V_201 ;
T_6 V_202 ;
T_3 V_5 ;
T_3 V_82 ;
T_6 V_83 ;
#if 0
int codeset;
gboolean non_locking_shift;
#endif
F_41 ( V_195 -> V_203 , V_204 , L_42 ) ;
if ( V_4 ) {
V_179 = F_6 ( V_4 , V_205 , V_1 , V_2 , - 1 ,
V_16 ) ;
V_196 = F_39 ( V_179 , V_206 ) ;
F_7 ( V_196 , V_207 , V_1 , V_2 , 1 , F_2 ( V_1 , V_2 ) ) ;
}
V_2 += 1 ;
V_198 = F_2 ( V_1 , V_2 ) & 0xF ;
if ( V_196 != NULL )
F_7 ( V_196 , V_208 , V_1 , V_2 , 1 , V_198 ) ;
V_2 += 1 ;
if ( V_198 != 0 ) {
F_42 ( V_1 , V_199 , V_2 , V_198 ) ;
if ( V_196 != NULL ) {
F_43 ( V_196 , V_209 ,
V_1 , V_2 , 1 , ( V_199 [ 0 ] & 0x80 ) != 0 ) ;
V_199 [ 0 ] &= 0x7F ;
F_44 ( V_196 , V_210 , V_1 , V_2 , V_198 , V_199 ) ;
}
V_2 += V_198 ;
}
V_200 = F_2 ( V_1 , V_2 ) ;
F_45 ( V_195 -> V_203 , V_211 ,
F_38 ( V_200 , & V_212 ,
L_43 ) ) ;
if ( V_196 != NULL )
F_7 ( V_196 , V_213 , V_1 , V_2 , 1 , V_200 ) ;
V_2 += 1 ;
V_201 = F_2 ( V_1 , V_2 ) ;
if ( V_196 != NULL ) {
V_179 = F_7 ( V_196 , V_214 , V_1 ,
V_2 , 1 , V_201 ) ;
V_197 = F_39 ( V_179 , V_215 ) ;
F_43 ( V_197 , V_216 , V_1 ,
V_2 , 1 , V_201 ) ;
if ( V_201 & V_217 ) {
F_7 ( V_197 , V_218 , V_1 ,
V_2 , 1 , V_201 ) ;
}
}
V_2 += 1 ;
V_202 = F_8 ( V_1 , V_2 ) ;
if ( V_196 != NULL )
F_7 ( V_196 , V_219 , V_1 , V_2 , 2 , V_202 ) ;
V_2 += 2 ;
#if 0
codeset = 0;
non_locking_shift = TRUE;
#endif
while ( F_46 ( V_1 , V_2 ) > 0 ) {
V_5 = F_2 ( V_1 , V_2 ) ;
V_82 = F_2 ( V_1 , V_2 + 1 ) ;
V_83 = F_8 ( V_1 , V_2 + 2 ) ;
if ( V_196 != NULL ) {
F_17 ( V_1 , V_2 , V_83 ,
V_196 , V_5 , V_82 ) ;
}
#if 0
if (non_locking_shift)
codeset = 0;
switch (info_element) {
case Q2931_IE_BBAND_LOCKING_SHIFT:
if (info_element_len >= 1) {
non_locking_shift = FALSE;
codeset = tvb_get_guint8(tvb, offset + 4) & 0x07;
}
break;
case Q2931_IE_BBAND_NLOCKING_SHIFT:
if (info_element_len >= 1) {
non_locking_shift = TRUE;
codeset = tvb_get_guint8(tvb, offset + 4) & 0x07;
}
break;
}
#endif
V_2 += 1 + 1 + 2 + V_83 ;
}
}
void
F_47 ( void )
{
static T_9 V_220 [] = {
{ & V_207 ,
{ L_44 , L_45 ,
V_221 , V_222 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_208 ,
{ L_46 , L_47 ,
V_221 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_209 ,
{ L_48 , L_49 ,
V_225 , V_226 , F_48 ( & V_227 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_210 ,
{ L_50 , L_51 ,
V_228 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_213 ,
{ L_52 , L_53 ,
V_221 , V_222 | V_229 , & V_212 , 0x0 ,
NULL , V_223 }
} ,
{ & V_214 ,
{ L_54 , L_55 ,
V_221 , V_222 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_216 ,
{ L_56 , L_57 ,
V_225 , 8 , F_48 ( & V_230 ) , V_217 ,
NULL , V_223 }
} ,
{ & V_218 ,
{ L_58 , L_59 ,
V_221 , V_224 , F_49 ( V_231 ) , V_232 ,
NULL , V_223 }
} ,
{ & V_219 ,
{ L_60 , L_61 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_188 ,
{ L_62 , L_63 ,
V_225 , 8 , F_48 ( & V_234 ) , V_189 ,
NULL , V_223 }
} ,
{ & V_187 ,
{ L_64 , L_65 ,
V_221 , V_224 , F_49 ( V_235 ) , V_192 ,
NULL , V_223 }
} ,
{ & V_190 ,
{ L_58 , L_66 ,
V_221 , V_224 , F_49 ( V_236 ) , V_237 ,
NULL , V_223 }
} ,
{ & V_15 ,
{ L_67 , L_68 ,
V_221 , V_222 , F_49 ( V_238 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_17 ,
{ L_69 , L_70 ,
V_228 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_18 ,
{ L_71 , L_72 ,
V_221 , V_222 , F_49 ( V_239 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_19 ,
{ L_73 , L_74 ,
V_221 , V_222 , F_49 ( V_240 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_20 ,
{ L_75 , L_76 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_21 ,
{ L_77 , L_78 ,
V_221 , V_222 , F_49 ( V_241 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_22 ,
{ L_79 , L_80 ,
V_221 , V_222 , F_49 ( V_242 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_23 ,
{ L_81 , L_82 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_24 ,
{ L_83 , L_84 ,
V_221 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_25 ,
{ L_85 , L_86 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_26 ,
{ L_87 , L_88 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_27 ,
{ L_89 , L_90 ,
V_221 , V_222 , F_49 ( V_243 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_28 ,
{ L_91 , L_92 ,
V_221 , V_222 , F_49 ( V_244 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_45 ,
{ L_93 , L_94 ,
V_221 , V_222 , F_49 ( V_245 ) , 0x1F ,
NULL , V_223 }
} ,
{ & V_47 ,
{ L_95 , L_96 ,
V_221 , V_222 , F_49 ( V_246 ) , 0x1F ,
NULL , V_223 }
} ,
{ & V_48 ,
{ L_97 , L_98 ,
V_221 , V_222 , F_49 ( V_247 ) , 0x60 ,
NULL , V_223 }
} ,
{ & V_49 ,
{ L_99 , L_100 ,
V_221 , V_222 , F_49 ( V_248 ) , 0x03 ,
NULL , V_223 }
} ,
{ & V_50 ,
{ L_101 , L_102 ,
V_221 , V_222 , F_49 ( V_249 ) , 0x7F ,
NULL , V_223 }
} ,
{ & V_55 ,
{ L_103 , L_104 ,
V_221 , V_222 , NULL , 0x1F ,
NULL , V_223 }
} ,
{ & V_56 ,
{ L_105 , L_106 ,
V_221 , V_222 , F_49 ( V_250 ) , 0x1F ,
NULL , V_223 }
} ,
{ & V_59 ,
{ L_107 , L_108 ,
V_221 , V_222 , NULL , 0x7F ,
NULL , V_223 }
} ,
{ & V_60 ,
{ L_89 , L_109 ,
V_221 , V_222 , F_49 ( V_251 ) , 0x60 ,
NULL , V_223 }
} ,
{ & V_61 ,
{ L_110 , L_111 ,
V_221 , V_224 , NULL , 0x7F ,
NULL , V_223 }
} ,
{ & V_62 ,
{ L_112 , L_113 ,
V_221 , V_222 , F_49 ( V_252 ) , 0x1F ,
NULL , V_223 }
} ,
{ & V_67 ,
{ L_114 , L_115 ,
V_221 , V_224 , NULL , 0x0F ,
NULL , V_223 }
} ,
{ & V_68 ,
{ L_116 , L_117 ,
V_221 , V_224 , NULL , 0x7F ,
NULL , V_223 }
} ,
{ & V_71 ,
{ L_118 , L_119 ,
V_221 , V_222 , F_49 ( V_253 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_73 ,
{ L_120 , L_121 ,
V_254 , V_222 , F_49 ( V_255 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_76 ,
{ L_122 , L_123 ,
V_233 , V_222 , F_49 ( V_256 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_78 ,
{ L_124 , L_125 ,
V_233 , V_222 , F_49 ( V_257 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_79 ,
{ L_126 , L_127 ,
V_233 , V_222 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_84 ,
{ L_128 , L_129 ,
V_221 , V_222 , F_49 ( V_258 ) , 0x0F ,
NULL , V_223 }
} ,
{ & V_85 ,
{ L_130 , L_131 ,
V_221 , V_222 | V_229 , & V_259 , 0x7F ,
NULL , V_223 }
} ,
{ & V_91 ,
{ L_132 , L_133 ,
V_221 , V_222 , F_49 ( V_260 ) , 0x7C ,
NULL , V_223 }
} ,
{ & V_92 ,
{ L_134 , L_135 ,
V_221 , V_222 , F_49 ( V_89 ) , 0x03 ,
NULL , V_223 }
} ,
{ & V_94 ,
{ L_136 , L_137 ,
V_228 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_96 ,
{ L_138 , L_139 ,
V_221 , V_222 | V_229 , & V_183 , 0x0 ,
NULL , V_223 }
} ,
{ & V_98 ,
{ L_140 , L_141 ,
V_221 , V_222 | V_229 , & V_183 , 0x0 ,
NULL , V_223 }
} ,
{ & V_99 ,
{ L_142 , L_143 ,
V_228 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_106 ,
{ L_144 , L_145 ,
V_221 , V_222 | V_229 , & V_183 , 0x0 ,
NULL , V_223 }
} ,
{ & V_108 ,
{ L_146 , L_147 ,
V_221 , V_222 , F_49 ( V_41 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_110 ,
{ L_148 , L_149 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_111 ,
{ L_150 , L_151 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_114 ,
{ L_52 , L_152 ,
V_221 , V_222 | V_229 , & V_212 , 0x0 ,
NULL , V_223 }
} ,
{ & V_116 ,
{ L_153 , L_154 ,
V_261 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_118 ,
{ L_155 , L_156 ,
V_221 , V_222 , F_49 ( V_262 ) , 0x3F ,
NULL , V_223 }
} ,
{ & V_121 ,
{ L_157 , L_158 ,
V_221 , V_222 , F_49 ( V_263 ) , 0x70 ,
NULL , V_223 }
} ,
{ & V_122 ,
{ L_159 , L_160 ,
V_221 , V_222 , F_49 ( V_264 ) , 0x0F ,
NULL , V_223 }
} ,
{ & V_123 ,
{ L_161 , L_162 ,
V_221 , V_222 , F_49 ( V_265 ) , 0x60 ,
NULL , V_223 }
} ,
{ & V_124 ,
{ L_163 , L_164 ,
V_221 , V_222 , F_49 ( V_266 ) , 0x03 ,
NULL , V_223 }
} ,
{ & V_126 ,
{ L_29 , L_165 ,
V_261 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_129 ,
{ L_29 , L_166 ,
V_228 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_130 ,
{ L_167 , L_168 ,
V_221 , V_222 , F_49 ( V_267 ) , 0x70 ,
NULL , V_223 }
} ,
{ & V_131 ,
{ L_169 , L_170 ,
V_221 , V_222 , F_49 ( V_268 ) , 0x10 ,
NULL , V_223 }
} ,
{ & V_132 ,
{ L_171 , L_172 ,
V_228 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_133 ,
{ L_173 , L_174 ,
V_221 , V_222 , F_49 ( V_269 ) , 0x18 ,
NULL , V_223 }
} ,
{ & V_134 ,
{ L_175 , L_176 ,
V_221 , V_222 , F_49 ( V_270 ) , 0x07 ,
NULL , V_223 }
} ,
{ & V_135 ,
{ L_148 , L_177 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_136 ,
{ L_150 , L_178 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_137 ,
{ L_179 , L_180 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_138 ,
{ L_181 , L_182 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_139 ,
{ L_183 , L_184 ,
V_221 , V_222 , F_49 ( V_271 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_140 ,
{ L_185 , L_186 ,
V_221 , V_222 , F_49 ( V_271 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_141 ,
{ L_187 , L_188 ,
V_221 , V_222 , F_49 ( V_272 ) , 0x0F ,
NULL , V_223 }
} ,
{ & V_142 ,
{ L_189 , L_190 ,
V_221 , V_222 , F_49 ( V_273 ) , 0x07 ,
NULL , V_223 }
} ,
{ & V_143 ,
{ L_191 , L_192 ,
V_221 , V_222 , F_49 ( V_274 ) , 0x70 ,
NULL , V_223 }
} ,
{ & V_144 ,
{ L_193 , L_194 ,
V_221 , V_222 , F_49 ( V_275 ) , 0x0F ,
NULL , V_223 }
} ,
{ & V_145 ,
{ L_195 , L_196 ,
V_261 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_146 ,
{ L_197 , L_198 ,
V_221 , V_222 , F_49 ( V_276 ) , 0x60 ,
NULL , V_223 }
} ,
{ & V_147 ,
{ L_199 , L_200 ,
V_221 , V_222 , F_49 ( V_277 ) , 0x07 ,
NULL , V_223 }
} ,
{ & V_148 ,
{ L_201 , L_202 ,
V_221 , V_222 , F_49 ( V_278 ) , 0x70 ,
NULL , V_223 }
} ,
{ & V_149 ,
{ L_203 , L_204 ,
V_221 , V_222 , F_49 ( V_279 ) , 0x07 ,
NULL , V_223 }
} ,
{ & V_150 ,
{ L_205 , L_206 ,
V_221 , V_222 , F_49 ( V_280 ) , 0x0 ,
NULL , V_223 }
} ,
{ & V_151 ,
{ L_207 , L_208 ,
V_233 , V_224 , NULL , 0x7FFF ,
NULL , V_223 }
} ,
{ & V_152 ,
{ L_209 , L_210 ,
V_221 , V_222 , F_49 ( V_281 ) , 0x3F ,
NULL , V_223 }
} ,
{ & V_184 ,
{ L_144 , L_211 ,
V_221 , V_222 | V_229 , & V_183 , 0x0 ,
NULL , V_223 }
} ,
{ & V_185 ,
{ L_212 , L_213 ,
V_221 , V_222 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_191 ,
{ L_214 , L_215 ,
V_233 , V_224 , NULL , 0x0 ,
NULL , V_223 }
} ,
{ & V_194 ,
{ L_216 , L_217 ,
V_228 , V_226 , NULL , 0x0 ,
NULL , V_223 }
} ,
} ;
static T_10 * V_282 [] = {
& V_206 ,
& V_215 ,
& V_182 ,
& V_186 ,
& V_128 ,
} ;
V_205 = F_50 ( L_42 , L_42 , L_218 ) ;
F_51 ( V_205 , V_220 , F_52 ( V_220 ) ) ;
F_53 ( V_282 , F_52 ( V_282 ) ) ;
F_54 ( L_218 , F_40 , V_205 ) ;
}
