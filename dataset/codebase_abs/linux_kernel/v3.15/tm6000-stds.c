static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0x04 ;
T_1 V_4 = 0x01 ;
T_1 V_5 = 0x02 ;
if ( V_2 -> V_6 ) {
F_2 ( V_2 , V_7 , 0x00 ) ;
F_2 ( V_2 , V_8 , 0x04 ) ;
F_2 ( V_2 , V_9 , 0x00 ) ;
F_2 ( V_2 , V_10 , 0x80 ) ;
F_2 ( V_2 , V_11 , 0x0c ) ;
if ( V_2 -> V_12 == V_13 )
F_2 ( V_2 , V_14 , 0x00 ) ;
else if ( V_2 -> V_12 == V_15 )
F_2 ( V_2 , V_14 , 0x02 ) ;
F_2 ( V_2 , V_16 , 0x18 ) ;
F_2 ( V_2 , V_17 , 0x0a ) ;
F_2 ( V_2 , V_18 , 0x40 ) ;
F_2 ( V_2 , V_19 , 0xfe ) ;
F_2 ( V_2 , V_20 , 0x13 ) ;
F_2 ( V_2 , V_7 , 0x80 ) ;
F_2 ( V_2 , V_21 , 0xff ) ;
return 0 ;
}
if ( ( V_2 -> V_22 & V_23 ) == V_24 ) {
V_4 |= 0x04 ;
} else if ( ( V_2 -> V_22 & V_23 ) == V_25 ) {
V_4 |= 0x43 ;
} else if ( V_2 -> V_22 & V_26 ) {
V_4 |= 0x22 ;
} else switch ( V_27 ) {
case 0 :
if ( ( V_2 -> V_22 & V_28 ) == V_29 )
V_4 |= 0x00 ;
else
V_4 |= 0x10 ;
break;
case 1 :
if ( V_2 -> V_22 & V_30 )
V_4 = 0x09 ;
else
V_4 = 0x05 ;
break;
case 2 :
if ( V_2 -> V_22 & V_30 ) {
V_4 = 0x06 ;
} else if ( V_2 -> V_22 & V_31 ) {
V_4 = 0x08 ;
} else if ( V_2 -> V_22 & V_29 ) {
V_4 = 0x0a ;
V_3 = 0x02 ;
} else {
V_4 = 0x07 ;
}
break;
case 3 :
if ( V_2 -> V_22 & V_30 ) {
V_4 = 0x0b ;
} else {
V_4 = 0x02 ;
}
break;
}
F_2 ( V_2 , V_7 , 0x00 ) ;
F_2 ( V_2 , V_8 , V_3 ) ;
F_2 ( V_2 , V_9 , 0x00 ) ;
F_2 ( V_2 , V_10 , 0xa0 ) ;
F_2 ( V_2 , V_11 , V_4 ) ;
F_2 ( V_2 , V_14 , V_5 ) ;
F_2 ( V_2 , V_32 , 0x00 ) ;
F_2 ( V_2 , V_33 , 0x00 ) ;
F_2 ( V_2 , V_16 , 0x08 ) ;
F_2 ( V_2 , V_34 , 0x91 ) ;
F_2 ( V_2 , V_35 , 0x20 ) ;
F_2 ( V_2 , V_17 , 0x12 ) ;
F_2 ( V_2 , V_18 , 0x20 ) ;
F_2 ( V_2 , V_36 , 0xf0 ) ;
F_2 ( V_2 , V_37 , 0x80 ) ;
F_2 ( V_2 , V_38 , 0xc0 ) ;
F_2 ( V_2 , V_39 , 0x80 ) ;
F_2 ( V_2 , V_40 , 0x12 ) ;
F_2 ( V_2 , V_41 , 0xfe ) ;
F_2 ( V_2 , V_42 , 0x20 ) ;
F_2 ( V_2 , V_43 , 0x14 ) ;
F_2 ( V_2 , V_44 , 0xfe ) ;
F_2 ( V_2 , V_45 , 0x01 ) ;
F_2 ( V_2 , V_46 , 0xa0 ) ;
F_2 ( V_2 , V_47 , 0x32 ) ;
F_2 ( V_2 , V_48 , 0x64 ) ;
F_2 ( V_2 , V_49 , 0x20 ) ;
F_2 ( V_2 , V_50 , 0x1c , 0x00 ) ;
F_2 ( V_2 , V_50 , 0x1d , 0x00 ) ;
F_2 ( V_2 , V_20 , 0x13 ) ;
F_2 ( V_2 , V_51 , 0x00 ) ;
F_2 ( V_2 , V_52 , 0x00 ) ;
F_2 ( V_2 , V_7 , 0x80 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & V_53 )
V_2 -> V_54 = 480 ;
else
V_2 -> V_54 = 576 ;
V_2 -> V_55 = 720 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
int V_58 , V_59 ;
for ( V_58 = 0 ; V_57 [ V_58 ] . V_60 ; V_58 ++ ) {
V_59 = F_2 ( V_2 , V_57 [ V_58 ] . V_60 , V_57 [ V_58 ] . V_61 , V_57 [ V_58 ] . V_62 ) ;
if ( V_59 < 0 ) {
F_5 ( V_63 L_1
L_2 ,
V_59 , V_57 [ V_58 ] . V_60 , V_57 [ V_58 ] . V_61 , V_57 [ V_58 ] . V_62 ) ;
return V_59 ;
}
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_58 , V_59 = 0 ;
T_2 V_66 = 0x8a ;
T_2 V_67 = 0xfc ;
T_2 V_68 = 0xf0 ;
T_2 V_69 = 0x0f ;
F_3 ( V_2 ) ;
if ( ! V_2 -> V_6 )
V_65 = & V_2 -> V_70 [ V_2 -> V_65 ] ;
else
V_65 = & V_2 -> V_71 ;
if ( V_2 -> V_72 == V_73 ) {
switch ( V_65 -> V_74 ) {
case V_75 :
F_2 ( V_2 , V_76 , 0xf4 ) ;
F_2 ( V_2 , V_77 , 0xf1 ) ;
F_2 ( V_2 , V_78 , 0xe0 ) ;
F_2 ( V_2 , V_79 , 0xc2 ) ;
F_2 ( V_2 , V_80 , 0xe8 ) ;
V_66 |= 0x01 ;
break;
case V_81 :
F_2 ( V_2 , V_76 , 0xf8 ) ;
F_2 ( V_2 , V_77 , 0xf1 ) ;
F_2 ( V_2 , V_78 , 0xe0 ) ;
F_2 ( V_2 , V_79 , 0xc2 ) ;
F_2 ( V_2 , V_80 , 0xe8 ) ;
V_66 |= 0x01 ;
break;
case V_82 :
F_2 ( V_2 , V_76 , 0xfc ) ;
F_2 ( V_2 , V_83 , 0xf8 ) ;
V_69 = 0x00 ;
F_2 ( V_2 , V_77 , 0xf2 ) ;
F_2 ( V_2 , V_78 , 0xf0 ) ;
F_2 ( V_2 , V_79 , 0xc2 ) ;
F_2 ( V_2 , V_80 , 0xe0 ) ;
break;
default:
break;
}
switch ( V_65 -> V_84 ) {
case V_85 :
F_7 ( V_2 , V_86 ,
0x00 , 0x0f ) ;
F_7 ( V_2 , V_87 ,
0x10 , 0xf0 ) ;
break;
case V_88 :
F_7 ( V_2 , V_86 ,
0x08 , 0x0f ) ;
F_7 ( V_2 , V_87 ,
0x10 , 0xf0 ) ;
break;
case V_89 :
V_68 |= 0x02 ;
V_69 = 0x08 ;
V_66 |= 0x40 ;
V_67 |= 0x02 ;
F_2 ( V_2 , V_83 , 0xf3 ) ;
F_7 ( V_2 , V_86 ,
0x02 , 0x0f ) ;
F_7 ( V_2 , V_87 ,
0x30 , 0xf0 ) ;
break;
case V_90 :
V_68 |= 0x02 ;
V_69 = 0x08 ;
V_66 |= 0x40 ;
V_67 |= 0x02 ;
F_2 ( V_2 , V_83 , 0xf7 ) ;
F_7 ( V_2 , V_86 ,
0x02 , 0x0f ) ;
F_7 ( V_2 , V_87 ,
0x30 , 0xf0 ) ;
break;
default:
break;
}
F_2 ( V_2 , V_91 , V_68 ) ;
F_2 ( V_2 , V_92 , V_69 ) ;
F_2 ( V_2 , V_19 , V_67 ) ;
F_2 ( V_2 , V_21 , V_66 ) ;
} else {
switch ( V_65 -> V_74 ) {
case V_75 :
F_2 ( V_2 , V_93 , 0x10 ) ;
F_2 ( V_2 , V_94 , 0x00 ) ;
F_2 ( V_2 , V_95 , 0x0f ) ;
F_2 ( V_2 ,
V_96 , V_65 -> V_97 , 0 ) ;
break;
case V_81 :
F_2 ( V_2 , V_93 , 0x00 ) ;
F_2 ( V_2 , V_94 , 0x00 ) ;
F_2 ( V_2 , V_95 , 0x0f ) ;
F_2 ( V_2 ,
V_96 , V_65 -> V_97 , 0 ) ;
break;
case V_82 :
F_2 ( V_2 , V_93 , 0x10 ) ;
F_2 ( V_2 , V_94 , 0x10 ) ;
F_2 ( V_2 , V_95 , 0x00 ) ;
F_2 ( V_2 ,
V_96 , V_65 -> V_97 , 1 ) ;
break;
default:
break;
}
switch ( V_65 -> V_84 ) {
case V_85 :
F_7 ( V_2 ,
V_98 , 0x00 , 0x0f ) ;
break;
case V_88 :
F_7 ( V_2 ,
V_98 , 0x04 , 0x0f ) ;
break;
default:
break;
}
}
if ( V_65 -> type == V_99 ) {
for ( V_58 = 0 ; V_58 < F_8 ( V_100 ) ; V_58 ++ ) {
if ( V_2 -> V_22 & V_100 [ V_58 ] . V_101 ) {
V_59 = F_4 ( V_2 , V_100 [ V_58 ] . V_102 ) ;
goto V_103;
}
}
return - V_104 ;
} else {
for ( V_58 = 0 ; V_58 < F_8 ( V_105 ) ; V_58 ++ ) {
if ( V_2 -> V_22 & V_105 [ V_58 ] . V_101 ) {
V_59 = F_4 ( V_2 , V_105 [ V_58 ] . V_102 ) ;
goto V_103;
}
}
return - V_104 ;
}
V_103:
if ( V_59 < 0 )
return V_59 ;
if ( ( V_2 -> V_72 == V_73 ) &&
( ( V_65 -> V_84 == V_89 ) ||
( V_65 -> V_84 == V_90 ) ) )
F_1 ( V_2 ) ;
F_9 ( 40 ) ;
return 0 ;
}
