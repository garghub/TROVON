static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 [] = { V_3 } ;
T_1 V_5 [] = { 0 } ;
struct V_6 V_7 [] = { { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_12 = V_4 , . V_13 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_14 , . V_12 = V_5 , . V_13 = 1 } } ;
int V_15 ;
V_15 = F_2 ( V_2 -> V_16 , V_7 , 2 ) ;
if ( V_15 != 2 ) {
int V_17 = V_2 -> V_18 . V_19 ? V_2 -> V_18 . V_19 -> V_17 : - 1 ;
F_3 ( V_20 L_1
L_2 ,
V_17 , V_21 , V_3 , V_15 ) ;
}
return V_5 [ 0 ] ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_22 )
{
T_1 V_12 [] = { V_3 , V_22 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_12 = V_12 , . V_13 = 2 } ;
int V_15 ;
V_15 = F_2 ( V_2 -> V_16 , & V_7 , 1 ) ;
if ( V_15 != 1 ) {
int V_17 = V_2 -> V_18 . V_19 ? V_2 -> V_18 . V_19 -> V_17 : - 1 ;
F_3 ( V_20 L_3
L_4 ,
V_17 , V_21 , V_3 , V_22 , V_15 ) ;
}
return ( V_15 != 1 ) ? - V_23 : 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_24 , T_1 V_22 )
{
if ( V_24 == 0xff )
return F_4 ( V_2 , V_3 , V_22 ) ;
else {
T_1 V_25 ;
V_25 = F_1 ( V_2 , V_3 ) ;
V_25 &= ~ V_24 ;
V_25 |= ( V_22 & V_24 ) ;
return F_4 ( V_2 , V_3 , V_25 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_26 )
{
T_1 V_27 , V_28 , V_29 ;
while ( 1 ) {
V_27 = * V_26 ++ ;
V_28 = * V_26 ++ ;
V_29 = * V_26 ++ ;
if ( V_27 == 0xff ) {
if ( V_28 == 0xff )
break;
else
F_7 ( V_28 ) ;
}
else
F_5 ( V_2 , V_27 , V_28 , V_29 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_12 [ 2 ] = { 0x0f , 0xc0 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_12 = V_12 , . V_13 = 2 } ;
if( F_2 ( V_2 -> V_16 , & V_7 , 1 ) != 1 )
{
F_3 ( L_5 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_12 [ 2 ] = { 0x0f , 0x40 } ;
struct V_6 V_30 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_12 = V_12 , . V_13 = 2 } ;
if( F_2 ( V_2 -> V_16 , & V_30 , 1 ) != 1 )
{
F_3 ( L_6 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_31 )
{
V_31 |= V_2 -> V_31 & 0x63 ;
F_4 ( V_2 , 0x00 , V_31 & 0xfe ) ;
F_4 ( V_2 , 0x00 , V_31 | 0x01 ) ;
V_2 -> V_31 = V_31 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_32 )
{
T_3 V_33 ;
T_3 V_34 ;
T_4 V_35 = 0 ;
T_5 V_36 = 0 ;
T_2 V_37 = V_2 -> V_38 * 10 ;
if ( V_32 < ( T_2 ) ( V_37 / 984 ) ) {
V_36 = 3 ;
V_35 = 1 ;
} else if ( V_32 < ( T_2 ) ( V_37 / 640 ) ) {
V_36 = 3 ;
V_35 = 0 ;
} else if ( V_32 < ( T_2 ) ( V_37 / 492 ) ) {
V_36 = 2 ;
V_35 = 1 ;
} else if ( V_32 < ( T_2 ) ( V_37 / 320 ) ) {
V_36 = 2 ;
V_35 = 0 ;
} else if ( V_32 < ( T_2 ) ( V_37 / 246 ) ) {
V_36 = 1 ;
V_35 = 1 ;
} else if ( V_32 < ( T_2 ) ( V_37 / 160 ) ) {
V_36 = 1 ;
V_35 = 0 ;
} else if ( V_32 < ( T_2 ) ( V_37 / 123 ) ) {
V_36 = 0 ;
V_35 = 1 ;
}
V_34 = ( V_2 -> V_38 ) * 16 ;
V_34 >>= V_36 ;
V_34 += V_32 / 2 ;
V_34 /= V_32 ;
if ( V_34 > 255 )
V_34 = 255 ;
{
T_6 V_39 ;
V_39 = 1 << ( 24 + V_36 ) ;
V_39 *= V_32 ;
F_12 ( V_39 , V_2 -> V_38 ) ;
V_33 = ( T_3 ) V_39 ;
}
F_13 ( L_7 ,
V_32 , V_33 , V_34 , V_36 ) ;
F_5 ( V_2 , 0x03 , 0xc0 , V_36 << 6 ) ;
F_4 ( V_2 , 0x0a , V_33 & 255 ) ;
F_4 ( V_2 , 0x0b , ( V_33 >> 8 ) & 255 ) ;
F_4 ( V_2 , 0x0c , ( V_33 >> 16 ) & 31 ) ;
F_4 ( V_2 , 0x0d , V_34 ) ;
F_4 ( V_2 , 0x3d , ( V_35 << 7 ) ) ;
return 0 ;
}
static int F_14 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_43 [] = {
0x2a , 0xff , 0x02 ,
0xff , 0x64 , 0x00 ,
0x2a , 0xff , 0x03 ,
0xff , 0x64 , 0x00 ,
0x28 , 0xff , ( V_2 -> V_44 - 1 ) ,
0x29 , 0xff , ( ( V_2 -> V_45 - 1 ) << 6 ) | ( V_2 -> V_46 - 1 ) ,
0x00 , 0xff , V_47 ,
0x2a , 0xff , 0x08 ,
0xff , 0x64 , 0x00 ,
0x1f , 0xff , 0x00 ,
0xff , 0x64 , 0x00 ,
0xe6 , 0x0c , 0x04 ,
0x10 , 0xc0 , 0x80 ,
0x0e , 0xff , 0x82 ,
0x03 , 0x08 , 0x08 ,
0x2e , 0xbf , 0x30 ,
0x01 , 0xff , 0x30 ,
0x1e , 0x84 , 0x84 ,
0x1b , 0xff , 0xc8 ,
0x3b , 0xff , 0xff ,
0x3c , 0xff , 0x00 ,
0x34 , 0xff , 0x00 ,
0x35 , 0xff , 0xff ,
0x36 , 0xff , 0x00 ,
0x06 , 0xff , 0x7f ,
0x1c , 0x30 , 0x30 ,
0x37 , 0xff , 0xf6 ,
0x38 , 0xff , 0xff ,
0x02 , 0xff , 0x93 ,
0x2d , 0xff , 0xf6 ,
0x04 , 0x10 , 0x00 ,
0x12 , 0xff , V_48 ,
0x2b , 0x01 , 0xa1 ,
0x20 , 0xff , 0x04 ,
0x2c , 0xff , 0x0d ,
0xc4 , 0xff , 0x00 ,
0xc3 , 0x30 , 0x00 ,
0xb5 , 0xff , 0x19 ,
0x00 , 0x03 , 0x01 ,
0x00 , 0x03 , 0x03 ,
0xff , 0x64 , 0x00 ,
0xff , 0xff , 0xff
} ;
F_13 ( L_8 , V_41 -> V_19 -> V_17 ) ;
if ( V_2 -> V_9 -> V_49 ) {
V_43 [ 80 ] = ( V_2 -> V_9 -> V_49 & 0xff ) ;
V_43 [ 83 ] = ( V_2 -> V_9 -> V_49 >> 8 ) ;
}
if ( V_2 -> V_9 -> V_50 )
V_43 [ 95 ] = V_2 -> V_9 -> V_50 ;
F_6 ( V_2 , V_43 ) ;
return 0 ;
}
static int F_15 ( struct V_40 * V_41 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
static int V_53 [ 6 ] [ 6 ] = {
{ ( 5 << 2 ) , 0x78 , 0x8c , 0x96 , 0x78 , 0x4c } ,
{ ( 0 << 2 ) , 0x87 , 0xa2 , 0x91 , 0x8c , 0x57 } ,
{ ( 1 << 2 ) , 0x64 , 0x74 , 0x96 , 0x8c , 0x57 } ,
{ ( 2 << 2 ) , 0x46 , 0x43 , 0x6a , 0x6a , 0x44 } ,
{ ( 3 << 2 ) , 0x36 , 0x34 , 0x7e , 0x78 , 0x4c } ,
{ ( 4 << 2 ) , 0x26 , 0x23 , 0x6c , 0x5c , 0x3c } ,
} ;
int V_54 = V_52 -> V_55 . V_54 . V_56 ;
if ( V_54 < 0 || V_54 > 5 )
return - V_57 ;
if ( V_41 -> V_58 . V_59 . V_60 ) {
V_41 -> V_58 . V_59 . V_60 ( V_41 , V_52 ) ;
if ( V_41 -> V_58 . V_61 ) V_41 -> V_58 . V_61 ( V_41 , 0 ) ;
}
F_11 ( V_2 , V_52 -> V_55 . V_54 . V_62 ) ;
F_4 ( V_2 , 0x05 , V_53 [ V_54 ] [ 1 ] ) ;
F_4 ( V_2 , 0x08 , V_53 [ V_54 ] [ 2 ] ) ;
F_4 ( V_2 , 0x09 , V_53 [ V_54 ] [ 3 ] ) ;
F_4 ( V_2 , 0xb4 , V_53 [ V_54 ] [ 4 ] ) ;
F_4 ( V_2 , 0xb6 , V_53 [ V_54 ] [ 5 ] ) ;
F_5 ( V_2 , 0x04 , 0x40 , 0x40 ) ;
F_10 ( V_2 , V_53 [ V_54 ] [ 0 ] ) ;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 , T_7 * V_63 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
int V_64 ;
* V_63 = 0 ;
V_64 = F_1 ( V_2 , 0x11 ) ;
if ( V_64 & 2 )
* V_63 |= V_65 | V_66 ;
if ( V_64 & 4 )
* V_63 |= V_67 | V_68 ;
if ( V_64 & 8 )
* V_63 |= V_69 ;
return 0 ;
}
static int F_17 ( struct V_40 * V_41 , T_2 * V_70 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_71 , V_72 , V_73 ;
V_71 = F_1 ( V_2 , 0x14 ) ;
V_72 = F_1 ( V_2 , 0x15 ) ;
V_73 = F_1 ( V_2 , 0x16 ) & 0xf ;
F_5 ( V_2 , 0x10 , 0xc0 , 0x00 ) ;
* V_70 = V_71 | ( V_72 << 8 ) | ( V_73 << 16 ) ;
return 0 ;
}
static int F_18 ( struct V_40 * V_41 , T_5 * V_74 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_75 = F_1 ( V_2 , 0x2f ) ;
T_5 V_76 = ( ( 255 - F_1 ( V_2 , 0x17 ) ) ) + ( 255 - V_75 ) / 16 ;
if ( V_76 > 0x90 )
V_76 = V_76 + 2 * ( V_76 - 0x90 ) ;
if ( V_76 > 255 )
V_76 = 255 ;
* V_74 = ( V_76 << 8 ) | V_76 ;
return 0 ;
}
static int F_19 ( struct V_40 * V_41 , T_5 * V_77 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_78 = ~ F_1 ( V_2 , 0x18 ) ;
* V_77 = ( V_78 << 8 ) | V_78 ;
return 0 ;
}
static int F_20 ( struct V_40 * V_41 , T_2 * V_79 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_71 , V_72 , V_73 , V_80 ;
V_71 = F_1 ( V_2 , 0x74 ) ;
V_72 = F_1 ( V_2 , 0x75 ) ;
V_73 = F_1 ( V_2 , 0x76 ) ;
V_80 = F_1 ( V_2 , 0x77 ) ;
* V_79 = V_71 | ( V_72 << 8 ) | ( V_73 << 16 ) | ( V_80 << 24 ) ;
F_5 ( V_2 , 0x10 , 0x20 , 0x00 ) ;
F_5 ( V_2 , 0x10 , 0x20 , 0x20 ) ;
F_5 ( V_2 , 0x13 , 0x01 , 0x00 ) ;
return 0 ;
}
static int F_21 ( struct V_40 * V_41 , struct V_51 * V_52 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
int V_64 , V_81 ;
T_8 V_82 = 0 ;
V_64 = F_1 ( V_2 , 0x11 ) ;
V_82 = F_1 ( V_2 , 0x19 ) ;
V_81 = F_1 ( V_2 , 0x04 ) ;
if ( V_83 ) {
F_3 ( V_64 & 2 ? L_9 :
L_10 ,
V_2 -> V_18 . V_19 -> V_17 , V_82 ,
- ( ( T_3 ) V_52 -> V_55 . V_54 . V_62 * V_82 ) >> 10 ) ;
}
V_52 -> V_84 = ( V_81 & 0x20 ? 0 : 1 ) ;
V_52 -> V_55 . V_54 . V_56 = ( ( V_2 -> V_31 >> 2 ) & 7 ) + V_85 ;
V_52 -> V_55 . V_54 . V_86 = V_87 ;
V_52 -> V_88 = ( ( V_52 -> V_88 + 31250 ) / 62500 ) * 62500 ;
if ( V_64 & 2 )
V_52 -> V_88 -= ( ( T_3 ) V_52 -> V_55 . V_54 . V_62 * V_82 ) >> 10 ;
return 0 ;
}
static int F_22 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
F_4 ( V_2 , 0x1b , 0x02 ) ;
F_4 ( V_2 , 0x00 , 0x80 ) ;
return 0 ;
}
static int F_23 ( struct V_40 * V_41 , int V_89 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
if ( V_89 ) {
F_8 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
}
return 0 ;
}
static void F_24 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
F_25 ( V_2 ) ;
}
struct V_40 * F_26 ( const struct V_90 * V_9 ,
struct V_91 * V_16 ,
T_1 V_92 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_93 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_16 = V_16 ;
F_4 ( V_2 , 0x00 , 0x33 ) ;
if ( ( F_1 ( V_2 , 0x1a ) & 0xf0 ) != 0x70 ) goto error;
memcpy ( & V_2 -> V_18 . V_58 , & V_94 , sizeof( struct V_95 ) ) ;
V_2 -> V_92 = V_92 ;
V_2 -> V_31 = V_47 ;
if ( V_2 -> V_9 -> V_96 ) {
V_2 -> V_96 = V_2 -> V_9 -> V_96 ;
V_2 -> V_44 = V_2 -> V_9 -> V_44 ;
V_2 -> V_45 = V_2 -> V_9 -> V_45 ;
V_2 -> V_46 = V_2 -> V_9 -> V_46 ;
} else {
V_2 -> V_96 = 28920000 ;
V_2 -> V_44 = 8 ;
V_2 -> V_45 = 4 ;
V_2 -> V_46 = 1 ;
}
V_2 -> V_38 = ( V_2 -> V_96 * V_2 -> V_44 / \
( V_2 -> V_46 * V_2 -> V_45 ) ) ;
V_2 -> V_18 . V_58 . V_97 . V_98 = ( V_2 -> V_38 / 2 ) / 64 ;
V_2 -> V_18 . V_58 . V_97 . V_99 = ( V_2 -> V_38 / 2 ) / 4 ;
F_13 ( L_11 ,
V_21 , V_2 -> V_96 , V_2 -> V_44 , V_2 -> V_45 ,
V_2 -> V_46 ) ;
V_2 -> V_18 . V_42 = V_2 ;
return & V_2 -> V_18 ;
error:
F_25 ( V_2 ) ;
return NULL ;
}
