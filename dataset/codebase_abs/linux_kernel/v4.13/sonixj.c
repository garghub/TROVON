static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 , int V_3 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
if ( V_3 > V_6 ) {
F_2 ( L_1 ) ;
return;
}
V_4 = F_3 ( V_1 -> V_7 ,
F_4 ( V_1 -> V_7 , 0 ) ,
0 ,
V_8 | V_9 | V_10 ,
V_2 , 0 ,
V_1 -> V_11 , V_3 ,
500 ) ;
F_5 ( V_12 , L_2 , V_2 , V_1 -> V_11 [ 0 ] ) ;
if ( V_4 < 0 ) {
F_6 ( L_3 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_2 V_13 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_5 ( V_14 , L_4 , V_2 , V_13 ) ;
V_1 -> V_11 [ 0 ] = V_13 ;
V_4 = F_3 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
V_2 ,
0 ,
V_1 -> V_11 , 1 ,
500 ) ;
if ( V_4 < 0 ) {
F_6 ( L_5 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_9 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_16 ,
int V_3 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_5 ( V_14 , L_6 ,
V_2 , V_16 [ 0 ] , V_16 [ 1 ] ) ;
if ( V_3 > V_6 ) {
F_2 ( L_7 ) ;
return;
}
memcpy ( V_1 -> V_11 , V_16 , V_3 ) ;
V_4 = F_3 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
V_2 , 0 ,
V_1 -> V_11 , V_3 ,
500 ) ;
if ( V_4 < 0 ) {
F_6 ( L_8 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_10 ( struct V_1 * V_1 , T_2 V_17 , T_2 V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_5 ( V_14 , L_9 , V_17 , V_18 ) ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_22 :
case V_23 :
V_1 -> V_11 [ 0 ] = 0x80 | ( 2 << 4 ) ;
break;
default:
V_1 -> V_11 [ 0 ] = 0x81 | ( 2 << 4 ) ;
break;
}
V_1 -> V_11 [ 1 ] = V_19 -> V_24 ;
V_1 -> V_11 [ 2 ] = V_17 ;
V_1 -> V_11 [ 3 ] = V_18 ;
V_1 -> V_11 [ 4 ] = 0 ;
V_1 -> V_11 [ 5 ] = 0 ;
V_1 -> V_11 [ 6 ] = 0 ;
V_1 -> V_11 [ 7 ] = 0x10 ;
V_4 = F_3 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x08 ,
0 ,
V_1 -> V_11 , 8 ,
500 ) ;
F_11 ( 2 ) ;
if ( V_4 < 0 ) {
F_6 ( L_10 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_12 ( struct V_1 * V_1 ,
const T_2 * V_16 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_5 ( V_14 , L_11 ,
V_16 [ 2 ] , V_16 [ 3 ] ) ;
memcpy ( V_1 -> V_11 , V_16 , 8 ) ;
V_4 = F_3 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x08 , 0 ,
V_1 -> V_11 , 8 ,
500 ) ;
F_11 ( 2 ) ;
if ( V_4 < 0 ) {
F_6 ( L_12 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_13 ( struct V_1 * V_1 , T_2 V_17 , int V_3 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_2 V_25 [ 8 ] ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_22 :
case V_23 :
V_25 [ 0 ] = 0x80 | 0x10 ;
break;
default:
V_25 [ 0 ] = 0x81 | 0x10 ;
break;
}
V_25 [ 1 ] = V_19 -> V_24 ;
V_25 [ 2 ] = V_17 ;
V_25 [ 3 ] = 0 ;
V_25 [ 4 ] = 0 ;
V_25 [ 5 ] = 0 ;
V_25 [ 6 ] = 0 ;
V_25 [ 7 ] = 0x10 ;
F_12 ( V_1 , V_25 ) ;
F_11 ( 2 ) ;
V_25 [ 0 ] = ( V_25 [ 0 ] & 0x81 ) | ( V_3 << 4 ) | 0x02 ;
V_25 [ 2 ] = 0 ;
F_12 ( V_1 , V_25 ) ;
F_11 ( 2 ) ;
F_1 ( V_1 , 0x0a , 5 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
F_10 ( V_1 , 0x02 , 0 ) ;
F_11 ( 10 ) ;
F_7 ( V_1 , 0x02 , 0x66 ) ;
F_11 ( 10 ) ;
F_13 ( V_1 , 0 , 5 ) ;
if ( V_1 -> V_11 [ 0 ] == 0x02
&& V_1 -> V_11 [ 1 ] == 0x09
&& V_1 -> V_11 [ 2 ] == 0x01 ) {
F_5 ( V_26 , L_13 ) ;
return;
}
F_15 ( L_14 ,
V_1 -> V_11 [ 0 ] , V_1 -> V_11 [ 1 ] ,
V_1 -> V_11 [ 2 ] ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 , V_28 ;
T_1 V_18 = 0 ;
static const T_2 V_29 [] [ 4 ] [ 8 ] = {
{
{ 0xb0 , 0x5d , 0x07 , 0x00 , 0x02 , 0x00 , 0x00 , 0x10 } ,
{ 0x90 , 0x5d , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ,
{ 0xa2 , 0x5d , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ,
{ 0xb0 , 0x5d , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 }
} ,
{
{ 0xb0 , 0x5c , 0x01 , 0x00 , 0x04 , 0x00 , 0x00 , 0x10 } ,
{ 0x90 , 0x5c , 0x36 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ,
{ 0xa2 , 0x5c , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ,
{}
} ,
} ;
for ( V_27 = 0 ; V_27 < F_17 ( V_29 ) ; V_27 ++ ) {
F_7 ( V_1 , 0x17 , 0x62 ) ;
F_7 ( V_1 , 0x01 , 0x08 ) ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ )
F_12 ( V_1 , V_29 [ V_27 ] [ V_28 ] ) ;
F_11 ( 2 ) ;
F_1 ( V_1 , 0x0a , 5 ) ;
V_18 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
if ( V_29 [ V_27 ] [ 3 ] [ 0 ] != 0 )
F_12 ( V_1 , V_29 [ V_27 ] [ 3 ] ) ;
F_7 ( V_1 , 0x01 , 0x29 ) ;
F_7 ( V_1 , 0x17 , 0x42 ) ;
if ( V_18 != 0xffff )
break;
}
if ( V_1 -> V_5 < 0 )
return;
switch ( V_18 ) {
case 0x8221 :
F_5 ( V_26 , L_15 ) ;
V_19 -> V_20 = V_30 ;
break;
case 0x823a :
F_5 ( V_26 , L_16 ) ;
V_19 -> V_20 = V_31 ;
break;
case 0x8243 :
F_5 ( V_26 , L_17 ) ;
break;
default:
F_5 ( V_26 , L_18 , V_18 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_1 V_18 ;
F_7 ( V_1 , 0x17 , 0x62 ) ;
F_7 ( V_1 , 0x01 , 0x08 ) ;
V_19 -> V_24 = 0x21 ;
F_13 ( V_1 , 0x0a , 2 ) ;
V_18 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
F_7 ( V_1 , 0x01 , 0x29 ) ;
F_7 ( V_1 , 0x17 , 0x42 ) ;
if ( V_1 -> V_5 < 0 )
return;
if ( V_18 == 0x7628 ) {
V_19 -> V_20 = V_32 ;
V_1 -> V_33 . V_34 =
V_35 | V_36 ;
F_5 ( V_26 , L_19 ) ;
return;
}
F_5 ( V_26 , L_20 , V_18 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_1 V_18 ;
F_7 ( V_1 , 0x17 , 0x62 ) ;
F_7 ( V_1 , 0x01 , 0x08 ) ;
V_19 -> V_24 = 0x21 ;
F_13 ( V_1 , 0x0a , 2 ) ;
V_18 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
F_7 ( V_1 , 0x01 , 0x29 ) ;
F_7 ( V_1 , 0x17 , 0x42 ) ;
if ( ( V_18 & 0xff00 ) == 0x7600 ) {
F_5 ( V_26 , L_20 , V_18 ) ;
return;
}
F_7 ( V_1 , 0x17 , 0x62 ) ;
F_7 ( V_1 , 0x01 , 0x08 ) ;
V_19 -> V_24 = 0x6e ;
F_13 ( V_1 , 0x00 , 2 ) ;
V_18 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
F_7 ( V_1 , 0x01 , 0x29 ) ;
F_7 ( V_1 , 0x17 , 0x42 ) ;
if ( V_1 -> V_5 < 0 )
return;
if ( V_18 == 0x1030 ) {
F_5 ( V_26 , L_21 ) ;
V_19 -> V_20 = V_37 ;
return;
}
F_6 ( L_22 , V_18 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_1 V_18 ;
F_7 ( V_1 , 0x17 , 0x62 ) ;
F_7 ( V_1 , 0x01 , 0x08 ) ;
F_7 ( V_1 , 0x02 , 0x22 ) ;
V_19 -> V_24 = 0x21 ;
F_13 ( V_1 , 0x00 , 1 ) ;
V_18 = V_1 -> V_11 [ 4 ] ;
F_7 ( V_1 , 0x01 , 0x29 ) ;
F_7 ( V_1 , 0x17 , 0x42 ) ;
if ( V_18 == 0x99 ) {
F_5 ( V_26 , L_23 ) ;
V_19 -> V_20 = V_23 ;
return;
}
F_7 ( V_1 , 0x17 , 0x62 ) ;
F_7 ( V_1 , 0x01 , 0x0a ) ;
V_19 -> V_24 = 0x6e ;
F_13 ( V_1 , 0x00 , 2 ) ;
V_18 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
F_7 ( V_1 , 0x01 , 0x29 ) ;
F_7 ( V_1 , 0x17 , 0x42 ) ;
if ( V_1 -> V_5 < 0 )
return;
if ( V_18 == 0x2030 ) {
F_5 ( V_26 , L_24 ) ;
} else {
F_6 ( L_25 , V_18 ) ;
}
}
static int F_21 ( struct V_1 * V_1 ,
const struct V_38 * V_39 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
struct V_33 * V_33 ;
V_19 -> V_40 = V_39 -> V_41 >> 16 ;
V_19 -> V_20 = V_39 -> V_41 >> 8 ;
V_19 -> V_42 = V_39 -> V_41 ;
V_33 = & V_1 -> V_33 ;
if ( V_19 -> V_20 == V_21 ) {
V_33 -> V_43 = V_44 ;
V_33 -> V_45 = F_17 ( V_44 ) ;
} else {
V_33 -> V_43 = V_46 ;
V_33 -> V_45 = F_17 ( V_46 ) ;
}
V_33 -> V_47 = 24 ;
V_19 -> V_48 = - 1 ;
V_19 -> V_49 = V_50 ;
F_22 ( & V_19 -> V_51 , V_52 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
const T_2 * V_53 ;
T_2 V_54 [] = { 0x29 , 0x70 } ;
T_2 V_55 ;
F_7 ( V_1 , 0xf1 , 0x01 ) ;
F_1 ( V_1 , 0x00 , 1 ) ;
F_7 ( V_1 , 0xf1 , 0x00 ) ;
F_1 ( V_1 , 0x00 , 1 ) ;
V_55 = V_1 -> V_11 [ 0 ] ;
if ( V_1 -> V_5 < 0 )
return V_1 -> V_5 ;
F_5 ( V_26 , L_26 , V_55 ) ;
if ( V_1 -> V_56 )
V_54 [ 1 ] |= 0x04 ;
switch ( V_19 -> V_40 ) {
case V_57 :
case V_58 :
if ( V_55 != 0x11 )
return - V_59 ;
break;
default:
if ( V_55 != 0x12 )
return - V_59 ;
}
switch ( V_19 -> V_20 ) {
case V_60 :
F_16 ( V_1 ) ;
break;
case V_61 :
F_18 ( V_1 ) ;
break;
case V_62 :
F_19 ( V_1 ) ;
break;
case V_63 :
F_20 ( V_1 ) ;
break;
}
switch ( V_19 -> V_40 ) {
case V_57 :
F_7 ( V_1 , 0x02 , V_54 [ 1 ] ) ;
break;
default:
F_9 ( V_1 , 0x01 , V_54 , 2 ) ;
break;
}
F_7 ( V_1 , 0xf1 , 0x00 ) ;
V_53 = V_64 [ V_19 -> V_20 ] ;
V_19 -> V_24 = V_53 [ 9 ] ;
return V_1 -> V_5 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
struct V_65 * V_66 = & V_1 -> V_67 ;
V_1 -> V_68 . V_67 = V_66 ;
F_25 ( V_66 , 14 ) ;
V_19 -> V_69 = F_26 ( V_66 , & V_70 ,
V_71 , 0 , 255 , 1 , 128 ) ;
#define F_27 127
V_19 -> V_72 = F_26 ( V_66 , & V_70 ,
V_73 , 0 , F_27 , 1 , 20 ) ;
#define F_28 25
V_19 -> V_74 = F_26 ( V_66 , & V_70 ,
V_75 , 0 , 40 , 1 , F_28 ) ;
V_19 -> V_76 = F_26 ( V_66 , & V_70 ,
V_77 , 24 , 40 , 1 , 32 ) ;
V_19 -> V_78 = F_26 ( V_66 , & V_70 ,
V_79 , 24 , 40 , 1 , 32 ) ;
#define F_29 20
V_19 -> gamma = F_26 ( V_66 , & V_70 ,
V_80 , 0 , 40 , 1 , F_29 ) ;
if ( V_19 -> V_20 == V_22 )
V_19 -> V_81 = F_26 ( V_66 , & V_70 ,
V_82 , 0 , 255 , 1 , 16 ) ;
else
V_19 -> V_81 = F_26 ( V_66 , & V_70 ,
V_82 , 0 , 255 , 1 , 90 ) ;
if ( V_19 -> V_42 & V_83 )
V_19 -> V_84 = F_26 ( V_66 , & V_70 ,
V_85 , 0 , 1 , 1 , 0 ) ;
if ( V_19 -> V_20 == V_63 ) {
V_1 -> V_86 = F_26 ( V_66 , & V_70 ,
V_87 , 500 , 1500 , 1 , 1024 ) ;
V_1 -> V_88 = F_26 ( V_66 , & V_70 ,
V_89 , 4 , 49 , 1 , 15 ) ;
V_19 -> V_90 = F_26 ( V_66 , & V_70 ,
V_91 , 0 , 1 , 1 , 0 ) ;
}
if ( V_19 -> V_20 != V_21 && V_19 -> V_20 != V_92 &&
V_19 -> V_20 != V_37 && V_19 -> V_20 != V_32 &&
V_19 -> V_20 != V_93 )
V_1 -> V_94 = F_26 ( V_66 , & V_70 ,
V_95 , 0 , 1 , 1 , 1 ) ;
if ( V_19 -> V_20 == V_96 || V_19 -> V_20 == V_61 ||
V_19 -> V_20 == V_62 || V_19 -> V_20 == V_63 )
V_19 -> V_97 = F_26 ( V_66 , & V_70 ,
V_98 , 0 , 1 , 1 , 0 ) ;
if ( V_19 -> V_20 == V_61 || V_19 -> V_20 == V_62 ||
V_19 -> V_20 == V_92 )
V_19 -> V_99 = F_30 ( V_66 , & V_70 ,
V_100 ,
V_101 , 0 ,
V_102 ) ;
if ( V_66 -> error ) {
F_6 ( L_27 ) ;
return V_66 -> error ;
}
F_31 ( 2 , & V_19 -> V_76 ) ;
if ( V_19 -> V_20 == V_63 ) {
F_31 ( 2 , & V_19 -> V_97 ) ;
F_32 ( 3 , & V_1 -> V_94 , 0 , false ) ;
}
return 0 ;
}
static T_3 F_33 ( struct V_1 * V_1 ,
T_3 V_103 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
switch ( V_19 -> V_20 ) {
case V_23 : {
int V_104 , V_105 ;
V_104 = 19 + V_103 * 25 / 256 ;
F_10 ( V_1 , 0x68 , V_104 ) ;
V_104 -= 12 ;
V_105 = V_104 * V_104 * 4 ;
F_10 ( V_1 , 0x03 , V_105 >> 8 ) ;
F_10 ( V_1 , 0x04 , V_105 ) ;
break;
}
case V_96 : {
T_2 V_106 [] =
{ 0xc1 , 0x11 , 0x25 , 0x00 , 0x00 , 0x00 , 0x00 , 0x16 } ;
V_106 [ 3 ] = V_103 >> 16 ;
V_106 [ 4 ] = V_103 >> 8 ;
V_106 [ 5 ] = V_103 ;
F_12 ( V_1 , V_106 ) ;
break;
}
case V_60 :
case V_30 : {
T_2 V_107 [] =
{ 0xb1 , 0x5d , 0x09 , 0x00 , 0x00 , 0x00 , 0x00 , 0x16 } ;
static const T_2 V_108 [] =
{ 0xb1 , 0x5d , 0x07 , 0x00 , 0x03 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_109 [] =
{ 0xb1 , 0x5d , 0x07 , 0x00 , 0x02 , 0x00 , 0x00 , 0x10 } ;
if ( V_103 > 0x0635 )
V_103 = 0x0635 ;
else if ( V_103 < 0x0001 )
V_103 = 0x0001 ;
V_107 [ 3 ] = V_103 >> 8 ;
V_107 [ 4 ] = V_103 ;
F_12 ( V_1 , V_107 ) ;
F_12 ( V_1 , V_108 ) ;
F_12 ( V_1 , V_109 ) ;
break;
}
case V_110 : {
T_2 V_111 [] =
{ 0xa1 , 0x21 , 0x0f , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
T_2 V_112 [] =
{ 0xa1 , 0x21 , 0x10 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_113 [] =
{ 0xa1 , 0x21 , 0x00 , 0x10 , 0x00 , 0x00 , 0x00 , 0x1d } ;
if ( V_103 > 0x1fff )
V_103 = 0x1fff ;
else if ( V_103 < 0x0001 )
V_103 = 0x0001 ;
V_111 [ 3 ] = ( V_103 & 0x03fc ) >> 2 ;
F_12 ( V_1 , V_111 ) ;
V_112 [ 3 ] = ( ( V_103 & 0x1c00 ) >> 10 )
| ( ( V_103 & 0x0003 ) << 4 ) ;
F_12 ( V_1 , V_112 ) ;
F_12 ( V_1 , V_113 ) ;
F_5 ( V_114 , L_28 ,
( ( V_112 [ 3 ] & 0x07 ) << 10 )
| ( V_111 [ 3 ] << 2 )
| ( ( V_112 [ 3 ] & 0x30 ) >> 4 ) ) ;
break;
}
case V_31 : {
T_2 V_115 [] =
{ 0xb1 , 0x5c , 0x09 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
if ( V_103 > 0x0390 )
V_103 = 0x0390 ;
else if ( V_103 < 0x0060 )
V_103 = 0x0060 ;
V_115 [ 3 ] = V_103 >> 8 ;
V_115 [ 4 ] = V_103 ;
F_12 ( V_1 , V_115 ) ;
break;
}
case V_22 : {
T_2 V_116 [] =
{ 0xa0 , 0x34 , 0xe5 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
if ( V_103 > 0x03ff )
V_103 = 0x03ff ;
if ( V_103 < 0x0001 )
V_103 = 0x0001 ;
V_116 [ 3 ] = V_103 >> 2 ;
F_12 ( V_1 , V_116 ) ;
F_7 ( V_1 , 0x96 , V_103 >> 5 ) ;
F_5 ( V_114 , L_28 , V_116 [ 3 ] ) ;
break;
}
}
return V_103 ;
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
unsigned int V_103 ;
int V_69 = V_19 -> V_69 -> V_18 ;
T_2 V_117 ;
V_117 = ( V_69 - 0x80 ) >> 2 ;
switch ( V_19 -> V_20 ) {
case V_21 :
if ( V_117 > 0x1f )
V_117 = 0 ;
break;
case V_96 :
V_103 = V_69 << 12 ;
if ( V_103 > 0x002dc6c0 )
V_103 = 0x002dc6c0 ;
else if ( V_103 < 0x02a0 )
V_103 = 0x02a0 ;
V_19 -> V_86 = F_33 ( V_1 , V_103 ) ;
break;
case V_60 :
case V_110 :
V_103 = V_69 << 4 ;
V_19 -> V_86 = F_33 ( V_1 , V_103 ) ;
break;
case V_30 :
V_103 = V_69 << 2 ;
V_19 -> V_86 = F_33 ( V_1 , V_103 ) ;
break;
case V_23 :
V_103 = V_69 ;
V_19 -> V_86 = F_33 ( V_1 , V_103 ) ;
return;
case V_31 :
V_103 = V_69 << 2 ;
V_19 -> V_86 = F_33 ( V_1 , V_103 ) ;
return;
case V_22 :
V_103 = V_69 << 2 ;
V_19 -> V_86 = F_33 ( V_1 , V_103 ) ;
return;
}
F_7 ( V_1 , 0x96 , V_117 ) ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_2 V_117 ;
T_2 V_72 [ 6 ] ;
V_117 = V_19 -> V_72 -> V_18 * 37 / ( F_27 + 1 )
+ 37 ;
V_72 [ 0 ] = ( V_117 + 1 ) / 2 ;
V_72 [ 1 ] = 0 ;
V_72 [ 2 ] = V_117 ;
V_72 [ 3 ] = 0 ;
V_72 [ 4 ] = V_117 / 5 ;
V_72 [ 5 ] = 0 ;
F_9 ( V_1 , 0x84 , V_72 , sizeof V_72 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 , V_118 , V_119 ;
const T_4 * V_120 ;
T_2 V_121 [ 12 ] ;
static const T_4 V_122 [ 6 ] = {
- 24 , - 38 , 64 ,
62 , - 51 , - 9
} ;
static const T_4 V_123 [ 6 ] = {
- 20 , - 38 , 64 ,
60 , - 51 , - 9
} ;
V_119 = V_19 -> V_74 -> V_18 ;
if ( V_19 -> V_20 == V_30 )
V_120 = V_123 ;
else
V_120 = V_122 ;
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ ) {
V_118 = V_120 [ V_27 ] * V_119 / F_28 ;
V_121 [ V_27 * 2 ] = V_118 ;
V_121 [ V_27 * 2 + 1 ] = ( V_118 >> 8 ) & 0x0f ;
}
F_9 ( V_1 , 0x8a , V_121 , sizeof V_121 ) ;
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_63 ) {
T_2 V_124 [] =
{ 0xc1 , 0x6e , 0x16 , 0x00 , 0x40 , 0x00 , 0x00 , 0x10 } ;
V_124 [ 3 ] = V_19 -> V_76 -> V_18 * 2 ;
V_124 [ 5 ] = V_19 -> V_78 -> V_18 * 2 ;
F_12 ( V_1 , V_124 ) ;
return;
}
F_7 ( V_1 , 0x05 , V_19 -> V_76 -> V_18 ) ;
F_7 ( V_1 , 0x06 , V_19 -> V_78 -> V_18 ) ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 , V_18 ;
T_2 gamma [ 17 ] ;
const T_2 * V_125 ;
static const T_2 V_126 [ 17 ] = {
0x00 , 0x14 , 0x1c , 0x1c , 0x1c , 0x1c , 0x1b , 0x1a ,
0x18 , 0x13 , 0x10 , 0x0e , 0x08 , 0x07 , 0x04 , 0x02 , 0x00
} ;
switch ( V_19 -> V_20 ) {
case V_21 :
V_125 = V_127 ;
break;
case V_96 :
case V_30 :
case V_31 :
V_125 = V_128 ;
break;
case V_23 :
V_125 = V_129 ;
break;
case V_93 :
V_125 = V_130 ;
break;
default:
V_125 = V_131 ;
break;
}
V_18 = V_19 -> gamma -> V_18 ;
for ( V_27 = 0 ; V_27 < sizeof gamma ; V_27 ++ )
gamma [ V_27 ] = V_125 [ V_27 ]
+ V_126 [ V_27 ] * ( V_18 - F_29 ) / 32 ;
F_9 ( V_1 , 0x20 , gamma , sizeof gamma ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_63 ) {
T_2 V_132 [] =
{ 0xa1 , 0x6e , 0x1a , 0x00 , 0x40 , 0x00 , 0x00 , 0x10 } ;
V_132 [ 3 ] = V_1 -> V_86 -> V_18 >> 8 ;
F_12 ( V_1 , V_132 ) ;
F_11 ( 6 ) ;
V_132 [ 2 ] = 0x1b ;
V_132 [ 3 ] = V_1 -> V_86 -> V_18 ;
F_12 ( V_1 , V_132 ) ;
}
}
static void F_40 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
switch ( V_19 -> V_20 ) {
case V_61 :
case V_62 : {
T_2 V_133 ;
if ( V_19 -> V_20 == V_61 )
V_133 = 0xc0 ;
else
V_133 = 0xa0 ;
if ( V_1 -> V_94 -> V_18 )
V_133 |= 0x03 ;
F_10 ( & V_19 -> V_1 , 0x13 , V_133 ) ;
return;
}
}
if ( V_1 -> V_94 -> V_18 )
V_19 -> V_48 = V_134 ;
else
V_19 -> V_48 = - 1 ;
}
static void F_41 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_63 ) {
T_2 V_135 [] =
{ 0xa1 , 0x6e , 0x15 , 0x00 , 0x40 , 0x00 , 0x00 , 0x15 } ;
V_135 [ 3 ] = V_1 -> V_88 -> V_18 ;
F_12 ( V_1 , V_135 ) ;
}
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_2 V_136 ;
switch ( V_19 -> V_20 ) {
case V_96 :
V_136 = 0x18 ;
if ( V_19 -> V_97 -> V_18 )
V_136 |= 0x01 ;
F_10 ( V_1 , 0x01 , V_136 ) ;
break;
case V_61 :
V_136 = 0x02 ;
if ( ! V_19 -> V_97 -> V_18 )
V_136 |= 0x80 ;
F_10 ( V_1 , 0x75 , V_136 ) ;
break;
case V_62 :
V_136 = 0x06 ;
if ( V_19 -> V_97 -> V_18 )
V_136 |= 0x80 ;
F_10 ( V_1 , 0x75 , V_136 ) ;
break;
case V_63 :
V_136 = 0x0a ;
if ( V_19 -> V_90 -> V_18 )
V_136 |= 0x80 ;
if ( V_19 -> V_97 -> V_18 )
V_136 |= 0x40 ;
F_10 ( & V_19 -> V_1 , 0x1e , V_136 ) ;
break;
}
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_7 ( V_1 , 0x99 , V_19 -> V_81 -> V_18 ) ;
}
static void F_44 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
switch ( V_19 -> V_20 ) {
case V_21 :
F_7 ( V_1 , 0x02 ,
V_19 -> V_84 -> V_18 ? 0x64 : 0x60 ) ;
break;
case V_31 :
F_7 ( V_1 , 0x02 ,
V_19 -> V_84 -> V_18 ? 0x77 : 0x74 ) ;
break;
}
}
static void F_45 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_92 ) {
T_2 V_137 ;
V_137 = 0xdf ;
switch ( V_19 -> V_99 -> V_18 ) {
case 0 :
F_10 ( V_1 , 0x13 , V_137 | 0x20 ) ;
break;
case 1 :
F_10 ( V_1 , 0x13 , V_137 ) ;
F_10 ( V_1 , 0x3b , 0x0a ) ;
break;
case 2 :
F_10 ( V_1 , 0x13 , V_137 ) ;
F_10 ( V_1 , 0x3b , 0x02 ) ;
break;
}
} else {
T_2 V_138 = 0 , V_139 = 0 , V_140 = 0 ;
switch ( V_19 -> V_20 ) {
case V_61 :
V_138 = 0x08 ;
V_140 = 0x01 ;
break;
case V_62 :
V_138 = 0x11 ;
V_140 = 0x81 ;
break;
}
switch ( V_19 -> V_99 -> V_18 ) {
case 0 :
break;
case 1 :
V_138 |= 0x80 ;
V_139 = 0xac ;
V_140 |= 0x04 ;
break;
case 2 :
V_138 |= 0x80 ;
V_140 |= 0x04 ;
break;
}
F_10 ( V_1 , 0x2a , V_138 ) ;
F_10 ( V_1 , 0x2b , V_139 ) ;
F_10 ( V_1 , 0x2d , V_140 ) ;
}
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_47 ( V_19 -> V_141 , V_19 -> V_49 ) ;
#if V_6 < 64
#error "No room enough in usb_buf for quantization table"
#endif
memcpy ( V_1 -> V_11 , & V_19 -> V_141 [ V_142 ] , 64 ) ;
F_3 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x0100 , 0 ,
V_1 -> V_11 , 64 ,
500 ) ;
memcpy ( V_1 -> V_11 , & V_19 -> V_141 [ V_143 ] , 64 ) ;
F_3 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x0140 , 0 ,
V_1 -> V_11 , 64 ,
500 ) ;
V_19 -> V_144 ^= 0x40 ;
F_7 ( V_1 , 0x18 , V_19 -> V_144 ) ;
}
static void V_52 ( struct V_145 * V_51 )
{
struct V_19 * V_19 = F_48 ( V_51 , struct V_19 , V_51 ) ;
struct V_1 * V_1 = & V_19 -> V_1 ;
F_49 ( & V_1 -> V_146 ) ;
F_5 ( V_147 , L_29 , V_19 -> V_49 ) ;
V_1 -> V_5 = 0 ;
F_46 ( V_1 ) ;
F_50 ( & V_1 -> V_146 ) ;
}
static int F_51 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 ;
T_2 V_148 , V_149 ;
T_2 V_150 [ 2 ] ;
const T_2 * V_53 ;
const T_2 ( * V_151 ) [ 8 ] ;
const T_2 * V_152 ;
int V_25 ;
static const T_2 V_153 [] =
{ 0x00 , 0x40 , 0x20 , 0x00 , 0x00 , 0x00 } ;
static const T_2 V_154 [] =
{ 0x00 , 0x40 , 0x38 , 0x30 , 0x00 , 0x20 } ;
static const T_2 V_155 [] = { 0x60 , 0x00 , 0x00 } ;
static const T_2 V_156 [] = { 0x2d , 0x2d , 0x3a , 0x05 , 0x04 , 0x3f } ;
static const T_2 V_157 [] = { 0x28 , 0xd8 , 0x14 , 0xec } ;
static const T_2 V_158 [] =
{ 0x14 , 0xec , 0x0a , 0xf6 } ;
static const T_2 V_159 [] =
{ 0x1e , 0xe2 , 0x14 , 0xec } ;
static const T_2 V_160 [] = { 0x32 , 0xdd , 0x2d , 0xdd } ;
static const T_2 V_161 [] =
{ 0x32 , 0xce , 0x2d , 0xd3 } ;
static const T_2 V_162 [] =
{ 0x32 , 0xdd , 0x32 , 0xdd } ;
static const T_2 V_163 [] =
{ 0x14 , 0xe7 , 0x1e , 0xdd } ;
F_52 ( V_19 -> V_141 , V_1 -> V_164 . V_165 ,
V_1 -> V_164 . V_166 ,
0x21 ) ;
V_53 = V_64 [ V_19 -> V_20 ] ;
V_148 = V_53 [ 1 ] ;
if ( V_19 -> V_42 & V_167 )
V_148 ^= V_168 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
V_150 [ 0 ] = V_148 ;
V_150 [ 1 ] = V_53 [ 2 ] ;
if ( V_1 -> V_56 )
V_150 [ 1 ] |= 0x04 ;
F_9 ( V_1 , 0x01 , V_150 , 2 ) ;
F_9 ( V_1 , 0x08 , & V_53 [ 8 ] , 2 ) ;
F_9 ( V_1 , 0x17 , & V_53 [ 0x17 ] , 5 ) ;
switch ( V_19 -> V_20 ) {
case V_23 :
case V_92 :
case V_37 :
case V_63 :
case V_32 :
case V_93 :
V_152 = V_154 ;
break;
default:
V_152 = V_153 ;
break;
}
F_9 ( V_1 , 0x9a , V_152 , 6 ) ;
F_9 ( V_1 , 0xd4 , V_155 , sizeof V_155 ) ;
F_9 ( V_1 , 0x03 , & V_53 [ 3 ] , 0x0f ) ;
V_149 = V_53 [ 0x17 ] ;
switch ( V_19 -> V_20 ) {
case V_23 :
F_11 ( 50 ) ;
break;
case V_22 :
F_11 ( 10 ) ;
F_7 ( V_1 , 0x02 , 0x73 ) ;
V_149 |= V_169 ;
F_7 ( V_1 , 0x17 , V_149 ) ;
F_7 ( V_1 , 0x01 , 0x22 ) ;
F_11 ( 100 ) ;
V_148 = V_170 | V_168 ;
V_149 &= ~ V_171 ;
V_149 |= 0x04 ;
break;
}
V_148 |= V_172 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
V_149 |= V_169 ;
F_7 ( V_1 , 0x17 , V_149 ) ;
V_148 &= ~ V_173 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
V_148 &= ~ V_170 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
switch ( V_19 -> V_20 ) {
case V_96 :
F_14 ( V_1 ) ;
break;
case V_22 :
F_11 ( 10 ) ;
F_7 ( V_1 , 0x01 , V_148 ) ;
F_12 ( V_1 , V_174 [ 0 ] ) ;
F_12 ( V_1 , V_174 [ 1 ] ) ;
F_11 ( 15 ) ;
F_7 ( V_1 , 0x02 , 0x71 ) ;
F_11 ( 150 ) ;
break;
case V_93 :
F_11 ( 100 ) ;
F_7 ( V_1 , 0x02 , 0x62 ) ;
break;
}
F_53 ( V_1 , V_175 [ V_19 -> V_20 ] ) ;
F_7 ( V_1 , 0x15 , V_53 [ 0x15 ] ) ;
F_7 ( V_1 , 0x16 , V_53 [ 0x16 ] ) ;
F_7 ( V_1 , 0x12 , V_53 [ 0x12 ] ) ;
F_7 ( V_1 , 0x13 , V_53 [ 0x13 ] ) ;
F_7 ( V_1 , 0x18 , V_53 [ 0x18 ] ) ;
if ( V_19 -> V_20 == V_21 ) {
F_7 ( V_1 , 0xd2 , 0x3a ) ;
F_7 ( V_1 , 0xd3 , 0x30 ) ;
} else {
F_7 ( V_1 , 0xd2 , 0x6a ) ;
F_7 ( V_1 , 0xd3 , 0x50 ) ;
}
F_7 ( V_1 , 0xc6 , 0x00 ) ;
F_7 ( V_1 , 0xc7 , 0x00 ) ;
if ( V_19 -> V_20 == V_21 ) {
F_7 ( V_1 , 0xc8 , 0x2c ) ;
F_7 ( V_1 , 0xc9 , 0x24 ) ;
} else {
F_7 ( V_1 , 0xc8 , 0x50 ) ;
F_7 ( V_1 , 0xc9 , 0x3c ) ;
}
F_7 ( V_1 , 0x18 , V_53 [ 0x18 ] ) ;
switch ( V_19 -> V_20 ) {
case V_22 :
break;
default:
V_149 |= V_176 ;
break;
}
F_7 ( V_1 , 0x17 , V_149 ) ;
F_7 ( V_1 , 0x05 , 0x00 ) ;
F_7 ( V_1 , 0x07 , 0x00 ) ;
F_7 ( V_1 , 0x06 , 0x00 ) ;
F_7 ( V_1 , 0x14 , V_53 [ 0x14 ] ) ;
F_38 ( V_1 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_9 ( V_1 , 0x84 , V_177 , sizeof V_177 ) ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_92 :
case V_93 :
F_7 ( V_1 , 0x9a , 0x05 ) ;
break;
case V_23 :
case V_31 :
case V_30 :
F_7 ( V_1 , 0x9a , 0x07 ) ;
break;
case V_61 :
case V_62 :
F_7 ( V_1 , 0x9a , 0x0a ) ;
break;
case V_63 :
case V_32 :
F_7 ( V_1 , 0x9a , 0x06 ) ;
break;
default:
F_7 ( V_1 , 0x9a , 0x08 ) ;
break;
}
F_43 ( V_1 ) ;
F_9 ( V_1 , 0x84 , V_177 , sizeof V_177 ) ;
F_7 ( V_1 , 0x05 , 0x20 ) ;
F_7 ( V_1 , 0x07 , 0x20 ) ;
F_7 ( V_1 , 0x06 , 0x20 ) ;
V_151 = NULL ;
V_25 = V_1 -> V_33 . V_43 [ V_1 -> V_178 ] . V_179 ;
V_148 |= V_172 | V_180 ;
V_149 &= ~ V_171 ;
V_149 |= 0x02 ;
switch ( V_19 -> V_20 ) {
case V_21 :
V_151 = V_181 ;
break;
case V_23 :
V_151 = V_182 ;
break;
case V_96 :
case V_60 :
if ( ! V_25 )
V_148 &= ~ V_172 ;
V_149 &= ~ V_171 ;
V_149 |= 0x01 ;
break;
case V_30 :
V_151 = V_183 ;
break;
case V_110 :
if ( V_25 ) {
V_148 &= ~ V_172 ;
V_149 &= ~ V_171 ;
V_149 |= 0x01 ;
}
break;
case V_31 :
V_151 = V_184 ;
break;
case V_22 :
V_151 = V_185 ;
if ( ! V_25 ) {
V_149 &= ~ V_171 ;
V_149 |= 0x04 ;
} else {
V_148 &= ~ V_172 ;
V_149 &= ~ V_171 ;
V_149 |= 0x02 ;
}
break;
case V_61 :
V_151 = V_186 ;
break;
case V_62 :
V_151 = V_187 ;
V_149 &= ~ V_171 ;
V_149 |= 0x01 ;
break;
case V_92 :
V_151 = V_188 ;
break;
case V_37 :
V_151 = V_189 ;
break;
case V_63 :
V_151 = V_190 ;
break;
case V_32 :
V_151 = V_191 ;
break;
case V_93 :
V_151 = V_192 ;
break;
}
if ( V_151 != NULL ) {
F_53 ( V_1 , V_151 ) ;
}
F_9 ( V_1 , 0xc0 , V_156 , 6 ) ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_23 :
case V_32 :
F_9 ( V_1 , 0xca , V_158 , 4 ) ;
break;
case V_63 :
F_9 ( V_1 , 0xca , V_159 , 4 ) ;
break;
default:
F_9 ( V_1 , 0xca , V_157 , 4 ) ;
break;
}
switch ( V_19 -> V_20 ) {
case V_21 :
case V_61 :
case V_62 :
case V_92 :
case V_32 :
F_9 ( V_1 , 0xce , V_162 , 4 ) ;
break;
case V_23 :
F_9 ( V_1 , 0xce , V_161 , 4 ) ;
break;
case V_63 :
F_9 ( V_1 , 0xce , V_163 , 4 ) ;
break;
default:
F_9 ( V_1 , 0xce , V_160 , 4 ) ;
break;
}
V_19 -> V_144 = V_53 [ 0x18 ] | ( V_25 << 4 ) | 0x40 ;
F_7 ( V_1 , 0x18 , V_19 -> V_144 ) ;
F_46 ( V_1 ) ;
F_7 ( V_1 , 0x17 , V_149 ) ;
F_7 ( V_1 , 0x01 , V_148 ) ;
V_19 -> V_148 = V_148 ;
V_19 -> V_149 = V_149 ;
V_19 -> V_193 = V_19 -> V_47 = 0 ;
V_19 -> V_194 = V_19 -> V_195 = 0 ;
return V_1 -> V_5 ;
}
static void F_54 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
static const T_2 V_196 [] =
{ 0xa1 , 0x11 , 0x02 , 0x09 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_197 [] =
{ 0xb1 , 0x5d , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_198 [] =
{ 0xa1 , 0x21 , 0x76 , 0x20 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_199 [] =
{ 0xa1 , 0x21 , 0x12 , 0x80 , 0x00 , 0x00 , 0x00 , 0x10 } ;
T_2 V_148 ;
T_2 V_149 ;
V_148 = V_19 -> V_148 ;
V_149 = V_19 -> V_149 & ~ V_169 ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_23 :
case V_63 :
case V_93 :
V_148 |= V_200 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
V_148 &= ~ ( V_200 | V_180 ) ;
F_7 ( V_1 , 0x01 , V_148 ) ;
break;
case V_96 :
V_148 &= ~ V_180 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
F_12 ( V_1 , V_196 ) ;
break;
case V_60 :
case V_30 :
V_148 &= ~ V_180 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
F_12 ( V_1 , V_197 ) ;
break;
case V_31 :
case V_22 :
case V_37 :
V_148 &= ~ V_180 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
break;
case V_61 :
case V_62 :
V_148 &= ~ V_180 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
F_12 ( V_1 , V_198 ) ;
break;
case V_92 :
V_148 &= ~ V_180 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
break;
case V_32 :
F_12 ( V_1 , V_199 ) ;
break;
}
V_148 |= V_170 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
V_148 |= V_173 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
F_7 ( V_1 , 0x17 , V_149 ) ;
V_148 &= ~ V_172 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
V_148 |= V_200 ;
F_7 ( V_1 , 0x01 , V_148 ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_50 ( & V_1 -> V_146 ) ;
F_56 ( & V_19 -> V_51 ) ;
F_49 ( & V_1 -> V_146 ) ;
}
static void F_57 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_126 ;
int V_201 ;
T_2 V_202 = 130 ;
T_2 V_203 = 20 ;
if ( V_19 -> V_48 < 0 )
return;
if ( -- V_19 -> V_48 >= 0 )
return;
V_19 -> V_48 = V_134 ;
V_126 = F_58 ( & V_19 -> V_204 ) ;
F_5 ( V_114 , L_30 , V_126 ) ;
if ( V_19 -> V_20 == V_63 ) {
F_59 ( V_1 , V_126 , V_202 , V_203 ,
15 , 1024 ) ;
return;
}
if ( V_126 < V_202 - V_203 ||
V_126 > V_202 + V_203 ) {
switch ( V_19 -> V_20 ) {
case V_23 :
V_201 = V_19 -> V_86 ;
V_201 += ( V_202 - V_126 ) >> 6 ;
if ( V_201 < 0 )
V_201 = 0 ;
V_19 -> V_86 = F_33 ( V_1 ,
( unsigned int ) V_201 ) ;
break;
case V_96 :
V_201 = V_19 -> V_86 >> 8 ;
V_201 += ( V_202 - V_126 ) >> 4 ;
if ( V_201 < 0 )
V_201 = 0 ;
V_19 -> V_86 = F_33 ( V_1 ,
( unsigned int ) ( V_201 << 8 ) ) ;
break;
case V_22 :
case V_31 :
V_201 = V_19 -> V_86 ;
V_201 += ( V_202 - V_126 ) >> 2 ;
if ( V_201 < 0 )
V_201 = 0 ;
V_19 -> V_86 = F_33 ( V_1 ,
( unsigned int ) V_201 ) ;
F_37 ( V_1 ) ;
break;
default:
V_201 = V_19 -> V_86 ;
V_201 += ( V_202 - V_126 ) >> 6 ;
if ( V_201 < 0 )
V_201 = 0 ;
V_19 -> V_86 = F_33 ( V_1 ,
( unsigned int ) V_201 ) ;
F_37 ( V_1 ) ;
break;
}
}
}
static void F_60 ( struct V_19 * V_19 ,
T_2 * V_13 )
{
int V_204 ;
V_204 = ( V_13 [ 27 ] << 8 ) + V_13 [ 28 ]
+ ( V_13 [ 31 ] << 8 ) + V_13 [ 32 ]
+ ( V_13 [ 23 ] << 8 ) + V_13 [ 24 ]
+ ( V_13 [ 35 ] << 8 ) + V_13 [ 36 ]
+ ( V_13 [ 29 ] << 10 ) + ( V_13 [ 30 ] << 2 ) ;
V_204 >>= 10 ;
F_61 ( & V_19 -> V_204 , V_204 ) ;
}
static void F_62 ( struct V_1 * V_1 ,
T_2 * V_13 ,
int V_3 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 , V_205 ;
V_19 -> V_47 ++ ;
V_19 -> V_193 += V_3 ;
V_27 = V_19 -> V_195 ;
if ( V_27 != 0 ) {
V_19 -> V_195 = 0 ;
if ( V_27 < 0
&& V_13 [ 0 ] == 0xff
&& V_13 [ 1 ] == 0x00 )
goto V_206;
if ( V_13 [ 0 ] == 0xff && V_13 [ 1 ] == 0xff ) {
V_27 = 0 ;
goto V_206;
}
V_3 -= V_27 ;
if ( V_3 <= 0 )
return;
V_13 += V_27 ;
}
for ( V_27 = V_3 - 1 ; -- V_27 >= 0 ; ) {
if ( V_13 [ V_27 ] != 0xff ) {
V_27 -- ;
continue;
}
if ( V_13 [ V_27 + 1 ] == 0xff ) {
if ( V_27 + 2 >= V_3 || V_13 [ V_27 + 2 ] == 0x00 )
goto V_206;
}
}
if ( V_13 [ V_3 - 1 ] == 0xff )
V_19 -> V_195 = - 1 ;
if ( V_1 -> V_207 == V_208 )
F_63 ( V_1 , V_209 ,
V_19 -> V_141 , V_210 ) ;
F_63 ( V_1 , V_211 , V_13 , V_3 ) ;
return;
V_206:
V_205 = 0 ;
if ( V_27 > 2 ) {
if ( V_13 [ V_27 - 2 ] != 0xff || V_13 [ V_27 - 1 ] != 0xd9 ) {
V_1 -> V_207 = V_212 ;
V_205 = - 3 ;
}
} else if ( V_27 + 6 < V_3 ) {
if ( V_13 [ V_27 + 6 ] & 0x08 ) {
V_1 -> V_207 = V_212 ;
V_205 = - 5 ;
}
}
F_63 ( V_1 , V_208 , V_13 , V_27 ) ;
if ( V_205 == 0 ) {
int V_213 ;
V_213 = ( V_19 -> V_193 * 100 ) /
( V_19 -> V_47 *
V_1 -> V_214 [ 0 ] -> V_215 [ 0 ] . V_216 ) ;
if ( V_213 >= 85 )
V_205 = - 3 ;
else if ( V_213 < 75 )
V_205 = 2 ;
}
if ( V_205 != 0 ) {
V_19 -> V_194 += V_205 ;
if ( V_19 -> V_194 < - 6 || V_19 -> V_194 >= 12 ) {
V_19 -> V_194 = 0 ;
V_205 += V_19 -> V_49 ;
if ( V_205 < V_217 )
V_205 = V_217 ;
else if ( V_205 > V_218 )
V_205 = V_218 ;
if ( V_205 != V_19 -> V_49 ) {
V_19 -> V_49 = V_205 ;
F_64 ( & V_19 -> V_51 ) ;
}
}
} else {
V_19 -> V_194 = 0 ;
}
V_19 -> V_193 = V_19 -> V_47 = 0 ;
if ( V_27 + 62 > V_3 ) {
V_19 -> V_195 = V_27 + 62 - V_3 ;
return;
}
if ( V_19 -> V_48 >= 0 )
F_60 ( V_19 , V_13 + V_27 ) ;
V_27 += 62 ;
if ( V_27 < V_3 ) {
V_13 += V_27 ;
V_3 -= V_27 ;
F_63 ( V_1 , V_209 ,
V_19 -> V_141 , V_210 ) ;
F_63 ( V_1 , V_211 , V_13 , V_3 ) ;
}
}
static int F_65 ( struct V_219 * V_220 )
{
struct V_1 * V_1 =
F_48 ( V_220 -> V_221 , struct V_1 , V_67 ) ;
V_1 -> V_5 = 0 ;
if ( ! V_1 -> V_222 )
return 0 ;
switch ( V_220 -> V_39 ) {
case V_71 :
F_34 ( V_1 ) ;
break;
case V_73 :
F_35 ( V_1 ) ;
break;
case V_75 :
F_36 ( V_1 ) ;
break;
case V_77 :
F_37 ( V_1 ) ;
break;
case V_80 :
F_38 ( V_1 ) ;
break;
case V_95 :
F_40 ( V_1 ) ;
F_39 ( V_1 ) ;
F_41 ( V_1 ) ;
break;
case V_98 :
F_42 ( V_1 ) ;
break;
case V_82 :
F_43 ( V_1 ) ;
break;
case V_85 :
F_44 ( V_1 ) ;
break;
case V_100 :
F_45 ( V_1 ) ;
break;
default:
return - V_223 ;
}
return V_1 -> V_5 ;
}
static int F_66 ( struct V_1 * V_1 ,
T_2 * V_13 ,
int V_3 )
{
int V_4 = - V_223 ;
if ( V_3 == 1 && V_13 [ 0 ] == 1 ) {
F_67 ( V_1 -> V_224 , V_225 , 1 ) ;
F_68 ( V_1 -> V_224 ) ;
F_67 ( V_1 -> V_224 , V_225 , 0 ) ;
F_68 ( V_1 -> V_224 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_69 ( struct V_226 * V_227 ,
const struct V_38 * V_39 )
{
return F_70 ( V_227 , V_39 , & V_228 , sizeof( struct V_19 ) ,
V_229 ) ;
}
