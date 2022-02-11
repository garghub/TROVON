static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_3 , int V_4 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
memcpy ( V_1 -> V_7 , V_3 , V_4 ) ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 ,
V_2 , V_1 -> V_7 , V_4 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_1 ,
V_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_5 ( struct V_1 * V_1 ,
T_1 V_2 ,
T_1 V_12 )
{
int V_5 ;
if ( V_1 -> V_6 < 0 )
return;
V_1 -> V_7 [ 0 ] = V_12 ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 , V_2 , V_1 -> V_7 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_2 ,
V_2 , V_12 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_6 ( struct V_1 * V_1 ,
const T_1 * V_13 , int V_4 )
{
while ( -- V_4 >= 0 ) {
F_5 ( V_1 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
V_13 += 2 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
const T_1 * V_14 , int V_4 )
{
int V_2 ;
int V_5 = 0 ;
if ( V_1 -> V_6 < 0 )
return;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( V_14 [ V_2 ] == V_15 )
continue;
V_1 -> V_7 [ 0 ] = V_14 [ V_2 ] ;
V_5 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
0 ,
V_9 | V_10 | V_11 ,
0 , V_2 , V_1 -> V_7 , 1 ,
500 ) ;
if ( V_5 < 0 ) {
F_4 ( L_3 ,
V_2 , V_14 [ V_2 ] , V_5 ) ;
V_1 -> V_6 = V_5 ;
break;
}
}
}
static void F_8 ( struct V_1 * V_1 ,
const T_1 * V_13 ,
const T_1 * V_16 , unsigned int V_17 )
{
int V_2 , V_4 ;
for (; ; ) {
V_2 = * V_13 ++ ;
V_4 = * V_13 ++ ;
switch ( V_4 ) {
case V_18 :
return;
case V_19 :
F_7 ( V_1 , V_16 , V_17 ) ;
break;
default:
if ( V_4 > V_20 ) {
F_9 ( V_21 | V_22 ,
L_4 ) ;
return;
}
while ( V_4 > 0 ) {
if ( V_4 < 8 ) {
F_1 ( V_1 ,
V_2 , V_13 , V_4 ) ;
V_13 += V_4 ;
break;
}
F_1 ( V_1 , V_2 , V_13 , 8 ) ;
V_13 += 8 ;
V_2 += 8 ;
V_4 -= 8 ;
}
}
}
}
static int F_10 ( struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
struct V_26 * V_26 ;
V_26 = & V_1 -> V_26 ;
F_9 ( V_27 , L_5 ) ;
V_26 -> V_28 = V_29 ;
V_26 -> V_30 = F_11 ( V_29 ) ;
V_25 -> V_31 = V_32 ;
V_25 -> V_33 = V_34 ;
V_25 -> V_35 = V_36 ;
V_25 -> V_37 = V_38 ;
V_25 -> V_39 = V_40 ;
V_25 -> V_41 = V_42 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x10 , V_25 -> V_31 >> 4 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_33 = V_43 - V_25 -> V_33 ;
if ( V_33 < 1 )
V_33 = 1 ;
else if ( V_33 > 245 )
V_33 = 245 ;
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x0e , 0x00 ) ;
F_5 ( V_1 , 0x0f , V_33 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_44 ;
V_44 = 120 * V_25 -> V_35 / 1000 ;
if ( V_44 < 2 )
V_44 = 2 ;
else if ( V_44 > 63 )
V_44 = 63 ;
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x02 , V_44 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
if ( V_1 -> V_26 . V_28 [ ( int ) V_1 -> V_45 ] . V_46 &&
V_44 <= 3 ) {
F_5 ( V_1 , 0x08 , 0x09 ) ;
} else {
F_5 ( V_1 , 0x08 , 0x08 ) ;
}
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_1 V_47 ;
F_5 ( V_1 , 0xff , 0x04 ) ;
V_47 = ( V_25 -> V_39 ? 0x04 : 0x00 ) | ( V_25 -> V_41 ? 0x08 : 0x00 ) ;
F_5 ( V_1 , 0x21 , V_47 ) ;
F_5 ( V_1 , 0x11 , 0x01 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_48 , sizeof( V_48 ) / 2 ) ;
return V_1 -> V_6 ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_49 = 0 ;
F_8 ( V_1 , V_50 ,
V_51 , sizeof( V_51 ) ) ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
switch ( V_1 -> V_26 . V_28 [ ( int ) V_1 -> V_45 ] . V_46 ) {
case 2 :
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x17 , 0x20 ) ;
F_5 ( V_1 , 0x87 , 0x10 ) ;
break;
case 1 :
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x17 , 0x30 ) ;
F_5 ( V_1 , 0x87 , 0x11 ) ;
break;
case 0 :
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x17 , 0x00 ) ;
F_5 ( V_1 , 0x87 , 0x12 ) ;
break;
}
V_25 -> V_49 = 0 ;
V_25 -> V_52 = 0 ;
F_18 ( & V_25 -> V_53 , - 1 ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x78 , 0x05 ) ;
return V_1 -> V_6 ;
}
static void F_19 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0xff , 0x04 ) ;
F_5 ( V_1 , 0x27 , 0x80 ) ;
F_5 ( V_1 , 0x28 , 0xca ) ;
F_5 ( V_1 , 0x29 , 0x53 ) ;
F_5 ( V_1 , 0x2a , 0x0e ) ;
F_5 ( V_1 , 0xff , 0x01 ) ;
F_5 ( V_1 , 0x3e , 0x20 ) ;
F_5 ( V_1 , 0x78 , 0x44 ) ;
F_5 ( V_1 , 0x78 , 0x44 ) ;
F_5 ( V_1 , 0x78 , 0x44 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
int V_53 = F_22 ( & V_25 -> V_53 ) ;
int V_54 , V_55 ;
if ( V_53 == - 1 )
return;
V_54 = 200 ;
V_55 = 20 ;
if ( V_25 -> V_52 > 0 )
V_25 -> V_52 -- ;
else if ( F_23 ( V_1 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) )
V_25 -> V_52 = V_58 ;
}
static void F_24 ( struct V_1 * V_1 ,
T_3 V_59 , T_3 V_60 )
{
unsigned char V_61 [ 4 ] ;
F_25 ( V_1 , V_62 ,
V_63 , sizeof( V_63 ) ) ;
V_61 [ 0 ] = V_59 >> 8 ;
V_61 [ 1 ] = V_59 & 0xff ;
V_61 [ 2 ] = V_60 >> 8 ;
V_61 [ 3 ] = V_60 & 0xff ;
F_25 ( V_1 , V_64 ,
V_61 , sizeof( V_61 ) ) ;
F_25 ( V_1 , V_64 ,
V_65 , sizeof( V_65 ) ) ;
}
static void F_26 ( struct V_1 * V_1 ,
T_2 * V_47 ,
int V_4 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
T_2 * V_66 ;
unsigned char * V_67 ;
V_67 = F_27 ( & V_25 -> V_49 , V_47 , V_4 ) ;
if ( V_67 ) {
int V_68 , V_69 , V_70 ;
V_69 = 24 + sizeof F_28 ;
V_70 = 26 ;
V_68 = ( V_67 - V_47 ) - ( V_70 + sizeof F_28 ) ;
if ( V_68 < 0 ) {
V_1 -> V_71 += V_68 ;
V_68 = 0 ;
} else {
F_25 ( V_1 , V_64 , V_47 , V_68 ) ;
}
V_66 = V_1 -> V_66 ;
if ( V_66 != NULL
&& V_66 [ V_1 -> V_71 - 2 ] == 0xff
&& V_66 [ V_1 -> V_71 - 1 ] == 0xd9 )
F_25 ( V_1 , V_72 , NULL , 0 ) ;
V_68 = V_67 - V_47 ;
V_4 -= V_68 ;
V_47 = V_67 ;
if ( V_1 -> V_73 == V_72 &&
V_68 >= V_69 )
F_18 ( & V_25 -> V_53 , V_47 [ - V_69 ] +
V_47 [ - V_69 + 1 ] ) ;
else
F_18 ( & V_25 -> V_53 , - 1 ) ;
F_24 ( V_1 ,
V_1 -> V_74 , V_1 -> V_75 ) ;
}
F_25 ( V_1 , V_64 , V_47 , V_4 ) ;
}
static int F_29 ( struct V_1 * V_1 , T_4 V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_31 = V_76 ;
if ( V_1 -> V_77 )
F_12 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_30 ( struct V_1 * V_1 , T_4 * V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_76 = V_25 -> V_31 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , T_4 V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_33 = V_76 ;
if ( V_1 -> V_77 )
F_13 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_32 ( struct V_1 * V_1 , T_4 * V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_76 = V_25 -> V_33 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , T_4 V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_35 = V_76 ;
if ( V_1 -> V_77 )
F_14 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_34 ( struct V_1 * V_1 , T_4 * V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_76 = V_25 -> V_35 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_4 V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_37 = V_76 ;
if ( V_25 -> V_37 ) {
V_25 -> V_35 = V_36 ;
V_25 -> V_33 = V_34 ;
if ( V_1 -> V_77 ) {
V_25 -> V_52 =
V_58 ;
F_14 ( V_1 ) ;
F_13 ( V_1 ) ;
}
}
return V_1 -> V_6 ;
}
static int F_36 ( struct V_1 * V_1 , T_4 * V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_76 = V_25 -> V_37 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_4 V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_39 = V_76 ;
if ( V_1 -> V_77 )
F_15 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_38 ( struct V_1 * V_1 , T_4 * V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_76 = V_25 -> V_39 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , T_4 V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
V_25 -> V_41 = V_76 ;
if ( V_1 -> V_77 )
F_15 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_40 ( struct V_1 * V_1 , T_4 * V_76 )
{
struct V_25 * V_25 = (struct V_25 * ) V_1 ;
* V_76 = V_25 -> V_41 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 ,
T_2 * V_47 ,
int V_4 )
{
int V_5 = - V_78 ;
T_2 V_79 , V_80 ;
if ( V_4 == 2 ) {
V_79 = V_47 [ 0 ] ;
V_80 = V_47 [ 1 ] ;
if ( ( V_79 == 0x00 && V_80 == 0x11 ) ||
( V_79 == 0x22 && V_80 == 0x33 ) ||
( V_79 == 0x44 && V_80 == 0x55 ) ||
( V_79 == 0x66 && V_80 == 0x77 ) ||
( V_79 == 0x88 && V_80 == 0x99 ) ||
( V_79 == 0xaa && V_80 == 0xbb ) ||
( V_79 == 0xcc && V_80 == 0xdd ) ||
( V_79 == 0xee && V_80 == 0xff ) ) {
F_42 ( V_1 -> V_81 , V_82 , 1 ) ;
F_43 ( V_1 -> V_81 ) ;
F_42 ( V_1 -> V_81 , V_82 , 0 ) ;
F_43 ( V_1 -> V_81 ) ;
V_5 = 0 ;
}
}
return V_5 ;
}
static int F_44 ( struct V_83 * V_84 ,
const struct V_23 * V_24 )
{
return F_45 ( V_84 , V_24 , & V_85 , sizeof( struct V_25 ) ,
V_86 ) ;
}
