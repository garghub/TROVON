static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return;
F_2 ( V_9 , L_1 , V_2 , V_3 ) ;
V_1 -> V_10 [ 0 ] = V_3 ;
V_7 = F_3 ( V_5 ,
F_4 ( V_5 , 0 ) ,
0x01 ,
V_11 | V_12 | V_13 ,
0x00 , V_2 , V_1 -> V_10 , 1 , V_14 ) ;
if ( V_7 < 0 ) {
F_5 ( L_2 , V_7 ) ;
V_1 -> V_8 = V_7 ;
}
}
static T_2 F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 ;
if ( V_1 -> V_8 < 0 )
return 0 ;
V_7 = F_3 ( V_5 ,
F_7 ( V_5 , 0 ) ,
0x01 ,
V_15 | V_12 | V_13 ,
0x00 , V_2 , V_1 -> V_10 , 1 , V_14 ) ;
F_2 ( V_16 , L_3 , V_2 , V_1 -> V_10 [ 0 ] ) ;
if ( V_7 < 0 ) {
F_5 ( L_4 , V_7 ) ;
V_1 -> V_8 = V_7 ;
}
return V_1 -> V_10 [ 0 ] ;
}
static void F_8 ( struct V_1 * V_1 , int V_17 )
{
T_2 V_18 ;
F_2 ( V_19 , L_5 , V_17 ) ;
V_18 = F_6 ( V_1 , 0x21 ) ;
V_18 |= 0x80 ;
F_1 ( V_1 , 0x21 , V_18 ) ;
V_18 = F_6 ( V_1 , 0x23 ) ;
if ( V_17 )
V_18 |= 0x80 ;
else
V_18 &= ~ 0x80 ;
F_1 ( V_1 , 0x23 , V_18 ) ;
if ( ! V_17 ) {
V_18 = F_6 ( V_1 , 0x21 ) ;
V_18 &= ~ 0x80 ;
F_1 ( V_1 , 0x21 , V_18 ) ;
}
}
static int F_9 ( struct V_1 * V_1 )
{
T_2 V_18 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
V_18 = F_6 ( V_1 , V_21 ) ;
switch ( V_18 ) {
case 0x00 :
return 1 ;
case 0x04 :
return 0 ;
case 0x03 :
break;
default:
F_2 ( V_22 , L_6 ,
V_18 , V_20 + 1 ) ;
}
}
return 0 ;
}
static void F_10 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_9 , L_7 , V_2 , V_3 ) ;
F_1 ( V_1 , V_23 , V_2 ) ;
F_1 ( V_1 , V_24 , V_3 ) ;
F_1 ( V_1 , V_25 , V_26 ) ;
if ( ! F_9 ( V_1 ) ) {
F_5 ( L_8 ) ;
V_1 -> V_8 = - V_27 ;
}
}
static T_2 F_11 ( struct V_1 * V_1 , T_1 V_2 )
{
F_1 ( V_1 , V_23 , V_2 ) ;
F_1 ( V_1 , V_25 , V_28 ) ;
if ( ! F_9 ( V_1 ) )
F_5 ( L_9 ) ;
F_1 ( V_1 , V_25 , V_29 ) ;
if ( ! F_9 ( V_1 ) )
F_5 ( L_10 ) ;
return F_6 ( V_1 , V_30 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
int V_20 ;
struct V_32 {
T_2 V_33 ;
T_2 V_34 ;
T_2 V_35 ;
T_2 V_36 ;
};
const struct V_32 * V_37 ;
static const struct V_32 V_38 [] = {
{ 60 , 0x01 , 0xc1 , 0x04 } ,
{ 50 , 0x01 , 0x41 , 0x02 } ,
{ 40 , 0x02 , 0xc1 , 0x04 } ,
{ 30 , 0x04 , 0x81 , 0x02 } ,
{ 15 , 0x03 , 0x41 , 0x04 } ,
} ;
static const struct V_32 V_39 [] = {
{ 125 , 0x02 , 0x81 , 0x02 } ,
{ 100 , 0x02 , 0xc1 , 0x04 } ,
{ 75 , 0x03 , 0xc1 , 0x04 } ,
{ 60 , 0x04 , 0xc1 , 0x04 } ,
{ 50 , 0x02 , 0x41 , 0x04 } ,
{ 40 , 0x03 , 0x41 , 0x04 } ,
{ 30 , 0x04 , 0x41 , 0x04 } ,
} ;
if ( V_31 -> V_40 != V_41 )
return;
if ( V_1 -> V_42 . V_43 [ V_1 -> V_44 ] . V_45 == 0 ) {
V_37 = V_38 ;
V_20 = F_13 ( V_38 ) ;
} else {
V_37 = V_39 ;
V_20 = F_13 ( V_39 ) ;
}
while ( -- V_20 > 0 ) {
if ( V_31 -> V_46 >= V_37 -> V_33 )
break;
V_37 ++ ;
}
F_10 ( V_1 , 0x11 , V_37 -> V_34 ) ;
F_10 ( V_1 , 0x0d , V_37 -> V_35 ) ;
F_1 ( V_1 , 0xe5 , V_37 -> V_36 ) ;
F_2 ( V_47 , L_11 , V_37 -> V_33 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
int V_3 ;
V_3 = V_31 -> V_48 [ V_49 ] . V_3 ;
if ( V_31 -> V_40 == V_50 ) {
if ( V_3 < 0 )
V_3 = 0x80 - V_3 ;
F_10 ( V_1 , 0x55 , V_3 ) ;
} else {
F_10 ( V_1 , 0x9b , V_3 ) ;
}
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_3 ;
V_3 = V_31 -> V_48 [ V_51 ] . V_3 ;
if ( V_31 -> V_40 == V_50 )
F_10 ( V_1 , 0x56 , V_3 ) ;
else
F_10 ( V_1 , 0x9c , V_3 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_3 ;
if ( V_31 -> V_48 [ V_52 ] . V_3 )
return;
V_3 = V_31 -> V_48 [ V_53 ] . V_3 ;
switch ( V_3 & 0x30 ) {
case 0x00 :
V_3 &= 0x0f ;
break;
case 0x10 :
V_3 &= 0x0f ;
V_3 |= 0x30 ;
break;
case 0x20 :
V_3 &= 0x0f ;
V_3 |= 0x70 ;
break;
default:
V_3 &= 0x0f ;
V_3 |= 0xf0 ;
break;
}
F_10 ( V_1 , 0x00 , V_3 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_3 ;
if ( V_31 -> V_48 [ V_54 ] . V_3 )
return;
V_3 = V_31 -> V_48 [ V_55 ] . V_3 ;
if ( V_31 -> V_40 == V_50 ) {
F_10 ( V_1 , 0x10 , V_3 ) ;
} else {
F_10 ( V_1 , 0x08 , V_3 >> 7 ) ;
F_10 ( V_1 , 0x10 , V_3 << 1 ) ;
}
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
if ( V_31 -> V_48 [ V_52 ] . V_3 ) {
F_10 ( V_1 , 0x13 ,
F_11 ( V_1 , 0x13 ) | 0x04 ) ;
F_10 ( V_1 , 0x64 ,
F_11 ( V_1 , 0x64 ) | 0x03 ) ;
} else {
F_10 ( V_1 , 0x13 ,
F_11 ( V_1 , 0x13 ) & ~ 0x04 ) ;
F_10 ( V_1 , 0x64 ,
F_11 ( V_1 , 0x64 ) & ~ 0x03 ) ;
F_16 ( V_1 ) ;
}
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
if ( V_31 -> V_48 [ V_56 ] . V_3 ) {
F_10 ( V_1 , 0x13 ,
F_11 ( V_1 , 0x13 ) | 0x02 ) ;
if ( V_31 -> V_40 == V_41 )
F_10 ( V_1 , 0x63 ,
F_11 ( V_1 , 0x63 ) | 0xc0 ) ;
} else {
F_10 ( V_1 , 0x13 ,
F_11 ( V_1 , 0x13 ) & ~ 0x02 ) ;
if ( V_31 -> V_40 == V_41 )
F_10 ( V_1 , 0x63 ,
F_11 ( V_1 , 0x63 ) & ~ 0xc0 ) ;
}
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_18 ;
V_18 = V_31 -> V_40 == V_50 ?
0x05 :
0x01 ;
if ( V_31 -> V_48 [ V_54 ] . V_3 )
F_10 ( V_1 , 0x13 ,
F_11 ( V_1 , 0x13 ) | V_18 ) ;
else {
F_10 ( V_1 , 0x13 ,
F_11 ( V_1 , 0x13 ) & ~ V_18 ) ;
if ( V_31 -> V_40 == V_50 )
V_31 -> V_48 [ V_55 ] . V_3 =
F_11 ( V_1 , 10 ) ;
else
F_17 ( V_1 ) ;
}
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_3 ;
V_3 = V_31 -> V_48 [ V_57 ] . V_3 ;
F_10 ( V_1 , 0x91 , V_3 ) ;
F_10 ( V_1 , 0x8e , V_3 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_3 ;
if ( V_31 -> V_40 == V_50 ) {
V_3 = F_11 ( V_1 , 0x1e ) ;
V_3 &= ~ 0x30 ;
if ( V_31 -> V_48 [ V_58 ] . V_3 )
V_3 |= 0x20 ;
if ( V_31 -> V_48 [ V_59 ] . V_3 )
V_3 |= 0x10 ;
F_10 ( V_1 , 0x1e , V_3 ) ;
} else {
V_3 = F_11 ( V_1 , 0x0c ) ;
V_3 &= ~ 0xc0 ;
if ( V_31 -> V_48 [ V_58 ] . V_3 == 0 )
V_3 |= 0x40 ;
if ( V_31 -> V_48 [ V_59 ] . V_3 == 0 )
V_3 |= 0x80 ;
F_10 ( V_1 , 0x0c , V_3 ) ;
}
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_3 ;
int V_20 ;
static T_2 V_60 [] [ 6 ] = {
{ 0x42 , 0x42 , 0x00 , 0x11 , 0x30 , 0x41 } ,
{ 0x52 , 0x52 , 0x00 , 0x16 , 0x3c , 0x52 } ,
{ 0x66 , 0x66 , 0x00 , 0x1b , 0x4b , 0x66 } ,
{ 0x80 , 0x80 , 0x00 , 0x22 , 0x5e , 0x80 } ,
{ 0x9a , 0x9a , 0x00 , 0x29 , 0x71 , 0x9a } ,
{ 0xb8 , 0xb8 , 0x00 , 0x31 , 0x87 , 0xb8 } ,
{ 0xdd , 0xdd , 0x00 , 0x3b , 0xa2 , 0xdd } ,
} ;
V_3 = V_31 -> V_48 [ V_61 ] . V_3 ;
for ( V_20 = 0 ; V_20 < F_13 ( V_60 [ 0 ] ) ; V_20 ++ )
F_10 ( V_1 , 0x4f + V_20 , V_60 [ V_3 ] [ V_20 ] ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_2 V_3 ;
V_3 = V_31 -> V_48 [ V_62 ] . V_3 ? 0x9e : 0x00 ;
if ( V_31 -> V_40 == V_50 ) {
F_10 ( V_1 , 0x2a , 0x00 ) ;
if ( V_3 )
V_3 = 0x9d ;
}
F_10 ( V_1 , 0x2b , V_3 ) ;
}
static int F_25 ( struct V_1 * V_1 ,
const struct V_63 * V_64 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
struct V_42 * V_42 ;
V_42 = & V_1 -> V_42 ;
V_42 -> V_48 = V_31 -> V_48 ;
if ( V_65 [ V_52 ] . V_66 . V_67 == 0 )
V_1 -> V_68 |= ( 1 << V_56 ) ;
V_42 -> V_43 = V_69 ;
V_42 -> V_70 = F_13 ( V_69 ) ;
V_31 -> V_46 = 30 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_1 V_71 ;
static const struct V_72 V_73 [ V_74 ] = {
[ V_50 ] = { V_75 , F_13 (bridge_init_767x) } ,
[ V_41 ] = { V_76 , F_13 (bridge_init_772x) } ,
} ;
static const struct V_72 V_77 [ V_74 ] = {
[ V_50 ] = { V_78 , F_13 (sensor_init_767x) } ,
[ V_41 ] = { V_79 , F_13 (sensor_init_772x) } ,
} ;
F_1 ( V_1 , 0xe7 , 0x3a ) ;
F_1 ( V_1 , 0xe0 , 0x08 ) ;
F_27 ( 100 ) ;
F_1 ( V_1 , V_80 , 0x42 ) ;
F_10 ( V_1 , 0x12 , 0x80 ) ;
F_27 ( 10 ) ;
F_11 ( V_1 , 0x0a ) ;
V_71 = F_11 ( V_1 , 0x0a ) << 8 ;
F_11 ( V_1 , 0x0b ) ;
V_71 |= F_11 ( V_1 , 0x0b ) ;
F_2 ( V_47 , L_12 , V_71 ) ;
if ( ( V_71 & 0xfff0 ) == 0x7670 ) {
V_31 -> V_40 = V_50 ;
V_1 -> V_81 = ( 1 << V_53 ) |
( 1 << V_52 ) |
( 1 << V_57 ) ;
V_31 -> V_48 [ V_49 ] . V_82 = - 127 ;
V_31 -> V_48 [ V_49 ] . V_83 = 127 ;
V_31 -> V_48 [ V_49 ] . V_84 = 0 ;
V_31 -> V_48 [ V_51 ] . V_83 = 0x80 ;
V_31 -> V_48 [ V_51 ] . V_84 = 0x40 ;
V_31 -> V_48 [ V_55 ] . V_82 = 0x08 ;
V_31 -> V_48 [ V_55 ] . V_83 = 0x60 ;
V_31 -> V_48 [ V_55 ] . V_84 = 0x13 ;
V_31 -> V_48 [ V_57 ] . V_83 = 9 ;
V_31 -> V_48 [ V_57 ] . V_84 = 4 ;
V_31 -> V_48 [ V_58 ] . V_84 = 1 ;
V_1 -> V_42 . V_43 = V_85 ;
V_1 -> V_42 . V_70 = F_13 ( V_85 ) ;
} else {
V_31 -> V_40 = V_41 ;
V_1 -> V_81 = ( 1 << V_61 ) ;
V_1 -> V_42 . V_86 = 1 ;
V_1 -> V_42 . V_87 = 16384 ;
V_1 -> V_42 . V_88 = 2 ;
V_1 -> V_42 . V_89 = V_90 ;
}
F_28 ( V_1 , V_73 [ V_31 -> V_40 ] . V_3 ,
V_73 [ V_31 -> V_40 ] . V_91 ) ;
F_8 ( V_1 , 1 ) ;
F_29 ( V_1 , V_77 [ V_31 -> V_40 ] . V_3 ,
V_77 [ V_31 -> V_40 ] . V_91 ) ;
if ( V_31 -> V_40 == V_50 )
F_30 ( V_1 ) ;
F_31 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
int V_92 ;
static const struct V_72 V_93 [ V_74 ] [ 2 ] = {
[ V_50 ] = { { V_94 ,
F_13 (bridge_start_qvga_767x) } ,
{ V_95 ,
F_13 (bridge_start_vga_767x) } } ,
[ V_41 ] = { { V_96 ,
F_13 (bridge_start_qvga_772x) } ,
{ V_97 ,
F_13 (bridge_start_vga_772x) } } ,
} ;
static const struct V_72 V_98 [ V_74 ] [ 2 ] = {
[ V_50 ] = { { V_99 ,
F_13 (sensor_start_qvga_767x) } ,
{ V_100 ,
F_13 (sensor_start_vga_767x) } } ,
[ V_41 ] = { { V_101 ,
F_13 (sensor_start_qvga_772x) } ,
{ V_102 ,
F_13 (sensor_start_vga_772x) } } ,
} ;
if ( V_31 -> V_40 == V_50 )
F_10 ( V_1 , 0x1e , 0x04 ) ;
V_92 = V_1 -> V_44 ;
F_28 ( V_1 , V_93 [ V_31 -> V_40 ] [ V_92 ] . V_3 ,
V_93 [ V_31 -> V_40 ] [ V_92 ] . V_91 ) ;
F_29 ( V_1 , V_98 [ V_31 -> V_40 ] [ V_92 ] . V_3 ,
V_98 [ V_31 -> V_40 ] [ V_92 ] . V_91 ) ;
F_12 ( V_1 ) ;
if ( ! ( V_1 -> V_81 & ( 1 << V_52 ) ) )
F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
if ( ! ( V_1 -> V_81 & ( 1 << V_53 ) ) )
F_16 ( V_1 ) ;
F_17 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
if ( ! ( V_1 -> V_81 & ( 1 << V_57 ) ) )
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
if ( ! ( V_1 -> V_81 & ( 1 << V_61 ) ) )
F_23 ( V_1 ) ;
F_24 ( V_1 ) ;
F_8 ( V_1 , 1 ) ;
F_1 ( V_1 , 0xe0 , 0x00 ) ;
return V_1 -> V_8 ;
}
static void F_31 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0xe0 , 0x09 ) ;
F_8 ( V_1 , 0 ) ;
}
static void F_32 ( struct V_1 * V_1 ,
T_2 * V_18 , int V_91 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
T_3 V_103 ;
T_1 V_104 ;
int V_105 = V_91 ;
int V_106 ;
V_106 = V_1 -> V_42 . V_86 ? 2048 : 2040 ;
do {
V_91 = V_82 ( V_105 , V_106 ) ;
if ( V_18 [ 0 ] != 12 || V_91 < 12 ) {
F_2 ( V_107 , L_13 ) ;
goto V_108;
}
if ( V_18 [ 1 ] & V_109 ) {
F_2 ( V_107 , L_14 ) ;
goto V_108;
}
if ( ! ( V_18 [ 1 ] & V_110 ) ) {
F_2 ( V_107 , L_15 ) ;
goto V_108;
}
V_103 = ( V_18 [ 5 ] << 24 ) | ( V_18 [ 4 ] << 16 )
| ( V_18 [ 3 ] << 8 ) | V_18 [ 2 ] ;
V_104 = ( V_18 [ 1 ] & V_111 ) ? 1 : 0 ;
if ( V_103 != V_31 -> V_112 || V_104 != V_31 -> V_113 ) {
if ( V_1 -> V_114 == V_115 )
F_33 ( V_1 , V_116 ,
NULL , 0 ) ;
V_31 -> V_112 = V_103 ;
V_31 -> V_113 = V_104 ;
F_33 ( V_1 , V_117 ,
V_18 + 12 , V_91 - 12 ) ;
} else if ( V_18 [ 1 ] & V_118 ) {
V_31 -> V_112 = 0 ;
if ( V_1 -> V_119 == V_120
&& V_1 -> V_121 + V_91 - 12 !=
V_1 -> V_122 * V_1 -> V_123 * 2 ) {
F_2 ( V_107 , L_16 ) ;
goto V_108;
}
F_33 ( V_1 , V_116 ,
V_18 + 12 , V_91 - 12 ) ;
} else {
F_33 ( V_1 , V_115 ,
V_18 + 12 , V_91 - 12 ) ;
}
goto V_124;
V_108:
V_1 -> V_114 = V_125 ;
V_124:
V_105 -= V_91 ;
V_18 += V_91 ;
} while ( V_105 > 0 );
}
static int F_34 ( struct V_1 * V_1 , T_4 V_3 )
{
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
V_31 -> V_48 [ V_52 ] . V_3 = V_3 ;
if ( V_3 ) {
V_1 -> V_68 &= ~ ( 1 << V_56 ) ;
} else {
V_1 -> V_68 |= ( 1 << V_56 ) ;
if ( V_31 -> V_48 [ V_56 ] . V_3 ) {
V_31 -> V_48 [ V_56 ] . V_3 = 0 ;
if ( V_1 -> V_126 )
F_19 ( V_1 ) ;
}
}
if ( V_1 -> V_126 )
F_18 ( V_1 ) ;
return V_1 -> V_8 ;
}
static int F_35 ( struct V_1 * V_1 ,
struct V_127 * V_128 )
{
switch ( V_128 -> V_64 ) {
case V_129 :
switch ( V_128 -> V_130 ) {
case 0 :
strcpy ( ( char * ) V_128 -> V_131 , L_17 ) ;
return 0 ;
case 1 :
strcpy ( ( char * ) V_128 -> V_131 , L_18 ) ;
return 0 ;
}
break;
}
return - V_132 ;
}
static void F_36 ( struct V_1 * V_1 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 = & V_134 -> V_134 . V_137 ;
struct V_138 * V_139 = & V_136 -> V_140 ;
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
V_136 -> V_141 |= V_142 ;
V_139 -> V_143 = 1 ;
V_139 -> V_144 = V_31 -> V_46 ;
}
static void F_37 ( struct V_1 * V_1 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 = & V_134 -> V_134 . V_137 ;
struct V_138 * V_139 = & V_136 -> V_140 ;
struct V_31 * V_31 = (struct V_31 * ) V_1 ;
V_31 -> V_46 = V_139 -> V_144 / V_139 -> V_143 ;
if ( V_1 -> V_126 )
F_12 ( V_1 ) ;
V_139 -> V_143 = 1 ;
V_139 -> V_144 = V_31 -> V_46 ;
}
static int F_38 ( struct V_145 * V_146 , const struct V_63 * V_64 )
{
return F_39 ( V_146 , V_64 , & V_147 , sizeof( struct V_31 ) ,
V_148 ) ;
}
