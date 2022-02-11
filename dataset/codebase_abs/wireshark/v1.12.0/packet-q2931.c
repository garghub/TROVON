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
F_3 ( V_4 , V_1 , V_2 , 1 , L_5 ,
F_4 ( V_10 , V_15 , L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_10 == 0x40 ) {
if ( V_3 > 4 )
V_3 = 4 ;
F_3 ( V_4 , V_1 , V_2 , V_3 ,
L_6 ,
F_6 ( V_1 , V_2 , V_3 ) ) ;
return;
}
while ( V_3 >= 0 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
switch ( V_11 ) {
case 0x85 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_7 ,
F_4 ( V_12 , V_16 ,
L_4 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x86 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_8 ,
F_4 ( V_12 , V_17 ,
L_4 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x87 :
if ( V_3 < 3 )
return;
V_12 = F_7 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_9 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x88 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_10 ,
F_4 ( V_12 , V_18 ,
L_4 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x89 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_11 ,
F_4 ( V_12 , V_19 ,
L_4 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x8A :
if ( V_3 < 3 )
return;
V_12 = F_7 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_12 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x8B :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_13 , V_12 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x8C :
if ( V_3 < 3 )
return;
V_12 = F_7 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_14 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x81 :
if ( V_3 < 3 )
return;
V_12 = F_7 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_15 , V_12 ) ;
V_2 += 3 ;
V_3 -= 3 ;
break;
case 0x82 :
if ( V_3 < 5 )
return;
V_13 = F_7 ( V_1 , V_2 + 1 ) ;
V_14 = F_7 ( V_1 , V_2 + 3 ) ;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_16 , V_13 , V_14 ) ;
V_2 += 5 ;
V_3 -= 5 ;
break;
case 0x83 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_17 ,
F_4 ( V_12 , V_20 ,
L_4 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
case 0x84 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_18 ,
F_4 ( V_12 , V_21 ,
L_4 ) ) ;
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
F_8 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_11 ;
T_5 V_12 ;
while ( V_3 >= 0 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
switch ( V_11 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
if ( V_3 < 4 )
return;
V_12 = F_9 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 4 ,
L_20 ,
F_4 ( V_11 , V_34 ,
L_4 ) ,
V_12 , F_10 ( V_12 , L_21 , L_22 ) ) ;
V_2 += 4 ;
V_3 -= 4 ;
break;
case V_35 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_23 ,
F_4 ( V_11 , V_34 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
break;
case V_36 :
if ( V_3 < 2 )
return;
V_12 = F_2 ( V_1 , V_2 + 1 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_23 ,
F_4 ( V_11 , V_34 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_24 ,
( V_12 & 0x80 ) ? L_25 : L_26 ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_27 ,
( V_12 & 0x40 ) ? L_25 : L_26 ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_28 ,
( V_12 & 0x02 ) ? L_21 : L_29 ) ;
F_3 ( V_4 , V_1 , V_2 + 1 , 1 ,
L_30 ,
( V_12 & 0x01 ) ? L_21 : L_29 ) ;
V_2 += 2 ;
V_3 -= 2 ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_31 ,
V_11 ) ;
return;
}
}
}
static void
F_11 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_32 ,
F_4 ( V_37 & 0x1F , V_38 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
if ( ! ( V_37 & V_39 ) ) {
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_33 ,
F_4 ( V_37 & 0x1F , V_40 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_34 ,
F_4 ( V_37 & 0x60 , V_41 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_35 ,
F_4 ( V_37 & 0x03 , V_42 ,
L_4 ) ) ;
}
static void
F_12 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_36 ,
F_4 ( V_37 & 0x7F , V_43 ,
L_4 ) ) ;
}
static void
F_13 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
T_3 V_44 ;
T_3 V_45 ;
T_3 V_46 ;
T_5 V_47 ;
T_6 V_48 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
if ( ( V_37 & 0x60 ) == 0x20 ) {
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_37 ,
V_37 & 0x1F ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
if ( ( V_37 & 0x60 ) == 0x40 ) {
V_44 = V_37 & 0x1F ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_38 ,
F_4 ( V_44 , V_49 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_37 & V_39 )
goto V_50;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
if ( V_44 == V_51 ) {
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_39 ,
V_37 & 0x7F ) ;
} else {
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_17 ,
F_4 ( V_37 & 0x60 , V_52 ,
L_4 ) ) ;
}
V_2 += 1 ;
V_3 -= 1 ;
if ( V_37 & V_39 )
goto V_50;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_40 , V_37 & 0x7F ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
V_50:
;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
if ( ( V_37 & 0x60 ) == 0x60 ) {
V_45 = V_37 & 0x1F ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_41 ,
F_4 ( V_45 , V_53 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_37 & V_39 )
goto V_54;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
switch ( V_45 ) {
case V_55 :
case V_56 :
case V_57 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_17 ,
F_4 ( V_37 & 0x60 , V_52 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_37 & V_39 )
goto V_54;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_42 , V_37 & 0x0F ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_37 & V_39 )
goto V_54;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_43 , V_37 & 0x7F ) ;
break;
case V_58 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_44 ,
1 << ( V_37 & 0x0F ) ) ;
break;
case V_59 :
V_46 = ( V_37 & 0x7F ) << 1 ;
if ( V_37 & V_39 )
goto V_54;
if ( V_3 < 2 )
return;
V_46 |= ( F_2 ( V_1 , V_2 + 1 ) & 0x40 ) >> 6 ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_45 ,
F_4 ( V_46 , V_60 ,
L_4 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_46 == V_61 ) {
if ( V_3 < 6 )
return;
V_2 += 1 ;
V_47 = F_9 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_46 ,
V_47 ,
F_14 ( V_47 , V_62 ,
L_47 ) ) ;
V_2 += 3 ;
V_48 = F_7 ( V_1 , V_2 ) ;
switch ( V_47 ) {
case V_63 :
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_48 ,
F_4 ( V_48 , V_64 ,
L_49 ) ) ;
break;
case V_65 :
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_50 ,
F_4 ( V_48 , V_66 ,
L_49 ) ) ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_51 , V_48 ) ;
break;
}
}
break;
}
}
V_54:
;
}
static void
F_15 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
T_3 V_67 ;
T_3 V_68 ;
T_3 V_5 ;
T_3 V_69 ;
T_6 V_70 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_52 ,
F_4 ( V_37 & 0x0F , V_71 ,
L_53 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
V_67 = V_37 & 0x7F ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_54 ,
F_4 ( V_67 , V_72 ,
L_53 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_67 ) {
case V_73 :
case V_74 :
case V_75 :
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_55 ,
( V_37 & 0x80 ) ? L_56 : L_57 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_23 ,
( V_37 & 0x40 ) ? L_58 : L_59 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_60 ,
F_4 ( V_37 & 0x03 , V_76 ,
L_53 ) ) ;
break;
case V_77 :
V_68 = V_37 & 0x7C ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_61 ,
F_4 ( V_37 & 0x7C , V_78 ,
L_53 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_60 ,
F_4 ( V_37 & 0x03 , V_76 ,
L_53 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
switch ( V_68 ) {
case V_79 :
F_3 ( V_4 , V_1 , V_2 , V_3 ,
L_62 ,
F_6 ( V_1 , V_2 , V_3 ) ) ;
break;
case V_80 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_63 ,
F_4 ( F_2 ( V_1 , V_2 ) , V_81 ,
L_4 ) ) ;
break;
case V_82 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_64 ,
F_4 ( F_2 ( V_1 , V_2 ) , V_81 ,
L_4 ) ) ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , V_3 ,
L_65 ,
F_6 ( V_1 , V_2 , V_3 ) ) ;
break;
}
break;
case V_83 :
V_5 = F_2 ( V_1 , V_2 ) ;
V_69 = F_2 ( V_1 , V_2 + 1 ) ;
V_70 = F_7 ( V_1 , V_2 + 2 ) ;
F_16 ( V_1 , V_2 , V_70 , V_4 ,
V_5 , V_69 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
do {
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_66 ,
F_4 ( F_2 ( V_1 , V_2 ) , V_81 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( V_3 >= 0 );
break;
case V_89 :
do {
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_67 ,
F_4 ( F_2 ( V_1 , V_2 ) , V_34 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
} while ( V_3 >= 0 );
break;
case V_90 :
if ( V_3 < 2 )
return;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_68 , F_7 ( V_1 , V_2 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_3 < 2 )
return;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_69 , F_7 ( V_1 , V_2 ) ) ;
break;
case V_91 :
case V_92 :
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_70 ,
F_4 ( F_2 ( V_1 , V_2 ) , V_93 ,
L_4 ) ) ;
break;
case V_94 :
if ( V_3 < 3 )
return;
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_71 , F_17 ( F_18 () , V_1 , V_2 , 3 ) ) ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , V_3 ,
L_72 ,
F_6 ( V_1 , V_2 , V_3 ) ) ;
}
}
static void
F_19 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_73 ,
F_4 ( V_37 & 0x3F , V_95 ,
L_4 ) ) ;
}
static void
F_20 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
T_3 V_96 ;
T_7 * V_97 ;
T_2 * V_98 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_74 ,
F_4 ( V_37 & 0x70 , V_99 ,
L_4 ) ) ;
V_96 = V_37 & 0x0F ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_75 ,
F_4 ( V_96 , V_100 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( ! ( V_37 & V_39 ) ) {
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_76 ,
F_4 ( V_37 & 0x60 , V_101 ,
L_53 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_77 ,
F_4 ( V_37 & 0x03 , V_102 ,
L_53 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
}
if ( V_3 == 0 )
return;
switch ( V_96 ) {
case V_103 :
F_3 ( V_4 , V_1 , V_2 , V_3 , L_78 ,
V_3 , F_17 ( F_18 () , V_1 , V_2 , V_3 ) ) ;
break;
case V_104 :
if ( V_3 < 20 ) {
F_3 ( V_4 , V_1 , V_2 , V_3 ,
L_79 ,
F_6 ( V_1 , V_2 , V_3 ) ) ;
return;
}
V_97 = F_3 ( V_4 , V_1 , V_2 , V_3 , L_80 ) ;
V_98 = F_21 ( V_97 , V_105 ) ;
F_22 ( V_1 , V_2 , V_3 , V_98 ) ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , V_3 , L_81 ,
F_6 ( V_1 , V_2 , V_3 ) ) ;
break;
}
}
static void
F_23 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_82 ,
F_4 ( V_37 & 0x70 , V_106 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_83 ,
F_4 ( V_37 & 0x10 , V_107 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_3 ( V_4 , V_1 , V_2 , V_3 , L_84 ,
F_6 ( V_1 , V_2 , V_3 ) ) ;
}
static void
F_24 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_85 ,
F_4 ( V_37 & 0x18 , V_108 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_86 ,
F_4 ( V_37 & 0x07 , V_109 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 < 2 )
return;
F_3 ( V_4 , V_1 , V_2 , 2 , L_68 ,
F_7 ( V_1 , V_2 ) ) ;
V_2 += 2 ;
V_3 -= 2 ;
if ( V_3 < 2 )
return;
F_3 ( V_4 , V_1 , V_2 , 2 , L_69 ,
F_7 ( V_1 , V_2 ) ) ;
}
static void
F_25 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_11 ;
T_6 V_12 ;
while ( V_3 >= 3 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
V_12 = F_7 ( V_1 , V_2 + 1 ) ;
V_3 -= 3 ;
switch ( V_11 ) {
case 0x01 :
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_87 , V_12 ) ;
break;
case 0x03 :
if ( V_12 == 0xFFFF ) {
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_88 ) ;
} else {
F_3 ( V_4 , V_1 , V_2 , 3 ,
L_89 ,
V_12 ) ;
}
break;
default:
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_90 ,
V_11 ) ;
return;
}
}
}
static void
F_26 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_91 ,
F_4 ( V_37 , V_110 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_92 ,
F_4 ( V_37 , V_110 ,
L_4 ) ) ;
}
static void
F_27 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_93 ,
F_4 ( V_37 & 0x0F , V_111 ,
L_4 ) ) ;
}
static void
F_28 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_94 ,
F_4 ( V_37 & 0x07 , V_112 ,
L_4 ) ) ;
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
L_95 ) ;
V_2 += 1 ;
V_3 -= 1 ;
break;
default:
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_96 ,
V_11 ) ;
return;
}
}
}
static void
F_30 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_97 ,
F_4 ( V_37 & 0x70 , V_113 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_98 ,
F_4 ( V_37 & 0x0F , V_114 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
F_3 ( V_4 , V_1 , V_2 , V_3 ,
L_99 , V_3 , F_17 ( F_18 () , V_1 , V_2 , V_3 ) ) ;
}
static void
F_31 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_100 ,
F_4 ( V_37 & 0x60 , V_115 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_101 ,
( V_37 & 0x10 ) ? L_102 : L_103 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_104 ,
F_4 ( V_37 & 0x07 , V_116 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_105 ,
F_4 ( V_37 & 0x70 , V_117 ,
L_4 ) ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_106 ,
F_4 ( V_37 & 0x07 , V_118 ,
L_4 ) ) ;
}
static void
F_32 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
T_6 V_12 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_107 ,
F_4 ( V_37 , V_119 ,
L_4 ) ) ;
V_2 += 1 ;
V_3 -= 1 ;
if ( V_3 < 2 )
return;
V_12 = F_7 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_108 ,
( V_12 & 0x8000 ) ? L_109 :
L_110 ) ;
F_3 ( V_4 , V_1 , V_2 , 2 ,
L_111 ,
V_12 & 0x7FFF ) ;
}
static void
F_33 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 )
{
T_3 V_37 ;
if ( V_3 == 0 )
return;
V_37 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_4 , V_1 , V_2 , 1 ,
L_112 ,
F_4 ( V_37 & 0x3F , V_120 ,
L_4 ) ) ;
}
static void
F_34 ( T_1 * V_1 , int V_2 , int V_3 ,
T_2 * V_4 , T_3 V_5 )
{
switch ( V_5 ) {
case V_121 :
case V_8 :
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_122 :
case V_123 :
F_35 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_124 :
F_36 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_125 :
F_37 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_126 :
F_5 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_127 :
F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_128 :
F_11 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_129 :
F_12 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_130 :
F_13 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_131 :
F_19 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_132 :
case V_133 :
F_20 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_134 :
case V_135 :
F_23 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_136 :
F_15 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_137 :
F_24 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_138 :
F_25 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_139 :
F_26 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_140 :
F_27 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_141 :
F_28 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_142 :
F_29 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_143 :
F_30 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_144 :
F_31 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_145 :
F_32 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_146 :
F_33 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
}
}
static void
F_16 ( T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 ,
T_3 V_5 , T_3 V_69 )
{
T_7 * V_97 ;
T_2 * V_147 ;
T_2 * V_148 ;
V_97 = F_3 ( V_4 , V_1 , V_2 , 1 + 1 + 2 + V_3 , L_23 ,
F_4 ( V_5 , V_81 ,
L_113 ) ) ;
V_147 = F_21 ( V_97 , V_149 ) ;
F_3 ( V_147 , V_1 , V_2 , 1 , L_66 ,
F_4 ( V_5 , V_81 ,
L_4 ) ) ;
V_97 = F_3 ( V_147 , V_1 , V_2 + 1 , 1 ,
L_114 ,
V_69 ) ;
V_148 = F_21 ( V_97 , V_150 ) ;
F_38 ( V_148 , V_151 , V_1 , V_2 + 1 , 1 , V_152 ) ;
F_38 ( V_148 , V_153 , V_1 , V_2 + 1 , 1 , V_152 ) ;
if ( V_69 & V_154 ) {
F_38 ( V_148 , V_155 , V_1 , V_2 + 1 , 1 , V_152 ) ;
}
F_3 ( V_147 , V_1 , V_2 + 2 , 2 , L_115 , V_3 ) ;
if ( ( V_69 & V_156 )
== V_157 ) {
F_34 ( V_1 , V_2 + 4 ,
V_3 , V_147 , V_5 ) ;
} else {
F_3 ( V_147 , V_1 , V_2 + 4 , V_3 ,
L_116 , F_6 ( V_1 , V_2 + 4 , V_3 ) ) ;
}
}
static void
F_39 ( T_1 * V_1 , T_8 * V_158 , T_2 * V_4 )
{
int V_2 = 0 ;
T_2 * V_159 = NULL ;
T_7 * V_97 ;
T_2 * V_160 ;
T_3 V_161 ;
T_3 V_162 [ 15 ] ;
T_3 V_163 ;
T_3 V_164 ;
T_6 V_165 ;
T_3 V_5 ;
T_3 V_69 ;
T_6 V_70 ;
#if 0
int codeset;
gboolean non_locking_shift;
#endif
F_40 ( V_158 -> V_166 , V_167 , L_117 ) ;
if ( V_4 ) {
V_97 = F_38 ( V_4 , V_168 , V_1 , V_2 , - 1 ,
V_169 ) ;
V_159 = F_21 ( V_97 , V_170 ) ;
F_41 ( V_159 , V_171 , V_1 , V_2 , 1 , F_2 ( V_1 , V_2 ) ) ;
}
V_2 += 1 ;
V_161 = F_2 ( V_1 , V_2 ) & 0xF ;
if ( V_159 != NULL )
F_41 ( V_159 , V_172 , V_1 , V_2 , 1 , V_161 ) ;
V_2 += 1 ;
if ( V_161 != 0 ) {
F_42 ( V_1 , V_162 , V_2 , V_161 ) ;
if ( V_159 != NULL ) {
F_43 ( V_159 , V_173 ,
V_1 , V_2 , 1 , ( V_162 [ 0 ] & 0x80 ) != 0 ) ;
V_162 [ 0 ] &= 0x7F ;
F_44 ( V_159 , V_174 , V_1 , V_2 , V_161 , V_162 ) ;
}
V_2 += V_161 ;
}
V_163 = F_2 ( V_1 , V_2 ) ;
F_45 ( V_158 -> V_166 , V_175 ,
F_4 ( V_163 , V_93 ,
L_118 ) ) ;
if ( V_159 != NULL )
F_41 ( V_159 , V_176 , V_1 , V_2 , 1 , V_163 ) ;
V_2 += 1 ;
V_164 = F_2 ( V_1 , V_2 ) ;
if ( V_159 != NULL ) {
V_97 = F_41 ( V_159 , V_177 , V_1 ,
V_2 , 1 , V_164 ) ;
V_160 = F_21 ( V_97 , V_178 ) ;
F_43 ( V_160 , V_179 , V_1 ,
V_2 , 1 , V_164 ) ;
if ( V_164 & V_180 ) {
F_41 ( V_160 , V_181 , V_1 ,
V_2 , 1 , V_164 ) ;
}
}
V_2 += 1 ;
V_165 = F_7 ( V_1 , V_2 ) ;
if ( V_159 != NULL )
F_41 ( V_159 , V_182 , V_1 , V_2 , 2 , V_165 ) ;
V_2 += 2 ;
#if 0
codeset = 0;
non_locking_shift = TRUE;
#endif
while ( F_46 ( V_1 , V_2 ) > 0 ) {
V_5 = F_2 ( V_1 , V_2 ) ;
V_69 = F_2 ( V_1 , V_2 + 1 ) ;
V_70 = F_7 ( V_1 , V_2 + 2 ) ;
if ( V_159 != NULL ) {
F_16 ( V_1 , V_2 , V_70 ,
V_159 , V_5 , V_69 ) ;
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
V_2 += 1 + 1 + 2 + V_70 ;
}
}
void
F_47 ( void )
{
static T_9 V_183 [] = {
{ & V_171 ,
{ L_119 , L_120 , V_184 , V_185 , NULL , 0x0 ,
NULL , V_186 } } ,
{ & V_172 ,
{ L_121 , L_122 , V_184 , V_187 , NULL , 0x0 ,
NULL , V_186 } } ,
{ & V_173 ,
{ L_123 , L_124 , V_188 , V_189 , F_48 ( & V_190 ) , 0x0 ,
NULL , V_186 } } ,
{ & V_174 ,
{ L_125 , L_126 , V_191 , V_189 , NULL , 0x0 ,
NULL , V_186 } } ,
{ & V_176 ,
{ L_127 , L_128 , V_184 , V_185 , F_49 ( V_93 ) , 0x0 ,
NULL , V_186 } } ,
{ & V_177 ,
{ L_129 , L_130 , V_184 , V_185 , NULL , 0x0 ,
NULL , V_186 } } ,
{ & V_179 ,
{ L_131 , L_132 , V_188 , 8 , F_48 ( & V_192 ) , V_180 ,
NULL , V_186 } } ,
{ & V_181 ,
{ L_133 , L_134 , V_184 , V_187 , F_49 ( V_193 ) , V_194 ,
NULL , V_186 } } ,
{ & V_182 ,
{ L_135 , L_136 , V_195 , V_187 , NULL , 0x0 ,
NULL , V_186 } } ,
{ & V_153 ,
{ L_137 , L_138 , V_188 , 8 , F_48 ( & V_196 ) , V_154 ,
NULL , V_186 } } ,
{ & V_151 ,
{ L_139 , L_140 , V_184 , V_187 , F_49 ( V_197 ) , V_156 ,
NULL , V_186 } } ,
{ & V_155 ,
{ L_133 , L_141 , V_184 , V_187 , F_49 ( V_198 ) , V_199 ,
NULL , V_186 } } ,
} ;
static T_10 * V_200 [] = {
& V_170 ,
& V_178 ,
& V_149 ,
& V_150 ,
& V_105 ,
} ;
V_168 = F_50 ( L_117 , L_117 , L_142 ) ;
F_51 ( V_168 , V_183 , F_52 ( V_183 ) ) ;
F_53 ( V_200 , F_52 ( V_200 ) ) ;
F_54 ( L_142 , F_39 , V_168 ) ;
}
