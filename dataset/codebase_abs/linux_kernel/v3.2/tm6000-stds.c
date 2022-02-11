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
switch ( V_23 ) {
case 0 :
switch ( V_2 -> V_24 ) {
case V_25 :
V_4 |= 0x00 ;
break;
case V_26 :
V_4 |= 0x40 ;
break;
case V_27 :
case V_28 :
case V_29 :
V_4 |= 0x20 ;
break;
case V_30 :
V_4 |= 0x60 ;
break;
case V_31 :
V_4 |= 0x00 ;
break;
case V_32 :
V_4 |= 0x10 ;
break;
}
break;
case 1 :
switch ( V_2 -> V_24 ) {
case V_33 :
case V_34 :
V_4 = 0x05 ;
break;
case V_32 :
V_4 = 0x09 ;
break;
}
break;
case 2 :
switch ( V_2 -> V_24 ) {
case V_33 :
case V_34 :
V_4 = 0x07 ;
break;
case V_32 :
V_4 = 0x06 ;
break;
case V_35 :
V_4 = 0x08 ;
break;
case V_31 :
V_4 = 0x0a ;
V_3 = 0x02 ;
break;
}
V_6 = 1 ;
break;
case 3 :
switch ( V_2 -> V_24 ) {
case V_32 :
V_4 = 0x0b ;
break;
case V_25 :
V_4 = 0x04 ;
break;
case V_26 :
V_4 = 0x03 ;
break;
default:
V_4 = 0x02 ;
break;
}
break;
}
F_2 ( V_2 , V_8 , 0x00 ) ;
F_2 ( V_2 , V_9 , V_3 ) ;
F_2 ( V_2 , V_10 , 0x00 ) ;
F_2 ( V_2 , V_11 , 0xa0 ) ;
F_2 ( V_2 , V_12 , V_4 ) ;
F_2 ( V_2 , V_15 , V_5 ) ;
F_2 ( V_2 , V_36 , 0x00 ) ;
F_2 ( V_2 , V_37 , 0x00 ) ;
F_2 ( V_2 , V_17 , 0x08 ) ;
F_2 ( V_2 , V_38 , 0x91 ) ;
F_2 ( V_2 , V_39 , 0x20 ) ;
F_2 ( V_2 , V_18 , 0x12 ) ;
F_2 ( V_2 , V_19 , 0x20 ) ;
F_2 ( V_2 , V_40 , 0xf0 ) ;
F_2 ( V_2 , V_41 , 0x80 ) ;
F_2 ( V_2 , V_42 , 0xc0 ) ;
F_2 ( V_2 , V_43 , 0x80 ) ;
F_2 ( V_2 , V_44 , 0x12 ) ;
F_2 ( V_2 , V_45 , 0xfe ) ;
F_2 ( V_2 , V_46 , 0x20 ) ;
F_2 ( V_2 , V_47 , 0x14 ) ;
F_2 ( V_2 , V_48 , 0xfe ) ;
F_2 ( V_2 , V_49 , 0x01 ) ;
F_2 ( V_2 , V_50 , 0xa0 ) ;
F_2 ( V_2 , V_51 , 0x32 ) ;
F_2 ( V_2 , V_52 , 0x64 ) ;
F_2 ( V_2 , V_53 , 0x20 ) ;
F_2 ( V_2 , V_54 , 0x1c , 0x00 ) ;
F_2 ( V_2 , V_54 , 0x1d , 0x00 ) ;
F_2 ( V_2 , V_21 , 0x13 ) ;
F_2 ( V_2 , V_55 , 0x00 ) ;
F_2 ( V_2 , V_56 , 0x00 ) ;
F_2 ( V_2 , V_8 , 0x80 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 & V_57 )
V_2 -> V_58 = 480 ;
else
V_2 -> V_58 = 576 ;
V_2 -> V_59 = 720 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
int V_62 , V_63 ;
for ( V_62 = 0 ; V_61 [ V_62 ] . V_64 ; V_62 ++ ) {
V_63 = F_2 ( V_2 , V_61 [ V_62 ] . V_64 , V_61 [ V_62 ] . V_65 , V_61 [ V_62 ] . V_66 ) ;
if ( V_63 < 0 ) {
F_5 ( V_67 L_1
L_2 ,
V_63 , V_61 [ V_62 ] . V_64 , V_61 [ V_62 ] . V_65 , V_61 [ V_62 ] . V_66 ) ;
return V_63 ;
}
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
int V_62 , V_63 = 0 ;
T_2 V_70 = 0x8a ;
T_2 V_71 = 0xfc ;
T_2 V_72 = 0xf0 ;
T_2 V_73 = 0x0f ;
F_3 ( V_2 ) ;
if ( ! V_2 -> V_7 )
V_69 = & V_2 -> V_74 [ V_2 -> V_69 ] ;
else
V_69 = & V_2 -> V_75 ;
if ( V_2 -> V_76 == V_77 ) {
switch ( V_69 -> V_78 ) {
case V_79 :
F_2 ( V_2 , V_80 , 0xf4 ) ;
F_2 ( V_2 , V_81 , 0xf1 ) ;
F_2 ( V_2 , V_82 , 0xe0 ) ;
F_2 ( V_2 , V_83 , 0xc2 ) ;
F_2 ( V_2 , V_84 , 0xe8 ) ;
V_70 |= 0x01 ;
break;
case V_85 :
F_2 ( V_2 , V_80 , 0xf8 ) ;
F_2 ( V_2 , V_81 , 0xf1 ) ;
F_2 ( V_2 , V_82 , 0xe0 ) ;
F_2 ( V_2 , V_83 , 0xc2 ) ;
F_2 ( V_2 , V_84 , 0xe8 ) ;
V_70 |= 0x01 ;
break;
case V_86 :
F_2 ( V_2 , V_80 , 0xfc ) ;
F_2 ( V_2 , V_87 , 0xf8 ) ;
V_73 = 0x00 ;
F_2 ( V_2 , V_81 , 0xf2 ) ;
F_2 ( V_2 , V_82 , 0xf0 ) ;
F_2 ( V_2 , V_83 , 0xc2 ) ;
F_2 ( V_2 , V_84 , 0xe0 ) ;
break;
default:
break;
}
switch ( V_69 -> V_88 ) {
case V_89 :
F_7 ( V_2 , V_90 ,
0x00 , 0x0f ) ;
break;
case V_91 :
F_7 ( V_2 , V_90 ,
0x08 , 0x0f ) ;
break;
case V_92 :
V_72 |= 0x02 ;
V_73 = 0x08 ;
V_70 |= 0x40 ;
V_71 |= 0x02 ;
F_2 ( V_2 , V_87 , 0xf3 ) ;
F_7 ( V_2 , V_90 ,
0x02 , 0x0f ) ;
break;
case V_93 :
V_72 |= 0x02 ;
V_73 = 0x08 ;
V_70 |= 0x40 ;
V_71 |= 0x02 ;
F_2 ( V_2 , V_87 , 0xf7 ) ;
F_7 ( V_2 , V_90 ,
0x02 , 0x0f ) ;
break;
default:
break;
}
F_2 ( V_2 , V_94 , V_72 ) ;
F_2 ( V_2 , V_95 , V_73 ) ;
F_2 ( V_2 , V_20 , V_71 ) ;
F_2 ( V_2 , V_22 , V_70 ) ;
} else {
switch ( V_69 -> V_78 ) {
case V_79 :
F_2 ( V_2 , V_96 , 0x10 ) ;
F_2 ( V_2 , V_97 , 0x00 ) ;
F_2 ( V_2 , V_98 , 0x0f ) ;
F_2 ( V_2 ,
V_99 , V_69 -> V_100 , 0 ) ;
break;
case V_85 :
F_2 ( V_2 , V_96 , 0x00 ) ;
F_2 ( V_2 , V_97 , 0x00 ) ;
F_2 ( V_2 , V_98 , 0x0f ) ;
F_2 ( V_2 ,
V_99 , V_69 -> V_100 , 0 ) ;
break;
case V_86 :
F_2 ( V_2 , V_96 , 0x10 ) ;
F_2 ( V_2 , V_97 , 0x10 ) ;
F_2 ( V_2 , V_98 , 0x00 ) ;
F_2 ( V_2 ,
V_99 , V_69 -> V_100 , 1 ) ;
break;
default:
break;
}
switch ( V_69 -> V_88 ) {
case V_89 :
F_7 ( V_2 ,
V_101 , 0x00 , 0x0f ) ;
break;
case V_91 :
F_7 ( V_2 ,
V_101 , 0x04 , 0x0f ) ;
break;
default:
break;
}
}
if ( V_69 -> type == V_102 ) {
for ( V_62 = 0 ; V_62 < F_8 ( V_103 ) ; V_62 ++ ) {
if ( V_2 -> V_24 & V_103 [ V_62 ] . V_104 ) {
V_63 = F_4 ( V_2 , V_103 [ V_62 ] . V_105 ) ;
goto V_106;
}
}
return - V_107 ;
} else {
for ( V_62 = 0 ; V_62 < F_8 ( V_108 ) ; V_62 ++ ) {
if ( V_2 -> V_24 & V_108 [ V_62 ] . V_104 ) {
V_63 = F_4 ( V_2 , V_108 [ V_62 ] . V_105 ) ;
goto V_106;
}
}
return - V_107 ;
}
V_106:
if ( V_63 < 0 )
return V_63 ;
if ( ( V_2 -> V_76 == V_77 ) &&
( ( V_69 -> V_88 == V_92 ) ||
( V_69 -> V_88 == V_93 ) ) )
F_1 ( V_2 ) ;
F_9 ( 40 ) ;
return 0 ;
}
