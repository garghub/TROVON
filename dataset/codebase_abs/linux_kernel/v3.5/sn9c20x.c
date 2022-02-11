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
V_19 [ 0 ] = V_18 -> V_20 | ( 2 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_21 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = V_17 ;
V_19 [ 4 ] = 0x00 ;
V_19 [ 5 ] = 0x00 ;
V_19 [ 6 ] = 0x00 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
const struct V_22 * V_23 , int V_24 )
{
while ( -- V_24 >= 0 ) {
F_11 ( V_1 , V_23 -> V_2 , V_23 -> V_17 ) ;
V_23 ++ ;
}
}
static void F_13 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = V_18 -> V_20 | ( 3 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_21 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = V_17 >> 8 ;
V_19 [ 4 ] = V_17 ;
V_19 [ 5 ] = 0x00 ;
V_19 [ 6 ] = 0x00 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
}
static void F_14 ( struct V_1 * V_1 ,
const struct V_25 * V_23 , int V_24 )
{
while ( -- V_24 >= 0 ) {
F_13 ( V_1 , V_23 -> V_2 , V_23 -> V_17 ) ;
V_23 ++ ;
}
}
static void F_15 ( struct V_1 * V_1 , T_2 V_2 , T_2 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = V_18 -> V_20 | ( 1 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_21 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = 0 ;
V_19 [ 4 ] = 0 ;
V_19 [ 5 ] = 0 ;
V_19 [ 6 ] = 0 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
V_19 [ 0 ] = V_18 -> V_20 | ( 1 << 4 ) | 0x02 ;
V_19 [ 2 ] = 0 ;
F_9 ( V_1 , V_19 ) ;
F_1 ( V_1 , 0x10c2 , 5 ) ;
* V_17 = V_1 -> V_11 [ 4 ] ;
}
static void F_16 ( struct V_1 * V_1 , T_2 V_2 , T_1 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = V_18 -> V_20 | ( 1 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_21 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = 0 ;
V_19 [ 4 ] = 0 ;
V_19 [ 5 ] = 0 ;
V_19 [ 6 ] = 0 ;
V_19 [ 7 ] = 0x10 ;
F_9 ( V_1 , V_19 ) ;
V_19 [ 0 ] = V_18 -> V_20 | ( 2 << 4 ) | 0x02 ;
V_19 [ 2 ] = 0 ;
F_9 ( V_1 , V_19 ) ;
F_1 ( V_1 , 0x10c2 , 5 ) ;
* V_17 = ( V_1 -> V_11 [ 3 ] << 8 ) | V_1 -> V_11 [ 4 ] ;
}
static void F_17 ( struct V_1 * V_1 )
{
T_1 V_26 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_16 ( V_1 , 0x1c , & V_26 ) ;
if ( V_1 -> V_7 < 0 )
return;
if ( V_26 != 0x7fa2 ) {
F_5 ( L_5 , V_26 ) ;
V_1 -> V_7 = - V_27 ;
return;
}
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_28 , F_18 ( V_28 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_6 ) ;
V_18 -> V_29 = 1 ;
V_18 -> V_30 = 7 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_31 , F_18 ( V_31 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_7 ) ;
V_18 -> V_29 = 1 ;
V_18 -> V_30 = 2 ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_32 , F_18 ( V_32 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_8 ) ;
V_18 -> V_29 = 60 ;
V_18 -> V_30 = 11 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_33 , F_18 ( V_33 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_9 ) ;
V_18 -> V_29 = 3 ;
V_18 -> V_30 = 3 ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_11 ( V_1 , 0x12 , 0x80 ) ;
F_10 ( 200 ) ;
F_12 ( V_1 , V_34 , F_18 ( V_34 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_10 ) ;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = 1 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_1 V_14 ;
V_18 -> V_21 = 0x5d ;
F_16 ( V_1 , 0xff , & V_14 ) ;
if ( V_1 -> V_7 >= 0
&& V_14 == 0x8243 ) {
F_14 ( V_1 , V_35 , F_18 ( V_35 ) ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_11 ) ;
return;
}
V_18 -> V_29 = 2 ;
V_18 -> V_30 = 2 ;
V_18 -> V_36 = V_37 ;
F_24 ( L_12 ) ;
return;
}
V_1 -> V_7 = 0 ;
V_18 -> V_21 = 0x5c ;
F_13 ( V_1 , 0x01 , 0x0004 ) ;
F_16 ( V_1 , 0xff , & V_14 ) ;
if ( V_1 -> V_7 >= 0
&& V_14 == 0x823a ) {
F_14 ( V_1 , V_38 , F_18 ( V_38 ) ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_13 ) ;
return;
}
V_18 -> V_29 = 2 ;
V_18 -> V_30 = 2 ;
V_18 -> V_36 = V_39 ;
F_24 ( L_14 ) ;
return;
}
V_1 -> V_7 = 0 ;
V_18 -> V_21 = 0x5d ;
F_13 ( V_1 , 0xf0 , 0x0000 ) ;
if ( V_1 -> V_7 < 0 ) {
V_1 -> V_7 = 0 ;
V_18 -> V_21 = 0x48 ;
F_13 ( V_1 , 0xf0 , 0x0000 ) ;
}
F_16 ( V_1 , 0x00 , & V_14 ) ;
if ( V_1 -> V_7 >= 0
&& V_14 == 0x1229 ) {
F_14 ( V_1 , V_40 , F_18 ( V_40 ) ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_15 ) ;
return;
}
V_18 -> V_29 = 6 ;
V_18 -> V_30 = 2 ;
V_18 -> V_36 = V_41 ;
F_24 ( L_16 ) ;
return;
}
V_1 -> V_7 = - V_27 ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_14 ( V_1 , V_42 , F_18 ( V_42 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_17 ) ;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = 2 ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_14 ( V_1 , V_43 , F_18 ( V_43 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_18 ) ;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = 2 ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_1 V_26 ;
F_16 ( V_1 , 0x00 , & V_26 ) ;
if ( V_1 -> V_7 < 0 )
return;
switch ( V_26 ) {
case 0x8411 :
case 0x8421 :
F_24 ( L_19 ) ;
break;
case 0x8431 :
F_24 ( L_20 ) ;
break;
default:
F_5 ( L_21 , V_26 ) ;
V_1 -> V_7 = - V_27 ;
return;
}
F_14 ( V_1 , V_44 , F_18 ( V_44 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_22 ) ;
V_18 -> V_29 = 1 ;
V_18 -> V_30 = 1 ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_12 ( V_1 , V_45 , F_18 ( V_45 ) ) ;
if ( V_1 -> V_7 < 0 )
F_5 ( L_23 ) ;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = 1 ;
}
static void F_29 ( struct V_1 * V_1 ,
T_3 V_46 , T_3 V_47 , T_3 V_48 , T_3 V_49 )
{
T_3 V_50 , V_51 = 180 + V_49 ;
T_2 V_52 [ 21 ] ;
memset ( V_52 , 0 , sizeof V_52 ) ;
V_52 [ 2 ] = ( V_47 * 0x25 / 0x100 ) + 0x26 ;
V_52 [ 0 ] = 0x13 + ( V_52 [ 2 ] - 0x26 ) * 0x13 / 0x25 ;
V_52 [ 4 ] = 0x07 + ( V_52 [ 2 ] - 0x26 ) * 0x07 / 0x25 ;
V_52 [ 18 ] = V_46 - 0x80 ;
V_50 = ( V_53 [ V_51 ] * V_48 ) >> 8 ;
V_52 [ 6 ] = V_50 ;
V_52 [ 7 ] = ( V_50 >> 8 ) & 0x0f ;
V_50 = ( V_54 [ V_51 ] * V_48 ) >> 8 ;
V_52 [ 8 ] = V_50 ;
V_52 [ 9 ] = ( V_50 >> 8 ) & 0x0f ;
V_50 = ( V_55 [ V_51 ] * V_48 ) >> 8 ;
V_52 [ 10 ] = V_50 ;
V_52 [ 11 ] = ( V_50 >> 8 ) & 0x0f ;
V_50 = ( V_56 [ V_51 ] * V_48 ) >> 8 ;
V_52 [ 12 ] = V_50 ;
V_52 [ 13 ] = ( V_50 >> 8 ) & 0x0f ;
V_50 = ( V_57 [ V_51 ] * V_48 ) >> 8 ;
V_52 [ 14 ] = V_50 ;
V_52 [ 15 ] = ( V_50 >> 8 ) & 0x0f ;
V_50 = ( V_58 [ V_51 ] * V_48 ) >> 8 ;
V_52 [ 16 ] = V_50 ;
V_52 [ 17 ] = ( V_50 >> 8 ) & 0x0f ;
F_6 ( V_1 , 0x10e1 , V_52 , 21 ) ;
}
static void F_30 ( struct V_1 * V_1 , T_3 V_17 )
{
T_2 gamma [ 17 ] ;
T_2 V_59 = V_17 * 0xb8 / 0x100 ;
gamma [ 0 ] = 0x0a ;
gamma [ 1 ] = 0x13 + ( V_59 * ( 0xcb - 0x13 ) / 0xb8 ) ;
gamma [ 2 ] = 0x25 + ( V_59 * ( 0xee - 0x25 ) / 0xb8 ) ;
gamma [ 3 ] = 0x37 + ( V_59 * ( 0xfa - 0x37 ) / 0xb8 ) ;
gamma [ 4 ] = 0x45 + ( V_59 * ( 0xfc - 0x45 ) / 0xb8 ) ;
gamma [ 5 ] = 0x55 + ( V_59 * ( 0xfb - 0x55 ) / 0xb8 ) ;
gamma [ 6 ] = 0x65 + ( V_59 * ( 0xfc - 0x65 ) / 0xb8 ) ;
gamma [ 7 ] = 0x74 + ( V_59 * ( 0xfd - 0x74 ) / 0xb8 ) ;
gamma [ 8 ] = 0x83 + ( V_59 * ( 0xfe - 0x83 ) / 0xb8 ) ;
gamma [ 9 ] = 0x92 + ( V_59 * ( 0xfc - 0x92 ) / 0xb8 ) ;
gamma [ 10 ] = 0xa1 + ( V_59 * ( 0xfc - 0xa1 ) / 0xb8 ) ;
gamma [ 11 ] = 0xb0 + ( V_59 * ( 0xfc - 0xb0 ) / 0xb8 ) ;
gamma [ 12 ] = 0xbf + ( V_59 * ( 0xfb - 0xbf ) / 0xb8 ) ;
gamma [ 13 ] = 0xce + ( V_59 * ( 0xfb - 0xce ) / 0xb8 ) ;
gamma [ 14 ] = 0xdf + ( V_59 * ( 0xfd - 0xdf ) / 0xb8 ) ;
gamma [ 15 ] = 0xea + ( V_59 * ( 0xf9 - 0xea ) / 0xb8 ) ;
gamma [ 16 ] = 0xf5 ;
F_6 ( V_1 , 0x1190 , gamma , 17 ) ;
}
static void F_31 ( struct V_1 * V_1 , T_3 V_60 , T_3 V_61 )
{
F_8 ( V_1 , 0x118c , V_61 ) ;
F_8 ( V_1 , 0x118f , V_60 ) ;
}
static void F_32 ( struct V_1 * V_1 , T_3 V_62 , T_3 V_63 )
{
T_2 V_14 , V_64 ;
T_1 V_65 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( ( V_18 -> V_66 & V_67 ) && F_33 ( V_68 ) ) {
V_62 = ! V_62 ;
V_63 = ! V_63 ;
}
switch ( V_18 -> V_36 ) {
case V_69 :
V_14 = 0x01 ;
if ( V_62 )
V_14 |= 0x20 ;
if ( V_63 ) {
V_14 |= 0x10 ;
V_18 -> V_30 = 2 ;
} else {
V_18 -> V_30 = 3 ;
}
F_8 ( V_1 , 0x1182 , V_18 -> V_30 ) ;
F_11 ( V_1 , 0x1e , V_14 ) ;
break;
case V_70 :
F_15 ( V_1 , 0x1e , & V_14 ) ;
V_14 &= ~ 0x30 ;
V_64 = 0x01 ;
if ( V_62 )
V_14 |= 0x20 ;
if ( V_63 ) {
V_14 |= 0x10 ;
V_64 = 0x49 ;
}
F_11 ( V_1 , 0x1e , V_14 ) ;
F_11 ( V_1 , 0x3a , V_64 ) ;
break;
case V_39 :
case V_37 :
F_16 ( V_1 , 0x20 , & V_65 ) ;
V_65 &= ~ 0xc0a0 ;
if ( V_62 )
V_65 |= 0x8080 ;
if ( V_63 )
V_65 |= 0x4020 ;
F_13 ( V_1 , 0x20 , V_65 ) ;
break;
case V_71 :
case V_72 :
case V_41 :
F_16 ( V_1 , 0x20 , & V_65 ) ;
V_65 &= ~ 0x0003 ;
if ( V_62 )
V_65 |= 0x0002 ;
if ( V_63 )
V_65 |= 0x0001 ;
F_13 ( V_1 , 0x20 , V_65 ) ;
break;
case V_73 :
F_15 ( V_1 , 0x01 , & V_14 ) ;
V_14 &= ~ 0x03 ;
if ( V_63 )
V_14 |= 0x01 ;
if ( V_62 )
V_14 |= 0x02 ;
F_11 ( V_1 , 0x01 , V_14 ) ;
break;
}
}
static void F_34 ( struct V_1 * V_1 , T_3 V_74 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 exp [ 8 ] = { V_18 -> V_20 , V_18 -> V_21 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
int V_75 ;
if ( V_1 -> V_76 )
exp [ 7 ] = 0x1e ;
switch ( V_18 -> V_36 ) {
case V_69 :
case V_77 :
case V_78 :
case V_70 :
if ( V_74 > 547 )
V_75 = 547 ;
else
V_75 = V_74 ;
exp [ 0 ] |= ( 2 << 4 ) ;
exp [ 2 ] = 0x10 ;
exp [ 3 ] = V_75 >> 2 ;
exp [ 7 ] = 0x10 ;
F_9 ( V_1 , exp ) ;
exp [ 2 ] = 0x04 ;
exp [ 3 ] = V_75 & 0x0003 ;
exp [ 7 ] = 0x10 ;
F_9 ( V_1 , exp ) ;
V_74 -= V_75 ;
exp [ 7 ] = 0x1e ;
exp [ 0 ] |= ( 3 << 4 ) ;
exp [ 2 ] = 0x2d ;
exp [ 3 ] = V_74 ;
exp [ 4 ] = V_74 >> 8 ;
break;
case V_79 :
case V_41 :
case V_37 :
exp [ 0 ] |= ( 3 << 4 ) ;
exp [ 2 ] = 0x09 ;
exp [ 3 ] = V_74 >> 8 ;
exp [ 4 ] = V_74 ;
break;
case V_73 :
exp [ 0 ] |= ( 4 << 4 ) ;
exp [ 2 ] = 0x25 ;
exp [ 3 ] = V_74 >> 5 ;
exp [ 4 ] = V_74 << 3 ;
exp [ 5 ] = 0 ;
break;
default:
return;
}
F_9 ( V_1 , exp ) ;
}
static void F_35 ( struct V_1 * V_1 , T_3 V_80 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_81 [ 8 ] = { V_18 -> V_20 , V_18 -> V_21 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
if ( V_1 -> V_76 )
V_81 [ 7 ] = 0x15 ;
switch ( V_18 -> V_36 ) {
case V_69 :
case V_77 :
case V_82 :
case V_78 :
case V_70 :
V_81 [ 0 ] |= ( 2 << 4 ) ;
V_81 [ 3 ] = V_83 [ V_80 ] ;
break;
case V_37 :
V_81 [ 0 ] |= ( 3 << 4 ) ;
V_81 [ 2 ] = 0x35 ;
V_81 [ 3 ] = V_84 [ V_80 ] >> 8 ;
V_81 [ 4 ] = V_84 [ V_80 ] ;
break;
case V_41 :
V_81 [ 0 ] |= ( 3 << 4 ) ;
V_81 [ 2 ] = 0x2f ;
V_81 [ 3 ] = V_84 [ V_80 ] >> 8 ;
V_81 [ 4 ] = V_84 [ V_80 ] ;
break;
case V_79 :
V_81 [ 0 ] |= ( 3 << 4 ) ;
V_81 [ 2 ] = 0x2f ;
V_81 [ 3 ] = V_85 [ V_80 ] >> 8 ;
V_81 [ 4 ] = V_85 [ V_80 ] ;
break;
case V_73 :
V_81 [ 0 ] |= ( 2 << 4 ) ;
V_81 [ 2 ] = 0x30 ;
V_81 [ 3 ] = V_86 [ V_80 ] ;
break;
default:
return;
}
F_9 ( V_1 , V_81 ) ;
}
static void F_36 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_37 ( V_18 -> V_87 , V_17 ) ;
F_8 ( V_1 , 0x1061 , 0x01 ) ;
F_8 ( V_1 , 0x10e0 , V_18 -> V_88 | 0x20 ) ;
F_6 ( V_1 , 0x1100 , & V_18 -> V_87 [ V_89 ] , 64 ) ;
F_6 ( V_1 , 0x1140 , & V_18 -> V_87 [ V_90 ] , 64 ) ;
F_8 ( V_1 , 0x1061 , 0x03 ) ;
F_8 ( V_1 , 0x10e0 , V_18 -> V_88 ) ;
V_18 -> V_88 ^= 0x0c ;
F_8 ( V_1 , 0x10e0 , V_18 -> V_88 ) ;
}
static int F_38 ( struct V_1 * V_1 ,
struct V_91 * V_2 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_2 -> V_92 . type ) {
case V_93 :
if ( V_2 -> V_92 . V_94 != 0 )
return - V_95 ;
if ( V_2 -> V_2 < 0x1000 || V_2 -> V_2 > 0x11ff )
return - V_95 ;
F_1 ( V_1 , V_2 -> V_2 , 1 ) ;
V_2 -> V_17 = V_1 -> V_11 [ 0 ] ;
return V_1 -> V_7 ;
case V_96 :
if ( V_2 -> V_92 . V_94 != V_18 -> V_21 )
return - V_95 ;
if ( V_18 -> V_36 >= V_37 &&
V_18 -> V_36 <= V_71 ) {
F_16 ( V_1 , V_2 -> V_2 , ( T_1 * ) & V_2 -> V_17 ) ;
} else {
F_15 ( V_1 , V_2 -> V_2 , ( T_2 * ) & V_2 -> V_17 ) ;
}
return V_1 -> V_7 ;
}
return - V_95 ;
}
static int F_39 ( struct V_1 * V_1 ,
struct V_91 * V_2 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_2 -> V_92 . type ) {
case V_93 :
if ( V_2 -> V_92 . V_94 != 0 )
return - V_95 ;
if ( V_2 -> V_2 < 0x1000 || V_2 -> V_2 > 0x11ff )
return - V_95 ;
F_8 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) ;
return V_1 -> V_7 ;
case V_96 :
if ( V_2 -> V_92 . V_94 != V_18 -> V_21 )
return - V_95 ;
if ( V_18 -> V_36 >= V_37 &&
V_18 -> V_36 <= V_71 ) {
F_13 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) ;
} else {
F_11 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) ;
}
return V_1 -> V_7 ;
}
return - V_95 ;
}
static int F_40 ( struct V_1 * V_1 ,
struct V_97 * V_98 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_98 -> V_92 . type ) {
case V_93 :
if ( V_98 -> V_92 . V_94 != 0 )
return - V_95 ;
V_98 -> V_99 = 0 ;
V_98 -> V_100 = V_101 ;
return 0 ;
case V_96 :
if ( V_98 -> V_92 . V_94 != V_18 -> V_21 )
return - V_95 ;
V_98 -> V_99 = 0 ;
V_98 -> V_100 = V_102 [ V_18 -> V_36 ] ;
return 0 ;
}
return - V_95 ;
}
static int F_41 ( struct V_1 * V_1 ,
const struct V_103 * V_26 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
struct V_104 * V_104 ;
V_104 = & V_1 -> V_104 ;
V_104 -> V_105 = 1 ;
V_18 -> V_36 = V_26 -> V_106 >> 8 ;
V_18 -> V_21 = V_26 -> V_106 ;
V_18 -> V_66 = V_26 -> V_106 >> 16 ;
V_18 -> V_20 = 0x80 ;
switch ( V_18 -> V_36 ) {
case V_71 :
case V_72 :
case V_70 :
case V_82 :
V_104 -> V_107 = V_108 ;
V_104 -> V_109 = F_18 ( V_108 ) ;
break;
case V_79 :
V_104 -> V_107 = V_110 ;
V_104 -> V_109 = F_18 ( V_110 ) ;
break;
case V_73 :
V_18 -> V_20 = 0x81 ;
default:
V_104 -> V_107 = V_111 ;
V_104 -> V_109 = F_18 ( V_111 ) ;
break;
}
V_18 -> V_112 = 0 ;
V_18 -> V_113 = 0 ;
V_18 -> V_114 = 16 ;
F_42 ( & V_18 -> V_115 , V_116 ) ;
return 0 ;
}
static int F_43 ( struct V_117 * V_118 )
{
struct V_1 * V_1 =
F_44 ( V_118 -> V_119 , struct V_1 , V_120 ) ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_1 -> V_7 = 0 ;
if ( ! V_1 -> V_76 )
return 0 ;
switch ( V_118 -> V_26 ) {
case V_121 :
F_29 ( V_1 , V_18 -> V_46 -> V_17 ,
V_18 -> V_47 -> V_17 , V_18 -> V_122 -> V_17 , V_18 -> V_49 -> V_17 ) ;
break;
case V_123 :
F_30 ( V_1 , V_118 -> V_17 ) ;
break;
case V_124 :
F_31 ( V_1 , V_18 -> V_60 -> V_17 , V_18 -> V_61 -> V_17 ) ;
break;
case V_125 :
F_32 ( V_1 , V_18 -> V_62 -> V_17 , V_18 -> V_63 -> V_17 ) ;
break;
case V_126 :
F_34 ( V_1 , V_118 -> V_17 ) ;
break;
case V_127 :
F_35 ( V_1 , V_118 -> V_17 ) ;
break;
case V_128 :
if ( V_18 -> V_36 == V_82 )
F_35 ( V_1 , V_18 -> V_81 -> V_17 ) ;
else
F_34 ( V_1 , V_18 -> V_129 -> V_17 ) ;
break;
case V_130 :
F_36 ( V_1 , V_118 -> V_17 ) ;
break;
}
return V_1 -> V_7 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
struct V_131 * V_132 = & V_1 -> V_120 ;
V_1 -> V_133 . V_120 = V_132 ;
F_46 ( V_132 , 13 ) ;
V_18 -> V_46 = F_47 ( V_132 , & V_134 ,
V_121 , 0 , 255 , 1 , 127 ) ;
V_18 -> V_47 = F_47 ( V_132 , & V_134 ,
V_135 , 0 , 255 , 1 , 127 ) ;
V_18 -> V_122 = F_47 ( V_132 , & V_134 ,
V_136 , 0 , 255 , 1 , 127 ) ;
V_18 -> V_49 = F_47 ( V_132 , & V_134 ,
V_137 , - 180 , 180 , 1 , 0 ) ;
V_18 -> gamma = F_47 ( V_132 , & V_134 ,
V_123 , 0 , 255 , 1 , 0x10 ) ;
V_18 -> V_60 = F_47 ( V_132 , & V_134 ,
V_124 , 0 , 127 , 1 , 0x28 ) ;
V_18 -> V_61 = F_47 ( V_132 , & V_134 ,
V_138 , 0 , 127 , 1 , 0x28 ) ;
if ( V_18 -> V_36 != V_78 && V_18 -> V_36 != V_82 &&
V_18 -> V_36 != V_77 && V_18 -> V_36 != V_79 &&
V_18 -> V_36 != V_139 ) {
V_18 -> V_62 = F_47 ( V_132 , & V_134 ,
V_125 , 0 , 1 , 1 , 0 ) ;
V_18 -> V_63 = F_47 ( V_132 , & V_134 ,
V_140 , 0 , 1 , 1 , 0 ) ;
}
if ( V_18 -> V_36 != V_82 && V_18 -> V_36 != V_139 &&
V_18 -> V_36 != V_71 && V_18 -> V_36 != V_72 &&
V_18 -> V_36 != V_39 )
V_18 -> V_129 = F_47 ( V_132 , & V_134 ,
V_126 , 0 , 0x1780 , 1 , 0x33 ) ;
if ( V_18 -> V_36 != V_139 && V_18 -> V_36 != V_71 &&
V_18 -> V_36 != V_72 && V_18 -> V_36 != V_39 ) {
V_18 -> V_81 = F_47 ( V_132 , & V_134 ,
V_127 , 0 , 28 , 1 , 0 ) ;
V_18 -> V_141 = F_47 ( V_132 , & V_134 ,
V_128 , 0 , 1 , 1 , 1 ) ;
}
V_18 -> V_142 = F_47 ( V_132 , & V_134 ,
V_130 , 50 , 90 , 1 , 80 ) ;
if ( V_132 -> error ) {
F_5 ( L_24 ) ;
return V_132 -> error ;
}
F_48 ( 4 , & V_18 -> V_46 ) ;
F_48 ( 2 , & V_18 -> V_60 ) ;
if ( V_18 -> V_62 )
F_48 ( 2 , & V_18 -> V_62 ) ;
if ( V_18 -> V_141 ) {
if ( V_18 -> V_36 == V_82 )
F_49 ( 3 , & V_18 -> V_141 , 0 , false ) ;
else
F_49 ( 2 , & V_18 -> V_141 , 0 , false ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_15 ;
T_2 V_14 ;
T_2 V_143 [ 9 ] =
{ 0x80 , V_18 -> V_21 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } ;
for ( V_15 = 0 ; V_15 < F_18 ( V_144 ) ; V_15 ++ ) {
V_14 = V_144 [ V_15 ] [ 1 ] ;
F_6 ( V_1 , V_144 [ V_15 ] [ 0 ] , & V_14 , 1 ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_25 ) ;
return V_1 -> V_7 ;
}
}
if ( V_18 -> V_66 & V_145 )
F_8 ( V_1 , 0x1006 , 0x00 ) ;
else
F_8 ( V_1 , 0x1006 , 0x20 ) ;
F_6 ( V_1 , 0x10c0 , V_143 , 9 ) ;
if ( V_1 -> V_7 < 0 ) {
F_5 ( L_25 ) ;
return V_1 -> V_7 ;
}
switch ( V_18 -> V_36 ) {
case V_70 :
F_17 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_26 ) ;
break;
case V_78 :
F_19 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_27 ) ;
break;
case V_82 :
F_20 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_28 ) ;
break;
case V_69 :
F_21 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_29 ) ;
break;
case V_77 :
F_22 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_30 ) ;
break;
case V_139 :
F_23 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_31 ) ;
break;
case V_72 :
F_26 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_32 ) ;
break;
case V_71 :
F_25 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_33 ) ;
break;
case V_79 :
F_27 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
break;
case V_73 :
F_28 ( V_1 ) ;
if ( V_1 -> V_7 < 0 )
break;
F_24 ( L_34 ) ;
break;
default:
F_5 ( L_35 ) ;
V_1 -> V_7 = - V_27 ;
}
return V_1 -> V_7 ;
}
static void F_51 ( struct V_1 * V_1 , int V_146 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_14 ;
switch ( V_18 -> V_36 ) {
case V_82 :
if ( V_146 & V_147 ) {
F_11 ( V_1 , 0x17 , 0x1d ) ;
F_11 ( V_1 , 0x18 , 0xbd ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x81 ) ;
F_11 ( V_1 , 0x12 , 0x00 ) ;
V_18 -> V_29 = 140 ;
V_18 -> V_30 = 19 ;
} else {
F_11 ( V_1 , 0x17 , 0x13 ) ;
F_11 ( V_1 , 0x18 , 0x63 ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x79 ) ;
F_11 ( V_1 , 0x12 , 0x40 ) ;
V_18 -> V_29 = 60 ;
V_18 -> V_30 = 11 ;
}
break;
case V_70 :
if ( V_146 & V_147 ) {
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
case V_71 :
case V_72 :
if ( V_146 & V_147 ) {
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
static int F_52 ( struct V_1 * V_1 )
{
struct V_148 * V_149 ;
T_4 V_66 = V_1 -> V_104 . V_107 [ ( int ) V_1 -> V_150 ] . V_151 ;
if ( ! ( V_66 & ( V_152 | V_153 ) ) ) {
V_149 = F_53 ( V_1 -> V_5 , V_1 -> V_154 ) ;
if ( V_149 -> V_155 != 9 ) {
F_54 ( L_36
L_37 ,
V_149 -> V_155 ) ;
V_1 -> V_156 = V_149 -> V_155 ;
return 0 ;
}
switch ( V_1 -> V_157 ) {
case 160 :
V_1 -> V_156 = 2 ;
break;
case 320 :
V_1 -> V_156 = 6 ;
break;
default:
V_1 -> V_156 = 9 ;
break;
}
}
return 0 ;
}
static int F_55 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_146 = V_1 -> V_104 . V_107 [ ( int ) V_1 -> V_150 ] . V_151 ;
int V_157 = V_1 -> V_157 ;
int V_158 = V_1 -> V_158 ;
T_2 V_88 , V_159 = 0 ;
F_56 ( V_18 -> V_87 , V_158 , V_157 ,
0x21 ) ;
F_37 ( V_18 -> V_87 , F_57 ( V_18 -> V_142 ) ) ;
if ( V_146 & V_152 )
V_88 = 0x2d ;
else if ( V_146 & V_153 )
V_88 = 0x24 ;
else
V_88 = 0x2f ;
V_18 -> V_88 = V_88 ;
switch ( V_146 & V_160 ) {
case V_161 :
V_159 = 0xc0 ;
F_24 ( L_38 ) ;
break;
case V_162 :
V_159 = 0x80 ;
F_24 ( L_39 ) ;
break;
case V_163 :
V_159 = 0x90 ;
F_24 ( L_40 ) ;
break;
case V_164 :
V_159 = 0xa0 ;
F_24 ( L_41 ) ;
break;
}
F_51 ( V_1 , V_146 ) ;
F_6 ( V_1 , 0x1100 , & V_18 -> V_87 [ V_89 ] , 64 ) ;
F_6 ( V_1 , 0x1140 , & V_18 -> V_87 [ V_90 ] , 64 ) ;
F_6 ( V_1 , 0x10fb , F_58 ( V_157 , V_158 ) , 5 ) ;
F_6 ( V_1 , 0x1180 , F_59 ( V_146 , V_18 -> V_29 , V_18 -> V_30 ) , 6 ) ;
F_8 ( V_1 , 0x1189 , V_159 ) ;
F_8 ( V_1 , 0x10e0 , V_88 ) ;
F_29 ( V_1 , F_57 ( V_18 -> V_46 ) ,
F_57 ( V_18 -> V_47 ) ,
F_57 ( V_18 -> V_122 ) ,
F_57 ( V_18 -> V_49 ) ) ;
F_30 ( V_1 , F_57 ( V_18 -> gamma ) ) ;
F_31 ( V_1 , F_57 ( V_18 -> V_60 ) ,
F_57 ( V_18 -> V_61 ) ) ;
if ( V_18 -> V_81 )
F_35 ( V_1 , F_57 ( V_18 -> V_81 ) ) ;
if ( V_18 -> V_129 )
F_34 ( V_1 , F_57 ( V_18 -> V_129 ) ) ;
if ( V_18 -> V_62 )
F_32 ( V_1 , F_57 ( V_18 -> V_62 ) ,
F_57 ( V_18 -> V_63 ) ) ;
F_8 ( V_1 , 0x1007 , 0x20 ) ;
F_8 ( V_1 , 0x1061 , 0x03 ) ;
if ( V_146 & V_153 ) {
V_18 -> V_165 = V_18 -> V_166 = 0 ;
V_18 -> V_167 = 0 ;
V_18 -> V_168 =
F_60 ( V_169 ) ;
}
return V_1 -> V_7 ;
}
static void F_61 ( struct V_1 * V_1 )
{
F_8 ( V_1 , 0x1007 , 0x00 ) ;
F_8 ( V_1 , 0x1061 , 0x01 ) ;
}
static void F_62 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( V_18 -> V_168 != NULL ) {
F_63 ( & V_1 -> V_170 ) ;
F_64 ( V_18 -> V_168 ) ;
F_65 ( & V_1 -> V_170 ) ;
V_18 -> V_168 = NULL ;
}
}
static void F_66 ( struct V_1 * V_1 , T_1 V_171 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_3 V_172 = F_57 ( V_18 -> V_129 ) ;
T_3 V_173 = V_18 -> V_129 -> V_174 - V_18 -> V_114 ;
T_3 V_175 = V_18 -> V_129 -> V_176 + V_18 -> V_114 ;
T_5 V_177 ;
if ( V_171 < V_178 ) {
if ( V_172 > V_173 )
return;
V_177 = V_172 + V_18 -> V_114 ;
if ( V_177 > V_173 )
V_177 = V_173 ;
if ( V_177 < V_175 )
V_177 = V_175 ;
F_67 ( V_18 -> V_129 , V_177 ) ;
V_18 -> V_113 = V_18 -> V_112 ;
V_18 -> V_112 = 1 ;
if ( V_18 -> V_112 ^ V_18 -> V_113 )
V_18 -> V_114 /= 2 ;
else
V_18 -> V_114 += 2 ;
}
if ( V_171 > V_179 ) {
if ( V_172 < V_175 )
return;
V_177 = V_172 - V_18 -> V_114 ;
if ( V_177 > V_173 )
V_177 = V_173 ;
if ( V_177 < V_175 )
V_177 = V_175 ;
F_67 ( V_18 -> V_129 , V_177 ) ;
V_18 -> V_113 = V_18 -> V_112 ;
V_18 -> V_112 = 0 ;
if ( V_18 -> V_112 ^ V_18 -> V_113 )
V_18 -> V_114 /= 2 ;
else
V_18 -> V_114 += 2 ;
}
}
static void F_68 ( struct V_1 * V_1 , T_1 V_171 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_3 V_180 = F_57 ( V_18 -> V_81 ) ;
if ( V_171 < V_178 && V_180 < V_18 -> V_81 -> V_174 )
F_67 ( V_18 -> V_81 , V_180 + 1 ) ;
if ( V_171 > V_179 && V_180 > V_18 -> V_81 -> V_176 )
F_67 ( V_18 -> V_81 , V_180 - 1 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_171 ;
if ( V_18 -> V_141 == NULL || ! F_57 ( V_18 -> V_141 ) )
return;
V_171 = F_70 ( & V_18 -> V_171 ) ;
if ( V_18 -> V_36 == V_82 )
F_68 ( V_1 , V_171 ) ;
else
F_66 ( V_1 , V_171 ) ;
}
static void V_116 ( struct V_181 * V_115 )
{
struct V_18 * V_18 = F_44 ( V_115 , struct V_18 , V_115 ) ;
struct V_1 * V_1 = & V_18 -> V_1 ;
T_3 V_182 = F_57 ( V_18 -> V_142 ) ;
F_65 ( & V_1 -> V_170 ) ;
F_71 ( V_183 , L_42 , V_182 ) ;
F_36 ( V_1 , V_182 ) ;
F_63 ( & V_1 -> V_170 ) ;
}
static int F_72 ( struct V_1 * V_1 ,
T_2 * V_184 ,
int V_185 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( ! ( V_18 -> V_66 & V_186 ) && V_185 == 1 ) {
F_73 ( V_1 -> V_187 , V_188 , 1 ) ;
F_74 ( V_1 -> V_187 ) ;
F_73 ( V_1 -> V_187 , V_188 , 0 ) ;
F_74 ( V_1 -> V_187 ) ;
return 0 ;
}
return - V_95 ;
}
static void F_75 ( struct V_1 * V_1 ,
T_2 * V_184 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_189 , V_190 ;
V_189 = 0 ;
if ( V_184 [ 6 ] & 0x08 ) {
V_1 -> V_191 = V_192 ;
V_189 = - 5 ;
} else {
V_190 = ( V_18 -> V_165 * 100 ) /
( V_18 -> V_166 *
V_1 -> V_193 [ 0 ] -> V_194 [ 0 ] . V_3 ) ;
if ( V_190 >= 85 )
V_189 = - 3 ;
else if ( V_190 < 75 )
V_189 = 2 ;
}
if ( V_189 != 0 ) {
V_18 -> V_167 += V_189 ;
if ( V_18 -> V_167 < - 6 || V_18 -> V_167 >= 12 ) {
T_3 V_195 = V_18 -> V_142 -> V_196 . V_17 ;
V_18 -> V_167 = 0 ;
V_189 += V_195 ;
if ( V_189 < V_18 -> V_142 -> V_176 )
V_189 = V_18 -> V_142 -> V_176 ;
else if ( V_189 > V_18 -> V_142 -> V_174 )
V_189 = V_18 -> V_142 -> V_174 ;
if ( V_189 != V_195 ) {
V_18 -> V_142 -> V_196 . V_17 = V_189 ;
F_76 ( V_18 -> V_168 , & V_18 -> V_115 ) ;
}
}
} else {
V_18 -> V_167 = 0 ;
}
V_18 -> V_165 = V_18 -> V_166 = 0 ;
}
static void F_77 ( struct V_1 * V_1 ,
T_2 * V_184 ,
int V_185 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_171 , V_197 ;
static const T_2 V_198 [] =
{ 0xff , 0xff , 0x00 , 0xc4 , 0xc4 , 0x96 } ;
V_197 = ( V_18 -> V_88 & 0x03 ) == 0 ;
if ( V_185 >= 64 && memcmp ( V_184 , V_198 , 6 ) == 0 ) {
V_171 = ( ( V_184 [ 35 ] >> 2 ) & 3 ) |
( V_184 [ 20 ] << 2 ) |
( V_184 [ 19 ] << 10 ) ;
V_171 += ( ( V_184 [ 35 ] >> 4 ) & 3 ) |
( V_184 [ 22 ] << 2 ) |
( V_184 [ 21 ] << 10 ) ;
V_171 += ( ( V_184 [ 35 ] >> 6 ) & 3 ) |
( V_184 [ 24 ] << 2 ) |
( V_184 [ 23 ] << 10 ) ;
V_171 += ( V_184 [ 36 ] & 3 ) |
( V_184 [ 26 ] << 2 ) |
( V_184 [ 25 ] << 10 ) ;
V_171 += ( ( V_184 [ 36 ] >> 2 ) & 3 ) |
( V_184 [ 28 ] << 2 ) |
( V_184 [ 27 ] << 10 ) ;
V_171 += ( ( V_184 [ 36 ] >> 4 ) & 3 ) |
( V_184 [ 30 ] << 2 ) |
( V_184 [ 29 ] << 10 ) ;
V_171 += ( ( V_184 [ 36 ] >> 6 ) & 3 ) |
( V_184 [ 32 ] << 2 ) |
( V_184 [ 31 ] << 10 ) ;
V_171 += ( ( V_184 [ 44 ] >> 4 ) & 3 ) |
( V_184 [ 34 ] << 2 ) |
( V_184 [ 33 ] << 10 ) ;
V_171 >>= 9 ;
F_78 ( & V_18 -> V_171 , V_171 ) ;
if ( V_197 )
F_75 ( V_1 , V_184 ) ;
F_79 ( V_1 , V_199 , NULL , 0 ) ;
V_185 -= 64 ;
if ( V_185 == 0 )
return;
V_184 += 64 ;
}
if ( V_1 -> V_191 == V_199 ) {
if ( V_197 ) {
F_79 ( V_1 , V_200 ,
V_18 -> V_87 , V_201 ) ;
F_79 ( V_1 , V_202 ,
V_184 , V_185 ) ;
} else {
F_79 ( V_1 , V_200 ,
V_184 , V_185 ) ;
}
} else {
if ( V_197 ) {
V_18 -> V_166 ++ ;
V_18 -> V_165 += V_185 ;
}
F_79 ( V_1 , V_202 , V_184 , V_185 ) ;
}
}
static int F_80 ( struct V_148 * V_149 ,
const struct V_103 * V_26 )
{
return F_81 ( V_149 , V_26 , & V_203 , sizeof( struct V_18 ) ,
V_204 ) ;
}
