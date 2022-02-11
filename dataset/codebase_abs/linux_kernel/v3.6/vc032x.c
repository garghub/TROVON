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
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
struct V_60 * V_60 ;
int V_58 ;
static T_2 V_61 [ V_62 ] = {
[ V_63 ] = 64 ,
[ V_43 ] = 32 ,
[ V_64 ] = 32 ,
[ V_65 ] = 64 ,
[ V_66 ] = 128 ,
[ V_67 ] = 32 ,
[ V_42 ] = 64 ,
[ V_68 ] = 128 ,
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
return - V_69 ;
case V_63 :
F_7 ( V_21 , L_14 ) ;
break;
case V_43 :
F_7 ( V_21 , L_15 ) ;
V_22 -> V_29 = V_70 ;
break;
case V_64 :
F_7 ( V_21 , L_16 ) ;
break;
case V_65 :
F_7 ( V_21 , L_17 ) ;
break;
case V_66 :
F_7 ( V_21 , L_18 ) ;
break;
case V_67 :
F_7 ( V_21 , L_19 ) ;
break;
case V_42 :
F_7 ( V_21 , L_20 ) ;
break;
case V_68 :
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
V_60 = & V_1 -> V_60 ;
if ( V_22 -> V_29 == V_30 ) {
V_60 -> V_71 = V_72 ;
V_60 -> V_73 = F_14 ( V_72 ) ;
} else {
switch ( V_58 ) {
case V_68 :
V_60 -> V_71 = V_74 ;
V_60 -> V_73 = F_14 ( V_74 ) ;
break;
case V_64 :
V_60 -> V_71 = V_75 ;
V_60 -> V_73 = F_14 ( V_75 ) ;
break;
case V_66 :
V_60 -> V_71 = V_76 ;
V_60 -> V_73 = F_14 ( V_76 ) ;
break;
case V_42 :
V_60 -> V_71 = V_76 ;
V_60 -> V_73 = F_14 ( V_76 ) - 1 ;
break;
default:
V_60 -> V_71 = V_75 ;
V_60 -> V_73 = F_14 ( V_75 ) - 1 ;
break;
}
}
V_60 -> V_61 = V_61 [ V_22 -> V_58 ] ;
if ( V_22 -> V_58 == V_42 )
V_22 -> V_27 |= V_77 | V_78 ;
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
static void F_20 ( struct V_1 * V_1 , T_3 V_45 )
{
T_2 V_52 ;
V_52 = V_45 ;
if ( V_52 >= 0x80 )
V_52 &= 0x7f ;
else
V_52 = 0xff ^ V_52 ;
F_15 ( V_1 , 0x98 , & V_52 , 1 ) ;
}
static void F_21 ( struct V_1 * V_1 , T_2 V_45 )
{
F_15 ( V_1 , 0x99 , & V_45 , 1 ) ;
}
static void F_22 ( struct V_1 * V_1 , T_2 V_45 )
{
T_2 V_52 ;
V_52 = V_45 - ( V_45 >> 3 ) - 1 ;
F_15 ( V_1 , 0x94 , & V_52 , 1 ) ;
F_15 ( V_1 , 0x95 , & V_45 , 1 ) ;
}
static void F_23 ( struct V_1 * V_1 , bool V_79 , bool V_80 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_52 [ 2 ] ;
if ( V_22 -> V_27 & V_77 )
V_79 = ! V_79 ;
if ( V_22 -> V_27 & V_78 )
V_80 = ! V_80 ;
switch ( V_22 -> V_58 ) {
case V_64 :
case V_65 :
case V_66 :
V_52 [ 0 ] = V_52 [ 1 ] = 0 ;
F_15 ( V_1 , 0xf0 , V_52 , 2 ) ;
V_52 [ 0 ] = V_22 -> V_58 == V_64 ? 0x03 : 0x01 ;
V_52 [ 1 ] = 0x02 * V_79
| 0x01 * V_80 ;
F_15 ( V_1 , 0x20 , V_52 , 2 ) ;
break;
case V_67 :
case V_42 :
V_52 [ 0 ] = V_22 -> V_58 == V_67 ? 0x01 : 0x07 ;
V_52 [ 0 ] |= V_81 * V_79
| V_82 * V_80 ;
F_15 ( V_1 , V_83 , V_52 , 1 ) ;
break;
case V_68 :
V_52 [ 0 ] = 0 ;
F_15 ( V_1 , 0x03 , V_52 , 1 ) ;
V_52 [ 0 ] = 0x80 * V_79
| 0x40 * V_80
| 0x06 ;
F_15 ( V_1 , 0x1e , V_52 , 1 ) ;
break;
}
}
static void F_24 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
static const T_2 ( * V_84 [ 3 ] ) [ 4 ] =
{ V_85 , V_86 , V_87 } ;
if ( V_22 -> V_58 != V_67 )
return;
F_17 ( V_1 , V_84 [ V_45 ] ) ;
}
static void F_25 ( struct V_1 * V_1 , T_3 V_45 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
T_2 V_52 ;
switch ( V_22 -> V_58 ) {
case V_68 :
V_52 = 0 ;
F_15 ( V_1 , 0x03 , & V_52 , 1 ) ;
if ( V_45 < 0 )
V_52 = 0x6a ;
else
V_52 = 0xb5 + V_45 * 3 ;
F_15 ( V_1 , 0x61 , & V_52 , 1 ) ;
break;
case V_59 :
if ( V_45 < 0 )
V_52 = 0x7e ;
else
V_52 = 0x60 + V_45 * 0x0f ;
F_15 ( V_1 , 0x59 , & V_52 , 1 ) ;
break;
}
}
static void F_26 ( struct V_1 * V_1 , T_2 V_45 )
{
F_15 ( V_1 , 0x15 , & V_45 , 1 ) ;
}
static void F_27 ( struct V_1 * V_1 , T_3 V_45 )
{
T_2 V_52 ;
V_52 = V_45 >> 8 ;
F_15 ( V_1 , 0x1a , & V_52 , 1 ) ;
V_52 = V_45 ;
F_15 ( V_1 , 0x1b , & V_52 , 1 ) ;
}
static void F_28 ( struct V_1 * V_1 , T_3 V_45 )
{
static const T_2 V_52 [ 2 ] = { 0x28 , 0x3c } ;
F_15 ( V_1 , 0xd1 , & V_52 [ V_45 ] , 1 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_17 ( V_1 , V_88 ) ;
}
static void F_30 ( struct V_1 * V_1 , T_3 V_45 )
{
T_1 V_89 ;
T_2 V_52 ;
V_52 = ( V_45 << 4 ) | 0x0f ;
F_15 ( V_1 , 0xaa , & V_52 , 1 ) ;
V_89 = 613 + 12 * V_45 ;
V_52 = V_89 >> 8 ;
F_15 ( V_1 , 0xc4 , & V_52 , 1 ) ;
V_52 = V_89 ;
F_15 ( V_1 , 0xc5 , & V_52 , 1 ) ;
V_89 = 1093 - 12 * V_45 ;
V_52 = V_89 >> 8 ;
F_15 ( V_1 , 0xc6 , & V_52 , 1 ) ;
V_52 = V_89 ;
F_15 ( V_1 , 0xc7 , & V_52 , 1 ) ;
V_89 = 342 + 9 * V_45 ;
V_52 = V_89 >> 8 ;
F_15 ( V_1 , 0xc8 , & V_52 , 1 ) ;
V_52 = V_89 ;
F_15 ( V_1 , 0xc9 , & V_52 , 1 ) ;
V_89 = 702 - 9 * V_45 ;
V_52 = V_89 >> 8 ;
F_15 ( V_1 , 0xca , & V_52 , 1 ) ;
V_52 = V_89 ;
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
const T_2 ( * V_90 ) [ 4 ] ;
const T_2 * V_91 = NULL ;
const T_2 * V_92 = NULL ;
int V_93 ;
static const T_2 ( * V_94 [] ) [ 4 ] = {
V_95 ,
V_96 ,
V_97 ,
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
V_22 -> V_98 = 46 ;
} else {
if ( V_1 -> V_60 . V_71 [ V_1 -> V_99 ] . V_100
== V_101 )
V_22 -> V_98 = 0 ;
else
V_22 -> V_98 = 32 ;
}
V_93 = V_1 -> V_60 . V_71 [ ( int ) V_1 -> V_99 ] . V_102 ;
switch ( V_22 -> V_58 ) {
case V_63 :
V_91 = V_103 ;
V_92 = V_104 ;
if ( V_93 )
V_90 = V_105 ;
else
V_90 = V_106 ;
break;
case V_67 :
V_91 = V_107 ;
V_92 = V_108 ;
if ( V_93 )
V_90 = V_109 ;
else
V_90 = V_110 ;
break;
case V_43 :
V_91 = V_111 ;
V_92 = V_112 ;
if ( V_93 )
V_90 = V_113 ;
else
V_90 = V_114 ;
break;
case V_64 :
V_91 = V_111 ;
V_92 = V_115 ;
switch ( V_93 ) {
case 1 :
V_90 = V_116 ;
break;
case 0 :
V_90 = V_117 ;
break;
default:
V_90 = V_118 ;
break;
}
break;
case V_65 :
V_91 = V_111 ;
V_92 = V_115 ;
if ( V_93 )
V_90 = V_119 ;
else
V_90 = V_120 ;
break;
case V_66 :
V_91 = V_111 ;
V_92 = V_115 ;
V_90 = V_94 [ V_93 ] ;
break;
case V_42 :
V_90 = V_93 == 1 ? V_121 : V_122 ;
break;
case V_41 :
V_91 = V_123 ;
V_92 = V_124 ;
if ( V_93 )
V_90 = V_125 ;
else
V_90 = V_126 ;
F_17 ( V_1 , V_90 ) ;
V_90 = V_127 ;
break;
case V_68 :
V_91 = V_128 ;
V_92 = V_129 ;
V_90 = V_130 ;
break;
default:
F_17 ( V_1 , V_131 ) ;
F_29 ( V_1 ) ;
F_17 ( V_1 , V_132 ) ;
if ( V_93 )
V_90 = V_133 ;
else
V_90 = V_134 ;
F_17 ( V_1 , V_90 ) ;
F_5 ( V_1 , 0x8c , 0x0000 , 3 ) ;
F_10 ( V_1 , 0xa0 ,
V_1 -> V_11 [ 2 ] & 1 ? 0 : 1 ,
0xb35c ) ;
F_12 ( 300 ) ;
V_90 = V_135 ;
break;
}
F_17 ( V_1 , V_90 ) ;
if ( V_91 && V_92 ) {
F_16 ( V_1 , V_91 , 17 , 0xb84a ) ;
F_16 ( V_1 , V_91 , 17 , 0xb85b ) ;
F_16 ( V_1 , V_91 , 17 , 0xb86c ) ;
F_16 ( V_1 , V_92 , 9 , 0xb82c ) ;
switch ( V_22 -> V_58 ) {
case V_68 :
case V_63 :
F_10 ( V_1 , 0x89 , 0x0400 , 0x1415 ) ;
break;
case V_64 :
F_10 ( V_1 , 0x89 , 0x058c , 0x0000 ) ;
break;
}
F_12 ( 100 ) ;
}
switch ( V_22 -> V_58 ) {
case V_42 :
F_10 ( V_1 , 0x87 , 0xffff , 0xffff ) ;
F_10 ( V_1 , 0x88 , 0xff00 , 0xf0f1 ) ;
F_10 ( V_1 , 0xa0 , 0x0000 , 0xbfff ) ;
break;
case V_59 :
F_17 ( V_1 , V_136 ) ;
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
case V_64 :
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
if ( ! V_1 -> V_137 )
return;
if ( V_22 -> V_58 == V_64 )
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
F_7 ( V_138 ,
L_24 , V_4 ) ;
F_36 ( V_1 , V_139 , NULL , 0 ) ;
V_52 += V_22 -> V_98 ;
V_4 -= V_22 -> V_98 ;
F_36 ( V_1 , V_140 , V_52 , V_4 ) ;
return;
}
if ( V_22 -> V_29 == V_30 ) {
int V_46 , V_141 ;
V_141 = V_1 -> V_142 ;
V_46 = V_1 -> V_143 ;
if ( V_4 > V_46 - V_141 )
V_4 = V_46 - V_141 ;
}
F_36 ( V_1 , V_144 , V_52 , V_4 ) ;
}
static int F_37 ( struct V_145 * V_146 )
{
struct V_1 * V_1 =
F_38 ( V_146 -> V_147 , struct V_1 , V_148 ) ;
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
V_1 -> V_6 = 0 ;
if ( ! V_1 -> V_149 && V_146 -> V_54 != V_150 )
return 0 ;
switch ( V_146 -> V_54 ) {
case V_151 :
F_20 ( V_1 , V_146 -> V_45 ) ;
break;
case V_152 :
F_21 ( V_1 , V_146 -> V_45 ) ;
break;
case V_153 :
F_22 ( V_1 , V_146 -> V_45 ) ;
break;
case V_154 :
F_23 ( V_1 , V_22 -> V_79 -> V_45 , V_22 -> V_80 -> V_45 ) ;
break;
case V_155 :
F_25 ( V_1 , V_146 -> V_45 ) ;
break;
case V_156 :
F_28 ( V_1 , V_146 -> V_45 ) ;
break;
case V_157 :
F_26 ( V_1 , V_146 -> V_45 ) ;
break;
case V_158 :
F_27 ( V_1 , V_146 -> V_45 ) ;
break;
case V_159 :
F_30 ( V_1 , V_146 -> V_45 ) ;
break;
case V_150 :
F_24 ( V_1 , V_146 -> V_45 ) ;
break;
}
return V_1 -> V_6 ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = (struct V_22 * ) V_1 ;
struct V_160 * V_161 = & V_1 -> V_148 ;
bool V_162 = false ;
bool V_163 = false ;
bool V_164 = false ;
bool V_165 = false ;
bool V_166 = false ;
bool V_167 = false ;
bool V_168 = false ;
bool V_169 = false ;
bool V_170 = false ;
bool V_171 = false ;
switch ( V_22 -> V_58 ) {
case V_63 :
case V_43 :
case V_41 :
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_165 = true ;
break;
case V_42 :
V_165 = V_166 = true ;
break;
case V_68 :
V_165 = V_171 = true ;
break;
case V_59 :
V_162 = V_163 = V_164 = V_167 =
V_168 = V_169 = V_170 =
V_171 = true ;
break;
}
V_1 -> V_172 . V_148 = V_161 ;
F_40 ( V_161 , 8 ) ;
if ( V_162 )
F_41 ( V_161 , & V_173 ,
V_151 , 0 , 255 , 1 , 128 ) ;
if ( V_163 )
F_41 ( V_161 , & V_173 ,
V_152 , 0 , 255 , 1 , 127 ) ;
if ( V_164 )
F_41 ( V_161 , & V_173 ,
V_153 , 1 , 127 , 1 , 63 ) ;
if ( V_165 ) {
V_22 -> V_79 = F_41 ( V_161 , & V_173 ,
V_154 , 0 , 1 , 1 , 0 ) ;
V_22 -> V_80 = F_41 ( V_161 , & V_173 ,
V_174 , 0 , 1 , 1 , 0 ) ;
}
if ( V_171 )
F_41 ( V_161 , & V_173 ,
V_155 , - 1 , 2 , 1 , - 1 ) ;
if ( V_166 )
F_42 ( V_161 , & V_173 ,
V_150 ,
V_175 , 0 ,
V_176 ) ;
if ( V_169 )
F_41 ( V_161 , & V_173 ,
V_156 , 0 , 1 , 1 , 1 ) ;
if ( V_170 )
F_41 ( V_161 , & V_173 ,
V_157 , 0 , 78 , 1 , 0 ) ;
if ( V_168 )
F_41 ( V_161 , & V_173 ,
V_158 , 0 , 4095 , 1 , 450 ) ;
if ( V_167 )
F_41 ( V_161 , & V_173 ,
V_159 , 0 , 15 , 1 , 15 ) ;
if ( V_161 -> error ) {
F_4 ( L_25 ) ;
return V_161 -> error ;
}
if ( V_22 -> V_79 )
F_43 ( 2 , & V_22 -> V_79 ) ;
return 0 ;
}
static int F_44 ( struct V_177 * V_178 ,
const struct V_53 * V_54 )
{
return F_45 ( V_178 , V_54 , & V_179 , sizeof( struct V_22 ) ,
V_180 ) ;
}
