static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
V_2 ,
V_6 | V_7 | V_8 ,
0 ,
V_3 , V_1 -> V_9 , V_4 ,
500 ) ;
}
static void F_4 ( struct V_10 * V_5 ,
T_1 V_2 ,
T_1 V_11 ,
T_1 V_3 )
{
F_2 ( V_5 ,
F_5 ( V_5 , 0 ) ,
V_2 ,
V_12 | V_7 | V_8 ,
V_11 , V_3 ,
NULL , 0 , 500 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_4 ( V_1 -> V_5 , 0x07 , V_13 , 0x0004 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_14 ,
T_1 V_15 )
{
int V_16 = 60 ;
F_4 ( V_1 -> V_5 , 0x07 , V_15 , 0x0001 ) ;
F_4 ( V_1 -> V_5 , 0x07 , V_14 , 0x0000 ) ;
while ( V_16 -- ) {
F_1 ( V_1 , 0x07 , 0x0003 , 2 ) ;
if ( ( V_1 -> V_9 [ 0 ] | V_1 -> V_9 [ 1 ] ) == 0x00 )
break;
}
}
static void F_8 ( struct V_1 * V_1 ,
T_1 V_17 ,
T_1 V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
T_2 V_20 = 0x00 ;
T_2 V_21 = 0x00 ;
T_2 V_22 = 0x00 ;
F_9 ( V_23 , L_1 ) ;
F_6 ( V_1 ) ;
if ( V_17 & V_24 )
V_20 = 0x01 ;
if ( V_18 == 4 || V_18 == 5 || V_18 > 9 )
V_18 = 0 ;
if ( V_18 < 4 )
V_21 = 0x02 ;
V_22 = ( 0x48 | V_20 | V_21 ) ;
F_4 ( V_1 -> V_5 , 0x08 , V_22 , 0x0000 ) ;
F_7 ( V_1 , ( 0xc0 | ( V_18 & 0x0F ) ) , 0x02 ) ;
if ( V_17 & V_24 )
F_7 ( V_1 , 0x33 , 0x0e ) ;
else if ( V_17 & V_25 )
F_7 ( V_1 , 0x53 , 0x0e ) ;
else
F_7 ( V_1 , 0x03 , 0x0e ) ;
V_19 -> V_17 = V_17 ;
V_19 -> V_18 = V_18 ;
F_9 ( V_23 , L_2 , V_22 ) ;
F_9 ( V_23 , L_3 , V_17 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_1 ,
T_1 * V_17 , T_1 * V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_17 = V_19 -> V_17 ;
* V_18 = V_19 -> V_18 ;
F_9 ( V_23 , L_4 , * V_17 , * V_18 ) ;
}
static void F_11 ( struct V_1 * V_1 , T_1 V_26 ,
T_1 V_27 , T_1 V_28 )
{
struct V_10 * V_5 = V_1 -> V_5 ;
F_9 ( V_23 , L_5 ) ;
F_4 ( V_5 , 0x04 , ( 0x18 | ( V_26 & 0x07 ) ) , 0x0000 ) ;
F_4 ( V_5 , 0x04 , 0x41 , 0x0001 ) ;
F_4 ( V_5 , 0x04 , 0x00 , 0x0002 ) ;
F_4 ( V_5 , 0x04 , 0x00 , 0x0003 ) ;
F_4 ( V_5 , 0x04 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x04 , 0x01 , 0x0005 ) ;
F_4 ( V_5 , 0x04 , V_27 , 0x0006 ) ;
F_4 ( V_5 , 0x04 , V_28 , 0x0007 ) ;
F_4 ( V_5 , 0x04 , 0x00 , 0x0008 ) ;
F_4 ( V_5 , 0x04 , 0x00 , 0x0009 ) ;
F_4 ( V_5 , 0x04 , 0x21 , 0x000a ) ;
F_4 ( V_5 , 0x04 , 0x00 , 0x000b ) ;
}
static int F_12 ( struct V_1 * V_1 ,
const struct V_29 * V_30 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
struct V_31 * V_31 ;
V_31 = & V_1 -> V_31 ;
V_31 -> V_32 = V_33 ;
V_31 -> V_34 = F_13 ( V_33 ) ;
V_19 -> V_35 = V_36 [ V_37 ] . V_38 . V_39 ;
V_19 -> V_40 = V_36 [ V_41 ] . V_38 . V_39 ;
V_19 -> V_42 = V_36 [ V_43 ] . V_38 . V_39 ;
V_19 -> V_44 = V_36 [ V_45 ] . V_38 . V_39 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_10 * V_5 = V_1 -> V_5 ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x03 , 0xFF , 0x0003 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0000 ) ;
F_4 ( V_5 , 0x03 , 0x1c , 0x0001 ) ;
F_4 ( V_5 , 0x03 , 0x18 , 0x0001 ) ;
F_8 ( V_1 , 0 , 0 ) ;
F_4 ( V_5 , 0x03 , 0x1c , 0x0001 ) ;
F_4 ( V_5 , 0x03 , 0x18 , 0x0001 ) ;
F_4 ( V_5 , 0x05 , 0x00 , 0x0000 ) ;
F_4 ( V_5 , 0x05 , 0xef , 0x0001 ) ;
F_4 ( V_5 , 0x05 , 0x00 , 0x00c1 ) ;
F_4 ( V_5 , 0x05 , 0x00 , 0x00c2 ) ;
F_4 ( V_5 , 0x06 , 0x18 , 0x0002 ) ;
F_4 ( V_5 , 0x06 , 0xf5 , 0x0011 ) ;
F_4 ( V_5 , 0x06 , 0x02 , 0x0012 ) ;
F_4 ( V_5 , 0x06 , 0xfb , 0x0013 ) ;
F_4 ( V_5 , 0x06 , 0x00 , 0x0014 ) ;
F_4 ( V_5 , 0x06 , 0xa4 , 0x0051 ) ;
F_4 ( V_5 , 0x06 , 0x40 , 0x0052 ) ;
F_4 ( V_5 , 0x06 , 0x71 , 0x0053 ) ;
F_4 ( V_5 , 0x06 , 0x40 , 0x0054 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0003 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x03 , 0xFF , 0x0003 ) ;
F_4 ( V_5 , 0x02 , 0x00 , 0x0000 ) ;
F_4 ( V_5 , 0x03 , 0x60 , 0x0000 ) ;
F_4 ( V_5 , 0x03 , 0x18 , 0x0001 ) ;
F_6 ( V_1 ) ;
F_7 ( V_1 , 0x08 , 0x01 ) ;
F_7 ( V_1 , 0xc0 , 0x02 ) ;
F_7 ( V_1 , 0x33 , 0x03 ) ;
F_7 ( V_1 , 0x00 , 0x04 ) ;
F_7 ( V_1 , 0x00 , 0x05 ) ;
F_7 ( V_1 , 0x0d , 0x06 ) ;
F_7 ( V_1 , 0xf0 , 0x07 ) ;
F_7 ( V_1 , 0x98 , 0x08 ) ;
F_7 ( V_1 , 0x03 , 0x09 ) ;
F_7 ( V_1 , 0x80 , 0x0a ) ;
F_7 ( V_1 , 0x47 , 0x0b ) ;
F_7 ( V_1 , 0x48 , 0x0c ) ;
F_7 ( V_1 , 0x00 , 0x0d ) ;
F_7 ( V_1 , 0x03 , 0x0e ) ;
F_7 ( V_1 , 0x2a , 0x0f ) ;
F_7 ( V_1 , 0x00 , 0x10 ) ;
F_7 ( V_1 , 0x0c , 0x11 ) ;
F_7 ( V_1 , 0xb8 , 0x12 ) ;
F_7 ( V_1 , 0x01 , 0x13 ) ;
F_7 ( V_1 , 0x00 , 0x14 ) ;
F_7 ( V_1 , 0x00 , 0x15 ) ;
F_7 ( V_1 , 0x00 , 0x16 ) ;
F_7 ( V_1 , 0x00 , 0x17 ) ;
F_7 ( V_1 , 0x00 , 0x18 ) ;
F_7 ( V_1 , 0x00 , 0x19 ) ;
F_7 ( V_1 , 0x00 , 0x1a ) ;
F_7 ( V_1 , 0x00 , 0x1b ) ;
F_7 ( V_1 , 0x00 , 0x1c ) ;
F_7 ( V_1 , 0x00 , 0x1d ) ;
F_7 ( V_1 , 0x00 , 0x1e ) ;
F_7 ( V_1 , 0xa1 , 0x1f ) ;
F_7 ( V_1 , 0x02 , 0x40 ) ;
F_7 ( V_1 , 0xff , 0x41 ) ;
F_7 ( V_1 , 0xff , 0x42 ) ;
F_7 ( V_1 , 0xff , 0x43 ) ;
F_7 ( V_1 , 0xff , 0x44 ) ;
F_7 ( V_1 , 0xff , 0x45 ) ;
F_7 ( V_1 , 0xff , 0x46 ) ;
F_7 ( V_1 , 0xff , 0x47 ) ;
F_7 ( V_1 , 0xff , 0x48 ) ;
F_7 ( V_1 , 0xff , 0x49 ) ;
F_7 ( V_1 , 0xff , 0x4a ) ;
F_7 ( V_1 , 0xff , 0x4b ) ;
F_7 ( V_1 , 0xff , 0x4c ) ;
F_7 ( V_1 , 0xff , 0x4d ) ;
F_7 ( V_1 , 0xff , 0x4e ) ;
F_7 ( V_1 , 0xff , 0x4f ) ;
F_7 ( V_1 , 0xff , 0x50 ) ;
F_7 ( V_1 , 0xff , 0x51 ) ;
F_7 ( V_1 , 0xff , 0x52 ) ;
F_7 ( V_1 , 0xff , 0x53 ) ;
F_7 ( V_1 , 0xff , 0x54 ) ;
F_7 ( V_1 , 0xff , 0x55 ) ;
F_7 ( V_1 , 0xff , 0x56 ) ;
F_7 ( V_1 , 0xff , 0x57 ) ;
F_7 ( V_1 , 0x00 , 0x58 ) ;
F_7 ( V_1 , 0x54 , 0x59 ) ;
F_7 ( V_1 , 0x07 , 0x5a ) ;
F_7 ( V_1 , 0x83 , 0x5b ) ;
F_7 ( V_1 , 0x00 , 0x5c ) ;
F_7 ( V_1 , 0x00 , 0x5d ) ;
F_7 ( V_1 , 0x00 , 0x5e ) ;
F_7 ( V_1 , 0x00 , 0x5f ) ;
F_7 ( V_1 , 0x00 , 0x60 ) ;
F_7 ( V_1 , 0x05 , 0x61 ) ;
F_7 ( V_1 , 0x9f , 0x62 ) ;
F_9 ( V_23 , L_6 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_10 * V_5 = V_1 -> V_5 ;
T_1 V_17 ;
T_1 V_18 ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0003 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x03 , 0xFF , 0x0003 ) ;
F_4 ( V_5 , 0x02 , 0x00 , 0x0000 ) ;
F_4 ( V_5 , 0x03 , 0x60 , 0x0000 ) ;
F_4 ( V_5 , 0x03 , 0x18 , 0x0001 ) ;
F_6 ( V_1 ) ;
F_7 ( V_1 , 0x08 , 0x01 ) ;
F_7 ( V_1 , 0x33 , 0x03 ) ;
F_7 ( V_1 , 0x00 , 0x04 ) ;
F_7 ( V_1 , 0x00 , 0x05 ) ;
F_7 ( V_1 , 0x0d , 0x06 ) ;
F_7 ( V_1 , 0xf0 , 0x07 ) ;
F_7 ( V_1 , 0x98 , 0x08 ) ;
F_7 ( V_1 , 0x03 , 0x09 ) ;
F_7 ( V_1 , 0x80 , 0x0a ) ;
F_7 ( V_1 , 0x47 , 0x0b ) ;
F_7 ( V_1 , 0x48 , 0x0c ) ;
F_7 ( V_1 , 0x00 , 0x0d ) ;
F_7 ( V_1 , 0x2a , 0x0f ) ;
F_7 ( V_1 , 0x00 , 0x10 ) ;
F_7 ( V_1 , 0x0c , 0x11 ) ;
F_7 ( V_1 , 0xb8 , 0x12 ) ;
F_7 ( V_1 , 0x01 , 0x13 ) ;
F_7 ( V_1 , 0x00 , 0x14 ) ;
F_7 ( V_1 , 0x00 , 0x15 ) ;
F_7 ( V_1 , 0x00 , 0x16 ) ;
F_7 ( V_1 , 0x00 , 0x17 ) ;
F_7 ( V_1 , 0x00 , 0x18 ) ;
F_7 ( V_1 , 0x00 , 0x19 ) ;
F_7 ( V_1 , 0x00 , 0x1a ) ;
F_7 ( V_1 , 0x00 , 0x1b ) ;
F_7 ( V_1 , 0x00 , 0x1c ) ;
F_7 ( V_1 , 0x00 , 0x1d ) ;
F_7 ( V_1 , 0x00 , 0x1e ) ;
F_7 ( V_1 , 0xa1 , 0x1f ) ;
F_7 ( V_1 , 0x02 , 0x40 ) ;
F_7 ( V_1 , 0xff , 0x41 ) ;
F_7 ( V_1 , 0xff , 0x42 ) ;
F_7 ( V_1 , 0xff , 0x43 ) ;
F_7 ( V_1 , 0xff , 0x44 ) ;
F_7 ( V_1 , 0xff , 0x45 ) ;
F_7 ( V_1 , 0xff , 0x46 ) ;
F_7 ( V_1 , 0xff , 0x47 ) ;
F_7 ( V_1 , 0xff , 0x48 ) ;
F_7 ( V_1 , 0xff , 0x49 ) ;
F_7 ( V_1 , 0xff , 0x4a ) ;
F_7 ( V_1 , 0xff , 0x4b ) ;
F_7 ( V_1 , 0xff , 0x4c ) ;
F_7 ( V_1 , 0xff , 0x4d ) ;
F_7 ( V_1 , 0xff , 0x4e ) ;
F_7 ( V_1 , 0xff , 0x4f ) ;
F_7 ( V_1 , 0xff , 0x50 ) ;
F_7 ( V_1 , 0xff , 0x51 ) ;
F_7 ( V_1 , 0xff , 0x52 ) ;
F_7 ( V_1 , 0xff , 0x53 ) ;
F_7 ( V_1 , 0xff , 0x54 ) ;
F_7 ( V_1 , 0xff , 0x55 ) ;
F_7 ( V_1 , 0xff , 0x56 ) ;
F_7 ( V_1 , 0xff , 0x57 ) ;
F_7 ( V_1 , 0x00 , 0x58 ) ;
F_7 ( V_1 , 0x54 , 0x59 ) ;
F_7 ( V_1 , 0x07 , 0x5a ) ;
F_7 ( V_1 , 0x83 , 0x5b ) ;
F_7 ( V_1 , 0x00 , 0x5c ) ;
F_7 ( V_1 , 0x00 , 0x5d ) ;
F_7 ( V_1 , 0x00 , 0x5e ) ;
F_7 ( V_1 , 0x00 , 0x5f ) ;
F_7 ( V_1 , 0x00 , 0x60 ) ;
F_7 ( V_1 , 0x05 , 0x61 ) ;
F_7 ( V_1 , 0x9f , 0x62 ) ;
F_4 ( V_5 , 0x05 , 0x00 , 0x0003 ) ;
F_4 ( V_5 , 0x05 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x03 , 0x10 , 0x0001 ) ;
F_4 ( V_5 , 0x03 , 0x78 , 0x0000 ) ;
switch ( V_1 -> V_31 . V_32 [ ( int ) V_1 -> V_46 ] . V_47 ) {
case 0 :
F_11 ( V_1 , 0 , 0x10 , 0x10 ) ;
break;
case 1 :
F_11 ( V_1 , 1 , 0x1a , 0x1a ) ;
break;
case 2 :
F_11 ( V_1 , 2 , 0x1c , 0x1c ) ;
break;
case 4 :
F_11 ( V_1 , 4 , 0x34 , 0x34 ) ;
break;
default:
F_11 ( V_1 , 5 , 0x40 , 0x40 ) ;
break;
}
F_4 ( V_5 , 0x02 , 0x01 , 0x0000 ) ;
F_4 ( V_5 , 0x03 , 0x12 , 0x0000 ) ;
F_1 ( V_1 , 0x04 , 0x0001 , 2 ) ;
F_9 ( V_23 , L_7 ) ;
F_10 ( V_1 , & V_17 , & V_18 ) ;
F_8 ( V_1 , V_17 , V_18 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_10 * V_5 = V_1 -> V_5 ;
F_4 ( V_5 , 0x02 , 0x00 , 0x0000 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0004 ) ;
F_4 ( V_5 , 0x03 , 0x00 , 0x0003 ) ;
}
static void F_17 ( struct V_1 * V_1 ,
T_3 * V_48 ,
int V_49 )
{
switch ( V_48 [ 0 ] ) {
case 0 :
F_18 ( V_1 , V_50 , NULL , 0 ) ;
V_48 += V_51 ;
V_49 -= V_51 ;
F_18 ( V_1 , V_52 , V_48 , V_49 ) ;
break;
case 0xff :
break;
default:
V_48 += 1 ;
V_49 -= 1 ;
F_18 ( V_1 , V_53 , V_48 , V_49 ) ;
break;
}
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_6 ( V_1 ) ;
F_7 ( V_1 , V_19 -> V_35 , V_54 ) ;
F_7 ( V_1 , 0x01 , 0x09 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_6 ( V_1 ) ;
F_7 ( V_1 , V_19 -> V_40 , V_55 ) ;
F_7 ( V_1 , 0x01 , 0x09 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_6 ( V_1 ) ;
F_7 ( V_1 , V_19 -> V_42 , V_56 ) ;
F_7 ( V_1 , 0x01 , 0x09 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
F_6 ( V_1 ) ;
F_7 ( V_1 , V_19 -> V_44 , V_57 ) ;
F_7 ( V_1 , 0x01 , 0x09 ) ;
}
static int F_23 ( struct V_1 * V_1 , T_4 V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_35 = V_58 ;
if ( V_1 -> V_59 )
F_19 ( V_1 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , T_4 * V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_58 = V_19 -> V_35 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 , T_4 V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_40 = V_58 ;
if ( V_1 -> V_59 )
F_20 ( V_1 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , T_4 * V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_58 = V_19 -> V_40 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 , T_4 V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_42 = V_58 ;
if ( V_1 -> V_59 )
F_21 ( V_1 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , T_4 * V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_58 = V_19 -> V_42 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , T_4 V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
V_19 -> V_44 = V_58 ;
if ( V_1 -> V_59 )
F_22 ( V_1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_4 * V_58 )
{
struct V_19 * V_19 = (struct V_19 * ) V_1 ;
* V_58 = V_19 -> V_44 ;
return 0 ;
}
static int T_5 F_31 ( struct V_60 * V_61 ,
const struct V_29 * V_30 )
{
return F_32 ( V_61 , V_30 , & V_62 , sizeof( struct V_19 ) ,
V_63 ) ;
}
static int T_6 F_33 ( void )
{
int V_64 ;
V_64 = F_34 ( & V_65 ) ;
if ( V_64 < 0 )
return V_64 ;
F_9 ( V_66 , L_8 ) ;
return 0 ;
}
static void T_7 F_35 ( void )
{
F_36 ( & V_65 ) ;
F_9 ( V_66 , L_9 ) ;
}
