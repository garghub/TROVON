static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
if ( V_4 != 2 ) {
F_2 ( V_5 , V_2 , & V_7 , V_1 , V_3 , V_4 , L_1 , V_4 ) ;
return;
}
V_6 = F_3 ( V_1 , V_3 ) ;
if ( V_6 & 0x80 ) {
F_4 ( V_5 , V_8 , V_1 , V_3 , 1 ,
V_6 & 0x7F , L_2 , V_6 & 0x7F ) ;
} else {
F_4 ( V_5 , V_9 , V_1 , V_3 , 1 ,
V_6 & 0x7F , L_2 , V_6 & 0x7F ) ;
}
F_5 ( V_5 , V_10 , V_1 , V_3 + 1 , 1 , V_11 ) ;
}
static void
F_6 ( T_1 * V_1 , int V_3 , T_3 * V_5 )
{
unsigned int V_12 = F_3 ( V_1 , V_3 ) ;
if ( V_12 == V_13 ) {
F_4 ( V_5 , V_14 ,
V_1 , V_3 , 1 , V_12 ,
L_3 ) ;
} else if ( V_12 == V_15 ) {
F_4 ( V_5 , V_14 ,
V_1 , V_3 , 1 , V_12 ,
L_4 ) ;
} else if ( ( V_12 >= 16 && V_12 < 63 )
|| ( ( V_12 >= 80 ) && ( V_12 < 254 ) ) ) {
F_4 ( V_5 , V_14 ,
V_1 , V_3 , 1 , V_12 ,
L_5 ,
V_12 ) ;
} else if ( V_12 >= 64 && V_12 <= 79 ) {
F_4 ( V_5 , V_14 ,
V_1 , V_3 , 1 , V_12 ,
L_6 ,
V_12 ) ;
} else {
F_4 ( V_5 , V_14 ,
V_1 , V_3 , 1 , V_12 ,
L_7 ,
V_12 ) ;
}
}
static void
F_7 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
T_4 V_16 ;
T_4 V_17 ;
T_4 V_18 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_16 = V_6 & 0x60 ;
if ( V_16 != V_19 ) {
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_21 ) ;
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
return;
}
F_8 ( V_5 , V_24 , V_1 , V_3 , 1 , V_6 ) ;
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( ! ( V_6 & V_25 ) ) {
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_26 , V_1 , V_3 , 1 , V_21 ) ;
V_3 += 1 ;
V_4 -= 1 ;
}
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_8 ( V_5 , V_27 , V_1 , V_3 , 1 , V_6 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
if ( ( V_6 & 0x60 ) == 0x20 ) {
F_8 ( V_5 , V_28 , V_1 , V_3 , 1 , V_6 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_29;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_5 ( V_5 , V_30 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_31 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_29;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_5 ( V_5 , V_32 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_33 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_34 , V_1 , V_3 , 1 , V_21 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_29;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_5 ( V_5 , V_35 , V_1 , V_3 , 1 , V_11 ) ;
F_5 ( V_5 , V_36 , V_1 , V_3 , 1 , V_11 ) ;
F_5 ( V_5 , V_37 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_29;
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_38 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_39 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
}
V_29:
;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
if ( ( V_6 & 0x60 ) == 0x40 ) {
V_17 = V_6 & 0x1F ;
F_5 ( V_5 , V_40 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_41;
if ( V_4 == 0 )
return;
if ( V_17 == V_42 ) {
F_5 ( V_5 , V_43 , V_1 , V_3 , 1 , V_11 ) ;
} else {
F_5 ( V_5 , V_44 , V_1 , V_3 , 1 , V_11 ) ;
}
V_3 += 1 ;
V_4 -= 1 ;
}
V_41:
;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
if ( ( V_6 & 0x60 ) == 0x60 ) {
V_18 = V_6 & 0x1F ;
F_5 ( V_5 , V_45 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_46;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
switch ( V_18 ) {
case V_47 :
case V_48 :
case V_49 :
F_5 ( V_5 , V_50 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_46;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_5 ( V_5 , V_51 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_25 )
goto V_46;
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_52 , V_1 , V_3 , 1 , V_11 ) ;
break;
case V_53 :
F_4 ( V_5 , V_54 , V_1 , V_3 , 1 ,
1 << ( V_6 & 0x0F ) , L_8 , 1 << ( V_6 & 0x0F ) ) ;
break;
case V_55 :
if ( V_6 & V_25 )
goto V_46;
#if 0
if (len == 0)
return;
#endif
F_5 ( V_5 , V_56 , V_1 , V_3 , 2 , V_11 ) ;
break;
}
}
V_46:
;
}
static void
F_10 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 , int V_57 )
{
T_4 V_6 ;
T_4 V_58 ;
T_4 V_16 ;
T_4 V_59 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_16 = V_6 & 0x60 ;
if ( V_16 != V_19 ) {
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_21 ) ;
return;
}
F_8 ( V_5 , V_60 , V_1 , V_3 , 1 , V_6 ) ;
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( ! ( V_6 & V_25 ) ) {
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_5 ( V_5 , V_61 , V_1 , V_3 , 1 , V_11 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
}
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_58 = V_6 & 0x7F ;
F_8 ( V_5 , V_57 , V_1 , V_3 , 1 , V_58 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_4 == 0 )
return;
switch ( V_58 ) {
case V_62 :
case V_63 :
case V_64 :
F_5 ( V_5 , V_65 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_66 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_67 , V_1 , V_3 , 1 , V_11 ) ;
break;
case V_68 :
V_59 = V_6 & 0x7C ;
F_5 ( V_5 , V_69 , V_1 , V_3 , 1 , V_11 ) ;
F_5 ( V_5 , V_67 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_4 == 0 )
return;
switch ( V_59 ) {
case V_70 :
F_5 ( V_5 , V_71 , V_1 , V_3 , V_4 , V_21 ) ;
break;
case V_72 :
F_5 ( V_5 , V_73 , V_1 , V_3 , 1 , V_11 ) ;
break;
case V_74 :
F_5 ( V_5 , V_75 , V_1 , V_3 , 1 , V_11 ) ;
break;
default:
F_5 ( V_5 , V_76 , V_1 , V_3 , V_4 , V_21 ) ;
break;
}
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
do {
F_5 ( V_5 , V_82 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
} while ( V_4 != 0 );
break;
case V_83 :
case V_84 :
F_5 ( V_5 , V_85 , V_1 , V_3 , 1 , V_11 ) ;
break;
case V_86 :
if ( V_4 < 3 )
return;
F_5 ( V_5 , V_87 , V_1 , V_3 , 3 , V_88 | V_21 ) ;
break;
default:
F_5 ( V_5 , V_89 , V_1 , V_3 , V_4 , V_21 ) ;
}
}
static void
F_11 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
T_4 V_16 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_16 = V_6 & 0x60 ;
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
if ( V_16 != V_19 ) {
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_21 ) ;
return;
}
F_5 ( V_5 , V_90 , V_1 , V_3 , 1 , V_11 ) ;
}
static void
F_12 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_91 ;
if ( V_4 == 0 )
return;
V_91 = F_3 ( V_1 , V_3 ) ;
F_8 ( V_5 , V_92 , V_1 , V_3 , 1 , V_91 ) ;
}
static void
F_13 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_93 , V_94 ;
if ( V_4 < 2 )
return;
V_93 = F_3 ( V_1 , V_3 ) ;
V_94 = F_3 ( V_1 , V_3 + 1 ) ;
F_8 ( V_5 , V_95 , V_1 , V_3 , 1 , V_93 ) ;
F_8 ( V_5 , V_96 , V_1 , V_3 + 1 , 1 , V_94 ) ;
}
static void
F_14 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_5 V_97 ;
T_4 V_98 = 2 ;
if ( V_4 < 3 )
return;
V_97 = ( ( F_3 ( V_1 , V_3 ) & 0x3F ) << 4 ) |
( ( F_3 ( V_1 , V_3 + 1 ) & 0x78 ) >> 3 ) ;
if ( V_4 == 4 ) {
V_97 = ( V_97 << 6 ) | ( ( F_3 ( V_1 , V_3 + 2 ) & 0x7E ) >> 1 ) ;
V_98 ++ ;
} else if ( V_4 == 5 ) {
V_97 = ( V_97 << 13 ) | ( F_3 ( V_1 , V_3 + 3 ) & 0x7F ) |
( ( F_3 ( V_1 , V_3 + 4 ) & 0x7E ) >> 1 ) ;
V_98 += 2 ;
}
F_8 ( V_5 , V_99 , V_1 , V_3 , V_98 , V_97 ) ;
F_5 ( V_5 , V_100 , V_1 , V_3 + V_98 , 1 , V_11 ) ;
}
static void
F_15 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
int V_101 ;
int V_102 ;
T_4 V_16 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_5 ( V_5 , V_103 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_104 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_105 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_106 , V_1 , V_3 , 1 , V_21 ) ;
if ( V_6 & V_107 ) {
F_5 ( V_5 , V_108 , V_1 , V_3 , 1 , V_11 ) ;
} else {
F_5 ( V_5 , V_109 , V_1 , V_3 , 1 , V_11 ) ;
}
V_3 += 1 ;
V_4 -= 1 ;
if ( V_6 & V_110 ) {
V_101 = V_3 ;
V_102 = 0 ;
do {
if ( V_4 == 0 )
break;
V_6 = F_3 ( V_1 , V_3 ) ;
V_3 += 1 ;
V_4 -= 1 ;
V_102 ++ ;
} while ( ! ( V_6 & V_25 ) );
if ( V_102 != 0 ) {
F_5 ( V_5 , V_111 , V_1 , V_101 , V_102 , V_21 ) ;
}
}
if ( V_6 & V_107 ) {
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_16 = V_6 & 0x60 ;
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
if ( V_16 != V_19 ) {
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_21 ) ;
return;
}
F_5 ( V_5 , V_112 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , ( V_6 & V_113 ) ? V_114 : V_115 , V_1 , V_3 , 1 , V_21 ) ;
}
}
static void
F_16 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
T_4 V_16 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_16 = V_6 & 0x60 ;
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
if ( V_16 != V_19 ) {
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_21 ) ;
return;
}
F_5 ( V_5 , V_116 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_117 , V_1 , V_3 , 1 , V_11 ) ;
}
static void
F_17 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
int V_118 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_118 = V_6 & 0x7F ;
F_5 ( V_5 , V_119 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_118 != 0 ) {
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_120 , V_1 , V_3 , 1 , V_11 ) ;
F_5 ( V_5 , V_121 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
V_118 -- ;
if ( V_4 == 0 )
return;
if ( V_118 > V_4 )
V_118 = V_4 ;
if ( V_118 != 0 ) {
F_5 ( V_5 , V_122 , V_1 , V_3 , V_118 , V_21 | V_88 ) ;
V_3 += V_118 ;
V_4 -= V_118 ;
}
}
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_123 , V_1 , V_3 , V_4 , V_21 ) ;
}
static int
F_18 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
T_3 * V_5 , int V_124 )
{
T_4 V_6 ;
T_6 V_125 ;
int V_126 ;
V_126 = 0 ;
V_6 = F_3 ( V_1 , V_3 ) ;
if ( V_6 & V_25 ) {
goto V_127;
}
V_125 = ( V_6 & 0x3 ) << 14 ;
V_3 += 1 ;
V_4 -= 1 ;
V_126 ++ ;
if ( V_4 == 0 ) {
goto V_128;
}
V_6 = F_3 ( V_1 , V_3 ) ;
if ( V_6 & V_25 ) {
goto V_127;
}
V_125 |= ( V_6 & 0x7F ) << 7 ;
V_3 += 1 ;
V_4 -= 1 ;
V_126 ++ ;
if ( V_4 == 0 ) {
goto V_128;
}
V_6 = F_3 ( V_1 , V_3 ) ;
if ( ! ( V_6 & V_25 ) ) {
goto V_127;
}
V_125 |= ( V_6 & 0x7F ) ;
V_3 += 1 ;
V_126 ++ ;
F_4 ( V_5 , V_124 , V_1 , V_3 , V_126 , V_125 , L_9 , V_125 ) ;
return V_126 ;
V_128:
F_2 ( V_5 , V_2 , & V_7 , V_1 , V_3 , V_4 ,
L_10 , F_19 ( V_124 ) ) ;
return - 1 ;
V_127:
F_2 ( V_5 , V_2 , & V_7 , V_1 , V_3 , V_4 ,
L_11 , F_19 ( V_124 ) ) ;
return - 1 ;
}
static void
F_20 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
T_3 * V_5 )
{
int V_126 ;
if ( V_4 == 0 )
return;
V_126 = F_18 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_129 ) ;
if ( V_126 < 0 )
return;
V_3 += V_126 ;
V_4 -= V_126 ;
if ( V_4 == 0 )
return;
V_126 = F_18 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_130 ) ;
if ( V_126 < 0 )
return;
V_3 += V_126 ;
V_4 -= V_126 ;
if ( V_4 == 0 )
return;
F_18 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_131 ) ;
}
static void
F_21 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
T_3 * V_5 )
{
if ( V_4 == 0 )
return;
F_18 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_132 ) ;
}
static void
F_22 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_133 , V_1 , V_3 , 1 , V_21 ) ;
F_5 ( V_5 , V_134 , V_1 , V_3 , 1 , V_21 ) ;
}
static void
F_23 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_135 , V_1 , V_3 , 1 , V_11 ) ;
}
static void
F_24 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 , int V_136 )
{
T_4 V_6 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_8 ( V_5 , V_137 , V_1 , V_3 , 1 , V_6 ) ;
F_8 ( V_5 , V_138 , V_1 , V_3 , 1 , V_6 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( ! ( V_6 & V_25 ) ) {
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_8 ( V_5 , V_139 , V_1 , V_3 , 1 , V_6 ) ;
F_8 ( V_5 , V_140 , V_1 , V_3 , 1 , V_6 ) ;
F_9 ( V_5 , V_23 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
}
if ( ! ( V_6 & V_25 ) ) {
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_141 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
}
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_136 , V_1 , V_3 , V_4 , V_88 | V_21 ) ;
}
static void
F_25 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_142 , V_1 , V_3 , 1 , V_11 ) ;
F_5 ( V_5 , V_143 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_4 == 0 )
return;
F_5 ( V_5 , V_144 , V_1 , V_3 , V_4 , V_21 ) ;
}
static void
F_26 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
T_4 V_16 ;
T_4 V_145 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_16 = V_6 & 0x60 ;
F_8 ( V_5 , V_22 , V_1 , V_3 , 1 , V_6 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_16 != V_19 ) {
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_21 ) ;
return;
}
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
V_145 = V_6 & 0x7F ;
F_5 ( V_5 , V_146 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( ! ( V_6 & V_25 ) ) {
if ( V_4 == 0 )
return;
if ( V_145 == V_147 ) {
F_5 ( V_5 , V_148 , V_1 , V_3 , 1 , V_11 ) ;
} else {
F_5 ( V_5 , V_149 , V_1 , V_3 , 1 , V_11 ) ;
}
}
}
static void
F_27 ( T_1 * V_1 , int V_3 , int V_4 ,
T_3 * V_5 )
{
T_4 V_6 ;
if ( V_4 == 0 )
return;
V_6 = F_3 ( V_1 , V_3 ) ;
F_5 ( V_5 , V_150 , V_1 , V_3 , 1 , V_11 ) ;
V_3 += 1 ;
V_4 -= 1 ;
if ( V_4 == 0 )
return;
switch ( V_6 ) {
case V_151 :
F_5 ( V_5 , V_152 , V_1 , V_3 , V_4 , V_21 | V_88 ) ;
break;
default:
F_5 ( V_5 , V_153 , V_1 , V_3 , V_4 , V_21 ) ;
break;
}
}
static void
F_28 ( T_1 * V_1 , int V_3 , int V_4 , T_3 * V_5 , int V_124 )
{
if ( V_4 != 0 ) {
F_5 ( V_5 , V_124 , V_1 , V_3 , V_4 , V_88 | V_21 ) ;
}
}
static void
F_29 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_5 )
{
int V_3 = 0 ;
T_3 * V_154 = NULL ;
T_7 * V_155 ;
T_3 * V_156 = NULL ;
T_4 V_157 ;
T_4 V_158 [ 15 ] ;
T_4 V_159 ;
T_4 V_160 ;
T_6 V_161 ;
int V_162 , V_163 ;
T_8 V_164 ;
F_30 ( V_2 -> V_165 , V_166 , L_3 ) ;
if ( V_5 ) {
V_155 = F_5 ( V_5 , V_167 , V_1 , V_3 , - 1 ,
V_21 ) ;
V_154 = F_31 ( V_155 , V_168 ) ;
F_6 ( V_1 , V_3 , V_154 ) ;
}
V_3 += 1 ;
V_157 = F_3 ( V_1 , V_3 ) & 0xF ;
if ( V_154 != NULL )
F_8 ( V_154 , V_169 , V_1 , V_3 , 1 , V_157 ) ;
V_3 += 1 ;
if ( V_157 != 0 ) {
F_32 ( V_1 , V_158 , V_3 , V_157 ) ;
F_9 ( V_154 , V_170 ,
V_1 , V_3 , 1 , ( V_158 [ 0 ] & 0x80 ) != 0 ) ;
V_158 [ 0 ] &= 0x7F ;
F_33 ( V_154 , V_171 ,
V_1 , V_3 , V_157 , V_158 ) ;
V_3 += V_157 ;
}
V_159 = F_3 ( V_1 , V_3 ) ;
F_34 ( V_2 -> V_165 , V_172 ,
F_35 ( V_159 , V_173 ,
L_12 ) ) ;
F_8 ( V_154 , V_85 , V_1 , V_3 , 1 , V_159 ) ;
V_3 += 1 ;
V_162 = V_163 = 0 ;
while ( F_36 ( V_1 , V_3 ) > 0 ) {
V_160 = F_3 ( V_1 , V_3 ) ;
if ( ( V_160 & V_174 ) &&
( ( V_160 & V_175 ) == V_176 ) ) {
V_164 = V_160 & V_177 ;
V_162 = V_160 & V_178 ;
if ( ! V_164 )
V_163 = V_162 ;
F_5 ( V_154 , V_164 ? V_179 : V_180 , V_1 , V_3 , 1 , V_21 ) ;
V_3 += 1 ;
continue;
}
if ( V_160 & V_174 ) {
switch ( ( V_162 << 8 ) | ( V_160 & V_175 ) ) {
case V_181 | V_182 :
F_5 ( V_154 , V_183 , V_1 , V_3 , 1 , V_11 ) ;
break;
default:
F_2 ( V_154 , V_2 , & V_184 , V_1 , V_3 , 1 ,
L_13 , V_160 ) ;
break;
}
V_3 += 1 ;
V_162 = V_163 ;
continue;
}
V_161 = F_3 ( V_1 , V_3 + 1 ) ;
if ( V_154 != NULL ) {
V_156 = F_37 ( V_154 , V_1 , V_3 ,
1 + 1 + V_161 , V_185 , NULL ,
F_35 ( V_160 , V_186 [ V_162 ] ,
L_13 ) ) ;
F_4 ( V_156 , V_82 , V_1 , V_3 , 1 , V_160 ,
L_14 , F_35 ( V_160 , V_186 [ V_162 ] , L_15 ) ) ;
F_5 ( V_156 , V_187 , V_1 , V_3 + 1 , 1 , V_11 ) ;
switch ( ( V_162 << 8 ) | V_160 ) {
case V_181 | V_188 :
F_1 ( V_1 ,
V_2 , V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_189 :
case V_181 | V_190 :
F_7 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_191 :
F_10 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ,
V_192 ) ;
break;
case V_181 | V_193 :
F_11 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_194 :
F_15 (
V_1 , V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_195 :
F_16 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_196 :
case V_181 | V_197 :
F_17 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_198 :
F_28 ( V_1 , V_3 + 2 ,
V_161 , V_156 ,
V_199 ) ;
break;
case V_181 | V_200 :
F_20 ( V_1 ,
V_2 , V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_201 :
F_21 (
V_1 , V_2 , V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_202 :
F_22 (
V_1 , V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_203 :
F_23 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_204 :
F_24 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ,
V_205 ) ;
break;
case V_181 | V_206 :
F_24 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ,
V_207 ) ;
break;
case V_181 | V_208 :
F_24 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ,
V_209 ) ;
break;
case V_181 | V_210 :
case V_181 | V_211 :
F_25 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_212 :
F_26 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_213 :
F_27 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_181 | V_214 :
case V_215 | V_214 :
case V_215 | V_216 :
F_12 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_215 | V_217 :
case V_215 | V_218 :
F_13 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
case V_215 | V_219 :
case V_215 | V_220 :
F_14 ( V_1 ,
V_3 + 2 , V_161 ,
V_156 ) ;
break;
default:
F_5 ( V_156 , V_20 , V_1 , V_3 + 2 , V_161 , V_21 ) ;
break;
}
}
V_3 += 1 + 1 + V_161 ;
V_162 = V_163 ;
}
}
void
F_38 ( void )
{
static T_9 V_124 [] = {
{ & V_14 ,
{ L_16 , L_17 , V_221 , V_222 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_170 ,
{ L_18 , L_19 , V_224 , V_225 , F_39 ( & V_226 ) , 0x0 ,
NULL , V_223 } } ,
{ & V_171 ,
{ L_20 , L_21 , V_227 , V_225 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_22 ,
{ L_22 , L_23 , V_221 , V_222 ,
F_40 ( V_228 ) , 0x60 , NULL , V_223 } } ,
{ & V_24 ,
{ L_24 , L_25 , V_221 , V_222 ,
F_40 ( V_229 ) , 0x1f , NULL , V_223 } } ,
{ & V_27 ,
{ L_26 , L_27 , V_221 , V_222 ,
F_40 ( V_230 ) , 0x60 , NULL , V_223 } } ,
{ & V_28 ,
{ L_28 , L_29 , V_221 , V_222 ,
F_40 ( V_231 ) , 0x1f , NULL , V_223 } } ,
{ & V_169 ,
{ L_30 , L_31 , V_221 , V_232 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_85 ,
{ L_32 , L_33 , V_221 , V_222 , F_40 ( V_173 ) , 0x0 ,
NULL , V_223 } } ,
{ & V_60 ,
{ L_34 , L_35 , V_221 , V_232 , F_40 ( V_233 ) , 0x0f ,
NULL , V_223 } } ,
{ & V_192 ,
{ L_36 , L_37 , V_221 , V_232 , F_40 ( V_234 ) , 0x7f ,
NULL , V_223 } } ,
{ & V_138 ,
{ L_38 , L_39 , V_221 , V_222 , F_40 ( V_235 ) , 0x70 ,
NULL , V_223 } } ,
{ & V_137 ,
{ L_40 , L_41 , V_221 , V_222 , F_40 ( V_236 ) , 0x0f ,
NULL , V_223 } } ,
{ & V_139 ,
{ L_42 , L_43 , V_221 , V_222 , F_40 ( V_237 ) , 0x03 ,
NULL , V_223 } } ,
{ & V_140 ,
{ L_44 , L_45 , V_221 , V_222 , F_40 ( V_238 ) , 0x60 ,
NULL , V_223 } } ,
{ & V_23 ,
{ L_46 , L_47 ,
V_224 , 8 , F_39 ( & V_239 ) , 0x80 ,
NULL , V_223 } } ,
{ & V_205 ,
{ L_48 , L_49 , V_240 , V_225 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_209 ,
{ L_50 , L_51 , V_240 , V_225 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_207 ,
{ L_52 , L_53 , V_240 , V_225 , NULL , 0x0 ,
NULL , V_223 } } ,
#if 0
{ &hf_q933_redirecting_number,
{ "Redirecting party number digits", "q933.redirecting_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
{ & V_92 ,
{ L_54 , L_55 , V_221 , V_232 , F_40 ( V_241 ) , 0x0 ,
NULL , V_223 } } ,
{ & V_95 ,
{ L_56 , L_57 , V_221 , V_232 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_96 ,
{ L_58 , L_59 , V_221 , V_232 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_20 ,
{ L_60 , L_61 , V_227 , V_225 , NULL , 0x0 ,
NULL , V_223 } } ,
{ & V_8 , { L_62 , L_63 , V_221 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_9 , { L_64 , L_65 , V_221 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_10 , { L_66 , L_67 , V_221 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_26 , { L_68 , L_69 , V_224 , 8 , F_39 ( & V_242 ) , 0x40 , NULL , V_223 } } ,
{ & V_30 , { L_70 , L_71 , V_224 , 8 , F_39 ( & V_243 ) , 0x40 , NULL , V_223 } } ,
{ & V_31 , { L_72 , L_73 , V_221 , V_232 , F_40 ( V_244 ) , 0x1F , NULL , V_223 } } ,
{ & V_32 , { L_74 , L_75 , V_224 , 8 , F_39 ( & V_245 ) , 0x40 , NULL , V_223 } } ,
{ & V_33 , { L_76 , L_77 , V_224 , 8 , F_39 ( & V_246 ) , 0x20 , NULL , V_223 } } ,
{ & V_34 , { L_78 , L_79 , V_224 , 8 , F_39 ( & V_247 ) , 0x10 , NULL , V_223 } } ,
{ & V_35 , { L_80 , L_81 , V_221 , V_232 , F_40 ( V_248 ) , 0x60 , NULL , V_223 } } ,
{ & V_36 , { L_82 , L_83 , V_221 , V_232 , F_40 ( V_249 ) , 0x18 , NULL , V_223 } } ,
{ & V_37 , { L_84 , L_85 , V_221 , V_232 , F_40 ( V_250 ) , 0x07 , NULL , V_223 } } ,
{ & V_38 , { L_86 , L_87 , V_224 , 8 , F_39 ( & V_251 ) , 0x40 , NULL , V_223 } } ,
{ & V_39 , { L_88 , L_89 , V_221 , V_222 , NULL , 0x3F , NULL , V_223 } } ,
{ & V_40 , { L_90 , L_91 , V_221 , V_222 , F_40 ( V_252 ) , 0x1F , NULL , V_223 } } ,
{ & V_43 , { L_92 , L_93 , V_221 , V_222 , NULL , 0x7F , NULL , V_223 } } ,
{ & V_44 , { L_94 , L_95 , V_221 , V_222 , F_40 ( V_253 ) , 0x03 , NULL , V_223 } } ,
{ & V_45 , { L_96 , L_97 , V_221 , V_222 , F_40 ( V_254 ) , 0x1F , NULL , V_223 } } ,
{ & V_50 , { L_98 , L_99 , V_221 , V_222 , F_40 ( V_255 ) , 0x60 , NULL , V_223 } } ,
{ & V_51 , { L_100 , L_101 , V_221 , V_232 , NULL , 0x0F , NULL , V_223 } } ,
{ & V_52 , { L_102 , L_103 , V_221 , V_232 , NULL , 0x7F , NULL , V_223 } } ,
{ & V_54 , { L_100 , L_101 , V_221 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_56 , { L_104 , L_105 , V_256 , V_222 , F_40 ( V_257 ) , 0x0FF0 , NULL , V_223 } } ,
{ & V_61 , { L_106 , L_107 , V_221 , V_222 , F_40 ( V_258 ) , 0x7F , NULL , V_223 } } ,
{ & V_65 , { L_108 , L_109 , V_224 , 8 , F_39 ( & V_259 ) , 0x80 , NULL , V_223 } } ,
{ & V_66 , { L_110 , L_111 , V_224 , 8 , NULL , 0x40 , NULL , V_223 } } ,
{ & V_67 , { L_110 , L_112 , V_221 , V_222 , F_40 ( V_260 ) , 0x03 , NULL , V_223 } } ,
{ & V_69 , { L_113 , L_114 , V_221 , V_222 , F_40 ( V_261 ) , 0x7C , NULL , V_223 } } ,
{ & V_71 , { L_115 , L_116 , V_227 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_73 , { L_117 , L_118 , V_221 , V_222 , F_40 ( V_262 ) , 0x0 , NULL , V_223 } } ,
{ & V_75 , { L_119 , L_120 , V_221 , V_222 , F_40 ( V_262 ) , 0x0 , NULL , V_223 } } ,
{ & V_76 , { L_121 , L_122 , V_227 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_82 , { L_123 , L_124 , V_221 , V_222 , F_40 ( V_262 ) , 0x0 , NULL , V_223 } } ,
{ & V_87 , { L_125 , L_126 , V_240 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_90 , { L_127 , L_128 , V_221 , V_222 , F_40 ( V_263 ) , 0x3F , NULL , V_223 } } ,
{ & V_99 , { L_129 , L_130 , V_264 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_100 , { L_131 , L_132 , V_221 , V_232 , F_40 ( V_265 ) , 0x0A , NULL , V_223 } } ,
{ & V_103 , { L_133 , L_134 , V_224 , 8 , F_39 ( & V_266 ) , V_110 , NULL , V_223 } } ,
{ & V_104 , { L_133 , L_135 , V_224 , 8 , F_39 ( & V_267 ) , V_107 , NULL , V_223 } } ,
{ & V_105 , { L_136 , L_137 , V_224 , 8 , F_39 ( & V_268 ) , 0x08 , NULL , V_223 } } ,
{ & V_106 , { L_136 , L_138 , V_224 , 8 , F_39 ( & V_269 ) , 0x04 , NULL , V_223 } } ,
{ & V_108 , { L_139 , L_140 , V_221 , V_222 , F_40 ( V_270 ) , 0x03 , NULL , V_223 } } ,
{ & V_109 , { L_139 , L_140 , V_221 , V_222 , F_40 ( V_271 ) , 0x03 , NULL , V_223 } } ,
{ & V_111 , { L_141 , L_142 , V_227 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_112 , { L_143 , L_144 , V_224 , 8 , F_39 ( & V_272 ) , V_113 , NULL , V_223 } } ,
{ & V_114 , { L_145 , L_146 , V_221 , V_222 , F_40 ( V_273 ) , 0x0F , NULL , V_223 } } ,
{ & V_115 , { L_147 , L_148 , V_221 , V_222 , F_40 ( V_273 ) , 0x0F , NULL , V_223 } } ,
{ & V_116 , { L_149 , L_150 , V_221 , V_222 , F_40 ( V_233 ) , 0x0F , NULL , V_223 } } ,
{ & V_117 , { L_151 , L_152 , V_221 , V_222 , F_40 ( V_274 ) , 0x7F , NULL , V_223 } } ,
{ & V_119 , { L_153 , L_154 , V_221 , V_232 , NULL , 0x7F , NULL , V_223 } } ,
{ & V_120 , { L_155 , L_156 , V_221 , V_222 , F_40 ( V_275 ) , 0x70 , NULL , V_223 } } ,
{ & V_121 , { L_157 , L_158 , V_221 , V_222 , F_40 ( V_276 ) , 0x0F , NULL , V_223 } } ,
{ & V_122 , { L_159 , L_160 , V_240 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_123 , { L_161 , L_162 , V_227 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_134 , { L_163 , L_164 , V_224 , 8 , F_39 ( & V_277 ) , 0x02 , NULL , V_223 } } ,
{ & V_135 , { L_165 , L_166 , V_221 , V_222 , F_40 ( V_278 ) , 0x07 , NULL , V_223 } } ,
{ & V_141 , { L_167 , L_168 , V_221 , V_222 , F_40 ( V_279 ) , 0x0F , NULL , V_223 } } ,
{ & V_142 , { L_169 , L_170 , V_221 , V_222 , F_40 ( V_280 ) , 0x70 , NULL , V_223 } } ,
{ & V_143 , { L_171 , L_172 , V_221 , V_222 , F_40 ( V_281 ) , 0x10 , NULL , V_223 } } ,
{ & V_144 , { L_173 , L_174 , V_227 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_146 , { L_175 , L_176 , V_221 , V_222 , F_40 ( V_282 ) , 0x7F , NULL , V_223 } } ,
{ & V_148 , { L_177 , L_178 , V_221 , V_222 , F_40 ( V_283 ) , 0x7F , NULL , V_223 } } ,
{ & V_149 , { L_179 , L_180 , V_221 , V_222 , F_40 ( V_282 ) , 0x7F , NULL , V_223 } } ,
{ & V_150 , { L_16 , L_181 , V_221 , V_222 , F_40 ( V_284 ) , 0x0 , NULL , V_223 } } ,
{ & V_152 , { L_182 , L_183 , V_240 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_153 , { L_182 , L_184 , V_227 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_180 , { L_185 , L_186 , V_221 , V_232 , F_40 ( V_285 ) , V_178 , NULL , V_223 } } ,
{ & V_179 , { L_187 , L_188 , V_221 , V_232 , F_40 ( V_285 ) , V_178 , NULL , V_223 } } ,
{ & V_183 , { L_189 , L_190 , V_221 , V_222 , F_40 ( V_286 ) , V_287 , NULL , V_223 } } ,
{ & V_187 , { L_191 , L_192 , V_221 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_89 , { L_193 , L_194 , V_227 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_199 , { L_195 , L_196 , V_240 , V_225 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_129 , { L_197 , L_198 , V_264 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_130 , { L_199 , L_200 , V_264 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_131 , { L_201 , L_202 , V_264 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_132 , { L_203 , L_204 , V_264 , V_232 , NULL , 0x0 , NULL , V_223 } } ,
{ & V_133 , { L_205 , L_206 , V_224 , 8 , F_39 ( & V_288 ) , 0x04 , NULL , V_223 } } ,
} ;
static T_10 * V_289 [] = {
& V_168 ,
& V_185 ,
} ;
static T_11 V_290 [] = {
{ & V_7 , { L_207 , V_291 , V_292 , L_208 , V_293 } } ,
{ & V_184 , { L_209 , V_294 , V_295 , L_210 , V_293 } } ,
} ;
T_12 * V_296 ;
V_167 = F_41 ( L_3 , L_3 , L_211 ) ;
F_42 ( V_167 , V_124 , F_43 ( V_124 ) ) ;
F_44 ( V_289 , F_43 ( V_289 ) ) ;
V_296 = F_45 ( V_167 ) ;
F_46 ( V_296 , V_290 , F_43 ( V_290 ) ) ;
F_47 ( L_211 , F_29 , V_167 ) ;
}
void
F_48 ( void )
{
T_13 V_297 ;
V_297 = F_49 ( L_211 ) ;
F_50 ( L_212 , V_13 , V_297 ) ;
F_50 ( L_213 , V_298 , V_297 ) ;
}
