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
#ifdef F_6
if ( V_1 -> V_6 < 0 )
return;
if ( V_4 == 1 )
F_7 ( V_12 , L_2 , V_2 , V_3 ,
V_1 -> V_11 [ 0 ] ) ;
else
F_7 ( V_12 , L_3 ,
V_2 , V_3 ,
V_1 -> V_11 [ 0 ] ,
V_1 -> V_11 [ 1 ] ,
V_1 -> V_11 [ 2 ] ) ;
#endif
}
static void F_8 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_13 ,
T_1 V_3 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_2 ( V_1 -> V_7 ,
F_9 ( V_1 -> V_7 , 0 ) ,
V_2 ,
V_14 | V_9 | V_10 ,
V_13 , V_3 , NULL , 0 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_4 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_10 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_13 ,
T_1 V_3 )
{
#ifdef F_6
if ( V_1 -> V_6 < 0 )
return;
F_7 ( V_15 , L_5 , V_2 , V_13 , V_3 ) ;
#endif
F_8 ( V_1 , V_2 , V_13 , V_3 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 ,
T_1 V_16 )
{
T_2 V_17 , V_18 , V_19 ;
int V_20 = 50 ;
F_5 ( V_1 , 0xa1 , 0xb33f , 1 ) ;
if ( ! ( V_1 -> V_11 [ 0 ] & 0x02 ) ) {
F_4 ( L_6 , V_1 -> V_11 [ 0 ] ) ;
return 0 ;
}
F_10 ( V_1 , 0xa0 , V_16 , 0xb33a ) ;
F_10 ( V_1 , 0xa0 , 0x02 , 0xb339 ) ;
do {
F_5 ( V_1 , 0xa1 , 0xb33b , 1 ) ;
if ( V_1 -> V_11 [ 0 ] == 0x00 )
break;
F_12 ( 40 ) ;
} while ( -- V_20 >= 0 );
F_5 ( V_1 , 0xa1 , 0xb33e , 1 ) ;
V_17 = V_1 -> V_11 [ 0 ] ;
F_5 ( V_1 , 0xa1 , 0xb33d , 1 ) ;
V_18 = V_1 -> V_11 [ 0 ] ;
F_5 ( V_1 , 0xa1 , 0xb33c , 1 ) ;
V_19 = V_1 -> V_11 [ 0 ] ;
if ( V_19 != 0 && V_18 != 0 && V_17 != 0 )
F_7 ( V_21 , L_7 ,
V_19 , V_18 , V_17 ) ;
F_5 ( V_1 , 0xa1 , 0xb334 , 1 ) ;
if ( V_1 -> V_11 [ 0 ] == 0x02 )
return ( V_19 << 8 ) + V_18 ;
return V_19 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
int V_23 , V_24 ;
T_1 V_13 ;
const struct V_25 * V_26 ;
if ( V_22 -> V_27 & V_28 ) {
F_10 ( V_1 , 0xa0 , 0x01 , 0xb301 ) ;
F_10 ( V_1 , 0x89 , 0xf0ff , 0xffff ) ;
}
F_5 ( V_1 , 0xa1 , 0xbfcf , 1 ) ;
F_7 ( V_21 , L_8 ,
V_22 -> V_29 == V_30 ? 1 : 3 , V_1 -> V_11 [ 0 ] ) ;
if ( V_22 -> V_29 == V_30 ) {
V_26 = V_31 ;
V_24 = F_14 ( V_31 ) ;
} else {
V_26 = V_32 ;
V_24 = F_14 ( V_32 ) ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
F_10 ( V_1 , 0xa0 , 0x02 , 0xb334 ) ;
F_10 ( V_1 , 0xa0 , V_26 -> V_33 , 0xb300 ) ;
F_10 ( V_1 , 0xa0 , V_26 -> V_34 , 0xb300 ) ;
F_10 ( V_1 , 0xa0 , 0x01 , 0xb308 ) ;
F_10 ( V_1 , 0xa0 , 0x0c , 0xb309 ) ;
F_10 ( V_1 , 0xa0 , V_26 -> V_35 , 0xb335 ) ;
F_10 ( V_1 , 0xa0 , V_26 -> V_36 , 0xb301 ) ;
V_13 = F_11 ( V_1 , V_26 -> V_37 ) ;
if ( V_13 == 0 && V_26 -> V_37 == 0x82 )
V_13 = F_11 ( V_1 , 0x83 ) ;
if ( V_13 != 0 ) {
F_7 ( V_38 | V_21 , L_9 ,
V_13 , V_23 ) ;
if ( V_13 == V_26 -> V_39 )
return V_26 -> V_40 ;
switch ( V_13 ) {
case 0x3130 :
return V_41 ;
case 0x7673 :
return V_42 ;
case 0x8243 :
return V_43 ;
}
}
V_26 ++ ;
}
return - 1 ;
}
static void F_15 ( struct V_1 * V_1 ,
T_2 V_44 , const T_2 * V_45 ,
T_2 V_46 )
{
int V_20 ;
#ifdef F_6
if ( V_1 -> V_6 < 0 )
return;
if ( V_46 == 1 )
F_7 ( V_15 , L_10 , V_44 , * V_45 ) ;
else
F_7 ( V_15 , L_11 , V_44 , * V_45 , V_45 [ 1 ] ) ;
#endif
F_1 ( V_1 , 0xa1 , 0xb33f , 1 ) ;
F_8 ( V_1 , 0xa0 , V_46 , 0xb334 ) ;
F_8 ( V_1 , 0xa0 , V_44 , 0xb33a ) ;
F_8 ( V_1 , 0xa0 , V_45 [ 0 ] , 0xb336 ) ;
if ( V_46 > 1 )
F_8 ( V_1 , 0xa0 , V_45 [ 1 ] , 0xb337 ) ;
F_8 ( V_1 , 0xa0 , 0x01 , 0xb339 ) ;
V_20 = 4 ;
do {
F_1 ( V_1 , 0xa1 , 0xb33b , 1 ) ;
if ( V_1 -> V_11 [ 0 ] == 0 )
break;
F_12 ( 20 ) ;
} while ( -- V_20 > 0 );
if ( V_20 <= 0 )
F_4 ( L_12 ) ;
}
static void F_16 ( struct V_1 * V_1 ,
const T_2 * V_47 , T_2 V_48 , T_1 V_49 )
{
int V_50 ;
T_1 V_51 = V_49 ;
for ( V_50 = 0 ; V_50 < V_48 ; V_50 ++ )
F_10 ( V_1 , 0xa0 , V_47 [ V_50 ] , V_51 ++ ) ;
}
static void F_17 ( struct V_1 * V_1 ,
const T_2 V_52 [] [ 4 ] )
{
int V_23 = 0 ;
for (; ; ) {
switch ( V_52 [ V_23 ] [ 3 ] ) {
default:
return;
case 0xcc :
F_10 ( V_1 , 0xa0 , V_52 [ V_23 ] [ 2 ] ,
( V_52 [ V_23 ] [ 0 ] ) << 8 | V_52 [ V_23 ] [ 1 ] ) ;
break;
case 0xaa :
F_15 ( V_1 , V_52 [ V_23 ] [ 1 ] , & V_52 [ V_23 ] [ 2 ] , 1 ) ;
break;
case 0xbb :
F_15 ( V_1 , V_52 [ V_23 ] [ 0 ] , & V_52 [ V_23 ] [ 1 ] , 2 ) ;
break;
case 0xdd :
F_12 ( V_52 [ V_23 ] [ 1 ] * 256 + V_52 [ V_23 ] [ 2 ] + 10 ) ;
break;
}
V_23 ++ ;
}
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_53 * V_54 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_29 = V_54 -> V_55 >> 8 ;
V_22 -> V_27 = V_54 -> V_55 & 0xff ;
if ( V_54 -> V_56 == 0x046d &&
( V_54 -> V_57 == 0x0892 || V_54 -> V_57 == 0x0896 ) )
V_22 -> V_58 = V_59 ;
V_22 -> V_60 = V_61 ;
V_22 -> V_62 = V_63 ;
V_22 -> V_64 = V_65 ;
V_22 -> V_66 = V_67 ;
V_22 -> V_68 = V_69 ;
V_22 -> V_70 = V_71 ;
V_22 -> V_72 = V_73 ;
V_22 -> V_74 = V_75 ;
V_22 -> V_76 = V_77 ;
V_22 -> V_78 = V_79 ;
V_22 -> V_80 = V_81 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
struct V_82 * V_82 ;
int V_58 ;
static T_2 V_83 [ V_84 ] = {
[ V_85 ] = 64 ,
[ V_43 ] = 32 ,
[ V_86 ] = 32 ,
[ V_87 ] = 64 ,
[ V_88 ] = 128 ,
[ V_89 ] = 32 ,
[ V_42 ] = 64 ,
[ V_90 ] = 128 ,
[ V_41 ] = 128 ,
[ V_59 ] = 128 ,
} ;
if ( V_22 -> V_58 != V_59 )
V_58 = F_13 ( V_1 ) ;
else
V_58 = V_22 -> V_58 ;
switch ( V_58 ) {
case - 1 :
F_4 ( L_13 ) ;
return - V_91 ;
case V_85 :
F_7 ( V_21 , L_14 ) ;
break;
case V_43 :
F_7 ( V_21 , L_15 ) ;
V_22 -> V_29 = V_92 ;
break;
case V_86 :
F_7 ( V_21 , L_16 ) ;
break;
case V_87 :
F_7 ( V_21 , L_17 ) ;
break;
case V_88 :
F_7 ( V_21 , L_18 ) ;
break;
case V_89 :
F_7 ( V_21 , L_19 ) ;
break;
case V_42 :
F_7 ( V_21 , L_20 ) ;
break;
case V_90 :
F_7 ( V_21 , L_21 ) ;
break;
case V_41 :
F_7 ( V_21 , L_22 ) ;
break;
case V_59 :
F_7 ( V_21 , L_23 ) ;
break;
}
V_22 -> V_58 = V_58 ;
V_82 = & V_1 -> V_82 ;
if ( V_22 -> V_29 == V_30 ) {
V_82 -> V_93 = V_94 ;
V_82 -> V_95 = F_14 ( V_94 ) ;
} else {
switch ( V_58 ) {
case V_90 :
V_82 -> V_93 = V_96 ;
V_82 -> V_95 = F_14 ( V_96 ) ;
break;
case V_86 :
V_82 -> V_93 = V_97 ;
V_82 -> V_95 = F_14 ( V_97 ) ;
break;
case V_88 :
V_82 -> V_93 = V_98 ;
V_82 -> V_95 = F_14 ( V_98 ) ;
break;
case V_42 :
V_82 -> V_93 = V_98 ;
V_82 -> V_95 = F_14 ( V_98 ) - 1 ;
break;
default:
V_82 -> V_93 = V_97 ;
V_82 -> V_95 = F_14 ( V_97 ) - 1 ;
break;
}
}
V_82 -> V_83 = V_83 [ V_22 -> V_58 ] ;
V_1 -> V_99 = V_99 [ V_22 -> V_58 ] ;
if ( V_22 -> V_58 == V_42 )
V_22 -> V_27 |= V_100 | V_101 ;
if ( V_22 -> V_29 == V_30 ) {
F_5 ( V_1 , 0x8a , 0 , 3 ) ;
F_10 ( V_1 , 0x87 , 0x00 , 0x0f0f ) ;
F_5 ( V_1 , 0x8b , 0 , 3 ) ;
F_10 ( V_1 , 0x88 , 0x00 , 0x0202 ) ;
if ( V_22 -> V_58 == V_59 ) {
F_5 ( V_1 , 0xa1 , 0xb300 , 1 ) ;
if ( V_1 -> V_11 [ 0 ] != 0 ) {
F_10 ( V_1 , 0xa0 , 0x26 , 0xb300 ) ;
F_10 ( V_1 , 0xa0 , 0x04 , 0xb300 ) ;
}
F_10 ( V_1 , 0xa0 , 0x00 , 0xb300 ) ;
}
}
return V_1 -> V_6 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_52 ;
if ( V_1 -> V_99 & ( 1 << V_102 ) )
return;
V_52 = V_22 -> V_60 ;
if ( V_52 >= 0x80 )
V_52 &= 0x7f ;
else
V_52 = 0xff ^ V_52 ;
F_15 ( V_1 , 0x98 , & V_52 , 1 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( V_1 -> V_99 & ( 1 << V_103 ) )
return;
F_15 ( V_1 , 0x99 , & V_22 -> V_62 , 1 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_52 ;
if ( V_1 -> V_99 & ( 1 << V_104 ) )
return;
V_52 = V_22 -> V_64 - ( V_22 -> V_64 >> 3 ) - 1 ;
F_15 ( V_1 , 0x94 , & V_52 , 1 ) ;
F_15 ( V_1 , 0x95 , & V_22 -> V_64 , 1 ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_52 [ 2 ] , V_66 , V_68 ;
V_66 = V_22 -> V_66 ;
if ( V_22 -> V_27 & V_100 )
V_66 = ! V_66 ;
V_68 = V_22 -> V_68 ;
if ( V_22 -> V_27 & V_101 )
V_68 = ! V_68 ;
switch ( V_22 -> V_58 ) {
case V_86 :
case V_87 :
case V_88 :
V_52 [ 0 ] = V_52 [ 1 ] = 0 ;
F_15 ( V_1 , 0xf0 , V_52 , 2 ) ;
V_52 [ 0 ] = V_22 -> V_58 == V_86 ? 0x03 : 0x01 ;
V_52 [ 1 ] = 0x02 * V_66
| 0x01 * V_68 ;
F_15 ( V_1 , 0x20 , V_52 , 2 ) ;
break;
case V_89 :
case V_42 :
V_52 [ 0 ] = V_22 -> V_58 == V_89 ? 0x01 : 0x07 ;
V_52 [ 0 ] |= V_105 * V_66
| V_106 * V_68 ;
F_15 ( V_1 , V_107 , V_52 , 1 ) ;
break;
case V_90 :
V_52 [ 0 ] = 0 ;
F_15 ( V_1 , 0x03 , V_52 , 1 ) ;
V_52 [ 0 ] = 0x80 * V_66
| 0x40 * V_68
| 0x06 ;
F_15 ( V_1 , 0x1e , V_52 , 1 ) ;
break;
}
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
static const T_2 ( * V_108 [ 3 ] ) [ 4 ] =
{ V_109 , V_110 , V_111 } ;
if ( V_22 -> V_58 != V_89 )
return;
F_17 ( V_1 , V_108 [ V_22 -> V_70 ] ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_52 ;
switch ( V_22 -> V_58 ) {
case V_90 :
V_52 = 0 ;
F_15 ( V_1 , 0x03 , & V_52 , 1 ) ;
if ( V_22 -> V_72 < 0 )
V_52 = 0x6a ;
else
V_52 = 0xb5 + V_22 -> V_72 * 3 ;
F_15 ( V_1 , 0x61 , & V_52 , 1 ) ;
break;
case V_59 :
if ( V_22 -> V_72 < 0 )
V_52 = 0x7e ;
else
V_52 = 0x60 + V_22 -> V_72 * 0x0f ;
F_15 ( V_1 , 0x59 , & V_52 , 1 ) ;
break;
}
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( V_1 -> V_99 & ( 1 << V_112 ) )
return;
F_15 ( V_1 , 0x15 , & V_22 -> V_74 , 1 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_52 ;
if ( V_1 -> V_99 & ( 1 << V_113 ) )
return;
V_52 = V_22 -> V_76 >> 8 ;
F_15 ( V_1 , 0x1a , & V_52 , 1 ) ;
V_52 = V_22 -> V_76 ;
F_15 ( V_1 , 0x1b , & V_52 , 1 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
static const T_2 V_52 [ 2 ] = { 0x28 , 0x3c } ;
if ( V_1 -> V_99 & ( 1 << V_114 ) )
return;
F_15 ( V_1 , 0xd1 , & V_52 [ V_22 -> V_78 ] , 1 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_17 ( V_1 , V_115 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_1 V_116 ;
T_2 V_52 ;
V_52 = ( V_22 -> V_80 << 4 ) | 0x0f ;
F_15 ( V_1 , 0xaa , & V_52 , 1 ) ;
V_116 = 613 + 12 * V_22 -> V_80 ;
V_52 = V_116 >> 8 ;
F_15 ( V_1 , 0xc4 , & V_52 , 1 ) ;
V_52 = V_116 ;
F_15 ( V_1 , 0xc5 , & V_52 , 1 ) ;
V_116 = 1093 - 12 * V_22 -> V_80 ;
V_52 = V_116 >> 8 ;
F_15 ( V_1 , 0xc6 , & V_52 , 1 ) ;
V_52 = V_116 ;
F_15 ( V_1 , 0xc7 , & V_52 , 1 ) ;
V_116 = 342 + 9 * V_22 -> V_80 ;
V_52 = V_116 >> 8 ;
F_15 ( V_1 , 0xc8 , & V_52 , 1 ) ;
V_52 = V_116 ;
F_15 ( V_1 , 0xc9 , & V_52 , 1 ) ;
V_116 = 702 - 9 * V_22 -> V_80 ;
V_52 = V_116 >> 8 ;
F_15 ( V_1 , 0xca , & V_52 , 1 ) ;
V_52 = V_116 ;
F_15 ( V_1 , 0xcb , & V_52 , 1 ) ;
}
static void F_31 ( struct V_1 * V_1 )
{
static const T_2 V_52 [ 2 ] = { 0x00 , 0x00 } ;
F_15 ( V_1 , 0x16 , & V_52 [ 0 ] , 1 ) ;
F_15 ( V_1 , 0x18 , & V_52 [ 1 ] , 1 ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
const T_2 ( * V_117 ) [ 4 ] ;
const T_2 * V_118 = NULL ;
const T_2 * V_119 = NULL ;
int V_120 ;
static const T_2 ( * V_121 [] ) [ 4 ] = {
V_122 ,
V_123 ,
V_124 ,
} ;
if ( V_22 -> V_27 & V_28 ) {
F_10 ( V_1 , 0x89 , 0xf0ff , 0xffff ) ;
F_10 ( V_1 , 0xa9 , 0x8348 , 0x000e ) ;
F_10 ( V_1 , 0xa9 , 0x0000 , 0x001a ) ;
}
if ( V_22 -> V_29 == V_30 ) {
F_10 ( V_1 , 0xa0 , 0xff , 0xbfec ) ;
F_10 ( V_1 , 0xa0 , 0xff , 0xbfed ) ;
F_10 ( V_1 , 0xa0 , 0xff , 0xbfee ) ;
F_10 ( V_1 , 0xa0 , 0xff , 0xbfef ) ;
V_22 -> V_125 = 46 ;
} else {
if ( V_1 -> V_82 . V_93 [ V_1 -> V_126 ] . V_127
== V_128 )
V_22 -> V_125 = 0 ;
else
V_22 -> V_125 = 32 ;
}
V_120 = V_1 -> V_82 . V_93 [ ( int ) V_1 -> V_126 ] . V_129 ;
switch ( V_22 -> V_58 ) {
case V_85 :
V_118 = V_130 ;
V_119 = V_131 ;
if ( V_120 )
V_117 = V_132 ;
else
V_117 = V_133 ;
break;
case V_89 :
V_118 = V_134 ;
V_119 = V_135 ;
if ( V_120 )
V_117 = V_136 ;
else
V_117 = V_137 ;
break;
case V_43 :
V_118 = V_138 ;
V_119 = V_139 ;
if ( V_120 )
V_117 = V_140 ;
else
V_117 = V_141 ;
break;
case V_86 :
V_118 = V_138 ;
V_119 = V_142 ;
switch ( V_120 ) {
case 1 :
V_117 = V_143 ;
break;
case 0 :
V_117 = V_144 ;
break;
default:
V_117 = V_145 ;
break;
}
break;
case V_87 :
V_118 = V_138 ;
V_119 = V_142 ;
if ( V_120 )
V_117 = V_146 ;
else
V_117 = V_147 ;
break;
case V_88 :
V_118 = V_138 ;
V_119 = V_142 ;
V_117 = V_121 [ V_120 ] ;
break;
case V_42 :
V_117 = V_120 == 1 ? V_148 : V_149 ;
break;
case V_41 :
V_118 = V_150 ;
V_119 = V_151 ;
if ( V_120 )
V_117 = V_152 ;
else
V_117 = V_153 ;
F_17 ( V_1 , V_117 ) ;
V_117 = V_154 ;
break;
case V_90 :
V_118 = V_155 ;
V_119 = V_156 ;
V_117 = V_157 ;
break;
default:
F_17 ( V_1 , V_158 ) ;
F_29 ( V_1 ) ;
F_30 ( V_1 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
F_25 ( V_1 ) ;
F_28 ( V_1 ) ;
F_27 ( V_1 ) ;
F_26 ( V_1 ) ;
F_17 ( V_1 , V_159 ) ;
if ( V_120 )
V_117 = V_160 ;
else
V_117 = V_161 ;
F_17 ( V_1 , V_117 ) ;
F_5 ( V_1 , 0x8c , 0x0000 , 3 ) ;
F_10 ( V_1 , 0xa0 ,
V_1 -> V_11 [ 2 ] & 1 ? 0 : 1 ,
0xb35c ) ;
F_12 ( 300 ) ;
V_117 = V_162 ;
break;
}
F_17 ( V_1 , V_117 ) ;
if ( V_118 && V_119 ) {
F_16 ( V_1 , V_118 , 17 , 0xb84a ) ;
F_16 ( V_1 , V_118 , 17 , 0xb85b ) ;
F_16 ( V_1 , V_118 , 17 , 0xb86c ) ;
F_16 ( V_1 , V_119 , 9 , 0xb82c ) ;
switch ( V_22 -> V_58 ) {
case V_90 :
case V_85 :
F_10 ( V_1 , 0x89 , 0x0400 , 0x1415 ) ;
break;
case V_86 :
F_10 ( V_1 , 0x89 , 0x058c , 0x0000 ) ;
break;
}
F_12 ( 100 ) ;
F_23 ( V_1 ) ;
F_24 ( V_1 ) ;
}
switch ( V_22 -> V_58 ) {
case V_42 :
F_10 ( V_1 , 0x87 , 0xffff , 0xffff ) ;
F_10 ( V_1 , 0x88 , 0xff00 , 0xf0f1 ) ;
F_10 ( V_1 , 0xa0 , 0x0000 , 0xbfff ) ;
break;
case V_59 :
F_17 ( V_1 , V_163 ) ;
F_31 ( V_1 ) ;
F_12 ( 80 ) ;
F_10 ( V_1 , 0x89 , 0xffff , 0xfdff ) ;
break;
}
return V_1 -> V_6 ;
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
switch ( V_22 -> V_58 ) {
case V_86 :
F_10 ( V_1 , 0x89 , 0x058c , 0x00ff ) ;
break;
case V_59 :
return;
default:
if ( ! ( V_22 -> V_27 & V_28 ) )
F_10 ( V_1 , 0x89 , 0xffff , 0xffff ) ;
break;
}
F_10 ( V_1 , 0xa0 , 0x01 , 0xb301 ) ;
F_10 ( V_1 , 0xa0 , 0x09 , 0xb003 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( ! V_1 -> V_164 )
return;
if ( V_22 -> V_58 == V_86 )
F_10 ( V_1 , 0x89 , 0x058c , 0x00ff ) ;
else if ( ! ( V_22 -> V_27 & V_28 ) )
F_10 ( V_1 , 0x89 , 0xffff , 0xffff ) ;
if ( V_22 -> V_58 == V_59 ) {
F_10 ( V_1 , 0xa0 , 0x26 , 0xb300 ) ;
F_10 ( V_1 , 0xa0 , 0x04 , 0xb300 ) ;
F_10 ( V_1 , 0xa0 , 0x00 , 0xb300 ) ;
}
}
static void F_35 ( struct V_1 * V_1 ,
T_2 * V_52 ,
int V_4 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
if ( V_52 [ 0 ] == 0xff && V_52 [ 1 ] == 0xd8 ) {
F_7 ( V_165 ,
L_24 , V_4 ) ;
F_36 ( V_1 , V_166 , NULL , 0 ) ;
V_52 += V_22 -> V_125 ;
V_4 -= V_22 -> V_125 ;
F_36 ( V_1 , V_167 , V_52 , V_4 ) ;
return;
}
if ( V_22 -> V_29 == V_30 ) {
int V_46 , V_168 ;
V_168 = V_1 -> V_169 ;
V_46 = V_1 -> V_170 ;
if ( V_4 > V_46 - V_168 )
V_4 = V_46 - V_168 ;
}
F_36 ( V_1 , V_171 , V_52 , V_4 ) ;
}
static int F_37 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_60 = V_45 ;
if ( V_1 -> V_172 )
F_20 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_38 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_60 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_62 = V_45 ;
if ( V_1 -> V_172 )
F_21 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_40 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_62 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_64 = V_45 ;
if ( V_1 -> V_172 )
F_22 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_42 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_64 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_66 = V_45 ;
if ( V_1 -> V_172 )
F_23 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_44 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_66 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_68 = V_45 ;
if ( V_1 -> V_172 )
F_23 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_46 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_68 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_70 = V_45 ;
if ( V_1 -> V_172 )
F_24 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_48 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_70 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_72 = V_45 ;
if ( V_1 -> V_172 )
F_25 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_50 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_72 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_74 = V_45 ;
if ( V_1 -> V_172 )
F_26 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_52 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_74 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_76 = V_45 ;
if ( V_1 -> V_172 )
F_27 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_54 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_76 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_78 = V_45 ;
if ( V_1 -> V_172 )
F_28 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_56 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_78 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_22 -> V_80 = V_45 ;
if ( V_1 -> V_172 )
F_30 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_58 ( struct V_1 * V_1 , T_3 * V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
* V_45 = V_22 -> V_80 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_1 ,
struct V_173 * V_174 )
{
static const char * V_175 [ 3 ] = { L_25 , L_26 , L_27 } ;
switch ( V_174 -> V_54 ) {
case V_176 :
if ( V_174 -> V_3 >= F_14 ( V_175 ) )
break;
strcpy ( ( char * ) V_174 -> V_177 , V_175 [ V_174 -> V_3 ] ) ;
return 0 ;
}
return - V_91 ;
}
static int F_60 ( struct V_178 * V_179 ,
const struct V_53 * V_54 )
{
return F_61 ( V_179 , V_54 , & V_180 , sizeof( struct V_22 ) ,
V_181 ) ;
}
