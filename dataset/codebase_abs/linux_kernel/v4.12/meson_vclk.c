void F_1 ( struct V_1 * V_2 , unsigned int div )
{
unsigned int V_3 = 0 ;
unsigned int V_4 = 0 ;
F_2 ( V_2 -> V_5 , V_6 , V_7 , 0 ) ;
F_2 ( V_2 -> V_5 , V_6 , V_8 , 0 ) ;
switch ( div ) {
case V_9 :
V_3 = 0x0aaa ;
V_4 = 0 ;
break;
case V_10 :
V_3 = 0x5294 ;
V_4 = 2 ;
break;
case V_11 :
V_3 = 0x0db6 ;
V_4 = 0 ;
break;
case V_12 :
V_3 = 0x36cc ;
V_4 = 1 ;
break;
case V_13 :
V_3 = 0x6666 ;
V_4 = 2 ;
break;
case V_14 :
V_3 = 0x0ccc ;
V_4 = 0 ;
break;
case V_15 :
V_3 = 0x739c ;
V_4 = 2 ;
break;
case V_16 :
V_3 = 0x0e38 ;
V_4 = 0 ;
break;
case V_17 :
V_3 = 0x0000 ;
V_4 = 3 ;
break;
case V_18 :
V_3 = 0x3c78 ;
V_4 = 1 ;
break;
case V_19 :
V_3 = 0x78f0 ;
V_4 = 2 ;
break;
case V_20 :
V_3 = 0x0fc0 ;
V_4 = 0 ;
break;
case V_21 :
V_3 = 0x3f80 ;
V_4 = 1 ;
break;
case V_22 :
V_3 = 0x7f80 ;
V_4 = 2 ;
break;
}
if ( div == V_23 )
F_2 ( V_2 -> V_5 , V_6 ,
V_24 , V_24 ) ;
else {
F_2 ( V_2 -> V_5 , V_6 ,
V_24 , 0 ) ;
F_2 ( V_2 -> V_5 , V_6 ,
3 << 16 , 0 ) ;
F_2 ( V_2 -> V_5 , V_6 ,
V_8 , 0 ) ;
F_2 ( V_2 -> V_5 , V_6 ,
0x7fff , 0 ) ;
F_2 ( V_2 -> V_5 , V_6 ,
3 << 16 , V_4 << 16 ) ;
F_2 ( V_2 -> V_5 , V_6 ,
V_8 , V_8 ) ;
F_2 ( V_2 -> V_5 , V_6 ,
0x7fff , V_3 ) ;
F_2 ( V_2 -> V_5 , V_6 ,
V_8 , 0 ) ;
}
F_2 ( V_2 -> V_5 , V_6 ,
V_7 , V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_25 ;
if ( F_4 ( V_2 , L_1 ) ) {
F_5 ( V_2 -> V_5 , V_26 , 0x5800023d ) ;
F_5 ( V_2 -> V_5 , V_27 , 0x00404e00 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0x0d5c5091 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x801da72c ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x71486980 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x00000e55 ) ;
F_5 ( V_2 -> V_5 , V_26 , 0x4800023d ) ;
} else if ( F_4 ( V_2 , L_2 ) ||
F_4 ( V_2 , L_3 ) ) {
F_5 ( V_2 -> V_5 , V_26 , 0x4000027b ) ;
F_5 ( V_2 -> V_5 , V_27 , 0x800cb300 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0xa6212844 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x0c4d000c ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x001fa729 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x01a31500 ) ;
F_2 ( V_2 -> V_5 , V_26 ,
V_32 , V_32 ) ;
F_2 ( V_2 -> V_5 , V_26 ,
V_32 , 0 ) ;
}
F_6 ( V_2 -> V_5 , V_26 , V_25 ,
( V_25 & V_33 ) , 10 , 0 ) ;
F_2 ( V_2 -> V_5 , V_34 , V_35 , 0 ) ;
F_1 ( V_2 , V_23 ) ;
F_2 ( V_2 -> V_5 , V_36 ,
V_37 , ( 55 - 1 ) ) ;
F_2 ( V_2 -> V_5 , V_34 ,
V_38 , ( 4 << V_39 ) ) ;
F_2 ( V_2 -> V_5 , V_34 , V_35 , V_35 ) ;
F_2 ( V_2 -> V_5 , V_40 ,
V_41 , ( 8 << V_42 ) ) ;
F_2 ( V_2 -> V_5 , V_36 ,
V_43 , ( 8 << V_44 ) ) ;
F_2 ( V_2 -> V_5 , V_36 ,
V_45 | V_46 , V_45 ) ;
F_2 ( V_2 -> V_5 , V_34 ,
V_47 , V_47 ) ;
F_2 ( V_2 -> V_5 , V_34 ,
V_48 , V_48 ) ;
F_2 ( V_2 -> V_5 , V_34 ,
V_48 , 0 ) ;
F_2 ( V_2 -> V_5 , V_49 ,
V_50 , V_50 ) ;
F_2 ( V_2 -> V_5 , V_49 ,
V_51 , V_51 ) ;
}
static inline unsigned int F_7 ( unsigned int V_52 )
{
switch ( V_52 ) {
case 1 :
return 0 ;
case 2 :
return 1 ;
case 4 :
return 2 ;
case 8 :
return 3 ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned int V_53 ,
unsigned int V_54 ,
unsigned int V_55 ,
unsigned int V_56 )
{
unsigned int V_25 ;
if ( F_4 ( V_2 , L_1 ) ) {
switch ( V_53 ) {
case 2970000 :
F_5 ( V_2 -> V_5 , V_26 , 0x5800023d ) ;
F_5 ( V_2 -> V_5 , V_27 , 0x00000000 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0x0d5c5091 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x801da72c ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x71486980 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x00000e55 ) ;
F_2 ( V_2 -> V_5 , V_26 ,
0x7 << 28 , 0x4 << 28 ) ;
F_6 ( V_2 -> V_5 , V_26 ,
V_25 , ( V_25 & V_33 ) , 10 , 0 ) ;
F_2 ( V_2 -> V_5 , V_27 ,
0xFFFF , 0x4e00 ) ;
break;
case 4320000 :
F_5 ( V_2 -> V_5 , V_26 , 0x5800025a ) ;
F_5 ( V_2 -> V_5 , V_27 , 0x00000000 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0x0d5c5091 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x801da72c ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x71486980 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x00000e55 ) ;
F_2 ( V_2 -> V_5 , V_26 ,
F_9 ( 28 ) , 0 ) ;
F_6 ( V_2 -> V_5 , V_26 ,
V_25 , ( V_25 & V_33 ) , 10 , 0 ) ;
break;
case 5940000 :
F_5 ( V_2 -> V_5 , V_26 , 0x5800027b ) ;
F_2 ( V_2 -> V_5 , V_27 ,
0xFFFF , 0x4c00 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0x135c5091 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x801da72c ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x71486980 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x00000e55 ) ;
F_2 ( V_2 -> V_5 , V_26 ,
F_9 ( 28 ) , 0 ) ;
F_6 ( V_2 -> V_5 , V_26 ,
V_25 , ( V_25 & V_33 ) , 10 , 0 ) ;
break;
} ;
} else if ( F_4 ( V_2 , L_2 ) ||
F_4 ( V_2 , L_3 ) ) {
switch ( V_53 ) {
case 2970000 :
F_5 ( V_2 -> V_5 , V_26 , 0x4000027b ) ;
F_5 ( V_2 -> V_5 , V_27 , 0x800cb300 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0x860f30c4 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x0c8e0000 ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x001fa729 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x01a31500 ) ;
break;
case 4320000 :
F_5 ( V_2 -> V_5 , V_26 , 0x400002b4 ) ;
F_5 ( V_2 -> V_5 , V_27 , 0x800cb000 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0x860f30c4 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x0c8e0000 ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x001fa729 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x01a31500 ) ;
break;
case 5940000 :
F_5 ( V_2 -> V_5 , V_26 , 0x400002f7 ) ;
F_5 ( V_2 -> V_5 , V_27 , 0x800cb200 ) ;
F_5 ( V_2 -> V_5 , V_28 , 0x860f30c4 ) ;
F_5 ( V_2 -> V_5 , V_29 , 0x0c8e0000 ) ;
F_5 ( V_2 -> V_5 , V_30 , 0x001fa729 ) ;
F_5 ( V_2 -> V_5 , V_31 , 0x01a31500 ) ;
break;
} ;
F_2 ( V_2 -> V_5 , V_26 ,
V_32 , V_32 ) ;
F_2 ( V_2 -> V_5 , V_26 ,
V_32 , 0 ) ;
F_6 ( V_2 -> V_5 , V_26 , V_25 ,
( V_25 & V_33 ) , 10 , 0 ) ;
} ;
if ( F_4 ( V_2 , L_1 ) )
F_2 ( V_2 -> V_5 , V_27 ,
3 << 16 , F_7 ( V_54 ) << 16 ) ;
else if ( F_4 ( V_2 , L_2 ) ||
F_4 ( V_2 , L_3 ) )
F_2 ( V_2 -> V_5 , V_28 ,
3 << 21 , F_7 ( V_54 ) << 21 ) ;
if ( F_4 ( V_2 , L_1 ) )
F_2 ( V_2 -> V_5 , V_27 ,
3 << 22 , F_7 ( V_55 ) << 22 ) ;
else if ( F_4 ( V_2 , L_2 ) ||
F_4 ( V_2 , L_3 ) )
F_2 ( V_2 -> V_5 , V_28 ,
3 << 23 , F_7 ( V_55 ) << 23 ) ;
if ( F_4 ( V_2 , L_1 ) )
F_2 ( V_2 -> V_5 , V_27 ,
3 << 18 , F_7 ( V_56 ) << 18 ) ;
else if ( F_4 ( V_2 , L_2 ) ||
F_4 ( V_2 , L_3 ) )
F_2 ( V_2 -> V_5 , V_28 ,
3 << 19 , F_7 ( V_56 ) << 19 ) ;
}
void F_10 ( struct V_1 * V_2 , unsigned int V_57 ,
unsigned int V_58 , unsigned int V_59 ,
unsigned int V_60 , bool V_61 )
{
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
if ( V_57 == V_65 ) {
F_3 ( V_2 ) ;
return;
}
V_63 = V_58 / V_60 ;
if ( V_63 == 0 ) {
F_11 ( L_4 ,
V_60 ) ;
return;
}
V_64 = V_58 / V_59 ;
if ( V_64 == 0 ) {
F_11 ( L_5 ,
V_59 ) ;
return;
}
switch ( V_58 ) {
case 54000 :
if ( V_61 )
V_62 = V_66 ;
else
V_62 = V_67 ;
break;
case 74250 :
V_62 = V_68 ;
break;
case 148500 :
if ( V_60 != 148500 )
V_62 = V_69 ;
else
V_62 = V_70 ;
break;
case 297000 :
V_62 = V_71 ;
break;
case 594000 :
V_62 = V_72 ;
break;
default:
F_11 ( L_6 ,
V_58 ) ;
return;
}
F_2 ( V_2 -> V_5 , V_73 ,
V_74 , 0 ) ;
F_2 ( V_2 -> V_5 , V_73 ,
V_75 , 0 ) ;
F_2 ( V_2 -> V_5 , V_73 ,
V_76 , V_76 ) ;
F_8 ( V_2 , V_77 [ V_62 ] . V_78 ,
V_77 [ V_62 ] . V_79 ,
V_77 [ V_62 ] . V_80 ,
V_77 [ V_62 ] . V_81 ) ;
F_1 ( V_2 , V_77 [ V_62 ] . V_82 ) ;
F_2 ( V_2 -> V_5 , V_83 ,
V_84 , 0 ) ;
F_2 ( V_2 -> V_5 , V_40 ,
V_85 , V_77 [ V_62 ] . V_86 - 1 ) ;
switch ( V_63 ) {
case 1 :
F_2 ( V_2 -> V_5 , V_83 ,
V_87 , V_87 ) ;
F_2 ( V_2 -> V_5 , V_73 ,
V_88 , 0 ) ;
break;
case 2 :
F_2 ( V_2 -> V_5 , V_83 ,
V_89 , V_89 ) ;
F_2 ( V_2 -> V_5 , V_73 ,
V_88 , 1 << V_90 ) ;
break;
case 4 :
F_2 ( V_2 -> V_5 , V_83 ,
V_91 , V_91 ) ;
F_2 ( V_2 -> V_5 , V_73 ,
V_88 , 2 << V_90 ) ;
break;
case 6 :
F_2 ( V_2 -> V_5 , V_83 ,
V_92 , V_92 ) ;
F_2 ( V_2 -> V_5 , V_73 ,
V_88 , 3 << V_90 ) ;
break;
case 12 :
F_2 ( V_2 -> V_5 , V_83 ,
V_93 , V_93 ) ;
F_2 ( V_2 -> V_5 , V_73 ,
V_88 , 4 << V_90 ) ;
break;
}
F_2 ( V_2 -> V_5 , V_49 ,
V_94 , V_94 ) ;
switch ( V_64 ) {
case 1 :
F_2 ( V_2 -> V_5 , V_83 ,
V_87 , V_87 ) ;
if ( V_61 )
F_2 ( V_2 -> V_5 , V_40 ,
V_41 , 0 ) ;
else
F_2 ( V_2 -> V_5 , V_40 ,
V_95 , 0 ) ;
break;
case 2 :
F_2 ( V_2 -> V_5 , V_83 ,
V_89 , V_89 ) ;
if ( V_61 )
F_2 ( V_2 -> V_5 , V_40 ,
V_41 , 1 << V_42 ) ;
else
F_2 ( V_2 -> V_5 , V_40 ,
V_95 , 1 << V_96 ) ;
break;
case 4 :
F_2 ( V_2 -> V_5 , V_83 ,
V_91 , V_91 ) ;
if ( V_61 )
F_2 ( V_2 -> V_5 , V_40 ,
V_41 , 2 << V_42 ) ;
else
F_2 ( V_2 -> V_5 , V_40 ,
V_95 , 2 << V_96 ) ;
break;
case 6 :
F_2 ( V_2 -> V_5 , V_83 ,
V_92 , V_92 ) ;
if ( V_61 )
F_2 ( V_2 -> V_5 , V_40 ,
V_41 , 3 << V_42 ) ;
else
F_2 ( V_2 -> V_5 , V_40 ,
V_95 , 3 << V_96 ) ;
break;
case 12 :
F_2 ( V_2 -> V_5 , V_83 ,
V_93 , V_93 ) ;
if ( V_61 )
F_2 ( V_2 -> V_5 , V_40 ,
V_41 , 4 << V_42 ) ;
else
F_2 ( V_2 -> V_5 , V_40 ,
V_95 , 4 << V_96 ) ;
break;
}
if ( V_61 )
F_2 ( V_2 -> V_5 , V_49 ,
V_50 , V_50 ) ;
else
F_2 ( V_2 -> V_5 , V_49 ,
V_97 , V_97 ) ;
F_2 ( V_2 -> V_5 , V_83 , V_98 , V_98 ) ;
}
