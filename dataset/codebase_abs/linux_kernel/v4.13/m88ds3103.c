static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
int V_6 ;
T_1 V_7 ;
if ( V_4 != 0xff ) {
V_6 = F_2 ( V_2 -> V_8 , V_3 , & V_7 , 1 ) ;
if ( V_6 )
return V_6 ;
V_5 &= V_4 ;
V_7 &= ~ V_4 ;
V_5 |= V_7 ;
}
return F_3 ( V_2 -> V_8 , V_3 , & V_5 , 1 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 , V_14 , V_15 ;
T_1 V_16 [ 83 ] ;
F_5 ( & V_13 -> V_2 , L_1 , V_11 ) ;
if ( V_11 > 86 ) {
V_6 = - V_17 ;
goto V_18;
}
for ( V_14 = 0 , V_15 = 0 ; V_14 < V_11 ; V_14 ++ , V_15 ++ ) {
V_16 [ V_15 ] = V_10 [ V_14 ] . V_5 ;
if ( V_14 == V_11 - 1 || V_10 [ V_14 ] . V_3 != V_10 [ V_14 + 1 ] . V_3 - 1 ||
! ( ( V_15 + 1 ) % ( V_2 -> V_19 -> V_20 - 1 ) ) ) {
V_6 = F_3 ( V_2 -> V_8 , V_10 [ V_14 ] . V_3 - V_15 , V_16 , V_15 + 1 ) ;
if ( V_6 )
goto V_18;
V_15 = - 1 ;
}
}
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
int F_6 ( struct V_21 * V_22 , T_1 * V_23 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
unsigned V_7 ;
int V_6 ;
V_6 = F_7 ( V_2 -> V_8 , 0x3f , & V_7 ) ;
if ( V_6 == 0 )
* V_23 = V_7 ;
return V_6 ;
}
static int F_8 ( struct V_21 * V_22 ,
enum V_25 * V_26 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_27 * V_28 = & V_22 -> V_29 ;
int V_6 , V_14 , V_30 ;
unsigned int V_31 ;
T_1 V_16 [ 3 ] ;
* V_26 = 0 ;
if ( ! V_2 -> V_32 ) {
V_6 = - V_33 ;
goto V_18;
}
switch ( V_28 -> V_34 ) {
case V_35 :
V_6 = F_7 ( V_2 -> V_8 , 0xd1 , & V_31 ) ;
if ( V_6 )
goto V_18;
if ( ( V_31 & 0x07 ) == 0x07 )
* V_26 = V_36 | V_37 |
V_38 | V_39 |
V_40 ;
break;
case V_41 :
V_6 = F_7 ( V_2 -> V_8 , 0x0d , & V_31 ) ;
if ( V_6 )
goto V_18;
if ( ( V_31 & 0x8f ) == 0x8f )
* V_26 = V_36 | V_37 |
V_38 | V_39 |
V_40 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_3 ) ;
V_6 = - V_17 ;
goto V_18;
}
V_2 -> V_25 = * V_26 ;
F_5 ( & V_13 -> V_2 , L_4 , V_31 , * V_26 ) ;
if ( V_2 -> V_25 & V_38 ) {
unsigned int V_42 , V_43 , signal , V_44 , V_45 ;
V_42 = 0 ;
#define F_9 3
switch ( V_28 -> V_34 ) {
case V_35 :
V_30 = 0 ;
for ( V_14 = 0 ; V_14 < F_9 ; V_14 ++ ) {
V_6 = F_7 ( V_2 -> V_8 , 0xff , & V_31 ) ;
if ( V_6 )
goto V_18;
V_30 += V_31 ;
}
V_30 = F_10 ( V_30 , 8 * F_9 ) ;
if ( V_30 )
V_42 = F_11 ( ( V_46 ) 10000 * F_12 ( V_30 ) , F_12 ( 10 ) ) ;
break;
case V_41 :
V_44 = 0 ;
V_45 = 0 ;
for ( V_14 = 0 ; V_14 < F_9 ; V_14 ++ ) {
V_6 = F_2 ( V_2 -> V_8 , 0x8c , V_16 , 3 ) ;
if ( V_6 )
goto V_18;
V_43 = V_16 [ 1 ] << 6 ;
V_43 |= V_16 [ 0 ] & 0x3f ;
V_43 >>= 2 ;
signal = V_16 [ 2 ] * V_16 [ 2 ] ;
signal >>= 1 ;
V_44 += V_43 ;
V_45 += signal ;
}
V_43 = V_44 / F_9 ;
signal = V_45 / F_9 ;
if ( signal > V_43 ) {
V_30 = signal / V_43 ;
V_42 = F_11 ( ( V_46 ) 10000 * F_13 ( V_30 ) , ( 1 << 24 ) ) ;
}
break;
default:
F_5 ( & V_13 -> V_2 , L_3 ) ;
V_6 = - V_17 ;
goto V_18;
}
if ( V_42 ) {
V_28 -> V_42 . V_47 [ 0 ] . V_48 = V_49 ;
V_28 -> V_42 . V_47 [ 0 ] . V_50 = V_42 ;
} else {
V_28 -> V_42 . V_47 [ 0 ] . V_48 = V_51 ;
}
} else {
V_28 -> V_42 . V_47 [ 0 ] . V_48 = V_51 ;
}
if ( V_2 -> V_25 & V_40 ) {
unsigned int V_31 , V_52 , V_53 ;
switch ( V_28 -> V_34 ) {
case V_35 :
V_6 = F_14 ( V_2 -> V_8 , 0xf9 , 0x04 ) ;
if ( V_6 )
goto V_18;
V_6 = F_7 ( V_2 -> V_8 , 0xf8 , & V_31 ) ;
if ( V_6 )
goto V_18;
if ( ! ( V_31 & 0x10 ) ) {
V_6 = F_2 ( V_2 -> V_8 , 0xf6 , V_16 , 2 ) ;
if ( V_6 )
goto V_18;
V_52 = V_16 [ 1 ] << 8 | V_16 [ 0 ] << 0 ;
V_53 = 0x800000 ;
V_2 -> V_52 += V_52 ;
V_2 -> V_53 += V_53 ;
V_2 -> V_54 = V_52 ;
V_31 |= 0x10 ;
V_6 = F_14 ( V_2 -> V_8 , 0xf8 , V_31 ) ;
if ( V_6 )
goto V_18;
}
break;
case V_41 :
V_6 = F_2 ( V_2 -> V_8 , 0xd5 , V_16 , 3 ) ;
if ( V_6 )
goto V_18;
V_31 = V_16 [ 2 ] << 16 | V_16 [ 1 ] << 8 | V_16 [ 0 ] << 0 ;
if ( V_31 > 4000 ) {
V_6 = F_2 ( V_2 -> V_8 , 0xf7 , V_16 , 2 ) ;
if ( V_6 )
goto V_18;
V_52 = V_16 [ 1 ] << 8 | V_16 [ 0 ] << 0 ;
V_53 = 32 * V_31 ;
V_2 -> V_52 += V_52 ;
V_2 -> V_53 += V_53 ;
V_2 -> V_54 = V_52 ;
V_6 = F_14 ( V_2 -> V_8 , 0xd1 , 0x01 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xf9 , 0x01 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xf9 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xd1 , 0x00 ) ;
if ( V_6 )
goto V_18;
}
break;
default:
F_5 ( & V_13 -> V_2 , L_3 ) ;
V_6 = - V_17 ;
goto V_18;
}
V_28 -> V_52 . V_47 [ 0 ] . V_48 = V_55 ;
V_28 -> V_52 . V_47 [ 0 ] . V_56 = V_2 -> V_52 ;
V_28 -> V_53 . V_47 [ 0 ] . V_48 = V_55 ;
V_28 -> V_53 . V_47 [ 0 ] . V_56 = V_2 -> V_53 ;
} else {
V_28 -> V_52 . V_47 [ 0 ] . V_48 = V_51 ;
V_28 -> V_53 . V_47 [ 0 ] . V_48 = V_51 ;
}
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_27 * V_28 = & V_22 -> V_29 ;
int V_6 , V_57 ;
const struct V_9 * V_58 ;
T_1 V_59 , V_60 = 0 , V_61 = 0 ;
T_1 V_16 [ 3 ] ;
T_2 V_62 ;
T_3 V_63 , V_64 ;
T_4 V_65 ;
F_5 ( & V_13 -> V_2 ,
L_5 ,
V_28 -> V_34 , V_28 -> V_66 , V_28 -> V_67 , V_28 -> V_68 ,
V_28 -> V_69 , V_28 -> V_70 , V_28 -> V_71 ) ;
if ( ! V_2 -> V_32 ) {
V_6 = - V_33 ;
goto V_18;
}
V_6 = F_14 ( V_2 -> V_8 , 0x07 , 0x80 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0x07 , 0x00 ) ;
if ( V_6 )
goto V_18;
if ( V_2 -> V_72 == V_73 ) {
V_6 = F_14 ( V_2 -> V_8 , 0x06 , 0xe0 ) ;
if ( V_6 )
goto V_18;
}
if ( V_22 -> V_74 . V_75 . V_76 ) {
V_6 = V_22 -> V_74 . V_75 . V_76 ( V_22 ) ;
if ( V_6 )
goto V_18;
}
if ( V_22 -> V_74 . V_75 . V_77 ) {
V_6 = V_22 -> V_74 . V_75 . V_77 ( V_22 , & V_63 ) ;
if ( V_6 )
goto V_18;
} else {
V_63 = V_28 -> V_67 ;
}
if ( V_2 -> V_72 == V_73 ) {
if ( V_28 -> V_68 > 45010000 )
V_2 -> V_78 = 110250000 ;
else
V_2 -> V_78 = 96000000 ;
if ( V_28 -> V_34 == V_35 )
V_64 = 96000000 ;
else
V_64 = 144000000 ;
V_6 = F_14 ( V_2 -> V_8 , 0x06 , 0x00 ) ;
if ( V_6 )
goto V_18;
F_16 ( 10000 , 20000 ) ;
} else {
V_2 -> V_78 = 96000000 ;
switch ( V_2 -> V_19 -> V_79 ) {
case V_80 :
case V_81 :
V_64 = V_2 -> V_19 -> V_82 ;
break;
case V_83 :
case V_84 :
if ( V_28 -> V_34 == V_35 )
V_64 = 96000000 ;
else {
if ( V_28 -> V_68 < 18000000 )
V_64 = 96000000 ;
else if ( V_28 -> V_68 < 28000000 )
V_64 = 144000000 ;
else
V_64 = 192000000 ;
}
break;
default:
F_5 ( & V_13 -> V_2 , L_6 ) ;
V_6 = - V_17 ;
goto V_18;
}
switch ( V_64 ) {
case 96000000 :
V_60 = 0x02 ;
V_61 = 0x01 ;
break;
case 144000000 :
V_60 = 0x00 ;
V_61 = 0x01 ;
break;
case 192000000 :
V_60 = 0x03 ;
V_61 = 0x00 ;
break;
}
V_6 = F_1 ( V_2 , 0x22 , 0xc0 , V_60 << 6 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x24 , 0xc0 , V_61 << 6 ) ;
if ( V_6 )
goto V_18;
}
V_6 = F_14 ( V_2 -> V_8 , 0xb2 , 0x01 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_18;
switch ( V_28 -> V_34 ) {
case V_35 :
if ( V_2 -> V_72 == V_73 ) {
V_57 = F_17 ( V_85 ) ;
V_58 = V_85 ;
} else {
V_57 = F_17 ( V_86 ) ;
V_58 = V_86 ;
}
break;
case V_41 :
if ( V_2 -> V_72 == V_73 ) {
V_57 = F_17 ( V_87 ) ;
V_58 = V_87 ;
} else {
V_57 = F_17 ( V_88 ) ;
V_58 = V_88 ;
}
break;
default:
F_5 ( & V_13 -> V_2 , L_3 ) ;
V_6 = - V_17 ;
goto V_18;
}
if ( V_28 -> V_34 != V_2 -> V_34 ) {
V_6 = F_4 ( V_2 , V_58 , V_57 ) ;
if ( V_6 )
goto V_18;
}
if ( V_2 -> V_72 == V_73 ) {
if ( V_28 -> V_34 == V_41 &&
V_28 -> V_68 <= 5000000 ) {
V_6 = F_14 ( V_2 -> V_8 , 0xc0 , 0x04 ) ;
if ( V_6 )
goto V_18;
V_16 [ 0 ] = 0x09 ;
V_16 [ 1 ] = 0x22 ;
V_16 [ 2 ] = 0x88 ;
V_6 = F_3 ( V_2 -> V_8 , 0x8a , V_16 , 3 ) ;
if ( V_6 )
goto V_18;
}
V_6 = F_1 ( V_2 , 0x9d , 0x08 , 0x08 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xf1 , 0x01 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x30 , 0x80 , 0x80 ) ;
if ( V_6 )
goto V_18;
}
switch ( V_2 -> V_19 -> V_79 ) {
case V_80 :
V_60 = 0x00 ;
V_59 = 0x06 ;
break;
case V_81 :
V_60 = 0x20 ;
V_59 = 0x06 ;
break;
case V_83 :
V_59 = 0x02 ;
break;
case V_84 :
V_59 = 0x03 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_6 ) ;
V_6 = - V_17 ;
goto V_18;
}
if ( V_2 -> V_19 -> V_89 )
V_59 |= 0x40 ;
V_6 = F_14 ( V_2 -> V_8 , 0xfd , V_59 ) ;
if ( V_6 )
goto V_18;
switch ( V_2 -> V_19 -> V_79 ) {
case V_80 :
case V_81 :
V_6 = F_1 ( V_2 , 0x29 , 0x20 , V_60 ) ;
if ( V_6 )
goto V_18;
V_62 = 0 ;
V_60 = 0x3f ;
V_61 = 0x3f ;
break;
default:
V_62 = F_18 ( V_64 , V_2 -> V_19 -> V_82 ) ;
V_60 = V_62 / 2 - 1 ;
V_61 = F_18 ( V_62 , 2 ) - 1 ;
}
F_5 ( & V_13 -> V_2 , L_7 ,
V_64 , V_2 -> V_19 -> V_82 , V_62 ) ;
V_59 = ( V_60 >> 2 ) & 0x0f ;
V_6 = F_19 ( V_2 -> V_8 , 0xfe , 0x0f , V_59 ) ;
if ( V_6 )
goto V_18;
V_59 = ( ( V_60 & 0x03 ) << 6 ) | V_61 >> 0 ;
V_6 = F_14 ( V_2 -> V_8 , 0xea , V_59 ) ;
if ( V_6 )
goto V_18;
if ( V_28 -> V_68 <= 3000000 )
V_59 = 0x20 ;
else if ( V_28 -> V_68 <= 10000000 )
V_59 = 0x10 ;
else
V_59 = 0x06 ;
V_6 = F_14 ( V_2 -> V_8 , 0xc3 , 0x08 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xc8 , V_59 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xc4 , 0x08 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xc7 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_62 = F_20 ( ( V_46 ) V_28 -> V_68 * 0x10000 , V_2 -> V_78 ) ;
V_16 [ 0 ] = ( V_62 >> 0 ) & 0xff ;
V_16 [ 1 ] = ( V_62 >> 8 ) & 0xff ;
V_6 = F_3 ( V_2 -> V_8 , 0x61 , V_16 , 2 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x4d , 0x02 , V_2 -> V_19 -> V_90 << 1 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x30 , 0x10 , V_2 -> V_19 -> V_91 << 4 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0x33 , V_2 -> V_19 -> V_92 ) ;
if ( V_6 )
goto V_18;
F_5 ( & V_13 -> V_2 , L_8 ,
( V_63 - V_28 -> V_67 ) ) ;
V_65 = 0x10000 * ( V_63 - V_28 -> V_67 ) ;
V_65 = F_10 ( V_65 , V_2 -> V_78 / 1000 ) ;
V_16 [ 0 ] = ( V_65 >> 0 ) & 0xff ;
V_16 [ 1 ] = ( V_65 >> 8 ) & 0xff ;
V_6 = F_3 ( V_2 -> V_8 , 0x5e , V_16 , 2 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xb2 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_2 -> V_34 = V_28 -> V_34 ;
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_27 * V_28 = & V_22 -> V_29 ;
int V_6 , V_57 , V_93 ;
unsigned int V_31 ;
const struct V_94 * V_94 ;
const char * V_95 ;
F_5 ( & V_13 -> V_2 , L_9 ) ;
V_2 -> V_32 = false ;
V_6 = F_1 ( V_2 , 0x08 , 0x01 , 0x01 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x04 , 0x01 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x23 , 0x10 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_6 = F_7 ( V_2 -> V_8 , 0xb9 , & V_31 ) ;
if ( V_6 )
goto V_18;
F_5 ( & V_13 -> V_2 , L_10 , V_31 ) ;
if ( V_31 )
goto V_32;
V_6 = F_14 ( V_2 -> V_8 , 0x07 , 0xe0 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0x07 , 0x00 ) ;
if ( V_6 )
goto V_18;
F_22 ( & V_13 -> V_2 , L_11 ,
V_96 . V_97 . V_95 ) ;
if ( V_2 -> V_72 == V_73 )
V_95 = V_98 ;
else
V_95 = V_99 ;
V_6 = F_23 ( & V_94 , V_95 , & V_13 -> V_2 ) ;
if ( V_6 ) {
F_24 ( & V_13 -> V_2 , L_12 , V_95 ) ;
goto V_18;
}
F_22 ( & V_13 -> V_2 , L_13 , V_95 ) ;
V_6 = F_14 ( V_2 -> V_8 , 0xb2 , 0x01 ) ;
if ( V_6 )
goto V_100;
for ( V_93 = V_94 -> V_101 ; V_93 > 0 ; V_93 -= ( V_2 -> V_19 -> V_20 - 1 ) ) {
V_57 = F_25 ( V_2 -> V_19 -> V_20 - 1 , V_93 ) ;
V_6 = F_3 ( V_2 -> V_8 , 0xb0 ,
& V_94 -> V_102 [ V_94 -> V_101 - V_93 ] ,
V_57 ) ;
if ( V_6 ) {
F_24 ( & V_13 -> V_2 , L_14 ,
V_6 ) ;
goto V_100;
}
}
V_6 = F_14 ( V_2 -> V_8 , 0xb2 , 0x00 ) ;
if ( V_6 )
goto V_100;
F_26 ( V_94 ) ;
V_6 = F_7 ( V_2 -> V_8 , 0xb9 , & V_31 ) ;
if ( V_6 )
goto V_18;
if ( ! V_31 ) {
V_6 = - V_17 ;
F_22 ( & V_13 -> V_2 , L_15 ) ;
goto V_18;
}
F_22 ( & V_13 -> V_2 , L_16 ,
V_96 . V_97 . V_95 ) ;
F_22 ( & V_13 -> V_2 , L_17 ,
( V_31 >> 4 ) & 0xf , ( V_31 >> 0 & 0xf ) ) ;
V_32:
V_2 -> V_32 = true ;
V_28 -> V_42 . V_57 = 1 ;
V_28 -> V_42 . V_47 [ 0 ] . V_48 = V_51 ;
V_28 -> V_52 . V_57 = 1 ;
V_28 -> V_52 . V_47 [ 0 ] . V_48 = V_51 ;
V_28 -> V_53 . V_57 = 1 ;
V_28 -> V_53 . V_47 [ 0 ] . V_48 = V_51 ;
return 0 ;
V_100:
F_26 ( V_94 ) ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_27 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 ;
unsigned int V_31 ;
F_5 ( & V_13 -> V_2 , L_9 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_34 = V_103 ;
if ( V_2 -> V_72 == V_73 )
V_31 = 0x29 ;
else
V_31 = 0x27 ;
V_6 = F_1 ( V_2 , V_31 , 0x01 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x08 , 0x01 , 0x00 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x04 , 0x01 , 0x01 ) ;
if ( V_6 )
goto V_18;
V_6 = F_1 ( V_2 , 0x23 , 0x10 , 0x10 ) ;
if ( V_6 )
goto V_18;
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_28 ( struct V_21 * V_22 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 ;
T_1 V_16 [ 3 ] ;
F_5 ( & V_13 -> V_2 , L_9 ) ;
if ( ! V_2 -> V_32 || ! ( V_2 -> V_25 & V_40 ) ) {
V_6 = 0 ;
goto V_18;
}
switch ( V_28 -> V_34 ) {
case V_35 :
V_6 = F_2 ( V_2 -> V_8 , 0xe0 , & V_16 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_18;
V_6 = F_2 ( V_2 -> V_8 , 0xe6 , & V_16 [ 1 ] , 1 ) ;
if ( V_6 )
goto V_18;
switch ( ( V_16 [ 0 ] >> 2 ) & 0x01 ) {
case 0 :
V_28 -> V_69 = V_104 ;
break;
case 1 :
V_28 -> V_69 = V_105 ;
break;
}
switch ( ( V_16 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_28 -> V_106 = V_107 ;
break;
case 1 :
V_28 -> V_106 = V_108 ;
break;
case 2 :
V_28 -> V_106 = V_109 ;
break;
case 3 :
V_28 -> V_106 = V_110 ;
break;
case 4 :
V_28 -> V_106 = V_111 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_18 ) ;
}
V_28 -> V_66 = V_112 ;
break;
case V_41 :
V_6 = F_2 ( V_2 -> V_8 , 0x7e , & V_16 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_18;
V_6 = F_2 ( V_2 -> V_8 , 0x89 , & V_16 [ 1 ] , 1 ) ;
if ( V_6 )
goto V_18;
V_6 = F_2 ( V_2 -> V_8 , 0xf2 , & V_16 [ 2 ] , 1 ) ;
if ( V_6 )
goto V_18;
switch ( ( V_16 [ 0 ] >> 0 ) & 0x0f ) {
case 2 :
V_28 -> V_106 = V_113 ;
break;
case 3 :
V_28 -> V_106 = V_111 ;
break;
case 4 :
V_28 -> V_106 = V_114 ;
break;
case 5 :
V_28 -> V_106 = V_110 ;
break;
case 6 :
V_28 -> V_106 = V_109 ;
break;
case 7 :
V_28 -> V_106 = V_115 ;
break;
case 8 :
V_28 -> V_106 = V_108 ;
break;
case 9 :
V_28 -> V_106 = V_116 ;
break;
case 10 :
V_28 -> V_106 = V_117 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_18 ) ;
}
switch ( ( V_16 [ 0 ] >> 5 ) & 0x01 ) {
case 0 :
V_28 -> V_70 = V_118 ;
break;
case 1 :
V_28 -> V_70 = V_119 ;
break;
}
switch ( ( V_16 [ 0 ] >> 6 ) & 0x07 ) {
case 0 :
V_28 -> V_66 = V_112 ;
break;
case 1 :
V_28 -> V_66 = V_120 ;
break;
case 2 :
V_28 -> V_66 = V_121 ;
break;
case 3 :
V_28 -> V_66 = V_122 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_19 ) ;
}
switch ( ( V_16 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_28 -> V_69 = V_104 ;
break;
case 1 :
V_28 -> V_69 = V_105 ;
break;
}
switch ( ( V_16 [ 2 ] >> 0 ) & 0x03 ) {
case 0 :
V_28 -> V_71 = V_123 ;
break;
case 1 :
V_28 -> V_71 = V_124 ;
break;
case 2 :
V_28 -> V_71 = V_125 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_20 ) ;
}
break;
default:
F_5 ( & V_13 -> V_2 , L_3 ) ;
V_6 = - V_17 ;
goto V_18;
}
V_6 = F_2 ( V_2 -> V_8 , 0x6d , V_16 , 2 ) ;
if ( V_6 )
goto V_18;
V_28 -> V_68 = F_20 ( ( V_46 ) ( V_16 [ 1 ] << 8 | V_16 [ 0 ] << 0 ) * V_2 -> V_78 , 0x10000 ) ;
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_29 ( struct V_21 * V_22 , T_2 * V_126 )
{
struct V_27 * V_28 = & V_22 -> V_29 ;
if ( V_28 -> V_42 . V_47 [ 0 ] . V_48 == V_49 )
* V_126 = F_30 ( V_28 -> V_42 . V_47 [ 0 ] . V_50 , 100 ) ;
else
* V_126 = 0 ;
return 0 ;
}
static int F_31 ( struct V_21 * V_22 , T_3 * V_127 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
* V_127 = V_2 -> V_54 ;
return 0 ;
}
static int F_32 ( struct V_21 * V_22 ,
enum V_128 V_128 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 ;
unsigned int V_31 , V_129 , V_130 ;
F_5 ( & V_13 -> V_2 , L_21 , V_128 ) ;
if ( ! V_2 -> V_32 ) {
V_6 = - V_33 ;
goto V_18;
}
switch ( V_128 ) {
case V_131 :
V_129 = 0 ;
V_130 = 0x47 ;
break;
case V_132 :
V_129 = 1 ;
V_130 = 0x00 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_22 ) ;
V_6 = - V_17 ;
goto V_18;
}
V_31 = V_129 << 7 | V_2 -> V_19 -> V_133 << 5 ;
V_6 = F_1 ( V_2 , 0xa2 , 0xe0 , V_31 ) ;
if ( V_6 )
goto V_18;
V_31 = 1 << 2 ;
V_6 = F_1 ( V_2 , 0xa1 , V_130 , V_31 ) ;
if ( V_6 )
goto V_18;
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_33 ( struct V_21 * V_22 ,
enum V_134 V_134 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 ;
unsigned int V_31 ;
bool V_135 , V_136 ;
F_5 ( & V_13 -> V_2 , L_23 , V_134 ) ;
if ( ! V_2 -> V_32 ) {
V_6 = - V_33 ;
goto V_18;
}
switch ( V_134 ) {
case V_137 :
V_135 = true ;
V_136 = false ;
break;
case V_138 :
V_135 = false ;
V_136 = false ;
break;
case V_139 :
V_135 = false ;
V_136 = true ;
break;
default:
F_5 ( & V_13 -> V_2 , L_24 ) ;
V_6 = - V_17 ;
goto V_18;
}
V_135 ^= V_2 -> V_19 -> V_140 ;
V_136 ^= V_2 -> V_19 -> V_141 ;
V_31 = V_136 << 1 | V_135 << 0 ;
V_6 = F_1 ( V_2 , 0xa2 , 0x03 , V_31 ) ;
if ( V_6 )
goto V_18;
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_34 ( struct V_21 * V_22 ,
struct V_142 * V_143 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 ;
unsigned int V_31 ;
unsigned long V_144 ;
F_5 ( & V_13 -> V_2 , L_25 ,
V_143 -> V_145 , V_143 -> V_146 ) ;
if ( ! V_2 -> V_32 ) {
V_6 = - V_33 ;
goto V_18;
}
if ( V_143 -> V_145 < 3 || V_143 -> V_145 > 6 ) {
V_6 = - V_17 ;
goto V_18;
}
V_31 = V_2 -> V_19 -> V_133 << 5 ;
V_6 = F_1 ( V_2 , 0xa2 , 0xe0 , V_31 ) ;
if ( V_6 )
goto V_18;
V_6 = F_3 ( V_2 -> V_8 , 0xa3 , V_143 -> V_146 ,
V_143 -> V_145 ) ;
if ( V_6 )
goto V_18;
V_6 = F_14 ( V_2 -> V_8 , 0xa1 ,
( V_143 -> V_145 - 1 ) << 3 | 0x07 ) ;
if ( V_6 )
goto V_18;
#define F_35 120
V_144 = V_147 + F_36 ( F_35 ) ;
V_31 = V_143 -> V_145 * 13500 ;
F_16 ( V_31 - 4000 , V_31 ) ;
for ( V_31 = 1 ; ! F_37 ( V_147 , V_144 ) && V_31 ; ) {
V_6 = F_7 ( V_2 -> V_8 , 0xa1 , & V_31 ) ;
if ( V_6 )
goto V_18;
V_31 = ( V_31 >> 6 ) & 0x1 ;
}
if ( V_31 == 0 ) {
F_5 ( & V_13 -> V_2 , L_26 ,
F_38 ( V_147 ) -
( F_38 ( V_144 ) - F_35 ) ) ;
} else {
F_5 ( & V_13 -> V_2 , L_27 ) ;
V_6 = F_1 ( V_2 , 0xa1 , 0xc0 , 0x40 ) ;
if ( V_6 )
goto V_18;
}
V_6 = F_1 ( V_2 , 0xa2 , 0xc0 , 0x80 ) ;
if ( V_6 )
goto V_18;
if ( V_31 == 1 ) {
V_6 = - V_148 ;
goto V_18;
}
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_39 ( struct V_21 * V_22 ,
enum V_149 V_149 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 ;
unsigned int V_31 , V_150 ;
unsigned long V_144 ;
F_5 ( & V_13 -> V_2 , L_28 , V_149 ) ;
if ( ! V_2 -> V_32 ) {
V_6 = - V_33 ;
goto V_18;
}
V_31 = V_2 -> V_19 -> V_133 << 5 ;
V_6 = F_1 ( V_2 , 0xa2 , 0xe0 , V_31 ) ;
if ( V_6 )
goto V_18;
switch ( V_149 ) {
case V_151 :
V_150 = 0x02 ;
break;
case V_152 :
V_150 = 0x01 ;
break;
default:
F_5 ( & V_13 -> V_2 , L_29 ) ;
V_6 = - V_17 ;
goto V_18;
}
V_6 = F_14 ( V_2 -> V_8 , 0xa1 , V_150 ) ;
if ( V_6 )
goto V_18;
#define F_40 40
V_144 = V_147 + F_36 ( F_40 ) ;
F_16 ( 8500 , 12500 ) ;
for ( V_31 = 1 ; ! F_37 ( V_147 , V_144 ) && V_31 ; ) {
V_6 = F_7 ( V_2 -> V_8 , 0xa1 , & V_31 ) ;
if ( V_6 )
goto V_18;
V_31 = ( V_31 >> 6 ) & 0x1 ;
}
if ( V_31 == 0 ) {
F_5 ( & V_13 -> V_2 , L_26 ,
F_38 ( V_147 ) -
( F_38 ( V_144 ) - F_40 ) ) ;
} else {
F_5 ( & V_13 -> V_2 , L_27 ) ;
V_6 = F_1 ( V_2 , 0xa1 , 0xc0 , 0x40 ) ;
if ( V_6 )
goto V_18;
}
V_6 = F_1 ( V_2 , 0xa2 , 0xc0 , 0x80 ) ;
if ( V_6 )
goto V_18;
if ( V_31 == 1 ) {
V_6 = - V_148 ;
goto V_18;
}
return 0 ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_41 ( struct V_21 * V_22 ,
struct V_153 * V_154 )
{
V_154 -> V_155 = 3000 ;
return 0 ;
}
static void F_42 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
struct V_12 * V_13 = V_2 -> V_13 ;
F_43 ( V_13 ) ;
}
static int F_44 ( struct V_156 * V_157 , T_3 V_158 )
{
struct V_1 * V_2 = F_45 ( V_157 ) ;
struct V_12 * V_13 = V_2 -> V_13 ;
int V_6 ;
struct V_159 V_146 = {
. V_160 = V_13 -> V_160 ,
. V_161 = 0 ,
. V_57 = 2 ,
. V_16 = L_30 ,
} ;
V_6 = F_46 ( V_13 -> V_162 , & V_146 , 1 ) ;
if ( V_6 != 1 ) {
F_47 ( & V_13 -> V_2 , L_31 , V_6 ) ;
if ( V_6 >= 0 )
V_6 = - V_163 ;
return V_6 ;
}
return 0 ;
}
struct V_21 * F_48 ( const struct V_164 * V_19 ,
struct V_165 * V_166 , struct V_165 * * V_167 )
{
struct V_12 * V_13 ;
struct V_168 V_169 ;
struct V_170 V_171 ;
V_171 . V_172 = V_19 -> clock ;
V_171 . V_20 = V_19 -> V_20 ;
V_171 . V_79 = V_19 -> V_79 ;
V_171 . V_82 = V_19 -> V_82 ;
V_171 . V_89 = V_19 -> V_89 ;
V_171 . V_90 = V_19 -> V_90 ;
V_171 . V_92 = V_19 -> V_92 ;
V_171 . V_91 = V_19 -> V_91 ;
V_171 . V_173 = V_19 -> V_174 ;
V_171 . V_133 = V_19 -> V_133 ;
V_171 . V_140 = V_19 -> V_140 ;
V_171 . V_141 = V_19 -> V_141 ;
V_171 . V_175 = true ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
F_49 ( V_169 . type , L_32 , V_176 ) ;
V_169 . V_160 = V_19 -> V_177 ;
V_169 . V_178 = & V_171 ;
V_13 = F_50 ( V_166 , & V_169 ) ;
if ( ! V_13 || ! V_13 -> V_2 . V_179 )
return NULL ;
* V_167 = V_171 . V_180 ( V_13 ) ;
return V_171 . V_181 ( V_13 ) ;
}
static struct V_21 * F_51 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_52 ( V_13 ) ;
F_5 ( & V_13 -> V_2 , L_9 ) ;
return & V_2 -> V_22 ;
}
static struct V_165 * F_53 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_52 ( V_13 ) ;
F_5 ( & V_13 -> V_2 , L_9 ) ;
return V_2 -> V_157 -> V_162 [ 0 ] ;
}
static int F_54 ( struct V_12 * V_13 ,
const struct V_182 * V_183 )
{
struct V_1 * V_2 ;
struct V_170 * V_171 = V_13 -> V_2 . V_178 ;
int V_6 ;
unsigned int V_31 ;
V_2 = F_55 ( sizeof( * V_2 ) , V_184 ) ;
if ( ! V_2 ) {
V_6 = - V_185 ;
goto V_18;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_186 . clock = V_171 -> V_172 ;
V_2 -> V_186 . V_20 = V_171 -> V_20 ;
V_2 -> V_186 . V_79 = V_171 -> V_79 ;
V_2 -> V_186 . V_82 = V_171 -> V_82 * 1000 ;
V_2 -> V_186 . V_89 = V_171 -> V_89 ;
V_2 -> V_186 . V_90 = V_171 -> V_90 ;
V_2 -> V_186 . V_91 = V_171 -> V_91 ;
V_2 -> V_186 . V_174 = V_171 -> V_173 ;
V_2 -> V_186 . V_133 = V_171 -> V_133 ;
V_2 -> V_186 . V_92 = V_171 -> V_92 ;
V_2 -> V_186 . V_140 = V_171 -> V_140 ;
V_2 -> V_186 . V_141 = V_171 -> V_141 ;
V_2 -> V_19 = & V_2 -> V_186 ;
V_2 -> V_187 . V_188 = 8 ,
V_2 -> V_187 . V_189 = 8 ,
V_2 -> V_187 . V_190 = V_2 ,
V_2 -> V_8 = F_56 ( V_13 , & V_2 -> V_187 ) ;
if ( F_57 ( V_2 -> V_8 ) ) {
V_6 = F_58 ( V_2 -> V_8 ) ;
goto V_191;
}
V_6 = F_7 ( V_2 -> V_8 , 0x00 , & V_31 ) ;
if ( V_6 )
goto V_191;
V_2 -> V_72 = V_31 >> 1 ;
F_5 ( & V_13 -> V_2 , L_33 , V_2 -> V_72 ) ;
switch ( V_2 -> V_72 ) {
case V_73 :
case V_192 :
break;
default:
goto V_191;
}
switch ( V_2 -> V_19 -> V_174 ) {
case V_193 :
V_31 = 0x80 ;
break;
case V_194 :
V_31 = 0x00 ;
break;
case V_195 :
V_31 = 0x10 ;
break;
default:
V_6 = - V_17 ;
goto V_191;
}
if ( ! V_171 -> V_82 ) {
V_6 = - V_17 ;
goto V_191;
}
if ( V_2 -> V_72 == V_73 )
V_31 = 0x00 ;
V_6 = F_14 ( V_2 -> V_8 , 0x29 , V_31 ) ;
if ( V_6 )
goto V_191;
V_6 = F_1 ( V_2 , 0x08 , 0x01 , 0x00 ) ;
if ( V_6 )
goto V_191;
V_6 = F_1 ( V_2 , 0x04 , 0x01 , 0x01 ) ;
if ( V_6 )
goto V_191;
V_6 = F_1 ( V_2 , 0x23 , 0x10 , 0x10 ) ;
if ( V_6 )
goto V_191;
V_2 -> V_157 = F_59 ( V_13 -> V_162 , & V_13 -> V_2 , 1 , 0 , 0 ,
F_44 , NULL ) ;
if ( ! V_2 -> V_157 ) {
V_6 = - V_185 ;
goto V_191;
}
V_2 -> V_157 -> V_196 = V_2 ;
V_6 = F_60 ( V_2 -> V_157 , 0 , 0 , 0 ) ;
if ( V_6 )
goto V_191;
memcpy ( & V_2 -> V_22 . V_74 , & V_96 , sizeof( struct V_197 ) ) ;
if ( V_2 -> V_72 == V_73 )
strncpy ( V_2 -> V_22 . V_74 . V_97 . V_95 , L_34 ,
sizeof( V_2 -> V_22 . V_74 . V_97 . V_95 ) ) ;
if ( ! V_171 -> V_175 )
V_2 -> V_22 . V_74 . V_198 = NULL ;
V_2 -> V_22 . V_24 = V_2 ;
F_61 ( V_13 , V_2 ) ;
V_171 -> V_181 = F_51 ;
V_171 -> V_180 = F_53 ;
return 0 ;
V_191:
F_62 ( V_2 ) ;
V_18:
F_5 ( & V_13 -> V_2 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_63 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_52 ( V_13 ) ;
F_5 ( & V_13 -> V_2 , L_9 ) ;
F_64 ( V_2 -> V_157 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
