static void F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 . V_6 ;
T_1 V_7 ;
int V_8 ;
if ( V_1 -> V_5 . V_9 < 0 )
return;
V_7 = * V_2 ++ ;
memcpy ( V_1 -> V_5 . V_10 , V_2 , 6 ) ;
V_8 = F_2 ( V_4 , F_3 ( V_4 , 0 ) , 0 ,
V_11 | V_12 | V_13 ,
V_7 , 0x06 , V_1 -> V_5 . V_10 , 6 , 500 ) ;
if ( V_8 < 0 ) {
F_4 ( L_1 , V_8 ) ;
V_1 -> V_5 . V_9 = V_8 ;
}
}
static void F_5 ( struct V_1 * V_1 , T_1 V_7 )
{
int V_8 ;
if ( V_1 -> V_5 . V_9 < 0 )
return;
V_8 = F_2 ( V_1 -> V_5 . V_6 ,
F_3 ( V_1 -> V_5 . V_6 , 0 ) ,
0 ,
V_12 | V_11 | V_13 ,
V_7 , 0x01 , NULL , 0 , 500 ) ;
F_6 ( V_14 ) ;
if ( V_8 < 0 ) {
F_4 ( L_2 , V_7 ) ;
V_1 -> V_5 . V_9 = V_8 ;
}
}
static int F_7 ( struct V_1 * V_1 )
{
int V_8 ;
if ( V_1 -> V_5 . V_9 < 0 )
return - 1 ;
V_8 = F_2 ( V_1 -> V_5 . V_6 ,
F_8 ( V_1 -> V_5 . V_6 , 0 ) ,
1 ,
V_15 | V_11 | V_13 ,
0 , 0x01 , V_1 -> V_5 . V_10 , 2 , 500 ) ;
if ( V_8 >= 0 ) {
V_8 = V_1 -> V_5 . V_10 [ 0 ] |
( V_1 -> V_5 . V_10 [ 1 ] << 8 ) ;
} else {
F_4 ( L_3 ) ;
V_1 -> V_5 . V_9 = V_8 ;
}
F_6 ( V_14 ) ;
return V_8 ;
}
static void F_9 ( struct V_1 * V_1 )
{
T_1 V_16 , V_17 ;
int V_18 , V_19 ;
F_10 ( V_1 , 0x39 , 0x0010 ) ;
for ( V_18 = 0 , V_19 = 0 ; V_18 < 32 ; V_18 ++ , V_19 += 2 ) {
V_16 = V_20 [ V_19 ] | ( ( unsigned ) ( V_20 [ V_19 + 1 ] ) << 8 ) ;
V_17 = V_21 [ V_19 ] | ( ( unsigned ) ( V_21 [ V_19 + 1 ] ) << 8 ) ;
F_10 ( V_1 , 0x40 + V_18 , V_16 ) ;
F_10 ( V_1 , 0x60 + V_18 , V_17 ) ;
}
F_10 ( V_1 , 0x39 , 0x0012 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0x0011 ) ;
F_5 ( V_1 , 0x0010 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0x0010 ) ;
F_5 ( V_1 , 0x0011 ) ;
F_5 ( V_1 , 0x0013 ) ;
}
static void F_13 ( struct V_1 * V_1 , T_2 V_22 )
{
T_2 V_23 ;
int V_24 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
V_24 = ( V_22 & 0x80 ) ? 2 : 0 ;
V_22 <<= 1 ;
F_5 ( V_1 , 0x10 | V_24 ) ;
F_5 ( V_1 , 0x11 | V_24 ) ;
F_5 ( V_1 , 0x10 | V_24 ) ;
}
}
static void F_14 ( struct V_1 * V_1 , T_2 * V_22 )
{
T_2 V_23 ;
* V_22 = 0 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
* V_22 <<= 1 ;
F_5 ( V_1 , 0x0013 ) ;
* V_22 |= ( F_7 ( V_1 ) & 0x0008 ) ? 1 : 0 ;
F_5 ( V_1 , 0x0012 ) ;
}
}
static void F_15 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0x0013 ) ;
F_5 ( V_1 , 0x0012 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
int V_24 ;
F_5 ( V_1 , 0x0012 ) ;
F_5 ( V_1 , 0x0013 ) ;
V_24 = F_7 ( V_1 ) ;
F_5 ( V_1 , 0x0012 ) ;
if ( V_24 >= 0 && ( V_24 & 0x08 ) ) {
F_17 ( V_25 , L_4 ) ;
V_1 -> V_5 . V_9 = - V_26 ;
}
}
static void F_18 ( struct V_1 * V_1 , T_2 V_27 , T_2 V_7 )
{
T_1 * V_2 = ( T_1 * ) V_1 -> V_5 . V_10 ;
V_2 [ 0 ] = 0x082f | ( ( V_1 -> V_28 & 0x80 ) ? 0x1500 : 0x0 ) ;
V_2 [ 0 ] |= ( V_1 -> V_28 & 0x40 ) ? 0x4000 : 0x0 ;
V_2 [ 1 ] = 0x2082 | ( ( V_1 -> V_28 & 0x40 ) ? 0x0005 : 0x0 ) ;
V_2 [ 1 ] |= ( V_1 -> V_28 & 0x20 ) ? 0x0150 : 0x0 ;
V_2 [ 1 ] |= ( V_1 -> V_28 & 0x10 ) ? 0x5400 : 0x0 ;
V_2 [ 2 ] = 0x8208 | ( ( V_1 -> V_28 & 0x08 ) ? 0x0015 : 0x0 ) ;
V_2 [ 2 ] |= ( V_1 -> V_28 & 0x04 ) ? 0x0540 : 0x0 ;
V_2 [ 2 ] |= ( V_1 -> V_28 & 0x02 ) ? 0x5000 : 0x0 ;
V_2 [ 3 ] = 0x1d20 | ( ( V_1 -> V_28 & 0x02 ) ? 0x0001 : 0x0 ) ;
V_2 [ 3 ] |= ( V_1 -> V_28 & 0x01 ) ? 0x0054 : 0x0 ;
F_1 ( V_1 , V_2 ) ;
V_2 [ 0 ] = 0x8208 | ( ( V_27 & 0x80 ) ? 0x0015 : 0x0 ) ;
V_2 [ 0 ] |= ( V_27 & 0x40 ) ? 0x0540 : 0x0 ;
V_2 [ 0 ] |= ( V_27 & 0x20 ) ? 0x5000 : 0x0 ;
V_2 [ 1 ] = 0x0820 | ( ( V_27 & 0x20 ) ? 0x0001 : 0x0 ) ;
V_2 [ 1 ] |= ( V_27 & 0x10 ) ? 0x0054 : 0x0 ;
V_2 [ 1 ] |= ( V_27 & 0x08 ) ? 0x1500 : 0x0 ;
V_2 [ 1 ] |= ( V_27 & 0x04 ) ? 0x4000 : 0x0 ;
V_2 [ 2 ] = 0x2082 | ( ( V_27 & 0x04 ) ? 0x0005 : 0x0 ) ;
V_2 [ 2 ] |= ( V_27 & 0x02 ) ? 0x0150 : 0x0 ;
V_2 [ 2 ] |= ( V_27 & 0x01 ) ? 0x5400 : 0x0 ;
V_2 [ 3 ] = 0x001d ;
F_1 ( V_1 , V_2 ) ;
V_2 [ 0 ] = 0x8208 | ( ( V_7 & 0x80 ) ? 0x0015 : 0x0 ) ;
V_2 [ 0 ] |= ( V_7 & 0x40 ) ? 0x0540 : 0x0 ;
V_2 [ 0 ] |= ( V_7 & 0x20 ) ? 0x5000 : 0x0 ;
V_2 [ 1 ] = 0x0820 | ( ( V_7 & 0x20 ) ? 0x0001 : 0x0 ) ;
V_2 [ 1 ] |= ( V_7 & 0x10 ) ? 0x0054 : 0x0 ;
V_2 [ 1 ] |= ( V_7 & 0x08 ) ? 0x1500 : 0x0 ;
V_2 [ 1 ] |= ( V_7 & 0x04 ) ? 0x4000 : 0x0 ;
V_2 [ 2 ] = 0x2082 | ( ( V_7 & 0x04 ) ? 0x0005 : 0x0 ) ;
V_2 [ 2 ] |= ( V_7 & 0x02 ) ? 0x0150 : 0x0 ;
V_2 [ 2 ] |= ( V_7 & 0x01 ) ? 0x5400 : 0x0 ;
V_2 [ 3 ] = 0xfe1d ;
F_1 ( V_1 , V_2 ) ;
F_17 ( V_29 , L_5 , V_7 , V_27 ) ;
}
static int F_19 ( struct V_1 * V_1 , T_2 V_27 )
{
int V_8 = 0 ;
T_2 V_7 ;
F_5 ( V_1 , 0x0013 ) ;
F_11 ( V_1 ) ;
F_13 ( V_1 , V_1 -> V_28 ) ;
F_16 ( V_1 ) ;
F_13 ( V_1 , V_27 ) ;
F_16 ( V_1 ) ;
F_12 ( V_1 ) ;
F_11 ( V_1 ) ;
F_13 ( V_1 , V_1 -> V_28 + 1 ) ;
F_16 ( V_1 ) ;
F_14 ( V_1 , & V_7 ) ;
F_15 ( V_1 ) ;
F_12 ( V_1 ) ;
F_5 ( V_1 , 0x0030 ) ;
if ( V_1 -> V_5 . V_9 >= 0 ) {
V_8 = V_7 ;
F_17 ( V_25 , L_6 , V_27 , V_7 ) ;
} else
F_17 ( V_30 , L_7 , V_27 ) ;
return V_8 ;
}
static void F_20 ( struct V_1 * V_1 )
{
F_10 ( V_1 , 0x00 , 0xff00 ) ;
F_10 ( V_1 , 0x00 , 0xbf17 ) ;
F_10 ( V_1 , 0x00 , 0xbf10 ) ;
F_10 ( V_1 , 0x01 , 0x0010 ) ;
F_10 ( V_1 , 0x01 , 0x0000 ) ;
F_10 ( V_1 , 0x01 , 0x0010 ) ;
F_10 ( V_1 , 0x01 , 0x0030 ) ;
V_1 -> V_31 = 1 ;
}
static void F_21 ( struct V_1 * V_1 )
{
unsigned long V_32 = V_1 -> V_33 ? ( 352 * 288 * 2 ) : ( 640 * 480 * 2 ) ,
y0 = 0x0000 ,
V_34 = y0 + V_32 / 2 ,
V_35 = V_34 + V_32 / 4 ,
y1 = V_35 + V_32 / 4 ,
V_36 = y1 + V_32 / 2 ,
V_37 = V_36 + V_32 / 4 ;
F_10 ( V_1 , 0x00 , 0xff00 ) ;
F_10 ( V_1 , 0x00 , 0xbf10 ) ;
F_10 ( V_1 , 0x03 , 0x405d ) ;
F_10 ( V_1 , 0x04 , 0x0030 ) ;
F_10 ( V_1 , 0x20 , y0 & 0xffff ) ;
F_10 ( V_1 , 0x21 , y0 >> 16 ) ;
F_10 ( V_1 , 0x24 , V_34 & 0xffff ) ;
F_10 ( V_1 , 0x25 , V_34 >> 16 ) ;
F_10 ( V_1 , 0x28 , V_35 & 0xffff ) ;
F_10 ( V_1 , 0x29 , V_35 >> 16 ) ;
F_10 ( V_1 , 0x22 , y1 & 0xffff ) ;
F_10 ( V_1 , 0x23 , y1 >> 16 ) ;
F_10 ( V_1 , 0x26 , V_36 & 0xffff ) ;
F_10 ( V_1 , 0x27 , V_36 >> 16 ) ;
F_10 ( V_1 , 0x2a , V_37 & 0xffff ) ;
F_10 ( V_1 , 0x2b , V_37 >> 16 ) ;
F_10 ( V_1 , 0x32 , y1 & 0xffff ) ;
F_10 ( V_1 , 0x33 , y1 >> 16 ) ;
F_10 ( V_1 , 0x34 , y1 & 0xffff ) ;
F_10 ( V_1 , 0x35 , y1 >> 16 ) ;
F_10 ( V_1 , 0x36 , 0x0000 ) ;
F_10 ( V_1 , 0x37 , 0x0804 ) ;
F_10 ( V_1 , 0x38 , 0x0000 ) ;
F_10 ( V_1 , 0x3f , 0x0000 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
int V_38 , V_39 , V_40 , V_41 , V_42 , V_43 , V_44 , V_45 ,
V_46 , V_47 ;
if ( V_1 -> V_33 ) {
V_46 = 352 ;
V_47 = 288 ;
} else {
V_46 = 640 ;
V_47 = 480 ;
}
if ( V_1 -> V_48 == V_49 ) {
if ( V_1 -> V_50 -> V_51 == 1 ) {
V_38 = 277 ;
V_39 = 37 ;
} else {
V_38 = 105 ;
V_39 = 37 ;
}
} else {
V_38 = 320 ;
V_39 = 35 ;
}
#define F_23 ( V_40 ) ((x) << 10)
V_42 = F_23 ( V_1 -> V_5 . V_52 ) / V_46 ;
V_43 = F_23 ( V_1 -> V_5 . V_53 ) / V_47 ;
V_44 = ( V_42 >= V_43 ) ? V_46 : F_23 ( V_1 -> V_5 . V_52 ) / V_43 ;
V_45 = ( V_42 >= V_43 ) ? F_23 ( V_1 -> V_5 . V_53 ) / V_42 : V_47 ;
V_1 -> V_54 = V_46 ;
V_1 -> V_55 = V_47 ;
V_40 = ( V_46 - V_44 ) / 2 ;
V_41 = ( V_47 - V_45 ) / 2 ;
F_10 ( V_1 , 0x10 , V_38 + V_40 ) ;
F_10 ( V_1 , 0x11 , V_39 + V_41 ) ;
F_10 ( V_1 , 0x12 , V_38 + V_40 + V_44 ) ;
F_10 ( V_1 , 0x13 , V_39 + V_41 + V_45 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
int V_51 , V_56 , V_57 ;
F_22 ( V_1 ) ;
F_10 ( V_1 , 0x14 , V_1 -> V_5 . V_52 ) ;
F_10 ( V_1 , 0x15 , V_1 -> V_5 . V_53 ) ;
F_10 ( V_1 , 0x30 , V_1 -> V_5 . V_52 ) ;
F_10 ( V_1 , 0x31 , V_1 -> V_5 . V_53 ) ;
if ( V_58 [ V_1 -> V_5 . V_59 ] . V_60 ==
V_61 ) {
F_10 ( V_1 , 0x2c , V_1 -> V_5 . V_52 / 2 ) ;
F_10 ( V_1 , 0x2d , V_1 -> V_5 . V_52 / 4 ) ;
} else
F_10 ( V_1 , 0x2c , V_1 -> V_5 . V_52 ) ;
F_10 ( V_1 , 0x00 , 0xbf17 ) ;
F_10 ( V_1 , 0x00 , 0xbf10 ) ;
V_51 = V_1 -> V_5 . V_52 * V_1 -> V_5 . V_53 ;
F_10 ( V_1 , 0x3d , V_51 & 0xffff ) ;
F_10 ( V_1 , 0x3e , V_51 >> 16 ) ;
if ( V_58 [ V_1 -> V_5 . V_59 ] . V_60 ==
V_61 ) {
F_25 ( V_1 -> V_62 , V_1 -> V_5 . V_53 ,
V_1 -> V_5 . V_52 , 0x22 ) ;
F_26 ( V_1 -> V_62 , F_27 ( V_1 -> V_63 ) ) ;
F_9 ( V_1 ) ;
F_28 ( V_1 -> V_63 , true ) ;
}
if ( V_1 -> V_48 == V_49 ) {
V_56 = 1 ;
V_57 = 1 ;
} else {
V_56 = 1 ;
V_57 = 0 ;
}
V_51 = ( V_56 << 12 ) | ( V_57 << 11 ) ;
if ( V_58 [ V_1 -> V_5 . V_59 ] . V_60 ==
V_61 ) {
V_51 |= 0x0003 ;
} else
V_51 |= 0x0080 ;
V_51 |= 0x8000 ;
F_10 ( V_1 , 0x16 , V_51 ) ;
V_1 -> V_5 . V_64 = 0 ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_28 ( V_1 -> V_63 , false ) ;
F_10 ( V_1 , 0x39 , 0x0000 ) ;
F_10 ( V_1 , 0x16 , 0x0000 ) ;
}
static void F_30 ( struct V_5 * V_5 ,
T_2 * V_2 ,
int V_65 )
{
struct V_1 * V_1 = (struct V_1 * ) V_5 ;
if ( V_58 [ V_5 -> V_59 ] . V_60 ==
V_61 ) {
if ( V_65 >= 2 &&
V_2 [ 0 ] == 0xff &&
V_2 [ 1 ] == 0xd8 ) {
F_31 ( V_5 , V_66 ,
NULL , 0 ) ;
F_31 ( V_5 , V_67 ,
V_1 -> V_62 , V_68 ) ;
V_65 -= 2 ;
V_2 += 2 ;
}
} else {
if ( V_5 -> V_64 ) {
F_31 ( V_5 , V_66 ,
NULL , 0 ) ;
F_31 ( V_5 , V_67 ,
NULL , 0 ) ;
V_5 -> V_64 = 0 ;
}
}
F_31 ( V_5 , V_69 , V_2 , V_65 ) ;
}
