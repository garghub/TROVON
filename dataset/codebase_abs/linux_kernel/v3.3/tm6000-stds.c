static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0x04 ;
T_1 V_4 = 0x01 ;
T_1 V_5 = 0x02 ;
T_1 V_6 = 0 ;
if ( V_2 -> V_7 ) {
F_2 ( V_2 , V_8 , 0x00 ) ;
F_2 ( V_2 , V_9 , 0x04 ) ;
F_2 ( V_2 , V_10 , 0x00 ) ;
F_2 ( V_2 , V_11 , 0x80 ) ;
F_2 ( V_2 , V_12 , 0x0c ) ;
if ( V_2 -> V_13 == V_14 )
F_2 ( V_2 , V_15 , 0x00 ) ;
else if ( V_2 -> V_13 == V_16 )
F_2 ( V_2 , V_15 , 0x02 ) ;
F_2 ( V_2 , V_17 , 0x18 ) ;
F_2 ( V_2 , V_18 , 0x0a ) ;
F_2 ( V_2 , V_19 , 0x40 ) ;
F_2 ( V_2 , V_20 , 0xfe ) ;
F_2 ( V_2 , V_21 , 0x13 ) ;
F_2 ( V_2 , V_8 , 0x80 ) ;
F_2 ( V_2 , V_22 , 0xff ) ;
return 0 ;
}
if ( ( V_2 -> V_23 & V_24 ) == V_25 ) {
V_4 |= 0x04 ;
} else if ( ( V_2 -> V_23 & V_24 ) == V_26 ) {
V_4 |= 0x43 ;
} else if ( V_2 -> V_23 & V_27 ) {
V_4 |= 0x22 ;
} else switch ( V_28 ) {
case 0 :
if ( ( V_2 -> V_23 & V_29 ) == V_30 )
V_4 |= 0x00 ;
else
V_4 |= 0x10 ;
break;
case 1 :
if ( V_2 -> V_23 & V_31 )
V_4 = 0x09 ;
else
V_4 = 0x05 ;
break;
case 2 :
if ( V_2 -> V_23 & V_31 ) {
V_4 = 0x06 ;
} else if ( V_2 -> V_23 & V_32 ) {
V_4 = 0x08 ;
} else if ( V_2 -> V_23 & V_30 ) {
V_4 = 0x0a ;
V_3 = 0x02 ;
} else {
V_4 = 0x07 ;
}
V_6 = 1 ;
break;
case 3 :
if ( V_2 -> V_23 & V_31 ) {
V_4 = 0x0b ;
} else {
V_4 = 0x02 ;
}
break;
}
F_2 ( V_2 , V_8 , 0x00 ) ;
F_2 ( V_2 , V_9 , V_3 ) ;
F_2 ( V_2 , V_10 , 0x00 ) ;
F_2 ( V_2 , V_11 , 0xa0 ) ;
F_2 ( V_2 , V_12 , V_4 ) ;
F_2 ( V_2 , V_15 , V_5 ) ;
F_2 ( V_2 , V_33 , 0x00 ) ;
F_2 ( V_2 , V_34 , 0x00 ) ;
F_2 ( V_2 , V_17 , 0x08 ) ;
F_2 ( V_2 , V_35 , 0x91 ) ;
F_2 ( V_2 , V_36 , 0x20 ) ;
F_2 ( V_2 , V_18 , 0x12 ) ;
F_2 ( V_2 , V_19 , 0x20 ) ;
F_2 ( V_2 , V_37 , 0xf0 ) ;
F_2 ( V_2 , V_38 , 0x80 ) ;
F_2 ( V_2 , V_39 , 0xc0 ) ;
F_2 ( V_2 , V_40 , 0x80 ) ;
F_2 ( V_2 , V_41 , 0x12 ) ;
F_2 ( V_2 , V_42 , 0xfe ) ;
F_2 ( V_2 , V_43 , 0x20 ) ;
F_2 ( V_2 , V_44 , 0x14 ) ;
F_2 ( V_2 , V_45 , 0xfe ) ;
F_2 ( V_2 , V_46 , 0x01 ) ;
F_2 ( V_2 , V_47 , 0xa0 ) ;
F_2 ( V_2 , V_48 , 0x32 ) ;
F_2 ( V_2 , V_49 , 0x64 ) ;
F_2 ( V_2 , V_50 , 0x20 ) ;
F_2 ( V_2 , V_51 , 0x1c , 0x00 ) ;
F_2 ( V_2 , V_51 , 0x1d , 0x00 ) ;
F_2 ( V_2 , V_21 , 0x13 ) ;
F_2 ( V_2 , V_52 , 0x00 ) ;
F_2 ( V_2 , V_53 , 0x00 ) ;
F_2 ( V_2 , V_8 , 0x80 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 & V_54 )
V_2 -> V_55 = 480 ;
else
V_2 -> V_55 = 576 ;
V_2 -> V_56 = 720 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
int V_59 , V_60 ;
for ( V_59 = 0 ; V_58 [ V_59 ] . V_61 ; V_59 ++ ) {
V_60 = F_2 ( V_2 , V_58 [ V_59 ] . V_61 , V_58 [ V_59 ] . V_62 , V_58 [ V_59 ] . V_63 ) ;
if ( V_60 < 0 ) {
F_5 ( V_64 L_1
L_2 ,
V_60 , V_58 [ V_59 ] . V_61 , V_58 [ V_59 ] . V_62 , V_58 [ V_59 ] . V_63 ) ;
return V_60 ;
}
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_59 , V_60 = 0 ;
T_2 V_67 = 0x8a ;
T_2 V_68 = 0xfc ;
T_2 V_69 = 0xf0 ;
T_2 V_70 = 0x0f ;
F_3 ( V_2 ) ;
if ( ! V_2 -> V_7 )
V_66 = & V_2 -> V_71 [ V_2 -> V_66 ] ;
else
V_66 = & V_2 -> V_72 ;
if ( V_2 -> V_73 == V_74 ) {
switch ( V_66 -> V_75 ) {
case V_76 :
F_2 ( V_2 , V_77 , 0xf4 ) ;
F_2 ( V_2 , V_78 , 0xf1 ) ;
F_2 ( V_2 , V_79 , 0xe0 ) ;
F_2 ( V_2 , V_80 , 0xc2 ) ;
F_2 ( V_2 , V_81 , 0xe8 ) ;
V_67 |= 0x01 ;
break;
case V_82 :
F_2 ( V_2 , V_77 , 0xf8 ) ;
F_2 ( V_2 , V_78 , 0xf1 ) ;
F_2 ( V_2 , V_79 , 0xe0 ) ;
F_2 ( V_2 , V_80 , 0xc2 ) ;
F_2 ( V_2 , V_81 , 0xe8 ) ;
V_67 |= 0x01 ;
break;
case V_83 :
F_2 ( V_2 , V_77 , 0xfc ) ;
F_2 ( V_2 , V_84 , 0xf8 ) ;
V_70 = 0x00 ;
F_2 ( V_2 , V_78 , 0xf2 ) ;
F_2 ( V_2 , V_79 , 0xf0 ) ;
F_2 ( V_2 , V_80 , 0xc2 ) ;
F_2 ( V_2 , V_81 , 0xe0 ) ;
break;
default:
break;
}
switch ( V_66 -> V_85 ) {
case V_86 :
F_7 ( V_2 , V_87 ,
0x00 , 0x0f ) ;
F_7 ( V_2 , V_88 ,
0x10 , 0xf0 ) ;
break;
case V_89 :
F_7 ( V_2 , V_87 ,
0x08 , 0x0f ) ;
F_7 ( V_2 , V_88 ,
0x10 , 0xf0 ) ;
break;
case V_90 :
V_69 |= 0x02 ;
V_70 = 0x08 ;
V_67 |= 0x40 ;
V_68 |= 0x02 ;
F_2 ( V_2 , V_84 , 0xf3 ) ;
F_7 ( V_2 , V_87 ,
0x02 , 0x0f ) ;
F_7 ( V_2 , V_88 ,
0x30 , 0xf0 ) ;
break;
case V_91 :
V_69 |= 0x02 ;
V_70 = 0x08 ;
V_67 |= 0x40 ;
V_68 |= 0x02 ;
F_2 ( V_2 , V_84 , 0xf7 ) ;
F_7 ( V_2 , V_87 ,
0x02 , 0x0f ) ;
F_7 ( V_2 , V_88 ,
0x30 , 0xf0 ) ;
break;
default:
break;
}
F_2 ( V_2 , V_92 , V_69 ) ;
F_2 ( V_2 , V_93 , V_70 ) ;
F_2 ( V_2 , V_20 , V_68 ) ;
F_2 ( V_2 , V_22 , V_67 ) ;
} else {
switch ( V_66 -> V_75 ) {
case V_76 :
F_2 ( V_2 , V_94 , 0x10 ) ;
F_2 ( V_2 , V_95 , 0x00 ) ;
F_2 ( V_2 , V_96 , 0x0f ) ;
F_2 ( V_2 ,
V_97 , V_66 -> V_98 , 0 ) ;
break;
case V_82 :
F_2 ( V_2 , V_94 , 0x00 ) ;
F_2 ( V_2 , V_95 , 0x00 ) ;
F_2 ( V_2 , V_96 , 0x0f ) ;
F_2 ( V_2 ,
V_97 , V_66 -> V_98 , 0 ) ;
break;
case V_83 :
F_2 ( V_2 , V_94 , 0x10 ) ;
F_2 ( V_2 , V_95 , 0x10 ) ;
F_2 ( V_2 , V_96 , 0x00 ) ;
F_2 ( V_2 ,
V_97 , V_66 -> V_98 , 1 ) ;
break;
default:
break;
}
switch ( V_66 -> V_85 ) {
case V_86 :
F_7 ( V_2 ,
V_99 , 0x00 , 0x0f ) ;
break;
case V_89 :
F_7 ( V_2 ,
V_99 , 0x04 , 0x0f ) ;
break;
default:
break;
}
}
if ( V_66 -> type == V_100 ) {
for ( V_59 = 0 ; V_59 < F_8 ( V_101 ) ; V_59 ++ ) {
if ( V_2 -> V_23 & V_101 [ V_59 ] . V_102 ) {
V_60 = F_4 ( V_2 , V_101 [ V_59 ] . V_103 ) ;
goto V_104;
}
}
return - V_105 ;
} else {
for ( V_59 = 0 ; V_59 < F_8 ( V_106 ) ; V_59 ++ ) {
if ( V_2 -> V_23 & V_106 [ V_59 ] . V_102 ) {
V_60 = F_4 ( V_2 , V_106 [ V_59 ] . V_103 ) ;
goto V_104;
}
}
return - V_105 ;
}
V_104:
if ( V_60 < 0 )
return V_60 ;
if ( ( V_2 -> V_73 == V_74 ) &&
( ( V_66 -> V_85 == V_90 ) ||
( V_66 -> V_85 == V_91 ) ) )
F_1 ( V_2 ) ;
F_9 ( 40 ) ;
return 0 ;
}
