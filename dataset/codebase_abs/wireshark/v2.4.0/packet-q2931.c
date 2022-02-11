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
F_3 ( V_4 , V_9 , V_1 , V_2 , 1 , V_7 ,
L_1 ,
( V_6 ? L_2 : L_3 ) ,
V_7 , F_4 ( V_7 , V_10 , L_4 ) ) ;
}
static void
F_5 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_12 ;
T_3 V_13 ;
T_6 V_14 ;
T_6 V_15 , V_16 ;
T_7 * V_17 ;
if ( V_3 == 0 )
return;
V_12 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_18 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_12 == 0x40 ) {
if ( V_3 > 4 )
V_3 = 4 ;
F_6 ( V_4 , V_20 , V_1 , V_2 , V_3 , V_21 ) ;
return;
}
while ( V_3 >= 0 ) {
V_13 = F_2 ( V_1 , V_2 ) ;
V_17 = F_6 ( V_4 , V_22 , V_1 , V_2 , 1 , V_21 ) ;
V_2 ++ ;
V_3 -- ;
switch ( V_13 ) {
case 0x85 :
if ( V_3 < 1 )
return;
F_6 ( V_4 , V_23 , V_1 , V_2 , 1 , V_21 ) ;
V_2 ++ ;
V_3 -- ;
break;
case 0x86 :
if ( V_3 < 1 )
return;
F_6 ( V_4 , V_24 , V_1 , V_2 , 1 , V_21 ) ;
V_2 ++ ;
V_3 -- ;
break;
case 0x87 :
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_25 , V_1 , V_2 , 2 , V_19 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x88 :
if ( V_3 < 1 )
return;
F_6 ( V_4 , V_26 , V_1 , V_2 , 1 , V_21 ) ;
V_2 ++ ;
V_3 -- ;
break;
case 0x89 :
if ( V_3 < 1 )
return;
F_6 ( V_4 , V_27 , V_1 , V_2 , 1 , V_21 ) ;
V_2 ++ ;
V_3 -- ;
break;
case 0x8A :
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_28 , V_1 , V_2 , 2 , V_19 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x8B :
if ( V_3 < 1 )
return;
V_14 = F_2 ( V_1 , V_2 ) ;
F_7 ( V_4 , V_29 , V_1 , V_2 , 1 ,
V_14 , L_5 , V_14 ) ;
V_2 ++ ;
V_3 -- ;
break;
case 0x8C :
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_30 , V_1 , V_2 , 2 , V_19 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x81 :
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_31 , V_1 , V_2 , 2 , V_19 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x82 :
if ( V_3 < 4 )
return;
V_15 = F_8 ( V_1 , V_2 ) ;
V_16 = F_8 ( V_1 , V_2 + 2 ) ;
F_7 ( V_4 , V_32 , V_1 , V_2 , 4 , F_9 ( V_1 , V_2 ) ,
L_6 , V_15 , V_16 ) ;
V_2 += 4 ;
V_3 -= 4 ;
break;
case 0x83 :
if ( V_3 < 1 )
return;
F_6 ( V_4 , V_33 , V_1 , V_2 , 1 , V_21 ) ;
V_2 ++ ;
V_3 -- ;
break;
case 0x84 :
if ( V_3 < 1 )
return;
F_6 ( V_4 , V_34 , V_1 , V_2 , 1 , V_21 ) ;
V_2 ++ ;
V_3 -- ;
break;
default:
F_10 ( V_11 , V_17 , & V_35 ) ;
return;
}
}
}
static void
F_11 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_13 ;
T_6 V_14 ;
T_7 * V_17 ;
while ( V_3 >= 0 ) {
V_13 = F_2 ( V_1 , V_2 ) ;
V_17 = F_6 ( V_4 , V_36 , V_1 , V_2 , 1 , V_21 ) ;
switch ( V_13 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
if ( V_3 < 4 )
return;
V_14 = F_12 ( V_1 , V_2 + 1 ) ;
F_13 ( V_4 , V_49 , V_1 , V_2 + 3 , 3 , V_14 ) ;
V_2 += 4 ;
V_3 -= 4 ;
break;
case V_50 :
V_2 += 1 ;
V_3 -= 1 ;
break;
case V_51 :
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_52 , V_1 , V_2 + 1 , 1 , V_21 ) ;
F_6 ( V_4 , V_53 , V_1 , V_2 + 1 , 1 , V_21 ) ;
F_6 ( V_4 , V_54 , V_1 , V_2 + 1 , 1 , V_21 ) ;
F_6 ( V_4 , V_55 , V_1 , V_2 + 1 , 1 , V_21 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
default:
F_10 ( V_11 , V_17 , & V_56 ) ;
return;
}
}
}
static void
F_14 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_57 ;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_58 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
if ( ! ( V_57 & V_59 ) ) {
F_6 ( V_4 , V_60 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_61 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_62 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_15 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_63 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_16 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_57 ;
T_3 V_64 ;
T_3 V_65 ;
T_3 V_66 ;
T_6 V_67 ;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
if ( ( V_57 & 0x60 ) == 0x20 ) {
F_6 ( V_4 , V_68 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
if ( ( V_57 & 0x60 ) == 0x40 ) {
V_64 = V_57 & 0x1F ;
F_6 ( V_4 , V_69 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_57 & V_59 )
goto V_70;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
if ( V_64 == V_71 ) {
F_6 ( V_4 , V_72 , V_1 , V_2 , 1 , V_19 ) ;
} else {
F_6 ( V_4 , V_73 , V_1 , V_2 , 1 , V_19 ) ;
}
V_2 += 1 ;
V_3 -= 1 ;
if ( V_57 & V_59 )
goto V_70;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
F_7 ( V_4 , V_74 , V_1 , V_2 , 1 ,
V_57 & 0x7F , L_7 , V_57 & 0x7F ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
V_70:
;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
if ( ( V_57 & 0x60 ) == 0x60 ) {
V_65 = V_57 & 0x1F ;
F_6 ( V_4 , V_75 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_57 & V_59 )
goto V_76;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
switch ( V_65 ) {
case V_77 :
case V_78 :
case V_79 :
F_6 ( V_4 , V_73 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_57 & V_59 )
goto V_76;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_80 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_57 & V_59 )
goto V_76;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_81 , V_1 , V_2 , 1 , V_19 ) ;
break;
case V_82 :
F_13 ( V_4 , V_80 , V_1 , V_2 , 1 , 1 << ( V_57 & 0x0F ) ) ;
break;
case V_83 :
V_66 = ( V_57 & 0x7F ) << 1 ;
if ( V_57 & V_59 )
goto V_76;
if ( V_3 < 2 )
return;
V_66 |= ( F_2 ( V_1 , V_2 + 1 ) & 0x40 ) >> 6 ;
F_13 ( V_4 , V_84 , V_1 , V_2 , 2 , V_66 ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_66 == V_85 ) {
if ( V_3 < 6 )
return;
V_2 += 1 ;
V_67 = F_12 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_86 , V_1 , V_2 , 3 , V_19 ) ;
V_2 += 3 ;
switch ( V_67 ) {
case V_87 :
F_6 ( V_4 , V_88 , V_1 , V_2 , 2 , V_19 ) ;
break;
case V_89 :
F_6 ( V_4 , V_90 , V_1 , V_2 , 2 , V_19 ) ;
break;
default:
F_6 ( V_4 , V_91 , V_1 , V_2 , 2 , V_19 ) ;
break;
}
}
break;
}
}
V_76:
;
}
static void
F_17 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_57 ;
T_3 V_92 ;
T_3 V_93 ;
T_3 V_5 ;
T_3 V_94 ;
T_8 V_95 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_96 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
V_92 = V_57 & 0x7F ;
F_6 ( V_4 , V_97 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_92 ) {
case V_98 :
case V_99 :
case V_100 :
F_6 ( V_4 , V_101 , V_1 , V_2 , 1 , V_21 ) ;
F_6 ( V_4 , V_102 , V_1 , V_2 , 1 , V_21 ) ;
F_6 ( V_4 , V_103 , V_1 , V_2 , 1 , V_21 ) ;
break;
case V_104 :
V_93 = V_57 & 0x7C ;
F_6 ( V_4 , V_105 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_103 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_93 ) {
case V_106 :
F_6 ( V_4 , V_107 , V_1 , V_2 , V_3 , V_21 ) ;
break;
case V_108 :
F_6 ( V_4 , V_109 , V_1 , V_2 , 1 , V_19 ) ;
break;
case V_110 :
F_6 ( V_4 , V_111 , V_1 , V_2 , 1 , V_19 ) ;
break;
default:
F_6 ( V_4 , V_112 , V_1 , V_2 , V_3 , V_21 ) ;
break;
}
break;
case V_113 :
V_5 = F_2 ( V_1 , V_2 ) ;
V_94 = F_2 ( V_1 , V_2 + 1 ) ;
V_95 = F_8 ( V_1 , V_2 + 2 ) ;
F_18 ( V_1 , V_11 , V_2 , V_95 , V_4 ,
V_5 , V_94 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
do {
F_6 ( V_4 , V_119 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( V_3 >= 0 );
break;
case V_120 :
do {
F_6 ( V_4 , V_121 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( V_3 >= 0 );
break;
case V_122 :
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_123 , V_1 , V_2 , 2 , V_19 ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_124 , V_1 , V_2 , 2 , V_19 ) ;
break;
case V_125 :
case V_126 :
F_6 ( V_4 , V_127 , V_1 , V_2 , 1 , V_19 ) ;
break;
case V_128 :
if ( V_3 < 3 )
return;
F_6 ( V_4 , V_129 , V_1 , V_2 , 3 , V_130 | V_21 ) ;
break;
default:
F_6 ( V_4 , V_112 , V_1 , V_2 , V_3 , V_21 ) ;
}
}
static void
F_19 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_131 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_20 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_57 ;
T_3 V_132 ;
T_2 * V_133 ;
if ( V_3 == 0 )
return;
V_57 = F_2 ( V_1 , V_2 ) ;
F_6 ( V_4 , V_134 , V_1 , V_2 , 1 , V_19 ) ;
V_132 = V_57 & 0x0F ;
F_6 ( V_4 , V_135 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ! ( V_57 & V_59 ) ) {
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_136 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_137 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
switch ( V_132 ) {
case V_138 :
F_6 ( V_4 , V_139 , V_1 , V_2 , V_3 , V_130 | V_21 ) ;
break;
case V_140 :
if ( V_3 < 20 ) {
F_6 ( V_4 , V_141 , V_1 , V_2 , V_3 , V_21 ) ;
return;
}
V_133 = F_21 ( V_4 , V_1 , V_2 , V_3 , V_142 , NULL , L_8 ) ;
F_22 ( V_1 , V_11 , V_2 , V_3 , V_133 ) ;
break;
default:
F_6 ( V_4 , V_143 , V_1 , V_2 , V_3 , V_21 ) ;
break;
}
}
static void
F_23 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_144 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_145 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_146 , V_1 , V_2 , V_3 , V_21 ) ;
}
static void
F_24 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_147 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_148 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_149 , V_1 , V_2 , 2 , V_19 ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_150 , V_1 , V_2 , 2 , V_19 ) ;
}
static void
F_25 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 , T_2 * V_4 )
{
T_3 V_13 ;
T_8 V_14 ;
T_7 * V_17 ;
while ( V_3 >= 3 ) {
V_17 = F_6 ( V_4 , V_151 , V_1 , V_2 , 1 , V_19 ) ;
V_13 = F_2 ( V_1 , V_2 ) ;
V_2 ++ ;
V_14 = F_8 ( V_1 , V_2 ) ;
V_3 -= 3 ;
switch ( V_13 ) {
case 0x01 :
F_13 ( V_4 , V_152 , V_1 , V_2 , 2 , V_14 ) ;
break;
case 0x03 :
if ( V_14 == 0xFFFF ) {
F_7 ( V_4 , V_153 , V_1 , V_2 , 2 ,
V_14 , L_9 ) ;
} else {
F_7 ( V_4 , V_153 , V_1 , V_2 , 2 ,
V_14 , L_10 , V_14 ) ;
}
break;
default:
F_10 ( V_11 , V_17 , & V_154 ) ;
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
F_6 ( V_4 , V_155 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_156 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_27 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_157 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_28 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_158 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_29 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_13 ;
T_7 * V_17 ;
while ( V_3 >= 0 ) {
V_17 = F_6 ( V_4 , V_159 , V_1 , V_2 , 1 , V_19 ) ;
V_13 = F_2 ( V_1 , V_2 ) ;
switch ( V_13 ) {
case 0xA1 :
F_6 ( V_4 , V_160 , V_1 , V_2 , 1 , V_21 ) ;
V_2 += 1 ;
V_3 -= 1 ;
break;
default:
F_10 ( V_11 , V_17 , & V_161 ) ;
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
F_6 ( V_4 , V_162 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_163 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_164 , V_1 , V_2 , V_3 , V_21 | V_130 ) ;
}
static void
F_31 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_165 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_166 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_167 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_168 , V_1 , V_2 , 1 , V_19 ) ;
F_6 ( V_4 , V_169 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_32 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_170 , V_1 , V_2 , 1 , V_19 ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 < 2 )
return;
F_6 ( V_4 , V_171 , V_1 , V_2 , 2 , V_19 ) ;
F_6 ( V_4 , V_172 , V_1 , V_2 , 2 , V_19 ) ;
}
static void
F_33 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
if ( V_3 == 0 )
return;
F_6 ( V_4 , V_173 , V_1 , V_2 , 1 , V_19 ) ;
}
static void
F_34 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 ,
T_2 * V_4 , T_3 V_5 )
{
switch ( V_5 ) {
case V_174 :
case V_8 :
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_175 :
case V_176 :
F_35 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_177 :
F_36 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_178 :
F_37 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_179 :
F_5 ( V_1 , V_11 , V_2 , V_3 , V_4 ) ;
break;
case V_180 :
F_11 ( V_1 , V_11 , V_2 , V_3 , V_4 ) ;
break;
case V_181 :
F_14 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_182 :
F_15 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_183 :
F_16 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_184 :
F_19 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_185 :
case V_186 :
F_20 ( V_1 , V_11 , V_2 , V_3 , V_4 ) ;
break;
case V_187 :
case V_188 :
F_23 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_189 :
F_17 ( V_1 , V_11 , V_2 , V_3 , V_4 ) ;
break;
case V_190 :
F_24 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_191 :
F_25 ( V_1 , V_11 , V_2 , V_3 , V_4 ) ;
break;
case V_192 :
F_26 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_193 :
F_27 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_194 :
F_28 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_195 :
F_29 ( V_1 , V_11 , V_2 , V_3 , V_4 ) ;
break;
case V_196 :
F_30 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_197 :
F_31 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_198 :
F_32 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_199 :
F_33 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
}
}
static void
F_18 ( T_1 * V_1 , T_5 * V_11 , int V_2 , int V_3 , T_2 * V_4 ,
T_3 V_5 , T_3 V_94 )
{
T_7 * V_17 ;
T_2 * V_200 ;
T_2 * V_201 ;
V_200 = F_21 ( V_4 , V_1 , V_2 , 1 + 1 + 2 + V_3 , V_202 , NULL ,
F_38 ( V_5 , & V_203 ,
L_11 ) ) ;
F_13 ( V_200 , V_204 , V_1 , V_2 , 1 , V_5 ) ;
V_17 = F_13 ( V_200 , V_205 , V_1 , V_2 + 1 , 1 , V_94 ) ;
V_201 = F_39 ( V_17 , V_206 ) ;
F_6 ( V_201 , V_207 , V_1 , V_2 + 1 , 1 , V_19 ) ;
F_6 ( V_201 , V_208 , V_1 , V_2 + 1 , 1 , V_19 ) ;
if ( V_94 & V_209 ) {
F_6 ( V_201 , V_210 , V_1 , V_2 + 1 , 1 , V_19 ) ;
}
F_13 ( V_200 , V_211 , V_1 , V_2 + 2 , 2 , V_3 ) ;
if ( ( V_94 & V_212 )
== V_213 ) {
F_34 ( V_1 , V_11 , V_2 + 4 ,
V_3 , V_200 , V_5 ) ;
} else {
F_6 ( V_200 , V_214 , V_1 , V_2 + 4 , V_3 , V_21 ) ;
}
}
static int
F_40 ( T_1 * V_1 , T_5 * V_11 , T_2 * V_4 , void * T_9 V_215 )
{
int V_2 = 0 ;
T_2 * V_216 ;
T_7 * V_17 ;
T_6 V_217 ;
T_3 V_218 [ 16 ] ;
T_3 V_219 ;
T_3 V_220 ;
T_8 V_221 ;
T_3 V_5 ;
T_3 V_94 ;
T_8 V_95 ;
#if 0
int codeset;
gboolean non_locking_shift;
#endif
static const int * V_222 [] = {
& V_223 ,
NULL
} ;
static const int * V_224 [] = {
& V_223 ,
& V_225 ,
NULL
} ;
F_41 ( V_11 -> V_226 , V_227 , L_12 ) ;
V_17 = F_6 ( V_4 , V_228 , V_1 , V_2 , - 1 , V_21 ) ;
V_216 = F_39 ( V_17 , V_229 ) ;
F_6 ( V_216 , V_230 , V_1 , V_2 , 1 , V_21 ) ;
V_2 += 1 ;
F_42 ( V_216 , V_231 , V_1 , V_2 , 1 , V_21 , & V_217 ) ;
V_2 += 1 ;
if ( V_217 != 0 ) {
F_43 ( V_1 , V_218 , V_2 , V_217 ) ;
F_44 ( V_216 , V_232 ,
V_1 , V_2 , 1 , ( V_218 [ 0 ] & 0x80 ) != 0 ) ;
V_218 [ 0 ] &= 0x7F ;
F_45 ( V_216 , V_233 , V_1 , V_2 , V_217 , V_218 ) ;
V_2 += V_217 ;
}
V_219 = F_2 ( V_1 , V_2 ) ;
F_46 ( V_11 -> V_226 , V_234 ,
F_38 ( V_219 , & V_235 ,
L_13 ) ) ;
F_13 ( V_216 , V_236 , V_1 , V_2 , 1 , V_219 ) ;
V_2 += 1 ;
V_220 = F_2 ( V_1 , V_2 ) ;
if ( V_220 & V_237 ) {
F_47 ( V_216 , V_1 , V_2 , V_238 , V_239 , V_224 , V_21 ) ;
} else {
F_47 ( V_216 , V_1 , V_2 , V_238 , V_239 , V_222 , V_21 ) ;
}
V_2 += 1 ;
V_221 = F_8 ( V_1 , V_2 ) ;
if ( V_216 != NULL )
F_13 ( V_216 , V_240 , V_1 , V_2 , 2 , V_221 ) ;
V_2 += 2 ;
#if 0
codeset = 0;
non_locking_shift = TRUE;
#endif
while ( F_48 ( V_1 , V_2 ) > 0 ) {
V_5 = F_2 ( V_1 , V_2 ) ;
V_94 = F_2 ( V_1 , V_2 + 1 ) ;
V_95 = F_8 ( V_1 , V_2 + 2 ) ;
if ( V_216 != NULL ) {
F_18 ( V_1 , V_11 , V_2 , V_95 ,
V_216 , V_5 , V_94 ) ;
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
V_2 += 1 + 1 + 2 + V_95 ;
}
return F_49 ( V_1 ) ;
}
void
F_50 ( void )
{
static T_10 V_241 [] = {
{ & V_230 ,
{ L_14 , L_15 ,
V_242 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_231 ,
{ L_16 , L_17 ,
V_242 , V_245 , NULL , 0x0F ,
NULL , V_244 }
} ,
{ & V_232 ,
{ L_18 , L_19 ,
V_246 , V_247 , F_51 ( & V_248 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_233 ,
{ L_20 , L_21 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_236 ,
{ L_22 , L_23 ,
V_242 , V_243 | V_250 , & V_235 , 0x0 ,
NULL , V_244 }
} ,
{ & V_238 ,
{ L_24 , L_25 ,
V_242 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_223 ,
{ L_26 , L_27 ,
V_246 , 8 , F_51 ( & V_251 ) , V_237 ,
NULL , V_244 }
} ,
{ & V_225 ,
{ L_28 , L_29 ,
V_242 , V_245 , F_52 ( V_252 ) , V_253 ,
NULL , V_244 }
} ,
{ & V_240 ,
{ L_30 , L_31 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_208 ,
{ L_32 , L_33 ,
V_246 , 8 , F_51 ( & V_255 ) , V_209 ,
NULL , V_244 }
} ,
{ & V_207 ,
{ L_34 , L_35 ,
V_242 , V_245 , F_52 ( V_256 ) , V_212 ,
NULL , V_244 }
} ,
{ & V_210 ,
{ L_28 , L_36 ,
V_242 , V_245 , F_52 ( V_257 ) , V_258 ,
NULL , V_244 }
} ,
{ & V_18 ,
{ L_37 , L_38 ,
V_242 , V_243 , F_52 ( V_259 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_20 ,
{ L_39 , L_40 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_23 ,
{ L_41 , L_42 ,
V_242 , V_243 , F_52 ( V_260 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_24 ,
{ L_43 , L_44 ,
V_242 , V_243 , F_52 ( V_261 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_25 ,
{ L_45 , L_46 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_26 ,
{ L_47 , L_48 ,
V_242 , V_243 , F_52 ( V_262 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_27 ,
{ L_49 , L_50 ,
V_242 , V_243 , F_52 ( V_263 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_28 ,
{ L_51 , L_52 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_29 ,
{ L_53 , L_54 ,
V_242 , V_245 | V_264 , & V_265 , 0x0 ,
NULL , V_244 }
} ,
{ & V_30 ,
{ L_55 , L_56 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_31 ,
{ L_57 , L_58 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_33 ,
{ L_59 , L_60 ,
V_242 , V_243 , F_52 ( V_266 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_34 ,
{ L_61 , L_62 ,
V_242 , V_243 , F_52 ( V_267 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_58 ,
{ L_63 , L_64 ,
V_242 , V_243 , F_52 ( V_268 ) , 0x1F ,
NULL , V_244 }
} ,
{ & V_60 ,
{ L_65 , L_66 ,
V_242 , V_243 , F_52 ( V_269 ) , 0x1F ,
NULL , V_244 }
} ,
{ & V_61 ,
{ L_67 , L_68 ,
V_242 , V_243 , F_52 ( V_270 ) , 0x60 ,
NULL , V_244 }
} ,
{ & V_62 ,
{ L_69 , L_70 ,
V_242 , V_243 , F_52 ( V_271 ) , 0x03 ,
NULL , V_244 }
} ,
{ & V_63 ,
{ L_71 , L_72 ,
V_242 , V_243 , F_52 ( V_272 ) , 0x7F ,
NULL , V_244 }
} ,
{ & V_68 ,
{ L_73 , L_74 ,
V_242 , V_243 , NULL , 0x1F ,
NULL , V_244 }
} ,
{ & V_69 ,
{ L_75 , L_76 ,
V_242 , V_243 , F_52 ( V_273 ) , 0x1F ,
NULL , V_244 }
} ,
{ & V_72 ,
{ L_77 , L_78 ,
V_242 , V_243 , NULL , 0x7F ,
NULL , V_244 }
} ,
{ & V_73 ,
{ L_59 , L_79 ,
V_242 , V_243 , F_52 ( V_274 ) , 0x60 ,
NULL , V_244 }
} ,
{ & V_74 ,
{ L_80 , L_81 ,
V_242 , V_245 , NULL , 0x7F ,
NULL , V_244 }
} ,
{ & V_75 ,
{ L_82 , L_83 ,
V_242 , V_243 , F_52 ( V_275 ) , 0x1F ,
NULL , V_244 }
} ,
{ & V_80 ,
{ L_84 , L_85 ,
V_242 , V_245 | V_264 , & V_265 , 0x0F ,
NULL , V_244 }
} ,
{ & V_81 ,
{ L_86 , L_87 ,
V_242 , V_245 , NULL , 0x7F ,
NULL , V_244 }
} ,
{ & V_84 ,
{ L_88 , L_89 ,
V_242 , V_243 , F_52 ( V_276 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_86 ,
{ L_90 , L_91 ,
V_277 , V_243 , F_52 ( V_278 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_88 ,
{ L_92 , L_93 ,
V_254 , V_243 , F_52 ( V_279 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_90 ,
{ L_94 , L_95 ,
V_254 , V_243 , F_52 ( V_280 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_91 ,
{ L_96 , L_97 ,
V_254 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_96 ,
{ L_98 , L_99 ,
V_242 , V_243 , F_52 ( V_281 ) , 0x0F ,
NULL , V_244 }
} ,
{ & V_97 ,
{ L_100 , L_101 ,
V_242 , V_243 | V_250 , & V_282 , 0x7F ,
NULL , V_244 }
} ,
{ & V_105 ,
{ L_102 , L_103 ,
V_242 , V_243 , F_52 ( V_283 ) , 0x7C ,
NULL , V_244 }
} ,
{ & V_103 ,
{ L_104 , L_105 ,
V_242 , V_243 , F_52 ( V_284 ) , 0x03 ,
NULL , V_244 }
} ,
{ & V_107 ,
{ L_106 , L_107 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_109 ,
{ L_108 , L_109 ,
V_242 , V_243 | V_250 , & V_203 , 0x0 ,
NULL , V_244 }
} ,
{ & V_111 ,
{ L_110 , L_111 ,
V_242 , V_243 | V_250 , & V_203 , 0x0 ,
NULL , V_244 }
} ,
{ & V_112 ,
{ L_112 , L_113 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_119 ,
{ L_114 , L_115 ,
V_242 , V_243 | V_250 , & V_203 , 0x0 ,
NULL , V_244 }
} ,
{ & V_121 ,
{ L_116 , L_117 ,
V_242 , V_243 , F_52 ( V_285 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_123 ,
{ L_118 , L_119 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_124 ,
{ L_120 , L_121 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_127 ,
{ L_22 , L_122 ,
V_242 , V_243 | V_250 , & V_235 , 0x0 ,
NULL , V_244 }
} ,
{ & V_129 ,
{ L_123 , L_124 ,
V_286 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_131 ,
{ L_125 , L_126 ,
V_242 , V_243 , F_52 ( V_287 ) , 0x3F ,
NULL , V_244 }
} ,
{ & V_134 ,
{ L_127 , L_128 ,
V_242 , V_243 , F_52 ( V_288 ) , 0x70 ,
NULL , V_244 }
} ,
{ & V_135 ,
{ L_129 , L_130 ,
V_242 , V_243 , F_52 ( V_289 ) , 0x0F ,
NULL , V_244 }
} ,
{ & V_136 ,
{ L_131 , L_132 ,
V_242 , V_243 , F_52 ( V_290 ) , 0x60 ,
NULL , V_244 }
} ,
{ & V_137 ,
{ L_133 , L_134 ,
V_242 , V_243 , F_52 ( V_291 ) , 0x03 ,
NULL , V_244 }
} ,
{ & V_139 ,
{ L_8 , L_135 ,
V_286 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_143 ,
{ L_8 , L_136 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_144 ,
{ L_137 , L_138 ,
V_242 , V_243 , F_52 ( V_292 ) , 0x70 ,
NULL , V_244 }
} ,
{ & V_145 ,
{ L_139 , L_140 ,
V_242 , V_243 , F_52 ( V_293 ) , 0x10 ,
NULL , V_244 }
} ,
{ & V_146 ,
{ L_141 , L_142 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_147 ,
{ L_143 , L_144 ,
V_242 , V_243 , F_52 ( V_294 ) , 0x18 ,
NULL , V_244 }
} ,
{ & V_148 ,
{ L_145 , L_146 ,
V_242 , V_243 , F_52 ( V_295 ) , 0x07 ,
NULL , V_244 }
} ,
{ & V_149 ,
{ L_118 , L_147 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_150 ,
{ L_120 , L_148 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_152 ,
{ L_149 , L_150 ,
V_254 , V_245 | V_264 , & V_296 , 0x0 ,
NULL , V_244 }
} ,
{ & V_153 ,
{ L_151 , L_152 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_155 ,
{ L_153 , L_154 ,
V_242 , V_243 , F_52 ( V_297 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_156 ,
{ L_155 , L_156 ,
V_242 , V_243 , F_52 ( V_297 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_157 ,
{ L_157 , L_158 ,
V_242 , V_243 , F_52 ( V_298 ) , 0x0F ,
NULL , V_244 }
} ,
{ & V_158 ,
{ L_159 , L_160 ,
V_242 , V_243 , F_52 ( V_299 ) , 0x07 ,
NULL , V_244 }
} ,
{ & V_162 ,
{ L_161 , L_162 ,
V_242 , V_243 , F_52 ( V_300 ) , 0x70 ,
NULL , V_244 }
} ,
{ & V_163 ,
{ L_163 , L_164 ,
V_242 , V_243 , F_52 ( V_301 ) , 0x0F ,
NULL , V_244 }
} ,
{ & V_164 ,
{ L_165 , L_166 ,
V_286 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_165 ,
{ L_167 , L_168 ,
V_242 , V_243 , F_52 ( V_302 ) , 0x60 ,
NULL , V_244 }
} ,
{ & V_166 ,
{ L_169 , L_170 ,
V_246 , 8 , F_51 ( & V_303 ) , 0x10 ,
NULL , V_244 }
} ,
{ & V_167 ,
{ L_171 , L_172 ,
V_242 , V_243 , F_52 ( V_304 ) , 0x07 ,
NULL , V_244 }
} ,
{ & V_168 ,
{ L_173 , L_174 ,
V_242 , V_243 , F_52 ( V_305 ) , 0x70 ,
NULL , V_244 }
} ,
{ & V_169 ,
{ L_175 , L_176 ,
V_242 , V_243 , F_52 ( V_306 ) , 0x07 ,
NULL , V_244 }
} ,
{ & V_170 ,
{ L_177 , L_178 ,
V_242 , V_243 , F_52 ( V_307 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_171 ,
{ L_179 , L_180 ,
V_246 , 16 , F_51 ( & V_308 ) , 0x8000 ,
NULL , V_244 }
} ,
{ & V_172 ,
{ L_179 , L_181 ,
V_254 , V_245 , NULL , 0x7FFF ,
NULL , V_244 }
} ,
{ & V_173 ,
{ L_182 , L_183 ,
V_242 , V_243 , F_52 ( V_309 ) , 0x3F ,
NULL , V_244 }
} ,
{ & V_204 ,
{ L_114 , L_184 ,
V_242 , V_243 | V_250 , & V_203 , 0x0 ,
NULL , V_244 }
} ,
{ & V_205 ,
{ L_185 , L_186 ,
V_242 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_211 ,
{ L_187 , L_188 ,
V_254 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_214 ,
{ L_189 , L_190 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_52 ,
{ L_191 , L_192 ,
V_246 , 8 , F_51 ( & V_310 ) , 0x80 ,
NULL , V_244 }
} ,
{ & V_53 ,
{ L_193 , L_194 ,
V_246 , 8 , F_51 ( & V_310 ) , 0x40 ,
NULL , V_244 }
} ,
{ & V_54 ,
{ L_195 , L_196 ,
V_246 , 8 , F_51 ( & V_311 ) , 0x02 ,
NULL , V_244 }
} ,
{ & V_55 ,
{ L_197 , L_198 ,
V_246 , 8 , F_51 ( & V_311 ) , 0x01 ,
NULL , V_244 }
} ,
{ & V_32 ,
{ L_199 , L_200 ,
V_312 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_101 ,
{ L_201 , L_202 ,
V_246 , 8 , F_51 ( & V_313 ) , 0x80 ,
NULL , V_244 }
} ,
{ & V_102 ,
{ L_203 , L_204 ,
V_246 , 8 , F_51 ( & V_314 ) , 0x40 ,
NULL , V_244 }
} ,
{ & V_141 ,
{ L_205 , L_206 ,
V_249 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_36 ,
{ L_207 , L_208 ,
V_242 , V_243 , F_52 ( V_285 ) , 0x0 ,
NULL , V_244 }
} ,
{ & V_49 ,
{ L_209 , L_210 ,
V_277 , V_245 | V_264 , & V_315 , 0x0 ,
NULL , V_244 }
} ,
{ & V_22 ,
{ L_207 , L_211 ,
V_242 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_151 ,
{ L_207 , L_212 ,
V_242 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_159 ,
{ L_207 , L_213 ,
V_242 , V_243 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_160 ,
{ L_214 , L_215 ,
V_316 , V_247 , NULL , 0x0 ,
NULL , V_244 }
} ,
{ & V_9 ,
{ L_216 , L_217 ,
V_242 , V_245 , NULL , 0x0 ,
NULL , V_244 }
} ,
} ;
static T_11 * V_317 [] = {
& V_229 ,
& V_239 ,
& V_202 ,
& V_206 ,
& V_142 ,
} ;
static T_12 V_318 [] = {
{ & V_56 , { L_218 , V_319 , V_320 , L_219 , V_321 } } ,
{ & V_35 , { L_220 , V_319 , V_320 , L_221 , V_321 } } ,
{ & V_154 , { L_222 , V_319 , V_320 , L_223 , V_321 } } ,
{ & V_161 , { L_224 , V_319 , V_320 , L_225 , V_321 } } ,
} ;
T_13 * V_322 ;
V_228 = F_53 ( L_12 , L_12 , L_226 ) ;
F_54 ( V_228 , V_241 , F_55 ( V_241 ) ) ;
F_56 ( V_317 , F_55 ( V_317 ) ) ;
V_322 = F_57 ( V_228 ) ;
F_58 ( V_322 , V_318 , F_55 ( V_318 ) ) ;
F_59 ( L_226 , F_40 , V_228 ) ;
}
