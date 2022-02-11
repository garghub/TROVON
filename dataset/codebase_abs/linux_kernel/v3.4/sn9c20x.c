static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
if ( V_1 -> V_7 < 0 )
return;
V_6 = F_2 ( V_5 , F_3 ( V_5 , 0 ) ,
0x00 ,
V_8 | V_9 | V_10 ,
V_2 ,
0x00 ,
V_1 -> V_11 ,
V_3 ,
500 ) ;
if ( F_4 ( V_6 < 0 || V_6 != V_3 ) ) {
F_5 ( L_1 , V_2 , V_6 ) ;
V_1 -> V_7 = V_6 ;
}
}
static void F_6 ( struct V_1 * V_1 , T_1 V_2 ,
const T_2 * V_12 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
if ( V_1 -> V_7 < 0 )
return;
memcpy ( V_1 -> V_11 , V_12 , V_3 ) ;
V_6 = F_2 ( V_5 , F_7 ( V_5 , 0 ) ,
0x08 ,
V_13 | V_9 | V_10 ,
V_2 ,
0x00 ,
V_1 -> V_11 ,
V_3 ,
500 ) ;
if ( F_4 ( V_6 < 0 || V_6 != V_3 ) ) {
F_5 ( L_2 , V_2 , V_6 ) ;
V_1 -> V_7 = V_6 ;
}
}
static void F_8 ( struct V_1 * V_1 , T_1 V_2 , const T_2 V_14 )
{
F_6 ( V_1 , V_2 , & V_14 , 1 ) ;
}
static void F_9 ( struct V_1 * V_1 , const T_2 * V_12 )
{
int V_15 ;
F_6 ( V_1 , 0x10c0 , V_12 , 8 ) ;
for ( V_15 = 0 ; V_15 < 5 ; V_15 ++ ) {
F_1 ( V_1 , 0x10c0 , 1 ) ;
if ( V_1 -> V_7 < 0 )
return;
if ( V_1 -> V_11 [ 0 ] & 0x04 ) {
if ( V_1 -> V_11 [ 0 ] & 0x08 ) {
F_5 ( L_3 ) ;
V_1 -> V_7 = - V_16 ;
}
return;
}
F_10 ( 10 ) ;
}
F_5 ( L_4 , V_12 [ 2 ] ) ;
}
static void F_11 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = 0x81 | ( 2 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_20 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = V_17 ;
V_19 [ 4 ] = 0x00 ;
V_19 [ 5 ] = 0x00 ;
V_19 [ 6 ] = 0x00 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
struct V_21 * V_22 , int V_23 )
{
while ( -- V_23 >= 0 ) {
F_11 ( V_1 , V_22 -> V_2 , V_22 -> V_17 ) ;
V_22 ++ ;
}
}
static void F_13 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = 0x81 | ( 3 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_20 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = V_17 >> 8 ;
V_19 [ 4 ] = V_17 ;
V_19 [ 5 ] = 0x00 ;
V_19 [ 6 ] = 0x00 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
}
static void F_14 ( struct V_1 * V_1 ,
struct V_24 * V_22 , int V_23 )
{
while ( -- V_23 >= 0 ) {
F_13 ( V_1 , V_22 -> V_2 , V_22 -> V_17 ) ;
V_22 ++ ;
}
}
static void F_15 ( struct V_1 * V_1 , T_2 V_2 , T_2 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = 0x81 | ( 1 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_20 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = 0 ;
V_19 [ 4 ] = 0 ;
V_19 [ 5 ] = 0 ;
V_19 [ 6 ] = 0 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
V_19 [ 0 ] = 0x81 | ( 1 << 4 ) | 0x02 ;
V_19 [ 2 ] = 0 ;
F_9 ( V_1 , V_19 ) ;
F_1 ( V_1 , 0x10c2 , 5 ) ;
* V_17 = V_1 -> V_11 [ 4 ] ;
}
static void F_16 ( struct V_1 * V_1 , T_2 V_2 , T_1 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = 0x81 | ( 1 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_20 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = 0 ;
V_19 [ 4 ] = 0 ;
V_19 [ 5 ] = 0 ;
V_19 [ 6 ] = 0 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
V_19 [ 0 ] = 0x81 | ( 2 << 4 ) | 0x02 ;
V_19 [ 2 ] = 0 ;
F_9 ( V_1 , V_19 ) ;
F_1 ( V_1 , 0x10c2 , 5 ) ;
* V_17 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
}
static void F_17 ( struct V_1 * V_1 )
{
T_1 V_25 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_16 ( V_1 , 0x1c , & V_25 ) ;
if ( V_1 -> V_7 < 0 )
return;
if ( V_25 != 0x7fa2 ) {
F_5 ( L_5 , V_25 ) ;
V_1 -> V_7 = - V_26 ;
return;
}
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_27 , F_18 ( V_27 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_6 ) ;
V_18 -> V_28 = 1 ;
V_18 -> V_29 = 7 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_30 , F_18 ( V_30 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_7 ) ;
V_1 -> V_31 = ( 1 << V_32 ) | ( 1 << V_33 ) ;
V_18 -> V_28 = 1 ;
V_18 -> V_29 = 2 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_34 , F_18 ( V_34 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_8 ) ;
V_1 -> V_31 = ( 1 << V_32 ) | ( 1 << V_33 )
| ( 1 << V_35 ) ;
V_18 -> V_28 = 60 ;
V_18 -> V_29 = 11 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_36 , F_18 ( V_36 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_9 ) ;
V_18 -> V_28 = 3 ;
V_18 -> V_29 = 3 ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_37 , F_18 ( V_37 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_10 ) ;
V_1 -> V_31 = ( 1 << V_32 ) | ( 1 << V_33 ) ;
V_18 -> V_28 = 0 ;
V_18 -> V_29 = 1 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_1 V_14 ;
V_18 -> V_20 = 0x5d ;
F_16 ( V_1 , 0xff , & V_14 ) ;
if ( V_1 -> V_7 >= 0
&& V_14 == 0x8243 ) {
F_14 ( V_1 , V_38 , F_18 ( V_38 ) ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_11 ) ;
return;
}
V_18 -> V_28 = 2 ;
V_18 -> V_29 = 2 ;
V_18 -> V_39 = V_40 ;
F_24 ( L_12 ) ;
return;
}
V_1 -> V_7 = 0 ;
V_18 -> V_20 = 0x5c ;
F_13 ( V_1 , 0x01 , 0x0004 ) ;
F_16 ( V_1 , 0xff , & V_14 ) ;
if ( V_1 -> V_7 >= 0
&& V_14 == 0x823a ) {
F_14 ( V_1 , V_41 , F_18 ( V_41 ) ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_13 ) ;
return;
}
V_1 -> V_31 = ( 1 << V_35 )
| ( 1 << V_42 )
| ( 1 << V_43 ) ;
V_18 -> V_28 = 2 ;
V_18 -> V_29 = 2 ;
V_18 -> V_39 = V_44 ;
F_24 ( L_14 ) ;
return;
}
V_1 -> V_7 = 0 ;
V_18 -> V_20 = 0x5d ;
F_13 ( V_1 , 0xf0 , 0x0000 ) ;
if ( V_1 -> V_7 < 0 ) {
V_1 -> V_7 = 0 ;
V_18 -> V_20 = 0x48 ;
F_13 ( V_1 , 0xf0 , 0x0000 ) ;
}
F_16 ( V_1 , 0x00 , & V_14 ) ;
if ( V_1 -> V_7 >= 0
&& V_14 == 0x1229 ) {
F_14 ( V_1 , V_45 , F_18 ( V_45 ) ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_15 ) ;
return;
}
V_18 -> V_28 = 6 ;
V_18 -> V_29 = 2 ;
V_18 -> V_39 = V_46 ;
F_24 ( L_16 ) ;
return;
}
V_1 -> V_7 = - V_26 ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_14 ( V_1 , V_47 , F_18 ( V_47 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_17 ) ;
V_1 -> V_31 = ( 1 << V_35 ) | ( 1 << V_42 )
| ( 1 << V_43 ) ;
V_18 -> V_28 = 0 ;
V_18 -> V_29 = 2 ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_14 ( V_1 , V_48 , F_18 ( V_48 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_18 ) ;
V_1 -> V_31 = ( 1 << V_35 ) | ( 1 << V_42 )
| ( 1 << V_43 ) ;
V_18 -> V_28 = 0 ;
V_18 -> V_29 = 2 ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_1 V_25 ;
F_16 ( V_1 , 0x00 , & V_25 ) ;
if ( V_1 -> V_7 < 0 )
return;
switch ( V_25 ) {
case 0x8411 :
case 0x8421 :
F_24 ( L_19 ) ;
break;
case 0x8431 :
F_24 ( L_20 ) ;
break;
default:
F_5 ( L_21 , V_25 ) ;
V_1 -> V_7 = - V_26 ;
return;
}
F_14 ( V_1 , V_49 , F_18 ( V_49 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_22 ) ;
V_1 -> V_31 = ( 1 << V_32 ) | ( 1 << V_33 ) ;
V_18 -> V_28 = 1 ;
V_18 -> V_29 = 1 ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_12 ( V_1 , V_50 , F_18 ( V_50 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_23 ) ;
V_18 -> V_28 = 0 ;
V_18 -> V_29 = 1 ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_51 ;
T_3 V_52 , V_53 = 180 + V_18 -> V_54 [ V_55 ] . V_17 ;
T_2 V_56 [ 21 ] ;
memset ( V_56 , 0 , sizeof V_56 ) ;
V_56 [ 2 ] = ( V_18 -> V_54 [ V_57 ] . V_17 * 0x25 / 0x100 ) + 0x26 ;
V_56 [ 0 ] = 0x13 + ( V_56 [ 2 ] - 0x26 ) * 0x13 / 0x25 ;
V_56 [ 4 ] = 0x07 + ( V_56 [ 2 ] - 0x26 ) * 0x07 / 0x25 ;
V_56 [ 18 ] = V_18 -> V_54 [ V_58 ] . V_17 - 0x80 ;
V_51 = V_18 -> V_54 [ V_59 ] . V_17 ;
V_52 = ( V_60 [ V_53 ] * V_51 ) >> 8 ;
V_56 [ 6 ] = V_52 ;
V_56 [ 7 ] = ( V_52 >> 8 ) & 0x0f ;
V_52 = ( V_61 [ V_53 ] * V_51 ) >> 8 ;
V_56 [ 8 ] = V_52 ;
V_56 [ 9 ] = ( V_52 >> 8 ) & 0x0f ;
V_52 = ( V_62 [ V_53 ] * V_51 ) >> 8 ;
V_56 [ 10 ] = V_52 ;
V_56 [ 11 ] = ( V_52 >> 8 ) & 0x0f ;
V_52 = ( V_63 [ V_53 ] * V_51 ) >> 8 ;
V_56 [ 12 ] = V_52 ;
V_56 [ 13 ] = ( V_52 >> 8 ) & 0x0f ;
V_52 = ( V_64 [ V_53 ] * V_51 ) >> 8 ;
V_56 [ 14 ] = V_52 ;
V_56 [ 15 ] = ( V_52 >> 8 ) & 0x0f ;
V_52 = ( V_65 [ V_53 ] * V_51 ) >> 8 ;
V_56 [ 16 ] = V_52 ;
V_56 [ 17 ] = ( V_52 >> 8 ) & 0x0f ;
F_6 ( V_1 , 0x10e1 , V_56 , 21 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 gamma [ 17 ] ;
T_2 V_66 = V_18 -> V_54 [ GAMMA ] . V_17 * 0xb8 / 0x100 ;
gamma [ 0 ] = 0x0a ;
gamma [ 1 ] = 0x13 + ( V_66 * ( 0xcb - 0x13 ) / 0xb8 ) ;
gamma [ 2 ] = 0x25 + ( V_66 * ( 0xee - 0x25 ) / 0xb8 ) ;
gamma [ 3 ] = 0x37 + ( V_66 * ( 0xfa - 0x37 ) / 0xb8 ) ;
gamma [ 4 ] = 0x45 + ( V_66 * ( 0xfc - 0x45 ) / 0xb8 ) ;
gamma [ 5 ] = 0x55 + ( V_66 * ( 0xfb - 0x55 ) / 0xb8 ) ;
gamma [ 6 ] = 0x65 + ( V_66 * ( 0xfc - 0x65 ) / 0xb8 ) ;
gamma [ 7 ] = 0x74 + ( V_66 * ( 0xfd - 0x74 ) / 0xb8 ) ;
gamma [ 8 ] = 0x83 + ( V_66 * ( 0xfe - 0x83 ) / 0xb8 ) ;
gamma [ 9 ] = 0x92 + ( V_66 * ( 0xfc - 0x92 ) / 0xb8 ) ;
gamma [ 10 ] = 0xa1 + ( V_66 * ( 0xfc - 0xa1 ) / 0xb8 ) ;
gamma [ 11 ] = 0xb0 + ( V_66 * ( 0xfc - 0xb0 ) / 0xb8 ) ;
gamma [ 12 ] = 0xbf + ( V_66 * ( 0xfb - 0xbf ) / 0xb8 ) ;
gamma [ 13 ] = 0xce + ( V_66 * ( 0xfb - 0xce ) / 0xb8 ) ;
gamma [ 14 ] = 0xdf + ( V_66 * ( 0xfd - 0xdf ) / 0xb8 ) ;
gamma [ 15 ] = 0xea + ( V_66 * ( 0xf9 - 0xea ) / 0xb8 ) ;
gamma [ 16 ] = 0xf5 ;
F_6 ( V_1 , 0x1190 , gamma , 17 ) ;
}
static void F_31 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_8 ( V_1 , 0x118c , V_18 -> V_54 [ V_67 ] . V_17 ) ;
F_8 ( V_1 , 0x118f , V_18 -> V_54 [ V_68 ] . V_17 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
T_2 V_14 , V_69 , V_70 , V_71 ;
T_1 V_72 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( ( V_18 -> V_73 & V_74 ) && F_33 ( V_75 ) ) {
V_70 = ! V_18 -> V_54 [ V_32 ] . V_17 ;
V_71 = ! V_18 -> V_54 [ V_33 ] . V_17 ;
} else {
V_70 = V_18 -> V_54 [ V_32 ] . V_17 ;
V_71 = V_18 -> V_54 [ V_33 ] . V_17 ;
}
switch ( V_18 -> V_39 ) {
case V_76 :
V_14 = 0x01 ;
if ( V_70 )
V_14 |= 0x20 ;
if ( V_71 ) {
V_14 |= 0x10 ;
V_18 -> V_29 = 2 ;
} else {
V_18 -> V_29 = 3 ;
}
F_8 ( V_1 , 0x1182 , V_18 -> V_29 ) ;
F_11 ( V_1 , 0x1e , V_14 ) ;
break;
case V_77 :
F_15 ( V_1 , 0x1e , & V_14 ) ;
V_14 &= ~ 0x30 ;
V_69 = 0x01 ;
if ( V_70 )
V_14 |= 0x20 ;
if ( V_71 ) {
V_14 |= 0x10 ;
V_69 = 0x49 ;
}
F_11 ( V_1 , 0x1e , V_14 ) ;
F_11 ( V_1 , 0x3a , V_69 ) ;
break;
case V_44 :
case V_40 :
F_16 ( V_1 , 0x20 , & V_72 ) ;
V_72 &= ~ 0xc0a0 ;
if ( V_70 )
V_72 |= 0x8080 ;
if ( V_71 )
V_72 |= 0x4020 ;
F_13 ( V_1 , 0x20 , V_72 ) ;
break;
case V_78 :
case V_79 :
case V_46 :
F_16 ( V_1 , 0x20 , & V_72 ) ;
V_72 &= ~ 0x0003 ;
if ( V_70 )
V_72 |= 0x0002 ;
if ( V_71 )
V_72 |= 0x0001 ;
F_13 ( V_1 , 0x20 , V_72 ) ;
break;
case V_80 :
F_15 ( V_1 , 0x01 , & V_14 ) ;
V_14 &= ~ 0x03 ;
if ( V_71 )
V_14 |= 0x01 ;
if ( V_70 )
V_14 |= 0x02 ;
F_11 ( V_1 , 0x01 , V_14 ) ;
break;
}
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 exp [ 8 ] = { 0x81 , V_18 -> V_20 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x1e } ;
int V_81 ;
V_81 = V_18 -> V_54 [ V_35 ] . V_17 ;
switch ( V_18 -> V_39 ) {
case V_76 :
case V_82 :
case V_83 :
case V_77 :
exp [ 0 ] |= ( 3 << 4 ) ;
exp [ 2 ] = 0x2d ;
exp [ 3 ] = V_81 ;
exp [ 4 ] = V_81 >> 8 ;
break;
case V_84 :
case V_46 :
case V_40 :
exp [ 0 ] |= ( 3 << 4 ) ;
exp [ 2 ] = 0x09 ;
exp [ 3 ] = V_81 >> 8 ;
exp [ 4 ] = V_81 ;
break;
case V_80 :
exp [ 0 ] |= ( 4 << 4 ) ;
exp [ 2 ] = 0x25 ;
exp [ 3 ] = V_81 >> 5 ;
exp [ 4 ] = V_81 << 3 ;
exp [ 5 ] = 0 ;
break;
default:
return;
}
F_9 ( V_1 , exp ) ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_85 [ 8 ] = { 0x81 , V_18 -> V_20 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x1d } ;
int V_86 ;
V_86 = V_18 -> V_54 [ V_43 ] . V_17 ;
switch ( V_18 -> V_39 ) {
case V_76 :
case V_82 :
case V_87 :
case V_83 :
case V_77 :
V_85 [ 0 ] |= ( 2 << 4 ) ;
V_85 [ 3 ] = V_88 [ V_86 ] ;
break;
case V_40 :
V_85 [ 0 ] |= ( 3 << 4 ) ;
V_85 [ 2 ] = 0x35 ;
V_85 [ 3 ] = V_89 [ V_86 ] >> 8 ;
V_85 [ 4 ] = V_89 [ V_86 ] ;
break;
case V_46 :
V_85 [ 0 ] |= ( 3 << 4 ) ;
V_85 [ 2 ] = 0x2f ;
V_85 [ 3 ] = V_89 [ V_86 ] >> 8 ;
V_85 [ 4 ] = V_89 [ V_86 ] ;
break;
case V_84 :
V_85 [ 0 ] |= ( 3 << 4 ) ;
V_85 [ 2 ] = 0x2f ;
V_85 [ 3 ] = V_90 [ V_86 ] >> 8 ;
V_85 [ 4 ] = V_90 [ V_86 ] ;
break;
case V_80 :
V_85 [ 0 ] |= ( 2 << 4 ) ;
V_85 [ 2 ] = 0x30 ;
V_85 [ 3 ] = V_91 [ V_86 ] ;
break;
default:
return;
}
F_9 ( V_1 , V_85 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_37 ( V_18 -> V_92 , V_18 -> V_54 [ V_93 ] . V_17 ) ;
F_8 ( V_1 , 0x1061 , 0x01 ) ;
F_8 ( V_1 , 0x10e0 , V_18 -> V_94 | 0x20 ) ;
F_6 ( V_1 , 0x1100 , & V_18 -> V_92 [ V_95 ] , 64 ) ;
F_6 ( V_1 , 0x1140 , & V_18 -> V_92 [ V_96 ] , 64 ) ;
F_8 ( V_1 , 0x1061 , 0x03 ) ;
F_8 ( V_1 , 0x10e0 , V_18 -> V_94 ) ;
V_18 -> V_94 ^= 0x0c ;
F_8 ( V_1 , 0x10e0 , V_18 -> V_94 ) ;
}
static int F_38 ( struct V_1 * V_1 ,
struct V_97 * V_2 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_2 -> V_98 . type ) {
case V_99 :
if ( V_2 -> V_98 . V_100 != 0 )
return - V_101 ;
if ( V_2 -> V_2 < 0x1000 || V_2 -> V_2 > 0x11ff )
return - V_101 ;
F_1 ( V_1 , V_2 -> V_2 , 1 ) ;
V_2 -> V_17 = V_1 -> V_11 [ 0 ] ;
return V_1 -> V_7 ;
case V_102 :
if ( V_2 -> V_98 . V_100 != V_18 -> V_20 )
return - V_101 ;
if ( V_18 -> V_39 >= V_40 &&
V_18 -> V_39 <= V_78 ) {
F_16 ( V_1 , V_2 -> V_2 , ( T_1 * ) & V_2 -> V_17 ) ;
} else {
F_15 ( V_1 , V_2 -> V_2 , ( T_2 * ) & V_2 -> V_17 ) ;
}
return V_1 -> V_7 ;
}
return - V_101 ;
}
static int F_39 ( struct V_1 * V_1 ,
struct V_97 * V_2 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_2 -> V_98 . type ) {
case V_99 :
if ( V_2 -> V_98 . V_100 != 0 )
return - V_101 ;
if ( V_2 -> V_2 < 0x1000 || V_2 -> V_2 > 0x11ff )
return - V_101 ;
F_8 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) ;
return V_1 -> V_7 ;
case V_102 :
if ( V_2 -> V_98 . V_100 != V_18 -> V_20 )
return - V_101 ;
if ( V_18 -> V_39 >= V_40 &&
V_18 -> V_39 <= V_78 ) {
F_13 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) ;
} else {
F_11 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) ;
}
return V_1 -> V_7 ;
}
return - V_101 ;
}
static int F_40 ( struct V_1 * V_1 ,
struct V_103 * V_104 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_104 -> V_98 . type ) {
case V_99 :
if ( V_104 -> V_98 . V_100 != 0 )
return - V_101 ;
V_104 -> V_105 = 0 ;
V_104 -> V_106 = V_107 ;
return 0 ;
case V_102 :
if ( V_104 -> V_98 . V_100 != V_18 -> V_20 )
return - V_101 ;
V_104 -> V_105 = 0 ;
V_104 -> V_106 = V_108 [ V_18 -> V_39 ] ;
return 0 ;
}
return - V_101 ;
}
static int F_41 ( struct V_1 * V_1 ,
const struct V_109 * V_25 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
struct V_110 * V_110 ;
V_110 = & V_1 -> V_110 ;
V_110 -> V_111 = 1 ;
V_18 -> V_39 = V_25 -> V_112 >> 8 ;
V_18 -> V_20 = V_25 -> V_112 ;
V_18 -> V_73 = V_25 -> V_112 >> 16 ;
switch ( V_18 -> V_39 ) {
case V_78 :
case V_79 :
case V_77 :
case V_87 :
V_110 -> V_113 = V_114 ;
V_110 -> V_115 = F_18 ( V_114 ) ;
break;
case V_84 :
V_110 -> V_113 = V_116 ;
V_110 -> V_115 = F_18 ( V_116 ) ;
break;
default:
V_110 -> V_113 = V_117 ;
V_110 -> V_115 = F_18 ( V_117 ) ;
break;
}
V_18 -> V_118 = 0 ;
V_18 -> V_119 = 0 ;
V_18 -> V_120 = 16 ;
V_1 -> V_110 . V_54 = V_18 -> V_54 ;
F_42 ( & V_18 -> V_121 , V_122 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_15 ;
T_2 V_14 ;
T_2 V_123 [ 9 ] =
{ 0x80 , V_18 -> V_20 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } ;
for ( V_15 = 0 ; V_15 < F_18 ( V_124 ) ; V_15 ++ ) {
V_14 = V_124 [ V_15 ] [ 1 ] ;
F_6 ( V_1 , V_124 [ V_15 ] [ 0 ] , & V_14 , 1 ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_24 ) ;
return V_1 -> V_7 ;
}
}
if ( V_18 -> V_73 & V_125 )
F_8 ( V_1 , 0x1006 , 0x00 ) ;
else
F_8 ( V_1 , 0x1006 , 0x20 ) ;
F_6 ( V_1 , 0x10c0 , V_123 , 9 ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_24 ) ;
return V_1 -> V_7 ;
}
switch ( V_18 -> V_39 ) {
case V_77 :
F_17 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_25 ) ;
break;
case V_83 :
F_19 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_26 ) ;
break;
case V_87 :
F_20 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_27 ) ;
break;
case V_76 :
F_21 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_28 ) ;
break;
case V_82 :
F_22 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_29 ) ;
break;
case V_126 :
F_23 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_30 ) ;
break;
case V_79 :
F_26 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_31 ) ;
break;
case V_78 :
F_25 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_32 ) ;
break;
case V_84 :
F_27 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
break;
case V_80 :
F_28 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_33 ) ;
break;
default:
F_5 ( L_34 ) ;
V_1 -> V_7 = - V_26 ;
}
return V_1 -> V_7 ;
}
static void F_44 ( struct V_1 * V_1 , int V_127 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_14 ;
switch ( V_18 -> V_39 ) {
case V_87 :
if ( V_127 & V_128 ) {
F_11 ( V_1 , 0x17 , 0x1d ) ;
F_11 ( V_1 , 0x18 , 0xbd ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x81 ) ;
F_11 ( V_1 , 0x12 , 0x00 ) ;
V_18 -> V_28 = 140 ;
V_18 -> V_29 = 19 ;
} else {
F_11 ( V_1 , 0x17 , 0x13 ) ;
F_11 ( V_1 , 0x18 , 0x63 ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x79 ) ;
F_11 ( V_1 , 0x12 , 0x40 ) ;
V_18 -> V_28 = 60 ;
V_18 -> V_29 = 11 ;
}
break;
case V_77 :
if ( V_127 & V_128 ) {
F_11 ( V_1 , 0x17 , 0x1b ) ;
F_11 ( V_1 , 0x18 , 0xbc ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x82 ) ;
F_15 ( V_1 , 0x12 , & V_14 ) ;
F_11 ( V_1 , 0x12 , V_14 & 0x07 ) ;
} else {
F_11 ( V_1 , 0x17 , 0x24 ) ;
F_11 ( V_1 , 0x18 , 0xc5 ) ;
F_11 ( V_1 , 0x19 , 0x00 ) ;
F_11 ( V_1 , 0x1a , 0x3c ) ;
F_15 ( V_1 , 0x12 , & V_14 ) ;
F_11 ( V_1 , 0x12 , ( V_14 & 0x7 ) | 0x40 ) ;
}
break;
case V_78 :
case V_79 :
if ( V_127 & V_128 ) {
F_13 ( V_1 , 0xf0 , 0x0002 ) ;
F_13 ( V_1 , 0xc8 , 0x970b ) ;
F_13 ( V_1 , 0xf0 , 0x0000 ) ;
} else {
F_13 ( V_1 , 0xf0 , 0x0002 ) ;
F_13 ( V_1 , 0xc8 , 0x8000 ) ;
F_13 ( V_1 , 0xf0 , 0x0000 ) ;
}
break;
}
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_129 * V_130 ;
T_4 V_73 = V_1 -> V_110 . V_113 [ ( int ) V_1 -> V_131 ] . V_132 ;
if ( ! ( V_73 & ( V_133 | V_134 ) ) ) {
V_130 = F_46 ( V_1 -> V_5 , V_1 -> V_135 ) ;
if ( V_130 -> V_136 != 9 ) {
F_47 ( L_35
L_36 ,
V_130 -> V_136 ) ;
V_1 -> V_137 = V_130 -> V_136 ;
return 0 ;
}
switch ( V_1 -> V_138 ) {
case 160 :
V_1 -> V_137 = 2 ;
break;
case 320 :
V_1 -> V_137 = 6 ;
break;
default:
V_1 -> V_137 = 9 ;
break;
}
}
return 0 ;
}
static int F_48 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_127 = V_1 -> V_110 . V_113 [ ( int ) V_1 -> V_131 ] . V_132 ;
int V_138 = V_1 -> V_138 ;
int V_139 = V_1 -> V_139 ;
T_2 V_94 , V_140 = 0 ;
F_49 ( V_18 -> V_92 , V_139 , V_138 ,
0x21 ) ;
F_37 ( V_18 -> V_92 , V_18 -> V_54 [ V_93 ] . V_17 ) ;
if ( V_127 & V_133 )
V_94 = 0x2d ;
else if ( V_127 & V_134 )
V_94 = 0x24 ;
else
V_94 = 0x2f ;
V_18 -> V_94 = V_94 ;
switch ( V_127 & V_141 ) {
case V_142 :
V_140 = 0xc0 ;
F_24 ( L_37 ) ;
break;
case V_143 :
V_140 = 0x80 ;
F_24 ( L_38 ) ;
break;
case V_144 :
V_140 = 0x90 ;
F_24 ( L_39 ) ;
break;
case V_145 :
V_140 = 0xa0 ;
F_24 ( L_40 ) ;
break;
}
F_44 ( V_1 , V_127 ) ;
F_6 ( V_1 , 0x1100 , & V_18 -> V_92 [ V_95 ] , 64 ) ;
F_6 ( V_1 , 0x1140 , & V_18 -> V_92 [ V_96 ] , 64 ) ;
F_6 ( V_1 , 0x10fb , F_50 ( V_138 , V_139 ) , 5 ) ;
F_6 ( V_1 , 0x1180 , F_51 ( V_127 , V_18 -> V_28 , V_18 -> V_29 ) , 6 ) ;
F_8 ( V_1 , 0x1189 , V_140 ) ;
F_8 ( V_1 , 0x10e0 , V_94 ) ;
F_29 ( V_1 ) ;
F_30 ( V_1 ) ;
F_31 ( V_1 ) ;
F_35 ( V_1 ) ;
F_34 ( V_1 ) ;
F_32 ( V_1 ) ;
F_8 ( V_1 , 0x1007 , 0x20 ) ;
F_8 ( V_1 , 0x1061 , 0x03 ) ;
if ( V_127 & V_134 ) {
V_18 -> V_146 = V_18 -> V_147 = 0 ;
V_18 -> V_148 = 0 ;
V_18 -> V_149 =
F_52 ( V_150 ) ;
}
return V_1 -> V_7 ;
}
static void F_53 ( struct V_1 * V_1 )
{
F_8 ( V_1 , 0x1007 , 0x00 ) ;
F_8 ( V_1 , 0x1061 , 0x01 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( V_18 -> V_149 != NULL ) {
F_55 ( & V_1 -> V_151 ) ;
F_56 ( V_18 -> V_149 ) ;
F_57 ( & V_1 -> V_151 ) ;
V_18 -> V_149 = NULL ;
}
}
static void F_58 ( struct V_1 * V_1 , T_1 V_152 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_5 V_153 ;
if ( V_152 < V_154 ) {
if ( V_18 -> V_54 [ V_35 ] . V_17 > 0x1770 )
return;
V_153 = V_18 -> V_54 [ V_35 ] . V_17 + V_18 -> V_120 ;
if ( V_153 > 0x1770 )
V_153 = 0x1770 ;
if ( V_153 < 0x10 )
V_153 = 0x10 ;
V_18 -> V_54 [ V_35 ] . V_17 = V_153 ;
F_34 ( V_1 ) ;
V_18 -> V_119 = V_18 -> V_118 ;
V_18 -> V_118 = 1 ;
if ( V_18 -> V_118 ^ V_18 -> V_119 )
V_18 -> V_120 /= 2 ;
else
V_18 -> V_120 += 2 ;
}
if ( V_152 > V_155 ) {
if ( V_18 -> V_54 [ V_35 ] . V_17 < 0x10 )
return;
V_153 = V_18 -> V_54 [ V_35 ] . V_17 - V_18 -> V_120 ;
if ( V_153 > 0x1700 )
V_153 = 0x1770 ;
if ( V_153 < 0x10 )
V_153 = 0x10 ;
V_18 -> V_54 [ V_35 ] . V_17 = V_153 ;
F_34 ( V_1 ) ;
V_18 -> V_119 = V_18 -> V_118 ;
V_18 -> V_118 = 0 ;
if ( V_18 -> V_118 ^ V_18 -> V_119 )
V_18 -> V_120 /= 2 ;
else
V_18 -> V_120 += 2 ;
}
}
static void F_59 ( struct V_1 * V_1 , T_1 V_152 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( V_152 < V_154 ) {
if ( V_18 -> V_54 [ V_43 ] . V_17 + 1 <= 28 ) {
V_18 -> V_54 [ V_43 ] . V_17 ++ ;
F_35 ( V_1 ) ;
}
}
if ( V_152 > V_155 ) {
if ( V_18 -> V_54 [ V_43 ] . V_17 > 0 ) {
V_18 -> V_54 [ V_43 ] . V_17 -- ;
F_35 ( V_1 ) ;
}
}
}
static void F_60 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_152 ;
if ( ! V_18 -> V_54 [ V_42 ] . V_17 )
return;
V_152 = F_61 ( & V_18 -> V_152 ) ;
if ( V_18 -> V_39 == V_87 )
F_59 ( V_1 , V_152 ) ;
else
F_58 ( V_1 , V_152 ) ;
}
static void V_122 ( struct V_156 * V_121 )
{
struct V_18 * V_18 = F_62 ( V_121 , struct V_18 , V_121 ) ;
struct V_1 * V_1 = & V_18 -> V_1 ;
F_57 ( & V_1 -> V_151 ) ;
F_63 ( V_157 , L_41 , V_18 -> V_54 [ V_93 ] . V_17 ) ;
F_36 ( V_1 ) ;
F_55 ( & V_1 -> V_151 ) ;
}
static int F_64 ( struct V_1 * V_1 ,
T_2 * V_158 ,
int V_159 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( ! ( V_18 -> V_73 & V_160 ) && V_159 == 1 ) {
F_65 ( V_1 -> V_161 , V_162 , 1 ) ;
F_66 ( V_1 -> V_161 ) ;
F_65 ( V_1 -> V_161 , V_162 , 0 ) ;
F_66 ( V_1 -> V_161 ) ;
return 0 ;
}
return - V_101 ;
}
static void F_67 ( struct V_1 * V_1 ,
T_2 * V_158 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_163 , V_164 ;
V_163 = 0 ;
if ( V_158 [ 6 ] & 0x08 ) {
V_1 -> V_165 = V_166 ;
V_163 = - 5 ;
} else {
V_164 = ( V_18 -> V_146 * 100 ) /
( V_18 -> V_147 *
V_1 -> V_167 [ 0 ] -> V_168 [ 0 ] . V_3 ) ;
if ( V_164 >= 85 )
V_163 = - 3 ;
else if ( V_164 < 75 )
V_163 = 2 ;
}
if ( V_163 != 0 ) {
V_18 -> V_148 += V_163 ;
if ( V_18 -> V_148 < - 6 || V_18 -> V_148 >= 12 ) {
V_18 -> V_148 = 0 ;
V_163 += V_18 -> V_54 [ V_93 ] . V_17 ;
if ( V_163 < V_169 )
V_163 = V_169 ;
else if ( V_163 > V_170 )
V_163 = V_170 ;
if ( V_163 != V_18 -> V_54 [ V_93 ] . V_17 ) {
V_18 -> V_54 [ V_93 ] . V_17 = V_163 ;
F_68 ( V_18 -> V_149 , & V_18 -> V_121 ) ;
}
}
} else {
V_18 -> V_148 = 0 ;
}
V_18 -> V_146 = V_18 -> V_147 = 0 ;
}
static void F_69 ( struct V_1 * V_1 ,
T_2 * V_158 ,
int V_159 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_152 , V_171 ;
static T_2 V_172 [] =
{ 0xff , 0xff , 0x00 , 0xc4 , 0xc4 , 0x96 } ;
V_171 = ( V_18 -> V_94 & 0x03 ) == 0 ;
if ( V_159 >= 64 && memcmp ( V_158 , V_172 , 6 ) == 0 ) {
V_152 = ( ( V_158 [ 35 ] >> 2 ) & 3 ) |
( V_158 [ 20 ] << 2 ) |
( V_158 [ 19 ] << 10 ) ;
V_152 += ( ( V_158 [ 35 ] >> 4 ) & 3 ) |
( V_158 [ 22 ] << 2 ) |
( V_158 [ 21 ] << 10 ) ;
V_152 += ( ( V_158 [ 35 ] >> 6 ) & 3 ) |
( V_158 [ 24 ] << 2 ) |
( V_158 [ 23 ] << 10 ) ;
V_152 += ( V_158 [ 36 ] & 3 ) |
( V_158 [ 26 ] << 2 ) |
( V_158 [ 25 ] << 10 ) ;
V_152 += ( ( V_158 [ 36 ] >> 2 ) & 3 ) |
( V_158 [ 28 ] << 2 ) |
( V_158 [ 27 ] << 10 ) ;
V_152 += ( ( V_158 [ 36 ] >> 4 ) & 3 ) |
( V_158 [ 30 ] << 2 ) |
( V_158 [ 29 ] << 10 ) ;
V_152 += ( ( V_158 [ 36 ] >> 6 ) & 3 ) |
( V_158 [ 32 ] << 2 ) |
( V_158 [ 31 ] << 10 ) ;
V_152 += ( ( V_158 [ 44 ] >> 4 ) & 3 ) |
( V_158 [ 34 ] << 2 ) |
( V_158 [ 33 ] << 10 ) ;
V_152 >>= 9 ;
F_70 ( & V_18 -> V_152 , V_152 ) ;
if ( V_171 )
F_67 ( V_1 , V_158 ) ;
F_71 ( V_1 , V_173 , NULL , 0 ) ;
V_159 -= 64 ;
if ( V_159 == 0 )
return;
V_158 += 64 ;
}
if ( V_1 -> V_165 == V_173 ) {
if ( V_171 ) {
F_71 ( V_1 , V_174 ,
V_18 -> V_92 , V_175 ) ;
F_71 ( V_1 , V_176 ,
V_158 , V_159 ) ;
} else {
F_71 ( V_1 , V_174 ,
V_158 , V_159 ) ;
}
} else {
if ( V_171 ) {
V_18 -> V_147 ++ ;
V_18 -> V_146 += V_159 ;
}
F_71 ( V_1 , V_176 , V_158 , V_159 ) ;
}
}
static int F_72 ( struct V_129 * V_130 ,
const struct V_109 * V_25 )
{
return F_73 ( V_130 , V_25 , & V_177 , sizeof( struct V_18 ) ,
V_178 ) ;
}
