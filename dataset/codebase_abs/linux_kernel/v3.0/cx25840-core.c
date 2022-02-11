int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_2 V_5 [ 3 ] ;
V_5 [ 0 ] = V_3 >> 8 ;
V_5 [ 1 ] = V_3 & 0xff ;
V_5 [ 2 ] = V_4 ;
return F_2 ( V_2 , V_5 , 3 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_4 )
{
T_2 V_5 [ 6 ] ;
V_5 [ 0 ] = V_3 >> 8 ;
V_5 [ 1 ] = V_3 & 0xff ;
V_5 [ 2 ] = V_4 & 0xff ;
V_5 [ 3 ] = ( V_4 >> 8 ) & 0xff ;
V_5 [ 4 ] = ( V_4 >> 16 ) & 0xff ;
V_5 [ 5 ] = V_4 >> 24 ;
return F_2 ( V_2 , V_5 , 6 ) ;
}
T_2 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 V_7 [ 2 ] ;
T_2 V_8 [ 2 ] , V_9 [ 1 ] ;
V_8 [ 0 ] = V_3 >> 8 ;
V_8 [ 1 ] = V_3 & 0xff ;
V_7 [ 0 ] . V_3 = V_2 -> V_3 ;
V_7 [ 0 ] . V_10 = 0 ;
V_7 [ 0 ] . V_11 = 2 ;
V_7 [ 0 ] . V_12 = ( char * ) V_8 ;
V_7 [ 1 ] . V_3 = V_2 -> V_3 ;
V_7 [ 1 ] . V_10 = V_13 ;
V_7 [ 1 ] . V_11 = 1 ;
V_7 [ 1 ] . V_12 = ( char * ) V_9 ;
if ( F_5 ( V_2 -> V_14 , V_7 , 2 ) < 2 )
return 0 ;
return V_9 [ 0 ] ;
}
T_3 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 V_7 [ 2 ] ;
T_2 V_8 [ 2 ] , V_9 [ 4 ] ;
V_8 [ 0 ] = V_3 >> 8 ;
V_8 [ 1 ] = V_3 & 0xff ;
V_7 [ 0 ] . V_3 = V_2 -> V_3 ;
V_7 [ 0 ] . V_10 = 0 ;
V_7 [ 0 ] . V_11 = 2 ;
V_7 [ 0 ] . V_12 = ( char * ) V_8 ;
V_7 [ 1 ] . V_3 = V_2 -> V_3 ;
V_7 [ 1 ] . V_10 = V_13 ;
V_7 [ 1 ] . V_11 = 4 ;
V_7 [ 1 ] . V_12 = ( char * ) V_9 ;
if ( F_5 ( V_2 -> V_14 , V_7 , 2 ) < 2 )
return 0 ;
return ( V_9 [ 3 ] << 24 ) | ( V_9 [ 2 ] << 16 ) | ( V_9 [ 1 ] << 8 ) |
V_9 [ 0 ] ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , unsigned V_15 ,
T_2 V_16 )
{
return F_1 ( V_2 , V_3 ,
( F_4 ( V_2 , V_3 ) & V_15 ) |
V_16 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_15 ,
T_3 V_16 )
{
return F_3 ( V_2 , V_3 ,
( F_6 ( V_2 , V_3 ) & V_15 ) |
V_16 ) ;
}
static int F_9 ( struct V_17 * V_18 , T_4 V_19 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
int V_22 ;
T_3 V_23 ;
T_2 V_24 , V_25 , V_26 ;
V_23 = F_6 ( V_2 , 0x120 ) ;
V_24 = F_4 ( V_2 , 0x160 ) ;
V_25 = F_4 ( V_2 , 0x164 ) ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ ) {
V_26 = V_21 [ V_22 ] . V_26 ;
if ( V_26 > V_27 )
V_26 = V_27 ;
switch ( V_21 [ V_22 ] . V_28 ) {
case V_29 :
if ( V_21 [ V_22 ] . V_30 != V_31 ) {
V_23 &= ~ ( 0x1 << 25 ) ;
} else {
if ( V_21 [ V_22 ] . V_10 &
( V_32 |
V_33 ) ) {
V_23 &= ~ ( 0x1 << 25 ) ;
} else {
V_23 |= ( 0x1 << 25 ) ;
}
if ( V_21 [ V_22 ] . V_10 &
V_34 ) {
V_23 &= ~ ( 0x1 << 24 ) ;
} else {
V_23 |= ( 0x1 << 24 ) ;
}
}
break;
case V_35 :
if ( V_21 [ V_22 ] . V_30 != V_36 ) {
V_24 |= ( 0x1 << 0 ) ;
V_23 &= ~ ( 0x3 << 18 ) ;
V_23 |= ( V_26 << 18 ) ;
} else {
V_24 &= ~ ( 0x1 << 0 ) ;
if ( V_21 [ V_22 ] . V_10 & V_37 ) {
V_25 &= ~ ( 0x1 << 0 ) ;
V_25 |= ( ( V_21 [ V_22 ] . V_4 & 0x1 ) << 0 ) ;
}
V_23 &= ~ ( 0x3 << 12 ) ;
V_23 |= ( V_26 << 12 ) ;
}
break;
case V_38 :
if ( V_21 [ V_22 ] . V_30 != V_39 ) {
V_24 |= ( 0x1 << 1 ) ;
if ( V_21 [ V_22 ] . V_10 & V_32 )
V_23 &= ~ ( 0x1 << 10 ) ;
else
V_23 |= ( 0x1 << 10 ) ;
V_23 &= ~ ( 0x3 << 18 ) ;
V_23 |= ( V_26 << 18 ) ;
} else {
V_24 &= ~ ( 0x1 << 1 ) ;
if ( V_21 [ V_22 ] . V_10 & V_37 ) {
V_25 &= ~ ( 0x1 << 1 ) ;
V_25 |= ( ( V_21 [ V_22 ] . V_4 & 0x1 ) << 1 ) ;
}
V_23 &= ~ ( 0x3 << 12 ) ;
V_23 |= ( V_26 << 12 ) ;
}
break;
case V_40 :
if ( V_21 [ V_22 ] . V_30 != V_41 ) {
V_24 |= ( 0x1 << 2 ) ;
V_23 &= ~ ( 0x3 << 22 ) ;
V_23 |= ( V_26 << 22 ) ;
} else {
V_24 &= ~ ( 0x1 << 2 ) ;
if ( V_21 [ V_22 ] . V_10 & V_37 ) {
V_25 &= ~ ( 0x1 << 2 ) ;
V_25 |= ( ( V_21 [ V_22 ] . V_4 & 0x1 ) << 2 ) ;
}
V_23 &= ~ ( 0x3 << 12 ) ;
V_23 |= ( V_26 << 12 ) ;
}
break;
case V_42 :
if ( V_21 [ V_22 ] . V_30 != V_43 ) {
V_24 |= ( 0x1 << 3 ) ;
V_23 &= ~ ( 0x3 << 22 ) ;
V_23 |= ( V_26 << 22 ) ;
} else {
V_24 &= ~ ( 0x1 << 3 ) ;
if ( V_21 [ V_22 ] . V_10 & V_37 ) {
V_25 &= ~ ( 0x1 << 3 ) ;
V_25 |= ( ( V_21 [ V_22 ] . V_4 & 0x1 ) << 3 ) ;
}
V_23 &= ~ ( 0x3 << 12 ) ;
V_23 |= ( V_26 << 12 ) ;
}
break;
case V_44 :
if ( V_21 [ V_22 ] . V_30 != V_45 ) {
V_24 |= ( 0x1 << 4 ) ;
V_23 &= ~ ( 0x3 << 22 ) ;
V_23 |= ( V_26 << 22 ) ;
} else {
V_24 &= ~ ( 0x1 << 4 ) ;
if ( V_21 [ V_22 ] . V_10 & V_37 ) {
V_25 &= ~ ( 0x1 << 4 ) ;
V_25 |= ( ( V_21 [ V_22 ] . V_4 & 0x1 ) << 4 ) ;
}
V_23 &= ~ ( 0x3 << 12 ) ;
V_23 |= ( V_26 << 12 ) ;
}
break;
}
}
F_1 ( V_2 , 0x164 , V_25 ) ;
F_1 ( V_2 , 0x160 , V_24 ) ;
F_3 ( V_2 , 0x120 , V_23 ) ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , T_4 V_19 ,
struct V_20 * V_46 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
if ( F_13 ( V_48 ) )
return F_9 ( V_18 , V_19 , V_46 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x159 , 0x23 ) ;
F_1 ( V_2 , 0x15a , 0x87 ) ;
F_1 ( V_2 , 0x15b , 0x06 ) ;
F_15 ( 10 ) ;
F_1 ( V_2 , 0x159 , 0xe1 ) ;
F_15 ( 10 ) ;
F_1 ( V_2 , 0x15a , 0x86 ) ;
F_1 ( V_2 , 0x159 , 0xe0 ) ;
F_1 ( V_2 , 0x159 , 0xe1 ) ;
F_1 ( V_2 , 0x15b , 0x10 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x15d , 0xe3 ) ;
F_1 ( V_2 , 0x15e , 0x86 ) ;
F_1 ( V_2 , 0x15f , 0x06 ) ;
F_15 ( 10 ) ;
F_1 ( V_2 , 0x15d , 0xe1 ) ;
F_1 ( V_2 , 0x15d , 0xe0 ) ;
F_1 ( V_2 , 0x15d , 0xe1 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0x000 , ~ 0x01 , 0x01 ) ;
F_7 ( V_2 , 0x000 , ~ 0x01 , 0x00 ) ;
F_7 ( V_2 , 0x15a , ~ 0x70 , 0x00 ) ;
F_7 ( V_2 , 0x15b , ~ 0x1e , 0x06 ) ;
F_7 ( V_2 , 0x159 , ~ 0x02 , 0x02 ) ;
F_15 ( 10 ) ;
F_7 ( V_2 , 0x159 , ~ 0x02 , 0x00 ) ;
F_7 ( V_2 , 0x159 , ~ 0xc0 , 0xc0 ) ;
F_7 ( V_2 , 0x159 , ~ 0x01 , 0x00 ) ;
F_7 ( V_2 , 0x159 , ~ 0x01 , 0x01 ) ;
F_7 ( V_2 , 0x15b , ~ 0x1e , 0x10 ) ;
}
static void F_18 ( struct V_49 * V_50 )
{
struct V_47 * V_48 = F_19 ( V_50 , struct V_47 , V_51 ) ;
F_20 ( V_48 -> V_52 ) ;
F_21 ( & V_48 -> V_53 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_54 ) ;
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
struct V_55 * V_56 ;
F_7 ( V_2 , 0x803 , ~ 0x10 , 0x00 ) ;
F_1 ( V_2 , 0x000 , 0x04 ) ;
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
F_1 ( V_2 , 0x136 , 0x0a ) ;
F_1 ( V_2 , 0x13c , 0x01 ) ;
F_1 ( V_2 , 0x13c , 0x00 ) ;
F_25 ( & V_48 -> V_51 , F_18 ) ;
F_26 ( & V_48 -> V_53 ) ;
V_56 = F_27 ( L_1 ) ;
F_28 ( & V_48 -> V_53 , & V_54 , V_57 ) ;
F_29 ( V_56 , & V_48 -> V_51 ) ;
F_30 () ;
F_31 ( & V_48 -> V_53 , & V_54 ) ;
F_32 ( V_56 ) ;
F_1 ( V_2 , 0x115 , 0x8c ) ;
F_1 ( V_2 , 0x116 , 0x07 ) ;
F_1 ( V_2 , 0x118 , 0x02 ) ;
F_1 ( V_2 , 0x4a5 , 0x80 ) ;
F_1 ( V_2 , 0x4a5 , 0x00 ) ;
F_1 ( V_2 , 0x402 , 0x00 ) ;
F_7 ( V_2 , 0x401 , ~ 0x18 , 0 ) ;
F_7 ( V_2 , 0x4a2 , ~ 0x10 , 0x10 ) ;
F_1 ( V_2 , 0x8d3 , 0x1f ) ;
F_1 ( V_2 , 0x8e3 , 0x03 ) ;
F_33 ( V_2 ) ;
F_1 ( V_2 , 0x914 , 0xa0 ) ;
F_1 ( V_2 , 0x918 , 0xa0 ) ;
F_1 ( V_2 , 0x919 , 0x01 ) ;
F_1 ( V_2 , 0x809 , 0x04 ) ;
F_1 ( V_2 , 0x8cf , 0x0f ) ;
F_34 ( V_2 , V_48 -> V_58 , V_48 -> V_59 ) ;
F_7 ( V_2 , 0x803 , ~ 0x10 , 0x10 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_23 ( V_54 ) ;
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
struct V_55 * V_56 ;
F_1 ( V_2 , 0x000 , 0 ) ;
F_7 ( V_2 , 0x102 , ~ 0x01 , 0x01 ) ;
F_7 ( V_2 , 0x102 , ~ 0x01 , 0x00 ) ;
F_7 ( V_2 , 0x803 , ~ 0x10 , 0x00 ) ;
F_1 ( V_2 , 0x398 , 0 ) ;
F_1 ( V_2 , 0x2 , 0x76 ) ;
F_1 ( V_2 , 0x1 , 0x40 ) ;
switch ( V_48 -> V_60 ) {
case V_61 :
F_3 ( V_2 , 0x11c , 0x00e8ba26 ) ;
F_3 ( V_2 , 0x118 , 0x0000040b ) ;
break;
case V_62 :
F_3 ( V_2 , 0x11c , 0x01d1744c ) ;
F_3 ( V_2 , 0x118 , 0x00000416 ) ;
break;
case V_63 :
default:
F_3 ( V_2 , 0x11c , 0x00000000 ) ;
F_3 ( V_2 , 0x118 , 0x00000414 ) ;
break;
}
F_3 ( V_2 , 0x33c , 0x00000001 ) ;
F_3 ( V_2 , 0x340 , 0x0df7df83 ) ;
F_3 ( V_2 , 0x10c , 0x002be2c9 ) ;
F_3 ( V_2 , 0x108 , 0x0000040f ) ;
F_3 ( V_2 , 0x414 , 0x00107d12 ) ;
F_3 ( V_2 , 0x420 , 0x3d008282 ) ;
switch ( V_48 -> V_60 ) {
case V_61 :
F_3 ( V_2 , 0x114 , 0x00bedfa4 ) ;
F_3 ( V_2 , 0x110 , 0x000a0307 ) ;
break;
case V_62 :
F_3 ( V_2 , 0x114 , 0x017dbf48 ) ;
F_3 ( V_2 , 0x110 , 0x000a030e ) ;
break;
case V_63 :
default:
F_3 ( V_2 , 0x114 , 0x01bf0c9e ) ;
F_3 ( V_2 , 0x110 , 0x000a030c ) ;
break;
} ;
F_1 ( V_2 , 0x102 , 0x10 ) ;
F_1 ( V_2 , 0x103 , 0x11 ) ;
F_1 ( V_2 , 0x400 , 0 ) ;
F_1 ( V_2 , 0x401 , 0xe8 ) ;
F_1 ( V_2 , 0x144 , 0x05 ) ;
F_1 ( V_2 , 0x160 , 0x1d ) ;
F_1 ( V_2 , 0x164 , 0x00 ) ;
F_25 ( & V_48 -> V_51 , F_18 ) ;
F_26 ( & V_48 -> V_53 ) ;
V_56 = F_27 ( L_1 ) ;
F_28 ( & V_48 -> V_53 , & V_54 , V_57 ) ;
F_29 ( V_56 , & V_48 -> V_51 ) ;
F_30 () ;
F_31 ( & V_48 -> V_53 , & V_54 ) ;
F_32 ( V_56 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 , V_48 -> V_58 , V_48 -> V_59 ) ;
F_7 ( V_2 , 0x803 , ~ 0x10 , 0x10 ) ;
F_3 ( V_2 , V_64 , 0xffffffff ) ;
F_1 ( V_2 , V_65 , 0xff ) ;
F_1 ( V_2 , V_66 , 0xff ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_23 ( V_54 ) ;
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
struct V_55 * V_56 ;
F_7 ( V_2 , 0x102 , ~ 0x01 , 0x01 ) ;
F_7 ( V_2 , 0x102 , ~ 0x01 , 0x00 ) ;
F_7 ( V_2 , 0x803 , ~ 0x10 , 0x00 ) ;
F_1 ( V_2 , 0x398 , 0 ) ;
F_1 ( V_2 , 0x2 , 0x76 ) ;
F_1 ( V_2 , 0x1 , 0x40 ) ;
F_3 ( V_2 , 0x33c , 0x00000001 ) ;
F_3 ( V_2 , 0x340 , 0x0df7df83 ) ;
F_3 ( V_2 , 0x414 , 0x00107d12 ) ;
F_3 ( V_2 , 0x420 , 0x3d008282 ) ;
F_1 ( V_2 , 0x102 , 0x10 ) ;
F_1 ( V_2 , 0x103 , 0x11 ) ;
F_1 ( V_2 , 0x400 , 0 ) ;
F_1 ( V_2 , 0x401 , 0xe8 ) ;
F_25 ( & V_48 -> V_51 , F_18 ) ;
F_26 ( & V_48 -> V_53 ) ;
V_56 = F_27 ( L_1 ) ;
F_28 ( & V_48 -> V_53 , & V_54 , V_57 ) ;
F_29 ( V_56 , & V_48 -> V_51 ) ;
F_30 () ;
F_31 ( & V_48 -> V_53 , & V_54 ) ;
F_32 ( V_56 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 , V_48 -> V_58 , V_48 -> V_59 ) ;
F_7 ( V_2 , 0x803 , ~ 0x10 , 0x10 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
T_5 V_67 = V_48 -> V_67 ;
int V_68 , V_69 , V_70 , V_71 , V_72 , V_73 ;
int V_74 , V_75 ;
int V_76 , V_77 , V_78 ;
T_3 V_79 , V_80 , V_81 ;
if ( V_67 & ~ V_82 )
F_1 ( V_2 , 0x49f , 0x11 ) ;
else
F_1 ( V_2 , 0x49f , 0x14 ) ;
if ( V_67 & V_83 ) {
V_68 = 132 ;
V_69 = 720 ;
V_70 = 93 ;
V_71 = 36 ;
V_72 = 580 ;
V_74 = 40 ;
V_75 = 0x21f ;
V_76 = 2 ;
if ( V_67 & V_84 ) {
V_77 = 0 ;
V_78 = 0 ;
V_73 = 0x0a425f ;
} else if ( V_67 == V_85 ) {
V_77 = 1 ;
V_78 = 0x20 ;
V_73 = 556453 ;
} else {
V_77 = 1 ;
V_78 = 0x20 ;
V_73 = 688739 ;
}
} else {
V_69 = 720 ;
V_68 = 122 ;
V_72 = 487 ;
V_76 = 1 ;
V_77 = 1 ;
V_75 = 0x21f ;
if ( V_67 == V_86 ) {
V_71 = 26 ;
V_74 = 26 ;
V_70 = 0x5b ;
V_76 = 2 ;
V_78 = 0x20 ;
V_73 = 688739 ;
} else if ( V_67 == V_87 ) {
V_71 = 20 ;
V_74 = 24 ;
V_70 = 0x61 ;
V_78 = 0x20 ;
V_73 = 555452 ;
} else {
V_71 = 26 ;
V_74 = 26 ;
V_70 = 0x5b ;
V_78 = 0x66 ;
V_73 = 556063 ;
}
}
if ( ! F_37 ( V_48 ) ) {
V_79 = F_4 ( V_2 , 0x108 ) ;
V_80 = F_6 ( V_2 , 0x10c ) & 0x1ffffff ;
V_81 = F_4 ( V_2 , 0x109 ) ;
F_38 ( 1 , V_88 , V_2 ,
L_2 ,
V_79 , V_80 , V_81 ) ;
if ( V_81 ) {
int V_89 , V_90 ;
int V_91 = ( 28636363L * ( ( ( ( V_92 ) V_79 ) << 25L ) + V_80 ) ) >> 25L ;
V_91 /= V_81 ;
F_38 ( 1 , V_88 , V_2 , L_3 ,
V_91 / 1000000 , V_91 % 1000000 ) ;
F_38 ( 1 , V_88 , V_2 , L_4 ,
V_91 / 8000000 , ( V_91 / 8 ) % 1000000 ) ;
V_89 = ( ( V_92 ) V_75 * V_91 ) >> 12 ;
F_38 ( 1 , V_88 , V_2 ,
L_5 ,
V_89 / 1000000 , V_89 % 1000000 ) ;
V_90 = ( ( ( V_92 ) V_73 ) * V_91 ) >> 24L ;
F_38 ( 1 , V_88 , V_2 ,
L_6 ,
V_90 / 1000000 , V_90 % 1000000 ) ;
F_38 ( 1 , V_88 , V_2 , L_7
L_8
L_9
L_10 ,
V_68 , V_69 , V_71 , V_72 , V_74 ,
V_75 , V_70 , V_76 , V_77 , V_78 , V_73 ) ;
}
}
F_1 ( V_2 , 0x470 , V_68 ) ;
F_1 ( V_2 , 0x471 ,
0xff & ( ( ( V_68 >> 8 ) & 0x3 ) | ( V_69 << 4 ) ) ) ;
F_1 ( V_2 , 0x472 , V_69 >> 4 ) ;
F_1 ( V_2 , 0x473 , V_70 ) ;
F_1 ( V_2 , 0x474 , V_71 ) ;
F_1 ( V_2 , 0x475 ,
0xff & ( ( ( V_71 >> 8 ) & 0x3 ) | ( V_72 << 4 ) ) ) ;
F_1 ( V_2 , 0x476 , V_72 >> 4 ) ;
F_1 ( V_2 , 0x477 , V_74 ) ;
F_1 ( V_2 , 0x478 , 0xff & V_75 ) ;
F_1 ( V_2 , 0x479 , 0xff & ( V_75 >> 8 ) ) ;
F_1 ( V_2 , 0x47a , V_76 << 6 | ( ( V_77 << 4 ) & 0x30 ) ) ;
F_1 ( V_2 , 0x47b , V_78 ) ;
F_1 ( V_2 , 0x47c , V_73 ) ;
F_1 ( V_2 , 0x47d , 0xff & V_73 >> 8 ) ;
F_1 ( V_2 , 0x47e , 0xff & V_73 >> 16 ) ;
if ( V_67 & V_83 ) {
F_1 ( V_2 , 0x47f , 0x01 ) ;
V_48 -> V_93 = 5 ;
} else {
F_1 ( V_2 , 0x47f , 0x00 ) ;
V_48 -> V_93 = 8 ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
T_5 V_67 = V_48 -> V_67 ;
if ( V_67 & V_84 ) {
F_1 ( V_2 , 0x402 , 0 ) ;
}
else {
F_1 ( V_2 , 0x402 , 0x04 ) ;
F_1 ( V_2 , 0x49f , ( V_67 & V_82 ) ? 0x14 : 0x11 ) ;
}
F_7 ( V_2 , 0x401 , ~ 0x60 , 0 ) ;
F_7 ( V_2 , 0x401 , ~ 0x60 , 0x60 ) ;
if ( F_40 ( V_48 ) )
return;
F_7 ( V_2 , 0x810 , ~ 0x01 , 1 ) ;
if ( V_48 -> V_94 ) {
F_1 ( V_2 , 0x808 , 0xf9 ) ;
F_1 ( V_2 , 0x80b , 0x00 ) ;
}
else if ( V_67 & V_95 ) {
int V_96 = V_48 -> V_97 ;
if ( V_67 == V_98 ) {
F_1 ( V_2 , 0x808 , V_96 ? 0x2f : 0xf7 ) ;
} else if ( V_67 == V_99 ) {
F_1 ( V_2 , 0x808 , V_96 ? 0x3f : 0xf8 ) ;
} else {
F_1 ( V_2 , 0x808 , V_96 ? 0x1f : 0xf6 ) ;
}
F_1 ( V_2 , 0x80b , 0x00 ) ;
} else if ( V_67 & V_100 ) {
F_1 ( V_2 , 0x808 , 0xff ) ;
F_1 ( V_2 , 0x80b , 0x00 ) ;
} else if ( V_67 & V_84 ) {
F_1 ( V_2 , 0x808 , 0xff ) ;
if ( ( V_67 & V_101 ) &&
! ( V_67 & ( V_102 | V_103 ) ) ) {
F_1 ( V_2 , 0x80b , 0x00 ) ;
} else if ( ! ( V_67 & V_101 ) &&
( V_67 & ( V_102 | V_103 ) ) ) {
F_1 ( V_2 , 0x80b , 0x08 ) ;
} else {
F_1 ( V_2 , 0x80b , 0x10 ) ;
}
}
F_7 ( V_2 , 0x810 , ~ 0x01 , 0 ) ;
}
static int F_34 ( struct V_1 * V_2 , enum V_104 V_58 ,
enum V_105 V_59 )
{
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
T_2 V_106 = ( V_58 >= V_107 &&
V_58 <= V_108 ) ;
T_2 V_109 = ( V_58 & V_110 ) ==
V_110 ;
int V_111 = V_58 & 0xf0 ;
int V_112 = V_58 & 0xf00 ;
T_2 V_113 ;
F_38 ( 1 , V_88 , V_2 ,
L_11 ,
V_58 , V_59 ) ;
if ( V_58 >= V_114 ) {
F_38 ( 1 , V_88 , V_2 , L_12 ,
V_58 ) ;
V_113 = V_58 & 0xff ;
V_106 = ! V_109 &&
( ( V_58 & V_115 ) != V_115 ) ;
F_38 ( 1 , V_88 , V_2 , L_13 ,
V_113 , V_106 ) ;
} else if ( V_106 ) {
V_113 = 0xf0 + ( V_58 - V_107 ) ;
} else {
if ( ( V_58 & ~ 0xff0 ) ||
V_111 < V_116 || V_111 > V_117 ||
V_112 < V_118 || V_112 > V_119 ) {
F_41 ( V_2 , L_14 ,
V_58 ) ;
return - V_120 ;
}
V_113 = 0xf0 + ( ( V_111 - V_116 ) >> 4 ) ;
if ( V_112 >= V_121 ) {
V_113 &= 0x3f ;
V_113 |= ( V_112 - V_121 ) >> 2 ;
} else {
V_113 &= 0xcf ;
V_113 |= ( V_112 - V_118 ) >> 4 ;
}
}
if ( ! F_13 ( V_48 ) && ! F_37 ( V_48 ) ) {
switch ( V_59 ) {
case V_122 :
break;
case V_123 : V_113 &= ~ 0x30 ; break;
case V_124 : V_113 &= ~ 0x30 ; V_113 |= 0x10 ; break;
case V_125 : V_113 &= ~ 0x30 ; V_113 |= 0x20 ; break;
case V_126 : V_113 &= ~ 0xc0 ; break;
case V_127 : V_113 &= ~ 0xc0 ; V_113 |= 0x40 ; break;
default:
F_41 ( V_2 , L_15 ,
V_59 ) ;
return - V_120 ;
}
}
F_1 ( V_2 , 0x103 , V_113 ) ;
if ( V_109 )
F_7 ( V_2 , 0x401 , ~ 0x6 , 0x6 ) ;
else
F_7 ( V_2 , 0x401 , ~ 0x6 , V_106 ? 0 : 0x02 ) ;
if ( ! F_13 ( V_48 ) && ! F_37 ( V_48 ) ) {
F_7 ( V_2 , 0x102 , ~ 0x2 , ( V_113 & 0x80 ) == 0 ? 2 : 0 ) ;
if ( ( V_113 & 0xc0 ) != 0xc0 && ( V_113 & 0x30 ) != 0x30 )
F_7 ( V_2 , 0x102 , ~ 0x4 , 4 ) ;
else
F_7 ( V_2 , 0x102 , ~ 0x4 , 0 ) ;
} else {
F_7 ( V_2 , 0x102 , ~ 0x4 , V_109 ? 0x4 : 0x0 ) ;
if ( V_106 ) {
F_7 ( V_2 , 0x102 , ~ 0x2 , 0 ) ;
} else if ( ! V_109 ) {
if ( V_112 >= V_121 ) {
F_7 ( V_2 , 0x102 , ~ 0x2 , 2 ) ;
} else {
F_7 ( V_2 , 0x102 , ~ 0x2 , 0 ) ;
}
}
}
V_48 -> V_58 = V_58 ;
V_48 -> V_59 = V_59 ;
F_42 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( F_13 ( V_48 ) ) {
F_1 ( V_2 , 0x124 , 0x03 ) ;
F_1 ( V_2 , 0x144 , 0x05 ) ;
F_1 ( V_2 , 0x914 , 0xa0 ) ;
F_1 ( V_2 , 0x918 , 0xa0 ) ;
F_1 ( V_2 , 0x919 , 0x01 ) ;
} else if ( F_37 ( V_48 ) ) {
F_1 ( V_2 , 0x124 , 0x03 ) ;
F_1 ( V_2 , 0x914 , 0xa0 ) ;
F_1 ( V_2 , 0x918 , 0xa0 ) ;
F_1 ( V_2 , 0x919 , 0x01 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
T_2 V_128 = 0 ;
T_2 V_129 = 0 ;
if ( V_48 -> V_67 == V_98 ) {
V_128 = 0x2 ;
} else if ( V_48 -> V_67 == V_130 ) {
V_128 = 0x3 ;
} else if ( V_48 -> V_67 == V_87 ) {
V_129 = 1 ;
V_128 = 0x5 ;
} else if ( V_48 -> V_67 == V_131 ) {
V_128 = 0x6 ;
} else if ( V_48 -> V_67 == V_85 ) {
V_128 = 0x7 ;
} else if ( V_48 -> V_67 == V_86 ) {
V_128 = 0x8 ;
} else {
if ( V_48 -> V_67 & V_82 )
V_128 = 0x1 ;
else if ( V_48 -> V_67 & V_100 )
V_128 = 0x4 ;
else if ( V_48 -> V_67 & V_84 )
V_128 = 0xc ;
}
F_38 ( 1 , V_88 , V_2 , L_16 , V_128 ) ;
if ( V_128 >= 4 && V_128 < 8 ) {
F_7 ( V_2 , 0x400 , ~ 0xf , 1 ) ;
F_7 ( V_2 , 0x47b , ~ 6 , 0 ) ;
}
F_7 ( V_2 , 0x400 , ~ 0xf , V_128 ) ;
F_7 ( V_2 , 0x403 , ~ 0x3 , V_129 ) ;
F_33 ( V_2 ) ;
if ( ! F_40 ( V_48 ) )
F_39 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_132 * V_133 )
{
struct V_17 * V_18 = F_45 ( V_133 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
switch ( V_133 -> V_60 ) {
case V_134 :
F_1 ( V_2 , 0x414 , V_133 -> V_135 - 128 ) ;
break;
case V_136 :
F_1 ( V_2 , 0x415 , V_133 -> V_135 << 1 ) ;
break;
case V_137 :
F_1 ( V_2 , 0x420 , V_133 -> V_135 << 1 ) ;
F_1 ( V_2 , 0x421 , V_133 -> V_135 << 1 ) ;
break;
case V_138 :
F_1 ( V_2 , 0x422 , V_133 -> V_135 ) ;
break;
default:
return - V_120 ;
}
return 0 ;
}
static int F_46 ( struct V_17 * V_18 , struct V_139 * V_128 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
int V_140 , V_141 , V_142 , V_143 , V_144 , V_145 ;
int V_146 = ! ( V_48 -> V_67 & V_95 ) ;
if ( V_128 -> V_147 != V_148 )
return - V_120 ;
V_128 -> V_149 = V_150 ;
V_128 -> V_151 = V_152 ;
V_142 = ( F_4 ( V_2 , 0x476 ) & 0x3f ) << 4 ;
V_142 |= ( F_4 ( V_2 , 0x475 ) & 0xf0 ) >> 4 ;
V_143 = ( F_4 ( V_2 , 0x472 ) & 0x3f ) << 4 ;
V_143 |= ( F_4 ( V_2 , 0x471 ) & 0xf0 ) >> 4 ;
V_145 = V_128 -> V_153 + ( V_146 ? 4 : 7 ) ;
if ( ( V_128 -> V_154 * 16 < V_143 ) || ( V_143 < V_128 -> V_154 ) ||
( V_145 * 8 < V_142 ) || ( V_142 < V_145 ) ) {
F_41 ( V_2 , L_17 ,
V_128 -> V_154 , V_128 -> V_153 ) ;
return - V_155 ;
}
V_140 = ( V_143 * ( 1 << 20 ) ) / V_128 -> V_154 - ( 1 << 20 ) ;
V_141 = ( 1 << 16 ) - ( V_142 * ( 1 << 9 ) / V_145 - ( 1 << 9 ) ) ;
V_141 &= 0x1fff ;
if ( V_128 -> V_154 >= 385 )
V_144 = 0 ;
else if ( V_128 -> V_154 > 192 )
V_144 = 1 ;
else if ( V_128 -> V_154 > 96 )
V_144 = 2 ;
else
V_144 = 3 ;
F_38 ( 1 , V_88 , V_2 , L_18 ,
V_128 -> V_154 , V_128 -> V_153 , V_140 , V_141 ) ;
F_1 ( V_2 , 0x418 , V_140 & 0xff ) ;
F_1 ( V_2 , 0x419 , ( V_140 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x41a , V_140 >> 16 ) ;
F_1 ( V_2 , 0x41c , V_141 & 0xff ) ;
F_1 ( V_2 , 0x41d , V_141 >> 8 ) ;
F_1 ( V_2 , 0x41e , 0x8 | V_144 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
static const char * const V_156 [] = {
L_19 ,
L_20 , L_21 , L_22 ,
L_23 , L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 ,
L_31 ,
L_32 , L_33 , L_34
} ;
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
T_2 V_157 = F_4 ( V_2 , 0x400 ) & 0xf ;
T_2 V_158 = F_4 ( V_2 , 0x40d ) ;
T_2 V_159 = F_4 ( V_2 , 0x40e ) ;
int V_58 = V_48 -> V_58 ;
F_48 ( V_2 , L_35 ,
( V_159 & 0x20 ) ? L_36 : L_37 ) ;
F_48 ( V_2 , L_38 ,
V_156 [ V_158 & 0xf ] ) ;
F_48 ( V_2 , L_39 ,
V_157 ? V_156 [ V_157 ] : L_40 ) ;
if ( V_58 >= V_107 &&
V_58 <= V_108 ) {
F_48 ( V_2 , L_41 ,
V_58 - V_107 + 1 ) ;
} else {
F_48 ( V_2 , L_42 ,
( V_58 & 0xf0 ) >> 4 , ( V_58 & 0xf00 ) >> 8 ) ;
}
F_48 ( V_2 , L_43 , V_48 -> V_160 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = F_12 ( F_24 ( V_2 ) ) ;
T_2 V_161 = F_4 ( V_2 , 0x803 ) ;
T_2 V_162 = F_4 ( V_2 , 0x804 ) ;
T_2 V_163 = F_4 ( V_2 , 0x805 ) ;
T_2 V_164 = F_4 ( V_2 , 0x808 ) ;
T_2 V_165 = F_4 ( V_2 , 0x809 ) ;
T_2 V_166 = F_4 ( V_2 , 0x80b ) ;
T_2 V_167 = F_4 ( V_2 , 0x8d3 ) ;
int V_59 = V_48 -> V_59 ;
char * V_21 ;
switch ( V_162 ) {
case 0x00 : V_21 = L_44 ; break;
case 0x01 : V_21 = L_45 ; break;
case 0x02 : V_21 = L_46 ; break;
case 0x04 : V_21 = L_47 ; break;
case 0x10 : V_21 = L_48 ; break;
case 0x11 : V_21 = L_49 ; break;
case 0x12 : V_21 = L_50 ; break;
case 0x14 : V_21 = L_51 ; break;
case 0xfe : V_21 = L_52 ; break;
default: V_21 = L_53 ;
}
F_48 ( V_2 , L_54 , V_21 ) ;
switch ( V_163 ) {
case 0x00 : V_21 = L_53 ; break;
case 0x01 : V_21 = L_55 ; break;
case 0x02 : V_21 = L_56 ; break;
case 0x03 : V_21 = L_57 ; break;
case 0x04 : V_21 = L_58 ; break;
case 0x05 : V_21 = L_59 ; break;
case 0x06 : V_21 = L_60 ; break;
case 0x07 : V_21 = L_61 ; break;
case 0x08 : V_21 = L_62 ; break;
case 0x09 : V_21 = L_63 ; break;
case 0x0a : V_21 = L_64 ; break;
case 0x0b : V_21 = L_65 ; break;
case 0x0c : V_21 = L_66 ; break;
case 0x0d : V_21 = L_67 ; break;
case 0x0e : V_21 = L_68 ; break;
case 0x0f : V_21 = L_69 ; break;
case 0x10 : V_21 = L_70 ; break;
case 0x11 : V_21 = L_71 ; break;
case 0xfd : V_21 = L_72 ; break;
case 0xfe : V_21 = L_73 ; break;
case 0xff : V_21 = L_74 ; break;
default: V_21 = L_53 ;
}
F_48 ( V_2 , L_75 , V_21 ) ;
F_48 ( V_2 , L_76 ,
( V_161 & 0x10 ) ?
( ( V_167 & 0x2 ) ? L_77 : L_78 ) : L_79 ) ;
switch ( V_164 >> 4 ) {
case 0x00 : V_21 = L_80 ; break;
case 0x01 : V_21 = L_69 ; break;
case 0x02 : V_21 = L_55 ; break;
case 0x03 : V_21 = L_56 ; break;
case 0x04 : V_21 = L_57 ; break;
case 0x05 : V_21 = L_58 ; break;
case 0x06 : V_21 = L_59 ; break;
case 0x07 : V_21 = L_60 ; break;
case 0x08 : V_21 = L_61 ; break;
case 0x09 : V_21 = L_62 ; break;
case 0x0a : V_21 = L_63 ; break;
case 0x0b : V_21 = L_64 ; break;
case 0x0c : V_21 = L_65 ; break;
case 0x0d : V_21 = L_66 ; break;
case 0x0e : V_21 = L_81 ; break;
case 0x0f : V_21 = L_40 ; break;
default: V_21 = L_80 ;
}
F_48 ( V_2 , L_82 , V_21 ) ;
if ( ( V_164 >> 4 ) < 0xF ) {
switch ( V_164 & 0xF ) {
case 0x00 : V_21 = L_83 ; break;
case 0x01 : V_21 = L_84 ; break;
case 0x02 : V_21 = L_85 ; break;
case 0x03 : V_21 = L_86 ; break;
case 0x04 : V_21 = L_87 ; break;
case 0x05 : V_21 = L_88 ; break;
case 0x06 : V_21 = L_89 ; break;
case 0x07 : V_21 = L_90 ; break;
case 0x08 : V_21 = L_91 ; break;
case 0x09 : V_21 = L_92 ; break;
case 0x0a : V_21 = L_93 ; break;
default: V_21 = L_80 ;
}
F_48 ( V_2 , L_94 , V_21 ) ;
} else {
switch ( V_164 & 0xF ) {
case 0x00 : V_21 = L_95 ; break;
case 0x01 : V_21 = L_96 ; break;
case 0x02 : V_21 = L_97 ; break;
case 0x03 : V_21 = L_98 ; break;
case 0x04 : V_21 = L_99 ; break;
case 0x05 : V_21 = L_100 ; break;
case 0x06 : V_21 = L_69 ; break;
case 0x07 : V_21 = L_55 ; break;
case 0x08 : V_21 = L_56 ; break;
case 0x09 : V_21 = L_101 ; break;
case 0x0f : V_21 = L_102 ; break;
default: V_21 = L_80 ;
}
F_48 ( V_2 , L_103 , V_21 ) ;
}
if ( V_59 ) {
F_48 ( V_2 , L_104 , V_59 ) ;
} else {
F_48 ( V_2 , L_105 ) ;
}
switch ( V_165 & 0xf ) {
case 0 : V_21 = L_106 ; break;
case 1 : V_21 = L_107 ; break;
case 2 : V_21 = L_108 ; break;
case 3 : V_21 = L_109 ; break;
case 4 : V_21 = L_45 ; break;
case 5 : V_21 = L_110 ; break;
case 6 : V_21 = L_111 ; break;
case 7 : V_21 = L_112 ; break;
default: V_21 = L_80 ;
}
F_48 ( V_2 , L_113 , V_21 ) ;
if ( ( V_164 & 0xf ) == 0xf ) {
switch ( ( V_166 >> 3 ) & 0x3 ) {
case 0 : V_21 = L_114 ; break;
case 1 : V_21 = L_115 ; break;
case 2 : V_21 = L_116 ; break;
default: V_21 = L_80 ;
}
F_48 ( V_2 , L_117 , V_21 ) ;
switch ( V_166 & 0x7 ) {
case 0 : V_21 = L_118 ; break;
case 1 : V_21 = L_69 ; break;
case 2 : V_21 = L_55 ; break;
case 3 : V_21 = L_56 ; break;
case 4 : V_21 = L_116 ; break;
default: V_21 = L_80 ;
}
F_48 ( V_2 , L_119 , V_21 ) ;
}
}
static int F_50 ( struct V_17 * V_18 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( ! V_48 -> V_168 ) {
V_48 -> V_168 = 1 ;
if ( F_40 ( V_48 ) )
F_17 ( V_2 ) ;
else if ( F_13 ( V_48 ) )
F_35 ( V_2 ) ;
else if ( F_37 ( V_48 ) )
F_36 ( V_2 ) ;
else
F_22 ( V_2 ) ;
}
return 0 ;
}
static int F_51 ( struct V_17 * V_18 , struct V_169 * V_113 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( ! F_52 ( V_2 , & V_113 -> V_170 ) )
return - V_120 ;
if ( ! F_53 ( V_171 ) )
return - V_172 ;
V_113 -> V_173 = 1 ;
V_113 -> V_135 = F_4 ( V_2 , V_113 -> V_113 & 0x0fff ) ;
return 0 ;
}
static int F_54 ( struct V_17 * V_18 , struct V_169 * V_113 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( ! F_52 ( V_2 , & V_113 -> V_170 ) )
return - V_120 ;
if ( ! F_53 ( V_171 ) )
return - V_172 ;
F_1 ( V_2 , V_113 -> V_113 & 0x0fff , V_113 -> V_135 & 0xff ) ;
return 0 ;
}
static int F_55 ( struct V_17 * V_18 , int V_174 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
T_2 V_175 ;
if ( F_40 ( V_48 ) || F_13 ( V_48 ) || F_37 ( V_48 ) )
return 0 ;
F_38 ( 1 , V_88 , V_2 , L_120 ,
V_174 ? L_121 : L_122 ) ;
if ( V_174 ) {
V_175 = F_4 ( V_2 , 0x115 ) | 0x80 ;
F_1 ( V_2 , 0x115 , V_175 ) ;
V_175 = F_4 ( V_2 , 0x116 ) | 0x03 ;
F_1 ( V_2 , 0x116 , V_175 ) ;
} else {
V_175 = F_4 ( V_2 , 0x115 ) & ~ ( 0x80 ) ;
F_1 ( V_2 , 0x115 , V_175 ) ;
V_175 = F_4 ( V_2 , 0x116 ) & ~ ( 0x03 ) ;
F_1 ( V_2 , 0x116 , V_175 ) ;
}
return 0 ;
}
static int F_56 ( struct V_17 * V_18 , int V_174 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
T_2 V_175 ;
F_38 ( 1 , V_88 , V_2 , L_123 ,
V_174 ? L_121 : L_122 ) ;
if ( V_174 ) {
if ( F_13 ( V_48 ) || F_37 ( V_48 ) ) {
V_175 = F_4 ( V_2 , 0x421 ) | 0x0b ;
F_1 ( V_2 , 0x421 , V_175 ) ;
} else {
V_175 = F_4 ( V_2 , 0x115 ) | 0x0c ;
F_1 ( V_2 , 0x115 , V_175 ) ;
V_175 = F_4 ( V_2 , 0x116 ) | 0x04 ;
F_1 ( V_2 , 0x116 , V_175 ) ;
}
} else {
if ( F_13 ( V_48 ) || F_37 ( V_48 ) ) {
V_175 = F_4 ( V_2 , 0x421 ) & ~ ( 0x0b ) ;
F_1 ( V_2 , 0x421 , V_175 ) ;
} else {
V_175 = F_4 ( V_2 , 0x115 ) & ~ ( 0x0c ) ;
F_1 ( V_2 , 0x115 , V_175 ) ;
V_175 = F_4 ( V_2 , 0x116 ) & ~ ( 0x04 ) ;
F_1 ( V_2 , 0x116 , V_175 ) ;
}
}
return 0 ;
}
static int F_57 ( struct V_17 * V_18 , T_5 V_67 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( V_48 -> V_94 == 0 && V_48 -> V_67 == V_67 )
return 0 ;
V_48 -> V_94 = 0 ;
V_48 -> V_67 = V_67 ;
return F_43 ( V_2 ) ;
}
static int F_58 ( struct V_17 * V_18 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
V_48 -> V_94 = 1 ;
return 0 ;
}
static int F_59 ( struct V_17 * V_18 ,
T_3 V_176 , T_3 V_177 , T_3 V_178 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
return F_34 ( V_2 , V_176 , V_48 -> V_59 ) ;
}
static int F_60 ( struct V_17 * V_18 ,
T_3 V_176 , T_3 V_177 , T_3 V_178 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
return F_34 ( V_2 , V_48 -> V_58 , V_176 ) ;
}
static int F_61 ( struct V_17 * V_18 , struct V_179 * V_180 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_17 * V_18 , struct V_181 * V_182 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
T_2 V_183 = F_4 ( V_2 , 0x40e ) & 0x20 ;
T_2 V_184 ;
int V_135 = 0 ;
if ( V_48 -> V_94 )
return 0 ;
V_182 -> signal = V_183 ? 0xffff : 0x0 ;
if ( F_40 ( V_48 ) )
return 0 ;
V_182 -> V_185 |=
V_186 | V_187 |
V_188 | V_189 ;
V_184 = F_4 ( V_2 , 0x804 ) ;
if ( ( V_184 & 0xf ) == 1 )
V_135 |= V_190 ;
else
V_135 |= V_191 ;
if ( V_184 == 2 || V_184 == 4 )
V_135 = V_192 | V_193 ;
if ( V_184 & 0x10 )
V_135 |= V_194 ;
V_182 -> V_195 = V_135 ;
V_182 -> V_196 = V_48 -> V_196 ;
return 0 ;
}
static int F_63 ( struct V_17 * V_18 , struct V_181 * V_182 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( V_48 -> V_94 || F_40 ( V_48 ) )
return 0 ;
switch ( V_182 -> V_196 ) {
case V_197 :
F_7 ( V_2 , 0x809 , ~ 0xf , 0x00 ) ;
break;
case V_198 :
case V_199 :
F_7 ( V_2 , 0x809 , ~ 0xf , 0x04 ) ;
break;
case V_200 :
F_7 ( V_2 , 0x809 , ~ 0xf , 0x07 ) ;
break;
case V_201 :
F_7 ( V_2 , 0x809 , ~ 0xf , 0x01 ) ;
break;
default:
return - V_120 ;
}
V_48 -> V_196 = V_182 -> V_196 ;
return 0 ;
}
static int F_64 ( struct V_17 * V_18 , T_3 V_135 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( F_40 ( V_48 ) )
F_17 ( V_2 ) ;
else if ( F_13 ( V_48 ) )
F_35 ( V_2 ) ;
else if ( F_37 ( V_48 ) )
F_36 ( V_2 ) ;
else
F_22 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_17 * V_18 , struct V_202 * V_203 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
return F_66 ( V_2 , V_203 , V_48 -> V_60 , V_48 -> V_204 ) ;
}
static int F_67 ( struct V_17 * V_18 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
F_47 ( V_2 ) ;
if ( ! F_40 ( V_48 ) )
F_49 ( V_2 ) ;
F_68 ( V_18 ) ;
F_69 ( & V_48 -> V_205 , V_18 -> V_206 ) ;
return 0 ;
}
static int F_70 ( struct V_17 * V_18 , T_3 V_207 ,
bool * V_208 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
struct V_1 * V_52 = F_10 ( V_18 ) ;
T_2 V_209 , V_210 , V_211 , V_212 , V_213 ;
T_3 V_214 , V_215 ;
bool V_216 ;
int V_217 = 0 ;
V_209 = F_4 ( V_52 , V_218 ) ;
F_38 ( 2 , V_88 , V_52 , L_124 ,
V_209 & V_219 ? L_125 : L_126 ,
V_209 & V_220 ? L_127 : L_128 ,
V_209 & V_221 ? L_129 : L_128 ) ;
if ( ( F_71 ( V_48 ) || F_72 ( V_48 ) ) ) {
V_212 = F_4 ( V_52 , V_222 ) ;
V_213 = F_4 ( V_52 , V_223 ) ;
F_38 ( 2 , V_88 , V_52 ,
L_130 ,
V_212 , V_213 ) ;
if ( V_209 & V_219 ) {
V_216 = false ;
V_217 = F_73 ( V_18 ,
V_207 , & V_216 ) ;
if ( V_216 )
* V_208 = true ;
}
}
V_210 = F_4 ( V_52 , V_66 ) ;
V_211 = F_4 ( V_52 , V_65 ) ;
F_38 ( 2 , V_88 , V_52 ,
L_131 ,
V_210 , V_211 ) ;
V_215 = F_6 ( V_52 , V_224 ) ;
F_38 ( 2 , V_88 , V_52 ,
L_132 ,
V_215 >> V_225 ,
V_215 & V_226 ) ;
if ( V_209 & V_220 ) {
if ( V_210 ) {
F_1 ( V_52 , V_66 , V_210 ) ;
* V_208 = true ;
}
}
V_214 = F_6 ( V_52 , V_64 ) ;
F_38 ( 2 , V_88 , V_52 ,
L_133 ,
V_214 & V_227 ,
V_214 >> V_228 ) ;
if ( V_209 & V_221 ) {
if ( V_214 & V_227 ) {
F_3 ( V_52 , V_64 , V_214 ) ;
* V_208 = true ;
}
}
V_209 = F_4 ( V_52 , V_218 ) ;
F_38 ( 2 , V_88 , V_52 , L_134 ,
V_209 & V_219 ? L_125 : L_126 ,
V_209 & V_220 ? L_127 : L_128 ,
V_209 & V_221 ? L_129 : L_128 ) ;
return V_217 ;
}
static int F_74 ( struct V_17 * V_18 , T_3 V_207 ,
bool * V_208 )
{
struct V_47 * V_48 = F_12 ( V_18 ) ;
* V_208 = false ;
if ( F_13 ( V_48 ) )
return F_70 ( V_18 , V_207 , V_208 ) ;
return - V_229 ;
}
static T_3 F_75 ( struct V_1 * V_2 )
{
T_3 V_217 ;
F_1 ( V_2 , 0x000 , 0 ) ;
if ( F_6 ( V_2 , 0x204 ) & 0xffff ) {
V_217 = F_6 ( V_2 , 0x300 ) ;
if ( ( ( V_217 & 0xffff0000 ) >> 16 ) == ( V_217 & 0xffff ) ) {
V_217 = V_63 ;
} else {
V_217 = V_62 ;
}
} else if ( F_6 ( V_2 , 0x300 ) & 0x0fffffff ) {
V_217 = V_61 ;
} else {
F_41 ( V_2 , L_135 ) ;
V_217 = V_62 ;
}
F_1 ( V_2 , 0x000 , 2 ) ;
return V_217 ;
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_230 * V_231 )
{
struct V_47 * V_48 ;
struct V_17 * V_18 ;
int V_232 ;
T_3 V_60 = V_233 ;
T_1 V_234 ;
if ( ! F_77 ( V_2 -> V_14 , V_235 ) )
return - V_236 ;
F_38 ( 1 , V_88 , V_2 , L_136 , V_2 -> V_3 << 1 ) ;
V_234 = F_4 ( V_2 , 0x101 ) << 8 ;
V_234 |= F_4 ( V_2 , 0x100 ) ;
F_38 ( 1 , V_88 , V_2 , L_137 , V_234 ) ;
if ( ( V_234 & 0xff00 ) == 0x8300 ) {
V_60 = V_237 + ( ( V_234 >> 4 ) & 0xf ) - 6 ;
} else if ( ( V_234 & 0xff00 ) == 0x8400 ) {
V_60 = V_238 + ( ( V_234 >> 4 ) & 0xf ) ;
} else if ( V_234 == 0x0000 ) {
V_60 = F_75 ( V_2 ) ;
} else if ( ( V_234 & 0xfff0 ) == 0x5A30 ) {
V_60 = V_239 ;
} else if ( ( V_234 & 0xff ) == ( V_234 >> 8 ) ) {
F_41 ( V_2 ,
L_138
L_139 ,
V_2 -> V_3 << 1 , V_2 -> V_14 -> V_206 ) ;
F_41 ( V_2 , L_140
L_141 ) ;
return - V_229 ;
} else {
F_38 ( 1 , V_88 , V_2 , L_142 ) ;
return - V_229 ;
}
V_48 = F_78 ( sizeof( struct V_47 ) , V_240 ) ;
if ( V_48 == NULL )
return - V_241 ;
V_18 = & V_48 -> V_18 ;
F_79 ( V_18 , V_2 , & V_242 ) ;
switch ( V_60 ) {
case V_63 :
F_48 ( V_2 , L_143 ,
V_2 -> V_3 << 1 , V_2 -> V_14 -> V_206 ) ;
break;
case V_62 :
F_48 ( V_2 , L_144 ,
V_2 -> V_3 << 1 , V_2 -> V_14 -> V_206 ) ;
break;
case V_61 :
F_48 ( V_2 , L_145 ,
V_2 -> V_3 << 1 , V_2 -> V_14 -> V_206 ) ;
break;
case V_239 :
F_48 ( V_2 , L_146 ,
V_234 , V_2 -> V_3 << 1 , V_2 -> V_14 -> V_206 ) ;
break;
case V_238 :
case V_243 :
case V_244 :
case V_245 :
F_48 ( V_2 , L_147 ,
( V_234 & 0xfff0 ) >> 4 ,
( V_234 & 0x0f ) < 3 ? ( V_234 & 0x0f ) + 1
: ( V_234 & 0x0f ) ,
V_2 -> V_3 << 1 , V_2 -> V_14 -> V_206 ) ;
break;
case V_237 :
case V_246 :
default:
F_48 ( V_2 , L_148 ,
( V_234 & 0xfff0 ) >> 4 , V_234 & 0x0f ,
V_2 -> V_3 << 1 , V_2 -> V_14 -> V_206 ) ;
break;
}
V_48 -> V_52 = V_2 ;
V_48 -> V_58 = V_247 ;
V_48 -> V_59 = V_127 ;
V_48 -> V_160 = 48000 ;
V_48 -> V_196 = V_199 ;
V_48 -> V_93 = 8 ;
V_48 -> V_60 = V_60 ;
V_48 -> V_204 = V_234 ;
F_80 ( & V_48 -> V_205 , 9 ) ;
F_81 ( & V_48 -> V_205 , & V_248 ,
V_134 , 0 , 255 , 1 , 128 ) ;
F_81 ( & V_48 -> V_205 , & V_248 ,
V_136 , 0 , 127 , 1 , 64 ) ;
F_81 ( & V_48 -> V_205 , & V_248 ,
V_137 , 0 , 127 , 1 , 64 ) ;
F_81 ( & V_48 -> V_205 , & V_248 ,
V_138 , - 128 , 127 , 1 , 0 ) ;
if ( ! F_40 ( V_48 ) ) {
V_232 = F_4 ( V_2 , 0x8d4 ) ;
if ( V_232 > 228 ) {
V_232 = 228 ;
F_1 ( V_2 , 0x8d4 , 228 ) ;
}
else if ( V_232 < 20 ) {
V_232 = 20 ;
F_1 ( V_2 , 0x8d4 , 20 ) ;
}
V_232 = ( ( ( 228 - V_232 ) >> 1 ) + 23 ) << 9 ;
V_48 -> V_249 = F_81 ( & V_48 -> V_205 ,
& V_250 , V_251 ,
0 , 65535 , 65535 / 100 , V_232 ) ;
V_48 -> V_252 = F_81 ( & V_48 -> V_205 ,
& V_250 , V_253 ,
0 , 1 , 1 , 0 ) ;
F_81 ( & V_48 -> V_205 , & V_250 ,
V_254 ,
0 , 65535 , 65535 / 100 , 32768 ) ;
F_81 ( & V_48 -> V_205 , & V_250 ,
V_255 ,
0 , 65535 , 65535 / 100 , 32768 ) ;
F_81 ( & V_48 -> V_205 , & V_250 ,
V_256 ,
0 , 65535 , 65535 / 100 , 32768 ) ;
}
V_18 -> V_257 = & V_48 -> V_205 ;
if ( V_48 -> V_205 . error ) {
int V_258 = V_48 -> V_205 . error ;
F_82 ( & V_48 -> V_205 ) ;
F_83 ( V_48 ) ;
return V_258 ;
}
if ( ! F_40 ( V_48 ) )
F_84 ( 2 , & V_48 -> V_249 ) ;
F_85 ( & V_48 -> V_205 ) ;
if ( V_2 -> V_259 . V_260 ) {
struct V_261 * V_262 = V_2 -> V_259 . V_260 ;
V_48 -> V_97 = V_262 -> V_97 ;
}
F_86 ( V_18 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_24 ( V_2 ) ;
struct V_47 * V_48 = F_12 ( V_18 ) ;
F_88 ( V_18 ) ;
F_89 ( V_18 ) ;
F_82 ( & V_48 -> V_205 ) ;
F_83 ( V_48 ) ;
return 0 ;
}
static T_6 int F_90 ( void )
{
return F_91 ( & V_263 ) ;
}
static T_7 void F_92 ( void )
{
F_93 ( & V_263 ) ;
}
