T_1 *
F_1 ( T_1 * V_1 , T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_5 ,
T_4 V_6 , T_4 V_7 ,
T_4 V_8 ,
T_4 V_9 , T_4 V_10 ,
T_4 V_11 )
{
T_1 * V_12 ;
T_5 * V_13 = ( T_5 * ) F_2 ( V_14 ) ;
char string [ 2 ] ;
T_5 * V_15 ;
T_6 V_16 = 0 ;
T_7 V_17 = 0 ;
T_7 V_18 = 0 ;
T_7 V_19 ;
T_8 V_20 = 0 ;
T_7 V_21 ;
T_7 V_22 ;
T_8 V_23 = 0 ;
T_8 V_24 ;
T_8 V_25 = 0 ;
T_5 V_26 ;
T_8 V_27 ;
T_8 V_28 ;
T_8 V_29 ;
T_7 V_30 = 0 ;
T_8 V_31 ;
T_5 V_32 ;
T_5 V_33 ;
T_5 V_34 ;
T_7 V_35 ;
T_7 V_36 ;
T_7 V_37 ;
T_7 V_38 ;
T_7 V_39 ;
T_7 V_40 ;
T_8 V_41 = F_3 ( V_2 , 0 ) ;
T_7 V_42 = 0 ;
T_7 V_43 = 0 ;
T_7 V_44 = 0 ;
T_7 V_45 = 0 ;
T_5 V_46 = 0 ;
T_9 V_47 = TRUE ;
T_9 V_48 = FALSE ;
T_7 V_49 ;
T_5 V_50 = 0 ;
T_7 V_51 [ 5 ] ;
T_7 V_52 [ 5 ] ;
T_7 V_53 [ 5 ] ;
T_7 V_54 [ 5 ] ;
T_6 V_55 = 0 ;
T_8 V_56 ;
T_8 V_57 ;
T_5 * V_58 ;
unsigned char V_59 [ V_60 ] ;
T_10 V_61 ;
T_7 V_62 ;
T_7 V_63 ;
T_7 V_64 ;
T_7 V_65 ;
T_7 V_66 ;
T_7 V_67 ;
T_7 V_68 ;
T_7 V_69 ;
T_7 V_70 ;
T_7 V_71 ;
T_7 V_72 ;
T_7 V_73 ;
T_7 V_74 ;
T_7 V_75 ;
T_7 V_76 ;
T_7 V_77 ;
T_7 V_78 ;
T_7 V_79 ;
T_7 V_80 ;
T_7 V_81 ;
T_7 V_82 ;
T_7 V_83 ;
T_7 V_84 ;
T_7 V_85 ;
T_7 V_86 ;
T_7 V_87 ;
T_7 V_88 ;
T_7 V_89 ;
T_7 V_90 ;
T_7 V_91 ;
T_7 V_92 ;
T_7 V_93 ;
T_7 V_94 ;
V_95 = FALSE ;
V_96 = FALSE ;
V_97 = FALSE ;
V_98 = 0 ;
switch( V_6 ) {
case 0 :
break;
case 1 :
V_95 = TRUE ;
V_98 = 1 ;
break;
case 2 :
V_95 = TRUE ;
V_96 = TRUE ;
V_98 = 1 ;
break;
case 3 :
V_95 = TRUE ;
V_96 = TRUE ;
V_97 = TRUE ;
V_98 = 2 ;
break;
default:
V_95 = TRUE ;
V_98 = 1 ;
break;
}
V_13 [ 0 ] = ( V_14 >> 8 ) & 0x00FF ;
V_13 [ 1 ] = V_14 & 0x00FF ;
V_13 [ 2 ] = 0 ;
V_13 [ 3 ] = 16 ;
V_13 [ 4 ] = 0 ;
V_13 [ 5 ] = 1 ;
V_13 [ 6 ] = ( V_10 >> 8 ) & 0x00FF ;
V_13 [ 7 ] = V_10 & 0x00FF ;
V_13 [ 8 ] = ( V_9 >> 8 ) & 0x00FF ;
V_13 [ 9 ] = V_9 & 0x00FF ;
V_25 = F_3 ( V_1 , 0 ) ;
V_56 = V_13 [ 2 ] << 8 ;
V_56 = V_56 | V_13 [ 3 ] ;
V_57 = ( ( 8 * ( V_8 + V_41 ) ) + 1000 ) * V_56 ;
F_4 ( V_4 , V_1 , V_23 , 1 , L_1 , V_57 , V_41 , V_56 ) ;
F_4 ( V_4 , V_1 , V_23 , 1 , L_2 , V_41 , V_25 , V_57 ) ;
V_16 = V_5 ;
if ( V_97 )
F_4 ( V_4 , V_1 , V_23 , 1 , L_3 , V_16 ) ;
while ( V_25 > V_23 && V_16 < V_14 ) {
V_13 [ V_16 ] = F_5 ( V_1 , V_23 ) ;
if ( V_97 )
F_4 ( V_4 , V_1 , V_23 , 1 ,
L_4 , V_16 , V_13 [ V_16 ] ) ;
V_16 ++ ;
V_23 ++ ;
}
V_15 = ( T_5 * ) F_6 ( V_14 ) ;
V_27 = V_11 ;
V_29 = 0 ;
F_4 ( V_4 , V_1 , V_23 , 1 , L_5 ,
V_27 , V_41 ) ;
V_99:
if ( V_55 > V_57 ) {
V_42 = 15 ;
goto V_100;
}
V_55 ++ ;
V_26 = V_13 [ V_27 & 0xffff ] ;
switch ( V_26 ) {
case V_101 :
if ( V_42 == 0 )
V_42 = 9 ;
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_6 ,
V_27 ) ;
F_4 ( V_4 , V_1 , 0 , - 1 , L_7 ,
F_7 ( V_42 , V_102 , L_8 ) ) ;
if ( V_30 > 0 ) {
V_12 = F_8 ( V_2 , V_15 , V_30 , V_30 ) ;
F_9 ( V_12 , V_103 ) ;
F_10 ( V_3 , V_12 , L_9 ) ;
F_4 ( V_4 , V_12 , 0 , - 1 , L_10 ) ;
return V_12 ;
}
V_103 ( V_15 ) ;
return NULL ;
break;
case V_104 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_11 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_14 ,
V_27 , V_73 , V_74 ) ;
}
V_40 = V_73 & V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_105 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_16 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_17 ,
V_27 , V_73 , V_74 ) ;
}
V_40 = V_73 | V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_106 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_18 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_19 ,
V_27 , V_73 ) ;
}
V_40 = V_73 ^ 0xffff ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_107 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_20 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_21 ,
V_27 , V_73 , V_74 ) ;
}
V_40 = V_73 << V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_108 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_22 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_23 ,
V_27 , V_73 , V_74 ) ;
}
V_40 = V_73 >> V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_109 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_24 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_25 ,
V_27 , V_73 , V_74 ) ;
}
V_40 = V_73 + V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_26 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
case V_110 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_27 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_28 ,
V_27 , V_73 , V_74 ) ;
}
V_40 = V_73 - V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_26 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_111 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_29 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_30 ,
V_27 , V_73 , V_74 ) ;
}
if ( V_74 == 0 ) {
V_42 = 4 ;
goto V_100;
}
V_40 = V_73 * V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_112 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_31 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_32 ,
V_27 , V_73 , V_74 ) ;
}
if ( V_74 == 0 ) {
V_42 = 4 ;
goto V_100;
}
V_40 = V_73 / V_74 ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_113 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_33 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_11 ( V_13 , V_28 , & V_73 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_12 ,
V_28 , V_73 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_74 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_13 ,
V_28 , V_74 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_34 ,
V_27 , V_73 , V_74 ) ;
}
if ( V_74 == 0 ) {
V_42 = 4 ;
goto V_100;
}
V_40 = V_73 - V_74 * ( V_73 / V_74 ) ;
V_34 = V_40 & 0xff ;
V_33 = V_40 >> 8 ;
V_13 [ V_24 ] = V_33 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_15 ,
V_40 , V_24 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_114 :
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_35 ,
V_27 ) ;
}
F_4 ( V_4 , V_1 , 0 , - 1 , L_36 ) ;
break;
case V_115 :
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_37 ,
V_27 ) ;
}
F_4 ( V_4 , V_1 , 0 , - 1 , L_36 ) ;
break;
case V_116 :
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_38 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_85 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_39 ,
V_28 , V_85 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_40 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_11 ( V_13 , V_28 , & V_86 , & V_24 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_41 ,
V_28 , V_86 ) ;
}
V_55 = V_55 + V_62 ;
V_17 = 0 ;
V_20 = V_85 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , 0 , - 1 ,
L_42 , V_35 ) ;
}
F_13 ( & V_61 ) ;
while ( V_17 < V_62 ) {
T_7 V_117 = V_62 ;
if ( V_20 < V_35 && V_35 <= V_20 + ( V_62 - V_17 ) ) {
V_117 = V_35 - V_85 ;
}
if ( V_20 + V_117 >= V_14 )
goto V_100;
F_14 ( & V_61 , & V_13 [ V_20 ] , V_117 ) ;
V_20 = ( V_20 + V_117 ) & 0xffff ;
V_17 = ( V_17 + V_117 ) & 0xffff ;
if ( V_20 >= V_35 ) {
V_20 = V_36 ;
}
}
F_15 ( & V_61 , V_59 ) ;
V_20 = V_86 ;
for ( V_17 = 0 ; V_17 < V_60 ; V_17 ++ ) {
V_13 [ V_20 ] = V_59 [ V_17 ] ;
V_20 = ( V_20 + 1 ) & 0xffff ;
V_17 ++ ;
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
}
if ( V_96 ) {
F_4 ( V_4 , V_2 , 0 , - 1 ,
L_43 ,
F_16 ( V_59 , V_60 ) ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_118 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_44 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_65 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_45 ,
V_28 , V_65 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_66 ) ;
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_46 ,
V_27 , V_65 , V_66 ) ;
}
V_34 = V_66 & 0xff ;
V_33 = V_66 >> 8 ;
V_13 [ V_65 ] = V_33 ;
V_13 [ ( V_65 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_47 ,
V_28 , V_66 ) ;
F_4 ( V_4 , V_1 , 0 , - 1 , L_48 ,
V_65 , V_66 , V_66 ) ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_119 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_49 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_65 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_45 ,
V_28 , V_65 ) ;
}
V_28 = V_31 ;
V_31 = F_17 ( V_13 , V_28 , & V_17 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_50 ,
V_28 , V_17 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_51 ,
V_27 , V_65 , V_17 , V_17 - 1 ) ;
}
V_28 = V_31 ;
V_55 = V_55 + V_17 ;
while ( V_17 > 0 ) {
V_17 = V_17 - 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_66 ) ;
V_34 = V_66 & 0xff ;
V_33 = V_66 >> 8 ;
if ( V_65 >= V_14 - 1 )
goto V_100;
V_13 [ V_65 ] = V_33 ;
V_13 [ ( V_65 + 1 ) & 0xffff ] = V_34 ;
V_62 = V_31 - V_28 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_52 ,
V_28 , V_66 , V_65 , V_66 , V_66 ) ;
}
V_65 = V_65 + 2 ;
V_28 = V_31 ;
}
V_27 = V_31 ;
goto V_99;
break;
case V_120 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_53 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_66 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_47 ,
V_28 , V_66 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_54 ,
V_27 , V_66 ) ;
}
V_27 = V_31 ;
V_38 = ( V_13 [ 70 ] << 8 ) | V_13 [ 71 ] ;
V_39 = ( V_13 [ V_38 ] << 8 )
| V_13 [ ( V_38 + 1 ) & 0xFFFF ] ;
V_65 = ( V_38 + V_39 * 2 + 2 ) & 0xFFFF ;
if ( V_65 >= V_14 - 1 )
goto V_100;
V_13 [ V_65 ] = ( V_66 >> 8 ) & 0x00FF ;
V_13 [ ( V_65 + 1 ) & 0xFFFF ] = V_66 & 0x00FF ;
if ( V_38 >= V_14 - 1 )
goto V_100;
V_39 = ( V_39 + 1 ) & 0xFFFF ;
V_13 [ V_38 ] = ( V_39 >> 8 ) & 0x00FF ;
V_13 [ ( V_38 + 1 ) & 0xFFFF ] = V_39 & 0x00FF ;
goto V_99;
break;
case V_121 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_55 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_64 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_47 ,
V_28 , V_64 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_56 ,
V_27 , V_64 ) ;
}
V_27 = V_31 ;
V_38 = ( V_13 [ 70 ] << 8 ) | V_13 [ 71 ] ;
V_39 = ( V_13 [ V_38 ] << 8 )
| V_13 [ ( V_38 + 1 ) & 0xFFFF ] ;
if ( V_39 == 0 )
{
V_42 = 16 ;
goto V_100;
}
if ( V_38 >= V_14 - 1 )
goto V_100;
V_39 = ( V_39 - 1 ) & 0xFFFF ;
V_13 [ V_38 ] = ( V_39 >> 8 ) & 0x00FF ;
V_13 [ ( V_38 + 1 ) & 0xFFFF ] = V_39 & 0x00FF ;
V_65 = ( V_38 + V_39 * 2 + 2 ) & 0xFFFF ;
if ( V_65 >= V_14 - 1 )
goto V_100;
V_66 = ( V_13 [ V_65 ] << 8 )
| V_13 [ ( V_65 + 1 ) & 0xFFFF ] ;
if ( V_64 >= V_14 - 1 )
goto V_100;
V_13 [ V_64 ] = ( V_66 >> 8 ) & 0x00FF ;
V_13 [ ( V_64 + 1 ) & 0xFFFF ] = V_66 & 0x00FF ;
goto V_99;
break;
case V_122 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_57 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_85 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_39 ,
V_28 , V_85 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_40 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_64 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_58 ,
V_28 , V_64 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_59 ,
V_27 , V_85 , V_62 , V_64 ) ;
}
V_27 = V_31 ;
V_17 = 0 ;
V_20 = V_64 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_60 , V_35 ) ;
}
while ( V_17 < V_62 ) {
V_13 [ V_20 ] = V_13 [ V_85 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_61 ,
V_13 [ V_85 ] , V_13 [ V_85 ] , V_20 ) ;
}
V_85 = ( V_85 + 1 ) & 0xffff ;
V_20 = ( V_20 + 1 ) & 0xffff ;
V_17 ++ ;
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
if ( V_85 == V_35 ) {
V_85 = V_36 ;
}
}
V_55 = V_55 + V_62 ;
goto V_99;
break;
case V_123 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_62 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_85 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_39 ,
V_28 , V_85 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_40 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_11 ( V_13 , V_28 , & V_86 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_63 ,
V_28 , V_86 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_64 ,
V_27 , V_85 , V_62 , V_86 ) ;
}
V_27 = V_31 ;
V_17 = 0 ;
V_20 = V_86 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_60 , V_35 ) ;
}
while ( V_17 < V_62 ) {
V_13 [ V_20 ] = V_13 [ V_85 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_61 ,
V_13 [ V_85 ] , V_13 [ V_85 ] , V_20 ) ;
}
V_85 = ( V_85 + 1 ) & 0xffff ;
V_20 = ( V_20 + 1 ) & 0xffff ;
V_17 ++ ;
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
if ( V_85 == V_35 ) {
V_85 = V_36 ;
}
}
V_13 [ V_24 ] = V_20 >> 8 ;
V_13 [ ( V_24 + 1 ) & 0xffff ] = V_20 & 0x00ff ;
V_55 = V_55 + V_62 ;
goto V_99;
break;
case V_124 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_65 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_87 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_66 ,
V_28 , V_87 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_40 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_11 ( V_13 , V_28 , & V_86 , & V_24 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_41 ,
V_28 , V_86 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_67 ,
V_27 , V_87 , V_62 , V_24 ) ;
}
V_27 = V_31 ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
for ( V_85 = V_86 , V_16 = 0 ; V_16 < V_87 ; V_16 ++ )
{
if ( V_85 == V_36 )
{
V_85 = ( V_35 - 1 ) & 0xffff ;
}
else
{
V_85 = ( V_85 - 1 ) & 0xffff ;
}
}
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_68 ,
V_36 , V_35 , V_85 ) ;
}
V_17 = 0 ;
V_20 = V_86 ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_69 , V_36 , V_35 ) ;
}
while ( V_17 < V_62 ) {
V_13 [ V_20 ] = V_13 [ V_85 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_70 ,
V_13 [ V_85 ] , V_13 [ V_85 ] , ( V_85 ) , V_20 ) ;
}
V_17 ++ ;
V_20 = ( V_20 + 1 ) & 0xffff ;
V_85 = ( V_85 + 1 ) & 0xffff ;
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
if ( V_85 == V_35 ) {
V_85 = V_36 ;
}
}
V_13 [ V_24 ] = V_20 >> 8 ;
V_13 [ V_24 + 1 ] = V_20 & 0x00ff ;
V_55 = V_55 + V_62 ;
goto V_99;
break;
case V_125 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_71 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_65 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_45 ,
V_28 , V_65 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_40 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_94 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_72 ,
V_28 , V_94 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_87 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_66 ,
V_28 , V_87 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_73 ,
V_27 , V_65 , V_62 , V_94 , V_87 ) ;
}
V_27 = V_31 ;
V_17 = 0 ;
V_20 = V_65 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_69 , V_36 , V_35 ) ;
}
while ( V_17 < V_62 ) {
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
V_13 [ V_20 ] = ( V_94 + ( V_17 * V_87 ) ) & 0xff ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_74 ,
V_13 [ V_20 ] , V_13 [ V_20 ] , V_20 ) ;
}
V_20 = ( V_20 + 1 ) & 0xffff ;
V_17 ++ ;
}
V_55 = V_55 + V_62 ;
goto V_99;
break;
case V_126 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_75 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
F_18 ( V_13 , V_28 , & V_63 , V_27 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_63 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_77 ,
V_27 , V_63 ) ;
}
V_27 = V_63 ;
goto V_99;
break;
case V_127 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_78 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_75 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_47 ,
V_28 , V_75 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_76 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_47 ,
V_28 , V_76 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_77 ) ;
V_77 = ( V_27 + V_77 ) & 0xffff ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_77 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_78 ) ;
V_78 = ( V_27 + V_78 ) & 0xffff ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_78 ) ;
}
V_28 = V_31 ;
F_12 ( V_13 , V_28 , & V_79 ) ;
V_79 = ( V_27 + V_79 ) & 0xffff ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_79 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_79 ,
V_27 , V_75 , V_76 , V_77 , V_78 , V_79 ) ;
}
if ( V_75 < V_76 )
V_27 = V_77 ;
if ( V_75 == V_76 )
V_27 = V_78 ;
if ( V_75 > V_76 )
V_27 = V_79 ;
goto V_99;
break;
case V_128 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_80 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_18 ( V_13 , V_28 , & V_63 , V_27 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_63 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_81 ,
V_27 , V_63 ) ;
}
V_27 = V_31 ;
V_38 = ( V_13 [ 70 ] << 8 ) | V_13 [ 71 ] ;
V_39 = ( V_13 [ V_38 ] << 8 )
| V_13 [ ( V_38 + 1 ) & 0xFFFF ] ;
V_65 = ( V_38 + V_39 * 2 + 2 ) & 0xFFFF ;
if ( V_65 >= V_14 - 1 )
goto V_100;
V_13 [ V_65 ] = ( V_27 >> 8 ) & 0x00FF ;
V_13 [ ( V_65 + 1 ) & 0xFFFF ] = V_27 & 0x00FF ;
V_39 = ( V_39 + 1 ) & 0xFFFF ;
if ( V_38 >= V_14 - 1 )
goto V_100;
V_13 [ V_38 ] = ( V_39 >> 8 ) & 0x00FF ;
V_13 [ ( V_38 + 1 ) & 0xFFFF ] = V_39 & 0x00FF ;
V_27 = V_63 ;
goto V_99;
break;
case V_129 :
if ( V_95 || V_98 == 1 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_82 ,
V_27 ) ;
}
V_38 = ( V_13 [ 70 ] << 8 ) | V_13 [ 71 ] ;
V_39 = ( V_13 [ V_38 ] << 8 )
| V_13 [ ( V_38 + 1 ) & 0xFFFF ] ;
if ( V_39 == 0 )
{
V_42 = 16 ;
goto V_100;
}
V_39 = ( V_39 - 1 ) & 0xFFFF ;
if ( V_38 >= V_14 - 1 )
goto V_100;
V_13 [ V_38 ] = ( V_39 >> 8 ) & 0x00FF ;
V_13 [ ( V_38 + 1 ) & 0xFFFF ] = V_39 & 0x00FF ;
V_65 = ( V_38 + V_39 * 2 + 2 ) & 0xFFFF ;
V_63 = ( V_13 [ V_65 ] << 8 )
| V_13 [ ( V_65 + 1 ) & 0xFFFF ] ;
V_27 = V_63 ;
goto V_99;
break;
case V_130 :
V_49 = V_27 ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_83 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_17 ( V_13 , V_28 , & V_17 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_50 ,
V_28 , V_17 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_80 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_84 ,
V_28 , V_80 ) ;
}
V_28 = V_31 ;
V_18 = 0 ;
while ( V_18 < V_17 ) {
V_31 = F_12 ( V_13 , V_28 , & V_77 ) ;
V_77 = ( V_49 + V_77 ) & 0xffff ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_77 ) ;
}
if ( V_80 == V_18 ) {
V_27 = V_77 ;
}
V_28 = V_31 ;
V_18 ++ ;
}
if ( ( V_80 == V_17 ) || ( V_80 > V_17 ) ) {
V_42 = 5 ;
goto V_100;
}
if ( V_27 > V_14 ) {
V_42 = 6 ;
goto V_100;
}
V_55 = V_55 + V_17 ;
goto V_99;
break;
case V_131 :
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_85 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_66 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_47 ,
V_28 , V_66 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_85 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_39 ,
V_28 , V_85 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_40 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_63 ) ;
V_63 = ( V_27 + V_63 ) & 0xffff ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_63 ) ;
}
V_55 = V_55 + V_62 ;
V_17 = 0 ;
V_20 = V_85 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
V_40 = 0 ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , 0 , - 1 ,
L_42 , V_35 ) ;
}
while ( V_17 < V_62 ) {
T_7 V_117 = V_62 - V_17 ;
if ( V_20 < V_35 && V_35 <= V_20 + ( V_62 - V_17 ) ) {
V_117 = V_35 - V_20 ;
}
if ( V_20 + V_117 >= V_14 )
goto V_100;
V_40 = F_19 ( & V_13 [ V_20 ] , V_117 , ( T_7 ) ( V_40 ^ 0xffff ) ) ;
V_20 = ( V_20 + V_117 ) & 0xffff ;
V_17 = ( V_17 + V_117 ) & 0xffff ;
if ( V_20 >= V_35 ) {
V_20 = V_36 ;
}
}
V_40 = V_40 ^ 0xffff ;
if ( V_95 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_86 , V_40 ) ;
}
if ( V_40 != V_66 ) {
V_27 = V_63 ;
}
else {
V_27 = V_31 ;
}
goto V_99;
break;
case V_132 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_87 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_40 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_64 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_58 ,
V_28 , V_64 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_63 ) ;
V_63 = ( V_27 + V_63 ) & 0xffff ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_63 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_88 ,
V_27 , V_62 , V_64 , V_63 ) ;
}
V_17 = 0 ;
V_20 = V_64 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
if ( V_95 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_60 , V_35 ) ;
}
V_44 = 0 ;
V_45 = 0 ;
while ( V_17 < V_62 ) {
if ( V_29 > ( V_41 - 1 ) ) {
V_27 = V_63 ;
V_42 = 14 ;
goto V_99;
}
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
V_32 = F_5 ( V_2 , V_29 ) ;
V_13 [ V_20 ] = V_32 ;
if ( V_95 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_89 , V_32 , V_32 , V_20 ) ;
}
V_29 ++ ;
V_20 = ( V_20 + 1 ) & 0xffff ;
V_17 ++ ;
}
V_55 = V_55 + V_62 ;
V_27 = V_31 ;
goto V_99;
break;
case V_133 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_90 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_62 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_91 ,
V_28 , V_62 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_64 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_58 ,
V_28 , V_64 ) ;
}
V_28 = V_31 ;
V_31 = F_18 ( V_13 , V_28 , & V_63 , V_27 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_63 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_92 ,
V_27 , V_62 , V_64 , V_63 ) ;
}
V_27 = V_31 ;
V_37 = V_13 [ 68 ] << 8 ;
V_37 = V_37 | V_13 [ 69 ] ;
if ( V_62 > 16 ) {
V_42 = 7 ;
goto V_100;
}
if ( V_37 > 7 ) {
V_42 = 8 ;
goto V_100;
}
V_46 = ( V_37 & 0x0004 ) >> 2 ;
V_66 = F_20 ( V_2 , V_4 , V_46 ,
V_13 , & V_43 , & V_44 ,
& V_45 , & V_29 , V_62 , & V_42 , V_41 ) ;
if ( V_42 == 11 ) {
V_27 = V_63 ;
goto V_99;
}
V_33 = V_66 >> 8 ;
V_34 = V_66 & 0x00ff ;
if ( V_64 >= V_14 - 1 )
goto V_100;
V_13 [ V_64 ] = V_33 ;
V_13 [ ( V_64 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_93 , V_66 , V_66 , V_64 , V_44 ) ;
}
goto V_99;
break;
case V_134 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_94 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_64 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_58 ,
V_28 , V_64 ) ;
}
V_28 = V_31 ;
V_31 = F_18 ( V_13 , V_28 , & V_63 , V_27 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_76 ,
V_28 , V_63 ) ;
}
V_28 = V_31 ;
V_31 = F_17 ( V_13 , V_28 , & V_17 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_50 ,
V_28 , V_17 ) ;
}
V_28 = V_31 ;
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_95 ,
V_27 , V_64 , V_63 , V_17 , V_17 , V_17 , V_17 , V_17 ) ;
}
V_55 = V_55 + V_17 ;
V_37 = V_13 [ 68 ] << 8 ;
V_37 = V_37 | V_13 [ 69 ] ;
V_46 = ( V_37 & 0x0002 ) >> 1 ;
V_80 = 1 ;
V_21 = 0 ;
V_18 = V_17 ;
V_47 = TRUE ;
V_48 = V_97 ;
while ( V_18 > 0 ) {
V_31 = F_12 ( V_13 , V_28 , & V_81 ) ;
if ( V_48 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_96 ,
V_28 , V_81 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_82 ) ;
if ( V_48 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_97 ,
V_28 , V_82 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_83 ) ;
if ( V_48 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_98 ,
V_28 , V_83 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_84 ) ;
if ( V_48 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_99 ,
V_28 , V_84 ) ;
}
V_28 = V_31 ;
if ( V_47 ) {
V_20 = F_20 ( V_2 , V_4 , V_46 ,
V_13 , & V_43 , & V_44 ,
& V_45 , & V_29 , V_81 , & V_42 , V_41 ) ;
if ( V_42 == 11 ) {
V_27 = V_63 ;
goto V_99;
}
V_22 = V_21 ;
V_21 = ( V_21 << V_81 ) | V_20 ;
if ( V_97 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_100 ,
V_21 , V_22 , 1 << V_81 , V_20 ) ;
}
if ( ( V_21 < V_82 ) || ( V_21 > V_83 ) ) {
V_47 = TRUE ;
} else{
V_47 = FALSE ;
V_48 = FALSE ;
if ( V_96 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_101 ,
( V_21 + V_84 - V_82 ) , V_21 , V_84 , V_82 ) ;
}
V_21 = V_21 + V_84 - V_82 ;
V_33 = V_21 >> 8 ;
V_34 = V_21 & 0x00ff ;
if ( V_64 >= V_14 - 1 )
goto V_100;
V_13 [ V_64 ] = V_33 ;
V_13 [ ( V_64 + 1 ) & 0xffff ] = V_34 ;
if ( V_95 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_102 ,
V_21 , V_21 , V_64 , ( V_17 - V_18 + 1 ) , V_44 ) ;
}
}
}
V_18 = V_18 - 1 ;
}
if ( V_47 ) {
V_42 = 10 ;
goto V_100;
}
V_27 = V_31 ;
goto V_99;
break;
case V_135 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_103 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_67 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_104 ,
V_28 , V_67 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_68 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_105 ,
V_28 , V_68 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_69 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_106 ,
V_28 , V_69 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_70 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_107 ,
V_28 , V_70 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_71 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_108 ,
V_28 , V_71 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_72 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_109 ,
V_28 , V_72 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_110 ,
V_27 , V_67 , V_68 , V_69 , V_70 , V_71 , V_72 ) ;
}
V_27 = V_31 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
if ( V_96 ) {
F_4 ( V_4 , V_2 , V_29 , 1 ,
L_111 , V_35 , V_36 ) ;
}
V_42 = F_21 ( V_2 , V_4 , V_13 , V_67 , V_68 , V_69 , & V_70 ,
& V_71 , & V_72 , V_7 ) ;
if ( V_42 != 0 ) {
goto V_100;
}
V_55 = V_55 + V_70 ;
goto V_99;
break;
case V_136 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_112 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_70 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_107 ,
V_28 , V_70 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_71 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_108 ,
V_28 , V_71 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_72 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_109 ,
V_28 , V_72 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_90 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_113 ,
V_28 , V_90 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_91 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_114 ,
V_28 , V_91 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_115 ,
V_27 , V_70 , V_71 , V_72 , V_90 , V_91 ) ;
}
V_27 = V_31 ;
V_50 ++ ;
if ( V_50 > 4 ) {
V_42 = 12 ;
goto V_100;
}
if ( ( V_90 < 6 ) || ( V_90 > V_60 ) ) {
V_42 = 1 ;
goto V_100;
}
if ( V_91 == 65535 ) {
V_42 = 13 ;
goto V_100;
}
V_51 [ V_50 ] = V_70 ;
V_52 [ V_50 ] = V_71 ;
V_53 [ V_50 ] = V_72 ;
V_54 [ V_50 ] = V_90 ;
V_55 = V_55 + V_70 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
V_17 = 0 ;
V_20 = V_71 ;
while ( V_17 < V_70 ) {
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
string [ 0 ] = V_13 [ V_20 ] ;
string [ 1 ] = '\0' ;
if ( V_97 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_116 ,
V_20 , V_13 [ V_20 ] , V_13 [ V_20 ] , F_22 ( string , 1 ) ) ;
}
V_20 = ( V_20 + 1 ) & 0xffff ;
V_17 ++ ;
}
goto V_99;
break;
case V_137 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_117 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_67 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_104 ,
V_28 , V_67 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_68 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_105 ,
V_28 , V_68 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_118 ,
V_27 , V_67 , V_68 ) ;
}
V_27 = V_31 ;
F_23 ( V_13 , V_67 , V_68 ) ;
goto V_99;
break;
case V_138 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_119 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_88 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_120 ,
V_28 , V_88 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_89 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_121 ,
V_28 , V_89 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_122 ,
V_27 , V_88 , V_89 ) ;
}
V_27 = V_31 ;
V_17 = 0 ;
V_20 = V_88 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
if ( V_97 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_60 , V_35 ) ;
}
while ( V_17 < V_89 ) {
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
V_15 [ V_30 ] = V_13 [ V_20 ] ;
string [ 0 ] = V_13 [ V_20 ] ;
string [ 1 ] = '\0' ;
if ( V_97 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_123 ,
V_13 [ V_20 ] , V_13 [ V_20 ] , F_22 ( string , 1 ) , V_20 , V_30 ) ;
}
V_20 = ( V_20 + 1 ) & 0xffff ;
V_30 ++ ;
V_17 ++ ;
}
V_55 = V_55 + V_89 ;
goto V_99;
break;
case V_139 :
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_124 ,
V_27 ) ;
}
V_28 = V_27 + 1 ;
V_31 = F_12 ( V_13 , V_28 , & V_92 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_125 ,
V_28 , V_92 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_93 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_126 ,
V_28 , V_93 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_70 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_127 ,
V_28 , V_70 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_71 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_128 ,
V_28 , V_71 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_72 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_129 ,
V_28 , V_72 ) ;
}
V_28 = V_31 ;
V_31 = F_12 ( V_13 , V_28 , & V_90 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_130 ,
V_28 , V_90 ) ;
}
V_28 = V_31 ;
F_12 ( V_13 , V_28 , & V_91 ) ;
if ( V_98 == 2 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_131 ,
V_28 , V_91 ) ;
}
if ( V_98 == 1 )
{
F_4 ( V_4 , V_1 , 0 , - 1 ,
L_132 ,
V_27 , V_92 , V_93 , V_70 , V_71 , V_72 , V_90 , V_91 ) ;
}
V_50 ++ ;
if ( V_50 > 4 ) {
V_42 = 12 ;
goto V_100;
}
V_51 [ V_50 ] = V_70 ;
V_52 [ V_50 ] = V_71 ;
V_53 [ V_50 ] = V_72 ;
V_54 [ V_50 ] = V_90 ;
F_4 ( V_4 , V_1 , 0 , - 1 , L_133 , V_50 ) ;
if ( V_50 != 0 ) {
memset ( V_59 , 0 , V_60 ) ;
V_17 = 1 ;
V_35 = V_13 [ 66 ] << 8 ;
V_35 = V_35 | V_13 [ 67 ] ;
V_36 = V_13 [ 64 ] << 8 ;
V_36 = V_36 | V_13 [ 65 ] ;
while ( V_17 < V_50 + 1 ) {
V_58 = ( T_5 * ) F_6 ( V_51 [ V_17 ] + 8 ) ;
V_58 [ 0 ] = V_51 [ V_17 ] >> 8 ;
V_58 [ 1 ] = V_51 [ V_17 ] & 0xff ;
V_58 [ 2 ] = V_52 [ V_17 ] >> 8 ;
V_58 [ 3 ] = V_52 [ V_17 ] & 0xff ;
V_58 [ 4 ] = V_53 [ V_17 ] >> 8 ;
V_58 [ 5 ] = V_53 [ V_17 ] & 0xff ;
V_58 [ 6 ] = V_54 [ V_17 ] >> 8 ;
V_58 [ 7 ] = V_54 [ V_17 ] & 0xff ;
if ( V_97 ) {
for( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_134 ,
V_19 , V_58 [ V_19 ] ) ;
}
}
V_20 = V_52 [ V_17 ] ;
for( V_19 = 0 ; V_19 < V_51 [ V_17 ] ; V_19 ++ )
{
if ( V_20 == V_35 ) {
V_20 = V_36 ;
}
V_58 [ 8 + V_19 ] = V_13 [ V_20 ] ;
V_20 = ( V_20 + 1 ) & 0xffff ;
}
F_13 ( & V_61 ) ;
F_14 ( & V_61 , ( T_5 * ) V_58 , V_51 [ V_17 ] + 8 ) ;
F_15 ( & V_61 , V_59 ) ;
if ( V_97 ) {
F_4 ( V_4 , V_1 , 0 , - 1 , L_135 , F_16 ( V_59 , V_60 ) ) ;
}
#if 0
udvm_state_create(sha1buff, sha1_digest_buf, state_minimum_access_length_buff[n]);
#endif
F_24 ( V_58 , V_59 , V_140 ) ;
F_4 ( V_4 , V_1 , 0 , - 1 , L_136 ) ;
F_25 ( V_4 , V_7 , V_1 , 0 , 0 , F_16 ( V_59 , V_54 [ V_17 ] ) ) ;
V_17 ++ ;
}
}
V_12 = F_8 ( V_2 , V_15 , V_30 , V_30 ) ;
F_9 ( V_12 , V_103 ) ;
F_10 ( V_3 , V_12 , L_137 ) ;
V_55 = V_55 + V_70 ;
F_4 ( V_4 , V_1 , 0 , - 1 , L_138 ,
V_57 , V_55 ) ;
return V_12 ;
break;
default:
F_4 ( V_4 , V_1 , 0 , - 1 , L_139 ,
V_27 , V_26 , V_26 ) ;
break;
}
V_103 ( V_15 ) ;
return NULL ;
V_100:
F_4 ( V_4 , V_1 , 0 , - 1 , L_140 ,
F_7 ( V_42 , V_102 , L_8 ) ) ;
F_26 ( V_141 ) ;
V_103 ( V_15 ) ;
return NULL ;
}
static int
F_17 ( T_5 * V_13 , T_8 V_28 , T_7 * V_66 )
{
T_8 V_142 ;
T_7 V_143 ;
T_8 V_144 ;
T_8 V_23 = V_28 ;
T_5 V_145 ;
V_142 = V_13 [ V_28 ] ;
V_144 = V_142 >> 7 ;
if ( V_144 == 1 ) {
V_144 = V_142 >> 6 ;
if ( V_144 == 2 ) {
V_145 = V_13 [ V_28 ] & 0x1f ;
V_143 = V_145 << 8 ;
V_145 = V_13 [ ( V_28 + 1 ) & 0xffff ] ;
V_143 = V_143 | V_145 ;
* V_66 = V_143 ;
V_23 = V_23 + 2 ;
} else{
V_23 ++ ;
V_145 = V_13 [ V_28 ] & 0x1f ;
V_143 = V_145 << 8 ;
V_145 = V_13 [ ( V_28 + 1 ) & 0xffff ] ;
V_143 = V_143 | V_145 ;
* V_66 = V_143 ;
V_23 = V_23 + 2 ;
}
} else{
V_143 = ( V_142 & 0x7f ) ;
* V_66 = V_143 ;
V_23 ++ ;
}
return V_23 ;
}
static int
F_11 ( T_5 * V_13 , T_8 V_28 , T_7 * V_66 , T_8 * V_24 )
{
T_8 V_142 ;
T_7 V_143 ;
T_8 V_23 = V_28 ;
T_8 V_144 ;
T_5 V_145 ;
T_7 V_146 ;
V_142 = V_13 [ V_28 ] ;
V_144 = V_142 >> 7 ;
if ( V_144 == 1 ) {
V_144 = V_142 >> 6 ;
if ( V_144 == 2 ) {
V_145 = V_13 [ V_28 ] & 0x3f ;
V_143 = V_145 << 8 ;
V_145 = V_13 [ ( V_28 + 1 ) & 0xffff ] ;
V_143 = V_143 | V_145 ;
V_143 = ( V_143 * 2 ) ;
* V_24 = V_143 ;
V_146 = V_13 [ V_143 ] << 8 ;
V_146 = V_146 | V_13 [ ( V_143 + 1 ) & 0xffff ] ;
* V_66 = V_146 ;
V_23 = V_23 + 2 ;
} else{
V_28 ++ ;
V_143 = V_13 [ V_28 ] << 8 ;
V_143 = V_143 | V_13 [ ( V_28 + 1 ) & 0xffff ] ;
* V_24 = V_143 ;
V_146 = V_13 [ V_143 ] << 8 ;
V_146 = V_146 | V_13 [ ( V_143 + 1 ) & 0xffff ] ;
* V_66 = V_146 ;
V_23 = V_23 + 3 ;
}
} else{
V_143 = ( V_142 & 0x7f ) ;
V_143 = ( V_143 * 2 ) ;
* V_24 = V_143 ;
V_146 = V_13 [ V_143 ] << 8 ;
V_146 = V_146 | V_13 [ ( V_143 + 1 ) & 0xffff ] ;
* V_66 = V_146 ;
V_23 ++ ;
}
if ( V_23 >= V_14 || * V_24 >= V_14 - 1 )
F_26 ( V_141 ) ;
return V_23 ;
}
static int
F_12 ( T_5 * V_13 , T_8 V_28 , T_7 * V_66 )
{
T_8 V_144 ;
T_8 V_142 ;
T_8 V_23 = V_28 ;
T_7 V_143 ;
T_6 V_40 ;
T_5 V_145 ;
T_7 V_146 ;
T_7 V_147 = 0 ;
* V_66 = 0 ;
V_142 = V_13 [ V_28 ] ;
V_144 = ( V_142 & 0xc0 ) >> 6 ;
switch ( V_144 ) {
case 0 :
V_143 = V_13 [ V_28 ] ;
* V_66 = V_143 ;
V_23 ++ ;
break;
case 1 :
V_147 = ( V_142 & 0x3f ) * 2 ;
V_146 = V_13 [ V_147 ] << 8 ;
V_146 = V_146 | V_13 [ ( V_147 + 1 ) & 0xffff ] ;
* V_66 = V_146 ;
V_23 ++ ;
break;
case 2 :
V_144 = ( V_142 & 0xe0 ) >> 5 ;
if ( V_144 == 5 ) {
V_145 = V_13 [ V_28 ] & 0x1f ;
V_143 = V_145 << 8 ;
V_145 = V_13 [ ( V_28 + 1 ) & 0xffff ] ;
V_143 = V_143 | V_145 ;
* V_66 = V_143 ;
V_23 = V_23 + 2 ;
} else{
V_144 = ( V_142 & 0xf0 ) >> 4 ;
if ( V_144 == 9 ) {
V_145 = V_13 [ V_28 ] & 0x0f ;
V_143 = V_145 << 8 ;
V_145 = V_13 [ ( V_28 + 1 ) & 0xffff ] ;
V_143 = V_143 | V_145 ;
V_143 = V_143 + 61440 ;
* V_66 = V_143 ;
V_23 = V_23 + 2 ;
} else{
V_144 = ( V_142 & 0x08 ) >> 3 ;
if ( V_144 == 1 ) {
V_40 = 1 << ( ( V_13 [ V_28 ] & 0x07 ) + 8 ) ;
V_143 = V_40 & 0xffff ;
* V_66 = V_143 ;
V_23 ++ ;
} else{
V_144 = ( V_142 & 0x0e ) >> 1 ;
if ( V_144 == 3 ) {
V_40 = 1 << ( ( V_13 [ V_28 ] & 0x01 ) + 6 ) ;
V_143 = V_40 & 0xffff ;
* V_66 = V_143 ;
V_23 ++ ;
} else{
V_23 ++ ;
V_146 = V_13 [ ( V_28 + 1 ) & 0xffff ] << 8 ;
V_146 = V_146 | V_13 [ ( V_28 + 2 ) & 0xffff ] ;
if ( ( V_142 & 0x01 ) == 1 ) {
V_147 = V_146 ;
V_146 = V_13 [ V_147 ] << 8 ;
V_146 = V_146 | V_13 [ ( V_147 + 1 ) & 0xffff ] ;
}
* V_66 = V_146 ;
V_23 = V_23 + 2 ;
}
}
}
}
break;
case 3 :
V_144 = ( V_142 & 0x20 ) >> 5 ;
if ( V_144 == 1 ) {
V_143 = ( V_13 [ V_28 ] & 0x1f ) + 65504 ;
* V_66 = V_143 ;
V_23 ++ ;
} else{
V_147 = V_13 [ V_28 ] & 0x1f ;
V_147 = V_147 << 8 ;
V_147 = V_147 | V_13 [ ( V_28 + 1 ) & 0xffff ] ;
V_146 = V_13 [ V_147 ] << 8 ;
V_146 = V_146 | V_13 [ ( V_147 + 1 ) & 0xffff ] ;
* V_66 = V_146 ;
V_23 = V_23 + 2 ;
}
default :
break;
}
return V_23 ;
}
static int
F_18 ( T_5 * V_13 , T_8 V_28 , T_7 * V_66 , T_8 V_27 )
{
T_6 V_40 ;
T_7 V_148 ;
T_8 V_149 ;
V_149 = F_12 ( V_13 , V_28 , & V_148 ) ;
V_40 = V_148 & 0xffff ;
V_40 = V_40 + V_27 ;
* V_66 = V_40 & 0xffff ;
return V_149 ;
}
static int
F_20 (
T_1 * V_2 ,
T_3 * V_4 ,
T_5 V_46 ,
T_5 * V_13 ,
T_7 * V_43 ,
T_7 * V_44 ,
T_7 * V_45 ,
T_8 * V_29 ,
T_7 V_62 ,
T_7 * V_42 ,
T_8 V_41 )
{
T_7 V_37 ;
T_7 V_150 = V_62 ;
T_7 V_66 = 0 ;
T_5 V_32 ;
T_4 V_151 = V_41 - * V_29 ;
T_4 V_152 ;
T_4 V_153 = * V_43 & 0x0001 ;
T_4 V_154 = 0 ;
V_37 = V_13 [ 68 ] << 8 ;
V_37 = V_37 | V_13 [ 69 ] ;
* V_42 = 0 ;
V_152 = ( V_37 & 0x0001 ) != 0 ;
if ( V_153 != V_152 )
{
* V_44 = 0 ;
* V_43 = V_37 ;
}
if ( * V_44 + V_151 * 8 < V_62 )
{
* V_42 = 11 ;
return 0xfbad ;
}
while ( V_150 > 0 )
{
if ( * V_44 == 0 )
{
V_32 = F_5 ( V_2 , * V_29 ) ;
if ( V_95 ) {
F_4 ( V_4 , V_2 , * V_29 , 1 ,
L_141 , V_32 , V_32 , * V_29 ) ;
}
* V_29 = * V_29 + 1 ;
if ( V_152 != 0 )
{
V_32 = V_155 [ V_32 ] ;
}
* V_45 = V_32 ;
* V_44 = 8 ;
}
V_154 = V_150 < * V_44 ? V_150 : * V_44 ;
V_150 -= V_154 ;
* V_45 <<= V_154 ;
V_66 = ( V_66 << V_154 )
| ( ( * V_45 >> 8 ) & 0xFF ) ;
* V_44 -= V_154 ;
* V_45 &= 0x00FF ;
}
if ( V_46 != 0 )
{
T_7 V_34 = V_155 [ ( V_66 >> 8 ) & 0xFF ] ;
T_7 V_33 = V_155 [ V_66 & 0xFF ] ;
V_66 = ( ( V_33 << 8 ) | V_34 ) >> ( 16 - V_62 ) ;
}
return V_66 ;
}
