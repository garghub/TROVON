static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 , V_9 , V_10 ;
T_1 V_11 [ 83 ] ;
F_2 ( & V_7 -> V_2 , L_1 , V_5 ) ;
if ( V_5 > 86 ) {
V_8 = - V_12 ;
goto V_13;
}
for ( V_9 = 0 , V_10 = 0 ; V_9 < V_5 ; V_9 ++ , V_10 ++ ) {
V_11 [ V_10 ] = V_4 [ V_9 ] . V_14 ;
if ( V_9 == V_5 - 1 || V_4 [ V_9 ] . V_15 != V_4 [ V_9 + 1 ] . V_15 - 1 ||
! ( ( V_10 + 1 ) % ( V_2 -> V_16 -> V_17 - 1 ) ) ) {
V_8 = F_3 ( V_2 -> V_18 , V_4 [ V_9 ] . V_15 - V_10 , V_11 , V_10 + 1 ) ;
if ( V_8 )
goto V_13;
V_10 = - 1 ;
}
}
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
int F_4 ( struct V_19 * V_20 , T_1 * V_21 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
unsigned V_23 ;
int V_8 ;
V_8 = F_5 ( V_2 -> V_18 , 0x3f , & V_23 ) ;
if ( V_8 == 0 )
* V_21 = V_23 ;
return V_8 ;
}
static int F_6 ( struct V_19 * V_20 ,
enum V_24 * V_25 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_26 * V_27 = & V_20 -> V_28 ;
int V_8 , V_9 , V_29 ;
unsigned int V_30 ;
T_1 V_11 [ 3 ] ;
* V_25 = 0 ;
if ( ! V_2 -> V_31 ) {
V_8 = - V_32 ;
goto V_13;
}
switch ( V_27 -> V_33 ) {
case V_34 :
V_8 = F_5 ( V_2 -> V_18 , 0xd1 , & V_30 ) ;
if ( V_8 )
goto V_13;
if ( ( V_30 & 0x07 ) == 0x07 )
* V_25 = V_35 | V_36 |
V_37 | V_38 |
V_39 ;
break;
case V_40 :
V_8 = F_5 ( V_2 -> V_18 , 0x0d , & V_30 ) ;
if ( V_8 )
goto V_13;
if ( ( V_30 & 0x8f ) == 0x8f )
* V_25 = V_35 | V_36 |
V_37 | V_38 |
V_39 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_3 ) ;
V_8 = - V_12 ;
goto V_13;
}
V_2 -> V_24 = * V_25 ;
F_2 ( & V_7 -> V_2 , L_4 , V_30 , * V_25 ) ;
if ( V_2 -> V_24 & V_37 ) {
unsigned int V_41 , V_42 , signal , V_43 , V_44 ;
V_41 = 0 ;
#define F_7 3
switch ( V_27 -> V_33 ) {
case V_34 :
V_29 = 0 ;
for ( V_9 = 0 ; V_9 < F_7 ; V_9 ++ ) {
V_8 = F_5 ( V_2 -> V_18 , 0xff , & V_30 ) ;
if ( V_8 )
goto V_13;
V_29 += V_30 ;
}
V_29 = F_8 ( V_29 , 8 * F_7 ) ;
if ( V_29 )
V_41 = F_9 ( ( V_45 ) 10000 * F_10 ( V_29 ) , F_10 ( 10 ) ) ;
break;
case V_40 :
V_43 = 0 ;
V_44 = 0 ;
for ( V_9 = 0 ; V_9 < F_7 ; V_9 ++ ) {
V_8 = F_11 ( V_2 -> V_18 , 0x8c , V_11 , 3 ) ;
if ( V_8 )
goto V_13;
V_42 = V_11 [ 1 ] << 6 ;
V_42 |= V_11 [ 0 ] & 0x3f ;
V_42 >>= 2 ;
signal = V_11 [ 2 ] * V_11 [ 2 ] ;
signal >>= 1 ;
V_43 += V_42 ;
V_44 += signal ;
}
V_42 = V_43 / F_7 ;
signal = V_44 / F_7 ;
if ( signal > V_42 ) {
V_29 = signal / V_42 ;
V_41 = F_9 ( ( V_45 ) 10000 * F_12 ( V_29 ) , ( 1 << 24 ) ) ;
}
break;
default:
F_2 ( & V_7 -> V_2 , L_3 ) ;
V_8 = - V_12 ;
goto V_13;
}
if ( V_41 ) {
V_27 -> V_41 . V_46 [ 0 ] . V_47 = V_48 ;
V_27 -> V_41 . V_46 [ 0 ] . V_49 = V_41 ;
} else {
V_27 -> V_41 . V_46 [ 0 ] . V_47 = V_50 ;
}
} else {
V_27 -> V_41 . V_46 [ 0 ] . V_47 = V_50 ;
}
if ( V_2 -> V_24 & V_39 ) {
unsigned int V_30 , V_51 , V_52 ;
switch ( V_27 -> V_33 ) {
case V_34 :
V_8 = F_13 ( V_2 -> V_18 , 0xf9 , 0x04 ) ;
if ( V_8 )
goto V_13;
V_8 = F_5 ( V_2 -> V_18 , 0xf8 , & V_30 ) ;
if ( V_8 )
goto V_13;
if ( ! ( V_30 & 0x10 ) ) {
V_8 = F_11 ( V_2 -> V_18 , 0xf6 , V_11 , 2 ) ;
if ( V_8 )
goto V_13;
V_51 = V_11 [ 1 ] << 8 | V_11 [ 0 ] << 0 ;
V_52 = 0x800000 ;
V_2 -> V_51 += V_51 ;
V_2 -> V_52 += V_52 ;
V_2 -> V_53 = V_51 ;
V_30 |= 0x10 ;
V_8 = F_13 ( V_2 -> V_18 , 0xf8 , V_30 ) ;
if ( V_8 )
goto V_13;
}
break;
case V_40 :
V_8 = F_11 ( V_2 -> V_18 , 0xd5 , V_11 , 3 ) ;
if ( V_8 )
goto V_13;
V_30 = V_11 [ 2 ] << 16 | V_11 [ 1 ] << 8 | V_11 [ 0 ] << 0 ;
if ( V_30 > 4000 ) {
V_8 = F_11 ( V_2 -> V_18 , 0xf7 , V_11 , 2 ) ;
if ( V_8 )
goto V_13;
V_51 = V_11 [ 1 ] << 8 | V_11 [ 0 ] << 0 ;
V_52 = 32 * V_30 ;
V_2 -> V_51 += V_51 ;
V_2 -> V_52 += V_52 ;
V_2 -> V_53 = V_51 ;
V_8 = F_13 ( V_2 -> V_18 , 0xd1 , 0x01 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xf9 , 0x01 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xf9 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xd1 , 0x00 ) ;
if ( V_8 )
goto V_13;
}
break;
default:
F_2 ( & V_7 -> V_2 , L_3 ) ;
V_8 = - V_12 ;
goto V_13;
}
V_27 -> V_51 . V_46 [ 0 ] . V_47 = V_54 ;
V_27 -> V_51 . V_46 [ 0 ] . V_55 = V_2 -> V_51 ;
V_27 -> V_52 . V_46 [ 0 ] . V_47 = V_54 ;
V_27 -> V_52 . V_46 [ 0 ] . V_55 = V_2 -> V_52 ;
} else {
V_27 -> V_51 . V_46 [ 0 ] . V_47 = V_50 ;
V_27 -> V_52 . V_46 [ 0 ] . V_47 = V_50 ;
}
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_26 * V_27 = & V_20 -> V_28 ;
int V_8 , V_56 ;
const struct V_3 * V_57 ;
T_1 V_58 , V_59 = 0 , V_60 = 0 ;
T_1 V_11 [ 3 ] ;
T_2 V_61 , V_62 = 0 ;
T_3 V_63 , V_64 ;
T_4 V_65 ;
F_2 ( & V_7 -> V_2 ,
L_5 ,
V_27 -> V_33 , V_27 -> V_66 , V_27 -> V_67 , V_27 -> V_68 ,
V_27 -> V_69 , V_27 -> V_70 , V_27 -> V_71 ) ;
if ( ! V_2 -> V_31 ) {
V_8 = - V_32 ;
goto V_13;
}
V_8 = F_13 ( V_2 -> V_18 , 0x07 , 0x80 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0x07 , 0x00 ) ;
if ( V_8 )
goto V_13;
if ( V_2 -> V_72 == V_73 ) {
V_8 = F_13 ( V_2 -> V_18 , 0x06 , 0xe0 ) ;
if ( V_8 )
goto V_13;
}
if ( V_20 -> V_74 . V_75 . V_76 ) {
V_8 = V_20 -> V_74 . V_75 . V_76 ( V_20 ) ;
if ( V_8 )
goto V_13;
}
if ( V_20 -> V_74 . V_75 . V_77 ) {
V_8 = V_20 -> V_74 . V_75 . V_77 ( V_20 , & V_63 ) ;
if ( V_8 )
goto V_13;
} else {
V_63 = V_27 -> V_67 ;
}
if ( V_2 -> V_72 == V_73 ) {
if ( V_27 -> V_68 > 45010000 )
V_2 -> V_78 = 110250 ;
else
V_2 -> V_78 = 96000 ;
if ( V_27 -> V_33 == V_34 )
V_64 = 96000 ;
else
V_64 = 144000 ;
V_8 = F_13 ( V_2 -> V_18 , 0x06 , 0x00 ) ;
if ( V_8 )
goto V_13;
F_15 ( 10000 , 20000 ) ;
} else {
V_2 -> V_78 = 96000 ;
switch ( V_2 -> V_16 -> V_79 ) {
case V_80 :
case V_81 :
V_64 = V_2 -> V_16 -> V_82 ;
break;
case V_83 :
case V_84 :
if ( V_27 -> V_33 == V_34 )
V_64 = 96000 ;
else {
if ( V_27 -> V_68 < 18000000 )
V_64 = 96000 ;
else if ( V_27 -> V_68 < 28000000 )
V_64 = 144000 ;
else
V_64 = 192000 ;
}
break;
default:
F_2 ( & V_7 -> V_2 , L_6 ) ;
V_8 = - V_12 ;
goto V_13;
}
switch ( V_64 ) {
case 96000 :
V_59 = 0x02 ;
V_60 = 0x01 ;
break;
case 144000 :
V_59 = 0x00 ;
V_60 = 0x01 ;
break;
case 192000 :
V_59 = 0x03 ;
V_60 = 0x00 ;
break;
}
V_8 = F_16 ( V_2 -> V_18 , 0x22 , 0xc0 , V_59 << 6 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x24 , 0xc0 , V_60 << 6 ) ;
if ( V_8 )
goto V_13;
}
V_8 = F_13 ( V_2 -> V_18 , 0xb2 , 0x01 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0x00 , 0x01 ) ;
if ( V_8 )
goto V_13;
switch ( V_27 -> V_33 ) {
case V_34 :
if ( V_2 -> V_72 == V_73 ) {
V_56 = F_17 ( V_85 ) ;
V_57 = V_85 ;
} else {
V_56 = F_17 ( V_86 ) ;
V_57 = V_86 ;
}
break;
case V_40 :
if ( V_2 -> V_72 == V_73 ) {
V_56 = F_17 ( V_87 ) ;
V_57 = V_87 ;
} else {
V_56 = F_17 ( V_88 ) ;
V_57 = V_88 ;
}
break;
default:
F_2 ( & V_7 -> V_2 , L_3 ) ;
V_8 = - V_12 ;
goto V_13;
}
if ( V_27 -> V_33 != V_2 -> V_33 ) {
V_8 = F_1 ( V_2 , V_57 , V_56 ) ;
if ( V_8 )
goto V_13;
}
if ( V_2 -> V_72 == V_73 ) {
if ( ( V_27 -> V_33 == V_40 )
&& ( ( V_27 -> V_68 / 1000 ) <= 5000 ) ) {
V_8 = F_13 ( V_2 -> V_18 , 0xc0 , 0x04 ) ;
if ( V_8 )
goto V_13;
V_11 [ 0 ] = 0x09 ;
V_11 [ 1 ] = 0x22 ;
V_11 [ 2 ] = 0x88 ;
V_8 = F_3 ( V_2 -> V_18 , 0x8a , V_11 , 3 ) ;
if ( V_8 )
goto V_13;
}
V_8 = F_16 ( V_2 -> V_18 , 0x9d , 0x08 , 0x08 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xf1 , 0x01 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x30 , 0x80 , 0x80 ) ;
if ( V_8 )
goto V_13;
}
switch ( V_2 -> V_16 -> V_79 ) {
case V_80 :
V_59 = 0x00 ;
V_58 = 0x06 ;
break;
case V_81 :
V_59 = 0x20 ;
V_58 = 0x06 ;
break;
case V_83 :
V_58 = 0x02 ;
break;
case V_84 :
V_58 = 0x03 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_6 ) ;
V_8 = - V_12 ;
goto V_13;
}
if ( V_2 -> V_16 -> V_89 )
V_58 |= 0x40 ;
V_8 = F_13 ( V_2 -> V_18 , 0xfd , V_58 ) ;
if ( V_8 )
goto V_13;
switch ( V_2 -> V_16 -> V_79 ) {
case V_80 :
case V_81 :
V_8 = F_16 ( V_2 -> V_18 , 0x29 , 0x20 , V_59 ) ;
if ( V_8 )
goto V_13;
V_59 = 0 ;
V_60 = 0 ;
break;
default:
if ( V_2 -> V_16 -> V_82 ) {
V_62 = F_18 ( V_64 , V_2 -> V_16 -> V_82 ) ;
V_59 = V_62 / 2 ;
V_60 = F_18 ( V_62 , 2 ) ;
}
}
F_2 ( & V_7 -> V_2 ,
L_7 ,
V_64 , V_2 -> V_16 -> V_82 , V_62 ) ;
V_59 -- ;
V_60 -- ;
V_59 &= 0x3f ;
V_60 &= 0x3f ;
V_8 = F_11 ( V_2 -> V_18 , 0xfe , & V_58 , 1 ) ;
if ( V_8 )
goto V_13;
V_58 = ( ( V_58 & 0xf0 ) << 0 ) | V_59 >> 2 ;
V_8 = F_13 ( V_2 -> V_18 , 0xfe , V_58 ) ;
if ( V_8 )
goto V_13;
V_58 = ( ( V_59 & 0x03 ) << 6 ) | V_60 >> 0 ;
V_8 = F_13 ( V_2 -> V_18 , 0xea , V_58 ) ;
if ( V_8 )
goto V_13;
if ( V_27 -> V_68 <= 3000000 )
V_58 = 0x20 ;
else if ( V_27 -> V_68 <= 10000000 )
V_58 = 0x10 ;
else
V_58 = 0x06 ;
V_8 = F_13 ( V_2 -> V_18 , 0xc3 , 0x08 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xc8 , V_58 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xc4 , 0x08 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xc7 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_61 = F_8 ( ( V_27 -> V_68 / 1000 ) << 15 , V_2 -> V_78 / 2 ) ;
V_11 [ 0 ] = ( V_61 >> 0 ) & 0xff ;
V_11 [ 1 ] = ( V_61 >> 8 ) & 0xff ;
V_8 = F_3 ( V_2 -> V_18 , 0x61 , V_11 , 2 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x4d , 0x02 , V_2 -> V_16 -> V_90 << 1 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x30 , 0x10 , V_2 -> V_16 -> V_91 << 4 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0x33 , V_2 -> V_16 -> V_92 ) ;
if ( V_8 )
goto V_13;
F_2 ( & V_7 -> V_2 , L_8 ,
( V_63 - V_27 -> V_67 ) ) ;
V_65 = 0x10000 * ( V_63 - V_27 -> V_67 ) ;
V_65 = F_8 ( V_65 , V_2 -> V_78 ) ;
if ( V_65 < 0 )
V_65 += 0x10000 ;
V_11 [ 0 ] = ( V_65 >> 0 ) & 0xff ;
V_11 [ 1 ] = ( V_65 >> 8 ) & 0xff ;
V_8 = F_3 ( V_2 -> V_18 , 0x5e , V_11 , 2 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0x00 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xb2 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_2 -> V_33 = V_27 -> V_33 ;
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_26 * V_27 = & V_20 -> V_28 ;
int V_8 , V_56 , V_93 ;
unsigned int V_30 ;
const struct V_94 * V_95 = NULL ;
T_1 * V_96 ;
F_2 ( & V_7 -> V_2 , L_9 ) ;
V_2 -> V_31 = false ;
V_8 = F_16 ( V_2 -> V_18 , 0x08 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x04 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x23 , 0x10 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_8 = F_5 ( V_2 -> V_18 , 0xb9 , & V_30 ) ;
if ( V_8 )
goto V_13;
F_2 ( & V_7 -> V_2 , L_10 , V_30 ) ;
if ( V_30 )
goto V_97;
V_8 = F_13 ( V_2 -> V_18 , 0x07 , 0xe0 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0x07 , 0x00 ) ;
if ( V_8 )
goto V_13;
F_20 ( & V_7 -> V_2 , L_11 ,
V_98 . V_99 . V_100 ) ;
if ( V_2 -> V_72 == V_73 )
V_96 = V_101 ;
else
V_96 = V_102 ;
V_8 = F_21 ( & V_95 , V_96 , & V_7 -> V_2 ) ;
if ( V_8 ) {
F_22 ( & V_7 -> V_2 , L_12 , V_96 ) ;
goto V_13;
}
F_20 ( & V_7 -> V_2 , L_13 ,
V_96 ) ;
V_8 = F_13 ( V_2 -> V_18 , 0xb2 , 0x01 ) ;
if ( V_8 )
goto V_103;
for ( V_93 = V_95 -> V_104 ; V_93 > 0 ;
V_93 -= ( V_2 -> V_16 -> V_17 - 1 ) ) {
V_56 = V_93 ;
if ( V_56 > ( V_2 -> V_16 -> V_17 - 1 ) )
V_56 = ( V_2 -> V_16 -> V_17 - 1 ) ;
V_8 = F_3 ( V_2 -> V_18 , 0xb0 ,
& V_95 -> V_105 [ V_95 -> V_104 - V_93 ] , V_56 ) ;
if ( V_8 ) {
F_22 ( & V_7 -> V_2 , L_14 ,
V_8 ) ;
goto V_103;
}
}
V_8 = F_13 ( V_2 -> V_18 , 0xb2 , 0x00 ) ;
if ( V_8 )
goto V_103;
F_23 ( V_95 ) ;
V_95 = NULL ;
V_8 = F_5 ( V_2 -> V_18 , 0xb9 , & V_30 ) ;
if ( V_8 )
goto V_13;
if ( ! V_30 ) {
F_20 ( & V_7 -> V_2 , L_15 ) ;
V_8 = - V_106 ;
goto V_13;
}
F_20 ( & V_7 -> V_2 , L_16 ,
V_98 . V_99 . V_100 ) ;
F_20 ( & V_7 -> V_2 , L_17 ,
( V_30 >> 4 ) & 0xf , ( V_30 >> 0 & 0xf ) ) ;
V_97:
V_2 -> V_31 = true ;
V_27 -> V_41 . V_56 = 1 ;
V_27 -> V_41 . V_46 [ 0 ] . V_47 = V_50 ;
V_27 -> V_51 . V_56 = 1 ;
V_27 -> V_51 . V_46 [ 0 ] . V_47 = V_50 ;
V_27 -> V_52 . V_56 = 1 ;
V_27 -> V_52 . V_46 [ 0 ] . V_47 = V_50 ;
return 0 ;
V_103:
F_23 ( V_95 ) ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_30 ;
F_2 ( & V_7 -> V_2 , L_9 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_33 = V_107 ;
if ( V_2 -> V_72 == V_73 )
V_30 = 0x29 ;
else
V_30 = 0x27 ;
V_8 = F_16 ( V_2 -> V_18 , V_30 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x08 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x04 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_13;
V_8 = F_16 ( V_2 -> V_18 , 0x23 , 0x10 , 0x10 ) ;
if ( V_8 )
goto V_13;
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_25 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_26 * V_27 = & V_20 -> V_28 ;
int V_8 ;
T_1 V_11 [ 3 ] ;
F_2 ( & V_7 -> V_2 , L_9 ) ;
if ( ! V_2 -> V_31 || ! ( V_2 -> V_24 & V_39 ) ) {
V_8 = 0 ;
goto V_13;
}
switch ( V_27 -> V_33 ) {
case V_34 :
V_8 = F_11 ( V_2 -> V_18 , 0xe0 , & V_11 [ 0 ] , 1 ) ;
if ( V_8 )
goto V_13;
V_8 = F_11 ( V_2 -> V_18 , 0xe6 , & V_11 [ 1 ] , 1 ) ;
if ( V_8 )
goto V_13;
switch ( ( V_11 [ 0 ] >> 2 ) & 0x01 ) {
case 0 :
V_27 -> V_69 = V_108 ;
break;
case 1 :
V_27 -> V_69 = V_109 ;
break;
}
switch ( ( V_11 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_27 -> V_110 = V_111 ;
break;
case 1 :
V_27 -> V_110 = V_112 ;
break;
case 2 :
V_27 -> V_110 = V_113 ;
break;
case 3 :
V_27 -> V_110 = V_114 ;
break;
case 4 :
V_27 -> V_110 = V_115 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_18 ) ;
}
V_27 -> V_66 = V_116 ;
break;
case V_40 :
V_8 = F_11 ( V_2 -> V_18 , 0x7e , & V_11 [ 0 ] , 1 ) ;
if ( V_8 )
goto V_13;
V_8 = F_11 ( V_2 -> V_18 , 0x89 , & V_11 [ 1 ] , 1 ) ;
if ( V_8 )
goto V_13;
V_8 = F_11 ( V_2 -> V_18 , 0xf2 , & V_11 [ 2 ] , 1 ) ;
if ( V_8 )
goto V_13;
switch ( ( V_11 [ 0 ] >> 0 ) & 0x0f ) {
case 2 :
V_27 -> V_110 = V_117 ;
break;
case 3 :
V_27 -> V_110 = V_115 ;
break;
case 4 :
V_27 -> V_110 = V_118 ;
break;
case 5 :
V_27 -> V_110 = V_114 ;
break;
case 6 :
V_27 -> V_110 = V_113 ;
break;
case 7 :
V_27 -> V_110 = V_119 ;
break;
case 8 :
V_27 -> V_110 = V_112 ;
break;
case 9 :
V_27 -> V_110 = V_120 ;
break;
case 10 :
V_27 -> V_110 = V_121 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_18 ) ;
}
switch ( ( V_11 [ 0 ] >> 5 ) & 0x01 ) {
case 0 :
V_27 -> V_70 = V_122 ;
break;
case 1 :
V_27 -> V_70 = V_123 ;
break;
}
switch ( ( V_11 [ 0 ] >> 6 ) & 0x07 ) {
case 0 :
V_27 -> V_66 = V_116 ;
break;
case 1 :
V_27 -> V_66 = V_124 ;
break;
case 2 :
V_27 -> V_66 = V_125 ;
break;
case 3 :
V_27 -> V_66 = V_126 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_19 ) ;
}
switch ( ( V_11 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_27 -> V_69 = V_108 ;
break;
case 1 :
V_27 -> V_69 = V_109 ;
break;
}
switch ( ( V_11 [ 2 ] >> 0 ) & 0x03 ) {
case 0 :
V_27 -> V_71 = V_127 ;
break;
case 1 :
V_27 -> V_71 = V_128 ;
break;
case 2 :
V_27 -> V_71 = V_129 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_20 ) ;
}
break;
default:
F_2 ( & V_7 -> V_2 , L_3 ) ;
V_8 = - V_12 ;
goto V_13;
}
V_8 = F_11 ( V_2 -> V_18 , 0x6d , V_11 , 2 ) ;
if ( V_8 )
goto V_13;
V_27 -> V_68 = 1ull * ( ( V_11 [ 1 ] << 8 ) | ( V_11 [ 0 ] << 0 ) ) *
V_2 -> V_78 * 1000 / 0x10000 ;
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_26 ( struct V_19 * V_20 , T_2 * V_130 )
{
struct V_26 * V_27 = & V_20 -> V_28 ;
if ( V_27 -> V_41 . V_46 [ 0 ] . V_47 == V_48 )
* V_130 = F_27 ( V_27 -> V_41 . V_46 [ 0 ] . V_49 , 100 ) ;
else
* V_130 = 0 ;
return 0 ;
}
static int F_28 ( struct V_19 * V_20 , T_3 * V_131 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
* V_131 = V_2 -> V_53 ;
return 0 ;
}
static int F_29 ( struct V_19 * V_20 ,
enum V_132 V_132 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_30 , V_133 , V_134 ;
F_2 ( & V_7 -> V_2 , L_21 , V_132 ) ;
if ( ! V_2 -> V_31 ) {
V_8 = - V_32 ;
goto V_13;
}
switch ( V_132 ) {
case V_135 :
V_133 = 0 ;
V_134 = 0x47 ;
break;
case V_136 :
V_133 = 1 ;
V_134 = 0x00 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_22 ) ;
V_8 = - V_12 ;
goto V_13;
}
V_30 = V_133 << 7 | V_2 -> V_16 -> V_137 << 5 ;
V_8 = F_16 ( V_2 -> V_18 , 0xa2 , 0xe0 , V_30 ) ;
if ( V_8 )
goto V_13;
V_30 = 1 << 2 ;
V_8 = F_16 ( V_2 -> V_18 , 0xa1 , V_134 , V_30 ) ;
if ( V_8 )
goto V_13;
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_30 ( struct V_19 * V_20 ,
enum V_138 V_138 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_30 ;
bool V_139 , V_140 ;
F_2 ( & V_7 -> V_2 , L_23 , V_138 ) ;
if ( ! V_2 -> V_31 ) {
V_8 = - V_32 ;
goto V_13;
}
switch ( V_138 ) {
case V_141 :
V_139 = true ;
V_140 = false ;
break;
case V_142 :
V_139 = false ;
V_140 = false ;
break;
case V_143 :
V_139 = false ;
V_140 = true ;
break;
default:
F_2 ( & V_7 -> V_2 , L_24 ) ;
V_8 = - V_12 ;
goto V_13;
}
V_139 ^= V_2 -> V_16 -> V_144 ;
V_140 ^= V_2 -> V_16 -> V_145 ;
V_30 = V_140 << 1 | V_139 << 0 ;
V_8 = F_16 ( V_2 -> V_18 , 0xa2 , 0x03 , V_30 ) ;
if ( V_8 )
goto V_13;
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_31 ( struct V_19 * V_20 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_30 ;
unsigned long V_148 ;
F_2 ( & V_7 -> V_2 , L_25 ,
V_147 -> V_149 , V_147 -> V_150 ) ;
if ( ! V_2 -> V_31 ) {
V_8 = - V_32 ;
goto V_13;
}
if ( V_147 -> V_149 < 3 || V_147 -> V_149 > 6 ) {
V_8 = - V_12 ;
goto V_13;
}
V_30 = V_2 -> V_16 -> V_137 << 5 ;
V_8 = F_16 ( V_2 -> V_18 , 0xa2 , 0xe0 , V_30 ) ;
if ( V_8 )
goto V_13;
V_8 = F_3 ( V_2 -> V_18 , 0xa3 , V_147 -> V_150 ,
V_147 -> V_149 ) ;
if ( V_8 )
goto V_13;
V_8 = F_13 ( V_2 -> V_18 , 0xa1 ,
( V_147 -> V_149 - 1 ) << 3 | 0x07 ) ;
if ( V_8 )
goto V_13;
#define F_32 120
V_148 = V_151 + F_33 ( F_32 ) ;
F_15 ( 50000 , 54000 ) ;
for ( V_30 = 1 ; ! F_34 ( V_151 , V_148 ) && V_30 ; ) {
V_8 = F_5 ( V_2 -> V_18 , 0xa1 , & V_30 ) ;
if ( V_8 )
goto V_13;
V_30 = ( V_30 >> 6 ) & 0x1 ;
}
if ( V_30 == 0 ) {
F_2 ( & V_7 -> V_2 , L_26 ,
F_35 ( V_151 ) -
( F_35 ( V_148 ) - F_32 ) ) ;
} else {
F_2 ( & V_7 -> V_2 , L_27 ) ;
V_8 = F_16 ( V_2 -> V_18 , 0xa1 , 0xc0 , 0x40 ) ;
if ( V_8 )
goto V_13;
}
V_8 = F_16 ( V_2 -> V_18 , 0xa2 , 0xc0 , 0x80 ) ;
if ( V_8 )
goto V_13;
if ( V_30 == 1 ) {
V_8 = - V_152 ;
goto V_13;
}
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_36 ( struct V_19 * V_20 ,
enum V_153 V_153 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_30 , V_154 ;
unsigned long V_148 ;
F_2 ( & V_7 -> V_2 , L_28 , V_153 ) ;
if ( ! V_2 -> V_31 ) {
V_8 = - V_32 ;
goto V_13;
}
V_30 = V_2 -> V_16 -> V_137 << 5 ;
V_8 = F_16 ( V_2 -> V_18 , 0xa2 , 0xe0 , V_30 ) ;
if ( V_8 )
goto V_13;
switch ( V_153 ) {
case V_155 :
V_154 = 0x02 ;
break;
case V_156 :
V_154 = 0x01 ;
break;
default:
F_2 ( & V_7 -> V_2 , L_29 ) ;
V_8 = - V_12 ;
goto V_13;
}
V_8 = F_13 ( V_2 -> V_18 , 0xa1 , V_154 ) ;
if ( V_8 )
goto V_13;
#define F_37 40
V_148 = V_151 + F_33 ( F_37 ) ;
F_15 ( 8500 , 12500 ) ;
for ( V_30 = 1 ; ! F_34 ( V_151 , V_148 ) && V_30 ; ) {
V_8 = F_5 ( V_2 -> V_18 , 0xa1 , & V_30 ) ;
if ( V_8 )
goto V_13;
V_30 = ( V_30 >> 6 ) & 0x1 ;
}
if ( V_30 == 0 ) {
F_2 ( & V_7 -> V_2 , L_26 ,
F_35 ( V_151 ) -
( F_35 ( V_148 ) - F_37 ) ) ;
} else {
F_2 ( & V_7 -> V_2 , L_27 ) ;
V_8 = F_16 ( V_2 -> V_18 , 0xa1 , 0xc0 , 0x40 ) ;
if ( V_8 )
goto V_13;
}
V_8 = F_16 ( V_2 -> V_18 , 0xa2 , 0xc0 , 0x80 ) ;
if ( V_8 )
goto V_13;
if ( V_30 == 1 ) {
V_8 = - V_152 ;
goto V_13;
}
return 0 ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_38 ( struct V_19 * V_20 ,
struct V_157 * V_158 )
{
V_158 -> V_159 = 3000 ;
return 0 ;
}
static void F_39 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_40 ( V_7 ) ;
}
static int F_41 ( struct V_160 * V_161 , void * V_162 , T_3 V_163 )
{
struct V_1 * V_2 = V_162 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
struct V_164 V_150 = {
. V_165 = V_7 -> V_165 ,
. V_166 = 0 ,
. V_56 = 2 ,
. V_11 = L_30 ,
} ;
V_8 = F_42 ( V_7 -> V_167 , & V_150 , 1 ) ;
if ( V_8 != 1 ) {
F_43 ( & V_7 -> V_2 , L_31 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_168 ;
return V_8 ;
}
return 0 ;
}
struct V_19 * F_44 ( const struct V_169 * V_16 ,
struct V_160 * V_170 , struct V_160 * * V_171 )
{
struct V_6 * V_7 ;
struct V_172 V_173 ;
struct V_174 V_175 ;
V_175 . V_176 = V_16 -> clock ;
V_175 . V_17 = V_16 -> V_17 ;
V_175 . V_79 = V_16 -> V_79 ;
V_175 . V_82 = V_16 -> V_82 ;
V_175 . V_89 = V_16 -> V_89 ;
V_175 . V_90 = V_16 -> V_90 ;
V_175 . V_92 = V_16 -> V_92 ;
V_175 . V_91 = V_16 -> V_91 ;
V_175 . V_177 = V_16 -> V_178 ;
V_175 . V_137 = V_16 -> V_137 ;
V_175 . V_144 = V_16 -> V_144 ;
V_175 . V_145 = V_16 -> V_145 ;
V_175 . V_179 = true ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
F_45 ( V_173 . type , L_32 , V_180 ) ;
V_173 . V_165 = V_16 -> V_181 ;
V_173 . V_182 = & V_175 ;
V_7 = F_46 ( V_170 , & V_173 ) ;
if ( ! V_7 || ! V_7 -> V_2 . V_183 )
return NULL ;
* V_171 = V_175 . V_184 ( V_7 ) ;
return V_175 . V_185 ( V_7 ) ;
}
static struct V_19 * F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_48 ( V_7 ) ;
F_2 ( & V_7 -> V_2 , L_9 ) ;
return & V_2 -> V_20 ;
}
static struct V_160 * F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_48 ( V_7 ) ;
F_2 ( & V_7 -> V_2 , L_9 ) ;
return V_2 -> V_160 ;
}
static int F_50 ( struct V_6 * V_7 ,
const struct V_186 * V_187 )
{
struct V_1 * V_2 ;
struct V_174 * V_175 = V_7 -> V_2 . V_182 ;
int V_8 ;
unsigned int V_30 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_188 ) ;
if ( ! V_2 ) {
V_8 = - V_189 ;
goto V_13;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_190 . clock = V_175 -> V_176 ;
V_2 -> V_190 . V_17 = V_175 -> V_17 ;
V_2 -> V_190 . V_79 = V_175 -> V_79 ;
V_2 -> V_190 . V_82 = V_175 -> V_82 ;
V_2 -> V_190 . V_89 = V_175 -> V_89 ;
V_2 -> V_190 . V_90 = V_175 -> V_90 ;
V_2 -> V_190 . V_91 = V_175 -> V_91 ;
V_2 -> V_190 . V_178 = V_175 -> V_177 ;
V_2 -> V_190 . V_137 = V_175 -> V_137 ;
V_2 -> V_190 . V_92 = V_175 -> V_92 ;
V_2 -> V_190 . V_144 = V_175 -> V_144 ;
V_2 -> V_190 . V_145 = V_175 -> V_145 ;
V_2 -> V_16 = & V_2 -> V_190 ;
V_2 -> V_191 . V_192 = 8 ,
V_2 -> V_191 . V_193 = 8 ,
V_2 -> V_191 . V_194 = V_2 ,
V_2 -> V_18 = F_52 ( V_7 , & V_2 -> V_191 ) ;
if ( F_53 ( V_2 -> V_18 ) ) {
V_8 = F_54 ( V_2 -> V_18 ) ;
goto V_195;
}
V_8 = F_5 ( V_2 -> V_18 , 0x00 , & V_30 ) ;
if ( V_8 )
goto V_195;
V_2 -> V_72 = V_30 >> 1 ;
F_2 ( & V_7 -> V_2 , L_33 , V_2 -> V_72 ) ;
switch ( V_2 -> V_72 ) {
case V_73 :
case V_196 :
break;
default:
goto V_195;
}
switch ( V_2 -> V_16 -> V_178 ) {
case V_197 :
V_30 = 0x80 ;
break;
case V_198 :
V_30 = 0x00 ;
break;
case V_199 :
V_30 = 0x10 ;
break;
default:
V_8 = - V_12 ;
goto V_195;
}
if ( V_2 -> V_72 == V_73 )
V_30 = 0x00 ;
V_8 = F_13 ( V_2 -> V_18 , 0x29 , V_30 ) ;
if ( V_8 )
goto V_195;
V_8 = F_16 ( V_2 -> V_18 , 0x08 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_195;
V_8 = F_16 ( V_2 -> V_18 , 0x04 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_195;
V_8 = F_16 ( V_2 -> V_18 , 0x23 , 0x10 , 0x10 ) ;
if ( V_8 )
goto V_195;
V_2 -> V_160 = F_55 ( V_7 -> V_167 , & V_7 -> V_2 ,
V_2 , 0 , 0 , 0 , F_41 ,
NULL ) ;
if ( V_2 -> V_160 == NULL ) {
V_8 = - V_189 ;
goto V_195;
}
memcpy ( & V_2 -> V_20 . V_74 , & V_98 , sizeof( struct V_200 ) ) ;
if ( V_2 -> V_72 == V_73 )
strncpy ( V_2 -> V_20 . V_74 . V_99 . V_100 , L_34 ,
sizeof( V_2 -> V_20 . V_74 . V_99 . V_100 ) ) ;
if ( ! V_175 -> V_179 )
V_2 -> V_20 . V_74 . V_201 = NULL ;
V_2 -> V_20 . V_22 = V_2 ;
F_56 ( V_7 , V_2 ) ;
V_175 -> V_185 = F_47 ;
V_175 -> V_184 = F_49 ;
return 0 ;
V_195:
F_57 ( V_2 ) ;
V_13:
F_2 ( & V_7 -> V_2 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_48 ( V_7 ) ;
F_2 ( & V_7 -> V_2 , L_9 ) ;
F_59 ( V_2 -> V_160 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
