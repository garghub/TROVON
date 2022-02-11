static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
V_6 = F_2 ( V_5 , F_3 ( V_5 , 0 ) ,
0x00 ,
V_7 | V_8 | V_9 ,
V_2 ,
0x00 ,
V_1 -> V_10 ,
V_3 ,
500 ) ;
if ( F_4 ( V_6 < 0 || V_6 != V_3 ) ) {
F_5 ( L_1 , V_2 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_2 ,
const T_2 * V_12 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
memcpy ( V_1 -> V_10 , V_12 , V_3 ) ;
V_6 = F_2 ( V_5 , F_7 ( V_5 , 0 ) ,
0x08 ,
V_13 | V_8 | V_9 ,
V_2 ,
0x00 ,
V_1 -> V_10 ,
V_3 ,
500 ) ;
if ( F_4 ( V_6 < 0 || V_6 != V_3 ) ) {
F_5 ( L_2 , V_2 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , T_1 V_2 , const T_2 V_14 )
{
T_2 V_15 [ 1 ] = { V_14 } ;
return F_6 ( V_1 , V_2 , V_15 , 1 ) ;
}
static int F_9 ( struct V_1 * V_1 , const T_2 * V_12 )
{
int V_16 ;
F_6 ( V_1 , 0x10c0 , V_12 , 8 ) ;
for ( V_16 = 0 ; V_16 < 5 ; V_16 ++ ) {
F_1 ( V_1 , 0x10c0 , 1 ) ;
if ( V_1 -> V_10 [ 0 ] & 0x04 ) {
if ( V_1 -> V_10 [ 0 ] & 0x08 )
return - V_11 ;
return 0 ;
}
F_10 ( 1 ) ;
}
return - V_11 ;
}
static int F_11 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_17 )
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
return F_9 ( V_1 , V_19 ) ;
}
static int F_12 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_19 [ 8 ] ;
V_19 [ 0 ] = 0x81 | ( 3 << 4 ) ;
V_19 [ 1 ] = V_18 -> V_20 ;
V_19 [ 2 ] = V_2 ;
V_19 [ 3 ] = ( V_17 >> 8 ) & 0xff ;
V_19 [ 4 ] = V_17 & 0xff ;
V_19 [ 5 ] = 0x00 ;
V_19 [ 6 ] = 0x00 ;
V_19 [ 7 ] = 0x10 ;
return F_9 ( V_1 , V_19 ) ;
}
static int F_13 ( struct V_1 * V_1 , T_2 V_2 , T_2 * V_17 )
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
if ( F_9 ( V_1 , V_19 ) < 0 )
return - V_11 ;
V_19 [ 0 ] = 0x81 | ( 1 << 4 ) | 0x02 ;
V_19 [ 2 ] = 0 ;
if ( F_9 ( V_1 , V_19 ) < 0 )
return - V_11 ;
if ( F_1 ( V_1 , 0x10c2 , 5 ) < 0 )
return - V_11 ;
* V_17 = V_1 -> V_10 [ 4 ] ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , T_2 V_2 , T_1 * V_17 )
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
if ( F_9 ( V_1 , V_19 ) < 0 )
return - V_11 ;
V_19 [ 0 ] = 0x81 | ( 2 << 4 ) | 0x02 ;
V_19 [ 2 ] = 0 ;
if ( F_9 ( V_1 , V_19 ) < 0 )
return - V_11 ;
if ( F_1 ( V_1 , 0x10c2 , 5 ) < 0 )
return - V_11 ;
* V_17 = ( V_1 -> V_10 [ 3 ] << 8 ) | V_1 -> V_10 [ 4 ] ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
int V_16 ;
T_1 V_21 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( F_14 ( V_1 , 0x1c , & V_21 ) < 0 )
return - V_22 ;
if ( V_21 != 0x7fa2 ) {
F_5 ( L_3 , V_21 ) ;
return - V_23 ;
}
for ( V_16 = 0 ; V_16 < F_16 ( V_24 ) ; V_16 ++ ) {
if ( F_11 ( V_1 , V_24 [ V_16 ] . V_2 ,
V_24 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_4 ) ;
return - V_23 ;
}
}
V_18 -> V_25 = 1 ;
V_18 -> V_26 = 7 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_16 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
for ( V_16 = 0 ; V_16 < F_16 ( V_27 ) ; V_16 ++ ) {
if ( F_11 ( V_1 , V_27 [ V_16 ] . V_2 ,
V_27 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_5 ) ;
return - V_23 ;
}
}
V_1 -> V_28 = ( 1 << V_29 ) | ( 1 << V_30 ) ;
V_18 -> V_25 = 1 ;
V_18 -> V_26 = 2 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
int V_16 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
for ( V_16 = 0 ; V_16 < F_16 ( V_31 ) ; V_16 ++ ) {
if ( F_11 ( V_1 , V_31 [ V_16 ] . V_2 ,
V_31 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_6 ) ;
return - V_23 ;
}
}
V_1 -> V_28 = ( 1 << V_29 ) | ( 1 << V_30 )
| ( 1 << V_32 ) ;
V_18 -> V_25 = 60 ;
V_18 -> V_26 = 11 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
int V_16 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
for ( V_16 = 0 ; V_16 < F_16 ( V_33 ) ; V_16 ++ ) {
if ( F_11 ( V_1 , V_33 [ V_16 ] . V_2 ,
V_33 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_7 ) ;
return - V_23 ;
}
}
V_18 -> V_25 = 3 ;
V_18 -> V_26 = 3 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_16 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
for ( V_16 = 0 ; V_16 < F_16 ( V_34 ) ; V_16 ++ ) {
if ( F_11 ( V_1 , V_34 [ V_16 ] . V_2 ,
V_34 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_8 ) ;
return - V_23 ;
}
}
V_1 -> V_28 = ( 1 << V_29 ) | ( 1 << V_30 ) ;
V_18 -> V_25 = 0 ;
V_18 -> V_26 = 1 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_16 ;
T_1 V_14 ;
int V_35 ;
V_18 -> V_20 = 0x5d ;
V_35 = F_14 ( V_1 , 0xff , & V_14 ) ;
if ( ( V_35 == 0 ) && ( V_14 == 0x8243 ) ) {
for ( V_16 = 0 ; V_16 < F_16 ( V_36 ) ; V_16 ++ ) {
if ( F_12 ( V_1 , V_36 [ V_16 ] . V_2 ,
V_36 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_9 ) ;
return - V_23 ;
}
}
V_18 -> V_25 = 2 ;
V_18 -> V_26 = 2 ;
V_18 -> V_37 = V_38 ;
F_22 ( L_10 ) ;
return 0 ;
}
V_18 -> V_20 = 0x5c ;
F_12 ( V_1 , 0x01 , 0x0004 ) ;
V_35 = F_14 ( V_1 , 0xff , & V_14 ) ;
if ( ( V_35 == 0 ) && ( V_14 == 0x823a ) ) {
for ( V_16 = 0 ; V_16 < F_16 ( V_39 ) ; V_16 ++ ) {
if ( F_12 ( V_1 , V_39 [ V_16 ] . V_2 ,
V_39 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_11 ) ;
return - V_23 ;
}
}
V_1 -> V_28 = ( 1 << V_32 )
| ( 1 << V_40 )
| ( 1 << V_41 ) ;
V_18 -> V_25 = 2 ;
V_18 -> V_26 = 2 ;
V_18 -> V_37 = V_42 ;
F_22 ( L_12 ) ;
return 0 ;
}
V_18 -> V_20 = 0x5d ;
V_35 = F_12 ( V_1 , 0xf0 , 0x0000 ) ;
if ( V_35 < 0 ) {
V_18 -> V_20 = 0x48 ;
F_12 ( V_1 , 0xf0 , 0x0000 ) ;
}
V_35 = F_14 ( V_1 , 0x00 , & V_14 ) ;
if ( ( V_35 == 0 ) && ( V_14 == 0x1229 ) ) {
for ( V_16 = 0 ; V_16 < F_16 ( V_43 ) ; V_16 ++ ) {
if ( F_12 ( V_1 , V_43 [ V_16 ] . V_2 ,
V_43 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_13 ) ;
return - V_23 ;
}
}
V_18 -> V_25 = 6 ;
V_18 -> V_26 = 2 ;
V_18 -> V_37 = V_44 ;
F_22 ( L_14 ) ;
return 0 ;
}
return - V_23 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_16 ( V_45 ) ; V_16 ++ ) {
if ( F_12 ( V_1 , V_45 [ V_16 ] . V_2 ,
V_45 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_15 ) ;
return - V_23 ;
}
}
V_1 -> V_28 = ( 1 << V_32 ) | ( 1 << V_40 )
| ( 1 << V_41 ) ;
V_18 -> V_25 = 0 ;
V_18 -> V_26 = 2 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_16 ( V_46 ) ; V_16 ++ ) {
if ( F_12 ( V_1 , V_46 [ V_16 ] . V_2 ,
V_46 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_16 ) ;
return - V_23 ;
}
}
V_1 -> V_28 = ( 1 << V_32 ) | ( 1 << V_40 )
| ( 1 << V_41 ) ;
V_18 -> V_25 = 0 ;
V_18 -> V_26 = 2 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_16 ;
T_1 V_21 ;
if ( F_14 ( V_1 , 0x00 , & V_21 ) < 0 )
return - V_22 ;
switch ( V_21 ) {
case 0x8411 :
case 0x8421 :
F_22 ( L_17 ) ;
break;
case 0x8431 :
F_22 ( L_18 ) ;
break;
default:
F_5 ( L_19 , V_21 ) ;
return - V_23 ;
}
for ( V_16 = 0 ; V_16 < F_16 ( V_47 ) ; V_16 ++ ) {
if ( F_12 ( V_1 , V_47 [ V_16 ] . V_2 ,
V_47 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_20 ) ;
return - V_23 ;
}
}
V_1 -> V_28 = ( 1 << V_29 ) | ( 1 << V_30 ) ;
V_18 -> V_25 = 1 ;
V_18 -> V_26 = 1 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
int V_16 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
for ( V_16 = 0 ; V_16 < F_16 ( V_48 ) ; V_16 ++ ) {
if ( F_11 ( V_1 , V_48 [ V_16 ] . V_2 ,
V_48 [ V_16 ] . V_17 ) < 0 ) {
F_5 ( L_21 ) ;
return - V_23 ;
}
}
V_18 -> V_25 = 0 ;
V_18 -> V_26 = 1 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_3 V_49 , V_50 = 180 + V_18 -> V_51 ;
T_2 V_52 [ 21 ] ;
memset ( V_52 , 0 , sizeof V_52 ) ;
V_52 [ 2 ] = ( V_18 -> V_53 * 0x25 / 0x100 ) + 0x26 ;
V_52 [ 0 ] = 0x13 + ( V_52 [ 2 ] - 0x26 ) * 0x13 / 0x25 ;
V_52 [ 4 ] = 0x07 + ( V_52 [ 2 ] - 0x26 ) * 0x07 / 0x25 ;
V_52 [ 18 ] = V_18 -> V_54 - 0x80 ;
V_49 = ( V_55 [ V_50 ] * V_18 -> V_56 ) >> 8 ;
V_52 [ 6 ] = V_49 ;
V_52 [ 7 ] = ( V_49 >> 8 ) & 0x0f ;
V_49 = ( V_57 [ V_50 ] * V_18 -> V_56 ) >> 8 ;
V_52 [ 8 ] = V_49 ;
V_52 [ 9 ] = ( V_49 >> 8 ) & 0x0f ;
V_49 = ( V_58 [ V_50 ] * V_18 -> V_56 ) >> 8 ;
V_52 [ 10 ] = V_49 ;
V_52 [ 11 ] = ( V_49 >> 8 ) & 0x0f ;
V_49 = ( V_59 [ V_50 ] * V_18 -> V_56 ) >> 8 ;
V_52 [ 12 ] = V_49 ;
V_52 [ 13 ] = ( V_49 >> 8 ) & 0x0f ;
V_49 = ( V_60 [ V_50 ] * V_18 -> V_56 ) >> 8 ;
V_52 [ 14 ] = V_49 ;
V_52 [ 15 ] = ( V_49 >> 8 ) & 0x0f ;
V_49 = ( V_61 [ V_50 ] * V_18 -> V_56 ) >> 8 ;
V_52 [ 16 ] = V_49 ;
V_52 [ 17 ] = ( V_49 >> 8 ) & 0x0f ;
return F_6 ( V_1 , 0x10e1 , V_52 , 21 ) ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 gamma [ 17 ] ;
T_2 V_62 = V_18 -> gamma * 0xb8 / 0x100 ;
gamma [ 0 ] = 0x0a ;
gamma [ 1 ] = 0x13 + ( V_62 * ( 0xcb - 0x13 ) / 0xb8 ) ;
gamma [ 2 ] = 0x25 + ( V_62 * ( 0xee - 0x25 ) / 0xb8 ) ;
gamma [ 3 ] = 0x37 + ( V_62 * ( 0xfa - 0x37 ) / 0xb8 ) ;
gamma [ 4 ] = 0x45 + ( V_62 * ( 0xfc - 0x45 ) / 0xb8 ) ;
gamma [ 5 ] = 0x55 + ( V_62 * ( 0xfb - 0x55 ) / 0xb8 ) ;
gamma [ 6 ] = 0x65 + ( V_62 * ( 0xfc - 0x65 ) / 0xb8 ) ;
gamma [ 7 ] = 0x74 + ( V_62 * ( 0xfd - 0x74 ) / 0xb8 ) ;
gamma [ 8 ] = 0x83 + ( V_62 * ( 0xfe - 0x83 ) / 0xb8 ) ;
gamma [ 9 ] = 0x92 + ( V_62 * ( 0xfc - 0x92 ) / 0xb8 ) ;
gamma [ 10 ] = 0xa1 + ( V_62 * ( 0xfc - 0xa1 ) / 0xb8 ) ;
gamma [ 11 ] = 0xb0 + ( V_62 * ( 0xfc - 0xb0 ) / 0xb8 ) ;
gamma [ 12 ] = 0xbf + ( V_62 * ( 0xfb - 0xbf ) / 0xb8 ) ;
gamma [ 13 ] = 0xce + ( V_62 * ( 0xfb - 0xce ) / 0xb8 ) ;
gamma [ 14 ] = 0xdf + ( V_62 * ( 0xfd - 0xdf ) / 0xb8 ) ;
gamma [ 15 ] = 0xea + ( V_62 * ( 0xf9 - 0xea ) / 0xb8 ) ;
gamma [ 16 ] = 0xf5 ;
return F_6 ( V_1 , 0x1190 , gamma , 17 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
F_8 ( V_1 , 0x118c , V_18 -> V_63 ) ;
F_8 ( V_1 , 0x118f , V_18 -> V_64 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
T_2 V_14 , V_65 , V_66 , V_67 ;
T_1 V_68 ;
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( ( V_18 -> V_69 & V_70 ) && F_31 ( V_71 ) ) {
V_66 = ! V_18 -> V_66 ;
V_67 = ! V_18 -> V_67 ;
} else {
V_66 = V_18 -> V_66 ;
V_67 = V_18 -> V_67 ;
}
switch ( V_18 -> V_37 ) {
case V_72 :
V_14 = 0x01 ;
if ( V_66 )
V_14 |= 0x20 ;
if ( V_67 ) {
V_14 |= 0x10 ;
V_18 -> V_26 = 2 ;
} else
V_18 -> V_26 = 3 ;
F_8 ( V_1 , 0x1182 , V_18 -> V_26 ) ;
F_11 ( V_1 , 0x1e , V_14 ) ;
break;
case V_73 :
F_13 ( V_1 , 0x1e , & V_14 ) ;
V_14 &= ~ 0x30 ;
V_65 = 0x01 ;
if ( V_66 )
V_14 |= 0x20 ;
if ( V_67 ) {
V_14 |= 0x10 ;
V_65 = 0x49 ;
}
F_11 ( V_1 , 0x1e , V_14 ) ;
F_11 ( V_1 , 0x3a , V_65 ) ;
break;
case V_42 :
case V_38 :
F_14 ( V_1 , 0x20 , & V_68 ) ;
V_68 &= ~ 0xc0a0 ;
if ( V_66 )
V_68 |= 0x8080 ;
if ( V_67 )
V_68 |= 0x4020 ;
F_12 ( V_1 , 0x20 , V_68 ) ;
break;
case V_74 :
case V_75 :
case V_44 :
F_14 ( V_1 , 0x20 , & V_68 ) ;
V_68 &= ~ 0x0003 ;
if ( V_66 )
V_68 |= 0x0002 ;
if ( V_67 )
V_68 |= 0x0001 ;
F_12 ( V_1 , 0x20 , V_68 ) ;
break;
case V_76 :
F_13 ( V_1 , 0x01 , & V_14 ) ;
V_14 &= ~ 0x03 ;
if ( V_67 )
V_14 |= 0x01 ;
if ( V_66 )
V_14 |= 0x02 ;
F_11 ( V_1 , 0x01 , V_14 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 exp [ 8 ] = { 0x81 , V_18 -> V_20 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x1e } ;
switch ( V_18 -> V_37 ) {
case V_72 :
case V_77 :
case V_78 :
case V_73 :
exp [ 0 ] |= ( 3 << 4 ) ;
exp [ 2 ] = 0x2d ;
exp [ 3 ] = V_18 -> V_79 & 0xff ;
exp [ 4 ] = V_18 -> V_79 >> 8 ;
break;
case V_80 :
case V_44 :
case V_38 :
exp [ 0 ] |= ( 3 << 4 ) ;
exp [ 2 ] = 0x09 ;
exp [ 3 ] = V_18 -> V_79 >> 8 ;
exp [ 4 ] = V_18 -> V_79 & 0xff ;
break;
case V_76 :
exp [ 0 ] |= ( 4 << 4 ) ;
exp [ 2 ] = 0x25 ;
exp [ 3 ] = ( V_18 -> V_79 >> 5 ) & 0xff ;
exp [ 4 ] = ( V_18 -> V_79 << 3 ) & 0xff ;
exp [ 5 ] = 0 ;
break;
default:
return 0 ;
}
F_9 ( V_1 , exp ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_81 [ 8 ] = { 0x81 , V_18 -> V_20 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x1d } ;
switch ( V_18 -> V_37 ) {
case V_72 :
case V_77 :
case V_82 :
case V_78 :
case V_73 :
V_81 [ 0 ] |= ( 2 << 4 ) ;
V_81 [ 3 ] = V_83 [ V_18 -> V_81 ] ;
break;
case V_38 :
V_81 [ 0 ] |= ( 3 << 4 ) ;
V_81 [ 2 ] = 0x35 ;
V_81 [ 3 ] = V_84 [ V_18 -> V_81 ] >> 8 ;
V_81 [ 4 ] = V_84 [ V_18 -> V_81 ] & 0xff ;
break;
case V_44 :
V_81 [ 0 ] |= ( 3 << 4 ) ;
V_81 [ 2 ] = 0x2f ;
V_81 [ 3 ] = V_84 [ V_18 -> V_81 ] >> 8 ;
V_81 [ 4 ] = V_84 [ V_18 -> V_81 ] & 0xff ;
break;
case V_80 :
V_81 [ 0 ] |= ( 3 << 4 ) ;
V_81 [ 2 ] = 0x2f ;
V_81 [ 3 ] = V_85 [ V_18 -> V_81 ] >> 8 ;
V_81 [ 4 ] = V_85 [ V_18 -> V_81 ] & 0xff ;
break;
case V_76 :
V_81 [ 0 ] |= ( 2 << 4 ) ;
V_81 [ 2 ] = 0x30 ;
V_81 [ 3 ] = V_86 [ V_18 -> V_81 ] ;
break;
default:
return 0 ;
}
F_9 ( V_1 , V_81 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_54 = V_17 ;
if ( V_1 -> V_87 )
return F_27 ( V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_54 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_53 = V_17 ;
if ( V_1 -> V_87 )
return F_27 ( V_1 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_53 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_56 = V_17 ;
if ( V_1 -> V_87 )
return F_27 ( V_1 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_56 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_51 = V_17 ;
if ( V_1 -> V_87 )
return F_27 ( V_1 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_51 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> gamma = V_17 ;
if ( V_1 -> V_87 )
return F_28 ( V_1 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> gamma ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_63 = V_17 ;
if ( V_1 -> V_87 )
return F_29 ( V_1 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_63 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_64 = V_17 ;
if ( V_1 -> V_87 )
return F_29 ( V_1 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_64 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_66 = V_17 ;
if ( V_1 -> V_87 )
return F_30 ( V_1 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_66 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_67 = V_17 ;
if ( V_1 -> V_87 )
return F_30 ( V_1 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_67 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_79 = V_17 ;
if ( V_1 -> V_87 )
return F_32 ( V_1 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_79 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_81 = V_17 ;
if ( V_1 -> V_87 )
return F_33 ( V_1 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_81 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_1 , T_3 V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
V_18 -> V_88 = V_17 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_1 , T_3 * V_17 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
* V_17 = V_18 -> V_88 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_1 ,
struct V_89 * V_2 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_2 -> V_90 . type ) {
case V_91 :
if ( V_2 -> V_90 . V_92 != 0 )
return - V_22 ;
if ( V_2 -> V_2 < 0x1000 || V_2 -> V_2 > 0x11ff )
return - V_22 ;
if ( F_1 ( V_1 , V_2 -> V_2 , 1 ) < 0 )
return - V_22 ;
V_2 -> V_17 = V_1 -> V_10 [ 0 ] ;
return 0 ;
case V_93 :
if ( V_2 -> V_90 . V_92 != V_18 -> V_20 )
return - V_22 ;
if ( V_18 -> V_37 >= V_38 &&
V_18 -> V_37 <= V_74 ) {
if ( F_14 ( V_1 , V_2 -> V_2 , ( T_1 * ) & V_2 -> V_17 ) < 0 )
return - V_22 ;
} else {
if ( F_13 ( V_1 , V_2 -> V_2 , ( T_2 * ) & V_2 -> V_17 ) < 0 )
return - V_22 ;
}
return 0 ;
}
return - V_22 ;
}
static int F_59 ( struct V_1 * V_1 ,
struct V_89 * V_2 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_2 -> V_90 . type ) {
case V_91 :
if ( V_2 -> V_90 . V_92 != 0 )
return - V_22 ;
if ( V_2 -> V_2 < 0x1000 || V_2 -> V_2 > 0x11ff )
return - V_22 ;
if ( F_8 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) < 0 )
return - V_22 ;
return 0 ;
case V_93 :
if ( V_2 -> V_90 . V_92 != V_18 -> V_20 )
return - V_22 ;
if ( V_18 -> V_37 >= V_38 &&
V_18 -> V_37 <= V_74 ) {
if ( F_12 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) < 0 )
return - V_22 ;
} else {
if ( F_11 ( V_1 , V_2 -> V_2 , V_2 -> V_17 ) < 0 )
return - V_22 ;
}
return 0 ;
}
return - V_22 ;
}
static int F_60 ( struct V_1 * V_1 ,
struct V_94 * V_95 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
switch ( V_95 -> V_90 . type ) {
case V_91 :
if ( V_95 -> V_90 . V_92 != 0 )
return - V_22 ;
V_95 -> V_96 = 0 ;
V_95 -> V_97 = V_98 ;
return 0 ;
case V_93 :
if ( V_95 -> V_90 . V_92 != V_18 -> V_20 )
return - V_22 ;
V_95 -> V_96 = 0 ;
V_95 -> V_97 = V_99 [ V_18 -> V_37 ] ;
return 0 ;
}
return - V_22 ;
}
static int F_61 ( struct V_1 * V_1 ,
const struct V_100 * V_21 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
struct V_101 * V_101 ;
V_101 = & V_1 -> V_101 ;
V_101 -> V_102 = 1 ;
V_18 -> V_37 = ( V_21 -> V_103 >> 8 ) & 0xff ;
V_18 -> V_20 = V_21 -> V_103 & 0xff ;
V_18 -> V_69 = ( V_21 -> V_103 >> 16 ) & 0xff ;
switch ( V_18 -> V_37 ) {
case V_74 :
case V_75 :
case V_73 :
case V_82 :
V_101 -> V_104 = V_105 ;
V_101 -> V_106 = F_16 ( V_105 ) ;
break;
case V_80 :
V_101 -> V_104 = V_107 ;
V_101 -> V_106 = F_16 ( V_107 ) ;
break;
default:
V_101 -> V_104 = V_108 ;
V_101 -> V_106 = F_16 ( V_108 ) ;
break;
}
V_18 -> V_109 = 0 ;
V_18 -> V_110 = 0 ;
V_18 -> V_111 = 16 ;
V_18 -> V_54 = V_112 ;
V_18 -> V_53 = V_113 ;
V_18 -> V_56 = V_114 ;
V_18 -> V_51 = V_115 ;
V_18 -> gamma = V_116 ;
V_18 -> V_63 = V_117 ;
V_18 -> V_64 = V_118 ;
V_18 -> V_66 = V_119 ;
V_18 -> V_67 = V_120 ;
V_18 -> V_79 = V_121 ;
V_18 -> V_81 = V_122 ;
V_18 -> V_88 = V_123 ;
V_18 -> V_124 = 95 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_16 ;
T_2 V_14 ;
T_2 V_125 [ 9 ] =
{ 0x80 , V_18 -> V_20 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } ;
for ( V_16 = 0 ; V_16 < F_16 ( V_126 ) ; V_16 ++ ) {
V_14 = V_126 [ V_16 ] [ 1 ] ;
if ( F_6 ( V_1 , V_126 [ V_16 ] [ 0 ] , & V_14 , 1 ) < 0 ) {
F_5 ( L_22 ) ;
return - V_23 ;
}
}
if ( V_18 -> V_69 & V_127 )
F_8 ( V_1 , 0x1006 , 0x00 ) ;
else
F_8 ( V_1 , 0x1006 , 0x20 ) ;
if ( F_6 ( V_1 , 0x10c0 , V_125 , 9 ) < 0 ) {
F_5 ( L_22 ) ;
return - V_23 ;
}
switch ( V_18 -> V_37 ) {
case V_73 :
if ( F_15 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_23 ) ;
break;
case V_78 :
if ( F_17 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_24 ) ;
break;
case V_82 :
if ( F_18 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_25 ) ;
break;
case V_72 :
if ( F_19 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_26 ) ;
break;
case V_77 :
if ( F_20 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_27 ) ;
break;
case V_128 :
if ( F_21 ( V_1 ) < 0 )
return - V_23 ;
break;
case V_75 :
if ( F_24 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_28 ) ;
break;
case V_74 :
if ( F_23 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_29 ) ;
break;
case V_80 :
if ( F_25 ( V_1 ) < 0 )
return - V_23 ;
break;
case V_76 :
if ( F_26 ( V_1 ) < 0 )
return - V_23 ;
F_22 ( L_30 ) ;
break;
default:
F_22 ( L_31 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_1 , int V_129 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_2 V_14 ;
switch ( V_18 -> V_37 ) {
case V_82 :
if ( V_129 & V_130 ) {
F_11 ( V_1 , 0x17 , 0x1d ) ;
F_11 ( V_1 , 0x18 , 0xbd ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x81 ) ;
F_11 ( V_1 , 0x12 , 0x00 ) ;
V_18 -> V_25 = 140 ;
V_18 -> V_26 = 19 ;
} else {
F_11 ( V_1 , 0x17 , 0x13 ) ;
F_11 ( V_1 , 0x18 , 0x63 ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x79 ) ;
F_11 ( V_1 , 0x12 , 0x40 ) ;
V_18 -> V_25 = 60 ;
V_18 -> V_26 = 11 ;
}
break;
case V_73 :
if ( V_129 & V_130 ) {
F_11 ( V_1 , 0x17 , 0x1b ) ;
F_11 ( V_1 , 0x18 , 0xbc ) ;
F_11 ( V_1 , 0x19 , 0x01 ) ;
F_11 ( V_1 , 0x1a , 0x82 ) ;
F_13 ( V_1 , 0x12 , & V_14 ) ;
F_11 ( V_1 , 0x12 , V_14 & 0x07 ) ;
} else {
F_11 ( V_1 , 0x17 , 0x24 ) ;
F_11 ( V_1 , 0x18 , 0xc5 ) ;
F_11 ( V_1 , 0x19 , 0x00 ) ;
F_11 ( V_1 , 0x1a , 0x3c ) ;
F_13 ( V_1 , 0x12 , & V_14 ) ;
F_11 ( V_1 , 0x12 , ( V_14 & 0x7 ) | 0x40 ) ;
}
break;
case V_74 :
case V_75 :
if ( V_129 & V_130 ) {
F_12 ( V_1 , 0xf0 , 0x0002 ) ;
F_12 ( V_1 , 0xc8 , 0x970b ) ;
F_12 ( V_1 , 0xf0 , 0x0000 ) ;
} else {
F_12 ( V_1 , 0xf0 , 0x0002 ) ;
F_12 ( V_1 , 0xc8 , 0x8000 ) ;
F_12 ( V_1 , 0xf0 , 0x0000 ) ;
}
break;
}
}
static int F_64 ( struct V_1 * V_1 )
{
struct V_131 * V_132 ;
T_4 V_69 = V_1 -> V_101 . V_104 [ ( int ) V_1 -> V_133 ] . V_134 ;
if ( ! ( V_69 & ( V_135 | V_136 ) ) ) {
V_132 = F_65 ( V_1 -> V_5 , V_1 -> V_137 ) ;
if ( V_132 -> V_138 != 9 ) {
F_66 ( L_32
L_33 ,
V_132 -> V_138 ) ;
V_1 -> V_139 = V_132 -> V_138 ;
return 0 ;
}
switch ( V_1 -> V_140 ) {
case 160 :
V_1 -> V_139 = 2 ;
break;
case 320 :
V_1 -> V_139 = 6 ;
break;
default:
V_1 -> V_139 = 9 ;
}
}
return 0 ;
}
static int F_67 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_129 = V_1 -> V_101 . V_104 [ ( int ) V_1 -> V_133 ] . V_134 ;
int V_140 = V_1 -> V_140 ;
int V_141 = V_1 -> V_141 ;
T_2 V_142 , V_143 = 0 ;
F_68 ( V_18 -> V_144 , V_141 , V_140 ,
0x21 ) ;
F_69 ( V_18 -> V_144 , V_18 -> V_124 ) ;
if ( V_129 & V_135 )
V_142 = 0x2d ;
else if ( V_129 & V_136 )
V_142 = 0x2c ;
else
V_142 = 0x2f ;
switch ( V_129 & V_145 ) {
case V_146 :
V_143 = 0xc0 ;
F_22 ( L_34 ) ;
break;
case V_147 :
V_143 = 0x80 ;
F_22 ( L_35 ) ;
break;
case V_148 :
V_143 = 0x90 ;
F_22 ( L_36 ) ;
break;
case V_149 :
V_143 = 0xa0 ;
F_22 ( L_37 ) ;
break;
}
F_63 ( V_1 , V_129 ) ;
F_6 ( V_1 , 0x1100 , & V_18 -> V_144 [ V_150 ] , 64 ) ;
F_6 ( V_1 , 0x1140 , & V_18 -> V_144 [ V_151 ] , 64 ) ;
F_6 ( V_1 , 0x10fb , F_70 ( V_140 , V_141 ) , 5 ) ;
F_6 ( V_1 , 0x1180 , F_71 ( V_129 , V_18 -> V_25 , V_18 -> V_26 ) , 6 ) ;
F_8 ( V_1 , 0x1189 , V_143 ) ;
F_8 ( V_1 , 0x10e0 , V_142 ) ;
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
F_29 ( V_1 ) ;
F_33 ( V_1 ) ;
F_32 ( V_1 ) ;
F_30 ( V_1 ) ;
F_8 ( V_1 , 0x1007 , 0x20 ) ;
F_1 ( V_1 , 0x1061 , 1 ) ;
F_8 ( V_1 , 0x1061 , V_1 -> V_10 [ 0 ] | 0x02 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_1 )
{
F_8 ( V_1 , 0x1007 , 0x00 ) ;
F_1 ( V_1 , 0x1061 , 1 ) ;
F_8 ( V_1 , 0x1061 , V_1 -> V_10 [ 0 ] & ~ 0x02 ) ;
}
static void F_73 ( struct V_1 * V_1 , T_1 V_152 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
T_5 V_153 ;
if ( V_152 < V_154 ) {
if ( V_18 -> V_79 > 0x1770 )
return;
V_153 = V_18 -> V_79 + V_18 -> V_111 ;
if ( V_153 > 0x1770 )
V_153 = 0x1770 ;
if ( V_153 < 0x10 )
V_153 = 0x10 ;
V_18 -> V_79 = V_153 ;
F_32 ( V_1 ) ;
V_18 -> V_110 = V_18 -> V_109 ;
V_18 -> V_109 = 1 ;
if ( V_18 -> V_109 ^ V_18 -> V_110 )
V_18 -> V_111 /= 2 ;
else
V_18 -> V_111 += 2 ;
}
if ( V_152 > V_155 ) {
if ( V_18 -> V_79 < 0x10 )
return;
V_153 = V_18 -> V_79 - V_18 -> V_111 ;
if ( V_153 > 0x1700 )
V_153 = 0x1770 ;
if ( V_153 < 0x10 )
V_153 = 0x10 ;
V_18 -> V_79 = V_153 ;
F_32 ( V_1 ) ;
V_18 -> V_110 = V_18 -> V_109 ;
V_18 -> V_109 = 0 ;
if ( V_18 -> V_109 ^ V_18 -> V_110 )
V_18 -> V_111 /= 2 ;
else
V_18 -> V_111 += 2 ;
}
}
static void F_74 ( struct V_1 * V_1 , T_1 V_152 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
if ( V_152 < V_154 ) {
if ( V_18 -> V_81 + 1 <= 28 ) {
V_18 -> V_81 ++ ;
F_33 ( V_1 ) ;
}
}
if ( V_152 > V_155 ) {
if ( V_18 -> V_81 > 0 ) {
V_18 -> V_81 -- ;
F_33 ( V_1 ) ;
}
}
}
static void F_75 ( struct V_1 * V_1 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_152 ;
if ( ! V_18 -> V_88 )
return;
V_152 = F_76 ( & V_18 -> V_152 ) ;
if ( V_18 -> V_37 == V_82 )
F_74 ( V_1 , V_152 ) ;
else
F_73 ( V_1 , V_152 ) ;
}
static int F_77 ( struct V_1 * V_1 ,
T_2 * V_15 ,
int V_156 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_35 = - V_22 ;
if ( ! ( V_18 -> V_69 & V_157 ) && V_156 == 1 ) {
F_78 ( V_1 -> V_158 , V_159 , 1 ) ;
F_79 ( V_1 -> V_158 ) ;
F_78 ( V_1 -> V_158 , V_159 , 0 ) ;
F_79 ( V_1 -> V_158 ) ;
V_35 = 0 ;
}
return V_35 ;
}
static void F_80 ( struct V_1 * V_1 ,
T_2 * V_15 ,
int V_156 )
{
struct V_18 * V_18 = (struct V_18 * ) V_1 ;
int V_152 ;
static T_2 V_160 [] =
{ 0xff , 0xff , 0x00 , 0xc4 , 0xc4 , 0x96 } ;
if ( V_156 == 64 && memcmp ( V_15 , V_160 , 6 ) == 0 ) {
V_152 = ( ( V_15 [ 35 ] >> 2 ) & 3 ) |
( V_15 [ 20 ] << 2 ) |
( V_15 [ 19 ] << 10 ) ;
V_152 += ( ( V_15 [ 35 ] >> 4 ) & 3 ) |
( V_15 [ 22 ] << 2 ) |
( V_15 [ 21 ] << 10 ) ;
V_152 += ( ( V_15 [ 35 ] >> 6 ) & 3 ) |
( V_15 [ 24 ] << 2 ) |
( V_15 [ 23 ] << 10 ) ;
V_152 += ( V_15 [ 36 ] & 3 ) |
( V_15 [ 26 ] << 2 ) |
( V_15 [ 25 ] << 10 ) ;
V_152 += ( ( V_15 [ 36 ] >> 2 ) & 3 ) |
( V_15 [ 28 ] << 2 ) |
( V_15 [ 27 ] << 10 ) ;
V_152 += ( ( V_15 [ 36 ] >> 4 ) & 3 ) |
( V_15 [ 30 ] << 2 ) |
( V_15 [ 29 ] << 10 ) ;
V_152 += ( ( V_15 [ 36 ] >> 6 ) & 3 ) |
( V_15 [ 32 ] << 2 ) |
( V_15 [ 31 ] << 10 ) ;
V_152 += ( ( V_15 [ 44 ] >> 4 ) & 3 ) |
( V_15 [ 34 ] << 2 ) |
( V_15 [ 33 ] << 10 ) ;
V_152 >>= 9 ;
F_81 ( & V_18 -> V_152 , V_152 ) ;
F_82 ( V_1 , V_161 , NULL , 0 ) ;
return;
}
if ( V_1 -> V_162 == V_161 ) {
if ( V_1 -> V_101 . V_104 [ ( int ) V_1 -> V_133 ] . V_134
& V_136 ) {
F_82 ( V_1 , V_163 ,
V_18 -> V_144 , V_164 ) ;
F_82 ( V_1 , V_165 ,
V_15 , V_156 ) ;
} else {
F_82 ( V_1 , V_163 ,
V_15 , V_156 ) ;
}
} else {
F_82 ( V_1 , V_165 , V_15 , V_156 ) ;
}
}
static int F_83 ( struct V_131 * V_132 ,
const struct V_100 * V_21 )
{
return F_84 ( V_132 , V_21 , & V_166 , sizeof( struct V_18 ) ,
V_167 ) ;
}
