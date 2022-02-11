static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_2 ( V_1 -> V_7 ,
F_3 ( V_1 -> V_7 , 0 ) ,
V_2 ,
V_8 | V_9 | V_10 ,
1 ,
V_3 , V_1 -> V_11 , V_4 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_1 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_5 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_1 -> V_6 < 0 )
return;
if ( V_4 == 1 )
F_6 ( V_12 , L_2 , V_2 , V_3 ,
V_1 -> V_11 [ 0 ] ) ;
else
F_6 ( V_12 , L_3 ,
V_2 , V_3 , 3 , V_1 -> V_11 ) ;
}
static void F_7 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_13 ,
T_1 V_3 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_2 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
V_2 ,
V_14 | V_9 | V_10 ,
V_13 , V_3 , NULL , 0 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_4 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_9 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_13 ,
T_1 V_3 )
{
if ( V_1 -> V_6 < 0 )
return;
F_6 ( V_15 , L_5 , V_2 , V_13 , V_3 ) ;
F_7 ( V_1 , V_2 , V_13 , V_3 ) ;
}
static T_1 F_10 ( struct V_1 * V_1 ,
T_1 V_16 )
{
T_2 V_17 , V_18 , V_19 ;
int V_20 = 50 ;
F_5 ( V_1 , 0xa1 , 0xb33f , 1 ) ;
if ( ! ( V_1 -> V_11 [ 0 ] & 0x02 ) ) {
F_4 ( L_6 , V_1 -> V_11 [ 0 ] ) ;
return 0 ;
}
F_9 ( V_1 , 0xa0 , V_16 , 0xb33a ) ;
F_9 ( V_1 , 0xa0 , 0x02 , 0xb339 ) ;
do {
F_5 ( V_1 , 0xa1 , 0xb33b , 1 ) ;
if ( V_1 -> V_11 [ 0 ] == 0x00 )
break;
F_11 ( 40 ) ;
} while ( -- V_20 >= 0 );
F_5 ( V_1 , 0xa1 , 0xb33e , 1 ) ;
V_17 = V_1 -> V_11 [ 0 ] ;
F_5 ( V_1 , 0xa1 , 0xb33d , 1 ) ;
V_18 = V_1 -> V_11 [ 0 ] ;
F_5 ( V_1 , 0xa1 , 0xb33c , 1 ) ;
V_19 = V_1 -> V_11 [ 0 ] ;
if ( V_19 != 0 && V_18 != 0 && V_17 != 0 )
F_6 ( V_21 , L_7 ,
V_19 , V_18 , V_17 ) ;
F_5 ( V_1 , 0xa1 , 0xb334 , 1 ) ;
if ( V_1 -> V_11 [ 0 ] == 0x02 )
return ( V_19 << 8 ) + V_18 ;
return V_19 ;
}
static int F_12 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_23 , V_24 ;
T_1 V_13 ;
const struct V_25 * V_26 ;
if ( V_22 -> V_27 & V_28 ) {
F_9 ( V_1 , 0xa0 , 0x01 , 0xb301 ) ;
F_9 ( V_1 , 0x89 , 0xf0ff , 0xffff ) ;
}
F_5 ( V_1 , 0xa1 , 0xbfcf , 1 ) ;
F_6 ( V_21 , L_8 ,
V_22 -> V_29 == V_30 ? 1 : 3 , V_1 -> V_11 [ 0 ] ) ;
if ( V_22 -> V_29 == V_30 ) {
V_26 = V_31 ;
V_24 = F_13 ( V_31 ) ;
} else {
V_26 = V_32 ;
V_24 = F_13 ( V_32 ) ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
F_9 ( V_1 , 0xa0 , 0x02 , 0xb334 ) ;
F_9 ( V_1 , 0xa0 , V_26 -> V_33 , 0xb300 ) ;
F_9 ( V_1 , 0xa0 , V_26 -> V_34 , 0xb300 ) ;
F_9 ( V_1 , 0xa0 , 0x01 , 0xb308 ) ;
F_9 ( V_1 , 0xa0 , 0x0c , 0xb309 ) ;
F_9 ( V_1 , 0xa0 , V_26 -> V_35 , 0xb335 ) ;
F_9 ( V_1 , 0xa0 , V_26 -> V_36 , 0xb301 ) ;
V_13 = F_10 ( V_1 , V_26 -> V_37 ) ;
if ( V_13 == 0 && V_26 -> V_37 == 0x82 )
V_13 = F_10 ( V_1 , 0x83 ) ;
if ( V_13 != 0 ) {
F_6 ( V_21 , L_9 , V_13 , V_23 ) ;
if ( V_13 == V_26 -> V_38 )
return V_26 -> V_39 ;
switch ( V_13 ) {
case 0x3130 :
return V_40 ;
case 0x7673 :
return V_41 ;
case 0x8243 :
return V_42 ;
}
}
V_26 ++ ;
}
return - 1 ;
}
static void F_14 ( struct V_1 * V_1 ,
T_2 V_43 , const T_2 * V_44 ,
T_2 V_45 )
{
int V_20 ;
if ( V_1 -> V_6 < 0 )
return;
if ( V_45 == 1 )
F_6 ( V_15 , L_10 , V_43 , * V_44 ) ;
else
F_6 ( V_15 , L_11 , V_43 , * V_44 , V_44 [ 1 ] ) ;
F_1 ( V_1 , 0xa1 , 0xb33f , 1 ) ;
F_7 ( V_1 , 0xa0 , V_45 , 0xb334 ) ;
F_7 ( V_1 , 0xa0 , V_43 , 0xb33a ) ;
F_7 ( V_1 , 0xa0 , V_44 [ 0 ] , 0xb336 ) ;
if ( V_45 > 1 )
F_7 ( V_1 , 0xa0 , V_44 [ 1 ] , 0xb337 ) ;
F_7 ( V_1 , 0xa0 , 0x01 , 0xb339 ) ;
V_20 = 4 ;
do {
F_1 ( V_1 , 0xa1 , 0xb33b , 1 ) ;
if ( V_1 -> V_11 [ 0 ] == 0 )
break;
F_11 ( 20 ) ;
} while ( -- V_20 > 0 );
if ( V_20 <= 0 )
F_4 ( L_12 ) ;
}
static void F_15 ( struct V_1 * V_1 ,
const T_2 * V_46 , T_2 V_47 , T_1 V_48 )
{
int V_49 ;
T_1 V_50 = V_48 ;
for ( V_49 = 0 ; V_49 < V_47 ; V_49 ++ )
F_9 ( V_1 , 0xa0 , V_46 [ V_49 ] , V_50 ++ ) ;
}
static void F_16 ( struct V_1 * V_1 ,
const T_2 V_51 [] [ 4 ] )
{
int V_23 = 0 ;
for (; ; ) {
switch ( V_51 [ V_23 ] [ 3 ] ) {
default:
return;
case 0xcc :
F_9 ( V_1 , 0xa0 , V_51 [ V_23 ] [ 2 ] ,
( V_51 [ V_23 ] [ 0 ] ) << 8 | V_51 [ V_23 ] [ 1 ] ) ;
break;
case 0xaa :
F_14 ( V_1 , V_51 [ V_23 ] [ 1 ] , & V_51 [ V_23 ] [ 2 ] , 1 ) ;
break;
case 0xbb :
F_14 ( V_1 , V_51 [ V_23 ] [ 0 ] , & V_51 [ V_23 ] [ 1 ] , 2 ) ;
break;
case 0xdd :
F_11 ( V_51 [ V_23 ] [ 1 ] * 256 + V_51 [ V_23 ] [ 2 ] + 10 ) ;
break;
}
V_23 ++ ;
}
}
static int F_17 ( struct V_1 * V_1 ,
const struct V_52 * V_53 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_29 = V_53 -> V_54 >> 8 ;
V_22 -> V_27 = V_53 -> V_54 & 0xff ;
if ( V_53 -> V_55 == 0x046d &&
( V_53 -> V_56 == 0x0892 || V_53 -> V_56 == 0x0896 ) )
V_22 -> V_57 = V_58 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
struct V_59 * V_59 ;
int V_57 ;
static T_2 V_60 [ V_61 ] = {
[ V_62 ] = 64 ,
[ V_42 ] = 32 ,
[ V_63 ] = 32 ,
[ V_64 ] = 64 ,
[ V_65 ] = 128 ,
[ V_66 ] = 32 ,
[ V_41 ] = 64 ,
[ V_67 ] = 128 ,
[ V_40 ] = 128 ,
[ V_58 ] = 128 ,
} ;
if ( V_22 -> V_57 != V_58 )
V_57 = F_12 ( V_1 ) ;
else
V_57 = V_22 -> V_57 ;
switch ( V_57 ) {
case - 1 :
F_4 ( L_13 ) ;
return - V_68 ;
case V_62 :
F_6 ( V_21 , L_14 ) ;
break;
case V_42 :
F_6 ( V_21 , L_15 ) ;
V_22 -> V_29 = V_69 ;
break;
case V_63 :
F_6 ( V_21 , L_16 ) ;
break;
case V_64 :
F_6 ( V_21 , L_17 ) ;
break;
case V_65 :
F_6 ( V_21 , L_18 ) ;
break;
case V_66 :
F_6 ( V_21 , L_19 ) ;
break;
case V_41 :
F_6 ( V_21 , L_20 ) ;
break;
case V_67 :
F_6 ( V_21 , L_21 ) ;
break;
case V_40 :
F_6 ( V_21 , L_22 ) ;
break;
case V_58 :
F_6 ( V_21 , L_23 ) ;
break;
}
V_22 -> V_57 = V_57 ;
V_59 = & V_1 -> V_59 ;
if ( V_22 -> V_29 == V_30 ) {
V_59 -> V_70 = V_71 ;
V_59 -> V_72 = F_13 ( V_71 ) ;
} else {
switch ( V_57 ) {
case V_67 :
V_59 -> V_70 = V_73 ;
V_59 -> V_72 = F_13 ( V_73 ) ;
break;
case V_63 :
V_59 -> V_70 = V_74 ;
V_59 -> V_72 = F_13 ( V_74 ) ;
break;
case V_65 :
V_59 -> V_70 = V_75 ;
V_59 -> V_72 = F_13 ( V_75 ) ;
break;
case V_41 :
V_59 -> V_70 = V_75 ;
V_59 -> V_72 = F_13 ( V_75 ) - 1 ;
break;
default:
V_59 -> V_70 = V_74 ;
V_59 -> V_72 = F_13 ( V_74 ) - 1 ;
break;
}
}
V_59 -> V_60 = V_60 [ V_22 -> V_57 ] ;
if ( V_22 -> V_57 == V_41 )
V_22 -> V_27 |= V_76 | V_77 ;
if ( V_22 -> V_29 == V_30 ) {
F_5 ( V_1 , 0x8a , 0 , 3 ) ;
F_9 ( V_1 , 0x87 , 0x00 , 0x0f0f ) ;
F_5 ( V_1 , 0x8b , 0 , 3 ) ;
F_9 ( V_1 , 0x88 , 0x00 , 0x0202 ) ;
if ( V_22 -> V_57 == V_58 ) {
F_5 ( V_1 , 0xa1 , 0xb300 , 1 ) ;
if ( V_1 -> V_11 [ 0 ] != 0 ) {
F_9 ( V_1 , 0xa0 , 0x26 , 0xb300 ) ;
F_9 ( V_1 , 0xa0 , 0x04 , 0xb300 ) ;
}
F_9 ( V_1 , 0xa0 , 0x00 , 0xb300 ) ;
}
}
return V_1 -> V_6 ;
}
static void F_19 ( struct V_1 * V_1 , T_3 V_44 )
{
T_2 V_51 ;
V_51 = V_44 ;
if ( V_51 >= 0x80 )
V_51 &= 0x7f ;
else
V_51 = 0xff ^ V_51 ;
F_14 ( V_1 , 0x98 , & V_51 , 1 ) ;
}
static void F_20 ( struct V_1 * V_1 , T_2 V_44 )
{
F_14 ( V_1 , 0x99 , & V_44 , 1 ) ;
}
static void F_21 ( struct V_1 * V_1 , T_2 V_44 )
{
T_2 V_51 ;
V_51 = V_44 - ( V_44 >> 3 ) - 1 ;
F_14 ( V_1 , 0x94 , & V_51 , 1 ) ;
F_14 ( V_1 , 0x95 , & V_44 , 1 ) ;
}
static void F_22 ( struct V_1 * V_1 , bool V_78 , bool V_79 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_51 [ 2 ] ;
if ( V_22 -> V_27 & V_76 )
V_78 = ! V_78 ;
if ( V_22 -> V_27 & V_77 )
V_79 = ! V_79 ;
switch ( V_22 -> V_57 ) {
case V_63 :
case V_64 :
case V_65 :
V_51 [ 0 ] = V_51 [ 1 ] = 0 ;
F_14 ( V_1 , 0xf0 , V_51 , 2 ) ;
V_51 [ 0 ] = V_22 -> V_57 == V_63 ? 0x03 : 0x01 ;
V_51 [ 1 ] = 0x02 * V_78
| 0x01 * V_79 ;
F_14 ( V_1 , 0x20 , V_51 , 2 ) ;
break;
case V_66 :
case V_41 :
V_51 [ 0 ] = V_22 -> V_57 == V_66 ? 0x01 : 0x07 ;
V_51 [ 0 ] |= V_80 * V_78
| V_81 * V_79 ;
F_14 ( V_1 , V_82 , V_51 , 1 ) ;
break;
case V_67 :
V_51 [ 0 ] = 0 ;
F_14 ( V_1 , 0x03 , V_51 , 1 ) ;
V_51 [ 0 ] = 0x80 * V_78
| 0x40 * V_79
| 0x06 ;
F_14 ( V_1 , 0x1e , V_51 , 1 ) ;
break;
}
}
static void F_23 ( struct V_1 * V_1 , T_3 V_44 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
static const T_2 ( * V_83 [ 3 ] ) [ 4 ] =
{ V_84 , V_85 , V_86 } ;
if ( V_22 -> V_57 != V_66 )
return;
F_16 ( V_1 , V_83 [ V_44 ] ) ;
}
static void F_24 ( struct V_1 * V_1 , T_3 V_44 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_51 ;
switch ( V_22 -> V_57 ) {
case V_67 :
V_51 = 0 ;
F_14 ( V_1 , 0x03 , & V_51 , 1 ) ;
if ( V_44 < 0 )
V_51 = 0x6a ;
else
V_51 = 0xb5 + V_44 * 3 ;
F_14 ( V_1 , 0x61 , & V_51 , 1 ) ;
break;
case V_58 :
if ( V_44 < 0 )
V_51 = 0x7e ;
else
V_51 = 0x60 + V_44 * 0x0f ;
F_14 ( V_1 , 0x59 , & V_51 , 1 ) ;
break;
}
}
static void F_25 ( struct V_1 * V_1 , T_2 V_44 )
{
F_14 ( V_1 , 0x15 , & V_44 , 1 ) ;
}
static void F_26 ( struct V_1 * V_1 , T_3 V_44 )
{
T_2 V_51 ;
V_51 = V_44 >> 8 ;
F_14 ( V_1 , 0x1a , & V_51 , 1 ) ;
V_51 = V_44 ;
F_14 ( V_1 , 0x1b , & V_51 , 1 ) ;
}
static void F_27 ( struct V_1 * V_1 , T_3 V_44 )
{
static const T_2 V_51 [ 2 ] = { 0x28 , 0x3c } ;
F_14 ( V_1 , 0xd1 , & V_51 [ V_44 ] , 1 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
F_16 ( V_1 , V_87 ) ;
}
static void F_29 ( struct V_1 * V_1 , T_3 V_44 )
{
T_1 V_88 ;
T_2 V_51 ;
V_51 = ( V_44 << 4 ) | 0x0f ;
F_14 ( V_1 , 0xaa , & V_51 , 1 ) ;
V_88 = 613 + 12 * V_44 ;
V_51 = V_88 >> 8 ;
F_14 ( V_1 , 0xc4 , & V_51 , 1 ) ;
V_51 = V_88 ;
F_14 ( V_1 , 0xc5 , & V_51 , 1 ) ;
V_88 = 1093 - 12 * V_44 ;
V_51 = V_88 >> 8 ;
F_14 ( V_1 , 0xc6 , & V_51 , 1 ) ;
V_51 = V_88 ;
F_14 ( V_1 , 0xc7 , & V_51 , 1 ) ;
V_88 = 342 + 9 * V_44 ;
V_51 = V_88 >> 8 ;
F_14 ( V_1 , 0xc8 , & V_51 , 1 ) ;
V_51 = V_88 ;
F_14 ( V_1 , 0xc9 , & V_51 , 1 ) ;
V_88 = 702 - 9 * V_44 ;
V_51 = V_88 >> 8 ;
F_14 ( V_1 , 0xca , & V_51 , 1 ) ;
V_51 = V_88 ;
F_14 ( V_1 , 0xcb , & V_51 , 1 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
static const T_2 V_51 [ 2 ] = { 0x00 , 0x00 } ;
F_14 ( V_1 , 0x16 , & V_51 [ 0 ] , 1 ) ;
F_14 ( V_1 , 0x18 , & V_51 [ 1 ] , 1 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
const T_2 ( * V_89 ) [ 4 ] ;
const T_2 * V_90 = NULL ;
const T_2 * V_91 = NULL ;
int V_92 ;
static const T_2 ( * V_93 [] ) [ 4 ] = {
V_94 ,
V_95 ,
V_96 ,
} ;
if ( V_22 -> V_27 & V_28 ) {
F_9 ( V_1 , 0x89 , 0xf0ff , 0xffff ) ;
F_9 ( V_1 , 0xa9 , 0x8348 , 0x000e ) ;
F_9 ( V_1 , 0xa9 , 0x0000 , 0x001a ) ;
}
if ( V_22 -> V_29 == V_30 ) {
F_9 ( V_1 , 0xa0 , 0xff , 0xbfec ) ;
F_9 ( V_1 , 0xa0 , 0xff , 0xbfed ) ;
F_9 ( V_1 , 0xa0 , 0xff , 0xbfee ) ;
F_9 ( V_1 , 0xa0 , 0xff , 0xbfef ) ;
V_22 -> V_97 = 46 ;
} else {
if ( V_1 -> V_59 . V_70 [ V_1 -> V_98 ] . V_99
== V_100 )
V_22 -> V_97 = 0 ;
else
V_22 -> V_97 = 32 ;
}
V_92 = V_1 -> V_59 . V_70 [ ( int ) V_1 -> V_98 ] . V_101 ;
switch ( V_22 -> V_57 ) {
case V_62 :
V_90 = V_102 ;
V_91 = V_103 ;
if ( V_92 )
V_89 = V_104 ;
else
V_89 = V_105 ;
break;
case V_66 :
V_90 = V_106 ;
V_91 = V_107 ;
if ( V_92 )
V_89 = V_108 ;
else
V_89 = V_109 ;
break;
case V_42 :
V_90 = V_110 ;
V_91 = V_111 ;
if ( V_92 )
V_89 = V_112 ;
else
V_89 = V_113 ;
break;
case V_63 :
V_90 = V_110 ;
V_91 = V_114 ;
switch ( V_92 ) {
case 1 :
V_89 = V_115 ;
break;
case 0 :
V_89 = V_116 ;
break;
default:
V_89 = V_117 ;
break;
}
break;
case V_64 :
V_90 = V_110 ;
V_91 = V_114 ;
if ( V_92 )
V_89 = V_118 ;
else
V_89 = V_119 ;
break;
case V_65 :
V_90 = V_110 ;
V_91 = V_114 ;
V_89 = V_93 [ V_92 ] ;
break;
case V_41 :
V_89 = V_92 == 1 ? V_120 : V_121 ;
break;
case V_40 :
V_90 = V_122 ;
V_91 = V_123 ;
if ( V_92 )
V_89 = V_124 ;
else
V_89 = V_125 ;
F_16 ( V_1 , V_89 ) ;
V_89 = V_126 ;
break;
case V_67 :
V_90 = V_127 ;
V_91 = V_128 ;
V_89 = V_129 ;
break;
default:
F_16 ( V_1 , V_130 ) ;
F_28 ( V_1 ) ;
F_16 ( V_1 , V_131 ) ;
if ( V_92 )
V_89 = V_132 ;
else
V_89 = V_133 ;
F_16 ( V_1 , V_89 ) ;
F_5 ( V_1 , 0x8c , 0x0000 , 3 ) ;
F_9 ( V_1 , 0xa0 ,
V_1 -> V_11 [ 2 ] & 1 ? 0 : 1 ,
0xb35c ) ;
F_11 ( 300 ) ;
V_89 = V_134 ;
break;
}
F_16 ( V_1 , V_89 ) ;
if ( V_90 && V_91 ) {
F_15 ( V_1 , V_90 , 17 , 0xb84a ) ;
F_15 ( V_1 , V_90 , 17 , 0xb85b ) ;
F_15 ( V_1 , V_90 , 17 , 0xb86c ) ;
F_15 ( V_1 , V_91 , 9 , 0xb82c ) ;
switch ( V_22 -> V_57 ) {
case V_67 :
case V_62 :
F_9 ( V_1 , 0x89 , 0x0400 , 0x1415 ) ;
break;
case V_63 :
F_9 ( V_1 , 0x89 , 0x058c , 0x0000 ) ;
break;
}
F_11 ( 100 ) ;
}
switch ( V_22 -> V_57 ) {
case V_41 :
F_9 ( V_1 , 0x87 , 0xffff , 0xffff ) ;
F_9 ( V_1 , 0x88 , 0xff00 , 0xf0f1 ) ;
F_9 ( V_1 , 0xa0 , 0x0000 , 0xbfff ) ;
break;
case V_58 :
F_16 ( V_1 , V_135 ) ;
F_30 ( V_1 ) ;
F_11 ( 80 ) ;
F_9 ( V_1 , 0x89 , 0xffff , 0xfdff ) ;
break;
}
return V_1 -> V_6 ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
switch ( V_22 -> V_57 ) {
case V_63 :
F_9 ( V_1 , 0x89 , 0x058c , 0x00ff ) ;
break;
case V_58 :
return;
default:
if ( ! ( V_22 -> V_27 & V_28 ) )
F_9 ( V_1 , 0x89 , 0xffff , 0xffff ) ;
break;
}
F_9 ( V_1 , 0xa0 , 0x01 , 0xb301 ) ;
F_9 ( V_1 , 0xa0 , 0x09 , 0xb003 ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( ! V_1 -> V_136 )
return;
if ( V_22 -> V_57 == V_63 )
F_9 ( V_1 , 0x89 , 0x058c , 0x00ff ) ;
else if ( ! ( V_22 -> V_27 & V_28 ) )
F_9 ( V_1 , 0x89 , 0xffff , 0xffff ) ;
if ( V_22 -> V_57 == V_58 ) {
F_9 ( V_1 , 0xa0 , 0x26 , 0xb300 ) ;
F_9 ( V_1 , 0xa0 , 0x04 , 0xb300 ) ;
F_9 ( V_1 , 0xa0 , 0x00 , 0xb300 ) ;
}
}
static void F_34 ( struct V_1 * V_1 ,
T_2 * V_51 ,
int V_4 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( V_51 [ 0 ] == 0xff && V_51 [ 1 ] == 0xd8 ) {
F_6 ( V_137 ,
L_24 , V_4 ) ;
F_35 ( V_1 , V_138 , NULL , 0 ) ;
V_51 += V_22 -> V_97 ;
V_4 -= V_22 -> V_97 ;
F_35 ( V_1 , V_139 , V_51 , V_4 ) ;
return;
}
if ( V_22 -> V_29 == V_30 ) {
int V_45 , V_140 ;
V_140 = V_1 -> V_141 ;
V_45 = V_1 -> V_142 ;
if ( V_4 > V_45 - V_140 )
V_4 = V_45 - V_140 ;
}
F_35 ( V_1 , V_143 , V_51 , V_4 ) ;
}
static int F_36 ( struct V_144 * V_145 )
{
struct V_1 * V_1 =
F_37 ( V_145 -> V_146 , struct V_1 , V_147 ) ;
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( ! V_1 -> V_148 && V_145 -> V_53 != V_149 )
return 0 ;
switch ( V_145 -> V_53 ) {
case V_150 :
F_19 ( V_1 , V_145 -> V_44 ) ;
break;
case V_151 :
F_20 ( V_1 , V_145 -> V_44 ) ;
break;
case V_152 :
F_21 ( V_1 , V_145 -> V_44 ) ;
break;
case V_153 :
F_22 ( V_1 , V_22 -> V_78 -> V_44 , V_22 -> V_79 -> V_44 ) ;
break;
case V_154 :
F_24 ( V_1 , V_145 -> V_44 ) ;
break;
case V_155 :
F_27 ( V_1 , V_145 -> V_44 ) ;
break;
case V_156 :
F_25 ( V_1 , V_145 -> V_44 ) ;
break;
case V_157 :
F_26 ( V_1 , V_145 -> V_44 ) ;
break;
case V_158 :
F_29 ( V_1 , V_145 -> V_44 ) ;
break;
case V_149 :
F_23 ( V_1 , V_145 -> V_44 ) ;
break;
}
return V_1 -> V_6 ;
}
static int F_38 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
struct V_159 * V_160 = & V_1 -> V_147 ;
bool V_161 = false ;
bool V_162 = false ;
bool V_163 = false ;
bool V_164 = false ;
bool V_165 = false ;
bool V_166 = false ;
bool V_167 = false ;
bool V_168 = false ;
bool V_169 = false ;
bool V_170 = false ;
switch ( V_22 -> V_57 ) {
case V_62 :
case V_42 :
case V_40 :
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_164 = true ;
break;
case V_41 :
V_164 = V_165 = true ;
break;
case V_67 :
V_164 = V_170 = true ;
break;
case V_58 :
V_161 = V_162 = V_163 = V_166 =
V_167 = V_168 = V_169 =
V_170 = true ;
break;
}
V_1 -> V_171 . V_147 = V_160 ;
F_39 ( V_160 , 8 ) ;
if ( V_161 )
F_40 ( V_160 , & V_172 ,
V_150 , 0 , 255 , 1 , 128 ) ;
if ( V_162 )
F_40 ( V_160 , & V_172 ,
V_151 , 0 , 255 , 1 , 127 ) ;
if ( V_163 )
F_40 ( V_160 , & V_172 ,
V_152 , 1 , 127 , 1 , 63 ) ;
if ( V_164 ) {
V_22 -> V_78 = F_40 ( V_160 , & V_172 ,
V_153 , 0 , 1 , 1 , 0 ) ;
V_22 -> V_79 = F_40 ( V_160 , & V_172 ,
V_173 , 0 , 1 , 1 , 0 ) ;
}
if ( V_170 )
F_40 ( V_160 , & V_172 ,
V_154 , - 1 , 2 , 1 , - 1 ) ;
if ( V_165 )
F_41 ( V_160 , & V_172 ,
V_149 ,
V_174 , 0 ,
V_175 ) ;
if ( V_168 )
F_40 ( V_160 , & V_172 ,
V_155 , 0 , 1 , 1 , 1 ) ;
if ( V_169 )
F_40 ( V_160 , & V_172 ,
V_156 , 0 , 78 , 1 , 0 ) ;
if ( V_167 )
F_40 ( V_160 , & V_172 ,
V_157 , 0 , 4095 , 1 , 450 ) ;
if ( V_166 )
F_40 ( V_160 , & V_172 ,
V_158 , 0 , 15 , 1 , 15 ) ;
if ( V_160 -> error ) {
F_4 ( L_25 ) ;
return V_160 -> error ;
}
if ( V_22 -> V_78 )
F_42 ( 2 , & V_22 -> V_78 ) ;
return 0 ;
}
static int F_43 ( struct V_176 * V_177 ,
const struct V_52 * V_53 )
{
return F_44 ( V_177 , V_53 , & V_178 , sizeof( struct V_22 ) ,
V_179 ) ;
}
