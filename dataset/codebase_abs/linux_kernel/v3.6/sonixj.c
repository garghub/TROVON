static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 , int V_3 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
#ifdef F_2
if ( V_3 > V_6 ) {
F_3 ( L_1 ) ;
return;
}
#endif
V_4 = F_4 ( V_1 -> V_7 ,
F_5 ( V_1 -> V_7 , 0 ) ,
0 ,
V_8 | V_9 | V_10 ,
V_2 , 0 ,
V_1 -> V_11 , V_3 ,
500 ) ;
F_6 ( V_12 , L_2 , V_2 , V_1 -> V_11 [ 0 ] ) ;
if ( V_4 < 0 ) {
F_3 ( L_3 , V_4 ) ;
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
F_6 ( V_14 , L_4 , V_2 , V_13 ) ;
V_1 -> V_11 [ 0 ] = V_13 ;
V_4 = F_4 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
V_2 ,
0 ,
V_1 -> V_11 , 1 ,
500 ) ;
if ( V_4 < 0 ) {
F_3 ( L_5 , V_4 ) ;
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
F_6 ( V_14 , L_6 ,
V_2 , V_16 [ 0 ] , V_16 [ 1 ] ) ;
#ifdef F_2
if ( V_3 > V_6 ) {
F_3 ( L_7 ) ;
return;
}
#endif
memcpy ( V_1 -> V_11 , V_16 , V_3 ) ;
V_4 = F_4 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
V_2 , 0 ,
V_1 -> V_11 , V_3 ,
500 ) ;
if ( V_4 < 0 ) {
F_3 ( L_8 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_10 ( struct V_1 * V_1 , T_2 V_17 , T_2 V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_6 ( V_14 , L_9 , V_17 , V_18 ) ;
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
V_4 = F_4 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x08 ,
0 ,
V_1 -> V_11 , 8 ,
500 ) ;
if ( V_4 < 0 ) {
F_3 ( L_10 , V_4 ) ;
V_1 -> V_5 = V_4 ;
}
}
static void F_11 ( struct V_1 * V_1 ,
const T_2 * V_16 )
{
int V_4 ;
if ( V_1 -> V_5 < 0 )
return;
F_6 ( V_14 , L_11 ,
V_16 [ 2 ] , V_16 [ 3 ] ) ;
memcpy ( V_1 -> V_11 , V_16 , 8 ) ;
V_4 = F_4 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x08 , 0 ,
V_1 -> V_11 , 8 ,
500 ) ;
F_12 ( 2 ) ;
if ( V_4 < 0 ) {
F_3 ( L_12 , V_4 ) ;
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
F_11 ( V_1 , V_25 ) ;
F_12 ( 2 ) ;
V_25 [ 0 ] = ( V_25 [ 0 ] & 0x81 ) | ( V_3 << 4 ) | 0x02 ;
V_25 [ 2 ] = 0 ;
F_11 ( V_1 , V_25 ) ;
F_12 ( 2 ) ;
F_1 ( V_1 , 0x0a , 5 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
F_10 ( V_1 , 0x02 , 0 ) ;
F_12 ( 10 ) ;
F_7 ( V_1 , 0x02 , 0x66 ) ;
F_12 ( 10 ) ;
F_13 ( V_1 , 0 , 5 ) ;
if ( V_1 -> V_11 [ 0 ] == 0x02
&& V_1 -> V_11 [ 1 ] == 0x09
&& V_1 -> V_11 [ 2 ] == 0x01 ) {
F_6 ( V_26 , L_13 ) ;
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
F_11 ( V_1 , V_29 [ V_27 ] [ V_28 ] ) ;
F_12 ( 2 ) ;
F_1 ( V_1 , 0x0a , 5 ) ;
V_18 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
if ( V_29 [ V_27 ] [ 3 ] [ 0 ] != 0 )
F_11 ( V_1 , V_29 [ V_27 ] [ 3 ] ) ;
F_7 ( V_1 , 0x01 , 0x29 ) ;
F_7 ( V_1 , 0x17 , 0x42 ) ;
if ( V_18 != 0xffff )
break;
}
if ( V_1 -> V_5 < 0 )
return;
switch ( V_18 ) {
case 0x8221 :
F_6 ( V_26 , L_15 ) ;
V_19 -> V_20 = V_30 ;
break;
case 0x823a :
F_6 ( V_26 , L_16 ) ;
V_19 -> V_20 = V_31 ;
break;
case 0x8243 :
F_6 ( V_26 , L_17 ) ;
break;
default:
F_6 ( V_26 , L_18 , V_18 ) ;
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
F_6 ( V_26 , L_19 ) ;
return;
}
F_6 ( V_26 , L_20 , V_18 ) ;
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
F_6 ( V_26 , L_20 , V_18 ) ;
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
F_6 ( V_26 , L_21 ) ;
V_19 -> V_20 = V_37 ;
return;
}
F_3 ( L_22 , V_18 ) ;
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
F_6 ( V_26 , L_23 ) ;
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
F_6 ( V_26 , L_24 ) ;
} else {
F_3 ( L_25 , V_18 ) ;
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
V_33 -> V_48 = V_19 -> V_48 ;
V_19 -> V_49 = - 1 ;
V_19 -> V_50 = V_51 ;
F_22 ( & V_19 -> V_52 , V_53 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
const T_2 * V_54 ;
T_2 V_55 [] = { 0x29 , 0x70 } ;
T_2 V_56 ;
F_7 ( V_1 , 0xf1 , 0x01 ) ;
F_1 ( V_1 , 0x00 , 1 ) ;
F_7 ( V_1 , 0xf1 , 0x00 ) ;
F_1 ( V_1 , 0x00 , 1 ) ;
V_56 = V_1 -> V_11 [ 0 ] ;
if ( V_1 -> V_5 < 0 )
return V_1 -> V_5 ;
F_6 ( V_26 , L_26 , V_56 ) ;
if ( V_1 -> V_57 )
V_55 [ 1 ] |= 0x04 ;
switch ( V_19 -> V_40 ) {
case V_58 :
case V_59 :
if ( V_56 != 0x11 )
return - V_60 ;
break;
default:
if ( V_56 != 0x12 )
return - V_60 ;
}
switch ( V_19 -> V_20 ) {
case V_61 :
F_16 ( V_1 ) ;
break;
case V_62 :
F_18 ( V_1 ) ;
break;
case V_63 :
F_19 ( V_1 ) ;
break;
case V_64 :
F_20 ( V_1 ) ;
break;
}
switch ( V_19 -> V_40 ) {
case V_58 :
F_7 ( V_1 , 0x02 , V_55 [ 1 ] ) ;
break;
default:
F_9 ( V_1 , 0x01 , V_55 , 2 ) ;
break;
}
if ( V_19 -> V_20 == V_22 )
V_19 -> V_48 [ V_65 ] . V_66 = 0x10 ;
F_7 ( V_1 , 0xf1 , 0x00 ) ;
V_54 = V_67 [ V_19 -> V_20 ] ;
V_19 -> V_24 = V_54 [ 9 ] ;
V_1 -> V_68 = V_68 [ V_19 -> V_20 ] ;
if ( ! ( V_19 -> V_42 & V_69 ) )
V_1 -> V_68 |= ( 1 << V_70 ) ;
return V_1 -> V_5 ;
}
static T_3 F_24 ( struct V_1 * V_1 ,
T_3 V_71 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
switch ( V_19 -> V_20 ) {
case V_23 : {
int V_72 , V_73 ;
V_72 = 19 + V_71 * 25 / 256 ;
F_10 ( V_1 , 0x68 , V_72 ) ;
V_72 -= 12 ;
V_73 = V_72 * V_72 * 4 ;
F_10 ( V_1 , 0x03 , V_73 >> 8 ) ;
F_10 ( V_1 , 0x04 , V_73 ) ;
break;
}
case V_74 : {
T_2 V_75 [] =
{ 0xc1 , 0x11 , 0x25 , 0x00 , 0x00 , 0x00 , 0x00 , 0x16 } ;
V_75 [ 3 ] = V_71 >> 16 ;
V_75 [ 4 ] = V_71 >> 8 ;
V_75 [ 5 ] = V_71 ;
F_11 ( V_1 , V_75 ) ;
break;
}
case V_61 :
case V_30 : {
T_2 V_76 [] =
{ 0xb1 , 0x5d , 0x09 , 0x00 , 0x00 , 0x00 , 0x00 , 0x16 } ;
static const T_2 V_77 [] =
{ 0xb1 , 0x5d , 0x07 , 0x00 , 0x03 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_78 [] =
{ 0xb1 , 0x5d , 0x07 , 0x00 , 0x02 , 0x00 , 0x00 , 0x10 } ;
if ( V_71 > 0x0635 )
V_71 = 0x0635 ;
else if ( V_71 < 0x0001 )
V_71 = 0x0001 ;
V_76 [ 3 ] = V_71 >> 8 ;
V_76 [ 4 ] = V_71 ;
F_11 ( V_1 , V_76 ) ;
F_11 ( V_1 , V_77 ) ;
F_11 ( V_1 , V_78 ) ;
break;
}
case V_79 : {
T_2 V_80 [] =
{ 0xa1 , 0x21 , 0x0f , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
T_2 V_81 [] =
{ 0xa1 , 0x21 , 0x10 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_82 [] =
{ 0xa1 , 0x21 , 0x00 , 0x10 , 0x00 , 0x00 , 0x00 , 0x1d } ;
if ( V_71 > 0x1fff )
V_71 = 0x1fff ;
else if ( V_71 < 0x0001 )
V_71 = 0x0001 ;
V_80 [ 3 ] = ( V_71 & 0x03fc ) >> 2 ;
F_11 ( V_1 , V_80 ) ;
V_81 [ 3 ] = ( ( V_71 & 0x1c00 ) >> 10 )
| ( ( V_71 & 0x0003 ) << 4 ) ;
F_11 ( V_1 , V_81 ) ;
F_11 ( V_1 , V_82 ) ;
F_6 ( V_83 , L_27 ,
( ( V_81 [ 3 ] & 0x07 ) << 10 )
| ( V_80 [ 3 ] << 2 )
| ( ( V_81 [ 3 ] & 0x30 ) >> 4 ) ) ;
break;
}
case V_31 : {
T_2 V_84 [] =
{ 0xb1 , 0x5c , 0x09 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
if ( V_71 > 0x0390 )
V_71 = 0x0390 ;
else if ( V_71 < 0x0060 )
V_71 = 0x0060 ;
V_84 [ 3 ] = V_71 >> 8 ;
V_84 [ 4 ] = V_71 ;
F_11 ( V_1 , V_84 ) ;
break;
}
case V_22 : {
T_2 V_85 [] =
{ 0xa0 , 0x34 , 0xe5 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
if ( V_71 > 0x03ff )
V_71 = 0x03ff ;
if ( V_71 < 0x0001 )
V_71 = 0x0001 ;
V_85 [ 3 ] = V_71 >> 2 ;
F_11 ( V_1 , V_85 ) ;
F_7 ( V_1 , 0x96 , V_71 >> 5 ) ;
F_6 ( V_83 , L_27 , V_85 [ 3 ] ) ;
break;
}
}
return V_71 ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
unsigned int V_71 ;
int V_86 ;
T_2 V_87 ;
V_86 = V_19 -> V_48 [ V_88 ] . V_18 ;
V_87 = ( V_86 - 0x80 ) >> 2 ;
switch ( V_19 -> V_20 ) {
case V_21 :
if ( V_87 > 0x1f )
V_87 = 0 ;
break;
case V_74 :
V_71 = V_86 << 12 ;
if ( V_71 > 0x002dc6c0 )
V_71 = 0x002dc6c0 ;
else if ( V_71 < 0x02a0 )
V_71 = 0x02a0 ;
V_19 -> V_89 = F_24 ( V_1 , V_71 ) ;
break;
case V_61 :
case V_79 :
V_71 = V_86 << 4 ;
V_19 -> V_89 = F_24 ( V_1 , V_71 ) ;
break;
case V_30 :
V_71 = V_86 << 2 ;
V_19 -> V_89 = F_24 ( V_1 , V_71 ) ;
break;
case V_23 :
V_71 = V_86 ;
V_19 -> V_89 = F_24 ( V_1 , V_71 ) ;
return;
case V_31 :
V_71 = V_86 << 2 ;
V_19 -> V_89 = F_24 ( V_1 , V_71 ) ;
return;
case V_22 :
V_71 = V_86 << 2 ;
V_19 -> V_89 = F_24 ( V_1 , V_71 ) ;
return;
}
F_7 ( V_1 , 0x96 , V_87 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_2 V_87 ;
T_2 V_90 [ 6 ] ;
V_87 = V_19 -> V_48 [ V_91 ] . V_18 * 37 / ( V_92 + 1 )
+ 37 ;
V_90 [ 0 ] = ( V_87 + 1 ) / 2 ;
V_90 [ 1 ] = 0 ;
V_90 [ 2 ] = V_87 ;
V_90 [ 3 ] = 0 ;
V_90 [ 4 ] = V_87 / 5 ;
V_90 [ 5 ] = 0 ;
F_9 ( V_1 , 0x84 , V_90 , sizeof V_90 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 , V_93 , V_94 ;
const T_4 * V_95 ;
T_2 V_96 [ 12 ] ;
static const T_4 V_97 [ 6 ] = {
- 24 , - 38 , 64 ,
62 , - 51 , - 9
} ;
static const T_4 V_98 [ 6 ] = {
- 20 , - 38 , 64 ,
60 , - 51 , - 9
} ;
V_94 = V_19 -> V_48 [ V_99 ] . V_18 ;
if ( V_19 -> V_20 == V_30 )
V_95 = V_98 ;
else
V_95 = V_97 ;
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ ) {
V_93 = V_95 [ V_27 ] * V_94 / V_100 ;
V_96 [ V_27 * 2 ] = V_93 ;
V_96 [ V_27 * 2 + 1 ] = ( V_93 >> 8 ) & 0x0f ;
}
F_9 ( V_1 , 0x8a , V_96 , sizeof V_96 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_64 ) {
T_2 V_101 [] =
{ 0xc1 , 0x6e , 0x16 , 0x00 , 0x40 , 0x00 , 0x00 , 0x10 } ;
V_101 [ 3 ] = V_19 -> V_48 [ V_102 ] . V_18 * 2 ;
V_101 [ 5 ] = V_19 -> V_48 [ V_103 ] . V_18 * 2 ;
F_11 ( V_1 , V_101 ) ;
return;
}
F_7 ( V_1 , 0x05 , V_19 -> V_48 [ V_102 ] . V_18 ) ;
F_7 ( V_1 , 0x06 , V_19 -> V_48 [ V_103 ] . V_18 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 , V_18 ;
T_2 gamma [ 17 ] ;
const T_2 * V_104 ;
static const T_2 V_105 [ 17 ] = {
0x00 , 0x14 , 0x1c , 0x1c , 0x1c , 0x1c , 0x1b , 0x1a ,
0x18 , 0x13 , 0x10 , 0x0e , 0x08 , 0x07 , 0x04 , 0x02 , 0x00
} ;
switch ( V_19 -> V_20 ) {
case V_21 :
V_104 = V_106 ;
break;
case V_74 :
case V_30 :
case V_31 :
V_104 = V_107 ;
break;
case V_23 :
V_104 = V_108 ;
break;
case V_109 :
V_104 = V_110 ;
break;
default:
V_104 = V_111 ;
break;
}
V_18 = V_19 -> V_48 [ GAMMA ] . V_18 ;
for ( V_27 = 0 ; V_27 < sizeof gamma ; V_27 ++ )
gamma [ V_27 ] = V_104 [ V_27 ]
+ V_105 [ V_27 ] * ( V_18 - V_112 ) / 32 ;
F_9 ( V_1 , 0x20 , gamma , sizeof gamma ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_64 ) {
T_2 V_113 [] =
{ 0xa1 , 0x6e , 0x1a , 0x00 , 0x40 , 0x00 , 0x00 , 0x10 } ;
V_113 [ 3 ] = V_19 -> V_48 [ V_114 ] . V_18 >> 8 ;
F_11 ( V_1 , V_113 ) ;
F_12 ( 6 ) ;
V_113 [ 2 ] = 0x1b ;
V_113 [ 3 ] = V_19 -> V_48 [ V_114 ] . V_18 ;
F_11 ( V_1 , V_113 ) ;
}
}
static void F_31 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_1 -> V_68 & ( 1 << V_115 ) )
return;
switch ( V_19 -> V_20 ) {
case V_62 :
case V_63 : {
T_2 V_116 ;
if ( V_19 -> V_20 == V_62 )
V_116 = 0xc0 ;
else
V_116 = 0xa0 ;
if ( V_19 -> V_48 [ V_115 ] . V_18 )
V_116 |= 0x03 ;
F_10 ( & V_19 -> V_1 , 0x13 , V_116 ) ;
return;
}
}
if ( V_19 -> V_48 [ V_115 ] . V_18 )
V_19 -> V_49 = V_117 ;
else
V_19 -> V_49 = - 1 ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_20 == V_64 ) {
T_2 V_118 [] =
{ 0xa1 , 0x6e , 0x15 , 0x00 , 0x40 , 0x00 , 0x00 , 0x15 } ;
V_118 [ 3 ] = V_19 -> V_48 [ V_119 ] . V_18 ;
F_11 ( V_1 , V_118 ) ;
}
}
static void F_33 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_2 V_120 ;
switch ( V_19 -> V_20 ) {
case V_74 :
V_120 = 0x18 ;
if ( V_19 -> V_48 [ V_121 ] . V_18 )
V_120 |= 0x01 ;
F_10 ( V_1 , 0x01 , V_120 ) ;
break;
case V_62 :
V_120 = 0x02 ;
if ( ! V_19 -> V_48 [ V_121 ] . V_18 )
V_120 |= 0x80 ;
F_10 ( V_1 , 0x75 , V_120 ) ;
break;
case V_63 :
V_120 = 0x06 ;
if ( V_19 -> V_48 [ V_121 ] . V_18 )
V_120 |= 0x80 ;
F_10 ( V_1 , 0x75 , V_120 ) ;
break;
case V_64 :
V_120 = 0x0a ;
if ( V_19 -> V_48 [ V_122 ] . V_18 )
V_120 |= 0x80 ;
if ( V_19 -> V_48 [ V_121 ] . V_18 )
V_120 |= 0x40 ;
F_10 ( & V_19 -> V_1 , 0x1e , V_120 ) ;
break;
}
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_7 ( V_1 , 0x99 , V_19 -> V_48 [ V_65 ] . V_18 ) ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_1 -> V_68 & ( 1 << V_70 ) )
return;
switch ( V_19 -> V_20 ) {
case V_21 :
F_7 ( V_1 , 0x02 ,
V_19 -> V_48 [ V_70 ] . V_18 ? 0x64 : 0x60 ) ;
break;
case V_31 :
F_7 ( V_1 , 0x02 ,
V_19 -> V_48 [ V_70 ] . V_18 ? 0x77 : 0x74 ) ;
break;
}
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_1 -> V_68 & ( 1 << V_123 ) )
return;
if ( V_19 -> V_20 == V_124 ) {
T_2 V_125 ;
V_125 = 0xdf ;
switch ( V_19 -> V_48 [ V_123 ] . V_18 ) {
case 0 :
F_10 ( V_1 , 0x13 , V_125 | 0x20 ) ;
break;
case 1 :
F_10 ( V_1 , 0x13 , V_125 ) ;
F_10 ( V_1 , 0x3b , 0x0a ) ;
break;
case 2 :
F_10 ( V_1 , 0x13 , V_125 ) ;
F_10 ( V_1 , 0x3b , 0x02 ) ;
break;
}
} else {
T_2 V_126 = 0 , V_127 = 0 , V_128 = 0 ;
switch ( V_19 -> V_20 ) {
case V_62 :
V_126 = 0x08 ;
V_128 = 0x01 ;
break;
case V_63 :
V_126 = 0x11 ;
V_128 = 0x81 ;
break;
}
switch ( V_19 -> V_48 [ V_123 ] . V_18 ) {
case 0 :
break;
case 1 :
V_126 |= 0x80 ;
V_127 = 0xac ;
V_128 |= 0x04 ;
break;
case 2 :
V_126 |= 0x80 ;
V_128 |= 0x04 ;
break;
}
F_10 ( V_1 , 0x2a , V_126 ) ;
F_10 ( V_1 , 0x2b , V_127 ) ;
F_10 ( V_1 , 0x2d , V_128 ) ;
}
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_38 ( V_19 -> V_129 , V_19 -> V_50 ) ;
#if V_6 < 64
#error "No room enough in usb_buf for quantization table"
#endif
memcpy ( V_1 -> V_11 , & V_19 -> V_129 [ V_130 ] , 64 ) ;
F_4 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x0100 , 0 ,
V_1 -> V_11 , 64 ,
500 ) ;
memcpy ( V_1 -> V_11 , & V_19 -> V_129 [ V_131 ] , 64 ) ;
F_4 ( V_1 -> V_7 ,
F_8 ( V_1 -> V_7 , 0 ) ,
0x08 ,
V_15 | V_9 | V_10 ,
0x0140 , 0 ,
V_1 -> V_11 , 64 ,
500 ) ;
V_19 -> V_132 ^= 0x40 ;
F_7 ( V_1 , 0x18 , V_19 -> V_132 ) ;
}
static void V_53 ( struct V_133 * V_52 )
{
struct V_19 * V_19 = F_39 ( V_52 , struct V_19 , V_52 ) ;
struct V_1 * V_1 = & V_19 -> V_1 ;
F_40 ( & V_1 -> V_134 ) ;
F_6 ( V_135 , L_28 , V_19 -> V_50 ) ;
F_37 ( V_1 ) ;
F_41 ( & V_1 -> V_134 ) ;
}
static int F_42 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 ;
T_2 V_136 , V_137 ;
T_2 V_138 [ 2 ] ;
const T_2 * V_54 ;
const T_2 ( * V_139 ) [ 8 ] ;
const T_2 * V_140 ;
int V_25 ;
static const T_2 V_141 [] =
{ 0x00 , 0x40 , 0x20 , 0x00 , 0x00 , 0x00 } ;
static const T_2 V_142 [] =
{ 0x00 , 0x40 , 0x38 , 0x30 , 0x00 , 0x20 } ;
static const T_2 V_143 [] = { 0x60 , 0x00 , 0x00 } ;
static const T_2 V_144 [] = { 0x2d , 0x2d , 0x3a , 0x05 , 0x04 , 0x3f } ;
static const T_2 V_145 [] = { 0x28 , 0xd8 , 0x14 , 0xec } ;
static const T_2 V_146 [] =
{ 0x14 , 0xec , 0x0a , 0xf6 } ;
static const T_2 V_147 [] =
{ 0x1e , 0xe2 , 0x14 , 0xec } ;
static const T_2 V_148 [] = { 0x32 , 0xdd , 0x2d , 0xdd } ;
static const T_2 V_149 [] =
{ 0x32 , 0xce , 0x2d , 0xd3 } ;
static const T_2 V_150 [] =
{ 0x32 , 0xdd , 0x32 , 0xdd } ;
static const T_2 V_151 [] =
{ 0x14 , 0xe7 , 0x1e , 0xdd } ;
F_43 ( V_19 -> V_129 , V_1 -> V_152 , V_1 -> V_153 ,
0x21 ) ;
V_54 = V_67 [ V_19 -> V_20 ] ;
V_136 = V_54 [ 1 ] ;
if ( V_19 -> V_42 & V_154 )
V_136 ^= V_155 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
V_138 [ 0 ] = V_136 ;
V_138 [ 1 ] = V_54 [ 2 ] ;
if ( V_1 -> V_57 )
V_138 [ 1 ] |= 0x04 ;
F_9 ( V_1 , 0x01 , V_138 , 2 ) ;
F_9 ( V_1 , 0x08 , & V_54 [ 8 ] , 2 ) ;
F_9 ( V_1 , 0x17 , & V_54 [ 0x17 ] , 5 ) ;
switch ( V_19 -> V_20 ) {
case V_23 :
case V_124 :
case V_37 :
case V_64 :
case V_32 :
case V_109 :
V_140 = V_142 ;
break;
default:
V_140 = V_141 ;
break;
}
F_9 ( V_1 , 0x9a , V_140 , 6 ) ;
F_9 ( V_1 , 0xd4 , V_143 , sizeof V_143 ) ;
F_9 ( V_1 , 0x03 , & V_54 [ 3 ] , 0x0f ) ;
V_137 = V_54 [ 0x17 ] ;
switch ( V_19 -> V_20 ) {
case V_23 :
F_12 ( 50 ) ;
break;
case V_22 :
F_12 ( 10 ) ;
F_7 ( V_1 , 0x02 , 0x73 ) ;
V_137 |= V_156 ;
F_7 ( V_1 , 0x17 , V_137 ) ;
F_7 ( V_1 , 0x01 , 0x22 ) ;
F_12 ( 100 ) ;
V_136 = V_157 | V_155 ;
V_137 &= ~ V_158 ;
V_137 |= 0x04 ;
break;
}
V_136 |= V_159 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
V_137 |= V_156 ;
F_7 ( V_1 , 0x17 , V_137 ) ;
V_136 &= ~ V_160 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
V_136 &= ~ V_157 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
switch ( V_19 -> V_20 ) {
case V_74 :
F_14 ( V_1 ) ;
break;
case V_22 :
F_12 ( 10 ) ;
F_7 ( V_1 , 0x01 , V_136 ) ;
F_11 ( V_1 , V_161 [ 0 ] ) ;
F_11 ( V_1 , V_161 [ 1 ] ) ;
F_12 ( 15 ) ;
F_7 ( V_1 , 0x02 , 0x71 ) ;
F_12 ( 150 ) ;
break;
case V_109 :
F_12 ( 100 ) ;
F_7 ( V_1 , 0x02 , 0x62 ) ;
break;
}
F_44 ( V_1 , V_162 [ V_19 -> V_20 ] ) ;
F_7 ( V_1 , 0x15 , V_54 [ 0x15 ] ) ;
F_7 ( V_1 , 0x16 , V_54 [ 0x16 ] ) ;
F_7 ( V_1 , 0x12 , V_54 [ 0x12 ] ) ;
F_7 ( V_1 , 0x13 , V_54 [ 0x13 ] ) ;
F_7 ( V_1 , 0x18 , V_54 [ 0x18 ] ) ;
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
F_7 ( V_1 , 0x18 , V_54 [ 0x18 ] ) ;
switch ( V_19 -> V_20 ) {
case V_22 :
break;
default:
V_137 |= V_163 ;
break;
}
F_7 ( V_1 , 0x17 , V_137 ) ;
F_7 ( V_1 , 0x05 , 0x00 ) ;
F_7 ( V_1 , 0x07 , 0x00 ) ;
F_7 ( V_1 , 0x06 , 0x00 ) ;
F_7 ( V_1 , 0x14 , V_54 [ 0x14 ] ) ;
F_29 ( V_1 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_9 ( V_1 , 0x84 , V_164 , sizeof V_164 ) ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_124 :
case V_109 :
F_7 ( V_1 , 0x9a , 0x05 ) ;
break;
case V_23 :
case V_31 :
case V_30 :
F_7 ( V_1 , 0x9a , 0x07 ) ;
break;
case V_62 :
case V_63 :
F_7 ( V_1 , 0x9a , 0x0a ) ;
break;
case V_64 :
case V_32 :
F_7 ( V_1 , 0x9a , 0x06 ) ;
break;
default:
F_7 ( V_1 , 0x9a , 0x08 ) ;
break;
}
F_34 ( V_1 ) ;
F_9 ( V_1 , 0x84 , V_164 , sizeof V_164 ) ;
F_7 ( V_1 , 0x05 , 0x20 ) ;
F_7 ( V_1 , 0x07 , 0x20 ) ;
F_7 ( V_1 , 0x06 , 0x20 ) ;
V_139 = NULL ;
V_25 = V_1 -> V_33 . V_43 [ V_1 -> V_165 ] . V_166 ;
V_136 |= V_159 | V_167 ;
V_137 &= ~ V_158 ;
V_137 |= 0x02 ;
switch ( V_19 -> V_20 ) {
case V_21 :
V_139 = V_168 ;
break;
case V_23 :
V_139 = V_169 ;
break;
case V_74 :
case V_61 :
if ( ! V_25 )
V_136 &= ~ V_159 ;
V_137 &= ~ V_158 ;
V_137 |= 0x01 ;
break;
case V_30 :
V_139 = V_170 ;
break;
case V_79 :
if ( V_25 ) {
V_136 &= ~ V_159 ;
V_137 &= ~ V_158 ;
V_137 |= 0x01 ;
}
break;
case V_31 :
V_139 = V_171 ;
break;
case V_22 :
V_139 = V_172 ;
if ( ! V_25 ) {
V_137 &= ~ V_158 ;
V_137 |= 0x04 ;
} else {
V_136 &= ~ V_159 ;
V_137 &= ~ V_158 ;
V_137 |= 0x02 ;
}
break;
case V_62 :
V_139 = V_173 ;
break;
case V_63 :
V_139 = V_174 ;
V_137 &= ~ V_158 ;
V_137 |= 0x01 ;
break;
case V_124 :
V_139 = V_175 ;
break;
case V_37 :
V_139 = V_176 ;
break;
case V_64 :
V_139 = V_177 ;
break;
case V_32 :
V_139 = V_178 ;
break;
case V_109 :
V_139 = V_179 ;
break;
}
if ( V_139 != NULL ) {
F_44 ( V_1 , V_139 ) ;
}
F_9 ( V_1 , 0xc0 , V_144 , 6 ) ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_23 :
case V_32 :
F_9 ( V_1 , 0xca , V_146 , 4 ) ;
break;
case V_64 :
F_9 ( V_1 , 0xca , V_147 , 4 ) ;
break;
default:
F_9 ( V_1 , 0xca , V_145 , 4 ) ;
break;
}
switch ( V_19 -> V_20 ) {
case V_21 :
case V_62 :
case V_63 :
case V_124 :
case V_32 :
F_9 ( V_1 , 0xce , V_150 , 4 ) ;
break;
case V_23 :
F_9 ( V_1 , 0xce , V_149 , 4 ) ;
break;
case V_64 :
F_9 ( V_1 , 0xce , V_151 , 4 ) ;
break;
default:
F_9 ( V_1 , 0xce , V_148 , 4 ) ;
break;
}
V_19 -> V_132 = V_54 [ 0x18 ] | ( V_25 << 4 ) | 0x40 ;
F_7 ( V_1 , 0x18 , V_19 -> V_132 ) ;
F_37 ( V_1 ) ;
F_7 ( V_1 , 0x17 , V_137 ) ;
F_7 ( V_1 , 0x01 , V_136 ) ;
V_19 -> V_136 = V_136 ;
V_19 -> V_137 = V_137 ;
F_33 ( V_1 ) ;
F_25 ( V_1 ) ;
F_26 ( V_1 ) ;
F_27 ( V_1 ) ;
F_31 ( V_1 ) ;
if ( ! ( V_1 -> V_180 & ( ( 1 << V_114 ) | ( 1 << V_119 ) ) ) ) {
F_30 ( V_1 ) ;
F_32 ( V_1 ) ;
}
F_36 ( V_1 ) ;
V_19 -> V_181 = V_19 -> V_47 = 0 ;
V_19 -> V_182 = V_19 -> V_183 = 0 ;
V_19 -> V_184 = F_45 ( V_185 ) ;
return V_1 -> V_5 ;
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
static const T_2 V_186 [] =
{ 0xa1 , 0x11 , 0x02 , 0x09 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_187 [] =
{ 0xb1 , 0x5d , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_188 [] =
{ 0xa1 , 0x21 , 0x76 , 0x20 , 0x00 , 0x00 , 0x00 , 0x10 } ;
static const T_2 V_189 [] =
{ 0xa1 , 0x21 , 0x12 , 0x80 , 0x00 , 0x00 , 0x00 , 0x10 } ;
T_2 V_136 ;
T_2 V_137 ;
V_136 = V_19 -> V_136 ;
V_137 = V_19 -> V_137 & ~ V_156 ;
switch ( V_19 -> V_20 ) {
case V_21 :
case V_23 :
case V_64 :
case V_109 :
V_136 |= V_190 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
V_136 &= ~ ( V_190 | V_167 ) ;
F_7 ( V_1 , 0x01 , V_136 ) ;
break;
case V_74 :
V_136 &= ~ V_167 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
F_11 ( V_1 , V_186 ) ;
break;
case V_61 :
case V_30 :
V_136 &= ~ V_167 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
F_11 ( V_1 , V_187 ) ;
break;
case V_31 :
case V_22 :
case V_37 :
V_136 &= ~ V_167 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
break;
case V_62 :
case V_63 :
V_136 &= ~ V_167 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
F_11 ( V_1 , V_188 ) ;
break;
case V_124 :
V_136 &= ~ V_167 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
break;
case V_32 :
F_11 ( V_1 , V_189 ) ;
break;
}
V_136 |= V_157 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
V_136 |= V_160 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
F_7 ( V_1 , 0x17 , V_137 ) ;
V_136 &= ~ V_159 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
V_136 |= V_190 ;
F_7 ( V_1 , 0x01 , V_136 ) ;
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
if ( V_19 -> V_184 != NULL ) {
F_41 ( & V_1 -> V_134 ) ;
F_48 ( V_19 -> V_184 ) ;
F_40 ( & V_1 -> V_134 ) ;
V_19 -> V_184 = NULL ;
}
}
static void F_49 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_105 ;
int V_191 ;
T_2 V_192 = 130 ;
T_2 V_193 = 20 ;
if ( V_19 -> V_49 < 0 )
return;
if ( -- V_19 -> V_49 >= 0 )
return;
V_19 -> V_49 = V_117 ;
V_105 = F_50 ( & V_19 -> V_194 ) ;
F_6 ( V_83 , L_29 , V_105 ) ;
if ( V_19 -> V_20 == V_64 ) {
F_51 ( V_1 , V_105 , V_192 , V_193 ,
15 , 1024 ) ;
return;
}
if ( V_105 < V_192 - V_193 ||
V_105 > V_192 + V_193 ) {
switch ( V_19 -> V_20 ) {
case V_23 :
V_191 = V_19 -> V_89 ;
V_191 += ( V_192 - V_105 ) >> 6 ;
if ( V_191 < 0 )
V_191 = 0 ;
V_19 -> V_89 = F_24 ( V_1 ,
( unsigned int ) V_191 ) ;
break;
case V_74 :
V_191 = V_19 -> V_89 >> 8 ;
V_191 += ( V_192 - V_105 ) >> 4 ;
if ( V_191 < 0 )
V_191 = 0 ;
V_19 -> V_89 = F_24 ( V_1 ,
( unsigned int ) ( V_191 << 8 ) ) ;
break;
case V_22 :
case V_31 :
V_191 = V_19 -> V_89 ;
V_191 += ( V_192 - V_105 ) >> 2 ;
if ( V_191 < 0 )
V_191 = 0 ;
V_19 -> V_89 = F_24 ( V_1 ,
( unsigned int ) V_191 ) ;
F_28 ( V_1 ) ;
break;
default:
V_191 = V_19 -> V_89 ;
V_191 += ( V_192 - V_105 ) >> 6 ;
if ( V_191 < 0 )
V_191 = 0 ;
V_19 -> V_89 = F_24 ( V_1 ,
( unsigned int ) V_191 ) ;
F_28 ( V_1 ) ;
break;
}
}
}
static void F_52 ( struct V_19 * V_19 ,
T_2 * V_13 )
{
int V_194 ;
V_194 = ( V_13 [ 27 ] << 8 ) + V_13 [ 28 ]
+ ( V_13 [ 31 ] << 8 ) + V_13 [ 32 ]
+ ( V_13 [ 23 ] << 8 ) + V_13 [ 24 ]
+ ( V_13 [ 35 ] << 8 ) + V_13 [ 36 ]
+ ( V_13 [ 29 ] << 10 ) + ( V_13 [ 30 ] << 2 ) ;
V_194 >>= 10 ;
F_53 ( & V_19 -> V_194 , V_194 ) ;
}
static void F_54 ( struct V_1 * V_1 ,
T_2 * V_13 ,
int V_3 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
int V_27 , V_195 ;
V_19 -> V_47 ++ ;
V_19 -> V_181 += V_3 ;
V_27 = V_19 -> V_183 ;
if ( V_27 != 0 ) {
V_19 -> V_183 = 0 ;
if ( V_27 < 0
&& V_13 [ 0 ] == 0xff
&& V_13 [ 1 ] == 0x00 )
goto V_196;
if ( V_13 [ 0 ] == 0xff && V_13 [ 1 ] == 0xff ) {
V_27 = 0 ;
goto V_196;
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
goto V_196;
}
}
if ( V_13 [ V_3 - 1 ] == 0xff )
V_19 -> V_183 = - 1 ;
if ( V_1 -> V_197 == V_198 )
F_55 ( V_1 , V_199 ,
V_19 -> V_129 , V_200 ) ;
F_55 ( V_1 , V_201 , V_13 , V_3 ) ;
return;
V_196:
V_195 = 0 ;
if ( V_27 > 2 ) {
if ( V_13 [ V_27 - 2 ] != 0xff || V_13 [ V_27 - 1 ] != 0xd9 ) {
V_1 -> V_197 = V_202 ;
V_195 = - 3 ;
}
} else if ( V_27 + 6 < V_3 ) {
if ( V_13 [ V_27 + 6 ] & 0x08 ) {
V_1 -> V_197 = V_202 ;
V_195 = - 5 ;
}
}
F_55 ( V_1 , V_198 , V_13 , V_27 ) ;
if ( V_195 == 0 ) {
int V_203 ;
V_203 = ( V_19 -> V_181 * 100 ) /
( V_19 -> V_47 *
V_1 -> V_204 [ 0 ] -> V_205 [ 0 ] . V_206 ) ;
if ( V_203 >= 85 )
V_195 = - 3 ;
else if ( V_203 < 75 )
V_195 = 2 ;
}
if ( V_195 != 0 ) {
V_19 -> V_182 += V_195 ;
if ( V_19 -> V_182 < - 6 || V_19 -> V_182 >= 12 ) {
V_19 -> V_182 = 0 ;
V_195 += V_19 -> V_50 ;
if ( V_195 < V_207 )
V_195 = V_207 ;
else if ( V_195 > V_208 )
V_195 = V_208 ;
if ( V_195 != V_19 -> V_50 ) {
V_19 -> V_50 = V_195 ;
F_56 ( V_19 -> V_184 , & V_19 -> V_52 ) ;
}
}
} else {
V_19 -> V_182 = 0 ;
}
V_19 -> V_181 = V_19 -> V_47 = 0 ;
if ( V_27 + 62 > V_3 ) {
V_19 -> V_183 = V_27 + 62 - V_3 ;
return;
}
if ( V_19 -> V_49 >= 0 )
F_52 ( V_19 , V_13 + V_27 ) ;
V_27 += 62 ;
if ( V_27 < V_3 ) {
V_13 += V_27 ;
V_3 -= V_27 ;
F_55 ( V_1 , V_199 ,
V_19 -> V_129 , V_200 ) ;
F_55 ( V_1 , V_201 , V_13 , V_3 ) ;
}
}
static int F_57 ( struct V_1 * V_1 , T_5 V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_48 [ V_115 ] . V_18 = V_18 ;
if ( V_18 )
V_1 -> V_180 |= ( 1 << V_114 ) | ( 1 << V_119 ) ;
else
V_1 -> V_180 &= ~ ( 1 << V_114 ) & ~ ( 1 << V_119 ) ;
if ( V_1 -> V_209 )
F_31 ( V_1 ) ;
return V_1 -> V_5 ;
}
static int F_58 ( struct V_1 * V_1 ,
struct V_210 * V_211 )
{
switch ( V_211 -> V_39 ) {
case V_212 :
switch ( V_211 -> V_213 ) {
case 0 :
strcpy ( ( char * ) V_211 -> V_214 , L_30 ) ;
return 0 ;
case 1 :
strcpy ( ( char * ) V_211 -> V_214 , L_31 ) ;
return 0 ;
case 2 :
strcpy ( ( char * ) V_211 -> V_214 , L_32 ) ;
return 0 ;
}
break;
}
return - V_215 ;
}
static int F_59 ( struct V_1 * V_1 ,
T_2 * V_13 ,
int V_3 )
{
int V_4 = - V_215 ;
if ( V_3 == 1 && V_13 [ 0 ] == 1 ) {
F_60 ( V_1 -> V_216 , V_217 , 1 ) ;
F_61 ( V_1 -> V_216 ) ;
F_60 ( V_1 -> V_216 , V_217 , 0 ) ;
F_61 ( V_1 -> V_216 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_62 ( struct V_218 * V_219 ,
const struct V_38 * V_39 )
{
return F_63 ( V_219 , V_39 , & V_220 , sizeof( struct V_19 ) ,
V_221 ) ;
}
