static T_1 F_1 ( struct V_1 * V_1 ,
T_2 V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
int V_5 ;
if ( V_1 -> V_6 < 0 )
return 0 ;
V_5 = F_2 ( V_4 , F_3 ( V_4 , 0 ) ,
0x00 ,
V_7 | V_8 | V_9 ,
0x00 ,
V_2 ,
V_1 -> V_10 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_1 , V_5 ) ;
V_1 -> V_6 = V_5 ;
return 0 ;
}
return V_1 -> V_10 [ 0 ] ;
}
static void F_5 ( struct V_1 * V_1 ,
T_2 V_2 , T_2 V_11 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_2 ( V_4 , F_6 ( V_4 , 0 ) ,
0x01 ,
V_12 | V_8 | V_9 ,
V_11 ,
V_2 ,
NULL ,
0 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
int V_13 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
int V_14 , V_5 ;
F_5 ( V_1 , 0x634 , ( V_13 >> 16 ) & 0xff ) ;
F_5 ( V_1 , 0x635 , ( V_13 >> 8 ) & 0xff ) ;
F_5 ( V_1 , 0x636 , V_13 & 0xff ) ;
F_5 ( V_1 , 0x637 , 0 ) ;
F_5 ( V_1 , 0x638 , 4 ) ;
F_5 ( V_1 , 0x639 , 0 ) ;
F_5 ( V_1 , 0x63a , 0 ) ;
F_5 ( V_1 , 0x63b , 0 ) ;
F_5 ( V_1 , 0x630 , 5 ) ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_8 ( V_4 ,
F_9 ( V_4 , 0x05 ) ,
V_1 -> V_10 ,
4 ,
& V_14 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_3 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_10 ( struct V_1 * V_1 ,
int V_13 ,
unsigned int V_15 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
int V_14 , V_5 ;
T_3 V_16 = 0 ;
if ( V_13 == 0x003f08 ) {
F_1 ( V_1 , 0x0704 ) ;
V_16 = F_1 ( V_1 , 0x0705 ) ;
F_1 ( V_1 , 0x0650 ) ;
F_5 ( V_1 , 0x654 , V_16 ) ;
} else {
F_5 ( V_1 , 0x654 , ( V_13 >> 16 ) & 0xff ) ;
}
F_5 ( V_1 , 0x655 , ( V_13 >> 8 ) & 0xff ) ;
F_5 ( V_1 , 0x656 , V_13 & 0xff ) ;
F_5 ( V_1 , 0x657 , 0 ) ;
F_5 ( V_1 , 0x658 , 0x04 ) ;
F_5 ( V_1 , 0x659 , 0 ) ;
F_5 ( V_1 , 0x65a , 0 ) ;
F_5 ( V_1 , 0x65b , 0 ) ;
F_5 ( V_1 , 0x650 , 5 ) ;
if ( V_1 -> V_6 < 0 )
return;
V_1 -> V_10 [ 0 ] = V_15 >> 24 ;
V_1 -> V_10 [ 1 ] = V_15 >> 16 ;
V_1 -> V_10 [ 2 ] = V_15 >> 8 ;
V_1 -> V_10 [ 3 ] = V_15 ;
V_5 = F_8 ( V_4 ,
F_11 ( V_4 , 6 ) ,
V_1 -> V_10 ,
4 ,
& V_14 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_4 , V_5 ) ;
V_1 -> V_6 = V_5 ;
} else {
if ( V_13 == 0x003f08 ) {
V_16 += 4 ;
V_16 &= 0x3f ;
F_5 ( V_1 , 0x705 , V_16 ) ;
}
}
}
static void F_12 ( struct V_1 * V_1 ,
int V_17 )
{
F_10 ( V_1 , 0x003f08 , V_17 ) ;
}
static void F_13 ( struct V_1 * V_1 , T_4 V_15 )
{
int V_17 ;
V_17 = 0x06000000
+ ( V_15 << 16 ) ;
F_12 ( V_1 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_1 , T_4 V_15 )
{
int V_17 ;
V_17 = 0x07000000
+ ( V_15 << 16 ) ;
F_12 ( V_1 , V_17 ) ;
}
static void F_15 ( struct V_1 * V_1 , T_4 V_15 )
{
int V_17 ;
V_17 = 0x08000000
+ ( V_15 << 16 ) ;
F_12 ( V_1 , V_17 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_4 V_15 )
{
F_12 ( V_1 , V_15 == 1
? 0x33640000
: 0x33780000 ) ;
}
static int F_17 ( struct V_1 * V_1 ,
const struct V_18 * V_19 )
{
V_1 -> V_20 . V_21 = V_22 ;
V_1 -> V_20 . V_23 = F_18 ( V_22 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
T_1 V_5 ;
F_20 ( V_1 -> V_4 , V_1 -> V_24 , 1 ) ;
V_5 = F_1 ( V_1 , 0x0740 ) ;
if ( V_1 -> V_6 >= 0 ) {
if ( V_5 != 0xff ) {
F_4 ( L_5 , V_5 ) ;
V_1 -> V_6 = - V_25 ;
}
}
return V_1 -> V_6 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_26 * V_26 = (struct V_26 * ) V_1 ;
int V_5 , V_11 ;
F_22 ( V_26 -> V_27 , V_1 -> V_28 . V_29 ,
V_1 -> V_28 . V_30 ,
0x22 ) ;
F_23 ( V_26 -> V_27 , V_31 ) ;
F_20 ( V_1 -> V_4 , V_1 -> V_24 , 1 ) ;
F_12 ( V_1 , 0x10000000 ) ;
F_12 ( V_1 , 0x00000000 ) ;
F_12 ( V_1 , 0x8002e001 ) ;
F_12 ( V_1 , 0x14000000 ) ;
if ( V_1 -> V_28 . V_30 > 320 )
V_11 = 0x8002e001 ;
else
V_11 = 0x4001f000 ;
F_12 ( V_1 , V_11 ) ;
V_5 = F_20 ( V_1 -> V_4 ,
V_1 -> V_24 ,
V_1 -> V_32 ) ;
if ( V_5 < 0 ) {
F_4 ( L_6 ,
V_1 -> V_24 , V_1 -> V_32 ) ;
V_1 -> V_6 = V_5 ;
goto V_33;
}
F_1 ( V_1 , 0x0630 ) ;
F_7 ( V_1 , 0x000020 ) ;
F_1 ( V_1 , 0x0650 ) ;
F_10 ( V_1 , 0x000020 , 0xffffffff ) ;
F_5 ( V_1 , 0x0620 , 0 ) ;
F_5 ( V_1 , 0x0630 , 0 ) ;
F_5 ( V_1 , 0x0640 , 0 ) ;
F_5 ( V_1 , 0x0650 , 0 ) ;
F_5 ( V_1 , 0x0660 , 0 ) ;
F_12 ( V_1 , 0x09800000 ) ;
F_12 ( V_1 , 0x0a800000 ) ;
F_12 ( V_1 , 0x0b800000 ) ;
F_12 ( V_1 , 0x0d030000 ) ;
F_12 ( V_1 , 0x01000000 ) ;
F_12 ( V_1 , 0x01000000 ) ;
if ( V_1 -> V_6 >= 0 )
F_24 ( V_34 , L_7 ,
V_1 -> V_32 ) ;
V_33:
return V_1 -> V_6 ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_12 ( V_1 , 0x02000000 ) ;
F_12 ( V_1 , 0x02000000 ) ;
F_20 ( V_4 , V_1 -> V_24 , 1 ) ;
F_1 ( V_1 , 0x0630 ) ;
F_7 ( V_1 , 0x000020 ) ;
F_1 ( V_1 , 0x0650 ) ;
F_10 ( V_1 , 0x000020 , 0xffffffff ) ;
F_5 ( V_1 , 0x0620 , 0 ) ;
F_5 ( V_1 , 0x0630 , 0 ) ;
F_5 ( V_1 , 0x0640 , 0 ) ;
F_5 ( V_1 , 0x0650 , 0 ) ;
F_5 ( V_1 , 0x0660 , 0 ) ;
F_24 ( V_34 , L_8 ) ;
}
static void F_26 ( struct V_1 * V_1 ,
T_1 * V_35 ,
int V_36 )
{
struct V_26 * V_26 = (struct V_26 * ) V_1 ;
static unsigned char V_37 [] = { 0xff , 0xd9 } ;
if ( V_35 [ 0 ] == 0xff && V_35 [ 1 ] == 0xfe ) {
F_27 ( V_1 , V_38 ,
V_37 , 2 ) ;
F_27 ( V_1 , V_39 ,
V_26 -> V_27 , V_40 ) ;
#define F_28 12
V_35 += F_28 ;
V_36 -= F_28 ;
}
F_27 ( V_1 , V_41 , V_35 , V_36 ) ;
}
static int F_29 ( struct V_42 * V_43 )
{
struct V_1 * V_1 =
F_30 ( V_43 -> V_44 , struct V_1 , V_45 ) ;
V_1 -> V_6 = 0 ;
if ( ! V_1 -> V_46 )
return 0 ;
switch ( V_43 -> V_19 ) {
case V_47 :
F_13 ( V_1 , V_43 -> V_15 ) ;
break;
case V_48 :
F_14 ( V_1 , V_43 -> V_15 ) ;
break;
case V_49 :
F_15 ( V_1 , V_43 -> V_15 ) ;
break;
case V_50 :
F_16 ( V_1 , V_43 -> V_15 ) ;
break;
}
return V_1 -> V_6 ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_45 ;
V_1 -> V_53 . V_45 = V_52 ;
F_32 ( V_52 , 4 ) ;
F_33 ( V_52 , & V_54 ,
V_47 , 0 , 255 , 1 , 127 ) ;
F_33 ( V_52 , & V_54 ,
V_48 , 0 , 255 , 1 , 127 ) ;
F_33 ( V_52 , & V_54 ,
V_49 , 0 , 255 , 1 , 127 ) ;
F_34 ( V_52 , & V_54 ,
V_50 ,
V_55 , 1 ,
V_56 ) ;
if ( V_52 -> error ) {
F_4 ( L_9 ) ;
return V_52 -> error ;
}
return 0 ;
}
static int F_35 ( struct V_57 * V_58 ,
const struct V_18 * V_19 )
{
return F_36 ( V_58 , V_19 , & V_59 , sizeof( struct V_26 ) ,
V_60 ) ;
}
